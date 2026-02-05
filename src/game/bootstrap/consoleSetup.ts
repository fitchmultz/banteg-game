/**
 * Console Setup
 *
 * Initializes the developer console and wires up commands.
 */

import type { Renderer } from '../../engine';
import type { InputManager } from '../../engine';
import type { EntityManager } from '../../core/ecs';
import { gameState } from './gameState';

export async function initializeConsole(
  renderer: Renderer,
  input: InputManager,
  entityManager: EntityManager
): Promise<void> {
  const { Console, cvarRegistry, commandRegistry } = await import('../../console');

  const consoleInstance = new Console({ renderer, inputManager: input });
  gameState.console = consoleInstance;

  // Wire up CVAR onChange callbacks
  const r_showfps = cvarRegistry.get('r_showfps');
  if (r_showfps) {
    r_showfps.onChange = (value) => {
      if (gameState.renderSystem && typeof value === 'boolean') {
        gameState.renderSystem.showFps = value;
      }
    };
  }

  // Wire up commands
  const quitCmd = commandRegistry.get('quit');
  if (quitCmd) {
    quitCmd.handler = () => {
      const { returnToMainMenu } = require('./gameLifecycle');
      returnToMainMenu();
      return 'Returned to main menu';
    };
  }

  const godCmd = commandRegistry.get('god');
  if (godCmd) {
    godCmd.handler = () => {
      for (const playerId of gameState.playerEntityIds) {
        const entity = entityManager.getEntity(playerId);
        if (entity) {
          const player = entity.getComponent<'player'>('player');
          if (player) {
            player.invulnerable = !player.invulnerable;
          }
        }
      }
      return 'God mode toggled';
    };
  }

  const giveCmd = commandRegistry.get('give');
  if (giveCmd) {
    giveCmd.handler = (args) => {
      if (args.length < 1) return 'Usage: give <weapon|ammo|health> [amount]';
      const [type, amountStr] = args;
      const amount = amountStr ? Number.parseInt(amountStr, 10) : 1;

      const primaryPlayerId = gameState.playerEntityIds[0];
      if (primaryPlayerId === undefined) return 'No player found';

      const entity = entityManager.getEntity(primaryPlayerId);
      if (!entity) return 'Player entity not found';

      switch (type?.toLowerCase()) {
        case 'health': {
          const player = entity.getComponent<'player'>('player');
          if (player) {
            player.health = Math.min(player.maxHealth, player.health + amount);
            return `Gave ${amount} health`;
          }
          break;
        }
        case 'ammo': {
          const player = entity.getComponent<'player'>('player');
          if (player) {
            player.currentWeapon.ammo += amount;
            return `Gave ${amount} ammo`;
          }
          break;
        }
        default:
          return `Unknown item: ${type}`;
      }

      return 'Failed to give item';
    };
  }

  const killallCmd = commandRegistry.get('killall');
  if (killallCmd) {
    killallCmd.handler = () => {
      const entities = entityManager.getAllEntities();
      let count = 0;
      for (const entity of entities) {
        if (entity.hasComponent('creature')) {
          const creature = entity.getComponent<'creature'>('creature');
          if (creature) {
            creature.health = 0;
            count++;
          }
        }
      }
      return `Killed ${count} enemies`;
    };
  }

  const noclipCmd = commandRegistry.get('noclip');
  if (noclipCmd) {
    noclipCmd.handler = () => {
      for (const playerId of gameState.playerEntityIds) {
        const entity = entityManager.getEntity(playerId);
        if (entity) {
          const collider = entity.getComponent<'collider'>('collider');
          if (collider) {
            collider.enabled = !collider.enabled;
          }
        }
      }
      return 'Noclip toggled';
    };
  }

  // Update ent_count CVAR periodically
  setInterval(() => {
    const entCount = cvarRegistry.get('ent_count');
    if (entCount) {
      entCount.value = entityManager.getAllEntities().length;
    }
  }, 1000);
}
