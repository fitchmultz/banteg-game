/**
 * Game-specific type definitions
 */

import type { Color, Component, EntityId, Rectangle, Vector2 } from './index';

// Re-export from index for convenience
export type { Vector2, Rectangle, Color, EntityId, Component };

// ============================================================================
// Game State
// ============================================================================

export type GameState =
  | { type: 'MENU'; menu: MenuType }
  | { type: 'PLAYING'; mode: GameMode }
  | { type: 'PAUSED' }
  | { type: 'GAME_OVER'; stats: GameStats }
  | { type: 'VICTORY'; stats: GameStats }
  | { type: 'PERK_SELECT'; choices: PerkId[] };

export type MenuType = 'MAIN' | 'OPTIONS' | 'CREDITS';

export type GameMode =
  | { type: 'QUEST'; questId: QuestId }
  | { type: 'SURVIVAL' }
  | { type: 'COOP_SURVIVAL' }
  | { type: 'RUSH' }
  | { type: 'TUTORIAL' };

export interface GameStats {
  score: number;
  kills: number;
  timeElapsed: number;
  level: number;
}

// ============================================================================
// Enums
// ============================================================================

export enum CreatureTypeId {
  ZOMBIE = 0,
  ZOMBIE_FAST = 1,
  ZOMBIE_TANK = 2,
  SPIDER_SMALL = 3,
  SPIDER_LARGE = 4,
  ALIEN_TROOPER = 5,
  ALIEN_ELITE = 6,
  GHOST = 7,
  LIZARD = 8,
  LIZARD_KING = 9,
  LIZARD_MINION = 10,
}

export enum AiMode {
  IDLE = 0,
  CHASE = 1,
  ATTACK = 2,
  FLEE = 3,
  WANDER = 4,
  DEAD = 5,
}

export enum CreatureFlags {
  NONE = 0,
  FRIENDLY = 1 << 0,
  BOSS = 1 << 1,
  INVULNERABLE = 1 << 2,
  FROZEN = 1 << 3,
  BURNING = 1 << 4,
  POISONED = 1 << 5,
}

export enum ProjectileTypeId {
  PISTOL = 0,
  ASSAULT_RIFLE = 1,
  SUBMACHINE_GUN = 2,
  SHOTGUN = 3,
  PLASMA_RIFLE = 4,
  PLASMA_MINIGUN = 5,
  ION_RIFLE = 6,
  ION_MINIGUN = 7,
  ION_CANNON = 8,
  PLASMA_CANNON = 9,
  GAUSS_GUN = 10,
  PULSE_GUN = 11,
  BLADE_GUN = 12,
  SPLITTER_GUN = 13,
  SHRINKIFIER = 14,
  FIRE_BULLETS = 15,
  PLAGUE_SPREADER = 16,
  RAINBOW_GUN = 17,
  ROCKET = 100,
  SEEKER_ROCKET = 101,
  ROCKET_MINIGUN = 102,
}

export enum WeaponId {
  // Basic weapons (0-3)
  PISTOL = 0,
  ASSAULT_RIFLE = 1,
  SHOTGUN = 2,
  SUBMACHINE_GUN = 3,

  // Shotgun variants (4-6)
  SAWED_OFF_SHOTGUN = 4,
  JACKHAMMER = 5,
  GAUSS_SHOTGUN = 6,

  // Energy weapons (7-13)
  FLAMETHROWER = 7,
  PLASMA_RIFLE = 8,
  MULTI_PLASMA = 9,
  PLASMA_MINIGUN = 10,
  GAUSS_GUN = 11,
  PULSE_GUN = 12,
  PLASMA_CANNON = 13,

  // Rocket launchers (14-16)
  ROCKET_LAUNCHER = 14,
  SEEKER_ROCKETS = 15,
  MEAN_MINIGUN = 16,

  // Special weapons (17-22)
  PLASMA_SHOTGUN = 17,
  BLOW_TORCH = 18,
  HR_FLAMER = 19,
  MINI_ROCKET_SWARMERS = 20,
  ROCKET_MINIGUN = 21,
  ION_RIFLE = 22,

  // Advanced ion weapons (23-26)
  ION_MINIGUN = 23,
  ION_CANNON = 24,
  ION_SHOTGUN = 25,
  EVIL_SCYTHE = 26,

  // Exotic weapons (27-29)
  FLAMEBURST = 27,
  SPLITTER_GUN = 28,
  SHRINKIFIER = 29,
}

export enum PerkId {
  SHARPSHOOTER = 0,
  LONG_DISTANCE_RUNNER = 1,
  EVIL_EYES = 2,
  RADIOACTIVE = 3,
  FASTSHOT = 4,
  PYROMANIAC = 5,
  DOCTOR = 6,
  PYROKINETIC = 7,
  BONUS_MAGNET = 8,
  REFLEX_BOOSTED = 9,
  THICK_SKINNED = 10,
  REGENERATION = 11,
  GREATER_REGENERATION = 12,
  BANDAGE = 13,
  BREATHING_ROOM = 14,
  REGRESSION_BULLETS = 15,
  URANIUM_FILLED_BULLETS = 16,
  POISON_BULLETS = 17,
  // ID 18: Dodger - enhances dodge ability
  DODGER = 18,
  // ID 19: Final Revenge - revenge damage on death
  FINAL_REVENGE = 19,
  AMMUNITION_WITHIN = 20,
  ANXIOUS_LOADER = 21,
  AMMO_MANIAC = 22,
  MY_FAVOURITE_WEAPON = 23,
  RANDOM_WEAPON = 24,
  // ID 25: Veins of Poison - poison damage synergy
  VEINS_OF_POISON = 25,
  // ID 26: Toxic Avenger - advanced poison perk
  TOXIC_AVENGER = 26,
  // ID 27: Ninja - enhanced dodging and movement
  NINJA = 27,
  // ID 28: Ion Gun Master - ion weapon specialist
  ION_GUN_MASTER = 28,
  // ID 29: Angry Reloader - reload-based damage boost
  ANGRY_RELOADER = 29,
  INSTANT_WINNER = 30,
  FATAL_LOTTERY = 31,
  LIFELINE_50_50 = 32,
  JINXED = 33,
  INFERNAL_CONTRACT = 34,
  GRIM_DEAL = 35,
  DEATH_CLOCK = 36,
  HIGHLANDER = 37,
  PLAGUEBEARER = 38,
  MONSTER_VISION = 39,
  LEAN_MEAN_EXP_MACHINE = 40,
  PERK_EXPERT = 41,
  PERK_MASTER = 42,
  BONUS_ECONOMIST = 43,
  BLOODY_MESS = 44,
}

export type QuestId =
  // Tutorial / Early Game (Tier 1)
  | 'nagolipoli'
  | 'monster_blues'
  | 'the_gathering'
  | 'army_of_three'
  | 'knee_deep_in_the_dead'
  | 'the_gang_wars'
  | 'the_fortress'
  | 'cross_fire'
  | 'the_beating'
  | 'hidden_evil'
  | 'land_hostile'
  | 'minor_alien_breach'
  | 'alien_squads'
  | 'zombie_masters'
  | '8_legged_terror'
  | 'ghost_patrols'
  | 'nesting_grounds'
  | 'alien_dens'
  | 'arachnoid_farm'
  | 'gauntlet'
  | 'land_of_lizards'
  | 'lizard_kings'
  | 'lizard_raze'
  | 'lizard_zombie_pact'
  | 'syntax_terror'
  // Tier 1-2 Missing Quests
  | 'target_practice'
  | 'frontline_assault'
  | 'spider_wave_syndrome'
  | 'the_random_factor'
  | 'everred_pastures'
  | 'spider_spawns'
  | 'two_fronts'
  | 'sweep_stakes'
  | 'evil_zombies_at_large'
  | 'survival_of_the_fastest'
  // Tier 3-4 Missing Quests
  | 'the_blighting'
  | 'the_killing'
  | 'surrounded_by_reptiles'
  | 'the_lizquidation'
  | 'spiders_inc'
  | 'deja_vu'
  | 'major_alien_breach'
  | 'zombie_time'
  | 'the_collaboration'
  | 'the_massacre'
  | 'the_unblitzkrieg'
  // Tier 5 Bonus Quests
  | 'the_annihilation'
  | 'the_end_of_all'
  | 'the_spanking_of_the_dead'
  | 'spideroids';

export enum BonusType {
  POINTS = 0,
  WEAPON = 1,
  ATOMIC = 2,
  DOUBLE_EXPERIENCE = 3,
  FIREBLAST = 4,
  SHOCK_CHAIN = 5,
  REFLEX_BOOST = 6,
  SHIELD = 7,
  FREEZE = 8,
  SPEED = 9,
  ENERGIZER = 10,
  WEAPON_POWER_UP = 11,
  FIRE_BULLETS = 12,
  MEDIKIT = 13,
}

// ============================================================================
// Input
// ============================================================================

export interface KeyState {
  pressed: boolean;
  justPressed: boolean;
  justReleased: boolean;
}

export interface MouseState {
  x: number;
  y: number;
  dx: number;
  dy: number;
  wheel: number;
  buttons: {
    left: KeyState;
    middle: KeyState;
    right: KeyState;
  };
}

export interface InputState {
  keys: Map<string, KeyState>;
  mouse: MouseState;
}

// ============================================================================
// Audio
// ============================================================================

export interface AudioSample {
  name: string;
  buffer: AudioBuffer;
}

export interface AudioTrack {
  name: string;
  source: AudioBufferSourceNode | null;
  gainNode: GainNode;
  loop: boolean;
}

// ============================================================================
// Graphics
// ============================================================================

export interface Texture {
  name: string;
  image: HTMLImageElement | HTMLCanvasElement;
  width: number;
  height: number;
}

// ============================================================================
// Configuration
// ============================================================================

export interface GameConfig {
  playerName: string;
  sfxVolume: number;
  musicVolume: number;
  resolution: { width: number; height: number };
  fullscreen: boolean;
  controls: KeyBindings;
  controlsP2?: KeyBindings;
  goreIntensity: number; // 0 = off, 1 = normal, 2 = high
}

export interface KeyBindings {
  moveUp: string;
  moveDown: string;
  moveLeft: string;
  moveRight: string;
  fire: string;
  reload: string;
  swapWeapon: string;
  pause: string;
}
