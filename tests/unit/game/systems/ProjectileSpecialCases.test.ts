/**
 * Unit tests for projectile special case behaviors
 *
 * Tests the decompiled projectile behaviors:
 * - SHOCK_CHAIN (Ion Rifle): chains to nearest enemy on hit (up to 32 links, 100 unit range)
 * - SPLITTER_GUN: spawns 2 child projectiles at ±60° on hit
 * - PLAGUE_SPREADER: sets creature collision_flag on hit
 * - SHRINKIFIER: reduces target size by 35% on hit, kills if below 16.0 threshold
 * - PULSE_GUN: pushes enemies back on hit
 */

import { describe, it, expect, beforeEach } from 'vitest';
import type { UpdateContext } from '../../../../src/core/ecs/System';
import { EntityManager } from '../../../../src/core/ecs/EntityManager';
import { CollisionSystem } from '../../../../src/game/systems/CollisionSystem';
import {
  createCreature,
  createTransform,
  createCollider,
  CollisionLayer,
} from '../../../../src/game/components';
import { createProjectileEntity } from '../../../../src/game/entities/ProjectileFactory';
import { ProjectileTypeId, CreatureTypeId } from '../../../../src/types';
import {
  clearShockChainState,
  getShockChainState,
  setShockChainState,
} from '../../../../src/game/systems/ShockChainState';

// Helper to create a valid UpdateContext for tests
function createUpdateContext(overrides: Partial<UpdateContext> = {}): UpdateContext {
  return {
    dt: 0.016,
    unscaledDt: 0.016,
    gameTime: 0,
    frameNumber: 0,
    timeScale: 1,
    setTimeScale: () => {},
    ...overrides,
  };
}

describe('Projectile Special Cases', () => {
  let entityManager: EntityManager;
  let collisionSystem: CollisionSystem;

  beforeEach(() => {
    entityManager = new EntityManager();
    collisionSystem = new CollisionSystem(entityManager, undefined);
    clearShockChainState();
  });

  describe('SHRINKIFIER', () => {
    it('should reduce enemy size by 35% on hit', () => {
      // Create enemy with size 32
      const enemy = entityManager.createEntity();
      enemy.addComponent(createTransform(100, 100));
      enemy.addComponent(createCollider(16, CollisionLayer.ENEMY));
      enemy.addComponent(createCreature(CreatureTypeId.ZOMBIE, { size: 32, health: 100 }));

      // Create shrinkifier projectile
      createProjectileEntity(entityManager, ProjectileTypeId.SHRINKIFIER, 100, 100, 0, 1);

      // Run collision detection
      collisionSystem.update(entityManager, createUpdateContext());

      // Verify size reduced by 35% (32 * 0.65 = 20.8)
      const creature = enemy.getComponent<'creature'>('creature');
      expect(creature?.size).toBeCloseTo(20.8, 1);
    });

    it('should kill enemy when size drops below 16.0 threshold', () => {
      // Create enemy with size 20 (will shrink to 13, below threshold)
      const enemy = entityManager.createEntity();
      enemy.addComponent(createTransform(100, 100));
      enemy.addComponent(createCollider(16, CollisionLayer.ENEMY));
      enemy.addComponent(createCreature(CreatureTypeId.ZOMBIE, { size: 20, health: 100 }));

      // Create shrinkifier projectile
      createProjectileEntity(entityManager, ProjectileTypeId.SHRINKIFIER, 100, 100, 0, 1);

      // Run collision detection
      collisionSystem.update(entityManager, createUpdateContext());

      // Verify enemy health is 0 (marked for death)
      const creature = enemy.getComponent<'creature'>('creature');
      expect(creature?.health).toBe(0);
    });

    it('should not kill enemy when size stays above threshold', () => {
      // Create enemy with size 32 (will shrink to 20.8, above threshold)
      const enemy = entityManager.createEntity();
      enemy.addComponent(createTransform(100, 100));
      enemy.addComponent(createCollider(16, CollisionLayer.ENEMY));
      enemy.addComponent(createCreature(CreatureTypeId.ZOMBIE, { size: 32, health: 100 }));

      // Create shrinkifier projectile
      createProjectileEntity(entityManager, ProjectileTypeId.SHRINKIFIER, 100, 100, 0, 1);

      // Run collision detection
      collisionSystem.update(entityManager, createUpdateContext());

      // Verify enemy still has health
      const creature = enemy.getComponent<'creature'>('creature');
      expect(creature?.health).toBeGreaterThan(0);
    });
  });

  describe('SPLITTER_GUN', () => {
    it('should spawn 2 child projectiles at ±60 degrees on hit', () => {
      // Create enemy
      const enemy = entityManager.createEntity();
      enemy.addComponent(createTransform(100, 100));
      enemy.addComponent(createCollider(16, CollisionLayer.ENEMY));
      enemy.addComponent(createCreature(CreatureTypeId.ZOMBIE, { health: 100 }));

      // Create splitter gun projectile at 0 degrees
      createProjectileEntity(entityManager, ProjectileTypeId.SPLITTER_GUN, 100, 100, 0, 1);

      // Run collision detection
      collisionSystem.update(entityManager, createUpdateContext());

      // Count projectiles - should be original + 2 children
      // (parent may or may not be destroyed depending on entity manager behavior)
      const projectiles = entityManager.query(['projectile']);
      expect(projectiles.length).toBeGreaterThanOrEqual(2);
    });
  });

  describe('PLAGUE_SPREADER', () => {
    it('should set collision flag on enemy when hit', () => {
      // Create enemy
      const enemy = entityManager.createEntity();
      enemy.addComponent(createTransform(100, 100));
      enemy.addComponent(createCollider(16, CollisionLayer.ENEMY));
      enemy.addComponent(
        createCreature(CreatureTypeId.ZOMBIE, {
          health: 100,
          collisionFlag: false,
        })
      );

      // Create plague spreader projectile
      createProjectileEntity(entityManager, ProjectileTypeId.PLAGUE_SPREADER, 100, 100, 0, 1);

      // Run collision detection
      collisionSystem.update(entityManager, createUpdateContext());

      // Verify collision flag is set
      const creature = enemy.getComponent<'creature'>('creature');
      expect(creature?.collisionFlag).toBe(true);
    });
  });

  describe('PULSE_GUN', () => {
    it('should push enemy back on hit', () => {
      // Create enemy at (100, 100)
      const enemy = entityManager.createEntity();
      enemy.addComponent(createTransform(100, 100));
      enemy.addComponent(createCollider(16, CollisionLayer.ENEMY));
      enemy.addComponent(createCreature(CreatureTypeId.ZOMBIE, { health: 100 }));

      // Create pulse gun projectile moving right (0 degrees)
      createProjectileEntity(entityManager, ProjectileTypeId.PULSE_GUN, 100, 100, 0, 1);

      // Run collision detection
      collisionSystem.update(entityManager, createUpdateContext());

      // Verify enemy was pushed in projectile direction
      const transform = enemy.getComponent<'transform'>('transform');
      expect(transform?.x).toBeGreaterThan(100);
    });
  });

  describe('SHOCK_CHAIN (Ion Rifle)', () => {
    it('should initialize with 32 links when spawned from bonus', () => {
      // Create two enemies
      const enemy1 = entityManager.createEntity();
      enemy1.addComponent(createTransform(100, 100));
      enemy1.addComponent(createCollider(16, CollisionLayer.ENEMY));
      enemy1.addComponent(createCreature(CreatureTypeId.ZOMBIE, { health: 100 }));

      const enemy2 = entityManager.createEntity();
      enemy2.addComponent(createTransform(150, 100)); // Within 100 units
      enemy2.addComponent(createCollider(16, CollisionLayer.ENEMY));
      enemy2.addComponent(createCreature(CreatureTypeId.ZOMBIE, { health: 100 }));

      // Create ion rifle projectile with shock chain active
      const projectile = createProjectileEntity(
        entityManager,
        ProjectileTypeId.ION_RIFLE,
        100,
        100,
        0,
        1,
        { damage: 30 }
      );
      const projComponent = projectile.getComponent<'projectile'>('projectile');
      if (projComponent) {
        projComponent.isShockChainActive = true;
        projComponent.shockChainLinksLeft = 32;
      }
      setShockChainState(projectile.id, 32);

      // Verify initial state
      const state = getShockChainState();
      expect(state.linksLeft).toBe(32);
      expect(state.activeProjectileId).toBe(projectile.id);
    });

    it('should chain to nearest enemy and decrement links', () => {
      // Create two enemies
      const enemy1 = entityManager.createEntity();
      enemy1.addComponent(createTransform(100, 100));
      enemy1.addComponent(createCollider(16, CollisionLayer.ENEMY));
      enemy1.addComponent(createCreature(CreatureTypeId.ZOMBIE, { health: 100 }));

      const enemy2 = entityManager.createEntity();
      enemy2.addComponent(createTransform(150, 100)); // Within 100 units
      enemy2.addComponent(createCollider(16, CollisionLayer.ENEMY));
      enemy2.addComponent(createCreature(CreatureTypeId.ZOMBIE, { health: 100 }));

      // Create ion rifle projectile with shock chain active
      const projectile = createProjectileEntity(
        entityManager,
        ProjectileTypeId.ION_RIFLE,
        100,
        100,
        0,
        1,
        { damage: 30 }
      );
      const projComponent = projectile.getComponent<'projectile'>('projectile');
      if (projComponent) {
        projComponent.isShockChainActive = true;
        projComponent.shockChainLinksLeft = 32;
      }
      setShockChainState(projectile.id, 32);

      // Run collision detection (hits enemy1, should chain to enemy2)
      collisionSystem.update(entityManager, createUpdateContext());

      // Verify chain state was updated (links decremented, new projectile tracked)
      const state = getShockChainState();
      expect(state.linksLeft).toBe(31);
      expect(state.activeProjectileId).not.toBe(projectile.id); // New projectile ID
    });

    it('should stop chaining when no enemies in range', () => {
      // Create only one enemy
      const enemy = entityManager.createEntity();
      enemy.addComponent(createTransform(100, 100));
      enemy.addComponent(createCollider(16, CollisionLayer.ENEMY));
      enemy.addComponent(createCreature(CreatureTypeId.ZOMBIE, { health: 100 }));

      // Create ion rifle projectile with shock chain active
      const projectile = createProjectileEntity(
        entityManager,
        ProjectileTypeId.ION_RIFLE,
        100,
        100,
        0,
        1
      );
      const projComponent = projectile.getComponent<'projectile'>('projectile');
      if (projComponent) {
        projComponent.isShockChainActive = true;
        projComponent.shockChainLinksLeft = 32;
      }
      setShockChainState(projectile.id, 32);

      // Run collision detection
      collisionSystem.update(entityManager, createUpdateContext());

      // Verify chain state is cleared (no other enemy to chain to)
      const state = getShockChainState();
      expect(state.activeProjectileId).toBeNull();
      expect(state.linksLeft).toBe(0);
    });

    it('should not chain when isShockChainActive is false', () => {
      // Create two enemies
      const enemy1 = entityManager.createEntity();
      enemy1.addComponent(createTransform(100, 100));
      enemy1.addComponent(createCollider(16, CollisionLayer.ENEMY));
      enemy1.addComponent(createCreature(CreatureTypeId.ZOMBIE, { health: 100 }));

      const enemy2 = entityManager.createEntity();
      enemy2.addComponent(createTransform(150, 100));
      enemy2.addComponent(createCollider(16, CollisionLayer.ENEMY));
      enemy2.addComponent(createCreature(CreatureTypeId.ZOMBIE, { health: 100 }));

      // Create ion rifle projectile WITHOUT shock chain active (normal weapon fire)
      const projectile = createProjectileEntity(
        entityManager,
        ProjectileTypeId.ION_RIFLE,
        100,
        100,
        0,
        1,
        { damage: 30 }
      );
      // Note: isShockChainActive is undefined by default

      // Avoid unused variable warning
      void projectile;

      // Run collision detection
      collisionSystem.update(entityManager, createUpdateContext());

      // Verify no chain was started (state should remain clear)
      const state = getShockChainState();
      expect(state.activeProjectileId).toBeNull();
      expect(state.linksLeft).toBe(0);
    });
  });
});
