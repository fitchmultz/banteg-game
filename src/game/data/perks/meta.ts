/**
 * Meta Perks
 *
 * IDs: 0, 10, 21, 43
 */

import { PerkId } from '../../../types';
import type { PerkData } from './types.js';

export const META_PERKS: PerkData[] = [
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
