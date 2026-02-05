/**
 * Combat Perks
 *
 * IDs: 1-3, 6, 9, 11-14, 16-18, 31, 34-35, 39, 48
 */

import { PerkId } from '../../../types';
import type { PerkData } from './types.js';

export const COMBAT_PERKS: PerkData[] = [
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
