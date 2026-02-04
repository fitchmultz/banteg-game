/**
 * Tutorial Mode
 *
 * Interactive tutorial with stage-based progression:
 * - Stage 0: Introduction (auto-advance after 6s)
 * - Stage 1: Movement (wait for WASD input, then spawn bonuses)
 * - Stage 2: Collect bonuses (wait for all bonuses to be collected)
 * - Stage 3: Shoot (wait for fire input, then spawn enemies)
 * - Stage 4: Clear pack (wait for enemies cleared, spawn another pack)
 * - Stage 5: Practice loop (repeat pack+bonus cycles)
 * - Stage 6: Perk selection (grant XP, wait for perk chosen)
 * - Stage 7: Final clear (clear remaining enemies)
 * - Stage 8: Complete (victory)
 *
 * Ported from tutorial_timeline_update in decompiled source.
 *
 * Invariants:
 * - Player health is kept at 100 throughout tutorial
 * - XP is reset to 0 except during perk selection stage
 * - Stages progress based on player actions, not just time
 * - Scripted spawns happen at specific stage transitions
 */

import type { GameStats, EntityId, CreatureTypeId } from '../../types';
import type { EntityManager } from '../../core/ecs';
import type { ProgressionManager } from '../progression/ProgressionManager';
import { BonusType } from '../../types';

export type TutorialStage =
  | 0 // Intro
  | 1 // Movement
  | 2 // Collect bonuses
  | 3 // Shoot
  | 4 // Clear first pack
  | 5 // Practice loop
  | 6 // Perk selection
  | 7 // Final clear
  | 8; // Complete

export interface TutorialModeCallbacks {
  onStageChange?: (stage: TutorialStage, previousStage: TutorialStage) => void;
  onComplete?: (stats: GameStats) => void;
  onRequestPerkSelection?: () => void;
  onSpawnBonuses?: (bonuses: Array<{ type: BonusType; x: number; y: number; value?: number }>) => void;
  onSpawnEnemies?: (enemies: Array<{ creatureTypeId: CreatureTypeId; x: number; y: number }>) => void;
}

export interface TutorialModeOptions {
  introDurationMs?: number;
  practiceLoopCount?: number;
  xpForPerkSelection?: number;
}

export class TutorialMode {
  private entityManager: EntityManager;
  private callbacks: TutorialModeCallbacks;
  // Progression manager - reserved for future use
  // @ts-expect-error - unused for now but part of consistent mode interface
  private _progressionManager: ProgressionManager | undefined;
  private options: Required<TutorialModeOptions>;

  // Stage state
  private currentStage: TutorialStage = 0;
  private stageTimerMs = 0;
  private stageTransitionTimer = -1;
  private isActive = false;

  // Practice loop tracking
  private practiceLoopCount = 0;

  // Perk selection state
  private isInPerkSelection = false;
  private pendingPerkSelection = false;

  // Stats tracking
  private kills = 0;
  private elapsedTime = 0;

  // Player reference
  private playerEntityId: EntityId | null = null;

  // Track spawned bonuses/enemies for completion checking
  private spawnedBonuses = 0;
  private spawnedEnemies = 0;

  constructor(
    entityManager: EntityManager,
    callbacks: TutorialModeCallbacks = {},
    progressionManager?: ProgressionManager,
    options: TutorialModeOptions = {}
  ) {
    this.entityManager = entityManager;
    this.callbacks = callbacks;
    // Store progression manager for future use
    // eslint-disable-next-line @typescript-eslint/no-unused-vars
    this._progressionManager = progressionManager;
    this.options = {
      introDurationMs: 6000,
      practiceLoopCount: 8,
      xpForPerkSelection: 3000,
      ...options,
    };
  }

  /**
   * Set the player entity
   */
  setPlayerEntity(entityId: EntityId): void {
    this.playerEntityId = entityId;
  }

  /**
   * Start the tutorial
   */
  start(): void {
    this.isActive = true;
    this.currentStage = 0;
    this.stageTimerMs = 0;
    this.stageTransitionTimer = -1;
    this.practiceLoopCount = 0;
    this.isInPerkSelection = false;
    this.pendingPerkSelection = false;
    this.kills = 0;
    this.elapsedTime = 0;
    this.spawnedBonuses = 0;
    this.spawnedEnemies = 0;

    // Keep player healthy
    this.healPlayerToFull();

    this.callbacks.onStageChange?.(0, 0);
  }

  /**
   * Stop the tutorial
   */
  stop(): void {
    this.isActive = false;
  }

  /**
   * Update tutorial logic
   * Called every frame by GameModeSystem
   */
  update(dt: number): void {
    if (!this.isActive) return;

    this.elapsedTime += dt;
    this.stageTimerMs += dt * 1000;

    // Keep player at full health throughout tutorial
    this.healPlayerToFull();

    // Update stage transition timer
    if (this.stageTransitionTimer > -1) {
      this.stageTransitionTimer += dt * 1000;
      if (this.stageTransitionTimer >= 1000) {
        this.stageTransitionTimer = -1;
      }
    }

    // Process current stage
    this.processCurrentStage();
  }

  /**
   * Process logic for the current stage
   */
  private processCurrentStage(): void {
    switch (this.currentStage) {
      case 0:
        this.processIntroStage();
        break;
      case 1:
        // Stage 1 advances on movement input (checked via checkStageProgression)
        break;
      case 2:
        // Stage 2 advances when all bonuses collected (checked via checkStageProgression)
        break;
      case 3:
        // Stage 3 advances on fire input (checked via checkStageProgression)
        break;
      case 4:
        // Stage 4 advances when enemies cleared (checked via checkStageProgression)
        break;
      case 5:
        // Stage 5 is the practice loop (checked via checkStageProgression)
        break;
      case 6:
        // Stage 6 advances after perk selection
        this.processPerkSelectionStage();
        break;
      case 7:
        // Stage 7 advances when enemies cleared (checked via checkStageProgression)
        break;
      case 8:
        // Tutorial complete
        this.completeTutorial();
        break;
    }
  }

  private processIntroStage(): void {
    // Auto-advance after intro duration
    if (this.stageTimerMs >= this.options.introDurationMs && this.stageTransitionTimer === -1) {
      this.advanceStage();
    }
  }

  private processPerkSelectionStage(): void {
    // Grant XP for perk selection if not already done
    if (!this.pendingPerkSelection && !this.isInPerkSelection) {
      this.pendingPerkSelection = true;
      this.isInPerkSelection = true;
      this.callbacks.onRequestPerkSelection?.();
    }
  }

  /**
   * Check if stage can progress based on world state
   * Called from main.ts to coordinate with actual game state
   */
  checkStageProgression(checks: {
    hasMovementInput?: boolean;
    hasFireInput?: boolean;
    remainingBonuses?: number;
    remainingEnemies?: number;
  }): void {
    // Note: We don't check stageTransitionTimer here because it's for visual fade effects only
    // Game logic progression should not be blocked by visual transitions
    if (!this.isActive) return;

    switch (this.currentStage) {
      case 1: // Movement
        if (checks.hasMovementInput) {
          this.spawnTutorialBonuses();
          this.advanceStage();
        }
        break;

      case 2: // Collect bonuses
        if ((checks.remainingBonuses ?? 0) === 0 && this.spawnedBonuses > 0) {
          this.advanceStage();
        }
        break;

      case 3: // Shoot
        if (checks.hasFireInput) {
          this.spawnFirstEnemyPack();
          this.advanceStage();
        }
        break;

      case 4: // Clear first pack
        if ((checks.remainingEnemies ?? 1) === 0 && this.spawnedEnemies > 0) {
          this.spawnSecondEnemyPack();
          this.advanceStage();
        }
        break;

      case 5: // Practice loop
        if ((checks.remainingEnemies ?? 1) === 0 && this.spawnedEnemies > 0) {
          this.handlePracticeLoopIteration();
        }
        break;

      case 7: // Final clear
        if ((checks.remainingEnemies ?? 1) === 0 && this.spawnedEnemies > 0) {
          this.advanceStage();
        }
        break;
    }
  }

  /**
   * Handle practice loop iteration
   */
  private handlePracticeLoopIteration(): void {
    this.practiceLoopCount++;

    if (this.practiceLoopCount >= this.options.practiceLoopCount) {
      // Grant XP to trigger perk selection
      this.grantXPForPerkSelection();
      this.advanceStage();
    } else {
      // Spawn next wave
      this.spawnPracticeWave();
    }
  }

  /**
   * Advance to the next stage
   */
  private advanceStage(): void {
    if (this.currentStage >= 8) return;

    const previousStage = this.currentStage;
    this.currentStage = (this.currentStage + 1) as TutorialStage;
    this.stageTimerMs = 0;
    this.stageTransitionTimer = 0;

    // Note: spawnedBonuses and spawnedEnemies are NOT reset here
    // because stages 2, 4 need to verify collection of items spawned in previous stages

    this.callbacks.onStageChange?.(this.currentStage, previousStage);
  }

  /**
   * Spawn tutorial bonuses at fixed positions
   */
  private spawnTutorialBonuses(): void {
    const bonuses = [
      { type: BonusType.SPEED_BOOST, x: 260, y: 260, value: 500 },
      { type: BonusType.WEAPON_POWER_UP, x: 600, y: 400, value: 1000 },
      { type: BonusType.EXP_MULTIPLIER, x: 300, y: 400, value: 500 },
    ];
    this.spawnedBonuses = bonuses.length;
    this.callbacks.onSpawnBonuses?.(bonuses);
  }

  /**
   * Spawn first enemy pack (from left)
   */
  private spawnFirstEnemyPack(): void {
    const enemies = [
      { creatureTypeId: 0 as CreatureTypeId, x: -164, y: 412 }, // ZOMBIE
      { creatureTypeId: 1 as CreatureTypeId, x: -184, y: 512 }, // ZOMBIE_FAST
      { creatureTypeId: 0 as CreatureTypeId, x: -154, y: 612 }, // ZOMBIE
    ];
    this.spawnedEnemies = enemies.length;
    this.callbacks.onSpawnEnemies?.(enemies);
  }

  /**
   * Spawn second enemy pack (from right)
   */
  private spawnSecondEnemyPack(): void {
    const enemies = [
      { creatureTypeId: 0 as CreatureTypeId, x: 1188, y: 412 }, // ZOMBIE
      { creatureTypeId: 1 as CreatureTypeId, x: 1208, y: 512 }, // ZOMBIE_FAST
      { creatureTypeId: 0 as CreatureTypeId, x: 1178, y: 612 }, // ZOMBIE
    ];
    this.spawnedEnemies = enemies.length;
    this.callbacks.onSpawnEnemies?.(enemies);
  }

  /**
   * Spawn practice wave (alternating sides)
   */
  private spawnPracticeWave(): void {
    const fromRight = this.practiceLoopCount % 2 === 0;

    let enemies: Array<{ creatureTypeId: CreatureTypeId; x: number; y: number }>;

    if (fromRight) {
      enemies = [
        { creatureTypeId: 0 as CreatureTypeId, x: 1188, y: 1136 }, // ZOMBIE
        { creatureTypeId: 1 as CreatureTypeId, x: 1208, y: 512 }, // ZOMBIE_FAST
        { creatureTypeId: 0 as CreatureTypeId, x: 1178, y: 612 }, // ZOMBIE
      ];
    } else {
      enemies = [
        { creatureTypeId: 0 as CreatureTypeId, x: -164, y: 412 }, // ZOMBIE
        { creatureTypeId: 1 as CreatureTypeId, x: -184, y: 512 }, // ZOMBIE_FAST
        { creatureTypeId: 0 as CreatureTypeId, x: -154, y: 612 }, // ZOMBIE
      ];
    }

    // Spawn bonus on certain iterations
    if (this.practiceLoopCount < 6 && this.practiceLoopCount % 2 === 1) {
      const bonusType = this.getBonusTypeForLoop(this.practiceLoopCount);
      const bonusX = fromRight ? 1056 : -32;
      this.callbacks.onSpawnBonuses?.([{ type: bonusType, x: bonusX, y: 1056 }]);
      this.spawnedBonuses = 1;
    }

    this.spawnedEnemies = enemies.length;
    this.callbacks.onSpawnEnemies?.(enemies);
  }

  private getBonusTypeForLoop(loop: number): BonusType {
    switch (loop) {
      case 1:
        return BonusType.SPEED_BOOST;
      case 3:
        return BonusType.WEAPON_POWER_UP;
      case 5:
        return BonusType.EXP_MULTIPLIER;
      default:
        return BonusType.HEALTH;
    }
  }

  /**
   * Grant XP to trigger perk selection
   */
  private grantXPForPerkSelection(): void {
    if (this.playerEntityId === null) return;

    const player = this.entityManager.getEntity(this.playerEntityId);
    if (!player) return;

    const playerComp = player.getComponent<'player'>('player');
    if (playerComp) {
      playerComp.experience = this.options.xpForPerkSelection;
    }
  }

  /**
   * Heal player to full health
   */
  private healPlayerToFull(): void {
    if (this.playerEntityId === null) return;

    const player = this.entityManager.getEntity(this.playerEntityId);
    if (!player) return;

    // Heal player to full - access health component generically
    // @ts-expect-error - ComponentTypeMap doesn't include health yet
    const healthComp = player.getComponent('health');
    if (healthComp && 'current' in healthComp && 'max' in healthComp) {
      (healthComp as { current: number; max: number }).current = (
        healthComp as { current: number; max: number }
      ).max;
    }
  }

  /**
   * Called when perk selection is completed
   */
  onPerkSelected(): void {
    this.isInPerkSelection = false;
    // Spawn final enemies after perk selection
    this.spawnFinalEnemies();
  }

  /**
   * Spawn final enemies after perk selection
   */
  private spawnFinalEnemies(): void {
    const enemies = [
      { creatureTypeId: 0 as CreatureTypeId, x: -164, y: 412 },
      { creatureTypeId: 1 as CreatureTypeId, x: -184, y: 512 },
      { creatureTypeId: 0 as CreatureTypeId, x: -154, y: 612 },
      { creatureTypeId: 0 as CreatureTypeId, x: -32, y: -32 },
      { creatureTypeId: 0 as CreatureTypeId, x: 1188, y: 412 },
      { creatureTypeId: 1 as CreatureTypeId, x: 1208, y: 512 },
      { creatureTypeId: 0 as CreatureTypeId, x: 1178, y: 612 },
    ];
    this.spawnedEnemies = enemies.length;
    this.callbacks.onSpawnEnemies?.(enemies);
  }

  /**
   * Complete the tutorial
   */
  private completeTutorial(): void {
    const stats = this.getStats();
    this.callbacks.onComplete?.(stats);
    this.isActive = false;
  }

  /**
   * Get current stage
   */
  getCurrentStage(): TutorialStage {
    return this.currentStage;
  }

  /**
   * Get stage timer in ms
   */
  getStageTimerMs(): number {
    return this.stageTimerMs;
  }

  /**
   * Get elapsed time in seconds
   */
  getElapsedTime(): number {
    return this.elapsedTime;
  }

  /**
   * Check if in perk selection
   */
  isSelectingPerk(): boolean {
    return this.isInPerkSelection;
  }

  /**
   * Record a kill
   */
  recordKill(): void {
    if (!this.isActive) return;
    this.kills++;
  }

  /**
   * Get tutorial stats
   */
  getStats(): GameStats {
    return {
      score: this.kills * 10,
      kills: this.kills,
      timeElapsed: this.elapsedTime,
      level: 1,
    };
  }

  /**
   * Check if mode is active
   */
  isRunning(): boolean {
    return this.isActive;
  }

  /**
   * Get stage name for display
   */
  getStageName(stage: TutorialStage = this.currentStage): string {
    const names = [
      'Welcome',
      'Movement',
      'Collect Bonuses',
      'Shooting',
      'Clear Enemies',
      'Practice',
      'Perks',
      'Final Test',
      'Complete',
    ];
    return names[stage] ?? 'Unknown';
  }

  /**
   * Get stage prompt text
   */
  getStagePrompt(stage: TutorialStage = this.currentStage): string {
    const prompts = [
      "Welcome to the tutorial! You'll learn the basics of survival.",
      'Use WASD to move your character. Try moving around!',
      'Walk over bonuses to collect them. Collect all bonuses!',
      'Use left mouse button to shoot. Try firing your weapon!',
      'Clear all enemies to continue!',
      'Practice your skills! Clear waves and collect bonuses.',
      'Level up! Choose a perk to enhance your abilities.',
      'Final test! Clear all remaining enemies!',
      'Tutorial complete! You are ready for the real game.',
    ];
    return prompts[stage] ?? '';
  }

  /**
   * Skip to end (for testing)
   */
  skipToEnd(): void {
    this.currentStage = 8;
    this.stageTimerMs = 0;
  }

  /**
   * Restart tutorial
   */
  restart(): void {
    this.start();
  }
}
