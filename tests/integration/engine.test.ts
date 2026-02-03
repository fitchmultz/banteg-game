/**
 * Engine integration tests
 *
 * Tests interaction between engine subsystems.
 */

import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { Renderer } from '../../src/engine/Renderer';
import { AssetManager } from '../../src/engine/AssetManager';
import { SpriteAtlas } from '../../src/engine/SpriteAtlas';
import { InputManager } from '../../src/engine/InputManager';
import { AudioManager } from '../../src/engine/AudioManager';
import { GameLoop } from '../../src/core/GameLoop';
import { EntityManager, System, SystemManager } from '../../src/core/ecs';
import type { Component } from '../../src/types';

// Declare global for TypeScript
declare const global: {
  fetch: typeof fetch;
};

// Mock canvas context - create fresh one for each test
function createMockContext() {
  return {
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
}

let mockContext = createMockContext();

// Time tracking for mocks - start at non-zero to avoid first-frame special case
let mockTime = 1000;

// Mock requestAnimationFrame - captures callbacks and executes them
const rafCallbacks: Array<(time: number) => void> = [];
let rafId = 0;

// Mock performance.now
vi.stubGlobal('performance', {
  now: () => mockTime,
});

vi.stubGlobal('requestAnimationFrame', (callback: (time: number) => void) => {
  rafCallbacks.push(callback);
  return ++rafId;
});

vi.stubGlobal('cancelAnimationFrame', () => {
  rafCallbacks.length = 0;
});

// Mock URL.createObjectURL globally
vi.stubGlobal('URL', {
  createObjectURL: vi.fn(() => 'blob:mock-url'),
  revokeObjectURL: vi.fn(),
});

// Mock Image globally
class MockImage {
  src = '';
  onload: (() => void) | null = null;
  onerror: (() => void) | null = null;
  naturalWidth = 1;
  naturalHeight = 1;
  
  constructor() {
    // Delay to simulate async loading
    setTimeout(() => {
      if (this.onload) {
        this.onload();
      }
    }, 0);
  }
}

vi.stubGlobal('Image', MockImage);

// Helper to run a frame
function runFrame(time: number): void {
  mockTime = time;
  const callbacks = [...rafCallbacks];
  rafCallbacks.length = 0;
  for (const cb of callbacks) {
    cb(time);
  }
}

describe('Engine Integration', () => {
  beforeEach(() => {
    // Reset mocks
    mockContext = createMockContext();
    mockTime = 1000;
    rafCallbacks.length = 0;
    rafId = 0;
  });

  describe('Renderer + AssetManager + SpriteAtlas', () => {
    let container: HTMLDivElement;
    let renderer: Renderer;
    let assetManager: AssetManager;

    beforeEach(() => {
      container = document.createElement('div');
      document.body.appendChild(container);

      vi.spyOn(HTMLCanvasElement.prototype, 'getContext').mockReturnValue(
        mockContext as unknown as CanvasRenderingContext2D
      );

      renderer = new Renderer(container, { width: 800, height: 600 });
      assetManager = new AssetManager();
    });

    afterEach(() => {
      renderer.destroy();
      assetManager.unloadAll();
      container.remove();
      vi.clearAllMocks();
    });

    it('should draw loaded image via renderer', async () => {
      // Create a test image using a data URI
      const dataURI =
        'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAYAAAAfFcSJAAAADUlEQVR42mP8z8BQDwAEhQGAhKmMIQAAAABJRU5ErkJggg==';
      
      await assetManager.loadImage('test', dataURI);

      const image = assetManager.getImage('test');
      expect(image).toBeDefined();
      expect(image).toBeInstanceOf(MockImage);

      if (image) {
        renderer.drawImage(image as unknown as CanvasImageSource, 10, 20);
        expect(mockContext.drawImage).toHaveBeenCalledWith(image, 10, 20);
      }
    });

    it('should draw sprite from atlas', () => {
      const atlas = new SpriteAtlas();
      atlas.createFromGrid('test.png', 256, 256, 32, 32);

      const frame = atlas.getFrame('sprite_0_0');
      expect(frame).toBeDefined();

      const mockImage = new MockImage();

      if (frame) {
        renderer.drawSprite(mockImage as unknown as CanvasImageSource, frame, 100, 100);
        expect(mockContext.save).toHaveBeenCalled();
        expect(mockContext.drawImage).toHaveBeenCalled();
        expect(mockContext.restore).toHaveBeenCalled();
      }
    });

    it('should use viewport for drawing', () => {
      renderer.setViewport(100, 100, 400, 300);
      renderer.clear(0, 0, 0, 1);

      // Viewport should affect clear rect
      expect(mockContext.fillRect).toHaveBeenCalledWith(100, 100, 400, 300);
    });

    it('should convert world to screen coordinates', () => {
      renderer.setViewport(0, 0, 800, 600);
      renderer.setCamera(100, 100, 2, 0);

      const screen = renderer.worldToScreen(150, 150);
      // Camera at (100, 100), zoom 2, so world (150, 150) -> screen center + (50 * 2, 50 * 2)
      expect(screen.x).toBe(500); // 400 + 50 * 2
      expect(screen.y).toBe(400); // 300 + 50 * 2
    });

    it('should convert screen to world coordinates', () => {
      renderer.setViewport(0, 0, 800, 600);
      renderer.setCamera(0, 0, 1, 0);

      const world = renderer.screenToWorld(500, 400);
      // Screen (500, 400) -> world offset from center (100, 100)
      expect(world.x).toBeCloseTo(100);
      expect(world.y).toBeCloseTo(100);
    });
  });

  describe('InputManager + GameLoop', () => {
    let canvas: HTMLCanvasElement;
    let input: InputManager;
    let entityManager: EntityManager;
    let systemManager: SystemManager;
    let gameLoop: GameLoop;

    beforeEach(() => {
      canvas = document.createElement('canvas');
      canvas.width = 800;
      canvas.height = 600;
      document.body.appendChild(canvas);

      input = new InputManager(canvas);
      entityManager = new EntityManager();
      systemManager = new SystemManager();

      // Create a test system that responds to input
      class InputSystem extends System {
        name = 'InputSystem';
        update = vi.fn((_em, ctx) => {
          // System would read input here
          expect(ctx.dt).toBeGreaterThan(0);
        });
      }

      systemManager.addSystem(new InputSystem());

      gameLoop = new GameLoop(entityManager, systemManager, () => {
        // Render callback
      });
    });

    afterEach(() => {
      gameLoop.destroy();
      input.destroy();
      canvas.remove();
    });

    it('should process input during game loop update', () => {
      // Simulate key press before loop starts
      window.dispatchEvent(
        new KeyboardEvent('keydown', { code: 'KeyW', bubbles: true })
      );

      expect(input.isKeyDown('KeyW')).toBe(true);

      gameLoop.start();

      // Simulate frame
      runFrame(1020);

      // Input state should persist
      expect(input.isKeyDown('KeyW')).toBe(true);
    });

    it('should update input justPressed/justReleased each frame', () => {
      window.dispatchEvent(
        new KeyboardEvent('keydown', { code: 'KeyW', bubbles: true })
      );

      expect(input.wasKeyPressed('KeyW')).toBe(true);

      gameLoop.start();

      // First frame
      runFrame(1020);

      // After input.update() is called (usually by a system or game code)
      input.update();
      expect(input.wasKeyPressed('KeyW')).toBe(false);
    });
  });

  describe('AudioManager + GameLoop', () => {
    let audio: AudioManager;
    let entityManager: EntityManager;
    let systemManager: SystemManager;
    let gameLoop: GameLoop;

    beforeEach(() => {
      // Mock AudioContext
      class MockAudioContext {
        state = 'running';
        destination = {} as AudioDestinationNode;
        createBufferSource() {
          return {
            buffer: null,
            loop: false,
            onended: null as (() => void) | null,
            connect: () => ({ start: vi.fn(), stop: vi.fn() }),
            start: vi.fn(),
            stop: vi.fn(),
          };
        }
        createGain() {
          return { gain: { value: 1 }, connect: () => ({}) };
        }
        createStereoPanner() {
          return { pan: { value: 0 }, connect: () => ({}) };
        }
        decodeAudioData() {
          return Promise.resolve({} as AudioBuffer);
        }
        suspend() {
          return Promise.resolve();
        }
        resume() {
          return Promise.resolve();
        }
        close() {
          return Promise.resolve();
        }
      }

      vi.stubGlobal('AudioContext', MockAudioContext);

      audio = new AudioManager();
      entityManager = new EntityManager();
      systemManager = new SystemManager();

      // Create a test system that triggers audio
      class AudioSystem extends System {
        name = 'AudioSystem';
        update = vi.fn();
      }

      systemManager.addSystem(new AudioSystem());

      gameLoop = new GameLoop(entityManager, systemManager, () => {});
    });

    afterEach(() => {
      gameLoop.destroy();
      audio.destroy();
    });

    it('should allow audio to play during game loop', async () => {
      await audio.initialize();

      // Mock fetch for loading samples
      global.fetch = vi.fn().mockResolvedValue({
        ok: true,
        arrayBuffer: () => Promise.resolve(new ArrayBuffer(8)),
      } as unknown as Response);

      await audio.loadSample('shoot', 'shoot.mp3');

      gameLoop.start();

      // Simulate a frame where audio would be triggered
      runFrame(1020);

      // Audio manager should be initialized
      expect(audio.isInitialized).toBe(true);

      // Should be able to play sample
      expect(() => audio.playSample('shoot')).not.toThrow();
    });
  });

  describe('Full engine integration', () => {
    let container: HTMLDivElement;
    let canvas: HTMLCanvasElement;
    let renderer: Renderer;
    let input: InputManager;
    let entityManager: EntityManager;
    let systemManager: SystemManager;
    let gameLoop: GameLoop;

    beforeEach(() => {
      container = document.createElement('div');
      document.body.appendChild(container);

      vi.spyOn(HTMLCanvasElement.prototype, 'getContext').mockReturnValue(
        mockContext as unknown as CanvasRenderingContext2D
      );

      renderer = new Renderer(container, { width: 800, height: 600 });
      canvas = renderer.getCanvas();
      input = new InputManager(canvas);
      entityManager = new EntityManager();
      systemManager = new SystemManager();

      // Create movement system
      class MovementSystem extends System {
        name = 'Movement';
        update(em: EntityManager, ctx: { dt: number }) {
          const entities = em.query(['position', 'velocity']);
          for (const entity of entities) {
            const pos = entity.getComponent<{ type: string; x: number; y: number }>('position');
            const vel = entity.getComponent<{ type: string; vx: number; vy: number }>('velocity');
            if (pos && vel) {
              pos.x += vel.vx * ctx.dt;
              pos.y += vel.vy * ctx.dt;
            }
          }
        }
      }

      systemManager.addSystem(new MovementSystem());

      gameLoop = new GameLoop(entityManager, systemManager, () => {
        // Render callback uses renderer
        renderer.clear(0, 0, 0, 1);
      });
    });

    afterEach(() => {
      gameLoop.destroy();
      input.destroy();
      container.remove();
    });

    it('should run full game loop with ECS', () => {
      // Create an entity
      const entity = entityManager.createEntity();
      entity
        .addComponent({ type: 'position', x: 0, y: 0 } as Component)
        .addComponent({ type: 'velocity', vx: 100, vy: 50 } as Component);

      gameLoop.start();

      // Simulate frames over 1 second to ensure entity moves (need >16.67ms per update)
      runFrame(1020);
      runFrame(1040);
      runFrame(1060);
      runFrame(1080);
      runFrame(1100);

      // Entity should have moved
      const pos = entity.getComponent<{ type: string; x: number; y: number }>('position');
      expect(pos?.x).toBeGreaterThan(0);
      expect(pos?.y).toBeGreaterThan(0);
    });

    it('should render during game loop', () => {
      gameLoop.start();

      runFrame(1020);

      expect(mockContext.fillRect).toHaveBeenCalled();
    });

    it('should handle input during gameplay', () => {
      gameLoop.start();

      // Simulate player input
      window.dispatchEvent(
        new KeyboardEvent('keydown', { code: 'Space', bubbles: true })
      );

      runFrame(1020);

      // Input should be tracked
      expect(input.isKeyDown('Space')).toBe(true);
    });

    it('should support camera-relative rendering', () => {
      renderer.setCamera(100, 100, 2, 0);

      gameLoop.start();

      runFrame(1020);

      // Camera should be applied during render
      renderer.applyCamera();
      expect(mockContext.save).toHaveBeenCalled();
      expect(mockContext.translate).toHaveBeenCalled();
      expect(mockContext.scale).toHaveBeenCalled();
    });
  });

  describe('Asset loading integration', () => {
    let assetManager: AssetManager;

    beforeEach(() => {
      assetManager = new AssetManager({ basePath: '/assets/' });
    });

    afterEach(() => {
      assetManager.unloadAll();
    });

    it('should track load progress', async () => {
      expect(assetManager.loadProgress).toBe(1); // No loads pending

      // Load multiple images
      const images = [
        { name: 'img1', url: 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAYAAAAfFcSJAAAADUlEQVR42mP8z8BQDwAEhQGAhKmMIQAAAABJRU5ErkJggg==' },
        { name: 'img2', url: 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAYAAAAfFcSJAAAADUlEQVR42mP8z8BQDwAEhQGAhKmMIQAAAABJRU5ErkJggg==' },
      ];

      const promise = assetManager.loadImages(images);
      expect(assetManager.totalCount).toBe(2);

      await promise;

      expect(assetManager.loadProgress).toBe(1);
      expect(assetManager.loadedCount).toBe(2);
    });

    it('should cache loaded assets', async () => {
      const dataURI =
        'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAYAAAAfFcSJAAAADUlEQVR42mP8z8BQDwAEhQGAhKmMIQAAAABJRU5ErkJggg==';

      const img1 = await assetManager.loadImage('test', dataURI);
      const img2 = await assetManager.loadImage('test', dataURI);

      // Should return same cached image
      expect(img1).toBe(img2);
    });

    it('should allow asset unloading', async () => {
      const dataURI =
        'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAYAAAAfFcSJAAAADUlEQVR42mP8z8BQDwAEhQGAhKmMIQAAAABJRU5ErkJggg==';

      await assetManager.loadImage('test', dataURI);
      expect(assetManager.hasAsset('test')).toBe(true);

      assetManager.unload('test');
      expect(assetManager.hasAsset('test')).toBe(false);
    });

    it('should create blob URLs', () => {
      const url = assetManager.createBlobURL('test', 'text/plain');

      expect(url).toContain('blob:');
    });
  });
});
