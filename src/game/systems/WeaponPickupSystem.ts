/**
 * Weapon Pickup System
 *
 * Handles weapon pickup collection and equipping.
 * Implements two-slot weapon inventory: current + alternate.
 * Priority: 85 (runs before BonusSystem to process pickups)
 */

import { System } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs';
import { WeaponId } from '../../types';
import { weaponCollectEvents } from './CollisionSystem';
import { getWeaponData } from '../data';

export class WeaponPickupSystem extends System {
  readonly name = 'WeaponPickupSystem';
  readonly priority = 85;

  private entityManager: EntityManager;

  constructor(entityManager: EntityManager) {
    super();
    this.entityManager = entityManager;
  }

  update(): void {
    // Process weapon collect events from CollisionSystem
    for (const event of weaponCollectEvents) {
      const playerEntity = this.entityManager.getEntity(event.playerId);
      if (!playerEntity) continue;

      const player = playerEntity.getComponent<'player'>('player');
      if (!player) continue;

      this.applyWeaponPickup(player, event.weaponId, event.ammo);
    }
  }

  private applyWeaponPickup(
    player: {
      currentWeapon: { weaponId: number; clipSize: number; ammo: number };
      alternateWeapon: { weaponId: number; clipSize: number; ammo: number };
    },
    pickupWeaponId: number,
    pickupAmmo: number
  ): void {
    // Validate weapon ID
    if (!Object.values(WeaponId).includes(pickupWeaponId as WeaponId)) {
      console.warn(`Invalid weapon pickup ID: ${pickupWeaponId}`);
      return;
    }

    const weaponId = pickupWeaponId as WeaponId;
    const weaponData = getWeaponData(weaponId);

    // Check if player already has this weapon equipped
    if (player.currentWeapon.weaponId === weaponId) {
      // Add ammo to current weapon
      player.currentWeapon.ammo += pickupAmmo;
      return;
    }

    if (player.alternateWeapon.weaponId === weaponId) {
      // Add ammo to alternate weapon and swap to it
      player.alternateWeapon.ammo += pickupAmmo;
      this.swapWeapons(player);
      return;
    }

    // Check if current weapon is the default pistol (and we have an alternate)
    // If so, replace the alternate with the new weapon
    if (player.currentWeapon.weaponId === WeaponId.PISTOL && player.alternateWeapon.weaponId !== WeaponId.PISTOL) {
      // Replace alternate with new weapon, keep pistol as fallback
      player.alternateWeapon = {
        weaponId,
        clipSize: Math.min(weaponData.clipSize, pickupAmmo),
        ammo: Math.max(0, pickupAmmo - weaponData.clipSize),
      };
      // Swap to the new weapon
      this.swapWeapons(player);
      return;
    }

    // Default: Replace alternate weapon with new weapon, swap to it
    player.alternateWeapon = {
      weaponId,
      clipSize: Math.min(weaponData.clipSize, pickupAmmo),
      ammo: Math.max(0, pickupAmmo - weaponData.clipSize),
    };

    // Swap to the new weapon
    this.swapWeapons(player);
  }

  private swapWeapons(player: {
    currentWeapon: { weaponId: number; clipSize: number; ammo: number };
    alternateWeapon: { weaponId: number; clipSize: number; ammo: number };
  }): void {
    // Swap current and alternate weapons
    const temp = { ...player.currentWeapon };
    player.currentWeapon = { ...player.alternateWeapon };
    player.alternateWeapon = temp;
  }
}
