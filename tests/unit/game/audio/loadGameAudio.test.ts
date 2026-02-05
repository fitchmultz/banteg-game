/**
 * loadGameAudio unit tests
 */

import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import {
  loadGameAudio,
  isGameAudioLoaded,
  getLastLoadResult,
  resetLoadState,
} from '../../../../src/game/audio/loadGameAudio';
import { ALL_SFX_SAMPLES, ALL_TUNES } from '../../../../src/game/audio/catalog';
import type { AudioManager } from '../../../../src/engine';

// Mock global fetch
declare const global: {
  fetch: typeof fetch;
};

// Mock AudioManager
class MockAudioManager {
  samples = new Map<string, unknown>();
  tunes = new Map<string, unknown>();

  async loadSample(name: string, url: string): Promise<void> {
    const response = await fetch(url);
    if (!response.ok) {
      throw new Error(`Failed to load sample: ${response.status}`);
    }
    this.samples.set(name, { name, url });
  }

  async loadTune(name: string, url: string): Promise<void> {
    const response = await fetch(url);
    if (!response.ok) {
      throw new Error(`Failed to load tune: ${response.status}`);
    }
    this.tunes.set(name, { name, url });
  }

  playSample(): void {
    // No-op
  }

  playTune(): void {
    // No-op
  }

  stopTune(): void {
    // No-op
  }
}

describe('loadGameAudio', () => {
  let audio: MockAudioManager;

  beforeEach(() => {
    resetLoadState();
    audio = new MockAudioManager();
    vi.restoreAllMocks();
  });

  afterEach(() => {
    vi.unstubAllGlobals();
  });

  describe('initial state', () => {
    it('should not be loaded initially', () => {
      expect(isGameAudioLoaded()).toBe(false);
    });

    it('should return null for last load result initially', () => {
      expect(getLastLoadResult()).toBeNull();
    });
  });

  describe('successful loading', () => {
    it('should load all samples and tunes successfully', async () => {
      global.fetch = vi.fn().mockResolvedValue({
        ok: true,
        arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
      } as unknown as Response);

      const result = await loadGameAudio(audio as unknown as AudioManager);

      expect(result.success).toBe(true);
      expect(result.loadedSamples.length).toBe(ALL_SFX_SAMPLES.length);
      expect(result.loadedTunes.length).toBe(ALL_TUNES.length);
      expect(result.failures.length).toBe(0);
    });

    it('should mark as loaded after successful load', async () => {
      global.fetch = vi.fn().mockResolvedValue({
        ok: true,
        arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
      } as unknown as Response);

      await loadGameAudio(audio as unknown as AudioManager);

      expect(isGameAudioLoaded()).toBe(true);
    });

    it('should store load result', async () => {
      global.fetch = vi.fn().mockResolvedValue({
        ok: true,
        arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
      } as unknown as Response);

      const result = await loadGameAudio(audio as unknown as AudioManager);

      expect(getLastLoadResult()).toEqual(result);
    });

    it('should use single-flight pattern for concurrent calls', async () => {
      let callCount = 0;
      global.fetch = vi.fn().mockImplementation(() => {
        callCount++;
        return Promise.resolve({
          ok: true,
          arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
        } as unknown as Response);
      });

      const promise1 = loadGameAudio(audio as unknown as AudioManager);
      const promise2 = loadGameAudio(audio as unknown as AudioManager);

      const [result1, result2] = await Promise.all([promise1, promise2]);

      // Should return the same result object
      expect(result1).toBe(result2);
    });

    it('should return cached result on subsequent calls', async () => {
      global.fetch = vi.fn().mockResolvedValue({
        ok: true,
        arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
      } as unknown as Response);

      const result1 = await loadGameAudio(audio as unknown as AudioManager);

      // Reset fetch to verify cached result is used
      global.fetch = vi.fn().mockRejectedValue(new Error('Should not be called'));

      const result2 = await loadGameAudio(audio as unknown as AudioManager);

      expect(result1).toBe(result2);
    });
  });

  describe('failure handling', () => {
    it('should handle sample load failures gracefully', async () => {
      global.fetch = vi.fn().mockImplementation((url: string) => {
        if (url.includes('weapon_fire_gun')) {
          return Promise.resolve({
            ok: false,
            status: 404,
            statusText: 'Not Found',
          } as unknown as Response);
        }
        return Promise.resolve({
          ok: true,
          arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
        } as unknown as Response);
      });

      const result = await loadGameAudio(audio as unknown as AudioManager);

      expect(result.success).toBe(false);
      expect(result.failures.length).toBeGreaterThan(0);
      expect(result.failures[0]?.name).toBe('weapon_fire_gun');
      expect(result.failures[0]?.type).toBe('sample');
    });

    it('should handle tune load failures gracefully', async () => {
      global.fetch = vi.fn().mockImplementation((url: string) => {
        if (url.includes('music_game_loop')) {
          return Promise.resolve({
            ok: false,
            status: 500,
            statusText: 'Server Error',
          } as unknown as Response);
        }
        return Promise.resolve({
          ok: true,
          arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
        } as unknown as Response);
      });

      const result = await loadGameAudio(audio as unknown as AudioManager);

      expect(result.success).toBe(false);
      const musicFailure = result.failures.find((f) => f.type === 'tune');
      expect(musicFailure).toBeDefined();
      expect(musicFailure?.name).toBe('music_game_loop');
    });

    it('should still return loaded samples even with some failures', async () => {
      global.fetch = vi.fn().mockImplementation((url: string) => {
        // Fail only one sample (use shockwave which is unique)
        if (url.includes('shockwave')) {
          return Promise.resolve({
            ok: false,
            status: 404,
            statusText: 'Not Found',
          } as unknown as Response);
        }
        return Promise.resolve({
          ok: true,
          arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
        } as unknown as Response);
      });

      const result = await loadGameAudio(audio as unknown as AudioManager);

      expect(result.loadedSamples.length).toBe(ALL_SFX_SAMPLES.length - 1);
      expect(result.failures.length).toBe(1);
    });
  });

  describe('resetLoadState', () => {
    it('should reset load state', async () => {
      global.fetch = vi.fn().mockResolvedValue({
        ok: true,
        arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
      } as unknown as Response);

      await loadGameAudio(audio as unknown as AudioManager);
      expect(isGameAudioLoaded()).toBe(true);

      resetLoadState();

      expect(isGameAudioLoaded()).toBe(false);
      expect(getLastLoadResult()).toBeNull();
    });

    it('should allow reloading after reset', async () => {
      global.fetch = vi.fn().mockResolvedValue({
        ok: true,
        arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
      } as unknown as Response);

      await loadGameAudio(audio as unknown as AudioManager);
      resetLoadState();

      // This should trigger a new load, not use cached result
      const fetchSpy = vi.fn().mockResolvedValue({
        ok: true,
        arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
      } as unknown as Response);
      global.fetch = fetchSpy;

      await loadGameAudio(audio as unknown as AudioManager);

      expect(fetchSpy).toHaveBeenCalled();
    });
  });

  describe('URL construction', () => {
    it('should construct correct URLs for assets', async () => {
      const fetchMock = vi.fn().mockResolvedValue({
        ok: true,
        arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
      } as unknown as Response);
      global.fetch = fetchMock;

      await loadGameAudio(audio as unknown as AudioManager);

      // Check that SFX URLs are correct
      const sfxCalls = fetchMock.mock.calls.filter((call) =>
        (call[0] as string).includes('/assets/audio/sfx/')
      );
      expect(sfxCalls.length).toBe(ALL_SFX_SAMPLES.length);

      // Check that music URLs are correct
      const musicCalls = fetchMock.mock.calls.filter((call) =>
        (call[0] as string).includes('/assets/audio/music/')
      );
      expect(musicCalls.length).toBe(ALL_TUNES.length);
    });
  });
});
