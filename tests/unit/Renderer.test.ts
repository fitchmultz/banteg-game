/**
 * Renderer unit tests
 */

import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { Renderer } from '../../src/engine/Renderer';
import type { SpriteFrame } from '../../src/engine/SpriteAtlas';

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
  imageSmoothingEnabled: true,
};

describe('Renderer', () => {
  let container: HTMLDivElement;
  let renderer: Renderer;

  beforeEach(() => {
    container = document.createElement('div');
    document.body.appendChild(container);

    // Mock getContext
    vi.spyOn(HTMLCanvasElement.prototype, 'getContext').mockReturnValue(
      mockContext as unknown as CanvasRenderingContext2D
    );

    renderer = new Renderer(container, { width: 800, height: 600 });
  });

  afterEach(() => {
    renderer.destroy?.();
    container.remove();
    vi.clearAllMocks();
  });

  describe('creation', () => {
    it('should create a canvas element', () => {
      const canvas = container.querySelector('canvas');
      expect(canvas).toBeTruthy();
    });

    it('should set canvas dimensions', () => {
      const dims = renderer.getDimensions();
      expect(dims.width).toBe(800);
      expect(dims.height).toBe(600);
    });

    it('should get the canvas element', () => {
      const canvas = renderer.getCanvas();
      expect(canvas).toBeInstanceOf(HTMLCanvasElement);
    });

    it('should get the 2D context', () => {
      const ctx = renderer.getContext();
      expect(ctx).toBe(mockContext);
    });
  });

  describe('clearing', () => {
    it('should clear with color', () => {
      renderer.clear(1, 0, 0, 1);
      expect(mockContext.fillStyle).toBe('rgba(255, 0, 0, 1)');
      expect(mockContext.fillRect).toHaveBeenCalled();
    });

    it('should clear to black', () => {
      renderer.clearBlack();
      expect(mockContext.fillStyle).toBe('rgba(0, 0, 0, 1)');
    });
  });

  describe('color', () => {
    it('should set color', () => {
      renderer.setColor(1, 0.5, 0, 1);
      expect(mockContext.fillStyle).toBe('rgba(255, 127.5, 0, 1)');
      expect(mockContext.strokeStyle).toBe('rgba(255, 127.5, 0, 1)');
    });
  });

  describe('shapes', () => {
    it('should draw rectangle', () => {
      renderer.drawRect(10, 20, 100, 200);
      expect(mockContext.fillRect).toHaveBeenCalledWith(10, 20, 100, 200);
    });

    it('should draw rectangle outline', () => {
      renderer.drawRectOutline(10, 20, 100, 200, 2);
      expect(mockContext.lineWidth).toBe(2);
      expect(mockContext.strokeRect).toHaveBeenCalledWith(10, 20, 100, 200);
    });

    it('should draw circle', () => {
      renderer.drawCircle(100, 100, 50);
      expect(mockContext.beginPath).toHaveBeenCalled();
      expect(mockContext.arc).toHaveBeenCalledWith(100, 100, 50, 0, Math.PI * 2);
      expect(mockContext.fill).toHaveBeenCalled();
    });

    it('should draw circle outline', () => {
      renderer.drawCircleOutline(100, 100, 50, 3);
      expect(mockContext.lineWidth).toBe(3);
      expect(mockContext.stroke).toHaveBeenCalled();
    });

    it('should draw line', () => {
      renderer.drawLine(0, 0, 100, 100);
      expect(mockContext.beginPath).toHaveBeenCalled();
      expect(mockContext.moveTo).toHaveBeenCalledWith(0, 0);
      expect(mockContext.lineTo).toHaveBeenCalledWith(100, 100);
      expect(mockContext.stroke).toHaveBeenCalled();
    });
  });

  describe('text', () => {
    it('should draw text', () => {
      renderer.drawText('Hello', 10, 20, 16, 'sans-serif');
      expect(mockContext.font).toBe('16px sans-serif');
      expect(mockContext.fillText).toHaveBeenCalledWith('Hello', 10, 20);
    });

    it('should draw outlined text', () => {
      renderer.drawTextOutlined('Hello', 10, 20, 16, 'sans-serif', 2);
      expect(mockContext.lineWidth).toBe(2);
      expect(mockContext.strokeText).toHaveBeenCalledWith('Hello', 10, 20);
      expect(mockContext.fillText).toHaveBeenCalledWith('Hello', 10, 20);
    });

    it('should measure text', () => {
      const width = renderer.measureText('Hello', 16, 'sans-serif');
      expect(mockContext.measureText).toHaveBeenCalledWith('Hello');
      expect(width).toBe(50);
    });
  });

  describe('batch operations', () => {
    it('should begin and end batch', () => {
      renderer.beginBatch();
      expect(mockContext.save).toHaveBeenCalled();

      renderer.endBatch();
      expect(mockContext.restore).toHaveBeenCalled();
    });

    it('should auto-end batch when beginning new one', () => {
      renderer.beginBatch();
      renderer.beginBatch(); // Should auto-end previous
      expect(mockContext.restore).toHaveBeenCalled();
      expect(mockContext.save).toHaveBeenCalledTimes(2);
    });
  });

  describe('state stack', () => {
    it('should push and pop state', () => {
      renderer.pushState();
      expect(mockContext.save).toHaveBeenCalled();

      renderer.setTranslation(100, 100);

      renderer.popState();
      expect(mockContext.restore).toHaveBeenCalled();
    });
  });

  describe('viewport', () => {
    it('should set viewport', () => {
      renderer.setViewport(10, 20, 400, 300);
      const viewport = renderer.getViewport();
      expect(viewport).toEqual({ x: 10, y: 20, width: 400, height: 300 });
    });

    it('should reset viewport', () => {
      renderer.setViewport(10, 20, 400, 300);
      renderer.resetViewport();
      const viewport = renderer.getViewport();
      expect(viewport).toEqual({ x: 0, y: 0, width: 800, height: 600 });
    });
  });

  describe('camera', () => {
    it('should set camera', () => {
      renderer.setCamera(100, 200, 2, Math.PI / 4);
      const camera = renderer.getCamera();
      expect(camera).toEqual({ x: 100, y: 200, zoom: 2, rotation: Math.PI / 4 });
    });

    it('should convert world to screen', () => {
      renderer.setCamera(0, 0, 1, 0);
      const screen = renderer.worldToScreen(100, 100);
      expect(screen.x).toBe(500); // viewport x + width/2 + worldX
      expect(screen.y).toBe(400); // viewport y + height/2 + worldY
    });

    it('should convert screen to world', () => {
      renderer.setCamera(0, 0, 1, 0);
      const world = renderer.screenToWorld(500, 400);
      expect(world.x).toBeCloseTo(100);
      expect(world.y).toBeCloseTo(100);
    });

    it('should apply camera transform', () => {
      renderer.applyCamera();
      expect(mockContext.save).toHaveBeenCalled();
      expect(mockContext.translate).toHaveBeenCalled();
      expect(mockContext.scale).toHaveBeenCalled();
    });

    it('should restore camera transform', () => {
      renderer.applyCamera();
      renderer.restoreCamera();
      expect(mockContext.restore).toHaveBeenCalled();
    });
  });

  describe('sprite drawing', () => {
    it('should draw sprite from frame', () => {
      const mockImage = document.createElement('img');
      const frame: SpriteFrame = {
        name: 'test',
        x: 0,
        y: 0,
        width: 32,
        height: 32,
        uv: { u0: 0, v0: 0, u1: 1, v1: 1 },
      };

      renderer.drawSprite(mockImage, frame, 100, 100, { scale: 2 });

      expect(mockContext.save).toHaveBeenCalled();
      expect(mockContext.translate).toHaveBeenCalledWith(100, 100);
      expect(mockContext.drawImage).toHaveBeenCalled();
      expect(mockContext.restore).toHaveBeenCalled();
    });

    it('should draw sprite with rotation', () => {
      const mockImage = document.createElement('img');
      const frame: SpriteFrame = {
        name: 'test',
        x: 0,
        y: 0,
        width: 32,
        height: 32,
        uv: { u0: 0, v0: 0, u1: 1, v1: 1 },
      };

      renderer.drawSprite(mockImage, frame, 100, 100, { rotation: Math.PI / 2 });

      expect(mockContext.rotate).toHaveBeenCalledWith(Math.PI / 2);
    });

    it('should draw sprite with flip', () => {
      const mockImage = document.createElement('img');
      const frame: SpriteFrame = {
        name: 'test',
        x: 0,
        y: 0,
        width: 32,
        height: 32,
        uv: { u0: 0, v0: 0, u1: 1, v1: 1 },
      };

      renderer.drawSprite(mockImage, frame, 100, 100, { flipX: true, flipY: true });

      expect(mockContext.scale).toHaveBeenCalledWith(-1, -1);
    });
  });

  describe('resize', () => {
    it('should resize canvas', () => {
      renderer.resize(1024, 768);
      const dims = renderer.getDimensions();
      expect(dims.width).toBe(1024);
      expect(dims.height).toBe(768);
    });
  });
});
