/**
 * Perks Data Module
 *
 * Re-exports all perk data and utilities.
 */

// Types
export type { PerkCategory, PerkEffect, PerkData } from './types';

// Category perk arrays
export { META_PERKS } from './meta';
export { COMBAT_PERKS } from './combat';
export { DEFENSE_PERKS } from './defense';
export { UTILITY_PERKS } from './utility';
export { MOVEMENT_PERKS } from './movement';
export { SPECIAL_PERKS, ION_GUN_MASTER_PERK } from './special';
export { GAMBLE_PERKS } from './gamble';

// Calculations
export {
  calculateDamageMultiplier,
  calculateFireRateMultiplier,
  calculateReloadSpeedMultiplier,
  calculateMoveSpeedMultiplier,
  calculateMaxHealthMultiplier,
  calculateXpMultiplier,
  calculateHealthRegen,
  calculateBonusDurationMultiplier,
  calculateClipSizeBonus,
} from './calculations';

// Combined exports and utilities
import type { PerkData } from './types';
import type { PerkId } from '../../../types';
import { META_PERKS } from './meta';
import { COMBAT_PERKS } from './combat';
import { DEFENSE_PERKS } from './defense';
import { UTILITY_PERKS } from './utility';
import { MOVEMENT_PERKS } from './movement';
import { SPECIAL_PERKS, ION_GUN_MASTER_PERK } from './special';
import { GAMBLE_PERKS } from './gamble';

// All Perks Combined - sorted by ID for correct ordering
export const ALL_PERKS: PerkData[] = [
  ...META_PERKS,
  ...COMBAT_PERKS,
  ...DEFENSE_PERKS,
  ...UTILITY_PERKS,
  ...MOVEMENT_PERKS,
  ...SPECIAL_PERKS,
  ...GAMBLE_PERKS,
  ION_GUN_MASTER_PERK,
].sort((a, b) => a.id - b.id);

// Map for quick lookup
export const PERK_DATA_MAP: ReadonlyMap<PerkId, PerkData> = new Map(
  ALL_PERKS.map((perk) => [perk.id, perk])
);

/**
 * Get perk data by ID
 */
export function getPerkData(perkId: PerkId): PerkData | undefined {
  return PERK_DATA_MAP.get(perkId);
}

/**
 * Check if a perk is compatible with already selected perks
 */
export function isPerkCompatible(perkId: PerkId, selectedPerks: Map<PerkId, number>): boolean {
  const perk = getPerkData(perkId);
  if (!perk) return false;

  // Check max rank first
  const currentRank = selectedPerks.get(perkId) ?? 0;
  if (currentRank >= perk.maxRank) {
    return false;
  }

  // Check prerequisites first - if prerequisite is met, allow even if "incompatible"
  // This handles upgrade perks like GREATER_REGENERATION which requires but is "incompatible" with REGENERATION
  const prerequisiteMet = perk.requiresPerk ? selectedPerks.has(perk.requiresPerk) : true;

  // Check incompatibilities - this perk cannot be selected if user has incompatible perks
  // But skip this check if the "incompatible" perk is actually the prerequisite (upgrade case)
  if (perk.incompatibleWith) {
    for (const incompatibleId of perk.incompatibleWith) {
      // Skip if this "incompatible" perk is the prerequisite (upgrade case)
      if (perk.requiresPerk === incompatibleId && prerequisiteMet) {
        continue;
      }
      if (selectedPerks.has(incompatibleId)) {
        return false;
      }
    }
  }

  // Check if this perk is incompatible with any already selected perk
  // (reverse check - if a selected perk lists this one as incompatible)
  for (const [selectedId] of selectedPerks) {
    const selectedPerk = getPerkData(selectedId);
    if (selectedPerk?.incompatibleWith?.includes(perkId)) {
      return false;
    }
  }

  // Check prerequisites
  if (perk.requiresPerk && !prerequisiteMet) {
    return false;
  }

  return true;
}

/**
 * Get all perks that can be selected given current perks and level
 */
export function getAvailablePerks(
  selectedPerks: Map<PerkId, number>,
  playerLevel: number,
  excludeRare = false
): PerkId[] {
  return ALL_PERKS.filter((perk) => {
    // Exclude rare perks if requested
    if (excludeRare && perk.isRare) return false;

    // Check minimum level requirement
    if (perk.minLevel && playerLevel < perk.minLevel) return false;

    // Check compatibility
    return isPerkCompatible(perk.id, selectedPerks);
  }).map((perk) => perk.id);
}

/**
 * Generate random perk choices for level up
 * Returns 3 perk IDs that are valid for the current state
 */
export function generatePerkChoices(
  selectedPerks: Map<PerkId, number>,
  playerLevel: number,
  hasPerkExpert: boolean,
  hasPerkMaster: boolean
): PerkId[] {
  // Determine if rare perks can appear (10% base chance, 100% with Perk Expert)
  const canGetRare = hasPerkExpert || Math.random() < 0.1;
  const betterRarity = hasPerkMaster;

  // Get available perks (exclude rare unless canGetRare is true)
  const available = getAvailablePerks(selectedPerks, playerLevel, !canGetRare);

  // If no perks available (edge case), return empty
  if (available.length === 0) {
    return [];
  }

  // Weight perks by category (combat/defense more common for beginners)
  const weighted: PerkId[] = [];
  for (const perkId of available) {
    const perk = getPerkData(perkId);
    if (!perk) continue;
    let weight = 1;

    // Combat and defense perks are more common
    if (perk.category === 'combat' || perk.category === 'defense') {
      weight = betterRarity ? 2 : 3;
    }
    // Utility and movement are medium
    else if (perk.category === 'utility' || perk.category === 'movement') {
      weight = 2;
    }
    // Special and gamble are less common
    else {
      weight = betterRarity ? 2 : 1;
    }

    // Add weighted entries
    for (let i = 0; i < weight; i++) {
      weighted.push(perkId);
    }
  }

  // Select 3 unique perks
  const choices: PerkId[] = [];
  const used = new Set<PerkId>();

  // Guard against empty weighted array
  if (weighted.length === 0) {
    return [];
  }

  // Safety limit to prevent infinite loops
  let iterations = 0;
  const MAX_ITERATIONS = weighted.length * 10;

  while (choices.length < 3 && used.size < available.length && iterations < MAX_ITERATIONS) {
    iterations++;
    const randomIndex = Math.floor(Math.random() * weighted.length);
    const perkId = weighted[randomIndex];

    if (perkId !== undefined && !used.has(perkId)) {
      used.add(perkId);
      choices.push(perkId);
    }
  }

  return choices;
}
