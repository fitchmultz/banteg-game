/**
 * Terrain Generator
 *
 * Procedurally generates terrain backgrounds using the original Crimsonland (2003)
 * algorithm: 3-layer sprite compositing with random placement and rotation.
 *
 * Responsibilities:
 * - Generate procedural terrain detail sprites (rocks, pebbles, ground patches)
 * - Composite sprites onto 1024x1024 offscreen canvas using 3-layer algorithm
 * - Cache generated terrain texture for reuse
 *
 * Does NOT handle:
 * - Rendering (handled by RenderSystem)
 * - Camera/scrolling logic (handled by RenderSystem)
 * - Theme variations (future enhancement)
 *
 * Assumptions:
 * - Canvas API is available
 * - Generated texture is used as a repeating pattern
 */

export interface TerrainTheme {
  baseColor: { r: number; g: number; b: number };
  detailColor: { r: number; g: number; b: number };
  layer1Opacity: number;
  layer2Opacity: number;
  layer3Opacity: number;
}

export const DEFAULT_TERRAIN_THEME: TerrainTheme = {
  baseColor: { r: 63, g: 56, b: 25 }, // Brownish ground (0.247, 0.219, 0.098)
  detailColor: { r: 178, g: 178, b: 178 }, // Gray details (0.7, 0.7, 0.7)
  layer1Opacity: 0.9,
  layer2Opacity: 0.9,
  layer3Opacity: 0.6,
};

// Default texture size matching original
const DEFAULT_TEXTURE_SIZE = 1024;

// Layer counts from original decompiled code
const LAYER1_COUNT = 800;
const LAYER2_COUNT = 35;
const LAYER3_COUNT = 15;

// Margin for sprite placement (64px as in original)
const PLACEMENT_MARGIN = 64;

/**
 * Generates procedural terrain textures using the original 3-layer algorithm.
 */
export class TerrainGenerator {
  private canvas: HTMLCanvasElement;
  private ctx: CanvasRenderingContext2D;
  private theme: TerrainTheme;
  private textureSize: number;

  constructor(theme: TerrainTheme = DEFAULT_TERRAIN_THEME, textureSize = DEFAULT_TEXTURE_SIZE) {
    this.theme = theme;
    this.textureSize = textureSize;

    // Create offscreen canvas
    this.canvas = document.createElement('canvas');
    this.canvas.width = textureSize;
    this.canvas.height = textureSize;

    const ctx = this.canvas.getContext('2d');
    if (!ctx) {
      throw new Error('Failed to get 2D context for terrain generation');
    }
    this.ctx = ctx;
  }

  /**
   * Generate the terrain texture using the 3-layer algorithm.
   * Returns a canvas that can be used as a repeating pattern.
   */
  generateTerrainTexture(): HTMLCanvasElement {
    // Clear to base color
    this.fillBaseColor();

    // Generate and draw detail sprites for each layer
    this.drawLayer(LAYER1_COUNT, this.theme.layer1Opacity);
    this.drawLayer(LAYER2_COUNT, this.theme.layer2Opacity);
    this.drawLayer(LAYER3_COUNT, this.theme.layer3Opacity);

    return this.canvas;
  }

  /**
   * Get the generated terrain canvas.
   * Call generateTerrainTexture() first if not already generated.
   */
  getCanvas(): HTMLCanvasElement {
    return this.canvas;
  }

  /**
   * Get the texture dimensions.
   */
  getDimensions(): { width: number; height: number } {
    return { width: this.textureSize, height: this.textureSize };
  }

  /**
   * Fill the canvas with the base terrain color.
   */
  private fillBaseColor(): void {
    const { r, g, b } = this.theme.baseColor;
    this.ctx.fillStyle = `rgb(${r}, ${g}, ${b})`;
    this.ctx.fillRect(0, 0, this.textureSize, this.textureSize);
  }

  /**
   * Draw a layer of randomly placed detail sprites.
   */
  private drawLayer(count: number, opacity: number): void {
    const { r, g, b } = this.theme.detailColor;

    for (let i = 0; i < count; i++) {
      // Random position with margin (can place slightly outside for seamless tiling)
      const x = Math.random() * (this.textureSize + PLACEMENT_MARGIN * 2) - PLACEMENT_MARGIN;
      const y = Math.random() * (this.textureSize + PLACEMENT_MARGIN * 2) - PLACEMENT_MARGIN;

      // Random rotation (0-180 degrees / 0-PI radians)
      const rotation = Math.random() * Math.PI;

      // Draw the detail sprite
      this.drawDetailSprite(x, y, rotation, r, g, b, opacity);
    }
  }

  /**
   * Draw a single detail sprite (rock/pebble/patch).
   * Uses simple geometric shapes to match the game's aesthetic.
   */
  private drawDetailSprite(
    x: number,
    y: number,
    rotation: number,
    r: number,
    g: number,
    b: number,
    opacity: number
  ): void {
    this.ctx.save();

    // Set color with opacity
    this.ctx.fillStyle = `rgba(${r}, ${g}, ${b}, ${opacity})`;

    // Translate and rotate
    this.ctx.translate(x, y);
    this.ctx.rotate(rotation);

    // Draw a simple rock/pebble shape using irregular polygon
    // Size varies slightly for variety
    const baseSize = 4 + Math.random() * 4;
    this.drawRockShape(0, 0, baseSize);

    this.ctx.restore();
  }

  /**
   * Draw an irregular rock/pebble shape.
   */
  private drawRockShape(cx: number, cy: number, size: number): void {
    const points = 5 + Math.floor(Math.random() * 3); // 5-7 points
    const angleStep = (Math.PI * 2) / points;

    this.ctx.beginPath();

    for (let i = 0; i < points; i++) {
      const angle = i * angleStep;
      // Vary the radius for irregular shape
      const radius = size * (0.7 + Math.random() * 0.6);
      const px = cx + Math.cos(angle) * radius;
      const py = cy + Math.sin(angle) * radius;

      if (i === 0) {
        this.ctx.moveTo(px, py);
      } else {
        this.ctx.lineTo(px, py);
      }
    }

    this.ctx.closePath();
    this.ctx.fill();
  }
}

/**
 * Generate a terrain texture with the default theme.
 * Convenience function for quick terrain generation.
 */
export function generateTerrainTexture(
  theme: TerrainTheme = DEFAULT_TERRAIN_THEME,
  size = DEFAULT_TEXTURE_SIZE
): HTMLCanvasElement {
  const generator = new TerrainGenerator(theme, size);
  return generator.generateTerrainTexture();
}

/**
 * Create a canvas pattern from a terrain texture for efficient repeating rendering.
 */
export function createTerrainPattern(
  ctx: CanvasRenderingContext2D,
  terrainCanvas: HTMLCanvasElement
): CanvasPattern | null {
  return ctx.createPattern(terrainCanvas, 'repeat');
}
