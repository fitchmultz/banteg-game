/**
 * Storage Utilities
 *
 * Shared helpers for safe localStorage operations with automatic
 * cleanup of corrupt entries.
 */

/**
 * Safely parse localStorage JSON and validate it returns a non-null object.
 * On invalid JSON, null result, or non-object types, clears the storage key.
 *
 * @param key - The localStorage key to read
 * @returns Parsed object if valid, null if invalid (key is cleared)
 */
export function safeParseStorage<T extends object>(key: string): T | null {
  try {
    const stored = localStorage.getItem(key);
    if (!stored) {
      return null;
    }

    const parsed = JSON.parse(stored) as unknown;

    // Validate: must be a non-null object (not array, primitive, or null)
    if (typeof parsed !== 'object' || parsed === null || Array.isArray(parsed)) {
      console.warn(
        `Invalid storage data for key "${key}": expected object, got ${
          parsed === null ? 'null' : Array.isArray(parsed) ? 'array' : typeof parsed
        }. Clearing corrupt entry.`
      );
      localStorage.removeItem(key);
      return null;
    }

    return parsed as T;
  } catch (error) {
    console.warn(`Failed to parse storage for key "${key}":`, error);
    localStorage.removeItem(key);
    return null;
  }
}
