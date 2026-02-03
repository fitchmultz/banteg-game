/**
 * Weapon Data Tables
 *
 * Based on weapon_table_init from decompiled source.
 * Defines all weapon stats matching the original game's balance.
 */

import { WeaponId, ProjectileTypeId } from '../../types';

export interface WeaponData {
  /** Weapon display name */
  name: string;
  /** Base damage per projectile */
  damage: number;
  /** Time between shots (seconds) */
  fireRate: number;
  /** Magazine capacity */
  clipSize: number;
  /** Reload duration (seconds) */
  reloadTime: number;
  /** Bullet spread angle (radians) */
  spread: number;
  /** Number of pellets per shot (1 for standard bullets) */
  pelletCount: number;
  /** Type of projectile fired */
  projectileType: ProjectileTypeId;
  /** Movement speed multiplier when wielding this weapon (1.0 = normal) */
  moveSpeedMultiplier: number;
  /** Whether this weapon has automatic fire */
  automatic: boolean;
  /** Experience required to unlock */
  unlockXp: number;
}

// Weapon data matching the original game's balance
// Values derived from decompiled weapon_table_init
export const WEAPON_DATA: Record<WeaponId, WeaponData> = {
  [WeaponId.PISTOL]: {
    name: 'Pistol',
    damage: 15,
    fireRate: 0.3,
    clipSize: 12,
    reloadTime: 1.2,
    spread: 0.05,
    pelletCount: 1,
    projectileType: ProjectileTypeId.PISTOL,
    moveSpeedMultiplier: 1.0,
    automatic: false,
    unlockXp: 0,
  },
  [WeaponId.ASSAULT_RIFLE]: {
    name: 'Assault Rifle',
    damage: 12,
    fireRate: 0.1,
    clipSize: 30,
    reloadTime: 2.0,
    spread: 0.08,
    pelletCount: 1,
    projectileType: ProjectileTypeId.ASSAULT_RIFLE,
    moveSpeedMultiplier: 0.95,
    automatic: true,
    unlockXp: 500,
  },
  [WeaponId.SHOTGUN]: {
    name: 'Shotgun',
    damage: 8,
    fireRate: 0.8,
    clipSize: 8,
    reloadTime: 2.5,
    spread: 0.15,
    pelletCount: 5,
    projectileType: ProjectileTypeId.SHOTGUN,
    moveSpeedMultiplier: 0.9,
    automatic: false,
    unlockXp: 1000,
  },
  [WeaponId.SUBMACHINE_GUN]: {
    name: 'Submachine Gun',
    damage: 8,
    fireRate: 0.07,
    clipSize: 50,
    reloadTime: 1.8,
    spread: 0.12,
    pelletCount: 1,
    projectileType: ProjectileTypeId.SUBMACHINE_GUN,
    moveSpeedMultiplier: 1.0,
    automatic: true,
    unlockXp: 2000,
  },
};

/** Get weapon data by ID */
export function getWeaponData(weaponId: WeaponId): WeaponData {
  return WEAPON_DATA[weaponId] ?? WEAPON_DATA[WeaponId.PISTOL];
}

/** Check if weapon is unlocked for given XP */
export function isWeaponUnlocked(weaponId: WeaponId, experience: number): boolean {
  return experience >= WEAPON_DATA[weaponId].unlockXp;
}

/** Get all unlocked weapons for given XP */
export function getUnlockedWeapons(experience: number): WeaponId[] {
  return Object.values(WeaponId)
    .filter((id): id is WeaponId => typeof id === 'number')
    .filter((id) => isWeaponUnlocked(id, experience));
}
