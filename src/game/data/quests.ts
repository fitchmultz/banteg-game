/**
 * Quest Data Definitions
 *
 * Based on decompiled quest_build_* functions from crimsonland.exe.
 * Defines all 20 quests with objectives and time-based spawn patterns.
 */

import { type QuestId, CreatureTypeId } from '../../types';

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

// ============================================================================
// Quest 1-4: Tutorial / Early Game (Already partially implemented)
// ============================================================================

const QUEST_NAGOLIPOLI: QuestData = {
  id: 'nagolipoli',
  name: 'Nagolipoli',
  description: 'Survive the initial zombie outbreak. Tutorial level for new players.',
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
  objectives: [{ type: 'kill_count', target: 100, description: 'Kill 100 zombies' }],
  spawnEntries: [
    // Intense zombie waves
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 8, 8, 0, 2000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 4, 6, 8000, 3000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_TANK, 1, 5, 15000, 8000),
  ],
  unlockRequirement: 'army_of_three',
};

const QUEST_THE_GANG_WARS: QuestData = {
  id: 'the_gang_wars',
  name: 'The Gang Wars',
  description: 'Kill 75 mixed enemies in gang warfare.',
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
// Bonus Quests (Unlock after completing main quest line)
// ============================================================================

const QUEST_SYNTAX_TERROR: QuestData = {
  id: 'syntax_terror',
  name: 'Syntax Terror',
  description: 'Mixed enemy types in chaotic waves. (Bonus)',
  isBonus: true,
  objectives: [{ type: 'kill_count', target: 150, description: 'Kill 150 enemies' }],
  spawnEntries: [
    ...createWaveSpawns(CreatureTypeId.ZOMBIE, 3, 10, 0, 3000),
    ...createWaveSpawns(CreatureTypeId.ZOMBIE_FAST, 2, 10, 2000, 3000),
    ...createWaveSpawns(CreatureTypeId.SPIDER_SMALL, 2, 10, 4000, 3000),
    ...createWaveSpawns(CreatureTypeId.ALIEN_TROOPER, 2, 10, 6000, 3000),
    ...createWaveSpawns(CreatureTypeId.GHOST, 2, 10, 8000, 3000),
  ],
  unlockRequirement: 'gauntlet',
};

// ============================================================================
// All Quests Map
// ============================================================================

export const ALL_QUESTS: QuestData[] = [
  QUEST_NAGOLIPOLI,
  QUEST_MONSTER_BLUES,
  QUEST_THE_GATHERING,
  QUEST_ARMY_OF_THREE,
  QUEST_KNEE_DEEP_IN_THE_DEAD,
  QUEST_THE_GANG_WARS,
  QUEST_THE_FORTRESS,
  QUEST_CROSS_FIRE,
  QUEST_THE_BEATING,
  QUEST_HIDDEN_EVIL,
  QUEST_LAND_HOSTILE,
  QUEST_MINOR_ALIEN_BREACH,
  QUEST_ALIEN_SQUADS,
  QUEST_ZOMBIE_MASTERS,
  QUEST_8_LEGGED_TERROR,
  QUEST_GHOST_PATROLS,
  QUEST_NESTING_GROUNDS,
  QUEST_ALIEN_DENS,
  QUEST_ARACHNOID_FARM,
  QUEST_GAUNTLET,
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
