/**
 * Particle System
 *
 * Provides visual effects for explosions, muzzle flashes,
 * blood splatter, and other game events.
 */

import type { Renderer } from './Renderer';
import type { Color } from '../types';

export interface Particle {
  x: number;
  y: number;
  vx: number;
  vy: number;
  life: number;
  maxLife: number;
  size: number;
  startSize: number;
  endSize: number;
  color: Color;
  alpha: number;
  rotation: number;
  rotationSpeed: number;
  gravity: number;
  friction: number;
  active: boolean;
}

export interface ParticleEmitterOptions {
  x: number;
  y: number;
  count: number;
  color: Color;
  minSize?: number;
  maxSize?: number;
  minSpeed?: number;
  maxSpeed?: number;
  minLife?: number;
  maxLife?: number;
  gravity?: number;
  friction?: number;
  spread?: number; // radians
  direction?: number; // radians
}

export class ParticleSystem {
  private particles: Particle[] = [];
  private maxParticles: number;
  private poolIndex = 0;

  constructor(maxParticles = 1000) {
    this.maxParticles = maxParticles;
    // Pre-allocate particle pool
    this.particles = new Array(maxParticles).fill(null).map(() => this.createEmptyParticle());
  }

  private createEmptyParticle(): Particle {
    return {
      x: 0,
      y: 0,
      vx: 0,
      vy: 0,
      life: 0,
      maxLife: 0,
      size: 0,
      startSize: 0,
      endSize: 0,
      color: { r: 1, g: 1, b: 1, a: 1 },
      alpha: 1,
      rotation: 0,
      rotationSpeed: 0,
      gravity: 0,
      friction: 1,
      active: false,
    };
  }

  /**
   * Emit explosion particles
   */
  emitExplosion(x: number, y: number, count: number, color: Color, intensity = 1): void {
    const options: ParticleEmitterOptions = {
      x,
      y,
      count: Math.floor(count * intensity),
      color,
      minSize: 2,
      maxSize: 6,
      minSpeed: 50,
      maxSpeed: 150,
      minLife: 0.3,
      maxLife: 0.8,
      gravity: 50,
      friction: 0.95,
      spread: Math.PI * 2,
    };
    this.emit(options);
  }

  /**
   * Emit muzzle flash particles
   */
  emitMuzzleFlash(x: number, y: number, angle: number, intensity = 1): void {
    const options: ParticleEmitterOptions = {
      x,
      y,
      count: Math.floor(5 * intensity),
      color: { r: 1, g: 0.8, b: 0.2, a: 1 },
      minSize: 2,
      maxSize: 4,
      minSpeed: 30,
      maxSpeed: 80,
      minLife: 0.05,
      maxLife: 0.15,
      spread: 0.5,
      direction: angle,
      friction: 0.9,
    };
    this.emit(options);
  }

  /**
   * Emit blood splatter particles
   */
  emitBloodSplatter(x: number, y: number, direction: number, intensity = 1): void {
    // Skip if intensity is 0 (gore disabled)
    if (intensity <= 0) return;

    const count = Math.floor(8 * intensity);
    const sizeMultiplier = Math.min(intensity, 2); // Cap size increase at 2x

    const options: ParticleEmitterOptions = {
      x,
      y,
      count,
      color: { r: 0.8, g: 0.1, b: 0.1, a: 1 },
      minSize: 2 * sizeMultiplier,
      maxSize: 5 * sizeMultiplier,
      minSpeed: 20,
      maxSpeed: 100,
      minLife: 0.5,
      maxLife: 1.2,
      gravity: 100,
      spread: Math.PI / 3,
      direction,
      friction: 0.92,
    };
    this.emit(options);
  }

  /**
   * Emit sparkle particles for powerups/bonuses
   */
  emitSparkle(x: number, y: number, count = 6, color?: Color): void {
    const sparkleColor = color ?? { r: 1, g: 1, b: 0.5, a: 1 };
    const options: ParticleEmitterOptions = {
      x,
      y,
      count,
      color: sparkleColor,
      minSize: 1,
      maxSize: 3,
      minSpeed: 10,
      maxSpeed: 40,
      minLife: 0.3,
      maxLife: 0.6,
      spread: Math.PI * 2,
      friction: 0.98,
    };
    this.emit(options);
  }

  /**
   * Emit smoke particles
   */
  emitSmoke(x: number, y: number, count: number, intensity = 1): void {
    const options: ParticleEmitterOptions = {
      x,
      y,
      count: Math.floor(count * intensity),
      color: { r: 0.5, g: 0.5, b: 0.5, a: 0.6 },
      minSize: 4,
      maxSize: 12,
      minSpeed: 10,
      maxSpeed: 30,
      minLife: 0.5,
      maxLife: 1.5,
      gravity: -20, // Rise up
      spread: Math.PI / 2,
      friction: 0.97,
    };
    this.emit(options);
  }

  /**
   * Emit trail particles for projectiles
   */
  emitTrail(x: number, y: number, color: Color, size = 2): void {
    // Only emit occasionally to save particles
    if (Math.random() > 0.3) return;

    const options: ParticleEmitterOptions = {
      x: x + (Math.random() - 0.5) * 4,
      y: y + (Math.random() - 0.5) * 4,
      count: 1,
      color,
      minSize: size * 0.5,
      maxSize: size,
      minSpeed: 0,
      maxSpeed: 5,
      minLife: 0.1,
      maxLife: 0.3,
      spread: Math.PI * 2,
      friction: 0.95,
    };
    this.emit(options);
  }

  /**
   * Generic emit function
   */
  emit(options: ParticleEmitterOptions): void {
    const {
      x,
      y,
      count,
      color,
      minSize = 2,
      maxSize = 4,
      minSpeed = 20,
      maxSpeed = 50,
      minLife = 0.5,
      maxLife = 1.0,
      gravity = 0,
      friction = 1,
      spread = Math.PI * 2,
      direction = 0,
    } = options;

    for (let i = 0; i < count; i++) {
      const particle = this.getNextParticle();
      if (!particle) break;

      const angle = direction - spread / 2 + Math.random() * spread;
      const speed = minSpeed + Math.random() * (maxSpeed - minSpeed);

      particle.x = x;
      particle.y = y;
      particle.vx = Math.cos(angle) * speed;
      particle.vy = Math.sin(angle) * speed;
      particle.life = minLife + Math.random() * (maxLife - minLife);
      particle.maxLife = particle.life;
      particle.startSize = minSize + Math.random() * (maxSize - minSize);
      particle.endSize = particle.startSize * 0.2;
      particle.size = particle.startSize;
      particle.color = { ...color };
      particle.alpha = color.a ?? 1;
      particle.rotation = Math.random() * Math.PI * 2;
      particle.rotationSpeed = (Math.random() - 0.5) * 5;
      particle.gravity = gravity;
      particle.friction = friction;
      particle.active = true;
    }
  }

  private getNextParticle(): Particle | null {
    // Find an inactive particle
    for (let i = 0; i < this.maxParticles; i++) {
      const index = (this.poolIndex + i) % this.maxParticles;
      const particle = this.particles[index];
      if (!particle?.active) {
        this.poolIndex = (index + 1) % this.maxParticles;
        return particle ?? null;
      }
    }
    // Pool exhausted - reuse oldest particle
    const oldest = this.particles[this.poolIndex];
    this.poolIndex = (this.poolIndex + 1) % this.maxParticles;
    return oldest ?? null;
  }

  /**
   * Update all particles
   */
  update(dt: number): void {
    for (const particle of this.particles) {
      if (!particle.active) continue;

      // Update physics
      particle.vx *= particle.friction;
      particle.vy *= particle.friction;
      particle.vy += particle.gravity * dt;
      particle.x += particle.vx * dt;
      particle.y += particle.vy * dt;

      // Update rotation
      particle.rotation += particle.rotationSpeed * dt;

      // Update life
      particle.life -= dt;

      // Update size and alpha based on life
      const lifeRatio = particle.life / particle.maxLife;
      particle.size = particle.endSize + (particle.startSize - particle.endSize) * lifeRatio;
      particle.alpha = lifeRatio * particle.color.a;

      // Deactivate dead particles
      if (particle.life <= 0) {
        particle.active = false;
      }
    }
  }

  /**
   * Render all particles
   */
  render(renderer: Renderer): void {
    for (const particle of this.particles) {
      if (!particle.active) continue;

      renderer.setColor(
        particle.color.r,
        particle.color.g,
        particle.color.b,
        particle.alpha
      );

      // Draw particle as a small rectangle or circle
      if (particle.size < 3) {
        renderer.drawRect(
          particle.x - particle.size / 2,
          particle.y - particle.size / 2,
          particle.size,
          particle.size
        );
      } else {
        renderer.drawCircle(particle.x, particle.y, particle.size / 2);
      }
    }
  }

  /**
   * Clear all particles
   */
  clear(): void {
    for (const particle of this.particles) {
      particle.active = false;
    }
  }

  /**
   * Get active particle count
   */
  getActiveCount(): number {
    return this.particles.filter((p) => p.active).length;
  }
}
