/**
 * Collision System
 *
 * Handles collisions between entities: projectile-enemy, player-enemy, player-bonus, player-weaponPickup.
 * Uses circle-based collision detection.
 * Implements Bonus Magnet perk for auto-collection of nearby pickups.
 * Implements projectile special case behaviors from decompiled code:
 *   - Shock Chain (Ion Rifle): chains to nearest enemy on hit (up to 32 links, 100 unit range)
 *   - Splitter Gun: spawns 2 child projectiles at ±60° on hit
 *   - Plague Spreader: sets creature collision_flag on hit
 *   - Shrinkifier: reduces target size by 35% on hit, kills if below 16.0 threshold
 *   - Pulse Gun: pushes enemies back on hit
 * Priority: 60
 */

import type { EntityManager } from '../../core/ecs';
import { System, type UpdateContext } from '../../core/ecs/System';
import type { EntityId } from '../../types';
import { CollisionLayer, ProjectileTypeId } from '../components';
import { getProjectileData } from '../data';
import { createProjectileEntity } from '../entities/ProjectileFactory';
import type { PerkSystem } from './PerkSystem';
import {
  getShockChainState,
  updateShockChainState,
  clearShockChainState,
} from './ShockChainState';

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

export interface WeaponCollectEvent {
  playerId: EntityId;
  pickupId: EntityId;
  weaponId: number;
  ammo: number;
}

// Event queues processed by other systems
export const damageEvents: DamageEvent[] = [];
export const collectEvents: CollectEvent[] = [];
export const weaponCollectEvents: WeaponCollectEvent[] = [];

// Bonus magnet radius (in world units)
const BONUS_MAGNET_RADIUS = 150;

// Decompiled constants for projectile special cases
const SHOCK_CHAIN_RADIUS = 100;
const SPLITTER_ANGLE_OFFSET = 1.0471976; // 60 degrees in radians (decompiled line 170-172)
const SHRINK_MULTIPLIER = 0.65; // Shrinkifier reduces size by 35% (decompiled line 318)
const SHRINK_KILL_THRESHOLD = 16.0; // Kill enemy when size drops below this (decompiled line 321)
const PULSE_PUSH_MULTIPLIER = 3.0; // Pulse gun pushback multiplier (decompiled lines 326-328)

export class CollisionSystem extends System {
  readonly name = 'CollisionSystem';
  readonly priority = 60;

  private entityManager: EntityManager;
  private perkSystem: PerkSystem | null = null;

  constructor(entityManager: EntityManager, perkSystem?: PerkSystem) {
    super();
    this.entityManager = entityManager;
    if (perkSystem) {
      this.perkSystem = perkSystem;
    }
  }

  /**
   * Set the perk system for accessing perk effects
   */
  setPerkSystem(perkSystem: PerkSystem): void {
    this.perkSystem = perkSystem;
  }

  update(_entityManager: EntityManager, _context: UpdateContext): void {
    // Clear previous frame's events
    damageEvents.length = 0;
    collectEvents.length = 0;
    weaponCollectEvents.length = 0;

    // Get entities by layer
    const projectiles = this.entityManager.query(['projectile', 'transform', 'collider']);
    const enemies = this.entityManager.query(['creature', 'transform', 'collider']);
    const players = this.entityManager.query(['player', 'transform', 'collider']);
    const bonuses = this.entityManager.query(['bonus', 'transform', 'collider']);
    const weaponPickups = this.entityManager.query(['weaponPickup', 'transform', 'collider']);

    // Projectile vs Enemy collisions
    for (const projectile of projectiles) {
      const pCollider = projectile.getComponent<'collider'>('collider');
      if (!pCollider || !pCollider.enabled) continue;

      // Only check player projectiles against enemies
      if (pCollider.layer !== CollisionLayer.PROJECTILE_PLAYER) continue;

      const pTransform = projectile.getComponent<'transform'>('transform');
      const pData = projectile.getComponent<'projectile'>('projectile');
      if (!pTransform || !pData) continue;

      // Get projectile type data for fire damage flag
      const projectileTypeData = getProjectileData(pData.projectileTypeId);

      for (const enemy of enemies) {
        const eCollider = enemy.getComponent<'collider'>('collider');
        const eTransform = enemy.getComponent<'transform'>('transform');
        const eCreature = enemy.getComponent<'creature'>('creature');
        if (!eCollider || !eCollider.enabled || !eTransform || !eCreature) continue;

        if (this.checkCollision(pTransform, pCollider.radius, eTransform, eCollider.radius)) {
          // Queue damage event with fire damage from projectile data
          damageEvents.push({
            targetId: enemy.id,
            sourceId: pData.ownerId,
            damage: pData.damage,
            isFireDamage: projectileTypeData.fireDamage,
          });

          // Apply DoT effects if player has uranium/poison bullets
          if (this.perkSystem) {
            if (this.perkSystem.hasUraniumBullets(pData.ownerId)) {
              this.perkSystem.applyDotEffect(
                pData.ownerId,
                enemy.id,
                'uranium',
                5, // damage per tick from perk data
                5 // duration in seconds
              );
            }
            if (this.perkSystem.hasPoisonBullets(pData.ownerId)) {
              this.perkSystem.applyDotEffect(
                pData.ownerId,
                enemy.id,
                'poison',
                3, // damage per tick from perk data
                4 // duration in seconds
              );
            }
          }

          // Handle projectile-specific hit effects
          const shouldDestroy = this.handleProjectileHitEffect(
            projectile,
            pData,
            enemy,
            eTransform,
            eCreature,
            pTransform.rotation
          );

          // Handle piercing (only if projectile wasn't already destroyed by effect handler)
          if (shouldDestroy) {
            if (pData.pierceCount > 0) {
              pData.pierceCount--;
            } else {
              // Destroy projectile
              this.entityManager.destroyEntity(projectile.id);
            }
          }

          break; // Projectile can only hit one enemy per frame (unless piercing)
        }
      }
    }

    // Player vs Enemy collisions (contact damage)
    for (const player of players) {
      const pTransform = player.getComponent<'transform'>('transform');
      const pCollider = player.getComponent<'collider'>('collider');
      const pData = player.getComponent<'player'>('player');
      if (!pTransform || !pCollider || !pCollider.enabled || !pData) continue;

      for (const enemy of enemies) {
        const eTransform = enemy.getComponent<'transform'>('transform');
        const eCollider = enemy.getComponent<'collider'>('collider');
        const eData = enemy.getComponent<'creature'>('creature');
        if (!eTransform || !eCollider || !eCollider.enabled || !eData) continue;

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
      const pData = player.getComponent<'player'>('player');
      if (!pTransform || !pCollider || !pData) continue;

      // Check if player has Bonus Magnet perk and is alive
      const hasBonusMagnet = this.perkSystem?.hasBonusMagnet(player.id) ?? false;
      const isAlive = pData.health > 0;
      const magnetRadius = hasBonusMagnet && isAlive ? BONUS_MAGNET_RADIUS : pCollider.radius;

      for (const bonus of bonuses) {
        const bTransform = bonus.getComponent<'transform'>('transform');
        const bCollider = bonus.getComponent<'collider'>('collider');
        const bData = bonus.getComponent<'bonus'>('bonus');
        if (!bTransform || !bCollider || !bData) continue;

        if (this.checkCollision(pTransform, magnetRadius, bTransform, bCollider.radius)) {
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

    // Player vs Weapon Pickup collisions
    for (const player of players) {
      const pTransform = player.getComponent<'transform'>('transform');
      const pCollider = player.getComponent<'collider'>('collider');
      const pData = player.getComponent<'player'>('player');
      if (!pTransform || !pCollider || !pData) continue;

      // Check if player has Bonus Magnet perk and is alive
      const hasBonusMagnet = this.perkSystem?.hasBonusMagnet(player.id) ?? false;
      const isAlive = pData.health > 0;
      const magnetRadius = hasBonusMagnet && isAlive ? BONUS_MAGNET_RADIUS : pCollider.radius;

      for (const pickup of weaponPickups) {
        const wTransform = pickup.getComponent<'transform'>('transform');
        const wCollider = pickup.getComponent<'collider'>('collider');
        const wData = pickup.getComponent<'weaponPickup'>('weaponPickup');
        if (!wTransform || !wCollider || !wData) continue;

        if (this.checkCollision(pTransform, magnetRadius, wTransform, wCollider.radius)) {
          // Queue weapon collect event
          weaponCollectEvents.push({
            playerId: player.id,
            pickupId: pickup.id,
            weaponId: wData.weaponId,
            ammo: wData.ammo,
          });

          // Destroy pickup entity
          this.entityManager.destroyEntity(pickup.id);
        }
      }
    }
  }

  /**
   * Handle projectile-specific hit effects based on projectile type.
   * Called when a projectile hits an enemy.
   * Returns true if the projectile should be destroyed, false if it should continue.
   */
  private handleProjectileHitEffect(
    projectile: import('../../core/ecs').Entity,
    projectileData: {
      projectileTypeId: ProjectileTypeId;
      damage: number;
      pierceCount: number;
      shockChainLinksLeft?: number | undefined;
      isShockChainActive?: boolean | undefined;
      ownerId: number;
    },
    enemy: import('../../core/ecs').Entity,
    enemyTransform: { x: number; y: number },
    enemyCreature: import('../components').Creature,
    projectileAngle: number
  ): boolean {
    const projectileTypeId = projectileData.projectileTypeId;

    switch (projectileTypeId) {
      case ProjectileTypeId.ION_RIFLE:
      case ProjectileTypeId.ION_MINIGUN: {
        // Shock chain logic (decompiled lines 273-290)
        const chainState = getShockChainState();

        // Only continue chain if this is the active shock chain projectile
        if (
          projectileData.isShockChainActive &&
          chainState.activeProjectileId === projectile.id &&
          chainState.linksLeft > 0
        ) {
          // Find nearest enemy within 100 units (excluding current target)
          const nextTarget = this.findNearestEnemy(
            { x: enemyTransform.x, y: enemyTransform.y },
            enemy.id,
            SHOCK_CHAIN_RADIUS
          );

          if (nextTarget) {
            // Decrement links
            const newLinksLeft = chainState.linksLeft - 1;

            // Calculate angle to next target
            const dx = nextTarget.transform.x - enemyTransform.x;
            const dy = nextTarget.transform.y - enemyTransform.y;
            const angle = Math.atan2(dy, dx);

            // Spawn new ion rifle projectile toward next target
            // Decompiled: angle - π/2 - π (coordinate system adjustment, lines 283-284)
            const adjustedAngle = angle - Math.PI / 2 - Math.PI;
            const newProjectile = createProjectileEntity(
              this.entityManager,
              ProjectileTypeId.ION_RIFLE,
              enemyTransform.x,
              enemyTransform.y,
              adjustedAngle,
              projectileData.ownerId,
              { damage: projectileData.damage }
            );

            // Set up new projectile for chain continuation
            const newProjComponent = newProjectile.getComponent<'projectile'>('projectile');
            if (newProjComponent) {
              newProjComponent.isShockChainActive = true;
              newProjComponent.shockChainLinksLeft = newLinksLeft;
            }

            // Update state to track new projectile
            updateShockChainState(newProjectile.id, newLinksLeft);

            // TODO: Play sfx_shock_hit_01
          } else {
            // No valid target, end chain
            clearShockChainState();
          }
        }
        return true; // Destroy projectile after hit
      }

      case ProjectileTypeId.SPLITTER_GUN: {
        // Splitter gun spawns 2 child projectiles at ±60° (decompiled lines 168-173)
        // Spawn first child at -60°
        createProjectileEntity(
          this.entityManager,
          ProjectileTypeId.SPLITTER_GUN,
          enemyTransform.x,
          enemyTransform.y,
          projectileAngle - SPLITTER_ANGLE_OFFSET,
          projectileData.ownerId,
          { damage: projectileData.damage * 0.5 } // Reduced damage for children
        );

        // Spawn second child at +60°
        createProjectileEntity(
          this.entityManager,
          ProjectileTypeId.SPLITTER_GUN,
          enemyTransform.x,
          enemyTransform.y,
          projectileAngle + SPLITTER_ANGLE_OFFSET,
          projectileData.ownerId,
          { damage: projectileData.damage * 0.5 }
        );

        return true; // Destroy parent projectile
      }

      case ProjectileTypeId.SHRINKIFIER: {
        // Shrinkifier reduces target size by 35% (decompiled lines 316-323)
        enemyCreature.size *= SHRINK_MULTIPLIER;

        // If size drops below threshold, kill the creature
        if (enemyCreature.size < SHRINK_KILL_THRESHOLD) {
          enemyCreature.health = 0; // Mark for death (HealthSystem will handle cleanup)
        }

        return true; // Destroy projectile
      }

      case ProjectileTypeId.PLAGUE_SPREADER: {
        // Plague spreader sets collision flag (decompiled line 331)
        enemyCreature.collisionFlag = true;
        return true; // Destroy projectile
      }

      case ProjectileTypeId.PULSE_GUN: {
        // Pulse gun pushes enemy back (decompiled lines 325-328)
        // Calculate push direction based on projectile angle
        const pushX = Math.cos(projectileAngle) * PULSE_PUSH_MULTIPLIER;
        const pushY = Math.sin(projectileAngle) * PULSE_PUSH_MULTIPLIER;

        enemyTransform.x += pushX;
        enemyTransform.y += pushY;

        return true; // Destroy projectile
      }

      default:
        return true; // Default: destroy projectile
    }
  }

  /**
   * Find nearest enemy within radius, excluding a specific entity.
   */
  private findNearestEnemy(
    position: { x: number; y: number },
    excludeId: number,
    radius: number
  ): { id: number; transform: { x: number; y: number } } | null {
    const enemies = this.entityManager.query(['creature', 'transform']);
    let nearest: { id: number; transform: { x: number; y: number }; distSq: number } | null = null;
    const radiusSq = radius * radius;

    for (const enemy of enemies) {
      if (enemy.id === excludeId) continue;

      const transform = enemy.getComponent<'transform'>('transform');
      const creature = enemy.getComponent<'creature'>('creature');
      if (!transform || !creature || creature.health <= 0) continue;

      const dx = transform.x - position.x;
      const dy = transform.y - position.y;
      const distSq = dx * dx + dy * dy;

      if (distSq <= radiusSq && (!nearest || distSq < nearest.distSq)) {
        nearest = { id: enemy.id, transform, distSq };
      }
    }

    return nearest ? { id: nearest.id, transform: nearest.transform } : null;
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
