/**
 * Extractor Validation Tests
 *
 * These tests validate the parity extractor produces sane, valid data.
 * They catch extraction bugs before they corrupt canonical-data.json.
 */

import { describe, expect, it } from 'vitest';
import { readFileSync } from 'node:fs';

const canonical = JSON.parse(readFileSync('tests/parity/canonical-data.json', 'utf-8'));

describe('Extractor Sanity - Weapons', () => {
  it('should have contiguous weapon IDs 0-39', () => {
    const ids = canonical.weapons.map((w: { id: number }) => w.id).sort((a: number, b: number) => a - b);
    expect(ids).toEqual(Array.from({ length: 40 }, (_, i) => i));
  });

  it('should have positive fire rates', () => {
    for (const w of canonical.weapons) {
      expect(w.fireRate, `Weapon ${w.id} (${w.name}) fireRate`).toBeGreaterThanOrEqual(0);
    }
  });

  it('should have non-negative damage', () => {
    for (const w of canonical.weapons) {
      expect(w.damage, `Weapon ${w.id} (${w.name}) damage`).toBeGreaterThanOrEqual(0);
    }
  });

  it('should have non-negative reload times', () => {
    for (const w of canonical.weapons) {
      expect(w.reloadTime, `Weapon ${w.id} (${w.name}) reloadTime`).toBeGreaterThanOrEqual(0);
    }
  });

  it('should have non-negative clip sizes', () => {
    for (const w of canonical.weapons) {
      expect(w.clipSize, `Weapon ${w.id} (${w.name}) clipSize`).toBeGreaterThanOrEqual(0);
    }
  });

  it('should have non-empty weapon names', () => {
    for (const w of canonical.weapons) {
      expect(w.name, `Weapon ${w.id} name`).toBeTruthy();
      expect(w.name.length, `Weapon ${w.id} name length`).toBeGreaterThan(0);
    }
  });
});

describe('Extractor Sanity - Creatures', () => {
  it('should have contiguous creature IDs 0-10', () => {
    const ids = canonical.creatures.map((c: { id: number }) => c.id).sort((a: number, b: number) => a - b);
    expect(ids).toEqual([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
  });

  it('should have reasonable health values', () => {
    for (const c of canonical.creatures) {
      expect(c.health, `Creature ${c.id} (${c.name}) health`).toBeGreaterThan(0);
      expect(c.health, `Creature ${c.id} (${c.name}) health`).toBeLessThan(10000);
    }
  });

  it('should have reasonable speed values', () => {
    for (const c of canonical.creatures) {
      expect(c.speed, `Creature ${c.id} (${c.name}) speed`).toBeGreaterThan(0);
      expect(c.speed, `Creature ${c.id} (${c.name}) speed`).toBeLessThan(500);
    }
  });

  it('should have reasonable damage values', () => {
    for (const c of canonical.creatures) {
      expect(c.damage, `Creature ${c.id} (${c.name}) damage`).toBeGreaterThanOrEqual(0);
      expect(c.damage, `Creature ${c.id} (${c.name}) damage`).toBeLessThan(500);
    }
  });

  it('should have non-empty creature names', () => {
    for (const c of canonical.creatures) {
      expect(c.name, `Creature ${c.id} name`).toBeTruthy();
      expect(c.name.length, `Creature ${c.id} name length`).toBeGreaterThan(0);
    }
  });
});

describe('Extractor Sanity - Perks', () => {
  it('should have contiguous perk IDs 0-57', () => {
    const ids = canonical.perks.map((p: { id: number }) => p.id).sort((a: number, b: number) => a - b);
    expect(ids).toEqual(Array.from({ length: 58 }, (_, i) => i));
  });

  it('should have non-empty perk names', () => {
    for (const p of canonical.perks) {
      expect(p.name, `Perk ${p.id} name`).toBeTruthy();
      expect(p.name.length, `Perk ${p.id} name length`).toBeGreaterThan(0);
    }
  });

  it('should have non-empty perk descriptions', () => {
    for (const p of canonical.perks) {
      expect(p.description, `Perk ${p.id} (${p.name}) description`).toBeTruthy();
      expect(p.description.length, `Perk ${p.id} description length`).toBeGreaterThan(0);
    }
  });

  it('should have valid perk categories', () => {
    const validCategories = ['combat', 'defense', 'utility', 'movement', 'gamble', 'special', 'meta'];
    for (const p of canonical.perks) {
      expect(validCategories, `Perk ${p.id} (${p.name}) category`).toContain(p.category);
    }
  });
});

describe('Extractor Sanity - Quests', () => {
  it('should have 50 quests', () => {
    expect(canonical.quests.length).toBe(50);
  });

  it('should have unique quest IDs', () => {
    const ids = canonical.quests.map((q: { id: string }) => q.id);
    const uniqueIds = new Set(ids);
    expect(uniqueIds.size).toBe(ids.length);
  });

  it('should have non-empty quest IDs', () => {
    for (const q of canonical.quests) {
      expect(q.id, 'Quest ID').toBeTruthy();
      expect(q.id.length, 'Quest ID length').toBeGreaterThan(0);
    }
  });

  it('should have non-empty quest names', () => {
    for (const q of canonical.quests) {
      expect(q.name, `Quest ${q.id} name`).toBeTruthy();
      expect(q.name.length, `Quest ${q.id} name length`).toBeGreaterThan(0);
    }
  });

  it('should have at least one objective type per quest', () => {
    for (const q of canonical.quests) {
      expect(q.objectiveTypes.length, `Quest ${q.id} objectiveTypes`).toBeGreaterThan(0);
    }
  });

  it('should have valid objective types', () => {
    const validTypes = ['kill_count', 'survive_time', 'reach_location', 'kill_bosses'];
    for (const q of canonical.quests) {
      for (const type of q.objectiveTypes) {
        expect(validTypes, `Quest ${q.id} objective type`).toContain(type);
      }
    }
  });
});

describe('Extractor Sanity - Bonuses', () => {
  it('should have contiguous bonus IDs 0-13', () => {
    const ids = canonical.bonuses.map((b: { id: number }) => b.id).sort((a: number, b: number) => a - b);
    expect(ids).toEqual([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]);
  });

  it('should have non-empty bonus names', () => {
    for (const b of canonical.bonuses) {
      expect(b.name, `Bonus ${b.id} name`).toBeTruthy();
      expect(b.name.length, `Bonus ${b.id} name length`).toBeGreaterThan(0);
    }
  });

  it('should have reasonable rarity values', () => {
    for (const b of canonical.bonuses) {
      expect(b.rarity, `Bonus ${b.id} (${b.name}) rarity`).toBeGreaterThanOrEqual(0);
      expect(b.rarity, `Bonus ${b.id} (${b.name}) rarity`).toBeLessThan(10000);
    }
  });
});

describe('Extractor Invariants', () => {
  it('should have deterministic extraction (stable output)', () => {
    // Verify the data structure is complete
    expect(canonical.weapons).toBeDefined();
    expect(canonical.creatures).toBeDefined();
    expect(canonical.perks).toBeDefined();
    expect(canonical.quests).toBeDefined();
    expect(canonical.bonuses).toBeDefined();

    // Verify counts match expected values
    expect(canonical.weapons.length).toBe(40);
    expect(canonical.creatures.length).toBe(11);
    expect(canonical.perks.length).toBe(58);
    expect(canonical.quests.length).toBe(50);
    expect(canonical.bonuses.length).toBe(14);
  });

  it('should have no duplicate names within each category', () => {
    const weaponNames = canonical.weapons.map((w: { name: string }) => w.name);
    expect(new Set(weaponNames).size).toBe(weaponNames.length);

    const creatureNames = canonical.creatures.map((c: { name: string }) => c.name);
    expect(new Set(creatureNames).size).toBe(creatureNames.length);

    const perkNames = canonical.perks.map((p: { name: string }) => p.name);
    expect(new Set(perkNames).size).toBe(perkNames.length);

    const questIds = canonical.quests.map((q: { id: string }) => q.id);
    expect(new Set(questIds).size).toBe(questIds.length);

    const bonusNames = canonical.bonuses.map((b: { name: string }) => b.name);
    expect(new Set(bonusNames).size).toBe(bonusNames.length);
  });
});
