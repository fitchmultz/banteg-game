/**
 * Survival Mode
 *
 * Infinite waves of enemies with escalating difficulty.
 * Perk selection on level up, high score tracking.
 */

import type { GameStats, PerkId, EntityId } from '../../types';
import type { EntityManager } from '../../core/ecs';
import type { SpawnSystem } from '../systems';
import type { PerkSystem } from '../systems/PerkSystem';
import type { ProgressionManager } from '../progression/ProgressionManager';

export interface SurvivalModeCallbacks {
  onWaveStart?: (wave: number) => void;
  onWaveComplete?: (wave: number) => void;
  onLevelUp?: (level: number) => void;
  onPerkSelectionStart?: (choices: PerkId[]) => void;
  onPerkSelected?: (perkId: PerkId) => void;
  onGameOver?: (stats: GameStats) => void;
  onXPChange?: (
    xp: number,
    progress: { current: number; required: number; percent: number }
  ) => void;
}

// XP required for each level
const XP_PER_LEVEL = [0, 100, 250, 500, 1000, 1500, 2500, 4000, 6000, 9000, 12000];

export class SurvivalMode {
  private spawnSystem: SpawnSystem;
  private perkSystem: PerkSystem | undefined;
  private callbacks: SurvivalModeCallbacks;
  private progressionManager: ProgressionManager | undefined;

  // Player progression
  private playerEntityId: EntityId | null = null;
  private playerXP = 0;
  private playerLevel = 1;
  private pendingLevelUps = 0;

  // Game state
  private isActive = false;
  private wave = 1;
  // private _startTime = 0; // TODO: Implement timing functionality
  private elapsedTime = 0;

  // Perk selection state
  private currentPerkChoices: PerkId[] = [];
  private isInPerkSelection = false;

  // Stats tracking
  private kills = 0;
  private score = 0;

  constructor(
    _entityManager: unknown,
    spawnSystem: SpawnSystem,
    callbacks: SurvivalModeCallbacks = {},
    perkSystem?: PerkSystem,
    progressionManager?: ProgressionManager
  ) {
    this.spawnSystem = spawnSystem;
    this.callbacks = callbacks;
    this.perkSystem = perkSystem;
    this.progressionManager = progressionManager;
  }

  /**
   * Set the player entity for perk application
   */
  setPlayerEntity(entityId: EntityId): void {
    this.playerEntityId = entityId;
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
    // this._startTime = performance.now();
    this.elapsedTime = 0;
    this.kills = 0;
    this.score = 0;
    this.currentPerkChoices = [];
    this.isInPerkSelection = false;

    // Start session tracking
    this.progressionManager?.startSession();

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
  update(dt: number): void {
    if (!this.isActive) return;

    this.elapsedTime += dt;

    // Update perk system (regeneration, etc.)
    // Note: PerkSystem.update expects (entityManager, context), but we're calling it directly
    // This is a simplified approach - in full implementation, PerkSystem should be added to SystemManager
    if (this.perkSystem) {
      this.perkSystem.update({} as EntityManager, { dt, gameTime: performance.now(), frameNumber: 0 });
    }

    // Check for pending level ups and trigger perk selection
    if (this.hasPendingLevelUp() && !this.isInPerkSelection && this.playerEntityId !== null) {
      this.startPerkSelection();
    }

    // Update wave
    const currentWave = this.spawnSystem.getWave();
    if (currentWave > this.wave) {
      this.wave = currentWave;
      this.callbacks.onWaveStart?.(this.wave);
    }
  }

  /**
   * Start perk selection
   */
  private startPerkSelection(): void {
    if (!this.perkSystem || this.playerEntityId === null) return;

    this.isInPerkSelection = true;
    this.currentPerkChoices = this.perkSystem.generatePerkChoices(this.playerEntityId, 3);

    this.callbacks.onPerkSelectionStart?.(this.currentPerkChoices);
  }

  /**
   * Select a perk from the current choices
   */
  selectPerk(choiceIndex: number): boolean {
    if (
      !this.isInPerkSelection ||
      choiceIndex < 0 ||
      choiceIndex >= this.currentPerkChoices.length
    ) {
      return false;
    }

    const perkId = this.currentPerkChoices[choiceIndex];
    if (perkId === undefined) return false;

    if (this.playerEntityId !== null && this.perkSystem) {
      const success = this.perkSystem.applyPerk(this.playerEntityId, perkId);

      if (success) {
        // Consume the level up
        this.consumeLevelUp();

        // Record in progression
        this.progressionManager?.recordPerkChosen(perkId);

        // Exit perk selection
        this.isInPerkSelection = false;
        this.currentPerkChoices = [];

        this.callbacks.onPerkSelected?.(perkId);
        return true;
      }
    }

    return false;
  }

  /**
   * Get current perk choices
   */
  getPerkChoices(): PerkId[] {
    return [...this.currentPerkChoices];
  }

  /**
   * Check if currently in perk selection
   */
  isSelectingPerk(): boolean {
    return this.isInPerkSelection;
  }

  /**
   * Cancel perk selection (use with caution - usually not allowed)
   */
  cancelPerkSelection(): void {
    this.isInPerkSelection = false;
    this.currentPerkChoices = [];
  }

  /**
   * Add XP to the player
   */
  addXP(amount: number): void {
    if (!this.isActive) return;

    // Apply XP multiplier from perks
    const multiplier =
      this.playerEntityId !== null
        ? (this.perkSystem?.getXpMultiplier(this.playerEntityId) ?? 1)
        : 1;

    const adjustedAmount = Math.floor(amount * multiplier);
    this.playerXP += adjustedAmount;

    // Check for level ups
    let leveledUp = false;
    while (
      this.playerLevel < XP_PER_LEVEL.length &&
      this.playerXP >= (XP_PER_LEVEL[this.playerLevel] ?? Number.POSITIVE_INFINITY)
    ) {
      this.pendingLevelUps++;
      this.playerLevel++;
      leveledUp = true;
      this.callbacks.onLevelUp?.(this.playerLevel);
    }

    if (leveledUp || amount > 0) {
      this.callbacks.onXPChange?.(this.playerXP, this.getXPProgress());
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
   * Get number of pending level ups
   */
  getPendingLevelUps(): number {
    return this.pendingLevelUps;
  }

  /**
   * Get XP progress to next level
   */
  getXPProgress(): { current: number; required: number; percent: number } {
    const currentLevelXP = XP_PER_LEVEL[this.playerLevel - 1] ?? 0;
    const nextLevelXP =
      XP_PER_LEVEL[this.playerLevel] ?? (XP_PER_LEVEL[XP_PER_LEVEL.length - 1] ?? 12000) * 2;
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
   * Get elapsed time in seconds
   */
  getElapsedTime(): number {
    return this.elapsedTime;
  }

  /**
   * Check if mode is active
   */
  isRunning(): boolean {
    return this.isActive;
  }

  /**
   * Record a kill
   */
  recordKill(rewardXP = 10): void {
    if (!this.isActive) return;

    this.kills++;
    this.addXP(rewardXP);
  }

  /**
   * Add score
   */
  addScore(points: number): void {
    if (!this.isActive) return;
    this.score += points;
  }

  /**
   * Get survival stats
   */
  getStats(): GameStats {
    return {
      score: this.score,
      kills: this.kills,
      timeElapsed: this.elapsedTime,
      level: this.playerLevel,
    };
  }

  /**
   * End the survival run and record stats
   */
  endRun(): GameStats {
    const stats = this.getStats();

    // Record in progression
    this.progressionManager?.recordSurvivalRun({
      ...stats,
      time: this.elapsedTime,
    });

    this.callbacks.onGameOver?.(stats);
    this.isActive = false;

    return stats;
  }

  /**
   * Get XP required for a specific level
   */
  static getXPForLevel(level: number): number {
    const xp = XP_PER_LEVEL[level];
    if (xp !== undefined) return xp;
    const lastXp = XP_PER_LEVEL[XP_PER_LEVEL.length - 1];
    return lastXp !== undefined ? lastXp * 2 : 24000;
  }

  /**
   * Get max level
   */
  static getMaxLevel(): number {
    return XP_PER_LEVEL.length;
  }
}
