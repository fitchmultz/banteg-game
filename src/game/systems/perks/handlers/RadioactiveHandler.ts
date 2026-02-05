/**
 * Radioactive Handler
 *
 * Handles radioactive aura damage from the RADIOACTIVE perk.
 */

import type { EntityManager } from '../../../../core/ecs';
import type { EntityId } from '../../../../types';

export class RadioactiveHandler {
  private readonly RADIOACTIVE_AURA_RADIUS = 150;

  constructor(private entityManager: EntityManager) {}

  /**
   * Apply radioactive aura damage to nearby creatures
   * From decompiled: radiation damage aura around player
   */
  applyRadioactiveAura(playerEntityId: EntityId, dt: number): void {
    const player = this.entityManager.getComponent<'player'>(playerEntityId, 'player');
    if (!player) return;

    // Get player position from transform component
    const playerEntity = this.entityManager.getEntity(playerEntityId);
    if (!playerEntity) return;

    const playerTransform = playerEntity.getComponent<'transform'>('transform');
    if (!playerTransform) return;

    const creatures = this.entityManager.query(['creature', 'transform']);

    for (const creatureEntity of creatures) {
      const creature = creatureEntity.getComponent<'creature'>('creature');
      const creatureTransform = creatureEntity.getComponent<'transform'>('transform');
      if (!creature || !creatureTransform || creature.health <= 0) continue;

      // Check distance
      const dx = playerTransform.x - creatureTransform.x;
      const dy = playerTransform.y - creatureTransform.y;
      const distance = Math.sqrt(dx * dx + dy * dy);

      if (distance <= this.RADIOACTIVE_AURA_RADIUS) {
        // Apply radiation damage per second (10 damage/sec from perk data)
        creature.health -= 10 * dt;
      }
    }
  }
}
