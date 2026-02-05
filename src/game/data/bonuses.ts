/**
 * Bonus/Powerup Data Tables
 *
 * Based on bonus_metadata_init from decompiled source at 00412660.
 * Defines all bonus/powerup types with their metadata.
 *
 * Stats are derived from grim.dll runtime conversions in bonus-conversions.ts
 * to achieve exact parity with the decompiled Crimsonland source.
 */

import { BonusType } from '../../types/game';
import { convertBonusStats, CANONICAL_BONUS_VALUES } from './bonus-conversions';

export interface BonusData {
  id: BonusType;
  name: string;
  description: string;
  duration: number; // seconds, -1 = permanent/instant
  rarity: number; // spawn weight
}

// Helper to build bonus data using conversion functions
function buildBonusData(type: BonusType): BonusData {
  const canonical = CANONICAL_BONUS_VALUES[type];
  const converted = convertBonusStats(canonical.rarity, canonical.duration, type);

  // Bonus descriptions from decompiled source
  const descriptions: Record<BonusType, string> = {
    [BonusType.POINTS]: 'You gain some experience points',
    [BonusType.WEAPON]: 'You get a new weapon',
    [BonusType.ATOMIC]: 'An amazing explosion of ATOMIC power',
    [BonusType.DOUBLE_EXPERIENCE]: 'Every experience point you get is doubled',
    [BonusType.FIREBLAST]: 'Fireballs all over the place',
    [BonusType.SHOCK_CHAIN]: 'Chain of shocks shock the crowd',
    [BonusType.REFLEX_BOOST]: 'You get more time to react as the world slows down',
    [BonusType.SHIELD]: 'Force field protects you for a while',
    [BonusType.FREEZE]: 'Monsters are frozen',
    [BonusType.SPEED]: 'Your movement speed increases for a while',
    [BonusType.ENERGIZER]: 'Suddenly monsters run away from you',
    [BonusType.WEAPON_POWER_UP]: 'Your firerate and load time increase',
    [BonusType.FIRE_BULLETS]: 'For few seconds... make them count',
    [BonusType.MEDIKIT]: 'You regain some of your health',
  };

  // Bonus names from decompiled source
  const names: Record<BonusType, string> = {
    [BonusType.POINTS]: 'Points',
    [BonusType.WEAPON]: 'Weapon',
    [BonusType.ATOMIC]: 'Atomic',
    [BonusType.DOUBLE_EXPERIENCE]: 'Double Experience',
    [BonusType.FIREBLAST]: 'Fireblast',
    [BonusType.SHOCK_CHAIN]: 'Shock Chain',
    [BonusType.REFLEX_BOOST]: 'Reflex Boost',
    [BonusType.SHIELD]: 'Shield',
    [BonusType.FREEZE]: 'Freeze',
    [BonusType.SPEED]: 'Speed',
    [BonusType.ENERGIZER]: 'Energizer',
    [BonusType.WEAPON_POWER_UP]: 'Weapon Power Up',
    [BonusType.FIRE_BULLETS]: 'Fire Bullets',
    [BonusType.MEDIKIT]: 'MediKit',
  };

  return {
    id: type,
    name: names[type],
    description: descriptions[type],
    duration: converted.duration,
    rarity: converted.rarity,
  };
}

// Bonus data matching the original game's balance
// Values derived from decompiled bonus_metadata_init via bonus-conversions.ts
export const BONUS_DATA: Record<BonusType, BonusData> = {
  [BonusType.POINTS]: buildBonusData(BonusType.POINTS),
  [BonusType.WEAPON]: buildBonusData(BonusType.WEAPON),
  [BonusType.ATOMIC]: buildBonusData(BonusType.ATOMIC),
  [BonusType.DOUBLE_EXPERIENCE]: buildBonusData(BonusType.DOUBLE_EXPERIENCE),
  [BonusType.FIREBLAST]: buildBonusData(BonusType.FIREBLAST),
  [BonusType.SHOCK_CHAIN]: buildBonusData(BonusType.SHOCK_CHAIN),
  [BonusType.REFLEX_BOOST]: buildBonusData(BonusType.REFLEX_BOOST),
  [BonusType.SHIELD]: buildBonusData(BonusType.SHIELD),
  [BonusType.FREEZE]: buildBonusData(BonusType.FREEZE),
  [BonusType.SPEED]: buildBonusData(BonusType.SPEED),
  [BonusType.ENERGIZER]: buildBonusData(BonusType.ENERGIZER),
  [BonusType.WEAPON_POWER_UP]: buildBonusData(BonusType.WEAPON_POWER_UP),
  [BonusType.FIRE_BULLETS]: buildBonusData(BonusType.FIRE_BULLETS),
  [BonusType.MEDIKIT]: buildBonusData(BonusType.MEDIKIT),
};

/** Get bonus data by type */
export function getBonusData(type: BonusType): BonusData {
  return BONUS_DATA[type];
}

/** Get all bonus types for random selection */
export function getAllBonusTypes(): BonusType[] {
  return Object.values(BonusType).filter((v): v is number => typeof v === 'number');
}

/** Get weighted random bonus type based on rarity */
export function getRandomBonusType(): BonusType {
  const types = getAllBonusTypes();
  const totalWeight = types.reduce((sum, type) => sum + BONUS_DATA[type].rarity, 0);
  let random = Math.random() * totalWeight;

  for (const type of types) {
    random -= BONUS_DATA[type].rarity;
    if (random <= 0) {
      return type;
    }
  }

  return BonusType.POINTS;
}
