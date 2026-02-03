/**
 * Crimsonland Remake - Main Entry Point
 */

import { EntityManager, SystemManager } from './core/ecs';
import { GameLoop } from './core/GameLoop';
import { Renderer, InputManager, AudioManager } from './engine';

const GAME_WIDTH = 1024;
const GAME_HEIGHT = 768;
const TARGET_UPS = 60;

async function init(): Promise<void> {
  const container = document.getElementById('game-container');
  if (!container) {
    throw new Error('Game container not found');
  }

  const renderer = new Renderer(container, {
    width: GAME_WIDTH,
    height: GAME_HEIGHT,
    smoothing: false,
  });

  const input = new InputManager(renderer.getCanvas());

  const audio = new AudioManager({
    sfxVolume: 0.7,
    musicVolume: 0.5,
  });

  renderer.getCanvas().addEventListener('click', () => {
    audio.initialize().catch(console.error);
  }, { once: true });

  const entityManager = new EntityManager();
  const systemManager = new SystemManager();

  const render = (_interpolation: number, fps: number): void => {
    renderer.clear(0, 0, 0, 1);
    renderer.setColor(1, 1, 1, 1);
    renderer.drawText(`FPS: ${fps}`, 10, 20);
  };

  const gameLoop = new GameLoop(entityManager, systemManager, render, {
    targetUps: TARGET_UPS,
    pauseOnBlur: true,
  });

  gameLoop.start();

  window.addEventListener('beforeunload', () => {
    gameLoop.destroy();
    input.destroy();
    audio.destroy();
  });

  console.log('Crimsonland Remake initialized');
}

if (document.readyState === 'loading') {
  document.addEventListener('DOMContentLoaded', init);
} else {
  init().catch(console.error);
}
