/**
 * Math utility tests
 */

import { describe, it, expect } from 'vitest';
import { Vector2, Rectangle, clamp, lerp, randomInt } from '../../src/core/math';

describe('Vector2', () => {
  it('should create a vector with default values', () => {
    const v = new Vector2();
    expect(v.x).toBe(0);
    expect(v.y).toBe(0);
  });

  it('should create a vector with specified values', () => {
    const v = new Vector2(3, 4);
    expect(v.x).toBe(3);
    expect(v.y).toBe(4);
  });

  it('should calculate length correctly', () => {
    const v = new Vector2(3, 4);
    expect(v.length()).toBe(5);
  });

  it('should normalize correctly', () => {
    const v = new Vector2(3, 4);
    v.normalize();
    expect(v.length()).toBeCloseTo(1);
  });

  it('should add vectors correctly', () => {
    const a = new Vector2(1, 2);
    const b = new Vector2(3, 4);
    a.add(b);
    expect(a.x).toBe(4);
    expect(a.y).toBe(6);
  });

  it('should scale correctly', () => {
    const v = new Vector2(2, 3);
    v.scale(2);
    expect(v.x).toBe(4);
    expect(v.y).toBe(6);
  });
});

describe('Rectangle', () => {
  it('should create a rectangle with default values', () => {
    const r = new Rectangle();
    expect(r.x).toBe(0);
    expect(r.y).toBe(0);
    expect(r.width).toBe(0);
    expect(r.height).toBe(0);
  });

  it('should detect point containment', () => {
    const r = new Rectangle(0, 0, 100, 100);
    expect(r.contains(50, 50)).toBe(true);
    expect(r.contains(150, 50)).toBe(false);
    expect(r.contains(50, 150)).toBe(false);
  });

  it('should detect intersections', () => {
    const a = new Rectangle(0, 0, 100, 100);
    const b = new Rectangle(50, 50, 100, 100);
    const c = new Rectangle(200, 200, 100, 100);
    expect(a.intersects(b)).toBe(true);
    expect(a.intersects(c)).toBe(false);
  });
});

describe('Math utilities', () => {
  it('should clamp values correctly', () => {
    expect(clamp(5, 0, 10)).toBe(5);
    expect(clamp(-5, 0, 10)).toBe(0);
    expect(clamp(15, 0, 10)).toBe(10);
  });

  it('should interpolate correctly', () => {
    expect(lerp(0, 10, 0)).toBe(0);
    expect(lerp(0, 10, 1)).toBe(10);
    expect(lerp(0, 10, 0.5)).toBe(5);
  });

  it('should generate random integers in range', () => {
    for (let i = 0; i < 100; i++) {
      const n = randomInt(1, 10);
      expect(n).toBeGreaterThanOrEqual(1);
      expect(n).toBeLessThanOrEqual(10);
    }
  });
});
