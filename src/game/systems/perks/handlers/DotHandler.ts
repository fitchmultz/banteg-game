/**
 * Damage over Time Handler
 *
 * Handles uranium and poison DoT effects on creatures.
 */

import type { EntityManager } from '../../../../core/ecs';
import type { EntityId } from '../../../../types';
import type { DotEffect } from '../types.js';

export class DotHandler {
  private dotEffects: Map<EntityId, DotEffect[]> = new Map();

  constructor(private entityManager: EntityManager) {}

  /**
   * Apply a DoT effect to a creature
   * Called by CollisionSystem when bullets with uranium/poison hit
   */
  applyDotEffect(
    playerEntityId: EntityId,
    creatureId: EntityId,
    type: 'uranium' | 'poison',
    damagePerTick: number,
    duration: number
  ): void {
    const effects = this.dotEffects.get(playerEntityId) ?? [];

    // Check if creature already has this type of DoT
    const existingIndex = effects.findIndex((e) => e.creatureId === creatureId && e.type === type);

    if (existingIndex >= 0) {
      // Refresh duration (stacking behavior)
      const existingEffect = effects[existingIndex];
      if (existingEffect) {
        existingEffect.remainingDuration = duration;
      }
    } else {
      // Add new DoT
      effects.push({
        creatureId,
        damagePerTick,
        remainingDuration: duration,
        tickInterval: 0.5, // Tick every 0.5 seconds
        timeUntilNextTick: 0,
        type,
      });
    }

    this.dotEffects.set(playerEntityId, effects);
  }

  /**
   * Update all active DoT effects
   */
  updateDotEffects(dt: number): void {
    for (const [playerId, effects] of this.dotEffects) {
      const remainingEffects: DotEffect[] = [];

      for (const effect of effects) {
        effect.timeUntilNextTick -= dt;
        effect.remainingDuration -= dt;

        if (effect.timeUntilNextTick <= 0) {
          // Apply damage tick
          const creatureEntity = this.entityManager.getEntity(effect.creatureId);
          if (creatureEntity) {
            const creature = creatureEntity.getComponent<'creature'>('creature');
            if (creature && creature.health > 0) {
              creature.health -= effect.damagePerTick;
            }
          }
          effect.timeUntilNextTick = effect.tickInterval;
        }

        // Keep effect if duration remains and creature is alive
        if (effect.remainingDuration > 0) {
          const creatureEntity = this.entityManager.getEntity(effect.creatureId);
          if (creatureEntity) {
            const creature = creatureEntity.getComponent<'creature'>('creature');
            if (creature && creature.health > 0) {
              remainingEffects.push(effect);
            }
          }
        }
      }

      if (remainingEffects.length === 0) {
        this.dotEffects.delete(playerId);
      } else {
        this.dotEffects.set(playerId, remainingEffects);
      }
    }
  }

  cleanupEntity(entityId: EntityId): void {
    this.dotEffects.delete(entityId);
  }
}
