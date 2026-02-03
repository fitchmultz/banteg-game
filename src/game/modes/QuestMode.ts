/**
 * Quest Mode
 *
 * Structured levels with specific objectives and enemy spawn patterns.
 */

import type { EntityManager } from '../../core/ecs';
import type { QuestId, GameStats } from '../../types';
import { CreatureFactory } from '../entities';

export interface QuestModeCallbacks {
  onQuestStart?: (questId: QuestId) => void;
  onQuestComplete?: (questId: QuestId) => void;
  onGameOver?: (stats: GameStats) => void;
}

export interface QuestObjective {
  type: 'kill_count' | 'survive_time' | 'reach_location';
  target: number;
  description: string;
}

export interface QuestData {
  id: QuestId;
  name: string;
  description: string;
  objectives: QuestObjective[];
  spawnTemplates: Array<{ templateId: number; x: number; y: number }>;
}

// Quest definitions (simplified - only a few quests defined)
const QUESTS: Partial<Record<QuestId, QuestData>> = {
  'nagolipoli': {
    id: 'nagolipoli',
    name: 'Nagolipoli',
    description: 'Survive the initial zombie outbreak.',
    objectives: [{ type: 'survive_time', target: 60, description: 'Survive for 60 seconds' }],
    spawnTemplates: [
      { templateId: 0x38, x: 100, y: 100 },
      { templateId: 0x38, x: -100, y: 100 },
    ],
  },
  'monster_blues': {
    id: 'monster_blues',
    name: 'Monster Blues',
    description: 'Eliminate 50 zombies.',
    objectives: [{ type: 'kill_count', target: 50, description: 'Kill 50 zombies' }],
    spawnTemplates: [
      { templateId: 0x38, x: 200, y: 200 },
      { templateId: 0x41, x: -200, y: 200 },
    ],
  },
  'the_gathering': {
    id: 'the_gathering',
    name: 'The Gathering',
    description: 'Face increasing waves.',
    objectives: [{ type: 'kill_count', target: 100, description: 'Kill 100 enemies' }],
    spawnTemplates: [],
  },
  'army_of_three': {
    id: 'army_of_three',
    name: 'Army of Three',
    description: 'Three powerful enemies await.',
    objectives: [{ type: 'kill_count', target: 3, description: 'Kill 3 elite enemies' }],
    spawnTemplates: [],
  },
};

export class QuestMode {
  private entityManager: EntityManager;
  private callbacks: QuestModeCallbacks;

  // Current quest
  private currentQuest: QuestData | null = null;
  private isActive = false;

  // Progress tracking
  private killCount = 0;
  private survivalTime = 0;

  constructor(entityManager: EntityManager, callbacks: QuestModeCallbacks = {}) {
    this.entityManager = entityManager;
    this.callbacks = callbacks;
  }

  /**
   * Start a quest
   */
  startQuest(questId: QuestId): boolean {
    const quest = QUESTS[questId];
    if (!quest) {
      console.warn(`Quest not found: ${questId}`);
      return false;
    }

    this.currentQuest = quest;
    this.isActive = true;
    this.killCount = 0;
    this.survivalTime = 0;

    // Spawn initial enemies
    this.spawnQuestEntities();

    this.callbacks.onQuestStart?.(questId);
    return true;
  }

  /**
   * Stop current quest
   */
  stop(): void {
    this.isActive = false;
    this.currentQuest = null;
  }

  /**
   * Update quest logic
   */
  update(dt: number): void {
    if (!this.isActive || !this.currentQuest) return;

    this.survivalTime += dt;

    // Check objectives
    this.checkObjectives();
  }

  /**
   * Record a kill
   */
  recordKill(): void {
    this.killCount++;
  }

  /**
   * Get current quest
   */
  getCurrentQuest(): QuestData | null {
    return this.currentQuest;
  }

  /**
   * Get quest progress
   */
  getProgress(): { kills: number; time: number } {
    return { kills: this.killCount, time: this.survivalTime };
  }

  /**
   * Check if mode is active
   */
  isRunning(): boolean {
    return this.isActive;
  }

  private spawnQuestEntities(): void {
    if (!this.currentQuest) return;

    for (const spawn of this.currentQuest.spawnTemplates) {
      CreatureFactory.createFromTemplate(
        this.entityManager,
        spawn.templateId,
        spawn.x,
        spawn.y
      );
    }
  }

  private checkObjectives(): void {
    if (!this.currentQuest) return;

    let allComplete = true;

    for (const objective of this.currentQuest.objectives) {
      let complete = false;

      switch (objective.type) {
        case 'kill_count':
          complete = this.killCount >= objective.target;
          break;
        case 'survive_time':
          complete = this.survivalTime >= objective.target;
          break;
        case 'reach_location':
          // Would need player position check
          complete = false;
          break;
      }

      if (!complete) {
        allComplete = false;
        break;
      }
    }

    if (allComplete) {
      this.completeQuest();
    }
  }

  private completeQuest(): void {
    if (!this.currentQuest) return;

    this.callbacks.onQuestComplete?.(this.currentQuest.id);
    this.isActive = false;
  }

  /**
   * Get all available quests
   */
  static getAvailableQuests(): QuestId[] {
    return Object.keys(QUESTS) as QuestId[];
  }

  /**
   * Get quest data
   */
  static getQuestData(questId: QuestId): QuestData | null {
    return QUESTS[questId] ?? null;
  }
}
