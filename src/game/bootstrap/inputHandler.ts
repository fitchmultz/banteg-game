/**
 * Input Handler
 *
 * Global keyboard event handling.
 */

import { gameState } from './gameState';

export function setupInputHandlers(): void {
  document.addEventListener('keydown', (e) => {
    // Toggle console with backtick/tilde
    if (e.code === 'Backquote') {
      gameState.console?.toggle();
      return;
    }

    if (gameState.console?.isOpen()) {
      const consumed = gameState.console.handleKeyDown(e);
      if (consumed) {
        e.preventDefault();
        return;
      }
    }

    // Toggle FPS counter with F3
    if (e.code === 'F3') {
      gameState.renderSystem?.toggleFps();
      return;
    }

    // Handle pause with configured key binding
    const pauseKey = gameState.settingsManager?.getKeyBindings().pause ?? 'Escape';
    if (e.code === pauseKey) {
      if (gameState.appState.type === 'PLAYING') {
        if (!gameState.perkSelectUI?.isShown()) {
          // Dispatch pause event - handler in main.ts has access to audio/renderer
          document.dispatchEvent(new CustomEvent('pauseGame'));
        }
      } else if (gameState.appState.type === 'PAUSED') {
        if (!gameState.optionsMenuUI?.isShown()) {
          document.dispatchEvent(new CustomEvent('resumeGame'));
        }
      }
      return;
    }

    // Quest menu from main menu
    if (e.code === 'KeyQ' && gameState.appState.type === 'MENU') {
      if (gameState.questMenuUI?.isShown()) {
        gameState.questMenuUI?.hide();
      } else {
        gameState.mainMenuUI?.hide();
        gameState.questMenuUI?.show();
      }
    }

    // High scores menu from main menu
    if (e.code === 'KeyH' && gameState.appState.type === 'MENU') {
      if (gameState.highScoresUI?.isShown()) {
        gameState.highScoresUI?.hide();
        const { showMainMenu } = require('./menuLifecycle');
        showMainMenu();
      } else {
        gameState.mainMenuUI?.hide();
        gameState.highScoresUI?.show();
      }
    }
  });

  document.addEventListener('keypress', (e) => {
    if (gameState.console?.isOpen()) {
      const consumed = gameState.console.handleInput(e.key);
      if (consumed) {
        e.preventDefault();
      }
    }
  });
}
