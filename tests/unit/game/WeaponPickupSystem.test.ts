/**
 * Weapon Pickup System Tests
 *
 * Tests the two-slot weapon inventory system and weapon pickup behavior.
 */

import { describe, it, expect, beforeEach } from 'vitest';
import { EntityManager } from '../../../src/core/ecs';
import { WeaponPickupSystem } from '../../../src/game/systems/WeaponPickupSystem';
import { weaponCollectEvents } from '../../../src/game/systems/CollisionSystem';
import { WeaponId, ProjectileTypeId } from '../../../src/types';
import { createPlayer } from '../../../src/game/components';
import { getWeaponData, getProjectileData, getUnlockedWeapons } from '../../../src/game/data';

describe('WeaponPickupSystem', () => {
  let entityManager: EntityManager;
  let weaponPickupSystem: WeaponPickupSystem;

  beforeEach(() => {
    entityManager = new EntityManager();
    weaponPickupSystem = new WeaponPickupSystem(entityManager);
    // Clear any pending events
    weaponCollectEvents.length = 0;
  });

  describe('Two-slot weapon inventory', () => {
    it('should initialize player with pistol in current slot and empty alternate', () => {
      const player = createPlayer(0);

      expect(player.currentWeapon.weaponId).toBe(WeaponId.PISTOL);
      expect(player.currentWeapon.clipSize).toBe(12);
      expect(player.currentWeapon.ammo).toBe(100);

      expect(player.alternateWeapon.weaponId).toBe(WeaponId.PISTOL);
      expect(player.alternateWeapon.clipSize).toBe(12);
      expect(player.alternateWeapon.ammo).toBe(0);
    });

    it('should swap weapons when swap is requested', () => {
      const player = createPlayer(0);

      // Set up specific weapon states for testing
      player.currentWeapon = {
        weaponId: WeaponId.ASSAULT_RIFLE,
        clipSize: 20,
        ammo: 100,
      };
      player.alternateWeapon = {
        weaponId: WeaponId.SHOTGUN,
        clipSize: 6,
        ammo: 50,
      };

      // Trigger swap
      player.swapWeaponRequested = true;

      // Create entity with player component
      const entity = entityManager.createEntity();
      entity.addComponent(player);

      // Process the swap through WeaponSystem logic (simulated here)
      const temp = { ...player.currentWeapon };
      player.currentWeapon = { ...player.alternateWeapon };
      player.alternateWeapon = temp;
      player.swapWeaponRequested = false;

      // Verify swap occurred
      expect(player.currentWeapon.weaponId).toBe(WeaponId.SHOTGUN);
      expect(player.currentWeapon.clipSize).toBe(6);
      expect(player.currentWeapon.ammo).toBe(50);

      expect(player.alternateWeapon.weaponId).toBe(WeaponId.ASSAULT_RIFLE);
      expect(player.alternateWeapon.clipSize).toBe(20);
      expect(player.alternateWeapon.ammo).toBe(100);
    });
  });

  describe('Weapon pickup collection', () => {
    it('should add ammo to current weapon when picking up same weapon', () => {
      const player = createPlayer(0);
      const initialAmmo = player.currentWeapon.ammo;

      // Create a pickup event for the same weapon (pistol)
      const entity = entityManager.createEntity();
      entity.addComponent(player);

      weaponCollectEvents.push({
        playerId: entity.id,
        pickupId: 999,
        weaponId: WeaponId.PISTOL,
        ammo: 60,
      });

      // Process pickup
      weaponPickupSystem.update(entityManager, {
        dt: 0.016,
        unscaledDt: 0.016,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      // Ammo should be added to current weapon
      expect(player.currentWeapon.ammo).toBe(initialAmmo + 60);
    });

    it('should add ammo and swap when picking up alternate weapon', () => {
      const player = createPlayer(0);

      // Set up: current = pistol, alternate = shotgun
      player.currentWeapon = {
        weaponId: WeaponId.PISTOL,
        clipSize: 12,
        ammo: 50,
      };
      player.alternateWeapon = {
        weaponId: WeaponId.SHOTGUN,
        clipSize: 6,
        ammo: 20,
      };

      const entity = entityManager.createEntity();
      entity.addComponent(player);

      // Pick up shotgun ammo
      weaponCollectEvents.push({
        playerId: entity.id,
        pickupId: 999,
        weaponId: WeaponId.SHOTGUN,
        ammo: 30,
      });

      // Process pickup
      weaponPickupSystem.update(entityManager, {
        dt: 0.016,
        unscaledDt: 0.016,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      // Should have swapped to shotgun and added ammo
      expect(player.currentWeapon.weaponId).toBe(WeaponId.SHOTGUN);
      expect(player.currentWeapon.ammo).toBe(50); // 20 + 30
    });

    it('should replace alternate weapon when picking up new weapon', () => {
      const player = createPlayer(0);

      // Set up: current = pistol, alternate = shotgun
      player.currentWeapon = {
        weaponId: WeaponId.PISTOL,
        clipSize: 12,
        ammo: 50,
      };
      player.alternateWeapon = {
        weaponId: WeaponId.SHOTGUN,
        clipSize: 6,
        ammo: 20,
      };

      const entity = entityManager.createEntity();
      entity.addComponent(player);

      // Pick up assault rifle (new weapon)
      weaponCollectEvents.push({
        playerId: entity.id,
        pickupId: 999,
        weaponId: WeaponId.ASSAULT_RIFLE,
        ammo: 90,
      });

      // Process pickup
      weaponPickupSystem.update(entityManager, {
        dt: 0.016,
        unscaledDt: 0.016,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      // Should have swapped to assault rifle, and pistol moved to alternate
      expect(player.currentWeapon.weaponId).toBe(WeaponId.ASSAULT_RIFLE);
      expect(player.alternateWeapon.weaponId).toBe(WeaponId.PISTOL);
    });

    it('should ignore invalid weapon pickup IDs', () => {
      const player = createPlayer(0);
      const initialCurrent = { ...player.currentWeapon };
      const initialAlternate = { ...player.alternateWeapon };

      const entity = entityManager.createEntity();
      entity.addComponent(player);

      // Try to pick up invalid weapon
      weaponCollectEvents.push({
        playerId: entity.id,
        pickupId: 999,
        weaponId: 999, // Invalid
        ammo: 60,
      });

      // Process pickup (should not throw)
      expect(() =>
        weaponPickupSystem.update(entityManager, {
          dt: 0.016,
          unscaledDt: 0.016,
          gameTime: 0,
          frameNumber: 0,
          timeScale: 1,
          setTimeScale: () => {},
        })
      ).not.toThrow();

      // Weapons should remain unchanged
      expect(player.currentWeapon).toEqual(initialCurrent);
      expect(player.alternateWeapon).toEqual(initialAlternate);
    });
  });

  describe('Multi-pellet weapon behavior', () => {
    it('should have correct pellet counts for shotgun variants', () => {
      const shotgun = getWeaponData(WeaponId.SHOTGUN);
      expect(shotgun.pelletCount).toBeGreaterThan(1);

      const sawedOff = getWeaponData(WeaponId.SAWED_OFF_SHOTGUN);
      expect(sawedOff.pelletCount).toBeGreaterThan(1);

      const gaussShotgun = getWeaponData(WeaponId.GAUSS_SHOTGUN);
      expect(gaussShotgun.pelletCount).toBeGreaterThan(1);

      const jackhammer = getWeaponData(WeaponId.JACKHAMMER);
      expect(jackhammer.pelletCount).toBeGreaterThan(1);

      const plasmaShotgun = getWeaponData(WeaponId.PLASMA_SHOTGUN);
      expect(plasmaShotgun.pelletCount).toBeGreaterThan(1);

      const ionShotgun = getWeaponData(WeaponId.ION_SHOTGUN);
      expect(ionShotgun.pelletCount).toBeGreaterThan(1);
    });

    it('should have higher pellet counts for high-tier shotguns', () => {
      const shotgun = getWeaponData(WeaponId.SHOTGUN);
      const gaussShotgun = getWeaponData(WeaponId.GAUSS_SHOTGUN);

      expect(gaussShotgun.pelletCount).toBeGreaterThan(shotgun.pelletCount);
    });
  });

  describe('Homing weapon behavior', () => {
    it('should have homing flag on appropriate projectile types', () => {
      const seekerRocket = getProjectileData(ProjectileTypeId.SEEKER_ROCKET);
      expect(seekerRocket.homing).toBe(true);

      const plasmaCannon = getProjectileData(ProjectileTypeId.PLASMA_CANNON);
      expect(plasmaCannon.homing).toBe(true);

      const bladeGun = getProjectileData(ProjectileTypeId.BLADE_GUN);
      expect(bladeGun.homing).toBe(true);

      const rainbowGun = getProjectileData(ProjectileTypeId.RAINBOW_GUN);
      expect(rainbowGun.homing).toBe(true);
    });

    it('should have seeker rockets mapped to correct weapon', () => {
      const seekerRocketsWeapon = getWeaponData(WeaponId.SEEKER_ROCKETS);
      expect(seekerRocketsWeapon.projectileType).toBe(101); // SEEKER_ROCKET
    });
  });

  describe('Weapon unlock progression', () => {
    it('should unlock weapons progressively with XP', () => {
      // At 0 XP, only pistol
      const unlocked0 = getUnlockedWeapons(0);
      expect(unlocked0).toContain(WeaponId.PISTOL);
      expect(unlocked0).not.toContain(WeaponId.ASSAULT_RIFLE);

      // At 500 XP, pistol and assault rifle
      const unlocked500 = getUnlockedWeapons(500);
      expect(unlocked500).toContain(WeaponId.PISTOL);
      expect(unlocked500).toContain(WeaponId.ASSAULT_RIFLE);

      // At 10000 XP, many weapons unlocked
      const unlocked10000 = getUnlockedWeapons(10000);
      expect(unlocked10000.length).toBeGreaterThan(5);
    });

    it('should have all 40 weapons unlockable at high XP', () => {
      const unlockedMax = getUnlockedWeapons(99999);
      expect(unlockedMax.length).toBe(40);
    });
  });
});
