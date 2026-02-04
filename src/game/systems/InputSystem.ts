/**
 * Input System
 *
 * Processes player input and updates Player component state.
 * Priority: 10
 */

import { System, type UpdateContext } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs/EntityManager';
import type { InputManager } from '../../engine';
import type { KeyBindings } from '../../types';

export class InputSystem extends System {
  readonly name = 'InputSystem';
  readonly priority = 10;

  private input: InputManager;
  private getBindings: () => KeyBindings;

  // Track continuous fire state
  private firePressed = false;
  private reloadPressed = false;
  private swapPressed = false;

  constructor(input: InputManager, getBindings: () => KeyBindings) {
    super();
    this.input = input;
    this.getBindings = getBindings;
  }

  update(entityManager: EntityManager, _context: UpdateContext): void {
    // Query all player entities
    const entities = entityManager.query(['player', 'transform']);

    const bindings = this.getBindings();

    for (const entity of entities) {
      const player = entity.getComponent<'player'>('player');
      const transform = entity.getComponent<'transform'>('transform');
      if (!player || !transform) continue;

      // Handle movement input using configured bindings
      let moveX = 0;
      let moveY = 0;

      if (this.input.isKeyDown(bindings.moveUp)) moveY -= 1;
      if (this.input.isKeyDown(bindings.moveDown)) moveY += 1;
      if (this.input.isKeyDown(bindings.moveLeft)) moveX -= 1;
      if (this.input.isKeyDown(bindings.moveRight)) moveX += 1;

      // Normalize diagonal movement
      if (moveX !== 0 && moveY !== 0) {
        const length = Math.sqrt(moveX * moveX + moveY * moveY);
        moveX /= length;
        moveY /= length;
      }

      // Store movement intent on player component (for MovementSystem)
      (player as unknown as Record<string, number>).moveIntentX = moveX;
      (player as unknown as Record<string, number>).moveIntentY = moveY;

      // Handle aiming (mouse position)
      const mousePos = this.input.getMousePos();
      const aimX = mousePos.x;
      const aimY = mousePos.y;

      player.aimX = aimX;
      player.aimY = aimY;

      // Calculate aim angle from player to mouse using actual canvas center
      const canvasSize = this.input.getCanvasSize();
      const screenX = canvasSize.width / 2;
      const screenY = canvasSize.height / 2;
      const dx = aimX - screenX;
      const dy = aimY - screenY;
      const aimAngle = Math.atan2(dy, dx);

      // Update player rotation to face aim direction
      transform.rotation = aimAngle;

      // Handle firing - now directly on player component
      const fireDown = this.input.isMouseButtonDown('left');
      player.fireJustPressed = fireDown && !this.firePressed;
      player.fireHeld = fireDown;
      this.firePressed = fireDown;

      // Handle reloading using configured binding
      const reloadKey = this.input.wasKeyPressed(bindings.reload);
      if (reloadKey && !this.reloadPressed) {
        player.reloadRequested = true;
      }
      this.reloadPressed = this.input.isKeyDown(bindings.reload);

      // Handle weapon swapping using configured binding
      const swapKey = this.input.wasKeyPressed(bindings.swapWeapon);
      if (swapKey && !this.swapPressed) {
        player.swapWeaponRequested = true;
      }
      this.swapPressed = this.input.isKeyDown(bindings.swapWeapon);
    }

    // Update input manager to clear justPressed/justReleased states
    this.input.update();
  }
}
