/**
 * Entity Renderer
 *
 * Renders all game entities: projectiles, creatures, corpses, players, bonuses, and weapon pickups.
 *
 * Responsibilities:
 * - Render projectiles (simple colored rectangles)
 * - Render creatures with sprite animation support
 * - Render corpses (dead enemies with darkened tint)
 * - Render players with shield and fire bullet effects
 * - Render bonuses with glow effects
 * - Render weapon pickups
 *
 * Non-responsibilities:
 * - Does not manage camera (handled by CameraManager)
 * - Does not render terrain (handled by TerrainRenderer)
 * - Does not render UI (handled by UiRenderer)
 */

import type { EntityManager } from '../../../core/ecs/EntityManager';
import type { AssetManager, Renderer, SpriteAtlas } from '../../../engine';
import { BonusType } from '../../components';
import { getWeaponData } from '../../data';

export class EntityRenderer {
  private renderer: Renderer;
  private entityManager: EntityManager;
  private assetManager: AssetManager | null;
  private spriteAtlas: SpriteAtlas | null;

  constructor(
    renderer: Renderer,
    entityManager: EntityManager,
    assetManager: AssetManager | null,
    spriteAtlas: SpriteAtlas | null
  ) {
    this.renderer = renderer;
    this.entityManager = entityManager;
    this.assetManager = assetManager;
    this.spriteAtlas = spriteAtlas;
  }

  /**
   * Render all game entities.
   */
  render(): void {
    this.renderProjectiles();
    this.renderCorpses();
    this.renderCreatures();
    this.renderPlayers();
    this.renderBonuses();
    this.renderWeaponPickups();
  }

  /**
   * Render projectiles as simple colored rectangles.
   */
  private renderProjectiles(): void {
    const projectiles = this.entityManager.query(['projectile', 'transform']);
    for (const entity of projectiles) {
      const transform = entity.getComponent<'transform'>('transform');
      const projectile = entity.getComponent<'projectile'>('projectile');
      if (!transform || !projectile) continue;

      // Simple projectile rendering (colored rectangle)
      this.renderer.setColor(1, 1, 0, 1);
      this.renderer.drawRect(transform.x - 2, transform.y - 2, 4, 4);
    }
  }

  /**
   * Render creatures with sprite animation support.
   */
  private renderCreatures(): void {
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
  }

  /**
   * Render corpses (dead enemies) with darkened tint.
   */
  private renderCorpses(): void {
    const corpses = this.entityManager.query(['corpse', 'transform', 'sprite']);
    for (const entity of corpses) {
      const transform = entity.getComponent<'transform'>('transform');
      const corpse = entity.getComponent<'corpse'>('corpse');
      const sprite = entity.getComponent<'sprite'>('sprite');
      if (!transform || !corpse || !sprite) continue;

      // Darken the tint for dead appearance
      const darkTint = {
        r: corpse.tint.r * 0.5,
        g: corpse.tint.g * 0.5,
        b: corpse.tint.b * 0.5,
        a: corpse.tint.a * 0.8,
      };

      const image = this.assetManager?.getImage('creatures');
      if (image && this.spriteAtlas) {
        // Use a static frame for corpses (frame 0)
        const frameName = `${sprite.textureName}_0`;
        const frame = this.spriteAtlas.getFrame(frameName);

        if (frame) {
          this.renderer.drawSprite(image, frame, transform.x, transform.y, {
            rotation: corpse.rotation,
            scale: corpse.size,
            opacity: darkTint.a,
          });
        } else {
          // Fallback to darkened circle
          this.renderer.setColor(darkTint.r, darkTint.g, darkTint.b, darkTint.a);
          this.renderer.drawCircle(transform.x, transform.y, 16 * corpse.size);
        }
      } else {
        // Fallback if image not loaded
        this.renderer.setColor(darkTint.r, darkTint.g, darkTint.b, darkTint.a);
        this.renderer.drawCircle(transform.x, transform.y, 16 * corpse.size);
      }
    }
  }

  /**
   * Render players with shield and fire bullet effects.
   */
  private renderPlayers(): void {
    const players = this.entityManager.query(['player', 'transform']);
    for (const entity of players) {
      const transform = entity.getComponent<'transform'>('transform');
      const player = entity.getComponent<'player'>('player');
      if (!transform || !player) continue;

      // Different colors for different players
      const playerIndex = player.playerIndex ?? 0;
      if (playerIndex === 0) {
        // P1: Green
        this.renderer.setColor(0, 1, 0, 1);
      } else {
        // P2: Blue
        this.renderer.setColor(0, 0.5, 1, 1);
      }
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
  }

  /**
   * Render bonuses with glow effects based on bonus type.
   */
  private renderBonuses(): void {
    const bonuses = this.entityManager.query(['bonus', 'transform']);
    for (const entity of bonuses) {
      const transform = entity.getComponent<'transform'>('transform');
      const bonus = entity.getComponent<'bonus'>('bonus');
      if (!transform || !bonus) continue;

      // Color based on bonus type
      const glowColor = this.getBonusGlowColor(bonus.bonusType);

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
  }

  /**
   * Get the glow color for a bonus type.
   */
  private getBonusGlowColor(bonusType: BonusType): { r: number; g: number; b: number } {
    switch (bonusType) {
      case BonusType.MEDIKIT:
        return { r: 1, g: 0, b: 0 };
      case BonusType.WEAPON:
        return { r: 1, g: 1, b: 0 };
      case BonusType.WEAPON_POWER_UP:
        return { r: 1, g: 0.5, b: 0 };
      case BonusType.SPEED:
        return { r: 0, g: 1, b: 1 };
      case BonusType.SHIELD:
        return { r: 0, g: 0.5, b: 1 };
      case BonusType.FIRE_BULLETS:
        return { r: 1, g: 0.3, b: 0 };
      case BonusType.DOUBLE_EXPERIENCE:
        return { r: 1, g: 0, b: 1 };
      case BonusType.POINTS:
        return { r: 1, g: 1, b: 0 };
      case BonusType.ATOMIC:
        return { r: 1, g: 0.3, b: 0 };
      case BonusType.FIREBLAST:
        return { r: 1, g: 0.3, b: 0 };
      case BonusType.SHOCK_CHAIN:
        return { r: 0, g: 0.666, b: 1 };
      case BonusType.FREEZE:
        return { r: 0, g: 0.666, b: 1 };
      case BonusType.ENERGIZER:
        return { r: 1, g: 0.866, b: 0 };
      case BonusType.REFLEX_BOOST:
        return { r: 0.666, g: 0, b: 1 };
      default:
        return { r: 1, g: 1, b: 1 };
    }
  }

  /**
   * Render weapon pickups with glow effects.
   */
  private renderWeaponPickups(): void {
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
}
