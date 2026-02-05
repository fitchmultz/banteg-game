/**
 * Tier 2-3 Quests (Mid Game)
 *
 * Fast & Furious challenges, Mixed Enemies, and Lizard quests.
 */

import { CreatureTypeId } from '../../../types';
import type { QuestData } from './types';
import { createWaveSpawns, createCircleSpawns, createRepeatingSingleSpawns } from './helpers';

// ============================================================================
// Fast and Furious (Tier 2)
// ============================================================================

export const QUEST_THE_BEATING: QuestData = {
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

export const QUEST_HIDDEN_EVIL: QuestData = {
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

export const QUEST_LAND_HOSTILE: QuestData = {
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

export const QUEST_MINOR_ALIEN_BREACH: QuestData = {
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
// Mixed Enemies (Tier 2-3)
// ============================================================================

export const QUEST_ALIEN_SQUADS: QuestData = {
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

export const QUEST_ZOMBIE_MASTERS: QuestData = {
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

export const QUEST_8_LEGGED_TERROR: QuestData = {
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

export const QUEST_GHOST_PATROLS: QuestData = {
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
// Lizard Quests (Tier 2-4)
// ============================================================================

export const QUEST_LAND_OF_LIZARDS: QuestData = {
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

export const QUEST_LIZARD_KINGS: QuestData = {
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

export const QUEST_LIZARD_RAZE: QuestData = {
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

export const QUEST_LIZARD_ZOMBIE_PACT: QuestData = {
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
