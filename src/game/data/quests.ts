/**
 * Quest Data Definitions
 *
 * Based on decompiled quest_build_* functions from crimsonland.exe.
 * Defines all 20 quests with objectives and time-based spawn patterns.
 */

import { CreatureTypeId, type QuestId } from '../../types';

export interface QuestSpawnEntry {
  /** Creature type to spawn */
  creatureTypeId: CreatureTypeId;
  /** Spawn X position (0 = random) */
  x: number;
  /** Spawn Y position (0 = random) */
  y: number;
  /** Movement direction (radians, optional) */
  heading?: number;
  /** Time in ms when this spawn triggers */
  triggerTimeMs: number;
  /** Number of creatures to spawn */
  count: number;
}

export type QuestObjectiveType = 'kill_count' | 'survive_time' | 'reach_location' | 'kill_bosses';

export interface QuestObjective {
  type: QuestObjectiveType;
  target: number;
  description: string;
  /** Optional: specific creature type to kill */
  creatureTypeId?: CreatureTypeId;
  /** Optional: target X coordinate for reach_location objectives */
  x?: number;
  /** Optional: target Y coordinate for reach_location objectives */
  y?: number;
}

export interface QuestData {
  id: QuestId;
  name: string;
  description: string;
  /** Optional time limit in milliseconds */
  timeLimitMs?: number;
  /** Objectives to complete the quest */
  objectives: QuestObjective[];
  /** Time-based spawn entries */
  spawnEntries: QuestSpawnEntry[];
  /** Quest that must be completed to unlock this one */
  unlockRequirement?: QuestId;
  /** Is this a bonus quest */
  isBonus?: boolean;
  /** Starting weapon for this quest (optional) */
  startingWeapon?: number;
}

// ============================================================================
// Helper Functions for Spawn Generation
// ============================================================================

function createWaveSpawns(
  creatureType: CreatureTypeId,
  countPerWave: number,
  waves: number,
  startTimeMs: number,
  intervalMs: number
): QuestSpawnEntry[] {
  const entries: QuestSpawnEntry[] = [];
  for (let wave = 0; wave < waves; wave++) {
    entries.push({
      creatureTypeId: creatureType,
      x: 0, // Random position
      y: 0,
      triggerTimeMs: startTimeMs + wave * intervalMs,
      count: countPerWave,
    });
  }
  return entries;
}

function createCornerSpawns(
  creatureType: CreatureTypeId,
  count: number,
  timeMs: number,
  distance: number
): QuestSpawnEntry[] {
  return [
    { creatureTypeId: creatureType, x: distance, y: distance, triggerTimeMs: timeMs, count },
    { creatureTypeId: creatureType, x: -distance, y: distance, triggerTimeMs: timeMs, count },
    { creatureTypeId: creatureType, x: distance, y: -distance, triggerTimeMs: timeMs, count },
    { creatureTypeId: creatureType, x: -distance, y: -distance, triggerTimeMs: timeMs, count },
  ];
}

function createRepeatingSingleSpawns(
  creatureType: CreatureTypeId,
  positions: Array<{ x: number; y: number }>,
  repeats: number,
  startTimeMs: number,
  intervalMs: number
): QuestSpawnEntry[] {
  const entries: QuestSpawnEntry[] = [];
  for (let i = 0; i < repeats; i++) {
    for (const pos of positions) {
      entries.push({
        creatureTypeId: creatureType,
        x: pos.x,
        y: pos.y,
        triggerTimeMs: startTimeMs + i * intervalMs,
        count: 1,
      });
    }
  }
  return entries;
}

function createCircleSpawns(
  creatureType: CreatureTypeId,
  center: { x: number; y: number },
  radius: number,
  count: number,
  timeMs: number
): QuestSpawnEntry[] {
  const entries: QuestSpawnEntry[] = [];
  for (let i = 0; i < count; i++) {
    const angle = (i / count) * Math.PI * 2;
    entries.push({
      creatureTypeId: creatureType,
      x: center.x + Math.cos(angle) * radius,
      y: center.y + Math.sin(angle) * radius,
      triggerTimeMs: timeMs,
      count: 1,
    });
  }
  return entries;
}

// ============================================================================
// Quest 1-4: Tutorial / Early Game (Already partially implemented)
// ============================================================================

const QUEST_NAGOLIPOLI: QuestData = {
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

const QUEST_MONSTER_BLUES: QuestData = {
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

const QUEST_THE_GATHERING: QuestData = {
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

const QUEST_ARMY_OF_THREE: QuestData = {
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

// ============================================================================
// Quest 5-8: Zombie Heavy
// ============================================================================

const QUEST_KNEE_DEEP_IN_THE_DEAD: QuestData = {
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

const QUEST_THE_GANG_WARS: QuestData = {
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

const QUEST_THE_FORTRESS: QuestData = {
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

const QUEST_CROSS_FIRE: QuestData = {
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

// ============================================================================
// Quest 9-12: Fast and Furious
// ============================================================================

const QUEST_THE_BEATING: QuestData = {
  id: 'the_beating',
  name: 'The Beating',
  description: 'Survive 60 seconds against fast zombies. Keep moving!',
  timeLimitMs: 480000,
  objectives: [{ type: 'survive_time', target: 60, description: 'Survive for 60 seconds' }],
  spawnEntries: [
    // Mostly fast zombies
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 5, 8, 0, 3000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 3, 6, 5000, 2000),
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: 0, triggerTimeMs: 30000, count: 2 },
  ],
  unlockRequirement: 'cross_fire',
};

const QUEST_HIDDEN_EVIL: QuestData = {
  id: 'hidden_evil',
  name: 'Hidden Evil',
  description: 'Kill 30 ghosts that appear in waves. Watch your back!',
  timeLimitMs: 300000,
  objectives: [
    {
      type: 'kill_count',
      target: 30,
      description: 'Kill 30 ghosts',
      creatureTypeId: CreatureTypeId.GHOST,
    },
  ],
  spawnEntries: [
    ...createWaveSpawns(CreatureTypeId.GHOST, 3, 10, 0, 4000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 2, 8, 5000, 5000),
    ...createWaveSpawns(CreatureTypeId.GHOST, 5, 4, 20000, 3000),
  ],
  unlockRequirement: 'the_beating',
};

const QUEST_LAND_HOSTILE: QuestData = {
  id: 'land_hostile',
  name: 'Land Hostile',
  description: 'Kill 60 aliens within the 120 second time limit.',
  timeLimitMs: 120000,
  objectives: [{ type: 'kill_count', target: 60, description: 'Kill 60 aliens' }],
  spawnEntries: [
    ...createWaveSpawns(CreatureTypeId.ALIEN_TROOPER, 4, 10, 0, 3000),
    ...createWaveSpawns(CreatureTypeId.ALIEN_ELITE, 2, 5, 15000, 8000),
  ],
  unlockRequirement: 'hidden_evil',
};

const QUEST_MINOR_ALIEN_BREACH: QuestData = {
  id: 'minor_alien_breach',
  name: 'Minor Alien Breach',
  description: 'Kill 40 alien troopers before they overwhelm you.',
  timeLimitMs: 120000,
  objectives: [
    {
      type: 'kill_count',
      target: 40,
      description: 'Kill 40 alien troopers',
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
    },
  ],
  spawnEntries: [
    ...createWaveSpawns(CreatureTypeId.ALIEN_TROOPER, 3, 8, 0, 3000),
    ...createWaveSpawns(CreatureTypeId.ALIEN_TROOPER, 5, 6, 10000, 2500),
    ...createWaveSpawns(CreatureTypeId.ALIEN_ELITE, 2, 4, 20000, 6000),
  ],
  unlockRequirement: 'land_hostile',
};

// ============================================================================
// Quest 13-16: Mixed Enemies
// ============================================================================

const QUEST_ALIEN_SQUADS: QuestData = {
  id: 'alien_squads',
  name: 'Alien Squads',
  description: 'Kill 80 mixed aliens in coordinated squads.',
  timeLimitMs: 180000,
  objectives: [{ type: 'kill_count', target: 80, description: 'Kill 80 mixed aliens' }],
  spawnEntries: [
    ...createWaveSpawns(CreatureTypeId.ALIEN_TROOPER, 4, 10, 0, 2500),
    ...createWaveSpawns(CreatureTypeId.ALIEN_ELITE, 2, 8, 5000, 4000),
    ...createWaveSpawns(CreatureTypeId.ALIEN_TROOPER, 3, 8, 15000, 2000),
  ],
  unlockRequirement: 'minor_alien_breach',
};

const QUEST_ZOMBIE_MASTERS: QuestData = {
  id: 'zombie_masters',
  name: 'Zombie Masters',
  description: 'Kill 3 elite zombie masters (boss fight).',
  timeLimitMs: 300000,
  objectives: [{ type: 'kill_count', target: 3, description: 'Kill 3 tank zombies' }],
  spawnEntries: [
    // Boss-style encounter with minions
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 0, count: 1 },
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 3, 5, 0, 4000),
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -400, y: 0, triggerTimeMs: 20000, count: 1 },
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 4, 5, 20000, 3000),
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: 400, triggerTimeMs: 40000, count: 1 },
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 5, 4, 40000, 2500),
  ],
  unlockRequirement: 'alien_squads',
};

const QUEST_8_LEGGED_TERROR: QuestData = {
  id: '8_legged_terror',
  name: '8-Legged Terror',
  description: 'Kill 50 spiders before they swarm you.',
  timeLimitMs: 240000,
  objectives: [
    {
      type: 'kill_count',
      target: 50,
      description: 'Kill 50 spiders',
      creatureTypeId: CreatureTypeId.SPIDER_SMALL,
    },
  ],
  spawnEntries: [
    ...createWaveSpawns(CreatureTypeId.SPIDER_SMALL, 4, 8, 0, 2500),
    ...createWaveSpawns(CreatureTypeId.SPIDER_LARGE, 2, 6, 8000, 5000),
    ...createWaveSpawns(CreatureTypeId.SPIDER_SMALL, 6, 5, 15000, 2000),
  ],
  unlockRequirement: 'zombie_masters',
};

const QUEST_GHOST_PATROLS: QuestData = {
  id: 'ghost_patrols',
  name: 'Ghost Patrols',
  description: 'Survive 120 seconds with constant ghost spawns.',
  timeLimitMs: 180000,
  objectives: [{ type: 'survive_time', target: 120, description: 'Survive for 120 seconds' }],
  spawnEntries: [
    ...createWaveSpawns(CreatureTypeId.GHOST, 3, 15, 0, 4000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 2, 10, 10000, 5000),
    ...createWaveSpawns(CreatureTypeId.GHOST, 5, 10, 30000, 3000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 3, 8, 60000, 4000),
  ],
  unlockRequirement: '8_legged_terror',
};

// ============================================================================
// Quest 17-20: Advanced Challenges
// ============================================================================

const QUEST_NESTING_GROUNDS: QuestData = {
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

const QUEST_ALIEN_DENS: QuestData = {
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

const QUEST_ARACHNOID_FARM: QuestData = {
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

const QUEST_GAUNTLET: QuestData = {
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

// ============================================================================
// Lizard Quests (Tier 2-4, unlock after Gauntlet)
// ============================================================================

const QUEST_LAND_OF_LIZARDS: QuestData = {
  id: 'land_of_lizards',
  name: 'Land of Lizards',
  description: 'Face 256 lizards spawning from 4 corner spawners. 180 second time limit.',
  timeLimitMs: 180000,
  objectives: [{ type: 'kill_count', target: 256, description: 'Kill 256 lizards' }],
  spawnEntries: [
    // 4 corner spawners, each spawning 64 lizards over time
    ...createRepeatingSingleSpawns(
      CreatureTypeId.LIZARD,
      [
        { x: 400, y: 400 },
        { x: -400, y: 400 },
        { x: 400, y: -400 },
        { x: -400, y: -400 },
      ],
      64,
      0,
      2500
    ),
  ],
  unlockRequirement: 'the_unblitzkrieg',
};

const QUEST_LIZARD_KINGS: QuestData = {
  id: 'lizard_kings',
  name: 'Lizard Kings',
  description: 'Defeat 3 Lizard King bosses, each spawning 8 minions in a circle pattern.',
  timeLimitMs: 180000,
  objectives: [{ type: 'kill_count', target: 3, description: 'Kill 3 Lizard Kings' }],
  spawnEntries: [
    // Lizard King 1 at t=1500ms with minions in circle pattern
    { creatureTypeId: CreatureTypeId.LIZARD_KING, x: 300, y: 0, triggerTimeMs: 1500, count: 1 },
    ...createCircleSpawns(CreatureTypeId.LIZARD_MINION, { x: 300, y: 0 }, 100, 8, 1500),
    // Lizard King 2 at t=60000ms
    { creatureTypeId: CreatureTypeId.LIZARD_KING, x: -300, y: 0, triggerTimeMs: 60000, count: 1 },
    ...createCircleSpawns(CreatureTypeId.LIZARD_MINION, { x: -300, y: 0 }, 100, 8, 60000),
    // Lizard King 3 at t=120000ms
    { creatureTypeId: CreatureTypeId.LIZARD_KING, x: 0, y: 300, triggerTimeMs: 120000, count: 1 },
    ...createCircleSpawns(CreatureTypeId.LIZARD_MINION, { x: 0, y: 300 }, 100, 8, 120000),
  ],
  unlockRequirement: 'land_of_lizards',
};

const QUEST_LIZARD_RAZE: QuestData = {
  id: 'lizard_raze',
  name: 'Lizard Raze',
  description: 'Survive 300 seconds against lizard waves from edges plus zombie spawners.',
  timeLimitMs: 300000,
  objectives: [{ type: 'survive_time', target: 300, description: 'Survive for 300 seconds' }],
  spawnEntries: [
    // Lizard waves from edges (template 0x2e/46)
    ...createWaveSpawns(CreatureTypeId.LIZARD, 4, 15, 0, 5000),
    ...createWaveSpawns(CreatureTypeId.LIZARD, 6, 10, 60000, 4000),
    ...createWaveSpawns(CreatureTypeId.LIZARD, 8, 10, 120000, 3500),
    // 3 zombie spawners at t=10000ms
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 350, y: 350, triggerTimeMs: 10000, count: 5 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: -350, y: 350, triggerTimeMs: 10000, count: 5 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 0, y: -350, triggerTimeMs: 10000, count: 5 },
    // Additional zombie waves
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 3, 10, 30000, 6000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_TANK, 2, 5, 60000, 15000),
  ],
  unlockRequirement: 'lizard_kings',
};

const QUEST_LIZARD_ZOMBIE_PACT: QuestData = {
  id: 'lizard_zombie_pact',
  name: 'Lizard Zombie Pact',
  description: 'Face the unholy alliance. Lizard waves with zombie spawns every 5 waves.',
  timeLimitMs: 300000,
  objectives: [{ type: 'kill_count', target: 200, description: 'Kill 200 enemies' }],
  spawnEntries: [
    // Lizard waves from edges (template 0x41/65)
    ...createWaveSpawns(CreatureTypeId.LIZARD, 3, 20, 0, 4000),
    ...createWaveSpawns(CreatureTypeId.LIZARD, 5, 15, 60000, 3500),
    // Zombie spawns every 5 waves (approx every 20000ms)
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 4, 4, 20000, 20000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 3, 4, 25000, 20000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_TANK, 1, 4, 30000, 20000),
    // Mixed spawns later
    ...createWaveSpawns(CreatureTypeId.LIZARD, 4, 10, 120000, 3000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 5, 5, 120000, 6000),
  ],
  unlockRequirement: 'lizard_raze',
};

// ============================================================================
// Tier 1-2 Missing Quests (Early-Mid Game)
// ============================================================================

const QUEST_TARGET_PRACTICE: QuestData = {
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
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 1, 22, 6000, 2500),
  ],
  unlockRequirement: 'army_of_three',
};

const QUEST_FRONTLINE_ASSAULT: QuestData = {
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

const QUEST_SPIDER_WAVE_SYNDROME: QuestData = {
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

const QUEST_THE_RANDOM_FACTOR: QuestData = {
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

const QUEST_EVERRED_PASTURES: QuestData = {
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

const QUEST_SPIDER_SPAWNS: QuestData = {
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

const QUEST_TWO_FRONTS: QuestData = {
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

const QUEST_SWEEP_STAKES: QuestData = {
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

const QUEST_EVIL_ZOMBIES_AT_LARGE: QuestData = {
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

const QUEST_SURVIVAL_OF_THE_FASTEST: QuestData = {
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
// Tier 3-4 Missing Quests (Mid-Late Game)
// ============================================================================

const QUEST_THE_BLIGHTING: QuestData = {
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

const QUEST_THE_KILLING: QuestData = {
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

const QUEST_SURROUNDED_BY_REPTILES: QuestData = {
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

const QUEST_THE_LIZQUIDATION: QuestData = {
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

const QUEST_SPIDERS_INC: QuestData = {
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

const QUEST_DEJA_VU: QuestData = {
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

const QUEST_MAJOR_ALIEN_BREACH: QuestData = {
  id: 'major_alien_breach',
  name: 'Major Alien Breach',
  description: 'Major alien invasion from corners. 5 minute defense.',
  timeLimitMs: 300000,
  startingWeapon: 18, // Ion Cannon
  objectives: [{ type: 'kill_count', target: 120, description: 'Kill 120 aliens' }],
  spawnEntries: [
    // Aliens from top-right and top-left corners, decreasing interval
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 4000,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 4000,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 6000,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 6000,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 7970,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 7970,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 9910,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 9910,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 11820,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 11820,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 13700,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 13700,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 15550,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 15550,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 17380,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 17380,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 19180,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 19180,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 20950,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 20950,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 22700,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 22700,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 24420,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 24420,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 26120,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 26120,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 27790,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 27790,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 29440,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 29440,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 31060,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 31060,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 32650,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 32650,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 34220,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 34220,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 35760,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 35760,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 37280,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 37280,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: 350,
      y: -100,
      triggerTimeMs: 38770,
      count: 2,
    },
    {
      creatureTypeId: CreatureTypeId.ALIEN_TROOPER,
      x: -100,
      y: -100,
      triggerTimeMs: 38770,
      count: 2,
    },
  ],
  unlockRequirement: 'deja_vu',
};

const QUEST_ZOMBIE_TIME: QuestData = {
  id: 'zombie_time',
  name: 'Zombie Time',
  description: 'Non-stop zombie waves from left and right. 5 minute survival.',
  timeLimitMs: 300000,
  objectives: [{ type: 'kill_count', target: 160, description: 'Kill 160 zombies' }],
  spawnEntries: [
    // Tank zombies from left and right every 8 seconds
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 1500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 1500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 9500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 9500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 17500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 17500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 25500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 25500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 33500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 33500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 41500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 41500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 49500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 49500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 57500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 57500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 65500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 65500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 73500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 73500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 81500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 81500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 89500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 89500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 97500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 97500, count: 8 },
  ],
  unlockRequirement: 'major_alien_breach',
};

const QUEST_THE_COLLABORATION: QuestData = {
  id: 'the_collaboration',
  name: 'The Collaboration',
  description: 'All enemy types collaborate against you. 6 minute epic battle.',
  timeLimitMs: 360000,
  objectives: [{ type: 'kill_count', target: 250, description: 'Kill 250 enemies' }],
  spawnEntries: [
    // Mixed spawns from all 4 directions
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 1500, count: 3 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 400, y: 400, triggerTimeMs: 1500, count: 3 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 1500, count: 3 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 1500, count: 3 },
    // Wave 2
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 12500, count: 4 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 400, y: 400, triggerTimeMs: 12500, count: 4 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 12500, count: 4 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 12500, count: 4 },
    // Continue pattern through 30 waves
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 23500, count: 5 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 400, y: 400, triggerTimeMs: 23500, count: 5 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 23500, count: 5 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 23500, count: 5 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 34500, count: 6 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 400, y: 400, triggerTimeMs: 34500, count: 6 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 34500, count: 6 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 34500, count: 6 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 45500, count: 7 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 400, y: 400, triggerTimeMs: 45500, count: 7 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 45500, count: 7 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 45500, count: 7 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 56500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 400, y: 400, triggerTimeMs: 56500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 56500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 56500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 67500, count: 9 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 400, y: 400, triggerTimeMs: 67500, count: 9 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 67500, count: 9 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 67500, count: 9 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 78500, count: 10 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 400, y: 400, triggerTimeMs: 78500, count: 10 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 78500, count: 10 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 78500, count: 10 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 89500, count: 11 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_FAST, x: 400, y: 400, triggerTimeMs: 89500, count: 11 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 89500, count: 11 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 89500, count: 11 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 100500, count: 12 },
    {
      creatureTypeId: CreatureTypeId.ZOMBIE_FAST,
      x: 400,
      y: 400,
      triggerTimeMs: 100500,
      count: 12,
    },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 100500, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 100500, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 111500, count: 13 },
    {
      creatureTypeId: CreatureTypeId.ZOMBIE_FAST,
      x: 400,
      y: 400,
      triggerTimeMs: 111500,
      count: 13,
    },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 111500, count: 13 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 111500, count: 13 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 122500, count: 14 },
    {
      creatureTypeId: CreatureTypeId.ZOMBIE_FAST,
      x: 400,
      y: 400,
      triggerTimeMs: 122500,
      count: 14,
    },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 122500, count: 14 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 122500, count: 14 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 133500, count: 15 },
    {
      creatureTypeId: CreatureTypeId.ZOMBIE_FAST,
      x: 400,
      y: 400,
      triggerTimeMs: 133500,
      count: 15,
    },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 133500, count: 15 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 133500, count: 15 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 144500, count: 16 },
    {
      creatureTypeId: CreatureTypeId.ZOMBIE_FAST,
      x: 400,
      y: 400,
      triggerTimeMs: 144500,
      count: 16,
    },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 144500, count: 16 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 144500, count: 16 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 155500, count: 17 },
    {
      creatureTypeId: CreatureTypeId.ZOMBIE_FAST,
      x: 400,
      y: 400,
      triggerTimeMs: 155500,
      count: 17,
    },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 155500, count: 17 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 155500, count: 17 },
    { creatureTypeId: CreatureTypeId.ZOMBIE, x: 400, y: 0, triggerTimeMs: 166500, count: 18 },
    {
      creatureTypeId: CreatureTypeId.ZOMBIE_FAST,
      x: 400,
      y: 400,
      triggerTimeMs: 166500,
      count: 18,
    },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: -100, y: 0, triggerTimeMs: 166500, count: 18 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 0, y: -100, triggerTimeMs: 166500, count: 18 },
  ],
  unlockRequirement: 'zombie_time',
};

const QUEST_THE_MASSACRE: QuestData = {
  id: 'the_massacre',
  name: 'The Massacre',
  description: 'Tank zombie massacre from right with lizard support. 5 minute challenge.',
  timeLimitMs: 300000,
  objectives: [{ type: 'kill_count', target: 200, description: 'Kill 200 enemies' }],
  spawnEntries: [
    // Tank zombies from right, increasing count
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 1500, count: 3 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 1500, count: 1 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 6500, count: 4 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 6500, count: 2 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 11500, count: 5 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 11500, count: 2 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 16500, count: 6 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 16500, count: 3 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 21500, count: 7 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 21500, count: 3 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 26500, count: 8 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 26500, count: 4 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 31500, count: 9 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 31500, count: 4 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 36500, count: 10 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 36500, count: 5 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 41500, count: 11 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 41500, count: 5 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 46500, count: 12 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 46500, count: 6 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 51500, count: 13 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 51500, count: 6 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 56500, count: 14 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 56500, count: 7 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 61500, count: 15 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 61500, count: 7 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 66500, count: 16 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 66500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 71500, count: 17 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 71500, count: 8 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 76500, count: 18 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 76500, count: 9 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 81500, count: 19 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 81500, count: 9 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 86500, count: 20 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 86500, count: 10 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 91500, count: 21 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 91500, count: 10 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 96500, count: 22 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 96500, count: 11 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 101500, count: 23 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 101500, count: 11 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 106500, count: 24 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 106500, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 111500, count: 25 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 111500, count: 12 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 116500, count: 26 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 116500, count: 13 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 121500, count: 27 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 121500, count: 13 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 126500, count: 28 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 126500, count: 14 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 131500, count: 29 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 131500, count: 14 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 136500, count: 30 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 136500, count: 15 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 141500, count: 31 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 141500, count: 15 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 146500, count: 32 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 146500, count: 16 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 151500, count: 33 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 151500, count: 16 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 156500, count: 34 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 156500, count: 17 },
    { creatureTypeId: CreatureTypeId.ZOMBIE_TANK, x: 400, y: 0, triggerTimeMs: 161500, count: 35 },
    { creatureTypeId: CreatureTypeId.LIZARD, x: 400, y: 0, triggerTimeMs: 161500, count: 17 },
  ],
  unlockRequirement: 'the_collaboration',
};

const QUEST_THE_UNBLITZKRIEG: QuestData = {
  id: 'the_unblitzkrieg',
  name: 'The Unblitzkrieg',
  description: '10-minute endurance test. Ghosts attack from all directions.',
  timeLimitMs: 600000,
  objectives: [{ type: 'survive_time', target: 600, description: 'Survive for 600 seconds' }],
  spawnEntries: [
    // Ghosts from all 4 edges in waves
    ...createWaveSpawns(CreatureTypeId.GHOST, 1, 60, 500, 1800),
    ...createWaveSpawns(CreatureTypeId.GHOST, 1, 60, 600, 1800),
    ...createWaveSpawns(CreatureTypeId.GHOST, 1, 60, 700, 1800),
    ...createWaveSpawns(CreatureTypeId.GHOST, 1, 60, 800, 1800),
    // Center spawn
    { creatureTypeId: CreatureTypeId.GHOST, x: 0, y: 0, triggerTimeMs: 10000, count: 1 },
    // Additional waves from corners
    ...createCornerSpawns(CreatureTypeId.GHOST, 1, 20000, 300),
    ...createCornerSpawns(CreatureTypeId.GHOST, 1, 40000, 300),
    ...createCornerSpawns(CreatureTypeId.GHOST, 1, 60000, 300),
    ...createCornerSpawns(CreatureTypeId.GHOST, 2, 80000, 350),
    ...createCornerSpawns(CreatureTypeId.GHOST, 2, 100000, 350),
    ...createCornerSpawns(CreatureTypeId.GHOST, 2, 120000, 350),
    ...createCornerSpawns(CreatureTypeId.GHOST, 3, 140000, 400),
    ...createCornerSpawns(CreatureTypeId.GHOST, 3, 160000, 400),
    ...createCornerSpawns(CreatureTypeId.GHOST, 3, 180000, 400),
    ...createCornerSpawns(CreatureTypeId.GHOST, 4, 200000, 400),
    ...createCornerSpawns(CreatureTypeId.GHOST, 4, 220000, 400),
    ...createCornerSpawns(CreatureTypeId.GHOST, 4, 240000, 400),
    ...createCornerSpawns(CreatureTypeId.GHOST, 5, 260000, 450),
    ...createCornerSpawns(CreatureTypeId.GHOST, 5, 280000, 450),
    ...createCornerSpawns(CreatureTypeId.GHOST, 5, 300000, 450),
    ...createCornerSpawns(CreatureTypeId.GHOST, 6, 320000, 450),
    ...createCornerSpawns(CreatureTypeId.GHOST, 6, 340000, 450),
    ...createCornerSpawns(CreatureTypeId.GHOST, 6, 360000, 450),
    ...createCornerSpawns(CreatureTypeId.GHOST, 7, 380000, 500),
    ...createCornerSpawns(CreatureTypeId.GHOST, 7, 400000, 500),
    ...createCornerSpawns(CreatureTypeId.GHOST, 7, 420000, 500),
    ...createCornerSpawns(CreatureTypeId.GHOST, 8, 440000, 500),
    ...createCornerSpawns(CreatureTypeId.GHOST, 8, 460000, 500),
    ...createCornerSpawns(CreatureTypeId.GHOST, 8, 480000, 500),
    ...createCornerSpawns(CreatureTypeId.GHOST, 9, 500000, 550),
    ...createCornerSpawns(CreatureTypeId.GHOST, 9, 520000, 550),
    ...createCornerSpawns(CreatureTypeId.GHOST, 9, 540000, 550),
    ...createCornerSpawns(CreatureTypeId.GHOST, 10, 560000, 550),
    ...createCornerSpawns(CreatureTypeId.GHOST, 10, 580000, 550),
    ...createCornerSpawns(CreatureTypeId.GHOST, 10, 600000, 550),
  ],
  unlockRequirement: 'the_massacre',
};

// ============================================================================
// Tier 5 Bonus Quests (Ultimate Challenges)
// ============================================================================

const QUEST_THE_ANNIHILATION: QuestData = {
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

const QUEST_THE_END_OF_ALL: QuestData = {
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

const QUEST_THE_SPANKING_OF_THE_DEAD: QuestData = {
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

const QUEST_SPIDEROIDS: QuestData = {
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

// ============================================================================
// Bonus Quests (Unlock after completing main quest line)
// ============================================================================

const QUEST_SYNTAX_TERROR: QuestData = {
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

// ============================================================================
// All Quests Map
// ============================================================================

export const ALL_QUESTS: QuestData[] = [
  // Tutorial / Early Game (Tier 1)
  QUEST_NAGOLIPOLI,
  QUEST_MONSTER_BLUES,
  QUEST_THE_GATHERING,
  QUEST_ARMY_OF_THREE,
  // Tier 1-2 Missing Quests
  QUEST_TARGET_PRACTICE,
  QUEST_FRONTLINE_ASSAULT,
  QUEST_SPIDER_WAVE_SYNDROME,
  QUEST_THE_RANDOM_FACTOR,
  QUEST_EVERRED_PASTURES,
  QUEST_SPIDER_SPAWNS,
  QUEST_TWO_FRONTS,
  QUEST_SWEEP_STAKES,
  QUEST_EVIL_ZOMBIES_AT_LARGE,
  QUEST_SURVIVAL_OF_THE_FASTEST,
  // Zombie Heavy (Tier 1-2)
  QUEST_KNEE_DEEP_IN_THE_DEAD,
  QUEST_THE_GANG_WARS,
  QUEST_THE_FORTRESS,
  QUEST_CROSS_FIRE,
  // Fast and Furious (Tier 2)
  QUEST_THE_BEATING,
  QUEST_HIDDEN_EVIL,
  QUEST_LAND_HOSTILE,
  QUEST_MINOR_ALIEN_BREACH,
  // Mixed Enemies (Tier 2-3)
  QUEST_ALIEN_SQUADS,
  QUEST_ZOMBIE_MASTERS,
  QUEST_8_LEGGED_TERROR,
  QUEST_GHOST_PATROLS,
  // Advanced Challenges (Tier 3)
  QUEST_NESTING_GROUNDS,
  QUEST_ALIEN_DENS,
  QUEST_ARACHNOID_FARM,
  QUEST_GAUNTLET,
  // Tier 3-4 Missing Quests
  QUEST_THE_BLIGHTING,
  QUEST_THE_KILLING,
  QUEST_SURROUNDED_BY_REPTILES,
  QUEST_THE_LIZQUIDATION,
  QUEST_SPIDERS_INC,
  QUEST_DEJA_VU,
  QUEST_MAJOR_ALIEN_BREACH,
  QUEST_ZOMBIE_TIME,
  QUEST_THE_COLLABORATION,
  QUEST_THE_MASSACRE,
  QUEST_THE_UNBLITZKRIEG,
  // Lizard Quests (Tier 2-4)
  QUEST_LAND_OF_LIZARDS,
  QUEST_LIZARD_KINGS,
  QUEST_LIZARD_RAZE,
  QUEST_LIZARD_ZOMBIE_PACT,
  // Tier 5 Bonus Quests
  QUEST_THE_ANNIHILATION,
  QUEST_THE_END_OF_ALL,
  QUEST_THE_SPANKING_OF_THE_DEAD,
  QUEST_SPIDEROIDS,
  QUEST_SYNTAX_TERROR,
];

export const QUEST_DATA_MAP: ReadonlyMap<QuestId, QuestData> = new Map(
  ALL_QUESTS.map((quest) => [quest.id, quest])
);

// ============================================================================
// Helper Functions
// ============================================================================

/**
 * Get quest data by ID
 */
export function getQuestData(questId: QuestId): QuestData | undefined {
  return QUEST_DATA_MAP.get(questId);
}

/**
 * Get the first quest (starting point)
 */
export function getStartingQuest(): QuestId {
  return 'nagolipoli';
}

/**
 * Check if a quest is unlocked given completed quests
 */
export function isQuestUnlocked(questId: QuestId, completedQuests: QuestId[]): boolean {
  const quest = getQuestData(questId);
  if (!quest) return false;

  // No requirement = always unlocked
  if (!quest.unlockRequirement) return true;

  // Check if required quest is completed
  return completedQuests.includes(quest.unlockRequirement);
}

/**
 * Get all quests that are unlocked but not completed
 */
export function getAvailableQuests(
  completedQuests: QuestId[],
  includeCompleted = false
): QuestId[] {
  return ALL_QUESTS.filter((quest) => {
    const isCompleted = completedQuests.includes(quest.id);
    if (isCompleted && !includeCompleted) return false;
    return isQuestUnlocked(quest.id, completedQuests);
  }).map((quest) => quest.id);
}

/**
 * Get the quest unlock order (linear progression for main quests)
 */
export function getQuestUnlockChain(): QuestId[] {
  const chain: QuestId[] = [];
  const added = new Set<QuestId>();

  for (const quest of ALL_QUESTS) {
    if (!quest.isBonus && !added.has(quest.id)) {
      chain.push(quest.id);
      added.add(quest.id);
    }
  }

  return chain;
}

/**
 * Get next quest in progression
 */
export function getNextQuest(currentQuestId: QuestId): QuestId | null {
  const chain = getQuestUnlockChain();
  const index = chain.indexOf(currentQuestId);
  if (index >= 0 && index < chain.length - 1) {
    const nextQuest = chain[index + 1];
    return nextQuest ?? null;
  }
  return null;
}

/**
 * Check if all main quests are completed
 */
export function areAllMainQuestsCompleted(completedQuests: QuestId[]): boolean {
  const mainQuests = ALL_QUESTS.filter((q) => !q.isBonus);
  return mainQuests.every((quest) => completedQuests.includes(quest.id));
}

/**
 * Get quest statistics
 */
export function getQuestStats(): {
  total: number;
  mainQuests: number;
  bonusQuests: number;
} {
  return {
    total: ALL_QUESTS.length,
    mainQuests: ALL_QUESTS.filter((q) => !q.isBonus).length,
    bonusQuests: ALL_QUESTS.filter((q) => q.isBonus).length,
  };
}
