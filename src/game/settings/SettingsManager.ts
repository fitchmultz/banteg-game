/**
 * Settings Manager
 *
 * Handles save/load for game settings including audio volumes, display options,
 * and configurable key bindings. Uses localStorage with versioning for future migrations.
 *
 * Responsibilities:
 * - Load and validate settings from localStorage
 * - Save settings to localStorage
 * - Apply settings to AudioManager and Renderer
 * - Provide default settings
 *
 * Non-responsibilities:
 * - Does not handle gameplay progression (see ProgressionManager)
 * - Does not render UI (see OptionsMenuUI)
 *
 * Assumptions:
 * - localStorage is available (falls back to defaults if not)
 * - Settings are validated on load to prevent invalid states
 */

import type { AudioManager } from '../../engine/AudioManager';
import type { Renderer } from '../../engine/Renderer';
import type { GameConfig, KeyBindings } from '../../types';

// Storage key for localStorage
export const SETTINGS_STORAGE_KEY = 'crimsonland_settings_v1';

// Current save version for migrations
export const SETTINGS_VERSION = 1;

// Valid resolution presets (avoid exotic sizes that break UI layout)
export const VALID_RESOLUTIONS: ReadonlyArray<{ width: number; height: number }> = [
  { width: 800, height: 600 },
  { width: 1024, height: 768 },
  { width: 1280, height: 720 },
  { width: 1280, height: 800 },
  { width: 1366, height: 768 },
  { width: 1440, height: 900 },
  { width: 1600, height: 900 },
  { width: 1920, height: 1080 },
];

// Default key bindings (matches current hardcoded behavior)
export const DEFAULT_KEY_BINDINGS: KeyBindings = {
  moveUp: 'KeyW',
  moveDown: 'KeyS',
  moveLeft: 'KeyA',
  moveRight: 'KeyD',
  fire: 'MouseLeft', // Special code for mouse left button
  reload: 'KeyR',
  swapWeapon: 'KeyQ',
  pause: 'Escape',
};

// Default P2 key bindings (arrow keys + numpad)
export const DEFAULT_KEY_BINDINGS_P2: KeyBindings = {
  moveUp: 'ArrowUp',
  moveDown: 'ArrowDown',
  moveLeft: 'ArrowLeft',
  moveRight: 'ArrowRight',
  fire: 'Numpad0', // Numpad 0 for fire
  reload: 'NumpadDecimal', // Numpad . for reload
  swapWeapon: 'NumpadEnter', // Numpad Enter for swap
  pause: 'Escape', // Shared pause key
};

// Default game configuration
export const DEFAULT_GAME_CONFIG: GameConfig = {
  playerName: 'Player',
  sfxVolume: 0.7,
  musicVolume: 0.5,
  resolution: { width: 1024, height: 768 },
  fullscreen: false,
  controls: { ...DEFAULT_KEY_BINDINGS },
};

// Settings storage envelope for versioning
interface SettingsEnvelope {
  version: number;
  config: GameConfig;
}

/**
 * Validate and normalize a GameConfig object.
 * Returns a valid GameConfig, filling in defaults for any invalid/missing fields.
 */
export function validateGameConfig(candidate: unknown): GameConfig {
  const result: GameConfig = { ...DEFAULT_GAME_CONFIG };

  if (typeof candidate !== 'object' || candidate === null) {
    return result;
  }

  const obj = candidate as Record<string, unknown>;

  // Validate playerName
  if (typeof obj.playerName === 'string' && obj.playerName.length > 0) {
    result.playerName = obj.playerName.slice(0, 20); // Max 20 chars
  }

  // Validate sfxVolume (clamp to 0-1)
  if (typeof obj.sfxVolume === 'number' && !Number.isNaN(obj.sfxVolume)) {
    result.sfxVolume = Math.max(0, Math.min(1, obj.sfxVolume));
  }

  // Validate musicVolume (clamp to 0-1)
  if (typeof obj.musicVolume === 'number' && !Number.isNaN(obj.musicVolume)) {
    result.musicVolume = Math.max(0, Math.min(1, obj.musicVolume));
  }

  // Validate resolution (must be from valid presets)
  if (
    typeof obj.resolution === 'object' &&
    obj.resolution !== null &&
    'width' in obj.resolution &&
    'height' in obj.resolution
  ) {
    const res = obj.resolution as { width: unknown; height: unknown };
    const width = typeof res.width === 'number' ? res.width : 0;
    const height = typeof res.height === 'number' ? res.height : 0;

    const isValidResolution = VALID_RESOLUTIONS.some(
      (r) => r.width === width && r.height === height
    );

    if (isValidResolution) {
      result.resolution = { width, height };
    }
  }

  // Validate fullscreen
  if (typeof obj.fullscreen === 'boolean') {
    result.fullscreen = obj.fullscreen;
  }

  // Validate controls
  if (typeof obj.controls === 'object' && obj.controls !== null) {
    const controls = obj.controls as Record<string, unknown>;
    const validatedControls: KeyBindings = { ...DEFAULT_KEY_BINDINGS };

    // Validate each key binding (must be non-empty string if present)
    const bindingKeys: Array<keyof KeyBindings> = [
      'moveUp',
      'moveDown',
      'moveLeft',
      'moveRight',
      'fire',
      'reload',
      'swapWeapon',
      'pause',
    ];

    for (const key of bindingKeys) {
      const value = controls[key];
      if (typeof value === 'string') {
        validatedControls[key] = value;
      }
    }

    result.controls = validatedControls;
  }

  // Validate controlsP2 (optional)
  if (typeof obj.controlsP2 === 'object' && obj.controlsP2 !== null) {
    const controlsP2 = obj.controlsP2 as Record<string, unknown>;
    const validatedControlsP2: KeyBindings = { ...DEFAULT_KEY_BINDINGS_P2 };

    const bindingKeys: Array<keyof KeyBindings> = [
      'moveUp',
      'moveDown',
      'moveLeft',
      'moveRight',
      'fire',
      'reload',
      'swapWeapon',
      'pause',
    ];

    for (const key of bindingKeys) {
      const value = controlsP2[key];
      if (typeof value === 'string') {
        validatedControlsP2[key] = value;
      }
    }

    result.controlsP2 = validatedControlsP2;
  }

  return result;
}

/**
 * Apply audio settings to an AudioManager instance.
 */
export function applyAudioSettings(audio: AudioManager, cfg: GameConfig): void {
  audio.setSfxVolume(cfg.sfxVolume);
  audio.setMusicVolume(cfg.musicVolume);
}

/**
 * Apply renderer settings to a Renderer instance.
 * Note: Fullscreen changes require user gesture, so this only handles resolution.
 */
export function applyRendererSettings(renderer: Renderer, cfg: GameConfig): void {
  const currentDimensions = renderer.getDimensions();
  if (
    currentDimensions.width !== cfg.resolution.width ||
    currentDimensions.height !== cfg.resolution.height
  ) {
    renderer.resize(cfg.resolution.width, cfg.resolution.height);
  }
}

/**
 * SettingsManager class - handles persistence and application of game settings.
 */
export class SettingsManager {
  private config: GameConfig;
  private dirty = false;

  constructor() {
    this.config = this.load();
  }

  /**
   * Get the current configuration.
   */
  getConfig(): GameConfig {
    return { ...this.config };
  }

  /**
   * Get just the key bindings (convenience method).
   */
  getKeyBindings(): KeyBindings {
    return { ...this.config.controls };
  }

  /**
   * Get key bindings for a specific player (P1 or P2).
   * P1 uses controls, P2 uses controlsP2 with fallback to defaults.
   */
  getKeyBindingsForPlayer(playerIndex: number): KeyBindings {
    if (playerIndex === 0) {
      return { ...this.config.controls };
    }
    // P2 uses controlsP2 if set, otherwise defaults
    return { ...(this.config.controlsP2 ?? DEFAULT_KEY_BINDINGS_P2) };
  }

  /**
   * Set the entire configuration (replaces current config).
   * Validates and persists automatically.
   */
  setConfig(next: GameConfig): void {
    this.config = validateGameConfig(next);
    this.dirty = true;
    this.save();
  }

  /**
   * Update configuration with partial changes (merges with current config).
   * Validates and persists automatically.
   */
  updateConfig(partial: Partial<GameConfig>): void {
    const merged: GameConfig = {
      ...this.config,
      ...partial,
      // Deep merge controls if provided
      controls: partial.controls
        ? { ...this.config.controls, ...partial.controls }
        : this.config.controls,
    };
    this.config = validateGameConfig(merged);
    this.dirty = true;
    this.save();
  }

  /**
   * Update a specific key binding.
   */
  updateKeyBinding(action: keyof KeyBindings, keyCode: string): void {
    this.config.controls[action] = keyCode;
    this.dirty = true;
    this.save();
  }

  /**
   * Reset to default settings.
   */
  reset(): void {
    this.config = { ...DEFAULT_GAME_CONFIG };
    this.dirty = true;
    this.save();
  }

  /**
   * Apply current settings to audio and renderer.
   */
  applySettings(audio: AudioManager, renderer: Renderer): void {
    applyAudioSettings(audio, this.config);
    applyRendererSettings(renderer, this.config);
  }

  /**
   * Load settings from localStorage.
   */
  private load(): GameConfig {
    try {
      const stored = localStorage.getItem(SETTINGS_STORAGE_KEY);
      if (stored) {
        const parsed = JSON.parse(stored) as SettingsEnvelope;
        return this.migrate(parsed);
      }
    } catch (error) {
      console.warn('Failed to load settings:', error);
    }
    return { ...DEFAULT_GAME_CONFIG };
  }

  /**
   * Migrate old save data to current version.
   */
  private migrate(data: Partial<SettingsEnvelope>): GameConfig {
    const version = data.version ?? 0;

    if (version < SETTINGS_VERSION) {
      console.log(`Migrating settings from version ${version} to ${SETTINGS_VERSION}`);
    }

    // Always validate to ensure defaults fill missing fields
    return validateGameConfig(data.config ?? {});
  }

  /**
   * Save settings to localStorage.
   */
  save(): void {
    if (!this.dirty) return;

    try {
      const envelope: SettingsEnvelope = {
        version: SETTINGS_VERSION,
        config: this.config,
      };
      localStorage.setItem(SETTINGS_STORAGE_KEY, JSON.stringify(envelope));
      this.dirty = false;
    } catch (error) {
      console.warn('Failed to save settings:', error);
    }
  }

  /**
   * Force save even if not dirty.
   */
  forceSave(): void {
    this.dirty = true;
    this.save();
  }

  /**
   * Get the default configuration (static utility).
   */
  static getDefaults(): GameConfig {
    return { ...DEFAULT_GAME_CONFIG };
  }

  /**
   * Get valid resolution presets.
   */
  static getValidResolutions(): ReadonlyArray<{ width: number; height: number }> {
    return VALID_RESOLUTIONS;
  }
}
