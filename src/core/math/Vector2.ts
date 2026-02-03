/**
 * 2D Vector math utilities
 */

import type { Vector2 as IVector2 } from '../../types';

export class Vector2 implements IVector2 {
  constructor(
    public x = 0,
    public y = 0
  ) {}

  static from(v: IVector2): Vector2 {
    return new Vector2(v.x, v.y);
  }

  static zero(): Vector2 {
    return new Vector2(0, 0);
  }

  static fromAngle(angle: number): Vector2 {
    return new Vector2(Math.cos(angle), Math.sin(angle));
  }

  static add(a: IVector2, b: IVector2): Vector2 {
    return new Vector2(a.x + b.x, a.y + b.y);
  }

  static sub(a: IVector2, b: IVector2): Vector2 {
    return new Vector2(a.x - b.x, a.y - b.y);
  }

  static scale(v: IVector2, s: number): Vector2 {
    return new Vector2(v.x * s, v.y * s);
  }

  static dot(a: IVector2, b: IVector2): number {
    return a.x * b.x + a.y * b.y;
  }

  static distance(a: IVector2, b: IVector2): number {
    const dx = a.x - b.x;
    const dy = a.y - b.y;
    return Math.sqrt(dx * dx + dy * dy);
  }

  static distanceSq(a: IVector2, b: IVector2): number {
    const dx = a.x - b.x;
    const dy = a.y - b.y;
    return dx * dx + dy * dy;
  }

  static lerp(a: IVector2, b: IVector2, t: number): Vector2 {
    return new Vector2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t);
  }

  static normalize(v: IVector2): Vector2 {
    const len = Math.sqrt(v.x * v.x + v.y * v.y);
    if (len === 0) {
      return new Vector2(0, 0);
    }
    return new Vector2(v.x / len, v.y / len);
  }

  static length(v: IVector2): number {
    return Math.sqrt(v.x * v.x + v.y * v.y);
  }

  static lengthSq(v: IVector2): number {
    return v.x * v.x + v.y * v.y;
  }

  add(v: IVector2): this {
    this.x += v.x;
    this.y += v.y;
    return this;
  }

  sub(v: IVector2): this {
    this.x -= v.x;
    this.y -= v.y;
    return this;
  }

  scale(s: number): this {
    this.x *= s;
    this.y *= s;
    return this;
  }

  normalize(): this {
    const len = Math.sqrt(this.x * this.x + this.y * this.y);
    if (len > 0) {
      this.x /= len;
      this.y /= len;
    }
    return this;
  }

  length(): number {
    return Math.sqrt(this.x * this.x + this.y * this.y);
  }

  lengthSq(): number {
    return this.x * this.x + this.y * this.y;
  }

  copy(): Vector2 {
    return new Vector2(this.x, this.y);
  }

  toObject(): IVector2 {
    return { x: this.x, y: this.y };
  }
}
