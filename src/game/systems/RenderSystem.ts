/**
 * Render System
 *
 * Renders all visible entities and UI.
 * Priority: 200 (last to run)
 */

import { System, type UpdateContext } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs/EntityManager';
import { type Renderer, ParticleSystem, type InputManager, type AssetManager, type SpriteAtlas } from '../../engine';
import { getWeaponData } from '../data';

export class RenderSystem extends System {
  readonly name = 'RenderSystem';
  readonly priority = 200;

  private renderer: Renderer;
  private entityManager: EntityManager;
  private particleSystem: ParticleSystem;
  private inputManager: InputManager | null = null;
  private assetManager: AssetManager | null = null;
  private spriteAtlas: SpriteAtlas | null = null;

  // Camera follow settings
  private cameraSmoothing = 0.1;
  private currentCameraX = 0;
  private currentCameraY = 0;

  // FPS counter
  private frameCount = 0;
  private lastFpsTime = 0;
  private currentFps = 0;
  private showFps = false;

  constructor(
    entityManager: EntityManager,
    renderer: Renderer,
    assetManager?: AssetManager,
    spriteAtlas?: SpriteAtlas,
    inputManager?: InputManager
  ) {
    super();
    this.entityManager = entityManager;
    this.renderer = renderer;
    this.assetManager = assetManager ?? null;
    this.spriteAtlas = spriteAtlas ?? null;
    this.inputManager = inputManager ?? null;
    this.particleSystem = new ParticleSystem(1000);
  }

  /**
   * Get the particle system for emitting effects
   */
  getParticleSystem(): ParticleSystem {
    return this.particleSystem;
  }

  /**
   * Toggle FPS counter display
   */
  toggleFps(): void {
    this.showFps = !this.showFps;
  }

  /**
   * Trigger screen shake
   */
  shake(intensity: number, duration: number): void {
    this.renderer.shake(intensity, duration);
  }

  update(_entityManager: EntityManager, context: UpdateContext): void {
    // Update FPS counter
    this.updateFps(context.dt);

    // Update screen shake
    this.renderer.updateScreenShake(context.dt);

    // Update particles
    this.particleSystem.update(context.dt);

    // Clear screen
    this.renderer.clearBlack();

    // Apply camera (with screen shake)
    this.updateCamera();
    const shakeOffset = this.renderer.getShakeOffset();
    this.renderer.setCamera(
      this.currentCameraX + shakeOffset.x,
      this.currentCameraY + shakeOffset.y
    );
    this.renderer.applyCamera();

    // Render entities
    this.renderEntities();

    // Render particles (world space)
    this.particleSystem.render(this.renderer);

    // Restore camera
    this.renderer.restoreCamera();

    // Render UI (in screen space)
    this.renderUI();

    // Render touch controls if enabled
    if (this.inputManager?.isTouchEnabled()) {
      const ctx = this.renderer.getContext();
      this.inputManager.renderTouchControls(ctx);
    }
  }

  private updateFps(dt: number): void {
    this.frameCount++;
    this.lastFpsTime += dt;
    if (this.lastFpsTime >= 1) {
      this.currentFps = this.frameCount;
      this.frameCount = 0;
      this.lastFpsTime = 0;
    }
  }

  private updateCamera(): void {
    // Find player to follow
    const players = this.entityManager.query(['player', 'transform']);
    if (players.length > 0) {
      const player = players[0];
      if (!player) return;
      const transform = player.getComponent<'transform'>('transform');
      if (!transform) return;

      // Smooth camera follow
      const targetX = transform.x;
      const targetY = transform.y;

      this.currentCameraX += (targetX - this.currentCameraX) * this.cameraSmoothing;
      this.currentCameraY += (targetY - this.currentCameraY) * this.cameraSmoothing;

      this.renderer.setCamera(this.currentCameraX, this.currentCameraY, 1, 0);
    }
  }

  private renderEntities(): void {
    // Render projectiles
    const projectiles = this.entityManager.query(['projectile', 'transform']);
    for (const entity of projectiles) {
      const transform = entity.getComponent<'transform'>('transform');
      const projectile = entity.getComponent<'projectile'>('projectile');
      if (!transform || !projectile) continue;

      // Simple projectile rendering (colored rectangle)
      this.renderer.setColor(1, 1, 0, 1);
      this.renderer.drawRect(transform.x - 2, transform.y - 2, 4, 4);
    }

    // Render creatures with sprites
    const creatures = this.entityManager.query(['creature', 'transform', 'sprite']);
    for (const entity of creatures) {
      const transform = entity.getComponent<'transform'>('transform');
      const creature = entity.getComponent<'creature'>('creature');
      const sprite = entity.getComponent<'sprite'>('sprite');
      if (!transform || !creature || !sprite) continue;

      const image = this.assetManager?.getImage('creatures');
      if (image && this.spriteAtlas) {
        // Build frame name: "{textureName}_{frame}"
        const frameName = `${sprite.textureName}_${creature.frame}`;
        const frame = this.spriteAtlas.getFrame(frameName);

        if (frame) {
          this.renderer.drawSprite(image, frame, transform.x, transform.y, {
            rotation: transform.rotation,
            scale: creature.size,
            opacity: creature.tint.a,
          });
        } else {
          // Fallback to colored circle if frame not found
          this.renderCreatureFallback(transform, creature);
        }
      } else {
        // Fallback if image not loaded
        this.renderCreatureFallback(transform, creature);
      }
    }

    // Render players
    const players = this.entityManager.query(['player', 'transform']);
    for (const entity of players) {
      const transform = entity.getComponent<'transform'>('transform');
      const player = entity.getComponent<'player'>('player');
      if (!transform || !player) continue;

      // Draw player
      this.renderer.setColor(0, 1, 0, 1);
      this.renderer.drawCircle(transform.x, transform.y, 12);

      // Draw shield if active
      if (player.shieldTimer > 0) {
        this.renderer.setColor(0, 0.5, 1, 0.5);
        this.renderer.drawCircleOutline(transform.x, transform.y, 18, 2);
      }

      // Draw fire bullet aura if active
      if (player.fireBulletsTimer > 0) {
        this.renderer.setColor(1, 0.3, 0, 0.3);
        this.renderer.drawCircle(transform.x, transform.y, 14);
      }
    }

    // Render bonuses with glow effects
    const bonuses = this.entityManager.query(['bonus', 'transform']);
    for (const entity of bonuses) {
      const transform = entity.getComponent<'transform'>('transform');
      const bonus = entity.getComponent<'bonus'>('bonus');
      if (!transform || !bonus) continue;

      // Color based on bonus type
      let glowColor: { r: number; g: number; b: number };
      switch (bonus.bonusType) {
        case 0: // HEALTH
          glowColor = { r: 1, g: 0, b: 0 };
          break;
        case 1: // AMMO
          glowColor = { r: 1, g: 1, b: 0 };
          break;
        case 2: // WEAPON_POWER_UP
          glowColor = { r: 1, g: 0.5, b: 0 };
          break;
        case 3: // SPEED_BOOST
          glowColor = { r: 0, g: 1, b: 1 };
          break;
        case 4: // SHIELD
          glowColor = { r: 0, g: 0.5, b: 1 };
          break;
        case 5: // FIRE_BULLETS
          glowColor = { r: 1, g: 0.3, b: 0 };
          break;
        case 6: // EXP_MULTIPLIER
          glowColor = { r: 1, g: 0, b: 1 };
          break;
        default:
          glowColor = { r: 1, g: 1, b: 1 };
      }

      // Draw glow
      this.renderer.drawGlow(transform.x, transform.y, 20, { ...glowColor, a: 0.5 });

      // Draw bonus
      this.renderer.setColor(glowColor.r, glowColor.g, glowColor.b, 1);
      this.renderer.drawCircle(transform.x, transform.y, 8);

      // Draw pulsing ring
      const pulse = 1 + Math.sin(Date.now() / 200) * 0.2;
      this.renderer.setColor(glowColor.r, glowColor.g, glowColor.b, 0.5);
      this.renderer.drawCircleOutline(transform.x, transform.y, 12 * pulse, 2);
    }

    // Render weapon pickups
    const weaponPickups = this.entityManager.query(['weaponPickup', 'transform']);
    for (const entity of weaponPickups) {
      const transform = entity.getComponent<'transform'>('transform');
      const pickup = entity.getComponent<'weaponPickup'>('weaponPickup');
      if (!transform || !pickup) continue;

      const weaponData = getWeaponData(pickup.weaponId);

      // Draw weapon pickup glow (orange for weapons)
      this.renderer.drawGlow(transform.x, transform.y, 25, { r: 1, g: 0.6, b: 0, a: 0.5 });

      // Draw weapon pickup base
      this.renderer.setColor(1, 0.6, 0, 1);
      this.renderer.drawRect(transform.x - 12, transform.y - 8, 24, 16);

      // Draw pulsing ring
      const pulse = 1 + Math.sin(Date.now() / 200) * 0.2;
      this.renderer.setColor(1, 0.8, 0, 0.5);
      this.renderer.drawCircleOutline(transform.x, transform.y, 16 * pulse, 2);

      // Draw ammo indicator
      this.renderer.setColor(1, 1, 1, 0.8);
      this.renderer.drawText(`${pickup.ammo}`, transform.x - 10, transform.y + 4);
      // Avoid unused variable warning by referencing weaponData
      void weaponData;
    }
  }

  /**
   * Fallback rendering for creatures when sprites are not available.
   */
  private renderCreatureFallback(
    transform: { x: number; y: number; rotation?: number },
    creature: { tint: { r: number; g: number; b: number; a: number }; size: number }
  ): void {
    this.renderer.setColor(creature.tint.r, creature.tint.g, creature.tint.b, creature.tint.a);
    const size = 16 * creature.size;
    this.renderer.drawCircle(transform.x, transform.y, size);
  }

  private renderUI(): void {
    const players = this.entityManager.query(['player']);
    if (players.length === 0) return;

    const player = players[0];
    if (!player) return;
    const playerComp = player.getComponent<'player'>('player');
    if (!playerComp) return;

    const currentWeaponData = getWeaponData(playerComp.currentWeapon.weaponId);
    const altWeaponData = getWeaponData(playerComp.alternateWeapon.weaponId);

    const canvas = this.renderer.getCanvas();
    const rightEdge = canvas.width;

    // Set text color
    this.renderer.setColor(1, 1, 1, 1);

    // Health bar
    const healthPercent = playerComp.health / playerComp.maxHealth;
    this.renderer.drawText(`HP: ${Math.ceil(playerComp.health)}/${playerComp.maxHealth}`, 10, 40);
    this.renderer.drawRectOutline(10, 50, 204, 14, 1);
    // Health bar gradient
    this.renderer.setColor(1 - healthPercent, healthPercent, 0, 1);
    this.renderer.drawRect(12, 52, 200 * healthPercent, 10);

    // XP bar (below health)
    const xpPercent = playerComp.experience / (playerComp.level * 100); // Approximate
    this.renderer.setColor(1, 1, 1, 1);
    this.renderer.drawText(`Level ${playerComp.level}`, 10, 85);
    this.renderer.drawRectOutline(10, 90, 204, 8, 1);
    this.renderer.setColor(0.2, 0.6, 1, 1);
    this.renderer.drawRect(12, 92, Math.min(200, 200 * xpPercent), 4);

    // Current weapon info
    this.renderer.setColor(1, 1, 1, 1);
    this.renderer.drawText(
      `Ammo: ${playerComp.currentWeapon.clipSize}/${currentWeaponData.clipSize} (${playerComp.currentWeapon.ammo})`,
      10,
      120
    );
    this.renderer.drawText(`Weapon: ${currentWeaponData.name}`, 10, 140);

    // Alternate weapon info
    this.renderer.setColor(0.7, 0.7, 0.7, 1);
    this.renderer.drawText(
      `Alt: ${altWeaponData.name} (${playerComp.alternateWeapon.clipSize}/${playerComp.alternateWeapon.ammo})`,
      10,
      160
    );
    // Show swap weapon key binding dynamically
    const swapKeyLabel = this.getSwapKeyLabel();
    this.renderer.setColor(0.5, 0.5, 0.5, 1);
    this.renderer.drawText(`[${swapKeyLabel}] Swap Weapon`, 10, 175);

    // Active effects (with icons)
    let yOffset = 205;
    if (playerComp.shieldTimer > 0) {
      this.renderer.drawGlow(25, yOffset - 5, 20, { r: 0, g: 0.5, b: 1, a: 0.5 });
      this.renderer.setColor(0, 0.5, 1, 1);
      this.renderer.drawText(`Shield: ${playerComp.shieldTimer.toFixed(1)}s`, 45, yOffset);
      yOffset += 25;
    }
    if (playerComp.fireBulletsTimer > 0) {
      this.renderer.drawGlow(25, yOffset - 5, 20, { r: 1, g: 0.3, b: 0, a: 0.5 });
      this.renderer.setColor(1, 0.3, 0, 1);
      this.renderer.drawText(
        `Fire: ${playerComp.fireBulletsTimer.toFixed(1)}s`,
        45,
        yOffset
      );
      yOffset += 25;
    }
    if (playerComp.speedBonusTimer > 0) {
      this.renderer.drawGlow(25, yOffset - 5, 20, { r: 0, g: 1, b: 1, a: 0.5 });
      this.renderer.setColor(0, 1, 1, 1);
      this.renderer.drawText(`Speed: ${playerComp.speedBonusTimer.toFixed(1)}s`, 45, yOffset);
    }

    // FPS counter (top-right, only if enabled)
    if (this.showFps) {
      this.renderer.setColor(0, 1, 0, 0.7);
      this.renderer.drawText(`FPS: ${this.currentFps}`, rightEdge - 80, 25);
    }
  }

  setCameraPosition(x: number, y: number): void {
    this.currentCameraX = x;
    this.currentCameraY = y;
  }

  /**
   * Get the display label for the swap weapon key.
   * Falls back to 'Q' if no input manager is available.
   */
  private getSwapKeyLabel(): string {
    // Try to get from window.gameState for dynamic binding
    // This is a bit hacky but maintains compatibility with the existing architecture
    const gameState = (window as unknown as { gameState?: { settingsManager?: { getKeyBindings: () => { swapWeapon: string } } } }).gameState;
    if (gameState?.settingsManager?.getKeyBindings) {
      const binding = gameState.settingsManager.getKeyBindings().swapWeapon;
      return this.formatKeyCode(binding);
    }
    return 'Q';
  }

  /**
   * Format a key code for display (e.g., 'KeyQ' -> 'Q', 'Escape' -> 'ESC').
   */
  private formatKeyCode(code: string): string {
    if (code.startsWith('Key')) {
      return code.slice(3);
    }
    if (code === 'Escape') return 'ESC';
    if (code === 'Space') return 'SPC';
    if (code.startsWith('Arrow')) {
      return code.slice(5).toUpperCase();
    }
    if (code.startsWith('Digit')) {
      return code.slice(5);
    }
    return code;
  }
}
