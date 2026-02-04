#!/usr/bin/env node
/**
 * Decompiled Source Splitter
 *
 * Purpose: Split large decompiled C files into per-function chunks based on
 * function header markers. Provides deterministic, byte-identical splitting
 * with verification capabilities.
 *
 * Non-responsibilities:
 * - Does not modify original source files
 * - Does not perform C parsing (only marker-based splitting)
 * - Does not handle manual edits to split chunks
 *
 * Invariants:
 * - Reassembly of split chunks must be byte-for-byte identical to original
 * - Output is deterministic (same input → same output)
 * - All markers must be found and recorded in manifest
 */

import { createHash } from 'node:crypto';
import { readFileSync, writeFileSync, existsSync, mkdirSync, readdirSync, rmSync } from 'node:fs';
import { dirname, join, basename } from 'node:path';

const VERSION = '1.0.0';
const SCHEMA_VERSION = 1;

// Marker regex: /* name @ hex_address */
export const MARKER_REGEX = /^\/\*\s+(.+?)\s+@\s+([0-9A-Fa-f]+)\s+\*\/$/;

/**
 * Compute SHA256 hash of a buffer
 * @param {Buffer} buffer
 * @returns {string}
 */
export function sha256(buffer) {
  return createHash('sha256').update(buffer).digest('hex');
}

/**
 * Sanitize a function name for use in a filename
 * Only allows [A-Za-z0-9_], replaces others with _, collapses repeats
 * @param {string} name
 * @returns {string}
 */
export function sanitizeName(name) {
  return name
    .replace(/[^A-Za-z0-9_]/g, '_')
    .replace(/_+/g, '_')
    .replace(/^_+|_+$/g, '');
}

/**
 * Find all function markers in a buffer
 * @param {Buffer} buffer
 * @returns {Array<{offset: number, name: string, addrHex: string, line: number}>}
 */
export function findMarkers(buffer) {
  const markers = [];
  let line = 1;
  let lineStart = 0;

  for (let i = 0; i < buffer.length; i++) {
    if (buffer[i] === 0x0a) { // LF
      // Check if this line is a marker
      const lineBuffer = buffer.slice(lineStart, i);
      // Strip any trailing CR for Windows line endings
      const endOffset = lineBuffer.length > 0 && lineBuffer[lineBuffer.length - 1] === 0x0d ? -1 : lineBuffer.length;
      const lineContent = lineBuffer.slice(0, endOffset).toString('utf-8');

      const match = lineContent.match(MARKER_REGEX);
      if (match) {
        markers.push({
          offset: lineStart,
          name: match[1],
          addrHex: match[2].toLowerCase(),
          line: line
        });
      }

      line++;
      lineStart = i + 1;
    }
  }

  // Check last line (in case file doesn't end with newline)
  if (lineStart < buffer.length) {
    const lineBuffer = buffer.slice(lineStart);
    const endOffset = lineBuffer.length > 0 && lineBuffer[lineBuffer.length - 1] === 0x0d ? -1 : lineBuffer.length;
    const lineContent = lineBuffer.slice(0, endOffset).toString('utf-8');

    const match = lineContent.match(MARKER_REGEX);
    if (match) {
      markers.push({
        offset: lineStart,
        name: match[1],
        addrHex: match[2].toLowerCase(),
        line: line
      });
    }
  }

  return markers;
}

/**
 * Create chunks from buffer based on markers
 * @param {Buffer} buffer
 * @param {Array} markers
 * @returns {Array<{start: number, end: number, marker: object|null}>}
 */
export function createChunks(buffer, markers) {
  const chunks = [];

  if (markers.length === 0) {
    // No markers - entire file is one chunk
    chunks.push({
      start: 0,
      end: buffer.length,
      marker: null
    });
    return chunks;
  }

  // First chunk: preamble (before first marker)
  if (markers[0].offset > 0) {
    chunks.push({
      start: 0,
      end: markers[0].offset,
      marker: null
    });
  }

  // Marker chunks
  for (let i = 0; i < markers.length; i++) {
    const start = markers[i].offset;
    const end = i < markers.length - 1 ? markers[i + 1].offset : buffer.length;
    chunks.push({
      start,
      end,
      marker: markers[i]
    });
  }

  return chunks;
}

/**
 * Generate filename for a chunk
 * @param {number} index
 * @param {object|null} marker
 * @returns {string}
 */
export function generateFilename(index, marker) {
  const idx = index.toString().padStart(5, '0');
  if (marker) {
    const safeName = sanitizeName(marker.name);
    return `${idx}_${safeName}_${marker.addrHex}.c`;
  }
  return `${idx}__preamble.c`;
}

/**
 * Split a file into chunks
 * @param {string} inputPath
 * @param {string} outputDir
 * @param {boolean} clean
 * @returns {object} Manifest
 */
export function splitFile(inputPath, outputDir, clean = false) {
  // Read input file as bytes
  const buffer = readFileSync(inputPath);
  const originalSha256 = sha256(buffer);

  // Find markers
  const markers = findMarkers(buffer);

  if (markers.length === 0) {
    throw new Error(
      `No function markers found in ${inputPath}; expected lines like /* name @ 00401030 */`
    );
  }

  // Create chunks
  const chunks = createChunks(buffer, markers);

  // Prepare output directories
  const chunksDir = join(outputDir, 'chunks');

  if (clean && existsSync(outputDir)) {
    // Remove existing output dir entirely for clean rebuild
    rmSync(outputDir, { recursive: true });
  }

  if (!existsSync(outputDir)) {
    mkdirSync(outputDir, { recursive: true });
  }
  if (!existsSync(chunksDir)) {
    mkdirSync(chunksDir, { recursive: true });
  }

  // Write chunks and build manifest
  const manifestChunks = [];
  for (let i = 0; i < chunks.length; i++) {
    const chunk = chunks[i];
    const filename = generateFilename(i, chunk.marker);
    const chunkBuffer = buffer.slice(chunk.start, chunk.end);
    const chunkSha256 = sha256(chunkBuffer);

    writeFileSync(join(chunksDir, filename), chunkBuffer);

    manifestChunks.push({
      index: i,
      file: filename,
      start: chunk.start,
      end: chunk.end,
      byteLength: chunk.end - chunk.start,
      sha256: chunkSha256,
      marker: chunk.marker ? {
        name: chunk.marker.name,
        addrHex: chunk.marker.addrHex,
        line: chunk.marker.line
      } : null
    });
  }

  // Build manifest with stable key order
  const manifest = {
    schemaVersion: SCHEMA_VERSION,
    source: {
      originalPath: `decompile/original/${basename(inputPath)}`,
      byteLength: buffer.length,
      sha256: originalSha256
    },
    chunkDir: 'chunks',
    chunks: manifestChunks
  };

  // Write manifest with stable formatting
  writeFileSync(
    join(outputDir, 'manifest.json'),
    `${JSON.stringify(manifest, null, 2)}\n`
  );

  return manifest;
}

/**
 * Verify reassembly of chunks against original
 * @param {string} manifestPath
 * @param {string} originalPath
 * @returns {object} Verification result
 */
export function verifyReassembly(manifestPath, originalPath) {
  const manifest = JSON.parse(readFileSync(manifestPath, 'utf-8'));
  const manifestDir = dirname(manifestPath);

  // Read and verify original
  if (!existsSync(originalPath)) {
    throw new Error(`Original file not found: ${originalPath}`);
  }
  const originalBuffer = readFileSync(originalPath);
  const originalSha256 = sha256(originalBuffer);

  if (originalSha256 !== manifest.source.sha256) {
    throw new Error(
      `SHA256 mismatch: original file has changed\nExpected: ${manifest.source.sha256}\nActual:   ${originalSha256}`
    );
  }

  // Reassemble chunks
  const chunks = manifest.chunks;
  const chunksDir = join(manifestDir, manifest.chunkDir);

  // Verify chunks are sorted by index
  const sortedChunks = [...chunks].sort((a, b) => a.index - b.index);
  for (let i = 0; i < sortedChunks.length; i++) {
    if (sortedChunks[i].index !== i) {
      throw new Error(`Chunk index ${i} missing or out of order`);
    }
  }

  // Read and concatenate chunks
  let currentOffset = 0;
  const assembledBuffers = [];

  for (const chunk of sortedChunks) {
    const chunkPath = join(chunksDir, chunk.file);

    if (!existsSync(chunkPath)) {
      throw new Error(`Chunk file missing: ${chunk.file}`);
    }

    const chunkBuffer = readFileSync(chunkPath);

    // Verify chunk sha256
    const chunkSha256 = sha256(chunkBuffer);
    if (chunkSha256 !== chunk.sha256) {
      throw new Error(
        `SHA256 mismatch for chunk ${chunk.file}\n` +
        `Expected: ${chunk.sha256}\n` +
        `Actual:   ${chunkSha256}`
      );
    }

    // Verify offset
    if (chunk.start !== currentOffset) {
      throw new Error(
        `Offset mismatch for chunk ${chunk.file}\n` +
        `Expected start: ${currentOffset}\n` +
        `Actual start:   ${chunk.start}`
      );
    }

    // Verify byte length
    if (chunkBuffer.length !== chunk.byteLength) {
      throw new Error(
        `Byte length mismatch for chunk ${chunk.file}\n` +
        `Expected: ${chunk.byteLength}\n` +
        `Actual:   ${chunkBuffer.length}`
      );
    }

    assembledBuffers.push(chunkBuffer);
    currentOffset = chunk.end;
  }

  // Verify total length
  if (currentOffset !== manifest.source.byteLength) {
    throw new Error(
      `Total length mismatch\nExpected: ${manifest.source.byteLength}\nActual:   ${currentOffset}`
    );
  }

  // Concatenate and verify against original
  const assembled = Buffer.concat(assembledBuffers);
  const assembledSha256 = sha256(assembled);

  if (assembledSha256 !== manifest.source.sha256) {
    throw new Error(
      `Reassembly SHA256 mismatch\nExpected: ${manifest.source.sha256}\nActual:   ${assembledSha256}`
    );
  }

  if (!assembled.equals(originalBuffer)) {
    throw new Error('Reassembled bytes do not match original (byte-for-byte check failed)');
  }

  return {
    success: true,
    chunksVerified: chunks.length,
    totalBytes: manifest.source.byteLength,
    sha256: manifest.source.sha256
  };
}

/**
 * Print help message
 */
function printHelp() {
  console.log(`
Decompiled Source Splitter v${VERSION}

Split large decompiled C files into per-function chunks based on header markers.

USAGE:
  node split.mjs <command> [options]

COMMANDS:
  split     Split a decompiled C file into chunks
  verify    Verify that chunks can be reassembled to match original

SPLIT OPTIONS:
  --in <path>        Input file path (required)
  --out <dir>        Output directory (default: derived from input filename)
  --clean            Remove existing output directory before splitting
  --no-verify        Skip roundtrip verification after splitting

VERIFY OPTIONS:
  --manifest <path>  Path to manifest.json (required)
  --original <path>  Path to original C file (required)

GLOBAL OPTIONS:
  --help, -h         Show this help message
  --version, -v      Show version

EXAMPLES:
  # Split crimsonland.exe_decompiled.c
  node scripts/decompile/split.mjs split \\
    --in decompile/original/crimsonland.exe_decompiled.c \\
    --out decompile/split/crimsonland.exe

  # Split with clean rebuild (removes existing output first)
  node scripts/decompile/split.mjs split \\
    --in decompile/original/grim.dll_decompiled.c \\
    --out decompile/split/grim.dll \\
    --clean

  # Verify existing split without re-splitting
  node scripts/decompile/split.mjs verify \\
    --manifest decompile/split/crimsonland.exe/manifest.json \\
    --original decompile/original/crimsonland.exe_decompiled.c

MARKER FORMAT:
  Split boundaries are lines matching: /* <name> @ <hex_address> */
  Example: /* console_input_clear @ 00401030 */

INVARIANTS:
  - Reassembly of chunks must be byte-for-byte identical to original
  - Output is deterministic (same input always produces same output)
  - Manifest contains SHA256 hashes for integrity verification
`);
}

/**
 * Main entry point
 */
async function main() {
  const args = process.argv.slice(2);

  // Handle help/version
  if (args.length === 0 || args.includes('--help') || args.includes('-h')) {
    printHelp();
    return 0;
  }

  if (args.includes('--version') || args.includes('-v')) {
    console.log(VERSION);
    return 0;
  }

  const command = args[0];

  // Parse arguments
  const getArg = (flag) => {
    const idx = args.indexOf(flag);
    return idx !== -1 && idx + 1 < args.length ? args[idx + 1] : null;
  };
  const hasFlag = (flag) => args.includes(flag);

  try {
    switch (command) {
      case 'split': {
        const inputPath = getArg('--in');
        let outputDir = getArg('--out');
        const clean = hasFlag('--clean');
        const skipVerify = hasFlag('--no-verify');

        if (!inputPath) {
          console.error('Error: --in is required');
          return 1;
        }

        if (!existsSync(inputPath)) {
          console.error(`Error: Input file not found: ${inputPath}`);
          return 1;
        }

        // Derive output dir from input if not specified
        if (!outputDir) {
          const base = basename(inputPath, '_decompiled.c');
          outputDir = `decompile/split/${base}`;
        }

        console.log(`Splitting ${inputPath}...`);
        const manifest = splitFile(inputPath, outputDir, clean);

        console.log(`Created ${manifest.chunks.length} chunks in ${outputDir}/chunks/`);
        console.log(`Manifest: ${outputDir}/manifest.json`);
        console.log(`Original SHA256: ${manifest.source.sha256}`);

        // Verify roundtrip
        if (!skipVerify) {
          console.log('Verifying reassembly...');
          const result = verifyReassembly(
            join(outputDir, 'manifest.json'),
            inputPath
          );
          console.log(`✓ Verification passed (${result.chunksVerified} chunks, ${result.totalBytes} bytes)`);
        }

        return 0;
      }

      case 'verify': {
        const manifestPath = getArg('--manifest');
        const originalPath = getArg('--original');

        if (!manifestPath) {
          console.error('Error: --manifest is required');
          return 1;
        }

        if (!originalPath) {
          console.error('Error: --original is required');
          return 1;
        }

        console.log(`Verifying ${manifestPath} against ${originalPath}...`);
        const result = verifyReassembly(manifestPath, originalPath);
        console.log(`✓ Verification passed (${result.chunksVerified} chunks, ${result.totalBytes} bytes)`);

        return 0;
      }

      default:
        console.error(`Error: Unknown command: ${command}`);
        console.error('Run with --help for usage information');
        return 1;
    }
  } catch (error) {
    console.error(`Error: ${error.message}`);
    return 1;
  }
}

// Only run main if this file is executed directly (not imported)
if (import.meta.url === `file://${process.argv[1]}`) {
  main().then(code => process.exit(code));
}
