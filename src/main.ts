/**
 * Crimsonland Remake - Main Entry Point
 *
 * Initializes the game engine, ECS systems, and starts the game loop.
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
} from './game/systems';
import { GameModeManager, SurvivalMode } from './game/modes';
import { PlayerFactory } from './game/entities';

const GAME_WIDTH = 1024;
const GAME_HEIGHT = 768;
const TARGET_UPS = 60;

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
  renderer.getCanvas().addEventListener('click', () => {
    audio.initialize().catch(console.error);
  }, { once: true });

  // Initialize ECS
  const entityManager = new EntityManager();
  const systemManager = new SystemManager();

  // Initialize game mode manager
  const gameModeManager = new GameModeManager({
    onStateChange: (newState, oldState) => {
      console.log(`Game state changed: ${oldState?.type} -> ${newState.type}`);
    },
    onGameOver: (stats) => {
      console.log('Game Over!', stats);
    },
  });

  // Initialize spawn system
  const spawnSystem = new SpawnSystem(entityManager, {
    mapWidth: 2048,
    mapHeight: 2048,
    spawnMargin: 100,
  });

  // Initialize survival mode
  const survivalMode = new SurvivalMode(
    entityManager,
    spawnSystem,
    {
      onWaveStart: (wave) => {
        console.log(`Wave ${wave} started!`);
      },
      onLevelUp: (level) => {
        console.log(`Level up! Now level ${level}`);
      },
    }
  );

  // Initialize game systems
  const inputSystem = new InputSystem(input);
  const movementSystem = new MovementSystem();
  const weaponSystem = new WeaponSystem(entityManager, audio);
  const aiSystem = new AiSystem(entityManager);
  const projectileSystem = new ProjectileSystem(entityManager);
  const collisionSystem = new CollisionSystem(entityManager);
  const healthSystem = new HealthSystem(entityManager, {
    onPlayerDeath: () => {
      gameModeManager.gameOver();
    },
    onCreatureDeath: (_creatureTypeId, _position) => {
      spawnSystem.onEnemyDefeated();
    },
    onScoreChange: (score) => {
      gameModeManager.updateStats({ score });
    },
    onXPChange: (xp) => {
      survivalMode.addXP(xp);
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
  systemManager.addSystem(lifetimeSystem);
  systemManager.addSystem(renderSystem);

  // Create player entity
  PlayerFactory.create(entityManager, 0, 0, {
    playerIndex: 0,
    weaponId: 0, // Pistol
  });

  // Set camera to player position
  renderSystem.setCameraPosition(0, 0);

  // Start survival mode
  survivalMode.start();
  gameModeManager.startGame({ type: 'SURVIVAL' });

  // Game loop
  const gameLoop = new GameLoop(entityManager, systemManager, () => {
    // Render callback - RenderSystem handles rendering
  }, {
    targetUps: TARGET_UPS,
    pauseOnBlur: true,
  });

  // Handle pause/resume
  window.addEventListener('keydown', (e) => {
    if (e.code === 'Escape') {
      if (gameModeManager.isPlaying()) {
        gameModeManager.pause();
        gameLoop.stop();
      } else if (gameModeManager.isPaused()) {
        gameModeManager.resume();
        gameLoop.start();
      }
    }
  });

  // Start the game
  gameLoop.start();

  // Cleanup on unload
  window.addEventListener('beforeunload', () => {
    gameLoop.destroy();
    input.destroy();
    audio.destroy();
    systemManager.clear();
    entityManager.clear();
  });

  console.log('Crimsonland Remake initialized');
  console.log('Controls:');
  console.log('  WASD - Move');
  console.log('  Mouse - Aim');
  console.log('  Left Click - Fire');
  console.log('  R - Reload');
  console.log('  Escape - Pause');
}

// Start when DOM is ready
if (document.readyState === 'loading') {
  document.addEventListener('DOMContentLoaded', init);
} else {
  init().catch(console.error);
}
