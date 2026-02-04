/**
 * Console Module
 *
 * Quake-style developer console and CVAR system.
 *
 * Responsibilities:
 * - Export all console components
 * - Provide unified access to CVARs, commands, and console UI
 *
 * Non-responsibilities:
 * - Does not initialize the console (done in main.ts)
 * - Does not handle game-specific command wiring
 */

export { Cvar, CvarFlags, CvarRegistry, cvarRegistry } from './Cvar';
export type { CvarDef, CvarValue } from './Cvar';
export { CommandFlags, CommandRegistry, commandRegistry } from './CommandRegistry';
export type { CommandDef, CommandHandler } from './CommandRegistry';
export { Console, ConsoleMessageType } from './Console';
export type { ConsoleMessage, ConsoleOptions } from './Console';
