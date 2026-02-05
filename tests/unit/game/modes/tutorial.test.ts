/**
 * Tutorial Mode Tests
 *
 * Tests for TutorialMode class including:
 * - Stage progression
 * - Input-based transitions
 * - Perk selection gate
 * - Stats tracking
 * - UI callbacks
 * - Failure modes
 */

import { describe, it, expect, vi, beforeEach } from 'vitest';
import type { Mock } from 'vitest';
import { TutorialMode } from '../../../../src/game/modes/TutorialMode';
import { EntityManager } from '../../../../src/core/ecs';
import type { BonusType } from '../../../../src/types';
import type { TutorialModeCallbacks, TutorialStage } from '../../../../src/game/modes/TutorialMode';
import type { CreatureTypeId } from '../../../../src/types';

describe('TutorialMode', () => {
  let entityManager: EntityManager;
  let tutorialMode: TutorialMode;
  let callbacks: TutorialModeCallbacks & {
    onStageChange: Mock<(stage: TutorialStage, previousStage: TutorialStage) => void>;
    onComplete: Mock<() => void>;
    onRequestPerkSelection: Mock<() => void>;
    onSpawnBonuses: Mock<
      (bonuses: Array<{ type: BonusType; x: number; y: number; value?: number }>) => void
    >;
    onSpawnEnemies: Mock<
      (enemies: Array<{ creatureTypeId: CreatureTypeId; x: number; y: number }>) => void
    >;
  };

  beforeEach(() => {
    entityManager = new EntityManager();
    callbacks = {
      onStageChange: vi.fn(),
      onComplete: vi.fn(),
      onRequestPerkSelection: vi.fn(),
      onSpawnBonuses: vi.fn(),
      onSpawnEnemies: vi.fn(),
    };
    tutorialMode = new TutorialMode(entityManager, callbacks);
  });

  describe('Basic Lifecycle', () => {
    it('should start at stage 0', () => {
      expect(tutorialMode.getCurrentStage()).toBe(0);
      expect(tutorialMode.isRunning()).toBe(false);
    });

    it('should be active after start', () => {
      tutorialMode.start();
      expect(tutorialMode.isRunning()).toBe(true);
      expect(tutorialMode.getCurrentStage()).toBe(0);
    });

    it('should reset to stage 0 on restart', () => {
      tutorialMode.start();
      tutorialMode.skipToEnd();
      tutorialMode.restart();
      expect(tutorialMode.getCurrentStage()).toBe(0);
    });

    it('should stop when requested', () => {
      tutorialMode.start();
      tutorialMode.stop();
      expect(tutorialMode.isRunning()).toBe(false);
    });
  });

  describe('Stage Progression', () => {
    beforeEach(() => {
      tutorialMode.start();
    });

    it('should auto-advance from intro stage after 6 seconds', () => {
      // At 5.9 seconds, should still be stage 0
      tutorialMode.update(5.9);
      expect(tutorialMode.getCurrentStage()).toBe(0);

      // At 6.1 seconds, should advance to stage 1
      tutorialMode.update(0.2);
      expect(tutorialMode.getCurrentStage()).toBe(1);
    });

    it('should call onStageChange when advancing', () => {
      tutorialMode.update(6.1);
      expect(callbacks.onStageChange).toHaveBeenCalledWith(1, 0);
    });

    it('should provide stage names for all stages', () => {
      const stageNames = [
        'Welcome',
        'Movement',
        'Collect Bonuses',
        'Shooting',
        'Clear Enemies',
        'Practice',
        'Perks',
        'Final Test',
        'Complete',
      ];

      for (let i = 0; i <= 8; i++) {
        expect(tutorialMode.getStageName(i as 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8)).toBe(
          stageNames[i]
        );
      }
    });

    it('should provide prompt text for all stages', () => {
      for (let i = 0; i <= 8; i++) {
        const prompt = tutorialMode.getStagePrompt(i as 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8);
        expect(typeof prompt).toBe('string');
        expect(prompt.length).toBeGreaterThan(0);
      }
    });
  });

  describe('Input-Based Stage Transitions', () => {
    beforeEach(() => {
      tutorialMode.start();
      // Skip to movement stage (stage 1) immediately
      tutorialMode.update(6.1);
      // Wait for transition timer to clear (1 second)
      tutorialMode.update(1.1);
      expect(tutorialMode.getCurrentStage()).toBe(1);
    });

    it('should advance from movement stage on input', () => {
      tutorialMode.checkStageProgression({ hasMovementInput: true });
      expect(tutorialMode.getCurrentStage()).toBe(2);
    });

    it('should spawn bonuses when advancing from movement stage', () => {
      tutorialMode.checkStageProgression({ hasMovementInput: true });
      expect(callbacks.onSpawnBonuses).toHaveBeenCalled();

      const bonuses = (callbacks.onSpawnBonuses.mock.calls[0]?.[0] ?? []) as unknown as Array<{
        type: BonusType;
        x: number;
        y: number;
      }>;
      expect(bonuses.length).toBe(3);
    });

    it('should advance from collect stage when all bonuses collected', () => {
      tutorialMode.checkStageProgression({ hasMovementInput: true }); // To stage 2
      tutorialMode.update(1.1); // Clear transition timer
      tutorialMode.checkStageProgression({ remainingBonuses: 0 });
      expect(tutorialMode.getCurrentStage()).toBe(3);
    });

    it('should not advance from collect stage if bonuses remain', () => {
      tutorialMode.checkStageProgression({ hasMovementInput: true }); // To stage 2
      tutorialMode.update(1.1); // Clear transition timer
      tutorialMode.checkStageProgression({ remainingBonuses: 2 });
      expect(tutorialMode.getCurrentStage()).toBe(2);
    });

    it('should advance from shoot stage on fire input', () => {
      tutorialMode.checkStageProgression({ hasMovementInput: true }); // 1 -> 2
      tutorialMode.update(1.1);
      tutorialMode.checkStageProgression({ remainingBonuses: 0 }); // 2 -> 3
      tutorialMode.update(1.1);

      tutorialMode.checkStageProgression({ hasFireInput: true });
      expect(tutorialMode.getCurrentStage()).toBe(4);
    });

    it('should spawn enemies when advancing from shoot stage', () => {
      tutorialMode.checkStageProgression({ hasMovementInput: true });
      tutorialMode.update(1.1);
      tutorialMode.checkStageProgression({ remainingBonuses: 0 });
      tutorialMode.update(1.1);

      tutorialMode.checkStageProgression({ hasFireInput: true });
      expect(callbacks.onSpawnEnemies).toHaveBeenCalled();
    });

    it('should advance from clear stage when all enemies defeated', () => {
      tutorialMode.checkStageProgression({ hasMovementInput: true });
      tutorialMode.update(1.1);
      tutorialMode.checkStageProgression({ remainingBonuses: 0 });
      tutorialMode.update(1.1);
      tutorialMode.checkStageProgression({ hasFireInput: true }); // Now at stage 4
      tutorialMode.update(1.1);

      tutorialMode.checkStageProgression({ remainingEnemies: 0 });
      expect(tutorialMode.getCurrentStage()).toBe(5);
    });
  });

  describe('Practice Loop Stage', () => {
    beforeEach(() => {
      tutorialMode.start();
      // Navigate to practice stage (stage 5)
      tutorialMode.update(6.1); // 0 -> 1
      tutorialMode.update(1.1); // clear timer
      tutorialMode.checkStageProgression({ hasMovementInput: true }); // 1 -> 2
      tutorialMode.update(1.1);
      tutorialMode.checkStageProgression({ remainingBonuses: 0 }); // 2 -> 3
      tutorialMode.update(1.1);
      tutorialMode.checkStageProgression({ hasFireInput: true }); // 3 -> 4
      tutorialMode.update(1.1);
      tutorialMode.checkStageProgression({ remainingEnemies: 0 }); // 4 -> 5

      expect(tutorialMode.getCurrentStage()).toBe(5);
    });

    it('should spawn enemies on first iteration', () => {
      expect(callbacks.onSpawnEnemies).toHaveBeenCalled();
    });

    it('should continue spawning waves in practice loop', () => {
      const initialSpawnCount = callbacks.onSpawnEnemies.mock.calls.length;

      // Simulate clearing enemies and advancing loop
      tutorialMode.update(1.1);
      tutorialMode.checkStageProgression({ remainingEnemies: 0 });

      expect(callbacks.onSpawnEnemies.mock.calls.length).toBeGreaterThan(initialSpawnCount);
    });

    it('should advance to perk selection after 8 loops', () => {
      // Simulate 8 iterations of the practice loop
      for (let i = 0; i < 8; i++) {
        tutorialMode.update(1.1);
        tutorialMode.checkStageProgression({ remainingEnemies: 0 });
      }

      expect(tutorialMode.getCurrentStage()).toBe(6);
    });
  });

  describe('Perk Selection Stage', () => {
    beforeEach(() => {
      tutorialMode = new TutorialMode(entityManager, callbacks, undefined, {
        practiceLoopCount: 2, // Fewer loops for faster test
      });
      tutorialMode.start();

      // Navigate to practice stage (5) first
      tutorialMode.update(6.1);
      tutorialMode.update(1.1);
      tutorialMode.checkStageProgression({ hasMovementInput: true });
      tutorialMode.update(1.1);
      tutorialMode.checkStageProgression({ remainingBonuses: 0 });
      tutorialMode.update(1.1);
      tutorialMode.checkStageProgression({ hasFireInput: true });
      tutorialMode.update(1.1);
      tutorialMode.checkStageProgression({ remainingEnemies: 0 });

      expect(tutorialMode.getCurrentStage()).toBe(5);

      // Now complete just 2 loops to get to perk selection
      tutorialMode.update(1.1);
      tutorialMode.checkStageProgression({ remainingEnemies: 0 });
      tutorialMode.update(1.1);
      tutorialMode.checkStageProgression({ remainingEnemies: 0 });

      expect(tutorialMode.getCurrentStage()).toBe(6);
    });

    it('should request perk selection when entering stage', () => {
      // The callback is triggered during update
      tutorialMode.update(0.1);
      expect(callbacks.onRequestPerkSelection).toHaveBeenCalled();
    });

    it('should be in perk selection state', () => {
      tutorialMode.update(0.1);
      expect(tutorialMode.isSelectingPerk()).toBe(true);
    });

    it('should advance after perk is selected', () => {
      tutorialMode.update(0.1);
      tutorialMode.onPerkSelected();
      expect(tutorialMode.isSelectingPerk()).toBe(false);
    });
  });

  describe('Final Stage and Completion', () => {
    beforeEach(() => {
      tutorialMode.start();
      tutorialMode.skipToEnd();
      expect(tutorialMode.getCurrentStage()).toBe(8);
    });

    it('should be at complete stage after skipToEnd', () => {
      expect(tutorialMode.getStageName()).toBe('Complete');
    });

    it('should complete tutorial when updating at final stage', () => {
      tutorialMode.update(0.1);
      expect(callbacks.onComplete).toHaveBeenCalled();
    });

    it('should return final stats on completion', () => {
      tutorialMode.update(0.1);
      expect(callbacks.onComplete).toHaveBeenCalledWith(
        expect.objectContaining({
          kills: expect.any(Number),
          score: expect.any(Number),
          timeElapsed: expect.any(Number),
          level: 1,
        })
      );
    });
  });

  describe('Stats Tracking', () => {
    beforeEach(() => {
      tutorialMode.start();
    });

    it('should track kills', () => {
      tutorialMode.recordKill();
      tutorialMode.recordKill();
      tutorialMode.recordKill();

      const stats = tutorialMode.getStats();
      expect(stats.kills).toBe(3);
    });

    it('should not track kills when stopped', () => {
      tutorialMode.stop();
      tutorialMode.recordKill();

      const stats = tutorialMode.getStats();
      expect(stats.kills).toBe(0);
    });

    it('should track elapsed time', () => {
      tutorialMode.update(5.0);
      const stats = tutorialMode.getStats();
      expect(stats.timeElapsed).toBeCloseTo(5.0, 5);
    });

    it('should calculate score based on kills', () => {
      tutorialMode.recordKill();
      tutorialMode.recordKill();

      const stats = tutorialMode.getStats();
      expect(stats.score).toBe(20); // 2 kills * 10 points
    });
  });

  describe('Skip and Navigation', () => {
    it('should skip to end stage', () => {
      tutorialMode.start();
      tutorialMode.skipToEnd();
      expect(tutorialMode.getCurrentStage()).toBe(8);
    });

    it('should restart from beginning', () => {
      tutorialMode.start();
      tutorialMode.update(6.1); // Advance to stage 1
      tutorialMode.restart();

      expect(tutorialMode.getCurrentStage()).toBe(0);
      expect(tutorialMode.getElapsedTime()).toBe(0);
    });
  });

  describe('Configuration', () => {
    it('should use custom intro duration', () => {
      const customTutorial = new TutorialMode(entityManager, callbacks, undefined, {
        introDurationMs: 1000, // 1 second instead of 6
      });
      customTutorial.start();

      customTutorial.update(0.9);
      expect(customTutorial.getCurrentStage()).toBe(0);

      customTutorial.update(0.2);
      expect(customTutorial.getCurrentStage()).toBe(1);
    });

    it('should use custom practice loop count', () => {
      const customTutorial = new TutorialMode(entityManager, callbacks, undefined, {
        practiceLoopCount: 2,
      });
      customTutorial.start();

      // Navigate to practice stage
      customTutorial.update(6.1);
      // Wait for transition timer to clear after each stage advance
      customTutorial.update(1.1);
      customTutorial.checkStageProgression({ hasMovementInput: true });
      customTutorial.update(1.1);
      customTutorial.checkStageProgression({ remainingBonuses: 0 });
      customTutorial.update(1.1);
      customTutorial.checkStageProgression({ hasFireInput: true });
      customTutorial.update(1.1);
      customTutorial.checkStageProgression({ remainingEnemies: 0 });

      // Now at practice stage (5)
      expect(customTutorial.getCurrentStage()).toBe(5);

      // Should only need 2 loops instead of 8
      customTutorial.update(1.1);
      customTutorial.checkStageProgression({ remainingEnemies: 0 });
      customTutorial.update(1.1);
      customTutorial.checkStageProgression({ remainingEnemies: 0 });

      expect(customTutorial.getCurrentStage()).toBe(6);
    });

    it('should use custom XP amount for perk selection', () => {
      // This is tested indirectly through the perk selection mechanism
      // The XP is granted but we verify it doesn't cause errors
      const customTutorial = new TutorialMode(entityManager, callbacks, undefined, {
        xpForPerkSelection: 500,
      });
      expect(customTutorial).toBeDefined();
    });
  });

  describe('Failure Modes', () => {
    it('should handle checkStageProgression when not active', () => {
      tutorialMode.stop();
      expect(() => {
        tutorialMode.checkStageProgression({ hasMovementInput: true });
      }).not.toThrow();
    });

    it('should handle multiple rapid stage checks', () => {
      tutorialMode.start();
      tutorialMode.update(6.1);
      tutorialMode.update(1.1);

      // First call should advance to stage 2 (movement -> collect)
      tutorialMode.checkStageProgression({ hasMovementInput: true });
      const stageAfterFirst = tutorialMode.getCurrentStage();
      expect(stageAfterFirst).toBe(2);

      // Subsequent calls should NOT advance because
      // stage 2 requires remainingBonuses === 0 AND spawnedBonuses > 0
      // We simulate that bonuses are still remaining
      for (let i = 0; i < 10; i++) {
        tutorialMode.checkStageProgression({ remainingBonuses: 3 });
      }

      // Should still be at stage 2 (waiting for bonuses to be collected)
      expect(tutorialMode.getCurrentStage()).toBe(stageAfterFirst);
    });

    it('should handle undefined progression checks gracefully', () => {
      tutorialMode.start();

      // Should not throw with empty checks
      expect(() => {
        tutorialMode.checkStageProgression({});
      }).not.toThrow();
    });
  });
});
