/**
 * Game Systems Module
 *
 * Re-exports all game systems and system priorities.
 */

export { InputSystem } from './InputSystem';
export { MovementSystem } from './MovementSystem';
export { WeaponSystem } from './WeaponSystem';
export { AiSystem } from './AiSystem';
export { ProjectileSystem } from './ProjectileSystem';
export { CollisionSystem } from './CollisionSystem';
export { HealthSystem } from './HealthSystem';
export { SpawnSystem } from './SpawnSystem';
export { BonusSystem } from './BonusSystem';
export { EffectSystem } from './EffectSystem';
export { LifetimeSystem } from './LifetimeSystem';
export { RenderSystem } from './RenderSystem';
export { PerkSystem } from './PerkSystem';
export { QuestSpawnSystem } from './QuestSpawnSystem';
export { RushSpawnSystem } from './RushSpawnSystem';
export { GameModeSystem } from './GameModeSystem';
export { WeaponPickupSystem } from './WeaponPickupSystem';
export { GameAudioSystem } from './GameAudioSystem';

// System priorities (lower = earlier)
export const SYSTEM_PRIORITIES = {
  InputSystem: 10,
  GameModeSystem: 15,
  MovementSystem: 20,
  WeaponSystem: 30,
  AiSystem: 40,
  ProjectileSystem: 50,
  CollisionSystem: 60,
  GameAudioSystem: 65,
  HealthSystem: 70,
  SpawnSystem: 80,
  QuestSpawnSystem: 85,
  RushSpawnSystem: 86,
  WeaponPickupSystem: 87,
  BonusSystem: 90,
  EffectSystem: 100,
  LifetimeSystem: 150,
  PerkSystem: 160,
  RenderSystem: 200,
} as const;
