/**
 * Perk System
 *
 * Manages perk application, stat calculations, and special perk effects.
 * Integrates with the ECS to apply perks to player entities.
 */

import type { EntityManager, UpdateContext } from '../../core/ecs';
import type { EntityId } from '../../types';
import { PerkId } from '../../types';
import type { Player } from '../components';
import {
  getPerkData,
  isPerkCompatible,
  generatePerkChoices as generateChoices,
  calculateDamageMultiplier,
  calculateFireRateMultiplier,
  calculateReloadSpeedMultiplier,
  calculateMoveSpeedMultiplier,
  calculateMaxHealthMultiplier,
  calculateXpMultiplier,
  calculateHealthRegen,
  calculateBonusDurationMultiplier,
  calculateClipSizeBonus,
  type PerkData,
} from '../data/perks';

export interface PerkSystemCallbacks {
  onPerkApplied?: (entityId: EntityId, perkId: PerkId, newRank: number) => void;
  onFatalLottery?: (entityId: EntityId, survived: boolean, xpGained: number) => void;
  onInfernalContract?: (entityId: EntityId, levelsGained: number) => void;
  onGrimDeal?: (entityId: EntityId, xpConverted: number) => void;
}

export interface ActivePerkEffect {
  perkId: PerkId;
  startedAt: number;
  duration: number;
}

export class PerkSystem {
  readonly name = 'PerkSystem';
  enabled = true;
  readonly priority = 10; // Update after gameplay systems, before render

  private entityManager: EntityManager;
  private callbacks: PerkSystemCallbacks;

  // Track active timed effects per entity
  private activeEffects: Map<EntityId, ActivePerkEffect[]> = new Map();

  // Track death clock timer per entity
  private deathClockTimers: Map<EntityId, number> = new Map();

  constructor(entityManager: EntityManager, callbacks: PerkSystemCallbacks = {}) {
    this.entityManager = entityManager;
    this.callbacks = callbacks;
  }

  /**
   * Apply a perk to an entity
   * Returns true if the perk was successfully applied
   */
  applyPerk(entityId: EntityId, perkId: PerkId): boolean {
    const player = this.entityManager.getComponent<'player'>(entityId, 'player');
    if (!player) return false;

    const perk = getPerkData(perkId);
    if (!perk) return false;

    // Check compatibility
    if (!isPerkCompatible(perkId, player.perkCounts)) {
      return false;
    }

    // Handle special perks with immediate effects
    const specialHandled = this.handleSpecialPerk(entityId, player, perk);
    if (!specialHandled) {
      return false;
    }

    // Increment perk count
    const currentRank = player.perkCounts.get(perkId) ?? 0;
    const newRank = currentRank + 1;
    player.perkCounts.set(perkId, newRank);

    // Apply stat modifiers
    this.applyStatModifiers(entityId, player, perk);

    this.callbacks.onPerkApplied?.(entityId, perkId, newRank);
    return true;
  }

  /**
   * Handle special perks with unique mechanics
   */
  private handleSpecialPerk(entityId: EntityId, player: Player, perk: PerkData): boolean {
    for (const effect of perk.effects) {
      switch (effect.type) {
        case 'special_instant_xp': {
          // Instant XP is handled by the caller (SurvivalMode)
          break;
        }

        case 'special_fatal_lottery': {
          const survived = Math.random() < 0.5;
          const xpGained = survived ? effect.value : 0;
          this.callbacks.onFatalLottery?.(entityId, survived, xpGained);
          return survived; // If died, don't apply the perk
        }

        case 'special_infernal_contract': {
          // +levels but reduce health to 10%
          player.health = Math.max(10, player.maxHealth * 0.1);
          this.callbacks.onInfernalContract?.(entityId, effect.value);
          break;
        }

        case 'special_grim_deal': {
          // Convert HP to XP, then die
          const xpConverted = player.health * 100;
          this.callbacks.onGrimDeal?.(entityId, xpConverted);
          player.health = 0;
          return true; // Perk is "applied" but player dies
        }

        case 'special_death_clock': {
          // Start death clock timer (30 seconds to survive with huge regen)
          this.deathClockTimers.set(entityId, 30);
          break;
        }

        case 'special_bandage': {
          // Random health boost
          const multiplier = 1 + Math.floor(Math.random() * 50);
          player.health = Math.min(player.maxHealth, player.health * multiplier);
          break;
        }

        case 'special_highlander': {
          // Mark for highlander mode (handled by spawn system)
          break;
        }

        case 'special_plaguebearer': {
          // Mark for plaguebearer mode (handled by death system)
          break;
        }

        case 'special_monster_vision': {
          // Enable monster vision (handled by render system)
          break;
        }

        case 'special_fire_bullets':
        case 'special_infinite_ammo_window':
        case 'special_ammo_refill_on_pickup':
        case 'special_random_weapon':
        case 'special_shield_on_hit':
        case 'special_regression_bullets':
        case 'special_time_slow_on_hit':
        case 'special_lifeline_50_50':
        case 'special_jinxed': {
          // These are handled by other systems checking perk counts
          break;
        }

        default:
          // Standard stat modifiers handled separately
          break;
      }
    }
    return true;
  }

  /**
   * Apply stat modifiers from a perk
   */
  private applyStatModifiers(_entityId: EntityId, player: Player, perk: PerkData): void {
    for (const effect of perk.effects) {
      switch (effect.type) {
        case 'max_health_multiplier': {
          const oldMax = player.maxHealth;
          const multiplier = calculateMaxHealthMultiplier(player.perkCounts);
          player.maxHealth = Math.floor(100 * multiplier);
          // Adjust current health proportionally
          player.health = Math.floor((player.health / oldMax) * player.maxHealth);
          break;
        }

        case 'clip_size_bonus': {
          // Clip size bonus is applied dynamically by weapon system
          // calculateClipSizeBonus(player.perkCounts) is called when needed
          break;
        }
      }
    }
  }

  /**
   * Update perk effects (regeneration, death clock, etc.)
   */
  update(_entityManager: EntityManager, context: UpdateContext): void {
    const dt = context.dt;
    const entities = this.entityManager.getEntitiesWithComponent('player');

    for (const entityId of entities) {
      const player = this.entityManager.getComponent<'player'>(entityId, 'player');
      if (!player) continue;

      // Handle health regeneration
      const regen = calculateHealthRegen(player.perkCounts);
      if (regen > 0 && player.health < player.maxHealth) {
        player.health = Math.min(player.maxHealth, player.health + regen * dt);
      }

      // Handle death clock
      const deathClockTime = this.deathClockTimers.get(entityId);
      if (deathClockTime !== undefined) {
        const newTime = deathClockTime - dt;
        if (newTime <= 0) {
          // Death clock expired - player dies
          player.health = 0;
          this.deathClockTimers.delete(entityId);
        } else {
          this.deathClockTimers.set(entityId, newTime);
          // Grant massive regen during death clock
          player.health = Math.min(player.maxHealth, player.health + 20 * dt);
        }
      }

      // Update active effects
      this.updateActiveEffects(entityId, dt);
    }
  }

  /**
   * Update and clean up timed effects
   */
  private updateActiveEffects(entityId: EntityId, _dt: number): void {
    const effects = this.activeEffects.get(entityId);
    if (!effects) return;

    const now = performance.now();
    const remainingEffects = effects.filter((effect) => {
      return now - effect.startedAt < effect.duration * 1000;
    });

    if (remainingEffects.length === 0) {
      this.activeEffects.delete(entityId);
    } else {
      this.activeEffects.set(entityId, remainingEffects);
    }
  }

  /**
   * Generate perk choices for level up
   */
  generatePerkChoices(entityId: EntityId, count = 3): PerkId[] {
    const player = this.entityManager.getComponent<'player'>(entityId, 'player');
    if (!player) return [];

    const hasPerkExpert = player.perkCounts.has(PerkId.PERK_EXPERT);
    const hasPerkMaster = player.perkCounts.has(PerkId.PERK_MASTER);

    return generateChoices(player.perkCounts, player.level, hasPerkExpert, hasPerkMaster).slice(
      0,
      count
    );
  }

  /**
   * Check if an entity can select a perk
   */
  canSelectPerk(entityId: EntityId, perkId: PerkId): boolean {
    const player = this.entityManager.getComponent<'player'>(entityId, 'player');
    if (!player) return false;

    return isPerkCompatible(perkId, player.perkCounts);
  }

  /**
   * Get the rank of a perk for an entity
   */
  getPerkRank(entityId: EntityId, perkId: PerkId): number {
    const player = this.entityManager.getComponent<'player'>(entityId, 'player');
    if (!player) return 0;

    return player.perkCounts.get(perkId) ?? 0;
  }

  /**
   * Check if entity has a specific perk
   */
  hasPerk(entityId: EntityId, perkId: PerkId): boolean {
    return this.getPerkRank(entityId, perkId) > 0;
  }

  /**
   * Get all perks for an entity
   */
  getAllPerks(entityId: EntityId): Map<PerkId, number> {
    const player = this.entityManager.getComponent<'player'>(entityId, 'player');
    if (!player) return new Map();

    return new Map(player.perkCounts);
  }

  // ============================================================================
  // Stat Calculation Methods
  // ============================================================================

  /**
   * Calculate damage multiplier for an entity
   */
  getDamageMultiplier(entityId: EntityId): number {
    const player = this.entityManager.getComponent<'player'>(entityId, 'player');
    if (!player) return 1;

    return calculateDamageMultiplier(player.perkCounts);
  }

  /**
   * Calculate fire rate multiplier for an entity
   */
  getFireRateMultiplier(entityId: EntityId): number {
    const player = this.entityManager.getComponent<'player'>(entityId, 'player');
    if (!player) return 1;

    return calculateFireRateMultiplier(player.perkCounts);
  }

  /**
   * Calculate reload speed multiplier for an entity
   */
  getReloadSpeedMultiplier(entityId: EntityId): number {
    const player = this.entityManager.getComponent<'player'>(entityId, 'player');
    if (!player) return 1;

    const multiplier = calculateReloadSpeedMultiplier(player.perkCounts);
    return 1 / multiplier; // Convert to speed multiplier
  }

  /**
   * Calculate move speed multiplier for an entity
   */
  getMoveSpeedMultiplier(entityId: EntityId): number {
    const player = this.entityManager.getComponent<'player'>(entityId, 'player');
    if (!player) return 1;

    return calculateMoveSpeedMultiplier(player.perkCounts);
  }

  /**
   * Calculate max health multiplier for an entity
   */
  getMaxHealthMultiplier(entityId: EntityId): number {
    const player = this.entityManager.getComponent<'player'>(entityId, 'player');
    if (!player) return 1;

    return calculateMaxHealthMultiplier(player.perkCounts);
  }

  /**
   * Calculate XP multiplier for an entity
   */
  getXpMultiplier(entityId: EntityId): number {
    const player = this.entityManager.getComponent<'player'>(entityId, 'player');
    if (!player) return 1;

    return calculateXpMultiplier(player.perkCounts);
  }

  /**
   * Calculate bonus duration multiplier for an entity
   */
  getBonusDurationMultiplier(entityId: EntityId): number {
    const player = this.entityManager.getComponent<'player'>(entityId, 'player');
    if (!player) return 1;

    return calculateBonusDurationMultiplier(player.perkCounts);
  }

  /**
   * Calculate clip size bonus for an entity
   */
  getClipSizeBonus(entityId: EntityId): number {
    const player = this.entityManager.getComponent<'player'>(entityId, 'player');
    if (!player) return 0;

    return calculateClipSizeBonus(player.perkCounts);
  }

  // ============================================================================
  // Special Perk Checks
  // ============================================================================

  /**
   * Check if entity has monster vision
   */
  hasMonsterVision(entityId: EntityId): boolean {
    return this.hasPerk(entityId, PerkId.MONSTER_VISION);
  }

  /**
   * Check if entity has fire bullets perk
   */
  hasFireBullets(entityId: EntityId): boolean {
    return this.hasPerk(entityId, PerkId.PYROMANIAC);
  }

  /**
   * Check if entity has plaguebearer
   */
  hasPlaguebearer(entityId: EntityId): boolean {
    return this.hasPerk(entityId, PerkId.PLAGUEBEARER);
  }

  /**
   * Check if entity has highlander mode
   */
  hasHighlander(entityId: EntityId): boolean {
    return this.hasPerk(entityId, PerkId.HIGHLANDER);
  }

  /**
   * Check if entity is in death clock mode
   */
  isInDeathClock(entityId: EntityId): boolean {
    return this.deathClockTimers.has(entityId);
  }

  /**
   * Get remaining death clock time
   */
  getDeathClockTime(entityId: EntityId): number | undefined {
    return this.deathClockTimers.get(entityId);
  }

  /**
   * Check if lifeline 50/50 triggers
   */
  rollLifeline50_50(entityId: EntityId): boolean {
    if (!this.hasPerk(entityId, PerkId.LIFELINE_50_50)) {
      return false;
    }
    return Math.random() < 0.5;
  }

  /**
   * Check if entity has infinite ammo window active
   * (This would need to be called by WeaponSystem after reload)
   */
  startInfiniteAmmoWindow(entityId: EntityId): void {
    if (!this.hasPerk(entityId, PerkId.AMMUNITION_WITHIN)) {
      return;
    }

    const effects = this.activeEffects.get(entityId) ?? [];
    effects.push({
      perkId: PerkId.AMMUNITION_WITHIN,
      startedAt: performance.now(),
      duration: 3, // 3 seconds
    });
    this.activeEffects.set(entityId, effects);
  }

  /**
   * Check if infinite ammo window is active
   */
  isInfiniteAmmoActive(entityId: EntityId): boolean {
    return this.isEffectActive(entityId, PerkId.AMMUNITION_WITHIN);
  }

  /**
   * Check if a timed effect is active
   */
  private isEffectActive(entityId: EntityId, perkId: PerkId): boolean {
    const effects = this.activeEffects.get(entityId);
    if (!effects) return false;

    const now = performance.now();
    return effects.some((effect) => {
      return effect.perkId === perkId && now - effect.startedAt < effect.duration * 1000;
    });
  }

  /**
   * Reset all perks for an entity
   */
  resetPerks(entityId: EntityId): void {
    const player = this.entityManager.getComponent<'player'>(entityId, 'player');
    if (!player) return;

    player.perkCounts.clear();
    this.activeEffects.delete(entityId);
    this.deathClockTimers.delete(entityId);
  }

  /**
   * Clean up data for removed entities
   */
  cleanupEntity(entityId: EntityId): void {
    this.activeEffects.delete(entityId);
    this.deathClockTimers.delete(entityId);
  }
}
