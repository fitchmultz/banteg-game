/**
 * Jinxed Handler
 *
 * Handles the Jinxed gamble perk effects.
 */

import type { EntityManager } from '../../../../core/ecs';
import type { EntityId } from '../../../../types';
import type { Player } from '../../../components';
import type { JinxState } from '../types.js';

export class JinxedHandler {
  private jinxStates: Map<EntityId, JinxState> = new Map();

  constructor(private entityManager: EntityManager) {}

  initializeJinx(entityId: EntityId, gameTime: number): void {
    this.jinxStates.set(entityId, {
      nextTriggerTime: gameTime + 2 + Math.random() * 2,
      interval: 2 + Math.random() * 2,
    });
  }

  /**
   * Update jinxed perk effects
   */
  updateJinxed(
    entityId: EntityId,
    player: Player,
    gameTime: number,
    _dt: number,
    hasJinxed: boolean
  ): void {
    if (!hasJinxed) {
      // Clean up jinx state if perk was removed
      this.jinxStates.delete(entityId);
      return;
    }

    let jinxState = this.jinxStates.get(entityId);
    if (!jinxState) {
      // Initialize jinx state
      jinxState = {
        nextTriggerTime: gameTime + 2 + Math.random() * 2,
        interval: 2 + Math.random() * 2,
      };
      this.jinxStates.set(entityId, jinxState);
    }

    // Check if it's time for a jinx effect
    if (gameTime >= jinxState.nextTriggerTime) {
      this.triggerJinxEffect(player);

      // Schedule next trigger
      jinxState.interval = 2 + Math.random() * 2;
      jinxState.nextTriggerTime = gameTime + jinxState.interval;
    }
  }

  /**
   * Trigger a jinx effect (random helpful or harmful outcome)
   */
  private triggerJinxEffect(player: Player): void {
    // 10% chance to damage player (downside)
    if (Math.random() < 0.1) {
      player.health = Math.max(0, player.health - 5);
    }

    // Kill a random creature (upside)
    const creatures = this.entityManager.query(['creature']);
    if (creatures.length > 0) {
      const randomIndex = Math.floor(Math.random() * creatures.length);
      const targetCreature = creatures[randomIndex]?.getComponent<'creature'>('creature');
      if (targetCreature) {
        targetCreature.health = 0;
      }
    }
  }

  cleanupEntity(entityId: EntityId): void {
    this.jinxStates.delete(entityId);
  }
}
