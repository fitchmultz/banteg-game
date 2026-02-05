/**
 * High Scores UI
 *
 * Displays high scores for Survival, Rush, and Quest modes.
 * Allows sorting, filtering, import/export, and reset functionality.
 *
 * This is the main orchestrator that composes tab renderers,
 * drawing utilities, and input handlers.
 */

import type { ProgressionManager } from '../../progression/ProgressionManager';
import type { HighScoresUIOptions, HighScoreTab, SortOption, SortDirection } from './types';
import { LAYOUT } from './layout';
import {
  drawPanel,
  drawTitle,
  drawTabs,
  drawSortControls,
  drawActionButtons,
  drawMessage,
  drawConfirmationModal,
  drawStatRow,
} from './draw';
import { drawSurvivalTab, drawQuestsTab, drawRushTab } from './tabs';
import {
  handleKeyDown,
  getTabAtPosition,
  getSortOptionAtPosition,
  getActionButtonAtPosition,
  getConfirmationButtonAtPosition,
} from './input';

export type { HighScoreTab, SortOption, SortDirection, HighScoresUIOptions } from './types';

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
    this.keyHandler = this.onKeyDown.bind(this);
    this.clickHandler = this.onClick.bind(this);
    this.mouseMoveHandler = this.onMouseMove.bind(this);

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
    drawPanel(this.ctx, width, height);

    // Draw title
    drawTitle(this.ctx, width, height);

    // Draw tabs
    drawTabs(this.ctx, width, height, this.currentTab);

    // Draw content based on current tab
    const centerX = width / 2;
    const contentY =
      height / 2 - LAYOUT.PANEL_HEIGHT / 2 + LAYOUT.TAB_HEIGHT + LAYOUT.HEADER_HEIGHT + 20;
    const contentWidth = LAYOUT.PANEL_WIDTH - LAYOUT.PADDING * 2;

    const boundDrawStatRow = (
      label: string,
      value: string,
      x: number,
      y: number,
      w: number
    ): void => {
      drawStatRow(this.ctx, label, value, x, y, w);
    };

    switch (this.currentTab) {
      case 'SURVIVAL':
        drawSurvivalTab(
          this.ctx,
          this.progressionManager,
          centerX,
          contentY,
          contentWidth,
          boundDrawStatRow
        );
        break;
      case 'QUESTS':
        drawQuestsTab(
          this.ctx,
          this.progressionManager,
          centerX,
          contentY,
          contentWidth,
          this.sortBy,
          this.sortDirection
        );
        break;
      case 'RUSH':
        drawRushTab(
          this.ctx,
          this.progressionManager,
          centerX,
          contentY,
          contentWidth,
          boundDrawStatRow
        );
        break;
    }

    // Draw sort controls
    drawSortControls(
      this.ctx,
      centerX - contentWidth / 2,
      contentY + 200,
      this.sortBy,
      this.sortDirection
    );

    // Draw action buttons
    drawActionButtons(this.ctx, centerX - contentWidth / 2, contentY + 260);

    // Draw message if any
    drawMessage(this.ctx, width, height, this.messageText, this.messageIsError);

    // Draw confirmation modal if showing
    if (this.showConfirmation) {
      drawConfirmationModal(this.ctx, width, height);
    }
  }

  private onKeyDown(e: KeyboardEvent): void {
    if (!this.isVisible) return;

    handleKeyDown(
      e,
      {
        currentTab: this.currentTab,
        sortBy: this.sortBy,
        sortDirection: this.sortDirection,
        showConfirmation: this.showConfirmation,
      },
      {
        onBack: () => this.options.onBack(),
        onTabChange: (tab) => {
          this.currentTab = tab;
        },
        onSortChange: (sortBy, sortDirection) => {
          this.sortBy = sortBy;
          this.sortDirection = sortDirection;
        },
        onExport: () => this.handleExport(),
        onImport: () => this.handleImport(),
        onReset: () => this.handleReset(),
        onConfirmReset: () => this.confirmReset(),
        onCancelReset: () => this.cancelReset(),
      }
    );
  }

  private onClick(e: MouseEvent): void {
    if (!this.isVisible) return;

    const rect = this.canvas.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;
    const width = this.canvas.width;
    const height = this.canvas.height;

    if (this.showConfirmation) {
      const button = getConfirmationButtonAtPosition(width, height, x, y);
      if (button === 'cancel') {
        this.cancelReset();
      } else if (button === 'confirm') {
        this.confirmReset();
      }
      return;
    }

    // Check tabs
    const tab = getTabAtPosition(width, height, x, y);
    if (tab) {
      this.currentTab = tab;
      return;
    }

    // Check sort controls
    const sortOption = getSortOptionAtPosition(width, height, x, y);
    if (sortOption) {
      if (this.sortBy === sortOption) {
        this.sortDirection = this.sortDirection === 'asc' ? 'desc' : 'asc';
      } else {
        this.sortBy = sortOption;
        this.sortDirection = sortOption === 'time' ? 'asc' : 'desc';
      }
      return;
    }

    // Check action buttons
    const actionButton = getActionButtonAtPosition(width, height, x, y);
    switch (actionButton) {
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
  }

  private onMouseMove(_e: MouseEvent): void {
    // Hover effects could be implemented here
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
