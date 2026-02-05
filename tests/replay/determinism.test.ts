/**
 * Deterministic Behavior Parity Tests
 *
 * These tests validate that the game produces identical results
 * when run with the same seed and inputs.
 */

import { describe, it, expect, beforeEach, afterEach } from 'vitest';
import { ReplayHarness, type ReplayScenario } from './ReplayHarness';
import { compareSnapshots } from './StateSnapshot';
import { mockRandomWithSeed, restoreRandom } from './SeededRNG';

describe('Deterministic Behavior Parity', () => {
  let harness: ReplayHarness;

  beforeEach(() => {
    harness = new ReplayHarness();
  });

  afterEach(() => {
    harness.destroy();
  });

  describe('SeededRNG', () => {
    it('should produce identical sequences with same seed', () => {
      mockRandomWithSeed(12345);
      const seq1 = [
        Math.random(),
        Math.random(),
        Math.random(),
        Math.random(),
        Math.random(),
      ];

      mockRandomWithSeed(12345);
      const seq2 = [
        Math.random(),
        Math.random(),
        Math.random(),
        Math.random(),
        Math.random(),
      ];

      restoreRandom();
      expect(seq1).toEqual(seq2);
    });

    it('should produce different sequences with different seeds', () => {
      mockRandomWithSeed(12345);
      const val1 = Math.random();

      mockRandomWithSeed(54321);
      const val2 = Math.random();

      restoreRandom();
      expect(val1).not.toBe(val2);
    });
  });

  describe('Basic Determinism', () => {
    it('should produce identical entity counts with same seed', () => {
      const scenario: ReplayScenario = {
        name: 'basic_determinism',
        seed: 12345,
        durationFrames: 60, // 1 second
        initialState: {
          playerPosition: { x: 0, y: 0 },
          gameMode: 'survival',
        },
        inputs: [],
      };

      harness.setupScenario(scenario);
      harness.runFrames(60);
      const count1 = harness.getEntityManager().entityCount;

      harness.setupScenario(scenario);
      harness.runFrames(60);
      const count2 = harness.getEntityManager().entityCount;

      expect(count1).toBe(count2);
    });

    it('should produce identical snapshots with same seed', () => {
      const scenario: ReplayScenario = {
        name: 'snapshot_determinism',
        seed: 54321,
        durationFrames: 120, // 2 seconds
        initialState: {
          playerPosition: { x: 100, y: 100 },
          gameMode: 'survival',
        },
        inputs: [],
      };

      harness.setupScenario(scenario);
      const snapshots1 = harness.runFrames(120, 30);

      harness.setupScenario(scenario);
      const snapshots2 = harness.runFrames(120, 30);

      // Compare snapshots at each captured frame
      for (const [frame, snapshot1] of snapshots1) {
        const snapshot2 = snapshots2.get(frame);
        expect(snapshot2).toBeDefined();
        if (snapshot2) {
          const differences = compareSnapshots(snapshot1, snapshot2, 0.01);
          expect(differences).toEqual([]);
        }
      }
    });

    it('should produce different RNG sequences with different seeds', () => {
      // Directly test that the seeded RNG produces different values
      mockRandomWithSeed(12345);
      const values1 = [
        Math.random(),
        Math.random(),
        Math.random(),
        Math.random(),
        Math.random(),
      ];
      restoreRandom();

      mockRandomWithSeed(54321);
      const values2 = [
        Math.random(),
        Math.random(),
        Math.random(),
        Math.random(),
        Math.random(),
      ];
      restoreRandom();

      // Different seeds should produce different sequences
      expect(values1).not.toEqual(values2);

      // Verify at least one value differs
      let foundDifference = false;
      for (let i = 0; i < values1.length; i++) {
        if (values1[i] !== values2[i]) {
          foundDifference = true;
          break;
        }
      }
      expect(foundDifference).toBe(true);
    });
  });

  describe('AI Tick Cadence (70-tick cycle)', () => {
    it('should update AI behavior deterministically', () => {
      const scenario: ReplayScenario = {
        name: 'ai_determinism',
        seed: 99999,
        durationFrames: 210, // 3.5 seconds = ~3 AI cycles
        initialState: {
          playerPosition: { x: 0, y: 0 },
          gameMode: 'survival',
        },
        inputs: [],
      };

      harness.setupScenario(scenario);
      const snapshots1 = harness.runFrames(210, 70);

      harness.setupScenario(scenario);
      const snapshots2 = harness.runFrames(210, 70);

      // Verify all snapshots match
      for (const [frame, snapshot1] of snapshots1) {
        const snapshot2 = snapshots2.get(frame);
        expect(snapshot2).toBeDefined();
        if (snapshot2) {
          const differences = compareSnapshots(snapshot1, snapshot2, 0.01);
          expect(differences).toEqual([]);
        }
      }
    });
  });

  describe('Spawn Timing Determinism', () => {
    it('should spawn creatures deterministically in survival mode', () => {
      const scenario: ReplayScenario = {
        name: 'survival_spawn_determinism',
        seed: 11111,
        durationFrames: 180, // 3 seconds
        initialState: {
          playerPosition: { x: 0, y: 0 },
          gameMode: 'survival',
        },
        inputs: [],
      };

      harness.setupScenario(scenario);
      const snapshots1 = harness.runFrames(180, 30);
      const spawnSystem1 = harness.getSpawnSystem();

      harness.setupScenario(scenario);
      const snapshots2 = harness.runFrames(180, 30);
      const spawnSystem2 = harness.getSpawnSystem();

      // Verify spawn counts match
      expect(spawnSystem1?.getSpawnedCount()).toBe(spawnSystem2?.getSpawnedCount());
      expect(spawnSystem1?.getActiveEnemies()).toBe(spawnSystem2?.getActiveEnemies());

      // Verify timeline snapshots match
      for (const [frame, snapshot1] of snapshots1) {
        const snapshot2 = snapshots2.get(frame);
        expect(snapshot2).toBeDefined();
        if (snapshot2) {
          const differences = compareSnapshots(snapshot1, snapshot2, 0.01);
          expect(differences).toEqual([]);
        }
      }
    });

    it('should follow quest timeline deterministically', () => {
      const scenario: ReplayScenario = {
        name: 'quest_spawn_determinism',
        seed: 22222,
        durationFrames: 300, // 5 seconds
        initialState: {
          playerPosition: { x: 0, y: 0 },
          gameMode: 'quest',
          questId: 'nagolipoli',
        },
        inputs: [],
      };

      harness.setupScenario(scenario);
      const snapshots1 = harness.runFrames(300, 60);
      const questSystem1 = harness.getQuestSpawnSystem();

      harness.setupScenario(scenario);
      const snapshots2 = harness.runFrames(300, 60);
      const questSystem2 = harness.getQuestSpawnSystem();

      // Verify quest timeline progress matches
      expect(questSystem1?.getTimelineMs()).toBe(questSystem2?.getTimelineMs());

      // Verify snapshots match
      for (const [frame, snapshot1] of snapshots1) {
        const snapshot2 = snapshots2.get(frame);
        expect(snapshot2).toBeDefined();
        if (snapshot2) {
          const differences = compareSnapshots(snapshot1, snapshot2, 0.01);
          expect(differences).toEqual([]);
        }
      }
    });
  });

  describe('Perk Interaction Determinism', () => {
    it('should produce consistent Fatal Lottery results with same seed', () => {
      const scenario: ReplayScenario = {
        name: 'fatal_lottery_determinism',
        seed: 77777,
        durationFrames: 60,
        initialState: {
          playerPosition: { x: 0, y: 0 },
          gameMode: 'survival',
        },
        inputs: [
          { frameNumber: 10, type: 'selectPerk', data: { perkId: 42 } }, // Fatal Lottery
        ],
      };

      harness.setupScenario(scenario);
      const snapshots1 = harness.runFrames(60);

      harness.setupScenario(scenario);
      const snapshots2 = harness.runFrames(60);

      // Results should be identical
      const snap1 = snapshots1.get(60);
      const snap2 = snapshots2.get(60);
      expect(snap1).toBeDefined();
      expect(snap2).toBeDefined();

      if (snap1 && snap2) {
        const differences = compareSnapshots(snap1, snap2, 0.01);
        expect(differences).toEqual([]);
      }
    });

    it('should produce consistent Bandage results with same seed', () => {
      const scenario: ReplayScenario = {
        name: 'bandage_determinism',
        seed: 88888,
        durationFrames: 60,
        initialState: {
          playerPosition: { x: 0, y: 0 },
          gameMode: 'survival',
        },
        inputs: [
          { frameNumber: 10, type: 'selectPerk', data: { perkId: 43 } }, // Bandage
        ],
      };

      harness.setupScenario(scenario);
      const snapshots1 = harness.runFrames(60);

      harness.setupScenario(scenario);
      const snapshots2 = harness.runFrames(60);

      const snap1 = snapshots1.get(60);
      const snap2 = snapshots2.get(60);
      expect(snap1).toBeDefined();
      expect(snap2).toBeDefined();

      if (snap1 && snap2) {
        const differences = compareSnapshots(snap1, snap2, 0.01);
        expect(differences).toEqual([]);
      }
    });

    it('should produce consistent Random Weapon results with same seed', () => {
      const scenario: ReplayScenario = {
        name: 'random_weapon_determinism',
        seed: 55555,
        durationFrames: 60,
        initialState: {
          playerPosition: { x: 0, y: 0 },
          gameMode: 'survival',
        },
        inputs: [
          { frameNumber: 10, type: 'selectPerk', data: { perkId: 17 } }, // Random Weapon
        ],
      };

      harness.setupScenario(scenario);
      const snapshots1 = harness.runFrames(60);

      harness.setupScenario(scenario);
      const snapshots2 = harness.runFrames(60);

      const snap1 = snapshots1.get(60);
      const snap2 = snapshots2.get(60);
      expect(snap1).toBeDefined();
      expect(snap2).toBeDefined();

      if (snap1 && snap2) {
        const differences = compareSnapshots(snap1, snap2, 0.01);
        expect(differences).toEqual([]);
      }
    });
  });

  describe('Input Application Determinism', () => {
    it('should process move inputs deterministically', () => {
      const scenario: ReplayScenario = {
        name: 'move_input_determinism',
        seed: 33333,
        durationFrames: 60,
        initialState: {
          playerPosition: { x: 0, y: 0 },
          gameMode: 'survival',
        },
        inputs: [
          { frameNumber: 10, type: 'move', data: { dx: 1, dy: 0 } },
          { frameNumber: 20, type: 'move', data: { dx: 0, dy: 1 } },
          { frameNumber: 30, type: 'move', data: { dx: -1, dy: 0 } },
          { frameNumber: 40, type: 'move', data: { dx: 0, dy: -1 } },
        ],
      };

      harness.setupScenario(scenario);
      const snapshots1 = harness.runFrames(60, 15);

      harness.setupScenario(scenario);
      const snapshots2 = harness.runFrames(60, 15);

      for (const [frame, snapshot1] of snapshots1) {
        const snapshot2 = snapshots2.get(frame);
        expect(snapshot2).toBeDefined();
        if (snapshot2) {
          const differences = compareSnapshots(snapshot1, snapshot2, 0.01);
          expect(differences).toEqual([]);
        }
      }
    });

    it('should process fire inputs deterministically', () => {
      const scenario: ReplayScenario = {
        name: 'fire_input_determinism',
        seed: 44444,
        durationFrames: 90,
        initialState: {
          playerPosition: { x: 0, y: 0 },
          gameMode: 'survival',
        },
        inputs: [
          { frameNumber: 10, type: 'fire', data: {} },
          { frameNumber: 30, type: 'fire', data: {} },
          { frameNumber: 50, type: 'fire', data: {} },
        ],
      };

      harness.setupScenario(scenario);
      const snapshots1 = harness.runFrames(90, 15);

      harness.setupScenario(scenario);
      const snapshots2 = harness.runFrames(90, 15);

      for (const [frame, snapshot1] of snapshots1) {
        const snapshot2 = snapshots2.get(frame);
        expect(snapshot2).toBeDefined();
        if (snapshot2) {
          const differences = compareSnapshots(snapshot1, snapshot2, 0.01);
          expect(differences).toEqual([]);
        }
      }
    });
  });

  describe('Edge Cases', () => {
    it('should handle empty input sequences deterministically', () => {
      const scenario: ReplayScenario = {
        name: 'empty_input_determinism',
        seed: 66666,
        durationFrames: 120,
        initialState: {
          playerPosition: { x: 500, y: 500 },
          gameMode: 'survival',
        },
        inputs: [],
      };

      harness.setupScenario(scenario);
      const snapshots1 = harness.runFrames(120, 30);

      harness.setupScenario(scenario);
      const snapshots2 = harness.runFrames(120, 30);

      for (const [frame, snapshot1] of snapshots1) {
        const snapshot2 = snapshots2.get(frame);
        expect(snapshot2).toBeDefined();
        if (snapshot2) {
          const differences = compareSnapshots(snapshot1, snapshot2, 0.01);
          expect(differences).toEqual([]);
        }
      }
    });

    it('should handle rapid inputs deterministically', () => {
      const scenario: ReplayScenario = {
        name: 'rapid_input_determinism',
        seed: 77777,
        durationFrames: 60,
        initialState: {
          playerPosition: { x: 0, y: 0 },
          gameMode: 'survival',
        },
        inputs: [
          { frameNumber: 5, type: 'fire', data: {} },
          { frameNumber: 6, type: 'fire', data: {} },
          { frameNumber: 7, type: 'fire', data: {} },
          { frameNumber: 8, type: 'reload', data: {} },
          { frameNumber: 9, type: 'swapWeapon', data: {} },
        ],
      };

      harness.setupScenario(scenario);
      const snapshots1 = harness.runFrames(60, 10);

      harness.setupScenario(scenario);
      const snapshots2 = harness.runFrames(60, 10);

      for (const [frame, snapshot1] of snapshots1) {
        const snapshot2 = snapshots2.get(frame);
        expect(snapshot2).toBeDefined();
        if (snapshot2) {
          const differences = compareSnapshots(snapshot1, snapshot2, 0.01);
          expect(differences).toEqual([]);
        }
      }
    });

    it('should handle multiple perk applications deterministically', () => {
      const scenario: ReplayScenario = {
        name: 'multi_perk_determinism',
        seed: 88888,
        durationFrames: 120,
        initialState: {
          playerPosition: { x: 0, y: 0 },
          gameMode: 'survival',
        },
        inputs: [
          { frameNumber: 10, type: 'selectPerk', data: { perkId: 0 } }, // BLOODY_MESS
          { frameNumber: 20, type: 'selectPerk', data: { perkId: 2 } }, // FAST_RELOADER
          { frameNumber: 30, type: 'selectPerk', data: { perkId: 4 } }, // FASTER_MOVES
        ],
      };

      harness.setupScenario(scenario);
      const snapshots1 = harness.runFrames(120, 20);

      harness.setupScenario(scenario);
      const snapshots2 = harness.runFrames(120, 20);

      for (const [frame, snapshot1] of snapshots1) {
        const snapshot2 = snapshots2.get(frame);
        expect(snapshot2).toBeDefined();
        if (snapshot2) {
          const differences = compareSnapshots(snapshot1, snapshot2, 0.01);
          expect(differences).toEqual([]);
        }
      }
    });
  });
});
