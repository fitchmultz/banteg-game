/**
 * Crimsonland Remake - Main Entry Point
 *
 * Initializes the game engine, ECS systems, and starts the game loop.
 * Now with quest system, perks, and progression tracking.
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
import { PerkSelectUI, QuestMenuUI } from './game/ui';
import { type GameState, PerkId } from './types';

const GAME_WIDTH = 1024;
const GAME_HEIGHT = 768;
const TARGET_UPS = 60;

// Global game state (for easy access from callbacks)
const gameState: {
  gameModeManager: GameModeManager | null;
  survivalMode: SurvivalMode | null;
  questMode: QuestMode | null;
  perkSystem: PerkSystem | null;
  progressionManager: ProgressionManager | null;
  perkSelectUI: PerkSelectUI | null;
  questMenuUI: QuestMenuUI | null;
  currentState: GameState | null;
  playerEntityId: number | null;
} = {
  gameModeManager: null,
  survivalMode: null,
  questMode: null,
  perkSystem: null,
  progressionManager: null,
  perkSelectUI: null,
  questMenuUI: null,
  currentState: null,
  playerEntityId: null,
};

async function init(): Promise<void> {
  const container = document.getElementById('game-container');
  if (!container) {
    throw new Error('Game container not found');
  }

  // Initialize renderer
  const renderer = new Renderer(container, {
    width: GAME_WIDTH,
    height: GAME_HEIGHT,
    smoothing: false,
  });

  // Initialize input manager
  const input = new InputManager(renderer.getCanvas());

  // Initialize audio manager
  const audio = new AudioManager({
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
  const entityManager = new EntityManager();
  const systemManager = new SystemManager();

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
      gameState.currentState = newState;

      // Handle PERK_SELECT state
      if (newState.type === 'PERK_SELECT') {
        // Perk selection UI will be triggered by SurvivalMode
      } else if (newState.type === 'PLAYING') {
        // Hide perk selection UI if visible
        gameState.perkSelectUI?.hide();
      }
    },
    onGameOver: (stats) => {
      console.log('Game Over!', stats);
      // Record survival run if in survival mode
      gameState.survivalMode?.endRun();
    },
  });
  gameState.gameModeManager = gameModeManager;

  // Initialize spawn system
  const spawnSystem = new SpawnSystem(entityManager, {
    mapWidth: 2048,
    mapHeight: 2048,
    spawnMargin: 100,
  });

  // Initialize perk system
  const perkSystem = new PerkSystem(entityManager, {
    onPerkApplied: (_entityId, perkId, newRank) => {
      console.log(`Perk applied: ${PerkId[perkId]} (rank ${newRank})`);
    },
    onFatalLottery: (_entityId, survived, xpGained) => {
      console.log(`Fatal Lottery: survived=${survived}, xp=${xpGained}`);
      if (!survived && gameState.playerEntityId !== null) {
        // Player died from fatal lottery
        gameModeManager.gameOver();
      }
    },
    onInfernalContract: (_entityId, levelsGained) => {
      console.log(`Infernal Contract: +${levelsGained} levels`);
    },
  });
  gameState.perkSystem = perkSystem;

  // Initialize survival mode with perk system
  const survivalMode = new SurvivalMode(
    entityManager,
    spawnSystem,
    {
      onWaveStart: (wave) => {
        console.log(`Wave ${wave} started!`);
      },
      onLevelUp: (level) => {
        console.log(`Level up! Now level ${level}`);
        // Start perk selection
        gameState.perkSelectUI?.show(
          perkSystem.generatePerkChoices(gameState.playerEntityId ?? 0, 3)
        );
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
    perkSystem,
    progressionManager
  );
  gameState.survivalMode = survivalMode;

  // Initialize quest mode with progression
  const questMode = new QuestMode(
    entityManager,
    {
      onQuestStart: (questId) => {
        console.log(`Quest started: ${questId}`);
      },
      onQuestComplete: (questId, stats) => {
        console.log(`Quest completed: ${questId}`, stats);
        // Return to menu or start next quest
      },
      onQuestFail: (questId, stats) => {
        console.log(`Quest failed: ${questId}`, stats);
      },
      onObjectiveUpdate: (_objective, _current, _target) => {
        // Update objective UI
      },
    },
    progressionManager
  );
  gameState.questMode = questMode;

  // Initialize game systems
  const inputSystem = new InputSystem(input);
  const movementSystem = new MovementSystem();
  const weaponSystem = new WeaponSystem(entityManager, audio);
  const aiSystem = new AiSystem(entityManager);
  const projectileSystem = new ProjectileSystem(entityManager);
  const collisionSystem = new CollisionSystem(entityManager);
  const healthSystem = new HealthSystem(entityManager, {
    onPlayerDeath: () => {
      progressionManager.recordDeath();
      gameModeManager.gameOver();
    },
    onCreatureDeath: (creatureTypeId, _position) => {
      spawnSystem.onEnemyDefeated();

      // Record kill in appropriate mode
      if (gameModeManager.isPlaying()) {
        const state = gameModeManager.getState();
        if (state.type === 'PLAYING') {
          if (state.mode.type === 'SURVIVAL') {
            survivalMode.recordKill(10);
          } else if (state.mode.type === 'QUEST') {
            questMode.recordKill(creatureTypeId, 10);
          }
        }
      }

      // Track in progression
      if (creatureTypeId !== undefined) {
        progressionManager.recordKill(creatureTypeId);
      }
    },
    onScoreChange: (score) => {
      gameModeManager.updateStats({ score });
    },
    onXPChange: (xp) => {
      // Apply XP multiplier from perks
      const multiplier =
        gameState.playerEntityId !== null
          ? perkSystem.getXpMultiplier(gameState.playerEntityId)
          : 1;
      survivalMode.addXP(Math.floor(xp * multiplier));
    },
  });
  const bonusSystem = new BonusSystem(entityManager);
  const effectSystem = new EffectSystem(entityManager);
  const lifetimeSystem = new LifetimeSystem(entityManager);
  const renderSystem = new RenderSystem(entityManager, renderer);

  // Add systems in priority order
  systemManager.addSystem(inputSystem);
  systemManager.addSystem(movementSystem);
  systemManager.addSystem(weaponSystem);
  systemManager.addSystem(aiSystem);
  systemManager.addSystem(projectileSystem);
  systemManager.addSystem(collisionSystem);
  systemManager.addSystem(healthSystem);
  systemManager.addSystem(spawnSystem);
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
  survivalMode.setPlayerEntity(playerEntity.id);

  // Set camera to player position
  renderSystem.setCameraPosition(0, 0);

  // Initialize UI components
  const perkSelectUI = new PerkSelectUI({
    canvas: renderer.getCanvas(),
    onSelect: (perkId) => {
      survivalMode.selectPerk(perkSelectUI.getChoices().indexOf(perkId));
      perkSelectUI.hide();
      gameModeManager.setState({ type: 'PLAYING', mode: { type: 'SURVIVAL' } });
    },
  });
  gameState.perkSelectUI = perkSelectUI;

  const questMenuUI = new QuestMenuUI({
    canvas: renderer.getCanvas(),
    progressionManager,
    onStartQuest: (questId) => {
      questMenuUI.hide();
      questMode.startQuest(questId);
      gameModeManager.startGame({ type: 'QUEST', questId });
    },
    onBack: () => {
      questMenuUI.hide();
      // Return to main menu
    },
  });
  gameState.questMenuUI = questMenuUI;

  // Start survival mode by default
  survivalMode.start();
  gameModeManager.startGame({ type: 'SURVIVAL' });

  // Game loop
  const gameLoop = new GameLoop(
    entityManager,
    systemManager,
    () => {
      // Render UI overlays
      if (gameState.perkSelectUI?.isShown()) {
        gameState.perkSelectUI.render();
      }
      if (gameState.questMenuUI?.isShown()) {
        gameState.questMenuUI.render();
      }
    },
    {
      targetUps: TARGET_UPS,
      pauseOnBlur: true,
    }
  );

  // Handle pause/resume
  window.addEventListener('keydown', (e) => {
    if (e.code === 'Escape') {
      if (perkSelectUI.isShown()) {
        // Don't allow escape during perk selection
        return;
      }

      if (gameModeManager.isPlaying()) {
        gameModeManager.pause();
        gameLoop.stop();
      } else if (gameModeManager.isPaused()) {
        gameModeManager.resume();
        gameLoop.start();
      }
    }

    // Quest menu hotkey
    if (e.code === 'KeyQ' && !gameModeManager.isPlaying()) {
      questMenuUI.show();
    }
  });

  // Start the game
  gameLoop.start();

  // Cleanup on unload
  window.addEventListener('beforeunload', () => {
    // Save progression
    progressionManager.save();

    // Cleanup
    gameLoop.destroy();
    input.destroy();
    audio.destroy();
    perkSelectUI.destroy();
    questMenuUI.destroy();
    systemManager.clear();
    entityManager.clear();
  });

  // Periodic save (every 30 seconds)
  setInterval(() => {
    progressionManager.save();
  }, 30000);

  console.log('Crimsonland Remake initialized');
  console.log('Controls:');
  console.log('  WASD - Move');
  console.log('  Mouse - Aim');
  console.log('  Left Click - Fire');
  console.log('  R - Reload');
  console.log('  Escape - Pause');
  console.log('  Q - Quest Menu (when not playing)');

  // Expose game state for debugging
  (window as unknown as Record<string, unknown>).gameState = gameState;
}

// Start when DOM is ready
if (document.readyState === 'loading') {
  document.addEventListener('DOMContentLoaded', init);
} else {
  init().catch(console.error);
}
