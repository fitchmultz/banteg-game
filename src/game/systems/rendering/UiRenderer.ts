/**
 * UI Renderer
 *
 * Renders UI/HUD for single-player and co-op modes.
 *
 * Responsibilities:
 * - Render single-player HUD (health, XP, ammo, weapon, active effects)
 * - Render co-op HUD (compact layout for each player)
 * - Render FPS counter
 * - Handle key binding display
 *
 * Non-responsibilities:
 * - Does not render game entities (handled by EntityRenderer)
 * - Does not render terrain (handled by TerrainRenderer)
 * - Does not manage camera (handled by CameraManager)
 */

import type { EntityManager } from '../../../core/ecs/EntityManager';
import type { Renderer } from '../../../engine';
import { getWeaponData } from '../../data';

export class UiRenderer {
  private renderer: Renderer;
  private entityManager: EntityManager;

  constructor(renderer: Renderer, entityManager: EntityManager) {
    this.renderer = renderer;
    this.entityManager = entityManager;
  }

  /**
   * Render the UI/HUD for all players.
   */
  render(showFps: boolean, currentFps: number): void {
    const players = this.entityManager.query(['player']);
    if (players.length === 0) return;

    const canvas = this.renderer.getCanvas();
    const rightEdge = canvas.width;

    // Sort players by playerIndex to ensure consistent ordering
    const sortedPlayers = [...players].sort((a, b) => {
      const playerA = a.getComponent<'player'>('player');
      const playerB = b.getComponent<'player'>('player');
      return (playerA?.playerIndex ?? 0) - (playerB?.playerIndex ?? 0);
    });

    // Render HUD for each player
    if (sortedPlayers.length === 1) {
      // Single player HUD (original layout)
      const player = sortedPlayers[0];
      if (player) {
        this.renderSinglePlayerHUD(player, 20);
      }
    } else {
      // Two-player HUD (side by side)
      const player1 = sortedPlayers[0];
      const player2 = sortedPlayers[1];
      if (player1) {
        this.renderPlayerHUD(player1, 20, true); // P1 on left
      }
      if (player2) {
        this.renderPlayerHUD(player2, rightEdge - 210, false); // P2 on right
      }
    }

    // FPS counter (top-right, only if enabled)
    if (showFps) {
      this.renderer.setColor(0, 1, 0, 0.7);
      this.renderer.drawText(`FPS: ${currentFps}`, rightEdge - 80, 25);
    }
  }

  /**
   * Render HUD for a single player (original layout).
   */
  renderSinglePlayerHUD(
    playerEntity: ReturnType<EntityManager['query']>[number],
    xOffset: number
  ): void {
    const playerComp = playerEntity.getComponent<'player'>('player');
    if (!playerComp) return;

    const currentWeaponData = getWeaponData(playerComp.currentWeapon.weaponId);
    const altWeaponData = getWeaponData(playerComp.alternateWeapon.weaponId);

    // Set text color
    this.renderer.setColor(1, 1, 1, 1);

    // Health bar
    const healthPercent = playerComp.health / playerComp.maxHealth;
    this.renderer.drawText(
      `HP: ${Math.ceil(playerComp.health)}/${playerComp.maxHealth}`,
      xOffset,
      40
    );
    this.renderer.drawRectOutline(xOffset, 50, 204, 14, 1);
    // Health bar gradient
    this.renderer.setColor(1 - healthPercent, healthPercent, 0, 1);
    this.renderer.drawRect(xOffset + 2, 52, 200 * healthPercent, 10);

    // XP bar (below health)
    const xpPercent = playerComp.experience / (playerComp.level * 100); // Approximate
    this.renderer.setColor(1, 1, 1, 1);
    this.renderer.drawText(`Level ${playerComp.level}`, xOffset, 85);
    this.renderer.drawRectOutline(xOffset, 90, 204, 8, 1);
    this.renderer.setColor(0.2, 0.6, 1, 1);
    this.renderer.drawRect(xOffset + 2, 92, Math.min(200, 200 * xpPercent), 4);

    // Current weapon info
    this.renderer.setColor(1, 1, 1, 1);
    this.renderer.drawText(
      `Ammo: ${playerComp.currentWeapon.clipSize}/${currentWeaponData.clipSize} (${playerComp.currentWeapon.ammo})`,
      xOffset,
      120
    );
    this.renderer.drawText(`Weapon: ${currentWeaponData.name}`, xOffset, 140);

    // Alternate weapon info
    this.renderer.setColor(0.7, 0.7, 0.7, 1);
    this.renderer.drawText(
      `Alt: ${altWeaponData.name} (${playerComp.alternateWeapon.clipSize}/${playerComp.alternateWeapon.ammo})`,
      xOffset,
      160
    );
    // Show swap weapon key binding dynamically
    const swapKeyLabel = this.getSwapKeyLabel();
    this.renderer.setColor(0.5, 0.5, 0.5, 1);
    this.renderer.drawText(`[${swapKeyLabel}] Swap Weapon`, xOffset, 175);

    // Active effects (with icons)
    let yOffset = 205;
    if (playerComp.shieldTimer > 0) {
      this.renderer.drawGlow(xOffset + 15, yOffset - 5, 20, { r: 0, g: 0.5, b: 1, a: 0.5 });
      this.renderer.setColor(0, 0.5, 1, 1);
      this.renderer.drawText(
        `Shield: ${playerComp.shieldTimer.toFixed(1)}s`,
        xOffset + 35,
        yOffset
      );
      yOffset += 25;
    }
    if (playerComp.fireBulletsTimer > 0) {
      this.renderer.drawGlow(xOffset + 15, yOffset - 5, 20, { r: 1, g: 0.3, b: 0, a: 0.5 });
      this.renderer.setColor(1, 0.3, 0, 1);
      this.renderer.drawText(
        `Fire: ${playerComp.fireBulletsTimer.toFixed(1)}s`,
        xOffset + 35,
        yOffset
      );
      yOffset += 25;
    }
    if (playerComp.speedBonusTimer > 0) {
      this.renderer.drawGlow(xOffset + 15, yOffset - 5, 20, { r: 0, g: 1, b: 1, a: 0.5 });
      this.renderer.setColor(0, 1, 1, 1);
      this.renderer.drawText(
        `Speed: ${playerComp.speedBonusTimer.toFixed(1)}s`,
        xOffset + 35,
        yOffset
      );
      yOffset += 25;
    }
    if (playerComp.freezeTimer > 0) {
      this.renderer.drawGlow(xOffset + 15, yOffset - 5, 20, { r: 0, g: 0.666, b: 1, a: 0.5 });
      this.renderer.setColor(0, 0.666, 1, 1);
      this.renderer.drawText(
        `Freeze: ${playerComp.freezeTimer.toFixed(1)}s`,
        xOffset + 35,
        yOffset
      );
      yOffset += 25;
    }
    if (playerComp.energizerTimer > 0) {
      this.renderer.drawGlow(xOffset + 15, yOffset - 5, 20, { r: 1, g: 0.866, b: 0, a: 0.5 });
      this.renderer.setColor(1, 0.866, 0, 1);
      this.renderer.drawText(
        `Energizer: ${playerComp.energizerTimer.toFixed(1)}s`,
        xOffset + 35,
        yOffset
      );
      yOffset += 25;
    }
    if (playerComp.reflexBoostTimer > 0) {
      this.renderer.drawGlow(xOffset + 15, yOffset - 5, 20, { r: 0.666, g: 0, b: 1, a: 0.5 });
      this.renderer.setColor(0.666, 0, 1, 1);
      this.renderer.drawText(
        `Reflex: ${playerComp.reflexBoostTimer.toFixed(1)}s`,
        xOffset + 35,
        yOffset
      );
    }
  }

  /**
   * Render HUD for a player in co-op mode.
   */
  renderPlayerHUD(
    playerEntity: ReturnType<EntityManager['query']>[number],
    xOffset: number,
    _isLeft: boolean
  ): void {
    const playerComp = playerEntity.getComponent<'player'>('player');
    if (!playerComp) return;

    const playerIndex = playerComp.playerIndex ?? 0;
    const currentWeaponData = getWeaponData(playerComp.currentWeapon.weaponId);

    // Player label color
    if (playerIndex === 0) {
      this.renderer.setColor(0, 1, 0, 1); // P1: Green
    } else {
      this.renderer.setColor(0, 0.5, 1, 1); // P2: Blue
    }

    // Player label
    const label = `P${playerIndex + 1}`;
    this.renderer.drawText(label, xOffset, 25);

    // Set text color
    this.renderer.setColor(1, 1, 1, 1);

    // Health bar
    const healthPercent = playerComp.health / playerComp.maxHealth;
    this.renderer.drawText(
      `HP: ${Math.ceil(playerComp.health)}/${playerComp.maxHealth}`,
      xOffset,
      45
    );
    this.renderer.drawRectOutline(xOffset, 55, 204, 14, 1);
    // Health bar gradient
    this.renderer.setColor(1 - healthPercent, healthPercent, 0, 1);
    this.renderer.drawRect(xOffset + 2, 57, 200 * healthPercent, 10);

    // Ammo
    this.renderer.setColor(1, 1, 1, 1);
    this.renderer.drawText(
      `Ammo: ${playerComp.currentWeapon.clipSize}/${currentWeaponData.clipSize}`,
      xOffset,
      85
    );

    // Weapon name
    this.renderer.setColor(0.8, 0.8, 0.8, 1);
    this.renderer.drawText(currentWeaponData.name, xOffset, 105);

    // Active effects (compact)
    let yOffset = 130;
    if (playerComp.shieldTimer > 0) {
      this.renderer.setColor(0, 0.5, 1, 1);
      this.renderer.drawText(`Shield: ${playerComp.shieldTimer.toFixed(0)}s`, xOffset, yOffset);
      yOffset += 20;
    }
    if (playerComp.fireBulletsTimer > 0) {
      this.renderer.setColor(1, 0.3, 0, 1);
      this.renderer.drawText(`Fire: ${playerComp.fireBulletsTimer.toFixed(0)}s`, xOffset, yOffset);
      yOffset += 20;
    }
    if (playerComp.speedBonusTimer > 0) {
      this.renderer.setColor(0, 1, 1, 1);
      this.renderer.drawText(`Speed: ${playerComp.speedBonusTimer.toFixed(0)}s`, xOffset, yOffset);
      yOffset += 20;
    }
    if (playerComp.freezeTimer > 0) {
      this.renderer.setColor(0, 0.666, 1, 1);
      this.renderer.drawText(`Freeze: ${playerComp.freezeTimer.toFixed(0)}s`, xOffset, yOffset);
      yOffset += 20;
    }
    if (playerComp.energizerTimer > 0) {
      this.renderer.setColor(1, 0.866, 0, 1);
      this.renderer.drawText(`Energ: ${playerComp.energizerTimer.toFixed(0)}s`, xOffset, yOffset);
      yOffset += 20;
    }
    if (playerComp.reflexBoostTimer > 0) {
      this.renderer.setColor(0.666, 0, 1, 1);
      this.renderer.drawText(
        `Reflex: ${playerComp.reflexBoostTimer.toFixed(0)}s`,
        xOffset,
        yOffset
      );
    }
  }

  /**
   * Get the display label for the swap weapon key.
   * Falls back to 'Q' if no input manager is available.
   */
  private getSwapKeyLabel(): string {
    // Try to get from window.gameState for dynamic binding
    // This is a bit hacky but maintains compatibility with the existing architecture
    const gameState = (
      window as unknown as {
        gameState?: { settingsManager?: { getKeyBindings: () => { swapWeapon: string } } };
      }
    ).gameState;
    if (gameState?.settingsManager?.getKeyBindings) {
      const binding = gameState.settingsManager.getKeyBindings().swapWeapon;
      return this.formatKeyCode(binding);
    }
    return 'Q';
  }

  /**
   * Format a key code for display (e.g., 'KeyQ' -> 'Q', 'Escape' -> 'ESC').
   */
  private formatKeyCode(code: string): string {
    if (code.startsWith('Key')) {
      return code.slice(3);
    }
    if (code === 'Escape') return 'ESC';
    if (code === 'Space') return 'SPC';
    if (code.startsWith('Arrow')) {
      return code.slice(5).toUpperCase();
    }
    if (code.startsWith('Digit')) {
      return code.slice(5);
    }
    return code;
  }
}
