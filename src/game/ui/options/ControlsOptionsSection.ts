/**
 * Controls Options Section
 *
 * Handles control settings: key binding configuration.
 */

import type { GameConfig, KeyBindings } from '../../../types';
import type { OptionItem, OptionsSection } from './types';

export const CONTROLS_SECTION: OptionsSection = 'CONTROLS';

export interface ControlsItemsResult {
  items: OptionItem[];
}

export type ControlAction = keyof KeyBindings;

export const CONTROL_ACTIONS: ControlAction[] = [
  'moveUp',
  'moveDown',
  'moveLeft',
  'moveRight',
  'reload',
  'swapWeapon',
  'pause',
  'fire',
];

export const ACTION_DISPLAY_NAMES: Record<ControlAction, string> = {
  moveUp: 'Move Up',
  moveDown: 'Move Down',
  moveLeft: 'Move Left',
  moveRight: 'Move Right',
  fire: 'Fire',
  reload: 'Reload',
  swapWeapon: 'Swap Weapon',
  pause: 'Pause',
};

export function buildControlsItems(config: GameConfig): ControlsItemsResult {
  const items: OptionItem[] = [
    { id: 'section_controls', label: 'CONTROLS', type: 'button', section: CONTROLS_SECTION },
    ...CONTROL_ACTIONS.map(
      (action): OptionItem => ({
        id: `bind_${action}`,
        label: ACTION_DISPLAY_NAMES[action],
        type: 'binding',
        section: CONTROLS_SECTION,
        value: config.controls[action],
      })
    ),
  ];

  return { items };
}

export function getActionFromBindingId(id: string): ControlAction | null {
  if (!id.startsWith('bind_')) return null;
  return id.replace('bind_', '') as ControlAction;
}

export function formatKeyCode(code: string): string {
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

export function formatActionName(action: ControlAction): string {
  return ACTION_DISPLAY_NAMES[action] ?? action;
}

export function updateKeyBinding(
  action: ControlAction,
  code: string,
  config: GameConfig
): Partial<GameConfig> {
  return {
    controls: {
      ...config.controls,
      [action]: code,
    },
  };
}
