/**
 * Weapon System
 *
 * Handles weapon firing mechanics, ammo tracking, reloading, and recoil.
 * Supports two-slot weapon switching.
 * Priority: 30
 *
 * Responsibilities:
 * - Process weapon firing input
 * - Handle reload timing and ammo management
 * - Play appropriate SFX for fire and reload events
 *
 * Non-goals:
 * - Does NOT handle projectile collision (CollisionSystem)
 * - Does NOT handle damage application (HealthSystem)
 */

import { System, type UpdateContext } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs';
import type { EntityId } from '../../types';
import type { AudioManager } from '../../engine';
import { getWeaponData, type WeaponData } from '../data';
import { ProjectileFactory } from '../entities';
import { getWeaponFireSample, getWeaponReloadSample } from '../audio';

// Track cooldowns and reload timers per entity
interface WeaponState {
  shotCooldown: number;
  reloadTimer: number;
  spreadHeat: number;
  lastWeaponId: number; // Track weapon changes for state reset
  wasReloading: boolean; // Track reload state transition for SFX
}

const weaponStates = new Map<EntityId, WeaponState>();

export class WeaponSystem extends System {
  readonly name = 'WeaponSystem';
  readonly priority = 30;

  private entityManager: EntityManager;
  private audio: AudioManager;

  // Spread decay per second
  private readonly spreadDecay = 0.5;
  // Maximum spread heat
  private readonly maxSpreadHeat = 2.0;

  constructor(entityManager: EntityManager, audio: AudioManager) {
    super();
    this.entityManager = entityManager;
    this.audio = audio;
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
        state = { shotCooldown: 0, reloadTimer: 0, spreadHeat: 0, lastWeaponId: -1, wasReloading: false };
        weaponStates.set(entity.id, state);
      }

      const weaponData = getWeaponData(player.currentWeapon.weaponId);

      // Check if weapon changed (swap happened) - reset timers
      if (state.lastWeaponId !== player.currentWeapon.weaponId) {
        state.shotCooldown = 0;
        state.reloadTimer = 0;
        state.spreadHeat = 0;
        state.lastWeaponId = player.currentWeapon.weaponId;
        state.wasReloading = false;
      }

      // Handle swap weapon request
      if (player.swapWeaponRequested) {
        this.swapWeapons(player);
        player.swapWeaponRequested = false;
        continue; // Skip firing this frame after swap
      }

      // Handle reload timer
      if (state.reloadTimer > 0) {
        state.reloadTimer -= dt;
        if (state.reloadTimer <= 0) {
          // Reload complete
          state.reloadTimer = 0;
          const reloadAmount = Math.min(
            weaponData.clipSize - player.currentWeapon.clipSize,
            player.currentWeapon.ammo
          );
          player.currentWeapon.clipSize += reloadAmount;
          player.currentWeapon.ammo -= reloadAmount;
        }
        state.wasReloading = true;
        continue; // Can't fire while reloading
      }

      // Detect reload end for SFX (transition from reloading to not reloading)
      if (state.wasReloading && state.reloadTimer <= 0) {
        state.wasReloading = false;
      }

      // Handle reload request
      if (player.reloadRequested && player.currentWeapon.clipSize < weaponData.clipSize && player.currentWeapon.ammo > 0) {
        state.reloadTimer = weaponData.reloadTime;
        player.reloadRequested = false;
        // Play reload sound
        this.audio.playSample(getWeaponReloadSample(player.currentWeapon.weaponId));
        state.wasReloading = true;
        continue;
      }

      // Auto-reload when empty
      if (player.currentWeapon.clipSize <= 0 && player.currentWeapon.ammo > 0 && state.reloadTimer <= 0) {
        state.reloadTimer = weaponData.reloadTime;
        // Play reload sound on auto-reload
        this.audio.playSample(getWeaponReloadSample(player.currentWeapon.weaponId));
        state.wasReloading = true;
        continue;
      }

      // Handle firing
      const canFire =
        state.shotCooldown <= 0 &&
        player.currentWeapon.clipSize > 0 &&
        (weaponData.automatic ? player.fireHeld : player.fireJustPressed);

      if (canFire) {
        this.fireWeapon(entity.id, player.currentWeapon, transform, state, weaponData);
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
      player.reloadRequested = false;
      player.fireJustPressed = false;
    }
  }

  private swapWeapons(player: {
    currentWeapon: { weaponId: number; clipSize: number; ammo: number };
    alternateWeapon: { weaponId: number; clipSize: number; ammo: number };
  }): void {
    // Swap current and alternate weapons
    const temp = { ...player.currentWeapon };
    player.currentWeapon = { ...player.alternateWeapon };
    player.alternateWeapon = temp;
  }

  private fireWeapon(
    ownerId: EntityId,
    weaponSlot: { weaponId: number; clipSize: number },
    transform: { x: number; y: number; rotation: number },
    state: WeaponState,
    weaponData: WeaponData
  ): void {
    // Set cooldown
    state.shotCooldown = weaponData.fireRate;

    // Decrement ammo
    weaponSlot.clipSize--;

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

    // Play fire sound
    this.audio.playSample(getWeaponFireSample(weaponSlot.weaponId));
  }

  destroy(): void {
    weaponStates.clear();
  }
}
