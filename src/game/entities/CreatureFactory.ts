/**
 * Creature Factory
 *
 * Creates enemy entities with proper component composition.
 */

import type { EntityManager } from '../../core/ecs';
import type { Entity } from '../../core/ecs';
import { type AiMode, CreatureTypeId } from '../../types';
import {
  CollisionLayer,
  createCollider,
  createCreature,
  createSprite,
  createTransform,
  createVelocity,
} from '../components';
import { getCreatureData } from '../data';

export interface CreatureCreateOptions {
  health?: number;
  aiMode?: AiMode;
  targetId?: number;
}

// Creature texture names mapped from types
export const CREATURE_TEXTURES: Record<CreatureTypeId, string> = {
  [CreatureTypeId.ZOMBIE]: 'zombie',
  [CreatureTypeId.ZOMBIE_FAST]: 'zombie_fast',
  [CreatureTypeId.ZOMBIE_TANK]: 'zombie_tank',
  [CreatureTypeId.SPIDER_SMALL]: 'spider_small',
  [CreatureTypeId.SPIDER_LARGE]: 'spider_large',
  [CreatureTypeId.ALIEN_TROOPER]: 'alien_trooper',
  [CreatureTypeId.ALIEN_ELITE]: 'alien_elite',
  [CreatureTypeId.GHOST]: 'ghost',
  [CreatureTypeId.LIZARD]: 'lizard',
  [CreatureTypeId.LIZARD_KING]: 'lizard_king',
  [CreatureTypeId.LIZARD_MINION]: 'lizard_minion',
};

/**
 * Create a creature entity at the specified position.
 */
export function createCreatureEntity(
  entityManager: EntityManager,
  creatureTypeId: CreatureTypeId,
  x: number,
  y: number,
  options: CreatureCreateOptions = {}
): Entity {
  const entity = entityManager.createEntity();
  const data = getCreatureData(creatureTypeId);

  // Transform - position and rotation
  const transform = createTransform(x, y, 0, data.size);
  entity.addComponent(transform);

  // Velocity - movement
  const velocity = createVelocity(0, 0, data.speed);
  entity.addComponent(velocity);

  // Creature component - stats and AI state
  const creature = createCreature(creatureTypeId, {
    health: options.health ?? data.health,
    maxHealth: data.health,
    aiMode: options.aiMode ?? data.defaultAiMode,
    moveSpeed: data.speed,
    hitboxSize: data.hitboxRadius,
    size: data.size,
    rewardValue: data.rewardXP,
    tint: data.tint,
    animRate: data.animRate,
  });
  entity.addComponent(creature);

  // Sprite - visual representation
  const textureName = CREATURE_TEXTURES[creatureTypeId] ?? 'zombie';
  const sprite = createSprite(textureName, 32, 32, {
    frameCount: 4,
    frameDuration: 0.2 / data.animRate,
  });
  entity.addComponent(sprite);

  // Collider - collision detection
  const collider = createCollider(data.hitboxRadius, CollisionLayer.ENEMY, {
    isTrigger: false,
  });
  entity.addComponent(collider);

  return entity;
}

/**
 * Create a creature from a spawn template (for quest mode).
 * Spawn templates define specific enemy configurations.
 */
export function createCreatureFromTemplate(
  entityManager: EntityManager,
  templateId: number,
  x: number,
  y: number
): Entity | null {
  // Map template IDs to creature types
  // These are derived from the decompiled spawn templates
  const templateMap: Record<number, CreatureTypeId> = {
    36: CreatureTypeId.SPIDER_SMALL,
    37: CreatureTypeId.SPIDER_LARGE,
    52: CreatureTypeId.ALIEN_TROOPER,
    53: CreatureTypeId.ALIEN_ELITE,
    56: CreatureTypeId.ZOMBIE,
    65: CreatureTypeId.LIZARD, // Lizard template (overrides zombie_fast - lizards use this in quests)
    80: CreatureTypeId.GHOST,
    // Lizard templates
    14: CreatureTypeId.LIZARD, // 14 - Land of Lizards spawner
    17: CreatureTypeId.LIZARD_KING, // 17 - Lizard King boss
    46: CreatureTypeId.LIZARD, // 46 - Lizard template for raze quest
    49: CreatureTypeId.LIZARD_MINION, // 49 - Lizard minion
  };

  const creatureTypeId = templateMap[templateId];
  if (creatureTypeId === undefined) {
    console.warn(`Unknown spawn template ID: ${templateId}`);
    return null;
  }

  return createCreatureEntity(entityManager, creatureTypeId, x, y);
}

export const CreatureFactory = {
  create: createCreatureEntity,
  createFromTemplate: createCreatureFromTemplate,
};
