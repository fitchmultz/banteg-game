/**
 * Perk Calculations
 *
 * Stat calculation functions derived from perk selections.
 */

import { PerkId } from '../../../types';

/**
 * Calculate damage multiplier from perks
 * Note: Evil Eyes bonus is calculated separately by PerkSystem based on targeting
 */
export function calculateDamageMultiplier(perkCounts: Map<PerkId, number>): number {
  let multiplier = 1;

  const sharpshooterCount = perkCounts.get(PerkId.SHARPSHOOTER) ?? 0;
  multiplier += sharpshooterCount * 0.15;

  // Note: Evil Eyes (25% bonus when targeting enemy) is handled separately
  // by PerkSystem.getDamageMultiplierWithEvilEyes() which checks evilEyesTargetCreature

  return multiplier;
}

/**
 * Calculate fire rate multiplier from perks
 */
export function calculateFireRateMultiplier(perkCounts: Map<PerkId, number>): number {
  let multiplier = 1;

  const fastshotCount = perkCounts.get(PerkId.FASTSHOT) ?? 0;
  multiplier += fastshotCount * 0.1;

  return multiplier;
}

/**
 * Calculate reload speed multiplier from perks
 */
export function calculateReloadSpeedMultiplier(perkCounts: Map<PerkId, number>): number {
  let multiplier = 1;

  const anxiousLoaderCount = perkCounts.get(PerkId.ANXIOUS_LOADER) ?? 0;
  multiplier += anxiousLoaderCount * 0.2;

  const fastloaderCount = perkCounts.get(PerkId.FASTLOADER) ?? 0;
  if (fastloaderCount > 0) {
    multiplier += 0.3;
  }

  return multiplier;
}

/**
 * Calculate move speed multiplier from perks
 */
export function calculateMoveSpeedMultiplier(perkCounts: Map<PerkId, number>): number {
  let multiplier = 1;

  const runnerCount = perkCounts.get(PerkId.LONG_DISTANCE_RUNNER) ?? 0;
  multiplier += runnerCount * 0.1;

  return multiplier;
}

/**
 * Calculate max health multiplier from perks
 */
export function calculateMaxHealthMultiplier(perkCounts: Map<PerkId, number>): number {
  let multiplier = 1;

  const thickSkinnedCount = perkCounts.get(PerkId.THICK_SKINNED) ?? 0;
  if (thickSkinnedCount > 0) {
    multiplier += 0.33;
  }

  return multiplier;
}

/**
 * Calculate XP multiplier from perks
 */
export function calculateXpMultiplier(perkCounts: Map<PerkId, number>): number {
  let multiplier = 1;

  const expMachineCount = perkCounts.get(PerkId.LEAN_MEAN_EXP_MACHINE) ?? 0;
  multiplier += expMachineCount * 0.1;

  return multiplier;
}

/**
 * Calculate health regeneration per second from perks
 */
export function calculateHealthRegen(perkCounts: Map<PerkId, number>): number {
  let regen = 0;

  if (perkCounts.has(PerkId.GREATER_REGENERATION)) {
    regen += 3;
  } else if (perkCounts.has(PerkId.REGENERATION)) {
    regen += 1;
  }

  const doctorCount = perkCounts.get(PerkId.DOCTOR) ?? 0;
  regen += doctorCount * 0.5;

  return regen;
}

/**
 * Calculate bonus duration multiplier from perks
 */
export function calculateBonusDurationMultiplier(perkCounts: Map<PerkId, number>): number {
  let multiplier = 1;

  // Bonus Economist: +25% per rank
  const economistCount = perkCounts.get(PerkId.BONUS_ECONOMIST) ?? 0;
  multiplier += economistCount * 0.25;

  // Note: Pyrokinetic extends fire bullet duration but is handled separately
  // by the fire bullet system, not as a general bonus duration multiplier

  return multiplier;
}

/**
 * Calculate clip size bonus from perks
 */
export function calculateClipSizeBonus(perkCounts: Map<PerkId, number>): number {
  const favouriteWeaponCount = perkCounts.get(PerkId.MY_FAVOURITE_WEAPON) ?? 0;
  return favouriteWeaponCount * 2;
}
