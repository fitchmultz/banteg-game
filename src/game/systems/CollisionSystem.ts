/**
 * Collision System
 *
 * Handles collisions between entities: projectile-enemy, player-enemy, player-bonus.
 * Uses circle-based collision detection.
 * Priority: 60
 */


import { System } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs';
import type { EntityId } from '../../types';
import { CollisionLayer } from '../components';

export interface DamageEvent {
  targetId: EntityId;
  sourceId: EntityId;
  damage: number;
  isFireDamage: boolean;
}

export interface CollectEvent {
  playerId: EntityId;
  bonusId: EntityId;
  bonusType: number;
  value: number;
}

// Event queues processed by other systems
export const damageEvents: DamageEvent[] = [];
export const collectEvents: CollectEvent[] = [];

export class CollisionSystem extends System {
  readonly name = 'CollisionSystem';
  readonly priority = 60;

  private entityManager: EntityManager;

  constructor(entityManager: EntityManager) {
    super();
    this.entityManager = entityManager;
  }

  update(): void {
    // Clear previous frame's events
    damageEvents.length = 0;
    collectEvents.length = 0;

    // Get entities by layer
    const projectiles = this.entityManager.query(['projectile', 'transform', 'collider']);
    const enemies = this.entityManager.query(['creature', 'transform', 'collider']);
    const players = this.entityManager.query(['player', 'transform', 'collider']);
    const bonuses = this.entityManager.query(['bonus', 'transform', 'collider']);

    // Projectile vs Enemy collisions
    for (const projectile of projectiles) {
      const pCollider = projectile.getComponent<'collider'>('collider');
      if (!pCollider) continue;
      
      // Only check player projectiles against enemies
      if (pCollider.layer !== CollisionLayer.PROJECTILE_PLAYER) continue;

      const pTransform = projectile.getComponent<'transform'>('transform');
      const pData = projectile.getComponent<'projectile'>('projectile');
      if (!pTransform || !pData) continue;

      for (const enemy of enemies) {
        const eCollider = enemy.getComponent<'collider'>('collider');
        const eTransform = enemy.getComponent<'transform'>('transform');
        if (!eCollider || !eTransform) continue;

        if (this.checkCollision(pTransform, pCollider.radius, eTransform, eCollider.radius)) {
          // Queue damage event
          damageEvents.push({
            targetId: enemy.id,
            sourceId: pData.ownerId,
            damage: pData.damage,
            isFireDamage: false, // TODO: Check projectile type
          });

          // Handle piercing
          if (pData.pierceCount > 0) {
            pData.pierceCount--;
          } else {
            // Destroy projectile
            this.entityManager.destroyEntity(projectile.id);
          }

          break; // Projectile can only hit one enemy per frame (unless piercing)
        }
      }
    }

    // Player vs Enemy collisions (contact damage)
    for (const player of players) {
      const pTransform = player.getComponent<'transform'>('transform');
      const pCollider = player.getComponent<'collider'>('collider');
      if (!pTransform || !pCollider) continue;

      for (const enemy of enemies) {
        const eTransform = enemy.getComponent<'transform'>('transform');
        const eCollider = enemy.getComponent<'collider'>('collider');
        const eData = enemy.getComponent<'creature'>('creature');
        if (!eTransform || !eCollider || !eData) continue;

        if (this.checkCollision(pTransform, pCollider.radius, eTransform, eCollider.radius)) {
          // Queue contact damage event
          damageEvents.push({
            targetId: player.id,
            sourceId: enemy.id,
            damage: eData.hitboxSize * 0.5, // Contact damage based on enemy size
            isFireDamage: false,
          });
        }
      }
    }

    // Player vs Bonus collisions
    for (const player of players) {
      const pTransform = player.getComponent<'transform'>('transform');
      const pCollider = player.getComponent<'collider'>('collider');
      if (!pTransform || !pCollider) continue;

      for (const bonus of bonuses) {
        const bTransform = bonus.getComponent<'transform'>('transform');
        const bCollider = bonus.getComponent<'collider'>('collider');
        const bData = bonus.getComponent<'bonus'>('bonus');
        if (!bTransform || !bCollider || !bData) continue;

        if (this.checkCollision(pTransform, pCollider.radius, bTransform, bCollider.radius)) {
          // Queue collect event
          collectEvents.push({
            playerId: player.id,
            bonusId: bonus.id,
            bonusType: bData.bonusType,
            value: bData.value,
          });

          // Destroy bonus entity
          this.entityManager.destroyEntity(bonus.id);
        }
      }
    }
  }

  private checkCollision(
    t1: { x: number; y: number },
    r1: number,
    t2: { x: number; y: number },
    r2: number
  ): boolean {
    const dx = t1.x - t2.x;
    const dy = t1.y - t2.y;
    const distance = Math.sqrt(dx * dx + dy * dy);
    return distance < r1 + r2;
  }
}
