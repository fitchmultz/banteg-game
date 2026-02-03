# Architecture Documentation

## Overview

This document describes the architecture of the Crimsonland Remake, a browser-based TypeScript reimplementation of the 2003 top-down shooter. The project demonstrates a complete rewrite from decompiled C source to modern web technologies.

## High-Level Architecture

```
┌─────────────────────────────────────────────────────────────────┐
│                        Browser Environment                       │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐         │
│  │  Canvas  │  │   Web    │  │   DOM    │  │  Local   │         │
│  │  2D API  │  │  Audio   │  │  Events  │  │ Storage  │         │
│  └────┬─────┘  └────┬─────┘  └────┬─────┘  └────┬─────┘         │
└───────┼─────────────┼─────────────┼─────────────┼───────────────┘
        │             │             │             │
        ▼             ▼             ▼             ▼
┌─────────────────────────────────────────────────────────────────┐
│                         Engine Layer                             │
│  ┌──────────────┐ ┌──────────────┐ ┌──────────────────────┐     │
│  │   Renderer   │ │InputManager  │ │    AudioManager      │     │
│  │  (Canvas 2D) │ │(Keyboard/   │ │   (Web Audio API)    │     │
│  │              │ │Mouse/Touch) │ │                      │     │
│  └──────────────┘ └──────────────┘ └──────────────────────┘     │
│  ┌──────────────┐ ┌────────────────────────────────────────┐     │
│  │ParticleSystem│ │         SpriteAtlas / Assets           │     │
│  └──────────────┘ └────────────────────────────────────────┘     │
└─────────────────────────────────────────────────────────────────┘
                                │
                                ▼
┌─────────────────────────────────────────────────────────────────┐
│                       Core Framework                             │
│  ┌─────────────────┐  ┌─────────────────┐  ┌────────────────┐   │
│  │  EntityManager  │  │  SystemManager  │  │   GameLoop     │   │
│  │  (ECS storage)  │  │ (Update sched)  │  │(Fixed timestep)│   │
│  └─────────────────┘  └─────────────────┘  └────────────────┘   │
└─────────────────────────────────────────────────────────────────┘
                                │
                                ▼
┌─────────────────────────────────────────────────────────────────┐
│                        Game Layer                                │
│  ┌─────────┐ ┌─────────┐ ┌─────────┐ ┌─────────┐ ┌─────────┐    │
│  │  Input  │ │ Weapon  │ │   AI    │ │Movement │ │Collision│    │
│  │ System  │ │ System  │ │ System  │ │ System  │ │ System  │    │
│  │  (10)   │ │  (30)   │ │  (40)   │ │  (50)   │ │  (60)   │    │
│  └─────────┘ └─────────┘ └─────────┘ └─────────┘ └─────────┘    │
│  ┌─────────┐ ┌─────────┐ ┌─────────┐ ┌─────────┐ ┌─────────┐    │
│  │ Health  │ │ Spawn   │ │  Bonus  │ │  Quest  │ │ Render  │    │
│  │ System  │ │ System  │ │ System  │ │ Spawn   │ │ System  │    │
│  │  (70)   │ │  (80)   │ │  (90)   │ │ System  │ │ (100)   │    │
│  └─────────┘ └─────────┘ └─────────┘ │  (85)   │ └─────────┘    │
│                                      └─────────┘                 │
└─────────────────────────────────────────────────────────────────┘
                                │
                                ▼
┌─────────────────────────────────────────────────────────────────┐
│                         Data Layer                               │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐         │
│  │  weapons │  │ creatures│  │perks.ts  │  │ quests.ts│         │
│  │   .ts    │  │   .ts    │  │          │  │          │         │
│  └──────────┘  └──────────┘  └──────────┘  └──────────┘         │
│  ┌──────────┐  ┌──────────┐  ┌────────────────────────┐         │
│  │projectile│  │progress. │  │     Game Modes         │         │
│  │  s.ts    │  │   ts     │  │ (Survival, Quest, etc) │         │
│  └──────────┘  └──────────┘  └────────────────────────┘         │
└─────────────────────────────────────────────────────────────────┘
```

## ECS Architecture

The game uses an Entity-Component-System (ECS) pattern that closely mirrors the entity tables found in the original C source code.

### Entity Manager

The `EntityManager` maintains a collection of entities, each with a unique ID and a set of components:

```typescript
class EntityManager {
  private entities: Map<EntityId, Entity>;
  private nextId: EntityId;
  private toDestroy: Set<EntityId>;
  
  // Key operations
  createEntity(): Entity
  destroyEntity(id: EntityId): boolean
  query(componentTypes: ComponentType[]): Entity[]
  processDestructions(): void
}
```

### Component Design

Components are plain data objects with factory functions:

| Component | Purpose | Key Fields |
|-----------|---------|------------|
| `Transform` | Position, rotation, scale | `x`, `y`, `rotation`, `scaleX/Y` |
| `Velocity` | Movement vector | `x`, `y`, `maxSpeed` |
| `Player` | Player state | `health`, `level`, `weaponId`, `perkCounts` |
| `Creature` | Enemy state | `creatureTypeId`, `aiMode`, `health`, `tint` |
| `Projectile` | Bullet data | `projectileTypeId`, `damage`, `lifetime`, `pierceCount` |
| `Collider` | Collision detection | `radius`, `layer`, `isTrigger` |
| `Sprite` | Visual representation | `textureName`, `frameCount`, `currentFrame` |
| `Bonus` | Pickup item | `bonusType`, `value`, `lifetime` |

### System Execution Order

Systems are executed in priority order during each update:

```
Priority 10:  InputSystem      - Process keyboard/mouse/touch
Priority 30:  WeaponSystem     - Handle firing, reloading, spread
Priority 40:  AiSystem         - Update creature AI (every 70 ticks)
Priority 50:  MovementSystem   - Apply velocity to position
Priority 60:  CollisionSystem  - Detect and resolve collisions
Priority 70:  HealthSystem     - Apply damage, handle death
Priority 80:  SpawnSystem      - Spawn new enemies/bonuses
Priority 85:  QuestSpawnSystem - Quest-specific spawning logic
Priority 90:  BonusSystem      - Handle perk/bonus pickups
Priority 100: RenderSystem     - Draw everything
```

## Fixed Timestep Game Loop

Based on the `frame_dt_ms` pattern from the original C source, the game uses a fixed timestep of 60 UPS (updates per second):

```typescript
class GameLoop {
  private targetUps = 60;
  private timeStep = 1000 / 60; // ~16.67ms
  private accumulator = 0;
  
  private loop(currentTime: number): void {
    const deltaTime = currentTime - this.lastTime;
    this.accumulator += deltaTime;
    
    // Fixed timestep updates
    while (this.accumulator >= this.timeStep) {
      this.systemManager.update(this.entityManager, context);
      this.entityManager.processDestructions();
      this.accumulator -= this.timeStep;
    }
    
    // Render with interpolation
    const interpolation = this.accumulator / this.timeStep;
    this.render(interpolation, this.currentFps);
  }
}
```

This approach ensures:
- **Deterministic gameplay**: Same input produces same results regardless of frame rate
- **Consistent physics**: 60 updates per second matches the original game's timing
- **Smooth rendering**: Interpolation provides smooth visuals even at varying frame rates

## Engine Layer

### Renderer

Replaces `grim.dll`'s Direct3D 8 wrapper with HTML5 Canvas 2D:

```typescript
class Renderer {
  // Viewport and camera
  setViewport(x, y, width, height)
  setCamera(x, y, zoom, rotation)
  worldToScreen(worldX, worldY)
  screenToWorld(screenX, screenY)
  
  // Drawing operations
  drawSprite(image, frame, x, y, options)
  drawRect(x, y, width, height)
  drawCircle(x, y, radius)
  drawText(text, x, y, fontSize)
  
  // Effects
  shake(intensity, duration, decay)
  drawGlow(x, y, radius, color)
  drawLight(x, y, radius, color, intensity, flicker)
}
```

Key features:
- **Transform stack**: `pushState()` / `popState()` for nested transforms
- **Screen shake**: Camera shake effect for explosions and damage
- **Glow effects**: Radial gradients for powerups and lighting
- **World/screen conversion**: Seamless coordinate space translation

### Input Manager

Replaces DirectInput with DOM event handling:

```typescript
class InputManager {
  // Keyboard
  isKeyPressed(keyCode): boolean
  isKeyJustPressed(keyCode): boolean
  
  // Mouse
  getMousePosition(): Vector2
  isMouseButtonPressed(button): boolean
  
  // Touch (mobile)
  getVirtualJoystick(): Vector2
  isFireButtonPressed(): boolean
  
  // Update (call each frame)
  update(): void
}
```

### Audio Manager

Replaces DirectSound with Web Audio API:

```typescript
class AudioManager {
  async initialize(): Promise<void>
  
  // Sound effects
  loadSample(name, url)
  playSample(name, volume?, pan?)
  
  // Music
  loadTune(name, url)
  playTune(name, loop?)
  stopTune(name)
  
  // Volume control
  setSfxVolume(volume)
  setMusicVolume(volume)
}
```

Features:
- **Spatial audio**: Stereo panning based on screen position
- **Concurrent limiting**: Max 32 simultaneous SFX
- **Automatic resumption**: Handles browser autoplay restrictions

### Particle System

Visual effects for explosions, blood, muzzle flashes:

```typescript
class ParticleSystem {
  emit(config: ParticleConfig, position: Vector2): void
  update(dt: number): void
  render(renderer: Renderer): void
}
```

Particle types:
- **Explosion**: Expanding circle with fade
- **Blood**: Small directional particles
- **Muzzle flash**: Brief bright flash at weapon position
- **Trail**: Continuous particle stream for projectiles

## Game Systems

### AI System

Controls creature behavior with state machine AI:

```typescript
class AiSystem extends System {
  readonly priority = 40;
  
  // AI update interval: 70 ticks at 60 FPS ≈ 1.17 seconds
  private readonly AI_UPDATE_INTERVAL = 70 / 60;
  
  updateAiMode(creature, transform, players, state): void
  executeBehavior(creature, transform, velocity, players, state, dt): void
}
```

AI modes from original source:
- `IDLE`: No movement
- `CHASE`: Move toward nearest player
- `ATTACK`: Stop at attack distance
- `FLEE`: Move away when low health
- `WANDER`: Random movement when no target

### Weapon System

Handles all weapon mechanics including fire rate, reloading, and spread:

```typescript
class WeaponSystem extends System {
  readonly priority = 30;
  
  private updateWeapon(player, transform, dt): void
  private fireWeapon(player, transform, weaponData): void
  private applySpread(baseAngle, spreadAmount): number
}
```

Key mechanics (from decompiled source):
- **Spread accumulation**: Continuous fire increases bullet spread
- **Spread decay**: Spread decreases when not firing
- **Reload interruption**: Can reload-cancel with fire

### Perk System

Manages 30+ perks with complex interactions:

```typescript
class PerkSystem extends System {
  getAvailablePerks(player, allPerks, count): PerkData[]
  applyPerk(player, perkId): void
  getPlayerStatModifier(player, statType): number
}
```

Perk categories:
- **Combat**: Damage, fire rate, reload speed
- **Defense**: Health, regeneration, shields
- **Utility**: XP bonuses, clip size, special abilities
- **Gamble**: High-risk, high-reward perks
- **Special**: Unique mechanics (fire bullets, time slow, etc.)

## Data Definitions

### Weapon Table

Mapped from `weapon_table_init` in decompiled source:

```typescript
interface WeaponData {
  name: string;
  damage: number;
  fireRate: number;      // seconds between shots
  clipSize: number;
  reloadTime: number;    // seconds
  spread: number;        // radians
  pelletCount: number;   // 1 for bullets, >1 for shotguns
  projectileType: ProjectileTypeId;
  moveSpeedMultiplier: number;
  automatic: boolean;
  unlockXp: number;
}
```

### Creature Table

Mapped from `creature_type_table` in decompiled source:

```typescript
interface CreatureData {
  name: string;
  health: number;
  speed: number;         // units per second
  size: number;          // visual scale
  hitboxRadius: number;
  contactDamage: number;
  rewardXP: number;
  defaultAiMode: AiMode;
  spawnWeight: number;   // for random spawning
  minWave: number;       // minimum wave to appear
}
```

### Quest System

21 unique quests mapped from `quest_table`:

```typescript
interface QuestData {
  id: QuestId;
  name: string;
  description: string;
  creatureTypes: CreatureTypeId[];
  spawnRate: number;
  timeLimit?: number;
  killTarget?: number;
  survivalTime?: number;
  rewardBonus?: BonusType;
}
```

## Performance Considerations

### Entity Queries

The ECS uses simple array iteration for queries. For the entity counts in this game (<1000), this is more efficient than complex indexing:

```typescript
query(componentTypes: ComponentType[]): Entity[] {
  const results: Entity[] = [];
  for (const entity of this.entities.values()) {
    if (entity.hasComponents(componentTypes)) {
      results.push(entity);
    }
  }
  return results;
}
```

### Collision Detection

Simple O(n²) collision with layer filtering:

```typescript
// Only check collisions between relevant layers
if ((layerA & targetLayersB) === 0) continue;

// Distance check
const dx = posA.x - posB.x;
const dy = posA.y - posB.y;
const distanceSquared = dx * dx + dy * dy;
const minDistance = radiusA + radiusB;
if (distanceSquared <= minDistance * minDistance) {
  // Collision detected
}
```

### Rendering Optimizations

- **Dirty rectangle tracking**: Only redraw changed regions
- **Batch drawing**: Group similar draw calls where possible
- **Viewport culling**: Skip entities outside camera view
- **Particle pooling**: Reuse particle objects to reduce GC

## File Organization

```
src/
├── core/                    # Framework layer
│   ├── ecs/                 # Entity Component System
│   │   ├── Entity.ts
│   │   ├── EntityManager.ts
│   │   └── System.ts
│   ├── math/                # Vector math utilities
│   │   └── Vector2.ts
│   └── GameLoop.ts          # Fixed timestep loop
├── engine/                  # Engine layer (grim.dll replacement)
│   ├── Renderer.ts          # Canvas 2D wrapper
│   ├── InputManager.ts      # Input abstraction
│   ├── AudioManager.ts      # Web Audio wrapper
│   ├── ParticleSystem.ts    # Visual effects
│   └── SpriteAtlas.ts       # Sprite sheet management
├── game/                    # Game layer
│   ├── components.ts        # All component definitions
│   ├── entities/            # Entity factory functions
│   │   ├── Player.ts
│   │   ├── Creature.ts
│   │   └── Projectile.ts
│   ├── systems/             # All game systems
│   │   ├── InputSystem.ts
│   │   ├── WeaponSystem.ts
│   │   ├── AiSystem.ts
│   │   └── ...
│   ├── data/                # Game data tables
│   │   ├── weapons.ts
│   │   ├── creatures.ts
│   │   ├── perks.ts
│   │   └── quests.ts
│   ├── modes/               # Game modes
│   │   ├── SurvivalMode.ts
│   │   └── QuestMode.ts
│   └── ui/                  # In-game UI
└── main.ts                  # Entry point
```

## Key Design Decisions

### 1. TypeScript Strict Mode

The entire project uses TypeScript strict mode for maximum type safety. This caught numerous translation errors during development.

### 2. Factory Functions Over Classes

Components use factory functions instead of classes:

```typescript
// Preferred
export function createPlayer(playerIndex = 0): Player {
  return { type: 'player', playerIndex, health: 100, ... };
}

// Avoided
class PlayerComponent implements Component { ... }
```

This approach:
- Makes components plain objects (easier serialization)
- Allows simple object spread for defaults
- Reduces `this` binding issues

### 3. Module-Level State for System Data

Some systems maintain private state at module level:

```typescript
// AiSystem.ts
const aiStates = new Map<number, AiState>();
```

This is acceptable because:
- State is tied to entity lifecycle
- System instances are singletons
- Cleanup happens in `destroy()` method

### 4. Type-Safe Component Access

Components are accessed with type-safe keys:

```typescript
const player = entity.getComponent<'player'>('player');
// TypeScript knows player is Player | undefined
```

## Testing Strategy

- **Unit tests**: Individual systems in isolation
- **Integration tests**: System interactions
- **Visual regression**: Screenshot comparisons for rendering
- **Balance testing**: Automated perk/weapon balance verification

## Future Enhancements

Potential areas for extension:

1. **WebGL Renderer**: For better performance with more entities
2. **Web Workers**: Move physics/collision to background thread
3. **Network Multiplayer**: WebRTC or WebSocket-based
4. **Level Editor**: Browser-based quest editor
5. **Mod Support**: Load external quest/weapon definitions
