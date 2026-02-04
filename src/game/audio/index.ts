/**
 * Game Audio Module
 *
 * Centralized audio management for gameplay events.
 *
 * Usage:
 *   import { loadGameAudio, getWeaponFireSample, SAMPLES } from './game/audio';
 *
 *   // After user gesture:
 *   await audio.initialize();
 *   const result = await loadGameAudio(audio);
 *
 *   // During gameplay:
 *   audio.playSample(getWeaponFireSample(weaponId));
 */

export {
  SAMPLES,
  TUNES,
  ALL_SFX_SAMPLES,
  ALL_TUNES,
  getWeaponFireSample,
  getWeaponReloadSample,
  getBonusPickupSample,
  getDamageSample,
  getDeathSample,
  type SampleName,
  type TuneName,
  type DamageSoundOptions,
  type DeathSoundOptions,
} from './catalog';

export {
  loadGameAudio,
  isGameAudioLoaded,
  getLastLoadResult,
  resetLoadState,
  type LoadResult,
} from './loadGameAudio';
