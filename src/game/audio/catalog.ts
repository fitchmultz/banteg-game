/**
 * Audio Catalog
 *
 * Central mapping layer for game events to audio sample names.
 * Avoids ad-hoc sound fields in data structures like WeaponData.
 *
 * Responsibilities:
 * - Map WeaponId to fire/reload sound sample names
 * - Map BonusType to pickup sound sample names
 * - Map damage/death events to appropriate SFX
 *
 * Non-goals:
 * - Does NOT load audio files (use loadGameAudio for that)
 * - Does NOT play sounds (use AudioManager for that)
 */

import { WeaponId, BonusType, type ProjectileTypeId } from '../../types';

/** All available SFX sample names */
export type SampleName =
  | 'weapon_fire_gun'
  | 'weapon_fire_shotgun'
  | 'weapon_fire_energy'
  | 'weapon_reload'
  | 'hit_player'
  | 'hit_enemy'
  | 'death_enemy'
  | 'death_player'
  | 'pickup_bonus'
  | 'pickup_weapon'
  | 'explosion';

/** All available music track names */
export type TuneName = 'music_game_loop';

/** Sample name constants for type-safe usage */
export const SAMPLES = {
  WEAPON_FIRE_GUN: 'weapon_fire_gun' as const,
  WEAPON_FIRE_SHOTGUN: 'weapon_fire_shotgun' as const,
  WEAPON_FIRE_ENERGY: 'weapon_fire_energy' as const,
  WEAPON_RELOAD: 'weapon_reload' as const,
  HIT_PLAYER: 'hit_player' as const,
  HIT_ENEMY: 'hit_enemy' as const,
  DEATH_ENEMY: 'death_enemy' as const,
  DEATH_PLAYER: 'death_player' as const,
  PICKUP_BONUS: 'pickup_bonus' as const,
  PICKUP_WEAPON: 'pickup_weapon' as const,
  EXPLOSION: 'explosion' as const,
};

/** Tune name constants */
export const TUNES = {
  GAME: 'music_game_loop' as const,
};

/**
 * Get the appropriate fire sound sample for a weapon.
 * Shotgun-type weapons get the shotgun sound, energy weapons get energy sound.
 */
export function getWeaponFireSample(weaponId: WeaponId): SampleName {
  switch (weaponId) {
    // Shotgun variants
    case WeaponId.SHOTGUN:
    case WeaponId.SAWED_OFF_SHOTGUN:
    case WeaponId.JACKHAMMER:
    case WeaponId.GAUSS_SHOTGUN:
    case WeaponId.PLASMA_SHOTGUN:
    case WeaponId.ION_SHOTGUN:
      return SAMPLES.WEAPON_FIRE_SHOTGUN;

    // Energy weapons (plasma, ion, pulse)
    case WeaponId.FLAMETHROWER:
    case WeaponId.PLASMA_RIFLE:
    case WeaponId.MULTI_PLASMA:
    case WeaponId.PLASMA_MINIGUN:
    case WeaponId.PULSE_GUN:
    case WeaponId.PLASMA_CANNON:
    case WeaponId.BLOW_TORCH:
    case WeaponId.HR_FLAMER:
    case WeaponId.FLAMEBURST:
    case WeaponId.ION_RIFLE:
    case WeaponId.ION_MINIGUN:
    case WeaponId.ION_CANNON:
      return SAMPLES.WEAPON_FIRE_ENERGY;

    // Default to gun sound for everything else
    default:
      return SAMPLES.WEAPON_FIRE_GUN;
  }
}

/**
 * Get the reload sound sample.
 * Currently all weapons use the same reload sound.
 */
export function getWeaponReloadSample(_weaponId: WeaponId): SampleName {
  return SAMPLES.WEAPON_RELOAD;
}

/**
 * Get the appropriate pickup sound for a bonus type.
 */
export function getBonusPickupSample(bonusType: BonusType): SampleName {
  switch (bonusType) {
    case BonusType.WEAPON_POWER_UP:
      return SAMPLES.PICKUP_WEAPON;
    default:
      return SAMPLES.PICKUP_BONUS;
  }
}

/** Options for damage sound selection */
export interface DamageSoundOptions {
  /** Whether the target is the player */
  targetIsPlayer: boolean;
  /** Whether the damage is fire-based */
  isFireDamage: boolean;
  /** Optional projectile type for context */
  projectileTypeId?: ProjectileTypeId;
}

/**
 * Get the appropriate hit sound for a damage event.
 */
export function getDamageSample(options: DamageSoundOptions): SampleName {
  if (options.targetIsPlayer) {
    return SAMPLES.HIT_PLAYER;
  }
  return SAMPLES.HIT_ENEMY;
}

/** Options for death sound selection */
export interface DeathSoundOptions {
  /** Whether the entity that died is the player */
  isPlayer: boolean;
  /** Optional creature type for variant sounds */
  creatureTypeId?: number;
  /** Whether this was an explosion kill */
  isExplosion?: boolean;
}

/**
 * Get the appropriate death sound.
 */
export function getDeathSample(options: DeathSoundOptions): SampleName {
  if (options.isPlayer) {
    return SAMPLES.DEATH_PLAYER;
  }
  if (options.isExplosion) {
    return SAMPLES.EXPLOSION;
  }
  return SAMPLES.DEATH_ENEMY;
}

/** All SFX samples that should be loaded for gameplay */
export const ALL_SFX_SAMPLES: SampleName[] = [
  SAMPLES.WEAPON_FIRE_GUN,
  SAMPLES.WEAPON_FIRE_SHOTGUN,
  SAMPLES.WEAPON_FIRE_ENERGY,
  SAMPLES.WEAPON_RELOAD,
  SAMPLES.HIT_PLAYER,
  SAMPLES.HIT_ENEMY,
  SAMPLES.DEATH_ENEMY,
  SAMPLES.DEATH_PLAYER,
  SAMPLES.PICKUP_BONUS,
  SAMPLES.PICKUP_WEAPON,
  SAMPLES.EXPLOSION,
];

/** All music tracks that should be loaded */
export const ALL_TUNES: TuneName[] = [TUNES.GAME];
