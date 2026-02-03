/**
 * Rectangle geometry utilities
 */

import type { Rectangle as IRectangle, Vector2 as IVector2 } from '../../types';

export class Rectangle implements IRectangle {
  constructor(
    public x = 0,
    public y = 0,
    public width = 0,
    public height = 0
  ) {}

  static from(r: IRectangle): Rectangle {
    return new Rectangle(r.x, r.y, r.width, r.height);
  }

  static fromCenter(center: IVector2, width: number, height: number): Rectangle {
    return new Rectangle(center.x - width / 2, center.y - height / 2, width, height);
  }

  static contains(r: IRectangle, p: IVector2): boolean {
    return p.x >= r.x && p.x < r.x + r.width && p.y >= r.y && p.y < r.y + r.height;
  }

  static intersects(a: IRectangle, b: IRectangle): boolean {
    return (
      a.x < b.x + b.width && a.x + a.width > b.x && a.y < b.y + b.height && a.y + a.height > b.y
    );
  }

  static center(r: IRectangle): { x: number; y: number } {
    return {
      x: r.x + r.width / 2,
      y: r.y + r.height / 2,
    };
  }

  get left(): number {
    return this.x;
  }

  get right(): number {
    return this.x + this.width;
  }

  get top(): number {
    return this.y;
  }

  get bottom(): number {
    return this.y + this.height;
  }

  get centerX(): number {
    return this.x + this.width / 2;
  }

  get centerY(): number {
    return this.y + this.height / 2;
  }

  contains(x: number, y: number): boolean {
    return x >= this.x && x < this.right && y >= this.y && y < this.bottom;
  }

  intersects(other: IRectangle): boolean {
    return Rectangle.intersects(this, other);
  }

  copy(): Rectangle {
    return new Rectangle(this.x, this.y, this.width, this.height);
  }

  toObject(): IRectangle {
    return { x: this.x, y: this.y, width: this.width, height: this.height };
  }
}
