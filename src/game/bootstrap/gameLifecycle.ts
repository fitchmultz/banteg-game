/**
 * Game Lifecycle
 *
 * Handles game start, pause, resume, restart, game over, and cleanup.
 */

import { GameLoop } from '../../core/GameLoop';
import type { EntityManager, SystemManager } from '../../core/ecs';
import {
  InputSystem,
  MovementSystem,
  WeaponSystem,
  AiSystem,
  ProjectileSystem,
  CollisionSystem,
  GameAudioSystem,
  HealthSystem,
  BonusSystem,
  WeaponPickupSystem,
  EffectSystem,
  PerkSystem,
  LifetimeSystem,
  RenderSystem,
  GameModeSystem,
  RushSpawnSystem,
  SpawnSystem,
} from '../systems';
import { PlayerFactory } from '../entities';
import { BonusFactory } from '../entities';
import { TerrainGenerator } from '../../engine/TerrainGenerator';
import { TUNES, getDeathSample } from '../audio';
import { getUnlockedWeapons, getQuestData } from '../data';
import { gameState } from './gameState';
import type { GameMode } from '../../types';
import type { Renderer, AudioManager, AssetManager, InputManager } from '../../engine';
import type { SpriteAtlas } from '../../engine';
import { startPauseLoop } from './menuLifecycle';
import type { Entity } from '../../core/ecs';

const TARGET_UPS = 60;

export function startGame(
  mode: GameMode,
  entityManager: EntityManager,
  systemManager: SystemManager,
  renderer: Renderer,
  input: InputManager,
  audio: AudioManager,
  assetManager: AssetManager,
  spriteAtlas: SpriteAtlas
): void {
  // Hide all menus
  gameState.mainMenuUI?.hide();
  gameState.questMenuUI?.hide();
  gameState.gameOverUI?.hide();
  gameState.tutorialUI?.hide();

  // Clear existing entities and systems
  systemManager.clear();
  entityManager.clear();

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
  const collisionSystem = new CollisionSystem(entityManager, audio);
  const gameAudioSystem = new GameAudioSystem(entityManager, audio);

  const isSurvival = mode.type === 'SURVIVAL' || mode.type === 'COOP_SURVIVAL';
  const isCoop = mode.type === 'COOP_SURVIVAL';
  const isRush = mode.type === 'RUSH';

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
      if (gameState.audioLoaded) {
        audio.playSample(getDeathSample({ isPlayer: true }));
      }
      gameState.progressionManager?.recordDeath();

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
    onCreatureDeath: (creatureTypeId, position, isBoss) => {
      if (gameState.audioLoaded) {
        audio.playSample(getDeathSample({ isPlayer: false, creatureTypeId }));
      }
      if (position && gameState.renderSystem) {
        const shakeIntensity = 2 + Math.random() * 3;
        gameState.renderSystem.shake(shakeIntensity, 0.1);
        const particleSystem = gameState.renderSystem.getParticleSystem();
        particleSystem.emitBloodSplatter(position.x, position.y, Math.random() * Math.PI * 2, 5);

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
              const unlockedWeapons = getUnlockedWeapons(playerComp.experience);
              const availableWeapons = unlockedWeapons.filter(
                (id) =>
                  id !== playerComp.currentWeapon.weaponId &&
                  id !== playerComp.alternateWeapon.weaponId
              );
              if (availableWeapons.length > 0) {
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

      if (isSurvival) {
        gameState.spawnSystem?.onEnemyDefeated();
      } else if (isRush) {
        gameState.rushSpawnSystem?.onEnemyDefeated();
      }

      if (gameState.gameModeManager?.isPlaying()) {
        const state = gameState.gameModeManager.getState();
        if (state.type === 'PLAYING') {
          switch (state.mode.type) {
            case 'SURVIVAL':
            case 'COOP_SURVIVAL':
              gameState.survivalMode?.recordKill(10);
              break;
            case 'QUEST':
              gameState.questMode?.recordKill(creatureTypeId, 10, isBoss ?? false);
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

      if (creatureTypeId !== undefined) {
        gameState.progressionManager?.recordKill(creatureTypeId);
      }
    },
    onScoreChange: (score) => {
      gameState.gameModeManager?.updateStats({ score });
    },
    onXPChange: (xp) => {
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
        }
      }
    },
  });

  const renderSystem = new RenderSystem(entityManager, renderer, assetManager, spriteAtlas, input);
  gameState.renderSystem = renderSystem;

  const bonusSystem = new BonusSystem(entityManager, undefined, renderSystem, audio);
  const weaponPickupSystem = new WeaponPickupSystem(entityManager);
  const effectSystem = new EffectSystem(entityManager);
  const lifetimeSystem = new LifetimeSystem(entityManager);

  const terrainGenerator = new TerrainGenerator();
  const terrainTexture = terrainGenerator.generateTerrainTexture();
  renderSystem.setTerrain(terrainTexture);

  const perkSystem = new PerkSystem(entityManager, {
    onPerkApplied: (_entityId, _perkId, newRank) => {
      console.log(`Perk applied: rank ${newRank}`);
      gameState.progressionManager?.recordPerkChosen(_perkId);
    },
    onFatalLottery: (_entityId, survived, xpGained) => {
      console.log(`Fatal Lottery: survived=${survived}, xp=${xpGained}`);
      if (!survived) {
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

  weaponSystem.setPerkSystem(perkSystem);
  collisionSystem.setPerkSystem(perkSystem);
  healthSystem.setPerkSystem(perkSystem);
  bonusSystem.setPerkSystem(perkSystem);
  weaponPickupSystem.setPerkSystem(perkSystem);

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

  systemManager.addSystem(inputSystem);
  systemManager.addSystem(gameModeSystem);
  systemManager.addSystem(movementSystem);
  systemManager.addSystem(weaponSystem);
  systemManager.addSystem(aiSystem);
  systemManager.addSystem(projectileSystem);
  systemManager.addSystem(collisionSystem);
  systemManager.addSystem(gameAudioSystem);
  systemManager.addSystem(healthSystem);
  if (gameState.spawnSystem) systemManager.addSystem(gameState.spawnSystem);
  if (gameState.rushSpawnSystem) systemManager.addSystem(gameState.rushSpawnSystem);
  systemManager.addSystem(bonusSystem);
  systemManager.addSystem(weaponPickupSystem);
  systemManager.addSystem(effectSystem);
  systemManager.addSystem(perkSystem);
  systemManager.addSystem(lifetimeSystem);
  systemManager.addSystem(renderSystem);

  // Create player entities
  const playerEntities: Entity[] = [];
  let startingWeaponId = 0;
  if (mode.type === 'QUEST') {
    const questData = getQuestData(mode.questId);
    if (questData?.startingWeapon !== undefined) {
      startingWeaponId = questData.startingWeapon;
    }
  }

  if (isCoop) {
    const player1 = PlayerFactory.create(entityManager, -50, 0, {
      playerIndex: 0,
      weaponId: startingWeaponId,
    });
    const player2 = PlayerFactory.create(entityManager, 50, 0, {
      playerIndex: 1,
      weaponId: startingWeaponId,
    });
    playerEntities.push(player1, player2);
    gameState.playerEntityId = player1.id;
    gameState.playerEntityIds = [player1.id, player2.id];
  } else {
    const playerEntity = PlayerFactory.create(entityManager, 0, 0, {
      playerIndex: 0,
      weaponId: startingWeaponId,
    });
    playerEntities.push(playerEntity);
    gameState.playerEntityId = playerEntity.id;
    gameState.playerEntityIds = [playerEntity.id];
  }

  if (isCoop) {
    gameState.survivalMode?.setPlayerEntities(gameState.playerEntityIds);
  } else {
    gameState.survivalMode?.setPlayerEntity(gameState.playerEntityIds[0] ?? 0);
  }
  gameState.rushMode?.setPlayerEntity(gameState.playerEntityIds[0] ?? 0);
  gameState.tutorialMode?.setPlayerEntity(gameState.playerEntityIds[0] ?? 0);

  renderSystem.setCameraPosition(0, 0);

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

  const gameLoop = new GameLoop(
    entityManager,
    systemManager,
    () => {
      if (gameState.perkSelectUI?.isShown()) {
        gameState.perkSelectUI?.render();
      }
      if (gameState.tutorialUI?.isShown()) {
        gameState.tutorialUI?.update(1 / 60);
        gameState.tutorialUI?.render();
      }
      if (gameState.console?.isOpen()) {
        gameState.console.render();
      }
    },
    { targetUps: TARGET_UPS, pauseOnBlur: true }
  );

  gameState.appState = { type: 'PLAYING', gameLoop };
  gameLoop.start();

  if (gameState.audioLoaded) {
    audio.playTune(TUNES.GAME, true);
  }
}

export function pauseGame(audio: AudioManager, renderer: Renderer): void {
  if (gameState.appState.type !== 'PLAYING') return;

  const { gameLoop } = gameState.appState;
  gameLoop.stop();

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

  startPauseLoop(renderer);
}

export function resumeGame(audio: AudioManager): void {
  if (gameState.appState.type !== 'PAUSED') return;

  const { gameLoop } = gameState.appState;
  gameState.pauseMenuUI?.hide();
  gameState.optionsMenuUI?.hide();
  gameState.appState = { type: 'PLAYING', gameLoop };
  gameLoop.start();

  if (gameState.audioLoaded) {
    audio.playTune(TUNES.GAME, true);
  }
}

export function restartGame(
  entityManager: EntityManager,
  systemManager: SystemManager,
  renderer: Renderer,
  input: InputManager,
  audio: AudioManager,
  assetManager: AssetManager,
  spriteAtlas: SpriteAtlas
): void {
  gameState.pauseMenuUI?.hide();
  gameState.gameOverUI?.hide();
  gameState.tutorialUI?.hide();

  const currentState = gameState.gameModeManager?.getState();
  if (currentState?.type === 'PLAYING') {
    startGame(
      currentState.mode,
      entityManager,
      systemManager,
      renderer,
      input,
      audio,
      assetManager,
      spriteAtlas
    );
  } else {
    startGame(
      { type: 'SURVIVAL' },
      entityManager,
      systemManager,
      renderer,
      input,
      audio,
      assetManager,
      spriteAtlas
    );
  }
}

export function returnToMainMenu(
  audio: AudioManager,
  _entityManager: EntityManager,
  _systemManager: SystemManager
): void {
  if (gameState.appState.type === 'PLAYING' || gameState.appState.type === 'PAUSED') {
    gameState.appState.gameLoop.destroy();
  }

  if (gameState.audioLoaded) {
    audio.stopTune(TUNES.GAME);
  }

  gameState.pauseMenuUI?.hide();
  gameState.gameOverUI?.hide();
  gameState.tutorialUI?.hide();
  gameState.gameModeManager?.returnToMenu();

  const { showMainMenu } = require('./menuLifecycle');
  showMainMenu();
}

export function handleGameOver(
  isVictory: boolean,
  stats: { score: number; kills: number; timeElapsed: number; level: number }
): void {
  if (gameState.appState.type === 'PLAYING') {
    gameState.appState.gameLoop.stop();
  }

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

export function cleanup(
  input: InputManager,
  audio: AudioManager,
  entityManager: EntityManager,
  systemManager: SystemManager
): void {
  gameState.progressionManager?.save();

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
  gameState.highScoresUI?.destroy();
  gameState.creditsUI?.destroy();
  gameState.console?.destroy();
  systemManager.clear();
  entityManager.clear();
}
