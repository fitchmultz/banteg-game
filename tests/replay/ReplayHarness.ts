/**
 * ReplayHarness - Deterministic Scenario Testing Infrastructure
 *
 * Provides a test harness for running headless game simulations with
 * controlled seeds and inputs, capturing state snapshots for verification.
 */

import { EntityManager } from '../../src/core/ecs/EntityManager';
import { SystemManager, type UpdateContext } from '../../src/core/ecs/System';
import { SpawnSystem } from '../../src/game/systems/SpawnSystem';
import { QuestSpawnSystem } from '../../src/game/systems/QuestSpawnSystem';
import { PerkSystem } from '../../src/game/systems/PerkSystem';
import { AiSystem } from '../../src/game/systems/AiSystem';
import { WeaponSystem } from '../../src/game/systems/WeaponSystem';
import { ProjectileSystem } from '../../src/game/systems/ProjectileSystem';
import { CollisionSystem } from '../../src/game/systems/CollisionSystem';
import { HealthSystem } from '../../src/game/systems/HealthSystem';
import { PlayerFactory } from '../../src/game/entities';
import { WeaponId } from '../../src/types';
import { getQuestData } from '../../src/game/data/quests';
import { mockRandomWithSeed, restoreRandom, testRNG } from './SeededRNG';
import { captureSnapshot, type StateSnapshot } from './StateSnapshot';

/**
 * Input event for replay recording
 */
export interface InputEvent {
  frameNumber: number;
  type: 'move' | 'fire' | 'reload' | 'selectPerk' | 'swapWeapon' | 'moveTo';
  data: Record<string, unknown>;
}

/**
 * Replay scenario definition
 */
export interface ReplayScenario {
  name: string;
  seed: number;
  durationFrames: number;
  initialState: {
    playerPosition: { x: number; y: number };
    gameMode: 'survival' | 'quest';
    questId?: string;
  };
  inputs: InputEvent[];
}

/**
 * Mock audio manager for headless testing
 */
class MockAudioManager {
  playSample(): void {
    // No-op for headless testing
  }
}

/**
 * Replay harness for deterministic scenario testing
 */
export class ReplayHarness {
  private entityManager: EntityManager;
  private systemManager: SystemManager;
  private spawnSystem: SpawnSystem | null = null;
  private questSpawnSystem: QuestSpawnSystem | null = null;
  private perkSystem: PerkSystem | null = null;
  private collisionSystem: CollisionSystem | null = null;

  private currentFrame = 0;
  private currentGameTime = 0;
  private playerEntityId: number | null = null;
  private inputs: InputEvent[] = [];
  private snapshots: Map<number, StateSnapshot> = new Map();

  // Fixed timestep
  private readonly dt = 1 / 60; // 60Hz

  constructor() {
    this.entityManager = new EntityManager();
    this.systemManager = new SystemManager();
  }

  /**
   * Set up a scenario for replay
   */
  setupScenario(scenario: ReplayScenario): void {
    // Reset state
    this.entityManager.clear();
    this.systemManager.clear();
    this.snapshots.clear();
    this.inputs = [...scenario.inputs];
    this.currentFrame = 0;
    this.currentGameTime = 0;
    this.playerEntityId = null;

    // Reset systems
    this.spawnSystem = null;
    this.questSpawnSystem = null;
    this.perkSystem = null;
    this.collisionSystem = null;

    // Seed RNG
    mockRandomWithSeed(scenario.seed);

    // Create mock audio
    const mockAudio = new MockAudioManager();

    // Set up systems based on game mode
    if (scenario.initialState.gameMode === 'survival') {
      this.spawnSystem = new SpawnSystem(this.entityManager, {
        mapWidth: 2048,
        mapHeight: 2048,
        spawnMargin: 100,
      });
      this.systemManager.addSystem(this.spawnSystem);
    } else if (scenario.initialState.gameMode === 'quest' && scenario.initialState.questId) {
      this.questSpawnSystem = new QuestSpawnSystem(
        this.entityManager,
        {},
        {
          mapWidth: 2048,
          mapHeight: 2048,
          spawnRadius: 800,
        }
      );
      const quest = getQuestData(
        scenario.initialState.questId as import('../../src/types').QuestId
      );
      if (quest) {
        this.questSpawnSystem.startQuest(quest);
      }
    }

    // Add perk system
    this.perkSystem = new PerkSystem(this.entityManager, {});
    this.systemManager.addSystem(
      this.perkSystem as unknown as import('../../src/core/ecs/System').System
    );

    // Add AI system
    this.systemManager.addSystem(new AiSystem(this.entityManager));

    // Add weapon system (with mock audio)
    const weaponSystem = new WeaponSystem(
      this.entityManager,
      mockAudio as unknown as import('../../src/engine').AudioManager
    );
    weaponSystem.setPerkSystem(this.perkSystem);
    this.systemManager.addSystem(weaponSystem);

    // Add projectile system
    this.systemManager.addSystem(new ProjectileSystem(this.entityManager));

    // Add collision system
    this.collisionSystem = new CollisionSystem(
      this.entityManager,
      mockAudio as unknown as import('../../src/engine').AudioManager,
      this.perkSystem
    );
    this.systemManager.addSystem(this.collisionSystem);

    // Add health system
    const healthSystem = new HealthSystem(this.entityManager, {}, this.perkSystem ?? undefined);
    this.systemManager.addSystem(healthSystem);

    // Create player
    const playerEntity = PlayerFactory.create(
      this.entityManager,
      scenario.initialState.playerPosition.x,
      scenario.initialState.playerPosition.y
    );
    this.playerEntityId = playerEntity.id;

    // Set up player with pistol
    const player = playerEntity.getComponent<'player'>('player');
    if (player) {
      player.currentWeapon.weaponId = WeaponId.PISTOL;
      player.currentWeapon.clipSize = 12;
      player.currentWeapon.ammo = 48;
    }
  }

  /**
   * Run scenario for specified number of frames
   */
  runFrames(count: number, captureInterval = 1): Map<number, StateSnapshot> {
    for (let i = 0; i < count; i++) {
      this.stepOneFrame();
      if (this.currentFrame % captureInterval === 0) {
        this.snapshots.set(this.currentFrame, this.captureCurrentState());
      }
    }
    return this.snapshots;
  }

  /**
   * Run single frame
   */
  stepOneFrame(): void {
    // Process inputs for this frame
    const frameInputs = this.inputs.filter((i) => i.frameNumber === this.currentFrame);
    for (const input of frameInputs) {
      this.applyInput(input);
    }

    // Create update context
    const context = this.createUpdateContext();

    // Update systems
    this.systemManager.update(this.entityManager, context);

    // Update quest spawn system if active
    if (this.questSpawnSystem?.isRunning()) {
      this.questSpawnSystem.update(this.dt);
    }

    // Process destructions
    this.entityManager.processDestructions();

    // Advance time
    this.currentFrame++;
    this.currentGameTime += this.dt;
  }

  /**
   * Get snapshot at specific frame
   */
  getSnapshot(frameNumber: number): StateSnapshot | undefined {
    return this.snapshots.get(frameNumber);
  }

  /**
   * Get current frame number
   */
  getCurrentFrame(): number {
    return this.currentFrame;
  }

  /**
   * Get entity manager for inspection
   */
  getEntityManager(): EntityManager {
    return this.entityManager;
  }

  /**
   * Get player entity ID
   */
  getPlayerEntityId(): number | null {
    return this.playerEntityId;
  }

  /**
   * Get perk system for testing
   */
  getPerkSystem(): PerkSystem | null {
    return this.perkSystem;
  }

  /**
   * Get spawn system for testing
   */
  getSpawnSystem(): SpawnSystem | null {
    return this.spawnSystem;
  }

  /**
   * Get quest spawn system for testing
   */
  getQuestSpawnSystem(): QuestSpawnSystem | null {
    return this.questSpawnSystem;
  }

  /**
   * Clean up resources
   */
  destroy(): void {
    this.entityManager.clear();
    this.systemManager.clear();
    restoreRandom();
  }

  private createUpdateContext(): UpdateContext {
    return {
      dt: this.dt,
      unscaledDt: this.dt,
      gameTime: this.currentGameTime,
      frameNumber: this.currentFrame,
      timeScale: 1.0,
      setTimeScale: () => {},
    };
  }

  private captureCurrentState(): StateSnapshot {
    const context = this.createUpdateContext();

    // Build system refs object conditionally to avoid undefined values
    const systemRefs: Parameters<typeof captureSnapshot>[2] = {};

    if (this.spawnSystem) {
      const spawn = this.spawnSystem;
      systemRefs.spawnSystem = {
        getWave: () => spawn.getWave(),
        getWaveProgress: () => spawn.getWaveProgress(),
        getSpawnedCount: () => spawn.getSpawnedCount(),
        getTargetCount: () => spawn.getTargetCount(),
        getActiveEnemies: () => spawn.getActiveEnemies(),
      };
    }

    if (this.questSpawnSystem) {
      const quest = this.questSpawnSystem;
      systemRefs.questSpawnSystem = {
        getTimelineMs: () => quest.getTimelineMs(),
        getRemainingSpawns: () => quest.getRemainingSpawns(),
        isRunning: () => quest.isRunning(),
      };
    }

    if (this.perkSystem) {
      systemRefs.perkSystem = {
        getActiveEffectCount: () => 0, // Simplified for now
        getDeathClockCount: () => 0,
        getJinxStateCount: () => 0,
        getDotEffectCount: () => 0,
      };
    }

    return captureSnapshot(this.entityManager, context, systemRefs, testRNG.getState());
  }

  private applyInput(input: InputEvent): void {
    if (!this.playerEntityId) return;

    const playerEntity = this.entityManager.getEntity(this.playerEntityId);
    if (!playerEntity) return;

    const player = playerEntity.getComponent<'player'>('player');
    const transform = playerEntity.getComponent<'transform'>('transform');
    if (!player || !transform) return;

    switch (input.type) {
      case 'move': {
        // Apply movement: data should have dx, dy
        const dx = (input.data.dx as number) ?? 0;
        const dy = (input.data.dy as number) ?? 0;
        const speed = 200; // Default player speed
        transform.x += dx * speed * this.dt;
        transform.y += dy * speed * this.dt;
        break;
      }

      case 'moveTo': {
        // Teleport to position: data should have x, y
        transform.x = (input.data.x as number) ?? transform.x;
        transform.y = (input.data.y as number) ?? transform.y;
        break;
      }

      case 'fire': {
        // Trigger fire input
        player.fireJustPressed = true;
        player.fireHeld = true;
        break;
      }

      case 'reload': {
        // Trigger reload
        player.reloadRequested = true;
        break;
      }

      case 'swapWeapon': {
        // Trigger weapon swap
        player.swapWeaponRequested = true;
        break;
      }

      case 'selectPerk': {
        // Apply perk to player
        const perkId = input.data.perkId as number;
        if (this.perkSystem && perkId !== undefined) {
          this.perkSystem.applyPerk(this.playerEntityId, perkId, this.currentGameTime);
        }
        break;
      }
    }
  }
}
