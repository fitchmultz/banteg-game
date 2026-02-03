/**
 * Bonus System
 *
 * Handles bonus collection effects: health, ammo, speed, shields, etc.
 * Priority: 90
 */


import { System } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs/EntityManager';
import { BonusType } from '../../types';
import { collectEvents } from './CollisionSystem';
import { getWeaponData } from '../data';

export class BonusSystem extends System {
  readonly name = 'BonusSystem';
  readonly priority = 90;

  private entityManager: EntityManager;

  // Effect durations (seconds)
  private readonly weaponPowerUpDuration = 10;
  private readonly speedBoostDuration = 10;
  private readonly shieldDuration = 15;
  private readonly fireBulletsDuration = 20;

  constructor(entityManager: EntityManager) {
    super();
    this.entityManager = entityManager;
  }

  update(): void {
    // Process collect events from CollisionSystem
    for (const event of collectEvents) {
      const playerEntity = this.entityManager.getEntity(event.playerId);
      if (!playerEntity) continue;

      const player = playerEntity.getComponent<'player'>('player');
      if (!player) continue;

      this.applyBonusEffect(player, event.bonusType, event.value);
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
    player: {
      health: number;
      maxHealth: number;
      ammo: number;
      clipSize: number;
      shieldTimer: number;
      fireBulletsTimer: number;
      speedBonusTimer: number;
      weaponId: number;
    },
    bonusType: number,
    value: number
  ): void {
    switch (bonusType) {
      case BonusType.HEALTH:
        player.health = Math.min(player.maxHealth, player.health + value);
        break;

      case BonusType.AMMO: {
        // Add ammo to current weapon
        const weaponData = getWeaponData(player.weaponId);
        const ammoToAdd = Math.floor(weaponData.clipSize * 0.5);
        player.ammo += ammoToAdd;
        break;
      }

      case BonusType.WEAPON_POWER_UP:
        // Increase weapon damage temporarily
        // (Applied in WeaponSystem when firing)
        player.fireBulletsTimer = Math.max(
          player.fireBulletsTimer,
          this.weaponPowerUpDuration
        );
        break;

      case BonusType.SPEED_BOOST:
        player.speedBonusTimer = Math.max(
          player.speedBonusTimer,
          this.speedBoostDuration
        );
        break;

      case BonusType.SHIELD:
        player.shieldTimer = Math.max(
          player.shieldTimer,
          this.shieldDuration
        );
        break;

      case BonusType.FIRE_BULLETS:
        player.fireBulletsTimer = Math.max(
          player.fireBulletsTimer,
          this.fireBulletsDuration
        );
        break;

      case BonusType.EXP_MULTIPLIER:
        // Experience multiplier would be tracked in a separate system
        // For now, just grant immediate XP
        // (XP is tracked in HealthSystem)
        break;
    }
  }
}
