/**
 * Spawn System
 *
 * Manages enemy spawning for survival mode with wave-based difficulty.
 * Priority: 80
 */


import { System, type UpdateContext } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs/EntityManager';
import { CreatureFactory } from '../entities';
import { selectRandomCreatureForWave } from '../data';

export interface SpawnSystemOptions {
  mapWidth: number;
  mapHeight: number;
  spawnMargin: number;
}

export class SpawnSystem extends System {
  readonly name = 'SpawnSystem';
  readonly priority = 80;

  private entityManager: EntityManager;
  private options: SpawnSystemOptions;

  // Current wave
  private wave = 1;
  // Enemies spawned this wave
  private spawnedThisWave = 0;
  // Target enemies for this wave
  private targetEnemies = 10;
  // Spawn cooldown
  private spawnCooldown = 0;
  // Base spawn interval
  private baseSpawnInterval = 2.0;
  // Wave timer
  private waveTimer = 0;
  // Wave duration (seconds)
  private waveDuration = 30;

  // Active enemies count (tracked externally)
  private activeEnemies = 0;

  // Spawn points around the map
  private spawnPoints: { x: number; y: number }[] = [];

  constructor(entityManager: EntityManager, options: Partial<SpawnSystemOptions> = {}) {
    super();
    this.entityManager = entityManager;
    this.options = {
      mapWidth: 2048,
      mapHeight: 2048,
      spawnMargin: 100,
      ...options,
    };

    this.generateSpawnPoints();
  }

  update(_entityManager: EntityManager, context: UpdateContext): void {
    const dt = context.dt;

    // Update wave timer
    this.waveTimer += dt;

    // Check for wave progression
    if (this.waveTimer >= this.waveDuration) {
      this.advanceWave();
    }

    // Update spawn cooldown
    if (this.spawnCooldown > 0) {
      this.spawnCooldown -= dt;
      return;
    }

    // Check if we need to spawn more enemies
    const remainingToSpawn = this.targetEnemies - this.spawnedThisWave;
    if (remainingToSpawn <= 0) return;

    // Limit concurrent enemies
    const maxConcurrentEnemies = 50 + this.wave * 5;
    if (this.activeEnemies >= maxConcurrentEnemies) return;

    // Spawn an enemy
    this.spawnEnemy();

    // Reset cooldown (decreases with higher waves)
    const difficultyMultiplier = 1 / (1 + this.wave * 0.1);
    this.spawnCooldown = this.baseSpawnInterval * difficultyMultiplier + Math.random() * 0.5;
  }

  private generateSpawnPoints(): void {
    const { mapWidth, mapHeight, spawnMargin } = this.options;
    const halfWidth = mapWidth / 2;
    const halfHeight = mapHeight / 2;

    // Generate spawn points around the edges
    const points: { x: number; y: number }[] = [];
    
    // Top and bottom edges
    for (let i = 0; i < 5; i++) {
      const x = (i / 4) * mapWidth - halfWidth;
      points.push({ x, y: -halfHeight - spawnMargin });
      points.push({ x, y: halfHeight + spawnMargin });
    }

    // Left and right edges
    for (let i = 0; i < 5; i++) {
      const y = (i / 4) * mapHeight - halfHeight;
      points.push({ x: -halfWidth - spawnMargin, y });
      points.push({ x: halfWidth + spawnMargin, y });
    }

    this.spawnPoints = points;
  }

  private spawnEnemy(): void {
    // Select random spawn point
    const spawnPoint = this.spawnPoints[Math.floor(Math.random() * this.spawnPoints.length)];
    if (!spawnPoint) return;

    // Select creature type based on current wave
    const creatureTypeId = selectRandomCreatureForWave(this.wave);

    // Spawn the creature
    CreatureFactory.create(
      this.entityManager,
      creatureTypeId,
      spawnPoint.x,
      spawnPoint.y
    );

    this.spawnedThisWave++;
    this.activeEnemies++;
  }

  private advanceWave(): void {
    this.wave++;
    this.waveTimer = 0;
    this.spawnedThisWave = 0;
    
    // Increase target enemies with each wave
    this.targetEnemies = 10 + this.wave * 5;

    console.log(`Wave ${this.wave} started! Target enemies: ${this.targetEnemies}`);
  }

  onEnemyDefeated(): void {
    this.activeEnemies = Math.max(0, this.activeEnemies - 1);
  }

  getWave(): number {
    return this.wave;
  }

  getWaveProgress(): number {
    return this.waveTimer / this.waveDuration;
  }

  getSpawnedCount(): number {
    return this.spawnedThisWave;
  }

  getTargetCount(): number {
    return this.targetEnemies;
  }

  getActiveEnemies(): number {
    return this.activeEnemies;
  }
}
