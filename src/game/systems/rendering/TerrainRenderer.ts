/**
 * Terrain Renderer
 *
 * Renders procedurally generated terrain background with UV scrolling.
 *
 * Responsibilities:
 * - Render terrain background with seamless tiling
 * - UV scrolling based on camera position for infinite scrolling effect
 * - Manage terrain canvas and pattern
 *
 * Non-responsibilities:
 * - Does not generate terrain (handled by TerrainGenerator)
 * - Does not manage camera position
 */

import type { Renderer } from '../../../engine';
import { TerrainGenerator, type TerrainTheme } from '../../../engine/TerrainGenerator';

export class TerrainRenderer {
  private renderer: Renderer;
  private terrainCanvas: HTMLCanvasElement | null = null;
  private terrainPattern: CanvasPattern | null = null;

  constructor(renderer: Renderer) {
    this.renderer = renderer;
  }

  /**
   * Set the terrain texture to use for background rendering.
   */
  setTerrain(terrainCanvas: HTMLCanvasElement): void {
    this.terrainCanvas = terrainCanvas;
    // Create pattern from terrain canvas for efficient repeating
    const ctx = this.renderer.getContext();
    this.terrainPattern = ctx.createPattern(terrainCanvas, 'repeat');
  }

  /**
   * Generate terrain with a specific theme.
   */
  generateTerrain(theme?: TerrainTheme): void {
    const generator = new TerrainGenerator(theme);
    const canvas = generator.generateTerrainTexture();
    this.setTerrain(canvas);
  }

  /**
   * Render the terrain background with UV scrolling based on camera position.
   */
  render(cameraX: number, cameraY: number): void {
    if (!this.terrainCanvas || !this.terrainPattern) {
      // Fallback to black if no terrain set
      this.renderer.clearBlack();
      return;
    }

    const ctx = this.renderer.getContext();
    const canvas = this.renderer.getCanvas();
    const terrainWidth = this.terrainCanvas.width;
    const terrainHeight = this.terrainCanvas.height;

    // Calculate UV offset from camera position for infinite scrolling
    const offsetX = -(cameraX % terrainWidth);
    const offsetY = -(cameraY % terrainHeight);

    // Draw terrain covering the viewport with offset for seamless tiling
    ctx.save();
    ctx.translate(offsetX, offsetY);
    ctx.fillStyle = this.terrainPattern;
    ctx.fillRect(
      -terrainWidth,
      -terrainHeight,
      canvas.width + terrainWidth * 2,
      canvas.height + terrainHeight * 2
    );
    ctx.restore();
  }
}
