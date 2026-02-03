/**
 * Effect System
 *
 * Updates and removes expired effects (shields, fire bullets, speed boosts).
 * Priority: 100
 */


import { System, type UpdateContext } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs/EntityManager';

export class EffectSystem extends System {
  readonly name = 'EffectSystem';
  readonly priority = 100;

  private entityManager: EntityManager;

  constructor(entityManager: EntityManager) {
    super();
    this.entityManager = entityManager;
  }

  update(_entityManager: EntityManager, context: UpdateContext): void {
    const dt = context.dt;

    // Update player effect timers
    const players = this.entityManager.query(['player']);

    for (const entity of players) {
      const player = entity.getComponent<'player'>('player');
      if (!player) continue;

      // Update shield timer
      if (player.shieldTimer > 0) {
        player.shieldTimer -= dt;
        if (player.shieldTimer < 0) {
          player.shieldTimer = 0;
        }
      }

      // Update fire bullets timer
      if (player.fireBulletsTimer > 0) {
        player.fireBulletsTimer -= dt;
        if (player.fireBulletsTimer < 0) {
          player.fireBulletsTimer = 0;
        }
      }

      // Update speed bonus timer
      if (player.speedBonusTimer > 0) {
        player.speedBonusTimer -= dt;
        if (player.speedBonusTimer < 0) {
          player.speedBonusTimer = 0;
        }
      }
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
