/**
 * Main Menu UI
 *
 * Displays the game title and main menu options.
 * Entry point for all game modes.
 */

import type { GameMode } from '../../types';

export type MenuOption = 'TUTORIAL' | 'SURVIVAL' | 'RUSH' | 'QUEST' | 'OPTIONS' | 'CREDITS';

export interface MenuButton {
  id: MenuOption;
  label: string;
  x: number;
  y: number;
  width: number;
  height: number;
  hovered: boolean;
}

export interface MainMenuUIOptions {
  canvas: HTMLCanvasElement;
  onSelectMode: (mode: GameMode) => void;
  onShowOptions?: () => void;
  onShowCredits?: () => void;
}

export class MainMenuUI {
  private canvas: HTMLCanvasElement;
  private ctx: CanvasRenderingContext2D;
  private options: MainMenuUIOptions;

  // UI State
  private isVisible = false;
  private buttons: MenuButton[] = [];
  private selectedIndex = 0;
  private animationTime = 0;
  private backgroundParticles: Array<{
    x: number;
    y: number;
    vx: number;
    vy: number;
    size: number;
    alpha: number;
  }> = [];

  // Input handling
  private keyHandler: (e: KeyboardEvent) => void;
  private clickHandler: (e: MouseEvent) => void;
  private mouseMoveHandler: (e: MouseEvent) => void;

  // Layout constants
  private readonly BUTTON_WIDTH = 280;
  private readonly BUTTON_HEIGHT = 50;
  private readonly BUTTON_SPACING = 20;
  private readonly TITLE_SIZE = 64;
  private readonly SUBTITLE_SIZE = 24;

  constructor(options: MainMenuUIOptions) {
    this.canvas = options.canvas;
    const ctx = this.canvas.getContext('2d');
    if (!ctx) {
      throw new Error('Could not get canvas context');
    }
    this.ctx = ctx;
    this.options = options;

    // Initialize background particles
    this.initParticles();

    // Bind input handlers
    this.keyHandler = this.handleKeyDown.bind(this);
    this.clickHandler = this.handleClick.bind(this);
    this.mouseMoveHandler = this.handleMouseMove.bind(this);

    this.attachEventListeners();
    this.buildButtons();
  }

  private initParticles(): void {
    this.backgroundParticles = [];
    for (let i = 0; i < 50; i++) {
      this.backgroundParticles.push({
        x: Math.random() * this.canvas.width,
        y: Math.random() * this.canvas.height,
        vx: (Math.random() - 0.5) * 20,
        vy: (Math.random() - 0.5) * 20,
        size: 1 + Math.random() * 3,
        alpha: 0.1 + Math.random() * 0.4,
      });
    }
  }

  private buildButtons(): void {
    const centerX = this.canvas.width / 2;
    const startY = this.canvas.height / 2 - 40;

    const buttonData: { id: MenuOption; label: string }[] = [
      { id: 'TUTORIAL', label: 'TUTORIAL' },
      { id: 'SURVIVAL', label: 'SURVIVAL MODE' },
      { id: 'RUSH', label: 'RUSH MODE' },
      { id: 'QUEST', label: 'QUEST MODE' },
      { id: 'OPTIONS', label: 'OPTIONS' },
      { id: 'CREDITS', label: 'CREDITS' },
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
   * Show the main menu
   */
  show(): void {
    this.isVisible = true;
    this.animationTime = 0;
    this.selectedIndex = 0;
    this.initParticles();
    this.buildButtons(); // Rebuild in case canvas resized
  }

  /**
   * Hide the main menu
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

    this.animationTime += dt;

    // Update background particles
    for (const p of this.backgroundParticles) {
      p.x += p.vx * dt;
      p.y += p.vy * dt;

      // Wrap around screen
      if (p.x < 0) p.x = this.canvas.width;
      if (p.x > this.canvas.width) p.x = 0;
      if (p.y < 0) p.y = this.canvas.height;
      if (p.y > this.canvas.height) p.y = 0;
    }
  }

  /**
   * Render the UI
   */
  render(): void {
    if (!this.isVisible) return;

    const width = this.canvas.width;
    const height = this.canvas.height;

    // Draw dark background
    this.ctx.fillStyle = '#0a0a0f';
    this.ctx.fillRect(0, 0, width, height);

    // Draw background particles
    this.drawBackgroundParticles();

    // Draw vignette effect
    this.drawVignette(width, height);

    // Draw title
    this.drawTitle(width);

    // Draw buttons
    for (let i = 0; i < this.buttons.length; i++) {
      const button = this.buttons[i];
      if (button) {
        this.drawButton(button, i === this.selectedIndex);
      }
    }

    // Draw footer
    this.drawFooter(width, height);
  }

  private drawBackgroundParticles(): void {
    for (const p of this.backgroundParticles) {
      this.ctx.fillStyle = `rgba(139, 0, 0, ${p.alpha})`;
      this.ctx.beginPath();
      this.ctx.arc(p.x, p.y, p.size, 0, Math.PI * 2);
      this.ctx.fill();
    }
  }

  private drawVignette(width: number, height: number): void {
    const gradient = this.ctx.createRadialGradient(
      width / 2,
      height / 2,
      Math.min(width, height) * 0.3,
      width / 2,
      height / 2,
      Math.max(width, height) * 0.7
    );
    gradient.addColorStop(0, 'rgba(0, 0, 0, 0)');
    gradient.addColorStop(1, 'rgba(0, 0, 0, 0.7)');

    this.ctx.fillStyle = gradient;
    this.ctx.fillRect(0, 0, width, height);
  }

  private drawTitle(width: number): void {
    const centerX = width / 2;
    const titleY = 120;

    // Glow effect
    const glowIntensity = 0.5 + Math.sin(this.animationTime * 3) * 0.2;
    this.ctx.shadowColor = '#8B0000';
    this.ctx.shadowBlur = 20 + glowIntensity * 15;

    // Main title
    this.ctx.font = `bold ${this.TITLE_SIZE}px Arial, sans-serif`;
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';

    // Crimson outline
    this.ctx.strokeStyle = '#8B0000';
    this.ctx.lineWidth = 3;
    this.ctx.strokeText('CRIMSONLAND', centerX, titleY);

    // White fill
    this.ctx.fillStyle = '#FFFFFF';
    this.ctx.fillText('CRIMSONLAND', centerX, titleY);

    // Subtitle
    this.ctx.shadowBlur = 0;
    this.ctx.font = `${this.SUBTITLE_SIZE}px Arial, sans-serif`;
    this.ctx.fillStyle = '#CC6666';
    this.ctx.fillText('REMAKE', centerX, titleY + 50);

    // Decorative line
    this.ctx.strokeStyle = '#8B0000';
    this.ctx.lineWidth = 2;
    this.ctx.beginPath();
    this.ctx.moveTo(centerX - 100, titleY + 70);
    this.ctx.lineTo(centerX + 100, titleY + 70);
    this.ctx.stroke();
  }

  private drawButton(button: MenuButton, isSelected: boolean): void {
    const { x, y, width, height, label, hovered } = button;
    const isHighlighted = hovered || isSelected;

    // Animation for hover
    const scale = isHighlighted ? 1.02 : 1;
    const offsetX = (width * (scale - 1)) / 2;
    const offsetY = (height * (scale - 1)) / 2;

    // Button shadow
    this.ctx.fillStyle = 'rgba(0, 0, 0, 0.5)';
    this.roundRect(x + 4, y + 4, width, height, 8);
    this.ctx.fill();

    // Button background
    const gradient = this.ctx.createLinearGradient(x, y, x, y + height);
    if (isHighlighted) {
      gradient.addColorStop(0, '#660000');
      gradient.addColorStop(1, '#330000');
    } else {
      gradient.addColorStop(0, '#333333');
      gradient.addColorStop(1, '#1a1a1a');
    }

    this.ctx.fillStyle = gradient;
    this.roundRect(x - offsetX, y - offsetY, width * scale, height * scale, 8);
    this.ctx.fill();

    // Button border
    this.ctx.strokeStyle = isHighlighted ? '#FF4444' : '#555555';
    this.ctx.lineWidth = isHighlighted ? 3 : 2;
    this.roundRect(x - offsetX, y - offsetY, width * scale, height * scale, 8);
    this.ctx.stroke();

    // Button glow on hover
    if (isHighlighted) {
      this.ctx.shadowColor = '#FF4444';
      this.ctx.shadowBlur = 10;
      this.roundRect(x - offsetX, y - offsetY, width * scale, height * scale, 8);
      this.ctx.stroke();
      this.ctx.shadowBlur = 0;
    }

    // Button text
    this.ctx.font = 'bold 18px Arial, sans-serif';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';
    this.ctx.fillStyle = isHighlighted ? '#FFFFFF' : '#CCCCCC';
    this.ctx.fillText(label, x + width / 2, y + height / 2);
  }

  private drawFooter(width: number, height: number): void {
    this.ctx.font = '12px Arial, sans-serif';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'bottom';
    this.ctx.fillStyle = '#666666';

    // Controls hint
    this.ctx.fillText(
      'Use Arrow Keys or Mouse to Navigate | Enter or Click to Select',
      width / 2,
      height - 40
    );

    // Version info
    this.ctx.fillStyle = '#444444';
    this.ctx.fillText('v0.1.0 | MIT License', width / 2, height - 20);
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

  private selectOption(option: MenuOption): void {
    switch (option) {
      case 'TUTORIAL':
        this.options.onSelectMode({ type: 'TUTORIAL' });
        break;
      case 'SURVIVAL':
        this.options.onSelectMode({ type: 'SURVIVAL' });
        break;
      case 'RUSH':
        this.options.onSelectMode({ type: 'RUSH' });
        break;
      case 'QUEST':
        this.options.onSelectMode({ type: 'QUEST', questId: 'nagolipoli' }); // Default first quest
        break;
      case 'OPTIONS':
        this.options.onShowOptions?.();
        break;
      case 'CREDITS':
        this.options.onShowCredits?.();
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
