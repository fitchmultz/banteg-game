/**
 * CVAR (Console Variable) System
 *
 * Type-safe runtime variables for the developer console.
 * Modeled after Quake's CVAR system.
 *
 * Responsibilities:
 * - Define CVAR types and flags
 * - Store and manage CVAR values with type safety
 * - Validate value ranges for numeric CVARs
 * - Trigger callbacks on value changes
 *
 * Non-responsibilities:
 * - Does not persist CVARs to storage (CVARs are runtime-only)
 * - Does not handle command execution (see CommandRegistry)
 * - Does not render UI (see Console)
 *
 * Assumptions:
 * - CVAR names are unique and case-sensitive
 * - onChange callbacks are synchronous
 * - Numeric CVARs with min/max bounds are validated on assignment
 */

/**
 * CVAR value types supported by the system
 */
export type CvarValue = string | number | boolean;

/**
 * CVAR flags for controlling behavior
 */
export enum CvarFlags {
  NONE = 0,
  CHEAT = 1 << 0, // Requires developer mode to modify
  READONLY = 1 << 1, // Cannot be modified
  ARCHIVE = 1 << 2, // Save to localStorage (not used - CVARs are runtime-only)
}

/**
 * CVAR definition interface for registration
 */
export interface CvarDef<T extends CvarValue = CvarValue> {
  name: string;
  defaultValue: T;
  description: string;
  flags?: CvarFlags;
  min?: number; // For number CVARs
  max?: number; // For number CVARs
  onChange?: ((value: T, oldValue: T) => void) | undefined;
}

/**
 * A console variable with type-safe value storage
 */
export class Cvar<T extends CvarValue = CvarValue> {
  readonly name: string;
  readonly defaultValue: T;
  readonly description: string;
  readonly flags: CvarFlags;
  readonly min: number | undefined;
  readonly max: number | undefined;

  private _value: T;
  private _onChange: ((value: T, oldValue: T) => void) | undefined;

  constructor(def: CvarDef<T>) {
    this.name = def.name;
    this.defaultValue = def.defaultValue;
    this.description = def.description;
    this.flags = def.flags ?? CvarFlags.NONE;
    this.min = def.min;
    this.max = def.max;
    this._value = def.defaultValue;
    this._onChange = def.onChange;
  }

  /**
   * Get or set the onChange callback
   */
  get onChange(): ((value: T, oldValue: T) => void) | undefined {
    return this._onChange;
  }

  set onChange(callback: ((value: T, oldValue: T) => void) | undefined) {
    this._onChange = callback;
  }

  /**
   * Get the current value
   */
  get value(): T {
    return this._value;
  }

  /**
   * Set the value with validation
   */
  set value(newValue: T) {
    if (this.flags & CvarFlags.READONLY) {
      return;
    }

    // Validate numeric bounds
    let finalValue = newValue;
    if (typeof newValue === 'number' && (this.min !== undefined || this.max !== undefined)) {
      const numValue = newValue as number;
      let clampedValue = numValue;
      if (this.min !== undefined && clampedValue < this.min) {
        clampedValue = this.min;
      }
      if (this.max !== undefined && clampedValue > this.max) {
        clampedValue = this.max;
      }
      finalValue = clampedValue as T;
    }

    const oldValue = this._value;
    if (oldValue !== finalValue) {
      this._value = finalValue;
      this._onChange?.(finalValue, oldValue);
    }
  }

  /**
   * Reset to default value
   */
  reset(): void {
    this.value = this.defaultValue;
  }

  /**
   * Convert value to string representation
   */
  toString(): string {
    return String(this._value);
  }

  /**
   * Parse value from string
   * @returns true if parsing succeeded
   */
  fromString(str: string): boolean {
    if (this.flags & CvarFlags.READONLY) {
      return false;
    }

    try {
      const oldValue = this._value;
      let newValue: T;

      if (typeof this.defaultValue === 'boolean') {
        // Parse boolean
        const lower = str.toLowerCase();
        newValue = (lower === '1' || lower === 'true' || lower === 'yes') as T;
      } else if (typeof this.defaultValue === 'number') {
        // Parse number
        const parsed = Number(str);
        if (Number.isNaN(parsed)) {
          return false;
        }
        let clampedValue: number = parsed;

        // Validate bounds
        if (this.min !== undefined && clampedValue < this.min) {
          clampedValue = this.min;
        }
        if (this.max !== undefined && clampedValue > this.max) {
          clampedValue = this.max;
        }
        newValue = clampedValue as T;
      } else {
        // Parse string
        newValue = str as T;
      }

      if (oldValue !== newValue) {
        this._value = newValue;
        this._onChange?.(newValue, oldValue);
      }
      return true;
    } catch {
      return false;
    }
  }
}

/**
 * Registry for all CVARs
 */
export class CvarRegistry {
  private cvars: Map<string, Cvar<CvarValue>> = new Map();

  /**
   * Register a new CVAR
   */
  register<T extends CvarValue>(def: CvarDef<T>): Cvar<T> {
    if (this.cvars.has(def.name)) {
      throw new Error(`CVAR '${def.name}' is already registered`);
    }
    const cvar = new Cvar(def);
    this.cvars.set(def.name, cvar as unknown as Cvar<CvarValue>);
    return cvar;
  }

  /**
   * Get a CVAR by name
   */
  get(name: string): Cvar<CvarValue> | undefined {
    return this.cvars.get(name);
  }

  /**
   * Get a CVAR value by name
   */
  getValue<T extends CvarValue>(name: string): T | undefined {
    const cvar = this.cvars.get(name);
    return cvar?.value as T | undefined;
  }

  /**
   * Set a CVAR value from string
   * @returns true if successful
   */
  setValue(name: string, value: string): boolean {
    const cvar = this.cvars.get(name);
    if (!cvar) {
      return false;
    }
    return cvar.fromString(value);
  }

  /**
   * List all registered CVARs
   */
  list(): Cvar<CvarValue>[] {
    return Array.from(this.cvars.values());
  }

  /**
   * List CVARs matching a prefix
   */
  listByPrefix(prefix: string): Cvar<CvarValue>[] {
    return this.list().filter((c) => c.name.startsWith(prefix));
  }
}

/**
 * Global CVAR registry instance
 */
export const cvarRegistry = new CvarRegistry();

// Register built-in CVARs

// Developer/Debug CVARs
cvarRegistry.register({
  name: 'developer',
  defaultValue: false,
  description: 'Enable developer mode (allows cheat commands)',
  flags: CvarFlags.NONE,
});

cvarRegistry.register({
  name: 'r_showfps',
  defaultValue: false,
  description: 'Show FPS counter',
  flags: CvarFlags.NONE,
});

cvarRegistry.register({
  name: 'r_drawentities',
  defaultValue: true,
  description: 'Render entities',
  flags: CvarFlags.NONE,
});

cvarRegistry.register({
  name: 'r_drawcollisions',
  defaultValue: false,
  description: 'Show collision hitboxes',
  flags: CvarFlags.CHEAT,
});

cvarRegistry.register({
  name: 'con_pause',
  defaultValue: false,
  description: 'Pause game when console is open',
  flags: CvarFlags.NONE,
});

cvarRegistry.register({
  name: 'timescale',
  defaultValue: 1.0,
  description: 'Game speed multiplier',
  min: 0.1,
  max: 10.0,
  flags: CvarFlags.CHEAT,
});

// Read-only CVARs (computed values)
cvarRegistry.register({
  name: 'ent_count',
  defaultValue: 0,
  description: 'Current entity count (read-only)',
  flags: CvarFlags.READONLY,
});

cvarRegistry.register({
  name: 'version',
  defaultValue: '1.0.0',
  description: 'Game version (read-only)',
  flags: CvarFlags.READONLY,
});
