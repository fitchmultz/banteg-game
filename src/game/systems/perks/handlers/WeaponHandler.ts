/**
 * Weapon Handler
 *
 * Handles weapon pickup and slot management for perks.
 */

import { WeaponId } from '../../../../types';
import type { Player, WeaponSlot } from '../../../components';
import { getWeaponData } from '../../../data';
import { calculateClipSizeBonus } from '../../../data/perks';

export class WeaponHandler {
  /**
   * Grant a random weapon to the player (helper for special_random_weapon)
   */
  grantRandomWeapon(player: Player): void {
    // Get all available weapon IDs
    const allWeaponIds = Object.values(WeaponId).filter(
      (id): id is WeaponId => typeof id === 'number'
    );

    // Filter out current weapon and pistol if possible
    const availableWeapons = allWeaponIds.filter((id) => {
      if (id === player.currentWeapon.weaponId) return false;
      // Keep pistol as fallback option
      return true;
    });

    // If no alternatives, allow pistol
    const candidateWeapons = availableWeapons.length > 0 ? availableWeapons : allWeaponIds;

    // Pick random weapon
    const randomIndex = Math.floor(Math.random() * candidateWeapons.length);
    const selectedWeaponId = candidateWeapons[randomIndex];

    if (selectedWeaponId === undefined) return;

    // Apply the weapon pickup using shared helper logic
    const weaponData = getWeaponData(selectedWeaponId);
    const pickupAmmo = Math.max(weaponData.clipSize * 3, 60);

    this.applyWeaponPickupToPlayer(player, selectedWeaponId, pickupAmmo);
  }

  /**
   * Apply a weapon pickup to a player (shared helper for consistency)
   * Mirrors the logic in WeaponPickupSystem
   */
  applyWeaponPickupToPlayer(player: Player, pickupWeaponId: WeaponId, pickupAmmo: number): void {
    const weaponData = getWeaponData(pickupWeaponId);

    // Check if player already has this weapon equipped
    if (player.currentWeapon.weaponId === pickupWeaponId) {
      // Add ammo to current weapon
      player.currentWeapon.ammo += pickupAmmo;
      return;
    }

    if (player.alternateWeapon.weaponId === pickupWeaponId) {
      // Add ammo to alternate weapon and swap to it
      player.alternateWeapon.ammo += pickupAmmo;
      this.swapWeaponSlots(player);
      return;
    }

    // Check if current weapon is the default pistol (and we have an alternate)
    // If so, replace the alternate with the new weapon
    if (
      player.currentWeapon.weaponId === WeaponId.PISTOL &&
      player.alternateWeapon.weaponId !== WeaponId.PISTOL
    ) {
      // Replace alternate with new weapon, keep pistol as fallback
      player.alternateWeapon = {
        weaponId: pickupWeaponId,
        clipSize: Math.min(weaponData.clipSize, pickupAmmo),
        ammo: Math.max(0, pickupAmmo - weaponData.clipSize),
      };
      // Swap to the new weapon
      this.swapWeaponSlots(player);
      return;
    }

    // Default: Replace alternate weapon with new weapon, swap to it
    player.alternateWeapon = {
      weaponId: pickupWeaponId,
      clipSize: Math.min(weaponData.clipSize, pickupAmmo),
      ammo: Math.max(0, pickupAmmo - weaponData.clipSize),
    };

    // Swap to the new weapon
    this.swapWeaponSlots(player);
  }

  /**
   * Swap current and alternate weapon slots
   */
  private swapWeaponSlots(player: Player): void {
    const temp: WeaponSlot = { ...player.currentWeapon };
    player.currentWeapon = { ...player.alternateWeapon };
    player.alternateWeapon = temp;
  }

  /**
   * Refill both weapon clips (for Ammo Maniac perk)
   */
  refillWeaponClips(player: Player): void {
    const currentWeaponData = getWeaponData(player.currentWeapon.weaponId);
    const alternateWeaponData = getWeaponData(player.alternateWeapon.weaponId);

    const clipBonus = calculateClipSizeBonus(player.perkCounts);

    // Refill current weapon clip
    const currentMaxClip = currentWeaponData.clipSize + clipBonus;
    const currentReloadAmount = Math.min(
      currentMaxClip - player.currentWeapon.clipSize,
      player.currentWeapon.ammo
    );
    player.currentWeapon.clipSize += currentReloadAmount;
    player.currentWeapon.ammo -= currentReloadAmount;

    // Refill alternate weapon clip
    const alternateMaxClip = alternateWeaponData.clipSize + clipBonus;
    const alternateReloadAmount = Math.min(
      alternateMaxClip - player.alternateWeapon.clipSize,
      player.alternateWeapon.ammo
    );
    player.alternateWeapon.clipSize += alternateReloadAmount;
    player.alternateWeapon.ammo -= alternateReloadAmount;
  }
}
