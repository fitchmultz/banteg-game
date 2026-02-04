/**
 * Projectile Factory
 *
 * Creates projectile entities with proper component composition.
 */

import type { EntityManager } from '../../core/ecs';
import type { EntityId } from '../../types';
import type { Entity } from '../../core/ecs';
import { ProjectileTypeId } from '../../types';
import {
  createTransform,
  createVelocity,
  createProjectile,
  createSprite,
  createCollider,
  createLifetime,
  CollisionLayer,
} from '../components';
import { getProjectileData } from '../data';

export interface ProjectileCreateOptions {
  damage?: number;
  lifetime?: number;
  pierceCount?: number;
}

// Projectile visual properties
const PROJECTILE_VISUALS: Record<ProjectileTypeId, { color: string; size: number }> = {
  [ProjectileTypeId.PISTOL]: { color: '#ffff00', size: 4 },
  [ProjectileTypeId.ASSAULT_RIFLE]: { color: '#ffff00', size: 4 },
  [ProjectileTypeId.SUBMACHINE_GUN]: { color: '#ffff00', size: 3 },
  [ProjectileTypeId.SHOTGUN]: { color: '#ffff00', size: 3 },
  [ProjectileTypeId.PLASMA_RIFLE]: { color: '#00ffff', size: 8 },
  [ProjectileTypeId.PLASMA_MINIGUN]: { color: '#00ffff', size: 8 },
  [ProjectileTypeId.ION_RIFLE]: { color: '#00ff00', size: 6 },
  [ProjectileTypeId.ION_MINIGUN]: { color: '#00ff00', size: 6 },
  [ProjectileTypeId.ION_CANNON]: { color: '#00ff00', size: 20 },
  [ProjectileTypeId.PLASMA_CANNON]: { color: '#ff00ff', size: 16 },
  [ProjectileTypeId.GAUSS_GUN]: { color: '#ffffff', size: 4 },
  [ProjectileTypeId.PULSE_GUN]: { color: '#ff8800', size: 20 },
  [ProjectileTypeId.BLADE_GUN]: { color: '#cccccc', size: 10 },
  [ProjectileTypeId.SPLITTER_GUN]: { color: '#ff00ff', size: 6 },
  [ProjectileTypeId.SHRINKIFIER]: { color: '#ff00ff', size: 12 },
  [ProjectileTypeId.FIRE_BULLETS]: { color: '#ff4400', size: 6 },
  [ProjectileTypeId.PLAGUE_SPREADER]: { color: '#44ff00', size: 8 },
  [ProjectileTypeId.RAINBOW_GUN]: { color: '#ff0088', size: 8 },
  // New projectile visuals for missing weapons (IDs 30-39)
  [ProjectileTypeId.GRIM_WEAPON]: { color: '#6600cc', size: 10 },
  [ProjectileTypeId.BUBBLEGUN]: { color: '#88ccff', size: 16 },
  [ProjectileTypeId.SPIDER_PLASMA]: { color: '#ff6600', size: 10 },
  [ProjectileTypeId.TRANSMUTATOR]: { color: '#00ff88', size: 12 },
  [ProjectileTypeId.BLASTER_R_300]: { color: '#ff0088', size: 8 },
  [ProjectileTypeId.NUKE_LAUNCHER]: { color: '#ff0000', size: 24 },
  [ProjectileTypeId.LIGHTING_RIFLE]: { color: '#ffff00', size: 6 },
  [ProjectileTypeId.ROCKET]: { color: '#ff4400', size: 12 },
  [ProjectileTypeId.SEEKER_ROCKET]: { color: '#ff6600', size: 12 },
  [ProjectileTypeId.ROCKET_MINIGUN]: { color: '#ff4400', size: 8 },
};

/**
 * Create a projectile entity.
 */
export function createProjectileEntity(
  entityManager: EntityManager,
  projectileTypeId: ProjectileTypeId,
  x: number,
  y: number,
  angle: number,
  ownerId: EntityId,
  options: ProjectileCreateOptions = {}
): Entity {
  const entity = entityManager.createEntity();
  const data = getProjectileData(projectileTypeId);
  const visuals = PROJECTILE_VISUALS[projectileTypeId] ?? { color: '#ffff00', size: 4 };

  // Transform - position and rotation
  const transform = createTransform(x, y, angle, 1);
  entity.addComponent(transform);

  // Velocity - movement in direction of angle
  const vx = Math.cos(angle) * data.speed;
  const vy = Math.sin(angle) * data.speed;
  const velocity = createVelocity(vx, vy, data.speed);
  entity.addComponent(velocity);

  // Projectile component
  const projectile = createProjectile(
    projectileTypeId,
    options.damage ?? data.damage,
    options.lifetime ?? data.lifetime,
    ownerId
  );
  projectile.pierceCount = options.pierceCount ?? data.pierceCount;
  entity.addComponent(projectile);

  // Sprite - visual representation (using colored placeholder)
  const sprite = createSprite('projectile', visuals.size, visuals.size, {
    frameCount: 1,
    frameDuration: 0.1,
  });
  entity.addComponent(sprite);

  // Collider - collision detection
  const collider = createCollider(data.radius, CollisionLayer.PROJECTILE_PLAYER, {
    isTrigger: true,
  });
  entity.addComponent(collider);

  // Lifetime - auto-destroy after duration
  const lifetime = createLifetime(options.lifetime ?? data.lifetime);
  entity.addComponent(lifetime);

  return entity;
}

/**
 * Create multiple projectiles with spread (for shotgun, etc.).
 */
export function createProjectilesWithSpread(
  entityManager: EntityManager,
  projectileTypeId: ProjectileTypeId,
  x: number,
  y: number,
  baseAngle: number,
  spreadAngle: number,
  pelletCount: number,
  ownerId: EntityId,
  options: ProjectileCreateOptions = {}
): Entity[] {
  const projectiles: Entity[] = [];

  for (let i = 0; i < pelletCount; i++) {
    // Calculate spread offset
    const spreadOffset = (Math.random() - 0.5) * spreadAngle * 2;
    const angle = baseAngle + spreadOffset;

    const projectile = createProjectileEntity(
      entityManager,
      projectileTypeId,
      x,
      y,
      angle,
      ownerId,
      options
    );
    projectiles.push(projectile);
  }

  return projectiles;
}

export const ProjectileFactory = {
  create: createProjectileEntity,
  createWithSpread: createProjectilesWithSpread,
};
