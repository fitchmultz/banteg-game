/**
 * Survival Tab Renderer
 *
 * Renders the Survival mode high scores tab.
 */

import type { ProgressionManager } from '../../../progression/ProgressionManager';
import { formatTime } from '../rendering';

type DrawStatRowFn = (label: string, value: string, x: number, y: number, width: number) => void;

export function drawSurvivalTab(
  ctx: CanvasRenderingContext2D,
  progressionManager: ProgressionManager,
  centerX: number,
  startY: number,
  width: number,
  drawStatRow: DrawStatRowFn
): void {
  const highScore = progressionManager.getSurvivalHighScore();

  // Section title
  ctx.font = 'bold 20px Arial, sans-serif';
  ctx.textAlign = 'center';
  ctx.fillStyle = '#FFD700';
  ctx.fillText('SURVIVAL MODE', centerX, startY);

  if (highScore.bestScore === 0) {
    // No records yet
    ctx.font = '16px Arial, sans-serif';
    ctx.fillStyle = '#888899';
    ctx.fillText('No survival records yet', centerX, startY + 50);
    return;
  }

  // Draw stats
  const statsY = startY + 50;
  const lineHeight = 40;

  drawStatRow(
    'Best Score:',
    highScore.bestScore.toLocaleString(),
    centerX - width / 4,
    statsY,
    width / 2
  );
  drawStatRow(
    'Best Time:',
    formatTime(highScore.bestTime),
    centerX - width / 4,
    statsY + lineHeight,
    width / 2
  );
  drawStatRow(
    'Best Level:',
    highScore.bestLevel.toString(),
    centerX - width / 4,
    statsY + lineHeight * 2,
    width / 2
  );

  const date = new Date(highScore.achievedAt).toLocaleDateString();
  drawStatRow('Achieved:', date, centerX - width / 4, statsY + lineHeight * 3, width / 2);
}
