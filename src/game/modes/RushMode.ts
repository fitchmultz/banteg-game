/**
 * Rush Mode
 *
 * Time-survival mode with forced shotgun, continuous ammo refill,
 * and rapid edge spawning with oscillating positions.
 *
 * Ported from rush_mode_update in decompiled source.
 *
 * Invariants:
 * - Player always has shotgun with full ammo
 * - Enemies spawn every 250ms from left/right edges
 * - Y position oscillates using sin/cos(elapsedSeconds) * 256
 * - Runs until player death (no victory condition)
 */

import type { GameStats, EntityId, CreatureTypeId } from '../../types';
import { WeaponId } from '../../types';
import type { EntityManager } from '../../core/ecs';
import type { ProgressionManager } from '../progression/ProgressionManager';

export interface RushModeCallbacks {
  onStart?: () => void;
  onGameOver?: (stats: GameStats) => void;
  onSpawn?: (creatureTypeId: CreatureTypeId, x: number, y: number) => void;
}

export interface RushModeOptions {
  mapWidth?: number;
  mapHeight?: number;
  spawnCooldownMs?: number;
  shotgunWeaponId?: WeaponId;
  ammoAmount?: number;
}

export class RushMode {
  private entityManager: EntityManager;
  private callbacks: RushModeCallbacks;
  private progressionManager: ProgressionManager | undefined;
  private options: Required<RushModeOptions>;

  // Game state
  private isActive = false;
  private elapsedTime = 0;
  private spawnCooldown = 0;

  // Stats tracking
  private kills = 0;
  private score = 0;

  // Player reference
  private playerEntityId: EntityId | null = null;

  constructor(
    entityManager: EntityManager,
    callbacks: RushModeCallbacks = {},
    progressionManager?: ProgressionManager,
    options: RushModeOptions = {}
  ) {
    this.entityManager = entityManager;
    this.callbacks = callbacks;
    this.progressionManager = progressionManager;
    this.options = {
      mapWidth: 2048,
      mapHeight: 2048,
      spawnCooldownMs: 250,
      shotgunWeaponId: WeaponId.SHOTGUN,
      ammoAmount: 30,
      ...options,
    };
  }

  /**
   * Set the player entity for weapon enforcement
   */
  setPlayerEntity(entityId: EntityId): void {
    this.playerEntityId = entityId;
  }

  /**
   * Start rush mode
   */
  start(): void {
    this.isActive = true;
    this.elapsedTime = 0;
    this.spawnCooldown = 0;
    this.kills = 0;
    this.score = 0;

    // Force shotgun immediately
    this.enforceShotgunLoadout();

    this.callbacks.onStart?.();
  }

  /**
   * Stop rush mode
   */
  stop(): void {
    this.isActive = false;
  }

  /**
   * Update rush mode logic
   * Called every frame by GameModeSystem
   */
  update(dt: number): void {
    if (!this.isActive) return;

    this.elapsedTime += dt;

    // Always enforce shotgun loadout
    this.enforceShotgunLoadout();

    // Update spawn cooldown and spawn enemies
    this.spawnCooldown -= dt * 1000; // Convert to ms

    while (this.spawnCooldown <= 0) {
      this.spawnCooldown += this.options.spawnCooldownMs;
      this.spawnEdgeEnemies();
    }
  }

  /**
   * Force player to use shotgun with full ammo
   */
  private enforceShotgunLoadout(): void {
    if (this.playerEntityId === null) return;

    const player = this.entityManager.getEntity(this.playerEntityId);
    if (!player) return;

    const playerComp = player.getComponent<'player'>('player');
    if (!playerComp) return;

    // Force shotgun if not equipped
    if (playerComp.currentWeapon.weaponId !== this.options.shotgunWeaponId) {
      playerComp.currentWeapon.weaponId = this.options.shotgunWeaponId;
    }

    // Refill ammo to max
    if (playerComp.currentWeapon.ammo < this.options.ammoAmount) {
      playerComp.currentWeapon.ammo = this.options.ammoAmount;
    }

    // Also set alternate to shotgun for consistency
    if (playerComp.alternateWeapon.weaponId !== this.options.shotgunWeaponId) {
      playerComp.alternateWeapon.weaponId = this.options.shotgunWeaponId;
      playerComp.alternateWeapon.ammo = this.options.ammoAmount;
    }
  }

  /**
   * Spawn enemies at left and right edges with oscillating Y positions
   * Ported from rush_mode_update spawn logic
   */
  private spawnEdgeEnemies(): void {
    const elapsedMs = this.elapsedTime * 1000;
    const { mapWidth, mapHeight } = this.options;
    const halfWidth = mapWidth / 2;
    const halfHeight = mapHeight / 2;

    // Calculate oscillating Y position (sin/cos of elapsed seconds * 256)
    const yOffset = Math.sin(elapsedMs * 0.001) * 256;
    const yOffset2 = Math.cos(elapsedMs * 0.001) * 256;

    // Right edge spawn (x = +width/2 + 64)
    const rightX = halfWidth + 64;
    const rightY = halfHeight + yOffset;

    // Left edge spawn (x = -width/2 - 64)
    const leftX = -halfWidth - 64;
    const leftY = halfHeight + yOffset2;

    // Spawn callbacks - actual spawning is done by RushSpawnSystem or caller
    this.callbacks.onSpawn?.(0, rightX, rightY); // ZOMBIE on right
    this.callbacks.onSpawn?.(1, leftX, leftY); // ZOMBIE_FAST on left
  }

  /**
   * Record a kill
   */
  recordKill(rewardScore = 10): void {
    if (!this.isActive) return;

    this.kills++;
    this.score += rewardScore;

    // Track in progression
    this.progressionManager?.recordKill(0); // Generic zombie kill
  }

  /**
   * Add score
   */
  addScore(points: number): void {
    if (!this.isActive) return;
    this.score += points;
  }

  /**
   * Get rush stats
   * Note: timeElapsed is the primary metric for rush high scores
   */
  getStats(): GameStats {
    return {
      score: this.score,
      kills: this.kills,
      timeElapsed: this.elapsedTime,
      level: 1, // Rush doesn't use levels
    };
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
   * End the rush run and record stats
   */
  endRun(): GameStats {
    const stats = this.getStats();

    // Record in progression as survival run (time-based)
    this.progressionManager?.recordSurvivalRun({
      ...stats,
      time: this.elapsedTime,
    });

    this.callbacks.onGameOver?.(stats);
    this.isActive = false;

    return stats;
  }
}
