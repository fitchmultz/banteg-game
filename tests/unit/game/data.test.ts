/**
 * Game Data Unit Tests
 */

import { describe, it, expect } from 'vitest';
import {
  WEAPON_DATA,
  getWeaponData,
  isWeaponUnlocked,
  getUnlockedWeapons,
  CREATURE_DATA,
  getCreatureData,
  getCreaturesForWave,
  selectRandomCreatureForWave,
  PROJECTILE_DATA,
  getProjectileData,
} from '../../../src/game/data';
import { WeaponId, CreatureTypeId, ProjectileTypeId } from '../../../src/types';

describe('Weapon Data', () => {
  it('should have valid weapon data for all weapon IDs', () => {
    const weaponIds = Object.values(WeaponId).filter(
      (id): id is WeaponId => typeof id === 'number'
    );

    for (const id of weaponIds) {
      const data = getWeaponData(id);
      expect(data).toBeDefined();
      expect(data.name).toBeTruthy();
      expect(data.damage).toBeGreaterThan(0);
      expect(data.fireRate).toBeGreaterThan(0);
      expect(data.clipSize).toBeGreaterThan(0);
      expect(data.reloadTime).toBeGreaterThan(0);
      expect(data.pelletCount).toBeGreaterThan(0);
      expect(data.moveSpeedMultiplier).toBeGreaterThan(0);
    }
  });

  it('should have WEAPON_DATA entries for every WeaponId', () => {
    const weaponIds = Object.values(WeaponId).filter(
      (id): id is WeaponId => typeof id === 'number'
    );

    // Should have 30 weapons (0-29)
    expect(weaponIds.length).toBe(30);

    // Every WeaponId should have a corresponding entry in WEAPON_DATA
    for (const id of weaponIds) {
      expect(WEAPON_DATA[id]).toBeDefined();
      expect(WEAPON_DATA[id].name).toBeTruthy();
    }
  });

  it('should have valid projectile type for every weapon', () => {
    const weaponIds = Object.values(WeaponId).filter(
      (id): id is WeaponId => typeof id === 'number'
    );

    for (const id of weaponIds) {
      const weaponData = getWeaponData(id);
      expect(weaponData.projectileType).toBeDefined();
      // Verify the projectile type exists in PROJECTILE_DATA
      const projectileData = getProjectileData(weaponData.projectileType);
      expect(projectileData).toBeDefined();
    }
  });

  it('should return pistol data for invalid weapon ID', () => {
    const data = getWeaponData(999 as WeaponId);
    expect(data).toEqual(WEAPON_DATA[WeaponId.PISTOL]);
  });

  it('should correctly determine weapon unlock status', () => {
    expect(isWeaponUnlocked(WeaponId.PISTOL, 0)).toBe(true);
    expect(isWeaponUnlocked(WeaponId.PISTOL, 1000)).toBe(true);
    expect(isWeaponUnlocked(WeaponId.ASSAULT_RIFLE, 0)).toBe(false);
    expect(isWeaponUnlocked(WeaponId.ASSAULT_RIFLE, 500)).toBe(true);
  });

  it('should return unlocked weapons for given XP', () => {
    const unlockedAt0 = getUnlockedWeapons(0);
    expect(unlockedAt0).toContain(WeaponId.PISTOL);
    expect(unlockedAt0).not.toContain(WeaponId.ASSAULT_RIFLE);

    const unlockedAt500 = getUnlockedWeapons(500);
    expect(unlockedAt500).toContain(WeaponId.PISTOL);
    expect(unlockedAt500).toContain(WeaponId.ASSAULT_RIFLE);
  });

  it('should have progression of unlock XP values', () => {
    // Early weapons should have lower unlock XP
    expect(WEAPON_DATA[WeaponId.PISTOL].unlockXp).toBe(0);
    expect(WEAPON_DATA[WeaponId.ASSAULT_RIFLE].unlockXp).toBeGreaterThan(0);
    expect(WEAPON_DATA[WeaponId.SHOTGUN].unlockXp).toBeGreaterThan(
      WEAPON_DATA[WeaponId.ASSAULT_RIFLE].unlockXp
    );

    // Late/exotic weapons should have high unlock XP
    expect(WEAPON_DATA[WeaponId.ION_CANNON].unlockXp).toBeGreaterThan(10000);
  });

  it('should have multi-pellet weapons with pelletCount > 1', () => {
    const shotgun = getWeaponData(WeaponId.SHOTGUN);
    expect(shotgun.pelletCount).toBeGreaterThan(1);

    const sawedOff = getWeaponData(WeaponId.SAWED_OFF_SHOTGUN);
    expect(sawedOff.pelletCount).toBeGreaterThan(1);

    const gaussShotgun = getWeaponData(WeaponId.GAUSS_SHOTGUN);
    expect(gaussShotgun.pelletCount).toBeGreaterThan(1);
  });
});

describe('Creature Data', () => {
  it('should have valid creature data for all creature types', () => {
    const creatureIds = Object.values(CreatureTypeId).filter(
      (id): id is CreatureTypeId => typeof id === 'number'
    );

    for (const id of creatureIds) {
      const data = getCreatureData(id);
      expect(data).toBeDefined();
      expect(data.name).toBeTruthy();
      expect(data.health).toBeGreaterThan(0);
      expect(data.speed).toBeGreaterThan(0);
      expect(data.hitboxRadius).toBeGreaterThan(0);
      expect(data.rewardXP).toBeGreaterThan(0);
      expect(data.spawnWeight).toBeGreaterThan(0);
    }
  });

  it('should return zombie data for invalid creature ID', () => {
    const data = getCreatureData(999 as CreatureTypeId);
    expect(data).toEqual(CREATURE_DATA[CreatureTypeId.ZOMBIE]);
  });

  it('should return creatures available for wave', () => {
    const wave1Creatures = getCreaturesForWave(1);
    expect(wave1Creatures).toContain(CreatureTypeId.ZOMBIE);
    expect(wave1Creatures).not.toContain(CreatureTypeId.ZOMBIE_TANK);

    const wave3Creatures = getCreaturesForWave(3);
    expect(wave3Creatures).toContain(CreatureTypeId.ZOMBIE);
    expect(wave3Creatures).toContain(CreatureTypeId.ZOMBIE_TANK);
  });

  it('should select valid random creature for wave', () => {
    for (let wave = 1; wave <= 10; wave++) {
      const creature = selectRandomCreatureForWave(wave);
      expect(typeof creature).toBe('number');
      const data = getCreatureData(creature);
      expect(data.minWave).toBeLessThanOrEqual(wave);
    }
  });

  it('should have different stats for different creature types', () => {
    const zombie = getCreatureData(CreatureTypeId.ZOMBIE);
    const fastZombie = getCreatureData(CreatureTypeId.ZOMBIE_FAST);
    const tankZombie = getCreatureData(CreatureTypeId.ZOMBIE_TANK);

    expect(fastZombie.speed).toBeGreaterThan(zombie.speed);
    expect(tankZombie.health).toBeGreaterThan(zombie.health);
    expect(tankZombie.speed).toBeLessThan(zombie.speed);
  });
});

describe('Projectile Data', () => {
  it('should have valid projectile data for all projectile types', () => {
    const projectileIds = Object.values(ProjectileTypeId).filter(
      (id): id is ProjectileTypeId => typeof id === 'number'
    );

    for (const id of projectileIds) {
      const data = getProjectileData(id);
      expect(data).toBeDefined();
      expect(data.name).toBeTruthy();
      expect(data.speed).toBeGreaterThan(0);
      expect(data.lifetime).toBeGreaterThan(0);
      expect(data.radius).toBeGreaterThan(0);
    }
  });

  it('should return pistol projectile for invalid ID', () => {
    const data = getProjectileData(999 as ProjectileTypeId);
    expect(data).toEqual(PROJECTILE_DATA[ProjectileTypeId.PISTOL]);
  });

  it('should have different speeds for different projectiles', () => {
    const pistol = getProjectileData(ProjectileTypeId.PISTOL);
    const gauss = getProjectileData(ProjectileTypeId.GAUSS_GUN);

    expect(gauss.speed).toBeGreaterThan(pistol.speed);
  });

  it('should identify fire damage projectiles', () => {
    const rocket = getProjectileData(ProjectileTypeId.ROCKET);
    const fireBullet = getProjectileData(ProjectileTypeId.FIRE_BULLETS);
    const pistol = getProjectileData(ProjectileTypeId.PISTOL);

    expect(rocket.fireDamage).toBe(true);
    expect(fireBullet.fireDamage).toBe(true);
    expect(pistol.fireDamage).toBe(false);
  });

  it('should identify homing projectiles', () => {
    const seekerRocket = getProjectileData(ProjectileTypeId.SEEKER_ROCKET);
    const plasmaCannon = getProjectileData(ProjectileTypeId.PLASMA_CANNON);
    const bladeGun = getProjectileData(ProjectileTypeId.BLADE_GUN);
    const rainbowGun = getProjectileData(ProjectileTypeId.RAINBOW_GUN);
    const pistol = getProjectileData(ProjectileTypeId.PISTOL);

    expect(seekerRocket.homing).toBe(true);
    expect(plasmaCannon.homing).toBe(true);
    expect(bladeGun.homing).toBe(true);
    expect(rainbowGun.homing).toBe(true);
    expect(pistol.homing).toBe(false);
  });

  it('should have PROJECTILE_DATA entries for all standard projectile types', () => {
    // Check that all standard projectile types (0-17, 100-102) have entries
    const standardTypes = [
      ProjectileTypeId.PISTOL,
      ProjectileTypeId.ASSAULT_RIFLE,
      ProjectileTypeId.SUBMACHINE_GUN,
      ProjectileTypeId.SHOTGUN,
      ProjectileTypeId.PLASMA_RIFLE,
      ProjectileTypeId.PLASMA_MINIGUN,
      ProjectileTypeId.ION_RIFLE,
      ProjectileTypeId.ION_MINIGUN,
      ProjectileTypeId.ION_CANNON,
      ProjectileTypeId.PLASMA_CANNON,
      ProjectileTypeId.GAUSS_GUN,
      ProjectileTypeId.PULSE_GUN,
      ProjectileTypeId.BLADE_GUN,
      ProjectileTypeId.SPLITTER_GUN,
      ProjectileTypeId.SHRINKIFIER,
      ProjectileTypeId.FIRE_BULLETS,
      ProjectileTypeId.PLAGUE_SPREADER,
      ProjectileTypeId.RAINBOW_GUN,
      ProjectileTypeId.ROCKET,
      ProjectileTypeId.SEEKER_ROCKET,
      ProjectileTypeId.ROCKET_MINIGUN,
    ];

    for (const type of standardTypes) {
      expect(PROJECTILE_DATA[type]).toBeDefined();
      expect(PROJECTILE_DATA[type].name).toBeTruthy();
    }
  });
});
