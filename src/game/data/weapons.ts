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
// IDs 0-29 correspond to canonical player weapons (see decompile/split/...weapon_table_init)
export const WEAPON_DATA: Record<WeaponId, WeaponData> = {
  // ============================================================================
  // BASIC WEAPONS (0-3)
  // ============================================================================

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

  // ============================================================================
  // SHOTGUN VARIANTS (4-6)
  // ============================================================================

  [WeaponId.SAWED_OFF_SHOTGUN]: {
    name: 'Sawed-off Shotgun',
    damage: 10,
    fireRate: 0.5,
    clipSize: 2,
    reloadTime: 1.5,
    spread: 0.25,
    pelletCount: 6,
    projectileType: ProjectileTypeId.SHOTGUN,
    moveSpeedMultiplier: 1.0,
    automatic: false,
    unlockXp: 3000,
  },

  [WeaponId.JACKHAMMER]: {
    name: 'Jackhammer',
    damage: 6,
    fireRate: 0.12,
    clipSize: 12,
    reloadTime: 2.0,
    spread: 0.18,
    pelletCount: 4,
    projectileType: ProjectileTypeId.SHOTGUN,
    moveSpeedMultiplier: 0.95,
    automatic: true,
    unlockXp: 4500,
  },

  [WeaponId.GAUSS_SHOTGUN]: {
    name: 'Gauss Shotgun',
    damage: 25,
    fireRate: 0.6,
    clipSize: 10,
    reloadTime: 2.2,
    spread: 0.12,
    pelletCount: 8,
    projectileType: ProjectileTypeId.GAUSS_GUN,
    moveSpeedMultiplier: 0.85,
    automatic: false,
    unlockXp: 8000,
  },

  // ============================================================================
  // ENERGY WEAPONS (7-13)
  // ============================================================================

  [WeaponId.FLAMETHROWER]: {
    name: 'Flamethrower',
    damage: 5,
    fireRate: 0.05,
    clipSize: 100,
    reloadTime: 3.0,
    spread: 0.2,
    pelletCount: 1,
    projectileType: ProjectileTypeId.FIRE_BULLETS,
    moveSpeedMultiplier: 0.9,
    automatic: true,
    unlockXp: 3500,
  },

  [WeaponId.PLASMA_RIFLE]: {
    name: 'Plasma Rifle',
    damage: 25,
    fireRate: 0.2,
    clipSize: 30,
    reloadTime: 2.5,
    spread: 0.03,
    pelletCount: 1,
    projectileType: ProjectileTypeId.PLASMA_RIFLE,
    moveSpeedMultiplier: 0.95,
    automatic: true,
    unlockXp: 4000,
  },

  [WeaponId.MULTI_PLASMA]: {
    name: 'Multi-Plasma',
    damage: 20,
    fireRate: 0.25,
    clipSize: 24,
    reloadTime: 2.8,
    spread: 0.08,
    pelletCount: 2,
    projectileType: ProjectileTypeId.PLASMA_RIFLE,
    moveSpeedMultiplier: 0.9,
    automatic: true,
    unlockXp: 5500,
  },

  [WeaponId.PLASMA_MINIGUN]: {
    name: 'Plasma Minigun',
    damage: 20,
    fireRate: 0.08,
    clipSize: 80,
    reloadTime: 3.5,
    spread: 0.1,
    pelletCount: 1,
    projectileType: ProjectileTypeId.PLASMA_MINIGUN,
    moveSpeedMultiplier: 0.85,
    automatic: true,
    unlockXp: 7000,
  },

  [WeaponId.GAUSS_GUN]: {
    name: 'Gauss Gun',
    damage: 150,
    fireRate: 0.6,
    clipSize: 6,
    reloadTime: 2.5,
    spread: 0.01,
    pelletCount: 1,
    projectileType: ProjectileTypeId.GAUSS_GUN,
    moveSpeedMultiplier: 0.8,
    automatic: false,
    unlockXp: 9000,
  },

  [WeaponId.PULSE_GUN]: {
    name: 'Pulse Gun',
    damage: 15,
    fireRate: 0.15,
    clipSize: 20,
    reloadTime: 2.0,
    spread: 0.15,
    pelletCount: 1,
    projectileType: ProjectileTypeId.PULSE_GUN,
    moveSpeedMultiplier: 0.95,
    automatic: true,
    unlockXp: 6000,
  },

  [WeaponId.PLASMA_CANNON]: {
    name: 'Plasma Cannon',
    damage: 80,
    fireRate: 0.8,
    clipSize: 4,
    reloadTime: 3.0,
    spread: 0.05,
    pelletCount: 1,
    projectileType: ProjectileTypeId.PLASMA_CANNON,
    moveSpeedMultiplier: 0.75,
    automatic: false,
    unlockXp: 10000,
  },

  // ============================================================================
  // ROCKET LAUNCHERS (14-16)
  // ============================================================================

  [WeaponId.ROCKET_LAUNCHER]: {
    name: 'Rocket Launcher',
    damage: 75,
    fireRate: 0.6,
    clipSize: 6,
    reloadTime: 3.0,
    spread: 0.08,
    pelletCount: 1,
    projectileType: ProjectileTypeId.ROCKET,
    moveSpeedMultiplier: 0.85,
    automatic: false,
    unlockXp: 5000,
  },

  [WeaponId.SEEKER_ROCKETS]: {
    name: 'Seeker Rockets',
    damage: 60,
    fireRate: 0.4,
    clipSize: 8,
    reloadTime: 2.8,
    spread: 0.1,
    pelletCount: 1,
    projectileType: ProjectileTypeId.SEEKER_ROCKET,
    moveSpeedMultiplier: 0.85,
    automatic: true,
    unlockXp: 7500,
  },

  [WeaponId.MEAN_MINIGUN]: {
    name: 'Mean Minigun',
    damage: 12,
    fireRate: 0.06,
    clipSize: 120,
    reloadTime: 4.0,
    spread: 0.15,
    pelletCount: 1,
    projectileType: ProjectileTypeId.ASSAULT_RIFLE,
    moveSpeedMultiplier: 0.8,
    automatic: true,
    unlockXp: 6500,
  },

  // ============================================================================
  // SPECIAL WEAPONS (17-22)
  // ============================================================================

  [WeaponId.PLASMA_SHOTGUN]: {
    name: 'Plasma Shotgun',
    damage: 15,
    fireRate: 0.5,
    clipSize: 16,
    reloadTime: 2.5,
    spread: 0.2,
    pelletCount: 5,
    projectileType: ProjectileTypeId.PLASMA_RIFLE,
    moveSpeedMultiplier: 0.9,
    automatic: false,
    unlockXp: 5500,
  },

  [WeaponId.BLOW_TORCH]: {
    name: 'Blow Torch',
    damage: 8,
    fireRate: 0.08,
    clipSize: 40,
    reloadTime: 2.0,
    spread: 0.25,
    pelletCount: 1,
    projectileType: ProjectileTypeId.FIRE_BULLETS,
    moveSpeedMultiplier: 1.0,
    automatic: true,
    unlockXp: 4000,
  },

  [WeaponId.HR_FLAMER]: {
    name: 'HR Flamer',
    damage: 6,
    fireRate: 0.04,
    clipSize: 80,
    reloadTime: 2.5,
    spread: 0.3,
    pelletCount: 1,
    projectileType: ProjectileTypeId.FIRE_BULLETS,
    moveSpeedMultiplier: 0.95,
    automatic: true,
    unlockXp: 6000,
  },

  [WeaponId.MINI_ROCKET_SWARMERS]: {
    name: 'Mini Rocket Swarmers',
    damage: 40,
    fireRate: 0.12,
    clipSize: 30,
    reloadTime: 3.0,
    spread: 0.12,
    pelletCount: 1,
    projectileType: ProjectileTypeId.ROCKET_MINIGUN,
    moveSpeedMultiplier: 0.9,
    automatic: true,
    unlockXp: 8500,
  },

  [WeaponId.ROCKET_MINIGUN]: {
    name: 'Rocket Minigun',
    damage: 40,
    fireRate: 0.1,
    clipSize: 40,
    reloadTime: 3.5,
    spread: 0.15,
    pelletCount: 1,
    projectileType: ProjectileTypeId.ROCKET_MINIGUN,
    moveSpeedMultiplier: 0.85,
    automatic: true,
    unlockXp: 9500,
  },

  [WeaponId.ION_RIFLE]: {
    name: 'Ion Rifle',
    damage: 30,
    fireRate: 0.15,
    clipSize: 25,
    reloadTime: 2.0,
    spread: 0.02,
    pelletCount: 1,
    projectileType: ProjectileTypeId.ION_RIFLE,
    moveSpeedMultiplier: 0.95,
    automatic: true,
    unlockXp: 7000,
  },

  // ============================================================================
  // ADVANCED ION WEAPONS (23-26)
  // ============================================================================

  [WeaponId.ION_MINIGUN]: {
    name: 'Ion Minigun',
    damage: 25,
    fireRate: 0.08,
    clipSize: 60,
    reloadTime: 3.0,
    spread: 0.06,
    pelletCount: 1,
    projectileType: ProjectileTypeId.ION_MINIGUN,
    moveSpeedMultiplier: 0.9,
    automatic: true,
    unlockXp: 9000,
  },

  [WeaponId.ION_CANNON]: {
    name: 'Ion Cannon',
    damage: 100,
    fireRate: 0.7,
    clipSize: 20,
    reloadTime: 3.5,
    spread: 0.03,
    pelletCount: 1,
    projectileType: ProjectileTypeId.ION_CANNON,
    moveSpeedMultiplier: 0.8,
    automatic: false,
    unlockXp: 12000,
  },

  [WeaponId.ION_SHOTGUN]: {
    name: 'Ion Shotgun',
    damage: 20,
    fireRate: 0.4,
    clipSize: 20,
    reloadTime: 2.5,
    spread: 0.12,
    pelletCount: 3,
    projectileType: ProjectileTypeId.ION_RIFLE,
    moveSpeedMultiplier: 0.9,
    automatic: false,
    unlockXp: 8500,
  },

  [WeaponId.EVIL_SCYTHE]: {
    name: 'Evil Scythe',
    damage: 40,
    fireRate: 0.3,
    clipSize: 25,
    reloadTime: 2.8,
    spread: 0.08,
    pelletCount: 1,
    projectileType: ProjectileTypeId.BLADE_GUN,
    moveSpeedMultiplier: 0.9,
    automatic: true,
    unlockXp: 11000,
  },

  // ============================================================================
  // EXOTIC WEAPONS (27-29)
  // ============================================================================

  [WeaponId.FLAMEBURST]: {
    name: 'Flameburst',
    damage: 25,
    fireRate: 0.25,
    clipSize: 20,
    reloadTime: 2.5,
    spread: 0.1,
    pelletCount: 1,
    projectileType: ProjectileTypeId.FIRE_BULLETS,
    moveSpeedMultiplier: 0.95,
    automatic: true,
    unlockXp: 10000,
  },

  [WeaponId.SPLITTER_GUN]: {
    name: 'Splitter Gun',
    damage: 20,
    fireRate: 0.18,
    clipSize: 24,
    reloadTime: 2.2,
    spread: 0.06,
    pelletCount: 1,
    projectileType: ProjectileTypeId.SPLITTER_GUN,
    moveSpeedMultiplier: 0.95,
    automatic: true,
    unlockXp: 10500,
  },

  [WeaponId.SHRINKIFIER]: {
    name: 'Shrinkifier',
    damage: 5,
    fireRate: 0.15,
    clipSize: 60,
    reloadTime: 2.0,
    spread: 0.05,
    pelletCount: 1,
    projectileType: ProjectileTypeId.SHRINKIFIER,
    moveSpeedMultiplier: 1.0,
    automatic: true,
    unlockXp: 11500,
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

/** Get weapon pickup ammo amount based on weapon type */
export function getWeaponPickupAmmo(weaponId: WeaponId): number {
  const data = getWeaponData(weaponId);
  // Give enough ammo for several clips
  return Math.max(data.clipSize * 3, 60);
}
