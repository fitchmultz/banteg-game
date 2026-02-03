/**
 * Core type definitions for Crimsonland Remake
 */

// ============================================================================
// Core Types
// ============================================================================

export type EntityId = number;
export type ComponentType = string;

export interface Component {
  readonly type: ComponentType;
}

// ============================================================================
// Math Types
// ============================================================================

export interface Vector2 {
  x: number;
  y: number;
}

export interface Rectangle {
  x: number;
  y: number;
  width: number;
  height: number;
}

export interface Color {
  r: number;
  g: number;
  b: number;
  a: number;
}

// Re-export game types
export * from './game';
