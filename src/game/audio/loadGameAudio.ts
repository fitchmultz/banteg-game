/**
 * Game Audio Loader
 *
 * Loads all game audio assets after user gesture.
 * Uses single-flight pattern to ensure multiple callers share one load operation.
 *
 * Responsibilities:
 * - Load all SFX samples and music tracks
 * - Handle asset loading failures gracefully
 * - Use import.meta.env.BASE_URL for correct path resolution (GitHub Pages compatible)
 *
 * Non-goals:
 * - Does NOT initialize AudioContext (caller must do that first)
 * - Does NOT play sounds
 */

import type { AudioManager } from '../../engine';
import { ALL_SFX_SAMPLES, ALL_TUNES, type SampleName, type TuneName } from './catalog';

export interface LoadResult {
  /** Successfully loaded sample names */
  loadedSamples: SampleName[];
  /** Successfully loaded tune names */
  loadedTunes: TuneName[];
  /** Failed loads with error details */
  failures: Array<{ name: string; type: 'sample' | 'tune'; error: Error }>;
  /** True if all assets loaded successfully */
  success: boolean;
}

/** Internal loading state */
interface LoadState {
  promise: Promise<LoadResult> | null;
  completed: boolean;
  result: LoadResult | null;
}

const loadState: LoadState = {
  promise: null,
  completed: false,
  result: null,
};

/**
 * Build a URL for an audio asset, respecting the base path.
 * Works correctly with GitHub Pages base: '/crimsonland-remake/'
 */
// eslint-disable-next-line @typescript-eslint/no-explicit-any
const VITE_BASE_URL = (import.meta as { env?: Record<string, string> }).env?.BASE_URL ?? '/';

function buildAssetUrl(path: string): string {
  // Ensure base ends with / and path doesn't start with /
  const normalizedBase = VITE_BASE_URL.endsWith('/') ? VITE_BASE_URL : `${VITE_BASE_URL}/`;
  const normalizedPath = path.startsWith('/') ? path.slice(1) : path;
  return `${normalizedBase}${normalizedPath}`;
}

/**
 * Load a single sample, returning success/failure.
 */
async function loadSampleSafe(
  audio: AudioManager,
  name: SampleName
): Promise<{ success: boolean; error?: Error }> {
  try {
    const url = buildAssetUrl(`assets/audio/sfx/${name}.wav`);
    await audio.loadSample(name, url);
    return { success: true };
  } catch (error) {
    return {
      success: false,
      error: error instanceof Error ? error : new Error(String(error)),
    };
  }
}

/**
 * Load a single tune, returning success/failure.
 */
async function loadTuneSafe(
  audio: AudioManager,
  name: TuneName
): Promise<{ success: boolean; error?: Error }> {
  try {
    const url = buildAssetUrl(`assets/audio/music/${name}.wav`);
    await audio.loadTune(name, url);
    return { success: true };
  } catch (error) {
    return {
      success: false,
      error: error instanceof Error ? error : new Error(String(error)),
    };
  }
}

/**
 * Internal implementation of game audio loading.
 * Loads all samples and tunes concurrently.
 */
async function doLoadGameAudio(audio: AudioManager): Promise<LoadResult> {
  const result: LoadResult = {
    loadedSamples: [],
    loadedTunes: [],
    failures: [],
    success: false,
  };

  // Load all SFX samples
  const sampleResults = await Promise.all(
    ALL_SFX_SAMPLES.map(async (name) => {
      const { success, error } = await loadSampleSafe(audio, name);
      return { name, success, error, type: 'sample' as const };
    })
  );

  // Load all music tracks
  const tuneResults = await Promise.all(
    ALL_TUNES.map(async (name) => {
      const { success, error } = await loadTuneSafe(audio, name);
      return { name, success, error, type: 'tune' as const };
    })
  );

  // Process results
  for (const r of sampleResults) {
    if (r.success) {
      result.loadedSamples.push(r.name as SampleName);
    } else if (r.error) {
      result.failures.push({
        name: r.name,
        type: 'sample',
        error: r.error,
      });
    }
  }

  for (const r of tuneResults) {
    if (r.success) {
      result.loadedTunes.push(r.name as TuneName);
    } else if (r.error) {
      result.failures.push({
        name: r.name,
        type: 'tune',
        error: r.error,
      });
    }
  }

  result.success = result.failures.length === 0;

  // Log results
  console.log(
    `[Audio] Loaded ${result.loadedSamples.length} samples, ${result.loadedTunes.length} tunes`
  );
  if (result.failures.length > 0) {
    console.warn(`[Audio] ${result.failures.length} assets failed to load:`);
    for (const f of result.failures) {
      console.warn(`  - ${f.type}: ${f.name} (${f.error.message})`);
    }
  }

  return result;
}

/**
 * Load all game audio assets.
 *
 * This function is single-flight: multiple concurrent calls will share
 * the same Promise and result. Safe to call multiple times.
 *
 * Must be called after AudioManager.initialize() and after a user gesture.
 *
 * @param audio The AudioManager instance to load assets into
 * @returns Promise resolving to load results
 */
export async function loadGameAudio(audio: AudioManager): Promise<LoadResult> {
  // Return cached result if already completed
  if (loadState.completed && loadState.result) {
    return loadState.result;
  }

  // Return existing promise if load is in progress
  if (loadState.promise) {
    return loadState.promise;
  }

  // Start new load
  loadState.promise = doLoadGameAudio(audio).then((result) => {
    loadState.completed = true;
    loadState.result = result;
    return result;
  });

  return loadState.promise;
}

/**
 * Check if game audio has been loaded.
 */
export function isGameAudioLoaded(): boolean {
  return loadState.completed;
}

/**
 * Get the last load result, or null if not loaded yet.
 */
export function getLastLoadResult(): LoadResult | null {
  return loadState.result;
}

/**
 * Reset the load state (useful for testing).
 */
export function resetLoadState(): void {
  loadState.promise = null;
  loadState.completed = false;
  loadState.result = null;
}
