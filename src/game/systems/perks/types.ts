/**
 * Perk System Types
 *
 * Type definitions for the perk system and its handlers.
 */

import type { EntityId, PerkId } from '../../../types';

export interface PerkSystemCallbacks {
  onPerkApplied?: (entityId: EntityId, perkId: PerkId, newRank: number) => void;
  onFatalLottery?: (entityId: EntityId, survived: boolean, xpGained: number) => void;
  onInfernalContract?: (entityId: EntityId, levelsGained: number) => void;
  onGrimDeal?: (entityId: EntityId, xpConverted: number) => void;
}

export interface ActivePerkEffect {
  perkId: PerkId;
  endsAtGameTime: number; // Deterministic: uses context.gameTime
  duration: number;
}

export interface JinxState {
  nextTriggerTime: number;
  interval: number;
}

export interface DotEffect {
  creatureId: EntityId;
  damagePerTick: number;
  remainingDuration: number;
  tickInterval: number;
  timeUntilNextTick: number;
  type: 'uranium' | 'poison';
}
