/**
 * UI Initialization
 *
 * Initializes all UI components with their callbacks.
 */

import type { Renderer } from '../../engine';
import type { InputManager } from '../../engine';
import type { AudioManager } from '../../engine';
import {
  MainMenuUI,
  OptionsMenuUI,
  PerkSelectUI,
  QuestMenuUI,
  PauseMenuUI,
  GameOverUI,
  TutorialUI,
  HighScoresUI,
  CreditsUI,
} from '../ui';
import { gameState } from './gameState';

export function initializeUI(renderer: Renderer, input: InputManager, audio: AudioManager): void {
  const settingsManager = gameState.settingsManager!;
  const progressionManager = gameState.progressionManager!;

  gameState.optionsMenuUI = new OptionsMenuUI({
    canvas: renderer.getCanvas(),
    getInitialConfig: () => settingsManager.getConfig(),
    onChangeConfig: (config) => {
      settingsManager.setConfig(config);
      settingsManager.applySettings(audio, renderer);
      input.handleResize();
    },
    onRequestBack: (context) => {
      gameState.optionsMenuUI?.hide();
      if (context === 'menu') {
        gameState.mainMenuUI?.show();
      } else {
        gameState.pauseMenuUI?.show(
          gameState.gameModeManager?.getStats() ?? { score: 0, kills: 0, timeElapsed: 0, level: 1 }
        );
      }
    },
  });

  gameState.mainMenuUI = new MainMenuUI({
    canvas: renderer.getCanvas(),
    onSelectMode: (mode) => {
      // Get engine instances from init context
      document.dispatchEvent(new CustomEvent('startGame', { detail: mode }));
    },
    onShowOptions: () => {
      gameState.mainMenuUI?.hide();
      gameState.optionsMenuUI?.show('menu');
    },
    onShowCredits: () => {
      gameState.mainMenuUI?.hide();
      gameState.creditsUI?.show();
    },
    onShowHighScores: () => {
      gameState.mainMenuUI?.hide();
      gameState.highScoresUI?.show();
    },
  });

  gameState.highScoresUI = new HighScoresUI({
    canvas: renderer.getCanvas(),
    progressionManager,
    onBack: () => {
      gameState.highScoresUI?.hide();
      const { showMainMenu } = require('./menuLifecycle');
      showMainMenu();
    },
  });

  gameState.creditsUI = new CreditsUI({
    canvas: renderer.getCanvas(),
    onBack: () => {
      gameState.creditsUI?.hide();
      const { showMainMenu } = require('./menuLifecycle');
      showMainMenu();
    },
  });

  gameState.perkSelectUI = new PerkSelectUI({
    canvas: renderer.getCanvas(),
    onSelect: (perkId) => {
      const { handlePerkSelection } = require('./perkHandler');
      handlePerkSelection(perkId);
    },
  });

  gameState.questMenuUI = new QuestMenuUI({
    canvas: renderer.getCanvas(),
    progressionManager,
    onStartQuest: (questId) => {
      gameState.questMenuUI?.hide();
      gameState.questMode?.startQuest(questId);
      gameState.gameModeManager?.startGame({ type: 'QUEST', questId });
    },
    onBack: () => {
      gameState.questMenuUI?.hide();
      const { showMainMenu } = require('./menuLifecycle');
      showMainMenu();
    },
  });

  gameState.pauseMenuUI = new PauseMenuUI({
    canvas: renderer.getCanvas(),
    onResume: () => {
      const { resumeGame } = require('./gameLifecycle');
      resumeGame();
    },
    onRestart: () => {
      const { restartGame } = require('./gameLifecycle');
      restartGame();
    },
    onMainMenu: () => {
      const { returnToMainMenu } = require('./gameLifecycle');
      returnToMainMenu();
    },
    onShowOptions: () => {
      gameState.pauseMenuUI?.hide();
      gameState.optionsMenuUI?.show('pause');
    },
  });

  gameState.gameOverUI = new GameOverUI({
    canvas: renderer.getCanvas(),
    onNewRun: () => {
      const { restartGame } = require('./gameLifecycle');
      restartGame();
    },
    onMainMenu: () => {
      const { returnToMainMenu } = require('./gameLifecycle');
      returnToMainMenu();
    },
  });

  gameState.tutorialUI = new TutorialUI({
    canvas: renderer.getCanvas(),
    onRepeat: () => {
      document.dispatchEvent(new CustomEvent('startGame', { detail: { type: 'TUTORIAL' } }));
    },
    onPlay: () => {
      document.dispatchEvent(new CustomEvent('startGame', { detail: { type: 'SURVIVAL' } }));
    },
    onSkip: () => {
      const { returnToMainMenu } = require('./gameLifecycle');
      returnToMainMenu();
    },
  });
}
