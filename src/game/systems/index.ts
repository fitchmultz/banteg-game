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

// System priorities (lower = earlier)
export const SYSTEM_PRIORITIES = {
  InputSystem: 10,
  MovementSystem: 20,
  WeaponSystem: 30,
  AiSystem: 40,
  ProjectileSystem: 50,
  CollisionSystem: 60,
  HealthSystem: 70,
  SpawnSystem: 80,
  BonusSystem: 90,
  EffectSystem: 100,
  LifetimeSystem: 150,
  RenderSystem: 200,
} as const;
