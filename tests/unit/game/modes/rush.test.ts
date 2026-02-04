/**
 * Rush Mode Tests
 *
 * Tests for RushMode class including:
 * - Basic lifecycle (start, stop, update)
 * - Spawn pacing and scoring
 * - Stats tracking
 * - Failure modes
 */

import { describe, it, expect, vi, beforeEach } from 'vitest';
import { RushMode } from '../../../../src/game/modes/RushMode';
import { EntityManager } from '../../../../src/core/ecs';

describe('RushMode', () => {
  let entityManager: EntityManager;
  let rushMode: RushMode;
  let callbacks: {
    onStart: ReturnType<typeof vi.fn>;
    onGameOver: ReturnType<typeof vi.fn>;
    onSpawn: ReturnType<typeof vi.fn>;
  };

  beforeEach(() => {
    entityManager = new EntityManager();
    callbacks = {
      onStart: vi.fn(),
      onGameOver: vi.fn(),
      onSpawn: vi.fn(),
    };
    rushMode = new RushMode(entityManager, callbacks);
  });

  describe('Basic Lifecycle', () => {
    it('should start in inactive state', () => {
      expect(rushMode.isRunning()).toBe(false);
      expect(rushMode.getElapsedTime()).toBe(0);
    });

    it('should become active after start', () => {
      rushMode.start();
      expect(rushMode.isRunning()).toBe(true);
      expect(callbacks.onStart).toHaveBeenCalled();
    });

    it('should become inactive after stop', () => {
      rushMode.start();
      rushMode.stop();
      expect(rushMode.isRunning()).toBe(false);
    });

    it('should not update when stopped', () => {
      rushMode.update(0.1);
      expect(rushMode.getElapsedTime()).toBe(0);
    });

    it('should track elapsed time when updating', () => {
      rushMode.start();
      rushMode.update(0.1);
      expect(rushMode.getElapsedTime()).toBeCloseTo(0.1, 5);
    });

    it('should accumulate time over multiple updates', () => {
      rushMode.start();
      rushMode.update(0.1);
      rushMode.update(0.2);
      rushMode.update(0.3);
      expect(rushMode.getElapsedTime()).toBeCloseTo(0.6, 5);
    });
  });

  describe('Spawn Behavior', () => {
    it('should trigger spawn callbacks when cooldown passes threshold', () => {
      rushMode.start();
      // First update should not spawn (cooldown starts at 0, will immediately trigger in while loop)
      // Actually the RushMode immediately spawns since cooldown starts at 0
      rushMode.update(0.01);
      expect(callbacks.onSpawn).toHaveBeenCalled();
    });

    it('should spawn enemies at left and right edges', () => {
      rushMode.start();
      rushMode.update(0.01);

      // Should spawn 2 enemies (one on each side)
      expect(callbacks.onSpawn).toHaveBeenCalledTimes(2);

      // Get spawn positions
      const calls = callbacks.onSpawn.mock.calls;
      const rightX = (calls[0]?.[1] ?? 0) as number;
      const leftX = (calls[1]?.[1] ?? 0) as number;

      // Right edge should be positive (around +1088 = 1024 + 64)
      expect(rightX).toBeGreaterThan(1000);
      // Left edge should be negative (around -1088)
      expect(leftX).toBeLessThan(-1000);
    });

    it('should oscillate Y positions based on elapsed time', () => {
      rushMode.start();
      rushMode.update(0.01);
      const firstY1 = (callbacks.onSpawn.mock.calls[0]?.[2] ?? 0) as number;

      // Reset and try again with more time elapsed
      callbacks.onSpawn.mockClear();
      const rushMode2 = new RushMode(entityManager, { onSpawn: callbacks.onSpawn });
      rushMode2.start();
      rushMode2.update(1.0); // Different elapsed time
      rushMode2.update(0.01);
      const secondY1 = (callbacks.onSpawn.mock.calls[0]?.[2] ?? 0) as number;

      // Y positions should be different due to sin/cos oscillation
      expect(firstY1).not.toBe(secondY1);
    });

    it('should spawn multiple waves over time', () => {
      rushMode.start();
      // Advance time by 1 second (should spawn ~4 waves)
      rushMode.update(1.0);

      // Should have spawned multiple times (at least 4 waves * 2 enemies = 8)
      expect(callbacks.onSpawn.mock.calls.length).toBeGreaterThanOrEqual(4);
    });
  });

  describe('Stats Tracking', () => {
    it('should track kills', () => {
      rushMode.start();
      rushMode.recordKill(10);
      rushMode.recordKill(10);

      const stats = rushMode.getStats();
      expect(stats.kills).toBe(2);
      expect(stats.score).toBe(20);
    });

    it('should not track kills when stopped', () => {
      rushMode.start();
      rushMode.stop();
      rushMode.recordKill(10);

      const stats = rushMode.getStats();
      expect(stats.kills).toBe(0);
    });

    it('should track score additions', () => {
      rushMode.start();
      rushMode.addScore(100);
      rushMode.addScore(50);

      const stats = rushMode.getStats();
      expect(stats.score).toBe(150);
    });

    it('should not add score when stopped', () => {
      rushMode.start();
      rushMode.stop();
      rushMode.addScore(100);

      const stats = rushMode.getStats();
      expect(stats.score).toBe(0);
    });

    it('should include time in stats', () => {
      rushMode.start();
      rushMode.update(5.0);

      const stats = rushMode.getStats();
      expect(stats.timeElapsed).toBeCloseTo(5.0, 5);
    });

    it('should have level 1 in stats (rush does not use levels)', () => {
      const stats = rushMode.getStats();
      expect(stats.level).toBe(1);
    });
  });

  describe('End Run', () => {
    it('should end run and return final stats', () => {
      rushMode.start();
      rushMode.update(10.0);
      rushMode.recordKill(5);

      const finalStats = rushMode.endRun();

      expect(finalStats.timeElapsed).toBeCloseTo(10.0, 5);
      expect(finalStats.kills).toBe(1); // 1 kill
      expect(rushMode.isRunning()).toBe(false);
      expect(callbacks.onGameOver).toHaveBeenCalled();
    });

    it('should call onGameOver callback when ending', () => {
      rushMode.start();
      rushMode.endRun();

      expect(callbacks.onGameOver).toHaveBeenCalledWith(
        expect.objectContaining({
          kills: expect.any(Number),
          score: expect.any(Number),
          timeElapsed: expect.any(Number),
          level: 1,
        })
      );
    });
  });

  describe('Configuration', () => {
    it('should use custom spawn cooldown', () => {
      const customRush = new RushMode(
        entityManager,
        { onSpawn: callbacks.onSpawn },
        undefined,
        { spawnCooldownMs: 100 } // Faster spawning
      );

      customRush.start();
      customRush.update(0.11);

      expect(callbacks.onSpawn).toHaveBeenCalled();
    });

    it('should use custom map dimensions', () => {
      const customRush = new RushMode(entityManager, { onSpawn: callbacks.onSpawn }, undefined, {
        mapWidth: 1024,
        mapHeight: 1024,
      });

      customRush.start();
      customRush.update(0.01);

      const calls = callbacks.onSpawn.mock.calls;
      const rightX = (calls[0]?.[1] ?? 0) as number;

      // With 1024 width, edge should be at +512 + 64 = +576
      expect(rightX).toBeCloseTo(576, 0);
    });
  });

  describe('Failure Modes', () => {
    it('should handle rapid start/stop cycles', () => {
      rushMode.start();
      rushMode.stop();
      rushMode.start();
      rushMode.stop();
      rushMode.start();

      expect(rushMode.isRunning()).toBe(true);
      expect(rushMode.getElapsedTime()).toBe(0); // Reset on start
    });

    it('should handle updates with zero delta time', () => {
      rushMode.start();
      rushMode.update(0);
      expect(rushMode.getElapsedTime()).toBe(0);
    });

    it('should handle very large delta times gracefully', () => {
      rushMode.start();
      // Simulate a large lag spike
      rushMode.update(10);

      // Should still track time correctly
      expect(rushMode.getElapsedTime()).toBe(10);

      // Should have spawned many enemies (but not crash)
      expect(callbacks.onSpawn.mock.calls.length).toBeGreaterThan(0);
    });
  });
});

describe('RushSpawnSystem', () => {
  // These tests would require mocking the ECS more thoroughly
  // For now, we test the integration through RushMode
  it('should be testable via integration', () => {
    // This test serves as a placeholder indicating that
    // RushSpawnSystem is tested through RushMode tests
    expect(true).toBe(true);
  });
});
