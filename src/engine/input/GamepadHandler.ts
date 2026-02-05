/**
 * Gamepad Handler
 *
 * Handles gamepad input via the Gamepad API.
 *
 * Responsibilities:
 * - Poll gamepad state via navigator.getGamepads()
 * - Track button states (pressed, justPressed, justReleased)
 * - Track analog axis values
 * - Manage gamepad connection/disconnection
 *
 * Non-responsibilities:
 * - Does not handle keyboard/mouse input
 * - Does not handle touch input
 * - Does not assign gamepads to specific players
 *
 * Assumptions:
 * - Gamepad API is available (gracefully degrades if not)
 * - poll() is called once per frame to update state
 */

import type { GamepadState } from './types';

export class GamepadHandler {
  private gamepads: Map<number, GamepadState> = new Map();

  /**
   * Poll all connected gamepads and update their state.
   * Call this once per frame.
   */
  poll(): void {
    if (!navigator.getGamepads) return;

    const gamepads = navigator.getGamepads();
    for (let i = 0; i < gamepads.length; i++) {
      const gamepad = gamepads[i];
      if (!gamepad) continue;

      let state = this.gamepads.get(i);
      if (!state) {
        state = {
          index: i,
          connected: true,
          buttons: [],
          axes: [],
        };
        this.gamepads.set(i, state);
      }

      // Update button states
      for (let b = 0; b < gamepad.buttons.length; b++) {
        const btn = gamepad.buttons[b];
        const pressed = typeof btn === 'object' ? btn.pressed : btn === 1.0;
        const value = typeof btn === 'object' ? btn.value : btn;

        let btnState = state.buttons[b];
        if (!btnState) {
          btnState = { pressed: false, justPressed: false, justReleased: false };
          state.buttons[b] = btnState;
        }

        if (pressed && !btnState.pressed) {
          btnState.justPressed = true;
        } else if (!pressed && btnState.pressed) {
          btnState.justReleased = true;
        }
        btnState.pressed = pressed;

        // Store value for analog buttons (triggers)
        if (value !== undefined) {
          (btnState as unknown as { value: number }).value = value;
        }
      }

      // Update axes
      state.axes = [...gamepad.axes];
      state.connected = true;
    }

    // Mark disconnected gamepads
    for (const [index, state] of this.gamepads) {
      const gamepad = gamepads[index];
      if (!gamepad) {
        state.connected = false;
      }
    }
  }

  /**
   * Clear justPressed/justReleased states for all gamepads.
   * Called automatically by poll(), but can be called separately if needed.
   */
  clearEdgeStates(): void {
    for (const state of this.gamepads.values()) {
      for (const btn of state.buttons) {
        btn.justPressed = false;
        btn.justReleased = false;
      }
    }
  }

  /**
   * Get the state of a specific gamepad.
   */
  getGamepad(index: number): GamepadState | undefined {
    return this.gamepads.get(index);
  }

  /**
   * Check if a gamepad button is currently pressed.
   */
  isButtonDown(gamepadIndex: number, button: number): boolean {
    const gamepad = this.gamepads.get(gamepadIndex);
    if (!gamepad || !gamepad.connected) return false;
    return gamepad.buttons[button]?.pressed ?? false;
  }

  /**
   * Check if a gamepad button was just pressed this frame.
   */
  wasButtonPressed(gamepadIndex: number, button: number): boolean {
    const gamepad = this.gamepads.get(gamepadIndex);
    if (!gamepad || !gamepad.connected) return false;
    return gamepad.buttons[button]?.justPressed ?? false;
  }

  /**
   * Check if a gamepad button was just released this frame.
   */
  wasButtonReleased(gamepadIndex: number, button: number): boolean {
    const gamepad = this.gamepads.get(gamepadIndex);
    if (!gamepad || !gamepad.connected) return false;
    return gamepad.buttons[button]?.justReleased ?? false;
  }

  /**
   * Get gamepad axis value (-1 to 1).
   */
  getAxis(gamepadIndex: number, axis: number): number {
    const gamepad = this.gamepads.get(gamepadIndex);
    if (!gamepad || !gamepad.connected) return 0;
    return gamepad.axes[axis] ?? 0;
  }

  /**
   * Check if any gamepad is connected.
   */
  hasGamepad(): boolean {
    for (const state of this.gamepads.values()) {
      if (state.connected) return true;
    }
    return false;
  }

  /**
   * Get the first connected gamepad index, or -1 if none.
   */
  getFirstGamepadIndex(): number {
    for (const [index, state] of this.gamepads) {
      if (state.connected) return index;
    }
    return -1;
  }

  /**
   * Get all connected gamepad indices.
   */
  getConnectedIndices(): number[] {
    const indices: number[] = [];
    for (const [index, state] of this.gamepads) {
      if (state.connected) {
        indices.push(index);
      }
    }
    return indices;
  }
}
