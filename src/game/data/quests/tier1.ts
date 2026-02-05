/**
 * Tier 1-2 Quests (Early-Mid Game)
 *
 * Early game quests including missing quests from original decompilation
 * and zombie-heavy challenges.
 */

import { CreatureTypeId } from '../../../types';
import type { QuestData } from './types';
import { createWaveSpawns, createCornerSpawns } from './helpers';

// ============================================================================
// Tier 1-2 Missing Quests (Early-Mid Game)
// ============================================================================

export const QUEST_TARGET_PRACTICE: QuestData = {
  id: 'target_practice',
  name: 'Target Practice',
  description: 'Practice your aim. Shoot targets that spawn in a spiral pattern.',
  timeLimitMs: 65000,
  objectives: [{ type: 'kill_count', target: 30, description: 'Shoot 30 targets' }],
  spawnEntries: [
    // Spiral pattern spawning - 30 targets in spiral
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 200, y: 200, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -200, y: 200, triggerTimeMs: 2500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 200, y: -200, triggerTimeMs: 3000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -200, y: -200, triggerTimeMs: 3500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 300, y: 0, triggerTimeMs: 4000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: 300, triggerTimeMs: 4500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -300, y: 0, triggerTimeMs: 5000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: -300, triggerTimeMs: 5500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 250, y: 150, triggerTimeMs: 6000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -250, y: 150, triggerTimeMs: 6500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 250, y: -150, triggerTimeMs: 7000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -250, y: -150, triggerTimeMs: 7500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 150, y: 250, triggerTimeMs: 8000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -150, y: 250, triggerTimeMs: 8500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 150, y: -250, triggerTimeMs: 9000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -150, y: -250, triggerTimeMs: 9500, count: 1 },
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 1, 14, 10000, 2500),
  ],
  unlockRequirement: 'army_of_three',
};

export const QUEST_FRONTLINE_ASSAULT: QuestData = {
  id: 'frontline_assault',
  name: 'Frontline Assault',
  description: 'Hold the line against waves from all directions. 5 minute survival.',
  timeLimitMs: 300000,
  objectives: [{ type: 'survive_time', target: 300, description: 'Survive for 300 seconds' }],
  spawnEntries: [
    // Waves from top (zombies and fast zombies)
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 2, 10, 0, 2500),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 2, 15, 5000, 2000),
    // Side spawns after wave 5
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_TANK, 1, 5, 20000, 15000),
    // Corner spawns for tank zombies at specific times
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 400, triggerTimeMs: 45000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -400, y: 400, triggerTimeMs: 45000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 400, triggerTimeMs: 90000, count: 2 },
    {
      creatureTypeId: CreatureTypeId.ZOMBIE_TANK,
      x: -400,
      y: -400,
      triggerTimeMs: 90000,
      count: 2,
    },
  ],
  unlockRequirement: 'target_practice',
};

export const QUEST_SPIDER_WAVE_SYNDROME: QuestData = {
  id: 'spider_wave_syndrome',
  name: 'Spider Wave Syndrome',
  description: 'Face massive spider waves from the left edge. 4 minute challenge.',
  timeLimitMs: 240000,
  objectives: [{ type: 'kill_count', target: 100, description: 'Kill 100 spiders' }],
  spawnEntries: [
    // Spider waves from left edge every ~5.5 seconds
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 1500, count: 6 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 7000, count: 6 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 12500, count: 7 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 18000, count: 7 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 23500, count: 8 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 29000, count: 8 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 34500, count: 9 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 40000, count: 9 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 45500, count: 10 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 51000, count: 10 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 56500, count: 11 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 62000, count: 11 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 67500, count: 12 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 73000, count: 12 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 78500, count: 13 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 84000, count: 13 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 89500, count: 14 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 95000, count: 14 },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 100500,
      count: 15,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 106000,
      count: 15,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 111500,
      count: 16,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 117000,
      count: 16,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 122500,
      count: 17,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 128000,
      count: 17,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 133500,
      count: 18,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 139000,
      count: 18,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 144500,
      count: 19,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 150000,
      count: 19,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 155500,
      count: 20,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 161000,
      count: 20,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 166500,
      count: 21,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 172000,
      count: 21,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 177500,
      count: 22,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 183000,
      count: 22,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 188500,
      count: 23,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 194000,
      count: 23,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 199500,
      count: 24,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 205000,
      count: 24,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 210500,
      count: 25,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 216000,
      count: 25,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 221500,
      count: 26,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 227000,
      count: 26,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 232500,
      count: 27,
    },
    {
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
      x: -100,
      y: 0,
      triggerTimeMs: 238000,
      count: 27,
    },
  ],
  unlockRequirement: 'frontline_assault',
};

export const QUEST_THE_RANDOM_FACTOR: QuestData = {
  id: 'the_random_factor',
  name: 'The Random Factor',
  description: 'Random enemy spawns from left and right. Adapt to the chaos!',
  timeLimitMs: 300000,
  objectives: [{ type: 'kill_count', target: 120, description: 'Kill 120 enemies' }],
  spawnEntries: [
    // Random spawns from left and right
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 4, 20, 1500, 5000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 6, 20, 1700, 5000),
    // Occasional tank zombies from top
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 30000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 80000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 130000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 180000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 230000, count: 1 },
  ],
  unlockRequirement: 'spider_wave_syndrome',
};

export const QUEST_EVERRED_PASTURES: QuestData = {
  id: 'everred_pastures',
  name: 'Everred Pastures',
  description: 'Face waves of varied enemies from all 4 directions. 5 minute endurance.',
  timeLimitMs: 300000,
  objectives: [{ type: 'kill_count', target: 150, description: 'Kill 150 enemies' }],
  spawnEntries: [
    // Waves from all 4 directions, increasing difficulty
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 1500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: -100, y: 0, triggerTimeMs: 1500, count: 1 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: 0, y: 400, triggerTimeMs: 1500, count: 1 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 1500, count: 1 },
    // Wave 2
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 14500, count: 2 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: -100, y: 0, triggerTimeMs: 14500, count: 2 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: 0, y: 400, triggerTimeMs: 14500, count: 2 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 14500, count: 2 },
    // Wave 3
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 27500, count: 3 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: -100, y: 0, triggerTimeMs: 27500, count: 3 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: 0, y: 400, triggerTimeMs: 27500, count: 3 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 27500, count: 3 },
    // Wave 4 - adds fast zombies from top/bottom
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 40500, count: 4 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: -100, y: 0, triggerTimeMs: 40500, count: 4 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: 0, y: 400, triggerTimeMs: 40500, count: 4 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 40500, count: 4 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 0, y: -100, triggerTimeMs: 40500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 0, y: 400, triggerTimeMs: 40500, count: 8 },
    // Continue pattern...
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 53500, count: 5 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: -100, y: 0, triggerTimeMs: 53500, count: 5 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: 0, y: 400, triggerTimeMs: 53500, count: 5 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 53500, count: 5 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 66500, count: 6 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: -100, y: 0, triggerTimeMs: 66500, count: 6 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: 0, y: 400, triggerTimeMs: 66500, count: 6 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 66500, count: 6 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 79500, count: 7 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: -100, y: 0, triggerTimeMs: 79500, count: 7 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: 0, y: 400, triggerTimeMs: 79500, count: 7 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 79500, count: 7 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 92500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: -100, y: 0, triggerTimeMs: 92500, count: 8 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: 0, y: 400, triggerTimeMs: 92500, count: 8 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 0, y: -100, triggerTimeMs: 92500, count: 8 },
  ],
  unlockRequirement: 'the_random_factor',
};

export const QUEST_SPIDER_SPAWNS: QuestData = {
  id: 'spider_spawns',
  name: 'Spider Spawns',
  description: 'Spiders spawn from 4 corners while waves attack from edges.',
  timeLimitMs: 300000,
  objectives: [{ type: 'kill_count', target: 80, description: 'Kill 80 spiders' }],
  spawnEntries: [
    // 4 corner spawners (spider queens)
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 300, y: 300, triggerTimeMs: 1500, count: 1 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: -300, y: 300, triggerTimeMs: 1500, count: 1 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 300, y: -300, triggerTimeMs: 1500, count: 1 },
    {
      creatureTypeId: CreatureTypeId.SPIDER_LARGE,
      x: -300,
      y: -300,
      triggerTimeMs: 1500,
      count: 1,
    },
    // Side spawns
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: -100, y: 0, triggerTimeMs: 3000, count: 2 },
    { creatureTypeId: CreatureTypeId.SPIDER_SMALL, x: 400, y: 0, triggerTimeMs: 21000, count: 2 },
    // Corner spiders at specific times
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 250, y: 250, triggerTimeMs: 18000, count: 1 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 350, y: 250, triggerTimeMs: 20500, count: 1 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 350, y: 350, triggerTimeMs: 26000, count: 1 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 250, y: 350, triggerTimeMs: 22000, count: 1 },
    { creatureTypeId: CreatureTypeId.SPIDER_LARGE, x: 300, y: 300, triggerTimeMs: 31500, count: 1 },
  ],
  unlockRequirement: 'everred_pastures',
};

export const QUEST_TWO_FRONTS: QuestData = {
  id: 'two_fronts',
  name: 'Two Fronts',
  description: 'Enemies attack from left and right simultaneously. Watch both sides!',
  timeLimitMs: 240000,
  objectives: [{ type: 'kill_count', target: 100, description: 'Kill 100 enemies' }],
  spawnEntries: [
    // Left side spawns (zombies)
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 1000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 3000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 5000, count: 1 },
    // Right side spawns (fast zombies)
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: -100, y: 0, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: -100, y: 0, triggerTimeMs: 4000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: -100, y: 0, triggerTimeMs: 6000, count: 1 },
    // Special spawns at waves 10 and 20
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 200, y: 200, triggerTimeMs: 2500, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: -200, y: -200, triggerTimeMs: 2500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 200, y: 200, triggerTimeMs: 8500, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: -200, y: -200, triggerTimeMs: 8500, count: 1 },
    // Final wave spawns
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -200, y: 200, triggerTimeMs: 62500, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 200, y: -200, triggerTimeMs: 62500, count: 1 },
    // Continue alternating pattern
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 1, 20, 7000, 2000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 1, 20, 8000, 2000),
  ],
  unlockRequirement: 'spider_spawns',
};

export const QUEST_SWEEP_STAKES: QuestData = {
  id: 'sweep_stakes',
  name: 'Sweep Stakes',
  description: 'Quick 35-second challenge with shotgun. Sweep the area clean!',
  timeLimitMs: 35000,
  startingWeapon: 6, // Shotgun
  objectives: [{ type: 'kill_count', target: 25, description: 'Kill 25 enemies' }],
  spawnEntries: [
    // Spiral pattern of targets
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 200, y: 200, triggerTimeMs: 2000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -200, y: 200, triggerTimeMs: 2200, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 200, y: -200, triggerTimeMs: 2400, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -200, y: -200, triggerTimeMs: 2600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 300, y: 0, triggerTimeMs: 2800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: 300, triggerTimeMs: 3000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -300, y: 0, triggerTimeMs: 3200, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: -300, triggerTimeMs: 3400, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 250, y: 150, triggerTimeMs: 3600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -250, y: 150, triggerTimeMs: 3800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 250, y: -150, triggerTimeMs: 4000, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -250, y: -150, triggerTimeMs: 4200, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 150, y: 250, triggerTimeMs: 4400, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -150, y: 250, triggerTimeMs: 4600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 150, y: -250, triggerTimeMs: 4800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -150, y: -250, triggerTimeMs: 5000, count: 1 },
    // More spawns
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 1, 9, 5200, 1500),
  ],
  unlockRequirement: 'two_fronts',
};

export const QUEST_EVIL_ZOMBIES_AT_LARGE: QuestData = {
  id: 'evil_zombies_at_large',
  name: 'Evil Zombies At Large',
  description: 'Powerful zombies spawn from all 4 edges. 3 minute survival.',
  timeLimitMs: 180000,
  objectives: [{ type: 'kill_count', target: 120, description: 'Kill 120 zombies' }],
  spawnEntries: [
    // 4-edge spawning with increasing count
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 1500, count: 4 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 1500, count: 4 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: 400, triggerTimeMs: 1500, count: 4 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 1500, count: 4 },
    // Wave 2
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 7000, count: 5 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 7000, count: 5 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: 400, triggerTimeMs: 7000, count: 5 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 7000, count: 5 },
    // Wave 3
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 12500, count: 6 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 12500, count: 6 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: 400, triggerTimeMs: 12500, count: 6 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 12500, count: 6 },
    // Continue through wave 14
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 18000, count: 7 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 18000, count: 7 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: 400, triggerTimeMs: 18000, count: 7 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 18000, count: 7 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 23500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 23500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: 400, triggerTimeMs: 23500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 23500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 29000, count: 9 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 29000, count: 9 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: 400, triggerTimeMs: 29000, count: 9 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 29000, count: 9 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 34500, count: 10 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 34500, count: 10 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: 400, triggerTimeMs: 34500, count: 10 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 34500, count: 10 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 40000, count: 11 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 40000, count: 11 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: 400, triggerTimeMs: 40000, count: 11 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 40000, count: 11 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 45500, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 45500, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: 400, triggerTimeMs: 45500, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 45500, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 51000, count: 13 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 51000, count: 13 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: 400, triggerTimeMs: 51000, count: 13 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 51000, count: 13 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 56500, count: 14 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 56500, count: 14 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: 400, triggerTimeMs: 56500, count: 14 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 56500, count: 14 },
  ],
  unlockRequirement: 'sweep_stakes',
};

export const QUEST_SURVIVAL_OF_THE_FASTEST: QuestData = {
  id: 'survival_of_the_fastest',
  name: 'Survival of the Fastest',
  description: 'Survive 2 minutes with SMG against fast-moving enemies.',
  timeLimitMs: 120000,
  startingWeapon: 5, // SMG
  objectives: [{ type: 'survive_time', target: 120, description: 'Survive for 120 seconds' }],
  spawnEntries: [
    // Fast spawns from all directions
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 256, y: 128, triggerTimeMs: 500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 300, y: 128, triggerTimeMs: 1400, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 344, y: 128, triggerTimeMs: 2300, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 388, y: 128, triggerTimeMs: 3200, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 432, y: 128, triggerTimeMs: 4100, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 476, y: 128, triggerTimeMs: 5000, count: 1 },
    // Right side
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 700, y: 256, triggerTimeMs: 5900, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 700, y: 300, triggerTimeMs: 6800, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 700, y: 344, triggerTimeMs: 7700, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 700, y: 388, triggerTimeMs: 8600, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 700, y: 432, triggerTimeMs: 9500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 700, y: 476, triggerTimeMs: 10400, count: 1 },
    // Continue with wave patterns
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 2, 20, 11000, 3000),
    ...createWaveSpawns(CreatureTypeId.SPIDER_SMALL, 2, 15, 15000, 4000),
    // Corner spawns at specific times
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 128, y: 128, triggerTimeMs: 22300, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 896, y: 128, triggerTimeMs: 22300, count: 1 },
    { creatureTypeId: CreatureTypeId.GHOST, x: 128, y: 896, triggerTimeMs: 24300, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 896, y: 896, triggerTimeMs: 24300, count: 1 },
  ],
  unlockRequirement: 'evil_zombies_at_large',
};

// ============================================================================
// Zombie Heavy (Tier 1-2)
// ============================================================================

export const QUEST_KNEE_DEEP_IN_THE_DEAD: QuestData = {
  id: 'knee_deep_in_the_dead',
  name: 'Knee Deep in the Dead',
  description: 'Kill 100 zombies in relentless waves.',
  timeLimitMs: 480000,
  objectives: [{ type: 'kill_count', target: 100, description: 'Kill 100 zombies' }],
  spawnEntries: [
    // Intense zombie waves
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 8, 8, 0, 2000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 4, 6, 8000, 3000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_TANK, 1, 5, 15000, 8000),
  ],
  unlockRequirement: 'survival_of_the_fastest',
};

export const QUEST_THE_GANG_WARS: QuestData = {
  id: 'the_gang_wars',
  name: 'The Gang Wars',
  description: 'Kill 75 mixed enemies in gang warfare.',
  timeLimitMs: 480000,
  objectives: [{ type: 'kill_count', target: 75, description: 'Kill 75 enemies' }],
  spawnEntries: [
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 3, 10, 0, 2500),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 3, 8, 5000, 3000),
    ...createWaveSpawns(CreatureTypeId.SPIDER_SMALL, 2, 6, 12000, 4000),
  ],
  unlockRequirement: 'knee_deep_in_the_dead',
};

export const QUEST_THE_FORTRESS: QuestData = {
  id: 'the_fortress',
  name: 'The Fortress',
  description: 'Survive 90 seconds in defensive positioning.',
  timeLimitMs: 480000,
  objectives: [{ type: 'survive_time', target: 90, description: 'Survive for 90 seconds' }],
  spawnEntries: [
    // Corner spawns for defensive feel
    ...createCornerSpawns(CreatureTypeId.ZOMBIE, 3, 0, 250),
    ...createCornerSpawns(CreatureTypeId.ZOMBIE, 4, 10000, 300),
    ...createCornerSpawns(CreatureTypeId.ZOMBIE_FAST, 3, 20000, 350),
    ...createCornerSpawns(CreatureTypeId.ZOMBIE_TANK, 2, 40000, 400),
    ...createCornerSpawns(CreatureTypeId.ZOMBIE, 5, 60000, 300),
  ],
  unlockRequirement: 'the_gang_wars',
};

export const QUEST_CROSS_FIRE: QuestData = {
  id: 'cross_fire',
  name: 'Cross Fire',
  description: 'Kill 50 enemies attacking from 4 corners simultaneously.',
  timeLimitMs: 480000,
  objectives: [{ type: 'kill_count', target: 50, description: 'Kill 50 enemies' }],
  spawnEntries: [
    ...createCornerSpawns(CreatureTypeId.ZOMBIE, 2, 0, 200),
    ...createCornerSpawns(CreatureTypeId.ZOMBIE_FAST, 2, 5000, 250),
    ...createCornerSpawns(CreatureTypeId.ZOMBIE, 3, 10000, 200),
    ...createCornerSpawns(CreatureTypeId.ZOMBIE_FAST, 3, 15000, 250),
    ...createCornerSpawns(CreatureTypeId.ZOMBIE_TANK, 1, 20000, 300),
  ],
  unlockRequirement: 'the_fortress',
};
