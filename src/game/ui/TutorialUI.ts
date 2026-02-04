/**
 * Tutorial UI
 *
 * Displays tutorial prompts with fade-in/out animation.
 * Provides buttons for: Repeat Tutorial, Play Game, Skip Tutorial.
 *
 * Note: Buttons are only shown at specific stages (intro and completion).
 * During gameplay stages, only the prompt text is displayed.
 */

import type { TutorialStage } from '../modes/TutorialMode';

export type TutorialButtonId = 'REPEAT' | 'PLAY' | 'SKIP';

export interface TutorialButton {
  id: TutorialButtonId;
  label: string;
  x: number;
  y: number;
  width: number;
  height: number;
  hovered: boolean;
}

export interface TutorialUIOptions {
  canvas: HTMLCanvasElement;
  onRepeat?: () => void;
  onPlay?: () => void;
  onSkip?: () => void;
}

export class TutorialUI {
  private canvas: HTMLCanvasElement;
  private ctx: CanvasRenderingContext2D;
  private options: TutorialUIOptions;

  // UI State
  private isVisible = false;
  private currentStage: TutorialStage = 0;
  private promptText = '';
  private stageName = '';
  private alpha = 0;
  private targetAlpha = 1;
  private buttons: TutorialButton[] = [];
  private showButtons = false;

  // Input handling
  private clickHandler: (e: MouseEvent) => void;
  private mouseMoveHandler: (e: MouseEvent) => void;

  // Layout constants
  private readonly PROMPT_BOX_WIDTH = 600;
  private readonly PROMPT_BOX_HEIGHT = 200;
  private readonly BUTTON_WIDTH = 180;
  private readonly BUTTON_HEIGHT = 45;
  private readonly BUTTON_SPACING = 20;

  constructor(options: TutorialUIOptions) {
    this.canvas = options.canvas;
    const ctx = this.canvas.getContext('2d');
    if (!ctx) {
      throw new Error('Could not get canvas context');
    }
    this.ctx = ctx;
    this.options = options;

    // Bind input handlers
    this.clickHandler = this.handleClick.bind(this);
    this.mouseMoveHandler = this.handleMouseMove.bind(this);

    this.attachEventListeners();
    this.buildButtons();
  }

  private buildButtons(): void {
    const centerX = this.canvas.width / 2;
    const buttonY = this.canvas.height / 2 + 120;

    const buttonData: { id: TutorialButtonId; label: string }[] = [
      { id: 'REPEAT', label: 'Repeat Tutorial' },
      { id: 'PLAY', label: 'Play Game' },
      { id: 'SKIP', label: 'Skip Tutorial' },
    ];

    const totalWidth =
      buttonData.length * this.BUTTON_WIDTH + (buttonData.length - 1) * this.BUTTON_SPACING;
    const startX = centerX - totalWidth / 2;

    this.buttons = buttonData.map((data, index) => ({
      id: data.id,
      label: data.label,
      x: startX + index * (this.BUTTON_WIDTH + this.BUTTON_SPACING),
      y: buttonY,
      width: this.BUTTON_WIDTH,
      height: this.BUTTON_HEIGHT,
      hovered: false,
    }));
  }

  /**
   * Show the tutorial UI
   */
  show(): void {
    this.isVisible = true;
    this.alpha = 0;
    this.targetAlpha = 1;
  }

  /**
   * Hide the tutorial UI
   */
  hide(): void {
    this.isVisible = false;
    this.showButtons = false;
  }

  /**
   * Check if UI is visible
   */
  isShown(): boolean {
    return this.isVisible;
  }

  /**
   * Update the displayed stage
   */
  setStage(stage: TutorialStage, promptText: string, stageName: string): void {
    this.currentStage = stage;
    this.promptText = promptText;
    this.stageName = stageName;

    // Show buttons on intro (stage 0) and completion (stage 8)
    this.showButtons = stage === 0 || stage === 8;

    // Rebuild buttons in case canvas was resized
    this.buildButtons();
  }

  /**
   * Update animation
   */
  update(dt: number): void {
    if (!this.isVisible) return;

    // Fade in/out
    const fadeSpeed = dt * 3;
    if (this.alpha < this.targetAlpha) {
      this.alpha = Math.min(this.targetAlpha, this.alpha + fadeSpeed);
    } else if (this.alpha > this.targetAlpha) {
      this.alpha = Math.max(0, this.alpha - fadeSpeed);
    }
  }

  /**
   * Render the UI
   */
  render(): void {
    if (!this.isVisible || this.alpha <= 0) return;

    // Draw prompt box
    this.drawPromptBox();

    // Draw buttons if enabled
    if (this.showButtons && this.alpha >= 0.9) {
      for (const button of this.buttons) {
        this.drawButton(button);
      }
    }
  }

  private drawPromptBox(): void {
    const centerX = this.canvas.width / 2;
    const centerY = this.canvas.height / 2;
    const boxX = centerX - this.PROMPT_BOX_WIDTH / 2;
    const boxY = centerY - this.PROMPT_BOX_HEIGHT / 2;

    // Box background with alpha
    this.ctx.fillStyle = `rgba(20, 20, 30, ${0.9 * this.alpha})`;
    this.roundRect(boxX, boxY, this.PROMPT_BOX_WIDTH, this.PROMPT_BOX_HEIGHT, 12);
    this.ctx.fill();

    // Box border
    this.ctx.strokeStyle = `rgba(139, 0, 0, ${this.alpha})`;
    this.ctx.lineWidth = 3;
    this.roundRect(boxX, boxY, this.PROMPT_BOX_WIDTH, this.PROMPT_BOX_HEIGHT, 12);
    this.ctx.stroke();

    // Stage name header
    this.ctx.font = 'bold 20px Arial, sans-serif';
    this.ctx.fillStyle = `rgba(255, 68, 68, ${this.alpha})`;
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'top';
    this.ctx.fillText(this.stageName.toUpperCase(), centerX, boxY + 20);

    // Prompt text
    this.ctx.font = '18px Arial, sans-serif';
    this.ctx.fillStyle = `rgba(255, 255, 255, ${this.alpha})`;
    this.wrapText(this.promptText, centerX, boxY + 60, this.PROMPT_BOX_WIDTH - 40, 24);

    // Progress indicator
    if (this.currentStage > 0 && this.currentStage < 8) {
      this.drawProgressIndicator(centerX, boxY + this.PROMPT_BOX_HEIGHT - 30);
    }
  }

  private drawProgressIndicator(x: number, y: number): void {
    const stageCount = 7; // Stages 1-7 are gameplay
    const currentProgress = Math.min(this.currentStage, stageCount);
    const barWidth = 200;
    const barHeight = 6;

    const barX = x - barWidth / 2;

    // Background
    this.ctx.fillStyle = `rgba(100, 100, 100, ${0.5 * this.alpha})`;
    this.ctx.fillRect(barX, y, barWidth, barHeight);

    // Progress
    const progressWidth = (currentProgress / stageCount) * barWidth;
    this.ctx.fillStyle = `rgba(255, 68, 68, ${this.alpha})`;
    this.ctx.fillRect(barX, y, progressWidth, barHeight);
  }

  private drawButton(button: TutorialButton): void {
    const { x, y, width, height, label, hovered } = button;

    // Animation for hover
    const scale = hovered ? 1.05 : 1;
    const offsetX = (width * (scale - 1)) / 2;
    const offsetY = (height * (scale - 1)) / 2;

    // Button shadow
    this.ctx.fillStyle = 'rgba(0, 0, 0, 0.5)';
    this.roundRect(x + 4, y + 4, width, height, 6);
    this.ctx.fill();

    // Button background
    const gradient = this.ctx.createLinearGradient(x, y, x, y + height);
    if (hovered) {
      gradient.addColorStop(0, '#660000');
      gradient.addColorStop(1, '#330000');
    } else {
      gradient.addColorStop(0, '#444444');
      gradient.addColorStop(1, '#222222');
    }

    this.ctx.fillStyle = gradient;
    this.roundRect(x - offsetX, y - offsetY, width * scale, height * scale, 6);
    this.ctx.fill();

    // Button border
    this.ctx.strokeStyle = hovered ? '#FF4444' : '#666666';
    this.ctx.lineWidth = hovered ? 2 : 1;
    this.roundRect(x - offsetX, y - offsetY, width * scale, height * scale, 6);
    this.ctx.stroke();

    // Button text
    this.ctx.font = 'bold 16px Arial, sans-serif';
    this.ctx.fillStyle = hovered ? '#FFFFFF' : '#CCCCCC';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';
    this.ctx.fillText(label, x + width / 2, y + height / 2);
  }

  private handleClick(e: MouseEvent): void {
    if (!this.isVisible || !this.showButtons) return;

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
        this.handleButtonClick(button.id);
        return;
      }
    }
  }

  private handleButtonClick(buttonId: TutorialButtonId): void {
    switch (buttonId) {
      case 'REPEAT':
        this.options.onRepeat?.();
        break;
      case 'PLAY':
        this.options.onPlay?.();
        break;
      case 'SKIP':
        this.options.onSkip?.();
        break;
    }
  }

  private handleMouseMove(e: MouseEvent): void {
    if (!this.isVisible || !this.showButtons) return;

    const rect = this.canvas.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    for (const button of this.buttons) {
      button.hovered =
        x >= button.x &&
        x <= button.x + button.width &&
        y >= button.y &&
        y <= button.y + button.height;
    }
  }

  private attachEventListeners(): void {
    this.canvas.addEventListener('click', this.clickHandler);
    this.canvas.addEventListener('mousemove', this.mouseMoveHandler);
  }

  detachEventListeners(): void {
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
   * Clean up event listeners
   */
  destroy(): void {
    this.detachEventListeners();
  }
}
