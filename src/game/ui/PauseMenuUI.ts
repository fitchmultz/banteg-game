/**
 * Pause Menu UI
 *
 * Displays when the game is paused.
 * Shows game stats and resume/options/main menu buttons.
 */

export type PauseOption = 'RESUME' | 'OPTIONS' | 'RESTART' | 'MAIN_MENU';

export interface PauseButton {
  id: PauseOption;
  label: string;
  x: number;
  y: number;
  width: number;
  height: number;
  hovered: boolean;
}

export interface PauseStats {
  score: number;
  kills: number;
  timeElapsed: number;
  level: number;
}

export interface PauseMenuUIOptions {
  canvas: HTMLCanvasElement;
  onResume: () => void;
  onRestart: () => void;
  onMainMenu: () => void;
  onShowOptions?: () => void;
}

export class PauseMenuUI {
  private canvas: HTMLCanvasElement;
  private ctx: CanvasRenderingContext2D;
  private options: PauseMenuUIOptions;

  // UI State
  private isVisible = false;
  private buttons: PauseButton[] = [];
  private selectedIndex = 0;
  private stats: PauseStats = { score: 0, kills: 0, timeElapsed: 0, level: 1 };
  private animationProgress = 0;

  // Input handling
  private keyHandler: (e: KeyboardEvent) => void;
  private clickHandler: (e: MouseEvent) => void;
  private mouseMoveHandler: (e: MouseEvent) => void;

  // Layout constants
  private readonly BUTTON_WIDTH = 240;
  private readonly BUTTON_HEIGHT = 45;
  private readonly BUTTON_SPACING = 15;

  constructor(options: PauseMenuUIOptions) {
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
    const startY = this.canvas.height / 2 - 20;

    const buttonData: { id: PauseOption; label: string }[] = [
      { id: 'RESUME', label: 'RESUME' },
      { id: 'RESTART', label: 'RESTART' },
      { id: 'OPTIONS', label: 'OPTIONS' },
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
   * Show the pause menu
   */
  show(stats?: PauseStats): void {
    if (stats) {
      this.stats = { ...stats };
    }
    this.isVisible = true;
    this.selectedIndex = 0;
    this.animationProgress = 0;
    this.buildButtons(); // Rebuild in case canvas resized
    this.animateIn();
  }

  /**
   * Hide the pause menu
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
   * Update stats while paused
   */
  updateStats(stats: PauseStats): void {
    this.stats = { ...stats };
  }

  /**
   * Update animation
   */
  update(dt: number): void {
    if (!this.isVisible) return;

    if (this.animationProgress < 1) {
      this.animationProgress = Math.min(1, this.animationProgress + dt * 4);
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

    // Draw semi-transparent overlay
    const overlayAlpha = 0.7 * this.animationProgress;
    this.ctx.fillStyle = `rgba(0, 0, 0, ${overlayAlpha})`;
    this.ctx.fillRect(0, 0, width, height);

    // Draw panel background
    this.drawPanel(width, height);

    // Draw title
    this.drawTitle(width);

    // Draw stats
    this.drawStats(width);

    // Draw buttons
    for (let i = 0; i < this.buttons.length; i++) {
      const button = this.buttons[i];
      if (button) {
        this.drawButton(button, i === this.selectedIndex);
      }
    }

    // Draw instructions
    this.drawInstructions(width, height);
  }

  private drawPanel(width: number, height: number): void {
    const panelWidth = 400;
    const panelHeight = 480;
    const panelX = (width - panelWidth) / 2;
    const panelY = (height - panelHeight) / 2;

    // Animation offset
    const animOffset = (1 - this.animationProgress) * 30;
    const y = panelY + animOffset;

    // Panel shadow
    this.ctx.fillStyle = 'rgba(0, 0, 0, 0.5)';
    this.roundRect(panelX + 6, y + 6, panelWidth, panelHeight, 12);
    this.ctx.fill();

    // Panel background
    const gradient = this.ctx.createLinearGradient(panelX, y, panelX, y + panelHeight);
    gradient.addColorStop(0, '#1a1a2e');
    gradient.addColorStop(1, '#0f0f1a');

    this.ctx.fillStyle = gradient;
    this.roundRect(panelX, y, panelWidth, panelHeight, 12);
    this.ctx.fill();

    // Panel border
    this.ctx.strokeStyle = '#333355';
    this.ctx.lineWidth = 2;
    this.roundRect(panelX, y, panelWidth, panelHeight, 12);
    this.ctx.stroke();
  }

  private drawTitle(width: number): void {
    const titleY = this.canvas.height / 2 - 180;

    this.ctx.font = 'bold 36px Arial, sans-serif';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';

    // Glow effect
    this.ctx.shadowColor = '#8B0000';
    this.ctx.shadowBlur = 15;

    // Text
    this.ctx.fillStyle = '#FFD700';
    this.ctx.fillText('PAUSED', width / 2, titleY);

    this.ctx.shadowBlur = 0;

    // Underline
    this.ctx.strokeStyle = '#8B0000';
    this.ctx.lineWidth = 2;
    this.ctx.beginPath();
    this.ctx.moveTo(width / 2 - 60, titleY + 25);
    this.ctx.lineTo(width / 2 + 60, titleY + 25);
    this.ctx.stroke();
  }

  private drawStats(width: number): void {
    const centerX = width / 2;
    const statsY = this.canvas.height / 2 - 120;

    const minutes = Math.floor(this.stats.timeElapsed / 60);
    const seconds = Math.floor(this.stats.timeElapsed % 60);
    const timeStr = `${minutes}:${seconds.toString().padStart(2, '0')}`;

    const stats = [
      { label: 'Score', value: this.stats.score.toLocaleString() },
      { label: 'Kills', value: this.stats.kills.toString() },
      { label: 'Time', value: timeStr },
      { label: 'Level', value: this.stats.level.toString() },
    ];

    this.ctx.font = 'bold 16px Arial, sans-serif';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';

    let currentY = statsY;
    for (const stat of stats) {
      // Label
      this.ctx.fillStyle = '#888899';
      this.ctx.fillText(stat.label, centerX - 50, currentY);

      // Value
      this.ctx.fillStyle = '#FFFFFF';
      this.ctx.fillText(stat.value, centerX + 50, currentY);

      currentY += 28;
    }

    // Separator line
    this.ctx.strokeStyle = '#333355';
    this.ctx.lineWidth = 1;
    this.ctx.beginPath();
    this.ctx.moveTo(centerX - 100, currentY + 5);
    this.ctx.lineTo(centerX + 100, currentY + 5);
    this.ctx.stroke();
  }

  private drawButton(button: PauseButton, isSelected: boolean): void {
    const { x, y, width, height, label, hovered } = button;
    const isHighlighted = hovered || isSelected;

    // Button background
    const gradient = this.ctx.createLinearGradient(x, y, x, y + height);
    if (isHighlighted) {
      gradient.addColorStop(0, '#660000');
      gradient.addColorStop(1, '#330000');
    } else {
      gradient.addColorStop(0, '#2a2a3e');
      gradient.addColorStop(1, '#1a1a2e');
    }

    this.ctx.fillStyle = gradient;
    this.roundRect(x, y, width, height, 6);
    this.ctx.fill();

    // Button border
    this.ctx.strokeStyle = isHighlighted ? '#FF4444' : '#444466';
    this.ctx.lineWidth = isHighlighted ? 2 : 1;
    this.roundRect(x, y, width, height, 6);
    this.ctx.stroke();

    // Button text
    this.ctx.font = 'bold 16px Arial, sans-serif';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';
    this.ctx.fillStyle = isHighlighted ? '#FFFFFF' : '#AAAAAA';
    this.ctx.fillText(label, x + width / 2, y + height / 2);
  }

  private drawInstructions(width: number, height: number): void {
    this.ctx.font = '14px Arial, sans-serif';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'bottom';
    this.ctx.fillStyle = 'rgba(255, 255, 255, 0.5)';
    this.ctx.fillText(
      'Press ESC to Resume | Arrow Keys to Navigate | Enter to Select',
      width / 2,
      height - 50
    );
  }

  private handleKeyDown(e: KeyboardEvent): void {
    if (!this.isVisible) return;

    switch (e.key) {
      case 'Escape':
        this.options.onResume();
        break;
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

  private selectOption(option: PauseOption): void {
    switch (option) {
      case 'RESUME':
        this.options.onResume();
        break;
      case 'RESTART':
        this.options.onRestart();
        break;
      case 'OPTIONS':
        this.options.onShowOptions?.();
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
