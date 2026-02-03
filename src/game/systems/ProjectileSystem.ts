/**
 * Projectile System
 *
 * Updates projectile positions, handles lifetime, and applies special behaviors.
 * Priority: 50
 */

import { System, type UpdateContext } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs/EntityManager';

export class ProjectileSystem extends System {
  readonly name = 'ProjectileSystem';
  readonly priority = 50;

  private entityManager: EntityManager;

  constructor(entityManager: EntityManager) {
    super();
    this.entityManager = entityManager;
  }

  update(_entityManager: EntityManager, context: UpdateContext): void {
    const dt = context.dt;

    // Query all projectiles
    const projectiles = this.entityManager.query([
      'projectile',
      'transform',
      'velocity',
      'lifetime',
    ]);

    for (const entity of projectiles) {
      const projectile = entity.getComponent<'projectile'>('projectile');
      const transform = entity.getComponent<'transform'>('transform');
      const velocity = entity.getComponent<'velocity'>('velocity');
      const lifetime = entity.getComponent<'lifetime'>('lifetime');
      if (!projectile || !transform || !velocity || !lifetime) continue;

      // Update lifetime
      lifetime.remaining -= dt;

      // Mark for destruction if lifetime expired
      if (lifetime.remaining <= 0) {
        this.entityManager.destroyEntity(entity.id);
        continue;
      }

      // Update rotation to match velocity direction
      if (velocity.x !== 0 || velocity.y !== 0) {
        transform.rotation = Math.atan2(velocity.y, velocity.x);
      }

      // Handle special projectile behaviors based on type
      // (Homing, gravity effects, etc. would be implemented here)
    }
  }
}
