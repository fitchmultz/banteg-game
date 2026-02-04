/**
 * Settings Manager Unit Tests
 */

import { describe, it, expect, beforeEach, vi, afterEach } from 'vitest';
import {
  SettingsManager,
  SETTINGS_STORAGE_KEY,
  SETTINGS_VERSION,
  DEFAULT_GAME_CONFIG,
  DEFAULT_KEY_BINDINGS,
  validateGameConfig,
  applyAudioSettings,
  applyRendererSettings,
  VALID_RESOLUTIONS,
} from '../../../../src/game/settings/SettingsManager';
import type { GameConfig } from '../../../../src/types';
import type { AudioManager } from '../../../../src/engine/AudioManager';
import type { Renderer } from '../../../../src/engine/Renderer';

// Create a fresh storage object for test isolation
function createStorage(): Record<string, string> {
  return {};
}

// Factory to create a fresh localStorage mock with isolated storage
function createLocalStorageMock(store: Record<string, string>) {
  return {
    getItem: vi.fn((key: string) => store[key] ?? null),
    setItem: vi.fn((key: string, value: string) => {
      store[key] = value;
    }),
    clear: vi.fn(() => {
      for (const key of Object.keys(store)) {
        delete store[key];
      }
    }),
    removeItem: vi.fn((key: string) => {
      delete store[key];
    }),
  };
}

// Mock AudioManager
function createMockAudioManager() {
  return {
    setSfxVolume: vi.fn(),
    setMusicVolume: vi.fn(),
    getSfxVolume: vi.fn(() => 0.7),
    getMusicVolume: vi.fn(() => 0.5),
  };
}

// Mock Renderer
function createMockRenderer() {
  return {
    resize: vi.fn(),
    getDimensions: vi.fn(() => ({ width: 1024, height: 768 })),
  };
}

describe('SettingsManager', () => {
  let store: Record<string, string>;
  let localStorageMock: ReturnType<typeof createLocalStorageMock>;

  beforeEach(() => {
    // Create completely fresh isolated storage for each test
    store = createStorage();
    localStorageMock = createLocalStorageMock(store);
    // Stub global localStorage
    vi.stubGlobal('localStorage', localStorageMock);
  });

  afterEach(() => {
    vi.unstubAllGlobals();
    vi.clearAllMocks();
  });

  describe('Initialization', () => {
    it('should create with default settings when no stored settings exist', () => {
      const manager = new SettingsManager();

      expect(manager.getConfig().sfxVolume).toBe(DEFAULT_GAME_CONFIG.sfxVolume);
      expect(manager.getConfig().musicVolume).toBe(DEFAULT_GAME_CONFIG.musicVolume);
      expect(manager.getConfig().resolution).toEqual(DEFAULT_GAME_CONFIG.resolution);
      expect(manager.getConfig().fullscreen).toBe(DEFAULT_GAME_CONFIG.fullscreen);
      expect(manager.getConfig().playerName).toBe(DEFAULT_GAME_CONFIG.playerName);
    });

    it('should load saved settings', () => {
      const savedSettings = {
        version: 1,
        config: {
          playerName: 'TestPlayer',
          sfxVolume: 0.8,
          musicVolume: 0.3,
          resolution: { width: 1280, height: 720 },
          fullscreen: true,
          controls: {
            moveUp: 'ArrowUp',
            moveDown: 'ArrowDown',
            moveLeft: 'ArrowLeft',
            moveRight: 'ArrowRight',
            fire: 'MouseLeft',
            reload: 'KeyR',
            swapWeapon: 'KeyQ',
            pause: 'Escape',
          },
        },
      };

      store[SETTINGS_STORAGE_KEY] = JSON.stringify(savedSettings);
      const manager = new SettingsManager();

      expect(manager.getConfig().playerName).toBe('TestPlayer');
      expect(manager.getConfig().sfxVolume).toBe(0.8);
      expect(manager.getConfig().musicVolume).toBe(0.3);
      expect(manager.getConfig().resolution).toEqual({ width: 1280, height: 720 });
      expect(manager.getConfig().fullscreen).toBe(true);
    });

    it('should handle corrupted localStorage gracefully', () => {
      store[SETTINGS_STORAGE_KEY] = 'not valid json{';
      const manager = new SettingsManager();

      expect(manager.getConfig().sfxVolume).toBe(DEFAULT_GAME_CONFIG.sfxVolume);
      expect(manager.getConfig().resolution).toEqual(DEFAULT_GAME_CONFIG.resolution);
    });

    it('should handle null in localStorage', () => {
      store[SETTINGS_STORAGE_KEY] = 'null';
      const manager = new SettingsManager();

      expect(manager.getConfig().sfxVolume).toBe(DEFAULT_GAME_CONFIG.sfxVolume);
    });
  });

  describe('Configuration Management', () => {
    it('should get configuration', () => {
      const manager = new SettingsManager();
      const config = manager.getConfig();

      expect(config).toEqual(
        expect.objectContaining({
          playerName: expect.any(String),
          sfxVolume: expect.any(Number),
          musicVolume: expect.any(Number),
          resolution: expect.any(Object),
          fullscreen: expect.any(Boolean),
          controls: expect.any(Object),
        })
      );
    });

    it('should get key bindings', () => {
      const manager = new SettingsManager();
      const bindings = manager.getKeyBindings();

      expect(bindings.moveUp).toBeDefined();
      expect(bindings.moveDown).toBeDefined();
      expect(bindings.moveLeft).toBeDefined();
      expect(bindings.moveRight).toBeDefined();
      expect(bindings.reload).toBeDefined();
      expect(bindings.swapWeapon).toBeDefined();
      expect(bindings.pause).toBeDefined();
    });

    it('should set entire configuration', () => {
      const manager = new SettingsManager();
      const newConfig: GameConfig = {
        playerName: 'NewName',
        sfxVolume: 0.5,
        musicVolume: 0.5,
        resolution: { width: 1920, height: 1080 },
        fullscreen: true,
        controls: { ...DEFAULT_GAME_CONFIG.controls },
        goreIntensity: 1,
      };

      manager.setConfig(newConfig);

      expect(manager.getConfig().playerName).toBe('NewName');
      expect(manager.getConfig().sfxVolume).toBe(0.5);
      expect(manager.getConfig().resolution).toEqual({ width: 1920, height: 1080 });
    });

    it('should update configuration partially', () => {
      const manager = new SettingsManager();

      manager.updateConfig({ sfxVolume: 0.3 });

      expect(manager.getConfig().sfxVolume).toBe(0.3);
      expect(manager.getConfig().musicVolume).toBe(DEFAULT_GAME_CONFIG.musicVolume);
    });

    it('should update key binding', () => {
      const manager = new SettingsManager();

      manager.updateKeyBinding('reload', 'KeyT');

      expect(manager.getKeyBindings().reload).toBe('KeyT');
    });

    it('should reset to defaults', () => {
      const manager = new SettingsManager();

      manager.updateConfig({ sfxVolume: 0.2, playerName: 'Changed' });
      expect(manager.getConfig().sfxVolume).toBe(0.2);

      manager.reset();

      expect(manager.getConfig().sfxVolume).toBe(DEFAULT_GAME_CONFIG.sfxVolume);
      expect(manager.getConfig().playerName).toBe(DEFAULT_GAME_CONFIG.playerName);
    });
  });

  describe('Persistence', () => {
    it('should save to localStorage', () => {
      const manager = new SettingsManager();

      manager.updateConfig({ sfxVolume: 0.4 });
      manager.save();

      expect(localStorageMock.setItem).toHaveBeenCalled();
      const saved = JSON.parse(store[SETTINGS_STORAGE_KEY] ?? '{}');
      expect(saved.version).toBe(SETTINGS_VERSION);
      expect(saved.config.sfxVolume).toBe(0.4);
    });

    it('should not save if not dirty', () => {
      const manager = new SettingsManager();
      manager.save();

      // Should not be called since no changes were made
      expect(localStorageMock.setItem).not.toHaveBeenCalled();
    });

    it('should force save even if not dirty', () => {
      const manager = new SettingsManager();
      manager.forceSave();

      expect(localStorageMock.setItem).toHaveBeenCalled();
    });

    it('should handle localStorage errors gracefully', () => {
      const errorMock = createLocalStorageMock(store);
      errorMock.setItem = vi.fn(() => {
        throw new Error('QuotaExceededError');
      });
      vi.stubGlobal('localStorage', errorMock);

      const manager = new SettingsManager();
      manager.updateConfig({ sfxVolume: 0.5 });

      // Should not throw
      expect(() => manager.save()).not.toThrow();
    });
  });

  describe('Settings Application', () => {
    it('should apply audio settings', () => {
      const manager = new SettingsManager();
      const audio = createMockAudioManager();

      manager.updateConfig({ sfxVolume: 0.4, musicVolume: 0.6 });
      applyAudioSettings(audio as unknown as AudioManager, manager.getConfig());

      expect(audio.setSfxVolume).toHaveBeenCalledWith(0.4);
      expect(audio.setMusicVolume).toHaveBeenCalledWith(0.6);
    });

    it('should apply renderer settings', () => {
      const manager = new SettingsManager();
      const renderer = createMockRenderer();

      manager.updateConfig({ resolution: { width: 1280, height: 720 } });
      applyRendererSettings(renderer as unknown as Renderer, manager.getConfig());

      expect(renderer.resize).toHaveBeenCalledWith(1280, 720);
    });

    it('should not resize if dimensions match', () => {
      const manager = new SettingsManager();
      const renderer = createMockRenderer();
      renderer.getDimensions = vi.fn(() => ({ width: 1024, height: 768 }));

      manager.updateConfig({ resolution: { width: 1024, height: 768 } });
      applyRendererSettings(renderer as unknown as Renderer, manager.getConfig());

      expect(renderer.resize).not.toHaveBeenCalled();
    });
  });

  describe('Migration', () => {
    it('should migrate from version 0 (no version field)', () => {
      const v0Data = {
        config: {
          playerName: 'OldPlayer',
          sfxVolume: 0.6,
          // Missing some fields
        },
        // No version field
      };

      store[SETTINGS_STORAGE_KEY] = JSON.stringify(v0Data);
      const manager = new SettingsManager();

      expect(manager.getConfig().playerName).toBe('OldPlayer');
      expect(manager.getConfig().sfxVolume).toBe(0.6);
      // Should fill in defaults for missing fields
      expect(manager.getConfig().controls).toBeDefined();
    });
  });

  describe('Validation', () => {
    it('should clamp sfxVolume to 0-1 range', () => {
      const invalid = { ...DEFAULT_GAME_CONFIG, sfxVolume: 1.5 };
      const validated = validateGameConfig(invalid);

      expect(validated.sfxVolume).toBe(1);
    });

    it('should clamp negative volumes to 0', () => {
      const invalid = { ...DEFAULT_GAME_CONFIG, musicVolume: -0.5 };
      const validated = validateGameConfig(invalid);

      expect(validated.musicVolume).toBe(0);
    });

    it('should reject invalid resolution and use default', () => {
      const invalid = {
        ...DEFAULT_GAME_CONFIG,
        resolution: { width: 9999, height: 9999 },
      };
      const validated = validateGameConfig(invalid);

      expect(validated.resolution).toEqual(DEFAULT_GAME_CONFIG.resolution);
    });

    it('should accept valid resolution', () => {
      const valid = {
        ...DEFAULT_GAME_CONFIG,
        resolution: { width: 1280, height: 720 },
      };
      const validated = validateGameConfig(valid);

      expect(validated.resolution).toEqual({ width: 1280, height: 720 });
    });

    it('should truncate long player names', () => {
      const invalid = { ...DEFAULT_GAME_CONFIG, playerName: 'A'.repeat(50) };
      const validated = validateGameConfig(invalid);

      expect(validated.playerName.length).toBeLessThanOrEqual(20);
    });

    it('should handle non-string controls gracefully', () => {
      const invalid = {
        ...DEFAULT_GAME_CONFIG,
        controls: {
          ...DEFAULT_GAME_CONFIG.controls,
          reload: 123 as unknown as string,
        },
      };
      const validated = validateGameConfig(invalid);

      // Non-string value should fall back to default
      expect(validated.controls.reload).toBe(DEFAULT_KEY_BINDINGS.reload);
    });

    it('should handle null input gracefully', () => {
      const validated = validateGameConfig(null);
      expect(validated).toEqual(DEFAULT_GAME_CONFIG);
    });

    it('should handle non-object input gracefully', () => {
      const validated = validateGameConfig('invalid');
      expect(validated).toEqual(DEFAULT_GAME_CONFIG);
    });
  });

  describe('Static Methods', () => {
    it('should return default configuration', () => {
      const defaults = SettingsManager.getDefaults();
      expect(defaults).toEqual(DEFAULT_GAME_CONFIG);
    });

    it('should return valid resolution presets', () => {
      const resolutions = SettingsManager.getValidResolutions();
      expect(resolutions).toEqual(VALID_RESOLUTIONS);
    });
  });
});
