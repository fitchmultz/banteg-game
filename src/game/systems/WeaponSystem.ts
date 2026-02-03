/**
 * Weapon System
 *
 * Handles weapon firing mechanics, ammo tracking, reloading, and recoil.
 * Priority: 30
 */

import { System, type UpdateContext } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs';
import type { EntityId } from '../../types';
import type { AudioManager } from '../../engine';
import { getWeaponData } from '../data';
import { ProjectileFactory } from '../entities';

// Track cooldowns and reload timers per entity
interface WeaponState {
  shotCooldown: number;
  reloadTimer: number;
  spreadHeat: number;
}

const weaponStates = new Map<EntityId, WeaponState>();

export class WeaponSystem extends System {
  readonly name = 'WeaponSystem';
  readonly priority = 30;

  // Audio manager for sound effects (unused currently but will be needed)
  // private _audio: AudioManager;
  private entityManager: EntityManager;

  // Spread decay per second
  private readonly spreadDecay = 0.5;
  // Maximum spread heat
  private readonly maxSpreadHeat = 2.0;

  constructor(entityManager: EntityManager, _audio: AudioManager) {
    super();
    this.entityManager = entityManager;
    // this._audio = audio;  // Audio will be used for shooting sounds
  }

  update(_entityManager: EntityManager, context: UpdateContext): void {
    const dt = context.dt;

    // Query all player entities
    const entities = this.entityManager.query(['player', 'transform']);

    for (const entity of entities) {
      const player = entity.getComponent<'player'>('player');
      const transform = entity.getComponent<'transform'>('transform');
      if (!player || !transform) continue;

      // Get or create weapon state for this entity
      let state = weaponStates.get(entity.id);
      if (!state) {
        state = { shotCooldown: 0, reloadTimer: 0, spreadHeat: 0 };
        weaponStates.set(entity.id, state);
      }

      const weaponData = getWeaponData(player.weaponId);

      // Handle reload timer
      if (state.reloadTimer > 0) {
        state.reloadTimer -= dt;
        if (state.reloadTimer <= 0) {
          // Reload complete
          state.reloadTimer = 0;
          const reloadAmount = Math.min(weaponData.clipSize - player.clipSize, player.ammo);
          player.clipSize += reloadAmount;
          player.ammo -= reloadAmount;
        }
        continue; // Can't fire while reloading
      }

      // Handle reload request
      const reloadRequested = (player as unknown as Record<string, boolean>).reloadRequested;
      if (reloadRequested && player.clipSize < weaponData.clipSize && player.ammo > 0) {
        state.reloadTimer = weaponData.reloadTime;
        (player as unknown as Record<string, boolean>).reloadRequested = false;
        continue;
      }

      // Auto-reload when empty
      if (player.clipSize <= 0 && player.ammo > 0 && state.reloadTimer <= 0) {
        state.reloadTimer = weaponData.reloadTime;
        continue;
      }

      // Handle firing
      const fireHeld = (player as unknown as Record<string, boolean>).fireHeld;
      const fireJustPressed = (player as unknown as Record<string, boolean>).fireJustPressed;

      const canFire =
        state.shotCooldown <= 0 &&
        player.clipSize > 0 &&
        (weaponData.automatic ? fireHeld : fireJustPressed);

      if (canFire) {
        this.fireWeapon(entity.id, player, transform, state, weaponData);
      }

      // Update cooldown
      if (state.shotCooldown > 0) {
        state.shotCooldown -= dt;
      }

      // Decay spread heat
      if (state.spreadHeat > 0) {
        state.spreadHeat = Math.max(0, state.spreadHeat - this.spreadDecay * dt);
      }

      // Clear input flags
      (player as unknown as Record<string, boolean>).reloadRequested = false;
    }
  }

  private fireWeapon(
    ownerId: EntityId,
    player: { weaponId: number; clipSize: number },
    transform: { x: number; y: number; rotation: number },
    state: WeaponState,
    weaponData: ReturnType<typeof getWeaponData>
  ): void {
    // Set cooldown
    state.shotCooldown = weaponData.fireRate;

    // Decrement ammo
    player.clipSize--;

    // Calculate spawn position (at player position)
    const spawnX = transform.x;
    const spawnY = transform.y;

    // Calculate base angle with spread
    const baseAngle = transform.rotation;
    const spreadAmount = weaponData.spread * (1 + state.spreadHeat);

    // Increase spread heat
    state.spreadHeat = Math.min(this.maxSpreadHeat, state.spreadHeat + weaponData.spread * 0.5);

    // Fire projectiles
    if (weaponData.pelletCount > 1) {
      // Shotgun-style multi-pellet spread
      ProjectileFactory.createWithSpread(
        this.entityManager,
        weaponData.projectileType,
        spawnX,
        spawnY,
        baseAngle,
        spreadAmount,
        weaponData.pelletCount,
        ownerId
      );
    } else {
      // Single projectile with spread
      const angleOffset = (Math.random() - 0.5) * spreadAmount * 2;
      ProjectileFactory.create(
        this.entityManager,
        weaponData.projectileType,
        spawnX,
        spawnY,
        baseAngle + angleOffset,
        ownerId
      );
    }

    // Play sound effect (placeholder)
    // this.audio.playSample(weaponData.shotSound);
  }

  destroy(): void {
    weaponStates.clear();
  }
}
