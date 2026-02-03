/**
 * InputManager unit tests
 */

import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { InputManager, KeyCode } from '../../src/engine/InputManager';

describe('InputManager', () => {
  let canvas: HTMLCanvasElement;
  let input: InputManager;

  beforeEach(() => {
    canvas = document.createElement('canvas');
    canvas.width = 800;
    canvas.height = 600;
    document.body.appendChild(canvas);
    input = new InputManager(canvas);
  });

  afterEach(() => {
    input.destroy();
    canvas.remove();
  });

  describe('keyboard input', () => {
    it('should track key down state', () => {
      window.dispatchEvent(
        new KeyboardEvent('keydown', { code: KeyCode.W, bubbles: true })
      );

      expect(input.isKeyDown(KeyCode.W)).toBe(true);
      expect(input.wasKeyPressed(KeyCode.W)).toBe(true);
    });

    it('should track key up state', () => {
      // First press the key
      window.dispatchEvent(
        new KeyboardEvent('keydown', { code: KeyCode.W, bubbles: true })
      );

      // Then release it
      window.dispatchEvent(
        new KeyboardEvent('keyup', { code: KeyCode.W, bubbles: true })
      );

      expect(input.isKeyDown(KeyCode.W)).toBe(false);
      expect(input.wasKeyReleased(KeyCode.W)).toBe(true);
    });

    it('should track multiple keys', () => {
      window.dispatchEvent(
        new KeyboardEvent('keydown', { code: KeyCode.W, bubbles: true })
      );
      window.dispatchEvent(
        new KeyboardEvent('keydown', { code: KeyCode.A, bubbles: true })
      );

      expect(input.isKeyDown(KeyCode.W)).toBe(true);
      expect(input.isKeyDown(KeyCode.A)).toBe(true);
      expect(input.isKeyDown(KeyCode.S)).toBe(false);
    });

    it('should clear justPressed on update', () => {
      window.dispatchEvent(
        new KeyboardEvent('keydown', { code: KeyCode.W, bubbles: true })
      );
      expect(input.wasKeyPressed(KeyCode.W)).toBe(true);

      input.update();
      expect(input.wasKeyPressed(KeyCode.W)).toBe(false);
      expect(input.isKeyDown(KeyCode.W)).toBe(true);
    });

    it('should clear justReleased on update', () => {
      window.dispatchEvent(
        new KeyboardEvent('keydown', { code: KeyCode.W, bubbles: true })
      );
      window.dispatchEvent(
        new KeyboardEvent('keyup', { code: KeyCode.W, bubbles: true })
      );
      expect(input.wasKeyReleased(KeyCode.W)).toBe(true);

      input.update();
      expect(input.wasKeyReleased(KeyCode.W)).toBe(false);
    });

    it('should return false for unknown keys', () => {
      expect(input.isKeyDown('UnknownKey')).toBe(false);
      expect(input.wasKeyPressed('UnknownKey')).toBe(false);
      expect(input.wasKeyReleased('UnknownKey')).toBe(false);
    });

    it('should handle rapid key presses', () => {
      const event1 = new KeyboardEvent('keydown', { code: KeyCode.SPACE, bubbles: true });
      window.dispatchEvent(event1);

      expect(input.wasKeyPressed(KeyCode.SPACE)).toBe(true);
      input.update();

      // Simulate holding key - should not trigger justPressed again
      const event2 = new KeyboardEvent('keydown', { code: KeyCode.SPACE, bubbles: true });
      window.dispatchEvent(event2);
      expect(input.wasKeyPressed(KeyCode.SPACE)).toBe(false);
    });
  });

  describe('mouse input', () => {
    it('should track mouse position', () => {
      const rect = { left: 0, top: 0, width: 800, height: 600 } as DOMRect;
      vi.spyOn(canvas, 'getBoundingClientRect').mockReturnValue(rect);

      canvas.dispatchEvent(
        new MouseEvent('mousemove', {
          clientX: 100,
          clientY: 200,
          bubbles: true,
        })
      );

      const pos = input.getMousePos();
      expect(pos.x).toBe(100);
      expect(pos.y).toBe(200);
    });

    it('should track mouse delta', () => {
      const rect = { left: 0, top: 0, width: 800, height: 600 } as DOMRect;
      vi.spyOn(canvas, 'getBoundingClientRect').mockReturnValue(rect);

      // First move
      canvas.dispatchEvent(
        new MouseEvent('mousemove', {
          clientX: 100,
          clientY: 100,
          bubbles: true,
        })
      );

      input.update();

      // Second move
      canvas.dispatchEvent(
        new MouseEvent('mousemove', {
          clientX: 150,
          clientY: 120,
          bubbles: true,
        })
      );

      const delta = input.getMouseDelta();
      expect(delta.x).toBe(50);
      expect(delta.y).toBe(20);
    });

    it('should track left mouse button', () => {
      canvas.dispatchEvent(
        new MouseEvent('mousedown', {
          button: 0,
          bubbles: true,
        })
      );

      expect(input.isMouseButtonDown('left')).toBe(true);
      expect(input.wasMouseButtonPressed('left')).toBe(true);
    });

    it('should track right mouse button', () => {
      canvas.dispatchEvent(
        new MouseEvent('mousedown', {
          button: 2,
          bubbles: true,
        })
      );

      expect(input.isMouseButtonDown('right')).toBe(true);
    });

    it('should track middle mouse button', () => {
      canvas.dispatchEvent(
        new MouseEvent('mousedown', {
          button: 1,
          bubbles: true,
        })
      );

      expect(input.isMouseButtonDown('middle')).toBe(true);
    });

    it('should handle mouse button release', () => {
      canvas.dispatchEvent(
        new MouseEvent('mousedown', {
          button: 0,
          bubbles: true,
        })
      );

      window.dispatchEvent(
        new MouseEvent('mouseup', {
          button: 0,
          bubbles: true,
        })
      );

      expect(input.isMouseButtonDown('left')).toBe(false);
    });

    it('should track mouse wheel', () => {
      canvas.dispatchEvent(
        new WheelEvent('wheel', {
          deltaY: 100,
          bubbles: true,
        })
      );

      expect(input.getMouseWheel()).toBe(1);
    });

    it('should track negative mouse wheel', () => {
      canvas.dispatchEvent(
        new WheelEvent('wheel', {
          deltaY: -100,
          bubbles: true,
        })
      );

      expect(input.getMouseWheel()).toBe(-1);
    });

    it('should clear wheel on update', () => {
      canvas.dispatchEvent(
        new WheelEvent('wheel', {
          deltaY: 100,
          bubbles: true,
        })
      );

      input.update();
      expect(input.getMouseWheel()).toBe(0);
    });

    it('should prevent context menu', () => {
      const event = new MouseEvent('contextmenu', { bubbles: true });
      const preventDefaultSpy = vi.spyOn(event, 'preventDefault');

      canvas.dispatchEvent(event);

      expect(preventDefaultSpy).toHaveBeenCalled();
    });
  });

  describe('state management', () => {
    it('should get full input state', () => {
      window.dispatchEvent(
        new KeyboardEvent('keydown', { code: KeyCode.W, bubbles: true })
      );

      const state = input.getState();
      expect(state.keys.has(KeyCode.W)).toBe(true);
      expect(state.keys.get(KeyCode.W)?.pressed).toBe(true);
    });

    it('should flush input', () => {
      window.dispatchEvent(
        new KeyboardEvent('keydown', { code: KeyCode.W, bubbles: true })
      );

      input.flushInput();

      expect(input.isKeyDown(KeyCode.W)).toBe(false);
      expect(input.getMousePos().x).toBe(0);
    });

    it('should clear mouse delta on update', () => {
      const rect = { left: 0, top: 0, width: 800, height: 600 } as DOMRect;
      vi.spyOn(canvas, 'getBoundingClientRect').mockReturnValue(rect);

      canvas.dispatchEvent(
        new MouseEvent('mousemove', {
          clientX: 100,
          clientY: 100,
          bubbles: true,
        })
      );

      input.update();
      const delta = input.getMouseDelta();
      expect(delta.x).toBe(0);
      expect(delta.y).toBe(0);
    });
  });

  describe('cleanup', () => {
    it('should remove event listeners on destroy', () => {
      const removeEventListenerSpy = vi.spyOn(window, 'removeEventListener');
      const canvasRemoveSpy = vi.spyOn(canvas, 'removeEventListener');

      input.destroy();

      expect(removeEventListenerSpy).toHaveBeenCalledWith('keydown', expect.any(Function));
      expect(removeEventListenerSpy).toHaveBeenCalledWith('keyup', expect.any(Function));
      expect(removeEventListenerSpy).toHaveBeenCalledWith('mouseup', expect.any(Function));
      expect(canvasRemoveSpy).toHaveBeenCalledWith('mousemove', expect.any(Function));
      expect(canvasRemoveSpy).toHaveBeenCalledWith('mousedown', expect.any(Function));
    });
  });

  describe('edge cases', () => {
    it('should handle unknown mouse buttons', () => {
      canvas.dispatchEvent(
        new MouseEvent('mousedown', {
          button: 99, // Invalid button
          bubbles: true,
        })
      );

      // Should not throw
      expect(input.isMouseButtonDown('left')).toBe(false);
      expect(input.isMouseButtonDown('right')).toBe(false);
      expect(input.isMouseButtonDown('middle')).toBe(false);
    });

    it('should handle key release for never-pressed key', () => {
      // Release a key that was never pressed
      window.dispatchEvent(
        new KeyboardEvent('keyup', { code: 'NeverPressed', bubbles: true })
      );

      // Should not throw
      expect(input.wasKeyReleased('NeverPressed')).toBe(false);
    });
  });
});

describe('KeyCode constants', () => {
  it('should define common key codes', () => {
    expect(KeyCode.W).toBe('KeyW');
    expect(KeyCode.A).toBe('KeyA');
    expect(KeyCode.S).toBe('KeyS');
    expect(KeyCode.D).toBe('KeyD');
    expect(KeyCode.SPACE).toBe('Space');
    expect(KeyCode.ENTER).toBe('Enter');
    expect(KeyCode.ESCAPE).toBe('Escape');
  });

  it('should define arrow keys', () => {
    expect(KeyCode.ARROW_UP).toBe('ArrowUp');
    expect(KeyCode.ARROW_DOWN).toBe('ArrowDown');
    expect(KeyCode.ARROW_LEFT).toBe('ArrowLeft');
    expect(KeyCode.ARROW_RIGHT).toBe('ArrowRight');
  });

  it('should define modifier keys', () => {
    expect(KeyCode.SHIFT_LEFT).toBe('ShiftLeft');
    expect(KeyCode.CTRL_LEFT).toBe('ControlLeft');
    expect(KeyCode.ALT_LEFT).toBe('AltLeft');
  });

  it('should define digit keys', () => {
    expect(KeyCode.DIGIT_1).toBe('Digit1');
    expect(KeyCode.DIGIT_2).toBe('Digit2');
    expect(KeyCode.DIGIT_3).toBe('Digit3');
    expect(KeyCode.DIGIT_4).toBe('Digit4');
    expect(KeyCode.DIGIT_5).toBe('Digit5');
  });
});
