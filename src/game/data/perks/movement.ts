/**
 * Movement Perks
 *
 * ID: 5
 */

import { PerkId } from '../../../types';
import type { PerkData } from './types.js';

export const MOVEMENT_PERKS: PerkData[] = [
  {
    id: PerkId.LONG_DISTANCE_RUNNER,
    name: 'Long Distance Runner',
    description: 'You move like a train that has full steam ahead!',
    category: 'movement',
    maxRank: 3,
    effects: [{ type: 'move_speed_multiplier', value: 0.1 }],
  },
];
