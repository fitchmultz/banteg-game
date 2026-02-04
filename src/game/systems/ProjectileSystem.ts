/**
 * Projectile System
 *
 * Updates projectile positions, handles lifetime, and applies special behaviors.
 * Supports homing projectiles that track enemies.
 * Priority: 50
 */

import { System, type UpdateContext } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs/EntityManager';
import { getProjectileData } from '../data';

// Homing turn rate in radians per second
const HOMING_TURN_RATE = Math.PI * 2; // 360 degrees per second

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

    // Query enemies once for homing calculations
    const enemies = this.entityManager.query(['creature', 'transform']);

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

      // Handle homing behavior
      const projectileData = getProjectileData(projectile.projectileTypeId);
      if (projectileData.homing && enemies.length > 0) {
        this.applyHoming(transform, velocity, enemies, dt);
      }

      // Update rotation to match velocity direction
      if (velocity.x !== 0 || velocity.y !== 0) {
        transform.rotation = Math.atan2(velocity.y, velocity.x);
      }
    }
  }

  private applyHoming(
    transform: { x: number; y: number; rotation: number },
    velocity: { x: number; y: number; maxSpeed: number },
    enemies: Array<{
      getComponent<T extends 'transform'>(type: T): { x: number; y: number } | undefined;
    }>,
    dt: number
  ): void {
    // Find nearest enemy
    let nearestEnemy: { x: number; y: number } | null = null;
    let nearestDist = Number.POSITIVE_INFINITY;

    for (const enemy of enemies) {
      const enemyTransform = enemy.getComponent<'transform'>('transform');
      if (!enemyTransform) continue;

      const dx = enemyTransform.x - transform.x;
      const dy = enemyTransform.y - transform.y;
      const dist = dx * dx + dy * dy;

      if (dist < nearestDist) {
        nearestDist = dist;
        nearestEnemy = enemyTransform;
      }
    }

    if (!nearestEnemy) return;

    // Calculate desired direction to target
    const dx = nearestEnemy.x - transform.x;
    const dy = nearestEnemy.y - transform.y;
    const targetAngle = Math.atan2(dy, dx);

    // Calculate current velocity angle
    const currentSpeed = Math.sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
    if (currentSpeed === 0) return;

    const currentAngle = Math.atan2(velocity.y, velocity.x);

    // Calculate angle difference (shortest path)
    let angleDiff = targetAngle - currentAngle;
    while (angleDiff > Math.PI) angleDiff -= Math.PI * 2;
    while (angleDiff < -Math.PI) angleDiff += Math.PI * 2;

    // Apply turning limit
    const maxTurn = HOMING_TURN_RATE * dt;
    const turnAmount = Math.max(-maxTurn, Math.min(maxTurn, angleDiff));

    // Calculate new velocity direction
    const newAngle = currentAngle + turnAmount;

    // Update velocity while maintaining speed
    velocity.x = Math.cos(newAngle) * currentSpeed;
    velocity.y = Math.sin(newAngle) * currentSpeed;
  }
}
