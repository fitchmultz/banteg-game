/**
 * Evil Eyes Handler
 *
 * Handles Evil Eyes targeting and damage bonus calculations.
 */

import type { EntityManager } from '../../../../core/ecs';
import type { EntityId } from '../../../../types';

export class EvilEyesHandler {
  private evilEyesTargetCreature: Map<EntityId, EntityId | null> = new Map();

  constructor(private entityManager: EntityManager) {}

  /**
   * Update Evil Eyes target creature
   * From decompiled: creature_find_in_radius(&player_state_table.aim_x, 12.0, 0)
   * Finds creature within 12 units of aim direction
   */
  updateEvilEyesTarget(entityId: EntityId, hasEvilEyes: boolean): void {
    if (!hasEvilEyes) {
      this.evilEyesTargetCreature.delete(entityId);
      return;
    }

    // Get player position and aim direction
    const playerEntity = this.entityManager.getEntity(entityId);
    if (!playerEntity) {
      this.evilEyesTargetCreature.delete(entityId);
      return;
    }

    const playerTransform = playerEntity.getComponent<'transform'>('transform');
    if (!playerTransform) {
      this.evilEyesTargetCreature.delete(entityId);
      return;
    }

    // Find creature in aim direction within 12 units (from decompiled code)
    const targetCreature = this.findCreatureInAimDirection(playerTransform, 12);
    this.evilEyesTargetCreature.set(entityId, targetCreature);
  }

  /**
   * Find a creature in the player's aim direction within specified radius
   * Simplified: finds nearest creature to aim direction
   */
  private findCreatureInAimDirection(
    playerTransform: { x: number; y: number; rotation?: number },
    radius: number
  ): EntityId | null {
    const creatures = this.entityManager.query(['creature', 'transform']);
    let nearestCreature: EntityId | null = null;
    let nearestDistance = radius;

    for (const creatureEntity of creatures) {
      const creature = creatureEntity.getComponent<'creature'>('creature');
      const creatureTransform = creatureEntity.getComponent<'transform'>('transform');
      if (!creature || !creatureTransform || creature.health <= 0) continue;

      // Calculate distance to creature
      const dx = creatureTransform.x - playerTransform.x;
      const dy = creatureTransform.y - playerTransform.y;
      const distance = Math.sqrt(dx * dx + dy * dy);

      if (distance < nearestDistance) {
        nearestDistance = distance;
        nearestCreature = creatureEntity.id;
      }
    }

    return nearestCreature;
  }

  /**
   * Check if Evil Eyes damage bonus should apply
   */
  hasEvilEyesBonus(entityId: EntityId): boolean {
    const target = this.evilEyesTargetCreature.get(entityId);
    return target !== null && target !== undefined;
  }

  /**
   * Get damage multiplier including Evil Eyes if applicable
   * From decompiled: 25% bonus when targeting enemy
   */
  getDamageMultiplierWithEvilEyes(baseMultiplier: number, entityId: EntityId): number {
    if (this.hasEvilEyesBonus(entityId)) {
      return baseMultiplier * 1.25; // 25% bonus from decompiled
    }

    return baseMultiplier;
  }

  cleanupEntity(entityId: EntityId): void {
    this.evilEyesTargetCreature.delete(entityId);
  }
}
