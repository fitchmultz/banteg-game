/**
 * Display Options Section
 *
 * Handles display settings: resolution cycling and fullscreen toggle.
 */

import type { GameConfig } from '../../../types';
import { VALID_RESOLUTIONS } from '../../settings/SettingsManager';
import type { OptionItem, OptionsSection } from './types';

export const DISPLAY_SECTION: OptionsSection = 'DISPLAY';

export interface DisplayItemsResult {
  items: OptionItem[];
  defaultResolutionIndex: number;
}

export function getResolutionIndex(config: GameConfig): number {
  const index = VALID_RESOLUTIONS.findIndex(
    (r) => r.width === config.resolution.width && r.height === config.resolution.height
  );
  return index >= 0 ? index : 1; // Default to 1024x768 (index 1)
}

export function buildDisplayItems(config: GameConfig): DisplayItemsResult {
  const items: OptionItem[] = [
    { id: 'section_display', label: 'DISPLAY', type: 'button', section: DISPLAY_SECTION },
    {
      id: 'resolution',
      label: 'Resolution',
      type: 'cycle',
      section: DISPLAY_SECTION,
      value: getResolutionIndex(config),
      options: VALID_RESOLUTIONS.map((r) => `${r.width}x${r.height}`),
    },
    {
      id: 'fullscreen',
      label: 'Fullscreen',
      type: 'toggle',
      section: DISPLAY_SECTION,
      value: config.fullscreen,
    },
  ];

  return {
    items,
    defaultResolutionIndex: 1,
  };
}

export function updateDisplayConfig(
  itemId: string,
  value: number | boolean,
  _config: GameConfig
): Partial<GameConfig> | null {
  switch (itemId) {
    case 'resolution': {
      const index = value as number;
      const resolution = VALID_RESOLUTIONS[index];
      return resolution ? { resolution: { ...resolution } } : null;
    }
    case 'fullscreen':
      return { fullscreen: value as boolean };
    default:
      return null;
  }
}

export function toggleFullscreen(fullscreen: boolean): void {
  if (fullscreen) {
    document.documentElement.requestFullscreen().catch((err) => {
      console.warn('Failed to enter fullscreen:', err);
    });
  } else {
    if (document.fullscreenElement) {
      document.exitFullscreen().catch((err) => {
        console.warn('Failed to exit fullscreen:', err);
      });
    }
  }
}
