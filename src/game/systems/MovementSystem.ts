/**
 * Movement System
 *
 * Updates entity positions based on velocity and handles player movement input.
 * Priority: 20
 */

import { System, type UpdateContext } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs/EntityManager';
import { getWeaponData } from '../data';

export class MovementSystem extends System {
  readonly name = 'MovementSystem';
  readonly priority = 20;

  // Base player movement speed
  private readonly basePlayerSpeed = 200;

  update(entityManager: EntityManager, context: UpdateContext): void {
    const dt = context.dt;

    // Process all entities with transform and velocity
    const entities = entityManager.query(['transform', 'velocity']);

    for (const entity of entities) {
      const transform = entity.getComponent<'transform'>('transform');
      const velocity = entity.getComponent<'velocity'>('velocity');
      if (!transform || !velocity) continue;

      // Handle player movement input
      const player = entity.getComponent<'player'>('player');
      if (player) {
        const moveIntentX = (player as unknown as Record<string, number>).moveIntentX ?? 0;
        const moveIntentY = (player as unknown as Record<string, number>).moveIntentY ?? 0;

        // Apply weapon speed multiplier
        const weaponData = getWeaponData(player.weaponId);
        const speedMultiplier = weaponData.moveSpeedMultiplier;

        // Calculate target velocity
        const targetVx = moveIntentX * this.basePlayerSpeed * speedMultiplier;
        const targetVy = moveIntentY * this.basePlayerSpeed * speedMultiplier;

        // Apply speed boost if active
        let finalSpeed = 1.0;
        if (player.speedBonusTimer > 0) {
          finalSpeed *= 1.5;
        }

        // Set velocity
        velocity.x = targetVx * finalSpeed;
        velocity.y = targetVy * finalSpeed;
      }

      // Handle creature AI movement
      const creature = entity.getComponent<'creature'>('creature');
      if (creature) {
        // Creature velocity is set by AISystem
        // Just ensure it doesn't exceed max speed
        const speed = Math.sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
        if (speed > velocity.maxSpeed && speed > 0) {
          velocity.x = (velocity.x / speed) * velocity.maxSpeed;
          velocity.y = (velocity.y / speed) * velocity.maxSpeed;
        }
      }

      // Update position
      transform.x += velocity.x * dt;
      transform.y += velocity.y * dt;
    }
  }
}
