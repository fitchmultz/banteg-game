/**
 * Quest Data Module
 *
 * Re-exports all quest-related types, data, and utilities.
 */

// Types
export type {
  QuestSpawnEntry,
  QuestObjectiveType,
  QuestObjective,
  QuestData,
} from './types';

// Data
export { ALL_QUESTS, QUEST_DATA_MAP } from './data';

// Query functions
export {
  getQuestData,
  getStartingQuest,
  isQuestUnlocked,
  getAvailableQuests,
  getQuestUnlockChain,
  getNextQuest,
  areAllMainQuestsCompleted,
  getQuestStats,
} from './queries';
