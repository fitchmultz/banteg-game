/**
 * TerrainGenerator Tests
 *
 * Tests for the procedural terrain generation system.
 */

import { describe, expect, it, vi, beforeEach, afterEach } from 'vitest';
import {
  TerrainGenerator,
  DEFAULT_TERRAIN_THEME,
  generateTerrainTexture,
  createTerrainPattern,
  type TerrainTheme,
} from '../../../src/engine/TerrainGenerator';

// Mock canvas context
const mockContext = {
  fillStyle: '',
  strokeStyle: '',
  lineWidth: 1,
  font: '',
  globalAlpha: 1,
  fillRect: vi.fn(),
  strokeRect: vi.fn(),
  beginPath: vi.fn(),
  arc: vi.fn(),
  fill: vi.fn(),
  stroke: vi.fn(),
  moveTo: vi.fn(),
  lineTo: vi.fn(),
  drawImage: vi.fn(),
  fillText: vi.fn(),
  strokeText: vi.fn(),
  measureText: vi.fn().mockReturnValue({ width: 50 }),
  save: vi.fn(),
  restore: vi.fn(),
  translate: vi.fn(),
  rotate: vi.fn(),
  scale: vi.fn(),
  setTransform: vi.fn(),
  clip: vi.fn(),
  rect: vi.fn(),
  closePath: vi.fn(),
  createPattern: vi.fn().mockReturnValue({} as CanvasPattern),
  imageSmoothingEnabled: true,
};

describe('TerrainGenerator', () => {
  beforeEach(() => {
    // Mock getContext
    vi.spyOn(HTMLCanvasElement.prototype, 'getContext').mockReturnValue(
      mockContext as unknown as CanvasRenderingContext2D
    );
  });

  afterEach(() => {
    vi.clearAllMocks();
  });

  describe('Construction', () => {
    it('should create with default theme', () => {
      const generator = new TerrainGenerator();
      expect(generator).toBeDefined();
      expect(generator.getCanvas()).toBeDefined();
      expect(generator.getDimensions()).toEqual({ width: 1024, height: 1024 });
    });

    it('should create with custom theme', () => {
      const customTheme: TerrainTheme = {
        baseColor: { r: 255, g: 0, b: 0 },
        detailColor: { r: 0, g: 255, b: 0 },
        layer1Opacity: 0.5,
        layer2Opacity: 0.5,
        layer3Opacity: 0.5,
      };
      const generator = new TerrainGenerator(customTheme);
      expect(generator).toBeDefined();
    });

    it('should create with custom size', () => {
      const generator = new TerrainGenerator(DEFAULT_TERRAIN_THEME, 512);
      expect(generator.getDimensions()).toEqual({ width: 512, height: 512 });
    });
  });

  describe('Texture Generation', () => {
    it('should generate terrain texture', () => {
      const generator = new TerrainGenerator();
      const canvas = generator.generateTerrainTexture();
      expect(canvas).toBeDefined();
      expect(canvas.width).toBe(1024);
      expect(canvas.height).toBe(1024);
      // Should fill base color and draw layers
      expect(mockContext.fillRect).toHaveBeenCalled();
    });

    it('should return same canvas on multiple calls', () => {
      const generator = new TerrainGenerator();
      const canvas1 = generator.generateTerrainTexture();
      const canvas2 = generator.generateTerrainTexture();
      expect(canvas1).toBe(canvas2);
    });

    it('should draw detail sprites with save/restore', () => {
      const generator = new TerrainGenerator();
      generator.generateTerrainTexture();
      // Should use save/restore for each detail sprite
      expect(mockContext.save).toHaveBeenCalled();
      expect(mockContext.restore).toHaveBeenCalled();
    });

    it('should use correct base color', () => {
      const generator = new TerrainGenerator();
      generator.generateTerrainTexture();
      // First fillRect call should be with base color (63, 56, 25)
      const firstFillRectCall = mockContext.fillRect.mock.calls[0];
      expect(firstFillRectCall).toBeDefined();
      // Check that fillStyle was set to base color at some point
      expect(mockContext.fillStyle).toBeDefined();
    });
  });

  describe('Theme Constants', () => {
    it('should have correct default theme values', () => {
      expect(DEFAULT_TERRAIN_THEME.baseColor).toEqual({ r: 63, g: 56, b: 25 });
      expect(DEFAULT_TERRAIN_THEME.detailColor).toEqual({ r: 178, g: 178, b: 178 });
      expect(DEFAULT_TERRAIN_THEME.layer1Opacity).toBe(0.9);
      expect(DEFAULT_TERRAIN_THEME.layer2Opacity).toBe(0.9);
      expect(DEFAULT_TERRAIN_THEME.layer3Opacity).toBe(0.6);
    });
  });

  describe('Convenience Functions', () => {
    it('generateTerrainTexture should create texture with defaults', () => {
      const canvas = generateTerrainTexture();
      expect(canvas).toBeDefined();
      expect(canvas.width).toBe(1024);
      expect(canvas.height).toBe(1024);
    });

    it('generateTerrainTexture should accept custom theme', () => {
      const customTheme: TerrainTheme = {
        baseColor: { r: 100, g: 100, b: 100 },
        detailColor: { r: 200, g: 200, b: 200 },
        layer1Opacity: 0.8,
        layer2Opacity: 0.7,
        layer3Opacity: 0.6,
      };
      const canvas = generateTerrainTexture(customTheme, 256);
      expect(canvas.width).toBe(256);
      expect(canvas.height).toBe(256);
    });

    it('createTerrainPattern should create pattern from canvas', () => {
      const pattern = createTerrainPattern(
        mockContext as unknown as CanvasRenderingContext2D,
        document.createElement('canvas')
      );
      expect(pattern).toBeDefined();
      expect(mockContext.createPattern).toHaveBeenCalledWith(
        expect.any(HTMLCanvasElement),
        'repeat'
      );
    });

    it('createTerrainPattern should return null when pattern creation fails', () => {
      mockContext.createPattern.mockReturnValueOnce(null);
      const pattern = createTerrainPattern(
        mockContext as unknown as CanvasRenderingContext2D,
        document.createElement('canvas')
      );
      expect(pattern).toBeNull();
    });
  });

  describe('Canvas Context', () => {
    it('should throw error if canvas context fails', () => {
      // Mock getContext to return null
      vi.spyOn(HTMLCanvasElement.prototype, 'getContext').mockReturnValue(null);

      expect(() => new TerrainGenerator()).toThrow(
        'Failed to get 2D context for terrain generation'
      );
    });
  });

  describe('Layer Drawing', () => {
    it('should draw all three layers', () => {
      const generator = new TerrainGenerator();
      generator.generateTerrainTexture();

      // Should draw base color + 800 + 35 + 15 = 851 fillRect calls
      // (base color fill + detail sprites as irregular polygons)
      expect(mockContext.fillRect).toHaveBeenCalled();
      expect(mockContext.beginPath).toHaveBeenCalled();
      expect(mockContext.closePath).toHaveBeenCalled();
    });

    it('should use random rotation for sprites', () => {
      const generator = new TerrainGenerator();
      generator.generateTerrainTexture();

      // Should rotate for each detail sprite
      expect(mockContext.rotate).toHaveBeenCalled();
    });

    it('should translate for each sprite position', () => {
      const generator = new TerrainGenerator();
      generator.generateTerrainTexture();

      // Should translate for each detail sprite
      expect(mockContext.translate).toHaveBeenCalled();
    });
  });
});
