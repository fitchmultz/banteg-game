/**
 * High Scores UI Types
 *
 * Shared types for the high scores UI system.
 */

import type { QuestId } from '../../../types';
import type { QuestHighScore } from '../../progression/ProgressionManager';

export type HighScoreTab = 'SURVIVAL' | 'QUESTS' | 'RUSH';
export type SortOption = 'score' | 'time' | 'date';
export type SortDirection = 'asc' | 'desc';

export interface HighScoresUIOptions {
  canvas: HTMLCanvasElement;
  progressionManager: import('../../progression/ProgressionManager').ProgressionManager;
  onBack: () => void;
}

export interface QuestScoreEntry {
  questId: QuestId;
  questName: string;
  highScore: QuestHighScore;
}

export interface LayoutConstants {
  readonly PANEL_WIDTH: number;
  readonly PANEL_HEIGHT: number;
  readonly TAB_HEIGHT: number;
  readonly HEADER_HEIGHT: number;
  readonly ROW_HEIGHT: number;
  readonly PADDING: number;
}
