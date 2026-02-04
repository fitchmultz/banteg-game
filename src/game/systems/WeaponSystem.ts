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
 * - Apply perk multipliers (damage, fire rate, reload speed, clip size)
 * - Honor infinite ammo window from Ammunition Within perk
 * - Play appropriate SFX for fire and reload events
 *
 * Non-goals:
 * - Does NOT handle projectile collision (CollisionSystem)
 * - Does NOT handle damage application (HealthSystem)
 * - Does NOT handle perk application (PerkSystem)
 */

import { System, type UpdateContext } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs';
import type { EntityId } from '../../types';
import type { AudioManager } from '../../engine';
import { getWeaponData, type WeaponData } from '../data';
import { ProjectileFactory } from '../entities';
import { getWeaponFireSample, getWeaponReloadSample } from '../audio';
import type { PerkSystem } from './PerkSystem';

// Track cooldowns and reload timers per entity
interface WeaponState {
  shotCooldown: number;
  reloadTimer: number;
  spreadHeat: number;
  lastWeaponId: number; // Track weapon changes for state reset
  wasReloading: boolean; // Track reload state transition for SFX
  reloadJustCompleted: boolean; // Track if reload just finished this frame
}

const weaponStates = new Map<EntityId, WeaponState>();

export class WeaponSystem extends System {
  readonly name = 'WeaponSystem';
  readonly priority = 30;

  private entityManager: EntityManager;
  private audio: AudioManager;
  private perkSystem: PerkSystem | null = null;

  // Spread decay per second
  private readonly spreadDecay = 0.5;
  // Maximum spread heat
  private readonly maxSpreadHeat = 2.0;

  constructor(entityManager: EntityManager, audio: AudioManager, perkSystem?: PerkSystem) {
    super();
    this.entityManager = entityManager;
    this.audio = audio;
    if (perkSystem) {
      this.perkSystem = perkSystem;
    }
  }

  /**
   * Set the perk system for accessing perk multipliers
   */
  setPerkSystem(perkSystem: PerkSystem): void {
    this.perkSystem = perkSystem;
  }

  update(_entityManager: EntityManager, context: UpdateContext): void {
    const dt = context.dt;
    const gameTime = context.gameTime;

    // Query all player entities
    const entities = this.entityManager.query(['player', 'transform']);

    for (const entity of entities) {
      const player = entity.getComponent<'player'>('player');
      const transform = entity.getComponent<'transform'>('transform');
      if (!player || !transform) continue;

      // Get or create weapon state for this entity
      let state = weaponStates.get(entity.id);
      if (!state) {
        state = {
          shotCooldown: 0,
          reloadTimer: 0,
          spreadHeat: 0,
          lastWeaponId: -1,
          wasReloading: false,
          reloadJustCompleted: false,
        };
        weaponStates.set(entity.id, state);
      }

      const weaponData = getWeaponData(player.currentWeapon.weaponId);

      // Get perk multipliers
      const fireRateMultiplier = this.perkSystem?.getFireRateMultiplier(entity.id) ?? 1;
      const reloadSpeedMultiplier = this.perkSystem?.getReloadSpeedMultiplier(entity.id) ?? 1;
      const clipSizeBonus = this.perkSystem?.getClipSizeBonus(entity.id) ?? 0;
      const effectiveClipSize = weaponData.clipSize + clipSizeBonus;

      // Check for infinite ammo window
      const infiniteAmmoActive = this.perkSystem?.isInfiniteAmmoActive(entity.id, gameTime) ?? false;

      // Check if weapon changed (swap happened) - reset timers
      if (state.lastWeaponId !== player.currentWeapon.weaponId) {
        state.shotCooldown = 0;
        state.reloadTimer = 0;
        state.spreadHeat = 0;
        state.lastWeaponId = player.currentWeapon.weaponId;
        state.wasReloading = false;
        state.reloadJustCompleted = false;
      }

      // Handle swap weapon request
      if (player.swapWeaponRequested) {
        this.swapWeapons(player);
        player.swapWeaponRequested = false;
        continue; // Skip firing this frame after swap
      }

      // Handle reload timer
      state.reloadJustCompleted = false;
      if (state.reloadTimer > 0) {
        state.reloadTimer -= dt;
        if (state.reloadTimer <= 0) {
          // Reload complete
          state.reloadTimer = 0;
          state.reloadJustCompleted = true;

          const reloadAmount = Math.min(
            effectiveClipSize - player.currentWeapon.clipSize,
            player.currentWeapon.ammo
          );
          player.currentWeapon.clipSize += reloadAmount;
          player.currentWeapon.ammo -= reloadAmount;

          // Trigger infinite ammo window on reload completion
          if (this.perkSystem && reloadAmount > 0) {
            this.perkSystem.startInfiniteAmmoWindow(entity.id, gameTime);
          }
        }
        state.wasReloading = true;
        continue; // Can't fire while reloading
      }

      // Detect reload end for SFX (transition from reloading to not reloading)
      if (state.wasReloading && state.reloadTimer <= 0) {
        state.wasReloading = false;
      }

      // Handle reload request
      if (player.reloadRequested && player.currentWeapon.clipSize < effectiveClipSize && player.currentWeapon.ammo > 0) {
        state.reloadTimer = weaponData.reloadTime / reloadSpeedMultiplier;
        player.reloadRequested = false;
        // Play reload sound
        this.audio.playSample(getWeaponReloadSample(player.currentWeapon.weaponId));
        state.wasReloading = true;
        continue;
      }

      // Auto-reload when empty (only if not in infinite ammo window)
      if (!infiniteAmmoActive && player.currentWeapon.clipSize <= 0 && player.currentWeapon.ammo > 0 && state.reloadTimer <= 0) {
        state.reloadTimer = weaponData.reloadTime / reloadSpeedMultiplier;
        // Play reload sound on auto-reload
        this.audio.playSample(getWeaponReloadSample(player.currentWeapon.weaponId));
        state.wasReloading = true;
        continue;
      }

      // Handle firing
      const canFire =
        state.shotCooldown <= 0 &&
        (infiniteAmmoActive || player.currentWeapon.clipSize > 0) &&
        (weaponData.automatic ? player.fireHeld : player.fireJustPressed);

      if (canFire) {
        this.fireWeapon(
          entity.id,
          player.currentWeapon,
          transform,
          state,
          weaponData,
          infiniteAmmoActive,
          fireRateMultiplier
        );
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
    weaponData: WeaponData,
    infiniteAmmoActive: boolean,
    fireRateMultiplier: number
  ): void {
    // Set cooldown with fire rate multiplier (higher multiplier = lower cooldown = faster firing)
    state.shotCooldown = weaponData.fireRate / fireRateMultiplier;

    // Decrement ammo (only if not in infinite ammo window)
    if (!infiniteAmmoActive) {
      weaponSlot.clipSize--;
    }

    // Calculate damage with multiplier
    let damage = weaponData.damage;
    if (this.perkSystem) {
      damage *= this.perkSystem.getDamageMultiplier(ownerId);
    }

    // Calculate spawn position (at player position)
    const spawnX = transform.x;
    const spawnY = transform.y;

    // Calculate base angle with spread
    const baseAngle = transform.rotation;
    const spreadAmount = weaponData.spread * (1 + state.spreadHeat);

    // Increase spread heat
    state.spreadHeat = Math.min(this.maxSpreadHeat, state.spreadHeat + weaponData.spread * 0.5);

    // Fire projectiles with calculated damage
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
        ownerId,
        { damage }
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
        ownerId,
        { damage }
      );
    }

    // Play fire sound
    this.audio.playSample(getWeaponFireSample(weaponSlot.weaponId));
  }

  destroy(): void {
    weaponStates.clear();
  }
}
