# Contributing to Crimsonland Remake

Thank you for your interest in contributing! This document provides guidelines for development, code style, and the contribution process.

## Development Setup

### Prerequisites

- [Node.js](https://nodejs.org/) 20+ (LTS recommended)
- [pnpm](https://pnpm.io/) 9+ (`npm install -g pnpm`)

### Installation

```bash
# Clone the repository
git clone https://github.com/mitchfultz/crimsonland-remake.git
cd crimsonland-remake

# Install dependencies
make install
# or: pnpm install
```

### Development Server

```bash
# Start dev server with hot reload
make dev
# or: pnpm run dev

# Open http://localhost:5173
```

### Running Tests

```bash
# Run all tests
make test
# or: pnpm run test

# Run tests in watch mode
pnpm run test:watch

# Run tests with coverage
pnpm run test:coverage
```

### Code Quality

```bash
# Run linter
make lint
# or: pnpm run lint

# Run linter with auto-fix
pnpm run lint:fix

# Run type checker
make type-check
# or: pnpm run type-check

# Run full CI gate (runs all checks)
make ci
# or: pnpm run ci
```

## Project Structure

```
src/
├── core/                    # Framework layer
│   ├── ecs/                 # Entity Component System
│   │   ├── Entity.ts        # Entity with components
│   │   ├── EntityManager.ts # Entity lifecycle and queries
│   │   └── System.ts        # Base system class
│   ├── math/                # Vector math utilities
│   │   └── Vector2.ts       # 2D vector operations
│   └── GameLoop.ts          # Fixed timestep game loop
├── engine/                  # Engine layer (replaces grim.dll)
│   ├── Renderer.ts          # Canvas 2D wrapper
│   ├── InputManager.ts      # Input abstraction
│   ├── AudioManager.ts      # Web Audio API wrapper
│   ├── ParticleSystem.ts    # Visual effects
│   └── SpriteAtlas.ts       # Sprite sheet management
├── game/                    # Game layer
│   ├── components.ts        # All component definitions
│   ├── entities/            # Entity factory functions
│   ├── systems/             # Game systems
│   ├── data/                # Game data (weapons, creatures, etc.)
│   ├── modes/               # Game modes
│   └── ui/                  # In-game UI
├── types/                   # TypeScript type definitions
└── main.ts                  # Entry point
```

## Code Style

We use [Biome](https://biomejs.dev/) for linting and formatting. Configuration is in `biome.json`.

### TypeScript Guidelines

#### Use Strict Mode

All code must compile with TypeScript strict mode enabled. No `any` types without justification.

```typescript
// Good
function processPlayer(player: Player): void {
  // Type-safe access
}

// Bad
function processPlayer(player: any): void {
  // No type safety
}
```

#### Prefer Interfaces Over Types

For object shapes, use interfaces:

```typescript
// Good
interface WeaponData {
  name: string;
  damage: number;
}

// Acceptable for unions
type WeaponId = WeaponId.PISTOL | WeaponId.SHOTGUN;
```

#### Use const for Immutable Values

```typescript
// Good
const MAX_ENEMIES = 100;
const playerSpeed = 200;

// Bad
let MAX_ENEMIES = 100;  // Never reassigned
```

#### Explicit Return Types

Public functions should have explicit return types:

```typescript
// Good
export function calculateDamage(
  weapon: WeaponData,
  distance: number
): number {
  return weapon.damage * (1 - distance * 0.001);
}

// Acceptable for simple cases
export const double = (x: number): number => x * 2;
```

#### Null Checks

Always handle potentially undefined values:

```typescript
// Good
const player = entity.getComponent<'player'>('player');
if (player) {
  player.health -= damage;
}

// Or with optional chaining
const health = entity.getComponent<'player'>('player')?.health ?? 0;

// Bad
const player = entity.getComponent<'player'>('player');
player.health -= damage;  // May throw if undefined
```

### Naming Conventions

| Category | Convention | Example |
|----------|------------|---------|
| Classes | PascalCase | `EntityManager` |
| Interfaces | PascalCase | `WeaponData` |
| Type aliases | PascalCase | `EntityId` |
| Enums | PascalCase | `WeaponId` |
| Enum members | SCREAMING_SNAKE_CASE | `PISTOL`, `ASSAULT_RIFLE` |
| Functions | camelCase | `createPlayer()` |
| Variables | camelCase | `playerHealth` |
| Constants | SCREAMING_SNAKE_CASE | `MAX_ENTITIES` |
| Private members | _camelCase with underscore | `_privateField` |

### File Organization

- One class/interface per file (generally)
- Co-locate related types and factory functions
- Keep files under 500 lines when possible

```typescript
// components.ts pattern
export interface Player extends Component {
  type: 'player';
  health: number;
  // ...
}

export function createPlayer(options?: Partial<Player>): Player {
  return {
    type: 'player',
    health: 100,
    // ... defaults
    ...options,
  };
}
```

## Architecture Guidelines

### ECS Pattern

The game uses Entity-Component-System architecture:

- **Entities**: Lightweight IDs with component containers
- **Components**: Pure data, no logic
- **Systems**: Process entities with specific components

#### Creating a New Component

```typescript
// In components.ts or new file
export interface MyComponent extends Component {
  type: 'myComponent';
  value: number;
}

export function createMyComponent(value: number): MyComponent {
  return {
    type: 'myComponent',
    value,
  };
}

// Add to ComponentTypeMap
type GameComponent = 
  | // ... existing components
  | MyComponent;

interface ComponentTypeMap {
  // ... existing mappings
  myComponent: MyComponent;
}
```

#### Creating a New System

```typescript
import { System, type UpdateContext } from '../core/ecs/System';
import type { EntityManager } from '../core/ecs/EntityManager';

export class MySystem extends System {
  readonly name = 'MySystem';
  readonly priority = 50;  // See priority guidelines below
  
  update(entityManager: EntityManager, context: UpdateContext): void {
    const entities = entityManager.query(['myComponent', 'transform']);
    
    for (const entity of entities) {
      const myComp = entity.getComponent<'myComponent'>('myComponent');
      const transform = entity.getComponent<'transform'>('transform');
      
      if (!myComp || !transform) continue;
      
      // System logic here
    }
  }
  
  destroy(): void {
    // Cleanup if needed
  }
}
```

### System Priority Guidelines

Systems execute in priority order (lower = earlier):

```
Priority 10:  Input handling
Priority 30:  Weapon updates (before movement)
Priority 40:  AI decisions
Priority 50:  Movement (after AI sets velocity)
Priority 60:  Collision detection
Priority 70:  Health/damage application
Priority 80:  Spawning new entities
Priority 90:  Bonus/pickup handling
Priority 100: Rendering (always last)
```

When adding a new system, choose an appropriate priority that respects dependencies.

### State Management

- Prefer component data over module-level state
- Keep system state minimal
- Use `destroy()` for cleanup

```typescript
// Good: State in component
interface Player extends Component {
  type: 'player';
  score: number;
}

// Acceptable: Module cache for performance
const pathCache = new Map<EntityId, Path>();

// Clean up
destroy(): void {
  pathCache.clear();
}
```

## Testing Guidelines

### Unit Tests

Place tests in `tests/unit/` mirroring the source structure:

```typescript
// tests/unit/game/systems/MySystem.test.ts
import { describe, it, expect } from 'vitest';
import { MySystem } from '../../../../src/game/systems/MySystem';
import { EntityManager } from '../../../../src/core/ecs/EntityManager';

describe('MySystem', () => {
  it('should process entities with myComponent', () => {
    const entityManager = new EntityManager();
    const system = new MySystem();
    
    // Create test entity
    const entity = entityManager.createEntity();
    entity.addComponent(createMyComponent(100));
    
    // Run system
    system.update(entityManager, { dt: 0.016, gameTime: 0, frameNumber: 0 });
    
    // Assert
    expect(entity.getComponent<'myComponent'>('myComponent')?.value).toBe(99);
  });
});
```

### Integration Tests

For testing system interactions:

```typescript
// tests/integration/Combat.test.ts
import { describe, it, expect } from 'vitest';

describe('Combat Integration', () => {
  it('should damage creature when projectile hits', () => {
    // Set up game state with player, weapon, creature
    // Fire weapon
    // Step collision system
    // Assert creature took damage
  });
});
```

### Test Data

Use factory functions to create test data:

```typescript
function createTestPlayer(overrides?: Partial<Player>): Player {
  return createPlayer({
    health: 100,
    weaponId: WeaponId.PISTOL,
    ...overrides,
  });
}
```

## Documentation

### Code Comments

```typescript
/**
 * Calculates weapon damage with distance falloff.
 * 
 * @param weapon - Weapon data containing base damage
 * @param distance - Distance to target in pixels
 * @returns Final damage value, minimum 1
 */
function calculateDamage(weapon: WeaponData, distance: number): number {
  // Apply 10% damage reduction per 100 pixels
  const falloff = Math.floor(distance / 100) * 0.1;
  return Math.max(1, weapon.damage * (1 - falloff));
}
```

### Documentation Files

When adding significant features, update relevant docs:

- `docs/ARCHITECTURE.md` - System design changes
- `docs/LESSONS_LEARNED.md` - New insights from implementation
- `docs/MAPPING.md` - New C-to-TypeScript patterns
- `README.md` - User-facing feature documentation

## Pull Request Process

1. **Fork and branch**: Create a feature branch (`git checkout -b feature/my-feature`)
2. **Make changes**: Follow code style and architecture guidelines
3. **Test**: Ensure all tests pass (`make ci`)
4. **Document**: Update relevant documentation
5. **Commit**: Use clear commit messages
6. **Push**: Push to your fork
7. **PR**: Open a pull request with:
   - Clear description of changes
   - Reference to any related issues
   - Screenshots/GIFs for visual changes

### Commit Message Format

```
type(scope): subject

body (optional)

footer (optional)
```

Types:
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code style (formatting, no logic change)
- `refactor`: Code refactoring
- `test`: Test changes
- `chore`: Build/config changes

Examples:
```
feat(weapons): add plasma rifle

Adds the plasma rifle weapon type with unique projectile behavior.
Plasma projectiles pierce through enemies and deal damage over time.

fix(ai): prevent creatures from getting stuck on corners

docs(readme): update control mappings
```

## Game Balance Changes

When modifying game balance (weapon stats, creature health, perk effects):

1. Document the change reason in PR description
2. Consider adding a test for the new value
3. Update relevant data file documentation
4. If significant, update `docs/LESSONS_LEARNED.md` with rationale

## Questions?

- Open an issue for discussion
- Check existing documentation in `docs/`
- Review similar code in the codebase

## Code of Conduct

- Be respectful and constructive
- Focus on the code, not the person
- Welcome newcomers and help them learn
- Assume good intent

Thank you for contributing to Crimsonland Remake!
