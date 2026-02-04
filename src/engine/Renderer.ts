/**
 * Canvas 2D Renderer
 *
 * Replacement for grim.dll's Direct3D 8 rendering.
 * Provides viewport/camera support, sprite drawing, and transform state management.
 */

import type { Vector2 } from '../types';
import type { SpriteFrame } from './SpriteAtlas';

export interface RendererOptions {
  width: number;
  height: number;
  smoothing?: boolean;
}

export interface Viewport {
  x: number;
  y: number;
  width: number;
  height: number;
}

export interface Camera {
  x: number;
  y: number;
  zoom: number;
  rotation: number;
}

export interface SpriteDrawOptions {
  /** Width to draw (defaults to frame width) */
  width?: number;
  /** Height to draw (defaults to frame height) */
  height?: number;
  /** Rotation in radians */
  rotation?: number;
  /** Opacity (0-1) */
  opacity?: number;
  /** Flip horizontally */
  flipX?: boolean;
  /** Flip vertically */
  flipY?: boolean;
  /** Scale factor */
  scale?: number;
}

export interface ScreenShake {
  intensity: number;
  duration: number;
  decay: number;
  currentTime: number;
}

interface TransformState {
  rotation: number;
  translation: Vector2;
  scale: Vector2;
}

export class Renderer {
  private canvas: HTMLCanvasElement;
  private ctx: CanvasRenderingContext2D;
  private width: number;
  private height: number;

  private batchActive = false;
  private currentRotation = 0;
  private currentTranslation: Vector2 = { x: 0, y: 0 };
  private currentScale: Vector2 = { x: 1, y: 1 };

  // Viewport and camera
  private viewport: Viewport = { x: 0, y: 0, width: 0, height: 0 };
  private camera: Camera = { x: 0, y: 0, zoom: 1, rotation: 0 };
  private useViewport = false;

  // Transform state stack
  private stateStack: TransformState[] = [];

  // Screen shake effect
  private screenShake: ScreenShake | null = null;
  private shakeOffsetX = 0;
  private shakeOffsetY = 0;

  constructor(container: HTMLElement, options: RendererOptions) {
    this.width = options.width;
    this.height = options.height;

    this.canvas = document.createElement('canvas');
    this.canvas.width = this.width;
    this.canvas.height = this.height;
    this.canvas.style.display = 'block';
    this.canvas.style.imageRendering = options.smoothing ? 'auto' : 'pixelated';

    container.appendChild(this.canvas);

    const ctx = this.canvas.getContext('2d');
    if (!ctx) {
      throw new Error('Failed to get 2D context');
    }
    this.ctx = ctx;

    this.ctx.imageSmoothingEnabled = options.smoothing ?? false;

    // Initialize viewport to full canvas
    this.viewport = { x: 0, y: 0, width: this.width, height: this.height };
  }

  // ============================================================================
  // Viewport and Camera
  // ============================================================================

  /**
   * Set the viewport (clipping region)
   */
  setViewport(x: number, y: number, width: number, height: number): void {
    this.viewport = { x, y, width, height };
    this.useViewport = true;
    this.applyViewport();
  }

  /**
   * Reset viewport to full canvas
   */
  resetViewport(): void {
    this.useViewport = false;
    this.viewport = { x: 0, y: 0, width: this.width, height: this.height };
    this.ctx.restore();
    this.ctx.save();
  }

  /**
   * Get current viewport
   */
  getViewport(): Viewport {
    return { ...this.viewport };
  }

  /**
   * Set camera position and zoom
   */
  setCamera(x: number, y: number, zoom = 1, rotation = 0): void {
    this.camera = { x, y, zoom, rotation };
  }

  /**
   * Get current camera state
   */
  getCamera(): Camera {
    return { ...this.camera };
  }

  /**
   * Convert world coordinates to screen coordinates
   */
  worldToScreen(worldX: number, worldY: number): { x: number; y: number } {
    const dx = worldX - this.camera.x;
    const dy = worldY - this.camera.y;

    // Apply rotation
    const cos = Math.cos(-this.camera.rotation);
    const sin = Math.sin(-this.camera.rotation);
    const rx = dx * cos - dy * sin;
    const ry = dx * sin + dy * cos;

    // Apply zoom and translate to center of viewport
    return {
      x: this.viewport.x + this.viewport.width / 2 + rx * this.camera.zoom,
      y: this.viewport.y + this.viewport.height / 2 + ry * this.camera.zoom,
    };
  }

  /**
   * Convert screen coordinates to world coordinates
   */
  screenToWorld(screenX: number, screenY: number): { x: number; y: number } {
    // Remove viewport offset
    const x = screenX - this.viewport.x - this.viewport.width / 2;
    const y = screenY - this.viewport.y - this.viewport.height / 2;

    // Remove zoom
    const zx = x / this.camera.zoom;
    const zy = y / this.camera.zoom;

    // Remove rotation
    const cos = Math.cos(this.camera.rotation);
    const sin = Math.sin(this.camera.rotation);
    const rx = zx * cos - zy * sin;
    const ry = zx * sin + zy * cos;

    return {
      x: this.camera.x + rx,
      y: this.camera.y + ry,
    };
  }

  /**
   * Apply camera transform for world-space rendering
   */
  applyCamera(): void {
    this.ctx.save();

    // Translate to viewport center
    this.ctx.translate(
      this.viewport.x + this.viewport.width / 2,
      this.viewport.y + this.viewport.height / 2
    );

    // Apply zoom
    this.ctx.scale(this.camera.zoom, this.camera.zoom);

    // Apply rotation
    this.ctx.rotate(this.camera.rotation);

    // Translate by negative camera position
    this.ctx.translate(-this.camera.x, -this.camera.y);
  }

  /**
   * Restore transform after camera rendering
   */
  restoreCamera(): void {
    this.ctx.restore();
  }

  // ============================================================================
  // Transform State Stack
  // ============================================================================

  /**
   * Push current transform state onto the stack
   */
  pushState(): void {
    this.stateStack.push({
      rotation: this.currentRotation,
      translation: { ...this.currentTranslation },
      scale: { ...this.currentScale },
    });
    this.ctx.save();
  }

  /**
   * Pop transform state from the stack
   */
  popState(): void {
    const state = this.stateStack.pop();
    if (state) {
      this.currentRotation = state.rotation;
      this.currentTranslation = state.translation;
      this.currentScale = state.scale;
    }
    this.ctx.restore();
    if (this.batchActive) {
      this.applyTransform();
    }
  }

  // ============================================================================
  // Sprite Drawing
  // ============================================================================

  /**
   * Draw a sprite from a sprite atlas frame
   */
  drawSprite(
    image: CanvasImageSource,
    frame: SpriteFrame,
    x: number,
    y: number,
    options: SpriteDrawOptions = {}
  ): void {
    const width = options.width ?? frame.width;
    const height = options.height ?? frame.height;
    const scale = options.scale ?? 1;
    const opacity = options.opacity ?? 1;

    this.ctx.save();

    // Apply opacity
    this.ctx.globalAlpha = opacity;

    // Move to position
    this.ctx.translate(x, y);

    // Apply rotation
    if (options.rotation) {
      this.ctx.rotate(options.rotation);
    }

    // Apply flips
    const scaleX = options.flipX ? -scale : scale;
    const scaleY = options.flipY ? -scale : scale;
    this.ctx.scale(scaleX, scaleY);

    // Draw the sprite centered
    const drawWidth = width * scale;
    const drawHeight = height * scale;
    const drawX = -drawWidth / 2;
    const drawY = -drawHeight / 2;

    this.ctx.drawImage(
      image,
      frame.x,
      frame.y,
      frame.width,
      frame.height,
      drawX,
      drawY,
      drawWidth,
      drawHeight
    );

    this.ctx.restore();
  }

  /**
   * Draw a sprite using raw UV coordinates
   */
  drawSpriteUV(
    image: CanvasImageSource,
    x: number,
    y: number,
    width: number,
    height: number,
    u0: number,
    v0: number,
    u1: number,
    v1: number,
    options: SpriteDrawOptions = {}
  ): void {
    const imgWidth =
      (image as HTMLImageElement).naturalWidth || (image as HTMLCanvasElement).width || 1;
    const imgHeight =
      (image as HTMLImageElement).naturalHeight || (image as HTMLCanvasElement).height || 1;

    const sx = u0 * imgWidth;
    const sy = v0 * imgHeight;
    const sw = (u1 - u0) * imgWidth;
    const sh = (v1 - v0) * imgHeight;

    const scale = options.scale ?? 1;
    const opacity = options.opacity ?? 1;

    this.ctx.save();

    this.ctx.globalAlpha = opacity;
    this.ctx.translate(x, y);

    if (options.rotation) {
      this.ctx.rotate(options.rotation);
    }

    const scaleX = options.flipX ? -scale : scale;
    const scaleY = options.flipY ? -scale : scale;
    this.ctx.scale(scaleX, scaleY);

    const drawWidth = width * scale;
    const drawHeight = height * scale;

    this.ctx.drawImage(
      image,
      sx,
      sy,
      sw,
      sh,
      -drawWidth / 2,
      -drawHeight / 2,
      drawWidth,
      drawHeight
    );

    this.ctx.restore();
  }

  // ============================================================================
  // Basic Drawing Operations
  // ============================================================================

  clear(r: number, g: number, b: number, a = 1): void {
    this.ctx.fillStyle = `rgba(${r * 255}, ${g * 255}, ${b * 255}, ${a})`;
    this.ctx.fillRect(this.viewport.x, this.viewport.y, this.viewport.width, this.viewport.height);
  }

  clearBlack(): void {
    this.clear(0, 0, 0, 1);
  }

  beginBatch(): void {
    if (this.batchActive) {
      this.endBatch();
    }
    this.ctx.save();
    this.batchActive = true;
    this.applyTransform();
  }

  endBatch(): void {
    if (this.batchActive) {
      this.ctx.restore();
      this.batchActive = false;
    }
  }

  flushBatch(): void {
    // Canvas 2D renders immediately, so this is a no-op
  }

  setColor(r: number, g: number, b: number, a: number): void {
    this.ctx.fillStyle = `rgba(${r * 255}, ${g * 255}, ${b * 255}, ${a})`;
    this.ctx.strokeStyle = `rgba(${r * 255}, ${g * 255}, ${b * 255}, ${a})`;
  }

  setRotation(radians: number): void {
    this.currentRotation = radians;
    this.applyTransform();
  }

  setTranslation(x: number, y: number): void {
    this.currentTranslation = { x, y };
    this.applyTransform();
  }

  setScale(x: number, y: number): void {
    this.currentScale = { x, y };
    this.applyTransform();
  }

  drawRect(x: number, y: number, width: number, height: number): void {
    this.ctx.fillRect(x, y, width, height);
  }

  drawRectOutline(x: number, y: number, width: number, height: number, lineWidth = 1): void {
    this.ctx.lineWidth = lineWidth;
    this.ctx.strokeRect(x, y, width, height);
  }

  drawCircle(x: number, y: number, radius: number): void {
    this.ctx.beginPath();
    this.ctx.arc(x, y, radius, 0, Math.PI * 2);
    this.ctx.fill();
  }

  drawCircleOutline(x: number, y: number, radius: number, lineWidth = 1): void {
    this.ctx.lineWidth = lineWidth;
    this.ctx.beginPath();
    this.ctx.arc(x, y, radius, 0, Math.PI * 2);
    this.ctx.stroke();
  }

  drawLine(x1: number, y1: number, x2: number, y2: number, lineWidth = 1): void {
    this.ctx.lineWidth = lineWidth;
    this.ctx.beginPath();
    this.ctx.moveTo(x1, y1);
    this.ctx.lineTo(x2, y2);
    this.ctx.stroke();
  }

  drawImage(
    image: CanvasImageSource,
    x: number,
    y: number,
    width?: number,
    height?: number,
    sx?: number,
    sy?: number,
    sw?: number,
    sh?: number
  ): void {
    if (
      sx !== undefined &&
      sy !== undefined &&
      sw !== undefined &&
      sh !== undefined &&
      width !== undefined &&
      height !== undefined
    ) {
      this.ctx.drawImage(image, sx, sy, sw, sh, x, y, width, height);
    } else if (width !== undefined && height !== undefined) {
      this.ctx.drawImage(image, x, y, width, height);
    } else {
      this.ctx.drawImage(image, x, y);
    }
  }

  drawText(text: string, x: number, y: number, fontSize = 12, fontFamily = 'monospace'): void {
    this.ctx.font = `${fontSize}px ${fontFamily}`;
    this.ctx.fillText(text, x, y);
  }

  drawTextOutlined(
    text: string,
    x: number,
    y: number,
    fontSize = 12,
    fontFamily = 'monospace',
    outlineWidth = 1
  ): void {
    this.ctx.font = `${fontSize}px ${fontFamily}`;
    this.ctx.lineWidth = outlineWidth;
    this.ctx.strokeText(text, x, y);
    this.ctx.fillText(text, x, y);
  }

  measureText(text: string, fontSize = 12, fontFamily = 'monospace'): number {
    this.ctx.font = `${fontSize}px ${fontFamily}`;
    return this.ctx.measureText(text).width;
  }

  drawFullscreen(): void {
    this.ctx.fillRect(this.viewport.x, this.viewport.y, this.viewport.width, this.viewport.height);
  }

  getDimensions(): { width: number; height: number } {
    return { width: this.width, height: this.height };
  }

  resize(width: number, height: number): void {
    this.width = width;
    this.height = height;
    this.canvas.width = width;
    this.canvas.height = height;

    // Update viewport to match new size if using full canvas
    if (!this.useViewport) {
      this.viewport = { x: 0, y: 0, width, height };
    }
  }

  getCanvas(): HTMLCanvasElement {
    return this.canvas;
  }

  getContext(): CanvasRenderingContext2D {
    return this.ctx;
  }

  // ============================================================================
  // Screen Shake Effect
  // ============================================================================

  /**
   * Trigger a screen shake effect
   * @param intensity - Maximum pixel offset
   * @param duration - Duration in seconds
   * @param decay - How quickly the shake fades (0-1)
   */
  shake(intensity: number, duration: number, decay = 0.9): void {
    // If there's already a shake, use the stronger one
    if (this.screenShake && this.screenShake.intensity > intensity) {
      return;
    }
    this.screenShake = {
      intensity,
      duration,
      decay,
      currentTime: 0,
    };
  }

  /**
   * Update screen shake (call once per frame)
   */
  updateScreenShake(dt: number): void {
    if (!this.screenShake) {
      this.shakeOffsetX = 0;
      this.shakeOffsetY = 0;
      return;
    }

    this.screenShake.currentTime += dt;

    if (this.screenShake.currentTime >= this.screenShake.duration) {
      this.screenShake = null;
      this.shakeOffsetX = 0;
      this.shakeOffsetY = 0;
      return;
    }

    // Calculate remaining intensity
    const progress = this.screenShake.currentTime / this.screenShake.duration;
    const currentIntensity = this.screenShake.intensity * (1 - progress) * this.screenShake.decay;

    // Random offset
    this.shakeOffsetX = (Math.random() - 0.5) * 2 * currentIntensity;
    this.shakeOffsetY = (Math.random() - 0.5) * 2 * currentIntensity;
  }

  /**
   * Get current shake offset for applying to camera
   */
  getShakeOffset(): { x: number; y: number } {
    return { x: this.shakeOffsetX, y: this.shakeOffsetY };
  }

  // ============================================================================
  // Glow and Lighting Effects
  // ============================================================================

  /**
   * Draw a radial glow effect using a gradient
   */
  drawGlow(
    x: number,
    y: number,
    radius: number,
    color: { r: number; g: number; b: number; a?: number }
  ): void {
    const gradient = this.ctx.createRadialGradient(x, y, 0, x, y, radius);
    const alpha = color.a ?? 1;
    gradient.addColorStop(
      0,
      `rgba(${color.r * 255}, ${color.g * 255}, ${color.b * 255}, ${alpha})`
    );
    gradient.addColorStop(
      0.5,
      `rgba(${color.r * 255}, ${color.g * 255}, ${color.b * 255}, ${alpha * 0.3})`
    );
    gradient.addColorStop(1, `rgba(${color.r * 255}, ${color.g * 255}, ${color.b * 255}, 0)`);

    this.ctx.fillStyle = gradient;
    this.ctx.fillRect(x - radius, y - radius, radius * 2, radius * 2);
  }

  /**
   * Draw a shadow/darkness effect
   */
  drawShadow(x: number, y: number, radius: number, darkness = 0.5): void {
    const gradient = this.ctx.createRadialGradient(x, y, 0, x, y, radius);
    gradient.addColorStop(0, `rgba(0, 0, 0, ${darkness})`);
    gradient.addColorStop(1, 'rgba(0, 0, 0, 0)');

    this.ctx.fillStyle = gradient;
    this.ctx.fillRect(x - radius, y - radius, radius * 2, radius * 2);
  }

  /**
   * Draw a light source with flicker effect
   */
  drawLight(
    x: number,
    y: number,
    radius: number,
    color: { r: number; g: number; b: number },
    intensity = 1,
    flicker = 0
  ): void {
    const flickerAmount = flicker > 0 ? (Math.random() - 0.5) * flicker : 0;
    const currentIntensity = Math.max(0, intensity + flickerAmount);

    const gradient = this.ctx.createRadialGradient(x, y, 0, x, y, radius);
    gradient.addColorStop(
      0,
      `rgba(${color.r * 255}, ${color.g * 255}, ${color.b * 255}, ${currentIntensity})`
    );
    gradient.addColorStop(
      0.4,
      `rgba(${color.r * 255}, ${color.g * 255}, ${color.b * 255}, ${currentIntensity * 0.3})`
    );
    gradient.addColorStop(1, 'rgba(0, 0, 0, 0)');

    this.ctx.globalCompositeOperation = 'screen';
    this.ctx.fillStyle = gradient;
    this.ctx.fillRect(x - radius, y - radius, radius * 2, radius * 2);
    this.ctx.globalCompositeOperation = 'source-over';
  }

  /**
   * Draw a trail effect (semi-transparent fading line)
   */
  drawTrail(
    points: { x: number; y: number }[],
    color: { r: number; g: number; b: number; a: number },
    width: number
  ): void {
    if (points.length < 2) return;

    this.ctx.beginPath();
    this.ctx.moveTo(points[0]?.x ?? 0, points[0]?.y ?? 0);

    for (let i = 1; i < points.length; i++) {
      const point = points[i];
      if (point) {
        this.ctx.lineTo(point.x, point.y);
      }
    }

    this.ctx.strokeStyle = `rgba(${color.r * 255}, ${color.g * 255}, ${color.b * 255}, ${color.a})`;
    this.ctx.lineWidth = width;
    this.ctx.lineCap = 'round';
    this.ctx.lineJoin = 'round';
    this.ctx.stroke();
  }

  /**
   * Clean up renderer resources
   */
  destroy(): void {
    this.canvas.remove();
  }

  // ============================================================================
  // Private Methods
  // ============================================================================

  private applyTransform(): void {
    if (!this.batchActive) return;

    this.ctx.setTransform(
      this.currentScale.x,
      0,
      0,
      this.currentScale.y,
      this.currentTranslation.x,
      this.currentTranslation.y
    );

    if (this.currentRotation !== 0) {
      this.ctx.rotate(this.currentRotation);
    }
  }

  private applyViewport(): void {
    this.ctx.save();
    this.ctx.beginPath();
    this.ctx.rect(this.viewport.x, this.viewport.y, this.viewport.width, this.viewport.height);
    this.ctx.clip();
  }
}
