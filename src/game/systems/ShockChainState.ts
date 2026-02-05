/**
 * Shock Chain State Management
 *
 * Global state for tracking shock chain bonus effect across frames.
 * The shock chain needs to persist state between projectile hits.
 * Based on decompiled globals: shock_chain_projectile_id and shock_chain_links_left
 */

// Decompiled constant: shock_chain_links_left starts at 32 (lines 274-275)
export const SHOCK_CHAIN_MAX_LINKS = 32;

interface ShockChainState {
  activeProjectileId: number | null;
  linksLeft: number;
}

const state: ShockChainState = {
  activeProjectileId: null,
  linksLeft: 0,
};

/**
 * Initialize shock chain state when a new chain starts.
 * Called by BonusSystem when SHOCK_CHAIN bonus is collected.
 */
export function setShockChainState(projectileId: number, linksLeft: number): void {
  state.activeProjectileId = projectileId;
  state.linksLeft = linksLeft;
}

/**
 * Get current shock chain state.
 * Called by CollisionSystem to check if a projectile hit should continue the chain.
 */
export function getShockChainState(): ShockChainState {
  return { ...state };
}

/**
 * Update shock chain state (called when chain continues to new projectile).
 */
export function updateShockChainState(newProjectileId: number, newLinksLeft: number): void {
  state.activeProjectileId = newProjectileId;
  state.linksLeft = newLinksLeft;
}

/**
 * Clear shock chain state (called when chain ends - no more targets or links exhausted).
 */
export function clearShockChainState(): void {
  state.activeProjectileId = null;
  state.linksLeft = 0;
}
