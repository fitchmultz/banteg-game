/**
 * Input Manager
 *
 * Replacement for grim.dll's DirectInput handling.
 * Coordinates multiple input devices including gamepads for co-op play.
 *
 * Responsibilities:
 * - Coordinate keyboard, mouse, touch, and gamepad input handlers
 * - Provide unified query methods for bindings (keyboard codes, mouse buttons, gamepad buttons)
 * - Track input edges (justPressed/justReleased) per frame
 * - Expose high-level input state to game systems
 *
 * Non-responsibilities:
 * - Does not assign input to specific players (see InputSystem)
 * - Does not handle input remapping UI
 * - Does not process touch controls for multiple players (touch is single-player only)
 * - Does not implement device-specific logic (delegated to handlers)
 *
 * Assumptions:
 * - Gamepad API is available (gracefully degrades if not)
 * - update() is called once per frame to clear edge states
 * - Handlers are initialized in constructor and destroyed with destroy()
 */

import type { InputState } from '../../types/game';
import {
  KeyCode,
  GamepadButton,
  type KeyCodeType,
  type MouseButton,
  type GamepadButtonType,
  type VirtualJoystickState,
  type TouchButtonState,
  type GamepadState,
} from './types';
import { KeyboardMouseHandler } from './KeyboardMouseHandler';
import { TouchHandler } from './TouchHandler';
import { GamepadHandler } from './GamepadHandler';

export { KeyCode, GamepadButton, type KeyCodeType, type MouseButton, type GamepadButtonType };
export type { VirtualJoystickState, TouchButtonState, GamepadState };

export class InputManager {
  private keyboardMouse: KeyboardMouseHandler;
  private touch: TouchHandler;
  private gamepad: GamepadHandler;
  private canvas: HTMLCanvasElement;

  constructor(canvas: HTMLCanvasElement) {
    this.canvas = canvas;
    this.keyboardMouse = new KeyboardMouseHandler(canvas);
    this.touch = new TouchHandler(canvas);
    this.gamepad = new GamepadHandler();
  }

  // ============================================================================
  // Keyboard/Mouse Delegation
  // ============================================================================

  isKeyDown(code: string): boolean {
    return this.keyboardMouse.isKeyDown(code);
  }

  wasKeyPressed(code: string): boolean {
    return this.keyboardMouse.wasKeyPressed(code);
  }

  wasKeyReleased(code: string): boolean {
    return this.keyboardMouse.wasKeyReleased(code);
  }

  isMouseButtonDown(button: MouseButton): boolean {
    return this.keyboardMouse.isMouseButtonDown(button);
  }

  wasMouseButtonPressed(button: MouseButton): boolean {
    return this.keyboardMouse.wasMouseButtonPressed(button);
  }

  wasMouseButtonReleased(button: MouseButton): boolean {
    return this.keyboardMouse.wasMouseButtonReleased(button);
  }

  getMousePos(): { x: number; y: number } {
    return this.keyboardMouse.getMousePos();
  }

  getMouseDelta(): { x: number; y: number } {
    return this.keyboardMouse.getMouseDelta();
  }

  getMouseWheel(): number {
    return this.keyboardMouse.getMouseWheel();
  }

  // ============================================================================
  // Touch Controls Delegation
  // ============================================================================

  /**
   * Enable touch controls for mobile devices
   */
  enableTouchControls(): void {
    this.touch.enable();
  }

  /**
   * Disable touch controls
   */
  disableTouchControls(): void {
    this.touch.disable();
  }

  /**
   * Check if the device supports touch
   */
  static isTouchDevice(): boolean {
    return TouchHandler.isTouchDevice();
  }

  /**
   * Check if touch controls are enabled
   */
  isTouchEnabled(): boolean {
    return this.touch.isEnabled();
  }

  /**
   * Get virtual joystick state
   */
  getVirtualJoystick(): VirtualJoystickState {
    return this.touch.getVirtualJoystick();
  }

  /**
   * Get fire button state
   */
  getFireButton(): TouchButtonState {
    return this.touch.getFireButton();
  }

  /**
   * Get reload button state
   */
  getReloadButton(): TouchButtonState {
    return this.touch.getReloadButton();
  }

  /**
   * Render touch controls (call from render system)
   */
  renderTouchControls(ctx: CanvasRenderingContext2D): void {
    this.touch.render(ctx);
  }

  // ============================================================================
  // Gamepad Delegation
  // ============================================================================

  /**
   * Get the state of a specific gamepad.
   */
  getGamepad(index: number): GamepadState | undefined {
    return this.gamepad.getGamepad(index);
  }

  /**
   * Check if a gamepad button is currently pressed.
   */
  isGamepadButtonDown(gamepadIndex: number, button: number): boolean {
    return this.gamepad.isButtonDown(gamepadIndex, button);
  }

  /**
   * Check if a gamepad button was just pressed this frame.
   */
  wasGamepadButtonPressed(gamepadIndex: number, button: number): boolean {
    return this.gamepad.wasButtonPressed(gamepadIndex, button);
  }

  /**
   * Check if a gamepad button was just released this frame.
   */
  wasGamepadButtonReleased(gamepadIndex: number, button: number): boolean {
    return this.gamepad.wasButtonReleased(gamepadIndex, button);
  }

  /**
   * Get gamepad axis value (-1 to 1).
   */
  getGamepadAxis(gamepadIndex: number, axis: number): number {
    return this.gamepad.getAxis(gamepadIndex, axis);
  }

  /**
   * Check if any gamepad is connected.
   */
  hasGamepad(): boolean {
    return this.gamepad.hasGamepad();
  }

  /**
   * Get the first connected gamepad index, or -1 if none.
   */
  getFirstGamepadIndex(): number {
    return this.gamepad.getFirstGamepadIndex();
  }

  // ============================================================================
  // Unified Binding API
  // ============================================================================

  /**
   * Unified binding check - works with keyboard codes, mouse buttons, and gamepad buttons.
   * @param binding - The binding string (e.g., 'KeyW', 'MouseLeft', 'Gamepad0:0' for gamepad 0 button 0)
   */
  isDown(binding: string): boolean {
    // Mouse buttons
    if (binding === 'MouseLeft') return this.isMouseButtonDown('left');
    if (binding === 'MouseMiddle') return this.isMouseButtonDown('middle');
    if (binding === 'MouseRight') return this.isMouseButtonDown('right');

    // Gamepad bindings: "Gamepad{index}:{button}"
    if (binding.startsWith('Gamepad')) {
      const match = binding.match(/Gamepad(\d+):(\d+)/);
      if (match) {
        const gpIndex = Number.parseInt(match[1] ?? '0', 10);
        const btnIndex = Number.parseInt(match[2] ?? '0', 10);
        return this.isGamepadButtonDown(gpIndex, btnIndex);
      }
      return false;
    }

    // Keyboard keys
    return this.isKeyDown(binding);
  }

  /**
   * Unified binding check for just pressed state.
   */
  wasPressed(binding: string): boolean {
    // Mouse buttons
    if (binding === 'MouseLeft') return this.wasMouseButtonPressed('left');
    if (binding === 'MouseMiddle') return this.wasMouseButtonPressed('middle');
    if (binding === 'MouseRight') return this.wasMouseButtonPressed('right');

    // Gamepad bindings
    if (binding.startsWith('Gamepad')) {
      const match = binding.match(/Gamepad(\d+):(\d+)/);
      if (match) {
        const gpIndex = Number.parseInt(match[1] ?? '0', 10);
        const btnIndex = Number.parseInt(match[2] ?? '0', 10);
        return this.wasGamepadButtonPressed(gpIndex, btnIndex);
      }
      return false;
    }

    // Keyboard keys
    return this.wasKeyPressed(binding);
  }

  /**
   * Unified binding check for just released state.
   */
  wasReleased(binding: string): boolean {
    // Mouse buttons
    if (binding === 'MouseLeft') return this.wasMouseButtonReleased('left');
    if (binding === 'MouseMiddle') return this.wasMouseButtonReleased('middle');
    if (binding === 'MouseRight') return this.wasMouseButtonReleased('right');

    // Gamepad bindings
    if (binding.startsWith('Gamepad')) {
      const match = binding.match(/Gamepad(\d+):(\d+)/);
      if (match) {
        const gpIndex = Number.parseInt(match[1] ?? '0', 10);
        const btnIndex = Number.parseInt(match[2] ?? '0', 10);
        return this.wasGamepadButtonReleased(gpIndex, btnIndex);
      }
      return false;
    }

    // Keyboard keys
    return this.wasKeyReleased(binding);
  }

  // ============================================================================
  // Utility Methods
  // ============================================================================

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
    this.touch.handleResize();
  }

  /**
   * Update input manager to clear justPressed/justReleased states.
   * Call once per frame after processing all input.
   */
  update(): void {
    this.keyboardMouse.update();
    this.touch.update();
    this.gamepad.poll();
  }

  /**
   * Simulate a key press (used internally for touch button mapping).
   * Note: This is a no-op in the refactored version as touch buttons
   * are queried directly. Kept for API compatibility.
   */
  setMousePos(_x: number, _y: number): void {
    // Not supported in standard browser APIs
  }

  /**
   * Flush all input state.
   */
  flushInput(): void {
    this.keyboardMouse.flush();
  }

  /**
   * Get full input state snapshot.
   */
  getState(): InputState {
    return this.keyboardMouse.getState();
  }

  /**
   * Clean up all event listeners.
   */
  destroy(): void {
    this.keyboardMouse.destroy();
    this.touch.destroy();
  }
}
