/**
 * Keyboard and Mouse Handler
 *
 * Handles keyboard and mouse input events.
 *
 * Responsibilities:
 * - Track keyboard key states (pressed, justPressed, justReleased)
 * - Track mouse position, delta, wheel, and button states
 * - Attach/detach DOM event listeners for keyboard/mouse
 *
 * Non-responsibilities:
 * - Does not handle touch input
 * - Does not handle gamepad input
 * - Does not render anything
 *
 * Assumptions:
 * - update() is called once per frame to clear edge states
 * - Canvas element is provided for mouse coordinate calculations
 */

import type { KeyState, MouseState, MouseButton } from './types';

export interface KeyboardMouseState {
  keys: Map<string, KeyState>;
  mouse: MouseState;
}

export class KeyboardMouseHandler {
  private keys: Map<string, KeyState> = new Map();
  private mouse: MouseState;
  private canvas: HTMLCanvasElement;

  private boundHandlers: {
    keyDown: (e: KeyboardEvent) => void;
    keyUp: (e: KeyboardEvent) => void;
    mouseMove: (e: MouseEvent) => void;
    mouseDown: (e: MouseEvent) => void;
    mouseUp: (e: MouseEvent) => void;
    wheel: (e: WheelEvent) => void;
    contextMenu: (e: MouseEvent) => void;
  };

  constructor(canvas: HTMLCanvasElement) {
    this.canvas = canvas;

    this.mouse = {
      x: 0,
      y: 0,
      dx: 0,
      dy: 0,
      wheel: 0,
      buttons: {
        left: { pressed: false, justPressed: false, justReleased: false },
        middle: { pressed: false, justPressed: false, justReleased: false },
        right: { pressed: false, justPressed: false, justReleased: false },
      },
    };

    this.boundHandlers = {
      keyDown: this.handleKeyDown.bind(this),
      keyUp: this.handleKeyUp.bind(this),
      mouseMove: this.handleMouseMove.bind(this),
      mouseDown: this.handleMouseDown.bind(this),
      mouseUp: this.handleMouseUp.bind(this),
      wheel: this.handleWheel.bind(this),
      contextMenu: (e) => e.preventDefault(),
    };

    this.attachListeners();
  }

  // Query methods
  isKeyDown(code: string): boolean {
    return this.keys.get(code)?.pressed ?? false;
  }

  wasKeyPressed(code: string): boolean {
    return this.keys.get(code)?.justPressed ?? false;
  }

  wasKeyReleased(code: string): boolean {
    return this.keys.get(code)?.justReleased ?? false;
  }

  isMouseButtonDown(button: MouseButton): boolean {
    return this.mouse.buttons[button].pressed;
  }

  wasMouseButtonPressed(button: MouseButton): boolean {
    return this.mouse.buttons[button].justPressed;
  }

  wasMouseButtonReleased(button: MouseButton): boolean {
    return this.mouse.buttons[button].justReleased;
  }

  getMousePos(): { x: number; y: number } {
    return { x: this.mouse.x, y: this.mouse.y };
  }

  getMouseDelta(): { x: number; y: number } {
    return { x: this.mouse.dx, y: this.mouse.dy };
  }

  getMouseWheel(): number {
    return this.mouse.wheel;
  }

  // State management
  update(): void {
    for (const state of this.keys.values()) {
      state.justPressed = false;
      state.justReleased = false;
    }

    for (const button of Object.values(this.mouse.buttons)) {
      button.justPressed = false;
      button.justReleased = false;
    }

    this.mouse.dx = 0;
    this.mouse.dy = 0;
    this.mouse.wheel = 0;
  }

  flush(): void {
    this.keys.clear();
    this.resetMouseState();
  }

  getState(): KeyboardMouseState {
    return {
      keys: new Map(this.keys),
      mouse: { ...this.mouse },
    };
  }

  destroy(): void {
    this.detachListeners();
  }

  // Event handlers
  private attachListeners(): void {
    window.addEventListener('keydown', this.boundHandlers.keyDown);
    window.addEventListener('keyup', this.boundHandlers.keyUp);
    this.canvas.addEventListener('mousemove', this.boundHandlers.mouseMove);
    this.canvas.addEventListener('mousedown', this.boundHandlers.mouseDown);
    window.addEventListener('mouseup', this.boundHandlers.mouseUp);
    this.canvas.addEventListener('wheel', this.boundHandlers.wheel, { passive: true });
    this.canvas.addEventListener('contextmenu', this.boundHandlers.contextMenu);
  }

  private detachListeners(): void {
    window.removeEventListener('keydown', this.boundHandlers.keyDown);
    window.removeEventListener('keyup', this.boundHandlers.keyUp);
    this.canvas.removeEventListener('mousemove', this.boundHandlers.mouseMove);
    this.canvas.removeEventListener('mousedown', this.boundHandlers.mouseDown);
    window.removeEventListener('mouseup', this.boundHandlers.mouseUp);
    this.canvas.removeEventListener('wheel', this.boundHandlers.wheel);
    this.canvas.removeEventListener('contextmenu', this.boundHandlers.contextMenu);
  }

  private handleKeyDown(e: KeyboardEvent): void {
    let state = this.keys.get(e.code);
    if (!state) {
      state = { pressed: false, justPressed: false, justReleased: false };
      this.keys.set(e.code, state);
    }

    if (!state.pressed) {
      state.pressed = true;
      state.justPressed = true;
    }
  }

  private handleKeyUp(e: KeyboardEvent): void {
    const state = this.keys.get(e.code);
    if (state) {
      state.pressed = false;
      state.justReleased = true;
    }
  }

  private handleMouseMove(e: MouseEvent): void {
    const rect = this.canvas.getBoundingClientRect();
    const newX = e.clientX - rect.left;
    const newY = e.clientY - rect.top;

    this.mouse.dx = newX - this.mouse.x;
    this.mouse.dy = newY - this.mouse.y;
    this.mouse.x = newX;
    this.mouse.y = newY;
  }

  private handleMouseDown(e: MouseEvent): void {
    const button = this.getMouseButtonName(e.button);
    if (button) {
      this.mouse.buttons[button].pressed = true;
      this.mouse.buttons[button].justPressed = true;
    }
  }

  private handleMouseUp(e: MouseEvent): void {
    const button = this.getMouseButtonName(e.button);
    if (button) {
      this.mouse.buttons[button].pressed = false;
      this.mouse.buttons[button].justReleased = true;
    }
  }

  private handleWheel(e: WheelEvent): void {
    this.mouse.wheel = Math.sign(e.deltaY);
  }

  private getMouseButtonName(button: number): MouseButton | null {
    switch (button) {
      case 0:
        return 'left';
      case 1:
        return 'middle';
      case 2:
        return 'right';
      default:
        return null;
    }
  }

  private resetMouseState(): void {
    this.mouse.x = 0;
    this.mouse.y = 0;
    this.mouse.dx = 0;
    this.mouse.dy = 0;
    this.mouse.wheel = 0;

    for (const button of Object.values(this.mouse.buttons)) {
      button.pressed = false;
      button.justPressed = false;
      button.justReleased = false;
    }
  }
}
