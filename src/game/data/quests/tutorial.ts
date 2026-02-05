/**
 * Tutorial Quests
 *
 * First 4 quests introducing new players to the game mechanics.
 */

import { CreatureTypeId } from '../../../types';
import type { QuestData } from './types';
import { createWaveSpawns } from './helpers';

export const QUEST_NAGOLIPOLI: QuestData = {
  id: 'nagolipoli',
  name: 'Nagolipoli',
  description: 'Survive the initial zombie outbreak. Tutorial level for new players.',
  timeLimitMs: 480000,
  objectives: [{ type: 'survive_time', target: 60, description: 'Survive for 60 seconds' }],
  spawnEntries: [
    // Initial spawn
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 200, y: 200, triggerTimeMs: 0, count: 3 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -200, y: 200, triggerTimeMs: 0, count: 3 },
    // Wave spawns every 10 seconds
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 2, 5, 10000, 10000),
  ],
};

export const QUEST_MONSTER_BLUES: QuestData = {
  id: 'monster_blues',
  name: 'Monster Blues',
  description: 'Eliminate 50 zombies. Learn the basics of combat.',
  timeLimitMs: 480000,
  objectives: [{ type: 'kill_count', target: 50, description: 'Kill 50 zombies' }],
  spawnEntries: [
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 4, 8, 0, 3000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 2, 5, 15000, 5000),
  ],
  unlockRequirement: 'nagolipoli',
};

export const QUEST_THE_GATHERING: QuestData = {
  id: 'the_gathering',
  name: 'The Gathering',
  description: 'Face increasing waves of mixed enemies.',
  timeLimitMs: 480000,
  objectives: [{ type: 'kill_count', target: 100, description: 'Kill 100 enemies' }],
  spawnEntries: [
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 5, 6, 0, 4000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 3, 5, 10000, 5000),
    ...createWaveSpawns(CreatureTypeId.SPIDER_SMALL, 4, 4, 20000, 6000),
  ],
  unlockRequirement: 'monster_blues',
};

export const QUEST_ARMY_OF_THREE: QuestData = {
  id: 'army_of_three',
  name: 'Army of Three',
  description: 'Three powerful elite enemies await. Your first real challenge.',
  timeLimitMs: 480000,
  objectives: [{ type: 'kill_count', target: 3, description: 'Kill 3 tank zombies' }],
  spawnEntries: [
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 300, y: 300, triggerTimeMs: 0, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -300, y: 300, triggerTimeMs: 5000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -300, triggerTimeMs: 10000, count: 1 },
  ],
  unlockRequirement: 'the_gathering',
};
