/**
 * Game State
 *
 * Global game state singleton for easy access from callbacks.
 */

import type { GlobalGameState, AppState } from './types';

export const gameState: GlobalGameState = {
  appState: { type: 'MENU' },
  gameModeManager: null,
  survivalMode: null,
  questMode: null,
  rushMode: null,
  tutorialMode: null,
  perkSystem: null,
  progressionManager: null,
  mainMenuUI: null,
  perkSelectUI: null,
  questMenuUI: null,
  pauseMenuUI: null,
  gameOverUI: null,
  tutorialUI: null,
  optionsMenuUI: null,
  highScoresUI: null,
  creditsUI: null,
  settingsManager: null,
  currentGameState: null,
  playerEntityId: null,
  playerEntityIds: [],
  renderSystem: null,
  spawnSystem: null,
  rushSpawnSystem: null,
  audioLoaded: false,
  console: null,
};

export function setAppState(state: AppState): void {
  gameState.appState = state;
}
