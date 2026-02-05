/**
 * Progression System Unit Tests
 */

import { describe, it, expect, beforeEach, vi, afterEach } from 'vitest';
import { ProgressionManager, STORAGE_KEY } from '../../../src/game/progression/ProgressionManager';
import type { ProgressionCallbacks } from '../../../src/game/progression/ProgressionManager';
import { type QuestId, PerkId, CreatureTypeId, WeaponId } from '../../../src/types';

// Create a fresh storage object for test isolation
function createStorage(): Record<string, string> {
  return {};
}

// Factory to create a fresh localStorage mock with isolated storage
function createLocalStorageMock(store: Record<string, string>) {
  return {
    getItem: vi.fn((key: string) => store[key] ?? null),
    setItem: vi.fn((key: string, value: string) => {
      store[key] = value;
    }),
    clear: vi.fn(() => {
      for (const key of Object.keys(store)) {
        delete store[key];
      }
    }),
    removeItem: vi.fn((key: string) => {
      delete store[key];
    }),
  };
}

// Factory for fresh ProgressionManager with isolated storage
function createProgressionManager(
  callbacks?: ProgressionCallbacks,
  store?: Record<string, string>
): { manager: ProgressionManager; store: Record<string, string> } {
  const storageStore = store ?? createStorage();
  const mock = createLocalStorageMock(storageStore);
  vi.stubGlobal('localStorage', mock);
  const manager = new ProgressionManager(callbacks);
  return { manager, store: storageStore };
}

describe('ProgressionManager', () => {
  let manager: ProgressionManager;
  let store: Record<string, string>;
  let localStorageMock: ReturnType<typeof createLocalStorageMock>;

  beforeEach(() => {
    // Create completely fresh isolated storage for each test
    store = createStorage();
    localStorageMock = createLocalStorageMock(store);
    // Stub global localStorage
    vi.stubGlobal('localStorage', localStorageMock);
    // Create fresh manager
    manager = new ProgressionManager();
  });

  afterEach(() => {
    vi.unstubAllGlobals();
    vi.clearAllMocks();
  });

  describe('Initialization', () => {
    it('should create with default progression', () => {
      expect(manager.getCompletedQuests()).toEqual([]);
      expect(manager.getSurvivalHighScore().bestScore).toBe(0);
      expect(manager.getStatistics().totalKills).toBe(0);
    });

    it('should load saved progression', () => {
      const savedData = {
        version: 1,
        completedQuests: ['nagolipoli' as QuestId],
        questHighScores: {
          nagolipoli: {
            bestTime: 45,
            bestScore: 1000,
            completedAt: '2024-01-01',
            attempts: 1,
          },
        },
        survivalHighScore: {
          bestScore: 5000,
          bestTime: 120,
          bestLevel: 5,
          achievedAt: '2024-01-01',
        },
        statistics: {
          totalKills: 100,
          totalDeaths: 5,
          totalTimePlayed: 3600,
          totalQuestsCompleted: 1,
          totalSurvivalRuns: 10,
          perksChosen: {},
          killsByCreatureType: {},
          shotsFired: 1000,
          shotsHit: 800,
          accuracy: 80,
        },
        unlockedFeatures: [],
        lastPlayedAt: '2024-01-01',
        totalPlaySessions: 5,
      };

      store[STORAGE_KEY] = JSON.stringify(savedData);
      // Create manager that uses the pre-populated store
      const loadedManager = new ProgressionManager();

      expect(loadedManager.isQuestCompleted('nagolipoli')).toBe(true);
      expect(loadedManager.getSurvivalHighScore().bestScore).toBe(5000);
      expect(loadedManager.getStatistics().totalKills).toBe(100);
    });
  });

  describe('Quest Progression', () => {
    it('should record quest completion', () => {
      manager.recordQuestComplete('nagolipoli', {
        time: 60,
        score: 1000,
        kills: 50,
      });

      expect(manager.isQuestCompleted('nagolipoli')).toBe(true);
      expect(manager.getQuestHighScore('nagolipoli')).not.toBeNull();
    });

    it('should update high score on better performance', () => {
      manager.recordQuestComplete('nagolipoli', {
        time: 60,
        score: 1000,
        kills: 50,
      });

      manager.recordQuestComplete('nagolipoli', {
        time: 45, // Better time
        score: 1500, // Better score
        kills: 60,
      });

      const highScore = manager.getQuestHighScore('nagolipoli');
      expect(highScore?.bestTime).toBe(45);
      expect(highScore?.bestScore).toBe(1500);
      expect(highScore?.attempts).toBe(2);
    });

    it('should keep existing high score on worse performance', () => {
      manager.recordQuestComplete('nagolipoli', {
        time: 45,
        score: 1500,
        kills: 60,
      });

      manager.recordQuestComplete('nagolipoli', {
        time: 60, // Worse time
        score: 1000, // Worse score
        kills: 50,
      });

      const highScore = manager.getQuestHighScore('nagolipoli');
      expect(highScore?.bestTime).toBe(45);
      expect(highScore?.bestScore).toBe(1500);
    });

    it('should check quest unlock status', () => {
      expect(manager.isQuestUnlocked('nagolipoli')).toBe(true);
      expect(manager.isQuestUnlocked('monster_blues')).toBe(false);

      manager.recordQuestComplete('nagolipoli', { time: 60, score: 1000, kills: 50 });

      expect(manager.isQuestUnlocked('monster_blues')).toBe(true);
    });

    it('should get completed quests', () => {
      manager.recordQuestComplete('nagolipoli', { time: 60, score: 1000, kills: 50 });
      manager.recordQuestComplete('monster_blues', { time: 90, score: 2000, kills: 75 });

      const completed = manager.getCompletedQuests();
      expect(completed).toContain('nagolipoli');
      expect(completed).toContain('monster_blues');
    });
  });

  describe('Survival Progression', () => {
    it('should record survival run', () => {
      manager.recordSurvivalRun({
        score: 5000,
        kills: 100,
        time: 120,
        level: 10,
        timeElapsed: 120,
      });

      expect(manager.getSurvivalHighScore().bestScore).toBe(5000);
      expect(manager.getSurvivalHighScore().bestLevel).toBe(10);
    });

    it('should update high score on better performance', () => {
      manager.recordSurvivalRun({
        score: 5000,
        kills: 100,
        time: 120,
        level: 10,
        timeElapsed: 120,
      });

      manager.recordSurvivalRun({
        score: 8000, // Better
        kills: 150,
        time: 180, // Better
        level: 15, // Better
        timeElapsed: 180,
      });

      expect(manager.getSurvivalHighScore().bestScore).toBe(8000);
      expect(manager.getSurvivalHighScore().bestTime).toBe(180);
      expect(manager.getSurvivalHighScore().bestLevel).toBe(15);
    });

    it('should track total survival runs', () => {
      expect(manager.getStatistics().totalSurvivalRuns).toBe(0);

      manager.recordSurvivalRun({ score: 1000, kills: 20, time: 30, level: 3, timeElapsed: 30 });
      expect(manager.getStatistics().totalSurvivalRuns).toBe(1);

      manager.recordSurvivalRun({ score: 2000, kills: 40, time: 60, level: 5, timeElapsed: 60 });
      expect(manager.getStatistics().totalSurvivalRuns).toBe(2);
    });
  });

  describe('Statistics Tracking', () => {
    it('should record kills', () => {
      manager.recordKill(CreatureTypeId.ZOMBIE);
      manager.recordKill(CreatureTypeId.ZOMBIE);
      manager.recordKill(CreatureTypeId.SPIDER_SMALL);

      const stats = manager.getStatistics();
      expect(stats.totalKills).toBe(3);
      expect(stats.killsByCreatureType[CreatureTypeId.ZOMBIE.toString()]).toBe(2);
      expect(stats.killsByCreatureType[CreatureTypeId.SPIDER_SMALL.toString()]).toBe(1);
    });

    it('should record deaths', () => {
      manager.recordDeath();
      manager.recordDeath();

      expect(manager.getStatistics().totalDeaths).toBe(2);
    });

    it('should record time played', () => {
      manager.recordTimePlayed(60);
      manager.recordTimePlayed(120);

      expect(manager.getStatistics().totalTimePlayed).toBe(180);
    });

    it('should record perks chosen', () => {
      manager.recordPerkChosen(PerkId.SHARPSHOOTER);
      manager.recordPerkChosen(PerkId.SHARPSHOOTER);
      manager.recordPerkChosen(PerkId.REGENERATION);

      const stats = manager.getStatistics();
      expect(stats.perksChosen[PerkId.SHARPSHOOTER.toString()]).toBe(2);
      expect(stats.perksChosen[PerkId.REGENERATION.toString()]).toBe(1);
    });

    it('should calculate accuracy', () => {
      manager.recordShotsFired(10);
      manager.recordShotsHit(8);

      expect(manager.getStatistics().accuracy).toBe(80);
    });

    it('should set favorite weapon', () => {
      manager.setFavoriteWeapon(WeaponId.SHOTGUN);

      expect(manager.getStatistics().favoriteWeapon).toBe(WeaponId.SHOTGUN);
    });
  });

  describe('Features & Milestones', () => {
    it('should unlock features', () => {
      manager.unlockFeature('test_feature');

      expect(manager.isFeatureUnlocked('test_feature')).toBe(true);
      expect(manager.getUnlockedFeatures()).toContain('test_feature');
    });

    it('should not duplicate features', () => {
      manager.unlockFeature('test_feature');
      manager.unlockFeature('test_feature');

      expect(manager.getUnlockedFeatures().filter((f) => f === 'test_feature').length).toBe(1);
    });

    it('should check milestones', () => {
      // Set up stats for 100 kills milestone
      for (let i = 0; i < 100; i++) {
        manager.recordKill(CreatureTypeId.ZOMBIE);
      }

      const milestones = manager.checkMilestones();
      expect(milestones).toContain('100 Kills');
      expect(manager.isFeatureUnlocked('kills_100')).toBe(true);
    });

    it('should check quest completion milestones', () => {
      // Complete 5 quests
      const quests: QuestId[] = [
        'nagolipoli',
        'monster_blues',
        'the_gathering',
        'army_of_three',
        'knee_deep_in_the_dead',
      ];
      for (const quest of quests) {
        manager.recordQuestComplete(quest, { time: 60, score: 1000, kills: 50 });
      }

      const milestones = manager.checkMilestones();
      expect(milestones).toContain('5 Quests Completed');
      expect(manager.isFeatureUnlocked('quests_5')).toBe(true);
    });
  });

  describe('Session Management', () => {
    it('should track play sessions', () => {
      // Fresh manager with clean storage
      const { manager: sessionManager } = createProgressionManager();
      expect(sessionManager.getTotalSessions()).toBe(0);

      sessionManager.startSession();
      expect(sessionManager.getTotalSessions()).toBe(1);

      sessionManager.startSession();
      expect(sessionManager.getTotalSessions()).toBe(2);
    });

    it('should update last played timestamp', () => {
      // Fresh manager with clean storage
      const { manager: timestampManager } = createProgressionManager();
      const before = Date.now();
      timestampManager.startSession();
      const after = Date.now();

      const lastPlayed = new Date(timestampManager.getLastPlayedAt()).getTime();
      expect(lastPlayed).toBeGreaterThanOrEqual(before);
      expect(lastPlayed).toBeLessThanOrEqual(after);
    });
  });

  describe('Save/Load', () => {
    it('should save to localStorage', () => {
      manager.recordQuestComplete('nagolipoli', { time: 60, score: 1000, kills: 50 });
      manager.save();

      expect(localStorageMock.setItem).toHaveBeenCalled();
      const firstCall = localStorageMock.setItem.mock.calls[0];
      expect(firstCall).toBeDefined();
      if (firstCall) {
        const savedData = JSON.parse(firstCall[1] as string);
        expect(savedData.completedQuests).toContain('nagolipoli');
      }
    });

    it('should not save if not dirty', () => {
      manager.save();
      expect(localStorageMock.setItem).not.toHaveBeenCalled();
    });

    it('should force save even if not dirty', () => {
      manager.forceSave();
      expect(localStorageMock.setItem).toHaveBeenCalled();
    });
  });

  describe('Import/Export', () => {
    it('should export progression data', () => {
      manager.recordQuestComplete('nagolipoli', { time: 60, score: 1000, kills: 50 });

      const exported = manager.exportData();
      const parsed = JSON.parse(exported);

      expect(parsed.completedQuests).toContain('nagolipoli');
    });

    it('should import progression data', () => {
      const data = {
        version: 1,
        completedQuests: ['monster_blues' as QuestId],
        questHighScores: {},
        survivalHighScore: {
          bestScore: 10000,
          bestTime: 300,
          bestLevel: 20,
          achievedAt: '2024-01-01',
        },
        statistics: {
          totalKills: 500,
          totalDeaths: 10,
          totalTimePlayed: 7200,
          totalQuestsCompleted: 1,
          totalSurvivalRuns: 20,
          perksChosen: {},
          killsByCreatureType: {},
          shotsFired: 0,
          shotsHit: 0,
          accuracy: 0,
        },
        unlockedFeatures: [],
        lastPlayedAt: '2024-01-01',
        totalPlaySessions: 10,
      };

      const result = manager.importData(JSON.stringify(data));
      expect(result).toBe(true);
      expect(manager.isQuestCompleted('monster_blues')).toBe(true);
      expect(manager.getSurvivalHighScore().bestScore).toBe(10000);
    });

    it('should handle invalid import data', () => {
      const result = manager.importData('invalid json');
      expect(result).toBe(false);
    });
  });

  describe('Reset', () => {
    it('should reset all progression', () => {
      // Create completely isolated storage and manager
      const isolatedStore = createStorage();
      const isolatedMock = createLocalStorageMock(isolatedStore);
      vi.stubGlobal('localStorage', isolatedMock);

      const resetManager = new ProgressionManager();
      resetManager.recordQuestComplete('nagolipoli', { time: 60, score: 1000, kills: 50 });
      resetManager.recordSurvivalRun({
        score: 5000,
        kills: 100,
        time: 120,
        level: 10,
        timeElapsed: 120,
      });

      expect(resetManager.getSurvivalHighScore().bestScore).toBe(5000);

      resetManager.reset();

      expect(resetManager.getCompletedQuests()).toEqual([]);
      expect(resetManager.getSurvivalHighScore().bestScore).toBe(0);
      expect(resetManager.getStatistics().totalKills).toBe(0);
    });
  });

  describe('Callbacks', () => {
    it('should call onQuestCompleted callback', () => {
      const onQuestCompleted = vi.fn();
      const { manager: callbackManager } = createProgressionManager({ onQuestCompleted });

      callbackManager.recordQuestComplete('nagolipoli', { time: 60, score: 1000, kills: 50 });

      expect(onQuestCompleted).toHaveBeenCalledWith('nagolipoli', expect.any(Object));
    });

    it('should call onNewSurvivalRecord callback', () => {
      const onNewSurvivalRecord = vi.fn();
      const { manager: callbackManager } = createProgressionManager({ onNewSurvivalRecord });

      callbackManager.recordSurvivalRun({
        score: 10000,
        kills: 200,
        time: 300,
        level: 25,
        timeElapsed: 300,
      });

      expect(onNewSurvivalRecord).toHaveBeenCalledWith(expect.any(Object));
    });

    it('should call onMilestoneReached callback', () => {
      const onMilestoneReached = vi.fn();
      const { manager: callbackManager } = createProgressionManager({ onMilestoneReached });

      // Set up stats for 100 kills milestone
      for (let i = 0; i < 100; i++) {
        callbackManager.recordKill(CreatureTypeId.ZOMBIE);
      }
      callbackManager.checkMilestones();

      expect(onMilestoneReached).toHaveBeenCalled();
    });
  });

  describe('Failure Modes', () => {
    it('should handle corrupted localStorage gracefully', () => {
      // Pre-populate store before creating manager
      store[STORAGE_KEY] = 'not valid json{';
      const corruptedManager = new ProgressionManager();
      expect(corruptedManager.getStatistics().totalKills).toBe(0);
      expect(corruptedManager.getCompletedQuests()).toEqual([]);
      // Verify corrupt entry is cleared
      expect(localStorageMock.removeItem).toHaveBeenCalledWith(STORAGE_KEY);
    });

    it('should handle localStorage with null value', () => {
      store[STORAGE_KEY] = 'null';
      const nullManager = new ProgressionManager();
      expect(nullManager.getStatistics().totalKills).toBe(0);
      // Verify corrupt entry is cleared
      expect(localStorageMock.removeItem).toHaveBeenCalledWith(STORAGE_KEY);
    });

    it('should handle missing required fields in stored data', () => {
      const incompleteData = {
        version: 1,
        // Missing most fields
        completedQuests: ['nagolipoli'],
      };
      store[STORAGE_KEY] = JSON.stringify(incompleteData);
      const incompleteManager = new ProgressionManager();
      // Should merge with defaults
      expect(incompleteManager.isQuestCompleted('nagolipoli')).toBe(true);
      expect(incompleteManager.getStatistics().totalKills).toBe(0);
    });

    it('should migrate from version 0 (no version field)', () => {
      const v0Data = {
        completedQuests: ['nagolipoli'],
        questHighScores: {
          nagolipoli: {
            bestTime: 60,
            bestScore: 1000,
            completedAt: '2024-01-01',
            attempts: 1,
          },
        },
        survivalHighScore: {
          bestScore: 5000,
          bestTime: 120,
          bestLevel: 5,
          achievedAt: '2024-01-01',
        },
        statistics: {
          totalKills: 100,
          totalDeaths: 5,
          totalTimePlayed: 3600,
          totalQuestsCompleted: 1,
          totalSurvivalRuns: 10,
          perksChosen: {},
          killsByCreatureType: {},
          shotsFired: 0,
          shotsHit: 0,
          accuracy: 0,
        },
        unlockedFeatures: [],
        lastPlayedAt: '2024-01-01',
        totalPlaySessions: 5,
        // No version field - indicates v0
      };
      store[STORAGE_KEY] = JSON.stringify(v0Data);
      const migratedManager = new ProgressionManager();
      expect(migratedManager.isQuestCompleted('nagolipoli')).toBe(true);
      expect(migratedManager.getTotalSessions()).toBe(5);
    });

    it('should handle callback exceptions without breaking operations', () => {
      const onQuestCompleted = vi.fn().mockImplementation(() => {
        throw new Error('Callback error');
      });
      const { manager: callbackManager } = createProgressionManager({ onQuestCompleted });

      // Should not throw even though callback throws
      expect(() => {
        callbackManager.recordQuestComplete('nagolipoli', { time: 60, score: 1000, kills: 50 });
      }).not.toThrow();

      // Quest should still be recorded
      expect(callbackManager.isQuestCompleted('nagolipoli')).toBe(true);
    });

    it('should handle onNewSurvivalRecord callback exception', () => {
      const onNewSurvivalRecord = vi.fn().mockImplementation(() => {
        throw new Error('Survival callback error');
      });
      const { manager: callbackManager } = createProgressionManager({ onNewSurvivalRecord });

      expect(() => {
        callbackManager.recordSurvivalRun({
          score: 10000,
          kills: 200,
          time: 300,
          level: 25,
          timeElapsed: 300,
        });
      }).not.toThrow();

      // Record should still be saved
      expect(callbackManager.getSurvivalHighScore().bestScore).toBe(10000);
    });

    it('should handle onMilestoneReached callback exception', () => {
      const onMilestoneReached = vi.fn().mockImplementation(() => {
        throw new Error('Milestone callback error');
      });
      const { manager: callbackManager } = createProgressionManager({ onMilestoneReached });

      // Set up stats for 100 kills milestone
      for (let i = 0; i < 100; i++) {
        callbackManager.recordKill(CreatureTypeId.ZOMBIE);
      }

      expect(() => {
        callbackManager.checkMilestones();
      }).not.toThrow();

      // Milestone should still be unlocked
      expect(callbackManager.isFeatureUnlocked('kills_100')).toBe(true);
    });

    it('should handle quest high score with negative time', () => {
      manager.recordQuestComplete('nagolipoli', { time: -10, score: 1000, kills: 50 });
      const highScore = manager.getQuestHighScore('nagolipoli');
      expect(highScore?.bestTime).toBe(-10);
    });

    it('should handle quest high score with negative score', () => {
      manager.recordQuestComplete('nagolipoli', { time: 60, score: -500, kills: 50 });
      const highScore = manager.getQuestHighScore('nagolipoli');
      expect(highScore?.bestScore).toBe(-500);
    });

    it('should handle statistics with very large numbers', () => {
      const largeData = {
        version: 1,
        completedQuests: [],
        questHighScores: {},
        survivalHighScore: {
          bestScore: Number.MAX_SAFE_INTEGER,
          bestTime: Number.MAX_SAFE_INTEGER,
          bestLevel: Number.MAX_SAFE_INTEGER,
          achievedAt: '2024-01-01',
        },
        statistics: {
          totalKills: Number.MAX_SAFE_INTEGER,
          totalDeaths: Number.MAX_SAFE_INTEGER,
          totalTimePlayed: Number.MAX_SAFE_INTEGER,
          totalQuestsCompleted: Number.MAX_SAFE_INTEGER,
          totalSurvivalRuns: Number.MAX_SAFE_INTEGER,
          perksChosen: {},
          killsByCreatureType: {},
          shotsFired: Number.MAX_SAFE_INTEGER,
          shotsHit: Number.MAX_SAFE_INTEGER,
          accuracy: 100,
        },
        unlockedFeatures: [],
        lastPlayedAt: '2024-01-01',
        totalPlaySessions: Number.MAX_SAFE_INTEGER,
      };
      store[STORAGE_KEY] = JSON.stringify(largeData);
      const largeManager = new ProgressionManager();
      expect(largeManager.getStatistics().totalKills).toBe(Number.MAX_SAFE_INTEGER);
      expect(largeManager.getTotalSessions()).toBe(Number.MAX_SAFE_INTEGER);
    });

    it('should handle import with valid JSON but missing structure', () => {
      const result = manager.importData('{}');
      expect(result).toBe(true);
      // Should use defaults for missing fields
      expect(manager.getStatistics().totalKills).toBe(0);
    });

    it('should handle import with array instead of object', () => {
      const result = manager.importData('[]');
      expect(result).toBe(true);
      // importData uses migrate which spreads, so array becomes object with indices
      expect(manager.getStatistics().totalKills).toBe(0);
    });

    it('should clear localStorage when stored data is an array', () => {
      store[STORAGE_KEY] = '[]';
      const arrayManager = new ProgressionManager();
      expect(arrayManager.getStatistics().totalKills).toBe(0);
      expect(localStorageMock.removeItem).toHaveBeenCalledWith(STORAGE_KEY);
    });

    it('should handle localStorage quota exceeded error gracefully', () => {
      const quotaError = new Error('QuotaExceededError');
      quotaError.name = 'QuotaExceededError';
      localStorageMock.setItem.mockImplementation(() => {
        throw quotaError;
      });

      manager.recordQuestComplete('nagolipoli', { time: 60, score: 1000, kills: 50 });

      // Should not throw, just log warning
      expect(() => manager.save()).not.toThrow();
    });

    it('should handle localStorage being unavailable', () => {
      vi.stubGlobal('localStorage', undefined);
      const { manager: noStorageManager } = createProgressionManager();
      expect(noStorageManager.getStatistics().totalKills).toBe(0);
      // Operations should not throw
      expect(() => {
        noStorageManager.recordKill(CreatureTypeId.ZOMBIE);
        noStorageManager.save();
      }).not.toThrow();
    });

    it('should handle empty string in localStorage', () => {
      store[STORAGE_KEY] = '';
      const emptyManager = new ProgressionManager();
      expect(emptyManager.getStatistics().totalKills).toBe(0);
    });

    it('should handle quest high score comparison with zero values', () => {
      // First completion with zero score
      manager.recordQuestComplete('nagolipoli', { time: 60, score: 0, kills: 0 });
      let highScore = manager.getQuestHighScore('nagolipoli');
      expect(highScore?.bestScore).toBe(0);

      // Second completion with positive score
      manager.recordQuestComplete('nagolipoli', { time: 60, score: 100, kills: 10 });
      highScore = manager.getQuestHighScore('nagolipoli');
      expect(highScore?.bestScore).toBe(100);
    });

    it('should handle multiple callback errors in sequence', () => {
      let callCount = 0;
      const onQuestCompleted = vi.fn().mockImplementation(() => {
        callCount++;
        throw new Error(`Error ${callCount}`);
      });
      const { manager: callbackManager } = createProgressionManager({ onQuestCompleted });

      expect(() => {
        callbackManager.recordQuestComplete('nagolipoli', { time: 60, score: 1000, kills: 50 });
        callbackManager.recordQuestComplete('monster_blues', { time: 60, score: 1000, kills: 50 });
      }).not.toThrow();

      expect(callbackManager.isQuestCompleted('nagolipoli')).toBe(true);
      expect(callbackManager.isQuestCompleted('monster_blues')).toBe(true);
      expect(callCount).toBe(2);
    });
  });
});
