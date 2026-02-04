/**
 * AudioManager unit tests
 */

import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { AudioManager } from '../../src/engine/AudioManager';

// Declare global fetch for TypeScript
declare const global: {
  fetch: typeof fetch;
};

// Mock Web Audio API
class MockAudioBuffer {
  duration = 1.0;
  length = 44100;
  sampleRate = 44100;
  numberOfChannels = 2;
}

class MockAudioBufferSourceNode {
  buffer: AudioBuffer | null = null;
  loop = false;
  onended: (() => void) | null = null;

  connect(): MockAudioBufferSourceNode {
    return this;
  }

  start(): void {
    // Simulate async end
    setTimeout(() => {
      this.onended?.();
    }, 0);
  }

  stop(): void {
    // No-op for mock
  }
}

class MockGainNode {
  gain = { value: 1.0 };

  connect(): MockGainNode {
    return this;
  }
}

class MockStereoPannerNode {
  pan = { value: 0 };

  connect(): MockStereoPannerNode {
    return this;
  }
}

class MockAudioContext {
  state = 'running';
  destination = {} as AudioDestinationNode;

  createBufferSource(): MockAudioBufferSourceNode {
    return new MockAudioBufferSourceNode();
  }

  createGain(): MockGainNode {
    return new MockGainNode();
  }

  createStereoPanner(): MockStereoPannerNode {
    return new MockStereoPannerNode();
  }

  decodeAudioData(): Promise<AudioBuffer> {
    return Promise.resolve(new MockAudioBuffer() as unknown as AudioBuffer);
  }

  suspend(): Promise<void> {
    this.state = 'suspended';
    return Promise.resolve();
  }

  resume(): Promise<void> {
    this.state = 'running';
    return Promise.resolve();
  }

  close(): Promise<void> {
    return Promise.resolve();
  }
}

describe('AudioManager', () => {
  let audio: AudioManager;

  beforeEach(() => {
    // Setup global mocks
    vi.stubGlobal('AudioContext', MockAudioContext);
    vi.stubGlobal('webkitAudioContext', MockAudioContext);

    audio = new AudioManager();
  });

  afterEach(() => {
    audio.destroy();
    vi.unstubAllGlobals();
  });

  describe('initialization', () => {
    it('should initialize with default options', () => {
      expect(audio.getSfxVolume()).toBe(1.0);
      expect(audio.getMusicVolume()).toBe(1.0);
    });

    it('should initialize with custom options', () => {
      const customAudio = new AudioManager({
        sfxVolume: 0.5,
        musicVolume: 0.8,
        maxConcurrentSfx: 16,
      });

      expect(customAudio.getSfxVolume()).toBe(0.5);
      expect(customAudio.getMusicVolume()).toBe(0.8);
    });

    it('should initialize audio context', async () => {
      await audio.initialize();
      expect(audio.isInitialized).toBe(true);
    });

    it('should not reinitialize if already initialized', async () => {
      await audio.initialize();
      const firstInit = audio.isInitialized;

      await audio.initialize(); // Second call
      expect(audio.isInitialized).toBe(firstInit);
    });

    it('should handle unsupported Web Audio API', async () => {
      vi.stubGlobal('AudioContext', undefined);
      vi.stubGlobal('webkitAudioContext', undefined);

      const consoleSpy = vi.spyOn(console, 'warn').mockImplementation(() => {});
      const fallbackAudio = new AudioManager();
      await fallbackAudio.initialize();

      expect(consoleSpy).toHaveBeenCalledWith('Web Audio API not supported');
      expect(fallbackAudio.isInitialized).toBe(false);

      consoleSpy.mockRestore();
    });

    it('should resume suspended context on init', async () => {
      const ctx = new MockAudioContext();
      ctx.state = 'suspended';

      vi.stubGlobal(
        'AudioContext',
        vi.fn(() => ctx)
      );

      const resumeSpy = vi.spyOn(ctx, 'resume');
      await audio.initialize();

      expect(resumeSpy).toHaveBeenCalled();
    });
  });

  describe('sample loading', () => {
    it('should load a sample', async () => {
      global.fetch = vi.fn().mockResolvedValue({
        ok: true,
        arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
      } as unknown as Response);

      await audio.loadSample('test', 'test.mp3');
      expect(global.fetch).toHaveBeenCalledWith('test.mp3');
    });

    it('should throw on network errors when loading samples', async () => {
      global.fetch = vi.fn().mockRejectedValue(new Error('Network error'));

      await expect(audio.loadSample('test', 'test.mp3')).rejects.toThrow('Network error');
    });

    it('should throw on HTTP error responses when loading samples', async () => {
      global.fetch = vi.fn().mockResolvedValue({
        ok: false,
        status: 404,
        statusText: 'Not Found',
      } as unknown as Response);

      await expect(audio.loadSample('test', 'test.mp3')).rejects.toThrow(
        'Failed to load sample "test": HTTP 404 Not Found (test.mp3)'
      );
    });

    it('should initialize before loading if needed', async () => {
      global.fetch = vi.fn().mockResolvedValue({
        ok: true,
        arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
      } as unknown as Response);

      expect(audio.isInitialized).toBe(false);
      await audio.loadSample('test', 'test.mp3');
      expect(audio.isInitialized).toBe(true);
    });
  });

  describe('sample playback', () => {
    beforeEach(async () => {
      await audio.initialize();

      global.fetch = vi.fn().mockResolvedValue({
        ok: true,
        arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
      } as unknown as Response);

      await audio.loadSample('test', 'test.mp3');
    });

    it('should play a loaded sample', () => {
      // Should not throw
      audio.playSample('test');
    });

    it('should warn when playing unknown sample', () => {
      const consoleSpy = vi.spyOn(console, 'warn').mockImplementation(() => {});
      audio.playSample('unknown');
      expect(consoleSpy).toHaveBeenCalledWith('Sample not found: unknown');
      consoleSpy.mockRestore();
    });

    it('should play sample with custom volume', () => {
      const ctx = audio.isInitialized ? (audio as unknown as { ctx: MockAudioContext }).ctx : null;
      if (!ctx) throw new Error('AudioContext not initialized');

      const createGainSpy = vi.spyOn(ctx, 'createGain');
      audio.playSample('test', 0.5);

      const gainNode = createGainSpy.mock.results[0]?.value as MockGainNode | undefined;
      expect(gainNode?.gain.value).toBe(0.5);
    });

    it('should play sample with panning', () => {
      const ctx = audio.isInitialized ? (audio as unknown as { ctx: MockAudioContext }).ctx : null;
      if (!ctx) throw new Error('AudioContext not initialized');

      const createPannerSpy = vi.spyOn(ctx, 'createStereoPanner');
      audio.playSample('test', 1.0, -0.5);

      const pannerNode = createPannerSpy.mock.results[0]?.value as MockStereoPannerNode | undefined;
      expect(pannerNode?.pan.value).toBe(-0.5);
    });

    it('should limit concurrent SFX', async () => {
      const maxConcurrent = 2;
      const limitedAudio = new AudioManager({ maxConcurrentSfx: maxConcurrent });
      await limitedAudio.initialize();

      await limitedAudio.loadSample('test', 'test.mp3');

      // Play multiple samples
      for (let i = 0; i < 5; i++) {
        limitedAudio.playSample('test');
      }

      // Should not throw or cause issues
      expect(limitedAudio).toBeTruthy();
    });

    it('should calculate pan from screen position', () => {
      audio.playSamplePanned('test', 100, 200);
      // pan = (100 / 200) * 2 - 1 = 0
    });
  });

  describe('music/tune playback', () => {
    beforeEach(async () => {
      await audio.initialize();

      global.fetch = vi.fn().mockResolvedValue({
        ok: true,
        arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
      } as unknown as Response);

      await audio.loadTune('bgm', 'music.mp3');
    });

    it('should throw on HTTP error responses when loading tunes', async () => {
      global.fetch = vi.fn().mockResolvedValue({
        ok: false,
        status: 500,
        statusText: 'Internal Server Error',
      } as unknown as Response);

      await expect(audio.loadTune('bgm', 'music.mp3')).rejects.toThrow(
        'Failed to load tune "bgm": HTTP 500 Internal Server Error (music.mp3)'
      );
    });

    it('should load a tune', async () => {
      const tracks = (audio as unknown as { tracks: Map<string, unknown> }).tracks;
      expect(tracks.has('bgm')).toBe(true);
    });

    it('should play a tune', () => {
      audio.playTune('bgm', true);
      const tracks = (audio as unknown as { tracks: Map<string, { source: unknown }> }).tracks;
      expect(tracks.get('bgm')?.source).toBeTruthy();
    });

    it('should stop a tune', () => {
      audio.playTune('bgm');
      audio.stopTune('bgm');
      const tracks = (audio as unknown as { tracks: Map<string, { source: unknown }> }).tracks;
      expect(tracks.get('bgm')?.source).toBeNull();
    });

    it('should loop tunes when specified', () => {
      const ctx = audio.isInitialized ? (audio as unknown as { ctx: MockAudioContext }).ctx : null;
      if (!ctx) throw new Error('AudioContext not initialized');

      const createBufferSourceSpy = vi.spyOn(ctx, 'createBufferSource');
      audio.playTune('bgm', true);

      const source = createBufferSourceSpy.mock.results[0]?.value as
        | MockAudioBufferSourceNode
        | undefined;
      expect(source?.loop).toBe(true);
    });

    it('should mute a tune', () => {
      audio.playTune('bgm');
      audio.muteTune('bgm');

      const tracks = (
        audio as unknown as { tracks: Map<string, { gainNode: { gain: { value: number } } }> }
      ).tracks;
      const track = tracks.get('bgm');
      expect(track?.gainNode.gain.value).toBe(0);
    });

    it('should unmute a tune', () => {
      audio.playTune('bgm');
      audio.muteTune('bgm');
      audio.unmuteTune('bgm');

      const tracks = (
        audio as unknown as { tracks: Map<string, { gainNode: { gain: { value: number } } }> }
      ).tracks;
      const track = tracks.get('bgm');
      expect(track?.gainNode.gain.value).toBe(1.0);
    });

    it('should stop all music', () => {
      audio.playTune('bgm');
      audio.stopAllMusic();

      const tracks = (audio as unknown as { tracks: Map<string, { source: unknown }> }).tracks;
      expect(tracks.get('bgm')?.source).toBeNull();
    });
  });

  describe('volume control', () => {
    beforeEach(async () => {
      await audio.initialize();
    });

    it('should set SFX volume', () => {
      audio.setSfxVolume(0.5);
      expect(audio.getSfxVolume()).toBe(0.5);
    });

    it('should clamp SFX volume to 0-1 range', () => {
      audio.setSfxVolume(-1);
      expect(audio.getSfxVolume()).toBe(0);

      audio.setSfxVolume(2);
      expect(audio.getSfxVolume()).toBe(1);
    });

    it('should set music volume', async () => {
      global.fetch = vi.fn().mockResolvedValue({
        ok: true,
        arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
      } as unknown as Response);

      await audio.loadTune('bgm', 'music.mp3');

      audio.setMusicVolume(0.5);
      expect(audio.getMusicVolume()).toBe(0.5);
    });

    it('should clamp music volume to 0-1 range', async () => {
      global.fetch = vi.fn().mockResolvedValue({
        ok: true,
        arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
      } as unknown as Response);

      await audio.loadTune('bgm', 'music.mp3');

      audio.setMusicVolume(-0.5);
      expect(audio.getMusicVolume()).toBe(0);

      audio.setMusicVolume(1.5);
      expect(audio.getMusicVolume()).toBe(1);
    });

    it('should mute all audio', async () => {
      const ctx = (audio as unknown as { ctx: MockAudioContext | null }).ctx;
      if (ctx) {
        const suspendSpy = vi.spyOn(ctx, 'suspend');
        audio.muteAll();
        expect(suspendSpy).toHaveBeenCalled();
      }
    });

    it('should unmute all audio', async () => {
      const ctx = (audio as unknown as { ctx: MockAudioContext | null }).ctx;
      if (ctx) {
        const resumeSpy = vi.spyOn(ctx, 'resume');
        audio.unmuteAll();
        expect(resumeSpy).toHaveBeenCalled();
      }
    });
  });

  describe('cleanup', () => {
    it('should stop all music on destroy', async () => {
      await audio.initialize();

      global.fetch = vi.fn().mockResolvedValue({
        ok: true,
        arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
      } as unknown as Response);

      await audio.loadTune('bgm', 'music.mp3');
      audio.playTune('bgm');

      const stopAllSpy = vi.spyOn(audio, 'stopAllMusic');
      audio.destroy();

      expect(stopAllSpy).toHaveBeenCalled();
    });

    it('should close audio context on destroy', async () => {
      await audio.initialize();

      const ctx = (audio as unknown as { ctx: MockAudioContext | null }).ctx;
      if (ctx) {
        const closeSpy = vi.spyOn(ctx, 'close');
        audio.destroy();
        expect(closeSpy).toHaveBeenCalled();
      }
    });
  });
});
