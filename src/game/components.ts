/**
 * Game Components
 *
 * ECS components representing game state.
 */

import type { Component, Color } from '../types';
import {
  CreatureTypeId,
  ProjectileTypeId,
  WeaponId,
  PerkId,
  AiMode,
  CreatureFlags,
  BonusType,
} from '../types';

export { CreatureTypeId, ProjectileTypeId, WeaponId, PerkId, AiMode, CreatureFlags, BonusType };

// Transform Component
export interface Transform extends Component {
  type: 'transform';
  x: number;
  y: number;
  rotation: number;
  scaleX: number;
  scaleY: number;
}

export function createTransform(x = 0, y = 0, rotation = 0, scale = 1): Transform {
  return {
    type: 'transform',
    x,
    y,
    rotation,
    scaleX: scale,
    scaleY: scale,
  };
}

// Velocity Component
export interface Velocity extends Component {
  type: 'velocity';
  x: number;
  y: number;
  maxSpeed: number;
}

export function createVelocity(x = 0, y = 0, maxSpeed = Number.POSITIVE_INFINITY): Velocity {
  return {
    type: 'velocity',
    x,
    y,
    maxSpeed,
  };
}

// Weapon slot state for two-slot inventory
export interface WeaponSlot {
  weaponId: WeaponId;
  clipSize: number;
  ammo: number;
}

// Player Component
export interface Player extends Component {
  type: 'player';
  playerIndex: number;
  health: number;
  maxHealth: number;
  experience: number;
  level: number;
  // Two-slot weapon system
  currentWeapon: WeaponSlot;
  alternateWeapon: WeaponSlot;
  aimX: number;
  aimY: number;
  perkCounts: Map<PerkId, number>;
  shieldTimer: number;
  fireBulletsTimer: number;
  speedBonusTimer: number;
  // Input flags (set by InputSystem, read by WeaponSystem)
  fireHeld: boolean;
  fireJustPressed: boolean;
  reloadRequested: boolean;
  swapWeaponRequested: boolean;
}

export function createPlayer(playerIndex = 0): Player {
  return {
    type: 'player',
    playerIndex,
    health: 100,
    maxHealth: 100,
    experience: 0,
    level: 1,
    currentWeapon: {
      weaponId: WeaponId.PISTOL,
      clipSize: 12,
      ammo: 100,
    },
    alternateWeapon: {
      weaponId: WeaponId.PISTOL,
      clipSize: 12,
      ammo: 0,
    },
    aimX: 1,
    aimY: 0,
    perkCounts: new Map(),
    shieldTimer: 0,
    fireBulletsTimer: 0,
    speedBonusTimer: 0,
    fireHeld: false,
    fireJustPressed: false,
    reloadRequested: false,
    swapWeaponRequested: false,
  };
}

// Creature Component
export interface Creature extends Component {
  type: 'creature';
  creatureTypeId: CreatureTypeId;
  health: number;
  maxHealth: number;
  aiMode: AiMode;
  flags: CreatureFlags;
  tint: Color;
  size: number;
  hitboxSize: number;
  moveSpeed: number;
  attackCooldown: number;
  rewardValue: number;
  frame: number;
  frameTime: number;
  animRate: number;
}

export function createCreature(
  creatureTypeId: CreatureTypeId,
  options: Partial<Omit<Creature, 'type' | 'creatureTypeId'>> = {}
): Creature {
  return {
    type: 'creature',
    creatureTypeId,
    health: options.health ?? 100,
    maxHealth: options.maxHealth ?? 100,
    aiMode: options.aiMode ?? AiMode.IDLE,
    flags: options.flags ?? CreatureFlags.NONE,
    tint: options.tint ?? { r: 1, g: 1, b: 1, a: 1 },
    size: options.size ?? 1,
    animRate: options.animRate ?? 1.0,
    hitboxSize: options.hitboxSize ?? 16,
    moveSpeed: options.moveSpeed ?? 50,
    attackCooldown: options.attackCooldown ?? 0,
    rewardValue: options.rewardValue ?? 10,
    frame: options.frame ?? 0,
    frameTime: options.frameTime ?? 0,
  };
}

// Projectile Component
export interface Projectile extends Component {
  type: 'projectile';
  projectileTypeId: ProjectileTypeId;
  damage: number;
  lifetime: number;
  ownerId: number;
  pierceCount: number;
}

export function createProjectile(
  projectileTypeId: ProjectileTypeId,
  damage: number,
  lifetime: number,
  ownerId: number
): Projectile {
  return {
    type: 'projectile',
    projectileTypeId,
    damage,
    lifetime,
    ownerId,
    pierceCount: 0,
  };
}

// Sprite Component
export interface Sprite extends Component {
  type: 'sprite';
  textureName: string;
  width: number;
  height: number;
  srcX?: number;
  srcY?: number;
  srcWidth?: number;
  srcHeight?: number;
  frameCount: number;
  frameDuration: number;
  currentFrame: number;
  loop: boolean;
}

export function createSprite(
  textureName: string,
  width: number,
  height: number,
  options: Partial<Omit<Sprite, 'type' | 'textureName' | 'width' | 'height'>> = {}
): Sprite {
  return {
    type: 'sprite',
    textureName,
    width,
    height,
    frameCount: options.frameCount ?? 1,
    frameDuration: options.frameDuration ?? 0.1,
    currentFrame: options.currentFrame ?? 0,
    loop: options.loop ?? true,
  };
}

// Collider Component
export enum CollisionLayer {
  NONE = 0,
  PLAYER = 1 << 0,
  ENEMY = 1 << 1,
  PROJECTILE_PLAYER = 1 << 2,
  PROJECTILE_ENEMY = 1 << 3,
  BONUS = 1 << 4,
  OBSTACLE = 1 << 5,
}

export interface Collider extends Component {
  type: 'collider';
  radius: number;
  offsetX: number;
  offsetY: number;
  isTrigger: boolean;
  layer: CollisionLayer;
}

export function createCollider(
  radius: number,
  layer: CollisionLayer,
  options: Partial<Omit<Collider, 'type' | 'radius' | 'layer'>> = {}
): Collider {
  return {
    type: 'collider',
    radius,
    layer,
    offsetX: options.offsetX ?? 0,
    offsetY: options.offsetY ?? 0,
    isTrigger: options.isTrigger ?? false,
  };
}

// Bonus Component
export interface Bonus extends Component {
  type: 'bonus';
  bonusType: BonusType;
  value: number;
  lifetime: number;
}

export function createBonus(bonusType: BonusType, value = 1): Bonus {
  return {
    type: 'bonus',
    bonusType,
    value,
    lifetime: 30,
  };
}

// Weapon Pickup Component
export interface WeaponPickup extends Component {
  type: 'weaponPickup';
  weaponId: WeaponId;
  ammo: number;
}

export function createWeaponPickup(weaponId: WeaponId, ammo: number): WeaponPickup {
  return {
    type: 'weaponPickup',
    weaponId,
    ammo,
  };
}

// Lifetime Component
export interface Lifetime extends Component {
  type: 'lifetime';
  remaining: number;
}

export function createLifetime(seconds: number): Lifetime {
  return {
    type: 'lifetime',
    remaining: seconds,
  };
}

// Effect Component
export interface Effect extends Component {
  type: 'effect';
  effectType: string;
  duration: number;
  elapsed: number;
}

export function createEffect(effectType: string, duration: number): Effect {
  return {
    type: 'effect',
    effectType,
    duration,
    elapsed: 0,
  };
}

// Corpse Component
export interface Corpse extends Component {
  type: 'corpse';
  creatureTypeId: CreatureTypeId;
  tint: Color;
  size: number;
  rotation: number;
}

export function createCorpse(
  creatureTypeId: CreatureTypeId,
  tint: Color,
  size: number,
  rotation: number
): Corpse {
  return {
    type: 'corpse',
    creatureTypeId,
    tint,
    size,
    rotation,
  };
}

export type GameComponent =
  | Transform
  | Velocity
  | Player
  | Creature
  | Projectile
  | Sprite
  | Collider
  | Bonus
  | WeaponPickup
  | Lifetime
  | Effect
  | Corpse;

// Component type mapping for type-safe lookups
export interface ComponentTypeMap {
  transform: Transform;
  velocity: Velocity;
  player: Player;
  creature: Creature;
  projectile: Projectile;
  sprite: Sprite;
  collider: Collider;
  bonus: Bonus;
  weaponPickup: WeaponPickup;
  lifetime: Lifetime;
  effect: Effect;
  corpse: Corpse;
}
