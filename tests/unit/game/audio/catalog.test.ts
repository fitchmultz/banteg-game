/**
 * Audio Catalog unit tests
 */

import { describe, it, expect } from 'vitest';
import {
  SAMPLES,
  TUNES,
  ALL_SFX_SAMPLES,
  ALL_TUNES,
  getWeaponFireSample,
  getWeaponReloadSample,
  getBonusPickupSample,
  getDamageSample,
  getDeathSample,
} from '../../../../src/game/audio/catalog';
import { WeaponId, BonusType } from '../../../../src/types';

describe('Audio Catalog', () => {
  describe('SAMPLES constants', () => {
    it('should have all required SFX samples defined', () => {
      expect(SAMPLES.WEAPON_FIRE_GUN).toBe('weapon_fire_gun');
      expect(SAMPLES.WEAPON_FIRE_SHOTGUN).toBe('weapon_fire_shotgun');
      expect(SAMPLES.WEAPON_FIRE_ENERGY).toBe('weapon_fire_energy');
      expect(SAMPLES.WEAPON_RELOAD).toBe('weapon_reload');
      expect(SAMPLES.HIT_PLAYER).toBe('hit_player');
      expect(SAMPLES.HIT_ENEMY).toBe('hit_enemy');
      expect(SAMPLES.DEATH_ENEMY).toBe('death_enemy');
      expect(SAMPLES.DEATH_PLAYER).toBe('death_player');
      expect(SAMPLES.PICKUP_BONUS).toBe('pickup_bonus');
      expect(SAMPLES.PICKUP_WEAPON).toBe('pickup_weapon');
      expect(SAMPLES.EXPLOSION).toBe('explosion');
      expect(SAMPLES.EXPLOSION_LARGE).toBe('explosion_large');
      expect(SAMPLES.SHOCKWAVE).toBe('shockwave');
      expect(SAMPLES.SHOCK_HIT).toBe('shock_hit');
      expect(SAMPLES.EXPLOSION_MEDIUM).toBe('explosion_medium');
    });

    it('should have music tune constants', () => {
      expect(TUNES.GAME).toBe('music_game_loop');
    });

    it('ALL_SFX_SAMPLES should include all sample names', () => {
      expect(ALL_SFX_SAMPLES).toContain(SAMPLES.WEAPON_FIRE_GUN);
      expect(ALL_SFX_SAMPLES).toContain(SAMPLES.WEAPON_FIRE_SHOTGUN);
      expect(ALL_SFX_SAMPLES).toContain(SAMPLES.WEAPON_FIRE_ENERGY);
      expect(ALL_SFX_SAMPLES).toContain(SAMPLES.WEAPON_RELOAD);
      expect(ALL_SFX_SAMPLES).toContain(SAMPLES.HIT_PLAYER);
      expect(ALL_SFX_SAMPLES).toContain(SAMPLES.HIT_ENEMY);
      expect(ALL_SFX_SAMPLES).toContain(SAMPLES.DEATH_ENEMY);
      expect(ALL_SFX_SAMPLES).toContain(SAMPLES.DEATH_PLAYER);
      expect(ALL_SFX_SAMPLES).toContain(SAMPLES.PICKUP_BONUS);
      expect(ALL_SFX_SAMPLES).toContain(SAMPLES.PICKUP_WEAPON);
      expect(ALL_SFX_SAMPLES).toContain(SAMPLES.EXPLOSION);
      expect(ALL_SFX_SAMPLES).toContain(SAMPLES.EXPLOSION_LARGE);
      expect(ALL_SFX_SAMPLES).toContain(SAMPLES.SHOCKWAVE);
      expect(ALL_SFX_SAMPLES).toContain(SAMPLES.SHOCK_HIT);
      expect(ALL_SFX_SAMPLES).toContain(SAMPLES.EXPLOSION_MEDIUM);
      expect(ALL_SFX_SAMPLES.length).toBe(15);
    });

    it('ALL_TUNES should include game music', () => {
      expect(ALL_TUNES).toContain(TUNES.GAME);
      expect(ALL_TUNES.length).toBe(1);
    });
  });

  describe('getWeaponFireSample', () => {
    it('should return shotgun sound for shotgun weapons', () => {
      expect(getWeaponFireSample(WeaponId.SHOTGUN)).toBe(SAMPLES.WEAPON_FIRE_SHOTGUN);
      expect(getWeaponFireSample(WeaponId.SAWED_OFF_SHOTGUN)).toBe(SAMPLES.WEAPON_FIRE_SHOTGUN);
      expect(getWeaponFireSample(WeaponId.JACKHAMMER)).toBe(SAMPLES.WEAPON_FIRE_SHOTGUN);
      expect(getWeaponFireSample(WeaponId.GAUSS_SHOTGUN)).toBe(SAMPLES.WEAPON_FIRE_SHOTGUN);
      expect(getWeaponFireSample(WeaponId.PLASMA_SHOTGUN)).toBe(SAMPLES.WEAPON_FIRE_SHOTGUN);
      expect(getWeaponFireSample(WeaponId.ION_SHOTGUN)).toBe(SAMPLES.WEAPON_FIRE_SHOTGUN);
    });

    it('should return energy sound for energy weapons', () => {
      expect(getWeaponFireSample(WeaponId.FLAMETHROWER)).toBe(SAMPLES.WEAPON_FIRE_ENERGY);
      expect(getWeaponFireSample(WeaponId.PLASMA_RIFLE)).toBe(SAMPLES.WEAPON_FIRE_ENERGY);
      expect(getWeaponFireSample(WeaponId.MULTI_PLASMA)).toBe(SAMPLES.WEAPON_FIRE_ENERGY);
      expect(getWeaponFireSample(WeaponId.PLASMA_MINIGUN)).toBe(SAMPLES.WEAPON_FIRE_ENERGY);
      expect(getWeaponFireSample(WeaponId.PULSE_GUN)).toBe(SAMPLES.WEAPON_FIRE_ENERGY);
      expect(getWeaponFireSample(WeaponId.PLASMA_CANNON)).toBe(SAMPLES.WEAPON_FIRE_ENERGY);
      expect(getWeaponFireSample(WeaponId.BLOW_TORCH)).toBe(SAMPLES.WEAPON_FIRE_ENERGY);
      expect(getWeaponFireSample(WeaponId.HR_FLAMER)).toBe(SAMPLES.WEAPON_FIRE_ENERGY);
      expect(getWeaponFireSample(WeaponId.FLAMEBURST)).toBe(SAMPLES.WEAPON_FIRE_ENERGY);
      expect(getWeaponFireSample(WeaponId.ION_RIFLE)).toBe(SAMPLES.WEAPON_FIRE_ENERGY);
      expect(getWeaponFireSample(WeaponId.ION_MINIGUN)).toBe(SAMPLES.WEAPON_FIRE_ENERGY);
      expect(getWeaponFireSample(WeaponId.ION_CANNON)).toBe(SAMPLES.WEAPON_FIRE_ENERGY);
    });

    it('should return gun sound for ballistic weapons', () => {
      expect(getWeaponFireSample(WeaponId.PISTOL)).toBe(SAMPLES.WEAPON_FIRE_GUN);
      expect(getWeaponFireSample(WeaponId.ASSAULT_RIFLE)).toBe(SAMPLES.WEAPON_FIRE_GUN);
      expect(getWeaponFireSample(WeaponId.SUBMACHINE_GUN)).toBe(SAMPLES.WEAPON_FIRE_GUN);
      expect(getWeaponFireSample(WeaponId.GAUSS_GUN)).toBe(SAMPLES.WEAPON_FIRE_GUN);
      expect(getWeaponFireSample(WeaponId.ROCKET_LAUNCHER)).toBe(SAMPLES.WEAPON_FIRE_GUN);
      expect(getWeaponFireSample(WeaponId.SEEKER_ROCKETS)).toBe(SAMPLES.WEAPON_FIRE_GUN);
      expect(getWeaponFireSample(WeaponId.MEAN_MINIGUN)).toBe(SAMPLES.WEAPON_FIRE_GUN);
      expect(getWeaponFireSample(WeaponId.EVIL_SCYTHE)).toBe(SAMPLES.WEAPON_FIRE_GUN);
      expect(getWeaponFireSample(WeaponId.SPLITTER_GUN)).toBe(SAMPLES.WEAPON_FIRE_GUN);
      expect(getWeaponFireSample(WeaponId.SHRINKIFIER)).toBe(SAMPLES.WEAPON_FIRE_GUN);
    });
  });

  describe('getWeaponReloadSample', () => {
    it('should return weapon_reload for all weapons', () => {
      // All weapons currently use the same reload sound
      expect(getWeaponReloadSample(WeaponId.PISTOL)).toBe(SAMPLES.WEAPON_RELOAD);
      expect(getWeaponReloadSample(WeaponId.SHOTGUN)).toBe(SAMPLES.WEAPON_RELOAD);
      expect(getWeaponReloadSample(WeaponId.PLASMA_RIFLE)).toBe(SAMPLES.WEAPON_RELOAD);
    });
  });

  describe('getBonusPickupSample', () => {
    it('should return pickup_weapon for WEAPON_POWER_UP', () => {
      expect(getBonusPickupSample(BonusType.WEAPON_POWER_UP)).toBe(SAMPLES.PICKUP_WEAPON);
    });

    it('should return pickup_bonus for all other bonus types', () => {
      expect(getBonusPickupSample(BonusType.MEDIKIT)).toBe(SAMPLES.PICKUP_BONUS);
      expect(getBonusPickupSample(BonusType.WEAPON)).toBe(SAMPLES.PICKUP_BONUS);
      expect(getBonusPickupSample(BonusType.SPEED)).toBe(SAMPLES.PICKUP_BONUS);
      expect(getBonusPickupSample(BonusType.SHIELD)).toBe(SAMPLES.PICKUP_BONUS);
      expect(getBonusPickupSample(BonusType.FIRE_BULLETS)).toBe(SAMPLES.PICKUP_BONUS);
      expect(getBonusPickupSample(BonusType.DOUBLE_EXPERIENCE)).toBe(SAMPLES.PICKUP_BONUS);
    });
  });

  describe('getDamageSample', () => {
    it('should return hit_player when target is player', () => {
      expect(getDamageSample({ targetIsPlayer: true, isFireDamage: false })).toBe(
        SAMPLES.HIT_PLAYER
      );
      expect(getDamageSample({ targetIsPlayer: true, isFireDamage: true })).toBe(
        SAMPLES.HIT_PLAYER
      );
    });

    it('should return hit_enemy when target is not player', () => {
      expect(getDamageSample({ targetIsPlayer: false, isFireDamage: false })).toBe(
        SAMPLES.HIT_ENEMY
      );
      expect(getDamageSample({ targetIsPlayer: false, isFireDamage: true })).toBe(
        SAMPLES.HIT_ENEMY
      );
    });
  });

  describe('getDeathSample', () => {
    it('should return death_player for player death', () => {
      expect(getDeathSample({ isPlayer: true })).toBe(SAMPLES.DEATH_PLAYER);
      expect(getDeathSample({ isPlayer: true, creatureTypeId: 0 })).toBe(SAMPLES.DEATH_PLAYER);
    });

    it('should return explosion for explosion kills', () => {
      expect(getDeathSample({ isPlayer: false, isExplosion: true })).toBe(SAMPLES.EXPLOSION);
    });

    it('should return death_enemy for regular enemy death', () => {
      expect(getDeathSample({ isPlayer: false })).toBe(SAMPLES.DEATH_ENEMY);
      expect(getDeathSample({ isPlayer: false, creatureTypeId: 0 })).toBe(SAMPLES.DEATH_ENEMY);
      expect(getDeathSample({ isPlayer: false, isExplosion: false })).toBe(SAMPLES.DEATH_ENEMY);
    });
  });
});
