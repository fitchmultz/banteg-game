/**
 * Rush Spawn System
 *
 * ECS system that handles actual enemy spawning for Rush mode.
 * Receives spawn commands from RushMode and creates entities.
 *
 * Priority: 85 (between SpawnSystem and WeaponPickupSystem)
 */

import { System, type UpdateContext } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs/EntityManager';
import { CreatureFactory } from '../entities';
import { CreatureTypeId } from '../../types';

export interface RushSpawnSystemOptions {
  mapWidth?: number;
  mapHeight?: number;
}

export class RushSpawnSystem extends System {
  readonly name = 'RushSpawnSystem';
  readonly priority = 85;

  private entityManager: EntityManager;

  // Pending spawns to process this frame
  private pendingSpawns: Array<{ creatureTypeId: CreatureTypeId; x: number; y: number }> = [];

  // Active enemy count
  private activeEnemies = 0;

  constructor(entityManager: EntityManager, options: RushSpawnSystemOptions = {}) {
    super();
    this.entityManager = entityManager;
    // Options parameter reserved for future use
    void options;
  }

  update(_entityManager: EntityManager, _context: UpdateContext): void {
    // Process all pending spawns
    while (this.pendingSpawns.length > 0) {
      const spawn = this.pendingSpawns.shift();
      if (spawn) {
        this.spawnEnemy(spawn.creatureTypeId, spawn.x, spawn.y);
      }
    }
  }

  /**
   * Queue an enemy spawn
   * Called by RushMode.update() when it's time to spawn
   */
  queueSpawn(creatureTypeId: CreatureTypeId, x: number, y: number): void {
    this.pendingSpawns.push({ creatureTypeId, x, y });
  }

  /**
   * Actually spawn the enemy entity
   */
  private spawnEnemy(creatureTypeId: CreatureTypeId, x: number, y: number): void {
    // Create the creature
    const entity = CreatureFactory.create(this.entityManager, creatureTypeId, x, y);

    // Apply speed boost to fast zombies (as per decompiled source)
    if (creatureTypeId === CreatureTypeId.ZOMBIE_FAST) {
      const velocity = entity.getComponent<'velocity'>('velocity');
      if (velocity) {
        velocity.maxSpeed *= 1.4;
      }
    }

    this.activeEnemies++;
  }

  /**
   * Called when an enemy is defeated
   */
  onEnemyDefeated(): void {
    this.activeEnemies = Math.max(0, this.activeEnemies - 1);
  }

  /**
   * Get number of active enemies
   */
  getActiveEnemies(): number {
    return this.activeEnemies;
  }

  /**
   * Clear all pending spawns (e.g., on game over)
   */
  clearPendingSpawns(): void {
    this.pendingSpawns = [];
  }

  /**
   * Reset the system
   */
  reset(): void {
    this.pendingSpawns = [];
    this.activeEnemies = 0;
  }
}
