/**
 * Entity Component System module
 * 
 * Provides the core ECS architecture for the game.
 * This replaces the struct-of-arrays pattern from the original C source
 * with a more flexible component-based approach.
 */

export { Entity } from './Entity';
export { EntityManager } from './EntityManager';
export { System, SystemManager, type UpdateContext } from './System';
