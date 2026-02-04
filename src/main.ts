/**
 * Crimsonland Remake - Main Entry Point
 *
 * Initializes the game engine, ECS systems, and manages game state.
 * Now with main menu, quest system, perks, progression tracking,
 * RUSH mode, and TUTORIAL mode.
 */

import { GameLoop } from './core/GameLoop';
import { type Entity, EntityManager, SystemManager } from './core/ecs';
import {
  AssetManager,
  AudioManager,
  InputManager,
  Renderer,
  SpriteAtlas,
  generateSpriteAtlas,
} from './engine';
import { TerrainGenerator } from './engine/TerrainGenerator';
import { TUNES, getDeathSample, loadGameAudio } from './game/audio';
import { getUnlockedWeapons } from './game/data';
import { BonusFactory, PlayerFactory } from './game/entities';
import { CreatureFactory } from './game/entities';
import { GameModeManager, QuestMode, RushMode, SurvivalMode, TutorialMode } from './game/modes';
import { ProgressionManager } from './game/progression';
import { SettingsManager } from './game/settings/SettingsManager';
import {
  AiSystem,
  BonusSystem,
  CollisionSystem,
  EffectSystem,
  GameAudioSystem,
  GameModeSystem,
  HealthSystem,
  InputSystem,
  LifetimeSystem,
  MovementSystem,
  PerkSystem,
  ProjectileSystem,
  RenderSystem,
  RushSpawnSystem,
  SpawnSystem,
  WeaponPickupSystem,
  WeaponSystem,
} from './game/systems';
import {
  GameOverUI,
  MainMenuUI,
  OptionsMenuUI,
  PauseMenuUI,
  PerkSelectUI,
  QuestMenuUI,
  TutorialUI,
} from './game/ui';
import { type GameMode, type GameState, PerkId } from './types';

// Default game dimensions (will be overridden by settings)
let GAME_WIDTH = 1024;
let GAME_HEIGHT = 768;
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
  settingsManager: SettingsManager | null;
  currentGameState: GameState | null;
  playerEntityId: number | null; // P1 entity ID (for backward compatibility)
  playerEntityIds: number[]; // All player entity IDs (for co-op)
  renderSystem: RenderSystem | null;
  // Spawn systems (single source of truth)
  spawnSystem: SpawnSystem | null;
  rushSpawnSystem: RushSpawnSystem | null;
  // Audio loaded flag
  audioLoaded: boolean;
}

const gameState: GlobalGameState = {
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
  settingsManager: null,
  currentGameState: null,
  playerEntityId: null,
  playerEntityIds: [],
  renderSystem: null,
  spawnSystem: null,
  rushSpawnSystem: null,
  audioLoaded: false,
};

// Core engine instances
let entityManager: EntityManager;
let systemManager: SystemManager;
let renderer: Renderer;
let input: InputManager;
let audio: AudioManager;
let assetManager: AssetManager;
let spriteAtlas: SpriteAtlas;

async function init(): Promise<void> {
  const container = document.getElementById('game-container');
  if (!container) {
    throw new Error('Game container not found');
  }

  // Initialize settings manager first (loads from localStorage)
  const settingsManager = new SettingsManager();
  gameState.settingsManager = settingsManager;

  // Apply settings to game dimensions
  const settings = settingsManager.getConfig();
  GAME_WIDTH = settings.resolution.width;
  GAME_HEIGHT = settings.resolution.height;

  // Initialize renderer with settings resolution
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

  // Initialize audio manager with settings volumes
  audio = new AudioManager({
    sfxVolume: settings.sfxVolume,
    musicVolume: settings.musicVolume,
  });

  // Initialize asset manager for sprite loading
  assetManager = new AssetManager({
    basePath: '',
  });

  // Initialize sprite atlas for creature animations
  spriteAtlas = new SpriteAtlas();

  // Generate and load creature sprites
  const { image: spriteCanvas, data: atlasData } = generateSpriteAtlas();
  spriteAtlas.loadFromData(atlasData);

  // Convert canvas to blob and create object URL for AssetManager
  const spriteBlob = await new Promise<Blob | null>((resolve) => {
    spriteCanvas.toBlob(resolve, 'image/png');
  });

  if (spriteBlob) {
    const spriteUrl = URL.createObjectURL(spriteBlob);
    await assetManager.loadImage('creatures', spriteUrl);
    console.log('Creature sprites loaded successfully');
  } else {
    console.warn('Failed to generate creature sprites, falling back to colored circles');
  }

  // Initialize audio and load assets on first user gesture
  renderer.getCanvas().addEventListener(
    'click',
    async () => {
      try {
        await audio.initialize();
        const result = await loadGameAudio(audio);
        gameState.audioLoaded = result.success;
      } catch (error) {
        console.error('Failed to initialize audio:', error);
        gameState.audioLoaded = false;
      }
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
        // Perk selection UI will be triggered by the active mode
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
      gameState.rushMode?.endRun();
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
        if (!survived) {
          // In co-op, only game over when all players are dead
          const currentMode = gameModeManager.getState();
          const isCoopMode =
            currentMode.type === 'PLAYING' && currentMode.mode.type === 'COOP_SURVIVAL';
          if (isCoopMode) {
            const alivePlayers = gameState.playerEntityIds.filter((id) => {
              const entity = entityManager.getEntity(id);
              if (!entity) return false;
              const player = entity.getComponent<'player'>('player');
              return player && player.health > 0;
            });
            if (alivePlayers.length === 0) {
              gameModeManager.gameOver();
            }
          } else {
            gameModeManager.gameOver();
          }
        }
      },
      onInfernalContract: (_entityId, levelsGained) => {
        console.log(`Infernal Contract: +${levelsGained} levels`);
      },
    }),
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

  // Initialize rush mode
  const rushMode = new RushMode(
    entityManager,
    {
      onStart: () => {
        console.log('Rush mode started!');
      },
      onGameOver: (stats) => {
        console.log('Rush mode ended!', stats);
      },
      onSpawn: (creatureTypeId, x, y) => {
        gameState.rushSpawnSystem?.queueSpawn(creatureTypeId, x, y);
      },
    },
    progressionManager
  );
  gameState.rushMode = rushMode;

  // Initialize tutorial mode
  const tutorialMode = new TutorialMode(
    entityManager,
    {
      onStageChange: (stage, previousStage) => {
        console.log(`Tutorial stage: ${previousStage} -> ${stage}`);
        const prompt = tutorialMode.getStagePrompt(stage);
        const name = tutorialMode.getStageName(stage);
        gameState.tutorialUI?.setStage(stage, prompt, name);
      },
      onComplete: (stats) => {
        console.log('Tutorial completed!', stats);
        handleGameOver(true, stats);
      },
      onRequestPerkSelection: () => {
        const primaryPlayerId = gameState.playerEntityIds[0] ?? 0;
        const choices = gameState.perkSystem?.generatePerkChoices(primaryPlayerId, 3) ?? [];
        gameState.perkSelectUI?.show(choices);
        gameModeManager.setState({ type: 'PERK_SELECT', choices });
      },
      onSpawnBonuses: (bonuses) => {
        for (const bonus of bonuses) {
          const options = bonus.value !== undefined ? { value: bonus.value } : undefined;
          BonusFactory.create(entityManager, bonus.type, bonus.x, bonus.y, options);
        }
      },
      onSpawnEnemies: (enemies) => {
        for (const enemy of enemies) {
          CreatureFactory.create(entityManager, enemy.creatureTypeId, enemy.x, enemy.y);
        }
      },
    },
    progressionManager
  );
  gameState.tutorialMode = tutorialMode;

  // Initialize UI components
  gameState.optionsMenuUI = new OptionsMenuUI({
    canvas: renderer.getCanvas(),
    getInitialConfig: () => settingsManager.getConfig(),
    onChangeConfig: (config) => {
      // Update settings and apply them
      settingsManager.setConfig(config);
      settingsManager.applySettings(audio, renderer);
      // Update touch controls layout if needed
      input.handleResize();
    },
    onRequestBack: (context) => {
      gameState.optionsMenuUI?.hide();
      if (context === 'menu') {
        gameState.mainMenuUI?.show();
      } else {
        gameState.pauseMenuUI?.show(
          gameState.gameModeManager?.getStats() ?? {
            score: 0,
            kills: 0,
            timeElapsed: 0,
            level: 1,
          }
        );
      }
    },
  });

  gameState.mainMenuUI = new MainMenuUI({
    canvas: renderer.getCanvas(),
    onSelectMode: (mode) => startGame(mode),
    onShowOptions: () => {
      gameState.mainMenuUI?.hide();
      gameState.optionsMenuUI?.show('menu');
    },
    onShowCredits: () => {
      console.log('Credits not implemented yet');
    },
  });

  gameState.perkSelectUI = new PerkSelectUI({
    canvas: renderer.getCanvas(),
    onSelect: (perkId) => {
      handlePerkSelection(perkId);
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
      gameState.pauseMenuUI?.hide();
      gameState.optionsMenuUI?.show('pause');
    },
  });

  gameState.gameOverUI = new GameOverUI({
    canvas: renderer.getCanvas(),
    onNewRun: restartGame,
    onMainMenu: returnToMainMenu,
  });

  gameState.tutorialUI = new TutorialUI({
    canvas: renderer.getCanvas(),
    onRepeat: () => {
      startGame({ type: 'TUTORIAL' });
    },
    onPlay: () => {
      startGame({ type: 'SURVIVAL' });
    },
    onSkip: () => {
      returnToMainMenu();
    },
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

function handlePerkSelection(perkId: PerkId): void {
  const currentState = gameState.gameModeManager?.getState();
  if (currentState?.type !== 'PERK_SELECT') return;

  // Get the mode from the previous state (before PERK_SELECT)
  const previousState = gameState.gameModeManager?.getPreviousState();
  let mode: GameMode = { type: 'SURVIVAL' };

  if (previousState?.type === 'PLAYING') {
    mode = previousState.mode;
  }

  // Route perk selection to the correct mode
  switch (mode.type) {
    case 'SURVIVAL':
    case 'COOP_SURVIVAL': {
      const choices = gameState.perkSelectUI?.getChoices() ?? [];
      const success = gameState.survivalMode?.selectPerk(choices.indexOf(perkId));
      if (success) {
        gameState.perkSelectUI?.hide();
        gameState.gameModeManager?.setState({ type: 'PLAYING', mode });
      }
      break;
    }
    case 'TUTORIAL': {
      // Apply perk directly via perk system
      const primaryPlayerId = gameState.playerEntityIds[0];
      if (primaryPlayerId !== undefined && gameState.perkSystem) {
        const success = gameState.perkSystem.applyPerk(primaryPlayerId, perkId);
        if (success) {
          gameState.tutorialMode?.onPerkSelected();
          gameState.perkSelectUI?.hide();
          gameState.gameModeManager?.setState({ type: 'PLAYING', mode: { type: 'TUTORIAL' } });
        }
      }
      break;
    }
    default:
      // Other modes don't have perks
      gameState.perkSelectUI?.hide();
      gameState.gameModeManager?.setState({ type: 'PLAYING', mode });
      break;
  }
}

function showMainMenu(): void {
  gameState.appState = { type: 'MENU' };
  gameState.mainMenuUI?.show();
  gameState.pauseMenuUI?.hide();
  gameState.gameOverUI?.hide();
  gameState.perkSelectUI?.hide();
  gameState.questMenuUI?.hide();
  gameState.tutorialUI?.hide();
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
  gameState.tutorialUI?.hide();

  // Clear existing entities and systems
  systemManager.clear();
  entityManager.clear();

  // Reset spawn system references
  gameState.spawnSystem = null;
  gameState.rushSpawnSystem = null;

  // Initialize game systems
  const inputSystem = new InputSystem(
    input,
    (playerIndex: number) =>
      gameState.settingsManager?.getKeyBindingsForPlayer(playerIndex) ?? {
        moveUp: 'KeyW',
        moveDown: 'KeyS',
        moveLeft: 'KeyA',
        moveRight: 'KeyD',
        fire: 'MouseLeft',
        reload: 'KeyR',
        swapWeapon: 'KeyQ',
        pause: 'Escape',
      }
  );
  const movementSystem = new MovementSystem();
  const weaponSystem = new WeaponSystem(entityManager, audio);
  const aiSystem = new AiSystem(entityManager);
  const projectileSystem = new ProjectileSystem(entityManager);
  const collisionSystem = new CollisionSystem(entityManager);
  const gameAudioSystem = new GameAudioSystem(entityManager, audio);

  // Determine which mode we're starting
  const isSurvival = mode.type === 'SURVIVAL' || mode.type === 'COOP_SURVIVAL';
  const isCoop = mode.type === 'COOP_SURVIVAL';
  const isRush = mode.type === 'RUSH';

  // Create spawn systems based on mode
  if (isSurvival) {
    gameState.spawnSystem = new SpawnSystem(entityManager, {
      mapWidth: 2048,
      mapHeight: 2048,
      spawnMargin: 100,
    });
  } else if (isRush) {
    gameState.rushSpawnSystem = new RushSpawnSystem(entityManager, {
      mapWidth: 2048,
      mapHeight: 2048,
    });
  }

  const healthSystem = new HealthSystem(entityManager, {
    onPlayerDeath: (_entityId: number) => {
      // Play player death sound
      if (gameState.audioLoaded) {
        audio.playSample(getDeathSample({ isPlayer: true }));
      }
      gameState.progressionManager?.recordDeath();

      // In co-op mode, only game over when all players are dead
      if (isCoop) {
        const alivePlayers = gameState.playerEntityIds.filter((id) => {
          const entity = entityManager.getEntity(id);
          if (!entity) return false;
          const player = entity.getComponent<'player'>('player');
          return player && player.health > 0;
        });
        if (alivePlayers.length === 0) {
          gameState.gameModeManager?.gameOver();
        }
      } else {
        gameState.gameModeManager?.gameOver();
      }
    },
    onCreatureDeath: (creatureTypeId, position) => {
      // Play enemy death sound
      if (gameState.audioLoaded) {
        audio.playSample(getDeathSample({ isPlayer: false, creatureTypeId }));
      }
      // Screen shake on enemy death
      if (position && gameState.renderSystem) {
        const shakeIntensity = 2 + Math.random() * 3;
        gameState.renderSystem.shake(shakeIntensity, 0.1);

        // Particle effects
        const particleSystem = gameState.renderSystem.getParticleSystem();
        particleSystem.emitBloodSplatter(position.x, position.y, Math.random() * Math.PI * 2, 5);

        // Chance to spawn weapon pickup (10% chance)
        // In co-op, use the first alive player for weapon unlocks
        const alivePlayerId = gameState.playerEntityIds.find((id) => {
          const entity = entityManager.getEntity(id);
          if (!entity) return false;
          const player = entity.getComponent<'player'>('player');
          return player && player.health > 0;
        });
        if (Math.random() < 0.1 && alivePlayerId !== undefined) {
          const player = entityManager.getEntity(alivePlayerId);
          if (player) {
            const playerComp = player.getComponent<'player'>('player');
            if (playerComp) {
              // Get unlocked weapons based on player XP
              const unlockedWeapons = getUnlockedWeapons(playerComp.experience);
              // Filter out current and alternate weapons
              const availableWeapons = unlockedWeapons.filter(
                (id) =>
                  id !== playerComp.currentWeapon.weaponId &&
                  id !== playerComp.alternateWeapon.weaponId
              );
              if (availableWeapons.length > 0) {
                // Pick random weapon
                const randomIndex = Math.floor(Math.random() * availableWeapons.length);
                const randomWeapon = availableWeapons[randomIndex];
                if (randomWeapon !== undefined) {
                  BonusFactory.createWeaponPickup(
                    entityManager,
                    randomWeapon,
                    position.x,
                    position.y
                  );
                }
              }
            }
          }
        }
      }

      // Route onEnemyDefeated to the active spawn system
      if (isSurvival) {
        gameState.spawnSystem?.onEnemyDefeated();
      } else if (isRush) {
        gameState.rushSpawnSystem?.onEnemyDefeated();
      }

      // Record kill in appropriate mode
      if (gameState.gameModeManager?.isPlaying()) {
        const state = gameState.gameModeManager.getState();
        if (state.type === 'PLAYING') {
          switch (state.mode.type) {
            case 'SURVIVAL':
            case 'COOP_SURVIVAL':
              gameState.survivalMode?.recordKill(10);
              break;
            case 'QUEST':
              gameState.questMode?.recordKill(creatureTypeId, 10);
              break;
            case 'RUSH':
              gameState.rushMode?.recordKill(10);
              break;
            case 'TUTORIAL':
              gameState.tutorialMode?.recordKill();
              break;
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
      // Use first alive player for multiplier (in co-op, both share perks anyway)
      const alivePlayerId = gameState.playerEntityIds.find((id) => {
        const entity = entityManager.getEntity(id);
        if (!entity) return false;
        const player = entity.getComponent<'player'>('player');
        return player && player.health > 0;
      });
      const multiplier =
        alivePlayerId !== undefined && gameState.perkSystem
          ? gameState.perkSystem.getXpMultiplier(alivePlayerId)
          : 1;

      const adjustedXP = Math.floor(xp * multiplier);

      // Route XP to the active mode
      const state = gameState.gameModeManager?.getState();
      if (state?.type === 'PLAYING') {
        switch (state.mode.type) {
          case 'SURVIVAL':
          case 'COOP_SURVIVAL':
            gameState.survivalMode?.addXP(adjustedXP);
            break;
          case 'RUSH':
            gameState.rushMode?.addScore(adjustedXP);
            break;
          case 'TUTORIAL':
            // Tutorial has its own XP management
            break;
        }
      }
    },
  });

  const bonusSystem = new BonusSystem(entityManager);
  const weaponPickupSystem = new WeaponPickupSystem(entityManager);
  const effectSystem = new EffectSystem(entityManager);
  const lifetimeSystem = new LifetimeSystem(entityManager);
  const renderSystem = new RenderSystem(entityManager, renderer, assetManager, spriteAtlas, input);
  gameState.renderSystem = renderSystem;

  // Generate terrain texture and set it on the render system
  const terrainGenerator = new TerrainGenerator();
  const terrainTexture = terrainGenerator.generateTerrainTexture();
  renderSystem.setTerrain(terrainTexture);

  // Create perk system for this game session
  const perkSystem = new PerkSystem(entityManager, {
    onPerkApplied: (_entityId, perkId, newRank) => {
      console.log(`Perk applied: ${PerkId[perkId]} (rank ${newRank})`);
      gameState.progressionManager?.recordPerkChosen(perkId);
    },
    onFatalLottery: (_entityId, survived, xpGained) => {
      console.log(`Fatal Lottery: survived=${survived}, xp=${xpGained}`);
      if (!survived) {
        // In co-op, only game over when all players are dead
        const currentMode = gameState.gameModeManager?.getState();
        const isCoopMode =
          currentMode?.type === 'PLAYING' && currentMode.mode.type === 'COOP_SURVIVAL';
        if (isCoopMode) {
          const alivePlayers = gameState.playerEntityIds.filter((id) => {
            const entity = entityManager.getEntity(id);
            if (!entity) return false;
            const player = entity.getComponent<'player'>('player');
            return player && player.health > 0;
          });
          if (alivePlayers.length === 0) {
            gameState.gameModeManager?.gameOver();
          }
        } else {
          gameState.gameModeManager?.gameOver();
        }
      }
    },
    onInfernalContract: (_entityId, levelsGained) => {
      console.log(`Infernal Contract: +${levelsGained} levels`);
    },
  });
  gameState.perkSystem = perkSystem;

  // Wire up perk system to other systems that need it
  weaponSystem.setPerkSystem(perkSystem);
  collisionSystem.setPerkSystem(perkSystem);
  healthSystem.setPerkSystem(perkSystem);
  bonusSystem.setPerkSystem(perkSystem);
  weaponPickupSystem.setPerkSystem(perkSystem);

  // Create game mode system to update modes every tick
  if (!gameState.gameModeManager) {
    throw new Error('GameModeManager not initialized');
  }
  const gameModeSystem = new GameModeSystem({
    gameModeManager: gameState.gameModeManager,
    survivalMode: gameState.survivalMode,
    questMode: gameState.questMode,
    rushMode: gameState.rushMode,
    tutorialMode: gameState.tutorialMode,
  });

  // Add systems in priority order
  systemManager.addSystem(inputSystem);
  systemManager.addSystem(gameModeSystem);
  systemManager.addSystem(movementSystem);
  systemManager.addSystem(weaponSystem);
  systemManager.addSystem(aiSystem);
  systemManager.addSystem(projectileSystem);
  systemManager.addSystem(collisionSystem);
  systemManager.addSystem(gameAudioSystem);
  systemManager.addSystem(healthSystem);

  // Add spawn systems only for modes that need them
  if (gameState.spawnSystem) {
    systemManager.addSystem(gameState.spawnSystem);
  }
  if (gameState.rushSpawnSystem) {
    systemManager.addSystem(gameState.rushSpawnSystem);
  }

  systemManager.addSystem(bonusSystem);
  systemManager.addSystem(weaponPickupSystem);
  systemManager.addSystem(effectSystem);
  systemManager.addSystem(perkSystem);
  systemManager.addSystem(lifetimeSystem);
  systemManager.addSystem(renderSystem);

  // Create player entities
  const playerEntities: Entity[] = [];

  if (isCoop) {
    // Create two players for co-op mode
    const player1 = PlayerFactory.create(entityManager, -50, 0, {
      playerIndex: 0,
      weaponId: 0, // Pistol
    });
    const player2 = PlayerFactory.create(entityManager, 50, 0, {
      playerIndex: 1,
      weaponId: 0, // Pistol
    });
    playerEntities.push(player1, player2);
    gameState.playerEntityId = player1.id;
    gameState.playerEntityIds = [player1.id, player2.id];
  } else {
    // Single player
    const playerEntity = PlayerFactory.create(entityManager, 0, 0, {
      playerIndex: 0,
      weaponId: 0, // Pistol
    });
    playerEntities.push(playerEntity);
    gameState.playerEntityId = playerEntity.id;
    gameState.playerEntityIds = [playerEntity.id];
  }

  // Set player entity/entities for modes that need them
  if (isCoop) {
    gameState.survivalMode?.setPlayerEntities(gameState.playerEntityIds);
  } else {
    gameState.survivalMode?.setPlayerEntity(gameState.playerEntityIds[0] ?? 0);
  }
  gameState.rushMode?.setPlayerEntity(gameState.playerEntityIds[0] ?? 0);
  gameState.tutorialMode?.setPlayerEntity(gameState.playerEntityIds[0] ?? 0);

  // Set camera to player position (will be updated by RenderSystem for co-op)
  renderSystem.setCameraPosition(0, 0);

  // Start the appropriate mode
  switch (mode.type) {
    case 'SURVIVAL':
    case 'COOP_SURVIVAL':
      gameState.survivalMode?.start();
      break;
    case 'QUEST':
      gameState.questMode?.startQuest(mode.questId);
      break;
    case 'RUSH':
      gameState.rushMode?.start();
      break;
    case 'TUTORIAL':
      gameState.tutorialMode?.start();
      gameState.tutorialUI?.show();
      gameState.tutorialUI?.setStage(
        0,
        gameState.tutorialMode?.getStagePrompt(0) ?? '',
        gameState.tutorialMode?.getStageName(0) ?? ''
      );
      break;
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
      if (gameState.tutorialUI?.isShown()) {
        gameState.tutorialUI?.update(1 / 60); // Approximate dt for UI
        gameState.tutorialUI?.render();
      }
    },
    {
      targetUps: TARGET_UPS,
      pauseOnBlur: true,
    }
  );

  gameState.appState = { type: 'PLAYING', gameLoop };
  gameLoop.start();

  // Start game music if audio is loaded
  if (gameState.audioLoaded) {
    audio.playTune(TUNES.GAME, true);
  }
}

function pauseGame(): void {
  if (gameState.appState.type !== 'PLAYING') return;

  const { gameLoop } = gameState.appState;
  gameLoop.stop();

  // Pause music
  if (gameState.audioLoaded) {
    audio.stopTune(TUNES.GAME);
  }

  const stats = gameState.gameModeManager?.getStats() ?? {
    score: 0,
    kills: 0,
    timeElapsed: 0,
    level: 1,
  };

  gameState.pauseMenuUI?.show(stats);
  gameState.appState = { type: 'PAUSED', gameLoop };

  // Start pause loop for overlay rendering
  startPauseLoop();
}

function resumeGame(): void {
  if (gameState.appState.type !== 'PAUSED') return;

  const { gameLoop } = gameState.appState;
  gameState.pauseMenuUI?.hide();
  gameState.optionsMenuUI?.hide();
  gameState.appState = { type: 'PLAYING', gameLoop };
  gameLoop.start();

  // Resume music
  if (gameState.audioLoaded) {
    audio.playTune(TUNES.GAME, true);
  }
}

function restartGame(): void {
  gameState.pauseMenuUI?.hide();
  gameState.gameOverUI?.hide();
  gameState.tutorialUI?.hide();

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

  // Stop music
  if (gameState.audioLoaded) {
    audio.stopTune(TUNES.GAME);
  }

  gameState.pauseMenuUI?.hide();
  gameState.gameOverUI?.hide();
  gameState.tutorialUI?.hide();
  gameState.gameModeManager?.returnToMenu();

  showMainMenu();
  startMenuLoop();
}

function handleGameOver(
  isVictory: boolean,
  stats: { score: number; kills: number; timeElapsed: number; level: number }
): void {
  if (gameState.appState.type === 'PLAYING') {
    gameState.appState.gameLoop.stop();
  }

  // Stop music
  if (gameState.audioLoaded) {
    audio.stopTune(TUNES.GAME);
  }

  // Get best score for comparison
  const survivalRecord = gameState.progressionManager?.getSurvivalHighScore();
  const bestScore =
    survivalRecord && survivalRecord.bestScore > 0 ? survivalRecord.bestScore : undefined;

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
  gameState.tutorialUI?.destroy();
  gameState.optionsMenuUI?.destroy();
  systemManager.clear();
  entityManager.clear();
}

/**
 * Start the pause overlay loop.
 * Renders pause menu UI and options menu UI while paused.
 */
let pauseLoopId: number | null = null;
function startPauseLoop(): void {
  if (pauseLoopId !== null) return;

  let lastTime = performance.now();

  function pauseLoop(currentTime: number): void {
    if (gameState.appState.type !== 'PAUSED') {
      pauseLoopId = null;
      return;
    }

    const dt = Math.min((currentTime - lastTime) / 1000, 0.1);
    lastTime = currentTime;

    // Only render UI if options menu is shown (pause menu is static)
    if (gameState.optionsMenuUI?.isShown()) {
      // Draw a snapshot of the game state behind the options menu
      // The game loop has stopped, so we just draw the last frame with a dark overlay
      renderer.clearBlack();

      // Update and render options menu
      gameState.optionsMenuUI.update(dt);
      gameState.optionsMenuUI.render();
    }

    pauseLoopId = requestAnimationFrame(pauseLoop);
  }

  pauseLoopId = requestAnimationFrame(pauseLoop);
}

// Handle keyboard input
document.addEventListener('keydown', (e) => {
  // Toggle FPS counter with F3
  if (e.code === 'F3') {
    gameState.renderSystem?.toggleFps();
    return;
  }

  // Handle pause with configured key binding
  const pauseKey = gameState.settingsManager?.getKeyBindings().pause ?? 'Escape';
  if (e.code === pauseKey) {
    // Don't pause if in options menu (ESC should go back instead)
    if (gameState.appState.type === 'PLAYING') {
      if (!gameState.perkSelectUI?.isShown()) {
        pauseGame();
      }
    } else if (gameState.appState.type === 'PAUSED') {
      // Only resume if options menu is not shown
      if (!gameState.optionsMenuUI?.isShown()) {
        resumeGame();
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
