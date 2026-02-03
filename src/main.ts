/**
 * Crimsonland Remake - Main Entry Point
 *
 * Initializes the game engine, ECS systems, and manages game state.
 * Now with main menu, quest system, perks, and progression tracking.
 */

import { EntityManager, SystemManager } from './core/ecs';
import { GameLoop } from './core/GameLoop';
import { Renderer, InputManager, AudioManager } from './engine';
import {
  InputSystem,
  MovementSystem,
  WeaponSystem,
  AiSystem,
  ProjectileSystem,
  CollisionSystem,
  HealthSystem,
  SpawnSystem,
  BonusSystem,
  EffectSystem,
  LifetimeSystem,
  RenderSystem,
  PerkSystem,
} from './game/systems';
import { GameModeManager, SurvivalMode, QuestMode } from './game/modes';
import { PlayerFactory } from './game/entities';
import { ProgressionManager } from './game/progression';
import { PerkSelectUI, QuestMenuUI, MainMenuUI, PauseMenuUI, GameOverUI } from './game/ui';
import { type GameState, type GameMode, PerkId } from './types';

const GAME_WIDTH = 1024;
const GAME_HEIGHT = 768;
const TARGET_UPS = 60;

type AppState =
  | { type: 'MENU' }
  | { type: 'PLAYING'; gameLoop: GameLoop }
  | { type: 'PAUSED'; gameLoop: GameLoop }
  | { type: 'GAME_OVER'; isVictory: boolean };

// Global game state (for easy access from callbacks)
interface GlobalGameState {
  appState: AppState;
  gameModeManager: GameModeManager | null;
  survivalMode: SurvivalMode | null;
  questMode: QuestMode | null;
  perkSystem: PerkSystem | null;
  progressionManager: ProgressionManager | null;
  mainMenuUI: MainMenuUI | null;
  perkSelectUI: PerkSelectUI | null;
  questMenuUI: QuestMenuUI | null;
  pauseMenuUI: PauseMenuUI | null;
  gameOverUI: GameOverUI | null;
  currentGameState: GameState | null;
  playerEntityId: number | null;
  renderSystem: RenderSystem | null;
}

const gameState: GlobalGameState = {
  appState: { type: 'MENU' },
  gameModeManager: null,
  survivalMode: null,
  questMode: null,
  perkSystem: null,
  progressionManager: null,
  mainMenuUI: null,
  perkSelectUI: null,
  questMenuUI: null,
  pauseMenuUI: null,
  gameOverUI: null,
  currentGameState: null,
  playerEntityId: null,
  renderSystem: null,
};

// Core engine instances
let entityManager: EntityManager;
let systemManager: SystemManager;
let renderer: Renderer;
let input: InputManager;
let audio: AudioManager;

async function init(): Promise<void> {
  const container = document.getElementById('game-container');
  if (!container) {
    throw new Error('Game container not found');
  }

  // Initialize renderer
  renderer = new Renderer(container, {
    width: GAME_WIDTH,
    height: GAME_HEIGHT,
    smoothing: false,
  });

  // Initialize input manager
  input = new InputManager(renderer.getCanvas());

  // Enable touch controls if on touch device
  if (InputManager.isTouchDevice()) {
    input.enableTouchControls();
    console.log('Touch controls enabled');
  }

  // Initialize audio manager
  audio = new AudioManager({
    sfxVolume: 0.7,
    musicVolume: 0.5,
  });

  // Initialize audio on first click
  renderer.getCanvas().addEventListener(
    'click',
    () => {
      audio.initialize().catch(console.error);
    },
    { once: true }
  );

  // Initialize ECS
  entityManager = new EntityManager();
  systemManager = new SystemManager();

  // Initialize progression manager
  const progressionManager = new ProgressionManager({
    onQuestCompleted: (questId) => {
      console.log(`Quest completed: ${questId}`);
    },
    onNewSurvivalRecord: (record) => {
      console.log('New survival record:', record);
    },
    onMilestoneReached: (milestone) => {
      console.log(`Milestone reached: ${milestone}`);
    },
  });
  gameState.progressionManager = progressionManager;

  // Initialize game mode manager
  const gameModeManager = new GameModeManager({
    onStateChange: (newState, oldState) => {
      console.log(`Game state changed: ${oldState?.type} -> ${newState.type}`);
      gameState.currentGameState = newState;

      // Handle PERK_SELECT state
      if (newState.type === 'PERK_SELECT') {
        // Perk selection UI will be triggered by SurvivalMode
      } else if (newState.type === 'PLAYING') {
        // Hide perk selection UI if visible
        gameState.perkSelectUI?.hide();
      } else if (newState.type === 'GAME_OVER' || newState.type === 'VICTORY') {
        handleGameOver(newState.type === 'VICTORY', newState.stats);
      }
    },
    onGameOver: (stats) => {
      console.log('Game Over!', stats);
      gameState.survivalMode?.endRun();
    },
  });
  gameState.gameModeManager = gameModeManager;

  // Initialize survival mode with perk system
  const survivalMode = new SurvivalMode(
    entityManager,
    new SpawnSystem(entityManager, {
      mapWidth: 2048,
      mapHeight: 2048,
      spawnMargin: 100,
    }),
    {
      onWaveStart: (wave) => {
        console.log(`Wave ${wave} started!`);
      },
      onLevelUp: (level) => {
        console.log(`Level up! Now level ${level}`);
        // Perk choices will be generated when game starts
        gameState.perkSelectUI?.show([]);
      },
      onPerkSelectionStart: (choices) => {
        gameModeManager.setState({ type: 'PERK_SELECT', choices });
      },
      onPerkSelected: (_perkId) => {
        gameModeManager.setState({ type: 'PLAYING', mode: { type: 'SURVIVAL' } });
      },
      onXPChange: (_xp, _progress) => {
        // Could update XP bar UI here
      },
    },
    new PerkSystem(entityManager, {
      onPerkApplied: (_entityId, perkId, newRank) => {
        console.log(`Perk applied: ${PerkId[perkId]} (rank ${newRank})`);
      },
      onFatalLottery: (_entityId, survived, xpGained) => {
        console.log(`Fatal Lottery: survived=${survived}, xp=${xpGained}`);
        if (!survived && gameState.playerEntityId !== null) {
          gameModeManager.gameOver();
        }
      },
      onInfernalContract: (_entityId, levelsGained) => {
        console.log(`Infernal Contract: +${levelsGained} levels`);
      },
    }),
    progressionManager
  );
  gameState.survivalMode = survivalMode;
  // PerkSystem is available through survivalMode's callbacks
  // Access perk system through gameState - will be initialized on game start

  // Initialize quest mode with progression
  const questMode = new QuestMode(
    entityManager,
    {
      onQuestStart: (questId) => {
        console.log(`Quest started: ${questId}`);
      },
      onQuestComplete: (questId, stats) => {
        console.log(`Quest completed: ${questId}`, stats);
        handleGameOver(true, stats);
      },
      onQuestFail: (questId, stats) => {
        console.log(`Quest failed: ${questId}`, stats);
        handleGameOver(false, stats);
      },
      onObjectiveUpdate: (_objective, _current, _target) => {
        // Update objective UI
      },
    },
    progressionManager
  );
  gameState.questMode = questMode;

  // Initialize UI components
  gameState.mainMenuUI = new MainMenuUI({
    canvas: renderer.getCanvas(),
    onSelectMode: (mode) => startGame(mode),
    onShowOptions: () => {
      console.log('Options menu not implemented yet');
    },
    onShowCredits: () => {
      console.log('Credits not implemented yet');
    },
  });

  gameState.perkSelectUI = new PerkSelectUI({
    canvas: renderer.getCanvas(),
    onSelect: (perkId) => {
      const choices = gameState.perkSelectUI?.getChoices() ?? [];
      survivalMode.selectPerk(choices.indexOf(perkId));
      gameState.perkSelectUI?.hide();
      gameModeManager.setState({ type: 'PLAYING', mode: { type: 'SURVIVAL' } });
    },
  });

  gameState.questMenuUI = new QuestMenuUI({
    canvas: renderer.getCanvas(),
    progressionManager,
    onStartQuest: (questId) => {
      gameState.questMenuUI?.hide();
      questMode.startQuest(questId);
      gameModeManager.startGame({ type: 'QUEST', questId });
    },
    onBack: () => {
      gameState.questMenuUI?.hide();
      showMainMenu();
    },
  });

  gameState.pauseMenuUI = new PauseMenuUI({
    canvas: renderer.getCanvas(),
    onResume: resumeGame,
    onRestart: restartGame,
    onMainMenu: returnToMainMenu,
    onShowOptions: () => {
      console.log('Options menu not implemented yet');
    },
  });

  gameState.gameOverUI = new GameOverUI({
    canvas: renderer.getCanvas(),
    onNewRun: restartGame,
    onMainMenu: returnToMainMenu,
  });

  // Show main menu
  showMainMenu();

  // Start the menu loop
  startMenuLoop();

  // Cleanup on unload
  window.addEventListener('beforeunload', cleanup);

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

function showMainMenu(): void {
  gameState.appState = { type: 'MENU' };
  gameState.mainMenuUI?.show();
  gameState.pauseMenuUI?.hide();
  gameState.gameOverUI?.hide();
  gameState.perkSelectUI?.hide();
  gameState.questMenuUI?.hide();
}

function startMenuLoop(): void {
  let lastTime = performance.now();

  function menuLoop(currentTime: number): void {
    if (gameState.appState.type !== 'MENU') return;

    const dt = Math.min((currentTime - lastTime) / 1000, 0.1);
    lastTime = currentTime;

    // Clear screen
    renderer.clearBlack();

    // Update and render main menu
    gameState.mainMenuUI?.update(dt);
    gameState.mainMenuUI?.render();

    // Also render quest menu if visible
    if (gameState.questMenuUI?.isShown()) {
      gameState.questMenuUI?.render();
    }

    requestAnimationFrame(menuLoop);
  }

  requestAnimationFrame(menuLoop);
}

function startGame(mode: GameMode): void {
  // Hide all menus
  gameState.mainMenuUI?.hide();
  gameState.questMenuUI?.hide();
  gameState.gameOverUI?.hide();

  // Clear existing entities and systems
  systemManager.clear();
  entityManager.clear();

  // Initialize game systems
  const inputSystem = new InputSystem(input);
  const movementSystem = new MovementSystem();
  const weaponSystem = new WeaponSystem(entityManager, audio);
  const aiSystem = new AiSystem(entityManager);
  const projectileSystem = new ProjectileSystem(entityManager);
  const collisionSystem = new CollisionSystem(entityManager);
  const healthSystem = new HealthSystem(entityManager, {
    onPlayerDeath: () => {
      gameState.progressionManager?.recordDeath();
      gameState.gameModeManager?.gameOver();
    },
    onCreatureDeath: (creatureTypeId, position) => {
      // Screen shake on enemy death
      if (position && gameState.renderSystem) {
        const shakeIntensity = 2 + Math.random() * 3;
        gameState.renderSystem.shake(shakeIntensity, 0.1);

        // Particle effects
        const particleSystem = gameState.renderSystem.getParticleSystem();
        particleSystem.emitBloodSplatter(position.x, position.y, Math.random() * Math.PI * 2, 5);
      }

      new SpawnSystem(entityManager, {
        mapWidth: 2048,
        mapHeight: 2048,
        spawnMargin: 100,
      }).onEnemyDefeated();

      // Record kill in appropriate mode
      if (gameState.gameModeManager?.isPlaying()) {
        const state = gameState.gameModeManager.getState();
        if (state.type === 'PLAYING') {
          if (state.mode.type === 'SURVIVAL') {
            gameState.survivalMode?.recordKill(10);
          } else if (state.mode.type === 'QUEST') {
            gameState.questMode?.recordKill(creatureTypeId, 10);
          }
        }
      }

      // Track in progression
      if (creatureTypeId !== undefined) {
        gameState.progressionManager?.recordKill(creatureTypeId);
      }
    },
    onScoreChange: (score) => {
      gameState.gameModeManager?.updateStats({ score });
    },
    onXPChange: (xp) => {
      // Apply XP multiplier from perks
      const multiplier =
        gameState.playerEntityId !== null && gameState.perkSystem
          ? gameState.perkSystem.getXpMultiplier(gameState.playerEntityId)
          : 1;
      gameState.survivalMode?.addXP(Math.floor(xp * multiplier));
    },
  });
  const bonusSystem = new BonusSystem(entityManager);
  const effectSystem = new EffectSystem(entityManager);
  const lifetimeSystem = new LifetimeSystem(entityManager);
  const renderSystem = new RenderSystem(entityManager, renderer, input);
  gameState.renderSystem = renderSystem;

  // Create perk system for this game session
  const perkSystem = new PerkSystem(entityManager, {
    onPerkApplied: (_entityId, perkId, newRank) => {
      console.log(`Perk applied: ${PerkId[perkId]} (rank ${newRank})`);
      gameState.progressionManager?.recordPerkChosen(perkId);
    },
    onFatalLottery: (_entityId, survived, xpGained) => {
      console.log(`Fatal Lottery: survived=${survived}, xp=${xpGained}`);
      if (!survived && gameState.playerEntityId !== null) {
        gameState.gameModeManager?.gameOver();
      }
    },
    onInfernalContract: (_entityId, levelsGained) => {
      console.log(`Infernal Contract: +${levelsGained} levels`);
    },
  });
  gameState.perkSystem = perkSystem;

  // Add systems in priority order
  systemManager.addSystem(inputSystem);
  systemManager.addSystem(movementSystem);
  systemManager.addSystem(weaponSystem);
  systemManager.addSystem(aiSystem);
  systemManager.addSystem(projectileSystem);
  systemManager.addSystem(collisionSystem);
  systemManager.addSystem(healthSystem);
  systemManager.addSystem(new SpawnSystem(entityManager, {
    mapWidth: 2048,
    mapHeight: 2048,
    spawnMargin: 100,
  }));
  systemManager.addSystem(bonusSystem);
  systemManager.addSystem(effectSystem);
  systemManager.addSystem(perkSystem);
  systemManager.addSystem(lifetimeSystem);
  systemManager.addSystem(renderSystem);

  // Create player entity
  const playerEntity = PlayerFactory.create(entityManager, 0, 0, {
    playerIndex: 0,
    weaponId: 0, // Pistol
  });
  gameState.playerEntityId = playerEntity.id;
  gameState.survivalMode?.setPlayerEntity(playerEntity.id);

  // Set camera to player position
  renderSystem.setCameraPosition(0, 0);

  // Start the appropriate mode
  if (mode.type === 'SURVIVAL') {
    gameState.survivalMode?.start();
  } else if (mode.type === 'QUEST') {
    gameState.questMode?.startQuest(mode.questId);
  }

  gameState.gameModeManager?.startGame(mode);

  // Create game loop
  const gameLoop = new GameLoop(
    entityManager,
    systemManager,
    () => {
      // Render UI overlays
      if (gameState.perkSelectUI?.isShown()) {
        gameState.perkSelectUI?.render();
      }
    },
    {
      targetUps: TARGET_UPS,
      pauseOnBlur: true,
    }
  );

  gameState.appState = { type: 'PLAYING', gameLoop };
  gameLoop.start();

  // Start game music
  // audio.playTune('game', true);
}

function pauseGame(): void {
  if (gameState.appState.type !== 'PLAYING') return;

  const { gameLoop } = gameState.appState;
  gameLoop.stop();

  const stats = gameState.gameModeManager?.getStats() ?? {
    score: 0,
    kills: 0,
    timeElapsed: 0,
    level: 1,
  };

  gameState.pauseMenuUI?.show(stats);
  gameState.appState = { type: 'PAUSED', gameLoop };
}

function resumeGame(): void {
  if (gameState.appState.type !== 'PAUSED') return;

  const { gameLoop } = gameState.appState;
  gameState.pauseMenuUI?.hide();
  gameState.appState = { type: 'PLAYING', gameLoop };
  gameLoop.start();
}

function restartGame(): void {
  gameState.pauseMenuUI?.hide();
  gameState.gameOverUI?.hide();

  // Get current mode
  const currentState = gameState.gameModeManager?.getState();
  if (currentState?.type === 'PLAYING') {
    startGame(currentState.mode);
  } else {
    // Default to survival
    startGame({ type: 'SURVIVAL' });
  }
}

function returnToMainMenu(): void {
  // Stop any running game loop
  if (gameState.appState.type === 'PLAYING' || gameState.appState.type === 'PAUSED') {
    gameState.appState.gameLoop.destroy();
  }

  gameState.pauseMenuUI?.hide();
  gameState.gameOverUI?.hide();
  gameState.gameModeManager?.returnToMenu();

  showMainMenu();
  startMenuLoop();
}

function handleGameOver(isVictory: boolean, stats: { score: number; kills: number; timeElapsed: number; level: number }): void {
  if (gameState.appState.type === 'PLAYING') {
    gameState.appState.gameLoop.stop();
  }

  // Get best score for comparison
  const survivalRecord = gameState.progressionManager?.getSurvivalHighScore();
  const bestScore = survivalRecord && survivalRecord.bestScore > 0 ? survivalRecord.bestScore : undefined;

  gameState.gameOverUI?.show({
    ...stats,
    isVictory,
    ...(bestScore !== undefined && { bestScore }),
  });

  gameState.appState = { type: 'GAME_OVER', isVictory };
}

function cleanup(): void {
  // Save progression
  gameState.progressionManager?.save();

  // Cleanup all systems
  if (gameState.appState.type === 'PLAYING' || gameState.appState.type === 'PAUSED') {
    gameState.appState.gameLoop.destroy();
  }

  input.destroy();
  audio.destroy();
  gameState.mainMenuUI?.destroy();
  gameState.perkSelectUI?.destroy();
  gameState.questMenuUI?.destroy();
  gameState.pauseMenuUI?.destroy();
  gameState.gameOverUI?.destroy();
  systemManager.clear();
  entityManager.clear();
}

// Handle keyboard input
document.addEventListener('keydown', (e) => {
  // Toggle FPS counter with F3
  if (e.code === 'F3') {
    gameState.renderSystem?.toggleFps();
    return;
  }

  // Handle pause
  if (e.code === 'Escape') {
    if (gameState.appState.type === 'PLAYING') {
      if (!gameState.perkSelectUI?.isShown()) {
        pauseGame();
      }
    } else if (gameState.appState.type === 'PAUSED') {
      resumeGame();
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
});

// Periodic save (every 30 seconds)
setInterval(() => {
  gameState.progressionManager?.save();
}, 30000);

// Start when DOM is ready
if (document.readyState === 'loading') {
  document.addEventListener('DOMContentLoaded', init);
} else {
  init().catch(console.error);
}
