/**
 * Gamble Perks
 *
 * IDs: 7-8, 15, 24, 32, 41-42, 47, 57
 */

import { PerkId } from '../../../types';
import type { PerkData } from './types.js';

export const GAMBLE_PERKS: PerkData[] = [
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
