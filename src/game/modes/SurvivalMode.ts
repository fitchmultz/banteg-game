/**
 * Survival Mode
 *
 * Infinite waves of enemies with escalating difficulty.
 * Perk selection on level up, high score tracking.
 */

import type { GameStats } from '../../types';
import type { SpawnSystem } from '../systems';

export interface SurvivalModeCallbacks {
  onWaveStart?: (wave: number) => void;
  onWaveComplete?: (wave: number) => void;
  onLevelUp?: (level: number) => void;
  onGameOver?: (stats: GameStats) => void;
}

// XP required for each level
const XP_PER_LEVEL = [0, 100, 250, 500, 1000, 1500, 2500, 4000, 6000, 9000, 12000];

export class SurvivalMode {
  private spawnSystem: SpawnSystem;
  private callbacks: SurvivalModeCallbacks;

  // Player progression
  private playerXP = 0;
  private playerLevel = 1;
  private pendingLevelUps = 0;

  // Game state
  private isActive = false;
  private wave = 1;

  constructor(
    _entityManager: unknown,
    spawnSystem: SpawnSystem,
    callbacks: SurvivalModeCallbacks = {}
  ) {
    this.spawnSystem = spawnSystem;
    this.callbacks = callbacks;
  }

  /**
   * Start survival mode
   */
  start(): void {
    this.isActive = true;
    this.playerXP = 0;
    this.playerLevel = 1;
    this.pendingLevelUps = 0;
    this.wave = 1;

    this.callbacks.onWaveStart?.(this.wave);
  }

  /**
   * Stop survival mode
   */
  stop(): void {
    this.isActive = false;
  }

  /**
   * Update survival mode logic
   */
  update(): void {
    if (!this.isActive) return;

    // Update wave
    const currentWave = this.spawnSystem.getWave();
    if (currentWave > this.wave) {
      this.wave = currentWave;
      this.callbacks.onWaveStart?.(this.wave);
    }
  }

  /**
   * Add XP to the player
   */
  addXP(amount: number): void {
    if (!this.isActive) return;

    this.playerXP += amount;

    // Check for level ups
    while (
      this.playerLevel < XP_PER_LEVEL.length &&
      this.playerXP >= (XP_PER_LEVEL[this.playerLevel] ?? Number.POSITIVE_INFINITY)
    ) {
      this.pendingLevelUps++;
      this.playerLevel++;
      this.callbacks.onLevelUp?.(this.playerLevel);
    }
  }

  /**
   * Consume a pending level up
   */
  consumeLevelUp(): boolean {
    if (this.pendingLevelUps > 0) {
      this.pendingLevelUps--;
      return true;
    }
    return false;
  }

  /**
   * Check if there are pending level ups
   */
  hasPendingLevelUp(): boolean {
    return this.pendingLevelUps > 0;
  }

  /**
   * Get XP progress to next level
   */
  getXPProgress(): { current: number; required: number; percent: number } {
    const currentLevelXP = XP_PER_LEVEL[this.playerLevel - 1] ?? 0;
    const nextLevelXP = XP_PER_LEVEL[this.playerLevel] ?? (XP_PER_LEVEL[XP_PER_LEVEL.length - 1] ?? 12000) * 2;
    const required = nextLevelXP - currentLevelXP;
    const current = this.playerXP - currentLevelXP;
    const percent = Math.min(1, current / required);

    return { current, required, percent };
  }

  /**
   * Get current level
   */
  getLevel(): number {
    return this.playerLevel;
  }

  /**
   * Get total XP
   */
  getXP(): number {
    return this.playerXP;
  }

  /**
   * Get current wave
   */
  getWave(): number {
    return this.wave;
  }

  /**
   * Check if mode is active
   */
  isRunning(): boolean {
    return this.isActive;
  }

  /**
   * Get survival stats
   */
  getStats(): GameStats {
    return {
      score: this.playerXP,
      kills: this.spawnSystem.getSpawnedCount() - this.spawnSystem.getActiveEnemies(),
      timeElapsed: 0, // Would need to track this
      level: this.playerLevel,
    };
  }
}
