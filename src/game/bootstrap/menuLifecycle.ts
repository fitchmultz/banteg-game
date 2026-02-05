/**
 * Menu Lifecycle
 *
 * Handles menu loop and main menu display.
 */

import type { Renderer } from '../../engine';
import { gameState } from './gameState';

let pauseLoopId: number | null = null;

export function showMainMenu(): void {
  gameState.appState = { type: 'MENU' };
  gameState.mainMenuUI?.show();
  gameState.pauseMenuUI?.hide();
  gameState.gameOverUI?.hide();
  gameState.perkSelectUI?.hide();
  gameState.questMenuUI?.hide();
  gameState.tutorialUI?.hide();
  gameState.highScoresUI?.hide();
  gameState.creditsUI?.hide();
}

export function startMenuLoop(renderer: Renderer): void {
  let lastTime = performance.now();

  function menuLoop(currentTime: number): void {
    if (gameState.appState.type !== 'MENU') return;

    const dt = Math.min((currentTime - lastTime) / 1000, 0.1);
    lastTime = currentTime;

    renderer.clearBlack();

    gameState.mainMenuUI?.update(dt);
    gameState.mainMenuUI?.render();

    if (gameState.questMenuUI?.isShown()) {
      gameState.questMenuUI?.render();
    }

    if (gameState.highScoresUI?.isShown()) {
      gameState.highScoresUI?.update(dt);
      gameState.highScoresUI?.render();
    }

    if (gameState.creditsUI?.isShown()) {
      gameState.creditsUI?.update(dt);
      gameState.creditsUI?.render();
    }

    requestAnimationFrame(menuLoop);
  }

  requestAnimationFrame(menuLoop);
}

export function startPauseLoop(renderer: Renderer): void {
  if (pauseLoopId !== null) return;

  let lastTime = performance.now();

  function pauseLoop(currentTime: number): void {
    if (gameState.appState.type !== 'PAUSED') {
      pauseLoopId = null;
      return;
    }

    const dt = Math.min((currentTime - lastTime) / 1000, 0.1);
    lastTime = currentTime;

    if (gameState.optionsMenuUI?.isShown()) {
      renderer.clearBlack();
      gameState.optionsMenuUI.update(dt);
      gameState.optionsMenuUI.render();
    }

    pauseLoopId = requestAnimationFrame(pauseLoop);
  }

  pauseLoopId = requestAnimationFrame(pauseLoop);
}
