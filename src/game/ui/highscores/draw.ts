/**
 * High Scores UI Drawing Functions
 *
 * Component-level drawing functions for the high scores UI.
 */

import { roundRect, darkenColor, wrapText } from './rendering';
import { LAYOUT, TABS, TAB_WIDTH, SORT_OPTIONS, ACTION_BUTTONS } from './layout';
import type { HighScoreTab, SortOption, SortDirection } from './types';

export function drawPanel(
  ctx: CanvasRenderingContext2D,
  canvasWidth: number,
  canvasHeight: number
): void {
  const panelX = (canvasWidth - LAYOUT.PANEL_WIDTH) / 2;
  const panelY = (canvasHeight - LAYOUT.PANEL_HEIGHT) / 2;

  // Panel shadow
  ctx.fillStyle = 'rgba(0, 0, 0, 0.5)';
  roundRect(ctx, panelX + 6, panelY + 6, LAYOUT.PANEL_WIDTH, LAYOUT.PANEL_HEIGHT, 12);
  ctx.fill();

  // Panel background
  const gradient = ctx.createLinearGradient(panelX, panelY, panelX, panelY + LAYOUT.PANEL_HEIGHT);
  gradient.addColorStop(0, '#1a1a2e');
  gradient.addColorStop(1, '#0f0f1a');

  ctx.fillStyle = gradient;
  roundRect(ctx, panelX, panelY, LAYOUT.PANEL_WIDTH, LAYOUT.PANEL_HEIGHT, 12);
  ctx.fill();

  // Panel border
  ctx.strokeStyle = '#333355';
  ctx.lineWidth = 2;
  roundRect(ctx, panelX, panelY, LAYOUT.PANEL_WIDTH, LAYOUT.PANEL_HEIGHT, 12);
  ctx.stroke();
}

export function drawTitle(
  ctx: CanvasRenderingContext2D,
  canvasWidth: number,
  canvasHeight: number
): void {
  const titleY = canvasHeight / 2 - LAYOUT.PANEL_HEIGHT / 2 + 40;

  ctx.font = 'bold 32px Arial, sans-serif';
  ctx.textAlign = 'center';
  ctx.textBaseline = 'middle';

  // Glow effect
  ctx.shadowColor = '#8B0000';
  ctx.shadowBlur = 15;

  ctx.fillStyle = '#FFD700';
  ctx.fillText('HIGH SCORES', canvasWidth / 2, titleY);

  ctx.shadowBlur = 0;

  // Underline
  ctx.strokeStyle = '#8B0000';
  ctx.lineWidth = 2;
  ctx.beginPath();
  ctx.moveTo(canvasWidth / 2 - 80, titleY + 20);
  ctx.lineTo(canvasWidth / 2 + 80, titleY + 20);
  ctx.stroke();
}

export function drawTabs(
  ctx: CanvasRenderingContext2D,
  canvasWidth: number,
  canvasHeight: number,
  currentTab: HighScoreTab
): void {
  const tabHeight = LAYOUT.TAB_HEIGHT;
  const startX = canvasWidth / 2 - (TABS.length * TAB_WIDTH) / 2;
  const tabY = canvasHeight / 2 - LAYOUT.PANEL_HEIGHT / 2 + 80;

  for (let i = 0; i < TABS.length; i++) {
    const tab = TABS[i];
    if (!tab) continue;

    const x = startX + i * TAB_WIDTH;
    const isActive = currentTab === tab;

    // Tab background
    if (isActive) {
      const gradient = ctx.createLinearGradient(x, tabY, x, tabY + tabHeight);
      gradient.addColorStop(0, '#660000');
      gradient.addColorStop(1, '#330000');
      ctx.fillStyle = gradient;
    } else {
      ctx.fillStyle = '#2a2a3e';
    }

    ctx.beginPath();
    ctx.moveTo(x + 8, tabY);
    ctx.lineTo(x + TAB_WIDTH - 8, tabY);
    ctx.quadraticCurveTo(x + TAB_WIDTH, tabY, x + TAB_WIDTH, tabY + 8);
    ctx.lineTo(x + TAB_WIDTH, tabY + tabHeight);
    ctx.lineTo(x, tabY + tabHeight);
    ctx.lineTo(x, tabY + 8);
    ctx.quadraticCurveTo(x, tabY, x + 8, tabY);
    ctx.closePath();
    ctx.fill();

    // Tab border
    ctx.strokeStyle = isActive ? '#FF4444' : '#444466';
    ctx.lineWidth = isActive ? 2 : 1;
    ctx.stroke();

    // Tab text
    ctx.font = isActive ? 'bold 14px Arial' : '14px Arial';
    ctx.textAlign = 'center';
    ctx.textBaseline = 'middle';
    ctx.fillStyle = isActive ? '#FFFFFF' : '#888899';
    ctx.fillText(tab, x + TAB_WIDTH / 2, tabY + tabHeight / 2);
  }
}

export function drawStatRow(
  ctx: CanvasRenderingContext2D,
  label: string,
  value: string,
  x: number,
  y: number,
  width: number
): void {
  ctx.font = '16px Arial, sans-serif';
  ctx.textAlign = 'left';
  ctx.fillStyle = '#AAAAAA';
  ctx.fillText(label, x, y);

  ctx.textAlign = 'right';
  ctx.fillStyle = '#FFFFFF';
  ctx.fillText(value, x + width, y);
}

export function drawSortControls(
  ctx: CanvasRenderingContext2D,
  x: number,
  y: number,
  sortBy: SortOption,
  sortDirection: SortDirection
): void {
  const buttonWidth = 100;
  const buttonHeight = 30;
  const buttonSpacing = 10;

  ctx.font = '12px Arial, sans-serif';
  ctx.textAlign = 'left';
  ctx.fillStyle = '#888899';
  ctx.fillText('Sort:', x, y + 20);

  const startX = x + 50;

  for (let i = 0; i < SORT_OPTIONS.length; i++) {
    const option = SORT_OPTIONS[i];
    if (!option) continue;

    const btnX = startX + i * (buttonWidth + buttonSpacing);
    const isActive = sortBy === option.id;

    // Button background
    if (isActive) {
      const gradient = ctx.createLinearGradient(btnX, y, btnX, y + buttonHeight);
      gradient.addColorStop(0, '#660000');
      gradient.addColorStop(1, '#330000');
      ctx.fillStyle = gradient;
    } else {
      ctx.fillStyle = '#2a2a3e';
    }

    roundRect(ctx, btnX, y, buttonWidth, buttonHeight, 6);
    ctx.fill();

    // Button border
    ctx.strokeStyle = isActive ? '#FF4444' : '#444466';
    ctx.lineWidth = isActive ? 2 : 1;
    roundRect(ctx, btnX, y, buttonWidth, buttonHeight, 6);
    ctx.stroke();

    // Button text
    ctx.font = isActive ? 'bold 12px Arial' : '12px Arial';
    ctx.textAlign = 'center';
    ctx.textBaseline = 'middle';
    ctx.fillStyle = isActive ? '#FFFFFF' : '#888899';

    let text = option.label;
    if (isActive) {
      text += sortDirection === 'asc' ? ' ↑' : ' ↓';
    }
    ctx.fillText(text, btnX + buttonWidth / 2, y + buttonHeight / 2);
  }
}

export function drawActionButtons(ctx: CanvasRenderingContext2D, x: number, y: number): void {
  const buttonWidth = 120;
  const buttonHeight = 35;
  const buttonSpacing = 15;

  for (let i = 0; i < ACTION_BUTTONS.length; i++) {
    const button = ACTION_BUTTONS[i];
    if (!button) continue;

    const btnX = x + i * (buttonWidth + buttonSpacing);

    // Button background
    const gradient = ctx.createLinearGradient(btnX, y, btnX, y + buttonHeight);
    gradient.addColorStop(0, button.color);
    gradient.addColorStop(1, darkenColor(button.color, 20));
    ctx.fillStyle = gradient;

    roundRect(ctx, btnX, y, buttonWidth, buttonHeight, 6);
    ctx.fill();

    // Button border
    ctx.strokeStyle = button.color;
    ctx.lineWidth = 2;
    roundRect(ctx, btnX, y, buttonWidth, buttonHeight, 6);
    ctx.stroke();

    // Button text
    ctx.font = 'bold 12px Arial';
    ctx.textAlign = 'center';
    ctx.textBaseline = 'middle';
    ctx.fillStyle = '#FFFFFF';
    ctx.fillText(button.label, btnX + buttonWidth / 2, y + buttonHeight / 2);
  }
}

export function drawMessage(
  ctx: CanvasRenderingContext2D,
  canvasWidth: number,
  canvasHeight: number,
  messageText: string,
  messageIsError: boolean
): void {
  if (!messageText) return;

  const msgY = canvasHeight / 2 + LAYOUT.PANEL_HEIGHT / 2 - 30;

  ctx.font = '14px Arial, sans-serif';
  ctx.textAlign = 'center';
  ctx.textBaseline = 'middle';
  ctx.fillStyle = messageIsError ? '#FF4444' : '#44AA44';
  ctx.fillText(messageText, canvasWidth / 2, msgY);
}

export function drawConfirmationModal(
  ctx: CanvasRenderingContext2D,
  canvasWidth: number,
  canvasHeight: number
): void {
  // Dark overlay
  ctx.fillStyle = 'rgba(0, 0, 0, 0.8)';
  ctx.fillRect(0, 0, canvasWidth, canvasHeight);

  // Dialog box
  const dialogWidth = 400;
  const dialogHeight = 200;
  const dialogX = (canvasWidth - dialogWidth) / 2;
  const dialogY = (canvasHeight - dialogHeight) / 2;

  // Dialog background
  ctx.fillStyle = '#1a1a2e';
  roundRect(ctx, dialogX, dialogY, dialogWidth, dialogHeight, 12);
  ctx.fill();

  // Dialog border
  ctx.strokeStyle = '#FF4444';
  ctx.lineWidth = 3;
  roundRect(ctx, dialogX, dialogY, dialogWidth, dialogHeight, 12);
  ctx.stroke();

  // Warning title
  ctx.font = 'bold 24px Arial';
  ctx.textAlign = 'center';
  ctx.textBaseline = 'middle';
  ctx.fillStyle = '#FF4444';
  ctx.fillText('WARNING!', canvasWidth / 2, dialogY + 40);

  // Warning text
  ctx.font = '14px Arial';
  ctx.fillStyle = '#FFFFFF';
  wrapText(
    ctx,
    'This will permanently delete ALL high scores, quest progress, and statistics.',
    canvasWidth / 2,
    dialogY + 80,
    dialogWidth - 40,
    20
  );

  // Buttons
  const btnWidth = 120;
  const btnHeight = 35;
  const btnY = dialogY + dialogHeight - 60;

  // Cancel button
  const cancelX = canvasWidth / 2 - btnWidth - 10;
  ctx.fillStyle = '#444466';
  roundRect(ctx, cancelX, btnY, btnWidth, btnHeight, 6);
  ctx.fill();
  ctx.strokeStyle = '#666688';
  ctx.lineWidth = 2;
  roundRect(ctx, cancelX, btnY, btnWidth, btnHeight, 6);
  ctx.stroke();

  ctx.font = 'bold 14px Arial';
  ctx.fillStyle = '#FFFFFF';
  ctx.fillText('Cancel', canvasWidth / 2 - btnWidth / 2 - 10, btnY + btnHeight / 2);

  // Confirm button
  const confirmX = canvasWidth / 2 + 10;
  ctx.fillStyle = '#AA4444';
  roundRect(ctx, confirmX, btnY, btnWidth, btnHeight, 6);
  ctx.fill();
  ctx.strokeStyle = '#FF4444';
  ctx.lineWidth = 2;
  roundRect(ctx, confirmX, btnY, btnWidth, btnHeight, 6);
  ctx.stroke();

  ctx.fillStyle = '#FFFFFF';
  ctx.fillText('Yes, Reset', canvasWidth / 2 + btnWidth / 2 + 10, btnY + btnHeight / 2);
}
