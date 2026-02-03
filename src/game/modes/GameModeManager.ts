/**
 * Game Mode Manager
 *
 * Manages game state transitions and mode-specific logic.
 */

import type { GameState, GameStats, GameMode } from '../../types';

export interface GameModeCallbacks {
  onStateChange?: (newState: GameState, oldState: GameState) => void;
  onGameOver?: (stats: GameStats) => void;
  onVictory?: (stats: GameStats) => void;
}

export class GameModeManager {
  private currentState: GameState;
  private previousState: GameState | null = null;
  private callbacks: GameModeCallbacks;
  private gameStats: GameStats;
  private startTime = 0;

  constructor(callbacks: GameModeCallbacks = {}) {
    this.callbacks = callbacks;
    this.gameStats = {
      score: 0,
      kills: 0,
      timeElapsed: 0,
      level: 1,
    };
    this.currentState = { type: 'MENU', menu: 'MAIN' };
    this.startTime = performance.now();
  }

  /**
   * Get current game state
   */
  getState(): GameState {
    return this.currentState;
  }

  /**
   * Get previous game state
   */
  getPreviousState(): GameState | null {
    return this.previousState;
  }

  /**
   * Transition to a new game state
   */
  setState(newState: GameState): void {
    this.previousState = this.currentState;
    this.currentState = newState;

    // Handle state-specific initialization
    switch (newState.type) {
      case 'PLAYING':
        if (this.previousState?.type !== 'PAUSED') {
          this.resetStats();
        }
        break;
      case 'GAME_OVER':
        this.gameStats.timeElapsed = this.getElapsedTime();
        this.callbacks.onGameOver?.(this.gameStats);
        break;
      case 'VICTORY':
        this.gameStats.timeElapsed = this.getElapsedTime();
        this.callbacks.onVictory?.(this.gameStats);
        break;
    }

    this.callbacks.onStateChange?.(newState, this.previousState);
  }

  /**
   * Start playing a game mode
   */
  startGame(mode: GameMode): void {
    this.setState({ type: 'PLAYING', mode });
  }

  /**
   * Pause the game
   */
  pause(): void {
    if (this.currentState.type === 'PLAYING') {
      this.setState({ type: 'PAUSED' });
    }
  }

  /**
   * Resume from pause
   */
  resume(): void {
    if (this.currentState.type === 'PAUSED' && this.previousState?.type === 'PLAYING') {
      this.setState(this.previousState);
    }
  }

  /**
   * End game with game over
   */
  gameOver(): void {
    this.setState({ type: 'GAME_OVER', stats: this.gameStats });
  }

  /**
   * End game with victory
   */
  victory(): void {
    this.setState({ type: 'VICTORY', stats: this.gameStats });
  }

  /**
   * Show perk selection screen
   */
  showPerkSelect(choices: number[]): void {
    this.setState({ type: 'PERK_SELECT', choices });
  }

  /**
   * Return to main menu
   */
  returnToMenu(): void {
    this.setState({ type: 'MENU', menu: 'MAIN' });
  }

  /**
   * Check if game is currently playing
   */
  isPlaying(): boolean {
    return this.currentState.type === 'PLAYING';
  }

  /**
   * Check if game is paused
   */
  isPaused(): boolean {
    return this.currentState.type === 'PAUSED';
  }

  /**
   * Get current game stats
   */
  getStats(): GameStats {
    return { ...this.gameStats };
  }

  /**
   * Update game stats
   */
  updateStats(updates: Partial<GameStats>): void {
    Object.assign(this.gameStats, updates);
  }

  /**
   * Add to kill count
   */
  addKill(): void {
    this.gameStats.kills++;
  }

  /**
   * Add to score
   */
  addScore(points: number): void {
    this.gameStats.score += points;
  }

  /**
   * Set player level
   */
  setLevel(level: number): void {
    this.gameStats.level = level;
  }

  /**
   * Reset game stats
   */
  private resetStats(): void {
    this.gameStats = {
      score: 0,
      kills: 0,
      timeElapsed: 0,
      level: 1,
    };
    this.startTime = performance.now();
  }

  /**
   * Get elapsed time in seconds
   */
  private getElapsedTime(): number {
    return (performance.now() - this.startTime) / 1000;
  }

  /**
   * Update (call each frame)
   */
  update(): void {
    if (this.isPlaying()) {
      this.gameStats.timeElapsed = this.getElapsedTime();
    }
  }
}
