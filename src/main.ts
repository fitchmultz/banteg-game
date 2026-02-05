/**
 * Crimsonland Remake - Main Entry Point
 *
 * Initializes the game engine, ECS systems, and manages game state.
 * Refactored into bootstrap modules for maintainability.
 */

import { EntityManager, SystemManager } from './core/ecs';
import { SettingsManager } from './game/settings/SettingsManager';
import { ProgressionManager } from './game/progression';
import {
  gameState,
  initializeEngine,
  initializeModes,
  initializeUI,
  initializeConsole,
  showMainMenu,
  startMenuLoop,
  startGame,
  pauseGame,
  resumeGame,
  restartGame,
  returnToMainMenu,
  cleanup,
  setupInputHandlers,
} from './game/bootstrap';

// TARGET_UPS is defined in gameLifecycle module

// Core engine instances (module-level for event handler access)
let engineInstances: Awaited<ReturnType<typeof initializeEngine>>;
let entityManager: EntityManager;
let systemManager: SystemManager;

async function init(): Promise<void> {
  const container = document.getElementById('game-container');
  if (!container) {
    throw new Error('Game container not found');
  }

  // Initialize settings manager first (loads from localStorage)
  const settingsManager = new SettingsManager();
  gameState.settingsManager = settingsManager;

  // Initialize engine (renderer, input, audio, assets)
  engineInstances = await initializeEngine(container, settingsManager);
  const { renderer, input, audio, assetManager, spriteAtlas } = engineInstances;

  // Initialize ECS
  entityManager = new EntityManager();
  systemManager = new SystemManager();

  // Initialize progression manager
  const progressionManager = new ProgressionManager({
    onQuestCompleted: (questId) => console.log(`Quest completed: ${questId}`),
    onNewSurvivalRecord: (record) => console.log('New survival record:', record),
    onMilestoneReached: (milestone) => console.log(`Milestone reached: ${milestone}`),
  });
  gameState.progressionManager = progressionManager;

  // Initialize game modes
  initializeModes(entityManager, progressionManager);

  // Initialize UI components
  initializeUI(renderer, input, audio);

  // Initialize console
  await initializeConsole(renderer, input, entityManager);

  // Show main menu
  showMainMenu();
  startMenuLoop(renderer);

  // Setup input handlers
  setupInputHandlers();

  // Wire up event handlers for game lifecycle
  document.addEventListener('startGame', ((e: CustomEvent) => {
    startGame(
      e.detail,
      entityManager,
      systemManager,
      renderer,
      input,
      audio,
      assetManager,
      spriteAtlas
    );
  }) as EventListener);

  document.addEventListener('pauseGame', () => {
    pauseGame(audio, renderer);
  });

  document.addEventListener('resumeGame', () => {
    resumeGame(audio);
  });

  document.addEventListener('restartGame', (() => {
    restartGame(entityManager, systemManager, renderer, input, audio, assetManager, spriteAtlas);
  }) as EventListener);

  document.addEventListener('returnToMainMenu', () => {
    returnToMainMenu(audio, entityManager, systemManager);
  });

  // Cleanup on unload
  window.addEventListener('beforeunload', () => {
    cleanup(input, audio, entityManager, systemManager);
  });

  // Periodic save (every 30 seconds)
  setInterval(() => {
    gameState.progressionManager?.save();
  }, 30000);

  console.log('Crimsonland Remake initialized');
  console.log('Controls:');
  console.log('  WASD - Move');
  console.log('  Mouse - Aim');
  console.log('  Left Click - Fire');
  console.log('  R - Reload');
  console.log('  Escape - Pause');

  // Expose game state for debugging
  (window as unknown as Record<string, unknown>).gameState = gameState;
  (window as unknown as Record<string, unknown>).toggleFps = () => {
    gameState.renderSystem?.toggleFps();
  };
}

// Start when DOM is ready
if (document.readyState === 'loading') {
  document.addEventListener('DOMContentLoaded', init);
} else {
  init().catch(console.error);
}
