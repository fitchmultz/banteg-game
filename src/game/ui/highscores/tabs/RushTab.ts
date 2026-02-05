/**
 * Rush Tab Renderer
 *
 * Renders the Rush mode high scores tab.
 */

import type { ProgressionManager } from '../../../progression/ProgressionManager';
import { formatTime } from '../rendering';

type DrawStatRowFn = (label: string, value: string, x: number, y: number, width: number) => void;

export function drawRushTab(
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
  ctx.fillText('RUSH MODE', centerX, startY);

  // Note about Rush sharing survival scores
  ctx.font = '12px Arial, sans-serif';
  ctx.fillStyle = '#888899';
  ctx.fillText('(Rush mode uses Survival high scores)', centerX, startY + 25);

  if (highScore.bestScore === 0) {
    // No records yet
    ctx.font = '16px Arial, sans-serif';
    ctx.fillStyle = '#888899';
    ctx.fillText('No rush records yet', centerX, startY + 60);
    return;
  }

  // Draw best time prominently (primary Rush metric)
  ctx.font = 'bold 48px Arial, sans-serif';
  ctx.fillStyle = '#FFD700';
  ctx.fillText(formatTime(highScore.bestTime), centerX, startY + 90);

  ctx.font = '14px Arial, sans-serif';
  ctx.fillStyle = '#AAAAAA';
  ctx.fillText('Best Time', centerX, startY + 115);

  // Draw additional stats
  const statsY = startY + 160;
  const lineHeight = 35;

  drawStatRow(
    'Best Score:',
    highScore.bestScore.toLocaleString(),
    centerX - width / 4,
    statsY,
    width / 2
  );
  drawStatRow(
    'Best Level:',
    highScore.bestLevel.toString(),
    centerX - width / 4,
    statsY + lineHeight,
    width / 2
  );

  const date = new Date(highScore.achievedAt).toLocaleDateString();
  drawStatRow('Achieved:', date, centerX - width / 4, statsY + lineHeight * 2, width / 2);
}
