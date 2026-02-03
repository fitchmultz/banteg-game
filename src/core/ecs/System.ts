/**
 * Entity Component System - System
 *
 * Systems process entities with specific components each frame.
 */

import type { EntityManager } from './EntityManager';

export interface UpdateContext {
  dt: number;
  gameTime: number;
  frameNumber: number;
}

export abstract class System {
  abstract readonly name: string;
  enabled = true;
  readonly priority: number = 0;

  initialize?(): void;
  abstract update(entityManager: EntityManager, context: UpdateContext): void;
  destroy?(): void;
}

export class SystemManager {
  private systems: System[] = [];

  addSystem(system: System): void {
    this.systems.push(system);
    this.systems.sort((a, b) => a.priority - b.priority);

    if (system.initialize) {
      system.initialize();
    }
  }

  removeSystem(name: string): boolean {
    const index = this.systems.findIndex((s) => s.name === name);
    if (index === -1) {
      return false;
    }

    const system = this.systems[index];
    if (system?.destroy) {
      system.destroy();
    }

    this.systems.splice(index, 1);
    return true;
  }

  getSystem<T extends System>(name: string): T | undefined {
    return this.systems.find((s) => s.name === name) as T | undefined;
  }

  update(entityManager: EntityManager, context: UpdateContext): void {
    for (const system of this.systems) {
      if (system.enabled) {
        system.update(entityManager, context);
      }
    }
  }

  clear(): void {
    for (const system of this.systems) {
      if (system.destroy) {
        system.destroy();
      }
    }
    this.systems = [];
  }
}
