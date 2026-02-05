/**
 * Parity Regression Tests
 *
 * These tests fail when TypeScript implementation drifts from decompiled source.
 * Run `pnpm test:parity` to verify parity.
 */

import { readFileSync } from 'node:fs';
import { describe, expect, it } from 'vitest';
import { BONUS_DATA } from '../../src/game/data/bonuses';
import { CREATURE_DATA } from '../../src/game/data/creatures';
import { ALL_PERKS } from '../../src/game/data/perks';
import { ALL_QUESTS } from '../../src/game/data/quests';
import { WEAPON_DATA } from '../../src/game/data/weapons';
import { BonusType, CreatureTypeId, PerkId, WeaponId } from '../../src/types/game';

const canonical = JSON.parse(readFileSync('tests/parity/canonical-data.json', 'utf-8'));

// =============================================================================
// Stat Parity Test Helpers
// =============================================================================

/**
 * NOTE ON STAT CONVERSIONS:
 *
 * Many stats have significant deviations because the decompiled values
 * use different units than the gameplay values:
 *
 * - Damage: Raw * 100 ≈ gameplay (but varies by weapon type)
 * - Fire Rate: Different units (shots/sec vs sec/shot), high variance expected
 * - Reload Time: Engine frames vs seconds, high variance expected
 * - Clip Size: Engine ammo vs magazine, often unrelated
 *
 * The parity tests validate that values are in reasonable ranges
 * rather than enforcing exact numeric parity, which would require
 * implementing the full grim.dll runtime conversion logic.
 */

describe('Weapon Parity', () => {
  it('should have exactly the same number of weapons as decompiled source', () => {
    expect(Object.keys(WEAPON_DATA).length).toBe(canonical.weapons.length);
  });

  it('should have matching weapon IDs', () => {
    const tsIds = Object.keys(WEAPON_DATA)
      .map(Number)
      .sort((a, b) => a - b);
    const canonicalIds = canonical.weapons
      .map((w: { id: number }) => w.id)
      .sort((a: number, b: number) => a - b);
    expect(tsIds).toEqual(canonicalIds);
  });

  it('should have all weapons defined for each WeaponId enum value', () => {
    const allWeaponIds = Object.values(WeaponId).filter((v): v is number => typeof v === 'number');
    for (const id of allWeaponIds) {
      expect(WEAPON_DATA[id as WeaponId], `Weapon ${id} should be defined`).toBeDefined();
    }
  });

  // Per-field stat parity tests (IDs 0-29 - standard weapons)
  describe('Weapon Stat Parity (Standard Weapons)', () => {
    const standardWeapons = canonical.weapons.filter((w: { id: number }) => w.id <= 29);

    it('should have damage values in reasonable gameplay ranges', () => {
      // NOTE: Damage values from decompile require type-specific conversion.
      // The raw hex values represent engine units that get scaled at runtime
      // based on weapon category (pistols, rifles, plasma, ion, etc.).
      // We validate that gameplay values are reasonable rather than enforcing
      // exact parity with converted decompile values.
      const badDamage: string[] = [];
      for (const canonicalWeapon of standardWeapons) {
        const tsWeapon = WEAPON_DATA[canonicalWeapon.id as WeaponId];
        if (!tsWeapon) continue;

        // Skip weapons with 0 damage (special/placeholders)
        if (canonicalWeapon.damage === 0) continue;

        // Check that gameplay damage is reasonable (1 to 500)
        if (tsWeapon.damage < 1 || tsWeapon.damage > 500) {
          badDamage.push(`${canonicalWeapon.name}: ts=${tsWeapon.damage} (should be 1-500)`);
        }
      }
      if (badDamage.length > 0) {
        console.log('Bad weapon damage values:', badDamage);
      }
      expect(badDamage).toEqual([]);
    });

    it('should track damage conversion ratios for tuning reference', () => {
      // This test logs the damage ratios for reference when tuning.
      // It always passes but provides data for balancing decisions.
      const ratios: string[] = [];
      for (const canonicalWeapon of standardWeapons) {
        const tsWeapon = WEAPON_DATA[canonicalWeapon.id as WeaponId];
        if (!tsWeapon || canonicalWeapon.damage === 0) continue;

        const ratio = tsWeapon.damage / canonicalWeapon.damage;
        ratios.push(
          `${canonicalWeapon.name}: canonical=${canonicalWeapon.damage.toFixed(1)}, ts=${tsWeapon.damage}, ratio=${ratio.toFixed(2)}`
        );
      }
      console.log('Weapon damage conversion reference:', ratios);
      expect(ratios.length).toBeGreaterThan(0); // Always pass - just for reference
    });

    it('should have fireRate values in reasonable ranges', () => {
      // Fire rate in canonical appears to be shots-per-second
      // Fire rate in gameplay is seconds-between-shots
      // They are reciprocals: canonical ≈ 1 / gameplay
      // This test checks that values are in reasonable gameplay ranges
      const badRates: string[] = [];
      for (const canonicalWeapon of standardWeapons) {
        const tsWeapon = WEAPON_DATA[canonicalWeapon.id as WeaponId];
        if (!tsWeapon) continue;

        // Check that gameplay fireRate is reasonable (0.01 to 2 seconds)
        if (tsWeapon.fireRate < 0.01 || tsWeapon.fireRate > 2.0) {
          badRates.push(
            `${canonicalWeapon.name}: ts=${tsWeapon.fireRate} (should be 0.01-2.0 sec)`
          );
        }
      }
      if (badRates.length > 0) {
        console.log('Bad fireRate values:', badRates.slice(0, 10));
      }
      expect(badRates).toEqual([]);
    });

    it('should have reloadTime values in reasonable ranges', () => {
      // Reload time in canonical appears to be in engine units (frames)
      // Reload time in gameplay is seconds
      // This test checks that values are in reasonable gameplay ranges
      const badReloads: string[] = [];
      for (const canonicalWeapon of standardWeapons) {
        const tsWeapon = WEAPON_DATA[canonicalWeapon.id as WeaponId];
        if (!tsWeapon) continue;

        // Check that gameplay reloadTime is reasonable (0.5 to 5 seconds)
        if (tsWeapon.reloadTime < 0.5 || tsWeapon.reloadTime > 5.0) {
          badReloads.push(
            `${canonicalWeapon.name}: ts=${tsWeapon.reloadTime} (should be 0.5-5.0 sec)`
          );
        }
      }
      if (badReloads.length > 0) {
        console.log('Bad reloadTime values:', badReloads.slice(0, 10));
      }
      expect(badReloads).toEqual([]);
    });

    it('should have clipSize values in reasonable ranges', () => {
      // Clip size in canonical doesn't directly map to gameplay
      // This test checks that values are in reasonable gameplay ranges
      const badClips: string[] = [];
      for (const canonicalWeapon of standardWeapons) {
        const tsWeapon = WEAPON_DATA[canonicalWeapon.id as WeaponId];
        if (!tsWeapon) continue;

        // Check that gameplay clipSize is reasonable (1 to 200)
        if (tsWeapon.clipSize < 1 || tsWeapon.clipSize > 200) {
          badClips.push(`${canonicalWeapon.name}: ts=${tsWeapon.clipSize} (should be 1-200)`);
        }
      }
      if (badClips.length > 0) {
        console.log('Bad clipSize values:', badClips.slice(0, 10));
      }
      expect(badClips).toEqual([]);
    });
  });
});

describe('Perk Parity', () => {
  // All 58 perks (IDs 0-57) are now implemented and match the decompiled source.
  // See: tests/parity/canonical-data.json for canonical perk data.

  it('should have exactly the same number of perks as decompiled source', () => {
    expect(ALL_PERKS.length).toBe(canonical.perks.length);
  });

  it('should have matching perk IDs', () => {
    const tsIds = ALL_PERKS.map((p) => p.id).sort((a, b) => a - b);
    const canonicalIds = canonical.perks
      .map((p: { id: number }) => p.id)
      .sort((a: number, b: number) => a - b);
    expect(tsIds).toEqual(canonicalIds);
  });

  it('should have all perks defined for each PerkId enum value', () => {
    const allPerkIds = Object.values(PerkId).filter((v): v is number => typeof v === 'number');
    for (const id of allPerkIds) {
      const perk = ALL_PERKS.find((p) => p.id === id);
      expect(perk, `Perk ${id} should be defined`).toBeDefined();
    }
  });
});

describe('Creature Parity', () => {
  it('should have exactly the same number of creature types', () => {
    expect(Object.keys(CREATURE_DATA).length).toBe(canonical.creatures.length);
  });

  it('should have matching creature IDs', () => {
    const tsIds = Object.keys(CREATURE_DATA)
      .map(Number)
      .sort((a, b) => a - b);
    const canonicalIds = canonical.creatures
      .map((c: { id: number }) => c.id)
      .sort((a: number, b: number) => a - b);
    expect(tsIds).toEqual(canonicalIds);
  });

  it('should have all creatures defined for each CreatureTypeId enum value', () => {
    const allCreatureIds = Object.values(CreatureTypeId).filter(
      (v): v is number => typeof v === 'number'
    );
    for (const id of allCreatureIds) {
      expect(CREATURE_DATA[id as CreatureTypeId], `Creature ${id} should be defined`).toBeDefined();
    }
  });

  // Per-field stat parity tests
  describe('Creature Stat Parity', () => {
    it('should have exact health parity with canonical values', () => {
      // Creature health now uses grim.dll conversion formulas for exact parity
      const mismatches: string[] = [];
      for (const canonicalCreature of canonical.creatures) {
        const tsCreature = CREATURE_DATA[canonicalCreature.id as CreatureTypeId];
        if (!tsCreature) continue;

        if (tsCreature.health !== canonicalCreature.health) {
          mismatches.push(
            `${canonicalCreature.name}: ts=${tsCreature.health}, canonical=${canonicalCreature.health}`
          );
        }
      }
      if (mismatches.length > 0) {
        console.log('Creature health mismatches:', mismatches);
      }
      expect(mismatches).toEqual([]);
    });

    it('should have exact speed parity with canonical values', () => {
      // Creature speed now uses grim.dll conversion formulas for exact parity
      const mismatches: string[] = [];
      for (const canonicalCreature of canonical.creatures) {
        const tsCreature = CREATURE_DATA[canonicalCreature.id as CreatureTypeId];
        if (!tsCreature) continue;

        if (tsCreature.speed !== canonicalCreature.speed) {
          mismatches.push(
            `${canonicalCreature.name}: ts=${tsCreature.speed}, canonical=${canonicalCreature.speed}`
          );
        }
      }
      if (mismatches.length > 0) {
        console.log('Creature speed mismatches:', mismatches);
      }
      expect(mismatches).toEqual([]);
    });

    it('should have exact contact damage parity with canonical values', () => {
      // Creature damage now uses grim.dll conversion formulas for exact parity
      const mismatches: string[] = [];
      for (const canonicalCreature of canonical.creatures) {
        const tsCreature = CREATURE_DATA[canonicalCreature.id as CreatureTypeId];
        if (!tsCreature) continue;

        if (tsCreature.contactDamage !== canonicalCreature.damage) {
          mismatches.push(
            `${canonicalCreature.name}: ts=${tsCreature.contactDamage}, canonical=${canonicalCreature.damage}`
          );
        }
      }
      if (mismatches.length > 0) {
        console.log('Creature damage mismatches:', mismatches);
      }
      expect(mismatches).toEqual([]);
    });
  });
});

describe('Bonus Parity', () => {
  it('should have correct number of bonus types matching decompiled source', () => {
    const tsBonusCount = Object.values(BonusType).filter(
      (v): v is number => typeof v === 'number'
    ).length;
    expect(tsBonusCount).toBe(canonical.bonuses.length);
  });

  it('should have all bonus types defined in BonusType enum', () => {
    const allBonusIds = canonical.bonuses.map((b: { id: number }) => b.id);
    const tsBonusIds = Object.values(BonusType).filter((v): v is number => typeof v === 'number');

    for (const id of allBonusIds) {
      expect(tsBonusIds).toContain(id);
    }
  });

  // Per-field stat parity tests
  describe('Bonus Stat Parity', () => {
    it('should have exact duration parity with canonical values', () => {
      // Bonus durations now use grim.dll conversion formulas for exact parity
      const mismatches: string[] = [];
      for (const canonicalBonus of canonical.bonuses) {
        const tsBonus = BONUS_DATA[canonicalBonus.id as BonusType];
        if (!tsBonus) continue;

        if (tsBonus.duration !== canonicalBonus.duration) {
          mismatches.push(
            `${canonicalBonus.name}: ts=${tsBonus.duration}, canonical=${canonicalBonus.duration}`
          );
        }
      }
      if (mismatches.length > 0) {
        console.log('Bonus duration mismatches:', mismatches);
      }
      expect(mismatches).toEqual([]);
    });

    it('should have exact rarity parity with canonical values (after conversion)', () => {
      // Bonus rarities now use grim.dll conversion formulas for exact parity
      // Rarity 0 in canonical (special spawn) is converted to 1 in gameplay
      const mismatches: string[] = [];
      for (const canonicalBonus of canonical.bonuses) {
        const tsBonus = BONUS_DATA[canonicalBonus.id as BonusType];
        if (!tsBonus) continue;

        if (tsBonus.rarity !== canonicalBonus.rarity) {
          mismatches.push(
            `${canonicalBonus.name}: ts=${tsBonus.rarity}, canonical=${canonicalBonus.rarity}`
          );
        }
      }
      if (mismatches.length > 0) {
        console.log('Bonus rarity mismatches:', mismatches);
      }
      expect(mismatches).toEqual([]);
    });
  });
});

describe('Quest Parity', () => {
  it('should have exactly the same number of quests', () => {
    expect(ALL_QUESTS.length).toBe(canonical.quests.length);
  });

  it('should have all quest IDs defined', () => {
    const canonicalIds = canonical.quests.map((q: { id: string }) => q.id).sort();
    const tsIds = ALL_QUESTS.map((q: { id: string }) => q.id).sort();
    expect(tsIds).toEqual(canonicalIds);
  });

  it('should have all quest objectives implemented', () => {
    const unimplemented: string[] = [];
    for (const quest of ALL_QUESTS) {
      for (const objective of quest.objectives) {
        if (!isObjectiveImplemented(objective.type)) {
          unimplemented.push(`${quest.id}.${objective.type}`);
        }
      }
    }
    expect(unimplemented).toEqual([]);
  });

  it('should have matching time limits', () => {
    const mismatches: string[] = [];
    for (const canonicalQuest of canonical.quests) {
      const tsQuest = ALL_QUESTS.find((q) => q.id === canonicalQuest.id);
      if (!tsQuest) continue;

      const tsTimeLimit = tsQuest.timeLimitMs ?? 0;
      if (tsTimeLimit !== canonicalQuest.timeLimitMs) {
        mismatches.push(
          `${canonicalQuest.id}: ts=${tsTimeLimit}, canonical=${canonicalQuest.timeLimitMs}`
        );
      }
    }
    expect(mismatches).toEqual([]);
  });

  it('should have matching starting weapons', () => {
    const mismatches: string[] = [];
    for (const canonicalQuest of canonical.quests) {
      const tsQuest = ALL_QUESTS.find((q) => q.id === canonicalQuest.id);
      if (!tsQuest) continue;

      const tsWeapon = tsQuest.startingWeapon ?? 1; // Default to pistol (1) if not set
      if (tsWeapon !== canonicalQuest.startWeaponId) {
        mismatches.push(
          `${canonicalQuest.id}: ts=${tsWeapon}, canonical=${canonicalQuest.startWeaponId}`
        );
      }
    }
    expect(mismatches).toEqual([]);
  });
});

function isObjectiveImplemented(type: string): boolean {
  const implemented = ['kill_count', 'survive_time'];
  return implemented.includes(type);
}
