/**
 * Touch Handler
 *
 * Handles touch input for mobile devices with virtual controls.
 *
 * Responsibilities:
 * - Track touch events and finger positions
 * - Manage virtual joystick state and calculations
 * - Manage touch buttons (fire, reload)
 * - Render touch controls to canvas
 *
 * Non-responsibilities:
 * - Does not handle keyboard/mouse input
 * - Does not handle gamepad input
 * - Does not process input for multiple players
 *
 * Assumptions:
 * - Touch is single-player only
 * - Canvas is used for coordinate calculations
 */

import type { TouchState, VirtualJoystickState, TouchButtonState } from './types';

export interface TouchHandlerState {
  virtualJoystick: VirtualJoystickState;
  fireButton: TouchButtonState;
  reloadButton: TouchButtonState;
}

export class TouchHandler {
  private touches: Map<number, TouchState> = new Map();
  private touchEnabled = false;
  private virtualJoystick: VirtualJoystickState;
  private fireButton: TouchButtonState;
  private reloadButton: TouchButtonState;
  private canvas: HTMLCanvasElement;

  private boundHandlers: {
    touchStart: (e: TouchEvent) => void;
    touchMove: (e: TouchEvent) => void;
    touchEnd: (e: TouchEvent) => void;
  };

  constructor(canvas: HTMLCanvasElement) {
    this.canvas = canvas;

    this.virtualJoystick = {
      active: false,
      x: 0,
      y: 0,
      dx: 0,
      dy: 0,
      angle: 0,
      magnitude: 0,
    };

    this.fireButton = {
      active: false,
      x: 0,
      y: 0,
      radius: 50,
      pressed: false,
      justPressed: false,
      justReleased: false,
      label: 'FIRE',
    };

    this.reloadButton = {
      active: false,
      x: 0,
      y: 0,
      radius: 35,
      pressed: false,
      justPressed: false,
      justReleased: false,
      label: 'R',
    };

    this.boundHandlers = {
      touchStart: this.handleTouchStart.bind(this),
      touchMove: this.handleTouchMove.bind(this),
      touchEnd: this.handleTouchEnd.bind(this),
    };
  }

  /**
   * Enable touch controls for mobile devices
   */
  enable(): void {
    if (this.touchEnabled) return;
    this.touchEnabled = true;
    this.setupTouchControls();
    this.attachListeners();
  }

  /**
   * Disable touch controls
   */
  disable(): void {
    if (!this.touchEnabled) return;
    this.touchEnabled = false;
    this.detachListeners();
  }

  /**
   * Check if touch controls are enabled
   */
  isEnabled(): boolean {
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

  /**
   * Get full touch state
   */
  getState(): TouchHandlerState {
    return {
      virtualJoystick: { ...this.virtualJoystick },
      fireButton: { ...this.fireButton },
      reloadButton: { ...this.reloadButton },
    };
  }

  /**
   * Handle canvas resize - updates touch control positions
   */
  handleResize(): void {
    if (this.touchEnabled) {
      this.setupTouchControls();
    }
  }

  /**
   * Update touch handler to clear justPressed/justReleased states
   */
  update(): void {
    if (this.touchEnabled) {
      this.fireButton.justPressed = false;
      this.fireButton.justReleased = false;
      this.reloadButton.justPressed = false;
      this.reloadButton.justReleased = false;
    }
  }

  /**
   * Render touch controls (call from render system)
   */
  render(ctx: CanvasRenderingContext2D): void {
    if (!this.touchEnabled) return;

    // Draw virtual joystick base
    ctx.fillStyle = 'rgba(100, 100, 100, 0.3)';
    ctx.beginPath();
    ctx.arc(this.virtualJoystick.x, this.virtualJoystick.y, 80, 0, Math.PI * 2);
    ctx.fill();

    // Draw joystick stick
    const stickX = this.virtualJoystick.x + this.virtualJoystick.dx * 60;
    const stickY = this.virtualJoystick.y + this.virtualJoystick.dy * 60;
    ctx.fillStyle = this.virtualJoystick.active
      ? 'rgba(200, 200, 200, 0.6)'
      : 'rgba(150, 150, 150, 0.4)';
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
    ctx.fillStyle = this.reloadButton.pressed
      ? 'rgba(100, 150, 255, 0.6)'
      : 'rgba(50, 80, 150, 0.4)';
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

  destroy(): void {
    if (this.touchEnabled) {
      this.detachListeners();
    }
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

  private attachListeners(): void {
    this.canvas.addEventListener('touchstart', this.boundHandlers.touchStart, { passive: false });
    this.canvas.addEventListener('touchmove', this.boundHandlers.touchMove, { passive: false });
    this.canvas.addEventListener('touchend', this.boundHandlers.touchEnd, { passive: false });
    this.canvas.addEventListener('touchcancel', this.boundHandlers.touchEnd, { passive: false });
  }

  private detachListeners(): void {
    this.canvas.removeEventListener('touchstart', this.boundHandlers.touchStart);
    this.canvas.removeEventListener('touchmove', this.boundHandlers.touchMove);
    this.canvas.removeEventListener('touchend', this.boundHandlers.touchEnd);
    this.canvas.removeEventListener('touchcancel', this.boundHandlers.touchEnd);
  }
}
