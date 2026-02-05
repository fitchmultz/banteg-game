/**
 * Tier 3 Advanced Challenges
 *
 * Advanced challenges for experienced players.
 */

import { CreatureTypeId } from '../../../types';
import type { QuestData } from './types';
import { createWaveSpawns, createCornerSpawns } from './helpers';

export const QUEST_NESTING_GROUNDS: QuestData = {
  id: 'nesting_grounds',
  name: 'Nesting Grounds',
  description: 'Kill 60 spiders with increasing difficulty.',
  timeLimitMs: 240000,
  objectives: [{ type: 'kill_count', target: 60, description: 'Kill 60 spiders' }],
  spawnEntries: [
    ...createWaveSpawns(CreatureTypeId.SPIDER_SMALL, 4, 5, 0, 3000),
    ...createWaveSpawns(CreatureTypeId.SPIDER_LARGE, 2, 5, 8000, 5000),
    ...createWaveSpawns(CreatureTypeId.SPIDER_SMALL, 6, 5, 15000, 2500),
    ...createWaveSpawns(CreatureTypeId.SPIDER_LARGE, 4, 5, 25000, 4000),
  ],
  unlockRequirement: 'ghost_patrols',
};

export const QUEST_ALIEN_DENS: QuestData = {
  id: 'alien_dens',
  name: 'Alien Dens',
  description: 'Clear 3 alien nests (location-based challenge).',
  timeLimitMs: 180000,
  objectives: [{ type: 'kill_count', target: 50, description: 'Clear the alien dens' }],
  spawnEntries: [
    // Nest 1
    ...createCornerSpawns(CreatureTypeId.ALIEN_TROOPER, 3, 0, 200),
    // Nest 2
    ...createCornerSpawns(CreatureTypeId.ALIEN_TROOPER, 4, 20000, 250),
    ...createCornerSpawns(CreatureTypeId.ALIEN_ELITE, 2, 20000, 300),
    // Nest 3
    ...createCornerSpawns(CreatureTypeId.ALIEN_ELITE, 3, 45000, 300),
    ...createCornerSpawns(CreatureTypeId.ALIEN_TROOPER, 5, 45000, 350),
  ],
  unlockRequirement: 'nesting_grounds',
};

export const QUEST_ARACHNOID_FARM: QuestData = {
  id: 'arachnoid_farm',
  name: 'Arachnoid Farm',
  description: 'Kill 100 spiders in massive waves.',
  timeLimitMs: 240000,
  objectives: [{ type: 'kill_count', target: 100, description: 'Kill 100 spiders' }],
  spawnEntries: [
    ...createWaveSpawns(CreatureTypeId.SPIDER_SMALL, 6, 10, 0, 2000),
    ...createWaveSpawns(CreatureTypeId.SPIDER_LARGE, 3, 8, 5000, 4000),
    ...createWaveSpawns(CreatureTypeId.SPIDER_SMALL, 8, 8, 15000, 1500),
    ...createWaveSpawns(CreatureTypeId.SPIDER_LARGE, 5, 6, 30000, 3000),
  ],
  unlockRequirement: 'alien_dens',
};

export const QUEST_GAUNTLET: QuestData = {
  id: 'gauntlet',
  name: 'Gauntlet',
  description: 'Endurance challenge: survive 300 seconds.',
  timeLimitMs: 300000,
  objectives: [{ type: 'survive_time', target: 300, description: 'Survive for 300 seconds' }],
  spawnEntries: [
    // Early waves - zombies
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 4, 10, 0, 5000),
    // Mid waves - mixed
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 4, 10, 60000, 4000),
    ...createWaveSpawns(CreatureTypeId.SPIDER_SMALL, 4, 10, 120000, 4000),
    // Late waves - heavy
    ...createWaveSpawns(CreatureTypeId.ALIEN_TROOPER, 4, 10, 180000, 3500),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_TANK, 2, 10, 200000, 8000),
    // Final waves - intense
    ...createWaveSpawns(CreatureTypeId.ALIEN_ELITE, 3, 10, 240000, 4000),
    ...createCornerSpawns(CreatureTypeId.ZOMBIE_TANK, 2, 270000, 400),
  ],
  unlockRequirement: 'arachnoid_farm',
};
