/**
 * Render System
 *
 * Renders all visible entities and UI.
 * Now supports co-op mode with shared camera and two-player HUD,
 * and procedurally generated terrain backgrounds.
 * Priority: 200 (last to run)
 *
 * Responsibilities:
 * - Orchestrate rendering passes by delegating to sub-renderers
 * - Manage FPS counter
 * - Handle screen shake effects
 * - Manage particle effects
 * - Bridge between game state and rendering subsystems
 *
 * Non-responsibilities:
 * - Does not handle input processing
 * - Does not manage game state
 * - Does not handle touch controls rendering (handled by InputManager)
 * - Does not generate terrain (handled by TerrainRenderer)
 * - Does not manage camera (handled by CameraManager)
 * - Does not render entities directly (handled by EntityRenderer)
 * - Does not render UI directly (handled by UiRenderer)
 *
 * Assumptions:
 * - Renderer is initialized with valid canvas
 * - EntityManager contains valid entities with required components
 * - Sub-renderers are properly initialized
 */

import type { EntityManager } from '../../core/ecs/EntityManager';
import { System, type UpdateContext } from '../../core/ecs/System';
import {
  type AssetManager,
  type InputManager,
  ParticleSystem,
  type Renderer,
  type SpriteAtlas,
} from '../../engine';
import { TerrainRenderer } from './rendering/TerrainRenderer';
import { CameraManager } from './rendering/CameraManager';
import { EntityRenderer } from './rendering/EntityRenderer';
import { UiRenderer } from './rendering/UiRenderer';

export class RenderSystem extends System {
  readonly name = 'RenderSystem';
  readonly priority = 200;

  private renderer: Renderer;
  private particleSystem: ParticleSystem;
  private inputManager: InputManager | null = null;

  // Sub-renderers
  private terrainRenderer: TerrainRenderer;
  private cameraManager: CameraManager;
  private entityRenderer: EntityRenderer;
  private uiRenderer: UiRenderer;

  // FPS counter
  private frameCount = 0;
  private lastFpsTime = 0;
  private currentFps = 0;
  showFps = false;

  constructor(
    entityManager: EntityManager,
    renderer: Renderer,
    assetManager?: AssetManager,
    spriteAtlas?: SpriteAtlas,
    inputManager?: InputManager
  ) {
    super();
    this.renderer = renderer;
    this.inputManager = inputManager ?? null;
    this.particleSystem = new ParticleSystem(1000);

    // Initialize sub-renderers
    this.terrainRenderer = new TerrainRenderer(renderer);
    this.cameraManager = new CameraManager(renderer, entityManager);
    this.entityRenderer = new EntityRenderer(
      renderer,
      entityManager,
      assetManager ?? null,
      spriteAtlas ?? null
    );
    this.uiRenderer = new UiRenderer(renderer, entityManager);
  }

  /**
   * Get the particle system for emitting effects
   */
  getParticleSystem(): ParticleSystem {
    return this.particleSystem;
  }

  /**
   * Toggle FPS counter display
   */
  toggleFps(): void {
    this.showFps = !this.showFps;
  }

  /**
   * Trigger screen shake
   */
  shake(intensity: number, duration: number): void {
    this.renderer.shake(intensity, duration);
  }

  /**
   * Set the terrain texture to use for background rendering.
   * Delegates to TerrainRenderer.
   */
  setTerrain(terrainCanvas: HTMLCanvasElement): void {
    this.terrainRenderer.setTerrain(terrainCanvas);
  }

  /**
   * Generate terrain with a specific theme.
   * Delegates to TerrainRenderer.
   */
  generateTerrain(theme?: import('../../engine/TerrainGenerator').TerrainTheme): void {
    this.terrainRenderer.generateTerrain(theme);
  }

  /**
   * Set camera position directly.
   * Delegates to CameraManager.
   */
  setCameraPosition(x: number, y: number): void {
    this.cameraManager.setPosition(x, y);
  }

  update(_entityManager: EntityManager, context: UpdateContext): void {
    // Update FPS counter
    this.updateFps(context.dt);

    // Update screen shake
    this.renderer.updateScreenShake(context.dt);

    // Update particles
    this.particleSystem.update(context.dt);

    // Update camera and get current state
    const cameraState = this.cameraManager.update(context.dt);

    // Apply camera with screen shake offset
    const shakeOffset = this.renderer.getShakeOffset();
    this.renderer.setCamera(
      cameraState.x + shakeOffset.x,
      cameraState.y + shakeOffset.y,
      cameraState.zoom,
      0
    );
    this.renderer.applyCamera();

    // Render terrain background
    this.terrainRenderer.render(cameraState.x, cameraState.y);

    // Render entities
    this.entityRenderer.render();

    // Render particles (world space)
    this.particleSystem.render(this.renderer);

    // Restore camera
    this.renderer.restoreCamera();

    // Render UI (in screen space)
    this.uiRenderer.render(this.showFps, this.currentFps);

    // Render touch controls if enabled
    if (this.inputManager?.isTouchEnabled()) {
      const ctx = this.renderer.getContext();
      this.inputManager.renderTouchControls(ctx);
    }
  }

  private updateFps(dt: number): void {
    this.frameCount++;
    this.lastFpsTime += dt;
    if (this.lastFpsTime >= 1) {
      this.currentFps = this.frameCount;
      this.frameCount = 0;
      this.lastFpsTime = 0;
    }
  }
}
