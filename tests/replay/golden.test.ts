/**
 * Golden File Replay Tests
 *
 * These tests compare against known-good state snapshots.
 * Run with UPDATE_GOLDEN=1 to regenerate golden files.
 */

import { describe, it, expect, beforeEach, afterEach } from 'vitest';
import { readFileSync, writeFileSync, existsSync, mkdirSync } from 'node:fs';
import { join } from 'node:path';
import { ReplayHarness } from './ReplayHarness';
import { serializeSnapshot, deserializeSnapshot, compareSnapshots } from './StateSnapshot';
import type { ReplayScenario } from './ReplayHarness';

// Use relative path from project root for golden files
const GOLDEN_DIR = join(process.cwd(), 'tests/replay/golden');
const UPDATE_GOLDEN = process.env.UPDATE_GOLDEN === '1';

// Predefined scenarios for golden file testing
const GOLDEN_SCENARIOS: ReplayScenario[] = [
  {
    name: 'survival_wave1',
    seed: 10001,
    durationFrames: 180, // 3 seconds
    initialState: { playerPosition: { x: 0, y: 0 }, gameMode: 'survival' },
    inputs: [],
  },
  {
    name: 'quest_nagolipoli',
    seed: 10002,
    durationFrames: 300, // 5 seconds
    initialState: { playerPosition: { x: 0, y: 0 }, gameMode: 'quest', questId: 'nagolipoli' },
    inputs: [],
  },
  {
    name: 'weapon_firing',
    seed: 10003,
    durationFrames: 60,
    initialState: { playerPosition: { x: 0, y: 0 }, gameMode: 'survival' },
    inputs: [
      { frameNumber: 5, type: 'fire', data: {} },
      { frameNumber: 10, type: 'fire', data: {} },
      { frameNumber: 15, type: 'fire', data: {} },
    ],
  },
  {
    name: 'perk_fatal_lottery',
    seed: 10004,
    durationFrames: 60,
    initialState: { playerPosition: { x: 0, y: 0 }, gameMode: 'survival' },
    inputs: [
      { frameNumber: 10, type: 'selectPerk', data: { perkId: 42 } },
    ],
  },
  {
    name: 'movement_sequence',
    seed: 10005,
    durationFrames: 120,
    initialState: { playerPosition: { x: 0, y: 0 }, gameMode: 'survival' },
    inputs: [
      { frameNumber: 10, type: 'moveTo', data: { x: 100, y: 0 } },
      { frameNumber: 30, type: 'moveTo', data: { x: 100, y: 100 } },
      { frameNumber: 60, type: 'moveTo', data: { x: 0, y: 100 } },
      { frameNumber: 90, type: 'moveTo', data: { x: 0, y: 0 } },
    ],
  },
];

describe('Golden File Tests', () => {
  let harness: ReplayHarness;

  beforeEach(() => {
    harness = new ReplayHarness();
    if (!existsSync(GOLDEN_DIR)) {
      mkdirSync(GOLDEN_DIR, { recursive: true });
    }
  });

  afterEach(() => {
    harness.destroy();
  });

  for (const scenario of GOLDEN_SCENARIOS) {
    it(`should match golden file: ${scenario.name}`, () => {
      const goldenPath = join(GOLDEN_DIR, `${scenario.name}.golden`);

      harness.setupScenario(scenario);
      const snapshots = harness.runFrames(scenario.durationFrames, 30);

      if (UPDATE_GOLDEN || !existsSync(goldenPath)) {
        // Write golden file
        const data = JSON.stringify(
          Array.from(snapshots.entries()).map(([frame, snapshot]) => ({
            frame,
            snapshot: serializeSnapshot(snapshot),
          })),
          null,
          2
        );
        writeFileSync(goldenPath, data);
        console.log(`Updated golden file: ${goldenPath}`);
        return;
      }

      // Read and compare against golden file
      const goldenData = JSON.parse(readFileSync(goldenPath, 'utf-8')) as Array<{
        frame: number;
        snapshot: string;
      }>;

      for (const { frame, snapshot: goldenSnapshotStr } of goldenData) {
        const actualSnapshot = snapshots.get(frame);
        expect(actualSnapshot).toBeDefined();

        const goldenSnapshot = deserializeSnapshot(goldenSnapshotStr);

        // Use the compareSnapshots function for detailed comparison
        if (actualSnapshot) {
          const differences = compareSnapshots(goldenSnapshot, actualSnapshot, 0.01);

          if (differences.length > 0) {
            console.log(`Differences at frame ${frame}:`, differences);
          }

          expect(differences).toEqual([]);
        }
      }
    });
  }
});
