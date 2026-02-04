/**
 * Bonus/Powerup Data Tables
 *
 * Based on bonus_metadata_init from decompiled source at 00412660.
 * Defines all bonus/powerup types with their metadata.
 */

import { BonusType } from '../../types/game';

export interface BonusData {
  id: BonusType;
  name: string;
  description: string;
  duration: number; // seconds, -1 = permanent/instant
  rarity: number; // spawn weight
}

// Bonus data matching the original game's balance
// Values derived from decompiled bonus_metadata_init
export const BONUS_DATA: Record<BonusType, BonusData> = {
  [BonusType.POINTS]: {
    id: BonusType.POINTS,
    name: 'Points',
    description: 'You gain some experience points',
    duration: 12,
    rarity: 500,
  },
  [BonusType.WEAPON]: {
    id: BonusType.WEAPON,
    name: 'Weapon',
    description: 'You get a new weapon',
    duration: -1,
    rarity: 3,
  },
  [BonusType.ATOMIC]: {
    id: BonusType.ATOMIC,
    name: 'Atomic',
    description: 'An amazing explosion of ATOMIC power',
    duration: 1,
    rarity: 1,
  },
  [BonusType.DOUBLE_EXPERIENCE]: {
    id: BonusType.DOUBLE_EXPERIENCE,
    name: 'Double Experience',
    description: 'Every experience point you get is doubled',
    duration: 4,
    rarity: 1,
  },
  [BonusType.FIREBLAST]: {
    id: BonusType.FIREBLAST,
    name: 'Fireblast',
    description: 'Fireballs all over the place',
    duration: 2,
    rarity: 1,
  },
  [BonusType.SHOCK_CHAIN]: {
    id: BonusType.SHOCK_CHAIN,
    name: 'Shock Chain',
    description: 'Chain of shocks shock the crowd',
    duration: 3,
    rarity: 1,
  },
  [BonusType.REFLEX_BOOST]: {
    id: BonusType.REFLEX_BOOST,
    name: 'Reflex Boost',
    description: 'You get more time to react as the world slows down',
    duration: 5,
    rarity: 3,
  },
  [BonusType.SHIELD]: {
    id: BonusType.SHIELD,
    name: 'Shield',
    description: 'Force field protects you for a while',
    duration: 6,
    rarity: 7,
  },
  [BonusType.FREEZE]: {
    id: BonusType.FREEZE,
    name: 'Freeze',
    description: 'Monsters are frozen',
    duration: 8,
    rarity: 5,
  },
  [BonusType.SPEED]: {
    id: BonusType.SPEED,
    name: 'Speed',
    description: 'Your movement speed increases for a while',
    duration: 9,
    rarity: 8,
  },
  [BonusType.ENERGIZER]: {
    id: BonusType.ENERGIZER,
    name: 'Energizer',
    description: 'Suddenly monsters run away from you',
    duration: 10,
    rarity: 8,
  },
  [BonusType.WEAPON_POWER_UP]: {
    id: BonusType.WEAPON_POWER_UP,
    name: 'Weapon Power Up',
    description: 'Your firerate and load time increase',
    duration: 7,
    rarity: 10,
  },
  [BonusType.FIRE_BULLETS]: {
    id: BonusType.FIRE_BULLETS,
    name: 'Fire Bullets',
    description: 'For few seconds... make them count',
    duration: 11,
    rarity: 4,
  },
  [BonusType.MEDIKIT]: {
    id: BonusType.MEDIKIT,
    name: 'MediKit',
    description: 'You regain some of your health',
    duration: 14,
    rarity: 10,
  },
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
