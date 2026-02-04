/**
 * Decompiled Source Splitter Tests
 *
 * @vitest-environment node
 */

import { describe, it, expect, beforeAll, afterAll } from 'vitest';
import { readFileSync, writeFileSync, mkdirSync, rmSync, existsSync } from 'node:fs';
import { join } from 'node:path';
import {
  findMarkers,
  sha256,
  sanitizeName,
  createChunks,
  generateFilename,
  splitFile,
  verifyReassembly,
  MARKER_REGEX,
} from '../../../scripts/decompile/split.mjs';

const FIXTURES_DIR = join(__dirname, 'fixtures');
const TEMP_DIR = join(__dirname, 'temp');

describe('Decompiled Source Splitter', () => {
  // Clean up temp dir before and after tests
  beforeAll(() => {
    if (existsSync(TEMP_DIR)) {
      rmSync(TEMP_DIR, { recursive: true });
    }
    mkdirSync(TEMP_DIR, { recursive: true });
  });

  afterAll(() => {
    if (existsSync(TEMP_DIR)) {
      rmSync(TEMP_DIR, { recursive: true });
    }
  });

  describe('Utility Functions', () => {
    describe('sha256', () => {
      it('should compute SHA256 hash correctly', () => {
        const buffer = Buffer.from('hello world');
        const hash = sha256(buffer);
        expect(hash).toBe('b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde9');
      });

      it('should return consistent hashes for same input', () => {
        const buffer = Buffer.from('test data');
        const hash1 = sha256(buffer);
        const hash2 = sha256(buffer);
        expect(hash1).toBe(hash2);
      });
    });

    describe('sanitizeName', () => {
      it('should allow valid characters', () => {
        expect(sanitizeName('valid_name123')).toBe('valid_name123');
      });

      it('should replace invalid characters with underscore', () => {
        expect(sanitizeName('name@with:special!chars')).toBe('name_with_special_chars');
      });

      it('should collapse multiple underscores', () => {
        expect(sanitizeName('name___with___underscores')).toBe('name_with_underscores');
      });

      it('should trim leading and trailing underscores', () => {
        expect(sanitizeName('__name__')).toBe('name');
      });

      it('should handle function names with dots', () => {
        expect(sanitizeName('FUN_004010f0')).toBe('FUN_004010f0');
      });

      it('should handle empty string', () => {
        expect(sanitizeName('')).toBe('');
      });
    });

    describe('MARKER_REGEX', () => {
      it('should match valid markers', () => {
        expect('/* func_name @ 00401030 */'.match(MARKER_REGEX)).toBeTruthy();
        expect('/* FUN_100019f0 @ 100019f0 */'.match(MARKER_REGEX)).toBeTruthy();
        expect('/* test_init @ 00100000 */'.match(MARKER_REGEX)).toBeTruthy();
      });

      it('should capture name and address', () => {
        const match = '/* console_input_clear @ 00401030 */'.match(MARKER_REGEX);
        expect(match?.[1]).toBe('console_input_clear');
        expect(match?.[2]).toBe('00401030');
      });

      it('should not match malformed markers', () => {
        expect('/* no_at_sign */'.match(MARKER_REGEX)).toBeFalsy();
        expect('/* bad @ marker */'.match(MARKER_REGEX)).toBeFalsy();
        expect('not a marker at all'.match(MARKER_REGEX)).toBeFalsy();
      });
    });

    describe('findMarkers', () => {
      it('should find all markers in a simple file', () => {
        const buffer = readFileSync(join(FIXTURES_DIR, 'simple.c'));
        const markers = findMarkers(buffer);

        expect(markers).toHaveLength(3);
        expect(markers[0]?.name).toBe('test_init');
        expect(markers[0]?.addrHex).toBe('00100000');
        expect(markers[1]?.name).toBe('test_process');
        expect(markers[1]?.addrHex).toBe('00100020');
        expect(markers[2]?.name).toBe('test_cleanup');
        expect(markers[2]?.addrHex).toBe('00100040');
      });

      it('should return empty array for file with no markers', () => {
        const buffer = readFileSync(join(FIXTURES_DIR, 'no_markers.c'));
        const markers = findMarkers(buffer);
        expect(markers).toHaveLength(0);
      });

      it('should record correct line numbers', () => {
        const buffer = readFileSync(join(FIXTURES_DIR, 'simple.c'));
        const markers = findMarkers(buffer);

        expect(markers[0]?.line).toBe(3);
        expect(markers[1]?.line).toBe(9);
        expect(markers[2]?.line).toBe(15);
      });

      it('should record correct byte offsets', () => {
        const buffer = readFileSync(join(FIXTURES_DIR, 'simple.c'));
        const markers = findMarkers(buffer);

        expect(markers[0]?.offset).toBeGreaterThanOrEqual(0);
        expect(markers[1]?.offset).toBeGreaterThan(markers[0]?.offset ?? 0);
        expect(markers[2]?.offset).toBeGreaterThan(markers[1]?.offset ?? 0);
      });
    });

    describe('createChunks', () => {
      it('should create preamble chunk when markers exist', () => {
        const buffer = Buffer.from('/* preamble */\n/* func @ 00100000 */\nvoid func() {}');
        const markers = findMarkers(buffer);
        const chunks = createChunks(buffer, markers);

        expect(chunks.length).toBeGreaterThanOrEqual(2);
        expect(chunks[0]?.marker).toBeNull(); // preamble
        expect(chunks[1]?.marker).not.toBeNull();
      });

      it('should create single chunk when no markers', () => {
        const buffer = Buffer.from('void foo() {}');
        const chunks = createChunks(buffer, []);

        expect(chunks).toHaveLength(1);
        expect(chunks[0]?.start).toBe(0);
        expect(chunks[0]?.end).toBe(buffer.length);
        expect(chunks[0]?.marker).toBeNull();
      });

      it('should create contiguous chunks', () => {
        const buffer = readFileSync(join(FIXTURES_DIR, 'simple.c'));
        const markers = findMarkers(buffer);
        const chunks = createChunks(buffer, markers);

        // Verify chunks are contiguous
        for (let i = 1; i < chunks.length; i++) {
          expect(chunks[i]?.start).toBe(chunks[i - 1]?.end);
        }
      });
    });

    describe('generateFilename', () => {
      it('should generate preamble filename', () => {
        expect(generateFilename(0, null)).toBe('00000__preamble.c');
        expect(generateFilename(5, null)).toBe('00005__preamble.c');
      });

      it('should generate marker chunk filename', () => {
        const marker = { name: 'test_func', addrHex: '00401030', line: 1, offset: 0 };
        expect(generateFilename(1, marker)).toBe('00001_test_func_00401030.c');
      });

      it('should sanitize marker names in filename', () => {
        const marker = { name: 'func@with:special', addrHex: '00100000', line: 1, offset: 0 };
        expect(generateFilename(1, marker)).toBe('00001_func_with_special_00100000.c');
      });

      it('should pad index with zeros', () => {
        const marker = { name: 'test', addrHex: '00100000', line: 1, offset: 0 };
        expect(generateFilename(99999, marker)).toBe('99999_test_00100000.c');
      });
    });
  });

  describe('Split and Verify', () => {
    it('should split simple.c and create manifest', () => {
      const inputPath = join(FIXTURES_DIR, 'simple.c');
      const outputDir = join(TEMP_DIR, 'simple_split');

      const manifest = splitFile(inputPath, outputDir, true);

      expect(manifest.schemaVersion).toBe(1);
      expect(manifest.source.originalPath).toContain('simple.c');
      expect(manifest.chunks).toHaveLength(4); // preamble + 3 functions
      expect(existsSync(join(outputDir, 'manifest.json'))).toBe(true);
      expect(existsSync(join(outputDir, 'chunks'))).toBe(true);
    });

    it('should throw error for file with no markers', () => {
      const inputPath = join(FIXTURES_DIR, 'no_markers.c');
      const outputDir = join(TEMP_DIR, 'no_markers_split');

      expect(() => {
        splitFile(inputPath, outputDir, true);
      }).toThrow('No function markers found');
    });

    it('should verify reassembly correctly', () => {
      const inputPath = join(FIXTURES_DIR, 'simple.c');
      const outputDir = join(TEMP_DIR, 'simple_verify');

      splitFile(inputPath, outputDir, true);
      const result = verifyReassembly(
        join(outputDir, 'manifest.json'),
        inputPath
      );

      expect(result.success).toBe(true);
      expect(result.chunksVerified).toBe(4);
    });

    it('should detect modified original during verification', () => {
      const inputPath = join(FIXTURES_DIR, 'simple.c');
      const outputDir = join(TEMP_DIR, 'simple_modified');

      splitFile(inputPath, outputDir, true);

      // Modify the original temporarily
      const originalContent = readFileSync(inputPath);
      const modifiedContent = Buffer.concat([originalContent, Buffer.from('\n')]);
      const modifiedPath = join(TEMP_DIR, 'modified.c');
      writeFileSync(modifiedPath, modifiedContent);

      expect(() => {
        verifyReassembly(
          join(outputDir, 'manifest.json'),
          modifiedPath
        );
      }).toThrow('SHA256 mismatch');
    });

    it('should produce deterministic output', () => {
      const inputPath = join(FIXTURES_DIR, 'simple.c');
      const outputDir1 = join(TEMP_DIR, 'det1');
      const outputDir2 = join(TEMP_DIR, 'det2');

      const manifest1 = splitFile(inputPath, outputDir1, true);
      const manifest2 = splitFile(inputPath, outputDir2, true);

      // Manifests should be identical
      expect(JSON.stringify(manifest1)).toBe(JSON.stringify(manifest2));

      // Chunk files should be identical
      for (const chunk of manifest1.chunks) {
        const file1 = readFileSync(join(outputDir1, 'chunks', chunk.file));
        const file2 = readFileSync(join(outputDir2, 'chunks', chunk.file));
        expect(file1.equals(file2)).toBe(true);
      }
    });
  });

  describe('Real Repository Artifacts', () => {
    it('should verify crimsonland.exe split output', () => {
      const result = verifyReassembly(
        'decompile/split/crimsonland.exe/manifest.json',
        'decompile/original/crimsonland.exe_decompiled.c'
      );

      expect(result.success).toBe(true);
      expect(result.chunksVerified).toBeGreaterThan(0);
      expect(result.totalBytes).toBe(2008301);
    });

    it('should verify grim.dll split output', () => {
      const result = verifyReassembly(
        'decompile/split/grim.dll/manifest.json',
        'decompile/original/grim.dll_decompiled.c'
      );

      expect(result.success).toBe(true);
      expect(result.chunksVerified).toBeGreaterThan(0);
      expect(result.totalBytes).toBe(1506447);
    });

    it('should have correct preamble structure for crimsonland.exe', () => {
      const manifest = JSON.parse(
        readFileSync('decompile/split/crimsonland.exe/manifest.json', 'utf-8')
      );

      expect(manifest.chunks[0].marker).toBeNull();
      expect(manifest.chunks[0].start).toBe(0);
      expect(manifest.chunks[0].index).toBe(0);
    });

    it('should have strictly increasing marker line numbers', () => {
      const manifest = JSON.parse(
        readFileSync('decompile/split/crimsonland.exe/manifest.json', 'utf-8')
      );

      const markerChunks = manifest.chunks.filter((c: { marker: unknown }) => c.marker !== null);
      for (let i = 1; i < markerChunks.length; i++) {
        expect(markerChunks[i].marker.line).toBeGreaterThan(markerChunks[i - 1].marker.line);
      }
    });

    it('should have contiguous chunks in crimsonland.exe', () => {
      const manifest = JSON.parse(
        readFileSync('decompile/split/crimsonland.exe/manifest.json', 'utf-8')
      );

      for (let i = 1; i < manifest.chunks.length; i++) {
        expect(manifest.chunks[i].start).toBe(manifest.chunks[i - 1].end);
      }
    });
  });
});
