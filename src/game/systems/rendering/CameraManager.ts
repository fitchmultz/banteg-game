/**
 * Camera Manager
 *
 * Manages camera position, zoom, and co-op camera calculations.
 *
 * Responsibilities:
 * - Calculate camera target position based on player positions
 * - Handle co-op camera with zoom to fit all players
 * - Smooth camera movement and zoom transitions
 * - Provide camera state for rendering
 *
 * Non-responsibilities:
 * - Does not apply camera to renderer (handled by RenderSystem)
 * - Does not handle screen shake (handled by Renderer)
 */

import type { EntityManager } from '../../../core/ecs/EntityManager';
import type { Renderer } from '../../../engine';

// Camera constants for co-op mode
const COOP_CAMERA_PADDING = 200; // Padding around players in pixels
const COOP_MIN_ZOOM = 0.6; // Minimum zoom level (don't zoom out too far)
const COOP_MAX_ZOOM = 1.2; // Maximum zoom level
const COOP_ZOOM_SMOOTHING = 0.05; // How quickly zoom changes

export interface CameraState {
  x: number;
  y: number;
  zoom: number;
}

export class CameraManager {
  private renderer: Renderer;
  private entityManager: EntityManager;

  // Camera state
  private cameraSmoothing = 0.1;
  private currentCameraX = 0;
  private currentCameraY = 0;
  private currentCameraZoom = 1;

  constructor(renderer: Renderer, entityManager: EntityManager) {
    this.renderer = renderer;
    this.entityManager = entityManager;
  }

  /**
   * Update camera position and zoom based on player positions.
   * Returns the current camera state after smoothing.
   */
  update(_dt: number): CameraState {
    // Find all players
    const players = this.entityManager.query(['player', 'transform']);
    if (players.length === 0) {
      return this.getState();
    }

    // Get player positions
    const playerPositions: { x: number; y: number }[] = [];
    for (const player of players) {
      const transform = player.getComponent<'transform'>('transform');
      if (transform) {
        playerPositions.push({ x: transform.x, y: transform.y });
      }
    }

    if (playerPositions.length === 0) {
      return this.getState();
    }

    // Compute camera target
    const cameraTarget = this.computeCoopCameraTarget(playerPositions);

    // Smooth camera position
    this.currentCameraX += (cameraTarget.x - this.currentCameraX) * this.cameraSmoothing;
    this.currentCameraY += (cameraTarget.y - this.currentCameraY) * this.cameraSmoothing;

    // Smooth zoom
    this.currentCameraZoom += (cameraTarget.zoom - this.currentCameraZoom) * COOP_ZOOM_SMOOTHING;

    return this.getState();
  }

  /**
   * Get the current camera state.
   */
  getState(): CameraState {
    return {
      x: this.currentCameraX,
      y: this.currentCameraY,
      zoom: this.currentCameraZoom,
    };
  }

  /**
   * Set the camera position directly.
   */
  setPosition(x: number, y: number): void {
    this.currentCameraX = x;
    this.currentCameraY = y;
  }

  /**
   * Compute camera target position and zoom for co-op mode.
   * Centers on midpoint of all players with zoom to fit.
   */
  private computeCoopCameraTarget(players: { x: number; y: number }[]): CameraState {
    if (players.length === 0) return { x: 0, y: 0, zoom: 1 };
    if (players.length === 1) return { x: players[0]?.x ?? 0, y: players[0]?.y ?? 0, zoom: 1 };

    // Find bounding box of all players
    let minX = players[0]?.x ?? 0;
    let maxX = players[0]?.x ?? 0;
    let minY = players[0]?.y ?? 0;
    let maxY = players[0]?.y ?? 0;

    for (const player of players) {
      minX = Math.min(minX, player.x);
      maxX = Math.max(maxX, player.x);
      minY = Math.min(minY, player.y);
      maxY = Math.max(maxY, player.y);
    }

    // Center on midpoint
    const centerX = (minX + maxX) / 2;
    const centerY = (minY + maxY) / 2;

    // Calculate required zoom to fit all players with padding
    const canvas = this.renderer.getCanvas();
    const boundsWidth = maxX - minX + COOP_CAMERA_PADDING * 2;
    const boundsHeight = maxY - minY + COOP_CAMERA_PADDING * 2;

    const zoomX = canvas.width / boundsWidth;
    const zoomY = canvas.height / boundsHeight;
    let targetZoom = Math.min(zoomX, zoomY);

    // Clamp zoom to min/max
    targetZoom = Math.max(COOP_MIN_ZOOM, Math.min(COOP_MAX_ZOOM, targetZoom));

    return { x: centerX, y: centerY, zoom: targetZoom };
  }
}
