# Crimsonland Remake

A browser-based remake of Crimsonland, a top-down shooter originally released in 2003.
This project is based on analysis of the decompiled C source code from the original game.

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
│   │   ├── Renderer.ts    # Canvas 2D wrapper
│   │   ├── InputManager.ts
│   │   └── AudioManager.ts
│   ├── game/
│   │   ├── components.ts  # Game component definitions
│   │   ├── entities/      # Entity factories
│   │   ├── systems/       # Game systems
│   │   ├── modes/         # Quest, Survival, Rush modes
│   │   └── data/          # Weapon, creature, perk definitions
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

## License

MIT
