/**
 * Quest Spawn System
 *
 * Handles time-based enemy spawning for quest mode.
 * Based on quest_spawn_timeline from decompiled source.
 */

import type { EntityManager } from '../../core/ecs';
import type { CreatureTypeId } from '../../types';
import type { QuestSpawnEntry, QuestData } from '../data/quests';
import { CreatureFactory } from '../entities';

export interface QuestSpawnSystemCallbacks {
  onSpawn?: (creatureTypeId: CreatureTypeId, count: number) => void;
  onTimelineComplete?: () => void;
}

export class QuestSpawnSystem {
  private entityManager: EntityManager;
  private callbacks: QuestSpawnSystemCallbacks;

  // Current quest data
  private questData: QuestData | null = null;

  // Timeline state
  private timelineMs = 0;
  private nextSpawnIndex = 0;
  private isActive = false;
  private isPaused = false;

  // Spawn area configuration
  private spawnRadius = 800;
  // private _mapWidth = 2048; // Reserved for future spawn boundary logic
  // private _mapHeight = 2048;

  constructor(
    entityManager: EntityManager,
    callbacks: QuestSpawnSystemCallbacks = {},
    options: { mapWidth?: number; mapHeight?: number; spawnRadius?: number } = {}
  ) {
    this.entityManager = entityManager;
    this.callbacks = callbacks;

    // Map dimensions reserved for future spawn boundary logic
    // if (options.mapWidth !== undefined) this._mapWidth = options.mapWidth;
    // if (options.mapHeight !== undefined) this._mapHeight = options.mapHeight;
    if (options.spawnRadius !== undefined) this.spawnRadius = options.spawnRadius;
  }

  /**
   * Start the spawn timeline for a quest
   */
  startQuest(questData: QuestData): void {
    this.questData = questData;
    this.timelineMs = 0;
    this.nextSpawnIndex = 0;
    this.isActive = true;
    this.isPaused = false;

    // Sort spawn entries by trigger time to ensure correct order
    questData.spawnEntries.sort((a, b) => a.triggerTimeMs - b.triggerTimeMs);
  }

  /**
   * Stop the spawn system
   */
  stop(): void {
    this.isActive = false;
    this.questData = null;
  }

  /**
   * Pause spawning
   */
  pause(): void {
    this.isPaused = true;
  }

  /**
   * Resume spawning
   */
  resume(): void {
    this.isPaused = false;
  }

  /**
   * Update the spawn timeline
   */
  update(dt: number): void {
    if (!this.isActive || this.isPaused || !this.questData) return;

    // Update timeline (convert dt from seconds to milliseconds)
    this.timelineMs += dt * 1000;

    // Process pending spawns
    this.processPendingSpawns();
  }

  /**
   * Process all spawn entries that should trigger by current timeline
   */
  private processPendingSpawns(): void {
    if (!this.questData) return;

    const spawnEntries = this.questData.spawnEntries;

    while (this.nextSpawnIndex < spawnEntries.length) {
      const entry = spawnEntries[this.nextSpawnIndex];
      if (!entry) break;

      if (entry.triggerTimeMs <= this.timelineMs) {
        this.spawnCreature(entry);
        this.nextSpawnIndex++;
      } else {
        // Next spawn is in the future, stop processing
        break;
      }
    }

    // Check if timeline is complete
    if (this.nextSpawnIndex >= spawnEntries.length) {
      this.callbacks.onTimelineComplete?.();
    }
  }

  /**
   * Spawn a creature based on entry data
   */
  private spawnCreature(entry: QuestSpawnEntry): void {
    const { creatureTypeId, x, y, count } = entry;

    for (let i = 0; i < count; i++) {
      // Determine spawn position
      let spawnX = x;
      let spawnY = y;

      // If position is 0,0 or not specified, use random position at edge
      if (x === 0 && y === 0) {
        const pos = this.getRandomSpawnPosition();
        spawnX = pos.x;
        spawnY = pos.y;
      }

      // Add slight randomization to prevent stacking
      spawnX += (Math.random() - 0.5) * 40;
      spawnY += (Math.random() - 0.5) * 40;

      CreatureFactory.createFromTemplate(this.entityManager, creatureTypeId, spawnX, spawnY);
    }

    this.callbacks.onSpawn?.(creatureTypeId, count);
  }

  /**
   * Get a random spawn position at the edge of the spawn radius
   */
  private getRandomSpawnPosition(): { x: number; y: number } {
    const angle = Math.random() * Math.PI * 2;
    const distance = this.spawnRadius + Math.random() * 200;

    return {
      x: Math.cos(angle) * distance,
      y: Math.sin(angle) * distance,
    };
  }

  /**
   * Get current timeline position in milliseconds
   */
  getTimelineMs(): number {
    return this.timelineMs;
  }

  /**
   * Get current timeline position in seconds
   */
  getTimelineSeconds(): number {
    return Math.floor(this.timelineMs / 1000);
  }

  /**
   * Get progress through the spawn timeline (0-1)
   */
  getProgress(): number {
    if (!this.questData || this.questData.spawnEntries.length === 0) {
      return 1;
    }

    const lastEntry = this.questData.spawnEntries[this.questData.spawnEntries.length - 1];
    if (!lastEntry) return 1;
    return Math.min(1, this.timelineMs / lastEntry.triggerTimeMs);
  }

  /**
   * Check if timeline is complete
   */
  isTimelineComplete(): boolean {
    if (!this.questData) return true;
    return this.nextSpawnIndex >= this.questData.spawnEntries.length;
  }

  /**
   * Get number of remaining spawn entries
   */
  getRemainingSpawns(): number {
    if (!this.questData) return 0;
    return this.questData.spawnEntries.length - this.nextSpawnIndex;
  }

  /**
   * Check if spawn table is empty (no pending spawns)
   * Mirrors quest_spawn_table_empty() from decompiled source @ 00434220
   * Returns true when quest_spawn_count is 0 or all entries have count <= 0
   */
  isSpawnTableEmpty(): boolean {
    if (!this.questData) return true;

    // Check if all remaining entries have count <= 0
    for (let i = this.nextSpawnIndex; i < this.questData.spawnEntries.length; i++) {
      const entry = this.questData.spawnEntries[i];
      if (entry && entry.count > 0) {
        return false;
      }
    }

    return true;
  }

  /**
   * Get time until next spawn in milliseconds
   */
  getTimeUntilNextSpawn(): number | null {
    if (!this.questData || this.nextSpawnIndex >= this.questData.spawnEntries.length) {
      return null;
    }

    const nextEntry = this.questData.spawnEntries[this.nextSpawnIndex];
    if (!nextEntry) return null;
    return Math.max(0, nextEntry.triggerTimeMs - this.timelineMs);
  }

  /**
   * Seek to a specific time in the timeline (for debugging/save states)
   */
  seekToTime(timeMs: number): void {
    if (!this.questData) return;

    this.timelineMs = timeMs;
    this.nextSpawnIndex = 0;

    // Find the next spawn index based on time
    for (let i = 0; i < this.questData.spawnEntries.length; i++) {
      const entry = this.questData.spawnEntries[i];
      if (entry && entry.triggerTimeMs > timeMs) {
        this.nextSpawnIndex = i;
        break;
      }
    }
  }

  /**
   * Check if spawn system is active
   */
  isRunning(): boolean {
    return this.isActive;
  }

  /**
   * Check if spawn system is paused
   */
  isSpawnPaused(): boolean {
    return this.isPaused;
  }

  /**
   * Get current quest data
   */
  getCurrentQuest(): QuestData | null {
    return this.questData;
  }

  /**
   * Force spawn a specific entry (for testing/debugging)
   */
  forceSpawn(entryIndex: number): boolean {
    if (!this.questData || entryIndex < 0 || entryIndex >= this.questData.spawnEntries.length) {
      return false;
    }

    const entry = this.questData.spawnEntries[entryIndex];
    if (!entry) return false;
    this.spawnCreature(entry);
    return true;
  }

  /**
   * Reset the spawn system
   */
  reset(): void {
    this.stop();
    this.timelineMs = 0;
    this.nextSpawnIndex = 0;
  }
}
