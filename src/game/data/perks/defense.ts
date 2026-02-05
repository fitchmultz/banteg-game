/**
 * Defense Perks
 *
 * IDs: 29, 32-33, 38, 45-46, 49, 55
 */

import { PerkId } from '../../../types';
import type { PerkData } from './types.js';

export const DEFENSE_PERKS: PerkData[] = [
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
