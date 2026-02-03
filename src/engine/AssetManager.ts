/**
 * Asset Manager
 *
 * Centralized loading and caching for images, audio, and JSON assets.
 * Handles async loading with progress tracking and error handling.
 */

export interface AssetManagerOptions {
  /** Base path for all asset URLs */
  basePath?: string;
  /** Maximum concurrent loads */
  maxConcurrentLoads?: number;
}

export type AssetType = 'image' | 'audio' | 'json';

export interface AssetLoadResult {
  name: string;
  type: AssetType;
  success: boolean;
  error?: Error;
}

type Asset = HTMLImageElement | AudioBuffer | unknown;

// Type guard to check if asset is image-like
function isImageLike(asset: unknown): asset is HTMLImageElement {
  return (
    typeof asset === 'object' &&
    asset !== null &&
    'src' in asset &&
    'naturalWidth' in asset
  );
}

// Type guard to check if asset is audio-like
function isAudioLike(asset: unknown): asset is AudioBuffer {
  return typeof asset === 'object' && asset !== null && 'duration' in asset;
}

export class AssetManager {
  private assets: Map<string, Asset> = new Map();
  private loading: Map<string, Promise<Asset>> = new Map();
  private basePath: string;
  private maxConcurrentLoads: number;
  private activeLoads = 0;
  private loadQueue: Array<() => void> = [];
  private totalLoads = 0;
  private completedLoads = 0;

  constructor(options: AssetManagerOptions = {}) {
    this.basePath = options.basePath ?? '';
    this.maxConcurrentLoads = options.maxConcurrentLoads ?? 6;
  }

  /**
   * Load an image asset
   */
  async loadImage(name: string, url: string): Promise<HTMLImageElement> {
    const fullUrl = this.resolveUrl(url);

    // Return cached asset if available
    const cached = this.assets.get(name);
    if (isImageLike(cached)) {
      return cached;
    }

    // Return existing promise if already loading
    const existing = this.loading.get(name);
    if (existing) {
      return existing as Promise<HTMLImageElement>;
    }

    const loadPromise = this.queueLoad<HTMLImageElement>(() =>
      this.loadImageElement(fullUrl, name)
    );

    this.loading.set(name, loadPromise);
    return loadPromise;
  }

  /**
   * Load multiple images at once
   */
  async loadImages(images: Array<{ name: string; url: string }>): Promise<AssetLoadResult[]> {
    const promises = images.map(async ({ name, url }) => {
      try {
        await this.loadImage(name, url);
        return { name, type: 'image' as const, success: true };
      } catch (error) {
        return {
          name,
          type: 'image' as const,
          success: false,
          error: error instanceof Error ? error : new Error(String(error)),
        };
      }
    });

    return Promise.all(promises);
  }

  /**
   * Load a JSON asset
   */
  async loadJSON(name: string, url: string): Promise<unknown> {
    const fullUrl = this.resolveUrl(url);

    // Return cached asset if available
    const cached = this.assets.get(name);
    if (cached !== undefined && !isImageLike(cached) && !isAudioLike(cached)) {
      return cached;
    }

    // Return existing promise if already loading
    const existing = this.loading.get(name);
    if (existing) {
      return existing;
    }

    const loadPromise = this.queueLoad<unknown>(() => this.fetchJSON(fullUrl, name));
    this.loading.set(name, loadPromise);
    return loadPromise;
  }

  /**
   * Load multiple JSON files at once
   */
  async loadJSONFiles(files: Array<{ name: string; url: string }>): Promise<AssetLoadResult[]> {
    const promises = files.map(async ({ name, url }) => {
      try {
        await this.loadJSON(name, url);
        return { name, type: 'json' as const, success: true };
      } catch (error) {
        return {
          name,
          type: 'json' as const,
          success: false,
          error: error instanceof Error ? error : new Error(String(error)),
        };
      }
    });

    return Promise.all(promises);
  }

  /**
   * Get a loaded image by name
   */
  getImage(name: string): HTMLImageElement | undefined {
    const asset = this.assets.get(name);
    return isImageLike(asset) ? asset : undefined;
  }

  /**
   * Get a loaded JSON asset by name
   */
  getJSON<T = unknown>(name: string): T | undefined {
    const asset = this.assets.get(name);
    if (asset !== undefined && !isImageLike(asset) && !isAudioLike(asset)) {
      return asset as T;
    }
    return undefined;
  }

  /**
   * Check if an asset is loaded
   */
  hasAsset(name: string): boolean {
    return this.assets.has(name);
  }

  /**
   * Check if an asset is currently loading
   */
  isLoading(name: string): boolean {
    return this.loading.has(name);
  }

  /**
   * Unload a specific asset
   */
  unload(name: string): boolean {
    this.loading.delete(name);
    return this.assets.delete(name);
  }

  /**
   * Unload all assets
   */
  unloadAll(): void {
    this.assets.clear();
    this.loading.clear();
    this.loadQueue = [];
    this.activeLoads = 0;
    this.totalLoads = 0;
    this.completedLoads = 0;
  }

  /**
   * Get load progress (0 to 1)
   */
  get loadProgress(): number {
    if (this.totalLoads === 0) return 1;
    return this.completedLoads / this.totalLoads;
  }

  /**
   * Get number of loaded assets
   */
  get loadedCount(): number {
    return this.assets.size;
  }

  /**
   * Get total number of assets (loaded + loading)
   */
  get totalCount(): number {
    return this.assets.size + this.loading.size;
  }

  /**
   * Create a blob URL from raw data (useful for generated assets)
   */
  createBlobURL(data: BlobPart, type: string): string {
    const blob = new Blob([data], { type });
    return URL.createObjectURL(blob);
  }

  /**
   * Revoke a blob URL to free memory
   */
  revokeBlobURL(url: string): void {
    URL.revokeObjectURL(url);
  }

  private resolveUrl(url: string): string {
    if (url.startsWith('http') || url.startsWith('data:') || url.startsWith('blob:')) {
      return url;
    }
    return this.basePath + url;
  }

  private async queueLoad<T>(loadFn: () => Promise<T>): Promise<T> {
    this.totalLoads++;

    // Wait if at max concurrent loads
    if (this.activeLoads >= this.maxConcurrentLoads) {
      await new Promise<void>((resolve) => {
        this.loadQueue.push(resolve);
      });
    }

    this.activeLoads++;

    try {
      const result = await loadFn();
      return result;
    } finally {
      this.activeLoads--;
      this.completedLoads++;

      // Process next in queue
      const next = this.loadQueue.shift();
      if (next) {
        next();
      }
    }
  }

  private async loadImageElement(url: string, name: string): Promise<HTMLImageElement> {
    return new Promise((resolve, reject) => {
      const img = new Image();

      img.onload = () => {
        this.assets.set(name, img);
        this.loading.delete(name);
        resolve(img);
      };

      img.onerror = () => {
        this.loading.delete(name);
        reject(new Error(`Failed to load image: ${url}`));
      };

      img.src = url;
    });
  }

  private async fetchJSON(url: string, name: string): Promise<unknown> {
    try {
      const response = await fetch(url);
      if (!response.ok) {
        throw new Error(`HTTP ${response.status}: ${response.statusText}`);
      }
      const data = await response.json();
      this.assets.set(name, data);
      this.loading.delete(name);
      return data;
    } catch (error) {
      this.loading.delete(name);
      throw error instanceof Error ? error : new Error(`Failed to load JSON: ${url}`);
    }
  }
}
