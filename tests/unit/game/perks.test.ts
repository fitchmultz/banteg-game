/**
 * Perk System Unit Tests
 */

import { describe, it, expect, vi } from 'vitest';
import {
  getPerkData,
  isPerkCompatible,
  getAvailablePerks,
  generatePerkChoices,
  calculateDamageMultiplier,
  calculateFireRateMultiplier,
  calculateReloadSpeedMultiplier,
  calculateMoveSpeedMultiplier,
  calculateMaxHealthMultiplier,
  calculateXpMultiplier,
  calculateHealthRegen,
  calculateBonusDurationMultiplier,
  calculateClipSizeBonus,
  ALL_PERKS,
  type PerkCategory,
} from '../../../src/game/data/perks';
import { PerkId } from '../../../src/types';

describe('Perk Data', () => {
  it('should have perk data for all defined perk IDs', () => {
    // Test that all perks in ALL_PERKS have valid data
    for (const perk of ALL_PERKS) {
      expect(perk.id).toBeDefined();
      expect(perk.name).toBeTruthy();
      expect(perk.description).toBeTruthy();
      expect(perk.category).toBeTruthy();
      expect(perk.maxRank).toBeGreaterThan(0);
      expect(perk.effects).toBeDefined();

      // Verify getPerkData returns correct data
      const data = getPerkData(perk.id);
      expect(data).toBeDefined();
      expect(data?.id).toBe(perk.id);
    }
  });

  it('should have valid categories for all perks', () => {
    const validCategories: PerkCategory[] = [
      'combat',
      'defense',
      'utility',
      'movement',
      'special',
      'gamble',
      'meta',
    ];

    for (const perk of ALL_PERKS) {
      expect(validCategories).toContain(perk.category);
    }
  });

  it('should define incompatible perks correctly', () => {
    const thickSkinned = getPerkData(PerkId.THICK_SKINNED);
    expect(thickSkinned!.incompatibleWith).toContain(PerkId.REGENERATION);
    expect(thickSkinned!.incompatibleWith).toContain(PerkId.GREATER_REGENERATION);
  });

  it('should define prerequisite perks correctly', () => {
    const greaterRegen = getPerkData(PerkId.GREATER_REGENERATION);
    expect(greaterRegen!.requiresPerk).toBe(PerkId.REGENERATION);

    const perkMaster = getPerkData(PerkId.PERK_MASTER);
    expect(perkMaster!.requiresPerk).toBe(PerkId.PERK_EXPERT);
  });
});

describe('Perk Compatibility', () => {
  it('should allow selecting compatible perks', () => {
    const selectedPerks = new Map<PerkId, number>();

    expect(isPerkCompatible(PerkId.SHARPSHOOTER, selectedPerks)).toBe(true);
    expect(isPerkCompatible(PerkId.FASTSHOT, selectedPerks)).toBe(true);
    expect(isPerkCompatible(PerkId.REGENERATION, selectedPerks)).toBe(true);
  });

  it('should prevent selecting incompatible perks', () => {
    const selectedPerks = new Map<PerkId, number>([[PerkId.THICK_SKINNED, 1]]);

    expect(isPerkCompatible(PerkId.REGENERATION, selectedPerks)).toBe(false);
    expect(isPerkCompatible(PerkId.GREATER_REGENERATION, selectedPerks)).toBe(false);
  });

  it('should prevent selecting perks without prerequisites', () => {
    const selectedPerks = new Map<PerkId, number>();

    expect(isPerkCompatible(PerkId.GREATER_REGENERATION, selectedPerks)).toBe(false);
    expect(isPerkCompatible(PerkId.PERK_MASTER, selectedPerks)).toBe(false);
  });

  it('should allow selecting perks with prerequisites met', () => {
    const selectedPerks = new Map<PerkId, number>([[PerkId.REGENERATION, 1]]);

    expect(isPerkCompatible(PerkId.GREATER_REGENERATION, selectedPerks)).toBe(true);
  });

  it('should prevent exceeding max rank', () => {
    const sharpshooterData = getPerkData(PerkId.SHARPSHOOTER)!;
    const selectedPerks = new Map<PerkId, number>([
      [PerkId.SHARPSHOOTER, sharpshooterData.maxRank],
    ]);

    expect(isPerkCompatible(PerkId.SHARPSHOOTER, selectedPerks)).toBe(false);
  });
});

describe('Perk Choices Generation', () => {
  it('should generate valid perk choices', () => {
    const selectedPerks = new Map<PerkId, number>();
    const choices = generatePerkChoices(selectedPerks, 1, false, false);

    expect(choices.length).toBeGreaterThan(0);
    expect(choices.length).toBeLessThanOrEqual(3);

    // All choices should be valid perk IDs
    for (const choice of choices) {
      expect(getPerkData(choice)).toBeDefined();
    }
  });

  it('should generate unique perk choices', () => {
    const selectedPerks = new Map<PerkId, number>();
    const choices = generatePerkChoices(selectedPerks, 1, false, false);

    const uniqueChoices = new Set(choices);
    expect(uniqueChoices.size).toBe(choices.length);
  });

  it('should exclude rare perks without perk expert', () => {
    const selectedPerks = new Map<PerkId, number>();

    // Mock Math.random to ensure no rare perks (return value > 0.1)
    const randomSpy = vi.spyOn(Math, 'random').mockReturnValue(0.5);

    try {
      // Run multiple times - all choices should exclude rare perks
      for (let i = 0; i < 50; i++) {
        const choices = generatePerkChoices(selectedPerks, 1, false, false);
        for (const choice of choices) {
          const perk = getPerkData(choice)!;
          expect(perk.isRare).not.toBe(true);
        }
      }
    } finally {
      randomSpy.mockRestore();
    }
  });

  it('should return empty array when no perks available', () => {
    // Select all perks
    const selectedPerks = new Map<PerkId, number>();
    for (const perk of ALL_PERKS) {
      selectedPerks.set(perk.id, perk.maxRank);
    }

    const choices = generatePerkChoices(selectedPerks, 10, false, false);
    expect(choices).toEqual([]);
  });
});

describe('Perk Stat Calculations', () => {
  describe('Damage Multiplier', () => {
    it('should calculate base damage multiplier', () => {
      const perkCounts = new Map<PerkId, number>();
      expect(calculateDamageMultiplier(perkCounts)).toBe(1);
    });

    it('should apply sharpshooter bonus', () => {
      const perkCounts = new Map<PerkId, number>([[PerkId.SHARPSHOOTER, 2]]);
      expect(calculateDamageMultiplier(perkCounts)).toBe(1.3); // 1 + 2 * 0.15
    });

    it('should apply evil eyes bonus', () => {
      const perkCounts = new Map<PerkId, number>([[PerkId.EVIL_EYES, 1]]);
      expect(calculateDamageMultiplier(perkCounts)).toBe(1.1);
    });
  });

  describe('Fire Rate Multiplier', () => {
    it('should calculate base fire rate multiplier', () => {
      const perkCounts = new Map<PerkId, number>();
      expect(calculateFireRateMultiplier(perkCounts)).toBe(1);
    });

    it('should apply fastshot bonus', () => {
      const perkCounts = new Map<PerkId, number>([[PerkId.FASTSHOT, 3]]);
      expect(calculateFireRateMultiplier(perkCounts)).toBe(1.3); // 1 + 3 * 0.1
    });
  });

  describe('Reload Speed Multiplier', () => {
    it('should calculate reload speed multiplier', () => {
      const perkCounts = new Map<PerkId, number>([[PerkId.ANXIOUS_LOADER, 2]]);
      expect(calculateReloadSpeedMultiplier(perkCounts)).toBe(1.4); // 1 + 2 * 0.2
    });
  });

  describe('Move Speed Multiplier', () => {
    it('should calculate move speed multiplier', () => {
      const perkCounts = new Map<PerkId, number>([[PerkId.LONG_DISTANCE_RUNNER, 2]]);
      expect(calculateMoveSpeedMultiplier(perkCounts)).toBe(1.2); // 1 + 2 * 0.1
    });
  });

  describe('Max Health Multiplier', () => {
    it('should calculate base health multiplier', () => {
      const perkCounts = new Map<PerkId, number>();
      expect(calculateMaxHealthMultiplier(perkCounts)).toBe(1);
    });

    it('should apply thick skinned bonus', () => {
      const perkCounts = new Map<PerkId, number>([[PerkId.THICK_SKINNED, 1]]);
      expect(calculateMaxHealthMultiplier(perkCounts)).toBe(1.33);
    });
  });

  describe('XP Multiplier', () => {
    it('should calculate XP multiplier', () => {
      const perkCounts = new Map<PerkId, number>([[PerkId.LEAN_MEAN_EXP_MACHINE, 3]]);
      expect(calculateXpMultiplier(perkCounts)).toBe(1.3); // 1 + 3 * 0.1
    });
  });

  describe('Health Regeneration', () => {
    it('should calculate base regen', () => {
      const perkCounts = new Map<PerkId, number>();
      expect(calculateHealthRegen(perkCounts)).toBe(0);
    });

    it('should apply regeneration', () => {
      const perkCounts = new Map<PerkId, number>([[PerkId.REGENERATION, 1]]);
      expect(calculateHealthRegen(perkCounts)).toBe(1);
    });

    it('should apply greater regeneration', () => {
      const perkCounts = new Map<PerkId, number>([
        [PerkId.REGENERATION, 1],
        [PerkId.GREATER_REGENERATION, 1],
      ]);
      expect(calculateHealthRegen(perkCounts)).toBe(3); // Greater regen replaces basic
    });

    it('should apply doctor bonus', () => {
      const perkCounts = new Map<PerkId, number>([
        [PerkId.REGENERATION, 1],
        [PerkId.DOCTOR, 2],
      ]);
      expect(calculateHealthRegen(perkCounts)).toBe(2); // 1 + 2 * 0.5
    });
  });

  describe('Bonus Duration Multiplier', () => {
    it('should calculate bonus duration', () => {
      const perkCounts = new Map<PerkId, number>([
        [PerkId.BONUS_ECONOMIST, 2],
        [PerkId.PYROKINETIC, 1],
      ]);
      expect(calculateBonusDurationMultiplier(perkCounts)).toBe(1.5); // 1 + 2*0.25 + 0.5
    });
  });

  describe('Clip Size Bonus', () => {
    it('should calculate clip size bonus', () => {
      const perkCounts = new Map<PerkId, number>([[PerkId.MY_FAVOURITE_WEAPON, 2]]);
      expect(calculateClipSizeBonus(perkCounts)).toBe(4); // 2 * 2
    });
  });
});

describe('Available Perks', () => {
  it('should return available perks for new player', () => {
    const selectedPerks = new Map<PerkId, number>();
    const available = getAvailablePerks(selectedPerks, 1, false);

    expect(available.length).toBeGreaterThan(0);

    // Should not include perks with prerequisites
    expect(available).not.toContain(PerkId.GREATER_REGENERATION);
    expect(available).not.toContain(PerkId.PERK_MASTER);
  });

  it('should exclude rare perks when requested', () => {
    const selectedPerks = new Map<PerkId, number>();
    const available = getAvailablePerks(selectedPerks, 1, true);

    for (const perkId of available) {
      const perk = getPerkData(perkId)!;
      expect(perk.isRare).not.toBe(true);
    }
  });

  it('should exclude maxed out perks', () => {
    const sharpshooterData = getPerkData(PerkId.SHARPSHOOTER)!;
    const selectedPerks = new Map<PerkId, number>([
      [PerkId.SHARPSHOOTER, sharpshooterData.maxRank],
    ]);
    const available = getAvailablePerks(selectedPerks, 1, false);

    expect(available).not.toContain(PerkId.SHARPSHOOTER);
  });
});
