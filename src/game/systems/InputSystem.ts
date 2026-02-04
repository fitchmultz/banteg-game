/**
 * Input System
 *
 * Processes player input and updates Player component state.
 * Now supports multiple players with per-player input bindings.
 * Priority: 10
 *
 * Responsibilities:
 * - Process input for all player entities
 * - Support per-player bindings (P1 keyboard+mouse, P2 gamepad/keyboard)
 * - Track per-entity input edge states (fire/reload/swap)
 * - Handle gamepad input for P2
 *
 * Non-responsibilities:
 * - Does not handle input device assignment (see main.ts)
 * - Does not render input UI
 * - Does not handle touch controls (handled by InputManager)
 *
 * Assumptions:
 * - Player entities have 'player' and 'transform' components
 * - Player component has playerIndex (0 for P1, 1 for P2)
 * - getBindingsForPlayer returns valid KeyBindings for each player
 * - update() is called once per frame after processing all players
 */

import type { EntityManager } from '../../core/ecs/EntityManager';
import { System, type UpdateContext } from '../../core/ecs/System';
import type { InputManager } from '../../engine';
import type { EntityId, KeyBindings } from '../../types';

interface PlayerInputState {
  firePressed: boolean;
  reloadPressed: boolean;
  swapPressed: boolean;
}

export class InputSystem extends System {
  readonly name = 'InputSystem';
  readonly priority = 10;

  private input: InputManager;
  private getBindingsForPlayer: (playerIndex: number) => KeyBindings;

  // Per-entity edge state tracking
  private playerInputStates: Map<EntityId, PlayerInputState> = new Map();

  constructor(input: InputManager, getBindingsForPlayer: (playerIndex: number) => KeyBindings) {
    super();
    this.input = input;
    this.getBindingsForPlayer = getBindingsForPlayer;
  }

  update(entityManager: EntityManager, _context: UpdateContext): void {
    // Query all player entities
    const entities = entityManager.query(['player', 'transform']);

    for (const entity of entities) {
      const player = entity.getComponent<'player'>('player');
      const transform = entity.getComponent<'transform'>('transform');
      if (!player || !transform) continue;

      const playerIndex = player.playerIndex ?? 0;
      const bindings = this.getBindingsForPlayer(playerIndex);

      // Get or create per-entity input state
      let inputState = this.playerInputStates.get(entity.id);
      if (!inputState) {
        inputState = { firePressed: false, reloadPressed: false, swapPressed: false };
        this.playerInputStates.set(entity.id, inputState);
      }

      if (playerIndex === 0) {
        // P1: Keyboard + Mouse
        this.processP1Input(player, transform, bindings, inputState);
      } else {
        // P2: Gamepad preferred, fallback to keyboard
        this.processP2Input(player, transform, bindings, inputState);
      }
    }

    // Update input manager to clear justPressed/justReleased states
    this.input.update();
  }

  private processP1Input(
    player: {
      aimX: number;
      aimY: number;
      fireJustPressed: boolean;
      fireHeld: boolean;
      reloadRequested: boolean;
      swapWeaponRequested: boolean;
    },
    transform: { rotation: number },
    bindings: KeyBindings,
    inputState: PlayerInputState
  ): void {
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
    player.aimX = mousePos.x;
    player.aimY = mousePos.y;

    // Calculate aim angle from player to mouse using actual canvas center
    const canvasSize = this.input.getCanvasSize();
    const screenX = canvasSize.width / 2;
    const screenY = canvasSize.height / 2;
    const dx = mousePos.x - screenX;
    const dy = mousePos.y - screenY;
    const aimAngle = Math.atan2(dy, dx);

    // Update player rotation to face aim direction
    transform.rotation = aimAngle;

    // Handle firing
    const fireDown = this.input.isMouseButtonDown('left');
    player.fireJustPressed = fireDown && !inputState.firePressed;
    player.fireHeld = fireDown;
    inputState.firePressed = fireDown;

    // Handle reloading using configured binding
    const reloadKey = this.input.wasKeyPressed(bindings.reload);
    if (reloadKey && !inputState.reloadPressed) {
      player.reloadRequested = true;
    }
    inputState.reloadPressed = this.input.isKeyDown(bindings.reload);

    // Handle weapon swapping using configured binding
    const swapKey = this.input.wasKeyPressed(bindings.swapWeapon);
    if (swapKey && !inputState.swapPressed) {
      player.swapWeaponRequested = true;
    }
    inputState.swapPressed = this.input.isKeyDown(bindings.swapWeapon);
  }

  private processP2Input(
    player: {
      aimX: number;
      aimY: number;
      fireJustPressed: boolean;
      fireHeld: boolean;
      reloadRequested: boolean;
      swapWeaponRequested: boolean;
    },
    transform: { rotation: number },
    bindings: KeyBindings,
    inputState: PlayerInputState
  ): void {
    const gamepadIndex = this.input.getFirstGamepadIndex();
    const hasGamepad = gamepadIndex >= 0;

    // Handle movement
    let moveX = 0;
    let moveY = 0;

    if (hasGamepad) {
      // Gamepad left stick for movement
      const leftStickX = this.input.getGamepadAxis(gamepadIndex, 0);
      const leftStickY = this.input.getGamepadAxis(gamepadIndex, 1);

      // Apply deadzone
      const deadzone = 0.15;
      if (Math.abs(leftStickX) > deadzone) moveX = leftStickX;
      if (Math.abs(leftStickY) > deadzone) moveY = leftStickY;
    }

    // Fallback to keyboard if no gamepad movement
    if (moveX === 0 && moveY === 0) {
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
    }

    // Store movement intent
    (player as unknown as Record<string, number>).moveIntentX = moveX;
    (player as unknown as Record<string, number>).moveIntentY = moveY;

    // Handle aiming
    let aimX = 0;
    let aimY = 0;

    if (hasGamepad) {
      // Gamepad right stick for aiming
      const rightStickX = this.input.getGamepadAxis(gamepadIndex, 2);
      const rightStickY = this.input.getGamepadAxis(gamepadIndex, 3);

      const deadzone = 0.15;
      if (Math.abs(rightStickX) > deadzone || Math.abs(rightStickY) > deadzone) {
        aimX = rightStickX;
        aimY = rightStickY;
      }
    }

    // If no right stick input, aim in movement direction
    if (aimX === 0 && aimY === 0 && (moveX !== 0 || moveY !== 0)) {
      aimX = moveX;
      aimY = moveY;
    }

    // Update aim and rotation
    if (aimX !== 0 || aimY !== 0) {
      player.aimX = aimX;
      player.aimY = aimY;
      transform.rotation = Math.atan2(aimY, aimX);
    }

    // Handle firing
    let fireDown = false;
    if (hasGamepad) {
      // RT (button 7) or A (button 0) for fire
      fireDown =
        this.input.isGamepadButtonDown(gamepadIndex, 7) ||
        this.input.isGamepadButtonDown(gamepadIndex, 0);
    }
    // Fallback to keyboard fire binding
    if (!fireDown) {
      fireDown = this.input.isKeyDown(bindings.fire);
    }

    player.fireJustPressed = fireDown && !inputState.firePressed;
    player.fireHeld = fireDown;
    inputState.firePressed = fireDown;

    // Handle reloading
    let reloadPressed = false;
    if (hasGamepad) {
      // X (button 2) for reload
      reloadPressed = this.input.wasGamepadButtonPressed(gamepadIndex, 2);
    }
    if (!reloadPressed) {
      reloadPressed = this.input.wasKeyPressed(bindings.reload);
    }
    if (reloadPressed && !inputState.reloadPressed) {
      player.reloadRequested = true;
    }
    inputState.reloadPressed = hasGamepad
      ? this.input.isGamepadButtonDown(gamepadIndex, 2) || this.input.isKeyDown(bindings.reload)
      : this.input.isKeyDown(bindings.reload);

    // Handle weapon swapping
    let swapPressed = false;
    if (hasGamepad) {
      // Y (button 3) for swap
      swapPressed = this.input.wasGamepadButtonPressed(gamepadIndex, 3);
    }
    if (!swapPressed) {
      swapPressed = this.input.wasKeyPressed(bindings.swapWeapon);
    }
    if (swapPressed && !inputState.swapPressed) {
      player.swapWeaponRequested = true;
    }
    inputState.swapPressed = hasGamepad
      ? this.input.isGamepadButtonDown(gamepadIndex, 3) || this.input.isKeyDown(bindings.swapWeapon)
      : this.input.isKeyDown(bindings.swapWeapon);
  }
}
