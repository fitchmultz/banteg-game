/**
 * Effect System
 *
 * Updates and removes expired effects (shields, fire bullets, speed boosts).
 * Priority: 100
 */

import type { EntityManager } from '../../core/ecs/EntityManager';
import { System, type UpdateContext } from '../../core/ecs/System';

export class EffectSystem extends System {
  readonly name = 'EffectSystem';
  readonly priority = 100;

  private entityManager: EntityManager;

  constructor(entityManager: EntityManager) {
    super();
    this.entityManager = entityManager;
  }

  update(_entityManager: EntityManager, context: UpdateContext): void {
    // Use real-time so slow-motion doesn't unintentionally extend timers.
    const dt = context.unscaledDt;

    // Update player effect timers
    const players = this.entityManager.query(['player']);

    for (const entity of players) {
      const player = entity.getComponent<'player'>('player');
      if (!player) continue;

      const dec = (t: number): number => (t > 0 ? Math.max(0, t - dt) : 0);

      player.shieldTimer = dec(player.shieldTimer);
      player.fireBulletsTimer = dec(player.fireBulletsTimer);
      player.speedBonusTimer = dec(player.speedBonusTimer);

      player.freezeTimer = dec(player.freezeTimer);
      player.energizerTimer = dec(player.energizerTimer);
      player.reflexBoostTimer = dec(player.reflexBoostTimer);
    }

    // Update effect components on entities
    const effects = this.entityManager.query(['effect']);
    for (const entity of effects) {
      const effect = entity.getComponent<'effect'>('effect');
      if (!effect) continue;

      effect.elapsed += dt;

      // Remove effect if expired
      if (effect.elapsed >= effect.duration) {
        entity.removeComponent('effect');

        // If entity has no more components, destroy it
        if (entity.componentCount === 0) {
          this.entityManager.destroyEntity(entity.id);
        }
      }
    }
  }
}
