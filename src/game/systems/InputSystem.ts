/**
 * Input System
 *
 * Processes player input and updates Player component state.
 * Priority: 10
 */

import { System, type UpdateContext } from '../../core/ecs/System';
import type { EntityManager } from '../../core/ecs/EntityManager';
import { type InputManager, KeyCode } from '../../engine';

export class InputSystem extends System {
  readonly name = 'InputSystem';
  readonly priority = 10;

  private input: InputManager;

  // Track continuous fire state
  private firePressed = false;
  private reloadPressed = false;
  private swapPressed = false;

  constructor(input: InputManager) {
    super();
    this.input = input;
  }

  update(entityManager: EntityManager, _context: UpdateContext): void {
    // Query all player entities
    const entities = entityManager.query(['player', 'transform']);

    for (const entity of entities) {
      const player = entity.getComponent<'player'>('player');
      const transform = entity.getComponent<'transform'>('transform');
      if (!player || !transform) continue;

      // Handle movement input (WASD)
      let moveX = 0;
      let moveY = 0;

      if (this.input.isKeyDown(KeyCode.W)) moveY -= 1;
      if (this.input.isKeyDown(KeyCode.S)) moveY += 1;
      if (this.input.isKeyDown(KeyCode.A)) moveX -= 1;
      if (this.input.isKeyDown(KeyCode.D)) moveX += 1;

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

      // Calculate aim angle from player to mouse
      const screenX = 512; // Center of screen (TODO: get from renderer)
      const screenY = 384;
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

      // Handle reloading - now directly on player component
      const reloadKey = this.input.wasKeyPressed(KeyCode.R);
      if (reloadKey && !this.reloadPressed) {
        player.reloadRequested = true;
      }
      this.reloadPressed = this.input.isKeyDown(KeyCode.R);

      // Handle weapon swapping (Q key)
      const swapKey = this.input.wasKeyPressed(KeyCode.Q);
      if (swapKey && !this.swapPressed) {
        player.swapWeaponRequested = true;
      }
      this.swapPressed = this.input.isKeyDown(KeyCode.Q);
    }

    // Update input manager to clear justPressed/justReleased states
    this.input.update();
  }
}
