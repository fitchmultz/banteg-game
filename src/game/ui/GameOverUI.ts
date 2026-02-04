/**
 * Game Over / Victory Screen UI
 *
 * Displays final stats and options after game ends.
 */

import type { GameStats } from '../../types';

export type GameOverOption = 'NEW_RUN' | 'MAIN_MENU';

export interface GameOverButton {
  id: GameOverOption;
  label: string;
  x: number;
  y: number;
  width: number;
  height: number;
  hovered: boolean;
}

export interface GameOverStats extends GameStats {
  isVictory: boolean;
  // Survival mode stats
  bestScore?: number;
  bestTime?: number;
  // Quest mode stats
  questName?: string;
}

export interface GameOverUIOptions {
  canvas: HTMLCanvasElement;
  onNewRun: () => void;
  onMainMenu: () => void;
}

export class GameOverUI {
  private canvas: HTMLCanvasElement;
  private ctx: CanvasRenderingContext2D;
  private options: GameOverUIOptions;

  // UI State
  private isVisible = false;
  private buttons: GameOverButton[] = [];
  private selectedIndex = 0;
  private stats: GameOverStats = {
    score: 0,
    kills: 0,
    timeElapsed: 0,
    level: 1,
    isVictory: false,
  };
  private animationProgress = 0;
  private displayScore = 0;
  private displayKills = 0;

  // Input handling
  private keyHandler: (e: KeyboardEvent) => void;
  private clickHandler: (e: MouseEvent) => void;
  private mouseMoveHandler: (e: MouseEvent) => void;

  // Layout constants
  private readonly BUTTON_WIDTH = 220;
  private readonly BUTTON_HEIGHT = 50;
  private readonly BUTTON_SPACING = 20;

  constructor(options: GameOverUIOptions) {
    this.canvas = options.canvas;
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
    this.buildButtons();
  }

  private buildButtons(): void {
    const centerX = this.canvas.width / 2;
    const startY = this.canvas.height / 2 + 80;

    const buttonData: { id: GameOverOption; label: string }[] = [
      { id: 'NEW_RUN', label: 'NEW RUN' },
      { id: 'MAIN_MENU', label: 'MAIN MENU' },
    ];

    this.buttons = buttonData.map((data, index) => ({
      id: data.id,
      label: data.label,
      x: centerX - this.BUTTON_WIDTH / 2,
      y: startY + index * (this.BUTTON_HEIGHT + this.BUTTON_SPACING),
      width: this.BUTTON_WIDTH,
      height: this.BUTTON_HEIGHT,
      hovered: false,
    }));
  }

  /**
   * Show the game over screen
   */
  show(stats: GameOverStats): void {
    this.stats = { ...stats };
    this.isVisible = true;
    this.selectedIndex = 0;
    this.animationProgress = 0;
    this.displayScore = 0;
    this.displayKills = 0;
    this.buildButtons();
    this.animateIn();
  }

  /**
   * Hide the game over screen
   */
  hide(): void {
    this.isVisible = false;
  }

  /**
   * Check if UI is visible
   */
  isShown(): boolean {
    return this.isVisible;
  }

  /**
   * Update animation
   */
  update(dt: number): void {
    if (!this.isVisible) return;

    if (this.animationProgress < 1) {
      this.animationProgress = Math.min(1, this.animationProgress + dt * 2);
    }

    // Animate score counting up
    const scoreSpeed = Math.max(100, this.stats.score * 0.5) * dt;
    if (this.displayScore < this.stats.score) {
      this.displayScore = Math.min(this.stats.score, this.displayScore + scoreSpeed);
    }

    // Animate kills counting up
    const killSpeed = Math.max(10, this.stats.kills * 0.3) * dt;
    if (this.displayKills < this.stats.kills) {
      this.displayKills = Math.min(this.stats.kills, this.displayKills + killSpeed);
    }
  }

  private animateIn(): void {
    this.animationProgress = 0;
  }

  /**
   * Render the UI
   */
  render(): void {
    if (!this.isVisible) return;

    const width = this.canvas.width;
    const height = this.canvas.height;

    // Draw background overlay
    const overlayAlpha = 0.85 * this.animationProgress;
    this.ctx.fillStyle = `rgba(0, 0, 0, ${overlayAlpha})`;
    this.ctx.fillRect(0, 0, width, height);

    // Draw game over/victory banner
    this.drawBanner(width, height);

    // Draw stats panel
    this.drawStatsPanel(width, height);

    // Draw buttons
    for (let i = 0; i < this.buttons.length; i++) {
      const button = this.buttons[i];
      if (button) {
        this.drawButton(button, i === this.selectedIndex);
      }
    }
  }

  private drawBanner(width: number, height: number): void {
    const isVictory = this.stats.isVictory;
    const title = isVictory ? 'VICTORY!' : 'GAME OVER';
    const color = isVictory ? '#00AA00' : '#AA0000';

    const animOffset = (1 - this.animationProgress) * 50;
    const titleY = height * 0.2 + animOffset;

    // Glow effect
    const pulse = Math.sin(Date.now() / 500) * 5;
    this.ctx.shadowColor = color;
    this.ctx.shadowBlur = 20 + pulse;

    // Title text
    this.ctx.font = 'bold 56px Arial, sans-serif';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';
    this.ctx.fillStyle = isVictory ? '#00FF00' : '#FF4444';
    this.ctx.fillText(title, width / 2, titleY);

    this.ctx.shadowBlur = 0;

    // Quest name if in quest mode
    if (this.stats.questName) {
      this.ctx.font = '24px Arial, sans-serif';
      this.ctx.fillStyle = '#AAAAAA';
      this.ctx.fillText(this.stats.questName, width / 2, titleY + 45);
    }

    // Decorative lines
    this.ctx.strokeStyle = color;
    this.ctx.lineWidth = 2;
    this.ctx.beginPath();
    this.ctx.moveTo(width / 2 - 120, titleY + 55);
    this.ctx.lineTo(width / 2 + 120, titleY + 55);
    this.ctx.stroke();
  }

  private drawStatsPanel(width: number, height: number): void {
    const panelWidth = 380;
    const panelHeight = 240;
    const panelX = (width - panelWidth) / 2;
    const panelY = height * 0.35;

    // Animation
    const animOffset = (1 - this.animationProgress) * 30;

    // Panel shadow
    this.ctx.fillStyle = 'rgba(0, 0, 0, 0.5)';
    this.roundRect(panelX + 6, panelY + 6 + animOffset, panelWidth, panelHeight, 12);
    this.ctx.fill();

    // Panel background
    const gradient = this.ctx.createLinearGradient(panelX, panelY, panelX, panelY + panelHeight);
    gradient.addColorStop(0, 'rgba(30, 30, 50, 0.95)');
    gradient.addColorStop(1, 'rgba(15, 15, 30, 0.95)');

    this.ctx.fillStyle = gradient;
    this.roundRect(panelX, panelY + animOffset, panelWidth, panelHeight, 12);
    this.ctx.fill();

    // Panel border
    this.ctx.strokeStyle = this.stats.isVictory ? '#004400' : '#440000';
    this.ctx.lineWidth = 2;
    this.roundRect(panelX, panelY + animOffset, panelWidth, panelHeight, 12);
    this.ctx.stroke();

    // Draw stats
    this.drawStatsContent(panelX, panelY + animOffset, panelWidth);
  }

  private drawStatsContent(panelX: number, panelY: number, panelWidth: number): void {
    const minutes = Math.floor(this.stats.timeElapsed / 60);
    const seconds = Math.floor(this.stats.timeElapsed % 60);
    const timeStr = `${minutes}:${seconds.toString().padStart(2, '0')}`;

    const stats = [
      { label: 'Final Score', value: Math.floor(this.displayScore).toLocaleString() },
      { label: 'Enemies Defeated', value: Math.floor(this.displayKills).toString() },
      { label: 'Time Survived', value: timeStr },
      { label: 'Level Reached', value: this.stats.level.toString() },
    ];

    let currentY = panelY + 40;
    const leftX = panelX + 30;
    const rightX = panelX + panelWidth - 30;

    for (const stat of stats) {
      // Label
      this.ctx.font = 'bold 18px Arial, sans-serif';
      this.ctx.textAlign = 'left';
      this.ctx.textBaseline = 'middle';
      this.ctx.fillStyle = '#888899';
      this.ctx.fillText(stat.label, leftX, currentY);

      // Value
      this.ctx.textAlign = 'right';
      this.ctx.fillStyle = '#FFFFFF';
      this.ctx.fillText(stat.value, rightX, currentY);

      currentY += 45;
    }

    // High score comparison
    if (this.stats.bestScore && this.stats.bestScore > 0) {
      const isNewRecord = this.stats.score > this.stats.bestScore;

      this.ctx.textAlign = 'center';
      this.ctx.font = '14px Arial, sans-serif';

      if (isNewRecord) {
        this.ctx.fillStyle = '#FFD700';
        this.ctx.fillText('★ NEW RECORD! ★', panelX + panelWidth / 2, currentY + 10);
      } else {
        this.ctx.fillStyle = '#666677';
        this.ctx.fillText(
          `Best: ${this.stats.bestScore.toLocaleString()}`,
          panelX + panelWidth / 2,
          currentY + 10
        );
      }
    }
  }

  private drawButton(button: GameOverButton, isSelected: boolean): void {
    const { x, y, width, height, label, hovered } = button;
    const isHighlighted = hovered || isSelected;

    // Animation offset
    const animOffset = (1 - this.animationProgress) * 20;

    // Button background
    const gradient = this.ctx.createLinearGradient(x, y + animOffset, x, y + height + animOffset);
    if (isHighlighted) {
      gradient.addColorStop(0, '#660000');
      gradient.addColorStop(1, '#330000');
    } else {
      gradient.addColorStop(0, '#2a2a3e');
      gradient.addColorStop(1, '#1a1a2e');
    }

    this.ctx.fillStyle = gradient;
    this.roundRect(x, y + animOffset, width, height, 8);
    this.ctx.fill();

    // Button border
    this.ctx.strokeStyle = isHighlighted ? '#FF4444' : '#444466';
    this.ctx.lineWidth = isHighlighted ? 3 : 2;
    this.roundRect(x, y + animOffset, width, height, 8);
    this.ctx.stroke();

    // Glow effect
    if (isHighlighted) {
      this.ctx.shadowColor = '#FF4444';
      this.ctx.shadowBlur = 10;
      this.roundRect(x, y + animOffset, width, height, 8);
      this.ctx.stroke();
      this.ctx.shadowBlur = 0;
    }

    // Button text
    this.ctx.font = 'bold 18px Arial, sans-serif';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';
    this.ctx.fillStyle = isHighlighted ? '#FFFFFF' : '#AAAAAA';
    this.ctx.fillText(label, x + width / 2, y + height / 2 + animOffset);
  }

  private handleKeyDown(e: KeyboardEvent): void {
    if (!this.isVisible) return;

    switch (e.key) {
      case 'ArrowUp':
        this.selectedIndex = Math.max(0, this.selectedIndex - 1);
        break;
      case 'ArrowDown':
        this.selectedIndex = Math.min(this.buttons.length - 1, this.selectedIndex + 1);
        break;
      case 'Enter':
      case ' ': {
        const button = this.buttons[this.selectedIndex];
        if (button) {
          this.selectOption(button.id);
        }
        break;
      }
    }
  }

  private handleClick(e: MouseEvent): void {
    if (!this.isVisible) return;

    const rect = this.canvas.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    for (const button of this.buttons) {
      if (
        x >= button.x &&
        x <= button.x + button.width &&
        y >= button.y &&
        y <= button.y + button.height
      ) {
        this.selectOption(button.id);
        return;
      }
    }
  }

  private handleMouseMove(e: MouseEvent): void {
    if (!this.isVisible) return;

    const rect = this.canvas.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    for (let i = 0; i < this.buttons.length; i++) {
      const button = this.buttons[i];
      if (!button) continue;

      const wasHovered = button.hovered;
      button.hovered =
        x >= button.x &&
        x <= button.x + button.width &&
        y >= button.y &&
        y <= button.y + button.height;

      if (button.hovered && !wasHovered) {
        this.selectedIndex = i;
      }
    }
  }

  private selectOption(option: GameOverOption): void {
    switch (option) {
      case 'NEW_RUN':
        this.options.onNewRun();
        break;
      case 'MAIN_MENU':
        this.options.onMainMenu();
        break;
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

  /**
   * Clean up event listeners
   */
  destroy(): void {
    this.detachEventListeners();
  }
}
