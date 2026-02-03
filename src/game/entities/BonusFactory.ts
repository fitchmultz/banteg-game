/**
 * Bonus/Power-up Factory
 *
 * Creates bonus entities that players can collect.
 */

import type { EntityManager } from '../../core/ecs';
import type { Entity } from '../../core/ecs';
import { BonusType, type WeaponId } from '../../types';
import {
  createTransform,
  createBonus,
  createSprite,
  createCollider,
  createWeaponPickup,
  createLifetime,
  CollisionLayer,
} from '../components';

export interface BonusCreateOptions {
  value?: number;
  lifetime?: number;
}

// Bonus visual properties
const BONUS_VISUALS: Record<BonusType, { color: string; size: number; label: string }> = {
  [BonusType.HEALTH]: { color: '#ff0000', size: 16, label: 'HP' },
  [BonusType.AMMO]: { color: '#ffff00', size: 16, label: 'AM' },
  [BonusType.WEAPON_POWER_UP]: { color: '#ff8800', size: 20, label: 'WP' },
  [BonusType.SPEED_BOOST]: { color: '#00ffff', size: 16, label: 'SP' },
  [BonusType.SHIELD]: { color: '#0088ff', size: 20, label: 'SH' },
  [BonusType.FIRE_BULLETS]: { color: '#ff4400', size: 18, label: 'FB' },
  [BonusType.EXP_MULTIPLIER]: { color: '#ff00ff', size: 16, label: 'XP' },
};

// Default bonus values
const BONUS_VALUES: Record<BonusType, number> = {
  [BonusType.HEALTH]: 25,
  [BonusType.AMMO]: 30,
  [BonusType.WEAPON_POWER_UP]: 10, // seconds
  [BonusType.SPEED_BOOST]: 10, // seconds
  [BonusType.SHIELD]: 15, // seconds
  [BonusType.FIRE_BULLETS]: 20, // seconds
  [BonusType.EXP_MULTIPLIER]: 2, // multiplier
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
    { type: BonusType.HEALTH, weight: 20 },
    { type: BonusType.AMMO, weight: 25 },
    { type: BonusType.WEAPON_POWER_UP, weight: 10 },
    { type: BonusType.SPEED_BOOST, weight: 15 },
    { type: BonusType.SHIELD, weight: 10 },
    { type: BonusType.FIRE_BULLETS, weight: 8 },
    { type: BonusType.EXP_MULTIPLIER, weight: 12 },
  ];

  const totalWeight = types.reduce((sum, t) => sum + t.weight, 0);
  let random = Math.random() * totalWeight;

  for (const { type, weight } of types) {
    random -= weight;
    if (random <= 0) {
      return createBonusEntity(entityManager, type, x, y);
    }
  }

  return createBonusEntity(entityManager, BonusType.HEALTH, x, y);
}

export const BonusFactory = {
  create: createBonusEntity,
  createWeaponPickup: createWeaponPickupEntity,
  createRandom: createRandomBonus,
};
