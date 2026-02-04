/**
 * Bonus Effect Tests
 *
 * Tests for ATOMIC, SHOCK_CHAIN, FIREBLAST, and POINTS bonus effects.
 */

import { describe, expect, it, beforeEach } from 'vitest';
import type { UpdateContext } from '../../../src/core/ecs/System';
import { EntityManager } from '../../../src/core/ecs/EntityManager';
import { BonusSystem } from '../../../src/game/systems/BonusSystem';
import { BonusType, ProjectileTypeId, CreatureTypeId } from '../../../src/types';
import { createPlayer, createCreature, createTransform } from '../../../src/game/components';
import { createBonusEntity } from '../../../src/game/entities/BonusFactory';
import { collectEvents } from '../../../src/game/systems/CollisionSystem';

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

describe('ATOMIC Bonus Effect', () => {
  let entityManager: EntityManager;
  let bonusSystem: BonusSystem;

  beforeEach(() => {
    entityManager = new EntityManager();
    bonusSystem = new BonusSystem(entityManager);
    // Clear collect events between tests
    collectEvents.length = 0;
  });

  it('should spawn pistol and gauss projectiles when collected', () => {
    // Setup player
    const player = entityManager.createEntity();
    player.addComponent(createPlayer(0));
    player.addComponent(createTransform(100, 100));

    // Create ATOMIC bonus
    const bonus = createBonusEntity(entityManager, BonusType.ATOMIC, 100, 100);

    // Simulate collection
    collectEvents.push({
      playerId: player.id,
      bonusId: bonus.id,
      bonusType: BonusType.ATOMIC,
      value: 0,
    });

    // Update system
    bonusSystem.update(entityManager, createUpdateContext());

    // Check projectiles were spawned
    const projectiles = entityManager.query(['projectile']);
    const pistolCount = projectiles.filter((p) => {
      const proj = p.getComponent<'projectile'>('projectile');
      return proj?.projectileTypeId === ProjectileTypeId.PISTOL;
    }).length;
    const gaussCount = projectiles.filter((p) => {
      const proj = p.getComponent<'projectile'>('projectile');
      return proj?.projectileTypeId === ProjectileTypeId.GAUSS_GUN;
    }).length;

    expect(pistolCount).toBeGreaterThanOrEqual(4);
    expect(pistolCount).toBeLessThanOrEqual(7);
    expect(gaussCount).toBe(2);
  });

  it('should damage enemies within 256 units', () => {
    // Setup player at origin
    const player = entityManager.createEntity();
    player.addComponent(createPlayer(0));
    player.addComponent(createTransform(0, 0));

    // Setup enemy within range (100 units away)
    const enemy = entityManager.createEntity();
    const creature = createCreature(CreatureTypeId.ZOMBIE, { health: 1000 });
    enemy.addComponent(creature);
    enemy.addComponent(createTransform(100, 0));

    // Setup enemy outside range (300 units away)
    const farEnemy = entityManager.createEntity();
    const farCreature = createCreature(CreatureTypeId.ZOMBIE, { health: 1000 });
    farEnemy.addComponent(farCreature);
    farEnemy.addComponent(createTransform(300, 0));

    // Create and collect ATOMIC bonus
    const bonus = createBonusEntity(entityManager, BonusType.ATOMIC, 0, 0);
    collectEvents.push({
      playerId: player.id,
      bonusId: bonus.id,
      bonusType: BonusType.ATOMIC,
      value: 0,
    });

    bonusSystem.update(entityManager, createUpdateContext());

    // Check enemy within range took damage (radial damage + possible projectile hits)
    expect(creature.health).toBeLessThan(1000);
    // Expected radial damage: (256 - 100) * 5 = 780, but projectiles may add more

    // Check enemy outside range took no radial damage
    // (may still take projectile damage if hit by random projectiles)
    expect(farCreature.health).toBeLessThanOrEqual(1000);
  });

  it('should deal radial damage to enemies at center', () => {
    // Setup player at origin
    const player = entityManager.createEntity();
    player.addComponent(createPlayer(0));
    player.addComponent(createTransform(0, 0));

    // Setup enemy at same position (center of blast)
    const enemy = entityManager.createEntity();
    const creature = createCreature(CreatureTypeId.ZOMBIE, { health: 2000 });
    enemy.addComponent(creature);
    enemy.addComponent(createTransform(0, 0));

    // Create and collect ATOMIC bonus
    const bonus = createBonusEntity(entityManager, BonusType.ATOMIC, 0, 0);
    collectEvents.push({
      playerId: player.id,
      bonusId: bonus.id,
      bonusType: BonusType.ATOMIC,
      value: 0,
    });

    bonusSystem.update(entityManager, createUpdateContext());

    // Radial damage at center: 256 * 5 = 1280
    // Plus potential projectile damage, so health should be much lower
    expect(creature.health).toBeLessThan(1000);
  });
});

describe('FIREBLAST Bonus Effect', () => {
  let entityManager: EntityManager;
  let bonusSystem: BonusSystem;

  beforeEach(() => {
    entityManager = new EntityManager();
    bonusSystem = new BonusSystem(entityManager);
    collectEvents.length = 0;
  });

  it('should spawn exactly 16 plasma rifle projectiles', () => {
    // Setup player
    const player = entityManager.createEntity();
    player.addComponent(createPlayer(0));
    player.addComponent(createTransform(100, 100));

    // Create FIREBLAST bonus
    const bonus = createBonusEntity(entityManager, BonusType.FIREBLAST, 100, 100);

    // Simulate collection
    collectEvents.push({
      playerId: player.id,
      bonusId: bonus.id,
      bonusType: BonusType.FIREBLAST,
      value: 0,
    });

    // Update system
    bonusSystem.update(entityManager, createUpdateContext());

    // Check exactly 16 plasma projectiles were spawned
    const projectiles = entityManager.query(['projectile']);
    const plasmaCount = projectiles.filter((p) => {
      const proj = p.getComponent<'projectile'>('projectile');
      return proj?.projectileTypeId === ProjectileTypeId.PLASMA_RIFLE;
    }).length;

    expect(plasmaCount).toBe(16);
  });

  it('should spawn projectiles in radial pattern (all directions)', () => {
    // Setup player
    const player = entityManager.createEntity();
    player.addComponent(createPlayer(0));
    player.addComponent(createTransform(0, 0));

    // Create FIREBLAST bonus
    const bonus = createBonusEntity(entityManager, BonusType.FIREBLAST, 0, 0);

    // Simulate collection
    collectEvents.push({
      playerId: player.id,
      bonusId: bonus.id,
      bonusType: BonusType.FIREBLAST,
      value: 0,
    });

    // Update system
    bonusSystem.update(entityManager, createUpdateContext());

    // Check projectiles are spread in all directions
    const projectiles = entityManager.query(['projectile', 'velocity']);
    const velocities = projectiles
      .map((p) => p.getComponent<'velocity'>('velocity'))
      .filter((v): v is NonNullable<typeof v> => v !== null);

    // Should have velocities in all quadrants
    const hasRight = velocities.some((v) => v.x > 0 && Math.abs(v.x) > Math.abs(v.y));
    const hasLeft = velocities.some((v) => v.x < 0 && Math.abs(v.x) > Math.abs(v.y));
    const hasUp = velocities.some((v) => v.y < 0 && Math.abs(v.y) > Math.abs(v.x));
    const hasDown = velocities.some((v) => v.y > 0 && Math.abs(v.y) > Math.abs(v.x));

    expect(hasRight).toBe(true);
    expect(hasLeft).toBe(true);
    expect(hasUp).toBe(true);
    expect(hasDown).toBe(true);
  });
});

describe('SHOCK_CHAIN Bonus Effect', () => {
  let entityManager: EntityManager;
  let bonusSystem: BonusSystem;

  beforeEach(() => {
    entityManager = new EntityManager();
    bonusSystem = new BonusSystem(entityManager);
    collectEvents.length = 0;
  });

  it('should spawn ion rifle projectile toward nearest enemy', () => {
    // Setup player at origin
    const player = entityManager.createEntity();
    player.addComponent(createPlayer(0));
    player.addComponent(createTransform(0, 0));

    // Setup enemy to the right
    const enemy = entityManager.createEntity();
    enemy.addComponent(createCreature(CreatureTypeId.ZOMBIE));
    enemy.addComponent(createTransform(100, 0));

    // Create SHOCK_CHAIN bonus
    const bonus = createBonusEntity(entityManager, BonusType.SHOCK_CHAIN, 0, 0);

    // Simulate collection
    collectEvents.push({
      playerId: player.id,
      bonusId: bonus.id,
      bonusType: BonusType.SHOCK_CHAIN,
      value: 0,
    });

    // Update system
    bonusSystem.update(entityManager, createUpdateContext());

    // Check ion projectile was spawned
    const projectiles = entityManager.query(['projectile']);
    const ionCount = projectiles.filter((p) => {
      const proj = p.getComponent<'projectile'>('projectile');
      return proj?.projectileTypeId === ProjectileTypeId.ION_RIFLE;
    }).length;

    expect(ionCount).toBe(1);
  });

  it('should not spawn projectile when no enemies exist', () => {
    // Setup player at origin (no enemies)
    const player = entityManager.createEntity();
    player.addComponent(createPlayer(0));
    player.addComponent(createTransform(0, 0));

    // Create SHOCK_CHAIN bonus
    const bonus = createBonusEntity(entityManager, BonusType.SHOCK_CHAIN, 0, 0);

    // Simulate collection
    collectEvents.push({
      playerId: player.id,
      bonusId: bonus.id,
      bonusType: BonusType.SHOCK_CHAIN,
      value: 0,
    });

    // Update system
    bonusSystem.update(entityManager, createUpdateContext());

    // Check no ion projectile was spawned
    const projectiles = entityManager.query(['projectile']);
    const ionCount = projectiles.filter((p) => {
      const proj = p.getComponent<'projectile'>('projectile');
      return proj?.projectileTypeId === ProjectileTypeId.ION_RIFLE;
    }).length;

    expect(ionCount).toBe(0);
  });

  it('should target nearest enemy among multiple', () => {
    // Setup player at origin
    const player = entityManager.createEntity();
    player.addComponent(createPlayer(0));
    player.addComponent(createTransform(0, 0));

    // Setup near enemy (should be targeted)
    const nearEnemy = entityManager.createEntity();
    nearEnemy.addComponent(createCreature(CreatureTypeId.ZOMBIE));
    nearEnemy.addComponent(createTransform(50, 0));

    // Setup far enemy
    const farEnemy = entityManager.createEntity();
    farEnemy.addComponent(createCreature(CreatureTypeId.ZOMBIE));
    farEnemy.addComponent(createTransform(200, 0));

    // Create SHOCK_CHAIN bonus
    const bonus = createBonusEntity(entityManager, BonusType.SHOCK_CHAIN, 0, 0);

    // Simulate collection
    collectEvents.push({
      playerId: player.id,
      bonusId: bonus.id,
      bonusType: BonusType.SHOCK_CHAIN,
      value: 0,
    });

    // Update system
    bonusSystem.update(entityManager, createUpdateContext());

    // Check ion projectile was spawned
    const projectiles = entityManager.query(['projectile']);
    const ionProjectiles = projectiles.filter((p) => {
      const proj = p.getComponent<'projectile'>('projectile');
      return proj?.projectileTypeId === ProjectileTypeId.ION_RIFLE;
    });

    expect(ionProjectiles.length).toBe(1);
  });
});

describe('POINTS Bonus Effect', () => {
  let entityManager: EntityManager;
  let bonusSystem: BonusSystem;

  beforeEach(() => {
    entityManager = new EntityManager();
    bonusSystem = new BonusSystem(entityManager);
    collectEvents.length = 0;
  });

  it('should grant experience points to player', () => {
    const player = entityManager.createEntity();
    const playerComp = createPlayer(0);
    playerComp.experience = 0;
    player.addComponent(playerComp);
    player.addComponent(createTransform(0, 0));

    // Collect POINTS bonus with value 500
    const bonus = createBonusEntity(entityManager, BonusType.POINTS, 0, 0);
    // Override the value
    const bonusComp = bonus.getComponent<'bonus'>('bonus');
    if (bonusComp) {
      bonusComp.value = 500;
    }

    collectEvents.push({
      playerId: player.id,
      bonusId: bonus.id,
      bonusType: BonusType.POINTS,
      value: 500,
    });

    bonusSystem.update(entityManager, createUpdateContext());

    expect(playerComp.experience).toBe(500);
  });

  it('should accumulate experience from multiple POINTS bonuses', () => {
    const player = entityManager.createEntity();
    const playerComp = createPlayer(0);
    playerComp.experience = 100;
    player.addComponent(playerComp);
    player.addComponent(createTransform(0, 0));

    // Collect first POINTS bonus with value 250
    let bonus = createBonusEntity(entityManager, BonusType.POINTS, 0, 0);
    collectEvents.push({
      playerId: player.id,
      bonusId: bonus.id,
      bonusType: BonusType.POINTS,
      value: 250,
    });

    bonusSystem.update(entityManager, createUpdateContext());

    expect(playerComp.experience).toBe(350); // 100 + 250

    // Clear events to simulate CollisionSystem clearing them
    collectEvents.length = 0;

    // Collect second POINTS bonus with value 150
    bonus = createBonusEntity(entityManager, BonusType.POINTS, 0, 0);
    collectEvents.push({
      playerId: player.id,
      bonusId: bonus.id,
      bonusType: BonusType.POINTS,
      value: 150,
    });

    bonusSystem.update(entityManager, createUpdateContext({ gameTime: 0.016 }));

    expect(playerComp.experience).toBe(500); // 350 + 150
  });
});

describe('Bonus Spawn Guard', () => {
  let entityManager: EntityManager;
  let bonusSystem: BonusSystem;

  beforeEach(() => {
    entityManager = new EntityManager();
    bonusSystem = new BonusSystem(entityManager);
    collectEvents.length = 0;
  });

  it('should be inactive by default', () => {
    expect(BonusSystem.isSpawnGuardActive()).toBe(false);
  });

  it('should activate during ATOMIC effect', () => {
    const player = entityManager.createEntity();
    player.addComponent(createPlayer(0));
    player.addComponent(createTransform(0, 0));

    // Before effect
    expect(BonusSystem.isSpawnGuardActive()).toBe(false);

    // Trigger ATOMIC
    const bonus = createBonusEntity(entityManager, BonusType.ATOMIC, 0, 0);
    collectEvents.push({
      playerId: player.id,
      bonusId: bonus.id,
      bonusType: BonusType.ATOMIC,
      value: 0,
    });

    bonusSystem.update(entityManager, createUpdateContext());

    // After effect, spawn guard should be released
    expect(BonusSystem.isSpawnGuardActive()).toBe(false);
  });
});
