/**
 * Input Types
 *
 * Shared type definitions for all input handlers.
 *
 * Responsibilities:
 * - Define key codes, gamepad button mappings
 * - Define state interfaces for all input devices
 *
 * Non-responsibilities:
 * - Does not implement input handling logic
 * - Does not manage event listeners
 */

import type { KeyState, MouseState, InputState } from '../../types/game';

export type { KeyState, MouseState, InputState };

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

export type KeyCodeType = (typeof KeyCode)[keyof typeof KeyCode];

export type MouseButton = 'left' | 'middle' | 'right';

export const GamepadButton = {
  A: 0,
  B: 1,
  X: 2,
  Y: 3,
  LB: 4,
  RB: 5,
  LT: 6,
  RT: 7,
  BACK: 8,
  START: 9,
  L3: 10,
  R3: 11,
  UP: 12,
  DOWN: 13,
  LEFT: 14,
  RIGHT: 15,
} as const;

export type GamepadButtonType = (typeof GamepadButton)[keyof typeof GamepadButton];

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

export interface GamepadState {
  index: number;
  connected: boolean;
  buttons: KeyState[];
  axes: number[];
}
