/**
 * Quest Menu UI
 *
 * Displays available quests with their completion status.
 * Allows players to select and start quests.
 */

import type { QuestId } from '../../types';
import { getQuestData, type QuestData, getQuestStats, ALL_QUESTS } from '../data/quests';
import type { ProgressionManager } from '../progression/ProgressionManager';

export type QuestStatus = 'locked' | 'available' | 'completed';

export interface QuestMenuState {
  quests: Map<QuestId, QuestStatus>;
  selectedQuest: QuestId | null;
  completedQuests: QuestId[];
}

export interface QuestMenuUIOptions {
  canvas: HTMLCanvasElement;
  progressionManager: ProgressionManager;
  onStartQuest: (questId: QuestId) => void;
  onBack?: () => void;
}

export interface QuestButton {
  questId: QuestId;
  x: number;
  y: number;
  width: number;
  height: number;
  status: QuestStatus;
  hovered: boolean;
}

export class QuestMenuUI {
  private canvas: HTMLCanvasElement;
  private ctx: CanvasRenderingContext2D;
  private options: QuestMenuUIOptions;
  private progressionManager: ProgressionManager;

  // UI State
  private isVisible = false;
  private questButtons: QuestButton[] = [];
  private selectedQuest: QuestId | null = null;
  private scrollOffset = 0;

  // Input handling
  private keyHandler: (e: KeyboardEvent) => void;
  private clickHandler: (e: MouseEvent) => void;
  private mouseMoveHandler: (e: MouseEvent) => void;

  // Layout constants
  private readonly GRID_COLS = 4;
  private readonly BUTTON_WIDTH = 180;
  private readonly BUTTON_HEIGHT = 80;
  private readonly BUTTON_SPACING_X = 20;
  private readonly BUTTON_SPACING_Y = 20;
  private readonly PADDING = 40;
  private readonly PANEL_WIDTH = 350;

  constructor(options: QuestMenuUIOptions) {
    this.canvas = options.canvas;
    this.progressionManager = options.progressionManager;
    const ctx = this.canvas.getContext('2d');
    if (!ctx) {
      throw new Error('Could not get canvas context');
    }
    this.ctx = ctx;
    this.options = options;

    // Bind input handlers
    this.keyHandler = this.handleKeyDown.bind(this);
    this.clickHandler = this.handleClick.bind(this);
    this.mouseMoveHandler = this.handleMouseMove.bind(this);

    this.attachEventListeners();
  }

  /**
   * Show the quest menu UI
   */
  show(): void {
    this.isVisible = true;
    this.selectedQuest = null;
    this.scrollOffset = 0;
    this.buildQuestButtons();
  }

  /**
   * Hide the quest menu UI
   */
  hide(): void {
    this.isVisible = false;
    this.questButtons = [];
    this.selectedQuest = null;
  }

  /**
   * Check if UI is visible
   */
  isShown(): boolean {
    return this.isVisible;
  }

  /**
   * Refresh quest data (call when progression changes)
   */
  refresh(): void {
    if (this.isVisible) {
      this.buildQuestButtons();
    }
  }

  /**
   * Render the UI
   */
  render(): void {
    if (!this.isVisible) return;

    const width = this.canvas.width;
    const height = this.canvas.height;

    // Draw background
    this.ctx.fillStyle = '#1a1a2e';
    this.ctx.fillRect(0, 0, width, height);

    // Draw title
    this.drawTitle(width);

    // Draw quest grid
    this.drawQuestGrid();

    // Draw info panel
    this.drawInfoPanel(width, height);

    // Draw back button
    this.drawBackButton(width, height);

    // Draw progress summary
    this.drawProgressSummary(width, height);
  }

  private buildQuestButtons(): void {
    const completedQuests = this.progressionManager.getCompletedQuests();

    this.questButtons = ALL_QUESTS.map((quest: QuestData, index: number) => {
      const col = index % this.GRID_COLS;
      const row = Math.floor(index / this.GRID_COLS);

      let status: QuestStatus = 'locked';
      if (completedQuests.includes(quest.id)) {
        status = 'completed';
      } else if (this.progressionManager.isQuestUnlocked(quest.id)) {
        status = 'available';
      }

      return {
        questId: quest.id,
        x: this.PADDING + col * (this.BUTTON_WIDTH + this.BUTTON_SPACING_X),
        y: 100 + row * (this.BUTTON_HEIGHT + this.BUTTON_SPACING_Y) - this.scrollOffset,
        width: this.BUTTON_WIDTH,
        height: this.BUTTON_HEIGHT,
        status,
        hovered: false,
      };
    });
  }

  private drawTitle(width: number): void {
    const title = 'QUEST SELECT';
    this.ctx.font = 'bold 36px Arial, sans-serif';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'top';

    // Draw shadow
    this.ctx.fillStyle = 'rgba(0, 0, 0, 0.5)';
    this.ctx.fillText(title, width / 2 + 2, 12);

    // Draw text
    this.ctx.fillStyle = '#FFD700';
    this.ctx.fillText(title, width / 2, 10);

    // Draw underline
    this.ctx.strokeStyle = '#FFD700';
    this.ctx.lineWidth = 2;
    this.ctx.beginPath();
    this.ctx.moveTo(width / 2 - 100, 55);
    this.ctx.lineTo(width / 2 + 100, 55);
    this.ctx.stroke();
  }

  private drawQuestGrid(): void {
    for (const button of this.questButtons) {
      // Skip if out of view
      if (button.y < 80 || button.y > this.canvas.height - 100) continue;

      this.drawQuestButton(button);
    }
  }

  private drawQuestButton(button: QuestButton): void {
    const quest = getQuestData(button.questId);
    if (!quest) return;

    const { x, y, width, height, status, hovered } = button;

    // Button background based on status
    let bgColor: string;
    switch (status) {
      case 'completed':
        bgColor = hovered ? '#2d5016' : '#1e3a0f';
        break;
      case 'available':
        bgColor = hovered ? '#8B0000' : '#4B0000';
        break;
      default:
        bgColor = '#333';
        break;
    }

    // Draw button background
    this.ctx.fillStyle = bgColor;
    this.roundRect(x, y, width, height, 8);
    this.ctx.fill();

    // Draw border
    if (this.selectedQuest === button.questId) {
      this.ctx.strokeStyle = '#FFD700';
      this.ctx.lineWidth = 3;
    } else if (hovered) {
      this.ctx.strokeStyle = '#AAA';
      this.ctx.lineWidth = 2;
    } else {
      this.ctx.strokeStyle = '#555';
      this.ctx.lineWidth = 1;
    }
    this.roundRect(x, y, width, height, 8);
    this.ctx.stroke();

    // Draw quest name
    this.ctx.font = 'bold 14px Arial, sans-serif';
    this.ctx.fillStyle = status === 'locked' ? '#777' : '#FFF';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';

    // Truncate name if too long
    let name = quest.name;
    const metrics = this.ctx.measureText(name);
    if (metrics.width > width - 10) {
      while (this.ctx.measureText(`${name}...`).width > width - 10 && name.length > 0) {
        name = name.slice(0, -1);
      }
      name = `${name}...`;
    }
    this.ctx.fillText(name, x + width / 2, y + height / 2);

    // Draw status indicator
    if (status === 'completed') {
      this.ctx.fillStyle = '#FFD700';
      this.ctx.font = '16px Arial, sans-serif';
      this.ctx.fillText('★', x + width - 15, y + 15);
    } else if (status === 'locked') {
      this.ctx.fillStyle = '#555';
      this.ctx.font = '14px Arial, sans-serif';
      this.ctx.fillText('🔒', x + width - 15, y + 15);
    }

    // Draw bonus indicator
    if (quest.isBonus) {
      this.ctx.fillStyle = '#FF6B6B';
      this.ctx.font = '10px Arial, sans-serif';
      this.ctx.fillText('BONUS', x + width / 2, y + height - 8);
    }
  }

  private drawInfoPanel(width: number, height: number): void {
    const panelX = width - this.PANEL_WIDTH - this.PADDING;
    const panelY = 80;
    const panelHeight = height - 200;

    // Panel background
    this.ctx.fillStyle = 'rgba(0, 0, 0, 0.5)';
    this.roundRect(panelX, panelY, this.PANEL_WIDTH, panelHeight, 8);
    this.ctx.fill();

    // Panel border
    this.ctx.strokeStyle = '#555';
    this.ctx.lineWidth = 2;
    this.roundRect(panelX, panelY, this.PANEL_WIDTH, panelHeight, 8);
    this.ctx.stroke();

    if (!this.selectedQuest) {
      // Draw placeholder text
      this.ctx.font = '16px Arial, sans-serif';
      this.ctx.fillStyle = '#777';
      this.ctx.textAlign = 'center';
      this.ctx.fillText('Select a quest', panelX + this.PANEL_WIDTH / 2, panelY + 50);
      this.ctx.fillText('to view details', panelX + this.PANEL_WIDTH / 2, panelY + 75);
      return;
    }

    const quest = getQuestData(this.selectedQuest);
    if (!quest) return;

    const highScore = this.progressionManager.getQuestHighScore(this.selectedQuest);

    let y = panelY + 20;

    // Quest name
    this.ctx.font = 'bold 20px Arial, sans-serif';
    this.ctx.fillStyle = '#FFD700';
    this.ctx.textAlign = 'center';
    this.wrapText(quest.name, panelX + this.PANEL_WIDTH / 2, y, this.PANEL_WIDTH - 20, 24);
    y += 50;

    // Description
    this.ctx.font = '14px Arial, sans-serif';
    this.ctx.fillStyle = '#CCC';
    this.wrapText(quest.description, panelX + this.PANEL_WIDTH / 2, y, this.PANEL_WIDTH - 20, 18);
    y += 60;

    // Objectives
    this.ctx.font = 'bold 14px Arial, sans-serif';
    this.ctx.fillStyle = '#FFF';
    this.ctx.fillText('Objectives:', panelX + this.PANEL_WIDTH / 2, y);
    y += 25;

    this.ctx.font = '13px Arial, sans-serif';
    this.ctx.fillStyle = '#AAA';
    for (const objective of quest.objectives) {
      this.ctx.fillText(`• ${objective.description}`, panelX + 15, y);
      y += 20;
    }
    y += 15;

    // High score info
    if (highScore) {
      this.ctx.font = 'bold 14px Arial, sans-serif';
      this.ctx.fillStyle = '#FFF';
      this.ctx.fillText('Best Score:', panelX + this.PANEL_WIDTH / 2, y);
      y += 20;

      this.ctx.font = '13px Arial, sans-serif';
      this.ctx.fillStyle = '#FFD700';
      this.ctx.fillText(
        `Score: ${highScore.bestScore.toLocaleString()}`,
        panelX + this.PANEL_WIDTH / 2,
        y
      );
      y += 18;

      const minutes = Math.floor(highScore.bestTime / 60);
      const seconds = Math.floor(highScore.bestTime % 60);
      this.ctx.fillText(
        `Time: ${minutes}:${seconds.toString().padStart(2, '0')}`,
        panelX + this.PANEL_WIDTH / 2,
        y
      );
      y += 18;

      this.ctx.fillStyle = '#888';
      this.ctx.font = '11px Arial, sans-serif';
      const date = new Date(highScore.completedAt).toLocaleDateString();
      this.ctx.fillText(`Completed: ${date}`, panelX + this.PANEL_WIDTH / 2, y);
      y += 30;
    }

    // Start button (only for available/completed quests)
    const button = this.questButtons.find((b) => b.questId === this.selectedQuest);
    if (button && button.status !== 'locked') {
      y = panelY + panelHeight - 50;
      this.drawStartButton(panelX + this.PANEL_WIDTH / 2 - 60, y, 120, 35);
    }
  }

  private drawStartButton(x: number, y: number, width: number, height: number): void {
    const isHovered =
      this.questButtons.find((b) => b.questId === this.selectedQuest)?.hovered ?? false;

    // Button background
    this.ctx.fillStyle = isHovered ? '#228B22' : '#006400';
    this.roundRect(x, y, width, height, 6);
    this.ctx.fill();

    // Border
    this.ctx.strokeStyle = '#32CD32';
    this.ctx.lineWidth = 2;
    this.roundRect(x, y, width, height, 6);
    this.ctx.stroke();

    // Text
    this.ctx.font = 'bold 16px Arial, sans-serif';
    this.ctx.fillStyle = '#FFF';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';
    this.ctx.fillText('START QUEST', x + width / 2, y + height / 2);
  }

  private drawBackButton(_width: number, height: number): void {
    const x = 20;
    const y = height - 60;
    const btnWidth = 100;
    const btnHeight = 40;

    this.ctx.fillStyle = '#444';
    this.roundRect(x, y, btnWidth, btnHeight, 6);
    this.ctx.fill();

    this.ctx.strokeStyle = '#666';
    this.ctx.lineWidth = 2;
    this.roundRect(x, y, btnWidth, btnHeight, 6);
    this.ctx.stroke();

    this.ctx.font = 'bold 14px Arial, sans-serif';
    this.ctx.fillStyle = '#FFF';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';
    this.ctx.fillText('← BACK', x + btnWidth / 2, y + btnHeight / 2);
  }

  private drawProgressSummary(width: number, height: number): void {
    const completedQuests = this.progressionManager.getCompletedQuests();
    const questStats = getQuestStats();

    this.ctx.font = '14px Arial, sans-serif';
    this.ctx.fillStyle = '#AAA';
    this.ctx.textAlign = 'right';
    this.ctx.fillText(
      `${completedQuests.length} / ${questStats.mainQuests} quests completed`,
      width - 20,
      height - 30
    );
  }

  private handleKeyDown(e: KeyboardEvent): void {
    if (!this.isVisible) return;

    switch (e.key) {
      case 'Escape':
        this.options.onBack?.();
        break;
      case 'Enter':
        if (this.selectedQuest) {
          const button = this.questButtons.find((b) => b.questId === this.selectedQuest);
          if (button && button.status !== 'locked') {
            this.options.onStartQuest(this.selectedQuest);
          }
        }
        break;
    }
  }

  private handleClick(e: MouseEvent): void {
    if (!this.isVisible) return;

    const rect = this.canvas.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    // Check back button
    if (x >= 20 && x <= 120 && y >= this.canvas.height - 60 && y <= this.canvas.height - 20) {
      this.options.onBack?.();
      return;
    }

    // Check quest buttons
    for (const button of this.questButtons) {
      if (
        x >= button.x &&
        x <= button.x + button.width &&
        y >= button.y &&
        y <= button.y + button.height
      ) {
        this.selectedQuest = button.questId;

        // Check if clicking start button on selected quest
        const panelX = this.canvas.width - this.PANEL_WIDTH - this.PADDING;
        const panelY = 80;
        const panelHeight = this.canvas.height - 200;
        const startBtnY = panelY + panelHeight - 50;

        if (
          button.status !== 'locked' &&
          x >= panelX + this.PANEL_WIDTH / 2 - 60 &&
          x <= panelX + this.PANEL_WIDTH / 2 + 60 &&
          y >= startBtnY &&
          y <= startBtnY + 35
        ) {
          this.options.onStartQuest(button.questId);
        }
        return;
      }
    }

    // Deselect if clicking elsewhere
    this.selectedQuest = null;
  }

  private handleMouseMove(e: MouseEvent): void {
    if (!this.isVisible) return;

    const rect = this.canvas.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    for (const button of this.questButtons) {
      button.hovered =
        x >= button.x &&
        x <= button.x + button.width &&
        y >= button.y &&
        y <= button.y + button.height;
    }
  }

  private attachEventListeners(): void {
    window.addEventListener('keydown', this.keyHandler);
    this.canvas.addEventListener('click', this.clickHandler);
    this.canvas.addEventListener('mousemove', this.mouseMoveHandler);
  }

  detachEventListeners(): void {
    window.removeEventListener('keydown', this.keyHandler);
    this.canvas.removeEventListener('click', this.clickHandler);
    this.canvas.removeEventListener('mousemove', this.mouseMoveHandler);
  }

  private roundRect(x: number, y: number, width: number, height: number, radius: number): void {
    this.ctx.beginPath();
    this.ctx.moveTo(x + radius, y);
    this.ctx.lineTo(x + width - radius, y);
    this.ctx.quadraticCurveTo(x + width, y, x + width, y + radius);
    this.ctx.lineTo(x + width, y + height - radius);
    this.ctx.quadraticCurveTo(x + width, y + height, x + width - radius, y + height);
    this.ctx.lineTo(x + radius, y + height);
    this.ctx.quadraticCurveTo(x, y + height, x, y + height - radius);
    this.ctx.lineTo(x, y + radius);
    this.ctx.quadraticCurveTo(x, y, x + radius, y);
    this.ctx.closePath();
  }

  private wrapText(text: string, x: number, y: number, maxWidth: number, lineHeight: number): void {
    const words = text.split(' ');
    let line = '';
    let currentY = y;

    for (let i = 0; i < words.length; i++) {
      const testLine = `${line}${words[i]} `;
      const metrics = this.ctx.measureText(testLine);
      const testWidth = metrics.width;

      if (testWidth > maxWidth && i > 0) {
        this.ctx.fillText(line.trim(), x, currentY);
        line = `${words[i]} `;
        currentY += lineHeight;
      } else {
        line = testLine;
      }
    }

    this.ctx.fillText(line.trim(), x, currentY);
  }

  /**
   * Destroy the UI and clean up
   */
  destroy(): void {
    this.detachEventListeners();
    this.hide();
  }
}
