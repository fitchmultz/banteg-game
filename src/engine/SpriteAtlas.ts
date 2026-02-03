/**
 * Sprite Atlas
 *
 * Manages sprite atlas data for efficient texture packing.
 * Supports JSON-based atlas definitions with UV coordinate calculations.
 */

export interface SpriteFrame {
  /** Frame name/identifier */
  name: string;
  /** X position in the atlas (pixels) */
  x: number;
  /** Y position in the atlas (pixels) */
  y: number;
  /** Width of the frame (pixels) */
  width: number;
  /** Height of the frame (pixels) */
  height: number;
  /** UV coordinates (0-1 range) */
  uv: {
    u0: number;
    v0: number;
    u1: number;
    v1: number;
  };
  /** Pivot point (0-1 range, defaults to 0.5, 0.5) */
  pivot?: { x: number; y: number };
  /** Source size before trimming */
  sourceSize?: { width: number; height: number };
  /** Trimmed sprite offset */
  spriteSourceSize?: { x: number; y: number };
}

export interface SpriteAnimation {
  /** Animation name */
  name: string;
  /** Frame names in order */
  frames: string[];
  /** Frame duration in seconds */
  frameDuration: number;
  /** Whether to loop */
  loop: boolean;
}

export interface SpriteAtlasData {
  /** Atlas metadata */
  meta: {
    image: string;
    size: { w: number; h: number };
    scale: number;
  };
  /** Frame definitions */
  frames: Record<string, SpriteAtlasFrame>;
  /** Animation definitions */
  animations?: Record<string, SpriteAtlasAnimation>;
}

export interface SpriteAtlasFrame {
  frame: { x: number; y: number; w: number; h: number };
  rotated?: boolean;
  trimmed?: boolean;
  spriteSourceSize?: { x: number; y: number; w: number; h: number };
  sourceSize?: { w: number; h: number };
  pivot?: { x: number; y: number };
}

export interface SpriteAtlasAnimation {
  frames: Array<{ name: string; duration?: number }>;
  duration?: number;
}

export class SpriteAtlas {
  private frames: Map<string, SpriteFrame> = new Map();
  private animations: Map<string, SpriteAnimation> = new Map();
  private atlasWidth = 0;
  private atlasHeight = 0;
  private imageName = '';

  /**
   * Load atlas data from a parsed JSON object
   */
  loadFromData(data: SpriteAtlasData): void {
    this.clear();

    this.atlasWidth = data.meta.size.w;
    this.atlasHeight = data.meta.size.h;
    this.imageName = data.meta.image;

    // Parse frames
    for (const [name, frameData] of Object.entries(data.frames)) {
      const frame = this.parseFrame(name, frameData);
      this.frames.set(name, frame);
    }

    // Parse animations if present
    if (data.animations) {
      for (const [name, animData] of Object.entries(data.animations)) {
        const animation = this.parseAnimation(name, animData);
        this.animations.set(name, animation);
      }
    }
  }

  /**
   * Load atlas data from a JSON file URL
   */
  async loadFromURL(url: string): Promise<void> {
    const response = await fetch(url);
    if (!response.ok) {
      throw new Error(`Failed to load sprite atlas: ${response.status} ${response.statusText}`);
    }

    const data = (await response.json()) as SpriteAtlasData;
    this.loadFromData(data);
  }

  /**
   * Get a frame by name
   */
  getFrame(name: string): SpriteFrame | undefined {
    return this.frames.get(name);
  }

  /**
   * Get an animation by name
   */
  getAnimation(name: string): SpriteAnimation | undefined {
    return this.animations.get(name);
  }

  /**
   * Check if a frame exists
   */
  hasFrame(name: string): boolean {
    return this.frames.has(name);
  }

  /**
   * Check if an animation exists
   */
  hasAnimation(name: string): boolean {
    return this.animations.has(name);
  }

  /**
   * Get all frame names
   */
  getFrameNames(): string[] {
    return Array.from(this.frames.keys());
  }

  /**
   * Get all animation names
   */
  getAnimationNames(): string[] {
    return Array.from(this.animations.keys());
  }

  /**
   * Get the atlas image name
   */
  getImageName(): string {
    return this.imageName;
  }

  /**
   * Get atlas dimensions
   */
  getDimensions(): { width: number; height: number } {
    return { width: this.atlasWidth, height: this.atlasHeight };
  }

  /**
   * Clear all data
   */
  clear(): void {
    this.frames.clear();
    this.animations.clear();
    this.atlasWidth = 0;
    this.atlasHeight = 0;
    this.imageName = '';
  }

  /**
   * Create a simple atlas from a grid layout
   */
  createFromGrid(
    imageName: string,
    atlasWidth: number,
    atlasHeight: number,
    cellWidth: number,
    cellHeight: number,
    options?: {
      spacing?: number;
      margin?: number;
      names?: string[];
    }
  ): void {
    this.clear();

    this.imageName = imageName;
    this.atlasWidth = atlasWidth;
    this.atlasHeight = atlasHeight;

    const spacing = options?.spacing ?? 0;
    const margin = options?.margin ?? 0;
    const names = options?.names;

    const cols = Math.floor((atlasWidth - margin * 2) / (cellWidth + spacing));
    const rows = Math.floor((atlasHeight - margin * 2) / (cellHeight + spacing));

    let nameIndex = 0;

    for (let row = 0; row < rows; row++) {
      for (let col = 0; col < cols; col++) {
        const x = margin + col * (cellWidth + spacing);
        const y = margin + row * (cellHeight + spacing);

        const name = names?.[nameIndex] ?? `sprite_${row}_${col}`;

        const frame: SpriteFrame = {
          name,
          x,
          y,
          width: cellWidth,
          height: cellHeight,
          uv: this.calculateUV(x, y, cellWidth, cellHeight),
          pivot: { x: 0.5, y: 0.5 },
        };

        this.frames.set(name, frame);
        nameIndex++;
      }
    }
  }

  /**
   * Get the number of frames
   */
  get frameCount(): number {
    return this.frames.size;
  }

  /**
   * Get the number of animations
   */
  get animationCount(): number {
    return this.animations.size;
  }

  private parseFrame(name: string, data: SpriteAtlasFrame): SpriteFrame {
    const { x, y, w, h } = data.frame;

    const frame: SpriteFrame = {
      name,
      x,
      y,
      width: w,
      height: h,
      uv: this.calculateUV(x, y, w, h),
      pivot: data.pivot ?? { x: 0.5, y: 0.5 },
    };

    if (data.sourceSize) {
      frame.sourceSize = { width: data.sourceSize.w, height: data.sourceSize.h };
    }

    if (data.spriteSourceSize) {
      frame.spriteSourceSize = { x: data.spriteSourceSize.x, y: data.spriteSourceSize.y };
    }

    return frame;
  }

  private parseAnimation(name: string, data: SpriteAtlasAnimation): SpriteAnimation {
    const frames = data.frames.map((f) => f.name);

    // Calculate total duration (use first frame's duration or default to 100ms per frame)
    const totalDuration =
      data.duration ??
      data.frames.reduce((sum, f) => sum + (f.duration ?? 100), 0);

    const frameDuration = totalDuration / frames.length / 1000; // Convert to seconds

    return {
      name,
      frames,
      frameDuration,
      loop: true,
    };
  }

  private calculateUV(x: number, y: number, width: number, height: number) {
    return {
      u0: x / this.atlasWidth,
      v0: y / this.atlasHeight,
      u1: (x + width) / this.atlasWidth,
      v1: (y + height) / this.atlasHeight,
    };
  }
}

/**
 * Sprite animation player for managing animation state
 */
export class SpriteAnimator {
  private currentAnimation: SpriteAnimation | null = null;
  private currentFrameIndex = 0;
  private frameTime = 0;
  private isPlaying = false;
  private isFinished = false;

  /**
   * Play an animation
   */
  play(animation: SpriteAnimation, startFrame = 0): void {
    this.currentAnimation = animation;
    this.currentFrameIndex = startFrame;
    this.frameTime = 0;
    this.isPlaying = true;
    this.isFinished = false;
  }

  /**
   * Stop the current animation
   */
  stop(): void {
    this.isPlaying = false;
  }

  /**
   * Resume the current animation
   */
  resume(): void {
    if (this.currentAnimation) {
      this.isPlaying = true;
    }
  }

  /**
   * Update animation state
   */
  update(dt: number): void {
    if (!this.isPlaying || !this.currentAnimation || this.isFinished) {
      return;
    }

    this.frameTime += dt;

    while (this.frameTime >= this.currentAnimation.frameDuration) {
      this.frameTime -= this.currentAnimation.frameDuration;
      this.currentFrameIndex++;

      if (this.currentFrameIndex >= this.currentAnimation.frames.length) {
        if (this.currentAnimation.loop) {
          this.currentFrameIndex = 0;
        } else {
          this.currentFrameIndex = this.currentAnimation.frames.length - 1;
          this.isFinished = true;
          this.isPlaying = false;
        }
      }
    }
  }

  /**
   * Get the current frame name
   */
  getCurrentFrameName(): string | null {
    if (!this.currentAnimation) return null;
    return this.currentAnimation.frames[this.currentFrameIndex] ?? null;
  }

  /**
   * Set a specific frame
   */
  setFrame(index: number): void {
    if (this.currentAnimation) {
      this.currentFrameIndex = Math.max(
        0,
        Math.min(index, this.currentAnimation.frames.length - 1)
      );
      this.frameTime = 0;
    }
  }

  /**
   * Reset to the first frame
   */
  reset(): void {
    this.currentFrameIndex = 0;
    this.frameTime = 0;
    this.isFinished = false;
  }

  /**
   * Check if animation is currently playing
   */
  get playing(): boolean {
    return this.isPlaying;
  }

  /**
   * Check if animation has finished (non-looping only)
   */
  get finished(): boolean {
    return this.isFinished;
  }

  /**
   * Get current animation progress (0-1)
   */
  get progress(): number {
    if (!this.currentAnimation) return 0;
    const totalFrames = this.currentAnimation.frames.length;
    const frameProgress = this.frameTime / this.currentAnimation.frameDuration;
    return (this.currentFrameIndex + frameProgress) / totalFrames;
  }
}
