/**
 * Health System
 *
 * Processes damage events, handles death, manages health regeneration.
 * Priority: 70
 */


import { System, type UpdateContext } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs';
import type { EntityId } from '../../types';
import { damageEvents } from './CollisionSystem';
import { BonusFactory } from '../entities';
import { getCreatureData } from '../data';
import { AiMode } from '../../types';

// Track entity health states
interface HealthState {
  hitFlashTimer: number;
  isDead: boolean;
}

const healthStates = new Map<EntityId, HealthState>();

export interface GameStateCallbacks {
  onPlayerDeath?: () => void;
  onCreatureDeath?: (creatureTypeId: number, position: { x: number; y: number }) => void;
  onScoreChange?: (score: number) => void;
  onXPChange?: (xp: number) => void;
}

export class HealthSystem extends System {
  readonly name = 'HealthSystem';
  readonly priority = 70;

  private entityManager: EntityManager;
  private callbacks: GameStateCallbacks;
  private score = 0;

  // Hit flash duration
  private readonly hitFlashDuration = 0.2;
  // Regeneration interval (seconds)
  private readonly regenInterval = 1.0;
  // Base regeneration amount per interval
  private readonly baseRegenAmount = 1;

  private regenAccumulator = 0;

  constructor(entityManager: EntityManager, callbacks: GameStateCallbacks = {}) {
    super();
    this.entityManager = entityManager;
    this.callbacks = callbacks;
  }

  update(_entityManager: EntityManager, context: UpdateContext): void {
    const dt = context.dt;

    // Process damage events from CollisionSystem
    for (const event of damageEvents) {
      this.applyDamage(event.targetId, event.damage);
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
        this.callbacks.onPlayerDeath?.();
      }

      // Handle regeneration
      if (player.health > 0 && player.health < player.maxHealth) {
        this.regenAccumulator += dt;
        if (this.regenAccumulator >= this.regenInterval) {
          this.regenAccumulator -= this.regenInterval;
          // Calculate regeneration amount based on perks
          let regenAmount = this.baseRegenAmount;
          const regenPerkCount = player.perkCounts.get(11) ?? 0; // REGENERATION
          const greaterRegenPerkCount = player.perkCounts.get(12) ?? 0; // GREATER_REGENERATION
          regenAmount += regenPerkCount * 2 + greaterRegenPerkCount * 5;

          player.health = Math.min(player.maxHealth, player.health + regenAmount);
        }
      }
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
          this.handleCreatureDeath(entity.id, creature, transform);
        }
      }
    }
  }

  private applyDamage(targetId: EntityId, damage: number): void {
    const entity = this.entityManager.getEntity(targetId);
    if (!entity) return;

    const player = entity.getComponent<'player'>('player');
    const creature = entity.getComponent<'creature'>('creature');
    const state = this.getOrCreateHealthState(targetId);

    if (state.isDead) return;

    // Check for shield
    if (player && player.shieldTimer > 0) {
      // Shield absorbs damage
      return;
    }

    // Apply damage
    if (player) {
      player.health -= damage;
      state.hitFlashTimer = this.hitFlashDuration;
    } else if (creature) {
      creature.health -= damage;
      state.hitFlashTimer = this.hitFlashDuration;
    }
  }

  private handleCreatureDeath(
    entityId: EntityId,
    creature: { creatureTypeId: number; rewardValue: number },
    transform: { x: number; y: number }
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

    // Notify callback
    this.callbacks.onCreatureDeath?.(creature.creatureTypeId, transform);

    // Destroy entity
    this.entityManager.destroyEntity(entityId);
  }

  private getOrCreateHealthState(entityId: EntityId): HealthState {
    let state = healthStates.get(entityId);
    if (!state) {
      state = { hitFlashTimer: 0, isDead: false };
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
