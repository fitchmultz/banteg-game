/**
 * High Scores UI Input Handling
 *
 * Input event handlers and hit detection for UI elements.
 */

import type { HighScoreTab, SortOption, SortDirection } from './types';
import { LAYOUT, TABS, TAB_WIDTH, SORT_OPTIONS } from './layout';

export interface InputState {
  currentTab: HighScoreTab;
  sortBy: SortOption;
  sortDirection: SortDirection;
  showConfirmation: boolean;
}

export interface InputActions {
  onBack: () => void;
  onTabChange: (tab: HighScoreTab) => void;
  onSortChange: (sortBy: SortOption, sortDirection: SortDirection) => void;
  onExport: () => void;
  onImport: () => void;
  onReset: () => void;
  onConfirmReset: () => void;
  onCancelReset: () => void;
}

/**
 * Cycle to next/previous tab
 */
export function cycleTab(currentTab: HighScoreTab, direction: number): HighScoreTab {
  const currentIndex = TABS.indexOf(currentTab);
  const newIndex = (currentIndex + direction + TABS.length) % TABS.length;
  return TABS[newIndex] ?? 'SURVIVAL';
}

/**
 * Handle keyboard input
 */
export function handleKeyDown(e: KeyboardEvent, state: InputState, actions: InputActions): void {
  if (state.showConfirmation) {
    if (e.key === 'Escape') {
      actions.onCancelReset();
    } else if (e.key === 'Enter') {
      actions.onConfirmReset();
    }
    return;
  }

  switch (e.key) {
    case 'Escape':
      actions.onBack();
      break;
    case 'ArrowLeft':
      actions.onTabChange(cycleTab(state.currentTab, -1));
      break;
    case 'ArrowRight':
      actions.onTabChange(cycleTab(state.currentTab, 1));
      break;
  }
}

/**
 * Get tab click hit detection
 */
export function getTabAtPosition(
  canvasWidth: number,
  canvasHeight: number,
  x: number,
  y: number
): HighScoreTab | null {
  const tabHeight = LAYOUT.TAB_HEIGHT;
  const startX = canvasWidth / 2 - (TABS.length * TAB_WIDTH) / 2;
  const tabY = canvasHeight / 2 - LAYOUT.PANEL_HEIGHT / 2 + 80;

  for (let i = 0; i < TABS.length; i++) {
    const tabX = startX + i * TAB_WIDTH;
    if (x >= tabX && x <= tabX + TAB_WIDTH && y >= tabY && y <= tabY + tabHeight) {
      return TABS[i] ?? null;
    }
  }
  return null;
}

/**
 * Get sort button at position
 */
export function getSortOptionAtPosition(
  canvasWidth: number,
  canvasHeight: number,
  x: number,
  y: number
): SortOption | null {
  const buttonWidth = 100;
  const buttonHeight = 30;
  const buttonSpacing = 10;
  const panelX = (canvasWidth - LAYOUT.PANEL_WIDTH) / 2;
  const contentY =
    canvasHeight / 2 - LAYOUT.PANEL_HEIGHT / 2 + LAYOUT.TAB_HEIGHT + LAYOUT.HEADER_HEIGHT + 20;
  const startX = panelX + LAYOUT.PADDING + 50;
  const btnY = contentY + 200;

  for (let i = 0; i < SORT_OPTIONS.length; i++) {
    const btnX = startX + i * (buttonWidth + buttonSpacing);
    if (x >= btnX && x <= btnX + buttonWidth && y >= btnY && y <= btnY + buttonHeight) {
      return SORT_OPTIONS[i]?.id ?? null;
    }
  }
  return null;
}

/**
 * Get action button at position
 */
export function getActionButtonAtPosition(
  canvasWidth: number,
  canvasHeight: number,
  x: number,
  y: number
): 'export' | 'import' | 'reset' | null {
  const buttons = ['export', 'import', 'reset'] as const;
  const buttonWidth = 120;
  const buttonHeight = 35;
  const buttonSpacing = 15;
  const panelX = (canvasWidth - LAYOUT.PANEL_WIDTH) / 2;
  const contentY =
    canvasHeight / 2 - LAYOUT.PANEL_HEIGHT / 2 + LAYOUT.TAB_HEIGHT + LAYOUT.HEADER_HEIGHT + 20;
  const startX = panelX + LAYOUT.PADDING;
  const btnY = contentY + 260;

  for (let i = 0; i < buttons.length; i++) {
    const btnX = startX + i * (buttonWidth + buttonSpacing);
    if (x >= btnX && x <= btnX + buttonWidth && y >= btnY && y <= btnY + buttonHeight) {
      return buttons[i] ?? null;
    }
  }
  return null;
}

/**
 * Get confirmation dialog button at position
 */
export function getConfirmationButtonAtPosition(
  canvasWidth: number,
  canvasHeight: number,
  x: number,
  y: number
): 'cancel' | 'confirm' | null {
  const dialogHeight = 200;
  const dialogY = (canvasHeight - dialogHeight) / 2;
  const btnWidth = 120;
  const btnHeight = 35;
  const btnY = dialogY + dialogHeight - 60;

  // Cancel button
  const cancelX = canvasWidth / 2 - btnWidth - 10;
  if (x >= cancelX && x <= cancelX + btnWidth && y >= btnY && y <= btnY + btnHeight) {
    return 'cancel';
  }

  // Confirm button
  const confirmX = canvasWidth / 2 + 10;
  if (x >= confirmX && x <= confirmX + btnWidth && y >= btnY && y <= btnY + btnHeight) {
    return 'confirm';
  }

  return null;
}
