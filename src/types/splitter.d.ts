/**
 * Type declarations for scripts/decompile/split.mjs
 */

declare module '*scripts/decompile/split.mjs' {
  export interface Marker {
    offset: number;
    name: string;
    addrHex: string;
    line: number;
  }

  export interface Chunk {
    start: number;
    end: number;
    marker: Marker | null;
  }

  export interface ManifestChunk {
    index: number;
    file: string;
    start: number;
    end: number;
    byteLength: number;
    sha256: string;
    marker: {
      name: string;
      addrHex: string;
      line: number;
    } | null;
  }

  export interface Manifest {
    schemaVersion: number;
    source: {
      originalPath: string;
      byteLength: number;
      sha256: string;
    };
    chunkDir: string;
    chunks: ManifestChunk[];
  }

  export interface VerifyResult {
    success: boolean;
    chunksVerified: number;
    totalBytes: number;
    sha256: string;
  }

  export const MARKER_REGEX: RegExp;

  export function sha256(buffer: Buffer): string;
  export function sanitizeName(name: string): string;
  export function findMarkers(buffer: Buffer): Marker[];
  export function createChunks(buffer: Buffer, markers: Marker[]): Chunk[];
  export function generateFilename(index: number, marker: Marker | null): string;
  export function splitFile(inputPath: string, outputDir: string, clean?: boolean): Manifest;
  export function verifyReassembly(manifestPath: string, originalPath: string): VerifyResult;
}
