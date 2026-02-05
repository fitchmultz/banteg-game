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
import { BonusType, ProjectileTypeId } from '../../../../src/types';
import { CollisionSystem } from '../../../../src/game/systems/CollisionSystem';
import {
  setShockChainState,
  clearShockChainState,
} from '../../../../src/game/systems/ShockChainState';
import { createProjectileEntity } from '../../../../src/game/entities/ProjectileFactory';

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

  describe('shock chain audio', () => {
    beforeEach(() => {
      clearShockChainState();
    });

    it('should play shock_hit sound when shock chain continues', () => {
      // Create mock audio manager
      const mockAudio = {
        playSample: vi.fn(),
        playSamplePanned: vi.fn(),
      } as unknown as AudioManager;

      // Create collision system with mock audio
      const collisionSystem = new CollisionSystem(entityManager, mockAudio);

      // Create two enemies within chain range
      const enemy1 = entityManager.createEntity();
      enemy1.addComponent({
        type: 'creature',
        creatureTypeId: 0,
        health: 50,
        maxHealth: 50,
        speed: 100,
        aiMode: 1,
        hitboxSize: 20,
        rewardValue: 10,
      });
      enemy1.addComponent({
        type: 'transform',
        x: 100,
        y: 100,
        rotation: 0,
      });
      enemy1.addComponent({
        type: 'collider',
        radius: 16,
        layer: 2, // ENEMY
        enabled: true,
      });

      const enemy2 = entityManager.createEntity();
      enemy2.addComponent({
        type: 'creature',
        creatureTypeId: 0,
        health: 50,
        maxHealth: 50,
        speed: 100,
        aiMode: 1,
        hitboxSize: 20,
        rewardValue: 10,
      });
      enemy2.addComponent({
        type: 'transform',
        x: 150, // Within 100 units of enemy1
        y: 100,
        rotation: 0,
      });
      enemy2.addComponent({
        type: 'collider',
        radius: 16,
        layer: 2, // ENEMY
        enabled: true,
      });

      // Create ion rifle projectile with shock chain active
      const projectile = createProjectileEntity(
        entityManager,
        ProjectileTypeId.ION_RIFLE,
        100,
        100,
        0,
        1,
        { damage: 30 }
      );
      const projComponent = projectile.getComponent('projectile');
      if (projComponent) {
        projComponent.isShockChainActive = true;
        projComponent.shockChainLinksLeft = 32;
      }
      setShockChainState(projectile.id, 32);

      // Create a player entity (projectile owner)
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
      player.addComponent({
        type: 'collider',
        radius: 16,
        layer: 1, // PLAYER
        enabled: true,
      });

      // Run collision detection (hits enemy1, should chain to enemy2 and play shock_hit)
      collisionSystem.update(entityManager, {
        dt: 0.016,
        unscaledDt: 0.016,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      // Verify shock_hit was played
      expect(mockAudio.playSample).toHaveBeenCalledWith(SAMPLES.SHOCK_HIT);
    });

    it('should not play shock_hit sound when shock chain has no valid target', () => {
      // Create mock audio manager
      const mockAudio = {
        playSample: vi.fn(),
        playSamplePanned: vi.fn(),
      } as unknown as AudioManager;

      // Create collision system with mock audio
      const collisionSystem = new CollisionSystem(entityManager, mockAudio);

      // Create only one enemy (no chain target)
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
        x: 100,
        y: 100,
        rotation: 0,
      });
      enemy.addComponent({
        type: 'collider',
        radius: 16,
        layer: 2, // ENEMY
        enabled: true,
      });

      // Create ion rifle projectile with shock chain active
      const projectile = createProjectileEntity(
        entityManager,
        ProjectileTypeId.ION_RIFLE,
        100,
        100,
        0,
        1,
        { damage: 30 }
      );
      const projComponent = projectile.getComponent('projectile');
      if (projComponent) {
        projComponent.isShockChainActive = true;
        projComponent.shockChainLinksLeft = 32;
      }
      setShockChainState(projectile.id, 32);

      // Create a player entity (projectile owner)
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
      player.addComponent({
        type: 'collider',
        radius: 16,
        layer: 1, // PLAYER
        enabled: true,
      });

      // Clear any previous calls
      vi.mocked(mockAudio.playSample).mockClear();

      // Run collision detection (hits enemy, but no target to chain to)
      collisionSystem.update(entityManager, {
        dt: 0.016,
        unscaledDt: 0.016,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      // Verify shock_hit was NOT played (no valid target for chain)
      expect(mockAudio.playSample).not.toHaveBeenCalledWith(SAMPLES.SHOCK_HIT);
    });
  });
});
