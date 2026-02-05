/**
 * StateSnapshot - Serializable State Capture for Replay Validation
 *
 * Captures entity and system state at specific points in time for comparison.
 * Used to verify determinism by comparing snapshots from different runs.
 */

import type { EntityManager } from '../../src/core/ecs/EntityManager';
import type { UpdateContext } from '../../src/core/ecs/System';

/**
 * Serializable entity snapshot
 */
export interface EntitySnapshot {
  id: number;
  type: string; // 'player' | 'creature' | 'projectile' | 'bonus' | 'weaponPickup'
  x: number;
  y: number;
  vx: number;
  vy: number;
  rotation: number;
  health?: number;
  maxHealth?: number;
  // Creature-specific
  aiMode?: number;
  creatureTypeId?: number;
  // Player-specific
  currentWeaponId?: number;
  ammo?: number;
  clipSize?: number;
  // Projectile-specific
  projectileTypeId?: number;
  lifetime?: number;
  damage?: number;
  // Bonus-specific
  bonusType?: number;
}

/**
 * System state snapshots for verification
 */
export interface SystemStateSnapshot {
  spawnSystem?: {
    wave: number;
    waveTimer: number;
    spawnedThisWave: number;
    targetEnemies: number;
    activeEnemies: number;
  };
  questSpawnSystem?: {
    timelineMs: number;
    remainingSpawns: number;
    isActive: boolean;
  };
  perkSystem?: {
    activeEffectCount: number;
    deathClockCount: number;
    jinxStateCount: number;
    dotEffectCount: number;
  };
}

/**
 * Complete state snapshot at a point in time
 */
export interface StateSnapshot {
  frameNumber: number;
  gameTime: number;
  entityCount: number;
  entities: EntitySnapshot[];
  systemState: SystemStateSnapshot;
  rngState?: number; // Optional RNG state for debugging
}

/**
 * Capture a snapshot of current game state
 */
export function captureSnapshot(
  entityManager: EntityManager,
  context: UpdateContext,
  systemRefs: {
    spawnSystem?: {
      getWave: () => number;
      getWaveProgress: () => number;
      getSpawnedCount: () => number;
      getTargetCount: () => number;
      getActiveEnemies: () => number;
    };
    questSpawnSystem?: {
      getTimelineMs: () => number;
      getRemainingSpawns: () => number;
      isRunning: () => boolean;
    };
    perkSystem?: {
      getActiveEffectCount: () => number;
      getDeathClockCount: () => number;
      getJinxStateCount: () => number;
      getDotEffectCount: () => number;
    };
  },
  rngState?: number
): StateSnapshot {
  const entities: EntitySnapshot[] = [];
  const allEntities = entityManager.getAllEntities();

  for (const entity of allEntities) {
    const snapshot: EntitySnapshot = {
      id: entity.id,
      type: 'unknown',
      x: 0,
      y: 0,
      vx: 0,
      vy: 0,
      rotation: 0,
    };

    // Determine entity type and capture relevant state
    if (entity.hasComponent('player')) {
      snapshot.type = 'player';
      const player = entity.getComponent<'player'>('player');
      const transform = entity.getComponent<'transform'>('transform');
      if (player && transform) {
        snapshot.x = transform.x;
        snapshot.y = transform.y;
        snapshot.rotation = transform.rotation;
        snapshot.health = player.health;
        snapshot.maxHealth = player.maxHealth;
        snapshot.currentWeaponId = player.currentWeapon.weaponId;
        snapshot.ammo = player.currentWeapon.ammo;
        snapshot.clipSize = player.currentWeapon.clipSize;
      }
    } else if (entity.hasComponent('creature')) {
      snapshot.type = 'creature';
      const creature = entity.getComponent<'creature'>('creature');
      const transform = entity.getComponent<'transform'>('transform');
      const velocity = entity.getComponent<'velocity'>('velocity');
      if (creature && transform) {
        snapshot.x = transform.x;
        snapshot.y = transform.y;
        snapshot.rotation = transform.rotation;
        snapshot.vx = velocity?.x ?? 0;
        snapshot.vy = velocity?.y ?? 0;
        snapshot.health = creature.health;
        snapshot.maxHealth = creature.maxHealth;
        snapshot.aiMode = creature.aiMode;
        snapshot.creatureTypeId = creature.creatureTypeId;
      }
    } else if (entity.hasComponent('projectile')) {
      snapshot.type = 'projectile';
      const projectile = entity.getComponent<'projectile'>('projectile');
      const transform = entity.getComponent<'transform'>('transform');
      const velocity = entity.getComponent<'velocity'>('velocity');
      if (projectile && transform) {
        snapshot.x = transform.x;
        snapshot.y = transform.y;
        snapshot.rotation = transform.rotation;
        snapshot.vx = velocity?.x ?? 0;
        snapshot.vy = velocity?.y ?? 0;
        snapshot.projectileTypeId = projectile.projectileTypeId;
        snapshot.lifetime = projectile.lifetime;
        snapshot.damage = projectile.damage;
      }
    } else if (entity.hasComponent('bonus')) {
      snapshot.type = 'bonus';
      const bonus = entity.getComponent<'bonus'>('bonus');
      const transform = entity.getComponent<'transform'>('transform');
      if (bonus && transform) {
        snapshot.x = transform.x;
        snapshot.y = transform.y;
        snapshot.bonusType = bonus.bonusType;
      }
    } else if (entity.hasComponent('weaponPickup')) {
      snapshot.type = 'weaponPickup';
      const pickup = entity.getComponent<'weaponPickup'>('weaponPickup');
      const transform = entity.getComponent<'transform'>('transform');
      if (pickup && transform) {
        snapshot.x = transform.x;
        snapshot.y = transform.y;
        snapshot.currentWeaponId = pickup.weaponId;
      }
    }

    entities.push(snapshot);
  }

  // Sort entities by ID for consistent ordering
  entities.sort((a, b) => a.id - b.id);

  // Capture system state
  const systemState: SystemStateSnapshot = {};

  if (systemRefs.spawnSystem) {
    systemState.spawnSystem = {
      wave: systemRefs.spawnSystem.getWave(),
      waveTimer: Math.round(systemRefs.spawnSystem.getWaveProgress() * 100) / 100,
      spawnedThisWave: systemRefs.spawnSystem.getSpawnedCount(),
      targetEnemies: systemRefs.spawnSystem.getTargetCount(),
      activeEnemies: systemRefs.spawnSystem.getActiveEnemies(),
    };
  }

  if (systemRefs.questSpawnSystem) {
    systemState.questSpawnSystem = {
      timelineMs: systemRefs.questSpawnSystem.getTimelineMs(),
      remainingSpawns: systemRefs.questSpawnSystem.getRemainingSpawns(),
      isActive: systemRefs.questSpawnSystem.isRunning(),
    };
  }

  if (systemRefs.perkSystem) {
    systemState.perkSystem = {
      activeEffectCount: systemRefs.perkSystem.getActiveEffectCount(),
      deathClockCount: systemRefs.perkSystem.getDeathClockCount(),
      jinxStateCount: systemRefs.perkSystem.getJinxStateCount(),
      dotEffectCount: systemRefs.perkSystem.getDotEffectCount(),
    };
  }

  const snapshot: StateSnapshot = {
    frameNumber: context.frameNumber,
    gameTime: Math.round(context.gameTime * 1000) / 1000,
    entityCount: entities.length,
    entities,
    systemState,
  };

  if (rngState !== undefined) {
    snapshot.rngState = rngState;
  }

  return snapshot;
}

/**
 * Compare two snapshots for equality
 * Returns array of differences (empty if equal)
 */
export function compareSnapshots(
  expected: StateSnapshot,
  actual: StateSnapshot,
  tolerance = 0.0001
): string[] {
  const differences: string[] = [];

  // Compare frame numbers
  if (expected.frameNumber !== actual.frameNumber) {
    differences.push(
      `frameNumber: expected ${expected.frameNumber}, got ${actual.frameNumber}`
    );
  }

  // Compare game times
  if (Math.abs(expected.gameTime - actual.gameTime) > tolerance) {
    differences.push(
      `gameTime: expected ${expected.gameTime}, got ${actual.gameTime}`
    );
  }

  // Compare entity counts
  if (expected.entityCount !== actual.entityCount) {
    differences.push(
      `entityCount: expected ${expected.entityCount}, got ${actual.entityCount}`
    );
  }

  // Compare entities
  const expectedEntities = new Map(expected.entities.map((e) => [e.id, e]));
  const actualEntities = new Map(actual.entities.map((e) => [e.id, e]));

  // Check for missing entities
  for (const [id, expectedEntity] of expectedEntities) {
    const actualEntity = actualEntities.get(id);
    if (!actualEntity) {
      differences.push(`Entity ${id} (${expectedEntity.type}): missing in actual`);
      continue;
    }

    // Compare entity properties
    const entityDiffs = compareEntitySnapshots(id, expectedEntity, actualEntity, tolerance);
    differences.push(...entityDiffs);
  }

  // Check for extra entities
  for (const [id, actualEntity] of actualEntities) {
    if (!expectedEntities.has(id)) {
      differences.push(`Entity ${id} (${actualEntity.type}): unexpected in actual`);
    }
  }

  // Compare system state
  const systemDiffs = compareSystemState(
    expected.systemState,
    actual.systemState,
    tolerance
  );
  differences.push(...systemDiffs);

  return differences;
}

/**
 * Compare two entity snapshots
 */
function compareEntitySnapshots(
  id: number,
  expected: EntitySnapshot,
  actual: EntitySnapshot,
  tolerance: number
): string[] {
  const differences: string[] = [];

  if (expected.type !== actual.type) {
    differences.push(`Entity ${id}: type expected ${expected.type}, got ${actual.type}`);
  }

  if (Math.abs(expected.x - actual.x) > tolerance) {
    differences.push(`Entity ${id}: x expected ${expected.x}, got ${actual.x}`);
  }

  if (Math.abs(expected.y - actual.y) > tolerance) {
    differences.push(`Entity ${id}: y expected ${expected.y}, got ${actual.y}`);
  }

  if (Math.abs(expected.rotation - actual.rotation) > tolerance) {
    differences.push(`Entity ${id}: rotation expected ${expected.rotation}, got ${actual.rotation}`);
  }

  // Compare health if present in both
  if (expected.health !== undefined && actual.health !== undefined) {
    if (Math.abs(expected.health - actual.health) > tolerance) {
      differences.push(
        `Entity ${id}: health expected ${expected.health}, got ${actual.health}`
      );
    }
  }

  // Compare creature-specific fields
  if (expected.aiMode !== undefined && actual.aiMode !== undefined) {
    if (expected.aiMode !== actual.aiMode) {
      differences.push(`Entity ${id}: aiMode expected ${expected.aiMode}, got ${actual.aiMode}`);
    }
  }

  if (expected.creatureTypeId !== undefined && actual.creatureTypeId !== undefined) {
    if (expected.creatureTypeId !== actual.creatureTypeId) {
      differences.push(
        `Entity ${id}: creatureTypeId expected ${expected.creatureTypeId}, got ${actual.creatureTypeId}`
      );
    }
  }

  return differences;
}

/**
 * Compare system state snapshots
 */
function compareSystemState(
  expected: SystemStateSnapshot,
  actual: SystemStateSnapshot,
  tolerance: number
): string[] {
  const differences: string[] = [];

  // Compare spawn system state
  if (expected.spawnSystem || actual.spawnSystem) {
    const exp = expected.spawnSystem;
    const act = actual.spawnSystem;
    if (!exp || !act) {
      differences.push('spawnSystem: one side has state, other does not');
    } else {
      if (exp.wave !== act.wave) {
        differences.push(`spawnSystem.wave: expected ${exp.wave}, got ${act.wave}`);
      }
      if (Math.abs(exp.spawnedThisWave - act.spawnedThisWave) > 0) {
        differences.push(
          `spawnSystem.spawnedThisWave: expected ${exp.spawnedThisWave}, got ${act.spawnedThisWave}`
        );
      }
      if (Math.abs(exp.activeEnemies - act.activeEnemies) > 0) {
        differences.push(
          `spawnSystem.activeEnemies: expected ${exp.activeEnemies}, got ${act.activeEnemies}`
        );
      }
    }
  }

  // Compare quest spawn system state
  if (expected.questSpawnSystem || actual.questSpawnSystem) {
    const exp = expected.questSpawnSystem;
    const act = actual.questSpawnSystem;
    if (!exp || !act) {
      differences.push('questSpawnSystem: one side has state, other does not');
    } else {
      if (Math.abs(exp.timelineMs - act.timelineMs) > tolerance * 1000) {
        differences.push(
          `questSpawnSystem.timelineMs: expected ${exp.timelineMs}, got ${act.timelineMs}`
        );
      }
    }
  }

  return differences;
}

/**
 * Serialize snapshot to compact JSON format for golden files
 */
export function serializeSnapshot(snapshot: StateSnapshot): string {
  // Use compact JSON without whitespace for smaller files
  // We don't sort keys to preserve nested entity data
  return JSON.stringify(snapshot);
}

/**
 * Deserialize snapshot from compact format
 */
export function deserializeSnapshot(data: string): StateSnapshot {
  return JSON.parse(data) as StateSnapshot;
}
