# Crimsonland Remake

A browser-based remake of Crimsonland, a top-down shooter originally released in 2003.
This project is based on analysis of the decompiled C source code from the original game.

## Play Online

🎮 **[Play the game here](https://mitchfultz.github.io/crimsonland-remake/)**

## Features

### Game Modes
- **Survival Mode**: Fight endless waves of enemies with leveling and perks
- **Quest Mode**: Complete 21 unique challenges with specific objectives

### Combat System
- 20+ weapon types (pistols, rifles, shotguns, plasma weapons, and more)
- 8 enemy types with unique AI behaviors (zombies, spiders, aliens, ghosts)
- 30+ perks that modify gameplay (fast shot, regeneration, pyromaniac, etc.)

### Visual Effects
- Particle system for explosions, blood splatter, muzzle flashes
- Screen shake effects on damage and explosions
- Glow effects for powerups and active abilities
- Smooth camera following with view shake

### UI
- Main menu with animated background particles
- Pause menu with game stats
- Game over/victory screens with score tracking
- Perk selection interface
- Quest selection menu with progression tracking

### Controls
- **Keyboard**: WASD to move, Mouse to aim, Click to fire, R to reload
- **Touch**: Virtual joystick and on-screen buttons (auto-enabled on touch devices)
- **Hotkeys**: Escape for pause, F3 to toggle FPS counter

## Tech Stack

- **Language:** TypeScript 5.7+ (strict mode)
- **Rendering:** HTML5 Canvas 2D API
- **Audio:** Web Audio API
- **Build:** Vite 6
- **Package Manager:** pnpm
- **Linting/Formatting:** Biome
- **Testing:** Vitest + jsdom

## Project Structure

```
/
├── src/
│   ├── core/
│   │   ├── ecs/           # Entity Component System
│   │   ├── math/          # Vector2, Rectangle, utilities
│   │   └── GameLoop.ts    # Fixed timestep game loop
│   ├── engine/
│   │   ├── Renderer.ts    # Canvas 2D wrapper with effects
│   │   ├── InputManager.ts # Keyboard, mouse, touch input
│   │   ├── AudioManager.ts # Web Audio API wrapper
│   │   └── ParticleSystem.ts # Visual effects system
│   ├── game/
│   │   ├── components.ts  # Game component definitions
│   │   ├── entities/      # Entity factories
│   │   ├── systems/       # Game systems (movement, collision, etc.)
│   │   ├── modes/         # Quest, Survival game modes
│   │   ├── data/          # Weapon, creature, perk definitions
│   │   ├── ui/            # In-game UI components
│   │   └── progression/   # Stats and unlock tracking
│   ├── types/             # TypeScript type definitions
│   └── main.ts            # Entry point
├── tests/
│   └── unit/              # Unit tests
├── public/
│   └── assets/            # Images, audio, fonts
└── index.html
```

## Development

```bash
# Install dependencies
make install

# Start dev server
make dev

# Run tests
make test

# Run linting
make lint

# Type check
make type-check

# Build for production
make build

# Preview production build
make preview

# Run full CI gate
make ci
```

## Original Game Analysis

The decompiled C source reveals the following key systems:

### Core Systems
- **Player:** Health, experience/leveling, weapons, perks
- **Creatures:** 8+ enemy types with AI state machines
- **Projectiles:** 20+ weapon types with unique behaviors
- **Perks:** 30+ passive bonuses
- **Quests:** 25+ named quest scenarios
- **Game Modes:** Quest, Survival, Rush, Tutorial

### Engine (grim.dll replacement)
- Direct3D 8 wrapper replaced with Canvas 2D
- DirectSound replaced with Web Audio API
- DirectInput replaced with standard DOM events

## Deployment

The project is deployed to GitHub Pages using local deployment (no GitHub Actions).

### Quick Deploy

```bash
make deploy
```

This builds the project and deploys to GitHub Pages using the `gh-pages` CLI.

### Prerequisites

- Node.js 20+ and pnpm
- GitHub CLI authenticated with repo write access

For detailed deployment instructions, see [docs/DEPLOYMENT.md](docs/DEPLOYMENT.md).

## Mobile Support

The game supports touch controls on mobile devices:
- Virtual joystick on the left for movement
- Fire button on the right
- Reload button above fire
- Touch controls are automatically enabled on touch-capable devices

## License

MIT
