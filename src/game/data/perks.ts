/**
 * Perk Data Definitions
 *
 * Based on perk meta table from decompiled source.
 * Defines all 58 perks (IDs 0-57) with their effects, categories, and metadata.
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
    | 'special_angry_reloader' // Reload-based damage boost
    | 'special_stationary_reloader' // Slower reload when moving
    | 'special_man_bomb' // Periodic explosion around player
    | 'special_fire_caugh' // Fireball attack
    | 'special_living_fortress' // Defense boost when stationary
    | 'special_tough_reloader' // Damage reduction during reload
    | 'special_alternate_weapon'; // Dual weapon wielding
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
// Meta Perks - IDs 0, 10, 21, 43
// ============================================================================

const META_PERKS: PerkData[] = [
  {
    id: PerkId.ANTIPERK,
    name: 'AntiPerk',
    description: 'You should not be seeing this...',
    category: 'meta',
    maxRank: 1,
    effects: [],
  },
  {
    id: PerkId.PLAGUEBEARER,
    name: 'Plaguebearer',
    description: 'You carry a horrible disease. Go spread it!',
    category: 'meta',
    maxRank: 1,
    effects: [{ type: 'special_plaguebearer', value: 1 }],
    isRare: true,
  },
  {
    id: PerkId.PERK_EXPERT,
    name: 'Perk Expert',
    description: 'You sure know how to pick a perk. Better options available.',
    category: 'meta',
    maxRank: 1,
    effects: [],
  },
  {
    id: PerkId.PERK_MASTER,
    name: 'Perk Master',
    description: 'Being the Perk Expert taught you even more.',
    category: 'meta',
    maxRank: 1,
    effects: [],
    requiresPerk: PerkId.PERK_EXPERT,
  },
];

// ============================================================================
// Combat Perks - IDs 1-3, 6, 9, 11-14, 16-18, 31, 34-35, 39, 48
// ============================================================================

const COMBAT_PERKS: PerkData[] = [
  {
    id: PerkId.BLOODY_MESS_QUICK_LEARNER,
    name: 'Bloody Mess',
    description: 'More the merrier! More blood guaranteed!',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'special_gore_intensity', value: 1 }],
  },
  {
    id: PerkId.SHARPSHOOTER,
    name: 'Sharpshooter',
    description: 'Miraculously your aiming improves!',
    category: 'combat',
    maxRank: 5,
    effects: [{ type: 'damage_multiplier', value: 0.15 }],
  },
  {
    id: PerkId.FASTLOADER,
    name: 'Fastloader',
    description: 'Man, you sure know how to load a gun.',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'reload_speed_multiplier', value: 0.3 }],
  },
  {
    id: PerkId.PYROKINETIC,
    name: 'Pyrokinetic',
    description: 'You see flames everywhere. Bare also.',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'bonus_duration_multiplier', value: 0.5 }],
  },
  {
    id: PerkId.ALTERNATE_WEAPON,
    name: 'Alternate Weapon',
    description: 'Ever fancied about having two weapons at the same time?',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'special_alternate_weapon', value: 1 }],
  },
  {
    id: PerkId.EVIL_EYES,
    name: 'Evil Eyes',
    description: 'No living, nor dead, can resist the power of your eyes!',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'special_evil_eyes', value: 0.25 }], // 25% bonus when targeting enemy
  },
  {
    id: PerkId.AMMO_MANIAC,
    name: 'Ammo Maniac',
    description: 'You squeeze and you push and you get more ammo!',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'special_ammo_refill_on_pickup', value: 1 }],
  },
  {
    id: PerkId.RADIOACTIVE,
    name: 'Radioactive',
    description: 'You are the Radioactive man, you are burning!',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'special_radioactive_aura', value: 10 }], // 10 damage per second to nearby enemies
  },
  {
    id: PerkId.FASTSHOT,
    name: 'Fastshot',
    description: 'Funny how you make your gun spit faster!',
    category: 'combat',
    maxRank: 5,
    effects: [{ type: 'fire_rate_multiplier', value: 0.1 }],
  },
  {
    id: PerkId.RANDOM_WEAPON,
    name: 'Random Weapon',
    description: 'Here, have this weapon. No questions asked.',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'special_random_weapon', value: 1 }],
  },
  {
    id: PerkId.MR_MELEE,
    name: 'Mr. Melee',
    description: 'You master the art of melee fighting.',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'damage_multiplier', value: 0.5 }], // 50% bonus to melee damage
  },
  {
    id: PerkId.ANXIOUS_LOADER,
    name: 'Anxious Loader',
    description: "When you can't stand waiting you load faster.",
    category: 'combat',
    maxRank: 3,
    effects: [{ type: 'reload_speed_multiplier', value: 0.2 }],
  },
  {
    id: PerkId.HOT_TEMPERED,
    name: 'Hot Tempered',
    description: 'It literally boils inside you. Touch them and they burn!',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'special_fire_bullets', value: 1.25 }],
  },
  {
    id: PerkId.BARREL_GREASER,
    name: 'Barrel Greaser',
    description: 'After studying a lot of physics and applied mechanics.',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'fire_rate_multiplier', value: 0.15 }],
  },
  {
    id: PerkId.AMMUNITION_WITHIN,
    name: 'Ammunition Within',
    description: "Empty clip doesn't prevent you from firing.",
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'special_infinite_ammo_window', value: 3 }],
  },
  {
    id: PerkId.PYROMANIAC,
    name: 'Pyromaniac',
    description: 'You just enjoy using fire as your weapon.',
    category: 'combat',
    maxRank: 1,
    effects: [{ type: 'special_fire_bullets', value: 1.25 }],
  },
  {
    id: PerkId.MY_FAVOURITE_WEAPON,
    name: 'My Favourite Weapon',
    description: 'You have grown very fond of your present weapon.',
    category: 'combat',
    maxRank: 3,
    effects: [{ type: 'clip_size_bonus', value: 2 }],
  },
];

// ============================================================================
// Defense Perks - IDs 29, 32-33, 38, 45-46, 49, 55
// ============================================================================

const DEFENSE_PERKS: PerkData[] = [
  {
    id: PerkId.DOCTOR,
    name: 'Doctor',
    description: 'With a single glance you can tell what is wrong.',
    category: 'defense',
    maxRank: 1,
    effects: [{ type: 'health_regen', value: 0.5 }],
  },
  {
    id: PerkId.BONUS_ECONOMIST,
    name: 'Bonus Economist',
    description: 'Your bonus power ups last 50% longer.',
    category: 'utility',
    maxRank: 3,
    effects: [{ type: 'bonus_duration_multiplier', value: 0.25 }],
  },
  {
    id: PerkId.THICK_SKINNED,
    name: 'Thick Skinned',
    description: 'Trade 1/3 of your health for only getting 1/3 damage.',
    category: 'defense',
    maxRank: 1,
    effects: [{ type: 'max_health_multiplier', value: 0.33 }],
    incompatibleWith: [PerkId.REGENERATION, PerkId.GREATER_REGENERATION],
  },
  {
    id: PerkId.REGENERATION,
    name: 'Regeneration',
    description: 'Your health replenishes but very slowly.',
    category: 'defense',
    maxRank: 1,
    effects: [{ type: 'health_regen', value: 1 }],
    incompatibleWith: [PerkId.THICK_SKINNED],
  },
  {
    id: PerkId.GREATER_REGENERATION,
    name: 'Greater Regeneration',
    description: 'Your health replenishes faster than normal.',
    category: 'defense',
    maxRank: 1,
    effects: [{ type: 'health_regen', value: 3 }],
    requiresPerk: PerkId.REGENERATION,
    incompatibleWith: [PerkId.THICK_SKINNED, PerkId.REGENERATION],
  },
  {
    id: PerkId.BREATHING_ROOM,
    name: 'Breathing Room',
    description: 'Trade 2/3rds of your health for tiny enemies.',
    category: 'defense',
    maxRank: 1,
    effects: [{ type: 'special_shield_on_hit', value: 1 }],
  },
  {
    id: PerkId.BANDAGE,
    name: 'Bandage',
    description: 'Here, eat this bandage and you will feel better.',
    category: 'defense',
    maxRank: 1,
    effects: [{ type: 'special_bandage', value: 1 }],
  },
  {
    id: PerkId.LIVING_FORTRESS,
    name: 'Living Fortress',
    description: "It comes a time in each man's life when he must take a stand.",
    category: 'defense',
    maxRank: 1,
    effects: [{ type: 'special_living_fortress', value: 1 }],
  },
];

// ============================================================================
// Utility Perks - IDs 4, 20, 27, 30
// ============================================================================

const UTILITY_PERKS: PerkData[] = [
  {
    id: PerkId.LEAN_MEAN_EXP_MACHINE,
    name: 'Lean Mean Exp Machine',
    description: 'Why kill for experience when you can just pick this?',
    category: 'utility',
    maxRank: 5,
    effects: [{ type: 'xp_multiplier', value: 0.1 }],
  },
  {
    id: PerkId.TELEKINETIC,
    name: 'Telekinetic',
    description: 'Picking up bonuses has never been easier.',
    category: 'utility',
    maxRank: 1,
    effects: [{ type: 'special_bonus_magnet', value: 1 }],
  },
  {
    id: PerkId.BONUS_MAGNET,
    name: 'Bonus Magnet',
    description: 'You somehow seem to lure all kinds of bonuses to you.',
    category: 'utility',
    maxRank: 1,
    effects: [{ type: 'special_bonus_magnet', value: 1 }],
  },
  {
    id: PerkId.MONSTER_VISION,
    name: 'Monster Vision',
    description: 'With your newly enhanced senses you can see them all.',
    category: 'utility',
    maxRank: 1,
    effects: [{ type: 'special_monster_vision', value: 1 }],
  },
];

// ============================================================================
// Movement Perks - ID 5
// ============================================================================

const MOVEMENT_PERKS: PerkData[] = [
  {
    id: PerkId.LONG_DISTANCE_RUNNER,
    name: 'Long Distance Runner',
    description: 'You move like a train that has full steam ahead!',
    category: 'movement',
    maxRank: 3,
    effects: [{ type: 'move_speed_multiplier', value: 0.1 }],
  },
];

// ============================================================================
// Special Perks - IDs 19, 22-26, 28, 36-37, 40, 44, 50, 52-54, 56
// ============================================================================

const SPECIAL_PERKS: PerkData[] = [
  {
    id: PerkId.FINAL_REVENGE,
    name: 'Final Revenge',
    description: 'Pick this and you will get your revenge when you die.',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_final_revenge', value: 1 }],
  },
  {
    id: PerkId.UNSTOPPABLE,
    name: 'Unstoppable',
    description: "Monsters can't slow you down with their nasty bites.",
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_time_slow_on_hit', value: 1 }],
  },
  {
    id: PerkId.REGRESSION_BULLETS,
    name: 'Regression Bullets',
    description: 'Attempt to shoot with an empty clip and it might just work.',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_regression_bullets', value: 1 }],
  },
  {
    id: PerkId.POISON_BULLETS,
    name: 'Poison Bullets',
    description: 'You tend to explicitly treat each bullet with poison.',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_poison_dot', value: 3 }], // 3 poison damage per tick
  },
  {
    id: PerkId.DODGER,
    name: 'Dodger',
    description: 'It seems so stupid just to take the blow, so you dodge it.',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_dodger', value: 1 }],
  },
  {
    id: PerkId.URANIUM_FILLED_BULLETS,
    name: 'Uranium Filled Bullets',
    description: 'Your bullets have a nice creamy uranium filling.',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_uranium_dot', value: 5 }], // 5 radiation damage per tick
  },
  {
    id: PerkId.VEINS_OF_POISON,
    name: 'Veins of Poison',
    description: 'A strong poison runs through your veins.',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_veins_of_poison', value: 1 }],
  },
  {
    id: PerkId.TOXIC_AVENGER,
    name: 'Toxic Avenger',
    description: 'You started out just by being poisonous.',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_toxic_avenger', value: 1 }],
  },
  {
    id: PerkId.NINJA,
    name: 'Ninja',
    description: 'You have taken your dodging abilities to a whole new level.',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_ninja', value: 1 }],
  },
  {
    id: PerkId.REFLEX_BOOSTED,
    name: 'Reflex Boosted',
    description: 'To you the world seems to go on a lazy pace.',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_time_slow_on_hit', value: 1 }],
  },
  {
    id: PerkId.ANGRY_RELOADER,
    name: 'Angry Reloader',
    description: 'You hate it when you run out of shots.',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_angry_reloader', value: 1 }],
  },
  {
    id: PerkId.STATIONARY_RELOADER,
    name: 'Stationary Reloader',
    description: "It's incredibly hard to reload your weapons while moving.",
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_stationary_reloader', value: 1 }],
  },
  {
    id: PerkId.MAN_BOMB,
    name: 'Man Bomb',
    description: 'You have the ability to go boom from time to time.',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_man_bomb', value: 1 }],
  },
  {
    id: PerkId.FIRE_CAUGH,
    name: 'Fire Caugh',
    description: 'You have a fireball stuck in your throat.',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_fire_caugh', value: 1 }],
  },
  {
    id: PerkId.TOUGH_RELOADER,
    name: 'Tough Reloader',
    description: 'Damage received during reloading is reduced.',
    category: 'special',
    maxRank: 1,
    effects: [{ type: 'special_tough_reloader', value: 0.5 }], // 50% damage reduction
  },
];

// ============================================================================
// Gamble Perks - IDs 7-8, 15, 24, 32, 41-42, 47, 57
// ============================================================================

const GAMBLE_PERKS: PerkData[] = [
  {
    id: PerkId.INSTANT_WINNER,
    name: 'Instant Winner',
    description: '2500 experience points. Right away!',
    category: 'gamble',
    maxRank: 1,
    effects: [{ type: 'special_instant_xp', value: 2500 }],
    isRare: true,
  },
  {
    id: PerkId.GRIM_DEAL,
    name: 'Grim Deal',
    description: "I'll make you a deal: I'll give you experience for your health.",
    category: 'gamble',
    maxRank: 1,
    effects: [{ type: 'special_grim_deal', value: 1 }],
    isRare: true,
  },
  {
    id: PerkId.FATAL_LOTTERY,
    name: 'Fatal Lottery',
    description: 'Fifty fifty chance of dying OR getting loads of experience.',
    category: 'gamble',
    maxRank: 1,
    effects: [{ type: 'special_fatal_lottery', value: 10000 }],
    isRare: true,
  },
  {
    id: PerkId.INFERNAL_CONTRACT,
    name: 'Infernal Contract',
    description: 'In exchange for your soul, a dark power grants you power.',
    category: 'gamble',
    maxRank: 1,
    effects: [{ type: 'special_infernal_contract', value: 3 }],
    isRare: true,
  },
  {
    id: PerkId.LIFELINE_50_50,
    name: 'Lifeline 50/50',
    description: 'The computer removes half of the monsters.',
    category: 'gamble',
    maxRank: 1,
    effects: [{ type: 'special_lifeline_50_50', value: 0.5 }],
    isRare: true,
  },
  {
    id: PerkId.JINXED,
    name: 'Jinxed',
    description: 'Things happen near you. Strangest things.',
    category: 'gamble',
    maxRank: 1,
    effects: [{ type: 'special_jinxed', value: 1 }],
    isRare: true,
  },
  {
    id: PerkId.DEATH_CLOCK,
    name: 'Death Clock',
    description: 'You die exactly in 30 seconds. You gain huge regen.',
    category: 'gamble',
    maxRank: 1,
    effects: [{ type: 'special_death_clock', value: 1 }],
    isRare: true,
  },
  {
    id: PerkId.HIGHLANDER,
    name: 'Highlander',
    description: 'You are immortal. Well, almost immortal.',
    category: 'gamble',
    maxRank: 1,
    effects: [{ type: 'special_highlander', value: 1 }],
    isRare: true,
  },
];

// ============================================================================
// Ion Gun Master - ID 51 (separate for clarity)
// ============================================================================

const ION_GUN_MASTER_PERK: PerkData = {
  id: PerkId.ION_GUN_MASTER,
  name: 'Ion Gun Master',
  description: "You're good with ion weapons. You rock!",
  category: 'special',
  maxRank: 1,
  effects: [{ type: 'special_ion_gun_master', value: 1 }],
};

// ============================================================================
// All Perks Combined - sorted by ID for correct ordering
// ============================================================================

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
