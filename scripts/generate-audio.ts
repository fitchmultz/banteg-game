#!/usr/bin/env node
/**
 * Audio Asset Generator
 *
 * Generates minimal WAV audio files for the game using raw PCM data.
 * This ensures license-safe assets that can be committed to the repo.
 *
 * Usage:
 *   npx tsx scripts/generate-audio.ts [options]
 *
 * Options:
 *   --output-dir <path>   Output directory (default: public/assets/audio)
 *   --sfx-only            Generate only SFX files
 *   --music-only          Generate only music files
 *   --help                Show this help message
 *
 * Examples:
 *   npx tsx scripts/generate-audio.ts
 *   npx tsx scripts/generate-audio.ts --output-dir ./dist/audio
 *   npx tsx scripts/generate-audio.ts --sfx-only
 */

import * as fs from 'node:fs';
import * as path from 'node:path';

interface SoundDef {
  name: string;
  type: 'sfx' | 'music';
  duration: number;
  generate: (sampleRate: number, duration: number) => Float32Array;
}

// Utility: Generate tone with frequency sweep
function generateTone(
  sampleRate: number,
  duration: number,
  freqStart: number,
  freqEnd: number,
  type: 'sine' | 'square' | 'sawtooth' | 'noise' = 'sine',
  volume = 0.5
): Float32Array {
  const samples = Math.floor(sampleRate * duration);
  const buffer = new Float32Array(samples);

  for (let i = 0; i < samples; i++) {
    const t = i / sampleRate;
    const progress = i / samples;
    const freq = freqStart + (freqEnd - freqStart) * progress;
    const phase = (t * freq) % 1;

    let sample = 0;
    switch (type) {
      case 'sine':
        sample = Math.sin(phase * Math.PI * 2);
        break;
      case 'square':
        sample = phase < 0.5 ? 1 : -1;
        break;
      case 'sawtooth':
        sample = phase * 2 - 1;
        break;
      case 'noise':
        sample = Math.random() * 2 - 1;
        break;
    }

    // Apply envelope (attack and decay)
    const attack = Math.min(1, t * 100); // 10ms attack
    const decay = Math.exp(-t / (duration * 0.3));
    buffer[i] = sample * volume * attack * decay;
  }

  return buffer;
}

// Utility: Apply lowpass filter (simple)
function applyLowpass(buffer: Float32Array, cutoff: number, sampleRate: number): Float32Array {
  const rc = 1.0 / (2 * Math.PI * cutoff);
  const dt = 1.0 / sampleRate;
  const alpha = dt / (rc + dt);

  const output = new Float32Array(buffer.length);
  output[0] = buffer[0];

  for (let i = 1; i < buffer.length; i++) {
    output[i] = output[i - 1] + alpha * (buffer[i] - output[i - 1]);
  }

  return output;
}

// Utility: Mix multiple buffers
function mixBuffers(buffers: Float32Array[]): Float32Array {
  const maxLength = Math.max(...buffers.map((b) => b.length));
  const output = new Float32Array(maxLength);

  for (const buffer of buffers) {
    for (let i = 0; i < buffer.length; i++) {
      output[i] += buffer[i];
    }
  }

  // Normalize
  const maxAmp = Math.max(...output.map(Math.abs));
  if (maxAmp > 1) {
    for (let i = 0; i < output.length; i++) {
      output[i] /= maxAmp;
    }
  }

  return output;
}

// Sound definitions
const SOUND_DEFS: SoundDef[] = [
  // Weapon fire sounds
  {
    name: 'weapon_fire_gun',
    type: 'sfx',
    duration: 0.15,
    generate: (sr) => {
      const tone = generateTone(sr, 0.1, 800, 100, 'square', 0.3);
      return applyLowpass(tone, 3000, sr);
    },
  },
  {
    name: 'weapon_fire_shotgun',
    type: 'sfx',
    duration: 0.25,
    generate: (sr) => {
      // White noise burst
      const samples = Math.floor(sr * 0.2);
      const noise = new Float32Array(samples);
      for (let i = 0; i < samples; i++) {
        noise[i] = (Math.random() * 2 - 1) * Math.exp(-i / (sr * 0.05)) * 0.5;
      }
      return applyLowpass(noise, 2000, sr);
    },
  },
  {
    name: 'weapon_fire_energy',
    type: 'sfx',
    duration: 0.2,
    generate: (sr) => {
      const tone = generateTone(sr, 0.15, 400, 1200, 'sawtooth', 0.2);
      return applyLowpass(tone, 4000, sr);
    },
  },
  {
    name: 'weapon_reload',
    type: 'sfx',
    duration: 0.4,
    generate: (sr) => {
      const samples = Math.floor(sr * 0.4);
      const buffer = new Float32Array(samples);

      // Sliding tone
      for (let i = 0; i < samples; i++) {
        const t = i / sr;
        const phase = (t * (200 + 100 * Math.sin(t * 15))) % 1;
        const envelope = Math.max(0, 1 - t / 0.35);
        buffer[i] = Math.sin(phase * Math.PI * 2) * 0.2 * envelope;
      }

      return buffer;
    },
  },
  // Hit sounds
  {
    name: 'hit_player',
    type: 'sfx',
    duration: 0.2,
    generate: (sr) => {
      const tone = generateTone(sr, 0.15, 150, 50, 'sawtooth', 0.4);
      return tone;
    },
  },
  {
    name: 'hit_enemy',
    type: 'sfx',
    duration: 0.1,
    generate: (sr) => {
      const tone = generateTone(sr, 0.08, 600, 200, 'square', 0.25);
      return tone;
    },
  },
  // Death sounds
  {
    name: 'death_enemy',
    type: 'sfx',
    duration: 0.3,
    generate: (sr) => {
      const tone = generateTone(sr, 0.25, 300, 30, 'sawtooth', 0.35);
      return tone;
    },
  },
  {
    name: 'death_player',
    type: 'sfx',
    duration: 0.5,
    generate: (sr) => {
      const tone = generateTone(sr, 0.4, 200, 20, 'sawtooth', 0.5);
      return tone;
    },
  },
  // Pickup sounds
  {
    name: 'pickup_bonus',
    type: 'sfx',
    duration: 0.3,
    generate: (sr) => {
      const samples = Math.floor(sr * 0.3);
      const buffer = new Float32Array(samples);

      // Arpeggio: C5 - E5 - G5
      const notes = [523.25, 659.25, 783.99];
      for (let n = 0; n < notes.length; n++) {
        const startSample = Math.floor(n * sr * 0.08);
        const endSample = Math.min(samples, startSample + Math.floor(sr * 0.15));
        for (let i = startSample; i < endSample; i++) {
          const t = (i - startSample) / sr;
          const envelope = Math.max(0, 1 - t / 0.12);
          buffer[i] += Math.sin(((t * notes[n]) % 1) * Math.PI * 2) * 0.15 * envelope;
        }
      }

      return buffer;
    },
  },
  {
    name: 'pickup_weapon',
    type: 'sfx',
    duration: 0.25,
    generate: (sr) => {
      const tone = generateTone(sr, 0.2, 330, 660, 'square', 0.25);
      return tone;
    },
  },
  // Explosion
  {
    name: 'explosion',
    type: 'sfx',
    duration: 0.4,
    generate: (sr) => {
      const samples = Math.floor(sr * 0.35);
      const noise = new Float32Array(samples);
      for (let i = 0; i < samples; i++) {
        noise[i] = (Math.random() * 2 - 1) * Math.exp(-i / (sr * 0.08)) * 0.6;
      }
      return applyLowpass(noise, 1500, sr);
    },
  },
  // Music loop
  {
    name: 'music_game_loop',
    type: 'music',
    duration: 8.0,
    generate: (sr) => {
      const samples = Math.floor(sr * 8);
      const buffer = new Float32Array(samples);

      // Simple ambient pattern
      const bassFreq = 55; // A1
      const beatSamples = Math.floor(sr * 0.5); // 120 BPM

      for (let beat = 0; beat < 16; beat++) {
        const startSample = beat * beatSamples;
        const endSample = Math.min(samples, startSample + beatSamples);

        // Bass every 4 beats
        if (beat % 4 === 0) {
          for (let i = startSample; i < Math.min(samples, startSample + beatSamples * 1.5); i++) {
            const t = (i - startSample) / sr;
            const envelope = Math.exp(-t / 0.3);
            buffer[i] += Math.sin(((t * bassFreq) % 1) * Math.PI * 2) * 0.2 * envelope;
          }
        }

        // Light melody on even beats
        if (beat % 2 === 0) {
          const melodyFreq = [110, 130.81, 146.83, 164.81][beat % 4];
          for (let i = startSample; i < endSample; i++) {
            const t = (i - startSample) / sr;
            const envelope = Math.exp(-t / 0.2) * 0.5;
            buffer[i] += Math.sin(((t * melodyFreq) % 1) * Math.PI * 2) * 0.15 * envelope;
          }
        }
      }

      return buffer;
    },
  },
];

/**
 * Convert Float32Array to WAV format and write to file
 */
async function writeWav(buffer: Float32Array, filepath: string, sampleRate = 44100): Promise<void> {
  const numChannels = 1;
  const format = 1; // PCM
  const bitDepth = 16;
  const bytesPerSample = bitDepth / 8;
  const blockAlign = numChannels * bytesPerSample;
  const byteRate = sampleRate * blockAlign;
  const dataLength = buffer.length * blockAlign;
  const headerLength = 44;
  const totalLength = headerLength + dataLength;

  const arrayBuffer = new ArrayBuffer(totalLength);
  const view = new DataView(arrayBuffer);
  let offset = 0;

  // Write string helper
  const writeString = (str: string) => {
    for (let i = 0; i < str.length; i++) {
      view.setUint8(offset++, str.charCodeAt(i));
    }
  };

  // RIFF chunk
  writeString('RIFF');
  view.setUint32(offset, totalLength - 8, true);
  offset += 4;
  writeString('WAVE');

  // fmt chunk
  writeString('fmt ');
  view.setUint32(offset, 16, true);
  offset += 4;
  view.setUint16(offset, format, true);
  offset += 2;
  view.setUint16(offset, numChannels, true);
  offset += 2;
  view.setUint32(offset, sampleRate, true);
  offset += 4;
  view.setUint32(offset, byteRate, true);
  offset += 4;
  view.setUint16(offset, blockAlign, true);
  offset += 2;
  view.setUint16(offset, bitDepth, true);
  offset += 2;

  // data chunk
  writeString('data');
  view.setUint32(offset, dataLength, true);
  offset += 4;

  // Write samples
  for (let i = 0; i < buffer.length; i++) {
    const sample = Math.max(-1, Math.min(1, buffer[i]));
    view.setInt16(offset, sample < 0 ? sample * 0x8000 : sample * 0x7fff, true);
    offset += 2;
  }

  // Write to file
  fs.writeFileSync(filepath, Buffer.from(arrayBuffer));
}

/**
 * Generate a single sound
 */
async function generateSound(def: SoundDef, outputDir: string): Promise<void> {
  const sampleRate = 44100;
  const buffer = def.generate(sampleRate, def.duration);
  const subDir = def.type === 'sfx' ? 'sfx' : 'music';
  const filepath = path.join(outputDir, subDir, `${def.name}.wav`);
  await writeWav(buffer, filepath, sampleRate);
  console.log(`Generated: ${filepath}`);
}

/**
 * Parse command line arguments
 */
function parseArgs(): { outputDir: string; sfxOnly: boolean; musicOnly: boolean; help: boolean } {
  const args = process.argv.slice(2);
  let outputDir = 'public/assets/audio';
  let sfxOnly = false;
  let musicOnly = false;
  let help = false;

  for (let i = 0; i < args.length; i++) {
    switch (args[i]) {
      case '--output-dir':
        outputDir = args[++i] ?? outputDir;
        break;
      case '--sfx-only':
        sfxOnly = true;
        break;
      case '--music-only':
        musicOnly = true;
        break;
      case '--help':
      case '-h':
        help = true;
        break;
    }
  }

  return { outputDir, sfxOnly, musicOnly, help };
}

/**
 * Print help message
 */
function printHelp(): void {
  console.log(`
Audio Asset Generator

Generates minimal WAV audio files for the game using raw PCM data.
This ensures license-safe assets that can be committed to the repo.

Usage:
  npx tsx scripts/generate-audio.ts [options]

Options:
  --output-dir <path>   Output directory (default: public/assets/audio)
  --sfx-only            Generate only SFX files
  --music-only          Generate only music files
  --help, -h            Show this help message

Examples:
  npx tsx scripts/generate-audio.ts
  npx tsx scripts/generate-audio.ts --output-dir ./dist/audio
  npx tsx scripts/generate-audio.ts --sfx-only
`);
}

/**
 * Main function
 */
async function main(): Promise<void> {
  const { outputDir, sfxOnly, musicOnly, help } = parseArgs();

  if (help) {
    printHelp();
    process.exit(0);
  }

  // Create directories
  fs.mkdirSync(path.join(outputDir, 'sfx'), { recursive: true });
  fs.mkdirSync(path.join(outputDir, 'music'), { recursive: true });

  // Filter sounds based on flags
  let sounds = SOUND_DEFS;
  if (sfxOnly) {
    sounds = sounds.filter((s) => s.type === 'sfx');
  } else if (musicOnly) {
    sounds = sounds.filter((s) => s.type === 'music');
  }

  console.log(`Generating ${sounds.length} audio files to ${outputDir}...`);

  for (const def of sounds) {
    try {
      await generateSound(def, outputDir);
    } catch (error) {
      console.error(`Failed to generate ${def.name}:`, error);
      process.exit(1);
    }
  }

  console.log('Done!');
}

main();
