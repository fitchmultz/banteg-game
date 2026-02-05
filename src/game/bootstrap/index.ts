/**
 * Bootstrap Module
 *
 * Re-exports all bootstrap functionality.
 */

export type { AppState, GlobalGameState } from './types';
export { gameState, setAppState } from './gameState';
export { initializeEngine, type EngineInstances } from './engineInit';
export { initializeModes, type ModeInstances } from './modeInit';
export { initializeUI } from './uiInit';
export { initializeConsole } from './consoleSetup';
export { showMainMenu, startMenuLoop, startPauseLoop } from './menuLifecycle';
export { handlePerkSelection } from './perkHandler';
export {
  startGame,
  pauseGame,
  resumeGame,
  restartGame,
  returnToMainMenu,
  handleGameOver,
  cleanup,
} from './gameLifecycle';
export { setupInputHandlers } from './inputHandler';
