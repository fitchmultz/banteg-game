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
  // New projectile types for missing weapons (IDs 30-39)
  GRIM_WEAPON = 18,
  BUBBLEGUN = 19,
  SPIDER_PLASMA = 20,
  TRANSMUTATOR = 21,
  BLASTER_R_300 = 22,
  NUKE_LAUNCHER = 23,
  LIGHTING_RIFLE = 24,
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

  // Missing exotic weapons (30-39)
  BLADE_GUN_WEAPON = 30,
  PLAGUE_SPREADER_GUN = 31,
  RAINBOW_GUN_WEAPON = 32,
  GRIM_WEAPON = 33,
  BUBBLEGUN = 34,
  SPIDER_PLASMA = 35,
  TRANSMUTATOR = 36,
  BLASTER_R_300 = 37,
  NUKE_LAUNCHER = 38,
  LIGHTING_RIFLE = 39,
}

export enum PerkId {
  // Perks 0-9
  ANTIPERK = 0,
  BLOODY_MESS_QUICK_LEARNER = 1, // Shared slot - Bloody Mess (FX on) / Quick Learner (FX off)
  SHARPSHOOTER = 2,
  FASTLOADER = 3,
  LEAN_MEAN_EXP_MACHINE = 4,
  LONG_DISTANCE_RUNNER = 5,
  PYROKINETIC = 6,
  INSTANT_WINNER = 7,
  GRIM_DEAL = 8,
  ALTERNATE_WEAPON = 9,

  // Perks 10-19
  PLAGUEBEARER = 10,
  EVIL_EYES = 11,
  AMMO_MANIAC = 12,
  RADIOACTIVE = 13,
  FASTSHOT = 14,
  FATAL_LOTTERY = 15,
  RANDOM_WEAPON = 16,
  MR_MELEE = 17,
  ANXIOUS_LOADER = 18,
  FINAL_REVENGE = 19,

  // Perks 20-29
  TELEKINETIC = 20, // Bonus Magnet
  PERK_EXPERT = 21,
  UNSTOPPABLE = 22, // Reflex Boosted
  REGRESSION_BULLETS = 23,
  INFERNAL_CONTRACT = 24,
  POISON_BULLETS = 25,
  DODGER = 26,
  BONUS_MAGNET = 27,
  URANIUM_FILLED_BULLETS = 28,
  DOCTOR = 29,

  // Perks 30-39
  MONSTER_VISION = 30,
  HOT_TEMPERED = 31, // Pyromaniac
  BONUS_ECONOMIST = 32,
  THICK_SKINNED = 33,
  BARREL_GREASER = 34,
  AMMUNITION_WITHIN = 35,
  VEINS_OF_POISON = 36,
  TOXIC_AVENGER = 37,
  REGENERATION = 38,
  PYROMANIAC = 39,

  // Perks 40-49
  NINJA = 40,
  HIGHLANDER = 41,
  JINXED = 42,
  PERK_MASTER = 43,
  REFLEX_BOOSTED = 44,
  GREATER_REGENERATION = 45,
  BREATHING_ROOM = 46,
  DEATH_CLOCK = 47,
  MY_FAVOURITE_WEAPON = 48,
  BANDAGE = 49,

  // Perks 50-57
  ANGRY_RELOADER = 50,
  ION_GUN_MASTER = 51,
  STATIONARY_RELOADER = 52,
  MAN_BOMB = 53,
  FIRE_CAUGH = 54,
  LIVING_FORTRESS = 55,
  TOUGH_RELOADER = 56,
  LIFELINE_50_50 = 57,
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
