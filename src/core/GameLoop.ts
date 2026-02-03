/**
 * Game Loop
 * 
 * Fixed timestep game loop with accumulator pattern.
 * Based on the frame_dt pattern from the original C source.
 */

import type { EntityManager } from './ecs/EntityManager';
import type { SystemManager, UpdateContext } from './ecs/System';

export interface GameLoopOptions {
  /** Target UPS (updates per second) */
  targetUps?: number;
  /** Maximum delta time to prevent spiral of death */
  maxDeltaTime?: number;
  /** Whether to pause when tab is hidden */
  pauseOnBlur?: boolean;
}

export type RenderCallback = (interpolation: number, fps: number) => void;
export type UpdateCallback = (context: UpdateContext) => void;

export class GameLoop {
  private targetUps: number;
  private timeStep: number;
  private maxDeltaTime: number;
  private pauseOnBlur: boolean;

  private accumulator = 0;
  private lastTime = 0;
  private frameNumber = 0;
  private isRunning = false;
  private rafId: number | null = null;
  private gameTime = 0;

  // FPS tracking
  private fpsUpdateInterval = 500; // ms
  private lastFpsUpdate = 0;
  private frameCount = 0;
  private currentFps = 0;

  constructor(
    private entityManager: EntityManager,
    private systemManager: SystemManager,
    private render: RenderCallback,
    options: GameLoopOptions = {}
  ) {
    this.targetUps = options.targetUps ?? 60;
    this.timeStep = 1000 / this.targetUps;
    this.maxDeltaTime = options.maxDeltaTime ?? 250;
    this.pauseOnBlur = options.pauseOnBlur ?? true;

    this.handleVisibilityChange = this.handleVisibilityChange.bind(this);
    this.loop = this.loop.bind(this);

    if (this.pauseOnBlur) {
      document.addEventListener('visibilitychange', this.handleVisibilityChange);
    }
  }

  /**
   * Start the game loop
   */
  start(): void {
    if (this.isRunning) return;

    this.isRunning = true;
    this.lastTime = performance.now();
    this.lastFpsUpdate = this.lastTime;
    this.rafId = requestAnimationFrame(this.loop);
  }

  /**
   * Stop the game loop
   */
  stop(): void {
    this.isRunning = false;
    if (this.rafId !== null) {
      cancelAnimationFrame(this.rafId);
      this.rafId = null;
    }
  }

  /**
   * Check if the loop is running
   */
  get running(): boolean {
    return this.isRunning;
  }

  /**
   * Get current FPS
   */
  get fps(): number {
    return this.currentFps;
  }

  /**
   * Get total game time in seconds
   */
  get totalGameTime(): number {
    return this.gameTime;
  }

  /**
   * Clean up resources
   */
  destroy(): void {
    this.stop();
    if (this.pauseOnBlur) {
      document.removeEventListener('visibilitychange', this.handleVisibilityChange);
    }
  }

  private handleVisibilityChange(): void {
    if (document.hidden) {
      // Pause when hidden
      this.lastTime = 0;
    }
  }

  private loop(currentTime: number): void {
    if (!this.isRunning) return;

    // Handle first frame or resume from pause
    if (this.lastTime === 0) {
      this.lastTime = currentTime;
    }

    // Calculate delta time
    let deltaTime = currentTime - this.lastTime;
    this.lastTime = currentTime;

    // Cap delta time to prevent spiral of death
    if (deltaTime > this.maxDeltaTime) {
      deltaTime = this.maxDeltaTime;
    }

    // Accumulate time for fixed timestep
    this.accumulator += deltaTime;

    // Update FPS counter
    this.frameCount++;
    if (currentTime - this.lastFpsUpdate >= this.fpsUpdateInterval) {
      this.currentFps = Math.round((this.frameCount * 1000) / (currentTime - this.lastFpsUpdate));
      this.frameCount = 0;
      this.lastFpsUpdate = currentTime;
    }

    // Fixed timestep updates
    while (this.accumulator >= this.timeStep) {
      const context: UpdateContext = {
        dt: this.timeStep / 1000,
        gameTime: this.gameTime,
        frameNumber: this.frameNumber,
      };

      this.systemManager.update(this.entityManager, context);
      this.entityManager.processDestructions();

      this.gameTime += this.timeStep / 1000;
      this.frameNumber++;
      this.accumulator -= this.timeStep;
    }

    // Render with interpolation
    const interpolation = this.accumulator / this.timeStep;
    this.render(interpolation, this.currentFps);

    this.rafId = requestAnimationFrame(this.loop);
  }
}
