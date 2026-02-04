/**
 * Perk System
 *
 * Manages perk application, stat calculations, and special perk effects.
 * Integrates with the ECS to apply perks to player entities.
 * Uses deterministic gameTime-based timing for all timed effects.
 */

import type { EntityManager, UpdateContext } from '../../core/ecs';
import type { EntityId } from '../../types';
import { PerkId, WeaponId } from '../../types';
import type { Player, WeaponSlot } from '../components';
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
import { getWeaponData } from '../data';

export interface PerkSystemCallbacks {
  onPerkApplied?: (entityId: EntityId, perkId: PerkId, newRank: number) => void;
  onFatalLottery?: (entityId: EntityId, survived: boolean, xpGained: number) => void;
  onInfernalContract?: (entityId: EntityId, levelsGained: number) => void;
  onGrimDeal?: (entityId: EntityId, xpConverted: number) => void;
}

export interface ActivePerkEffect {
  perkId: PerkId;
  endsAtGameTime: number; // Deterministic: uses context.gameTime
  duration: number;
}

export interface JinxState {
  nextTriggerTime: number;
  interval: number;
}

export class PerkSystem {
  readonly name = 'PerkSystem';
  enabled = true;
  readonly priority = 10; // Update after gameplay systems, before render

  private entityManager: EntityManager;
  private callbacks: PerkSystemCallbacks;

  // Track active timed effects per entity (deterministic gameTime-based)
  private activeEffects: Map<EntityId, ActivePerkEffect[]> = new Map();

  // Track death clock timer per entity
  private deathClockTimers: Map<EntityId, number> = new Map();

  // Track jinxed state per entity
  private jinxStates: Map<EntityId, JinxState> = new Map();

  constructor(entityManager: EntityManager, callbacks: PerkSystemCallbacks = {}) {
    this.entityManager = entityManager;
    this.callbacks = callbacks;
  }

  /**
   * Apply a perk to an entity
   * Returns true if the perk was successfully applied
   */
  applyPerk(entityId: EntityId, perkId: PerkId, gameTime = 0): boolean {
    const player = this.entityManager.getComponent<'player'>(entityId, 'player');
    if (!player) return false;

    const perk = getPerkData(perkId);
    if (!perk) return false;

    // Check compatibility
    if (!isPerkCompatible(perkId, player.perkCounts)) {
      return false;
    }

    // Handle special perks with immediate effects
    const specialHandled = this.handleSpecialPerk(entityId, player, perk, gameTime);
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
  private handleSpecialPerk(
    entityId: EntityId,
    player: Player,
    perk: PerkData,
    gameTime: number
  ): boolean {
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

        case 'special_random_weapon': {
          // Grant a random weapon immediately
          this.grantRandomWeapon(player);
          break;
        }

        case 'special_lifeline_50_50': {
          // Kill 50% of eligible creatures
          this.applyLifeline50_50();
          break;
        }

        case 'special_jinxed': {
          // Initialize jinx state
          this.jinxStates.set(entityId, {
            nextTriggerTime: gameTime + 2 + Math.random() * 2,
            interval: 2 + Math.random() * 2,
          });
          break;
        }

        case 'special_fire_bullets':
        case 'special_infinite_ammo_window':
        case 'special_ammo_refill_on_pickup':
        case 'special_shield_on_hit':
        case 'special_regression_bullets':
        case 'special_time_slow_on_hit': {
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
   * Grant a random weapon to the player (helper for special_random_weapon)
   */
  private grantRandomWeapon(player: Player): void {
    // Get all available weapon IDs
    const allWeaponIds = Object.values(WeaponId).filter((id): id is WeaponId => typeof id === 'number');

    // Filter out current weapon and pistol if possible
    const availableWeapons = allWeaponIds.filter((id) => {
      if (id === player.currentWeapon.weaponId) return false;
      // Keep pistol as fallback option
      return true;
    });

    // If no alternatives, allow pistol
    const candidateWeapons = availableWeapons.length > 0 ? availableWeapons : allWeaponIds;

    // Pick random weapon
    const randomIndex = Math.floor(Math.random() * candidateWeapons.length);
    const selectedWeaponId = candidateWeapons[randomIndex];

    if (selectedWeaponId === undefined) return;

    // Apply the weapon pickup using shared helper logic
    const weaponData = getWeaponData(selectedWeaponId);
    const pickupAmmo = Math.max(weaponData.clipSize * 3, 60);

    this.applyWeaponPickupToPlayer(player, selectedWeaponId, pickupAmmo);
  }

  /**
   * Apply a weapon pickup to a player (shared helper for consistency)
   * Mirrors the logic in WeaponPickupSystem
   */
  applyWeaponPickupToPlayer(player: Player, pickupWeaponId: WeaponId, pickupAmmo: number): void {
    const weaponData = getWeaponData(pickupWeaponId);

    // Check if player already has this weapon equipped
    if (player.currentWeapon.weaponId === pickupWeaponId) {
      // Add ammo to current weapon
      player.currentWeapon.ammo += pickupAmmo;
      return;
    }

    if (player.alternateWeapon.weaponId === pickupWeaponId) {
      // Add ammo to alternate weapon and swap to it
      player.alternateWeapon.ammo += pickupAmmo;
      this.swapWeaponSlots(player);
      return;
    }

    // Check if current weapon is the default pistol (and we have an alternate)
    // If so, replace the alternate with the new weapon
    if (player.currentWeapon.weaponId === WeaponId.PISTOL && player.alternateWeapon.weaponId !== WeaponId.PISTOL) {
      // Replace alternate with new weapon, keep pistol as fallback
      player.alternateWeapon = {
        weaponId: pickupWeaponId,
        clipSize: Math.min(weaponData.clipSize, pickupAmmo),
        ammo: Math.max(0, pickupAmmo - weaponData.clipSize),
      };
      // Swap to the new weapon
      this.swapWeaponSlots(player);
      return;
    }

    // Default: Replace alternate weapon with new weapon, swap to it
    player.alternateWeapon = {
      weaponId: pickupWeaponId,
      clipSize: Math.min(weaponData.clipSize, pickupAmmo),
      ammo: Math.max(0, pickupAmmo - weaponData.clipSize),
    };

    // Swap to the new weapon
    this.swapWeaponSlots(player);
  }

  /**
   * Swap current and alternate weapon slots
   */
  private swapWeaponSlots(player: Player): void {
    const temp: WeaponSlot = { ...player.currentWeapon };
    player.currentWeapon = { ...player.alternateWeapon };
    player.alternateWeapon = temp;
  }

  /**
   * Apply Lifeline 50/50: Kill 50% of eligible creatures
   */
  private applyLifeline50_50(): void {
    const creatures = this.entityManager.query(['creature']);
    const eligibleCreatures = creatures.filter((entity) => {
      const creature = entity.getComponent<'creature'>('creature');
      if (!creature) return false;
      // Skip invulnerable creatures
      // CreatureFlags.INVULNERABLE check would go here if we had flags access
      return creature.health > 0;
    });

    // Kill every other creature (stable order)
    for (let i = 0; i < eligibleCreatures.length; i += 2) {
      const creature = eligibleCreatures[i]?.getComponent<'creature'>('creature');
      if (creature) {
        creature.health = 0;
      }
    }
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
   * Update perk effects (regeneration, death clock, jinxed, etc.)
   */
  update(_entityManager: EntityManager, context: UpdateContext): void {
    const dt = context.dt;
    const gameTime = context.gameTime;
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

      // Handle jinxed perk
      this.updateJinxed(entityId, player, gameTime, dt);

      // Update active effects (clean up expired)
      this.updateActiveEffects(entityId, gameTime);
    }
  }

  /**
   * Update jinxed perk effects
   */
  private updateJinxed(entityId: EntityId, player: Player, gameTime: number, dt: number): void {
    if (!this.hasPerk(entityId, PerkId.JINXED)) {
      // Clean up jinx state if perk was removed
      this.jinxStates.delete(entityId);
      return;
    }

    let jinxState = this.jinxStates.get(entityId);
    if (!jinxState) {
      // Initialize jinx state
      jinxState = {
        nextTriggerTime: gameTime + 2 + Math.random() * 2,
        interval: 2 + Math.random() * 2,
      };
      this.jinxStates.set(entityId, jinxState);
    }

    // Check if it's time for a jinx effect
    if (gameTime >= jinxState.nextTriggerTime) {
      this.triggerJinxEffect(entityId, player, dt);

      // Schedule next trigger
      jinxState.interval = 2 + Math.random() * 2;
      jinxState.nextTriggerTime = gameTime + jinxState.interval;
    }
  }

  /**
   * Trigger a jinx effect (random helpful or harmful outcome)
   */
  private triggerJinxEffect(_entityId: EntityId, player: Player, _dt: number): void {
    // 10% chance to damage player (downside)
    if (Math.random() < 0.1) {
      player.health = Math.max(0, player.health - 5);
    }

    // Kill a random creature (upside)
    const creatures = this.entityManager.query(['creature']);
    if (creatures.length > 0) {
      const randomIndex = Math.floor(Math.random() * creatures.length);
      const targetCreature = creatures[randomIndex]?.getComponent<'creature'>('creature');
      if (targetCreature) {
        targetCreature.health = 0;
      }
    }
  }

  /**
   * Update and clean up timed effects (deterministic gameTime-based)
   */
  private updateActiveEffects(entityId: EntityId, gameTime: number): void {
    const effects = this.activeEffects.get(entityId);
    if (!effects) return;

    const remainingEffects = effects.filter((effect) => {
      return gameTime < effect.endsAtGameTime;
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
   * Returns time multiplier (higher = faster reload)
   */
  getReloadSpeedMultiplier(entityId: EntityId): number {
    const player = this.entityManager.getComponent<'player'>(entityId, 'player');
    if (!player) return 1;

    const multiplier = calculateReloadSpeedMultiplier(player.perkCounts);
    return multiplier; // This is already a speed multiplier (>1 = faster)
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
   * Start infinite ammo window (deterministic gameTime-based)
   * Called by WeaponSystem when reload completes
   */
  startInfiniteAmmoWindow(entityId: EntityId, gameTime: number, durationSeconds = 3): void {
    if (!this.hasPerk(entityId, PerkId.AMMUNITION_WITHIN)) {
      return;
    }

    const effects = this.activeEffects.get(entityId) ?? [];

    // Remove existing infinite ammo effect to reset timer
    const filteredEffects = effects.filter((e) => e.perkId !== PerkId.AMMUNITION_WITHIN);

    filteredEffects.push({
      perkId: PerkId.AMMUNITION_WITHIN,
      endsAtGameTime: gameTime + durationSeconds,
      duration: durationSeconds,
    });

    this.activeEffects.set(entityId, filteredEffects);
  }

  /**
   * Check if infinite ammo window is active (deterministic gameTime-based)
   */
  isInfiniteAmmoActive(entityId: EntityId, gameTime: number): boolean {
    return this.isEffectActive(entityId, PerkId.AMMUNITION_WITHIN, gameTime);
  }

  /**
   * Check if a timed effect is active (deterministic gameTime-based)
   */
  private isEffectActive(entityId: EntityId, perkId: PerkId, gameTime: number): boolean {
    const effects = this.activeEffects.get(entityId);
    if (!effects) return false;

    return effects.some((effect) => {
      return effect.perkId === perkId && gameTime < effect.endsAtGameTime;
    });
  }

  /**
   * Check if entity has regression bullets perk
   */
  hasRegressionBullets(entityId: EntityId): boolean {
    return this.hasPerk(entityId, PerkId.REGRESSION_BULLETS);
  }

  /**
   * Check if entity has shield on hit perk
   */
  hasShieldOnHit(entityId: EntityId): boolean {
    return this.hasPerk(entityId, PerkId.BREATHING_ROOM);
  }

  /**
   * Check if entity has time slow on hit perk
   */
  hasTimeSlowOnHit(entityId: EntityId): boolean {
    return this.hasPerk(entityId, PerkId.REFLEX_BOOSTED);
  }

  /**
   * Check if entity has ammo refill on pickup perk
   */
  hasAmmoRefillOnPickup(entityId: EntityId): boolean {
    return this.hasPerk(entityId, PerkId.AMMO_MANIAC);
  }

  /**
   * Check if entity has bonus magnet perk
   */
  hasBonusMagnet(entityId: EntityId): boolean {
    return this.hasPerk(entityId, PerkId.BONUS_MAGNET);
  }

  /**
   * Get gore intensity multiplier from Bloody Mess perk
   * Returns 1-4 based on rank (0-3)
   */
  getGoreIntensity(entityId: EntityId): number {
    const rank = this.getPerkRank(entityId, PerkId.BLOODY_MESS);
    return 1 + rank; // Returns 1-4 based on rank (0-3)
  }

  /**
   * Refill both weapon clips (for Ammo Maniac perk)
   */
  refillWeaponClips(player: Player): void {
    const currentWeaponData = getWeaponData(player.currentWeapon.weaponId);
    const alternateWeaponData = getWeaponData(player.alternateWeapon.weaponId);

    const clipBonus = calculateClipSizeBonus(player.perkCounts);

    // Refill current weapon clip
    const currentMaxClip = currentWeaponData.clipSize + clipBonus;
    const currentReloadAmount = Math.min(
      currentMaxClip - player.currentWeapon.clipSize,
      player.currentWeapon.ammo
    );
    player.currentWeapon.clipSize += currentReloadAmount;
    player.currentWeapon.ammo -= currentReloadAmount;

    // Refill alternate weapon clip
    const alternateMaxClip = alternateWeaponData.clipSize + clipBonus;
    const alternateReloadAmount = Math.min(
      alternateMaxClip - player.alternateWeapon.clipSize,
      player.alternateWeapon.ammo
    );
    player.alternateWeapon.clipSize += alternateReloadAmount;
    player.alternateWeapon.ammo -= alternateReloadAmount;
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
    this.jinxStates.delete(entityId);
  }

  /**
   * Clean up data for removed entities
   */
  cleanupEntity(entityId: EntityId): void {
    this.activeEffects.delete(entityId);
    this.deathClockTimers.delete(entityId);
    this.jinxStates.delete(entityId);
  }
}
