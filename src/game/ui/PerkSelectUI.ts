/**
 * Perk Selection UI
 *
 * Displays perk choices when player levels up.
 * Handles input for perk selection.
 */

import type { PerkId } from '../../types';
import { getPerkData, type PerkCategory } from '../data/perks';

export interface PerkSelectUIOptions {
  canvas: HTMLCanvasElement;
  onSelect: (perkId: PerkId) => void;
  onCancel?: () => void;
}

export interface PerkCard {
  perkId: PerkId;
  x: number;
  y: number;
  width: number;
  height: number;
  hovered: boolean;
  selected: boolean;
}

export class PerkSelectUI {
  private canvas: HTMLCanvasElement;
  private ctx: CanvasRenderingContext2D;
  private options: PerkSelectUIOptions;

  // UI State
  private isVisible = false;
  private perkChoices: PerkId[] = [];
  private cards: PerkCard[] = [];
  private selectedIndex = -1;
  private animationProgress = 0;

  // Input handling
  private keyHandler: (e: KeyboardEvent) => void;
  private clickHandler: (e: MouseEvent) => void;
  private mouseMoveHandler: (e: MouseEvent) => void;

  // Layout constants
  private readonly CARD_WIDTH = 280;
  private readonly CARD_HEIGHT = 350;
  private readonly CARD_SPACING = 40;

  constructor(options: PerkSelectUIOptions) {
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
  }

  /**
   * Show the perk selection UI
   */
  show(perkChoices: PerkId[]): void {
    this.perkChoices = perkChoices;
    this.isVisible = true;
    this.selectedIndex = -1;
    this.animationProgress = 0;

    this.layoutCards();
    this.animateIn();
  }

  /**
   * Hide the perk selection UI
   */
  hide(): void {
    this.isVisible = false;
    this.perkChoices = [];
    this.cards = [];
    this.selectedIndex = -1;
  }

  /**
   * Check if UI is visible
   */
  isShown(): boolean {
    return this.isVisible;
  }

  /**
   * Get current perk choices
   */
  getChoices(): PerkId[] {
    return [...this.perkChoices];
  }

  /**
   * Render the UI
   */
  render(): void {
    if (!this.isVisible) return;

    const width = this.canvas.width;
    const height = this.canvas.height;

    // Draw semi-transparent overlay
    this.ctx.fillStyle = `rgba(0, 0, 0, ${0.7 * this.animationProgress})`;
    this.ctx.fillRect(0, 0, width, height);

    // Draw title
    this.drawTitle(width, height);

    // Draw perk cards
    for (let i = 0; i < this.cards.length; i++) {
      const card = this.cards[i];
      if (card) this.drawCard(card, i);
    }

    // Draw instructions
    this.drawInstructions(width, height);
  }

  /**
   * Update animation
   */
  update(dt: number): void {
    if (!this.isVisible) return;

    // Animate cards in
    if (this.animationProgress < 1) {
      this.animationProgress = Math.min(1, this.animationProgress + dt * 3);
    }
  }

  private layoutCards(): void {
    const width = this.canvas.width;
    const height = this.canvas.height;

    const totalWidth =
      this.perkChoices.length * this.CARD_WIDTH + (this.perkChoices.length - 1) * this.CARD_SPACING;
    const startX = (width - totalWidth) / 2;
    const centerY = height / 2;

    this.cards = this.perkChoices.map((perkId, index) => ({
      perkId,
      x: startX + index * (this.CARD_WIDTH + this.CARD_SPACING),
      y: centerY - this.CARD_HEIGHT / 2,
      width: this.CARD_WIDTH,
      height: this.CARD_HEIGHT,
      hovered: false,
      selected: false,
    }));
  }

  private drawTitle(width: number, _height: number): void {
    const title = 'LEVEL UP! Choose a Perk';
    this.ctx.font = 'bold 36px Arial, sans-serif';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'top';

    // Draw shadow
    this.ctx.fillStyle = 'rgba(0, 0, 0, 0.5)';
    this.ctx.fillText(title, width / 2 + 2, 82);

    // Draw text
    this.ctx.fillStyle = '#FFD700';
    this.ctx.fillText(title, width / 2, 80);
  }

  private drawCard(card: PerkCard, index: number): void {
    const perk = getPerkData(card.perkId);
    if (!perk) return;

    const { x, y, width, height } = card;

    // Animation offset
    const animOffset = (1 - this.animationProgress) * 50;
    const animY = y + animOffset * (index - 1);

    // Card background
    const isHovered = card.hovered || this.selectedIndex === index;
    const bgColor = this.getCategoryColor(perk.category);

    // Card shadow
    this.ctx.fillStyle = 'rgba(0, 0, 0, 0.3)';
    this.ctx.fillRect(x + 4, animY + 4, width, height);

    // Card body
    this.ctx.fillStyle = isHovered ? this.lightenColor(bgColor, 20) : bgColor;
    this.roundRect(x, animY, width, height, 12);
    this.ctx.fill();

    // Card border
    this.ctx.strokeStyle = isHovered ? '#FFD700' : '#444';
    this.ctx.lineWidth = isHovered ? 3 : 2;
    this.roundRect(x, animY, width, height, 12);
    this.ctx.stroke();

    // Category indicator
    this.ctx.fillStyle = this.getCategoryDarkColor(perk.category);
    this.ctx.fillRect(x, animY, width, 40);

    // Category label
    this.ctx.font = 'bold 14px Arial, sans-serif';
    this.ctx.fillStyle = '#FFF';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';
    this.ctx.fillText(perk.category.toUpperCase(), x + width / 2, animY + 20);

    // Perk name
    this.ctx.font = 'bold 22px Arial, sans-serif';
    this.ctx.fillStyle = '#FFF';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'top';
    this.wrapText(perk.name, x + width / 2, animY + 60, width - 20, 26);

    // Perk description
    this.ctx.font = '16px Arial, sans-serif';
    this.ctx.fillStyle = '#CCC';
    this.wrapText(perk.description, x + width / 2, animY + 120, width - 20, 22);

    // Rank indicator (if stackable)
    if (perk.maxRank > 1) {
      this.ctx.font = '14px Arial, sans-serif';
      this.ctx.fillStyle = '#AAA';
      this.ctx.fillText(`Max ${perk.maxRank} ranks`, x + width / 2, animY + height - 50);
    }

    // Selection key hint
    this.ctx.font = 'bold 24px Arial, sans-serif';
    this.ctx.fillStyle = isHovered ? '#FFD700' : '#888';
    this.ctx.fillText((index + 1).toString(), x + width / 2, animY + height - 25);
  }

  private drawInstructions(width: number, height: number): void {
    this.ctx.font = '16px Arial, sans-serif';
    this.ctx.fillStyle = 'rgba(255, 255, 255, 0.7)';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'bottom';
    this.ctx.fillText(
      'Press 1, 2, or 3 to select  |  Click a card to choose',
      width / 2,
      height - 40
    );
  }

  private handleKeyDown(e: KeyboardEvent): void {
    if (!this.isVisible) return;

    switch (e.key) {
      case '1':
        this.selectCard(0);
        break;
      case '2':
        this.selectCard(1);
        break;
      case '3':
        this.selectCard(2);
        break;
      case 'Escape':
        // Cancel only if callback provided
        if (this.options.onCancel) {
          this.options.onCancel();
        }
        break;
    }
  }

  private handleClick(e: MouseEvent): void {
    if (!this.isVisible) return;

    const rect = this.canvas.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    for (let i = 0; i < this.cards.length; i++) {
      const card = this.cards[i];
      if (
        card &&
        x >= card.x &&
        x <= card.x + card.width &&
        y >= card.y &&
        y <= card.y + card.height
      ) {
        this.selectCard(i);
        break;
      }
    }
  }

  private handleMouseMove(e: MouseEvent): void {
    if (!this.isVisible) return;

    const rect = this.canvas.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    for (const card of this.cards) {
      card.hovered =
        x >= card.x && x <= card.x + card.width && y >= card.y && y <= card.y + card.height;
    }
  }

  private selectCard(index: number): void {
    if (index < 0 || index >= this.perkChoices.length) return;

    this.selectedIndex = index;
    const perkId = this.perkChoices[index];
    if (perkId === undefined) return;

    // Small delay for visual feedback
    setTimeout(() => {
      this.options.onSelect(perkId);
    }, 150);
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

  private animateIn(): void {
    this.animationProgress = 0;
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

  private getCategoryColor(category: PerkCategory): string {
    switch (category) {
      case 'combat':
        return '#8B0000'; // Dark red
      case 'defense':
        return '#006400'; // Dark green
      case 'utility':
        return '#00008B'; // Dark blue
      case 'movement':
        return '#FF8C00'; // Dark orange
      case 'special':
        return '#4B0082'; // Indigo
      case 'gamble':
        return '#8B008B'; // Dark magenta
      case 'meta':
        return '#2F4F4F'; // Dark slate gray
      default:
        return '#444';
    }
  }

  private getCategoryDarkColor(category: PerkCategory): string {
    switch (category) {
      case 'combat':
        return '#4B0000';
      case 'defense':
        return '#004B00';
      case 'utility':
        return '#00004B';
      case 'movement':
        return '#CC6600';
      case 'special':
        return '#2B0052';
      case 'gamble':
        return '#4B004B';
      case 'meta':
        return '#1F2F2F';
      default:
        return '#222';
    }
  }

  private lightenColor(color: string, percent: number): string {
    const num = Number.parseInt(color.replace('#', ''), 16);
    const amt = Math.round(2.55 * percent);
    const R = Math.min(255, (num >> 16) + amt);
    const G = Math.min(255, ((num >> 8) & 0x00ff) + amt);
    const B = Math.min(255, (num & 0x0000ff) + amt);
    return `#${(0x1000000 + R * 0x10000 + G * 0x100 + B).toString(16).slice(1)}`;
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
