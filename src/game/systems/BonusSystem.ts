/**
 * Bonus System
 *
 * Handles bonus collection effects: health, ammo, speed, shields, etc.
 * Applies perk multipliers (bonus duration, ammo refill on pickup).
 * Priority: 90
 */

import type { EntityManager } from '../../core/ecs/EntityManager';
import { System, type UpdateContext } from '../../core/ecs/System';
import { BonusType, PerkId } from '../../types';
import { getWeaponData } from '../data';
import { collectEvents } from './CollisionSystem';
import type { PerkSystem } from './PerkSystem';

export class BonusSystem extends System {
  readonly name = 'BonusSystem';
  readonly priority = 90;

  private entityManager: EntityManager;
  private perkSystem: PerkSystem | null = null;

  // Base effect durations (seconds)
  private readonly weaponPowerUpDuration = 10;
  private readonly speedBoostDuration = 10;
  private readonly shieldDuration = 15;
  private readonly fireBulletsDuration = 20;

  constructor(entityManager: EntityManager, perkSystem?: PerkSystem) {
    super();
    this.entityManager = entityManager;
    if (perkSystem) {
      this.perkSystem = perkSystem;
    }
  }

  /**
   * Set the perk system for accessing perk multipliers
   */
  setPerkSystem(perkSystem: PerkSystem): void {
    this.perkSystem = perkSystem;
  }

  private readonly reflexTimeScale = 0.4;

  update(_entityManager: EntityManager, context: UpdateContext): void {
    // Process collect events from CollisionSystem
    for (const event of collectEvents) {
      const playerEntity = this.entityManager.getEntity(event.playerId);
      if (!playerEntity) continue;

      const player = playerEntity.getComponent<'player'>('player');
      if (!player) continue;

      this.applyBonusEffect(event.playerId, player, event.bonusType, event.value, context);
    }

    // Update existing bonuses (remove expired)
    const bonuses = this.entityManager.query(['bonus', 'lifetime']);
    for (const entity of bonuses) {
      const bonus = entity.getComponent<'bonus'>('bonus');
      const lifetime = entity.getComponent<'lifetime'>('lifetime');
      if (!bonus || !lifetime) continue;

      // Update lifetime (also tracked in LifetimeSystem, but we check here too)
      bonus.lifetime = lifetime.remaining;
    }
  }

  private applyBonusEffect(
    playerId: number,
    player: {
      health: number;
      maxHealth: number;
      currentWeapon: { weaponId: number; clipSize: number; ammo: number };
      alternateWeapon: { weaponId: number; clipSize: number; ammo: number };
      shieldTimer: number;
      fireBulletsTimer: number;
      speedBonusTimer: number;

      // New timers
      freezeTimer: number;
      energizerTimer: number;
      reflexBoostTimer: number;

      perkCounts: Map<PerkId, number>;
    },
    bonusType: number,
    value: number,
    context: UpdateContext
  ): void {
    // Get bonus duration multiplier from perks
    const durationMultiplier = this.perkSystem?.getBonusDurationMultiplier(playerId) ?? 1;

    // Get Pyrokinetic bonus for fire bullets (adds 50% duration)
    const hasPyrokinetic = player.perkCounts.has(PerkId.PYROKINETIC);
    const pyrokineticMultiplier = hasPyrokinetic ? 1.5 : 1;

    switch (bonusType) {
      case BonusType.MEDIKIT:
        player.health = Math.min(player.maxHealth, player.health + value);
        break;

      case BonusType.WEAPON: {
        // Add ammo to current weapon
        const weaponData = getWeaponData(player.currentWeapon.weaponId);
        const ammoToAdd = Math.floor(weaponData.clipSize * 0.5);
        player.currentWeapon.ammo += ammoToAdd;

        // Apply Ammo Maniac clip refill if perk is active
        if (this.perkSystem?.hasAmmoRefillOnPickup(playerId)) {
          this.perkSystem.refillWeaponClips(
            player as Parameters<PerkSystem['refillWeaponClips']>[0]
          );
        }
        break;
      }

      case BonusType.WEAPON_POWER_UP:
        // Increase weapon damage temporarily
        // (Applied in WeaponSystem when firing)
        player.fireBulletsTimer = Math.max(
          player.fireBulletsTimer,
          this.weaponPowerUpDuration * durationMultiplier
        );
        break;

      case BonusType.SPEED:
        player.speedBonusTimer = Math.max(
          player.speedBonusTimer,
          this.speedBoostDuration * durationMultiplier
        );
        break;

      case BonusType.SHIELD:
        player.shieldTimer = Math.max(player.shieldTimer, this.shieldDuration * durationMultiplier);
        break;

      case BonusType.FIRE_BULLETS:
        // Apply both general duration multiplier AND Pyrokinetic bonus
        player.fireBulletsTimer = Math.max(
          player.fireBulletsTimer,
          this.fireBulletsDuration * durationMultiplier * pyrokineticMultiplier
        );
        break;

      case BonusType.DOUBLE_EXPERIENCE:
        // Experience multiplier would be tracked in a separate system
        // For now, just grant immediate XP
        // (XP is tracked in HealthSystem)
        break;

      case BonusType.FREEZE: {
        const durationSeconds = value * durationMultiplier;
        player.freezeTimer = Math.max(player.freezeTimer, durationSeconds);
        break;
      }

      case BonusType.ENERGIZER: {
        const durationSeconds = value * durationMultiplier;
        player.energizerTimer = Math.max(player.energizerTimer, durationSeconds);
        break;
      }

      case BonusType.REFLEX_BOOST: {
        const durationSeconds = value * durationMultiplier;
        player.reflexBoostTimer = Math.max(player.reflexBoostTimer, durationSeconds);

        // Ensure the time-scale effect is never shortened by a smaller pickup.
        context.setTimeScale(this.reflexTimeScale, player.reflexBoostTimer);
        break;
      }
    }
  }
}
