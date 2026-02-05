/**
 * Engine Initialization
 *
 * Initializes core engine systems: renderer, input, audio, assets.
 */

import {
  AssetManager,
  AudioManager,
  InputManager,
  Renderer,
  SpriteAtlas,
  generateSpriteAtlas,
} from '../../engine';
import { loadGameAudio } from '../audio';
import type { SettingsManager } from '../settings/SettingsManager';
import { gameState } from './gameState';

export interface EngineInstances {
  renderer: Renderer;
  input: InputManager;
  audio: AudioManager;
  assetManager: AssetManager;
  spriteAtlas: SpriteAtlas;
}

export async function initializeEngine(
  container: HTMLElement,
  settingsManager: SettingsManager
): Promise<EngineInstances> {
  const settings = settingsManager.getConfig();

  const renderer = new Renderer(container, {
    width: settings.resolution.width,
    height: settings.resolution.height,
    smoothing: false,
  });

  const input = new InputManager(renderer.getCanvas());

  if (InputManager.isTouchDevice()) {
    input.enableTouchControls();
    console.log('Touch controls enabled');
  }

  const audio = new AudioManager({
    sfxVolume: settings.sfxVolume,
    musicVolume: settings.musicVolume,
  });

  const assetManager = new AssetManager({ basePath: '' });
  const spriteAtlas = new SpriteAtlas();

  const { image: spriteCanvas, data: atlasData } = generateSpriteAtlas();
  spriteAtlas.loadFromData(atlasData);

  const spriteBlob = await new Promise<Blob | null>((resolve) => {
    spriteCanvas.toBlob(resolve, 'image/png');
  });

  if (spriteBlob) {
    const spriteUrl = URL.createObjectURL(spriteBlob);
    await assetManager.loadImage('creatures', spriteUrl);
    console.log('Creature sprites loaded successfully');
  } else {
    console.warn('Failed to generate creature sprites, falling back to colored circles');
  }

  // Initialize audio on first click
  renderer.getCanvas().addEventListener(
    'click',
    async () => {
      try {
        await audio.initialize();
        const result = await loadGameAudio(audio);
        gameState.audioLoaded = result.success;
      } catch (error) {
        console.error('Failed to initialize audio:', error);
        gameState.audioLoaded = false;
      }
    },
    { once: true }
  );

  return { renderer, input, audio, assetManager, spriteAtlas };
}
