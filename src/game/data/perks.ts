/**
 * Perk Data Definitions
 *
 * Based on perk meta table from decompiled source.
 * Defines all 35+ perks with their effects, categories, and metadata.
 */

import { PerkId } from '../../types';

export type PerkCategory =
  | 'combat'
  | 'defense'
  | 'utility'
  | 'movement'
  | 'special'
  | 'gamble'
  | 'meta';

export interface PerkEffect {
  type:
    | 'damage_multiplier'
    | 'fire_rate_multiplier'
    | 'reload_speed_multiplier'
    | 'move_speed_multiplier'
    | 'max_health_multiplier'
    | 'health_regen'
    | 'xp_multiplier'
    | 'clip_size_bonus'
    | 'bonus_duration_multiplier'
    | 'pierce_bonus'
    | 'special_fire_bullets'
    | 'special_infinite_ammo_window'
    | 'special_ammo_refill_on_pickup'
    | 'special_random_weapon'
    | 'special_monster_vision'
    | 'special_shield_on_hit'
    | 'special_regression_bullets'
    | 'special_time_slow_on_hit'
    | 'special_instant_xp'
    | 'special_fatal_lottery'
    | 'special_lifeline_50_50'
    | 'special_jinxed'
    | 'special_infernal_contract'
    | 'special_grim_deal'
    | 'special_death_clock'
    | 'special_highlander'
    | 'special_plaguebearer'
    | 'special_bonus_magnet'
    | 'special_bandage'
    | 'special_gore_intensity'
    // New effect types for proper perk behaviors:
    | 'special_radioactive_aura' // Radiation damage aura around player
    | 'special_evil_eyes' // Damage bonus only when targeting enemy
    | 'special_uranium_dot' // Radiation damage over time on hit
    | 'special_poison_dot' // Poison damage over time on hit
    | 'special_dodger' // Enhanced dodge ability
    | 'special_final_revenge' // Revenge damage on death
    | 'special_veins_of_poison' // Poison damage synergy
    | 'special_toxic_avenger' // Advanced poison effects
    | 'special_ninja' // Enhanced dodging and movement
    | 'special_ion_gun_master' // Ion weapon specialist
    | 'special_angry_reloader'; // Reload-based damage boost
  value: number;
}

export interface PerkData {
  id: PerkId;
  name: string;
  description: string;
  category: PerkCategory;
  maxRank: number;
  effects: PerkEffect[];
  incompatibleWith?: PerkId[];
  requiresPerk?: PerkId;
  minLevel?: number; // Minimum player level to appear
  isRare?: boolean; // Rare perks appear less frequently
}

// ============================================================================
// Combat Perks - Increase damage and firepower
// ============================================================================

const COMBAT_PERKS: PerkData[] = [
  {
    id: PerkId.SHARPSHOOTER,
    name: 'Sharpshooter',
    description: '+15% damage per rank',
    category: 'combat',
    maxRank: 5,
    effects: [{ type: 'damage_multiplier', value: 0.15 }],
  },
  {
    id: PerkId.FASTSHOT,
    name: 'Fastshot',
    description: '+10% fire rate per rank',
    category: 'combat',
    maxRank: 5,
    effects: [{ type: 'fire_rate_multiplier', value: 0.1 }],
  },
  {
    id: PerkId.PYROMANIAC,
    name: 'Pyromaniac',
    description: 'Fire damage +25%',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'special_fire_bullets', value: 1.25 }],
  },
  {
    id: PerkId.PYROKINETIC,
    name: 'Pyrokinetic',
    description: 'Fire bullets last longer',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'bonus_duration_multiplier', value: 0.5 }],
  },
  {
    id: PerkId.RADIOACTIVE,
    name: 'Radioactive',
    description: 'Radiation damage aura around player',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'special_radioactive_aura', value: 10 }], // 10 damage per second to nearby enemies
  },
  {
    id: PerkId.EVIL_EYES,
    name: 'Evil Eyes',
    description: 'Damage bonus when looking at enemy',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'special_evil_eyes', value: 0.25 }], // 25% bonus when targeting enemy
  },
  {
    id: PerkId.AMMUNITION_WITHIN,
    name: 'Ammunition Within',
    description: 'Infinite ammo for 3s after reload',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'special_infinite_ammo_window', value: 3 }],
  },
  {
    id: PerkId.ANXIOUS_LOADER,
    name: 'Anxious Loader',
    description: 'Faster reload when low ammo',
    category: 'combat',
    maxRank: 3,
    effects: [{ type: 'reload_speed_multiplier', value: 0.2 }],
  },
  {
    id: PerkId.AMMO_MANIAC,
    name: 'Ammo Maniac',
    description: 'Refill all weapons on pickup',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'special_ammo_refill_on_pickup', value: 1 }],
  },
  {
    id: PerkId.MY_FAVOURITE_WEAPON,
    name: 'My Favourite Weapon',
    description: '+2 clip size per rank for current weapon',
    category: 'combat',
    maxRank: 3,
    effects: [{ type: 'clip_size_bonus', value: 2 }],
  },
  {
    id: PerkId.RANDOM_WEAPON,
    name: 'Random Weapon',
    description: 'Get random weapon, bonus stats',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'special_random_weapon', value: 1 }],
  },
  {
    id: PerkId.BLOODY_MESS,
    name: 'Bloody Mess',
    description: 'Increases blood and gore effects. More blood splatter on enemy death.',
    category: 'combat',
    maxRank: 3,
    effects: [{ type: 'special_gore_intensity', value: 1 }],
  },
];

// ============================================================================
// Defense Perks - Increase survivability
// ============================================================================

const DEFENSE_PERKS: PerkData[] = [
  {
    id: PerkId.THICK_SKINNED,
    name: 'Thick Skinned',
    description: '+33% max health',
    category: 'defense',
    maxRank: 1,
    effects: [{ type: 'max_health_multiplier', value: 0.33 }],
    incompatibleWith: [PerkId.REGENERATION, PerkId.GREATER_REGENERATION],
  },
  {
    id: PerkId.REGENERATION,
    name: 'Regeneration',
    description: 'Heal 1 HP per second',
    category: 'defense',
    maxRank: 1,
    effects: [{ type: 'health_regen', value: 1 }],
    incompatibleWith: [PerkId.THICK_SKINNED],
  },
  {
    id: PerkId.GREATER_REGENERATION,
    name: 'Greater Regeneration',
    description: 'Heal 3 HP per second',
    category: 'defense',
    maxRank: 1,
    effects: [{ type: 'health_regen', value: 3 }],
    requiresPerk: PerkId.REGENERATION,
    incompatibleWith: [PerkId.THICK_SKINNED, PerkId.REGENERATION],
  },
  {
    id: PerkId.BANDAGE,
    name: 'Bandage',
    description: 'Random health boost (1-50x current)',
    category: 'defense',
    maxRank: 1,
    effects: [{ type: 'special_bandage', value: 1 }],
  },
  {
    id: PerkId.BREATHING_ROOM,
    name: 'Breathing Room',
    description: 'Reduce all enemies hitbox temporarily',
    category: 'defense',
    maxRank: 1,
    effects: [{ type: 'special_shield_on_hit', value: 1 }],
  },
  {
    id: PerkId.DOCTOR,
    name: 'Doctor',
    description: 'Medkits heal more',
    category: 'defense',
    maxRank: 1,
    effects: [{ type: 'health_regen', value: 0.5 }],
  },
];

// ============================================================================
// Utility Perks - Quality of life improvements
// ============================================================================

const UTILITY_PERKS: PerkData[] = [
  {
    id: PerkId.BONUS_ECONOMIST,
    name: 'Bonus Economist',
    description: 'Bonuses last longer',
    category: 'utility',
    maxRank: 3,
    effects: [{ type: 'bonus_duration_multiplier', value: 0.25 }],
  },
  {
    id: PerkId.BONUS_MAGNET,
    name: 'Bonus Magnet',
    description: 'Auto-collect nearby bonuses',
    category: 'utility',
    maxRank: 1,
    effects: [{ type: 'special_bonus_magnet', value: 1 }],
  },
  {
    id: PerkId.MONSTER_VISION,
    name: 'Monster Vision',
    description: 'See enemies through walls',
    category: 'utility',
    maxRank: 1,
    effects: [{ type: 'special_monster_vision', value: 1 }],
  },
  {
    id: PerkId.LEAN_MEAN_EXP_MACHINE,
    name: 'Lean Mean EXP Machine',
    description: '+10% XP per rank',
    category: 'utility',
    maxRank: 5,
    effects: [{ type: 'xp_multiplier', value: 0.1 }],
  },
];

// ============================================================================
// Movement Perks - Speed and agility
// ============================================================================

const MOVEMENT_PERKS: PerkData[] = [
  {
    id: PerkId.LONG_DISTANCE_RUNNER,
    name: 'Long Distance Runner',
    description: '+10% move speed',
    category: 'movement',
    maxRank: 3,
    effects: [{ type: 'move_speed_multiplier', value: 0.1 }],
  },
];

// ============================================================================
// Special Perks - Unique abilities
// ============================================================================

const SPECIAL_PERKS: PerkData[] = [
  {
    id: PerkId.REFLEX_BOOSTED,
    name: 'Reflex Boosted',
    description: 'Slow time briefly when hit',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_time_slow_on_hit', value: 1 }],
  },
  {
    id: PerkId.REGRESSION_BULLETS,
    name: 'Regression Bullets',
    description: 'Bullets return ammo on hit',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_regression_bullets', value: 1 }],
  },
  {
    id: PerkId.URANIUM_FILLED_BULLETS,
    name: 'Uranium Filled Bullets',
    description: 'Radiation damage over time',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_uranium_dot', value: 5 }], // 5 radiation damage per tick
  },
  {
    id: PerkId.POISON_BULLETS,
    name: 'Poison Bullets',
    description: 'Poison enemies',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_poison_dot', value: 3 }], // 3 poison damage per tick
  },
  // Missing perks from canonical data
  {
    id: PerkId.DODGER,
    name: 'Dodger',
    description: 'Enhanced dodge ability',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_dodger', value: 1 }],
  },
  {
    id: PerkId.FINAL_REVENGE,
    name: 'Final Revenge',
    description: 'Revenge damage on death',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_final_revenge', value: 1 }],
  },
  {
    id: PerkId.VEINS_OF_POISON,
    name: 'Veins of Poison',
    description: 'Poison damage synergy',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_veins_of_poison', value: 1 }],
  },
  {
    id: PerkId.TOXIC_AVENGER,
    name: 'Toxic Avenger',
    description: 'Advanced poison effects',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_toxic_avenger', value: 1 }],
  },
  {
    id: PerkId.NINJA,
    name: 'Ninja',
    description: 'Enhanced dodging and movement',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_ninja', value: 1 }],
  },
  {
    id: PerkId.ION_GUN_MASTER,
    name: 'Ion Gun Master',
    description: 'Ion weapon specialist',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_ion_gun_master', value: 1 }],
  },
  {
    id: PerkId.ANGRY_RELOADER,
    name: 'Angry Reloader',
    description: 'Reload-based damage boost',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_angry_reloader', value: 1 }],
  },
];

// ============================================================================
// Gamble Perks - High risk, high reward
// ============================================================================

const GAMBLE_PERKS: PerkData[] = [
  {
    id: PerkId.INSTANT_WINNER,
    name: 'Instant Winner',
    description: '+2500 XP immediately',
    category: 'gamble',
    maxRank: 1,
    effects: [{ type: 'special_instant_xp', value: 2500 }],
    isRare: true,
  },
  {
    id: PerkId.FATAL_LOTTERY,
    name: 'Fatal Lottery',
    description: '50% chance +10000 XP, 50% instant death',
    category: 'gamble',
    maxRank: 1,
    effects: [{ type: 'special_fatal_lottery', value: 10000 }],
    isRare: true,
  },
  {
    id: PerkId.LIFELINE_50_50,
    name: 'Lifeline 50/50',
    description: 'Kill 50% of damaged enemies instantly',
    category: 'gamble',
    maxRank: 1,
    effects: [{ type: 'special_lifeline_50_50', value: 0.5 }],
    isRare: true,
  },
  {
    id: PerkId.JINXED,
    name: 'Jinxed',
    description: 'Negative effects on enemies, risk to player',
    category: 'gamble',
    maxRank: 1,
    effects: [{ type: 'special_jinxed', value: 1 }],
    isRare: true,
  },
  {
    id: PerkId.INFERNAL_CONTRACT,
    name: 'Infernal Contract',
    description: '+3 levels but health reduced to 10%',
    category: 'gamble',
    maxRank: 1,
    effects: [{ type: 'special_infernal_contract', value: 3 }],
    isRare: true,
  },
  {
    id: PerkId.GRIM_DEAL,
    name: 'Grim Deal',
    description: 'Current HP converted to XP, then death',
    category: 'gamble',
    maxRank: 1,
    effects: [{ type: 'special_grim_deal', value: 1 }],
    isRare: true,
  },
  {
    id: PerkId.DEATH_CLOCK,
    name: 'Death Clock',
    description: 'Huge regen but limited time to survive',
    category: 'gamble',
    maxRank: 1,
    effects: [{ type: 'special_death_clock', value: 1 }],
    isRare: true,
  },
  {
    id: PerkId.HIGHLANDER,
    name: 'Highlander',
    description: 'Only one enemy type, but more dangerous',
    category: 'gamble',
    maxRank: 1,
    effects: [{ type: 'special_highlander', value: 1 }],
    isRare: true,
  },
];

// ============================================================================
// Meta Perks - Improve perk selection
// ============================================================================

const META_PERKS: PerkData[] = [
  {
    id: PerkId.PLAGUEBEARER,
    name: 'Plaguebearer',
    description: 'Enemies infect each other on death',
    category: 'meta',
    maxRank: 1,
    effects: [{ type: 'special_plaguebearer', value: 1 }],
    isRare: true,
  },
  {
    id: PerkId.PERK_EXPERT,
    name: 'Perk Expert',
    description: 'Better perk choices offered',
    category: 'meta',
    maxRank: 1,
    effects: [],
  },
  {
    id: PerkId.PERK_MASTER,
    name: 'Perk Master',
    description: 'Even better perk choices, requires Expert',
    category: 'meta',
    maxRank: 1,
    effects: [],
    requiresPerk: PerkId.PERK_EXPERT,
  },
];

// ============================================================================
// All Perks Combined
// ============================================================================

export const ALL_PERKS: PerkData[] = [
  ...COMBAT_PERKS,
  ...DEFENSE_PERKS,
  ...UTILITY_PERKS,
  ...MOVEMENT_PERKS,
  ...SPECIAL_PERKS,
  ...GAMBLE_PERKS,
  ...META_PERKS,
];

// Map for quick lookup
export const PERK_DATA_MAP: ReadonlyMap<PerkId, PerkData> = new Map(
  ALL_PERKS.map((perk) => [perk.id, perk])
);

// ============================================================================
// Helper Functions
// ============================================================================

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

  while (choices.length < 3 && used.size < available.length) {
    const randomIndex = Math.floor(Math.random() * weighted.length);
    const perkId = weighted[randomIndex];

    if (perkId !== undefined && !used.has(perkId)) {
      used.add(perkId);
      choices.push(perkId);
    }
  }

  return choices;
}

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
