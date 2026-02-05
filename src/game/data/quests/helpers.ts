/**
 * Quest Spawn Helper Functions
 *
 * Utilities for generating quest spawn entry patterns.
 */

import type { CreatureTypeId } from '../../../types';
import type { QuestSpawnEntry } from './types';

export function createWaveSpawns(
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

export function createCornerSpawns(
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

export function createRepeatingSingleSpawns(
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

export function createCircleSpawns(
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
