/**
 * Quest Mode
 *
 * Structured levels with specific objectives and time-based enemy spawn patterns.
 * Updated with QuestSpawnSystem for timeline-based spawning.
 */

import type { EntityManager } from '../../core/ecs';
import type { QuestId, GameStats, CreatureTypeId } from '../../types';
import { getQuestData, getAvailableQuests, type QuestData, type QuestObjective } from '../data/quests';
import { QuestSpawnSystem } from '../systems/QuestSpawnSystem';
import type { ProgressionManager } from '../progression/ProgressionManager';

export interface QuestModeCallbacks {
  onQuestStart?: (questId: QuestId) => void;
  onQuestComplete?: (questId: QuestId, stats: GameStats) => void;
  onQuestFail?: (questId: QuestId, stats: GameStats) => void;
  onObjectiveUpdate?: (objective: QuestObjective, current: number, target: number) => void;
  onSpawn?: (creatureTypeId: CreatureTypeId, count: number) => void;
}

export class QuestMode {
  private _entityManager: EntityManager;
  private callbacks: QuestModeCallbacks;
  private progressionManager: ProgressionManager | undefined;

  // Quest spawn system
  private questSpawnSystem: QuestSpawnSystem;

  // Current quest state
  private currentQuest: QuestData | null = null;
  private currentQuestId: QuestId | null = null;
  private isActive = false;
  // private _startTime = 0; // TODO: Implement timing functionality

  // Progress tracking
  private killCount = 0;
  private survivalTime = 0;
  private killCountsByType = new Map<CreatureTypeId, number>();
  private score = 0;

  constructor(
    entityManager: EntityManager,
    callbacks: QuestModeCallbacks = {},
    progressionManager?: ProgressionManager
  ) {
    this._entityManager = entityManager;
    this.callbacks = callbacks;
    this.progressionManager = progressionManager;

    // Initialize quest spawn system
    this.questSpawnSystem = new QuestSpawnSystem(this._entityManager, {
      onSpawn: (creatureTypeId, count) => {
        this.callbacks.onSpawn?.(creatureTypeId, count);
      },
      onTimelineComplete: () => {
        // Timeline complete - all enemies spawned
      },
    });
  }

  /**
   * Start a quest
   */
  startQuest(questId: QuestId): boolean {
    const quest = getQuestData(questId);
    if (!quest) {
      console.warn(`Quest not found: ${questId}`);
      return false;
    }

    this.currentQuest = quest;
    this.currentQuestId = questId;
    this.isActive = true;
    // this._startTime = performance.now();

    // Reset progress
    this.killCount = 0;
    this.survivalTime = 0;
    this.killCountsByType.clear();
    this.score = 0;

    // Start spawn timeline
    this.questSpawnSystem.startQuest(quest);

    this.callbacks.onQuestStart?.(questId);
    return true;
  }

  /**
   * Stop current quest
   */
  stop(): void {
    this.isActive = false;
    this.currentQuest = null;
    this.currentQuestId = null;
    this.questSpawnSystem.stop();
  }

  /**
   * Update quest logic
   */
  update(dt: number): void {
    if (!this.isActive || !this.currentQuest) return;

    // Update spawn timeline
    this.questSpawnSystem.update(dt);

    // Update survival time
    this.survivalTime += dt;

    // Check time limit
    if (this.currentQuest.timeLimitMs) {
      const elapsedMs = this.survivalTime * 1000;
      if (elapsedMs >= this.currentQuest.timeLimitMs) {
        this.failQuest('time_limit');
        return;
      }
    }

    // Check objectives
    this.checkObjectives();
  }

  /**
   * Record a kill
   */
  recordKill(creatureTypeId?: CreatureTypeId, rewardValue = 10): void {
    if (!this.isActive) return;

    this.killCount++;
    this.score += rewardValue;

    if (creatureTypeId !== undefined) {
      const current = this.killCountsByType.get(creatureTypeId) ?? 0;
      this.killCountsByType.set(creatureTypeId, current + 1);
    }

    // Track kill in progression
    if (creatureTypeId !== undefined) {
      this.progressionManager?.recordKill(creatureTypeId);
    }

    // Re-check objectives after kill
    this.checkObjectives();
  }

  /**
   * Add score
   */
  addScore(points: number): void {
    if (!this.isActive) return;
    this.score += points;
  }

  /**
   * Get current quest
   */
  getCurrentQuest(): QuestData | null {
    return this.currentQuest;
  }

  /**
   * Get current quest ID
   */
  getCurrentQuestId(): QuestId | null {
    return this.currentQuestId;
  }

  /**
   * Get quest progress
   */
  getProgress(): {
    kills: number;
    time: number;
    score: number;
    timelineProgress: number;
    killCountsByType: Map<CreatureTypeId, number>;
  } {
    return {
      kills: this.killCount,
      time: this.survivalTime,
      score: this.score,
      timelineProgress: this.questSpawnSystem.getProgress(),
      killCountsByType: new Map(this.killCountsByType),
    };
  }

  /**
   * Check if mode is active
   */
  isRunning(): boolean {
    return this.isActive;
  }

  /**
   * Get the quest spawn system
   */
  getSpawnSystem(): QuestSpawnSystem {
    return this.questSpawnSystem;
  }

  /**
   * Pause the quest
   */
  pause(): void {
    this.questSpawnSystem.pause();
  }

  /**
   * Resume the quest
   */
  resume(): void {
    this.questSpawnSystem.resume();
  }

  /**
   * Get remaining time if there's a time limit
   */
  getRemainingTime(): number | null {
    if (!this.currentQuest?.timeLimitMs) return null;

    const elapsedMs = this.survivalTime * 1000;
    const remainingMs = this.currentQuest.timeLimitMs - elapsedMs;
    return Math.max(0, remainingMs / 1000);
  }

  /**
   * Get current game stats
   */
  getStats(): GameStats {
    return {
      score: this.score,
      kills: this.killCount,
      timeElapsed: this.survivalTime,
      level: 1, // Quests don't use levels
    };
  }

  private checkObjectives(): void {
    if (!this.currentQuest) return;

    let allComplete = true;

    for (const objective of this.currentQuest.objectives) {
      let complete = false;
      let current = 0;

      switch (objective.type) {
        case 'kill_count':
          if (objective.creatureTypeId !== undefined) {
            current = this.killCountsByType.get(objective.creatureTypeId) ?? 0;
          } else {
            current = this.killCount;
          }
          complete = current >= objective.target;
          break;

        case 'survive_time':
          current = Math.floor(this.survivalTime);
          complete = this.survivalTime >= objective.target;
          break;

        case 'reach_location':
          // Would need player position check - not implemented
          current = 0;
          complete = false;
          break;

        case 'kill_bosses':
          // Similar to kill_count but for boss types
          current = this.killCount; // Simplified
          complete = current >= objective.target;
          break;
      }

      if (!complete) {
        allComplete = false;
      }

      // Notify on objective update (throttle to avoid spam)
      if (current !== objective.target) {
        this.callbacks.onObjectiveUpdate?.(objective, current, objective.target);
      }
    }

    if (allComplete) {
      this.completeQuest();
    }
  }

  private completeQuest(): void {
    if (!this.currentQuest || !this.currentQuestId) return;

    const stats = this.getStats();

    // Record completion in progression
    this.progressionManager?.recordQuestComplete(this.currentQuestId, {
      time: this.survivalTime,
      score: this.score,
      kills: this.killCount,
    });

    this.callbacks.onQuestComplete?.(this.currentQuestId, stats);
    this.isActive = false;
  }

  private failQuest(_reason: string): void {
    if (!this.currentQuest || !this.currentQuestId) return;

    const stats = this.getStats();

    this.callbacks.onQuestFail?.(this.currentQuestId, stats);
    this.isActive = false;
  }

  /**
   * Get all available quests (static helper)
   */
  static getAvailableQuests(): QuestId[] {
    return getAvailableQuests([]);
  }

  /**
   * Get quest data (static helper)
   */
  static getQuestData(questId: QuestId): QuestData | null {
    return getQuestData(questId) ?? null;
  }
}
