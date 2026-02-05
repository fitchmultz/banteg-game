/**
 * Tier 5 Bonus Quests (Ultimate Challenges)
 *
 * Ultimate challenge quests that unlock after completing the main quest line.
 */

import { CreatureTypeId } from '../../../types';
import type { QuestData } from './types';
import { createWaveSpawns, createCircleSpawns } from './helpers';

export const QUEST_THE_ANNIHILATION: QuestData = {
  id: 'the_annihilation',
  name: 'The Annihilation',
  description: 'Ultimate lizard and ghost challenge. 5 minute survival. (Bonus)',
  isBonus: true,
  timeLimitMs: 300000,
  objectives: [{ type: 'kill_count', target: 100, description: 'Kill 100 lizards and ghosts' }],
  spawnEntries: [
    // Initial lizard king spawn
    { creatureTypeId: CreatureTypeId.LIZARD_KING, x: 200, y: 0, triggerTimeMs: 500, count: 2 },
    // Ghost waves from left and right
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 350, triggerTimeMs: 500, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 375, triggerTimeMs: 1000, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 400, triggerTimeMs: 1500, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 425, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 450, triggerTimeMs: 2500, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 475, triggerTimeMs: 3000, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 500, triggerTimeMs: 3500, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 525, triggerTimeMs: 4000, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 550, triggerTimeMs: 4500, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 575, triggerTimeMs: 5000, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 600, triggerTimeMs: 5500, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 625, triggerTimeMs: 6000, count: 1 },
    // Second wave at 45 seconds
    { creatureTypeId: CreatureTypeId.LIZARD_KING, x: 200, y: 350, triggerTimeMs: 45000, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 375, triggerTimeMs: 45300, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 400, triggerTimeMs: 45600, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 425, triggerTimeMs: 45900, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 450, triggerTimeMs: 46200, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 475, triggerTimeMs: 46500, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 500, triggerTimeMs: 46800, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 525, triggerTimeMs: 47100, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 550, triggerTimeMs: 47400, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 575, triggerTimeMs: 47700, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 600, triggerTimeMs: 48000, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 625, triggerTimeMs: 48300, count: 1 },
    // Continue pattern
    { creatureTypeId: CreatureTypeId.LIZARD_KING, x: 200, y: 350, triggerTimeMs: 90000, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 375, triggerTimeMs: 90300, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 400, triggerTimeMs: 90600, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 425, triggerTimeMs: 90900, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 450, triggerTimeMs: 91200, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 475, triggerTimeMs: 91500, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 500, triggerTimeMs: 91800, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 525, triggerTimeMs: 92100, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 550, triggerTimeMs: 92400, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 575, triggerTimeMs: 92700, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 600, triggerTimeMs: 93000, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 625, triggerTimeMs: 93300, count: 1 },
  ],
  unlockRequirement: 'the_unblitzkrieg',
};

export const QUEST_THE_END_OF_ALL: QuestData = {
  id: 'the_end_of_all',
  name: 'The End of All',
  description: 'The final challenge. All enemy types in massive waves. 8 minute epic. (Bonus)',
  isBonus: true,
  timeLimitMs: 480000,
  objectives: [{ type: 'kill_count', target: 300, description: 'Kill 300 enemies' }],
  spawnEntries: [
    // Corner spawns - 4 lizard kings
    { creatureTypeId: CreatureTypeId.LIZARD_KING, x: 200, y: 200, triggerTimeMs: 3000, count: 1 },
    { creatureTypeId: CreatureTypeId.LIZARD_KING, x: -200, y: 200, triggerTimeMs: 6000, count: 1 },
    { creatureTypeId: CreatureTypeId.LIZARD_KING, x: 200, y: -200, triggerTimeMs: 9000, count: 1 },
    {
      creatureTypeId: CreatureTypeId.LIZARD_KING,
      x: -200,
      y: -200,
      triggerTimeMs: 12000,
      count: 1,
    },
    // Circle of ghosts at 13 seconds
    ...createCircleSpawns(CreatureTypeId.GHOST, { x: 0, y: 0 }, 100, 6, 13000),
    // Mixed waves
    { creatureTypeId: CreatureTypeId.LIZARD_KING, x: 0, y: 0, triggerTimeMs: 18000, count: 1 },
    // Second circle of ghosts at 43 seconds
    ...createCircleSpawns(CreatureTypeId.GHOST, { x: 0, y: 0 }, 180, 6, 43000),
    // Third circle at 48 seconds (offset)
    ...createCircleSpawns(CreatureTypeId.GHOST, { x: 0, y: 0 }, 100, 6, 48000),
    // Massive mixed spawns
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 60000, count: 5 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 60000, count: 5 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: 400, triggerTimeMs: 60000, count: 5 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 60000, count: 5 },
    { creatureTypeId: CreatureTypeId.LIZARD_KING, x: 200, y: 200, triggerTimeMs: 70000, count: 2 },
    { creatureTypeId: CreatureTypeId.LIZARD_KING, x: -200, y: 200, triggerTimeMs: 70000, count: 2 },
    // Final waves
    ...createWaveSpawns(CreatureTypeId.GHOST, 5, 20, 120000, 10000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_TANK, 3, 20, 150000, 10000),
    ...createWaveSpawns(CreatureTypeId.LIZARD_KING, 2, 10, 200000, 15000),
  ],
  unlockRequirement: 'the_annihilation',
};

export const QUEST_THE_SPANKING_OF_THE_DEAD: QuestData = {
  id: 'the_spanking_of_the_dead',
  name: 'The Spanking of the Dead',
  description: 'Elite zombie challenge with spiral spawning. 8 minute survival. (Bonus)',
  isBonus: true,
  timeLimitMs: 480000,
  objectives: [{ type: 'kill_count', target: 150, description: 'Kill 150 elite zombies' }],
  spawnEntries: [
    // Initial tank zombie spawns
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 200, y: 0, triggerTimeMs: 500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -200, y: 0, triggerTimeMs: 500, count: 1 },
    // Spiral spawning pattern
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 100, y: 0, triggerTimeMs: 5000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 95, y: 31, triggerTimeMs: 5300, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 81, y: 59, triggerTimeMs: 5600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 59, y: 81, triggerTimeMs: 5900, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 31, y: 95, triggerTimeMs: 6200, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: 100, triggerTimeMs: 6500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -31, y: 95, triggerTimeMs: 6800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -59, y: 81, triggerTimeMs: 7100, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -81, y: 59, triggerTimeMs: 7400, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -95, y: 31, triggerTimeMs: 7700, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 8000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -95, y: -31, triggerTimeMs: 8300, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -81, y: -59, triggerTimeMs: 8600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -59, y: -81, triggerTimeMs: 8900, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -31, y: -95, triggerTimeMs: 9200, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 9500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 31, y: -95, triggerTimeMs: 9800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 59, y: -81, triggerTimeMs: 10100, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 81, y: -59, triggerTimeMs: 10400, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 95, y: -31, triggerTimeMs: 10700, count: 1 },
    // Continue spiral with decreasing radius
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 90, y: 0, triggerTimeMs: 11000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 86, y: 28, triggerTimeMs: 11300, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 73, y: 53, triggerTimeMs: 11600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 53, y: 73, triggerTimeMs: 11900, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 28, y: 86, triggerTimeMs: 12200, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: 90, triggerTimeMs: 12500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -28, y: 86, triggerTimeMs: 12800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -53, y: 73, triggerTimeMs: 13100, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -73, y: 53, triggerTimeMs: 13400, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -86, y: 28, triggerTimeMs: 13700, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -90, y: 0, triggerTimeMs: 14000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -86, y: -28, triggerTimeMs: 14300, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -73, y: -53, triggerTimeMs: 14600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -53, y: -73, triggerTimeMs: 14900, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -28, y: -86, triggerTimeMs: 15200, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -90, triggerTimeMs: 15500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 28, y: -86, triggerTimeMs: 15800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 53, y: -73, triggerTimeMs: 16100, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 73, y: -53, triggerTimeMs: 16400, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 86, y: -28, triggerTimeMs: 16700, count: 1 },
    // Final massive spawns
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 40000, count: 16 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 50000, count: 16 },
  ],
  unlockRequirement: 'the_end_of_all',
};

export const QUEST_SPIDEROIDS: QuestData = {
  id: 'spideroids',
  name: 'Spideroids',
  description: 'Spider-asteroid hybrid challenge. 6 minute survival. (Bonus)',
  isBonus: true,
  timeLimitMs: 360000,
  objectives: [{ type: 'survive_time', target: 360, description: 'Survive for 360 seconds' }],
  spawnEntries: [
    // Spider spawns from right edge
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 400, y: 0, triggerTimeMs: 1000, count: 1 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: -100, y: 0, triggerTimeMs: 3000, count: 1 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 400, y: 100, triggerTimeMs: 6000, count: 1 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: -100, y: 100, triggerTimeMs: 9000, count: 1 },
    // Additional spawns in hardcore
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 400, y: 200, triggerTimeMs: 9000, count: 1 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 9000, count: 1 },
    // Continue pattern
    ...createWaveSpawns(CreatureTypeId.SPIDER_SMALL, 3, 30, 12000, 8000),
    ...createWaveSpawns(CreatureTypeId.SPIDER_LARGE, 2, 20, 15000, 10000),
  ],
  unlockRequirement: 'the_spanking_of_the_dead',
};

export const QUEST_SYNTAX_TERROR: QuestData = {
  id: 'syntax_terror',
  name: 'Syntax Terror',
  description: 'Mixed enemy types in chaotic waves. (Bonus)',
  timeLimitMs: 300000,
  isBonus: true,
  objectives: [{ type: 'kill_count', target: 150, description: 'Kill 150 enemies' }],
  spawnEntries: [
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 3, 10, 0, 3000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 2, 10, 2000, 3000),
    ...createWaveSpawns(CreatureTypeId.SPIDER_SMALL, 2, 10, 4000, 3000),
    ...createWaveSpawns(CreatureTypeId.ALIEN_TROOPER, 2, 10, 6000, 3000),
    ...createWaveSpawns(CreatureTypeId.GHOST, 2, 10, 8000, 3000),
  ],
  unlockRequirement: 'spideroids',
};
