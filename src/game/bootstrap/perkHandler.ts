/**
 * Perk Handler
 *
 * Handles perk selection across different game modes.
 */

import { gameState } from './gameState';
import type { PerkId } from '../../types';
import type { GameMode } from '../../types';

export function handlePerkSelection(perkId: PerkId): void {
  const currentState = gameState.gameModeManager?.getState();
  if (currentState?.type !== 'PERK_SELECT') return;

  const previousState = gameState.gameModeManager?.getPreviousState();
  let mode: GameMode = { type: 'SURVIVAL' };

  if (previousState?.type === 'PLAYING') {
    mode = previousState.mode;
  }

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
      gameState.perkSelectUI?.hide();
      gameState.gameModeManager?.setState({ type: 'PLAYING', mode });
      break;
  }
}
