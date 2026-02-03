/**
 * Lifetime System
 *
 * Destroys entities when their lifetime expires.
 * Priority: 150
 */

import { System, type UpdateContext } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs/EntityManager';

export class LifetimeSystem extends System {
  readonly name = 'LifetimeSystem';
  readonly priority = 150;

  private entityManager: EntityManager;

  constructor(entityManager: EntityManager) {
    super();
    this.entityManager = entityManager;
  }

  update(_entityManager: EntityManager, context: UpdateContext): void {
    const dt = context.dt;

    // Query all entities with lifetime
    const entities = this.entityManager.query(['lifetime']);

    for (const entity of entities) {
      const lifetime = entity.getComponent<'lifetime'>('lifetime');
      if (!lifetime) continue;

      lifetime.remaining -= dt;

      if (lifetime.remaining <= 0) {
        this.entityManager.destroyEntity(entity.id);
      }
    }
  }
}
