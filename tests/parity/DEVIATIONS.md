# Stat Deviations from Decompiled Source

This document tracks intentional deviations between the extracted canonical values
(from decompiled Crimsonland source) and the gameplay values used in this remake.

## Overview

The decompiled source stores values in "engine units" that get transformed at runtime
by the original grim.dll engine. The parity extractor applies basic conversions, but
significant gameplay tuning is still required.

## Weapon Stats

### Damage Conversion

The decompiled weapon table stores damage as small float values (0.14 for Pistol).
These are multiplied by 100 to get reasonable base damage values:

| Weapon | Canonical | Gameplay | Ratio | Notes |
|--------|-----------|----------|-------|-------|
| Pistol | 14 | 15 | 1.07 | Close match |
| Assault Rifle | 71 | 12 | 0.17 | Requires type-specific tuning |
| Shotgun | 12 | 8 | 0.67 | Per-pellet damage |
| Gauss Gun | 11 | 150 | 13.64 | High-damage weapons use different scaling |
| Plasma Rifle | 1 | 25 | 25.00 | Energy weapons need separate conversion |

**Key Finding**: Damage values require weapon-type-specific conversion factors.
The simple "multiply by 100" approach works for basic weapons but not for
specialized categories (energy, explosive, ion, etc.).

### Fire Rate

Decompiled values appear to be shots-per-second, while gameplay uses
seconds-between-shots (reciprocal relationship).

| Weapon | Canonical (sps) | Gameplay (sbs) | Reciprocal |
|--------|-----------------|----------------|------------|
| Pistol | 1.2 | 0.3 | 1/4 |
| Assault Rifle | 1.2 | 0.1 | 1/12 |
| Shotgun | 1.2 | 0.8 | 2/3 |

**Key Finding**: No consistent conversion factor. Gameplay values are manually tuned.

### Reload Time

Decompiled values appear to be in engine frames or animation cycles.

| Weapon | Canonical | Gameplay | Ratio |
|--------|-----------|----------|-------|
| Pistol | 0.22 | 1.2 | ~5.5x |
| Assault Rifle | 0.22 | 2.0 | ~9x |
| Shotgun | 0.09 | 2.5 | ~28x |

**Key Finding**: Highly variable ratios suggest frame counts or animation states,
not direct time measurements.

### Clip Size

Decompiled clipSize values do not consistently map to magazine capacity.
They may represent total ammo pools or engine-specific ammo units.

| Weapon | Canonical | Gameplay | Note |
|--------|-----------|----------|------|
| Pistol | 112 | 12 | Likely total ammo vs magazine |
| Assault Rifle | 12 | 30 | Inconsistent ratio |
| Shotgun | 25 | 8 | Different ammo system |

## Creature Stats

### Health

Decompiled creature stats use randomized formulas based on size:
```c
health = size * 1.1428572 + offset
```

The canonical extractor calculates average values, but gameplay uses
manually tuned representative values.

| Creature | Canonical | Gameplay | Ratio |
|----------|-----------|----------|-------|
| Zombie | 72 | 40 | 0.56 |
| Fast Zombie | 82 | 25 | 0.30 |
| Tank Zombie | 82 | 120 | 1.46 |

### Speed

Canonical speed is `move_speed * 30`, but gameplay values differ significantly:

| Creature | Canonical | Gameplay | Note |
|----------|-----------|----------|------|
| Zombie | 31 | 60 | ~2x for gameplay feel |
| Fast Zombie | 60 | 100 | "Fast" variant tuned up |
| Tank Zombie | 60 | 30 | "Tank" variant tuned down |

### Contact Damage

Randomized in decompile (`rand() % 10 + 4`), gameplay uses fixed representative values.

## Bonus Stats

### Duration

Canonical and gameplay durations match closely for most bonuses.

| Bonus | Canonical | Gameplay | Match |
|-------|-----------|----------|-------|
| Points | 12 | 12 | ✓ |
| Reflex Boost | 0 (instant) | 5 | Intentional gameplay change |
| Shield | 0 (instant) | 6 | Intentional gameplay change |

### Rarity

Canonical rarity of 0 means "special spawn logic" in the original engine.
Gameplay assigns minimum rarity of 1 for valid spawn weights.

| Bonus | Canonical | Gameplay | Note |
|-------|-----------|----------|------|
| Points | 500 | 500 | ✓ |
| Atomic | 0 | 1 | Minimum rarity for spawn system |
| Fireblast | 0 | 1 | Minimum rarity for spawn system |

## Perks

Perk data in the decompile contains names and descriptions but minimal numeric stats.
Most perk effects are implemented as gameplay logic, not data-driven values.

## Quests

Quest data matches closely between canonical and gameplay. The main variance is in
objective types which are inferred from quest names in the extractor.

## Conclusion

The decompiled values provide a useful baseline for:
- Weapon ID mappings
- Creature type mappings
- Bonus and perk existence (count/IDs)
- Quest definitions

However, **gameplay balance requires manual tuning**. The original grim.dll engine
applies runtime conversions that are not fully captured by static analysis of
the decompiled source. The parity test suite validates:

1. Data structure integrity (IDs, counts)
2. Reasonable value ranges
3. Critical fixed values (boss stats, key bonuses)

Intentional deviations should be documented in this file as they are identified.
