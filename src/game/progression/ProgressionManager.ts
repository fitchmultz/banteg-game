/**
 * Progression Manager
 *
 * Handles save/load for player progression, quest completion,
 * high scores, and statistics tracking.
 */

import type { QuestId, PerkId, WeaponId, CreatureTypeId, GameStats } from '../../types';
import { getQuestData, isQuestUnlocked, getStartingQuest } from '../data/quests';

// Storage key for localStorage
export const STORAGE_KEY = 'crimsonland_progression_v1';

// Current save version for migrations
const SAVE_VERSION = 1;

export interface QuestHighScore {
  bestTime: number; // Fastest completion time in seconds
  bestScore: number; // Highest score achieved
  completedAt: string; // ISO date string
  attempts: number; // Number of attempts
}

export interface SurvivalHighScore {
  bestScore: number;
  bestTime: number; // Longest survival time
  bestLevel: number; // Highest level reached
  achievedAt: string;
}

export interface PlayerStatistics {
  totalKills: number;
  totalDeaths: number;
  totalTimePlayed: number; // seconds
  totalQuestsCompleted: number;
  totalSurvivalRuns: number;
  perksChosen: Record<string, number>; // PerkId -> count
  killsByCreatureType: Record<string, number>; // CreatureTypeId -> count
  favoriteWeapon?: WeaponId;
  shotsFired: number;
  shotsHit: number;
  accuracy: number; // computed from shotsHit/shotsFired
}

export interface PlayerProgression {
  version: number;
  // Quest progress
  completedQuests: QuestId[];
  questHighScores: Partial<Record<QuestId, QuestHighScore>>;
  // Quest unlock indices (from decompiled quest_unlock_index, quest_unlock_index_full)
  questUnlockIndex: number; // Normal mode unlock progress
  questUnlockIndexFull: number; // Hardcore mode unlock progress
  // Survival progress
  survivalHighScore: SurvivalHighScore;
  // Statistics
  statistics: PlayerStatistics;
  // Meta
  unlockedFeatures: string[];
  lastPlayedAt: string;
  totalPlaySessions: number;
}

export interface ProgressionCallbacks {
  onQuestCompleted?: (questId: QuestId, highScore: QuestHighScore) => void;
  onNewSurvivalRecord?: (record: SurvivalHighScore) => void;
  onMilestoneReached?: (milestone: string) => void;
}

const DEFAULT_STATISTICS: PlayerStatistics = {
  totalKills: 0,
  totalDeaths: 0,
  totalTimePlayed: 0,
  totalQuestsCompleted: 0,
  totalSurvivalRuns: 0,
  perksChosen: {},
  killsByCreatureType: {},
  shotsFired: 0,
  shotsHit: 0,
  accuracy: 0,
};

const DEFAULT_SURVIVAL_HIGH_SCORE: SurvivalHighScore = {
  bestScore: 0,
  bestTime: 0,
  bestLevel: 0,
  achievedAt: new Date().toISOString(),
};

function createDefaultProgression(): PlayerProgression {
  return {
    version: SAVE_VERSION,
    completedQuests: [],
    questHighScores: {},
    questUnlockIndex: 0, // NEW: Quest unlock progress
    questUnlockIndexFull: 0, // NEW: Hardcore mode unlock progress
    survivalHighScore: { ...DEFAULT_SURVIVAL_HIGH_SCORE },
    statistics: { ...DEFAULT_STATISTICS },
    unlockedFeatures: [],
    lastPlayedAt: new Date().toISOString(),
    totalPlaySessions: 0,
  };
}

export class ProgressionManager {
  private data: PlayerProgression;
  private callbacks: ProgressionCallbacks;
  private dirty = false;

  constructor(callbacks: ProgressionCallbacks = {}) {
    this.callbacks = callbacks;
    this.data = this.load();
  }

  /**
   * Load progression from storage
   */
  private load(): PlayerProgression {
    try {
      const stored = localStorage.getItem(STORAGE_KEY);
      if (stored) {
        const parsed = JSON.parse(stored) as PlayerProgression;
        // Migrate if needed
        return this.migrate(parsed);
      }
    } catch (error) {
      console.warn('Failed to load progression:', error);
    }
    return createDefaultProgression();
  }

  /**
   * Migrate old save data to current version
   */
  private migrate(data: Partial<PlayerProgression>): PlayerProgression {
    const version = data.version ?? 0;

    if (version < SAVE_VERSION) {
      // Migration logic for future versions
      console.log(`Migrating save data from version ${version} to ${SAVE_VERSION}`);
    }

    return {
      ...createDefaultProgression(),
      ...data,
      version: SAVE_VERSION,
    };
  }

  /**
   * Save progression to storage
   */
  save(): void {
    if (!this.dirty) return;

    try {
      this.data.lastPlayedAt = new Date().toISOString();
      localStorage.setItem(STORAGE_KEY, JSON.stringify(this.data));
      this.dirty = false;
    } catch (error) {
      console.warn('Failed to save progression:', error);
    }
  }

  /**
   * Force save even if not dirty
   */
  forceSave(): void {
    this.dirty = true;
    this.save();
  }

  /**
   * Mark data as dirty (needs saving)
   */
  markDirty(): void {
    this.dirty = true;
  }

  // ============================================================================
  // Quest Progression
  // ============================================================================

  /**
   * Record quest completion
   */
  recordQuestComplete(
    questId: QuestId,
    stats: { time: number; score: number; kills: number }
  ): void {
    const now = new Date().toISOString();
    const existing = this.data.questHighScores[questId];

    const highScore: QuestHighScore = {
      bestTime: existing ? Math.min(existing.bestTime, stats.time) : stats.time,
      bestScore: existing ? Math.max(existing.bestScore, stats.score) : stats.score,
      completedAt: now,
      attempts: (existing?.attempts ?? 0) + 1,
    };

    this.data.questHighScores[questId] = highScore;

    if (!this.data.completedQuests.includes(questId)) {
      this.data.completedQuests.push(questId);
      this.data.statistics.totalQuestsCompleted++;
    }

    this.markDirty();
    try {
      this.callbacks.onQuestCompleted?.(questId, highScore);
    } catch (error) {
      console.warn('onQuestCompleted callback failed:', error);
    }
  }

  /**
   * Check if a quest is completed
   */
  isQuestCompleted(questId: QuestId): boolean {
    return this.data.completedQuests.includes(questId);
  }

  /**
   * Check if a quest is unlocked
   */
  isQuestUnlocked(questId: QuestId): boolean {
    // First quest is always unlocked
    if (questId === getStartingQuest()) return true;
    return isQuestUnlocked(questId, this.data.completedQuests);
  }

  /**
   * Get quest high score
   */
  getQuestHighScore(questId: QuestId): QuestHighScore | null {
    return this.data.questHighScores[questId] ?? null;
  }

  /**
   * Get all completed quests
   */
  getCompletedQuests(): QuestId[] {
    return [...this.data.completedQuests];
  }

  /**
   * Get all unlocked quests (completed + available)
   */
  getUnlockedQuests(): QuestId[] {
    return this.data.completedQuests.filter((questId) => this.isQuestUnlocked(questId));
  }

  /**
   * Get quest completion progress
   */
  getQuestProgress(): { completed: number; total: number; percentage: number } {
    const questData = getQuestData;
    // Count only non-bonus quests for main progress
    const mainQuests = Object.keys(this.data.questHighScores).filter((id) => {
      const q = questData(id as QuestId);
      return q && !q.isBonus;
    });

    // Total main quests (approximate based on unlock chain)
    const totalMainQuests = 20; // Known from quest data

    return {
      completed: mainQuests.length,
      total: totalMainQuests,
      percentage: Math.round((mainQuests.length / totalMainQuests) * 100),
    };
  }

  /**
   * Update quest unlock index (from decompiled quest_mode_update)
   * @param index The new unlock index
   * @param isHardcore Whether this is for hardcore mode
   */
  updateQuestUnlockIndex(index: number, isHardcore: boolean): void {
    if (index > this.data.questUnlockIndex) {
      this.data.questUnlockIndex = index;
      this.markDirty();
    }

    if (isHardcore && index > this.data.questUnlockIndexFull) {
      this.data.questUnlockIndexFull = index;
      this.markDirty();
    }
  }

  /**
   * Get current quest unlock index
   * @param isHardcore Whether to get hardcore mode index
   * @returns The current unlock index
   */
  getQuestUnlockIndex(isHardcore = false): number {
    if (isHardcore) {
      return this.data.questUnlockIndexFull;
    }
    return this.data.questUnlockIndex;
  }

  // ============================================================================
  // Survival Progression
  // ============================================================================

  /**
   * Record survival run results
   */
  recordSurvivalRun(stats: GameStats & { time: number }): void {
    const current = this.data.survivalHighScore;
    let newRecord = false;

    if (stats.score > current.bestScore) {
      current.bestScore = stats.score;
      newRecord = true;
    }

    if (stats.time > current.bestTime) {
      current.bestTime = stats.time;
      newRecord = true;
    }

    if (stats.level > current.bestLevel) {
      current.bestLevel = stats.level;
      newRecord = true;
    }

    if (newRecord) {
      current.achievedAt = new Date().toISOString();
      try {
        this.callbacks.onNewSurvivalRecord?.(current);
      } catch (error) {
        console.warn('onNewSurvivalRecord callback failed:', error);
      }
    }

    this.data.statistics.totalSurvivalRuns++;
    this.markDirty();
  }

  /**
   * Get survival high score
   */
  getSurvivalHighScore(): SurvivalHighScore {
    return { ...this.data.survivalHighScore };
  }

  // ============================================================================
  // Statistics Tracking
  // ============================================================================

  /**
   * Record a kill
   */
  recordKill(creatureTypeId: CreatureTypeId): void {
    this.data.statistics.totalKills++;

    const key = creatureTypeId.toString();
    this.data.statistics.killsByCreatureType[key] =
      (this.data.statistics.killsByCreatureType[key] ?? 0) + 1;

    this.markDirty();
  }

  /**
   * Record player death
   */
  recordDeath(): void {
    this.data.statistics.totalDeaths++;
    this.markDirty();
  }

  /**
   * Record time played
   */
  recordTimePlayed(seconds: number): void {
    this.data.statistics.totalTimePlayed += seconds;
    this.markDirty();
  }

  /**
   * Record perk chosen
   */
  recordPerkChosen(perkId: PerkId): void {
    const key = perkId.toString();
    this.data.statistics.perksChosen[key] = (this.data.statistics.perksChosen[key] ?? 0) + 1;
    this.markDirty();
  }

  /**
   * Record shots fired
   */
  recordShotsFired(count = 1): void {
    this.data.statistics.shotsFired += count;
    this.updateAccuracy();
    this.markDirty();
  }

  /**
   * Record shots hit
   */
  recordShotsHit(count = 1): void {
    this.data.statistics.shotsHit += count;
    this.updateAccuracy();
    this.markDirty();
  }

  /**
   * Update accuracy calculation
   */
  private updateAccuracy(): void {
    const { shotsFired, shotsHit } = this.data.statistics;
    if (shotsFired > 0) {
      this.data.statistics.accuracy = Math.round((shotsHit / shotsFired) * 100);
    }
  }

  /**
   * Set favorite weapon
   */
  setFavoriteWeapon(weaponId: WeaponId): void {
    this.data.statistics.favoriteWeapon = weaponId;
    this.markDirty();
  }

  /**
   * Get all statistics
   */
  getStatistics(): PlayerStatistics {
    return { ...this.data.statistics };
  }

  /**
   * Get specific stat
   */
  getStat<K extends keyof PlayerStatistics>(key: K): PlayerStatistics[K] {
    return this.data.statistics[key];
  }

  // ============================================================================
  // Features & Unlocks
  // ============================================================================

  /**
   * Unlock a feature
   */
  unlockFeature(feature: string): void {
    if (!this.data.unlockedFeatures.includes(feature)) {
      this.data.unlockedFeatures.push(feature);
      this.markDirty();
      try {
        this.callbacks.onMilestoneReached?.(feature);
      } catch (error) {
        console.warn('onMilestoneReached callback failed:', error);
      }
    }
  }

  /**
   * Check if a feature is unlocked
   */
  isFeatureUnlocked(feature: string): boolean {
    return this.data.unlockedFeatures.includes(feature);
  }

  /**
   * Get all unlocked features
   */
  getUnlockedFeatures(): string[] {
    return [...this.data.unlockedFeatures];
  }

  // ============================================================================
  // Session Management
  // ============================================================================

  /**
   * Start a new play session
   */
  startSession(): void {
    this.data.totalPlaySessions++;
    this.markDirty();
  }

  /**
   * Get total play sessions
   */
  getTotalSessions(): number {
    return this.data.totalPlaySessions;
  }

  /**
   * Get last played timestamp
   */
  getLastPlayedAt(): string {
    return this.data.lastPlayedAt;
  }

  // ============================================================================
  // Import/Export
  // ============================================================================

  /**
   * Export progression data as JSON string
   */
  exportData(): string {
    return JSON.stringify(this.data, null, 2);
  }

  /**
   * Import progression data from JSON string
   */
  importData(json: string): boolean {
    try {
      const parsed = JSON.parse(json) as PlayerProgression;
      this.data = this.migrate(parsed);
      this.markDirty();
      this.save();
      return true;
    } catch (error) {
      console.error('Failed to import progression data:', error);
      return false;
    }
  }

  /**
   * Reset all progression
   */
  reset(): void {
    this.data = createDefaultProgression();
    this.markDirty();
    this.save();
  }

  /**
   * Get raw data (for debugging)
   */
  getRawData(): PlayerProgression {
    return { ...this.data };
  }

  // ============================================================================
  // Milestones & Achievements
  // ============================================================================

  /**
   * Check and award milestones
   */
  checkMilestones(): string[] {
    const milestones: string[] = [];
    const stats = this.data.statistics;

    // Kill milestones
    if (stats.totalKills >= 100 && !this.isFeatureUnlocked('kills_100')) {
      this.unlockFeature('kills_100');
      milestones.push('100 Kills');
    }
    if (stats.totalKills >= 1000 && !this.isFeatureUnlocked('kills_1000')) {
      this.unlockFeature('kills_1000');
      milestones.push('1000 Kills');
    }
    if (stats.totalKills >= 10000 && !this.isFeatureUnlocked('kills_10000')) {
      this.unlockFeature('kills_10000');
      milestones.push('10000 Kills');
    }

    // Quest milestones
    const questProgress = this.getQuestProgress();
    if (questProgress.completed >= 5 && !this.isFeatureUnlocked('quests_5')) {
      this.unlockFeature('quests_5');
      milestones.push('5 Quests Completed');
    }
    if (questProgress.completed >= 10 && !this.isFeatureUnlocked('quests_10')) {
      this.unlockFeature('quests_10');
      milestones.push('10 Quests Completed');
    }
    if (questProgress.completed >= 20 && !this.isFeatureUnlocked('quests_all')) {
      this.unlockFeature('quests_all');
      milestones.push('All Quests Completed');
    }

    // Survival milestones
    if (this.data.survivalHighScore.bestLevel >= 10 && !this.isFeatureUnlocked('survival_10')) {
      this.unlockFeature('survival_10');
      milestones.push('Survival Level 10');
    }
    if (this.data.survivalHighScore.bestLevel >= 25 && !this.isFeatureUnlocked('survival_25')) {
      this.unlockFeature('survival_25');
      milestones.push('Survival Level 25');
    }

    return milestones;
  }
}
