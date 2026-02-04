/**
 * High Scores UI
 *
 * Displays high scores for Survival, Rush, and Quest modes.
 * Allows sorting, filtering, import/export, and reset functionality.
 */

import type { QuestId } from '../../types';
import { ALL_QUESTS } from '../data/quests';
import type { ProgressionManager, QuestHighScore } from '../progression/ProgressionManager';

export type HighScoreTab = 'SURVIVAL' | 'QUESTS' | 'RUSH';
export type SortOption = 'score' | 'time' | 'date';
export type SortDirection = 'asc' | 'desc';

export interface HighScoresUIOptions {
  canvas: HTMLCanvasElement;
  progressionManager: ProgressionManager;
  onBack: () => void;
}

interface QuestScoreEntry {
  questId: QuestId;
  questName: string;
  highScore: QuestHighScore;
}

export class HighScoresUI {
  private canvas: HTMLCanvasElement;
  private ctx: CanvasRenderingContext2D;
  private options: HighScoresUIOptions;
  private progressionManager: ProgressionManager;

  // UI State
  private isVisible = false;
  private currentTab: HighScoreTab = 'SURVIVAL';
  private sortBy: SortOption = 'score';
  private sortDirection: SortDirection = 'desc';
  private showConfirmation = false;
  private messageText = '';
  private messageTimer = 0;
  private messageIsError = false;

  // Layout constants
  private readonly PANEL_WIDTH = 700;
  private readonly PANEL_HEIGHT = 500;
  private readonly TAB_HEIGHT = 40;
  private readonly HEADER_HEIGHT = 50;
  private readonly ROW_HEIGHT = 35;
  private readonly PADDING = 30;

  // Input handling
  private keyHandler: (e: KeyboardEvent) => void;
  private clickHandler: (e: MouseEvent) => void;
  private mouseMoveHandler: (e: MouseEvent) => void;
  private fileInput: HTMLInputElement | null = null;

  constructor(options: HighScoresUIOptions) {
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
    this.createFileInput();
  }

  private createFileInput(): void {
    this.fileInput = document.createElement('input');
    this.fileInput.type = 'file';
    this.fileInput.accept = '.json';
    this.fileInput.style.display = 'none';
    this.fileInput.addEventListener('change', this.handleFileSelect.bind(this));
    document.body.appendChild(this.fileInput);
  }

  private handleFileSelect(event: Event): void {
    const target = event.target as HTMLInputElement;
    const file = target.files?.[0];
    if (!file) return;

    const reader = new FileReader();
    reader.onload = (e) => {
      try {
        const content = e.target?.result as string;
        const success = this.progressionManager.importData(content);
        if (success) {
          this.showMessage('Scores imported successfully', false);
        } else {
          this.showMessage('Failed to import scores', true);
        }
      } catch {
        this.showMessage('Invalid file format', true);
      }
    };
    reader.readAsText(file);

    // Reset input
    target.value = '';
  }

  /**
   * Show the high scores UI
   */
  show(): void {
    this.isVisible = true;
    this.currentTab = 'SURVIVAL';
    this.sortBy = 'score';
    this.sortDirection = 'desc';
    this.showConfirmation = false;
    this.messageText = '';
    this.messageTimer = 0;
  }

  /**
   * Hide the high scores UI
   */
  hide(): void {
    this.isVisible = false;
    this.showConfirmation = false;
    this.messageText = '';
    this.messageTimer = 0;
  }

  /**
   * Check if UI is visible
   */
  isShown(): boolean {
    return this.isVisible;
  }

  /**
   * Update animation and timers
   */
  update(dt: number): void {
    if (!this.isVisible) return;

    if (this.messageTimer > 0) {
      this.messageTimer -= dt;
      if (this.messageTimer <= 0) {
        this.messageText = '';
      }
    }
  }

  /**
   * Render the UI
   */
  render(): void {
    if (!this.isVisible) return;

    const width = this.canvas.width;
    const height = this.canvas.height;

    // Draw semi-transparent overlay
    this.ctx.fillStyle = 'rgba(0, 0, 0, 0.7)';
    this.ctx.fillRect(0, 0, width, height);

    // Draw panel
    this.drawPanel(width, height);

    // Draw title
    this.drawTitle(width);

    // Draw tabs
    this.drawTabs(width);

    // Draw content based on current tab
    const centerX = width / 2;
    const contentY = height / 2 - this.PANEL_HEIGHT / 2 + this.TAB_HEIGHT + this.HEADER_HEIGHT + 20;
    const contentWidth = this.PANEL_WIDTH - this.PADDING * 2;

    switch (this.currentTab) {
      case 'SURVIVAL':
        this.drawSurvivalTab(centerX, contentY, contentWidth);
        break;
      case 'QUESTS':
        this.drawQuestsTab(centerX, contentY, contentWidth);
        break;
      case 'RUSH':
        this.drawRushTab(centerX, contentY, contentWidth);
        break;
    }

    // Draw sort controls
    this.drawSortControls(centerX - contentWidth / 2, contentY + 200);

    // Draw action buttons
    this.drawActionButtons(centerX - contentWidth / 2, contentY + 260);

    // Draw message if any
    this.drawMessage(width, height);

    // Draw confirmation modal if showing
    if (this.showConfirmation) {
      this.drawConfirmationModal(width, height);
    }
  }

  private drawPanel(width: number, height: number): void {
    const panelX = (width - this.PANEL_WIDTH) / 2;
    const panelY = (height - this.PANEL_HEIGHT) / 2;

    // Panel shadow
    this.ctx.fillStyle = 'rgba(0, 0, 0, 0.5)';
    this.roundRect(panelX + 6, panelY + 6, this.PANEL_WIDTH, this.PANEL_HEIGHT, 12);
    this.ctx.fill();

    // Panel background
    const gradient = this.ctx.createLinearGradient(
      panelX,
      panelY,
      panelX,
      panelY + this.PANEL_HEIGHT
    );
    gradient.addColorStop(0, '#1a1a2e');
    gradient.addColorStop(1, '#0f0f1a');

    this.ctx.fillStyle = gradient;
    this.roundRect(panelX, panelY, this.PANEL_WIDTH, this.PANEL_HEIGHT, 12);
    this.ctx.fill();

    // Panel border
    this.ctx.strokeStyle = '#333355';
    this.ctx.lineWidth = 2;
    this.roundRect(panelX, panelY, this.PANEL_WIDTH, this.PANEL_HEIGHT, 12);
    this.ctx.stroke();
  }

  private drawTitle(width: number): void {
    const titleY = this.canvas.height / 2 - this.PANEL_HEIGHT / 2 + 40;

    this.ctx.font = 'bold 32px Arial, sans-serif';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';

    // Glow effect
    this.ctx.shadowColor = '#8B0000';
    this.ctx.shadowBlur = 15;

    this.ctx.fillStyle = '#FFD700';
    this.ctx.fillText('HIGH SCORES', width / 2, titleY);

    this.ctx.shadowBlur = 0;

    // Underline
    this.ctx.strokeStyle = '#8B0000';
    this.ctx.lineWidth = 2;
    this.ctx.beginPath();
    this.ctx.moveTo(width / 2 - 80, titleY + 20);
    this.ctx.lineTo(width / 2 + 80, titleY + 20);
    this.ctx.stroke();
  }

  private drawTabs(width: number): void {
    const tabs: HighScoreTab[] = ['SURVIVAL', 'QUESTS', 'RUSH'];
    const tabWidth = 140;
    const tabHeight = this.TAB_HEIGHT;
    const startX = width / 2 - (tabs.length * tabWidth) / 2;
    const tabY = this.canvas.height / 2 - this.PANEL_HEIGHT / 2 + 80;

    for (let i = 0; i < tabs.length; i++) {
      const tab = tabs[i];
      if (!tab) continue;

      const x = startX + i * tabWidth;
      const isActive = this.currentTab === tab;

      // Tab background
      if (isActive) {
        const gradient = this.ctx.createLinearGradient(x, tabY, x, tabY + tabHeight);
        gradient.addColorStop(0, '#660000');
        gradient.addColorStop(1, '#330000');
        this.ctx.fillStyle = gradient;
      } else {
        this.ctx.fillStyle = '#2a2a3e';
      }

      this.ctx.beginPath();
      this.ctx.moveTo(x + 8, tabY);
      this.ctx.lineTo(x + tabWidth - 8, tabY);
      this.ctx.quadraticCurveTo(x + tabWidth, tabY, x + tabWidth, tabY + 8);
      this.ctx.lineTo(x + tabWidth, tabY + tabHeight);
      this.ctx.lineTo(x, tabY + tabHeight);
      this.ctx.lineTo(x, tabY + 8);
      this.ctx.quadraticCurveTo(x, tabY, x + 8, tabY);
      this.ctx.closePath();
      this.ctx.fill();

      // Tab border
      this.ctx.strokeStyle = isActive ? '#FF4444' : '#444466';
      this.ctx.lineWidth = isActive ? 2 : 1;
      this.ctx.stroke();

      // Tab text
      this.ctx.font = isActive ? 'bold 14px Arial' : '14px Arial';
      this.ctx.textAlign = 'center';
      this.ctx.textBaseline = 'middle';
      this.ctx.fillStyle = isActive ? '#FFFFFF' : '#888899';
      this.ctx.fillText(tab, x + tabWidth / 2, tabY + tabHeight / 2);
    }
  }

  private drawSurvivalTab(centerX: number, startY: number, width: number): void {
    const highScore = this.progressionManager.getSurvivalHighScore();

    // Section title
    this.ctx.font = 'bold 20px Arial, sans-serif';
    this.ctx.textAlign = 'center';
    this.ctx.fillStyle = '#FFD700';
    this.ctx.fillText('SURVIVAL MODE', centerX, startY);

    if (highScore.bestScore === 0) {
      // No records yet
      this.ctx.font = '16px Arial, sans-serif';
      this.ctx.fillStyle = '#888899';
      this.ctx.fillText('No survival records yet', centerX, startY + 50);
      return;
    }

    // Draw stats
    const statsY = startY + 50;
    const lineHeight = 40;

    this.drawStatRow(
      'Best Score:',
      highScore.bestScore.toLocaleString(),
      centerX - width / 4,
      statsY,
      width / 2
    );
    this.drawStatRow(
      'Best Time:',
      this.formatTime(highScore.bestTime),
      centerX - width / 4,
      statsY + lineHeight,
      width / 2
    );
    this.drawStatRow(
      'Best Level:',
      highScore.bestLevel.toString(),
      centerX - width / 4,
      statsY + lineHeight * 2,
      width / 2
    );

    const date = new Date(highScore.achievedAt).toLocaleDateString();
    this.drawStatRow('Achieved:', date, centerX - width / 4, statsY + lineHeight * 3, width / 2);
  }

  private drawQuestsTab(centerX: number, startY: number, width: number): void {
    // Section title
    this.ctx.font = 'bold 20px Arial, sans-serif';
    this.ctx.textAlign = 'center';
    this.ctx.fillStyle = '#FFD700';
    this.ctx.fillText('QUEST COMPLETIONS', centerX, startY);

    // Get quest scores
    const questScores = this.getQuestScores();

    if (questScores.length === 0) {
      this.ctx.font = '16px Arial, sans-serif';
      this.ctx.fillStyle = '#888899';
      this.ctx.fillText('No quests completed yet', centerX, startY + 50);
      return;
    }

    // Sort quest scores
    const sortedScores = this.sortQuestScores(questScores);

    // Draw headers
    const headersY = startY + 40;
    const colWidth = width / 4;

    this.ctx.font = 'bold 14px Arial, sans-serif';
    this.ctx.fillStyle = '#AAAAAA';
    this.ctx.textAlign = 'left';
    this.ctx.fillText('Quest', centerX - width / 2, headersY);
    this.ctx.textAlign = 'center';
    this.ctx.fillText('Score', centerX - width / 2 + colWidth * 1.5, headersY);
    this.ctx.fillText('Time', centerX - width / 2 + colWidth * 2.5, headersY);
    this.ctx.fillText('Date', centerX - width / 2 + colWidth * 3.5, headersY);

    // Draw rows
    const rowY = headersY + 25;
    const maxRows = 4;

    for (let i = 0; i < Math.min(sortedScores.length, maxRows); i++) {
      const entry = sortedScores[i];
      if (!entry) continue;

      const y = rowY + i * this.ROW_HEIGHT;
      const isEven = i % 2 === 0;

      // Row background
      if (isEven) {
        this.ctx.fillStyle = 'rgba(255, 255, 255, 0.05)';
        this.ctx.fillRect(centerX - width / 2, y - 15, width, this.ROW_HEIGHT);
      }

      // Truncate quest name if too long
      let questName = entry.questName;
      this.ctx.font = '14px Arial, sans-serif';
      this.ctx.textAlign = 'left';
      this.ctx.fillStyle = '#FFFFFF';

      const maxNameWidth = colWidth - 10;
      while (this.ctx.measureText(`${questName}...`).width > maxNameWidth && questName.length > 0) {
        questName = questName.slice(0, -1);
      }
      if (questName.length < entry.questName.length) {
        questName = `${questName}...`;
      }
      this.ctx.fillText(questName, centerX - width / 2, y);

      // Score
      this.ctx.textAlign = 'center';
      this.ctx.fillText(
        entry.highScore.bestScore.toLocaleString(),
        centerX - width / 2 + colWidth * 1.5,
        y
      );

      // Time
      this.ctx.fillText(
        this.formatTime(entry.highScore.bestTime),
        centerX - width / 2 + colWidth * 2.5,
        y
      );

      // Date
      const date = new Date(entry.highScore.completedAt).toLocaleDateString();
      this.ctx.fillText(date, centerX - width / 2 + colWidth * 3.5, y);
    }

    if (sortedScores.length > maxRows) {
      this.ctx.font = '12px Arial, sans-serif';
      this.ctx.fillStyle = '#666666';
      this.ctx.textAlign = 'center';
      this.ctx.fillText(
        `... and ${sortedScores.length - maxRows} more`,
        centerX,
        rowY + maxRows * this.ROW_HEIGHT + 10
      );
    }
  }

  private drawRushTab(centerX: number, startY: number, width: number): void {
    const highScore = this.progressionManager.getSurvivalHighScore();

    // Section title
    this.ctx.font = 'bold 20px Arial, sans-serif';
    this.ctx.textAlign = 'center';
    this.ctx.fillStyle = '#FFD700';
    this.ctx.fillText('RUSH MODE', centerX, startY);

    // Note about Rush sharing survival scores
    this.ctx.font = '12px Arial, sans-serif';
    this.ctx.fillStyle = '#888899';
    this.ctx.fillText('(Rush mode uses Survival high scores)', centerX, startY + 25);

    if (highScore.bestScore === 0) {
      // No records yet
      this.ctx.font = '16px Arial, sans-serif';
      this.ctx.fillStyle = '#888899';
      this.ctx.fillText('No rush records yet', centerX, startY + 60);
      return;
    }

    // Draw best time prominently (primary Rush metric)
    this.ctx.font = 'bold 48px Arial, sans-serif';
    this.ctx.fillStyle = '#FFD700';
    this.ctx.fillText(this.formatTime(highScore.bestTime), centerX, startY + 90);

    this.ctx.font = '14px Arial, sans-serif';
    this.ctx.fillStyle = '#AAAAAA';
    this.ctx.fillText('Best Time', centerX, startY + 115);

    // Draw additional stats
    const statsY = startY + 160;
    const lineHeight = 35;

    this.drawStatRow(
      'Best Score:',
      highScore.bestScore.toLocaleString(),
      centerX - width / 4,
      statsY,
      width / 2
    );
    this.drawStatRow(
      'Best Level:',
      highScore.bestLevel.toString(),
      centerX - width / 4,
      statsY + lineHeight,
      width / 2
    );

    const date = new Date(highScore.achievedAt).toLocaleDateString();
    this.drawStatRow('Achieved:', date, centerX - width / 4, statsY + lineHeight * 2, width / 2);
  }

  private drawStatRow(label: string, value: string, x: number, y: number, width: number): void {
    this.ctx.font = '16px Arial, sans-serif';
    this.ctx.textAlign = 'left';
    this.ctx.fillStyle = '#AAAAAA';
    this.ctx.fillText(label, x, y);

    this.ctx.textAlign = 'right';
    this.ctx.fillStyle = '#FFFFFF';
    this.ctx.fillText(value, x + width, y);
  }

  private drawSortControls(x: number, y: number): void {
    const sortOptions: { id: SortOption; label: string }[] = [
      { id: 'score', label: 'By Score' },
      { id: 'time', label: 'By Time' },
      { id: 'date', label: 'By Date' },
    ];

    const buttonWidth = 100;
    const buttonHeight = 30;
    const buttonSpacing = 10;

    this.ctx.font = '12px Arial, sans-serif';
    this.ctx.textAlign = 'left';
    this.ctx.fillStyle = '#888899';
    this.ctx.fillText('Sort:', x, y + 20);

    const startX = x + 50;

    for (let i = 0; i < sortOptions.length; i++) {
      const option = sortOptions[i];
      if (!option) continue;

      const btnX = startX + i * (buttonWidth + buttonSpacing);
      const isActive = this.sortBy === option.id;

      // Button background
      if (isActive) {
        const gradient = this.ctx.createLinearGradient(btnX, y, btnX, y + buttonHeight);
        gradient.addColorStop(0, '#660000');
        gradient.addColorStop(1, '#330000');
        this.ctx.fillStyle = gradient;
      } else {
        this.ctx.fillStyle = '#2a2a3e';
      }

      this.roundRect(btnX, y, buttonWidth, buttonHeight, 6);
      this.ctx.fill();

      // Button border
      this.ctx.strokeStyle = isActive ? '#FF4444' : '#444466';
      this.ctx.lineWidth = isActive ? 2 : 1;
      this.roundRect(btnX, y, buttonWidth, buttonHeight, 6);
      this.ctx.stroke();

      // Button text
      this.ctx.font = isActive ? 'bold 12px Arial' : '12px Arial';
      this.ctx.textAlign = 'center';
      this.ctx.textBaseline = 'middle';
      this.ctx.fillStyle = isActive ? '#FFFFFF' : '#888899';

      let text = option.label;
      if (isActive) {
        text += this.sortDirection === 'asc' ? ' ↑' : ' ↓';
      }
      this.ctx.fillText(text, btnX + buttonWidth / 2, y + buttonHeight / 2);
    }
  }

  private drawActionButtons(x: number, y: number): void {
    const buttons: { id: string; label: string; color: string }[] = [
      { id: 'export', label: 'Export Scores', color: '#444466' },
      { id: 'import', label: 'Import Scores', color: '#444466' },
      { id: 'reset', label: 'Reset All', color: '#AA4444' },
    ];

    const buttonWidth = 120;
    const buttonHeight = 35;
    const buttonSpacing = 15;

    for (let i = 0; i < buttons.length; i++) {
      const button = buttons[i];
      if (!button) continue;

      const btnX = x + i * (buttonWidth + buttonSpacing);

      // Button background
      const gradient = this.ctx.createLinearGradient(btnX, y, btnX, y + buttonHeight);
      gradient.addColorStop(0, button.color);
      gradient.addColorStop(1, this.darkenColor(button.color, 20));
      this.ctx.fillStyle = gradient;

      this.roundRect(btnX, y, buttonWidth, buttonHeight, 6);
      this.ctx.fill();

      // Button border
      this.ctx.strokeStyle = button.color;
      this.ctx.lineWidth = 2;
      this.roundRect(btnX, y, buttonWidth, buttonHeight, 6);
      this.ctx.stroke();

      // Button text
      this.ctx.font = 'bold 12px Arial';
      this.ctx.textAlign = 'center';
      this.ctx.textBaseline = 'middle';
      this.ctx.fillStyle = '#FFFFFF';
      this.ctx.fillText(button.label, btnX + buttonWidth / 2, y + buttonHeight / 2);
    }
  }

  private drawMessage(width: number, height: number): void {
    if (!this.messageText) return;

    const msgY = height / 2 + this.PANEL_HEIGHT / 2 - 30;

    this.ctx.font = '14px Arial, sans-serif';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';
    this.ctx.fillStyle = this.messageIsError ? '#FF4444' : '#44AA44';
    this.ctx.fillText(this.messageText, width / 2, msgY);
  }

  private drawConfirmationModal(width: number, height: number): void {
    // Dark overlay
    this.ctx.fillStyle = 'rgba(0, 0, 0, 0.8)';
    this.ctx.fillRect(0, 0, width, height);

    // Dialog box
    const dialogWidth = 400;
    const dialogHeight = 200;
    const dialogX = (width - dialogWidth) / 2;
    const dialogY = (height - dialogHeight) / 2;

    // Dialog background
    this.ctx.fillStyle = '#1a1a2e';
    this.roundRect(dialogX, dialogY, dialogWidth, dialogHeight, 12);
    this.ctx.fill();

    // Dialog border
    this.ctx.strokeStyle = '#FF4444';
    this.ctx.lineWidth = 3;
    this.roundRect(dialogX, dialogY, dialogWidth, dialogHeight, 12);
    this.ctx.stroke();

    // Warning title
    this.ctx.font = 'bold 24px Arial';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';
    this.ctx.fillStyle = '#FF4444';
    this.ctx.fillText('WARNING!', width / 2, dialogY + 40);

    // Warning text
    this.ctx.font = '14px Arial';
    this.ctx.fillStyle = '#FFFFFF';
    this.wrapText(
      'This will permanently delete ALL high scores, quest progress, and statistics.',
      width / 2,
      dialogY + 80,
      dialogWidth - 40,
      20
    );

    // Buttons
    const btnWidth = 120;
    const btnHeight = 35;
    const btnY = dialogY + dialogHeight - 60;

    // Cancel button
    const cancelX = width / 2 - btnWidth - 10;
    this.ctx.fillStyle = '#444466';
    this.roundRect(cancelX, btnY, btnWidth, btnHeight, 6);
    this.ctx.fill();
    this.ctx.strokeStyle = '#666688';
    this.ctx.lineWidth = 2;
    this.roundRect(cancelX, btnY, btnWidth, btnHeight, 6);
    this.ctx.stroke();

    this.ctx.font = 'bold 14px Arial';
    this.ctx.fillStyle = '#FFFFFF';
    this.ctx.fillText('Cancel', width / 2 - btnWidth / 2 - 10, btnY + btnHeight / 2);

    // Confirm button
    const confirmX = width / 2 + 10;
    this.ctx.fillStyle = '#AA4444';
    this.roundRect(confirmX, btnY, btnWidth, btnHeight, 6);
    this.ctx.fill();
    this.ctx.strokeStyle = '#FF4444';
    this.ctx.lineWidth = 2;
    this.roundRect(confirmX, btnY, btnWidth, btnHeight, 6);
    this.ctx.stroke();

    this.ctx.fillStyle = '#FFFFFF';
    this.ctx.fillText('Yes, Reset', width / 2 + btnWidth / 2 + 10, btnY + btnHeight / 2);
  }

  private getQuestScores(): QuestScoreEntry[] {
    const entries: QuestScoreEntry[] = [];

    for (const quest of ALL_QUESTS) {
      const highScore = this.progressionManager.getQuestHighScore(quest.id);
      if (highScore) {
        entries.push({
          questId: quest.id,
          questName: quest.name,
          highScore,
        });
      }
    }

    return entries;
  }

  private sortQuestScores(scores: QuestScoreEntry[]): QuestScoreEntry[] {
    return [...scores].sort((a, b) => {
      let comparison = 0;

      switch (this.sortBy) {
        case 'score':
          comparison = a.highScore.bestScore - b.highScore.bestScore;
          break;
        case 'time':
          comparison = a.highScore.bestTime - b.highScore.bestTime;
          break;
        case 'date':
          comparison =
            new Date(a.highScore.completedAt).getTime() -
            new Date(b.highScore.completedAt).getTime();
          break;
      }

      return this.sortDirection === 'asc' ? comparison : -comparison;
    });
  }

  private handleExport(): void {
    const data = this.progressionManager.exportData();
    const blob = new Blob([data], { type: 'application/json' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = `crimsonland-scores-${new Date().toISOString().split('T')[0]}.json`;
    a.click();
    URL.revokeObjectURL(url);
    this.showMessage('Scores exported successfully', false);
  }

  private handleImport(): void {
    this.fileInput?.click();
  }

  private handleReset(): void {
    this.showConfirmation = true;
  }

  private confirmReset(): void {
    this.progressionManager.reset();
    this.showConfirmation = false;
    this.showMessage('All progression data reset', false);
  }

  private cancelReset(): void {
    this.showConfirmation = false;
  }

  private showMessage(text: string, isError: boolean): void {
    this.messageText = text;
    this.messageIsError = isError;
    this.messageTimer = 3; // 3 seconds
  }

  private handleKeyDown(e: KeyboardEvent): void {
    if (!this.isVisible) return;

    if (this.showConfirmation) {
      if (e.key === 'Escape') {
        this.cancelReset();
      } else if (e.key === 'Enter') {
        this.confirmReset();
      }
      return;
    }

    switch (e.key) {
      case 'Escape':
        this.options.onBack();
        break;
      case 'ArrowLeft':
        this.cycleTab(-1);
        break;
      case 'ArrowRight':
        this.cycleTab(1);
        break;
    }
  }

  private cycleTab(direction: number): void {
    const tabs: HighScoreTab[] = ['SURVIVAL', 'QUESTS', 'RUSH'];
    const currentIndex = tabs.indexOf(this.currentTab);
    const newIndex = (currentIndex + direction + tabs.length) % tabs.length;
    this.currentTab = tabs[newIndex] ?? 'SURVIVAL';
  }

  private handleClick(e: MouseEvent): void {
    if (!this.isVisible) return;

    const rect = this.canvas.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    if (this.showConfirmation) {
      this.handleConfirmationClick(x, y);
      return;
    }

    // Check tabs
    this.handleTabClick(x, y);

    // Check sort controls
    this.handleSortClick(x, y);

    // Check action buttons
    this.handleActionButtonClick(x, y);
  }

  private handleConfirmationClick(x: number, y: number): void {
    const width = this.canvas.width;
    const height = this.canvas.height;
    const dialogHeight = 200;
    const dialogY = (height - dialogHeight) / 2;
    const btnWidth = 120;
    const btnHeight = 35;
    const btnY = dialogY + dialogHeight - 60;

    // Cancel button
    const cancelX = width / 2 - btnWidth - 10;
    if (x >= cancelX && x <= cancelX + btnWidth && y >= btnY && y <= btnY + btnHeight) {
      this.cancelReset();
      return;
    }

    // Confirm button
    const confirmX = width / 2 + 10;
    if (x >= confirmX && x <= confirmX + btnWidth && y >= btnY && y <= btnY + btnHeight) {
      this.confirmReset();
    }
  }

  private handleTabClick(x: number, y: number): void {
    const tabs: HighScoreTab[] = ['SURVIVAL', 'QUESTS', 'RUSH'];
    const tabWidth = 140;
    const tabHeight = this.TAB_HEIGHT;
    const startX = this.canvas.width / 2 - (tabs.length * tabWidth) / 2;
    const tabY = this.canvas.height / 2 - this.PANEL_HEIGHT / 2 + 80;

    for (let i = 0; i < tabs.length; i++) {
      const tabX = startX + i * tabWidth;
      if (x >= tabX && x <= tabX + tabWidth && y >= tabY && y <= tabY + tabHeight) {
        this.currentTab = tabs[i] ?? 'SURVIVAL';
        return;
      }
    }
  }

  private handleSortClick(x: number, y: number): void {
    const sortOptions: SortOption[] = ['score', 'time', 'date'];
    const buttonWidth = 100;
    const buttonHeight = 30;
    const buttonSpacing = 10;
    const panelX = (this.canvas.width - this.PANEL_WIDTH) / 2;
    const contentY =
      this.canvas.height / 2 - this.PANEL_HEIGHT / 2 + this.TAB_HEIGHT + this.HEADER_HEIGHT + 20;
    const startX = panelX + this.PADDING + 50;
    const btnY = contentY + 260;

    for (let i = 0; i < sortOptions.length; i++) {
      const btnX = startX + i * (buttonWidth + buttonSpacing);
      if (x >= btnX && x <= btnX + buttonWidth && y >= btnY && y <= btnY + buttonHeight) {
        const option = sortOptions[i];
        if (this.sortBy === option) {
          // Toggle direction
          this.sortDirection = this.sortDirection === 'asc' ? 'desc' : 'asc';
        } else {
          this.sortBy = option ?? 'score';
          // Set default direction based on sort type
          this.sortDirection = option === 'time' ? 'asc' : 'desc';
        }
        return;
      }
    }
  }

  private handleActionButtonClick(x: number, y: number): void {
    const buttons = ['export', 'import', 'reset'];
    const buttonWidth = 120;
    const buttonHeight = 35;
    const buttonSpacing = 15;
    const panelX = (this.canvas.width - this.PANEL_WIDTH) / 2;
    const contentY =
      this.canvas.height / 2 - this.PANEL_HEIGHT / 2 + this.TAB_HEIGHT + this.HEADER_HEIGHT + 20;
    const startX = panelX + this.PADDING;
    const btnY = contentY + 260;

    for (let i = 0; i < buttons.length; i++) {
      const btnX = startX + i * (buttonWidth + buttonSpacing);
      if (x >= btnX && x <= btnX + buttonWidth && y >= btnY && y <= btnY + buttonHeight) {
        const buttonId = buttons[i];
        switch (buttonId) {
          case 'export':
            this.handleExport();
            break;
          case 'import':
            this.handleImport();
            break;
          case 'reset':
            this.handleReset();
            break;
        }
        return;
      }
    }
  }

  private handleMouseMove(_e: MouseEvent): void {
    // Hover effects could be implemented here
  }

  private attachEventListeners(): void {
    window.addEventListener('keydown', this.keyHandler);
    this.canvas.addEventListener('click', this.clickHandler);
    this.canvas.addEventListener('mousemove', this.mouseMoveHandler);
  }

  private detachEventListeners(): void {
    window.removeEventListener('keydown', this.keyHandler);
    this.canvas.removeEventListener('click', this.clickHandler);
    this.canvas.removeEventListener('mousemove', this.mouseMoveHandler);
  }

  private formatTime(seconds: number): string {
    const mins = Math.floor(seconds / 60);
    const secs = Math.floor(seconds % 60);
    return `${mins}:${secs.toString().padStart(2, '0')}`;
  }

  private darkenColor(color: string, percent: number): string {
    // Simple hex color darkening
    const num = Number.parseInt(color.replace('#', ''), 16);
    const amt = Math.round(2.55 * percent);
    const R = Math.max((num >> 16) - amt, 0);
    const G = Math.max(((num >> 8) & 0x00ff) - amt, 0);
    const B = Math.max((num & 0x0000ff) - amt, 0);
    return `#${(0x1000000 + R * 0x10000 + G * 0x100 + B).toString(16).slice(1)}`;
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
    if (this.fileInput) {
      document.body.removeChild(this.fileInput);
      this.fileInput = null;
    }
    this.hide();
  }
}
