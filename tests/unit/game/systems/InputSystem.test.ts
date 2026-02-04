/**
 * Input System Unit Tests - Configurable Bindings
 */

import { describe, it, expect, vi, beforeEach } from 'vitest';
import { InputSystem } from '../../../../src/game/systems/InputSystem';
import type { InputManager } from '../../../../src/engine';
import type { KeyBindings } from '../../../../src/types';
import { EntityManager } from '../../../../src/core/ecs';
import { PlayerFactory } from '../../../../src/game/entities';

// Mock InputManager interface with test helpers
interface MockInputManager extends InputManager {
  _setKeyDown: (code: string, down: boolean) => void;
  _setMousePos: (x: number, y: number) => void;
  _setMouseDown: (down: boolean) => void;
  _setCanvasSize: (width: number, height: number) => void;
}

// Mock InputManager factory
function createMockInputManager(): MockInputManager {
  const keyStates = new Map<string, boolean>();
  const justPressedStates = new Map<string, boolean>();
  let mousePos = { x: 0, y: 0 };
  let mouseDown = false;
  const canvasSize = { width: 1024, height: 768 };
  let touchEnabled = false;

  return {
    isKeyDown: vi.fn((code: string) => keyStates.get(code) ?? false),
    wasKeyPressed: vi.fn((code: string) => {
      const pressed = justPressedStates.get(code) ?? false;
      justPressedStates.set(code, false); // Clear after reading
      return pressed;
    }),
    wasKeyReleased: vi.fn(() => false),
    isMouseButtonDown: vi.fn(() => mouseDown),
    wasMouseButtonPressed: vi.fn(() => false),
    getMousePos: vi.fn(() => ({ ...mousePos })),
    getMouseDelta: vi.fn(() => ({ x: 0, y: 0 })),
    getMouseWheel: vi.fn(() => 0),
    setMousePos: vi.fn(),
    flushInput: vi.fn(),
    update: vi.fn(() => {
      // Clear just pressed states after each update
      justPressedStates.clear();
    }),
    getState: vi.fn(),
    getCanvasSize: vi.fn(() => ({ ...canvasSize })),
    destroy: vi.fn(),
    // Touch controls (not used in tests but required by type)
    enableTouchControls: vi.fn(() => {
      touchEnabled = true;
    }),
    disableTouchControls: vi.fn(() => {
      touchEnabled = false;
    }),
    isTouchEnabled: vi.fn(() => touchEnabled),
    getVirtualJoystick: vi.fn(() => ({
      active: false,
      x: 0,
      y: 0,
      dx: 0,
      dy: 0,
      angle: 0,
      magnitude: 0,
    })),
    getFireButton: vi.fn(() => ({
      active: false,
      x: 0,
      y: 0,
      radius: 50,
      pressed: false,
      justPressed: false,
      justReleased: false,
      label: 'FIRE',
    })),
    getReloadButton: vi.fn(() => ({
      active: false,
      x: 0,
      y: 0,
      radius: 35,
      pressed: false,
      justPressed: false,
      justReleased: false,
      label: 'R',
    })),
    handleResize: vi.fn(),
    renderTouchControls: vi.fn(),
    // Test helpers
    _setKeyDown: (code: string, down: boolean) => {
      if (down && !keyStates.get(code)) {
        justPressedStates.set(code, true);
      }
      keyStates.set(code, down);
    },
    _setMousePos: (x: number, y: number) => {
      mousePos = { x, y };
    },
    _setMouseDown: (down: boolean) => {
      mouseDown = down;
    },
    _setCanvasSize: (width: number, height: number) => {
      canvasSize.width = width;
      canvasSize.height = height;
    },
  } as unknown as MockInputManager;
}

// Default WASD bindings
const defaultBindings: KeyBindings = {
  moveUp: 'KeyW',
  moveDown: 'KeyS',
  moveLeft: 'KeyA',
  moveRight: 'KeyD',
  fire: 'MouseLeft',
  reload: 'KeyR',
  swapWeapon: 'KeyQ',
  pause: 'Escape',
};

// Arrow key bindings (remapped)
const arrowBindings: KeyBindings = {
  moveUp: 'ArrowUp',
  moveDown: 'ArrowDown',
  moveLeft: 'ArrowLeft',
  moveRight: 'ArrowRight',
  fire: 'MouseLeft',
  reload: 'KeyR',
  swapWeapon: 'KeyQ',
  pause: 'Escape',
};

describe('InputSystem', () => {
  let input: MockInputManager;
  let entityManager: EntityManager;

  beforeEach(() => {
    input = createMockInputManager();
    entityManager = new EntityManager();
  });

  describe('Default Bindings', () => {
    it('should use WASD for movement with default bindings', () => {
      const system = new InputSystem(input, () => defaultBindings);
      const player = PlayerFactory.create(entityManager, 0, 0, { playerIndex: 0, weaponId: 0 });

      // Press W key
      input._setKeyDown('KeyW', true);
      system.update(entityManager, {
        dt: 1 / 60,
        unscaledDt: 1 / 60,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      const playerComp = player.getComponent<'player'>('player');
      expect(playerComp).toBeDefined();
      if (playerComp) {
        expect((playerComp as unknown as Record<string, number>).moveIntentY).toBeLessThan(0);
      }
    });

    it('should handle diagonal movement', () => {
      const system = new InputSystem(input, () => defaultBindings);
      const player = PlayerFactory.create(entityManager, 0, 0, { playerIndex: 0, weaponId: 0 });

      // Press W and D keys
      input._setKeyDown('KeyW', true);
      input._setKeyDown('KeyD', true);
      system.update(entityManager, {
        dt: 1 / 60,
        unscaledDt: 1 / 60,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      const playerComp = player.getComponent<'player'>('player');
      expect(playerComp).toBeDefined();
      if (playerComp) {
        const moveX = (playerComp as unknown as Record<string, number>).moveIntentX;
        const moveY = (playerComp as unknown as Record<string, number>).moveIntentY;
        // Diagonal should be normalized
        expect(Math.abs(moveX ?? 0)).toBeCloseTo(Math.SQRT1_2, 2);
        expect(Math.abs(moveY ?? 0)).toBeCloseTo(Math.SQRT1_2, 2);
      }
    });

    it('should set reloadRequested when reload key is pressed', () => {
      const system = new InputSystem(input, () => defaultBindings);
      const player = PlayerFactory.create(entityManager, 0, 0, { playerIndex: 0, weaponId: 0 });

      // Press R key
      input._setKeyDown('KeyR', true);
      system.update(entityManager, {
        dt: 1 / 60,
        unscaledDt: 1 / 60,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      const playerComp = player.getComponent<'player'>('player');
      expect(playerComp).toBeDefined();
      if (playerComp) {
        expect(playerComp.reloadRequested).toBe(true);
      }
    });

    it('should set swapWeaponRequested when swap key is pressed', () => {
      const system = new InputSystem(input, () => defaultBindings);
      const player = PlayerFactory.create(entityManager, 0, 0, { playerIndex: 0, weaponId: 0 });

      // Press Q key
      input._setKeyDown('KeyQ', true);
      system.update(entityManager, {
        dt: 1 / 60,
        unscaledDt: 1 / 60,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      const playerComp = player.getComponent<'player'>('player');
      expect(playerComp).toBeDefined();
      if (playerComp) {
        expect(playerComp.swapWeaponRequested).toBe(true);
      }
    });
  });

  describe('Remapped Bindings', () => {
    it('should use arrow keys when remapped', () => {
      const system = new InputSystem(input, () => arrowBindings);
      const player = PlayerFactory.create(entityManager, 0, 0, { playerIndex: 0, weaponId: 0 });

      // Press ArrowUp key (not W)
      input._setKeyDown('ArrowUp', true);
      system.update(entityManager, {
        dt: 1 / 60,
        unscaledDt: 1 / 60,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      const playerComp = player.getComponent<'player'>('player');
      expect(playerComp).toBeDefined();
      if (playerComp) {
        expect((playerComp as unknown as Record<string, number>).moveIntentY).toBeLessThan(0);
      }
    });

    it('should not respond to WASD when remapped to arrows', () => {
      const system = new InputSystem(input, () => arrowBindings);
      const player = PlayerFactory.create(entityManager, 0, 0, { playerIndex: 0, weaponId: 0 });

      // Press W key (should not move since we're using arrows)
      input._setKeyDown('KeyW', true);
      system.update(entityManager, {
        dt: 1 / 60,
        unscaledDt: 1 / 60,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      const playerComp = player.getComponent<'player'>('player');
      expect(playerComp).toBeDefined();
      if (playerComp) {
        expect((playerComp as unknown as Record<string, number>).moveIntentY).toBe(0);
      }
    });
  });

  describe('Aiming', () => {
    it('should calculate aim angle from center of screen', () => {
      const system = new InputSystem(input, () => defaultBindings);
      const player = PlayerFactory.create(entityManager, 100, 100, { playerIndex: 0, weaponId: 0 });

      // Set canvas size to 1024x768
      input._setCanvasSize(1024, 768);
      // Mouse at right edge
      input._setMousePos(1024, 384);
      system.update(entityManager, {
        dt: 1 / 60,
        unscaledDt: 1 / 60,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      const transform = player.getComponent<'transform'>('transform');
      expect(transform).toBeDefined();
      if (transform) {
        // Should be aiming roughly to the right (angle near 0)
        expect(transform.rotation).toBeCloseTo(0, 1);
      }
    });

    it('should handle different canvas sizes for aim center', () => {
      const system = new InputSystem(input, () => defaultBindings);
      const player = PlayerFactory.create(entityManager, 0, 0, { playerIndex: 0, weaponId: 0 });

      // Set canvas size to 800x600
      input._setCanvasSize(800, 600);
      // Mouse at center-right, slightly below center to produce non-zero angle
      // Center is (400, 300), mouse at (600, 400)
      input._setMousePos(600, 400);
      system.update(entityManager, {
        dt: 1 / 60,
        unscaledDt: 1 / 60,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      const transform = player.getComponent<'transform'>('transform');
      expect(transform).toBeDefined();
      if (transform) {
        // Should be aiming down and right (positive angle from center)
        expect(transform.rotation).toBeGreaterThan(0);
      }
    });
  });

  describe('Firing', () => {
    it('should set fireHeld when mouse button is down', () => {
      const system = new InputSystem(input, () => defaultBindings);
      const player = PlayerFactory.create(entityManager, 0, 0, { playerIndex: 0, weaponId: 0 });

      input._setMouseDown(true);
      system.update(entityManager, {
        dt: 1 / 60,
        unscaledDt: 1 / 60,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      const playerComp = player.getComponent<'player'>('player');
      expect(playerComp).toBeDefined();
      if (playerComp) {
        expect(playerComp.fireHeld).toBe(true);
      }
    });

    it('should set fireJustPressed on initial click', () => {
      const system = new InputSystem(input, () => defaultBindings);
      const player = PlayerFactory.create(entityManager, 0, 0, { playerIndex: 0, weaponId: 0 });

      input._setMouseDown(true);
      system.update(entityManager, {
        dt: 1 / 60,
        unscaledDt: 1 / 60,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      const playerComp = player.getComponent<'player'>('player');
      expect(playerComp).toBeDefined();
      if (playerComp) {
        expect(playerComp.fireJustPressed).toBe(true);
      }
    });
  });

  describe('Binding Provider', () => {
    it('should read bindings from provider each update', () => {
      let currentBindings = defaultBindings;
      const system = new InputSystem(input, () => currentBindings);
      const player = PlayerFactory.create(entityManager, 0, 0, { playerIndex: 0, weaponId: 0 });

      // First update with WASD
      input._setKeyDown('KeyW', true);
      system.update(entityManager, {
        dt: 1 / 60,
        unscaledDt: 1 / 60,
        gameTime: 0,
        frameNumber: 0,
        timeScale: 1,
        setTimeScale: () => {},
      });

      let playerComp = player.getComponent<'player'>('player');
      if (playerComp) {
        expect((playerComp as unknown as Record<string, number>).moveIntentY).toBeLessThan(0);
      }

      // Reset and change bindings
      input._setKeyDown('KeyW', false);
      currentBindings = arrowBindings;

      // Update with arrow keys
      input._setKeyDown('ArrowUp', true);
      system.update(entityManager, {
        dt: 1 / 60,
        unscaledDt: 1 / 60,
        gameTime: 1 / 60,
        frameNumber: 2,
        timeScale: 1,
        setTimeScale: () => {},
      });

      playerComp = player.getComponent<'player'>('player');
      if (playerComp) {
        expect((playerComp as unknown as Record<string, number>).moveIntentY).toBeLessThan(0);
      }
    });
  });
});
