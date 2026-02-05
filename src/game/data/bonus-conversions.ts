/**
 * Bonus Stat Conversion Utilities
 *
 * Derived from analysis of bonus_metadata_init at 00412660.
 * Handles special spawn logic for rarity=0 bonuses and duration conversions.
 */

import { BonusType } from '../../types/game';

/** Bonuses with rarity=0 use special spawn logic in original engine */
const SPECIAL_SPAWN_BONUSES: Set<number> = new Set([
  BonusType.ATOMIC,
  BonusType.DOUBLE_EXPERIENCE,
  BonusType.FIREBLAST,
  BonusType.SHOCK_CHAIN,
]);

/** Bonuses that are instant in canonical but timed in gameplay */
const INSTANT_TO_TIMED: Record<number, number> = {
  [BonusType.REFLEX_BOOST]: 5,
  [BonusType.SHIELD]: 6,
  [BonusType.FREEZE]: 8,
  [BonusType.SPEED]: 9,
  [BonusType.ENERGIZER]: 10,
  [BonusType.WEAPON_POWER_UP]: 7,
  [BonusType.FIRE_BULLETS]: 11,
};

/**
 * Check if a bonus uses special spawn logic (rarity=0 in canonical).
 *
 * @param bonusType - Bonus type ID
 * @returns True if bonus uses special spawn logic
 */
export function usesSpecialSpawnLogic(bonusType: number): boolean {
  return SPECIAL_SPAWN_BONUSES.has(bonusType);
}

/**
 * Convert canonical rarity to gameplay rarity.
 *
 * In the original engine:
 * - rarity=0 means "special spawn logic" (not random spawn)
 * - Gameplay uses minimum of 1 for valid spawn weights
 *
 * @param canonicalRarity - Raw rarity from decompile (0 = special)
 * @param bonusType - Bonus type ID
 * @returns Gameplay rarity (minimum 1 for spawnable bonuses)
 */
export function convertBonusRarity(canonicalRarity: number, bonusType: number): number {
  // If canonical is 0, this bonus uses special spawn logic
  // For gameplay, we assign a minimum rarity of 1 for the spawn system
  if (canonicalRarity === 0) {
    // Special spawn bonuses get low but non-zero rarity
    if (usesSpecialSpawnLogic(bonusType)) {
      return 1;
    }
    // Other zero-rarity bonuses (shouldn't happen)
    return 1;
  }

  return canonicalRarity;
}

/**
 * Convert canonical duration to gameplay duration.
 *
 * Canonical durations:
 * - -1 = permanent/unlimited (weapon bonus)
 * - 0 = instant (some bonuses in original)
 * - >0 = seconds
 *
 * Gameplay uses actual seconds for timed bonuses.
 *
 * @param canonicalDuration - Raw duration from decompile
 * @param bonusType - Bonus type ID
 * @returns Gameplay duration in seconds
 */
export function convertBonusDuration(canonicalDuration: number, bonusType: number): number {
  // Keep special values as-is
  if (canonicalDuration < 0) return -1; // Permanent (weapon bonus)

  // Convert instant (0) to timed for certain bonuses
  if (canonicalDuration === 0 && INSTANT_TO_TIMED[bonusType] !== undefined) {
    return INSTANT_TO_TIMED[bonusType];
  }

  // Keep positive durations as-is
  return canonicalDuration;
}

/** Full bonus stat conversion result */
export interface ConvertedBonusStats {
  rarity: number;
  duration: number;
}

/**
 * Convert all stats for a bonus at once.
 *
 * @param canonicalRarity - Raw rarity from decompile
 * @param canonicalDuration - Raw duration from decompile
 * @param bonusType - Bonus type ID
 * @returns Converted gameplay stats
 */
export function convertBonusStats(
  canonicalRarity: number,
  canonicalDuration: number,
  bonusType: number
): ConvertedBonusStats {
  return {
    rarity: convertBonusRarity(canonicalRarity, bonusType),
    duration: convertBonusDuration(canonicalDuration, bonusType),
  };
}

/**
 * Get canonical bonus values as extracted from decompile.
 * These are the raw values before conversion.
 */
export const CANONICAL_BONUS_VALUES: Record<
  BonusType,
  { duration: number; rarity: number }
> = {
  [BonusType.POINTS]: { duration: 12, rarity: 500 },
  [BonusType.WEAPON]: { duration: -1, rarity: 3 },
  [BonusType.ATOMIC]: { duration: 1, rarity: 0 },
  [BonusType.DOUBLE_EXPERIENCE]: { duration: 0, rarity: 0 },
  [BonusType.FIREBLAST]: { duration: 2, rarity: 0 },
  [BonusType.SHOCK_CHAIN]: { duration: 3, rarity: 0 },
  [BonusType.REFLEX_BOOST]: { duration: 0, rarity: 3 },
  [BonusType.SHIELD]: { duration: 0, rarity: 7 },
  [BonusType.FREEZE]: { duration: 0, rarity: 5 },
  [BonusType.SPEED]: { duration: 0, rarity: 8 },
  [BonusType.ENERGIZER]: { duration: 0, rarity: 8 },
  [BonusType.WEAPON_POWER_UP]: { duration: 0, rarity: 10 },
  [BonusType.FIRE_BULLETS]: { duration: 0, rarity: 4 },
  [BonusType.MEDIKIT]: { duration: 14, rarity: 10 },
};
