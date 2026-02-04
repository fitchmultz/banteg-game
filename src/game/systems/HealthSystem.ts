/**
 * Health System
 *
 * Processes damage events, handles death, manages health regeneration.
 * Applies perk effects on damage: shield on hit, time slow, regression bullets.
 * Priority: 70
 */

import type { EntityManager } from '../../core/ecs';
import { System, type UpdateContext } from '../../core/ecs/System';
import type { ParticleSystem } from '../../engine/ParticleSystem';
import type { EntityId } from '../../types';
import { AiMode, type CreatureTypeId } from '../../types';
import { createCorpse, createLifetime, createSprite, createTransform } from '../components';
import { getCreatureData, getWeaponData } from '../data';
import { BonusFactory } from '../entities';
import { CREATURE_TEXTURES } from '../entities/CreatureFactory';
import type { SettingsManager } from '../settings/SettingsManager';
import { damageEvents } from './CollisionSystem';
import type { PerkSystem } from './PerkSystem';

// Track entity health states
interface HealthState {
  hitFlashTimer: number;
  isDead: boolean;
  // Track time-slow cooldown to prevent spam
  lastTimeSlowTrigger: number;
  // Track last damage source for kill attribution
  lastDamageSourceId: EntityId | null;
}

const healthStates = new Map<EntityId, HealthState>();

export interface GameStateCallbacks {
  onPlayerDeath?: (entityId: EntityId) => void;
  onCreatureDeath?: (
    creatureTypeId: number,
    position: { x: number; y: number },
    isBoss?: boolean
  ) => void;
  onScoreChange?: (score: number) => void;
  onXPChange?: (xp: number) => void;
}

export class HealthSystem extends System {
  readonly name = 'HealthSystem';
  readonly priority = 70;

  private entityManager: EntityManager;
  private callbacks: GameStateCallbacks;
  private perkSystem: PerkSystem | null = null;
  private particleSystem: ParticleSystem | null = null;
  private settingsManager: SettingsManager | null = null;
  private score = 0;

  // Hit flash duration
  private readonly hitFlashDuration = 0.2;
  // Time slow cooldown (seconds)
  private readonly timeSlowCooldown = 2.0;

  constructor(
    entityManager: EntityManager,
    callbacks: GameStateCallbacks = {},
    perkSystem?: PerkSystem,
    particleSystem?: ParticleSystem,
    settingsManager?: SettingsManager
  ) {
    super();
    this.entityManager = entityManager;
    this.callbacks = callbacks;
    if (perkSystem) {
      this.perkSystem = perkSystem;
    }
    if (particleSystem) {
      this.particleSystem = particleSystem;
    }
    if (settingsManager) {
      this.settingsManager = settingsManager;
    }
  }

  /**
   * Set the perk system for accessing perk effects
   */
  setPerkSystem(perkSystem: PerkSystem): void {
    this.perkSystem = perkSystem;
  }

  /**
   * Set the particle system for emitting effects
   */
  setParticleSystem(particleSystem: ParticleSystem): void {
    this.particleSystem = particleSystem;
  }

  /**
   * Set the settings manager for accessing game settings
   */
  setSettingsManager(settingsManager: SettingsManager): void {
    this.settingsManager = settingsManager;
  }

  update(_entityManager: EntityManager, context: UpdateContext): void {
    const dt = context.dt;
    const gameTime = context.gameTime;

    // Process damage events from CollisionSystem
    for (const event of damageEvents) {
      this.applyDamage(event, gameTime, context);
    }

    // Update all entities with health
    const players = this.entityManager.query(['player']);
    const creatures = this.entityManager.query(['creature']);

    // Update player health states
    for (const entity of players) {
      const player = entity.getComponent<'player'>('player');
      if (!player) continue;
      const state = this.getOrCreateHealthState(entity.id);

      // Handle hit flash
      if (state.hitFlashTimer > 0) {
        state.hitFlashTimer -= dt;
      }

      // Handle death
      if (player.health <= 0 && !state.isDead) {
        state.isDead = true;
        this.callbacks.onPlayerDeath?.(entity.id);
      }

      // Note: Health regeneration is handled by PerkSystem.update()
      // to avoid duplicate logic and ensure consistent perk-based regen
    }

    // Update creature health states
    for (const entity of creatures) {
      const creature = entity.getComponent<'creature'>('creature');
      if (!creature) continue;
      const transform = entity.getComponent<'transform'>('transform');
      const state = this.getOrCreateHealthState(entity.id);

      // Handle hit flash
      if (state.hitFlashTimer > 0) {
        state.hitFlashTimer -= dt;
      }

      // Handle death
      if (creature.health <= 0 && !state.isDead) {
        state.isDead = true;
        creature.aiMode = AiMode.DEAD;

        if (transform) {
          this.handleCreatureDeath(entity.id, creature, transform, state.lastDamageSourceId);
        }
      }
    }
  }

  private applyDamage(
    event: {
      targetId: EntityId;
      sourceId: EntityId;
      damage: number;
      isFireDamage: boolean;
    },
    gameTime: number,
    context: UpdateContext
  ): void {
    const entity = this.entityManager.getEntity(event.targetId);
    if (!entity) return;

    const player = entity.getComponent<'player'>('player');
    const creature = entity.getComponent<'creature'>('creature');
    const state = this.getOrCreateHealthState(event.targetId);

    if (state.isDead) return;

    let finalDamage = event.damage;

    // Apply fire damage multiplier if target is creature and damage is fire
    if (creature && event.isFireDamage && this.perkSystem) {
      // Check if source player has Pyromaniac
      const sourceHasPyromaniac = this.perkSystem.hasFireBullets(event.sourceId);
      if (sourceHasPyromaniac) {
        finalDamage *= 1.25; // 25% more fire damage
      }
    }

    // Check for shield on player
    if (player && player.shieldTimer > 0) {
      // Shield absorbs damage
      return;
    }

    // Check for invulnerability (god mode)
    if (player?.invulnerable) {
      return;
    }

    // Apply damage
    if (player) {
      player.health -= finalDamage;
      state.hitFlashTimer = this.hitFlashDuration;

      // Apply shield on hit (Breathing Room perk) if player is still alive
      if (player.health > 0 && this.perkSystem?.hasShieldOnHit(event.targetId)) {
        // Grant brief shield (3 seconds)
        player.shieldTimer = Math.max(player.shieldTimer, 3);
      }

      // Apply time slow on hit (Reflex Boosted perk) with cooldown
      if (this.perkSystem?.hasTimeSlowOnHit(event.targetId)) {
        const timeSinceLastTrigger = gameTime - state.lastTimeSlowTrigger;
        if (timeSinceLastTrigger >= this.timeSlowCooldown) {
          // Slow time to 0.3x for 2 seconds
          context.setTimeScale(0.3, 2);
          state.lastTimeSlowTrigger = gameTime;
        }
      }
    } else if (creature) {
      creature.health -= finalDamage;
      state.hitFlashTimer = this.hitFlashDuration;
      // Track damage source for kill attribution
      state.lastDamageSourceId = event.sourceId;

      // Apply regression bullets (ammo refund on hit)
      if (this.perkSystem?.hasRegressionBullets(event.sourceId)) {
        this.refundAmmoToPlayer(event.sourceId);
      }
    }
  }

  /**
   * Refund 1 ammo to the source player (for Regression Bullets perk)
   * Prefers clip refill, then reserve ammo
   */
  private refundAmmoToPlayer(sourceId: EntityId): void {
    const sourceEntity = this.entityManager.getEntity(sourceId);
    if (!sourceEntity) return;

    const player = sourceEntity.getComponent<'player'>('player');
    if (!player) return;

    const weaponData = getWeaponData(player.currentWeapon.weaponId);
    const clipBonus = this.perkSystem?.getClipSizeBonus(sourceId) ?? 0;
    const maxClipSize = weaponData.clipSize + clipBonus;

    // Try to refund to clip first (up to max clip size)
    if (player.currentWeapon.clipSize < maxClipSize) {
      player.currentWeapon.clipSize++;
    } else {
      // Clip is full, refund to reserve ammo
      player.currentWeapon.ammo++;
    }
  }

  private handleCreatureDeath(
    entityId: EntityId,
    creature: {
      creatureTypeId: CreatureTypeId;
      rewardValue: number;
      tint: { r: number; g: number; b: number; a: number };
      size: number;
      flags: number;
    },
    transform: { x: number; y: number },
    killerId: EntityId | null = null
  ): void {
    const data = getCreatureData(creature.creatureTypeId);

    // Award score and XP
    this.score += data.scoreValue;
    this.callbacks.onScoreChange?.(this.score);
    this.callbacks.onXPChange?.(creature.rewardValue);

    // Spawn bonus with some probability
    const bonusChance = 0.15; // 15% chance
    if (Math.random() < bonusChance) {
      BonusFactory.createRandom(this.entityManager, transform.x, transform.y);
    }

    // Get gore intensity from settings and Bloody Mess perk
    const goreSetting = this.settingsManager?.getConfig().goreIntensity ?? 1;
    // Use killer's Bloody Mess perk if available, otherwise default to 1x
    const bloodyMessRank =
      killerId !== null ? (this.perkSystem?.getGoreIntensity(killerId) ?? 1) : 1;
    const intensityMultiplier = bloodyMessRank; // 1x, 2x, 3x, 4x based on rank
    const totalIntensity = goreSetting * intensityMultiplier;

    // Emit blood particles if gore is enabled
    if (totalIntensity > 0 && this.particleSystem) {
      this.particleSystem.emitBloodSplatter(transform.x, transform.y, 0, totalIntensity);
    }

    // Create corpse entity with the creature's original texture
    const corpseEntity = this.entityManager.createEntity();
    const textureName = CREATURE_TEXTURES[creature.creatureTypeId] ?? 'zombie';
    corpseEntity.addComponent(
      createTransform(transform.x, transform.y, Math.random() * Math.PI * 2)
    );
    corpseEntity.addComponent(createSprite(textureName, 32, 32));
    corpseEntity.addComponent(
      createCorpse(
        creature.creatureTypeId,
        creature.tint,
        creature.size,
        Math.random() * Math.PI * 2
      )
    );
    corpseEntity.addComponent(createLifetime(30)); // 30 second lifetime

    // Notify callback - pass boss status
    const isBoss = (creature.flags & 0x02) !== 0; // CreatureFlags.BOSS = 1 << 1 = 0x02
    this.callbacks.onCreatureDeath?.(creature.creatureTypeId, transform, isBoss);

    // Destroy original creature entity
    this.entityManager.destroyEntity(entityId);
  }

  private getOrCreateHealthState(entityId: EntityId): HealthState {
    let state = healthStates.get(entityId);
    if (!state) {
      state = {
        hitFlashTimer: 0,
        isDead: false,
        lastTimeSlowTrigger: -999,
        lastDamageSourceId: null,
      };
      healthStates.set(entityId, state);
    }
    return state;
  }

  getScore(): number {
    return this.score;
  }

  setScore(score: number): void {
    this.score = score;
  }

  destroy(): void {
    healthStates.clear();
  }
}
