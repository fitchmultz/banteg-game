/**
 * Command Registry System
 *
 * Registers and executes console commands.
 * Modeled after Quake's command system.
 *
 * Responsibilities:
 * - Register and unregister commands
 * - Parse command lines and execute commands
 * - Manage command aliases
 * - Provide autocomplete suggestions
 *
 * Non-responsibilities:
 * - Does not handle CVARs (see Cvar.ts)
 * - Does not render UI (see Console.ts)
 * - Does not persist command history
 *
 * Assumptions:
 * - Command names are unique and case-sensitive
 * - Command handlers are synchronous
 * - Command output is returned as strings
 */

import { cvarRegistry } from './Cvar';

/**
 * Command handler function type
 */
export type CommandHandler = (args: string[]) => string | undefined;

/**
 * Command flags for controlling visibility and access
 */
export enum CommandFlags {
  NONE = 0,
  CHEAT = 1 << 0, // Requires developer mode
  HIDDEN = 1 << 1, // Don't show in help
}

/**
 * Command definition interface
 */
export interface CommandDef {
  name: string;
  description: string;
  usage?: string;
  flags?: CommandFlags;
  handler: CommandHandler;
}

/**
 * Registry for all console commands
 */
export class CommandRegistry {
  private commands: Map<string, CommandDef> = new Map();
  private aliases: Map<string, string> = new Map();

  /**
   * Register a new command
   */
  register(def: CommandDef): void {
    if (this.commands.has(def.name)) {
      throw new Error(`Command '${def.name}' is already registered`);
    }
    this.commands.set(def.name, def);
  }

  /**
   * Unregister a command
   */
  unregister(name: string): void {
    this.commands.delete(name);
  }

  /**
   * Execute a command line (parses and executes)
   * @returns output string or error message
   */
  execute(line: string): string {
    const trimmed = line.trim();
    if (!trimmed) {
      return '';
    }

    // Parse the command line
    const parts = this.parseLine(trimmed);
    if (parts.length === 0) {
      return '';
    }

    const [name, ...args] = parts;
    if (name === undefined) {
      return '';
    }
    return this.executeCommand(name, args);
  }

  /**
   * Execute a specific command with arguments
   */
  executeCommand(name: string, args: string[]): string {
    // Check for alias
    const aliasedName = this.aliases.get(name) ?? name;

    const command = this.commands.get(aliasedName);
    if (!command) {
      return `Unknown command: ${name}`;
    }

    // Check cheat flag
    if (command.flags !== undefined && command.flags & CommandFlags.CHEAT) {
      const developer = cvarRegistry.getValue<boolean>('developer');
      if (!developer) {
        return `Command '${name}' requires developer mode. Set 'developer 1' first.`;
      }
    }

    try {
      const result = command.handler(args);
      return result ?? '';
    } catch (error) {
      return `Error executing '${name}': ${error instanceof Error ? error.message : String(error)}`;
    }
  }

  /**
   * Get a command definition
   */
  get(name: string): CommandDef | undefined {
    return this.commands.get(name);
  }

  /**
   * List all registered commands
   */
  list(): CommandDef[] {
    return Array.from(this.commands.values());
  }

  /**
   * Find commands matching a prefix (for autocomplete)
   */
  findMatches(prefix: string): string[] {
    const matches: string[] = [];
    for (const name of this.commands.keys()) {
      if (name.startsWith(prefix)) {
        matches.push(name);
      }
    }
    for (const [alias] of this.aliases.entries()) {
      if (alias.startsWith(prefix)) {
        matches.push(alias);
      }
    }
    return matches.sort();
  }

  /**
   * Add a command alias
   */
  alias(name: string, target: string): void {
    this.aliases.set(name, target);
  }

  /**
   * Parse a command line into parts
   * Handles quoted strings
   */
  private parseLine(line: string): string[] {
    const parts: string[] = [];
    let current = '';
    let inQuotes = false;
    let quoteChar = '';

    for (let i = 0; i < line.length; i++) {
      const char = line[i];

      if (inQuotes) {
        if (char === quoteChar) {
          inQuotes = false;
          quoteChar = '';
        } else {
          current += char;
        }
      } else {
        if (char === '"' || char === "'") {
          inQuotes = true;
          quoteChar = char;
        } else if (char === ' ' || char === '\t') {
          if (current) {
            parts.push(current);
            current = '';
          }
        } else {
          current += char;
        }
      }
    }

    if (current) {
      parts.push(current);
    }

    return parts;
  }
}

/**
 * Global command registry instance
 */
export const commandRegistry = new CommandRegistry();

// Register built-in commands

// Help command
commandRegistry.register({
  name: 'help',
  description: 'Show available commands or help for a specific command',
  usage: 'help [command]',
  handler: (args) => {
    if (args.length > 0 && args[0] !== undefined) {
      const cmd = commandRegistry.get(args[0]);
      if (cmd) {
        return `${cmd.name}: ${cmd.description}\nUsage: ${cmd.usage || cmd.name}`;
      }
      return `Unknown command: ${args[0]}`;
    }

    const commands = commandRegistry
      .list()
      .filter((c) => c.flags === undefined || !(c.flags & CommandFlags.HIDDEN))
      .map((c) => `  ${c.name.padEnd(15)} - ${c.description}`)
      .join('\n');

    return `Available commands:\n${commands}`;
  },
});

// Clear command
commandRegistry.register({
  name: 'clear',
  description: 'Clear console output',
  handler: () => {
    // Console will handle this - return special marker
    return '__CLEAR__';
  },
});

// Echo command
commandRegistry.register({
  name: 'echo',
  description: 'Print text to console',
  usage: 'echo <text>',
  handler: (args) => args.join(' '),
});

// CVAR commands
commandRegistry.register({
  name: 'set',
  description: 'Set a CVAR value',
  usage: 'set <cvar> <value>',
  handler: (args) => {
    if (args.length < 2) return 'Usage: set <cvar> <value>';
    const [name, ...valueParts] = args;
    if (name === undefined) return 'Usage: set <cvar> <value>';
    const value = valueParts.join(' ');
    const success = cvarRegistry.setValue(name, value);
    return success ? `${name} = "${value}"` : `Failed to set ${name}`;
  },
});

commandRegistry.register({
  name: 'toggle',
  description: 'Toggle a boolean CVAR',
  usage: 'toggle <cvar>',
  handler: (args) => {
    if (args.length < 1 || args[0] === undefined) return 'Usage: toggle <cvar>';
    const cvar = cvarRegistry.get(args[0]);
    if (!cvar) return `Unknown CVAR: ${args[0]}`;
    if (typeof cvar.value !== 'boolean') return `${args[0]} is not a boolean`;
    cvar.value = !cvar.value;
    return `${args[0]} = ${cvar.value}`;
  },
});

commandRegistry.register({
  name: 'cvarlist',
  description: 'List all CVARs',
  handler: () => {
    const cvars = cvarRegistry.list();
    return cvars.map((c) => `  ${c.name.padEnd(20)} = "${c.toString()}"`).join('\n');
  },
});

// Game commands (to be wired up in main.ts)
commandRegistry.register({
  name: 'quit',
  description: 'Return to main menu',
  handler: () => {
    // Will be wired to returnToMainMenu in main.ts
    return 'Returning to main menu...';
  },
});

commandRegistry.register({
  name: 'god',
  description: 'Toggle god mode',
  flags: CommandFlags.CHEAT,
  handler: () => {
    // Will be wired to game logic in main.ts
    return 'God mode toggled';
  },
});

commandRegistry.register({
  name: 'give',
  description: 'Give item to player',
  usage: 'give <weapon|ammo|health> [amount]',
  flags: CommandFlags.CHEAT,
  handler: (args) => {
    if (args.length < 1 || args[0] === undefined)
      return 'Usage: give <weapon|ammo|health> [amount]';
    // Will be wired to game logic in main.ts
    return `Giving ${args.join(' ')}...`;
  },
});

commandRegistry.register({
  name: 'killall',
  description: 'Kill all enemies',
  flags: CommandFlags.CHEAT,
  handler: () => {
    // Will be wired to game logic in main.ts
    return 'Killing all enemies...';
  },
});

commandRegistry.register({
  name: 'noclip',
  description: 'Toggle noclip mode',
  flags: CommandFlags.CHEAT,
  handler: () => {
    // Will be wired to game logic in main.ts
    return 'Noclip toggled';
  },
});
