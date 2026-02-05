/**
 * Storage Utilities Unit Tests
 */

import { describe, it, expect, beforeEach, vi, afterEach } from 'vitest';
import { safeParseStorage } from '../../../../src/game/utils/storage';

// Create a fresh storage object for test isolation
function createStorage(): Record<string, string> {
  return {};
}

// Factory to create a fresh localStorage mock with isolated storage
function createLocalStorageMock(store: Record<string, string>) {
  return {
    getItem: vi.fn((key: string) => store[key] ?? null),
    setItem: vi.fn((key: string, value: string) => {
      store[key] = value;
    }),
    clear: vi.fn(() => {
      for (const key of Object.keys(store)) {
        delete store[key];
      }
    }),
    removeItem: vi.fn((key: string) => {
      delete store[key];
    }),
  };
}

describe('safeParseStorage', () => {
  let store: Record<string, string>;
  let localStorageMock: ReturnType<typeof createLocalStorageMock>;

  beforeEach(() => {
    store = createStorage();
    localStorageMock = createLocalStorageMock(store);
    vi.stubGlobal('localStorage', localStorageMock);
  });

  afterEach(() => {
    vi.unstubAllGlobals();
    vi.clearAllMocks();
  });

  it('should return null for non-existent key', () => {
    const result = safeParseStorage('non_existent_key');
    expect(result).toBeNull();
    expect(localStorageMock.removeItem).not.toHaveBeenCalled();
  });

  it('should return null for empty string', () => {
    store['test_key'] = '';
    const result = safeParseStorage('test_key');
    expect(result).toBeNull();
    expect(localStorageMock.removeItem).not.toHaveBeenCalled();
  });

  it('should parse valid object JSON', () => {
    const data = { version: 1, name: 'test' };
    store['test_key'] = JSON.stringify(data);
    const result = safeParseStorage('test_key');
    expect(result).toEqual(data);
    expect(localStorageMock.removeItem).not.toHaveBeenCalled();
  });

  it('should clear storage and return null for invalid JSON', () => {
    store['test_key'] = 'not valid json{';
    const result = safeParseStorage('test_key');
    expect(result).toBeNull();
    expect(localStorageMock.removeItem).toHaveBeenCalledWith('test_key');
  });

  it('should clear storage and return null for null JSON', () => {
    store['test_key'] = 'null';
    const result = safeParseStorage('test_key');
    expect(result).toBeNull();
    expect(localStorageMock.removeItem).toHaveBeenCalledWith('test_key');
  });

  it('should clear storage and return null for array JSON', () => {
    store['test_key'] = '[]';
    const result = safeParseStorage('test_key');
    expect(result).toBeNull();
    expect(localStorageMock.removeItem).toHaveBeenCalledWith('test_key');
  });

  it('should clear storage and return null for primitive JSON string', () => {
    store['test_key'] = '"just a string"';
    const result = safeParseStorage('test_key');
    expect(result).toBeNull();
    expect(localStorageMock.removeItem).toHaveBeenCalledWith('test_key');
  });

  it('should clear storage and return null for number JSON', () => {
    store['test_key'] = '123';
    const result = safeParseStorage('test_key');
    expect(result).toBeNull();
    expect(localStorageMock.removeItem).toHaveBeenCalledWith('test_key');
  });

  it('should clear storage and return null for boolean JSON', () => {
    store['test_key'] = 'true';
    const result = safeParseStorage('test_key');
    expect(result).toBeNull();
    expect(localStorageMock.removeItem).toHaveBeenCalledWith('test_key');
  });

  it('should handle localStorage getItem throwing', () => {
    localStorageMock.getItem.mockImplementation(() => {
      throw new Error('Storage disabled');
    });
    const result = safeParseStorage('test_key');
    expect(result).toBeNull();
    expect(localStorageMock.removeItem).toHaveBeenCalledWith('test_key');
  });

  it('should handle nested objects correctly', () => {
    const data = { version: 1, nested: { a: 1, b: [1, 2, 3] } };
    store['test_key'] = JSON.stringify(data);
    const result = safeParseStorage('test_key');
    expect(result).toEqual(data);
    expect(localStorageMock.removeItem).not.toHaveBeenCalled();
  });
});
