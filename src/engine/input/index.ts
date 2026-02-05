/**
 * Input Module
 *
 * Provides input handling for keyboard, mouse, touch, and gamepad.
 */

export {
  KeyCode,
  GamepadButton,
  type KeyCodeType,
  type MouseButton,
  type GamepadButtonType,
  type TouchState,
  type VirtualJoystickState,
  type TouchButtonState,
  type GamepadState,
  type KeyState,
  type MouseState,
  type InputState,
} from './types';

export { KeyboardMouseHandler, type KeyboardMouseState } from './KeyboardMouseHandler';
export { TouchHandler, type TouchHandlerState } from './TouchHandler';
export { GamepadHandler } from './GamepadHandler';
export { InputManager } from './InputManager';
