/**
 * SeededRNG - Seedable Random Number Generator for Deterministic Replays
 *
 * Uses mulberry32 algorithm - fast, decent quality, seedable.
 * This allows tests to produce identical random sequences for reproducibility.
 */

import { vi } from 'vitest';

export class SeededRNG {
  private state: number;

  constructor(seed: number) {
    this.state = seed >>> 0; // Ensure unsigned 32-bit
  }

  /**
   * Get next random number in [0, 1) range
   */
  next(): number {
    // mulberry32 algorithm
    // biome-ignore lint/suspicious/noAssignInExpressions: Required by mulberry32 algorithm
    let t = (this.state += 0x6d2b79f5);
    t = Math.imul(t ^ (t >>> 15), t | 1);
    t ^= t + Math.imul(t ^ (t >>> 7), t | 61);
    return ((t ^ (t >>> 14)) >>> 0) / 4294967296;
  }

  /**
   * Get random integer in [min, max) range
   */
  nextInt(min: number, max: number): number {
    return Math.floor(this.next() * (max - min)) + min;
  }

  /**
   * Get random float in [min, max) range
   */
  nextFloat(min: number, max: number): number {
    return this.next() * (max - min) + min;
  }

  /**
   * Reset to initial seed state
   */
  reset(seed: number): void {
    this.state = seed >>> 0;
  }

  /**
   * Get current state (for saving)
   */
  getState(): number {
    return this.state;
  }

  /**
   * Set state (for loading)
   */
  setState(state: number): void {
    this.state = state >>> 0;
  }
}

/**
 * Global RNG instance for tests - can be seeded for determinism
 */
export const testRNG = new SeededRNG(12345);

/**
 * Mock Math.random() with seeded RNG
 * Usage: mockRandomWithSeed(12345) in test setup
 */
export function mockRandomWithSeed(seed: number): void {
  testRNG.reset(seed);
  vi.spyOn(Math, 'random').mockImplementation(() => testRNG.next());
}

/**
 * Restore original Math.random()
 * Usage: restoreRandom() in test teardown
 */
export function restoreRandom(): void {
  vi.restoreAllMocks();
}
