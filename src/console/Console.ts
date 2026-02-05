/**
 * Console UI System
 *
 * Quake-style developer console overlay.
 * Handles input, rendering, and command execution.
 *
 * Responsibilities:
 * - Render console overlay with scrollable output
 * - Handle keyboard input for command entry
 * - Maintain command history and autocomplete
 * - Execute commands and display output
 *
 * Non-responsibilities:
 * - Does not define CVARs (see Cvar.ts)
 * - Does not define commands (see CommandRegistry.ts)
 * - Does not handle game logic
 *
 * Assumptions:
 * - Renderer provides Canvas 2D context
 * - InputManager provides keyboard state
 * - Console is rendered in screen space (not world space)
 */

import type { InputManager } from '../engine/input/InputManager';
import type { Renderer } from '../engine/Renderer';
import { commandRegistry } from './CommandRegistry';
import { cvarRegistry } from './Cvar';

/**
 * Console message types for color coding
 */
export enum ConsoleMessageType {
  INFO = 'info',
  WARNING = 'warning',
  ERROR = 'error',
  COMMAND = 'command',
  OUTPUT = 'output',
}

/**
 * Console message interface
 */
export interface ConsoleMessage {
  text: string;
  type: ConsoleMessageType;
  timestamp: number;
}

/**
 * Console options for initialization
 */
export interface ConsoleOptions {
  renderer: Renderer;
  inputManager: InputManager;
  maxHistory?: number; // Max command history (default: 50)
  maxOutputLines?: number; // Max output lines (default: 100)
}

/**
 * Quake-style developer console
 */
export class Console {
  private renderer: Renderer;
  private isVisible = false;

  // Input state
  private currentInput = '';
  private cursorPosition = 0;

  // History
  private commandHistory: string[] = [];
  private historyIndex = -1;
  private maxHistory: number;

  // Output
  private output: ConsoleMessage[] = [];
  private maxOutputLines: number;
  private scrollOffset = 0;

  // Autocomplete
  private autocompleteMatches: string[] = [];
  private autocompleteIndex = -1;

  // Visual constants
  private readonly CONSOLE_HEIGHT_RATIO = 0.4; // 40% of screen height
  private readonly FONT_SIZE = 14;
  private readonly FONT_FAMILY = 'monospace';
  private readonly LINE_HEIGHT = 18;
  private readonly PADDING = 10;
  private readonly BACKGROUND_COLOR = 'rgba(0, 0, 0, 0.85)';
  private readonly BORDER_COLOR = '#444444';
  private readonly INPUT_BACKGROUND = 'rgba(30, 30, 30, 0.9)';

  // Colors for message types
  private readonly TYPE_COLORS: Record<ConsoleMessageType, string> = {
    [ConsoleMessageType.INFO]: '#AAAAAA',
    [ConsoleMessageType.WARNING]: '#FFAA00',
    [ConsoleMessageType.ERROR]: '#FF4444',
    [ConsoleMessageType.COMMAND]: '#88AAFF',
    [ConsoleMessageType.OUTPUT]: '#FFFFFF',
  };

  constructor(options: ConsoleOptions) {
    this.renderer = options.renderer;
    this.maxHistory = options.maxHistory ?? 50;
    this.maxOutputLines = options.maxOutputLines ?? 100;

    // Print welcome message
    this.print('Console initialized. Type "help" for available commands.', ConsoleMessageType.INFO);
  }

  /**
   * Check if console is currently open
   */
  isOpen(): boolean {
    return this.isVisible;
  }

  /**
   * Toggle console visibility
   */
  toggle(): void {
    if (this.isVisible) {
      this.hide();
    } else {
      this.show();
    }
  }

  /**
   * Show the console
   */
  show(): void {
    this.isVisible = true;
    this.scrollOffset = 0;
    this.autocompleteMatches = [];
    this.autocompleteIndex = -1;
  }

  /**
   * Hide the console
   */
  hide(): void {
    this.isVisible = false;
    this.currentInput = '';
    this.cursorPosition = 0;
    this.historyIndex = -1;
    this.autocompleteMatches = [];
    this.autocompleteIndex = -1;
  }

  /**
   * Handle keydown events
   * @returns true if the key was consumed
   */
  handleKeyDown(e: KeyboardEvent): boolean {
    if (!this.isVisible) {
      return false;
    }

    switch (e.code) {
      case 'Escape':
        this.hide();
        return true;

      case 'Enter':
        this.executeCurrentCommand();
        return true;

      case 'Backspace':
        this.handleBackspace();
        return true;

      case 'Delete':
        this.handleDelete();
        return true;

      case 'ArrowLeft':
        this.moveCursor(-1);
        return true;

      case 'ArrowRight':
        this.moveCursor(1);
        return true;

      case 'ArrowUp':
        if (e.shiftKey) {
          this.scrollOutput(1);
        } else {
          this.navigateHistory(-1);
        }
        return true;

      case 'ArrowDown':
        if (e.shiftKey) {
          this.scrollOutput(-1);
        } else {
          this.navigateHistory(1);
        }
        return true;

      case 'Home':
        this.cursorPosition = 0;
        return true;

      case 'End':
        this.cursorPosition = this.currentInput.length;
        return true;

      case 'Tab':
        this.handleAutocomplete(e.shiftKey);
        return true;

      case 'PageUp':
        this.scrollOutput(5);
        return true;

      case 'PageDown':
        this.scrollOutput(-5);
        return true;

      default:
        // Let character input handle printable keys
        return false;
    }
  }

  /**
   * Handle keyup events
   * @returns true if the key was consumed
   */
  handleKeyUp(_e: KeyboardEvent): boolean {
    return this.isVisible;
  }

  /**
   * Handle character input
   * @returns true if the input was consumed
   */
  handleInput(key: string): boolean {
    if (!this.isVisible) {
      return false;
    }

    // Ignore control characters
    if (key.length === 1 && key.charCodeAt(0) >= 32) {
      this.insertCharacter(key);
      return true;
    }

    return false;
  }

  /**
   * Execute a command directly
   */
  executeCommand(line: string): void {
    if (!line.trim()) {
      return;
    }

    // Add to output as command
    this.print(`> ${line}`, ConsoleMessageType.COMMAND);

    // Execute and capture output
    const result = commandRegistry.execute(line);

    // Handle special markers
    if (result === '__CLEAR__') {
      this.clear();
      return;
    }

    // Print result if any
    if (result) {
      this.print(result, ConsoleMessageType.OUTPUT);
    }
  }

  /**
   * Print text to console output
   */
  print(text: string, type: ConsoleMessageType = ConsoleMessageType.OUTPUT): void {
    const lines = text.split('\n');
    for (const line of lines) {
      this.output.push({
        text: line,
        type,
        timestamp: Date.now(),
      });
    }

    // Trim output if too long
    while (this.output.length > this.maxOutputLines) {
      this.output.shift();
    }

    // Auto-scroll to bottom
    this.scrollOffset = 0;
  }

  /**
   * Clear console output
   */
  clear(): void {
    this.output = [];
    this.scrollOffset = 0;
  }

  /**
   * Render the console overlay
   */
  render(): void {
    if (!this.isVisible) {
      return;
    }

    const ctx = this.renderer.getContext();
    const canvas = ctx.canvas;
    const width = canvas.width;
    const height = Math.floor(canvas.height * this.CONSOLE_HEIGHT_RATIO);

    // Save context state
    ctx.save();

    // Draw background
    ctx.fillStyle = this.BACKGROUND_COLOR;
    ctx.fillRect(0, 0, width, height);

    // Draw border at bottom
    ctx.strokeStyle = this.BORDER_COLOR;
    ctx.lineWidth = 2;
    ctx.beginPath();
    ctx.moveTo(0, height);
    ctx.lineTo(width, height);
    ctx.stroke();

    // Set up text rendering
    ctx.font = `${this.FONT_SIZE}px ${this.FONT_FAMILY}`;
    ctx.textBaseline = 'top';

    // Calculate visible lines
    const inputHeight = this.LINE_HEIGHT + this.PADDING * 2;
    const outputHeight = height - inputHeight - this.PADDING;
    const maxVisibleLines = Math.floor(outputHeight / this.LINE_HEIGHT);

    // Draw output lines
    const startIndex = Math.max(0, this.output.length - maxVisibleLines - this.scrollOffset);
    const endIndex = Math.min(this.output.length, startIndex + maxVisibleLines);

    for (let i = startIndex; i < endIndex; i++) {
      const message = this.output[i];
      if (message === undefined) continue;
      const lineY = this.PADDING + (i - startIndex) * this.LINE_HEIGHT;

      ctx.fillStyle = this.TYPE_COLORS[message.type];
      ctx.fillText(message.text, this.PADDING, lineY);
    }

    // Draw input background
    const inputY = height - inputHeight;
    ctx.fillStyle = this.INPUT_BACKGROUND;
    ctx.fillRect(0, inputY, width, inputHeight);

    // Draw input prompt
    ctx.fillStyle = '#00FF00';
    ctx.fillText('>', this.PADDING, inputY + this.PADDING);

    // Draw input text
    ctx.fillStyle = '#FFFFFF';
    const inputX = this.PADDING + 20;
    ctx.fillText(this.currentInput, inputX, inputY + this.PADDING);

    // Draw cursor
    const cursorX = inputX + ctx.measureText(this.currentInput.slice(0, this.cursorPosition)).width;
    ctx.fillStyle = '#FFFFFF';
    ctx.fillRect(cursorX, inputY + this.PADDING, 2, this.FONT_SIZE);

    // Draw autocomplete suggestions
    if (this.autocompleteMatches.length > 0) {
      this.renderAutocomplete(ctx, width, inputY);
    }

    // Restore context state
    ctx.restore();
  }

  /**
   * Update console (for animations, etc.)
   */
  update(_dt: number): void {
    // Currently no animations, but reserved for future use
  }

  /**
   * Cleanup resources
   */
  destroy(): void {
    this.hide();
    this.output = [];
    this.commandHistory = [];
  }

  // Private helper methods

  private executeCurrentCommand(): void {
    const command = this.currentInput.trim();
    if (command) {
      // Add to history
      this.commandHistory.push(command);
      if (this.commandHistory.length > this.maxHistory) {
        this.commandHistory.shift();
      }

      // Execute
      this.executeCommand(command);

      // Clear input
      this.currentInput = '';
      this.cursorPosition = 0;
      this.historyIndex = -1;
      this.autocompleteMatches = [];
      this.autocompleteIndex = -1;
    }
  }

  private handleBackspace(): void {
    if (this.cursorPosition > 0) {
      this.currentInput =
        this.currentInput.slice(0, this.cursorPosition - 1) +
        this.currentInput.slice(this.cursorPosition);
      this.cursorPosition--;
      this.autocompleteMatches = [];
      this.autocompleteIndex = -1;
    }
  }

  private handleDelete(): void {
    if (this.cursorPosition < this.currentInput.length) {
      this.currentInput =
        this.currentInput.slice(0, this.cursorPosition) +
        this.currentInput.slice(this.cursorPosition + 1);
      this.autocompleteMatches = [];
      this.autocompleteIndex = -1;
    }
  }

  private moveCursor(delta: number): void {
    this.cursorPosition = Math.max(
      0,
      Math.min(this.currentInput.length, this.cursorPosition + delta)
    );
  }

  private navigateHistory(delta: number): void {
    if (this.commandHistory.length === 0) {
      return;
    }

    const newIndex = this.historyIndex + delta;

    if (newIndex >= this.commandHistory.length) {
      // Beyond end - clear input
      this.historyIndex = this.commandHistory.length;
      this.currentInput = '';
      this.cursorPosition = 0;
    } else if (newIndex < 0) {
      // Before beginning - restore original input (empty)
      this.historyIndex = -1;
      this.currentInput = '';
      this.cursorPosition = 0;
    } else {
      // Valid history entry
      this.historyIndex = newIndex;
      const historyEntry = this.commandHistory[this.commandHistory.length - 1 - this.historyIndex];
      if (historyEntry !== undefined) {
        this.currentInput = historyEntry;
        this.cursorPosition = this.currentInput.length;
      }
    }

    this.autocompleteMatches = [];
    this.autocompleteIndex = -1;
  }

  private scrollOutput(delta: number): void {
    const maxScroll = Math.max(0, this.output.length - 1);
    this.scrollOffset = Math.max(0, Math.min(maxScroll, this.scrollOffset + delta));
  }

  private handleAutocomplete(shiftKey: boolean): void {
    // If no matches yet, find them
    if (this.autocompleteMatches.length === 0) {
      const input = this.currentInput.trim();
      const parts = input.split(' ');

      if (parts.length === 1) {
        // Complete command name
        const prefix = parts[0] ?? '';
        this.autocompleteMatches = commandRegistry.findMatches(prefix);
      } else if (parts.length >= 2 && (parts[0] === 'set' || parts[0] === 'toggle')) {
        // Complete CVAR name
        const cvarPrefix = parts[1] ?? '';
        this.autocompleteMatches = cvarRegistry.listByPrefix(cvarPrefix).map((c) => c.name);
      }

      this.autocompleteIndex = -1;
    }

    if (this.autocompleteMatches.length === 0) {
      return;
    }

    // Cycle through matches
    if (shiftKey) {
      this.autocompleteIndex--;
      if (this.autocompleteIndex < 0) {
        this.autocompleteIndex = this.autocompleteMatches.length - 1;
      }
    } else {
      this.autocompleteIndex++;
      if (this.autocompleteIndex >= this.autocompleteMatches.length) {
        this.autocompleteIndex = 0;
      }
    }

    // Apply completion
    const match = this.autocompleteMatches[this.autocompleteIndex];
    if (match === undefined) return;

    const input = this.currentInput.trim();
    const parts = input.split(' ');

    if (parts.length === 1) {
      this.currentInput = match;
    } else if (parts.length >= 2) {
      parts[1] = match;
      this.currentInput = parts.join(' ');
    }

    this.cursorPosition = this.currentInput.length;
  }

  private insertCharacter(char: string): void {
    this.currentInput =
      this.currentInput.slice(0, this.cursorPosition) +
      char +
      this.currentInput.slice(this.cursorPosition);
    this.cursorPosition++;
    this.autocompleteMatches = [];
    this.autocompleteIndex = -1;
  }

  private renderAutocomplete(ctx: CanvasRenderingContext2D, _width: number, inputY: number): void {
    const suggestionY = inputY - this.autocompleteMatches.length * this.LINE_HEIGHT - this.PADDING;

    ctx.fillStyle = 'rgba(0, 0, 0, 0.9)';
    ctx.fillRect(
      this.PADDING,
      suggestionY,
      300,
      this.autocompleteMatches.length * this.LINE_HEIGHT + this.PADDING
    );

    ctx.strokeStyle = this.BORDER_COLOR;
    ctx.lineWidth = 1;
    ctx.strokeRect(
      this.PADDING,
      suggestionY,
      300,
      this.autocompleteMatches.length * this.LINE_HEIGHT + this.PADDING
    );

    for (let i = 0; i < this.autocompleteMatches.length; i++) {
      const match = this.autocompleteMatches[i];
      if (match === undefined) continue;
      const y = suggestionY + i * this.LINE_HEIGHT + this.PADDING / 2;

      if (i === this.autocompleteIndex) {
        ctx.fillStyle = 'rgba(100, 100, 100, 0.8)';
        ctx.fillRect(this.PADDING + 2, y - 2, 296, this.LINE_HEIGHT);
      }

      ctx.fillStyle = '#CCCCCC';
      ctx.fillText(match, this.PADDING + 5, y);
    }
  }
}
