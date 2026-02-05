/**
 * Credits Screen UI
 *
 * Displays game credits, attribution, and license information.
 * Follows the same pattern as GameOverUI and MainMenuUI.
 */

export interface CreditsUIOptions {
  canvas: HTMLCanvasElement;
  onBack: () => void;
}

export interface CreditsButton {
  id: 'BACK';
  label: string;
  x: number;
  y: number;
  width: number;
  height: number;
  hovered: boolean;
}

export class CreditsUI {
  private canvas: HTMLCanvasElement;
  private ctx: CanvasRenderingContext2D;
  private options: CreditsUIOptions;

  // UI State
  private isVisible = false;
  private button: CreditsButton;
  private animationProgress = 0;
  private scrollY = 0;
  private maxScrollY = 0;

  // Input handling
  private keyHandler: (e: KeyboardEvent) => void;
  private clickHandler: (e: MouseEvent) => void;
  private mouseMoveHandler: (e: MouseEvent) => void;
  private wheelHandler: (e: WheelEvent) => void;

  // Layout constants
  private readonly BUTTON_WIDTH = 220;
  private readonly BUTTON_HEIGHT = 50;
  private readonly TITLE_SIZE = 48;
  private readonly SECTION_TITLE_SIZE = 24;
  private readonly TEXT_SIZE = 16;
  private readonly LINE_HEIGHT = 28;
  private readonly PADDING = 40;

  // Credits content
  private readonly creditsSections: Array<{ title: string; lines: string[] }> = [
    {
      title: 'Original Game',
      lines: ['Crimsonland (2003)', 'Created by 10tons Ltd', 'Original design by Tero Alatalo'],
    },
    {
      title: 'Remake',
      lines: [
        'Crimsonland Remake',
        'A fan-made tribute project',
        'Built with TypeScript and HTML5 Canvas',
      ],
    },
    {
      title: 'Attribution',
      lines: [
        'Game engine: Custom ECS implementation',
        'Audio: Web Audio API',
        'Rendering: HTML5 Canvas 2D',
        'No external game libraries used',
      ],
    },
    {
      title: 'License',
      lines: [
        'MIT License',
        '',
        'This is a fan remake for educational purposes.',
        'Original Crimsonland is a trademark of 10tons Ltd.',
        'Please support the original game and developers!',
      ],
    },
  ];

  constructor(options: CreditsUIOptions) {
    this.canvas = options.canvas;
    const ctx = this.canvas.getContext('2d');
    if (!ctx) {
      throw new Error('Could not get canvas context');
    }
    this.ctx = ctx;
    this.options = options;

    // Initialize button
    this.button = {
      id: 'BACK',
      label: 'BACK TO MENU',
      x: this.canvas.width / 2 - this.BUTTON_WIDTH / 2,
      y: this.canvas.height - 100,
      width: this.BUTTON_WIDTH,
      height: this.BUTTON_HEIGHT,
      hovered: false,
    };

    // Calculate max scroll based on content
    this.calculateMaxScroll();

    // Bind input handlers
    this.keyHandler = this.handleKeyDown.bind(this);
    this.clickHandler = this.handleClick.bind(this);
    this.mouseMoveHandler = this.handleMouseMove.bind(this);
    this.wheelHandler = this.handleWheel.bind(this);

    this.attachEventListeners();
  }

  private calculateMaxScroll(): void {
    // Calculate total content height
    let contentHeight = this.PADDING * 2; // Top and bottom padding
    contentHeight += this.TITLE_SIZE + this.PADDING; // Main title

    for (const section of this.creditsSections) {
      contentHeight += this.SECTION_TITLE_SIZE + this.PADDING / 2; // Section title
      contentHeight += section.lines.length * this.LINE_HEIGHT; // Lines
      contentHeight += this.PADDING; // Space between sections
    }

    // Available height (minus button area)
    const availableHeight = this.canvas.height - 150;
    this.maxScrollY = Math.max(0, contentHeight - availableHeight);
  }

  /**
   * Show the credits screen
   */
  show(): void {
    this.isVisible = true;
    this.animationProgress = 0;
    this.scrollY = 0;
    this.calculateMaxScroll();
    this.updateButtonPosition();
    this.animateIn();
  }

  /**
   * Hide the credits screen
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
  }

  /**
   * Render the UI
   */
  render(): void {
    if (!this.isVisible) return;

    const width = this.canvas.width;
    const height = this.canvas.height;

    // Draw background
    this.drawBackground(width, height);

    // Draw title
    this.drawTitle(width);

    // Draw credits content with clipping
    this.drawCreditsContent(width, height);

    // Draw button
    this.drawButton();

    // Draw scroll indicator if needed
    if (this.maxScrollY > 0) {
      this.drawScrollIndicator(width, height);
    }
  }

  private drawBackground(width: number, height: number): void {
    // Dark background
    this.ctx.fillStyle = '#0a0a0f';
    this.ctx.fillRect(0, 0, width, height);

    // Vignette effect
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
    const animOffset = (1 - this.animationProgress) * 30;
    const titleY = 60 + animOffset;

    // Glow effect
    const pulse = Math.sin(Date.now() / 500) * 5;
    this.ctx.shadowColor = '#8B0000';
    this.ctx.shadowBlur = 20 + pulse;

    // Title text
    this.ctx.font = `bold ${this.TITLE_SIZE}px Arial, sans-serif`;
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';
    this.ctx.fillStyle = '#FFFFFF';
    this.ctx.fillText('CREDITS', width / 2, titleY);

    this.ctx.shadowBlur = 0;

    // Decorative line
    this.ctx.strokeStyle = '#8B0000';
    this.ctx.lineWidth = 2;
    this.ctx.beginPath();
    this.ctx.moveTo(width / 2 - 80, titleY + 30);
    this.ctx.lineTo(width / 2 + 80, titleY + 30);
    this.ctx.stroke();
  }

  private drawCreditsContent(width: number, height: number): void {
    const animOffset = (1 - this.animationProgress) * 20;
    const contentTop = 120;
    const contentHeight = height - 220; // Space for title and button
    const contentLeft = this.PADDING;
    const contentWidth = width - this.PADDING * 2;

    // Create clipping region
    this.ctx.save();
    this.ctx.beginPath();
    this.ctx.rect(contentLeft, contentTop, contentWidth, contentHeight);
    this.ctx.clip();

    let currentY = contentTop + this.PADDING - this.scrollY + animOffset;

    for (const section of this.creditsSections) {
      // Section title
      this.ctx.font = `bold ${this.SECTION_TITLE_SIZE}px Arial, sans-serif`;
      this.ctx.textAlign = 'center';
      this.ctx.textBaseline = 'middle';
      this.ctx.fillStyle = '#CC6666';
      this.ctx.fillText(section.title, width / 2, currentY);
      currentY += this.SECTION_TITLE_SIZE + 10;

      // Section lines
      this.ctx.font = `${this.TEXT_SIZE}px Arial, sans-serif`;
      this.ctx.fillStyle = '#AAAAAA';
      for (const line of section.lines) {
        if (line) {
          this.ctx.fillText(line, width / 2, currentY);
        }
        currentY += this.LINE_HEIGHT;
      }

      currentY += this.PADDING;
    }

    this.ctx.restore();
  }

  private drawButton(): void {
    const { x, y, width, height, label, hovered } = this.button;
    const isHighlighted = hovered;

    // Animation offset
    const animOffset = (1 - this.animationProgress) * 20;

    // Button shadow
    this.ctx.fillStyle = 'rgba(0, 0, 0, 0.5)';
    this.roundRect(x + 4, y + 4 + animOffset, width, height, 8);
    this.ctx.fill();

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

  private drawScrollIndicator(width: number, height: number): void {
    const indicatorY = height - 130;
    const alpha = 0.5 + Math.sin(Date.now() / 300) * 0.3;

    this.ctx.font = '14px Arial, sans-serif';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';
    this.ctx.fillStyle = `rgba(170, 170, 170, ${alpha})`;
    this.ctx.fillText('Scroll for more ↓', width / 2, indicatorY);
  }

  private updateButtonPosition(): void {
    this.button.x = this.canvas.width / 2 - this.BUTTON_WIDTH / 2;
    this.button.y = this.canvas.height - 80;
  }

  private handleKeyDown(e: KeyboardEvent): void {
    if (!this.isVisible) return;

    switch (e.key) {
      case 'Escape':
      case 'Enter':
      case ' ':
        this.goBack();
        break;
      case 'ArrowUp':
        this.scrollY = Math.max(0, this.scrollY - 50);
        e.preventDefault();
        break;
      case 'ArrowDown':
        this.scrollY = Math.min(this.maxScrollY, this.scrollY + 50);
        e.preventDefault();
        break;
      case 'Home':
        this.scrollY = 0;
        e.preventDefault();
        break;
      case 'End':
        this.scrollY = this.maxScrollY;
        e.preventDefault();
        break;
    }
  }

  private handleClick(e: MouseEvent): void {
    if (!this.isVisible) return;

    const rect = this.canvas.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    const btn = this.button;
    if (x >= btn.x && x <= btn.x + btn.width && y >= btn.y && y <= btn.y + btn.height) {
      this.goBack();
    }
  }

  private handleMouseMove(e: MouseEvent): void {
    if (!this.isVisible) return;

    const rect = this.canvas.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    const btn = this.button;
    btn.hovered = x >= btn.x && x <= btn.x + btn.width && y >= btn.y && y <= btn.y + btn.height;
  }

  private handleWheel(e: WheelEvent): void {
    if (!this.isVisible) return;

    e.preventDefault();
    const delta = e.deltaY > 0 ? 30 : -30;
    this.scrollY = Math.max(0, Math.min(this.maxScrollY, this.scrollY + delta));
  }

  private goBack(): void {
    this.options.onBack();
  }

  private animateIn(): void {
    this.animationProgress = 0;
  }

  private attachEventListeners(): void {
    window.addEventListener('keydown', this.keyHandler);
    this.canvas.addEventListener('click', this.clickHandler);
    this.canvas.addEventListener('mousemove', this.mouseMoveHandler);
    this.canvas.addEventListener('wheel', this.wheelHandler, { passive: false });
  }

  private detachEventListeners(): void {
    window.removeEventListener('keydown', this.keyHandler);
    this.canvas.removeEventListener('click', this.clickHandler);
    this.canvas.removeEventListener('mousemove', this.mouseMoveHandler);
    this.canvas.removeEventListener('wheel', this.wheelHandler);
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
