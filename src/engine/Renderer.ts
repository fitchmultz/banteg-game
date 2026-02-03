/**
 * Canvas 2D Renderer
 * 
 * Replacement for grim.dll's Direct3D 8 rendering.
 */

import type { Vector2 } from '../types';

export interface RendererOptions {
  width: number;
  height: number;
  smoothing?: boolean;
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
  }

  clear(r: number, g: number, b: number, a = 1): void {
    this.ctx.fillStyle = `rgba(${r * 255}, ${g * 255}, ${b * 255}, ${a})`;
    this.ctx.fillRect(0, 0, this.width, this.height);
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
    if (sx !== undefined && sy !== undefined && sw !== undefined && sh !== undefined && width !== undefined && height !== undefined) {
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
    this.ctx.fillRect(0, 0, this.width, this.height);
  }

  getDimensions(): { width: number; height: number } {
    return { width: this.width, height: this.height };
  }

  resize(width: number, height: number): void {
    this.width = width;
    this.height = height;
    this.canvas.width = width;
    this.canvas.height = height;
  }

  getCanvas(): HTMLCanvasElement {
    return this.canvas;
  }

  getContext(): CanvasRenderingContext2D {
    return this.ctx;
  }

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
}
