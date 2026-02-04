/**
 * Bonus/Power-up Factory
 *
 * Creates bonus entities that players can collect.
 */

import type { EntityManager } from '../../core/ecs';
import type { Entity } from '../../core/ecs';
import { BonusType, type WeaponId } from '../../types';
import {
  CollisionLayer,
  createBonus,
  createCollider,
  createLifetime,
  createSprite,
  createTransform,
  createWeaponPickup,
} from '../components';

export interface BonusCreateOptions {
  value?: number;
  lifetime?: number;
}

// Bonus visual properties
const BONUS_VISUALS: Record<BonusType, { color: string; size: number; label: string }> = {
  [BonusType.POINTS]: { color: '#ffff00', size: 16, label: 'XP' },
  [BonusType.WEAPON]: { color: '#ffff00', size: 16, label: 'WP' },
  [BonusType.ATOMIC]: { color: '#ff4400', size: 24, label: 'AT' },
  [BonusType.DOUBLE_EXPERIENCE]: { color: '#ff00ff', size: 16, label: '2X' },
  [BonusType.FIREBLAST]: { color: '#ff4400', size: 20, label: 'FB' },
  [BonusType.SHOCK_CHAIN]: { color: '#00aaff', size: 20, label: 'SC' },
  [BonusType.REFLEX_BOOST]: { color: '#aa00ff', size: 18, label: 'RB' },
  [BonusType.SHIELD]: { color: '#0088ff', size: 20, label: 'SH' },
  [BonusType.FREEZE]: { color: '#00aaff', size: 18, label: 'FR' },
  [BonusType.SPEED]: { color: '#00ffff', size: 16, label: 'SP' },
  [BonusType.ENERGIZER]: { color: '#ffdd00', size: 18, label: 'EN' },
  [BonusType.WEAPON_POWER_UP]: { color: '#ff8800', size: 20, label: 'PW' },
  [BonusType.FIRE_BULLETS]: { color: '#ff4400', size: 18, label: 'FB' },
  [BonusType.MEDIKIT]: { color: '#ff0000', size: 16, label: 'HP' },
};

// Default bonus values
const BONUS_VALUES: Record<BonusType, number> = {
  [BonusType.POINTS]: 500, // XP amount
  [BonusType.WEAPON]: 0, // Weapon pickup - handled separately
  [BonusType.ATOMIC]: 0, // Instant explosion
  [BonusType.DOUBLE_EXPERIENCE]: 4, // seconds
  [BonusType.FIREBLAST]: 2, // seconds
  [BonusType.SHOCK_CHAIN]: 3, // seconds
  [BonusType.REFLEX_BOOST]: 5, // seconds
  [BonusType.SHIELD]: 15, // seconds
  [BonusType.FREEZE]: 8, // seconds
  [BonusType.SPEED]: 10, // seconds
  [BonusType.ENERGIZER]: 8, // seconds
  [BonusType.WEAPON_POWER_UP]: 10, // seconds
  [BonusType.FIRE_BULLETS]: 20, // seconds
  [BonusType.MEDIKIT]: 25, // HP amount
};

/**
 * Create a bonus/power-up entity at the specified position.
 */
export function createBonusEntity(
  entityManager: EntityManager,
  bonusType: BonusType,
  x: number,
  y: number,
  options: BonusCreateOptions = {}
): Entity {
  const entity = entityManager.createEntity();
  const visuals = BONUS_VISUALS[bonusType];
  const value = options.value ?? BONUS_VALUES[bonusType];
  const lifetime = options.lifetime ?? 30; // Default 30 seconds before disappearing

  // Transform - position
  const transform = createTransform(x, y, 0, 1);
  entity.addComponent(transform);

  // Bonus component
  const bonus = createBonus(bonusType, value);
  bonus.lifetime = lifetime;
  entity.addComponent(bonus);

  // Sprite - visual representation
  const sprite = createSprite(`bonus_${bonusType}`, visuals.size, visuals.size, {
    frameCount: 1,
    frameDuration: 0.1,
  });
  entity.addComponent(sprite);

  // Collider - trigger for collection
  const collider = createCollider(visuals.size / 2, CollisionLayer.BONUS, {
    isTrigger: true,
  });
  entity.addComponent(collider);

  // Lifetime - auto-destroy after duration
  const lifetimeComp = createLifetime(lifetime);
  entity.addComponent(lifetimeComp);

  return entity;
}

/**
 * Create a weapon pickup entity.
 */
export function createWeaponPickupEntity(
  entityManager: EntityManager,
  weaponId: WeaponId,
  x: number,
  y: number,
  ammo?: number
): Entity {
  const entity = entityManager.createEntity();

  // Transform - position
  const transform = createTransform(x, y, 0, 1);
  entity.addComponent(transform);

  // Weapon pickup component
  const weaponPickup = createWeaponPickup(weaponId, ammo ?? 60);
  entity.addComponent(weaponPickup);

  // Sprite - visual representation
  const sprite = createSprite(`weapon_${weaponId}`, 24, 24, {
    frameCount: 1,
    frameDuration: 0.1,
  });
  entity.addComponent(sprite);

  // Collider - trigger for collection
  const collider = createCollider(12, CollisionLayer.BONUS, {
    isTrigger: true,
  });
  entity.addComponent(collider);

  // Lifetime - auto-destroy after duration
  const lifetime = createLifetime(45); // 45 seconds
  entity.addComponent(lifetime);

  return entity;
}

/**
 * Create a random bonus at the position.
 */
export function createRandomBonus(entityManager: EntityManager, x: number, y: number): Entity {
  // Weighted random selection
  const types = [
    { type: BonusType.POINTS, weight: 20 },
    { type: BonusType.WEAPON, weight: 25 },
    { type: BonusType.WEAPON_POWER_UP, weight: 10 },
    { type: BonusType.SPEED, weight: 15 },
    { type: BonusType.SHIELD, weight: 10 },
    { type: BonusType.FIRE_BULLETS, weight: 8 },
    { type: BonusType.DOUBLE_EXPERIENCE, weight: 12 },
    { type: BonusType.FREEZE, weight: 10 },
    { type: BonusType.ENERGIZER, weight: 8 },
    { type: BonusType.REFLEX_BOOST, weight: 8 },
    { type: BonusType.MEDIKIT, weight: 20 },
  ];

  const totalWeight = types.reduce((sum, t) => sum + t.weight, 0);
  let random = Math.random() * totalWeight;

  for (const { type, weight } of types) {
    random -= weight;
    if (random <= 0) {
      return createBonusEntity(entityManager, type, x, y);
    }
  }

  return createBonusEntity(entityManager, BonusType.MEDIKIT, x, y);
}

export const BonusFactory = {
  create: createBonusEntity,
  createWeaponPickup: createWeaponPickupEntity,
  createRandom: createRandomBonus,
};
