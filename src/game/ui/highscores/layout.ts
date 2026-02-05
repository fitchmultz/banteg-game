/**
 * High Scores UI Layout Constants
 *
 * Centralized layout constants for consistent UI rendering.
 */

import type { LayoutConstants, SortOption } from './types';

export const LAYOUT: LayoutConstants = {
  PANEL_WIDTH: 700,
  PANEL_HEIGHT: 500,
  TAB_HEIGHT: 40,
  HEADER_HEIGHT: 50,
  ROW_HEIGHT: 35,
  PADDING: 30,
} as const;

// Tab configuration
export const TABS = ['SURVIVAL', 'QUESTS', 'RUSH'] as const;
export const TAB_WIDTH = 140;

// Sort options
export const SORT_OPTIONS: { id: SortOption; label: string }[] = [
  { id: 'score', label: 'By Score' },
  { id: 'time', label: 'By Time' },
  { id: 'date', label: 'By Date' },
];

// Action buttons
export const ACTION_BUTTONS: { id: string; label: string; color: string }[] = [
  { id: 'export', label: 'Export Scores', color: '#444466' },
  { id: 'import', label: 'Import Scores', color: '#444466' },
  { id: 'reset', label: 'Reset All', color: '#AA4444' },
];
