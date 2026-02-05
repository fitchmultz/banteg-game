/**
 * Audio Options Section
 *
 * Handles audio settings: SFX volume and music volume sliders.
 */

import type { GameConfig } from '../../../types';
import type { OptionItem, OptionsSection } from './types';

export const AUDIO_SECTION: OptionsSection = 'AUDIO';

export interface AudioItemsResult {
  items: OptionItem[];
}

export function buildAudioItems(config: GameConfig): AudioItemsResult {
  const items: OptionItem[] = [
    { id: 'section_audio', label: 'AUDIO', type: 'button', section: AUDIO_SECTION },
    {
      id: 'sfxVolume',
      label: 'SFX Volume',
      type: 'slider',
      section: AUDIO_SECTION,
      value: Math.round(config.sfxVolume * 100),
      min: 0,
      max: 100,
    },
    {
      id: 'musicVolume',
      label: 'Music Volume',
      type: 'slider',
      section: AUDIO_SECTION,
      value: Math.round(config.musicVolume * 100),
      min: 0,
      max: 100,
    },
  ];

  return { items };
}

export function updateAudioConfig(
  itemId: string,
  value: number,
  _config: GameConfig
): Partial<GameConfig> | null {
  switch (itemId) {
    case 'sfxVolume':
      return { sfxVolume: value / 100 };
    case 'musicVolume':
      return { musicVolume: value / 100 };
    default:
      return null;
  }
}
