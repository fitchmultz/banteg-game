/**
 * Engine module
 *
 * Provides core engine systems: rendering, input, audio, asset management.
 * Replacement for grim.dll functionality.
 */

export { Renderer, type RendererOptions } from './Renderer';
export { InputManager, KeyCode, type KeyCodeType } from './input/InputManager';
export { AudioManager, type AudioManagerOptions } from './AudioManager';
export {
  AssetManager,
  type AssetManagerOptions,
  type AssetLoadResult,
  type AssetType,
} from './AssetManager';
export {
  SpriteAtlas,
  SpriteAnimator,
  type SpriteFrame,
  type SpriteAnimation,
  type SpriteAtlasData,
  type SpriteAtlasFrame,
  type SpriteAtlasAnimation,
} from './SpriteAtlas';
export { ParticleSystem, type Particle, type ParticleEmitterOptions } from './ParticleSystem';
export {
  generateSpriteAtlas,
  generateSpriteAssets,
  canvasToDataURL,
  atlasDataToJSON,
  saveGeneratedSprites,
  type GeneratedSpriteAtlas,
} from './SpriteGenerator';
export {
  TerrainGenerator,
  generateTerrainTexture,
  createTerrainPattern,
  type TerrainTheme,
  DEFAULT_TERRAIN_THEME,
} from './TerrainGenerator';
