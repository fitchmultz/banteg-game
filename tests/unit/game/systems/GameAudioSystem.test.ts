/**
 * GameAudioSystem unit tests
 */

import { describe, it, expect, vi, beforeEach } from 'vitest';
import { GameAudioSystem } from '../../../../src/game/systems/GameAudioSystem';
import {
  damageEvents,
  collectEvents,
  weaponCollectEvents,
} from '../../../../src/game/systems/CollisionSystem';
import { EntityManager } from '../../../../src/core/ecs';
import type { AudioManager } from '../../../../src/engine';
import { SAMPLES } from '../../../../src/game/audio/catalog';
import { BonusType } from '../../../../src/types';

// Mock AudioManager
function createMockAudioManager(): AudioManager {
  return {
    playSample: vi.fn(),
    playSamplePanned: vi.fn(),
  } as unknown as AudioManager;
}

describe('GameAudioSystem', () => {
  let system: GameAudioSystem;
  let entityManager: EntityManager;
  let audio: AudioManager;

  beforeEach(() => {
    // Clear event queues
    damageEvents.length = 0;
    collectEvents.length = 0;
    weaponCollectEvents.length = 0;

    entityManager = new EntityManager();
    audio = createMockAudioManager();
    system = new GameAudioSystem(entityManager, audio);
  });

  describe('damage events', () => {
    it('should play hit_player sound when player is damaged', () => {
      // Create player entity
      const player = entityManager.createEntity();
      player.addComponent({
        type: 'player',
        health: 100,
        maxHealth: 100,
        experience: 0,
        level: 1,
        currentWeapon: { weaponId: 0, clipSize: 10, ammo: 100 },
        alternateWeapon: { weaponId: 1, clipSize: 30, ammo: 90 },
        perkCounts: new Map(),
        fireHeld: false,
        fireJustPressed: false,
        reloadRequested: false,
        swapWeaponRequested: false,
        shieldTimer: 0,
      });
      player.addComponent({
        type: 'transform',
        x: 100,
        y: 100,
        rotation: 0,
      });

      // Queue damage event targeting player
      damageEvents.push({
        targetId: player.id,
        sourceId: 999,
        damage: 10,
        isFireDamage: false,
      });

      system.update();

      expect(audio.playSample).toHaveBeenCalled();
      expect(vi.mocked(audio.playSample).mock.calls[0]?.[0]).toBe(SAMPLES.HIT_PLAYER);
    });

    it('should play hit_enemy sound when enemy is damaged', () => {
      // Create enemy entity
      const enemy = entityManager.createEntity();
      enemy.addComponent({
        type: 'creature',
        creatureTypeId: 0,
        health: 50,
        maxHealth: 50,
        speed: 100,
        aiMode: 1,
        hitboxSize: 20,
        rewardValue: 10,
      });
      enemy.addComponent({
        type: 'transform',
        x: 200,
        y: 200,
        rotation: 0,
      });

      // Queue damage event targeting enemy
      damageEvents.push({
        targetId: enemy.id,
        sourceId: 1,
        damage: 20,
        isFireDamage: false,
      });

      system.update();

      expect(audio.playSample).toHaveBeenCalled();
      expect(vi.mocked(audio.playSample).mock.calls[0]?.[0]).toBe(SAMPLES.HIT_ENEMY);
    });
  });

  describe('collect events', () => {
    it('should play pickup_bonus sound for regular bonuses', () => {
      collectEvents.push({
        playerId: 1,
        bonusId: 100,
        bonusType: BonusType.MEDIKIT,
        value: 25,
      });

      system.update();

      expect(audio.playSample).toHaveBeenCalledWith(SAMPLES.PICKUP_BONUS);
    });

    it('should play pickup_weapon sound for weapon power up', () => {
      collectEvents.push({
        playerId: 1,
        bonusId: 100,
        bonusType: BonusType.WEAPON_POWER_UP,
        value: 0,
      });

      system.update();

      expect(audio.playSample).toHaveBeenCalledWith(SAMPLES.PICKUP_WEAPON);
    });
  });

  describe('weapon collect events', () => {
    it('should play pickup_weapon sound for weapon pickups', () => {
      weaponCollectEvents.push({
        playerId: 1,
        pickupId: 200,
        weaponId: 5,
        ammo: 60,
      });

      system.update();

      expect(audio.playSample).toHaveBeenCalledWith(SAMPLES.PICKUP_WEAPON);
    });
  });

  describe('destroy', () => {
    it('should clear processed event tracking on destroy', () => {
      collectEvents.push({
        playerId: 1,
        bonusId: 100,
        bonusType: BonusType.MEDIKIT,
        value: 25,
      });

      system.update();
      expect(() => system.destroy()).not.toThrow();
    });
  });
});
