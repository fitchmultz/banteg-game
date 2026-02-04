/**
 * Player Factory
 *
 * Creates player entities with proper component composition.
 * Uses two-slot weapon system (current + alternate).
 */

import type { EntityManager } from '../../core/ecs';
import type { Entity } from '../../core/ecs';
import { WeaponId } from '../../types';
import {
  createTransform,
  createVelocity,
  createPlayer,
  createSprite,
  createCollider,
  CollisionLayer,
} from '../components';
import { getWeaponData } from '../data';

export interface PlayerCreateOptions {
  playerIndex?: number;
  health?: number;
  weaponId?: WeaponId;
  ammo?: number;
}

/**
 * Create a player entity at the specified position.
 */
export function createPlayerEntity(
  entityManager: EntityManager,
  x: number,
  y: number,
  options: PlayerCreateOptions = {}
): Entity {
  const entity = entityManager.createEntity();
  const playerIndex = options.playerIndex ?? 0;
  const weaponId = options.weaponId ?? WeaponId.PISTOL;
  const weaponData = getWeaponData(weaponId);

  // Transform - position and rotation
  const transform = createTransform(x, y, 0, 1);
  entity.addComponent(transform);

  // Velocity - movement
  const velocity = createVelocity(0, 0, 200);
  entity.addComponent(velocity);

  // Player component - stats and state
  const player = createPlayer(playerIndex);
  player.health = options.health ?? 100;
  player.maxHealth = 100;

  // Set up two-slot weapon system
  player.currentWeapon = {
    weaponId,
    clipSize: weaponData.clipSize,
    ammo: options.ammo ?? weaponData.clipSize * 3,
  };
  player.alternateWeapon = {
    weaponId: WeaponId.PISTOL,
    clipSize: 12,
    ammo: 0,
  };

  entity.addComponent(player);

  // Sprite - visual representation
  const sprite = createSprite('player', 32, 32, {
    frameCount: 1,
    frameDuration: 0.1,
  });
  entity.addComponent(sprite);

  // Collider - collision detection
  const collider = createCollider(12, CollisionLayer.PLAYER, {
    isTrigger: false,
  });
  entity.addComponent(collider);

  return entity;
}

export const PlayerFactory = {
  create: createPlayerEntity,
};
