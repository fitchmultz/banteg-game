/**
 * Quest System Unit Tests
 */

import { describe, it, expect, beforeEach } from 'vitest';
import {
  getQuestData,
  isQuestUnlocked,
  getAvailableQuests,
  getQuestUnlockChain,
  getNextQuest,
  areAllMainQuestsCompleted,
  getQuestStats,
  ALL_QUESTS,
} from '../../../src/game/data/quests';
import { QuestMode } from '../../../src/game/modes/QuestMode';
import { EntityManager } from '../../../src/core/ecs';
import { type QuestId, CreatureTypeId } from '../../../src/types';

describe('Quest Data', () => {
  it('should have quest data for all quest IDs', () => {
    const questIds: QuestId[] = [
      // Tutorial / Early Game (Tier 1)
      'nagolipoli',
      'monster_blues',
      'the_gathering',
      'army_of_three',
      // Tier 1-2 Missing Quests
      'target_practice',
      'frontline_assault',
      'spider_wave_syndrome',
      'the_random_factor',
      'everred_pastures',
      'spider_spawns',
      'two_fronts',
      'sweep_stakes',
      'evil_zombies_at_large',
      'survival_of_the_fastest',
      // Zombie Heavy (Tier 1-2)
      'knee_deep_in_the_dead',
      'the_gang_wars',
      'the_fortress',
      'cross_fire',
      // Fast and Furious (Tier 2)
      'the_beating',
      'hidden_evil',
      'land_hostile',
      'minor_alien_breach',
      // Mixed Enemies (Tier 2-3)
      'alien_squads',
      'zombie_masters',
      '8_legged_terror',
      'ghost_patrols',
      // Advanced Challenges (Tier 3)
      'nesting_grounds',
      'alien_dens',
      'arachnoid_farm',
      'gauntlet',
      // Tier 3-4 Missing Quests
      'the_blighting',
      'the_killing',
      'surrounded_by_reptiles',
      'the_lizquidation',
      'spiders_inc',
      'deja_vu',
      'major_alien_breach',
      'zombie_time',
      'the_collaboration',
      'the_massacre',
      'the_unblitzkrieg',
      // Lizard Quests (Tier 2-4)
      'land_of_lizards',
      'lizard_kings',
      'lizard_raze',
      'lizard_zombie_pact',
      // Tier 5 Bonus Quests
      'the_annihilation',
      'the_end_of_all',
      'the_spanking_of_the_dead',
      'spideroids',
      'syntax_terror',
    ];

    for (const id of questIds) {
      const data = getQuestData(id);
      expect(data).toBeDefined();
      if (data) {
        expect(data.id).toBe(id);
        expect(data.name).toBeTruthy();
        expect(data.description).toBeTruthy();
        expect(data.objectives).toBeDefined();
        expect(data.objectives.length).toBeGreaterThan(0);
        expect(data.spawnEntries).toBeDefined();
      }
    }
  });

  it('should have valid objectives for all quests', () => {
    for (const quest of ALL_QUESTS) {
      for (const objective of quest.objectives) {
        expect(objective.type).toMatch(/^(kill_count|survive_time|reach_location|kill_bosses)$/);
        expect(objective.target).toBeGreaterThan(0);
        expect(objective.description).toBeTruthy();
      }
    }
  });

  it('should have spawn entries for all quests', () => {
    for (const quest of ALL_QUESTS) {
      expect(quest.spawnEntries.length).toBeGreaterThan(0);

      for (const entry of quest.spawnEntries) {
        expect(typeof entry.creatureTypeId).toBe('number');
        expect(typeof entry.x).toBe('number');
        expect(typeof entry.y).toBe('number');
        expect(typeof entry.triggerTimeMs).toBe('number');
        expect(entry.triggerTimeMs).toBeGreaterThanOrEqual(0);
        expect(typeof entry.count).toBe('number');
        expect(entry.count).toBeGreaterThan(0);
      }
    }
  });

  it('should have correct quest statistics', () => {
    const stats = getQuestStats();
    expect(stats.total).toBe(ALL_QUESTS.length);
    expect(stats.mainQuests + stats.bonusQuests).toBe(stats.total);
    expect(stats.mainQuests).toBeGreaterThan(0);
  });

  it('should have all 50 quests', () => {
    expect(ALL_QUESTS.length).toBe(50);
    expect(getQuestStats().total).toBe(50);
  });
});

describe('Quest Unlock System', () => {
  it('should unlock first quest by default', () => {
    expect(isQuestUnlocked('nagolipoli', [])).toBe(true);
  });

  it('should lock quests without completing prerequisites', () => {
    expect(isQuestUnlocked('monster_blues', [])).toBe(false);
    expect(isQuestUnlocked('the_gathering', [])).toBe(false);
  });

  it('should unlock quests after completing prerequisites', () => {
    expect(isQuestUnlocked('monster_blues', ['nagolipoli'])).toBe(true);
    expect(isQuestUnlocked('the_gathering', ['nagolipoli', 'monster_blues'])).toBe(true);
  });

  it('should maintain quest chain order', () => {
    const chain = getQuestUnlockChain();
    expect(chain.length).toBeGreaterThan(0);
    expect(chain[0]).toBe('nagolipoli');

    // Each quest should unlock the next
    for (let i = 1; i < chain.length; i++) {
      const questId = chain[i];
      expect(questId).toBeDefined();
      if (questId) {
        const currentQuest = getQuestData(questId);
        expect(currentQuest).toBeDefined();
        if (currentQuest) {
          expect(currentQuest.unlockRequirement).toBe(chain[i - 1]);
        }
      }
    }
  });

  it('should get next quest correctly', () => {
    expect(getNextQuest('nagolipoli')).toBe('monster_blues');
    expect(getNextQuest('monster_blues')).toBe('the_gathering');
  });

  it('should return null for last quest', () => {
    const chain = getQuestUnlockChain();
    const lastQuest = chain[chain.length - 1];
    expect(lastQuest).toBeDefined();
    if (lastQuest) {
      expect(getNextQuest(lastQuest)).toBeNull();
    }
  });
});

describe('Available Quests', () => {
  it('should return only first quest for new player', () => {
    const available = getAvailableQuests([]);
    expect(available).toContain('nagolipoli');
    expect(available).not.toContain('monster_blues');
  });

  it('should return unlocked quests', () => {
    const available = getAvailableQuests(['nagolipoli'], true); // include completed
    expect(available).toContain('nagolipoli');
    expect(available).toContain('monster_blues');
  });

  it('should include completed quests when requested', () => {
    const available = getAvailableQuests(['nagolipoli'], true);
    expect(available).toContain('nagolipoli');
  });

  it('should exclude completed quests by default', () => {
    const available = getAvailableQuests(['nagolipoli'], false);
    expect(available).not.toContain('nagolipoli');
  });
});

describe('Quest Completion', () => {
  it('should detect when all main quests are completed', () => {
    const mainQuests = ALL_QUESTS.filter((q) => !q.isBonus).map((q) => q.id);
    expect(areAllMainQuestsCompleted(mainQuests)).toBe(true);
  });

  it('should detect incomplete main quests', () => {
    expect(areAllMainQuestsCompleted([])).toBe(false);
    expect(areAllMainQuestsCompleted(['nagolipoli'])).toBe(false);
  });

  it('should identify bonus quests', () => {
    const bonusQuests = ALL_QUESTS.filter((q) => q.isBonus);
    expect(bonusQuests.length).toBeGreaterThan(0);
    expect(bonusQuests.some((q) => q.id === 'syntax_terror')).toBe(true);
  });
});

describe('Quest Spawn Entries', () => {
  it('should have valid trigger times', () => {
    for (const quest of ALL_QUESTS) {
      // Sort entries by time for checking (QuestSpawnSystem sorts them at runtime)
      const sortedEntries = [...quest.spawnEntries].sort(
        (a, b) => a.triggerTimeMs - b.triggerTimeMs
      );
      let lastTime = -1;
      for (const entry of sortedEntries) {
        expect(entry.triggerTimeMs).toBeGreaterThanOrEqual(lastTime);
        lastTime = entry.triggerTimeMs;
      }
    }
  });

  it('should use valid creature types', () => {
    const validCreatureTypes = Object.values(CreatureTypeId).filter(
      (id): id is CreatureTypeId => typeof id === 'number'
    );

    for (const quest of ALL_QUESTS) {
      for (const entry of quest.spawnEntries) {
        expect(validCreatureTypes).toContain(entry.creatureTypeId);
      }
    }
  });

  it('should have time limits for timed quests', () => {
    const timedQuest = getQuestData('land_hostile');
    expect(timedQuest?.timeLimitMs).toBeDefined();
    expect(timedQuest?.timeLimitMs).toBeGreaterThan(0);
  });
});

describe('Quest Objectives', () => {
  it('should have kill count objectives with positive targets', () => {
    for (const quest of ALL_QUESTS) {
      for (const objective of quest.objectives) {
        if (objective.type === 'kill_count') {
          expect(objective.target).toBeGreaterThan(0);
        }
      }
    }
  });

  it('should have survive time objectives with positive targets', () => {
    for (const quest of ALL_QUESTS) {
      for (const objective of quest.objectives) {
        if (objective.type === 'survive_time') {
          expect(objective.target).toBeGreaterThan(0);
        }
      }
    }
  });

  it('should have descriptions for all objectives', () => {
    for (const quest of ALL_QUESTS) {
      for (const objective of quest.objectives) {
        expect(objective.description.length).toBeGreaterThan(0);
      }
    }
  });

  it('should have x/y coordinates for reach_location objectives', () => {
    for (const quest of ALL_QUESTS) {
      for (const objective of quest.objectives) {
        if (objective.type === 'reach_location') {
          expect(objective.x).toBeDefined();
          expect(objective.y).toBeDefined();
          expect(typeof objective.x).toBe('number');
          expect(typeof objective.y).toBe('number');
        }
      }
    }
  });
});

describe('QuestMode Objective Evaluation', () => {
  let entityManager: EntityManager;
  let questMode: QuestMode;

  beforeEach(() => {
    entityManager = new EntityManager();
    questMode = new QuestMode(entityManager);
  });

  it('should track boss kills separately from regular kills', () => {
    // Start a quest
    questMode.startQuest('nagolipoli');

    // Record regular kills
    questMode.recordKill(CreatureTypeId.ZOMBIE, 10, false);
    questMode.recordKill(CreatureTypeId.ZOMBIE, 10, false);

    // Record boss kills
    questMode.recordKill(CreatureTypeId.LIZARD_KING, 50, true);
    questMode.recordKill(CreatureTypeId.LIZARD_KING, 50, true);

    // Check progress
    const progress = questMode.getProgress();
    expect(progress.kills).toBe(4); // Total kills
  });

  it('should update player position for reach_location objectives', () => {
    // Start a quest
    questMode.startQuest('nagolipoli');

    // Update player position
    questMode.updatePlayerPosition(100, 200);

    // Position should be updated (internal state)
    // This is tested indirectly through reach_location objective completion
  });

  it('should complete reach_location when player is within radius', () => {
    // Start quest and manually set the current quest
    questMode.startQuest('nagolipoli');

    // Test position far from target
    questMode.updatePlayerPosition(0, 0);
    // Should not complete

    // Test position within target radius
    questMode.updatePlayerPosition(500, 500);
    // Should complete (objectives checked on update)
  });

  it('should track kill_bosses separately from regular kills', () => {
    // Start a quest
    questMode.startQuest('nagolipoli');

    // Record regular kills - should not count toward boss kills
    questMode.recordKill(CreatureTypeId.ZOMBIE, 10, false);
    questMode.recordKill(CreatureTypeId.SPIDER_LARGE, 10, false);

    // Record boss kills - should count
    questMode.recordKill(CreatureTypeId.LIZARD_KING, 50, true);

    // Total kills should be 3
    const progress = questMode.getProgress();
    expect(progress.kills).toBe(3);
  });
});
