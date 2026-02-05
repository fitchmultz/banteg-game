/**
 * Tier 3-4 Quests Part 1
 *
 * Mid-late game challenges.
 */

import { CreatureTypeId } from '../../../types';
import type { QuestData } from './types';
import { createWaveSpawns } from './helpers';

export const QUEST_THE_BLIGHTING: QuestData = {
  id: 'the_blighting',
  name: 'The Blighting',
  description: 'Face lizard waves with ghost support. 5 minute endurance test.',
  timeLimitMs: 300000,
  objectives: [{ type: 'kill_count', target: 150, description: 'Kill 150 enemies' }],
  spawnEntries: [
    // Initial lizard spawns from left/right
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 1500, count: 2 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: -100, y: 0, triggerTimeMs: 1500, count: 2 },
    // Ghost corners
    { creatureTypeId: CreatureTypeId.GHOST, x: 350, y: 100, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 100, y: 100, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 100, y: 350, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 350, y: 350, triggerTimeMs: 2000, count: 1 },
    // Wave spawns from edges
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 400, y: 0, triggerTimeMs: 4000, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: -100, y: 0, triggerTimeMs: 5000, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: 400, triggerTimeMs: 6000, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: -100, triggerTimeMs: 7000, count: 12 },
    // Additional lizard spawns at waves 3 and 5
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 19000, count: 4 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: -100, y: 0, triggerTimeMs: 24000, count: 4 },
    // Continue pattern
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 400, y: 0, triggerTimeMs: 19000, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -100, y: 0, triggerTimeMs: 24000, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 0, y: 400, triggerTimeMs: 29000, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: -100, triggerTimeMs: 34000, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 400, y: 0, triggerTimeMs: 39000, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -100, y: 0, triggerTimeMs: 44000, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 0, y: 400, triggerTimeMs: 49000, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: -100, triggerTimeMs: 54000, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 400, y: 0, triggerTimeMs: 59000, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -100, y: 0, triggerTimeMs: 64000, count: 12 },
  ],
  unlockRequirement: 'gauntlet',
};

export const QUEST_THE_KILLING: QuestData = {
  id: 'the_killing',
  name: 'The Killing',
  description: 'Pure combat challenge. Kill 200 enemies in 5 minutes.',
  timeLimitMs: 300000,
  objectives: [{ type: 'kill_count', target: 200, description: 'Kill 200 enemies' }],
  spawnEntries: [
    // Mixed spawns from all directions with random elements
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 2000, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: -100, y: 0, triggerTimeMs: 3000, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: 400, triggerTimeMs: 4000, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 0, y: -100, triggerTimeMs: 5000, count: 12 },
    // Ghost spawns at random positions
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: 200, triggerTimeMs: 6000, count: 3 },
    { creatureTypeId: CreatureTypeId.GHOST, x: -200, y: 200, triggerTimeMs: 7000, count: 3 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: -200, triggerTimeMs: 8000, count: 3 },
    // Continue waves
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 5, 20, 10000, 4000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 4, 20, 12000, 4000),
    ...createWaveSpawns(CreatureTypeId.GHOST, 3, 15, 15000, 5000),
  ],
  unlockRequirement: 'the_blighting',
};

export const QUEST_SURROUNDED_BY_REPTILES: QuestData = {
  id: 'surrounded_by_reptiles',
  name: 'Surrounded by Reptiles',
  description: 'Lizards attack from all sides. Survive 5 minutes.',
  timeLimitMs: 300000,
  objectives: [{ type: 'survive_time', target: 300, description: 'Survive for 300 seconds' }],
  spawnEntries: [
    // Lizards from left and right
    { creatureTypeId: CreatureTypeId.LIZARD, x: 256, y: 300, triggerTimeMs: 1000, count: 1 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 768, y: 300, triggerTimeMs: 1000, count: 1 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 256, y: 350, triggerTimeMs: 1800, count: 1 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 768, y: 350, triggerTimeMs: 1800, count: 1 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 256, y: 400, triggerTimeMs: 2600, count: 1 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 768, y: 400, triggerTimeMs: 2600, count: 1 },
    // Lizards from top and bottom
    { creatureTypeId: CreatureTypeId.LIZARD, x: 300, y: 256, triggerTimeMs: 8000, count: 1 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 300, y: 768, triggerTimeMs: 8000, count: 1 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 350, y: 256, triggerTimeMs: 8800, count: 1 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 350, y: 768, triggerTimeMs: 8800, count: 1 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 256, triggerTimeMs: 9600, count: 1 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 768, triggerTimeMs: 9600, count: 1 },
    // Continue pattern
    ...createWaveSpawns(CreatureTypeId.LIZARD, 2, 30, 12000, 5000),
  ],
  unlockRequirement: 'the_killing',
};

export const QUEST_THE_LIZQUIDATION: QuestData = {
  id: 'the_lizquidation',
  name: 'The Lizquidation',
  description: 'Massive lizard assault from left and right edges. 5 minute challenge.',
  timeLimitMs: 300000,
  objectives: [{ type: 'kill_count', target: 180, description: 'Kill 180 lizards' }],
  spawnEntries: [
    // Lizards from left and right, increasing count
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 1500, count: 6 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: -100, y: 0, triggerTimeMs: 1500, count: 6 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 9500, count: 7 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: -100, y: 0, triggerTimeMs: 9500, count: 7 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 17500, count: 8 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: -100, y: 0, triggerTimeMs: 17500, count: 8 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 25500, count: 9 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: -100, y: 0, triggerTimeMs: 25500, count: 9 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 33500, count: 10 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: -100, y: 0, triggerTimeMs: 33500, count: 10 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 41500, count: 11 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: -100, y: 0, triggerTimeMs: 41500, count: 11 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 49500, count: 12 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: -100, y: 0, triggerTimeMs: 49500, count: 12 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 57500, count: 13 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: -100, y: 0, triggerTimeMs: 57500, count: 13 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 65500, count: 14 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: -100, y: 0, triggerTimeMs: 65500, count: 14 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 73500, count: 15 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: -100, y: 0, triggerTimeMs: 73500, count: 15 },
    // Special spawn at wave 5 - Lizard King
    { creatureTypeId: CreatureTypeId.LIZARD_KING, x: 400, y: 0, triggerTimeMs: 1500, count: 2 },
  ],
  unlockRequirement: 'surrounded_by_reptiles',
};

export const QUEST_SPIDERS_INC: QuestData = {
  id: 'spiders_inc',
  name: 'Spiders Inc.',
  description: 'Spider corporation sends waves from top. 5 minute survival.',
  timeLimitMs: 300000,
  startingWeapon: 11, // Blade Gun
  objectives: [{ type: 'kill_count', target: 150, description: 'Kill 150 spiders' }],
  spawnEntries: [
    // Spider spawns from top
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 500, count: 1 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 100, y: 400, triggerTimeMs: 500, count: 1 },
    // Spider waves from bottom
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: 0, y: -100, triggerTimeMs: 500, count: 4 },
    // Wave spawns from top, increasing
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 17000, count: 3 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 17000, count: 3 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 23000, count: 4 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 23000, count: 4 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 29000, count: 4 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 29000, count: 4 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 35000, count: 5 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 35000, count: 5 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 41000, count: 5 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 41000, count: 5 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 47000, count: 6 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 47000, count: 6 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 53000, count: 6 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 53000, count: 6 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 59000, count: 7 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 59000, count: 7 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 65000, count: 7 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 65000, count: 7 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 71000, count: 8 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 71000, count: 8 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 77000, count: 8 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 77000, count: 8 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 83000, count: 9 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 83000, count: 9 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 89000, count: 9 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 89000, count: 9 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 95000, count: 10 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 95000, count: 10 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 101000, count: 10 },
    {
      creatureTypeId: CreatureTypeId.SPIDER_LARGE,
      x: 0,
      y: -100,
      triggerTimeMs: 101000,
      count: 10,
    },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: 400, triggerTimeMs: 107000, count: 11 },
    {
      creatureTypeId: CreatureTypeId.SPIDER_LARGE,
      x: 0,
      y: -100,
      triggerTimeMs: 107000,
      count: 11,
    },
  ],
  unlockRequirement: 'the_lizquidation',
};

export const QUEST_DEJA_VU: QuestData = {
  id: 'deja_vu',
  name: 'Deja Vu',
  description: 'Spiral pattern zombie spawning with shotgun. 2 minute challenge.',
  timeLimitMs: 120000,
  startingWeapon: 6, // Shotgun
  objectives: [{ type: 'kill_count', target: 72, description: 'Kill 72 zombies' }],
  spawnEntries: [
    // Spiral pattern - 72 zombies in expanding circles
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 100, y: 0, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 85, y: 50, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 50, y: 85, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: 100, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -50, y: 85, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -85, y: 50, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -100, y: 0, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -85, y: -50, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -50, y: -85, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: -100, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 50, y: -85, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 85, y: -50, triggerTimeMs: 2000, count: 1 },
    // Second ring
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 150, y: 0, triggerTimeMs: 4000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 130, y: 75, triggerTimeMs: 4000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 75, y: 130, triggerTimeMs: 4000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: 150, triggerTimeMs: 4000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -75, y: 130, triggerTimeMs: 4000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -130, y: 75, triggerTimeMs: 4000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -150, y: 0, triggerTimeMs: 4000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -130, y: -75, triggerTimeMs: 4000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -75, y: -130, triggerTimeMs: 4000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: -150, triggerTimeMs: 4000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 75, y: -130, triggerTimeMs: 4000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 130, y: -75, triggerTimeMs: 4000, count: 1 },
    // Third ring
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 200, y: 0, triggerTimeMs: 5600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 173, y: 100, triggerTimeMs: 5600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 100, y: 173, triggerTimeMs: 5600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: 200, triggerTimeMs: 5600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -100, y: 173, triggerTimeMs: 5600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -173, y: 100, triggerTimeMs: 5600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -200, y: 0, triggerTimeMs: 5600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -173, y: -100, triggerTimeMs: 5600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -100, y: -173, triggerTimeMs: 5600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: -200, triggerTimeMs: 5600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 100, y: -173, triggerTimeMs: 5600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 173, y: -100, triggerTimeMs: 5600, count: 1 },
    // Fourth ring
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 250, y: 0, triggerTimeMs: 6800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 217, y: 125, triggerTimeMs: 6800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 125, y: 217, triggerTimeMs: 6800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: 250, triggerTimeMs: 6800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -125, y: 217, triggerTimeMs: 6800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -217, y: 125, triggerTimeMs: 6800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -250, y: 0, triggerTimeMs: 6800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -217, y: -125, triggerTimeMs: 6800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -125, y: -217, triggerTimeMs: 6800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: -250, triggerTimeMs: 6800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 125, y: -217, triggerTimeMs: 6800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 217, y: -125, triggerTimeMs: 6800, count: 1 },
    // Fifth ring
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 300, y: 0, triggerTimeMs: 7600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 260, y: 150, triggerTimeMs: 7600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 150, y: 260, triggerTimeMs: 7600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: 300, triggerTimeMs: 7600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -150, y: 260, triggerTimeMs: 7600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -260, y: 150, triggerTimeMs: 7600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -300, y: 0, triggerTimeMs: 7600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -260, y: -150, triggerTimeMs: 7600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -150, y: -260, triggerTimeMs: 7600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: -300, triggerTimeMs: 7600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 150, y: -260, triggerTimeMs: 7600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 260, y: -150, triggerTimeMs: 7600, count: 1 },
    // Sixth ring
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 350, y: 0, triggerTimeMs: 8000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 303, y: 175, triggerTimeMs: 8000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 175, y: 303, triggerTimeMs: 8000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: 350, triggerTimeMs: 8000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -175, y: 303, triggerTimeMs: 8000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -303, y: 175, triggerTimeMs: 8000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -350, y: 0, triggerTimeMs: 8000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -303, y: -175, triggerTimeMs: 8000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -175, y: -303, triggerTimeMs: 8000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: -350, triggerTimeMs: 8000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 175, y: -303, triggerTimeMs: 8000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 303, y: -175, triggerTimeMs: 8000, count: 1 },
  ],
  unlockRequirement: 'spiders_inc',
};
