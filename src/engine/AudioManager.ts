/**
 * Audio Manager
 * 
 * Replacement for grim.dll's DirectSound wrapper.
 * Uses Web Audio API for SFX and music playback.
 */

import type { AudioSample, AudioTrack } from '../types';

export interface AudioManagerOptions {
  sfxVolume?: number;
  musicVolume?: number;
  maxConcurrentSfx?: number;
}

export class AudioManager {
  private ctx: AudioContext | null = null;
  private samples: Map<string, AudioSample> = new Map();
  private tracks: Map<string, AudioTrack> = new Map();
  private sfxVolume = 1.0;
  private musicVolume = 1.0;
  private maxConcurrentSfx: number;
  private activeSfx: AudioBufferSourceNode[] = [];

  constructor(options: AudioManagerOptions = {}) {
    this.sfxVolume = options.sfxVolume ?? 1.0;
    this.musicVolume = options.musicVolume ?? 1.0;
    this.maxConcurrentSfx = options.maxConcurrentSfx ?? 32;
  }

  async initialize(): Promise<void> {
    if (this.ctx) return;

    const AudioContextClass = window.AudioContext || 
      (window as unknown as { webkitAudioContext: typeof AudioContext }).webkitAudioContext;
    
    if (!AudioContextClass) {
      console.warn('Web Audio API not supported');
      return;
    }

    this.ctx = new AudioContextClass();
    
    if (this.ctx.state === 'suspended') {
      await this.ctx.resume();
    }
  }

  async loadSample(name: string, url: string): Promise<void> {
    if (!this.ctx) {
      await this.initialize();
    }

    if (!this.ctx) {
      throw new Error('Audio context not available');
    }

    try {
      const response = await fetch(url);
      const arrayBuffer = await response.arrayBuffer();
      const audioBuffer = await this.ctx.decodeAudioData(arrayBuffer);
      
      this.samples.set(name, { name, buffer: audioBuffer });
    } catch (error) {
      console.error(`Failed to load sample: ${name}`, error);
    }
  }

  playSample(name: string, volume = 1.0, pan = 0): void {
    if (!this.ctx) return;

    const sample = this.samples.get(name);
    if (!sample) {
      console.warn(`Sample not found: ${name}`);
      return;
    }

    if (this.activeSfx.length >= this.maxConcurrentSfx) {
      const oldSource = this.activeSfx.shift();
      oldSource?.stop();
    }

    const source = this.ctx.createBufferSource();
    source.buffer = sample.buffer;

    const gainNode = this.ctx.createGain();
    gainNode.gain.value = volume * this.sfxVolume;

    const panner = this.ctx.createStereoPanner();
    panner.pan.value = pan;

    source.connect(panner);
    panner.connect(gainNode);
    gainNode.connect(this.ctx.destination);

    this.activeSfx.push(source);
    source.onended = () => {
      const index = this.activeSfx.indexOf(source);
      if (index > -1) {
        this.activeSfx.splice(index, 1);
      }
    };

    source.start();
  }

  playSamplePanned(name: string, x: number, screenWidth: number): void {
    const pan = (x / screenWidth) * 2 - 1;
    this.playSample(name, 1.0, pan);
  }

  async loadTune(name: string, url: string): Promise<void> {
    if (!this.ctx) {
      await this.initialize();
    }

    if (!this.ctx) {
      throw new Error('Audio context not available');
    }

    try {
      const response = await fetch(url);
      const arrayBuffer = await response.arrayBuffer();
      const audioBuffer = await this.ctx.decodeAudioData(arrayBuffer);

      const gainNode = this.ctx.createGain();
      gainNode.gain.value = this.musicVolume;
      gainNode.connect(this.ctx.destination);

      this.tracks.set(name, {
        name,
        source: null,
        gainNode,
        loop: false,
      });

      this.samples.set(name, { name, buffer: audioBuffer });
    } catch (error) {
      console.error(`Failed to load tune: ${name}`, error);
    }
  }

  playTune(name: string, loop = true): void {
    if (!this.ctx) return;

    const track = this.tracks.get(name);
    const sample = this.samples.get(name);
    
    if (!track || !sample) {
      console.warn(`Track not found: ${name}`);
      return;
    }

    this.stopTune(name);

    const source = this.ctx.createBufferSource();
    source.buffer = sample.buffer;
    source.loop = loop;

    source.connect(track.gainNode);

    track.source = source;
    track.loop = loop;

    source.start();
  }

  stopTune(name: string): void {
    const track = this.tracks.get(name);
    if (track?.source) {
      try {
        track.source.stop();
      } catch {
        // Ignore if already stopped
      }
      track.source = null;
    }
  }

  muteTune(name: string): void {
    const track = this.tracks.get(name);
    if (track) {
      track.gainNode.gain.value = 0;
    }
  }

  unmuteTune(name: string): void {
    const track = this.tracks.get(name);
    if (track) {
      track.gainNode.gain.value = this.musicVolume;
    }
  }

  stopAllMusic(): void {
    for (const name of this.tracks.keys()) {
      this.stopTune(name);
    }
  }

  setSfxVolume(volume: number): void {
    this.sfxVolume = Math.max(0, Math.min(1, volume));
  }

  setMusicVolume(volume: number): void {
    this.musicVolume = Math.max(0, Math.min(1, volume));
    
    for (const track of this.tracks.values()) {
      track.gainNode.gain.value = this.musicVolume;
    }
  }

  muteAll(): void {
    if (this.ctx) {
      this.ctx.suspend();
    }
  }

  unmuteAll(): void {
    if (this.ctx) {
      this.ctx.resume();
    }
  }

  get isInitialized(): boolean {
    return this.ctx !== null;
  }

  getSfxVolume(): number {
    return this.sfxVolume;
  }

  getMusicVolume(): number {
    return this.musicVolume;
  }

  destroy(): void {
    this.stopAllMusic();
    
    for (const source of this.activeSfx) {
      source.stop();
    }
    this.activeSfx = [];

    this.ctx?.close();
    this.ctx = null;
  }
}
