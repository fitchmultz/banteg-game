/**
 * Bonus System
 *
 * Handles bonus collection effects: health, ammo, speed, shields, etc.
 * Applies perk multipliers (bonus duration, ammo refill on pickup).
 * Priority: 90
 */

import type { EntityManager } from '../../core/ecs/EntityManager';
import { System, type UpdateContext } from '../../core/ecs/System';
import { BonusType, PerkId, ProjectileTypeId } from '../../types';
import { getWeaponData } from '../data';
import { collectEvents } from './CollisionSystem';
import type { PerkSystem } from './PerkSystem';
import { createProjectileEntity } from '../entities/ProjectileFactory';
import { setShockChainState, SHOCK_CHAIN_MAX_LINKS } from './ShockChainState';
import type { RenderSystem } from './RenderSystem';
import type { AudioManager } from '../../engine';
import { SAMPLES } from '../audio/catalog';

// Special owner ID for environmental/projectile damage (no XP/kill credit)
const ENVIRONMENTAL_OWNER_ID = -100;

export class BonusSystem extends System {
  readonly name = 'BonusSystem';
  readonly priority = 90;

  private entityManager: EntityManager;
  private perkSystem: PerkSystem | null = null;
  private renderSystem: RenderSystem | null = null;
  private audioManager: AudioManager | null = null;

  // Base effect durations (seconds)
  private readonly weaponPowerUpDuration = 10;
  private readonly speedBoostDuration = 10;
  private readonly shieldDuration = 15;
  private readonly fireBulletsDuration = 20;

  // Spawn guard - prevents certain bonuses from spawning during effects
  private static spawnGuard = false;

  constructor(
    entityManager: EntityManager,
    perkSystem?: PerkSystem,
    renderSystem?: RenderSystem,
    audioManager?: AudioManager
  ) {
    super();
    this.entityManager = entityManager;
    if (perkSystem) {
      this.perkSystem = perkSystem;
    }
    this.renderSystem = renderSystem ?? null;
    this.audioManager = audioManager ?? null;
  }

  /**
   * Set the render system for triggering visual effects
   */
  setRenderSystem(renderSystem: RenderSystem): void {
    this.renderSystem = renderSystem;
  }

  /**
   * Set the audio manager for playing SFX
   */
  setAudioManager(audioManager: AudioManager): void {
    this.audioManager = audioManager;
  }

  /**
   * Check if spawn guard is active (prevents certain bonus types from spawning)
   */
  static isSpawnGuardActive(): boolean {
    return BonusSystem.spawnGuard;
  }

  /**
   * Set the perk system for accessing perk multipliers
   */
  setPerkSystem(perkSystem: PerkSystem): void {
    this.perkSystem = perkSystem;
  }

  private readonly reflexTimeScale = 0.4;

  update(_entityManager: EntityManager, context: UpdateContext): void {
    // Process collect events from CollisionSystem
    for (const event of collectEvents) {
      const playerEntity = this.entityManager.getEntity(event.playerId);
      if (!playerEntity) continue;

      const player = playerEntity.getComponent<'player'>('player');
      if (!player) continue;

      this.applyBonusEffect(event.playerId, player, event.bonusType, event.value, context);
    }

    // Update existing bonuses (remove expired)
    const bonuses = this.entityManager.query(['bonus', 'lifetime']);
    for (const entity of bonuses) {
      const bonus = entity.getComponent<'bonus'>('bonus');
      const lifetime = entity.getComponent<'lifetime'>('lifetime');
      if (!bonus || !lifetime) continue;

      // Update lifetime (also tracked in LifetimeSystem, but we check here too)
      bonus.lifetime = lifetime.remaining;
    }
  }

  private applyBonusEffect(
    playerId: number,
    player: {
      health: number;
      maxHealth: number;
      experience: number;
      currentWeapon: { weaponId: number; clipSize: number; ammo: number };
      alternateWeapon: { weaponId: number; clipSize: number; ammo: number };
      shieldTimer: number;
      fireBulletsTimer: number;
      speedBonusTimer: number;

      // New timers
      freezeTimer: number;
      energizerTimer: number;
      reflexBoostTimer: number;

      perkCounts: Map<PerkId, number>;
    },
    bonusType: number,
    value: number,
    context: UpdateContext
  ): void {
    // Get bonus duration multiplier from perks
    const durationMultiplier = this.perkSystem?.getBonusDurationMultiplier(playerId) ?? 1;

    // Get Pyrokinetic bonus for fire bullets (adds 50% duration)
    const hasPyrokinetic = player.perkCounts.has(PerkId.PYROKINETIC);
    const pyrokineticMultiplier = hasPyrokinetic ? 1.5 : 1;

    switch (bonusType) {
      case BonusType.MEDIKIT:
        player.health = Math.min(player.maxHealth, player.health + value);
        break;

      case BonusType.WEAPON: {
        // Add ammo to current weapon
        const weaponData = getWeaponData(player.currentWeapon.weaponId);
        const ammoToAdd = Math.floor(weaponData.clipSize * 0.5);
        player.currentWeapon.ammo += ammoToAdd;

        // Apply Ammo Maniac clip refill if perk is active
        if (this.perkSystem?.hasAmmoRefillOnPickup(playerId)) {
          this.perkSystem.refillWeaponClips(
            player as Parameters<PerkSystem['refillWeaponClips']>[0]
          );
        }
        break;
      }

      case BonusType.WEAPON_POWER_UP:
        // Increase weapon damage temporarily
        // (Applied in WeaponSystem when firing)
        player.fireBulletsTimer = Math.max(
          player.fireBulletsTimer,
          this.weaponPowerUpDuration * durationMultiplier
        );
        break;

      case BonusType.SPEED:
        player.speedBonusTimer = Math.max(
          player.speedBonusTimer,
          this.speedBoostDuration * durationMultiplier
        );
        break;

      case BonusType.SHIELD:
        player.shieldTimer = Math.max(player.shieldTimer, this.shieldDuration * durationMultiplier);
        break;

      case BonusType.FIRE_BULLETS:
        // Apply both general duration multiplier AND Pyrokinetic bonus
        player.fireBulletsTimer = Math.max(
          player.fireBulletsTimer,
          this.fireBulletsDuration * durationMultiplier * pyrokineticMultiplier
        );
        break;

      case BonusType.DOUBLE_EXPERIENCE:
        // Experience multiplier would be tracked in a separate system
        // For now, just grant immediate XP
        // (XP is tracked in HealthSystem)
        break;

      case BonusType.FREEZE: {
        const durationSeconds = value * durationMultiplier;
        player.freezeTimer = Math.max(player.freezeTimer, durationSeconds);
        break;
      }

      case BonusType.ENERGIZER: {
        const durationSeconds = value * durationMultiplier;
        player.energizerTimer = Math.max(player.energizerTimer, durationSeconds);
        break;
      }

      case BonusType.REFLEX_BOOST: {
        const durationSeconds = value * durationMultiplier;
        player.reflexBoostTimer = Math.max(player.reflexBoostTimer, durationSeconds);

        // Ensure the time-scale effect is never shortened by a smaller pickup.
        context.setTimeScale(this.reflexTimeScale, player.reflexBoostTimer);
        break;
      }

      case BonusType.POINTS: {
        // Grant immediate experience points
        player.experience += value;
        break;
      }

      case BonusType.ATOMIC: {
        this.applyAtomicEffect(playerId);
        break;
      }

      case BonusType.SHOCK_CHAIN: {
        this.applyShockChainEffect(playerId);
        break;
      }

      case BonusType.FIREBLAST: {
        this.applyFireblastEffect(playerId);
        break;
      }
    }
  }

  /**
   * ATOMIC (Nuke) bonus effect
   * Spawns random projectiles + deals radial damage to all enemies within 256 units
   * Based on decompiled bonus_apply lines 208-256
   */
  private applyAtomicEffect(playerId: number): void {
    const playerEntity = this.entityManager.getEntity(playerId);
    if (!playerEntity) return;

    const transform = playerEntity.getComponent<'transform'>('transform');
    if (!transform) return;

    const x = transform.x;
    const y = transform.y;

    // Set spawn guard to prevent overlapping effects
    BonusSystem.spawnGuard = true;

    // Spawn 4-7 random pistol projectiles (decompiled: (rand & 3) + 4)
    const pistolCount = 4 + Math.floor(Math.random() * 4);
    for (let i = 0; i < pistolCount; i++) {
      // Random angle: decompiled uses (rand % 0x274) * 0.01 = 0-628 * 0.01 = 0-6.28 radians
      const angle = Math.random() * 628 * 0.01;
      const projectile = createProjectileEntity(
        this.entityManager,
        ProjectileTypeId.PISTOL,
        x,
        y,
        angle,
        ENVIRONMENTAL_OWNER_ID,
        { damage: 15 }
      );
      // Apply random speed variation: decompiled uses ((rand % 0x32) * 0.01 + 0.5) = 0.5-1.0x
      const velocity = projectile.getComponent<'velocity'>('velocity');
      if (velocity) {
        const speedScale = 0.5 + Math.random() * 0.5;
        velocity.x *= speedScale;
        velocity.y *= speedScale;
      }
    }

    // Spawn 2 gauss gun projectiles
    for (let i = 0; i < 2; i++) {
      const angle = Math.random() * 628 * 0.01;
      createProjectileEntity(
        this.entityManager,
        ProjectileTypeId.GAUSS_GUN,
        x,
        y,
        angle,
        ENVIRONMENTAL_OWNER_ID,
        { damage: 150 }
      );
    }

    // Deal radial damage to all enemies within 256 units
    // Decompiled: damage = (256 - distance) * 5
    const NUKE_RADIUS = 256;
    const enemies = this.entityManager.query(['creature', 'transform']);
    for (const enemy of enemies) {
      const creature = enemy.getComponent<'creature'>('creature');
      const enemyTransform = enemy.getComponent<'transform'>('transform');
      if (!creature || !enemyTransform) continue;

      const dx = enemyTransform.x - x;
      const dy = enemyTransform.y - y;
      const distance = Math.sqrt(dx * dx + dy * dy);

      if (distance <= NUKE_RADIUS) {
        // Damage = (256 - distance) * 5, max 1280 at center
        const damage = (NUKE_RADIUS - distance) * 5;
        creature.health -= damage;
      }
    }

    // Trigger camera shake (20 pulses, ~0.2s timer)
    // Decompiled: camera_shake_pulses = 0x14 (20), _camera_shake_timer = 0x3e4ccccd (~0.2s)
    if (this.renderSystem) {
      this.renderSystem.shake(20, 0.2);
    }

    // Spawn explosion burst particle effect
    // Decompiled: effect_spawn_explosion_burst(pfVar8, 1.0)
    const particleSystem = this.renderSystem?.getParticleSystem();
    if (particleSystem) {
      particleSystem.emitExplosion(x, y, 30, { r: 1, g: 0.5, b: 0.2, a: 1 }, 1.5);
    }

    // Play sfx_explosion_large and sfx_shockwave
    // Decompiled lines 254-255: sfx_play_panned(sfx_explosion_large); sfx_play_panned(sfx_shockwave);
    if (this.audioManager) {
      this.audioManager.playSample(SAMPLES.EXPLOSION_LARGE);
      this.audioManager.playSample(SAMPLES.SHOCKWAVE);
    }

    // Release spawn guard after effect completes
    BonusSystem.spawnGuard = false;
  }

  /**
   * SHOCK_CHAIN bonus effect
   * Finds nearest enemy and spawns ion rifle projectile toward them
   * Based on decompiled bonus_apply lines 148-167
   */
  private applyShockChainEffect(playerId: number): void {
    const playerEntity = this.entityManager.getEntity(playerId);
    if (!playerEntity) return;

    const transform = playerEntity.getComponent<'transform'>('transform');
    if (!transform) return;

    const x = transform.x;
    const y = transform.y;

    // Set spawn guard
    BonusSystem.spawnGuard = true;

    // Find nearest enemy
    const enemies = this.entityManager.query(['creature', 'transform']);
    let nearestEnemy: { x: number; y: number } | null = null;
    let nearestDistSq = Number.POSITIVE_INFINITY;

    for (const enemy of enemies) {
      const enemyTransform = enemy.getComponent<'transform'>('transform');
      if (!enemyTransform) continue;

      const dx = enemyTransform.x - x;
      const dy = enemyTransform.y - y;
      const distSq = dx * dx + dy * dy;

      if (distSq < nearestDistSq) {
        nearestDistSq = distSq;
        nearestEnemy = enemyTransform;
      }
    }

    if (nearestEnemy) {
      // Calculate angle to nearest enemy
      const dx = nearestEnemy.x - x;
      const dy = nearestEnemy.y - y;
      const angle = Math.atan2(dy, dx);

      // Spawn ion rifle projectile toward enemy
      // Decompiled: angle - π/2 - π (coordinate system adjustment)
      const adjustedAngle = angle - Math.PI / 2 - Math.PI;

      const projectile = createProjectileEntity(
        this.entityManager,
        ProjectileTypeId.ION_RIFLE,
        x,
        y,
        adjustedAngle,
        ENVIRONMENTAL_OWNER_ID,
        { damage: 30 }
      );

      // Initialize shock chain state for chain continuation
      const projComponent = projectile.getComponent<'projectile'>('projectile');
      if (projComponent) {
        projComponent.isShockChainActive = true;
        projComponent.shockChainLinksLeft = SHOCK_CHAIN_MAX_LINKS;
      }

      // Set global shock chain state (CollisionSystem will use this)
      setShockChainState(projectile.id, SHOCK_CHAIN_MAX_LINKS);

      // Play sfx_shock_hit_01
      // Decompiled line 166: sfx_play_panned(sfx_shock_hit_01);
      if (this.audioManager) {
        this.audioManager.playSample(SAMPLES.SHOCK_HIT);
      }
    }

    // Release spawn guard
    BonusSystem.spawnGuard = false;
  }

  /**
   * FIREBLAST bonus effect
   * Spawns 16 plasma rifle projectiles in radial pattern (22.5 degree increments)
   * Based on decompiled bonus_apply lines 168-184
   */
  private applyFireblastEffect(playerId: number): void {
    const playerEntity = this.entityManager.getEntity(playerId);
    if (!playerEntity) return;

    const transform = playerEntity.getComponent<'transform'>('transform');
    if (!transform) return;

    const x = transform.x;
    const y = transform.y;

    // Set spawn guard
    BonusSystem.spawnGuard = true;

    // Spawn 16 plasma rifle projectiles in radial pattern
    // 0.3926991 radians = 22.5 degrees (360/16)
    const PROJECTILE_COUNT = 16;
    const ANGLE_INCREMENT = (Math.PI * 2) / PROJECTILE_COUNT;

    for (let i = 0; i < PROJECTILE_COUNT; i++) {
      const angle = i * ANGLE_INCREMENT;
      createProjectileEntity(
        this.entityManager,
        ProjectileTypeId.PLASMA_RIFLE,
        x,
        y,
        angle,
        ENVIRONMENTAL_OWNER_ID,
        { damage: 25 }
      );
    }

    // Release spawn guard
    BonusSystem.spawnGuard = false;

    // Play sfx_explosion_medium
    // Decompiled line 183: sfx_play_panned(sfx_explosion_medium);
    if (this.audioManager) {
      this.audioManager.playSample(SAMPLES.EXPLOSION_MEDIUM);
    }
  }
}
