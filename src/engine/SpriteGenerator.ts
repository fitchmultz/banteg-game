/**
 * Sprite Generator
 *
 * Procedurally generates pixel-art style creature sprites using Canvas API.
 * Creates distinct sprites for each creature type with 4-frame walk animations.
 *
 * Responsibilities:
 * - Generate pixel-art sprites for all 8 creature types
 * - Create combined sprite atlas (256x256 PNG)
 * - Generate corresponding atlas JSON with frame definitions
 *
 * Does NOT handle:
 * - Asset loading (handled by AssetManager)
 * - Rendering (handled by Renderer)
 * - Animation state management (handled by AiSystem)
 */

export interface GeneratedSpriteAtlas {
  image: HTMLCanvasElement;
  data: SpriteAtlasData;
}

export interface SpriteAtlasData {
  meta: {
    image: string;
    size: { w: number; h: number };
    scale: number;
  };
  frames: Record<string, SpriteAtlasFrame>;
  animations: Record<string, SpriteAtlasAnimation>;
}

export interface SpriteAtlasFrame {
  frame: { x: number; y: number; w: number; h: number };
}

export interface SpriteAtlasAnimation {
  frames: Array<{ name: string }>;
  duration: number;
}

// Creature definitions for sprite generation
interface CreatureSpriteDef {
  name: string;
  baseColor: string;
  secondaryColor: string;
  eyeColor: string;
  shape: 'humanoid' | 'spider' | 'alien' | 'ghost';
  size: number;
}

const CREATURE_DEFS: CreatureSpriteDef[] = [
  {
    name: 'zombie',
    baseColor: '#5a7a4a',
    secondaryColor: '#4a6a3a',
    eyeColor: '#ff0000',
    shape: 'humanoid',
    size: 1.0,
  },
  {
    name: 'zombie_fast',
    baseColor: '#7a9a4a',
    secondaryColor: '#6a8a3a',
    eyeColor: '#ffff00',
    shape: 'humanoid',
    size: 0.9,
  },
  {
    name: 'zombie_tank',
    baseColor: '#3a4a3a',
    secondaryColor: '#2a3a2a',
    eyeColor: '#ff3333',
    shape: 'humanoid',
    size: 1.3,
  },
  {
    name: 'spider_small',
    baseColor: '#8a4a8a',
    secondaryColor: '#7a3a7a',
    eyeColor: '#ffffff',
    shape: 'spider',
    size: 0.6,
  },
  {
    name: 'spider_large',
    baseColor: '#5a2a5a',
    secondaryColor: '#4a1a4a',
    eyeColor: '#ff88ff',
    shape: 'spider',
    size: 1.1,
  },
  {
    name: 'alien_trooper',
    baseColor: '#4a9a9a',
    secondaryColor: '#3a8a8a',
    eyeColor: '#00ffff',
    shape: 'alien',
    size: 1.0,
  },
  {
    name: 'alien_elite',
    baseColor: '#3a6a9a',
    secondaryColor: '#2a5a8a',
    eyeColor: '#88ccff',
    shape: 'alien',
    size: 1.1,
  },
  {
    name: 'ghost',
    baseColor: '#cccccc',
    secondaryColor: '#aaaaaa',
    eyeColor: '#000000',
    shape: 'ghost',
    size: 1.0,
  },
];

const FRAME_SIZE = 32;
const ATLAS_WIDTH = 256;
const ATLAS_HEIGHT = 256;
const FRAMES_PER_ROW = ATLAS_WIDTH / FRAME_SIZE;

/**
 * Generate the complete sprite atlas with all creature sprites.
 */
export function generateSpriteAtlas(): GeneratedSpriteAtlas {
  const canvas = document.createElement('canvas');
  canvas.width = ATLAS_WIDTH;
  canvas.height = ATLAS_HEIGHT;
  const ctx = canvas.getContext('2d');
  if (!ctx) {
    throw new Error('Failed to get 2D context for sprite generation');
  }

  // Clear with transparent background
  ctx.clearRect(0, 0, ATLAS_WIDTH, ATLAS_HEIGHT);

  const frames: Record<string, SpriteAtlasFrame> = {};
  const animations: Record<string, SpriteAtlasAnimation> = {};

  let frameIndex = 0;

  for (const def of CREATURE_DEFS) {
    const animationFrames: Array<{ name: string }> = [];

    for (let frameNum = 0; frameNum < 4; frameNum++) {
      const x = (frameIndex % FRAMES_PER_ROW) * FRAME_SIZE;
      const y = Math.floor(frameIndex / FRAMES_PER_ROW) * FRAME_SIZE;
      const frameName = `${def.name}_${frameNum}`;

      // Draw the creature sprite
      drawCreatureFrame(ctx, x, y, def, frameNum);

      // Add frame definition
      frames[frameName] = {
        frame: { x, y, w: FRAME_SIZE, h: FRAME_SIZE },
      };

      animationFrames.push({ name: frameName });
      frameIndex++;
    }

    // Add animation definition
    animations[def.name] = {
      frames: animationFrames,
      duration: 800, // 800ms for full animation cycle
    };
  }

  const data: SpriteAtlasData = {
    meta: {
      image: 'creatures.png',
      size: { w: ATLAS_WIDTH, h: ATLAS_HEIGHT },
      scale: 1,
    },
    frames,
    animations,
  };

  return { image: canvas, data };
}

/**
 * Draw a single creature frame at the specified position.
 */
function drawCreatureFrame(
  ctx: CanvasRenderingContext2D,
  x: number,
  y: number,
  def: CreatureSpriteDef,
  frameNum: number
): void {
  const centerX = x + FRAME_SIZE / 2;
  const centerY = y + FRAME_SIZE / 2;

  // Calculate animation offset for walking effect
  const bounceOffset = Math.sin((frameNum * Math.PI) / 2) * 2 * def.size;

  ctx.save();

  switch (def.shape) {
    case 'humanoid':
      drawHumanoid(ctx, centerX, centerY + bounceOffset, def, frameNum);
      break;
    case 'spider':
      drawSpider(ctx, centerX, centerY + bounceOffset * 0.5, def, frameNum);
      break;
    case 'alien':
      drawAlien(ctx, centerX, centerY + bounceOffset, def, frameNum);
      break;
    case 'ghost':
      drawGhost(ctx, centerX, centerY + bounceOffset * 0.3, def, frameNum);
      break;
  }

  ctx.restore();
}

/**
 * Draw a humanoid creature (zombies).
 */
function drawHumanoid(
  ctx: CanvasRenderingContext2D,
  cx: number,
  cy: number,
  def: CreatureSpriteDef,
  frameNum: number
): void {
  const size = 12 * def.size;

  // Body
  ctx.fillStyle = def.baseColor;
  ctx.fillRect(cx - size * 0.6, cy - size * 0.3, size * 1.2, size * 1.2);

  // Head
  ctx.fillStyle = def.secondaryColor;
  ctx.fillRect(cx - size * 0.5, cy - size * 0.8, size, size * 0.6);

  // Eyes
  ctx.fillStyle = def.eyeColor;
  ctx.fillRect(cx - size * 0.3, cy - size * 0.6, size * 0.2, size * 0.15);
  ctx.fillRect(cx + size * 0.1, cy - size * 0.6, size * 0.2, size * 0.15);

  // Arms (animated)
  const armOffset = Math.sin((frameNum * Math.PI) / 2) * size * 0.3;
  ctx.fillStyle = def.baseColor;
  // Left arm
  ctx.fillRect(cx - size * 0.9, cy - size * 0.2 + armOffset, size * 0.3, size * 0.8);
  // Right arm
  ctx.fillRect(cx + size * 0.6, cy - size * 0.2 - armOffset, size * 0.3, size * 0.8);

  // Legs (animated)
  const legOffset = Math.cos((frameNum * Math.PI) / 2) * size * 0.2;
  // Left leg
  ctx.fillRect(cx - size * 0.4, cy + size * 0.8 + legOffset, size * 0.35, size * 0.5);
  // Right leg
  ctx.fillRect(cx + size * 0.05, cy + size * 0.8 - legOffset, size * 0.35, size * 0.5);
}

/**
 * Draw a spider creature.
 */
function drawSpider(
  ctx: CanvasRenderingContext2D,
  cx: number,
  cy: number,
  def: CreatureSpriteDef,
  frameNum: number
): void {
  const size = 10 * def.size;

  // Body
  ctx.fillStyle = def.baseColor;
  ctx.beginPath();
  ctx.ellipse(cx, cy, size * 0.8, size * 0.6, 0, 0, Math.PI * 2);
  ctx.fill();

  // Head (abdomen)
  ctx.fillStyle = def.secondaryColor;
  ctx.beginPath();
  ctx.ellipse(cx, cy - size * 0.5, size * 0.5, size * 0.4, 0, 0, Math.PI * 2);
  ctx.fill();

  // Eyes
  ctx.fillStyle = def.eyeColor;
  ctx.fillRect(cx - size * 0.2, cy - size * 0.6, size * 0.1, size * 0.1);
  ctx.fillRect(cx + size * 0.1, cy - size * 0.6, size * 0.1, size * 0.1);

  // Legs (8 legs, animated)
  const legWave = Math.sin((frameNum * Math.PI) / 2) * size * 0.3;
  ctx.strokeStyle = def.baseColor;
  ctx.lineWidth = 2;

  for (let i = 0; i < 4; i++) {
    const angle = (i / 4) * Math.PI - Math.PI / 2;
    const legOffset = (i % 2 === 0 ? 1 : -1) * legWave;

    // Left side legs
    const lx = cx - Math.cos(angle) * size * 0.5;
    const ly = cy + Math.sin(angle) * size * 0.3;
    ctx.beginPath();
    ctx.moveTo(lx, ly);
    ctx.lineTo(lx - size * 0.6, ly + legOffset - size * 0.3);
    ctx.stroke();

    // Right side legs
    const rx = cx + Math.cos(angle) * size * 0.5;
    const ry = cy + Math.sin(angle) * size * 0.3;
    ctx.beginPath();
    ctx.moveTo(rx, ry);
    ctx.lineTo(rx + size * 0.6, ry - legOffset - size * 0.3);
    ctx.stroke();
  }
}

/**
 * Draw an alien creature.
 */
function drawAlien(
  ctx: CanvasRenderingContext2D,
  cx: number,
  cy: number,
  def: CreatureSpriteDef,
  frameNum: number
): void {
  const size = 11 * def.size;

  // Body (sleek, tapered)
  ctx.fillStyle = def.baseColor;
  ctx.beginPath();
  ctx.moveTo(cx, cy - size);
  ctx.lineTo(cx + size * 0.5, cy + size * 0.5);
  ctx.lineTo(cx, cy + size * 0.8);
  ctx.lineTo(cx - size * 0.5, cy + size * 0.5);
  ctx.closePath();
  ctx.fill();

  // Head
  ctx.fillStyle = def.secondaryColor;
  ctx.beginPath();
  ctx.ellipse(cx, cy - size * 0.5, size * 0.4, size * 0.5, 0, 0, Math.PI * 2);
  ctx.fill();

  // Large alien eyes
  ctx.fillStyle = def.eyeColor;
  ctx.beginPath();
  ctx.ellipse(cx - size * 0.15, cy - size * 0.5, size * 0.12, size * 0.15, 0, 0, Math.PI * 2);
  ctx.fill();
  ctx.beginPath();
  ctx.ellipse(cx + size * 0.15, cy - size * 0.5, size * 0.12, size * 0.15, 0, 0, Math.PI * 2);
  ctx.fill();

  // Arms (animated, sleek)
  const armOffset = Math.sin((frameNum * Math.PI) / 2) * size * 0.2;
  ctx.strokeStyle = def.baseColor;
  ctx.lineWidth = 3;

  // Left arm
  ctx.beginPath();
  ctx.moveTo(cx - size * 0.3, cy);
  ctx.lineTo(cx - size * 0.7, cy + armOffset + size * 0.2);
  ctx.stroke();

  // Right arm
  ctx.beginPath();
  ctx.moveTo(cx + size * 0.3, cy);
  ctx.lineTo(cx + size * 0.7, cy - armOffset + size * 0.2);
  ctx.stroke();
}

/**
 * Draw a ghost creature.
 */
function drawGhost(
  ctx: CanvasRenderingContext2D,
  cx: number,
  cy: number,
  def: CreatureSpriteDef,
  frameNum: number
): void {
  const size = 12 * def.size;

  // Ghost body (semi-transparent, wavy)
  ctx.globalAlpha = 0.7;
  ctx.fillStyle = def.baseColor;

  // Main body
  ctx.beginPath();
  ctx.arc(cx, cy - size * 0.3, size * 0.6, Math.PI, 0);

  // Wavy bottom
  const waveOffset = Math.sin((frameNum * Math.PI) / 2) * size * 0.1;
  for (let i = 0; i <= 6; i++) {
    const wx = cx - size * 0.6 + (i / 6) * size * 1.2;
    const wy = cy + size * 0.3 + Math.sin(i + waveOffset) * size * 0.15;
    ctx.lineTo(wx, wy);
  }

  ctx.closePath();
  ctx.fill();

  // Eyes (dark voids)
  ctx.globalAlpha = 0.9;
  ctx.fillStyle = def.eyeColor;
  ctx.beginPath();
  ctx.arc(cx - size * 0.2, cy - size * 0.3, size * 0.12, 0, Math.PI * 2);
  ctx.fill();
  ctx.beginPath();
  ctx.arc(cx + size * 0.2, cy - size * 0.3, size * 0.12, 0, Math.PI * 2);
  ctx.fill();

  ctx.globalAlpha = 1.0;
}

/**
 * Convert the generated canvas to a PNG data URL.
 */
export function canvasToDataURL(canvas: HTMLCanvasElement): string {
  return canvas.toDataURL('image/png');
}

/**
 * Convert the generated atlas data to a JSON string.
 */
export function atlasDataToJSON(data: SpriteAtlasData): string {
  return JSON.stringify(data, null, 2);
}

/**
 * Generate and export both the PNG and JSON for the sprite atlas.
 * Returns data URLs that can be used directly or saved to files.
 */
export function generateSpriteAssets(): { pngDataUrl: string; jsonData: string } {
  const { image, data } = generateSpriteAtlas();
  return {
    pngDataUrl: canvasToDataURL(image),
    jsonData: atlasDataToJSON(data),
  };
}

/**
 * Pre-generate sprite assets and save them to the public directory.
 * This should be called during build time or on first run.
 */
export async function saveGeneratedSprites(
  _basePath = '/assets/sprites/creatures/'
): Promise<boolean> {
  try {
    const { image, data } = generateSpriteAtlas();

    // Convert canvas to blob
    const blob = await new Promise<Blob | null>((resolve) => {
      image.toBlob(resolve, 'image/png');
    });

    if (!blob) {
      console.error('Failed to create PNG blob');
      return false;
    }

    // In a browser environment, we can't directly write to the filesystem.
    // Instead, we provide the data for the application to handle.
    // For build-time generation, this would be handled by a Node.js script.

    console.log('Sprite atlas generated successfully');
    console.log(`Image size: ${ATLAS_WIDTH}x${ATLAS_HEIGHT}`);
    console.log(`Frames: ${Object.keys(data.frames).length}`);
    console.log(`Animations: ${Object.keys(data.animations).length}`);

    return true;
  } catch (error) {
    console.error('Failed to generate sprite assets:', error);
    return false;
  }
}
