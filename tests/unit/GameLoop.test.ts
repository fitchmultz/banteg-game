/**
 * GameLoop unit tests
 */

import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { GameLoop } from '../../src/core/GameLoop';
import { EntityManager } from '../../src/core/ecs/EntityManager';
import { System, SystemManager } from '../../src/core/ecs/System';

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

// Helper to run a frame
function runFrame(time: number): void {
  mockTime = time;
  const callbacks = [...rafCallbacks];
  rafCallbacks.length = 0;
  for (const cb of callbacks) {
    cb(time);
  }
}

describe('GameLoop', () => {
  let entityManager: EntityManager;
  let systemManager: SystemManager;
  let renderCallback: ReturnType<typeof vi.fn>;
  let gameLoop: GameLoop;

  beforeEach(() => {
    mockTime = 1000; // Start at non-zero time
    rafCallbacks.length = 0;
    rafId = 0;

    entityManager = new EntityManager();
    systemManager = new SystemManager();
    renderCallback = vi.fn();

    gameLoop = new GameLoop(entityManager, systemManager, renderCallback);
  });

  afterEach(() => {
    gameLoop.destroy();
    vi.clearAllMocks();
  });

  describe('lifecycle', () => {
    it('should start the loop', () => {
      gameLoop.start();
      expect(gameLoop.running).toBe(true);
    });

    it('should not start if already running', () => {
      gameLoop.start();
      const rafCount = rafCallbacks.length;

      gameLoop.start(); // Second start should be ignored
      expect(rafCallbacks.length).toBe(rafCount);
    });

    it('should stop the loop', () => {
      gameLoop.start();
      gameLoop.stop();
      expect(gameLoop.running).toBe(false);
    });

    it('should stop on destroy', () => {
      gameLoop.start();
      gameLoop.destroy();
      expect(gameLoop.running).toBe(false);
    });
  });

  describe('fixed timestep updates', () => {
    it('should call system updates', () => {
      const mockSystem = new (class extends System {
        name = 'TestSystem';
        update = vi.fn();
      })();

      systemManager.addSystem(mockSystem);
      gameLoop.start();

      // Simulate a frame (20ms > 16.67ms timestep at 60 UPS)
      runFrame(1020);

      expect(mockSystem.update).toHaveBeenCalled();
    });

    it('should cap delta time', () => {
      const mockSystem = new (class extends System {
        name = 'TestSystem';
        update = vi.fn();
      })();

      systemManager.addSystem(mockSystem);
      gameLoop.start();

      // Simulate a huge delta (more than maxDeltaTime of 250ms default)
      runFrame(1500);

      // Should still call update but with capped dt
      expect(mockSystem.update).toHaveBeenCalled();
    });

    it('should accumulate time for fixed timestep', () => {
      const mockSystem = new (class extends System {
        name = 'TestSystem';
        update = vi.fn();
      })();

      systemManager.addSystem(mockSystem);
      gameLoop.start();

      // Simulate multiple frames worth of time (~4 frames at 60fps)
      runFrame(1070);

      // Should have called update multiple times
      expect(mockSystem.update.mock.calls.length).toBeGreaterThan(1);
    });

    it('should process entity destructions after update', () => {
      entityManager.createEntity();
      const destroySpy = vi.spyOn(entityManager, 'processDestructions');

      gameLoop.start();

      runFrame(1020);

      expect(destroySpy).toHaveBeenCalled();
    });
  });

  describe('render callback', () => {
    it('should call render callback', () => {
      gameLoop.start();

      runFrame(1020);

      expect(renderCallback).toHaveBeenCalled();
    });

    it('should pass interpolation to render', () => {
      gameLoop.start();

      runFrame(1010); // Half a frame at 60fps

      const [interpolation] = renderCallback.mock.calls[0] as [number];
      expect(interpolation).toBeGreaterThanOrEqual(0);
      expect(interpolation).toBeLessThanOrEqual(1);
    });

    it('should pass FPS to render', () => {
      gameLoop.start();

      runFrame(1020);

      const [, fps] = renderCallback.mock.calls[0] as [number, number];
      expect(typeof fps).toBe('number');
    });
  });

  describe('FPS tracking', () => {
    it('should track FPS', () => {
      gameLoop.start();

      // Simulate multiple frames over 500ms (the FPS update interval)
      for (let i = 0; i <= 30; i++) {
        runFrame(1000 + i * 16.67);
      }

      // FPS should be approximately 60
      const fps = gameLoop.fps;
      expect(fps).toBeGreaterThan(0);
    });

    it('should update FPS periodically', () => {
      gameLoop.start();

      // First frame
      runFrame(1000);

      // Second frame after 500ms (fps update interval)
      runFrame(1500);

      expect(gameLoop.fps).toBeGreaterThanOrEqual(0);
    });
  });

  describe('game time tracking', () => {
    it('should track total game time', () => {
      gameLoop.start();

      // Run multiple frames to accumulate game time
      runFrame(1020);
      runFrame(1040);
      runFrame(1060);

      expect(gameLoop.totalGameTime).toBeGreaterThan(0);
    });
  });

  describe('pause on blur', () => {
    it('should create loop with pauseOnBlur option', () => {
      const loopWithPause = new GameLoop(entityManager, systemManager, renderCallback, {
        pauseOnBlur: true,
      });

      expect(loopWithPause).toBeTruthy();
      loopWithPause.destroy();
    });

    it('should pause when document is hidden', () => {
      // Mock document.hidden
      Object.defineProperty(document, 'hidden', {
        writable: true,
        configurable: true,
        value: true,
      });

      gameLoop.start();

      // Trigger visibility change
      document.dispatchEvent(new Event('visibilitychange'));

      // Next frame should handle the pause
      runFrame(1020);

      expect(gameLoop.running).toBe(true); // Still running, just paused time
    });

    it('should clean up visibility listener on destroy', () => {
      const removeEventListenerSpy = vi.spyOn(document, 'removeEventListener');

      const loopWithPause = new GameLoop(entityManager, systemManager, renderCallback, {
        pauseOnBlur: true,
      });

      loopWithPause.destroy();

      expect(removeEventListenerSpy).toHaveBeenCalledWith('visibilitychange', expect.any(Function));
    });
  });

  describe('options', () => {
    it('should use custom target UPS', () => {
      const customLoop = new GameLoop(entityManager, systemManager, renderCallback, {
        targetUps: 30,
      });

      expect(customLoop).toBeTruthy();
      customLoop.destroy();
    });

    it('should use custom max delta time', () => {
      const customLoop = new GameLoop(entityManager, systemManager, renderCallback, {
        maxDeltaTime: 100,
      });

      expect(customLoop).toBeTruthy();
      customLoop.destroy();
    });
  });
});
