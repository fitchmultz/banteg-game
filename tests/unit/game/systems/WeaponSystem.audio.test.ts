/**
 * WeaponSystem audio unit tests
 */

import { describe, it, expect, vi, beforeEach } from 'vitest';
import { WeaponSystem } from '../../../../src/game/systems/WeaponSystem';
import { EntityManager } from '../../../../src/core/ecs';
import type { AudioManager } from '../../../../src/engine';
import { SAMPLES, getWeaponFireSample } from '../../../../src/game/audio/catalog';
import { WeaponId } from '../../../../src/types';

// Mock AudioManager
function createMockAudioManager(): AudioManager {
  return {
    playSample: vi.fn(),
    playSamplePanned: vi.fn(),
  } as unknown as AudioManager;
}

describe('WeaponSystem audio', () => {
  let system: WeaponSystem;
  let entityManager: EntityManager;
  let audio: AudioManager;

  beforeEach(() => {
    entityManager = new EntityManager();
    audio = createMockAudioManager();
    system = new WeaponSystem(entityManager, audio);
  });

  function createPlayerWithWeapon(weaponId: WeaponId, ammoInClip: number, reserveAmmo: number) {
    const player = entityManager.createEntity();
    player.addComponent({
      type: 'player',
      health: 100,
      maxHealth: 100,
      experience: 0,
      level: 1,
      currentWeapon: {
        weaponId,
        clipSize: ammoInClip,
        ammo: reserveAmmo,
      },
      alternateWeapon: { weaponId: 0, clipSize: 10, ammo: 50 },
      perkCounts: new Map(),
      fireHeld: false,
      fireJustPressed: true,
      reloadRequested: false,
      swapWeaponRequested: false,
      shieldTimer: 0,
    });
    player.addComponent({
      type: 'transform',
      x: 0,
      y: 0,
      rotation: 0,
    });
    return player;
  }

  describe('fire SFX', () => {
    it('should play fire sound when weapon fires', () => {
      createPlayerWithWeapon(WeaponId.PISTOL, 6, 50);

      system.update(entityManager, {
        dt: 0.016,
        unscaledDt: 0.016,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      expect(audio.playSample).toHaveBeenCalled();
      const sampleName = vi.mocked(audio.playSample).mock.calls[0]?.[0] as string;
      expect(sampleName).toBe(getWeaponFireSample(WeaponId.PISTOL));
    });

    it('should play shotgun sound for shotgun weapons', () => {
      createPlayerWithWeapon(WeaponId.SHOTGUN, 8, 50);

      system.update(entityManager, {
        dt: 0.016,
        unscaledDt: 0.016,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      expect(audio.playSample).toHaveBeenCalled();
      expect(vi.mocked(audio.playSample).mock.calls[0]?.[0]).toBe(SAMPLES.WEAPON_FIRE_SHOTGUN);
    });

    it('should play energy sound for energy weapons', () => {
      const player = createPlayerWithWeapon(WeaponId.PLASMA_RIFLE, 30, 100);
      // Plasma rifle is automatic, so we need fireHeld not just fireJustPressed
      const playerComp = player.getComponent<'player'>('player');
      if (playerComp) {
        playerComp.fireHeld = true;
        playerComp.fireJustPressed = false;
      }

      system.update(entityManager, {
        dt: 0.016,
        unscaledDt: 0.016,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      expect(audio.playSample).toHaveBeenCalled();
      expect(vi.mocked(audio.playSample).mock.calls[0]?.[0]).toBe(SAMPLES.WEAPON_FIRE_ENERGY);
    });

    it('should not play fire sound when out of ammo', () => {
      createPlayerWithWeapon(WeaponId.PISTOL, 0, 0);

      system.update(entityManager, {
        dt: 0.016,
        unscaledDt: 0.016,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      expect(audio.playSample).not.toHaveBeenCalled();
    });

    it('should play one sound per shot, not per pellet for shotguns', () => {
      createPlayerWithWeapon(WeaponId.SHOTGUN, 8, 50);

      system.update(entityManager, {
        dt: 0.016,
        unscaledDt: 0.016,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      // Should play exactly one sound even though shotgun fires multiple pellets
      const fireSounds = vi
        .mocked(audio.playSample)
        .mock.calls.filter((call) => call[0] === SAMPLES.WEAPON_FIRE_SHOTGUN);
      expect(fireSounds.length).toBe(1);
    });
  });

  describe('reload SFX', () => {
    it('should play reload sound when reload is requested', () => {
      const player = createPlayerWithWeapon(WeaponId.PISTOL, 5, 50);
      const playerComp = player.getComponent<'player'>('player');
      if (playerComp) {
        playerComp.fireJustPressed = false;
        playerComp.reloadRequested = true;
      }

      system.update(entityManager, {
        dt: 0.016,
        unscaledDt: 0.016,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      const reloadCalls = vi
        .mocked(audio.playSample)
        .mock.calls.filter((call) => call[0] === SAMPLES.WEAPON_RELOAD);
      expect(reloadCalls.length).toBe(1);
    });

    it('should not play reload sound when clip is full', () => {
      const player = createPlayerWithWeapon(WeaponId.PISTOL, 12, 50); // Full clip for pistol
      const playerComp = player.getComponent<'player'>('player');
      if (playerComp) {
        playerComp.fireJustPressed = false;
        playerComp.reloadRequested = true;
      }

      system.update(entityManager, {
        dt: 0.016,
        unscaledDt: 0.016,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      const reloadCalls = vi
        .mocked(audio.playSample)
        .mock.calls.filter((call) => call[0] === SAMPLES.WEAPON_RELOAD);
      expect(reloadCalls.length).toBe(0);
    });

    it('should not play reload sound when no reserve ammo', () => {
      const player = createPlayerWithWeapon(WeaponId.PISTOL, 5, 0);
      const playerComp = player.getComponent<'player'>('player');
      if (playerComp) {
        playerComp.fireJustPressed = false;
        playerComp.reloadRequested = true;
      }

      system.update(entityManager, {
        dt: 0.016,
        unscaledDt: 0.016,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      const reloadCalls = vi
        .mocked(audio.playSample)
        .mock.calls.filter((call) => call[0] === SAMPLES.WEAPON_RELOAD);
      expect(reloadCalls.length).toBe(0);
    });
  });

  describe('weapon swap', () => {
    it('should not play fire sound on the frame of weapon swap', () => {
      const player = createPlayerWithWeapon(WeaponId.PISTOL, 10, 50);
      const playerComp = player.getComponent<'player'>('player');
      if (playerComp) {
        playerComp.swapWeaponRequested = true;
      }

      system.update(entityManager, {
        dt: 0.016,
        unscaledDt: 0.016,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      // Should not play any sound when swapping
      expect(audio.playSample).not.toHaveBeenCalled();
    });
  });

  describe('destroy', () => {
    it('should not throw on destroy', () => {
      expect(() => system.destroy()).not.toThrow();
    });
  });
});
