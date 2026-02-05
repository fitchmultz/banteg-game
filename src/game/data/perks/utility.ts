/**
 * Utility Perks
 *
 * IDs: 4, 20, 27, 30
 */

import { PerkId } from '../../../types';
import type { PerkData } from './types.js';

export const UTILITY_PERKS: PerkData[] = [
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
