/**
 * Quest Type Definitions
 *
 * Core types for quest data structures.
 */

import type { CreatureTypeId, QuestId } from '../../../types';

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
