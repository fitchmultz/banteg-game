/**
 * Entity Component System - Entity
 *
 * Entities are lightweight identifiers that group components together.
 */

import type { Component, ComponentType, EntityId } from '../../types';
import type { ComponentTypeMap } from '../../game/components';

export class Entity {
  private components: Map<ComponentType, Component>;

  constructor(public readonly id: EntityId) {
    this.components = new Map();
  }

  addComponent<T extends Component>(component: T): this {
    this.components.set(component.type, component);
    return this;
  }

  removeComponent(type: ComponentType): boolean {
    return this.components.delete(type);
  }

  getComponent<T extends keyof ComponentTypeMap>(type: T): ComponentTypeMap[T] | undefined {
    return this.components.get(type) as ComponentTypeMap[T] | undefined;
  }

  hasComponent(type: ComponentType): boolean {
    return this.components.has(type);
  }

  hasComponents(types: ComponentType[]): boolean {
    return types.every((type) => this.components.has(type));
  }

  getComponentTypes(): ComponentType[] {
    return Array.from(this.components.keys());
  }

  clear(): void {
    this.components.clear();
  }

  get componentCount(): number {
    return this.components.size;
  }
}
