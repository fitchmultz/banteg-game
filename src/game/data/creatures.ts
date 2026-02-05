/**
 * Creature Data Tables
 *
 * Based on creature_type_table from decompiled source.
 * Defines all enemy types with their stats and behaviors.
 *
 * Stats are derived from grim.dll runtime conversions in creature-conversions.ts
 * to achieve exact parity with the decompiled Crimsonland source.
 */

import { AiMode, CreatureTypeId } from '../../types';
import {
  convertCreatureStats,
  CREATURE_TYPE_TO_TEMPLATE,
} from './creature-conversions';

export interface CreatureData {
  /** Creature display name */
  name: string;
  /** Maximum health */
  health: number;
  /** Movement speed (units per second) */
  speed: number;
  /** Visual size multiplier */
  size: number;
  /** Collision radius */
  hitboxRadius: number;
  /** Contact damage to player */
  contactDamage: number;
  /** XP reward on kill */
  rewardXP: number;
  /** Default AI behavior */
  defaultAiMode: AiMode;
  /** Animation speed multiplier */
  animRate: number;
  /** Score value */
  scoreValue: number;
  /** Spawn weight for random spawning (higher = more common) */
  spawnWeight: number;
  /** Minimum wave to appear in */
  minWave: number;
  /** Color tint (for visual variety) */
  tint: { r: number; g: number; b: number; a: number };
}

// Helper to get converted stats from canonical formulas
function getCreatureStats(id: CreatureTypeId) {
  const templateId = CREATURE_TYPE_TO_TEMPLATE[id as number];
  if (templateId === undefined) {
    throw new Error(`No template mapping for creature ID: ${id}`);
  }
  return convertCreatureStats(templateId);
}

// Creature data matching the original game's balance
// Values derived from decompiled creature_type_table via creature-conversions.ts
export const CREATURE_DATA: Record<CreatureTypeId, CreatureData> = {
  [CreatureTypeId.ZOMBIE]: {
    name: 'Zombie',
    ...getCreatureStats(CreatureTypeId.ZOMBIE),
    size: 1.0,
    hitboxRadius: 16,
    rewardXP: 10,
    defaultAiMode: AiMode.CHASE,
    animRate: 1.2,
    scoreValue: 100,
    spawnWeight: 30,
    minWave: 1,
    tint: { r: 0.8, g: 1.0, b: 0.8, a: 1.0 },
  },
  [CreatureTypeId.ZOMBIE_FAST]: {
    name: 'Fast Zombie',
    ...getCreatureStats(CreatureTypeId.ZOMBIE_FAST),
    size: 0.9,
    hitboxRadius: 14,
    rewardXP: 15,
    defaultAiMode: AiMode.CHASE,
    animRate: 1.5,
    scoreValue: 150,
    spawnWeight: 20,
    minWave: 2,
    tint: { r: 1.0, g: 0.9, b: 0.7, a: 1.0 },
  },
  [CreatureTypeId.ZOMBIE_TANK]: {
    name: 'Tank Zombie',
    ...getCreatureStats(CreatureTypeId.ZOMBIE_TANK),
    size: 1.3,
    hitboxRadius: 22,
    rewardXP: 30,
    defaultAiMode: AiMode.CHASE,
    animRate: 0.9,
    scoreValue: 300,
    spawnWeight: 10,
    minWave: 3,
    tint: { r: 0.7, g: 0.8, b: 0.7, a: 1.0 },
  },
  [CreatureTypeId.SPIDER_SMALL]: {
    name: 'Small Spider',
    ...getCreatureStats(CreatureTypeId.SPIDER_SMALL),
    size: 0.6,
    hitboxRadius: 10,
    rewardXP: 12,
    defaultAiMode: AiMode.CHASE,
    animRate: 1.8,
    scoreValue: 120,
    spawnWeight: 25,
    minWave: 2,
    tint: { r: 0.9, g: 0.7, b: 0.9, a: 1.0 },
  },
  [CreatureTypeId.SPIDER_LARGE]: {
    name: 'Large Spider',
    ...getCreatureStats(CreatureTypeId.SPIDER_LARGE),
    size: 1.1,
    hitboxRadius: 18,
    rewardXP: 25,
    defaultAiMode: AiMode.CHASE,
    animRate: 1.3,
    scoreValue: 250,
    spawnWeight: 15,
    minWave: 4,
    tint: { r: 0.8, g: 0.6, b: 0.8, a: 1.0 },
  },
  [CreatureTypeId.ALIEN_TROOPER]: {
    name: 'Alien Trooper',
    ...getCreatureStats(CreatureTypeId.ALIEN_TROOPER),
    size: 1.0,
    hitboxRadius: 16,
    rewardXP: 20,
    defaultAiMode: AiMode.CHASE,
    animRate: 1.1,
    scoreValue: 200,
    spawnWeight: 15,
    minWave: 5,
    tint: { r: 0.7, g: 1.0, b: 1.0, a: 1.0 },
  },
  [CreatureTypeId.ALIEN_ELITE]: {
    name: 'Alien Elite',
    ...getCreatureStats(CreatureTypeId.ALIEN_ELITE),
    size: 1.1,
    hitboxRadius: 18,
    rewardXP: 35,
    defaultAiMode: AiMode.CHASE,
    animRate: 1.0,
    scoreValue: 350,
    spawnWeight: 8,
    minWave: 6,
    tint: { r: 0.6, g: 0.9, b: 1.0, a: 1.0 },
  },
  [CreatureTypeId.GHOST]: {
    name: 'Ghost',
    ...getCreatureStats(CreatureTypeId.GHOST),
    size: 1.0,
    hitboxRadius: 14,
    rewardXP: 25,
    defaultAiMode: AiMode.WANDER,
    animRate: 1.4,
    scoreValue: 250,
    spawnWeight: 12,
    minWave: 4,
    tint: { r: 0.9, g: 0.9, b: 1.0, a: 0.8 },
  },
  [CreatureTypeId.LIZARD]: {
    name: 'Lizard',
    ...getCreatureStats(CreatureTypeId.LIZARD),
    size: 1.0,
    hitboxRadius: 16,
    rewardXP: 22,
    defaultAiMode: AiMode.CHASE,
    animRate: 1.3,
    scoreValue: 220,
    spawnWeight: 12,
    minWave: 6,
    tint: { r: 0.75, g: 0.75, b: 0.38, a: 1.0 },
  },
  [CreatureTypeId.LIZARD_KING]: {
    name: 'Lizard King',
    ...getCreatureStats(CreatureTypeId.LIZARD_KING),
    size: 1.6,
    hitboxRadius: 26,
    rewardXP: 500,
    defaultAiMode: AiMode.CHASE,
    animRate: 1.0,
    scoreValue: 5000,
    spawnWeight: 0,
    minWave: 999,
    tint: { r: 0.99, g: 0.99, b: 0.21, a: 1.0 },
  },
  [CreatureTypeId.LIZARD_MINION]: {
    name: 'Lizard Minion',
    ...getCreatureStats(CreatureTypeId.LIZARD_MINION),
    size: 0.95,
    hitboxRadius: 15,
    rewardXP: 18,
    defaultAiMode: AiMode.CHASE,
    animRate: 1.3,
    scoreValue: 180,
    spawnWeight: 0,
    minWave: 999,
    tint: { r: 0.72, g: 0.72, b: 0.38, a: 1.0 },
  },
};

/** Get creature data by type ID */
export function getCreatureData(creatureTypeId: CreatureTypeId): CreatureData {
  return CREATURE_DATA[creatureTypeId] ?? CREATURE_DATA[CreatureTypeId.ZOMBIE];
}

/** Get creatures available for a given wave */
export function getCreaturesForWave(wave: number): CreatureTypeId[] {
  return Object.values(CreatureTypeId)
    .filter((id): id is CreatureTypeId => typeof id === 'number')
    .filter((id) => CREATURE_DATA[id].minWave <= wave);
}

/** Calculate spawn weights for wave (returns weighted random pool) */
export function getSpawnWeightsForWave(wave: number): Map<CreatureTypeId, number> {
  const available = getCreaturesForWave(wave);
  const weights = new Map<CreatureTypeId, number>();

  for (const id of available) {
    // Increase weight of higher-tier enemies as waves progress
    const data = CREATURE_DATA[id];
    const waveBonus = Math.max(0, wave - data.minWave) * 2;
    weights.set(id, data.spawnWeight + waveBonus);
  }

  return weights;
}

/** Select a random creature type for the given wave */
export function selectRandomCreatureForWave(wave: number): CreatureTypeId {
  const weights = getSpawnWeightsForWave(wave);
  const totalWeight = Array.from(weights.values()).reduce((a, b) => a + b, 0);
  let random = Math.random() * totalWeight;

  for (const [id, weight] of weights) {
    random -= weight;
    if (random <= 0) {
      return id;
    }
  }

  return CreatureTypeId.ZOMBIE;
}
