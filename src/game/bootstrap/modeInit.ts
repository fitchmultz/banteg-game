/**
 * Game Mode Initialization
 *
 * Initializes all game modes with their callbacks.
 */

import type { EntityManager } from '../../core/ecs';
import { SpawnSystem } from '../systems';
import { GameModeManager, SurvivalMode, QuestMode, RushMode, TutorialMode } from '../modes';
import { PerkSystem } from '../systems';
import type { ProgressionManager } from '../progression';
import { gameState } from './gameState';

export interface ModeInstances {
  gameModeManager: GameModeManager;
  survivalMode: SurvivalMode;
  questMode: QuestMode;
  rushMode: RushMode;
  tutorialMode: TutorialMode;
}

export function initializeModes(
  entityManager: EntityManager,
  progressionManager: ProgressionManager
): ModeInstances {
  const gameModeManager = new GameModeManager({
    onStateChange: (newState, oldState) => {
      console.log(`Game state changed: ${oldState?.type} -> ${newState.type}`);
      gameState.currentGameState = newState;

      if (newState.type === 'PLAYING') {
        gameState.perkSelectUI?.hide();
      } else if (newState.type === 'GAME_OVER' || newState.type === 'VICTORY') {
        // Lazy import to avoid circular dependency
        const { handleGameOver } = require('./gameLifecycle');
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

  const survivalMode = new SurvivalMode(
    entityManager,
    new SpawnSystem(entityManager, { mapWidth: 2048, mapHeight: 2048, spawnMargin: 100 }),
    {
      onWaveStart: (wave) => console.log(`Wave ${wave} started!`),
      onLevelUp: (level) => {
        console.log(`Level up! Now level ${level}`);
        gameState.perkSelectUI?.show([]);
      },
      onPerkSelectionStart: (choices) => {
        gameModeManager.setState({ type: 'PERK_SELECT', choices });
      },
      onPerkSelected: () => {
        gameModeManager.setState({ type: 'PLAYING', mode: { type: 'SURVIVAL' } });
      },
      onXPChange: () => {},
    },
    new PerkSystem(entityManager, {
      onPerkApplied: (_entityId, _perkId, newRank) => {
        console.log(`Perk applied: rank ${newRank}`);
      },
      onFatalLottery: (_entityId, survived, xpGained) => {
        console.log(`Fatal Lottery: survived=${survived}, xp=${xpGained}`);
        if (!survived) {
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

  const questMode = new QuestMode(
    entityManager,
    {
      onQuestStart: (questId) => console.log(`Quest started: ${questId}`),
      onQuestComplete: (questId, stats) => {
        console.log(`Quest completed: ${questId}`, stats);
        const { handleGameOver } = require('./gameLifecycle');
        handleGameOver(true, stats);
      },
      onQuestFail: (questId, stats) => {
        console.log(`Quest failed: ${questId}`, stats);
        const { handleGameOver } = require('./gameLifecycle');
        handleGameOver(false, stats);
      },
      onObjectiveUpdate: () => {},
    },
    progressionManager
  );
  gameState.questMode = questMode;

  const rushMode = new RushMode(
    entityManager,
    {
      onStart: () => console.log('Rush mode started!'),
      onGameOver: (stats) => console.log('Rush mode ended!', stats),
      onSpawn: (creatureTypeId, x, y) => {
        gameState.rushSpawnSystem?.queueSpawn(creatureTypeId, x, y);
      },
    },
    progressionManager
  );
  gameState.rushMode = rushMode;

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
        const { handleGameOver } = require('./gameLifecycle');
        handleGameOver(true, stats);
      },
      onRequestPerkSelection: () => {
        const primaryPlayerId = gameState.playerEntityIds[0] ?? 0;
        const choices = gameState.perkSystem?.generatePerkChoices(primaryPlayerId, 3) ?? [];
        gameState.perkSelectUI?.show(choices);
        gameModeManager.setState({ type: 'PERK_SELECT', choices });
      },
      onSpawnBonuses: (bonuses) => {
        const { BonusFactory } = require('../entities');
        for (const bonus of bonuses) {
          const options = bonus.value !== undefined ? { value: bonus.value } : undefined;
          BonusFactory.create(entityManager, bonus.type, bonus.x, bonus.y, options);
        }
      },
      onSpawnEnemies: (enemies) => {
        const { CreatureFactory } = require('../entities');
        for (const enemy of enemies) {
          CreatureFactory.create(entityManager, enemy.creatureTypeId, enemy.x, enemy.y);
        }
      },
    },
    progressionManager
  );
  gameState.tutorialMode = tutorialMode;

  return { gameModeManager, survivalMode, questMode, rushMode, tutorialMode };
}
