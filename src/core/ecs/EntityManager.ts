/**
 * Entity Component System - EntityManager
 *
 * Manages entity creation, destruction, and queries.
 */

import type { ComponentType, EntityId } from '../../types';
import type { ComponentTypeMap } from '../../game/components';
import { Entity } from './Entity';

export class EntityManager {
  private entities: Map<EntityId, Entity>;
  private nextId: EntityId;
  private toDestroy: Set<EntityId>;

  constructor() {
    this.entities = new Map();
    this.nextId = 1;
    this.toDestroy = new Set();
  }

  createEntity(): Entity {
    const id = this.nextId++;
    const entity = new Entity(id);
    this.entities.set(id, entity);
    return entity;
  }

  getEntity(id: EntityId): Entity | undefined {
    return this.entities.get(id);
  }

  hasEntity(id: EntityId): boolean {
    return this.entities.has(id);
  }

  destroyEntity(id: EntityId): boolean {
    if (!this.entities.has(id)) {
      return false;
    }
    this.toDestroy.add(id);
    return true;
  }

  removeEntity(id: EntityId): boolean {
    const entity = this.entities.get(id);
    if (!entity) {
      return false;
    }
    entity.clear();
    this.toDestroy.delete(id);
    return this.entities.delete(id);
  }

  processDestructions(): void {
    for (const id of this.toDestroy) {
      const entity = this.entities.get(id);
      if (entity) {
        entity.clear();
        this.entities.delete(id);
      }
    }
    this.toDestroy.clear();
  }

  getAllEntities(): Entity[] {
    return Array.from(this.entities.values());
  }

  query(componentTypes: ComponentType[]): Entity[] {
    const results: Entity[] = [];
    for (const entity of this.entities.values()) {
      if (entity.hasComponents(componentTypes)) {
        results.push(entity);
      }
    }
    return results;
  }

  queryAny(componentTypes: ComponentType[]): Entity[] {
    const results: Entity[] = [];
    for (const entity of this.entities.values()) {
      if (componentTypes.some((type) => entity.hasComponent(type))) {
        results.push(entity);
      }
    }
    return results;
  }

  /**
   * Get a component from an entity by its ID
   */
  getComponent<T extends keyof ComponentTypeMap>(
    entityId: EntityId,
    componentType: T
  ): ComponentTypeMap[T] | undefined {
    const entity = this.entities.get(entityId);
    if (!entity) return undefined;
    return entity.getComponent(componentType);
  }

  /**
   * Get all entity IDs that have a specific component
   */
  getEntitiesWithComponent(componentType: ComponentType): EntityId[] {
    const results: EntityId[] = [];
    for (const [id, entity] of this.entities) {
      if (entity.hasComponent(componentType)) {
        results.push(id);
      }
    }
    return results;
  }

  get entityCount(): number {
    return this.entities.size;
  }

  clear(): void {
    for (const entity of this.entities.values()) {
      entity.clear();
    }
    this.entities.clear();
    this.toDestroy.clear();
    this.nextId = 1;
  }
}
