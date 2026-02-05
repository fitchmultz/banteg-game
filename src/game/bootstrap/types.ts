/**
 * Bootstrap Types
 *
 * Core types and interfaces for game initialization.
 */

import type { GameLoop } from '../../core/GameLoop';
import type { GameModeManager } from '../modes';
import type { SurvivalMode, QuestMode, RushMode, TutorialMode } from '../modes';
import type { PerkSystem, RenderSystem, SpawnSystem, RushSpawnSystem } from '../systems';
import type { ProgressionManager } from '../progression';
import type { SettingsManager } from '../settings/SettingsManager';
import type {
  MainMenuUI,
  PerkSelectUI,
  QuestMenuUI,
  PauseMenuUI,
  GameOverUI,
  TutorialUI,
  OptionsMenuUI,
  HighScoresUI,
  CreditsUI,
} from '../ui';
import type { GameState } from '../../types';

export type AppState =
  | { type: 'MENU' }
  | { type: 'PLAYING'; gameLoop: GameLoop }
  | { type: 'PAUSED'; gameLoop: GameLoop }
  | { type: 'GAME_OVER'; isVictory: boolean };

export interface GlobalGameState {
  appState: AppState;
  gameModeManager: GameModeManager | null;
  survivalMode: SurvivalMode | null;
  questMode: QuestMode | null;
  rushMode: RushMode | null;
  tutorialMode: TutorialMode | null;
  perkSystem: PerkSystem | null;
  progressionManager: ProgressionManager | null;
  mainMenuUI: MainMenuUI | null;
  perkSelectUI: PerkSelectUI | null;
  questMenuUI: QuestMenuUI | null;
  pauseMenuUI: PauseMenuUI | null;
  gameOverUI: GameOverUI | null;
  tutorialUI: TutorialUI | null;
  optionsMenuUI: OptionsMenuUI | null;
  highScoresUI: HighScoresUI | null;
  creditsUI: CreditsUI | null;
  settingsManager: SettingsManager | null;
  currentGameState: GameState | null;
  playerEntityId: number | null;
  playerEntityIds: number[];
  renderSystem: RenderSystem | null;
  spawnSystem: SpawnSystem | null;
  rushSpawnSystem: RushSpawnSystem | null;
  audioLoaded: boolean;
  console: import('../../console').Console | null;
}
