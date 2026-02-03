/**
 * Render System
 *
 * Renders all visible entities and UI.
 * Priority: 200 (last to run)
 */


import { System } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs/EntityManager';
import type { Renderer } from '../../engine';
import { getWeaponData } from '../data';

export class RenderSystem extends System {
  readonly name = 'RenderSystem';
  readonly priority = 200;

  private renderer: Renderer;
  private entityManager: EntityManager;

  // Camera follow settings
  private cameraSmoothing = 0.1;
  private currentCameraX = 0;
  private currentCameraY = 0;

  constructor(entityManager: EntityManager, renderer: Renderer) {
    super();
    this.entityManager = entityManager;
    this.renderer = renderer;
  }

  update(): void {
    // Clear screen
    this.renderer.clearBlack();

    // Apply camera
    this.updateCamera();
    this.renderer.applyCamera();

    // Render entities
    this.renderEntities();

    // Restore camera
    this.renderer.restoreCamera();

    // Render UI (in screen space)
    this.renderUI();
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

    // Render creatures
    const creatures = this.entityManager.query(['creature', 'transform']);
    for (const entity of creatures) {
      const transform = entity.getComponent<'transform'>('transform');
      const creature = entity.getComponent<'creature'>('creature');
      if (!transform || !creature) continue;

      // Use creature tint for color
      this.renderer.setColor(
        creature.tint.r,
        creature.tint.g,
        creature.tint.b,
        creature.tint.a
      );

      // Draw creature as a circle
      const size = 16 * creature.size;
      this.renderer.drawCircle(transform.x, transform.y, size);
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

    // Render bonuses
    const bonuses = this.entityManager.query(['bonus', 'transform']);
    for (const entity of bonuses) {
      const transform = entity.getComponent<'transform'>('transform');
      const bonus = entity.getComponent<'bonus'>('bonus');
      if (!transform || !bonus) continue;

      // Color based on bonus type
      switch (bonus.bonusType) {
        case 0: // HEALTH
          this.renderer.setColor(1, 0, 0, 1);
          break;
        case 1: // AMMO
          this.renderer.setColor(1, 1, 0, 1);
          break;
        case 2: // WEAPON_POWER_UP
          this.renderer.setColor(1, 0.5, 0, 1);
          break;
        case 3: // SPEED_BOOST
          this.renderer.setColor(0, 1, 1, 1);
          break;
        case 4: // SHIELD
          this.renderer.setColor(0, 0.5, 1, 1);
          break;
        case 5: // FIRE_BULLETS
          this.renderer.setColor(1, 0.3, 0, 1);
          break;
        case 6: // EXP_MULTIPLIER
          this.renderer.setColor(1, 0, 1, 1);
          break;
        default:
          this.renderer.setColor(1, 1, 1, 1);
      }

      this.renderer.drawCircle(transform.x, transform.y, 8);
    }
  }

  private renderUI(): void {
    const players = this.entityManager.query(['player']);
    if (players.length === 0) return;

    const player = players[0];
    if (!player) return;
    const playerComp = player.getComponent<'player'>('player');
    if (!playerComp) return;
    const weaponData = getWeaponData(playerComp.weaponId);

    // Set text color
    this.renderer.setColor(1, 1, 1, 1);

    // Health bar
    const healthPercent = playerComp.health / playerComp.maxHealth;
    this.renderer.drawText(`HP: ${Math.ceil(playerComp.health)}/${playerComp.maxHealth}`, 10, 40);
    this.renderer.drawRectOutline(10, 50, 104, 14, 1);
    this.renderer.setColor(1 - healthPercent, healthPercent, 0, 1);
    this.renderer.drawRect(12, 52, 100 * healthPercent, 10);

    // Ammo
    this.renderer.setColor(1, 1, 1, 1);
    this.renderer.drawText(
      `Ammo: ${playerComp.clipSize}/${weaponData.clipSize} (${playerComp.ammo})`,
      10,
      80
    );

    // Weapon name
    this.renderer.drawText(`Weapon: ${weaponData.name}`, 10, 100);

    // Active effects
    let yOffset = 120;
    if (playerComp.shieldTimer > 0) {
      this.renderer.setColor(0, 0.5, 1, 1);
      this.renderer.drawText(`Shield: ${playerComp.shieldTimer.toFixed(1)}s`, 10, yOffset);
      yOffset += 20;
    }
    if (playerComp.fireBulletsTimer > 0) {
      this.renderer.setColor(1, 0.3, 0, 1);
      this.renderer.drawText(`Fire Bullets: ${playerComp.fireBulletsTimer.toFixed(1)}s`, 10, yOffset);
      yOffset += 20;
    }
    if (playerComp.speedBonusTimer > 0) {
      this.renderer.setColor(0, 1, 1, 1);
      this.renderer.drawText(`Speed Boost: ${playerComp.speedBonusTimer.toFixed(1)}s`, 10, yOffset);
    }
  }

  setCameraPosition(x: number, y: number): void {
    this.currentCameraX = x;
    this.currentCameraY = y;
  }
}
