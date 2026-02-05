/**
 * Quest Mode
 *
 * Structured levels with specific objectives and time-based enemy spawn patterns.
 * Updated with QuestSpawnSystem for timeline-based spawning.
 *
 * Transition State Machine (from decompiled quest_mode_update @ 004070e0):
 * - Transition timer starts when all objectives complete AND no creatures active AND spawn table empty
 * - 800ms: play questhit SFX, jump to 851ms (0x353)
 * - 2000ms: start victory music, jump to 2051ms (0x803)
 * - 2500ms (0x9c4): persist unlocks, save game, transition to completion screen
 */

import type { EntityManager } from '../../core/ecs';
import type { QuestId, GameStats, CreatureTypeId } from '../../types';
import {
  getQuestData,
  getAvailableQuests,
  type QuestData,
  type QuestObjective,
} from '../data/quests';
import { QuestSpawnSystem } from '../systems/QuestSpawnSystem';
import type { ProgressionManager } from '../progression/ProgressionManager';

export interface QuestModeCallbacks {
  onQuestStart?: (questId: QuestId) => void;
  onQuestComplete?: (questId: QuestId, stats: GameStats) => void;
  onQuestFail?: (questId: QuestId, stats: GameStats) => void;
  onObjectiveUpdate?: (objective: QuestObjective, current: number, target: number) => void;
  onSpawn?: (creatureTypeId: CreatureTypeId, count: number) => void;
  // Transition state machine callbacks (from decompiled quest_mode_update)
  onMuteExtraMusic?: () => void;
  onPlaySfx?: (sfxName: string) => void;
  onPlayMusic?: (trackName: string) => void;
  onUpdateUnlockIndices?: (unlockIndex: number, isHardcore: boolean) => void;
  onSaveGame?: () => void;
  onFlushInput?: () => void;
  onResetReflexBoost?: () => void;
  isHardcoreMode?: () => boolean;
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

  // Progress tracking
  private killCount = 0;
  private survivalTime = 0;
  private killCountsByType = new Map<CreatureTypeId, number>();
  private score = 0;
  private bossKillCount = 0;

  // Player position tracking for reach_location objectives
  private playerX = 0;
  private playerY = 0;

  // Transition state machine (from decompiled quest_mode_update @ 004070e0)
  private transitionTimerMs = -1; // -1 means not started, matches decompiled logic
  private readonly TRANSITION_SFX_THRESHOLD = 800;
  private readonly TRANSITION_SFX_JUMP_TO = 0x353; // 851ms
  private readonly TRANSITION_MUSIC_THRESHOLD = 2000;
  private readonly TRANSITION_MUSIC_JUMP_TO = 0x803; // 2051ms
  private readonly TRANSITION_COMPLETE_THRESHOLD = 0x9c4; // 2500ms

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

    // Reset progress
    this.killCount = 0;
    this.survivalTime = 0;
    this.killCountsByType.clear();
    this.score = 0;
    this.bossKillCount = 0;
    this.playerX = 0;
    this.playerY = 0;

    // Reset transition timer
    this.transitionTimerMs = -1;

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
    this.transitionTimerMs = -1;
    this.questSpawnSystem.stop();
  }

  /**
   * Update quest logic
   */
  update(dt: number): void {
    if (!this.isActive || !this.currentQuest) return;

    const dtMs = dt * 1000;

    // Update spawn timeline (from decompiled: only advances if no active creatures OR spawn table not empty)
    if (!this.creaturesNoneActive() || !this.questSpawnTableEmpty()) {
      this.questSpawnSystem.update(dt);
    }

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

    // If all objectives complete, run transition timer state machine
    if (this.areAllObjectivesComplete()) {
      this.updateTransitionTimer(dtMs);
    }
  }

  /**
   * Check if any creatures are currently active (alive)
   * Mirrors creatures_none_active() from decompiled source @ 00428210
   * Returns true when no creature entities exist with 'creature' component
   */
  private creaturesNoneActive(): boolean {
    // Query entity manager for entities with 'creature' component
    const creatures = this._entityManager.query(['creature']);
    return creatures.length === 0;
  }

  /**
   * Check if quest spawn table is empty (no pending spawns)
   * Mirrors quest_spawn_table_empty() from decompiled source @ 00434220
   * Returns true when spawn count is 0 or all entries have count <= 0
   */
  private questSpawnTableEmpty(): boolean {
    // Use QuestSpawnSystem's method to check if spawn table is empty
    return this.questSpawnSystem.isSpawnTableEmpty();
  }

  /**
   * Check if all objectives are complete without triggering completion
   */
  private areAllObjectivesComplete(): boolean {
    if (!this.currentQuest) return false;

    for (const objective of this.currentQuest.objectives) {
      let complete = false;

      switch (objective.type) {
        case 'kill_count':
          if (objective.creatureTypeId !== undefined) {
            complete = (this.killCountsByType.get(objective.creatureTypeId) ?? 0) >= objective.target;
          } else {
            complete = this.killCount >= objective.target;
          }
          break;

        case 'survive_time':
          complete = this.survivalTime >= objective.target;
          break;

        case 'reach_location': {
          if (objective.x !== undefined && objective.y !== undefined) {
            const dx = this.playerX - objective.x;
            const dy = this.playerY - objective.y;
            const distance = Math.sqrt(dx * dx + dy * dy);
            complete = distance <= objective.target;
          }
          break;
        }

        case 'kill_bosses':
          complete = this.bossKillCount >= objective.target;
          break;
      }

      if (!complete) return false;
    }

    return true;
  }

  /**
   * Update the quest transition timer state machine
   * Based on decompiled quest_mode_update @ 004070e0
   *
   * Transition timer only runs when:
   * - Demo mode is inactive (always true in our implementation)
   * - No active creatures (creatures_none_active returns true)
   * - Spawn table is empty (quest_spawn_table_empty returns true)
   *
   * Thresholds:
   * - 800ms: play questhit SFX, jump to 851ms
   * - 2000ms: start victory music, jump to 2051ms
   * - 2500ms: persist unlocks, save game, transition to completion
   */
  private updateTransitionTimer(dtMs: number): void {
    // Check prerequisites: no active creatures AND spawn table empty
    if (!this.creaturesNoneActive() || !this.questSpawnTableEmpty()) {
      return;
    }

    // Reset reflex boost timer (decompiled: _bonus_reflex_boost_timer = 0)
    this.callbacks.onResetReflexBoost?.();

    // State 1: Transition just starting (timer < 0)
    if (this.transitionTimerMs < 0) {
      this.transitionTimerMs = dtMs;
      // Mute extra music track
      this.callbacks.onMuteExtraMusic?.();
      // Increment quest play count
      this.incrementQuestPlayCount();
      return;
    }

    // State 2: At 800ms, play questhit SFX and jump to 851ms
    if (this.transitionTimerMs > this.TRANSITION_SFX_THRESHOLD && this.transitionTimerMs < this.TRANSITION_SFX_JUMP_TO) {
      this.callbacks.onPlaySfx?.('questhit');
      this.transitionTimerMs = dtMs + this.TRANSITION_SFX_JUMP_TO;
      return;
    }

    // State 3: At 2000ms, start victory music and jump to 2051ms
    if (this.transitionTimerMs > this.TRANSITION_MUSIC_THRESHOLD && this.transitionTimerMs < this.TRANSITION_MUSIC_JUMP_TO) {
      this.transitionTimerMs = this.TRANSITION_MUSIC_JUMP_TO;
      this.callbacks.onPlayMusic?.('crimsonquest');
      this.transitionTimerMs += dtMs;
      return;
    }

    // State 4: At 2500ms, complete the quest
    if (this.transitionTimerMs > this.TRANSITION_COMPLETE_THRESHOLD) {
      this.finalizeQuestCompletion();
      return;
    }

    // Advance timer
    this.transitionTimerMs += dtMs;
  }

  /**
   * Increment quest play count
   * From decompiled: game_status_blob.quest_play_counts[iVar2 + 0x28]++
   * where iVar2 = _quest_stage_minor + _quest_stage_major * 10
   */
  private incrementQuestPlayCount(): void {
    // This is tracked in ProgressionManager via quest high score attempts
    // The decompiled version tracks raw play counts, we track attempts in high scores
  }

  /**
   * Calculate unlock index from quest stage
   * From decompiled: iVar2 = _quest_stage_minor + -10 + _quest_stage_major * 10
   *
   * The unlock index represents progress through the quest chain.
   * We derive this from the current quest's position in the unlock chain.
   */
  private calculateUnlockIndex(): number {
    // Map quest ID to its position in the unlock chain
    // This is a simplified mapping - in the full implementation,
    // this would use the actual quest stage major/minor values
    const questOrder: QuestId[] = [
      'nagolipoli',
      'monster_blues',
      'the_gathering',
      'army_of_three',
      'target_practice',
      'frontline_assault',
      'spider_wave_syndrome',
      'the_random_factor',
      'everred_pastures',
      'spider_spawns',
      'two_fronts',
      'sweep_stakes',
      'evil_zombies_at_large',
      'survival_of_the_fastest',
      'knee_deep_in_the_dead',
      'the_gang_wars',
      'the_fortress',
      'cross_fire',
      'the_beating',
      'hidden_evil',
      'land_hostile',
      'minor_alien_breach',
      'alien_squads',
      'zombie_masters',
      '8_legged_terror',
      'ghost_patrols',
      'nesting_grounds',
      'alien_dens',
      'arachnoid_farm',
      'gauntlet',
      'the_blighting',
      'the_killing',
      'surrounded_by_reptiles',
      'the_lizquidation',
      'spiders_inc',
      'deja_vu',
      'major_alien_breach',
      'zombie_time',
      'the_collaboration',
      'the_massacre',
      'the_unblitzkrieg',
      'land_of_lizards',
      'lizard_kings',
      'lizard_raze',
      'lizard_zombie_pact',
      'the_annihilation',
      'the_end_of_all',
      'the_spanking_of_the_dead',
      'spideroids',
      'syntax_terror',
    ];

    if (!this.currentQuestId) return 0;

    const index = questOrder.indexOf(this.currentQuestId);
    if (index < 0) return 0;

    // Convert to unlock index format (decompiled uses: quest_stage_minor - 10 + quest_stage_major * 10)
    // This maps to: index in quest chain (0-based)
    return index;
  }

  /**
   * Finalize quest completion with unlock persistence and state transition
   * From decompiled: persist unlocks, save, set game_state_pending = 8, flush input
   */
  private finalizeQuestCompletion(): void {
    if (!this.currentQuestId) return;

    // Calculate unlock index
    const unlockIndex = this.calculateUnlockIndex();

    // Persist unlock indices
    const isHardcore = this.callbacks.isHardcoreMode?.() ?? false;
    this.callbacks.onUpdateUnlockIndices?.(unlockIndex, isHardcore);

    // Save game status
    this.callbacks.onSaveGame?.();

    const stats = this.getStats();

    // Record completion in progression
    this.progressionManager?.recordQuestComplete(this.currentQuestId, {
      time: this.survivalTime,
      score: this.score,
      kills: this.killCount,
    });

    // Trigger state transition (game_state_pending = 8)
    this.callbacks.onQuestComplete?.(this.currentQuestId, stats);

    // Flush input
    this.callbacks.onFlushInput?.();

    this.isActive = false;
  }

  /**
   * Record a kill
   */
  recordKill(creatureTypeId?: CreatureTypeId, rewardValue = 10, isBoss = false): void {
    if (!this.isActive) return;

    this.killCount++;
    this.score += rewardValue;

    if (creatureTypeId !== undefined) {
      const current = this.killCountsByType.get(creatureTypeId) ?? 0;
      this.killCountsByType.set(creatureTypeId, current + 1);
    }

    // Track boss kills separately
    if (isBoss) {
      this.bossKillCount++;
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
   * Update player position for reach_location objectives
   */
  updatePlayerPosition(x: number, y: number): void {
    this.playerX = x;
    this.playerY = y;
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

  /**
   * Get transition timer state (for testing)
   */
  getTransitionTimerMs(): number {
    return this.transitionTimerMs;
  }

  /**
   * Fail the quest
   */
  private failQuest(_reason: string): void {
    if (!this.currentQuest || !this.currentQuestId) return;

    const stats = this.getStats();

    this.callbacks.onQuestFail?.(this.currentQuestId, stats);
    this.isActive = false;
  }

  private checkObjectives(): void {
    if (!this.currentQuest) return;

    for (const objective of this.currentQuest.objectives) {
      let current = 0;

      switch (objective.type) {
        case 'kill_count':
          if (objective.creatureTypeId !== undefined) {
            current = this.killCountsByType.get(objective.creatureTypeId) ?? 0;
          } else {
            current = this.killCount;
          }
          break;

        case 'survive_time':
          current = Math.floor(this.survivalTime);
          break;

        case 'reach_location': {
          // Check if player is within target radius of objective location
          // objective.target contains the radius
          // objective.x and objective.y contain the target coordinates
          if (objective.x !== undefined && objective.y !== undefined) {
            const dx = this.playerX - objective.x;
            const dy = this.playerY - objective.y;
            const distance = Math.sqrt(dx * dx + dy * dy);
            const radius = objective.target;
            current = distance <= radius ? radius : Math.max(0, radius - distance);
          } else {
            current = 0;
          }
          break;
        }

        case 'kill_bosses':
          // Track kills of creatures with BOSS flag
          current = this.bossKillCount;
          break;
      }

      // Notify on objective update (throttle to avoid spam)
      if (current !== objective.target) {
        this.callbacks.onObjectiveUpdate?.(objective, current, objective.target);
      }
    }
  }

  /**
   * Get completion status for all objectives
   * Returns array of { objective, complete, current } for each objective
   */
  getObjectiveStatus(): Array<{ objective: QuestObjective; complete: boolean; current: number }> {
    if (!this.currentQuest) return [];

    return this.currentQuest.objectives.map((objective) => {
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

        case 'reach_location': {
          if (objective.x !== undefined && objective.y !== undefined) {
            const dx = this.playerX - objective.x;
            const dy = this.playerY - objective.y;
            const distance = Math.sqrt(dx * dx + dy * dy);
            current = distance <= objective.target ? objective.target : Math.max(0, objective.target - distance);
            complete = distance <= objective.target;
          }
          break;
        }

        case 'kill_bosses':
          current = this.bossKillCount;
          complete = current >= objective.target;
          break;
      }

      return { objective, complete, current };
    });
  }

  /**
   * Get current transition state for testing
   */
  getTransitionState(): {
    timerMs: number;
    isInTransition: boolean;
    creaturesNoneActive: boolean;
    spawnTableEmpty: boolean;
    allObjectivesComplete: boolean;
  } {
    return {
      timerMs: this.transitionTimerMs,
      isInTransition: this.transitionTimerMs >= 0,
      creaturesNoneActive: this.creaturesNoneActive(),
      spawnTableEmpty: this.questSpawnTableEmpty(),
      allObjectivesComplete: this.areAllObjectivesComplete(),
    };
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
