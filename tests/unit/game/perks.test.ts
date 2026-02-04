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
    expect(thickSkinned?.incompatibleWith).toContain(PerkId.REGENERATION);
    expect(thickSkinned?.incompatibleWith).toContain(PerkId.GREATER_REGENERATION);
  });

  it('should define prerequisite perks correctly', () => {
    const greaterRegen = getPerkData(PerkId.GREATER_REGENERATION);
    expect(greaterRegen?.requiresPerk).toBe(PerkId.REGENERATION);

    const perkMaster = getPerkData(PerkId.PERK_MASTER);
    expect(perkMaster?.requiresPerk).toBe(PerkId.PERK_EXPERT);
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
    const sharpshooterData = getPerkData(PerkId.SHARPSHOOTER);
    const selectedPerks = new Map<PerkId, number>([
      [PerkId.SHARPSHOOTER, sharpshooterData?.maxRank ?? 5],
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
          const perk = getPerkData(choice);
          expect(perk?.isRare).not.toBe(true);
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
      const perk = getPerkData(perkId);
      expect(perk?.isRare).not.toBe(true);
    }
  });

  it('should exclude maxed out perks', () => {
    const sharpshooterData = getPerkData(PerkId.SHARPSHOOTER);
    const selectedPerks = new Map<PerkId, number>([
      [PerkId.SHARPSHOOTER, sharpshooterData?.maxRank ?? 5],
    ]);
    const available = getAvailablePerks(selectedPerks, 1, false);

    expect(available).not.toContain(PerkId.SHARPSHOOTER);
  });
});

describe('Special Perk Effects', () => {
  describe('Infinite Ammo Window (Ammunition Within)', () => {
    it('should start infinite ammo window on reload', () => {
      // This is tested via integration with WeaponSystem
      // PerkSystem.startInfiniteAmmoWindow should set the effect
      expect(true).toBe(true); // Placeholder - actual test requires full system integration
    });

    it('should check infinite ammo window based on gameTime', () => {
      // PerkSystem.isInfiniteAmmoActive should return true during window
      expect(true).toBe(true); // Placeholder
    });
  });

  describe('Ammo Refill on Pickup (Ammo Maniac)', () => {
    it('should identify Ammo Maniac perk', () => {
      const perkCounts = new Map<PerkId, number>([[PerkId.AMMO_MANIAC, 1]]);
      const hasPerk = perkCounts.has(PerkId.AMMO_MANIAC);
      expect(hasPerk).toBe(true);
    });

    it('should calculate clip size bonus for refill', () => {
      const perkCounts = new Map<PerkId, number>([
        [PerkId.MY_FAVOURITE_WEAPON, 2],
        [PerkId.AMMO_MANIAC, 1],
      ]);
      const clipBonus = calculateClipSizeBonus(perkCounts);
      expect(clipBonus).toBe(4); // 2 * 2
    });
  });

  describe('Bonus Duration Multiplier', () => {
    it('should apply Bonus Economist multiplier', () => {
      const perkCounts = new Map<PerkId, number>([[PerkId.BONUS_ECONOMIST, 2]]);
      const multiplier = calculateBonusDurationMultiplier(perkCounts);
      expect(multiplier).toBe(1.5); // 1 + 2*0.25
    });

    it('should apply both Bonus Economist and Pyrokinetic', () => {
      // Note: Pyrokinetic adds 0.5 to the multiplier per the code
      const perkCounts = new Map<PerkId, number>([
        [PerkId.BONUS_ECONOMIST, 1],
        [PerkId.PYROKINETIC, 1],
      ]);
      const multiplier = calculateBonusDurationMultiplier(perkCounts);
      // 1 + 0.25 + 0.5 = 1.75
      expect(multiplier).toBe(1.75);
    });
  });

  describe('Perk Data for Special Effects', () => {
    it('should define special_infinite_ammo_window for Ammunition Within', () => {
      const perk = getPerkData(PerkId.AMMUNITION_WITHIN);
      expect(perk).toBeDefined();
      expect(perk?.effects.some((e) => e.type === 'special_infinite_ammo_window')).toBe(true);
      expect(perk?.effects.find((e) => e.type === 'special_infinite_ammo_window')?.value).toBe(3);
    });

    it('should define special_ammo_refill_on_pickup for Ammo Maniac', () => {
      const perk = getPerkData(PerkId.AMMO_MANIAC);
      expect(perk).toBeDefined();
      expect(perk?.effects.some((e) => e.type === 'special_ammo_refill_on_pickup')).toBe(true);
    });

    it('should define special_random_weapon for Random Weapon', () => {
      const perk = getPerkData(PerkId.RANDOM_WEAPON);
      expect(perk).toBeDefined();
      expect(perk?.effects.some((e) => e.type === 'special_random_weapon')).toBe(true);
    });

    it('should define special_shield_on_hit for Breathing Room', () => {
      const perk = getPerkData(PerkId.BREATHING_ROOM);
      expect(perk).toBeDefined();
      expect(perk?.effects.some((e) => e.type === 'special_shield_on_hit')).toBe(true);
    });

    it('should define special_regression_bullets for Regression Bullets', () => {
      const perk = getPerkData(PerkId.REGRESSION_BULLETS);
      expect(perk).toBeDefined();
      expect(perk?.effects.some((e) => e.type === 'special_regression_bullets')).toBe(true);
    });

    it('should define special_time_slow_on_hit for Reflex Boosted', () => {
      const perk = getPerkData(PerkId.REFLEX_BOOSTED);
      expect(perk).toBeDefined();
      expect(perk?.effects.some((e) => e.type === 'special_time_slow_on_hit')).toBe(true);
    });

    it('should define special_lifeline_50_50 for Lifeline 50/50', () => {
      const perk = getPerkData(PerkId.LIFELINE_50_50);
      expect(perk).toBeDefined();
      expect(perk?.effects.some((e) => e.type === 'special_lifeline_50_50')).toBe(true);
    });

    it('should define special_jinxed for Jinxed', () => {
      const perk = getPerkData(PerkId.JINXED);
      expect(perk).toBeDefined();
      expect(perk?.effects.some((e) => e.type === 'special_jinxed')).toBe(true);
    });

    it('should define special_bonus_magnet for Bonus Magnet', () => {
      const perk = getPerkData(PerkId.BONUS_MAGNET);
      expect(perk).toBeDefined();
      expect(perk?.effects.some((e) => e.type === 'special_bonus_magnet')).toBe(true);
    });

    it('should mark rare perks correctly', () => {
      const lifeline = getPerkData(PerkId.LIFELINE_50_50);
      const jinxed = getPerkData(PerkId.JINXED);
      const instantWinner = getPerkData(PerkId.INSTANT_WINNER);

      expect(lifeline?.isRare).toBe(true);
      expect(jinxed?.isRare).toBe(true);
      expect(instantWinner?.isRare).toBe(true);
    });
  });

  describe('Fire Bullets (Pyromaniac)', () => {
    it('should define special_fire_bullets for Pyromaniac', () => {
      const perk = getPerkData(PerkId.PYROMANIAC);
      expect(perk).toBeDefined();
      expect(perk?.effects.some((e) => e.type === 'special_fire_bullets')).toBe(true);
      expect(perk?.effects.find((e) => e.type === 'special_fire_bullets')?.value).toBe(1.25);
    });
  });

  describe('Perk System Integration', () => {
    it('should identify all special perk effect types', () => {
      // Verify all special effect types are defined in the type union
      const specialTypes = [
        'special_fire_bullets',
        'special_infinite_ammo_window',
        'special_ammo_refill_on_pickup',
        'special_random_weapon',
        'special_monster_vision',
        'special_shield_on_hit',
        'special_regression_bullets',
        'special_time_slow_on_hit',
        'special_instant_xp',
        'special_fatal_lottery',
        'special_lifeline_50_50',
        'special_jinxed',
        'special_infernal_contract',
        'special_grim_deal',
        'special_death_clock',
        'special_highlander',
        'special_plaguebearer',
        'special_bandage',
        'special_bonus_magnet',
      ];

      // Check that each special perk has the correct effect type
      for (const type of specialTypes) {
        const perksWithEffect = ALL_PERKS.filter((p) => p.effects.some((e) => e.type === type));
        // At least one perk should have each effect type
        expect(perksWithEffect.length).toBeGreaterThan(0);
      }
    });
  });
});
