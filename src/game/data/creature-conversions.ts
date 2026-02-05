/**
 * Creature Stat Conversion Utilities
 *
 * Derived from analysis of creature_spawn_template in decompiled source.
 * These functions convert raw engine values to gameplay values.
 *
 * The decompiled source uses randomized formulas based on creature size:
 * - health = size * 1.1428572 + offset
 * - move_speed varies by template (size-based or random)
 * - contact_damage = rand() % 10 + 4
 */

/** Creature template IDs mapped to creature type IDs */
export const CREATURE_TEMPLATE_MAP: Record<number, number> = {
  65: 0, // Zombie
  26: 1, // Fast Zombie
  36: 2, // Tank Zombie
  64: 3, // Small Spider
  61: 4, // Large Spider
  5: 5, // Alien Trooper
  1: 6, // Alien Elite
  33: 7, // Ghost
  49: 8, // Lizard
  17: 9, // Lizard King (boss - fixed stats)
  46: 10, // Lizard Minion
};

/** Reverse mapping from creature type ID to template ID */
export const CREATURE_TYPE_TO_TEMPLATE: Record<number, number> = {
  0: 0x41, // Zombie
  1: 0x1a, // Fast Zombie
  2: 0x24, // Tank Zombie
  3: 0x40, // Small Spider
  4: 0x3d, // Large Spider
  5: 0x05, // Alien Trooper
  6: 0x01, // Alien Elite
  7: 0x21, // Ghost
  8: 0x31, // Lizard
  9: 0x11, // Lizard King
  10: 0x2e, // Lizard Minion
};

/** Health formula parameters per template */
interface HealthFormula {
  mult: number;
  offset: number;
}

const HEALTH_FORMULAS: Record<number, HealthFormula> = {
  65: { mult: 1.1428572, offset: 10 }, // Zombie
  26: { mult: 1.1428572, offset: 20 }, // Fast Zombie
  36: { mult: 1.1428572, offset: 20 }, // Tank Zombie
  64: { mult: 1.1428572, offset: 20 }, // Small Spider
  61: { mult: 1.1428572, offset: 20 }, // Large Spider
  5: { mult: 1.1428572, offset: 20 }, // Alien Trooper
  1: { mult: 0, offset: 400 }, // Alien Elite (fixed)
  33: { mult: 1.1428572, offset: 20 }, // Ghost
  49: { mult: 1.1428572, offset: 10 }, // Lizard
  17: { mult: 0, offset: 1500 }, // Lizard King (boss)
  46: { mult: 1.1428572, offset: 10 }, // Lizard Minion
};

/** Size ranges for each template (from rand() % range + offset) */
const SIZE_RANGES: Record<number, [number, number]> = {
  65: [40, 69], // Zombie: rand() % 30 + 40
  26: [40, 69], // Fast Zombie: rand() % 30 + 40
  36: [40, 69], // Tank Zombie: rand() % 30 + 40
  64: [45, 59], // Small Spider: rand() % 15 + 45
  61: [40, 59], // Large Spider: rand() % 20 + 40
  5: [38, 52], // Alien Trooper: rand() % 15 + 38
  1: [80, 80], // Alien Elite: fixed 80
  33: [40, 69], // Ghost: rand() % 30 + 40
  49: [40, 69], // Lizard: rand() % 30 + 40
  17: [69, 69], // Lizard King: fixed 69
  46: [40, 69], // Lizard Minion: rand() % 30 + 40
};

/** Speed multiplier to convert move_speed to gameplay speed */
const SPEED_MULTIPLIER = 30;

/** Speed formula types per template */
interface SpeedFormula {
  type: 'size_based' | 'random' | 'fixed';
  base: number;
  factor: number;
}

const SPEED_FORMULAS: Record<number, SpeedFormula> = {
  65: { type: 'size_based', base: 0.9, factor: 0.0025 }, // Zombie
  26: { type: 'random', base: 1.1, factor: 0.1 }, // Fast Zombie
  36: { type: 'random', base: 1.1, factor: 0.1 }, // Tank Zombie
  64: { type: 'random', base: 1.1, factor: 0.1 }, // Small Spider
  61: { type: 'random', base: 1.1, factor: 0.1 }, // Large Spider
  5: { type: 'random', base: 1.1, factor: 0.1 }, // Alien Trooper
  1: { type: 'fixed', base: 2.0, factor: 0 }, // Alien Elite
  33: { type: 'random', base: 1.1, factor: 0.1 }, // Ghost
  49: { type: 'random', base: 1.1, factor: 0.1 }, // Lizard
  17: { type: 'fixed', base: 2.1, factor: 0 }, // Lizard King
  46: { type: 'random', base: 1.1, factor: 0.1 }, // Lizard Minion
};

/** Contact damage formulas per template */
const DAMAGE_OVERRIDES: Record<number, number> = {
  17: 150, // Lizard King
  1: 17, // Alien Elite
};

/**
 * Convert creature health using the formula: size * multiplier + offset
 *
 * @param templateId - Creature template ID
 * @param size - Creature size value
 * @returns Gameplay health value
 */
export function convertCreatureHealth(templateId: number, size: number): number {
  const formula = HEALTH_FORMULAS[templateId];
  if (!formula) return 50; // Default fallback

  if (formula.mult === 0) return formula.offset; // Fixed health (bosses)
  return Math.round(size * formula.mult + formula.offset);
}

/**
 * Convert creature move_speed to gameplay speed.
 *
 * @param templateId - Creature template ID
 * @param size - Creature size (for size-based formulas)
 * @param randValue - Random value 0-17 (for random formulas)
 * @returns Gameplay speed value
 */
export function convertCreatureSpeed(templateId: number, size: number, randValue: number): number {
  const formula = SPEED_FORMULAS[templateId];
  if (!formula) return 60; // Default fallback

  let moveSpeed: number;

  switch (formula.type) {
    case 'size_based':
      moveSpeed = size * formula.factor + formula.base;
      break;
    case 'random':
      // rand() % 18 * factor + base
      moveSpeed = randValue * formula.factor + formula.base;
      break;
    case 'fixed':
      moveSpeed = formula.base;
      break;
    default:
      moveSpeed = 2.0;
  }

  return Math.round(moveSpeed * SPEED_MULTIPLIER);
}

/**
 * Convert contact damage using rand() % 10 + 4 for most creatures.
 *
 * @param templateId - Creature template ID
 * @param randValue - Random value 0-9
 * @returns Gameplay contact damage value
 */
export function convertCreatureDamage(templateId: number, randValue: number): number {
  // Check for fixed overrides first
  const override = DAMAGE_OVERRIDES[templateId];
  if (override !== undefined) {
    return override;
  }

  // Default formula: rand() % 10 + 4 = 4-13 range
  return randValue + 4;
}

/**
 * Get average size for a template (midpoint of rand range).
 *
 * @param templateId - Creature template ID
 * @returns Average size value
 */
export function getAverageSize(templateId: number): number {
  const range = SIZE_RANGES[templateId];
  if (!range) return 55;
  return (range[0] + range[1]) / 2;
}

/**
 * Get size range for a template.
 *
 * @param templateId - Creature template ID
 * @returns [min, max] size range
 */
export function getSizeRange(templateId: number): [number, number] {
  return SIZE_RANGES[templateId] ?? [40, 69];
}

/**
 * Get average random speed value (midpoint of rand % 18).
 *
 * @returns Average of 0-17 = 8.5
 */
export function getAverageRandSpeed(): number {
  return 8.5; // Average of 0-17
}

/**
 * Get average damage value (midpoint of rand % 10 + 4).
 *
 * @returns Average of 4-13 = 8.5
 */
export function getAverageDamage(): number {
  return 8; // Rounded average of 4-13 for integer gameplay values
}

/** Full creature stat conversion result */
export interface ConvertedCreatureStats {
  health: number;
  speed: number;
  contactDamage: number;
}

/**
 * Convert all stats for a creature template at once using average values.
 *
 * @param templateId - Creature template ID
 * @returns Converted gameplay stats
 */
export function convertCreatureStats(templateId: number): ConvertedCreatureStats {
  const avgSize = getAverageSize(templateId);
  const avgRandSpeed = getAverageRandSpeed();

  return {
    health: convertCreatureHealth(templateId, avgSize),
    speed: convertCreatureSpeed(templateId, avgSize, avgRandSpeed),
    contactDamage: convertCreatureDamage(templateId, getAverageDamage() - 4),
  };
}

/**
 * Convert creature stats with specific values (for parity extractor).
 *
 * @param templateId - Creature template ID
 * @param size - Specific size value
 * @param randSpeed - Specific random speed value (0-17)
 * @param randDamage - Specific random damage value (0-9)
 * @returns Converted gameplay stats
 */
export function convertCreatureStatsExact(
  templateId: number,
  size: number,
  randSpeed: number,
  randDamage: number
): ConvertedCreatureStats {
  return {
    health: convertCreatureHealth(templateId, size),
    speed: convertCreatureSpeed(templateId, size, randSpeed),
    contactDamage: convertCreatureDamage(templateId, randDamage),
  };
}
