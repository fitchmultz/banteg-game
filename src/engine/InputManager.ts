/**
 * Input Manager
 *
 * Replacement for grim.dll's DirectInput handling.
 */

import type { InputState, KeyState, MouseState } from '../types';

export const KeyCode = {
  W: 'KeyW',
  A: 'KeyA',
  S: 'KeyS',
  D: 'KeyD',
  ARROW_UP: 'ArrowUp',
  ARROW_DOWN: 'ArrowDown',
  ARROW_LEFT: 'ArrowLeft',
  ARROW_RIGHT: 'ArrowRight',
  SPACE: 'Space',
  ENTER: 'Enter',
  ESCAPE: 'Escape',
  TAB: 'Tab',
  SHIFT_LEFT: 'ShiftLeft',
  SHIFT_RIGHT: 'ShiftRight',
  CTRL_LEFT: 'ControlLeft',
  CTRL_RIGHT: 'ControlRight',
  ALT_LEFT: 'AltLeft',
  ALT_RIGHT: 'AltRight',
  DIGIT_1: 'Digit1',
  DIGIT_2: 'Digit2',
  DIGIT_3: 'Digit3',
  DIGIT_4: 'Digit4',
  DIGIT_5: 'Digit5',
  R: 'KeyR',
  E: 'KeyE',
  Q: 'KeyQ',
  F: 'KeyF',
} as const;

export interface TouchState {
  identifier: number;
  x: number;
  y: number;
  startX: number;
  startY: number;
}

export interface VirtualJoystickState {
  active: boolean;
  x: number;
  y: number;
  dx: number;
  dy: number;
  angle: number;
  magnitude: number;
}

export interface TouchButtonState {
  active: boolean;
  x: number;
  y: number;
  radius: number;
  pressed: boolean;
  justPressed: boolean;
  justReleased: boolean;
  label: string;
}

export type KeyCodeType = (typeof KeyCode)[keyof typeof KeyCode];

export type MouseButton = 'left' | 'middle' | 'right';

export class InputManager {
  private keys: Map<string, KeyState> = new Map();
  private mouse: MouseState;
  private canvas: HTMLCanvasElement;

  // Touch controls
  private touches: Map<number, TouchState> = new Map();
  private touchEnabled = false;
  private virtualJoystick: VirtualJoystickState = {
    active: false,
    x: 0,
    y: 0,
    dx: 0,
    dy: 0,
    angle: 0,
    magnitude: 0,
  };
  private fireButton: TouchButtonState = {
    active: false,
    x: 0,
    y: 0,
    radius: 50,
    pressed: false,
    justPressed: false,
    justReleased: false,
    label: 'FIRE',
  };
  private reloadButton: TouchButtonState = {
    active: false,
    x: 0,
    y: 0,
    radius: 35,
    pressed: false,
    justPressed: false,
    justReleased: false,
    label: 'R',
  };

  private boundHandlers: {
    keyDown: (e: KeyboardEvent) => void;
    keyUp: (e: KeyboardEvent) => void;
    mouseMove: (e: MouseEvent) => void;
    mouseDown: (e: MouseEvent) => void;
    mouseUp: (e: MouseEvent) => void;
    wheel: (e: WheelEvent) => void;
    contextMenu: (e: MouseEvent) => void;
    touchStart: (e: TouchEvent) => void;
    touchMove: (e: TouchEvent) => void;
    touchEnd: (e: TouchEvent) => void;
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
      touchStart: this.handleTouchStart.bind(this),
      touchMove: this.handleTouchMove.bind(this),
      touchEnd: this.handleTouchEnd.bind(this),
    };

    this.attachListeners();
  }

  // ============================================================================
  // Touch Controls
  // ============================================================================

  /**
   * Enable touch controls for mobile devices
   */
  enableTouchControls(): void {
    if (this.touchEnabled) return;
    this.touchEnabled = true;
    this.setupTouchControls();
    this.attachTouchListeners();
  }

  /**
   * Disable touch controls
   */
  disableTouchControls(): void {
    if (!this.touchEnabled) return;
    this.touchEnabled = false;
    this.detachTouchListeners();
  }

  /**
   * Check if touch controls are enabled
   */
  isTouchEnabled(): boolean {
    return this.touchEnabled;
  }

  /**
   * Check if the device supports touch
   */
  static isTouchDevice(): boolean {
    return 'ontouchstart' in window || navigator.maxTouchPoints > 0;
  }

  /**
   * Get virtual joystick state
   */
  getVirtualJoystick(): VirtualJoystickState {
    return { ...this.virtualJoystick };
  }

  /**
   * Get fire button state
   */
  getFireButton(): TouchButtonState {
    return { ...this.fireButton };
  }

  /**
   * Get reload button state
   */
  getReloadButton(): TouchButtonState {
    return { ...this.reloadButton };
  }

  private setupTouchControls(): void {
    const padding = 80;
    const joystickRadius = 80;

    // Virtual joystick on the left side
    this.virtualJoystick = {
      active: false,
      x: padding + joystickRadius,
      y: this.canvas.height - padding - joystickRadius,
      dx: 0,
      dy: 0,
      angle: 0,
      magnitude: 0,
    };

    // Fire button on the right side
    this.fireButton = {
      active: true,
      x: this.canvas.width - padding - 60,
      y: this.canvas.height - padding - 80,
      radius: 60,
      pressed: false,
      justPressed: false,
      justReleased: false,
      label: 'FIRE',
    };

    // Reload button above fire button
    this.reloadButton = {
      active: true,
      x: this.canvas.width - padding - 40,
      y: this.canvas.height - padding - 180,
      radius: 40,
      pressed: false,
      justPressed: false,
      justReleased: false,
      label: 'R',
    };
  }

  private handleTouchStart(e: TouchEvent): void {
    e.preventDefault();

    for (let i = 0; i < e.changedTouches.length; i++) {
      const touch = e.changedTouches[i];
      if (!touch) continue;

      const x = touch.clientX - this.canvas.getBoundingClientRect().left;
      const y = touch.clientY - this.canvas.getBoundingClientRect().top;
      const identifier = touch.identifier;

      this.touches.set(identifier, {
        identifier,
        x,
        y,
        startX: x,
        startY: y,
      });

      // Check joystick area
      const dx = x - this.virtualJoystick.x;
      const dy = y - this.virtualJoystick.y;
      const dist = Math.sqrt(dx * dx + dy * dy);

      if (dist < 120) {
        this.virtualJoystick.active = true;
        this.updateVirtualJoystick(x, y);
      }

      // Check fire button
      const fireDx = x - this.fireButton.x;
      const fireDy = y - this.fireButton.y;
      if (Math.sqrt(fireDx * fireDx + fireDy * fireDy) < this.fireButton.radius) {
        this.fireButton.pressed = true;
        this.fireButton.justPressed = true;
      }

      // Check reload button
      const reloadDx = x - this.reloadButton.x;
      const reloadDy = y - this.reloadButton.y;
      if (Math.sqrt(reloadDx * reloadDx + reloadDy * reloadDy) < this.reloadButton.radius) {
        this.reloadButton.pressed = true;
        this.reloadButton.justPressed = true;
        // Simulate R key press
        this.simulateKeyPress('KeyR');
      }
    }
  }

  private handleTouchMove(e: TouchEvent): void {
    e.preventDefault();

    for (let i = 0; i < e.changedTouches.length; i++) {
      const touch = e.changedTouches[i];
      if (!touch) continue;

      const identifier = touch.identifier;
      const touchState = this.touches.get(identifier);

      if (touchState) {
        const x = touch.clientX - this.canvas.getBoundingClientRect().left;
        const y = touch.clientY - this.canvas.getBoundingClientRect().top;

        touchState.x = x;
        touchState.y = y;

        if (this.virtualJoystick.active) {
          this.updateVirtualJoystick(x, y);
        }
      }
    }
  }

  private handleTouchEnd(e: TouchEvent): void {
    e.preventDefault();

    for (let i = 0; i < e.changedTouches.length; i++) {
      const touch = e.changedTouches[i];
      if (!touch) continue;

      const identifier = touch.identifier;
      const touchState = this.touches.get(identifier);

      if (touchState) {
        // Check if this was controlling the joystick
        const dx = touchState.x - this.virtualJoystick.x;
        const dy = touchState.y - this.virtualJoystick.y;
        const dist = Math.sqrt(dx * dx + dy * dy);

        if (dist < 150 || this.virtualJoystick.active) {
          this.virtualJoystick.active = false;
          this.virtualJoystick.dx = 0;
          this.virtualJoystick.dy = 0;
          this.virtualJoystick.magnitude = 0;
        }

        // Check fire button
        const fireDx = touchState.startX - this.fireButton.x;
        const fireDy = touchState.startY - this.fireButton.y;
        if (Math.sqrt(fireDx * fireDx + fireDy * fireDy) < this.fireButton.radius) {
          this.fireButton.pressed = false;
          this.fireButton.justReleased = true;
        }

        // Check reload button
        const reloadDx = touchState.startX - this.reloadButton.x;
        const reloadDy = touchState.startY - this.reloadButton.y;
        if (Math.sqrt(reloadDx * reloadDx + reloadDy * reloadDy) < this.reloadButton.radius) {
          this.reloadButton.pressed = false;
          this.reloadButton.justReleased = false;
        }

        this.touches.delete(identifier);
      }
    }
  }

  private updateVirtualJoystick(x: number, y: number): void {
    const maxRadius = 60;
    let dx = x - this.virtualJoystick.x;
    let dy = y - this.virtualJoystick.y;
    const dist = Math.sqrt(dx * dx + dy * dy);

    if (dist > maxRadius) {
      const scale = maxRadius / dist;
      dx *= scale;
      dy *= scale;
    }

    this.virtualJoystick.dx = dx / maxRadius;
    this.virtualJoystick.dy = dy / maxRadius;
    this.virtualJoystick.magnitude = Math.min(1, dist / maxRadius);
    this.virtualJoystick.angle = Math.atan2(dy, dx);
  }

  private simulateKeyPress(code: string): void {
    const state: KeyState = { pressed: true, justPressed: true, justReleased: false };
    this.keys.set(code, state);
  }

  private attachTouchListeners(): void {
    this.canvas.addEventListener('touchstart', this.boundHandlers.touchStart, { passive: false });
    this.canvas.addEventListener('touchmove', this.boundHandlers.touchMove, { passive: false });
    this.canvas.addEventListener('touchend', this.boundHandlers.touchEnd, { passive: false });
    this.canvas.addEventListener('touchcancel', this.boundHandlers.touchEnd, { passive: false });
  }

  private detachTouchListeners(): void {
    this.canvas.removeEventListener('touchstart', this.boundHandlers.touchStart);
    this.canvas.removeEventListener('touchmove', this.boundHandlers.touchMove);
    this.canvas.removeEventListener('touchend', this.boundHandlers.touchEnd);
    this.canvas.removeEventListener('touchcancel', this.boundHandlers.touchEnd);
  }

  /**
   * Render touch controls (call from render system)
   */
  renderTouchControls(ctx: CanvasRenderingContext2D): void {
    if (!this.touchEnabled) return;

    // Draw virtual joystick base
    ctx.fillStyle = 'rgba(100, 100, 100, 0.3)';
    ctx.beginPath();
    ctx.arc(this.virtualJoystick.x, this.virtualJoystick.y, 80, 0, Math.PI * 2);
    ctx.fill();

    // Draw joystick stick
    const stickX = this.virtualJoystick.x + this.virtualJoystick.dx * 60;
    const stickY = this.virtualJoystick.y + this.virtualJoystick.dy * 60;
    ctx.fillStyle = this.virtualJoystick.active ? 'rgba(200, 200, 200, 0.6)' : 'rgba(150, 150, 150, 0.4)';
    ctx.beginPath();
    ctx.arc(stickX, stickY, 25, 0, Math.PI * 2);
    ctx.fill();

    // Draw fire button
    ctx.fillStyle = this.fireButton.pressed ? 'rgba(255, 100, 100, 0.6)' : 'rgba(150, 50, 50, 0.4)';
    ctx.beginPath();
    ctx.arc(this.fireButton.x, this.fireButton.y, this.fireButton.radius, 0, Math.PI * 2);
    ctx.fill();
    ctx.strokeStyle = 'rgba(255, 100, 100, 0.5)';
    ctx.lineWidth = 2;
    ctx.stroke();

    // Fire button label
    ctx.fillStyle = 'rgba(255, 255, 255, 0.7)';
    ctx.font = 'bold 16px Arial';
    ctx.textAlign = 'center';
    ctx.textBaseline = 'middle';
    ctx.fillText(this.fireButton.label, this.fireButton.x, this.fireButton.y);

    // Draw reload button
    ctx.fillStyle = this.reloadButton.pressed ? 'rgba(100, 150, 255, 0.6)' : 'rgba(50, 80, 150, 0.4)';
    ctx.beginPath();
    ctx.arc(this.reloadButton.x, this.reloadButton.y, this.reloadButton.radius, 0, Math.PI * 2);
    ctx.fill();
    ctx.strokeStyle = 'rgba(100, 150, 255, 0.5)';
    ctx.stroke();

    // Reload button label
    ctx.fillStyle = 'rgba(255, 255, 255, 0.7)';
    ctx.font = 'bold 14px Arial';
    ctx.fillText(this.reloadButton.label, this.reloadButton.x, this.reloadButton.y);
  }

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

  getMousePos(): { x: number; y: number } {
    return { x: this.mouse.x, y: this.mouse.y };
  }

  getMouseDelta(): { x: number; y: number } {
    return { x: this.mouse.dx, y: this.mouse.dy };
  }

  getMouseWheel(): number {
    return this.mouse.wheel;
  }

  /**
   * Get the canvas dimensions.
   */
  getCanvasSize(): { width: number; height: number } {
    return {
      width: this.canvas.width,
      height: this.canvas.height,
    };
  }

  /**
   * Handle canvas resize - updates touch control positions.
   * Call this after the canvas is resized.
   */
  handleResize(): void {
    if (this.touchEnabled) {
      this.setupTouchControls();
    }
  }

  setMousePos(_x: number, _y: number): void {
    // Not supported in standard browser APIs
  }

  flushInput(): void {
    this.keys.clear();
    this.resetMouseState();
  }

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

    // Reset touch button states
    if (this.touchEnabled) {
      this.fireButton.justPressed = false;
      this.fireButton.justReleased = false;
      this.reloadButton.justPressed = false;
      this.reloadButton.justReleased = false;
    }
  }

  getState(): InputState {
    return {
      keys: new Map(this.keys),
      mouse: { ...this.mouse },
    };
  }

  destroy(): void {
    this.detachListeners();
    if (this.touchEnabled) {
      this.detachTouchListeners();
    }
  }

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
