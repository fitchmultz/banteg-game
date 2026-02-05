/**
 * Quest Query Functions
 *
 * Accessor and utility functions for quest data.
 */

import type { QuestId } from '../../../types';
import { ALL_QUESTS, QUEST_DATA_MAP } from './data';
import type { QuestData } from './types';

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
