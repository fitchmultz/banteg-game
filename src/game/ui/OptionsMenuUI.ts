/**
 * Options Menu UI
 *
 * Displays settings for audio, display, and controls.
 * Accessible from both main menu and pause menu.
 */

import type { GameConfig, KeyBindings } from '../../types';
import { VALID_RESOLUTIONS, DEFAULT_GAME_CONFIG } from '../settings/SettingsManager';

export type OptionsSection = 'AUDIO' | 'DISPLAY' | 'CONTROLS';
export type OptionsMenuContext = 'menu' | 'pause';

export interface OptionsMenuUIOptions {
  canvas: HTMLCanvasElement;
  onChangeConfig: (config: GameConfig) => void;
  onRequestBack: (context: OptionsMenuContext) => void;
  getInitialConfig: () => GameConfig;
  getIsFullscreen?: () => boolean;
}

interface OptionItem {
  id: string;
  label: string;
  type: 'slider' | 'toggle' | 'cycle' | 'binding' | 'button';
  section: OptionsSection;
  value?: number | boolean | string;
  min?: number;
  max?: number;
  options?: string[];
}

export class OptionsMenuUI {
  private canvas: HTMLCanvasElement;
  private ctx: CanvasRenderingContext2D;
  private options: OptionsMenuUIOptions;

  // UI State
  private isVisible = false;
  private currentConfig: GameConfig;
  private context: OptionsMenuContext = 'menu';
  private selectedIndex = 0;
  private currentSection: OptionsSection = 'AUDIO';
  private rebindingAction: keyof KeyBindings | null = null;
  private animationProgress = 0;

  // Menu items
  private items: OptionItem[] = [];

  // Input handling
  private keyHandler: (e: KeyboardEvent) => void;
  private clickHandler: (e: MouseEvent) => void;
  private mouseMoveHandler: (e: MouseEvent) => void;

  // Layout constants
  private readonly PANEL_WIDTH = 500;
  private readonly PANEL_HEIGHT = 480;
  private readonly ITEM_HEIGHT = 40;
  private readonly ITEM_SPACING = 8;

  constructor(options: OptionsMenuUIOptions) {
    this.canvas = options.canvas;
    const ctx = this.canvas.getContext('2d');
    if (!ctx) {
      throw new Error('Could not get canvas context');
    }
    this.ctx = ctx;
    this.options = options;
    this.currentConfig = options.getInitialConfig();

    // Bind input handlers
    this.keyHandler = this.handleKeyDown.bind(this);
    this.clickHandler = this.handleClick.bind(this);
    this.mouseMoveHandler = this.handleMouseMove.bind(this);

    this.attachEventListeners();
    this.buildItems();
  }

  private buildItems(): void {
    this.items = [
      // AUDIO section
      { id: 'section_audio', label: 'AUDIO', type: 'button', section: 'AUDIO' },
      {
        id: 'sfxVolume',
        label: 'SFX Volume',
        type: 'slider',
        section: 'AUDIO',
        value: Math.round(this.currentConfig.sfxVolume * 100),
        min: 0,
        max: 100,
      },
      {
        id: 'musicVolume',
        label: 'Music Volume',
        type: 'slider',
        section: 'AUDIO',
        value: Math.round(this.currentConfig.musicVolume * 100),
        min: 0,
        max: 100,
      },

      // DISPLAY section
      { id: 'section_display', label: 'DISPLAY', type: 'button', section: 'DISPLAY' },
      {
        id: 'resolution',
        label: 'Resolution',
        type: 'cycle',
        section: 'DISPLAY',
        value: this.getResolutionIndex(),
        options: VALID_RESOLUTIONS.map((r) => `${r.width}x${r.height}`),
      },
      {
        id: 'fullscreen',
        label: 'Fullscreen',
        type: 'toggle',
        section: 'DISPLAY',
        value: this.currentConfig.fullscreen,
      },

      // CONTROLS section
      { id: 'section_controls', label: 'CONTROLS', type: 'button', section: 'CONTROLS' },
      {
        id: 'bind_moveUp',
        label: 'Move Up',
        type: 'binding',
        section: 'CONTROLS',
        value: this.currentConfig.controls.moveUp,
      },
      {
        id: 'bind_moveDown',
        label: 'Move Down',
        type: 'binding',
        section: 'CONTROLS',
        value: this.currentConfig.controls.moveDown,
      },
      {
        id: 'bind_moveLeft',
        label: 'Move Left',
        type: 'binding',
        section: 'CONTROLS',
        value: this.currentConfig.controls.moveLeft,
      },
      {
        id: 'bind_moveRight',
        label: 'Move Right',
        type: 'binding',
        section: 'CONTROLS',
        value: this.currentConfig.controls.moveRight,
      },
      {
        id: 'bind_reload',
        label: 'Reload',
        type: 'binding',
        section: 'CONTROLS',
        value: this.currentConfig.controls.reload,
      },
      {
        id: 'bind_swapWeapon',
        label: 'Swap Weapon',
        type: 'binding',
        section: 'CONTROLS',
        value: this.currentConfig.controls.swapWeapon,
      },
      {
        id: 'bind_pause',
        label: 'Pause',
        type: 'binding',
        section: 'CONTROLS',
        value: this.currentConfig.controls.pause,
      },
      {
        id: 'bind_fire',
        label: 'Fire',
        type: 'binding',
        section: 'CONTROLS',
        value: this.currentConfig.controls.fire,
      },

      // Action buttons
      { id: 'reset', label: 'Reset to Defaults', type: 'button', section: 'AUDIO' },
      { id: 'back', label: 'Back', type: 'button', section: 'AUDIO' },
    ];
  }

  private getResolutionIndex(): number {
    const index = VALID_RESOLUTIONS.findIndex(
      (r) =>
        r.width === this.currentConfig.resolution.width &&
        r.height === this.currentConfig.resolution.height
    );
    return index >= 0 ? index : 1; // Default to 1024x768 (index 1)
  }

  /**
   * Show the options menu
   */
  show(context: OptionsMenuContext = 'menu'): void {
    this.context = context;
    this.isVisible = true;
    this.selectedIndex = 0;
    this.currentSection = 'AUDIO';
    this.rebindingAction = null;
    this.animationProgress = 0;
    this.currentConfig = this.options.getInitialConfig();
    this.buildItems();
    this.animateIn();
  }

  /**
   * Hide the options menu
   */
  hide(): void {
    this.isVisible = false;
    this.rebindingAction = null;
  }

  /**
   * Check if UI is visible
   */
  isShown(): boolean {
    return this.isVisible;
  }

  /**
   * Get current configuration
   */
  getConfig(): GameConfig {
    return { ...this.currentConfig };
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

    // Draw panel
    this.drawPanel(width, height);

    // Draw title
    this.drawTitle(width);

    // Draw section tabs
    this.drawSectionTabs(width);

    // Draw items for current section
    this.drawItems(width);

    // Draw rebinding overlay if active
    if (this.rebindingAction) {
      this.drawRebindingOverlay(width, height);
    }

    // Draw instructions
    this.drawInstructions(width, height);
  }

  private drawPanel(width: number, height: number): void {
    const panelX = (width - this.PANEL_WIDTH) / 2;
    const panelY = (height - this.PANEL_HEIGHT) / 2;

    // Animation offset
    const animOffset = (1 - this.animationProgress) * 30;
    const y = panelY + animOffset;

    // Panel shadow
    this.ctx.fillStyle = 'rgba(0, 0, 0, 0.5)';
    this.roundRect(panelX + 6, y + 6, this.PANEL_WIDTH, this.PANEL_HEIGHT, 12);
    this.ctx.fill();

    // Panel background
    const gradient = this.ctx.createLinearGradient(panelX, y, panelX, y + this.PANEL_HEIGHT);
    gradient.addColorStop(0, '#1a1a2e');
    gradient.addColorStop(1, '#0f0f1a');

    this.ctx.fillStyle = gradient;
    this.roundRect(panelX, y, this.PANEL_WIDTH, this.PANEL_HEIGHT, 12);
    this.ctx.fill();

    // Panel border
    this.ctx.strokeStyle = '#333355';
    this.ctx.lineWidth = 2;
    this.roundRect(panelX, y, this.PANEL_WIDTH, this.PANEL_HEIGHT, 12);
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
    this.ctx.fillText('OPTIONS', width / 2, titleY);

    this.ctx.shadowBlur = 0;

    // Underline
    this.ctx.strokeStyle = '#8B0000';
    this.ctx.lineWidth = 2;
    this.ctx.beginPath();
    this.ctx.moveTo(width / 2 - 60, titleY + 20);
    this.ctx.lineTo(width / 2 + 60, titleY + 20);
    this.ctx.stroke();
  }

  private drawSectionTabs(width: number): void {
    const sections: OptionsSection[] = ['AUDIO', 'DISPLAY', 'CONTROLS'];
    const tabWidth = 120;
    const tabHeight = 36;
    const startX = width / 2 - (sections.length * tabWidth) / 2;
    const tabY = this.canvas.height / 2 - this.PANEL_HEIGHT / 2 + 80;

    for (let i = 0; i < sections.length; i++) {
      const section = sections[i];
      if (!section) continue;

      const x = startX + i * tabWidth;
      const isActive = this.currentSection === section;

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
      this.ctx.fillText(section, x + tabWidth / 2, tabY + tabHeight / 2);
    }
  }

  private drawItems(width: number): void {
    const sectionItems = this.items.filter((item) => item.section === this.currentSection);
    const panelX = (width - this.PANEL_WIDTH) / 2;
    const startY = this.canvas.height / 2 - this.PANEL_HEIGHT / 2 + 140;

    for (let i = 0; i < sectionItems.length; i++) {
      const item = sectionItems[i];
      if (!item) continue;

      const y = startY + i * (this.ITEM_HEIGHT + this.ITEM_SPACING);
      const isSelected = this.getSelectedItem()?.id === item.id;

      this.drawItem(item, panelX + 40, y, this.PANEL_WIDTH - 80, isSelected);
    }
  }

  private drawItem(
    item: OptionItem,
    x: number,
    y: number,
    width: number,
    isSelected: boolean
  ): void {
    // Label
    this.ctx.font = isSelected ? 'bold 16px Arial' : '16px Arial';
    this.ctx.textAlign = 'left';
    this.ctx.textBaseline = 'middle';
    this.ctx.fillStyle = isSelected ? '#FFFFFF' : '#CCCCCC';
    this.ctx.fillText(item.label, x, y + this.ITEM_HEIGHT / 2);

    // Value display
    const valueX = x + width - 100;

    switch (item.type) {
      case 'slider': {
        // Slider background
        this.ctx.fillStyle = '#333344';
        this.ctx.fillRect(valueX, y + 10, 100, 20);

        // Slider fill
        const value = (item.value as number) ?? 0;
        const max = item.max ?? 100;
        const fillWidth = (value / max) * 100;
        this.ctx.fillStyle = isSelected ? '#FF4444' : '#666677';
        this.ctx.fillRect(valueX, y + 10, fillWidth, 20);

        // Value text
        this.ctx.font = '12px Arial';
        this.ctx.textAlign = 'center';
        this.ctx.fillStyle = '#FFFFFF';
        this.ctx.fillText(`${value}%`, valueX + 50, y + this.ITEM_HEIGHT / 2);
        break;
      }

      case 'toggle': {
        const toggleOn = item.value as boolean;
        this.ctx.fillStyle = toggleOn ? '#44AA44' : '#AA4444';
        this.roundRect(valueX + 30, y + 8, 50, 24, 12);
        this.ctx.fill();

        this.ctx.font = '12px Arial';
        this.ctx.textAlign = 'center';
        this.ctx.fillStyle = '#FFFFFF';
        this.ctx.fillText(toggleOn ? 'ON' : 'OFF', valueX + 55, y + this.ITEM_HEIGHT / 2);
        break;
      }

      case 'cycle': {
        const options = item.options ?? [];
        const currentIndex = (item.value as number) ?? 0;
        const currentOption = options[currentIndex] ?? '?';

        this.ctx.font = isSelected ? 'bold 14px Arial' : '14px Arial';
        this.ctx.textAlign = 'center';
        this.ctx.fillStyle = isSelected ? '#FFD700' : '#AAAAAA';
        this.ctx.fillText(currentOption, valueX + 50, y + this.ITEM_HEIGHT / 2);

        // Arrows
        if (isSelected) {
          this.ctx.fillStyle = '#FFD700';
          this.ctx.fillText('<', valueX + 20, y + this.ITEM_HEIGHT / 2);
          this.ctx.fillText('>', valueX + 80, y + this.ITEM_HEIGHT / 2);
        }
        break;
      }

      case 'binding': {
        const keyCode = (item.value as string) ?? '';
        const displayKey = this.formatKeyCode(keyCode);

        // Binding box
        this.ctx.fillStyle = isSelected ? '#660000' : '#2a2a3e';
        this.roundRect(valueX + 10, y + 5, 80, 30, 4);
        this.ctx.fill();

        this.ctx.strokeStyle = isSelected ? '#FF4444' : '#444466';
        this.ctx.lineWidth = isSelected ? 2 : 1;
        this.ctx.stroke();

        this.ctx.font = isSelected ? 'bold 14px Arial' : '14px Arial';
        this.ctx.textAlign = 'center';
        this.ctx.fillStyle = '#FFFFFF';
        this.ctx.fillText(displayKey, valueX + 50, y + this.ITEM_HEIGHT / 2);
        break;
      }

      case 'button': {
        // Button background
        const gradient = this.ctx.createLinearGradient(x, y, x, y + this.ITEM_HEIGHT);
        if (isSelected) {
          gradient.addColorStop(0, '#660000');
          gradient.addColorStop(1, '#330000');
        } else {
          gradient.addColorStop(0, '#3a3a4e');
          gradient.addColorStop(1, '#2a2a3e');
        }

        this.ctx.fillStyle = gradient;
        this.roundRect(x + width / 4, y + 4, width / 2, this.ITEM_HEIGHT - 8, 6);
        this.ctx.fill();

        this.ctx.strokeStyle = isSelected ? '#FF4444' : '#444466';
        this.ctx.lineWidth = isSelected ? 2 : 1;
        this.roundRect(x + width / 4, y + 4, width / 2, this.ITEM_HEIGHT - 8, 6);
        this.ctx.stroke();

        this.ctx.font = isSelected ? 'bold 14px Arial' : '14px Arial';
        this.ctx.textAlign = 'center';
        this.ctx.fillStyle = '#FFFFFF';
        this.ctx.fillText(item.label, x + width / 2, y + this.ITEM_HEIGHT / 2);
        break;
      }
    }

    // Selection indicator
    if (isSelected) {
      this.ctx.strokeStyle = '#FF4444';
      this.ctx.lineWidth = 2;
      this.ctx.setLineDash([5, 3]);
      this.roundRect(x - 5, y - 2, width + 10, this.ITEM_HEIGHT + 4, 4);
      this.ctx.stroke();
      this.ctx.setLineDash([]);
    }
  }

  private drawRebindingOverlay(width: number, height: number): void {
    // Darken background
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

    this.ctx.strokeStyle = '#FF4444';
    this.ctx.lineWidth = 3;
    this.roundRect(dialogX, dialogY, dialogWidth, dialogHeight, 12);
    this.ctx.stroke();

    // Dialog text
    this.ctx.font = 'bold 24px Arial';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'middle';
    this.ctx.fillStyle = '#FFFFFF';
    this.ctx.fillText('Press any key...', width / 2, dialogY + 60);

    const actionName = this.rebindingAction ? this.formatActionName(this.rebindingAction) : '';
    this.ctx.font = '16px Arial';
    this.ctx.fillStyle = '#AAAAAA';
    this.ctx.fillText(`Binding: ${actionName}`, width / 2, dialogY + 100);

    this.ctx.font = '14px Arial';
    this.ctx.fillStyle = '#888899';
    this.ctx.fillText('Press ESCAPE to cancel', width / 2, dialogY + 140);
  }

  private drawInstructions(width: number, height: number): void {
    if (this.rebindingAction) return;

    this.ctx.font = '14px Arial';
    this.ctx.textAlign = 'center';
    this.ctx.textBaseline = 'bottom';
    this.ctx.fillStyle = 'rgba(255, 255, 255, 0.5)';

    let instructions = 'Arrow Keys: Navigate | Enter: Select/Change';
    if (this.currentSection === 'CONTROLS') {
      instructions += ' | Enter: Rebind Key';
    }
    instructions += ' | ESC: Back';

    this.ctx.fillText(instructions, width / 2, height - 50);
  }

  private handleKeyDown(e: KeyboardEvent): void {
    if (!this.isVisible) return;

    // Handle rebinding mode
    if (this.rebindingAction) {
      if (e.code === 'Escape') {
        this.rebindingAction = null;
      } else {
        this.applyKeyBinding(this.rebindingAction, e.code);
        this.rebindingAction = null;
      }
      return;
    }

    const sectionItems = this.items.filter((item) => item.section === this.currentSection);
    const currentItemIndex = sectionItems.findIndex(
      (item) => item.id === this.getSelectedItem()?.id
    );

    switch (e.key) {
      case 'ArrowUp': {
        const newIndex = Math.max(0, currentItemIndex - 1);
        this.selectedIndex = this.items.findIndex((item) => item.id === sectionItems[newIndex]?.id);
        break;
      }

      case 'ArrowDown': {
        const newIndex = Math.min(sectionItems.length - 1, currentItemIndex + 1);
        this.selectedIndex = this.items.findIndex((item) => item.id === sectionItems[newIndex]?.id);
        break;
      }

      case 'ArrowLeft': {
        const item = this.getSelectedItem();
        if (item?.type === 'slider') {
          this.adjustSlider(item, -5);
        } else if (item?.type === 'cycle') {
          this.cycleOption(item, -1);
        }
        break;
      }

      case 'ArrowRight': {
        const item = this.getSelectedItem();
        if (item?.type === 'slider') {
          this.adjustSlider(item, 5);
        } else if (item?.type === 'cycle') {
          this.cycleOption(item, 1);
        }
        break;
      }

      case 'Enter':
      case ' ': {
        const item = this.getSelectedItem();
        if (item) {
          this.activateItem(item);
        }
        break;
      }

      case 'Escape':
        this.options.onRequestBack(this.context);
        break;
    }

    // Tab navigation
    if (e.key === 'Tab') {
      e.preventDefault();
      const sections: OptionsSection[] = ['AUDIO', 'DISPLAY', 'CONTROLS'];
      const currentSectionIndex = sections.indexOf(this.currentSection);
      const nextIndex = e.shiftKey
        ? (currentSectionIndex - 1 + sections.length) % sections.length
        : (currentSectionIndex + 1) % sections.length;
      this.currentSection = sections[nextIndex] ?? 'AUDIO';
      this.selectedIndex = this.items.findIndex((item) => item.section === this.currentSection);
    }
  }

  private handleClick(e: MouseEvent): void {
    if (!this.isVisible || this.rebindingAction) return;

    const rect = this.canvas.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    // Check section tabs
    const sections: OptionsSection[] = ['AUDIO', 'DISPLAY', 'CONTROLS'];
    const tabWidth = 120;
    const tabHeight = 36;
    const startX = this.canvas.width / 2 - (sections.length * tabWidth) / 2;
    const tabY = this.canvas.height / 2 - this.PANEL_HEIGHT / 2 + 80;

    for (let i = 0; i < sections.length; i++) {
      const sectionX = startX + i * tabWidth;
      if (x >= sectionX && x <= sectionX + tabWidth && y >= tabY && y <= tabY + tabHeight) {
        this.currentSection = sections[i] ?? 'AUDIO';
        this.selectedIndex = this.items.findIndex((item) => item.section === this.currentSection);
        return;
      }
    }

    // Check items
    const panelX = (this.canvas.width - this.PANEL_WIDTH) / 2;
    const startY = this.canvas.height / 2 - this.PANEL_HEIGHT / 2 + 140;
    const sectionItems = this.items.filter((item) => item.section === this.currentSection);

    for (let i = 0; i < sectionItems.length; i++) {
      const item = sectionItems[i];
      if (!item) continue;

      const itemY = startY + i * (this.ITEM_HEIGHT + this.ITEM_SPACING);
      const itemX = panelX + 40;
      const itemWidth = this.PANEL_WIDTH - 80;

      if (x >= itemX && x <= itemX + itemWidth && y >= itemY && y <= itemY + this.ITEM_HEIGHT) {
        this.selectedIndex = this.items.findIndex((it) => it.id === item.id);
        this.activateItem(item);
        return;
      }
    }
  }

  private handleMouseMove(e: MouseEvent): void {
    if (!this.isVisible || this.rebindingAction) return;

    const rect = this.canvas.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    // Check items for hover effect
    const panelX = (this.canvas.width - this.PANEL_WIDTH) / 2;
    const startY = this.canvas.height / 2 - this.PANEL_HEIGHT / 2 + 140;
    const sectionItems = this.items.filter((item) => item.section === this.currentSection);

    for (let i = 0; i < sectionItems.length; i++) {
      const item = sectionItems[i];
      if (!item) continue;

      const itemY = startY + i * (this.ITEM_HEIGHT + this.ITEM_SPACING);
      const itemX = panelX + 40;
      const itemWidth = this.PANEL_WIDTH - 80;

      if (x >= itemX && x <= itemX + itemWidth && y >= itemY && y <= itemY + this.ITEM_HEIGHT) {
        this.selectedIndex = this.items.findIndex((it) => it.id === item.id);
        return;
      }
    }
  }

  private getSelectedItem(): OptionItem | undefined {
    return this.items[this.selectedIndex];
  }

  private adjustSlider(item: OptionItem, delta: number): void {
    const currentValue = (item.value as number) ?? 0;
    const min = item.min ?? 0;
    const max = item.max ?? 100;
    const newValue = Math.max(min, Math.min(max, currentValue + delta));
    item.value = newValue;

    // Update config
    if (item.id === 'sfxVolume') {
      this.currentConfig.sfxVolume = newValue / 100;
    } else if (item.id === 'musicVolume') {
      this.currentConfig.musicVolume = newValue / 100;
    }

    this.notifyConfigChange();
  }

  private cycleOption(item: OptionItem, direction: number): void {
    const options = item.options ?? [];
    const currentIndex = (item.value as number) ?? 0;
    const newIndex = (currentIndex + direction + options.length) % options.length;
    item.value = newIndex;

    // Update config
    if (item.id === 'resolution') {
      const resolution = VALID_RESOLUTIONS[newIndex];
      if (resolution) {
        this.currentConfig.resolution = { ...resolution };
      }
    }

    this.notifyConfigChange();
  }

  private toggleOption(item: OptionItem): void {
    const currentValue = item.value as boolean;
    item.value = !currentValue;

    // Update config
    if (item.id === 'fullscreen') {
      this.currentConfig.fullscreen = !currentValue;
      this.toggleFullscreen();
    }

    this.notifyConfigChange();
  }

  private toggleFullscreen(): void {
    if (this.currentConfig.fullscreen) {
      document.documentElement.requestFullscreen().catch((err) => {
        console.warn('Failed to enter fullscreen:', err);
        this.currentConfig.fullscreen = false;
        this.buildItems();
      });
    } else {
      if (document.fullscreenElement) {
        document.exitFullscreen().catch((err) => {
          console.warn('Failed to exit fullscreen:', err);
        });
      }
    }
  }

  private activateItem(item: OptionItem): void {
    switch (item.type) {
      case 'slider':
        // Sliders are adjusted with left/right
        break;

      case 'toggle':
        this.toggleOption(item);
        break;

      case 'cycle':
        this.cycleOption(item, 1);
        break;

      case 'binding': {
        const action = item.id.replace('bind_', '') as keyof KeyBindings;
        this.rebindingAction = action;
        break;
      }

      case 'button':
        if (item.id === 'back') {
          this.options.onRequestBack(this.context);
        } else if (item.id === 'reset') {
          this.resetToDefaults();
        }
        break;
    }
  }

  private applyKeyBinding(action: keyof KeyBindings, code: string): void {
    this.currentConfig.controls[action] = code;

    // Update item value
    const item = this.items.find((it) => it.id === `bind_${action}`);
    if (item) {
      item.value = code;
    }

    this.notifyConfigChange();
  }

  private resetToDefaults(): void {
    // Reset to default configuration
    this.currentConfig = { ...DEFAULT_GAME_CONFIG };
    this.buildItems();
    this.notifyConfigChange();

    // Apply fullscreen change if needed
    if (document.fullscreenElement && !this.currentConfig.fullscreen) {
      document.exitFullscreen().catch(console.error);
    }
  }

  private notifyConfigChange(): void {
    this.options.onChangeConfig({ ...this.currentConfig });
  }

  private formatKeyCode(code: string): string {
    if (code.startsWith('Key')) {
      return code.slice(3);
    }
    if (code === 'Escape') return 'ESC';
    if (code === 'Space') return 'SPC';
    if (code.startsWith('Arrow')) {
      return code.slice(5).toUpperCase();
    }
    if (code.startsWith('Digit')) {
      return code.slice(5);
    }
    if (code.startsWith('Numpad')) {
      return `N${code.slice(6)}`;
    }
    return code;
  }

  private formatActionName(action: keyof KeyBindings): string {
    const names: Record<keyof KeyBindings, string> = {
      moveUp: 'Move Up',
      moveDown: 'Move Down',
      moveLeft: 'Move Left',
      moveRight: 'Move Right',
      fire: 'Fire',
      reload: 'Reload',
      swapWeapon: 'Swap Weapon',
      pause: 'Pause',
    };
    return names[action] ?? action;
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

  private attachEventListeners(): void {
    window.addEventListener('keydown', this.keyHandler);
    this.canvas.addEventListener('click', this.clickHandler);
    this.canvas.addEventListener('mousemove', this.mouseMoveHandler);

    // Listen for fullscreen changes
    document.addEventListener('fullscreenchange', this.handleFullscreenChange.bind(this));
  }

  private detachEventListeners(): void {
    window.removeEventListener('keydown', this.keyHandler);
    this.canvas.removeEventListener('click', this.clickHandler);
    this.canvas.removeEventListener('mousemove', this.mouseMoveHandler);
    document.removeEventListener('fullscreenchange', this.handleFullscreenChange.bind(this));
  }

  private handleFullscreenChange(): void {
    const isFullscreen = !!document.fullscreenElement;
    if (this.currentConfig.fullscreen !== isFullscreen) {
      this.currentConfig.fullscreen = isFullscreen;
      this.buildItems();
    }
  }

  /**
   * Clean up event listeners
   */
  destroy(): void {
    this.detachEventListeners();
  }
}
