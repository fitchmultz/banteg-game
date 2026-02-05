/**
 * Options UI Types
 *
 * Shared types for the options menu components.
 */

import type { GameConfig } from '../../../types';

export type OptionsSection = 'AUDIO' | 'DISPLAY' | 'CONTROLS';
export type OptionsMenuContext = 'menu' | 'pause';

export interface OptionsMenuUIOptions {
  canvas: HTMLCanvasElement;
  onChangeConfig: (config: GameConfig) => void;
  onRequestBack: (context: OptionsMenuContext) => void;
  getInitialConfig: () => GameConfig;
  getIsFullscreen?: () => boolean;
}

export interface OptionItem {
  id: string;
  label: string;
  type: 'slider' | 'toggle' | 'cycle' | 'binding' | 'button';
  section: OptionsSection;
  value?: number | boolean | string;
  min?: number;
  max?: number;
  options?: string[];
}
