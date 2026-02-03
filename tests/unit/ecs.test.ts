/**
 * ECS (Entity Component System) unit tests
 */

import { describe, it, expect, vi, beforeEach } from 'vitest';
import { Entity } from '../../src/core/ecs/Entity';
import { EntityManager } from '../../src/core/ecs/EntityManager';
import { System, SystemManager } from '../../src/core/ecs/System';
import type { Component } from '../../src/types';

// Test components
interface PositionComponent extends Component {
  type: 'position';
  x: number;
  y: number;
}

interface VelocityComponent extends Component {
  type: 'velocity';
  vx: number;
  vy: number;
}

interface HealthComponent extends Component {
  type: 'health';
  current: number;
  max: number;
}

describe('Entity', () => {
  let entity: Entity;

  beforeEach(() => {
    entity = new Entity(1);
  });

  describe('creation', () => {
    it('should create entity with ID', () => {
      expect(entity.id).toBe(1);
    });

    it('should start with no components', () => {
      expect(entity.componentCount).toBe(0);
      expect(entity.getComponentTypes()).toEqual([]);
    });
  });

  describe('components', () => {
    it('should add component', () => {
      const pos: PositionComponent = { type: 'position', x: 10, y: 20 };
      entity.addComponent(pos);

      expect(entity.componentCount).toBe(1);
      expect(entity.hasComponent('position')).toBe(true);
    });

    it('should get component', () => {
      const pos: PositionComponent = { type: 'position', x: 10, y: 20 };
      entity.addComponent(pos);

      const retrieved = entity.getComponent<PositionComponent>('position');
      expect(retrieved).toBeDefined();
      expect(retrieved?.x).toBe(10);
      expect(retrieved?.y).toBe(20);
    });

    it('should return undefined for missing component', () => {
      const result = entity.getComponent('position');
      expect(result).toBeUndefined();
    });

    it('should check hasComponent', () => {
      const pos: PositionComponent = { type: 'position', x: 0, y: 0 };
      entity.addComponent(pos);

      expect(entity.hasComponent('position')).toBe(true);
      expect(entity.hasComponent('velocity')).toBe(false);
    });

    it('should check hasComponents (all)', () => {
      const pos: PositionComponent = { type: 'position', x: 0, y: 0 };
      const vel: VelocityComponent = { type: 'velocity', vx: 1, vy: 1 };

      entity.addComponent(pos).addComponent(vel);

      expect(entity.hasComponents(['position', 'velocity'])).toBe(true);
      expect(entity.hasComponents(['position', 'health'])).toBe(false);
    });

    it('should remove component', () => {
      const pos: PositionComponent = { type: 'position', x: 0, y: 0 };
      entity.addComponent(pos);

      const removed = entity.removeComponent('position');
      expect(removed).toBe(true);
      expect(entity.hasComponent('position')).toBe(false);
      expect(entity.componentCount).toBe(0);
    });

    it('should return false when removing non-existent component', () => {
      const removed = entity.removeComponent('position');
      expect(removed).toBe(false);
    });

    it('should support method chaining', () => {
      const pos: PositionComponent = { type: 'position', x: 0, y: 0 };
      const vel: VelocityComponent = { type: 'velocity', vx: 1, vy: 1 };

      const result = entity.addComponent(pos).addComponent(vel);

      expect(result).toBe(entity);
      expect(entity.componentCount).toBe(2);
    });

    it('should clear all components', () => {
      const pos: PositionComponent = { type: 'position', x: 0, y: 0 };
      const vel: VelocityComponent = { type: 'velocity', vx: 1, vy: 1 };

      entity.addComponent(pos).addComponent(vel);
      entity.clear();

      expect(entity.componentCount).toBe(0);
      expect(entity.hasComponent('position')).toBe(false);
      expect(entity.hasComponent('velocity')).toBe(false);
    });

    it('should get component types', () => {
      const pos: PositionComponent = { type: 'position', x: 0, y: 0 };
      const vel: VelocityComponent = { type: 'velocity', vx: 1, vy: 1 };

      entity.addComponent(pos).addComponent(vel);

      const types = entity.getComponentTypes();
      expect(types).toContain('position');
      expect(types).toContain('velocity');
      expect(types.length).toBe(2);
    });
  });
});

describe('EntityManager', () => {
  let manager: EntityManager;

  beforeEach(() => {
    manager = new EntityManager();
  });

  describe('entity creation', () => {
    it('should create entity', () => {
      const entity = manager.createEntity();
      expect(entity).toBeInstanceOf(Entity);
      expect(entity.id).toBe(1);
    });

    it('should auto-increment entity IDs', () => {
      const e1 = manager.createEntity();
      const e2 = manager.createEntity();
      const e3 = manager.createEntity();

      expect(e1.id).toBe(1);
      expect(e2.id).toBe(2);
      expect(e3.id).toBe(3);
    });

    it('should get entity by ID', () => {
      const entity = manager.createEntity();
      const retrieved = manager.getEntity(entity.id);

      expect(retrieved).toBe(entity);
    });

    it('should return undefined for unknown entity', () => {
      const result = manager.getEntity(999);
      expect(result).toBeUndefined();
    });

    it('should check hasEntity', () => {
      const entity = manager.createEntity();

      expect(manager.hasEntity(entity.id)).toBe(true);
      expect(manager.hasEntity(999)).toBe(false);
    });
  });

  describe('entity destruction', () => {
    it('should mark entity for destruction', () => {
      const entity = manager.createEntity();
      const result = manager.destroyEntity(entity.id);

      expect(result).toBe(true);
      expect(manager.hasEntity(entity.id)).toBe(true); // Still exists until processed
    });

    it('should return false for destroying non-existent entity', () => {
      const result = manager.destroyEntity(999);
      expect(result).toBe(false);
    });

    it('should process destructions', () => {
      const entity = manager.createEntity();
      manager.destroyEntity(entity.id);

      manager.processDestructions();

      expect(manager.hasEntity(entity.id)).toBe(false);
    });

    it('should immediately remove entity', () => {
      const entity = manager.createEntity();
      manager.removeEntity(entity.id);

      expect(manager.hasEntity(entity.id)).toBe(false);
    });

    it('should return false for removing non-existent entity', () => {
      const result = manager.removeEntity(999);
      expect(result).toBe(false);
    });
  });

  describe('entity queries', () => {
    it('should get all entities', () => {
      const e1 = manager.createEntity();
      const e2 = manager.createEntity();

      const all = manager.getAllEntities();

      expect(all.length).toBe(2);
      expect(all).toContain(e1);
      expect(all).toContain(e2);
    });

    it('should query by component types', () => {
      const e1 = manager.createEntity();
      e1.addComponent({ type: 'position', x: 0, y: 0 } as PositionComponent);

      const e2 = manager.createEntity();
      e2.addComponent({ type: 'position', x: 1, y: 1 } as PositionComponent);
      e2.addComponent({ type: 'velocity', vx: 1, vy: 1 } as VelocityComponent);

      const e3 = manager.createEntity();
      e3.addComponent({ type: 'health', current: 100, max: 100 } as HealthComponent);

      const positionEntities = manager.query(['position']);
      expect(positionEntities.length).toBe(2);
      expect(positionEntities).toContain(e1);
      expect(positionEntities).toContain(e2);

      const posVelEntities = manager.query(['position', 'velocity']);
      expect(posVelEntities.length).toBe(1);
      expect(posVelEntities[0]).toBe(e2);
    });

    it('should return empty array for query with no matches', () => {
      manager.createEntity();

      const result = manager.query(['nonexistent']);
      expect(result).toEqual([]);
    });

    it('should queryAny for any matching component', () => {
      const e1 = manager.createEntity();
      e1.addComponent({ type: 'position', x: 0, y: 0 } as PositionComponent);

      const e2 = manager.createEntity();
      e2.addComponent({ type: 'health', current: 100, max: 100 } as HealthComponent);

      const e3 = manager.createEntity();
      e3.addComponent({ type: 'velocity', vx: 1, vy: 1 } as VelocityComponent);

      const result = manager.queryAny(['position', 'health']);
      expect(result.length).toBe(2);
      expect(result).toContain(e1);
      expect(result).toContain(e2);
    });
  });

  describe('entity count', () => {
    it('should track entity count', () => {
      expect(manager.entityCount).toBe(0);

      manager.createEntity();
      expect(manager.entityCount).toBe(1);

      manager.createEntity();
      expect(manager.entityCount).toBe(2);
    });

    it('should update count after removal', () => {
      const e1 = manager.createEntity();
      manager.createEntity();

      expect(manager.entityCount).toBe(2);

      manager.removeEntity(e1.id);
      expect(manager.entityCount).toBe(1);
    });
  });

  describe('clear', () => {
    it('should clear all entities', () => {
      manager.createEntity();
      manager.createEntity();
      manager.createEntity();

      manager.clear();

      expect(manager.entityCount).toBe(0);
      expect(manager.getAllEntities()).toEqual([]);
    });

    it('should reset entity ID counter', () => {
      manager.createEntity();
      manager.createEntity();

      manager.clear();

      const newEntity = manager.createEntity();
      expect(newEntity.id).toBe(1);
    });
  });
});

describe('System', () => {
  describe('abstract class', () => {
    it('should require name property', () => {
      class TestSystem extends System {
        name = 'TestSystem';
        update() {}
      }

      const system = new TestSystem();
      expect(system.name).toBe('TestSystem');
      expect(system.enabled).toBe(true);
      expect(system.priority).toBe(0);
    });

    it('should allow custom priority', () => {
      class HighPrioritySystem extends System {
        name = 'HighPriority';
        priority = 100;
        update() {}
      }

      const system = new HighPrioritySystem();
      expect(system.priority).toBe(100);
    });
  });
});

describe('SystemManager', () => {
  let manager: SystemManager;

  beforeEach(() => {
    manager = new SystemManager();
  });

  describe('system management', () => {
    it('should add system', () => {
      class TestSystem extends System {
        name = 'TestSystem';
        update = vi.fn();
      }

      const system = new TestSystem();
      manager.addSystem(system);

      expect(manager.getSystem('TestSystem')).toBe(system);
    });

    it('should call initialize when adding system', () => {
      class TestSystem extends System {
        name = 'TestSystem';
        update = vi.fn();
        initialize = vi.fn();
      }

      const system = new TestSystem();
      manager.addSystem(system);

      expect(system.initialize).toHaveBeenCalled();
    });

    it('should sort systems by priority', () => {
      const updateOrder: string[] = [];

      class LowPrioritySystem extends System {
        name = 'Low';
        priority = 10;
        update() {
          updateOrder.push('low');
        }
      }

      class HighPrioritySystem extends System {
        name = 'High';
        priority = 1;
        update() {
          updateOrder.push('high');
        }
      }

      class MidPrioritySystem extends System {
        name = 'Mid';
        priority = 5;
        update() {
          updateOrder.push('mid');
        }
      }

      manager.addSystem(new LowPrioritySystem());
      manager.addSystem(new HighPrioritySystem());
      manager.addSystem(new MidPrioritySystem());

      const entityManager = new EntityManager();
      manager.update(entityManager, { dt: 0.016, gameTime: 0, frameNumber: 0 });

      expect(updateOrder).toEqual(['high', 'mid', 'low']);
    });

    it('should remove system', () => {
      class TestSystem extends System {
        name = 'TestSystem';
        update = vi.fn();
      }

      const system = new TestSystem();
      manager.addSystem(system);
      manager.removeSystem('TestSystem');

      expect(manager.getSystem('TestSystem')).toBeUndefined();
    });

    it('should return false when removing non-existent system', () => {
      const result = manager.removeSystem('NonExistent');
      expect(result).toBe(false);
    });

    it('should call destroy when removing system', () => {
      class TestSystem extends System {
        name = 'TestSystem';
        update = vi.fn();
        destroy = vi.fn();
      }

      const system = new TestSystem();
      manager.addSystem(system);
      manager.removeSystem('TestSystem');

      expect(system.destroy).toHaveBeenCalled();
    });

    it('should skip disabled systems', () => {
      class TestSystem extends System {
        name = 'TestSystem';
        update = vi.fn();
      }

      const system = new TestSystem();
      system.enabled = false;
      manager.addSystem(system);

      const entityManager = new EntityManager();
      manager.update(entityManager, { dt: 0.016, gameTime: 0, frameNumber: 0 });

      expect(system.update).not.toHaveBeenCalled();
    });
  });

  describe('update cycle', () => {
    it('should call update on all enabled systems', () => {
      const entityManager = new EntityManager();
      const context = { dt: 0.016, gameTime: 0, frameNumber: 0 };

      class SystemA extends System {
        name = 'A';
        update = vi.fn();
      }

      class SystemB extends System {
        name = 'B';
        update = vi.fn();
      }

      manager.addSystem(new SystemA());
      manager.addSystem(new SystemB());

      manager.update(entityManager, context);

      expect(manager.getSystem<SystemA>('A')?.update).toHaveBeenCalledWith(
        entityManager,
        context
      );
      expect(manager.getSystem<SystemB>('B')?.update).toHaveBeenCalledWith(
        entityManager,
        context
      );
    });
  });

  describe('cleanup', () => {
    it('should call destroy on all systems when clearing', () => {
      class SystemA extends System {
        name = 'A';
        update = vi.fn();
        destroy = vi.fn();
      }

      class SystemB extends System {
        name = 'B';
        update = vi.fn();
        destroy = vi.fn();
      }

      const systemA = new SystemA();
      const systemB = new SystemB();

      manager.addSystem(systemA);
      manager.addSystem(systemB);
      manager.clear();

      expect(systemA.destroy).toHaveBeenCalled();
      expect(systemB.destroy).toHaveBeenCalled();
    });

    it('should remove all systems when clearing', () => {
      class TestSystem extends System {
        name = 'Test';
        update = vi.fn();
      }

      manager.addSystem(new TestSystem());
      manager.clear();

      // After clear, the systems array should be empty
      // So getSystem should return undefined
      expect(manager.getSystem('Test')).toBeUndefined();
    });
  });
});
