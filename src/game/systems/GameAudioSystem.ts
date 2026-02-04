/**
 * Game Audio System
 *
 * Consumes collision event queues and plays appropriate SFX.
 * Provides centralized audio event handling for gameplay.
 * Priority: 65 (runs after CollisionSystem:60, before HealthSystem:70)
 *
 * Responsibilities:
 * - Play SFX for damage events (player hit, enemy hit)
 * - Play SFX for bonus and weapon pickups
 * - Optional stereo panning based on world position relative to player
 *
 * Non-goals:
 * - Does NOT handle death SFX (handled in HealthSystem callbacks)
 * - Does NOT load audio assets (handled in loadGameAudio)
 * - Does NOT play weapon fire/reload sounds (handled in WeaponSystem)
 */

import { System } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs';
import type { AudioManager } from '../../engine';
import {
  damageEvents,
  collectEvents,
  weaponCollectEvents,
  type DamageEvent,
  type CollectEvent,
  type WeaponCollectEvent,
} from './CollisionSystem';
import { getDamageSample, getBonusPickupSample, SAMPLES } from '../audio';

export class GameAudioSystem extends System {
  readonly name = 'GameAudioSystem';
  readonly priority = 65;

  private entityManager: EntityManager;
  private audio: AudioManager;

  // Track processed event IDs to avoid double-playing
  private processedDamageEvents = new Set<number>();
  private processedCollectEvents = new Set<number>();
  private processedWeaponEvents = new Set<number>();
  private eventIdCounter = 0;

  constructor(entityManager: EntityManager, audio: AudioManager) {
    super();
    this.entityManager = entityManager;
    this.audio = audio;
  }

  update(): void {
    // Get player position for panning calculations
    const playerPos = this.getPlayerPosition();

    // Process damage events
    for (const event of damageEvents) {
      const eventId = this.getEventId(event);
      if (this.processedDamageEvents.has(eventId)) continue;
      this.processedDamageEvents.add(eventId);

      const targetIsPlayer = this.isPlayer(event.targetId);
      const sample = getDamageSample({ targetIsPlayer, isFireDamage: event.isFireDamage });

      // Apply panning if target has a position and player exists
      const targetPos = this.getEntityPosition(event.targetId);
      if (targetPos && playerPos) {
        const pan = this.calculatePan(targetPos.x, playerPos.x);
        this.audio.playSample(sample, 1.0, pan);
      } else {
        this.audio.playSample(sample);
      }
    }

    // Cleanup old damage event IDs (keep last 100)
    if (this.processedDamageEvents.size > 100) {
      const toRemove = Array.from(this.processedDamageEvents).slice(
        0,
        this.processedDamageEvents.size - 100
      );
      for (const id of toRemove) {
        this.processedDamageEvents.delete(id);
      }
    }

    // Process collect events (bonuses)
    for (const event of collectEvents) {
      const eventId = this.getCollectEventId(event);
      if (this.processedCollectEvents.has(eventId)) continue;
      this.processedCollectEvents.add(eventId);

      const sample = getBonusPickupSample(event.bonusType);
      this.audio.playSample(sample);
    }

    // Cleanup old collect event IDs
    if (this.processedCollectEvents.size > 50) {
      const toRemove = Array.from(this.processedCollectEvents).slice(
        0,
        this.processedCollectEvents.size - 50
      );
      for (const id of toRemove) {
        this.processedCollectEvents.delete(id);
      }
    }

    // Process weapon collect events
    for (const event of weaponCollectEvents) {
      const eventId = this.getWeaponEventId(event);
      if (this.processedWeaponEvents.has(eventId)) continue;
      this.processedWeaponEvents.add(eventId);

      this.audio.playSample(SAMPLES.PICKUP_WEAPON);
    }

    // Cleanup old weapon event IDs
    if (this.processedWeaponEvents.size > 50) {
      const toRemove = Array.from(this.processedWeaponEvents).slice(
        0,
        this.processedWeaponEvents.size - 50
      );
      for (const id of toRemove) {
        this.processedWeaponEvents.delete(id);
      }
    }
  }

  /**
   * Get a unique ID for a damage event based on its content.
   * Uses a simple hash of the event properties.
   */
  private getEventId(event: DamageEvent): number {
    // Combine event properties into a hash
    const str = `${event.targetId}:${event.sourceId}:${event.damage}:${event.isFireDamage}:${this.eventIdCounter++}`;
    let hash = 0;
    for (let i = 0; i < str.length; i++) {
      const char = str.charCodeAt(i);
      hash = (hash << 5) - hash + char;
      hash = hash & hash; // Convert to 32bit integer
    }
    return hash;
  }

  private getCollectEventId(event: CollectEvent): number {
    const str = `${event.playerId}:${event.bonusId}:${event.bonusType}:${this.eventIdCounter++}`;
    let hash = 0;
    for (let i = 0; i < str.length; i++) {
      const char = str.charCodeAt(i);
      hash = (hash << 5) - hash + char;
      hash = hash & hash;
    }
    return hash;
  }

  private getWeaponEventId(event: WeaponCollectEvent): number {
    const str = `${event.playerId}:${event.pickupId}:${event.weaponId}:${this.eventIdCounter++}`;
    let hash = 0;
    for (let i = 0; i < str.length; i++) {
      const char = str.charCodeAt(i);
      hash = (hash << 5) - hash + char;
      hash = hash & hash;
    }
    return hash;
  }

  private isPlayer(entityId: number): boolean {
    const entity = this.entityManager.getEntity(entityId);
    return entity?.hasComponent('player') ?? false;
  }

  private getPlayerPosition(): { x: number; y: number } | null {
    const players = this.entityManager.query(['player', 'transform']);
    for (const entity of players) {
      const transform = entity.getComponent<'transform'>('transform');
      if (transform) {
        return { x: transform.x, y: transform.y };
      }
    }
    return null;
  }

  private getEntityPosition(entityId: number): { x: number; y: number } | null {
    const entity = this.entityManager.getEntity(entityId);
    if (!entity) return null;
    const transform = entity.getComponent<'transform'>('transform');
    return transform ? { x: transform.x, y: transform.y } : null;
  }

  /**
   * Calculate stereo pan based on world position relative to player.
   * Returns a value from -1 (full left) to 1 (full right).
   */
  private calculatePan(targetX: number, playerX: number): number {
    const maxDistance = 500; // Distance at which sound is fully panned
    const dx = targetX - playerX;
    const pan = Math.max(-1, Math.min(1, dx / maxDistance));
    return pan;
  }

  destroy(): void {
    this.processedDamageEvents.clear();
    this.processedCollectEvents.clear();
    this.processedWeaponEvents.clear();
  }
}
