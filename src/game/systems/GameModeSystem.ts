/**
 * Game Mode System
 *
 * ECS system that calls update() on the active game mode every tick.
 * This ensures SurvivalMode, QuestMode, RushMode, and TutorialMode
 * all receive regular updates during gameplay.
 *
 * Priority: 15 (between InputSystem and MovementSystem)
 *
 * Invariants:
 * - Only updates when game state is PLAYING
 * - Does not update when PAUSED, in MENU, PERK_SELECT, GAME_OVER, or VICTORY
 * - Routes update to the correct mode based on GameModeManager state
 */

import { System, type UpdateContext } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs/EntityManager';
import type { GameModeManager } from '../modes/GameModeManager';
import type { SurvivalMode } from '../modes/SurvivalMode';
import type { QuestMode } from '../modes/QuestMode';
import type { RushMode } from '../modes/RushMode';
import type { TutorialMode } from '../modes/TutorialMode';

export interface GameModeSystemOptions {
  gameModeManager: GameModeManager;
  survivalMode: SurvivalMode | null;
  questMode: QuestMode | null;
  rushMode: RushMode | null;
  tutorialMode: TutorialMode | null;
}

export class GameModeSystem extends System {
  readonly name = 'GameModeSystem';
  readonly priority = 15;

  private options: GameModeSystemOptions;

  constructor(options: GameModeSystemOptions) {
    super();
    this.options = options;
  }

  update(_entityManager: EntityManager, context: UpdateContext): void {
    const { gameModeManager, survivalMode, questMode, rushMode, tutorialMode } = this.options;

    // Only update when playing
    if (!gameModeManager.isPlaying()) {
      return;
    }

    const state = gameModeManager.getState();
    if (state.type !== 'PLAYING') {
      return;
    }

    const dt = context.dt;

    // Route update to the correct mode
    switch (state.mode.type) {
      case 'SURVIVAL':
        survivalMode?.update(dt);
        break;
      case 'QUEST':
        questMode?.update(dt);
        break;
      case 'RUSH':
        rushMode?.update(dt);
        break;
      case 'TUTORIAL':
        tutorialMode?.update(dt);
        break;
    }
  }
}
