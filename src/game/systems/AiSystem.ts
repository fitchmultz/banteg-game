/**
 * AI System
 *
 * Controls creature behavior: chasing, wandering, fleeing, attacking.
 * Updates every 70 ticks (creature_update_tick % 0x46 from decompiled source).
 * Priority: 40
 */

import type { EntityManager } from '../../core/ecs/EntityManager';
import { System, type UpdateContext } from '../../core/ecs/System';
import { AiMode, CreatureFlags } from '../../types';

// AI update interval (seconds) - approx 70 ticks at 60 FPS
const AI_UPDATE_INTERVAL = 70 / 60;

// Distance thresholds
const CHASE_DISTANCE = 600;
const ATTACK_DISTANCE = 30;
const FLEE_HEALTH_THRESHOLD = 0.3;

interface AiState {
  lastUpdateTime: number;
  targetId: number | null;
  wanderAngle: number;
  wanderChangeTimer: number;
}

const aiStates = new Map<number, AiState>();

export class AiSystem extends System {
  readonly name = 'AiSystem';
  readonly priority = 40;

  private entityManager: EntityManager;
  private readonly freezeSpeedMultiplier = 0.4;

  constructor(entityManager: EntityManager) {
    super();
    this.entityManager = entityManager;
  }

  update(_entityManager: EntityManager, context: UpdateContext): void {
    const gameTime = context.gameTime;
    const dt = context.dt;

    // Query all creatures
    const creatures = this.entityManager.query(['creature', 'transform', 'velocity']);
    const players = this.entityManager.query(['player', 'transform']);

    if (players.length === 0) return;

    // Check if freeze is active on any player
    const freezeActive = players.some((p) => {
      const pl = p.getComponent<'player'>('player');
      return (pl?.freezeTimer ?? 0) > 0;
    });
    const freezeMultiplier = freezeActive ? this.freezeSpeedMultiplier : 1.0;

    for (const creatureEntity of creatures) {
      const creature = creatureEntity.getComponent<'creature'>('creature');
      const transform = creatureEntity.getComponent<'transform'>('transform');
      const velocity = creatureEntity.getComponent<'velocity'>('velocity');
      if (!creature || !transform || !velocity) continue;

      // Update animation frame
      this.updateAnimation(creature, dt);

      // Get or create AI state
      let state = aiStates.get(creatureEntity.id);
      if (!state) {
        state = {
          lastUpdateTime: 0,
          targetId: null,
          wanderAngle: Math.random() * Math.PI * 2,
          wanderChangeTimer: 0,
        };
        aiStates.set(creatureEntity.id, state);
      }

      // Update AI mode periodically
      const shouldUpdate = gameTime - state.lastUpdateTime >= AI_UPDATE_INTERVAL;

      if (shouldUpdate) {
        state.lastUpdateTime = gameTime;
        this.updateAiMode(creature, transform, players, state);
      }

      // Execute behavior based on current mode
      this.executeBehavior(creature, transform, velocity, players, state, context.dt);

      // Apply freeze effect to creature velocity
      if (freezeMultiplier !== 1.0) {
        creature.flags |= CreatureFlags.FROZEN;
        velocity.x *= freezeMultiplier;
        velocity.y *= freezeMultiplier;
      } else {
        creature.flags &= ~CreatureFlags.FROZEN;
      }
    }
  }

  private updateAiMode(
    creature: { aiMode: AiMode; health: number; maxHealth: number },
    transform: { x: number; y: number },
    players: Array<{ getComponent: (type: 'transform') => { x: number; y: number } | undefined }>,
    _state: AiState
  ): void {
    const healthPercent = creature.health / creature.maxHealth;

    // Find nearest player
    let nearestPlayer: { x: number; y: number } | null = null;
    let nearestDistance = Number.POSITIVE_INFINITY;

    for (const playerEntity of players) {
      const playerTransform = playerEntity.getComponent('transform');
      if (!playerTransform) continue;

      const dx = playerTransform.x - transform.x;
      const dy = playerTransform.y - transform.y;
      const distance = Math.sqrt(dx * dx + dy * dy);

      if (distance < nearestDistance) {
        nearestDistance = distance;
        nearestPlayer = playerTransform;
      }
    }

    if (!nearestPlayer) {
      creature.aiMode = AiMode.IDLE;
      return;
    }

    // Determine AI mode based on situation
    if (healthPercent <= FLEE_HEALTH_THRESHOLD) {
      // Low health - flee from player
      creature.aiMode = AiMode.FLEE;
    } else if (nearestDistance <= ATTACK_DISTANCE) {
      // Close enough to attack
      creature.aiMode = AiMode.ATTACK;
    } else if (nearestDistance <= CHASE_DISTANCE) {
      // Within chase range
      creature.aiMode = AiMode.CHASE;
    } else if (creature.aiMode === AiMode.WANDER || creature.aiMode === AiMode.IDLE) {
      // Continue wandering
      creature.aiMode = AiMode.WANDER;
    } else {
      // Lost player, go back to wandering
      creature.aiMode = AiMode.WANDER;
    }
  }

  private executeBehavior(
    creature: { aiMode: AiMode; moveSpeed: number; creatureTypeId: number },
    transform: { x: number; y: number; rotation: number },
    velocity: { x: number; y: number },
    players: Array<{ getComponent: (type: 'transform') => { x: number; y: number } | undefined }>,
    state: AiState,
    dt: number
  ): void {
    // Creature data available via getCreatureData if needed
    // const data = getCreatureData(creature.creatureTypeId);

    switch (creature.aiMode) {
      case AiMode.IDLE:
        velocity.x = 0;
        velocity.y = 0;
        break;

      case AiMode.CHASE: {
        // Find nearest player
        let nearestPlayer: { x: number; y: number } | null = null;
        let nearestDistance = Number.POSITIVE_INFINITY;

        for (const playerEntity of players) {
          const playerTransform = playerEntity.getComponent('transform');
          if (!playerTransform) continue;

          const dx = playerTransform.x - transform.x;
          const dy = playerTransform.y - transform.y;
          const distance = Math.sqrt(dx * dx + dy * dy);

          if (distance < nearestDistance) {
            nearestDistance = distance;
            nearestPlayer = playerTransform;
          }
        }

        if (nearestPlayer) {
          const dx = nearestPlayer.x - transform.x;
          const dy = nearestPlayer.y - transform.y;
          const distance = Math.sqrt(dx * dx + dy * dy);

          if (distance > 0) {
            velocity.x = (dx / distance) * creature.moveSpeed;
            velocity.y = (dy / distance) * creature.moveSpeed;
            transform.rotation = Math.atan2(dy, dx);
          }
        }
        break;
      }

      case AiMode.ATTACK:
        // Stop moving when in attack range
        velocity.x = 0;
        velocity.y = 0;
        break;

      case AiMode.FLEE: {
        // Find nearest player to flee from
        let nearestPlayer: { x: number; y: number } | null = null;
        let nearestDistance = Number.POSITIVE_INFINITY;

        for (const playerEntity of players) {
          const playerTransform = playerEntity.getComponent('transform');
          if (!playerTransform) continue;

          const dx = playerTransform.x - transform.x;
          const dy = playerTransform.y - transform.y;
          const distance = Math.sqrt(dx * dx + dy * dy);

          if (distance < nearestDistance) {
            nearestDistance = distance;
            nearestPlayer = playerTransform;
          }
        }

        if (nearestPlayer) {
          const dx = transform.x - nearestPlayer.x;
          const dy = transform.y - nearestPlayer.y;
          const distance = Math.sqrt(dx * dx + dy * dy);

          if (distance > 0) {
            velocity.x = (dx / distance) * creature.moveSpeed * 1.2;
            velocity.y = (dy / distance) * creature.moveSpeed * 1.2;
            transform.rotation = Math.atan2(-dy, -dx);
          }
        }
        break;
      }

      case AiMode.WANDER:
        // Random wandering
        state.wanderChangeTimer -= dt;
        if (state.wanderChangeTimer <= 0) {
          state.wanderAngle += (Math.random() - 0.5) * Math.PI;
          state.wanderChangeTimer = 2 + Math.random() * 3;
        }

        velocity.x = Math.cos(state.wanderAngle) * creature.moveSpeed * 0.5;
        velocity.y = Math.sin(state.wanderAngle) * creature.moveSpeed * 0.5;
        transform.rotation = state.wanderAngle;
        break;

      case AiMode.DEAD:
        velocity.x = 0;
        velocity.y = 0;
        break;
    }
  }

  destroy(): void {
    aiStates.clear();
  }

  /**
   * Update creature animation frame based on movement and time.
   */
  private updateAnimation(
    creature: { frameTime: number; frame: number; animRate?: number; moveSpeed: number },
    dt: number
  ): void {
    // Only animate if creature is moving
    const isMoving = creature.moveSpeed > 0;
    if (!isMoving) return;

    // Advance frame time
    creature.frameTime += dt;

    // Calculate frame duration based on animation rate (default to 1.0)
    const animRate = creature.animRate ?? 1.0;
    const frameDuration = 0.2 / animRate;

    // Advance to next frame if duration elapsed
    if (creature.frameTime >= frameDuration) {
      creature.frameTime = 0;
      creature.frame = (creature.frame + 1) % 4; // 4-frame animation cycle
    }
  }
}
