/**
 * Special Perks
 *
 * IDs: 19, 22-26, 28, 36-37, 40, 44, 50, 52-54, 56
 * Plus Ion Gun Master (ID 51)
 */

import { PerkId } from '../../../types';
import type { PerkData } from './types.js';

export const SPECIAL_PERKS: PerkData[] = [
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

// Ion Gun Master - ID 51 (separate for clarity)
export const ION_GUN_MASTER_PERK: PerkData = {
  id: PerkId.ION_GUN_MASTER,
  name: 'Ion Gun Master',
  description: "You're good with ion weapons. You rock!",
  category: 'special',
  maxRank: 1,
  effects: [{ type: 'special_ion_gun_master', value: 1 }],
};
