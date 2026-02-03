# C-to-TypeScript Mapping Guide

This document provides a reference for how patterns from the decompiled C source were translated to TypeScript.

## Function Mapping

### Player Functions

| C Function | TypeScript Location | Notes |
|------------|---------------------|-------|
| `player_init(int idx)` | `entities/Player.ts`: `createPlayer()` | Returns component instead of mutating global |
| `player_update(int idx, float dt)` | `systems/InputSystem.ts` + `WeaponSystem.ts` | Split into multiple systems |
| `player_weapon_fire(int idx)` | `WeaponSystem.fireWeapon()` | Includes spread logic |
| `player_weapon_reload(int idx)` | `WeaponSystem.updateWeapon()` | Handles reload timing |
| `player_damage(int idx, int dmg)` | `HealthSystem.update()` | Applies damage with modifiers |
| `player_add_perk(int idx, int perk)` | `PerkSystem.applyPerk()` | Validates prerequisites |
| `player_level_up(int idx)` | `PlayerSystem.update()` | Triggers perk selection UI |

### Creature Functions

| C Function | TypeScript Location | Notes |
|------------|---------------------|-------|
| `creature_spawn(int type, float x, float y)` | `entities/Creature.ts`: `createCreatureEntity()` | Factory function with components |
| `creature_update_all(float dt)` | `AiSystem.update()` + `MovementSystem.update()` | Split AI and movement |
| `creature_update_ai(int idx)` | `AiSystem.updateAiMode()` | Runs every 70 ticks |
| `creature_damage(int idx, int dmg)` | `HealthSystem.update()` | Death spawns loot |
| `creature_die(int idx)` | `HealthSystem.destroyEntity()` + effects | Spawns particles |

### Projectile Functions

| C Function | TypeScript Location | Notes |
|------------|---------------------|-------|
| `projectile_spawn(...)` | `WeaponSystem.fireWeapon()` | Created per shot |
| `projectile_update_all(float dt)` | `ProjectileSystem.update()` + `MovementSystem.update()` | Position + lifetime |
| `projectile_hit_check(int idx)` | `CollisionSystem.update()` | Layer-based collision |

## Data Structure Mapping

### Structs to Interfaces

#### C Struct
```c
typedef struct {
  float x;
  float y;
  float rotation;
  float scale_x;
  float scale_y;
} transform;
```

#### TypeScript Interface
```typescript
export interface Transform extends Component {
  type: 'transform';
  x: number;
  y: number;
  rotation: number;
  scaleX: number;
  scaleY: number;
}
```

**Key changes:**
- `scale_x` → `scaleX` (TypeScript naming convention)
- Added `type` discriminator for union type narrowing
- Extends `Component` base interface

### Global Tables to Records

#### C Global Array
```c
#define MAX_WEAPONS 20
typedef struct {
  char name[32];
  int damage;
  float fire_rate;
  int clip_size;
  float reload_time;
  float spread;
  int pellet_count;
  int projectile_type;
  float move_speed_mult;
  int automatic;
  int unlock_xp;
} weapon_data;

weapon_data weapon_table[MAX_WEAPONS];

void weapon_table_init(void) {
  strcpy(weapon_table[WEAPON_PISTOL].name, "Pistol");
  weapon_table[WEAPON_PISTOL].damage = 15;
  weapon_table[WEAPON_PISTOL].fire_rate = 0.3f;
  // ...
}
```

#### TypeScript Record
```typescript
export interface WeaponData {
  name: string;
  damage: number;
  fireRate: number;
  clipSize: number;
  reloadTime: number;
  spread: number;
  pelletCount: number;
  projectileType: ProjectileTypeId;
  moveSpeedMultiplier: number;
  automatic: boolean;
  unlockXp: number;
}

export const WEAPON_DATA: Record<WeaponId, WeaponData> = {
  [WeaponId.PISTOL]: {
    name: 'Pistol',
    damage: 15,
    fireRate: 0.3,
    clipSize: 12,
    reloadTime: 1.2,
    spread: 0.05,
    pelletCount: 1,
    projectileType: ProjectileTypeId.PISTOL,
    moveSpeedMultiplier: 1.0,
    automatic: false,
    unlockXp: 0,
  },
  // ...
};
```

### Enums

#### C Enum
```c
typedef enum {
  WEAPON_PISTOL = 0,
  WEAPON_SHOTGUN = 1,
  WEAPON_MACHINE_GUN = 2,
  // ...
  WEAPON_COUNT
} weapon_id;
```

#### TypeScript Enum
```typescript
export enum WeaponId {
  PISTOL = 0,
  SHOTGUN = 1,
  MACHINE_GUN = 2,
  // ...
}
```

**Alternative: Union Types**
```typescript
export type WeaponId = 
  | 0   // PISTOL
  | 1   // SHOTGUN
  | 2   // MACHINE_GUN
  // ...
;
```

The enum approach was chosen for:
- Better IDE autocomplete
- Can use `Object.values(WeaponId)` for iteration
- Matches C semantics more closely

## Global State Migration

### Player State

**C Pattern:**
```c
// Global array indexed by player number
player_state player_state_table[4];

void player_heal(int player_idx, int amount) {
  player_state *p = &player_state_table[player_idx];
  p->health = min(p->health + amount, p->max_health);
}
```

**TypeScript Migration:**
```typescript
// Component attached to entity
interface Player extends Component {
  type: 'player';
  playerIndex: number;
  health: number;
  maxHealth: number;
  // ...
}

class HealthSystem extends System {
  update(entityManager: EntityManager): void {
    const entities = entityManager.query(['player', 'health']);
    for (const entity of entities) {
      const player = entity.getComponent<'player'>('player');
      // Heal logic here or in collision with health pickup
    }
  }
}
```

### Entity References

**C Pattern:**
```c
// Integer indices into global tables
typedef struct {
  int owner_player_idx;  // Who fired this projectile
  int target_creature_idx;  // For homing projectiles
} projectile;

void projectile_hit(projectile *p, int creature_idx) {
  creature *c = &creature_table[creature_idx];
  player_state *owner = &player_state_table[p->owner_player_idx];
  
  // Award XP to owner
  owner->experience += c->reward_xp;
}
```

**TypeScript Migration:**
```typescript
// Entity IDs instead of array indices
interface Projectile extends Component {
  type: 'projectile';
  ownerId: EntityId;  // Who fired this
  damage: number;
  // ...
}

class CollisionSystem extends System {
  update(entityManager: EntityManager): void {
    const projectiles = entityManager.query(['projectile', 'transform', 'collider']);
    const creatures = entityManager.query(['creature', 'transform', 'collider']);
    
    for (const projEntity of projectiles) {
      const projectile = projEntity.getComponent<'projectile'>('projectile');
      const owner = entityManager.getEntity(projectile.ownerId);
      const ownerPlayer = owner?.getComponent<'player'>('player');
      
      for (const creatureEntity of creatures) {
        if (this.checkCollision(projEntity, creatureEntity)) {
          const creature = creatureEntity.getComponent<'creature'>('creature');
          
          // Award XP to owner
          if (ownerPlayer) {
            ownerPlayer.experience += creature.rewardValue;
          }
        }
      }
    }
  }
}
```

## Engine API Mapping

### grim.dll Graphics

| grim.dll Function | Canvas 2D Equivalent | Implementation |
|-------------------|---------------------|----------------|
| `grim_begin_frame()` | `ctx.save()` + `ctx.fillRect()` | `Renderer.clear()` |
| `grim_end_frame()` | `ctx.restore()` | Automatic at frame end |
| `grim_draw_rect_filled(x, y, w, h)` | `ctx.fillRect(x, y, w, h)` | `Renderer.drawRect()` |
| `grim_draw_rect_outline(x, y, w, h)` | `ctx.strokeRect(x, y, w, h)` | `Renderer.drawRectOutline()` |
| `grim_draw_circle_filled(x, y, r)` | `ctx.arc() + ctx.fill()` | `Renderer.drawCircle()` |
| `grim_set_color(r, g, b, a)` | `ctx.fillStyle = rgba(...)` | `Renderer.setColor()` |
| `grim_draw_line(x1, y1, x2, y2)` | `ctx.beginPath() + moveTo + lineTo + stroke` | `Renderer.drawLine()` |
| `grim_draw_text(x, y, text)` | `ctx.fillText(text, x, y)` | `Renderer.drawText()` |
| `grim_set_rotation(angle)` | `ctx.rotate(angle)` | Applied during sprite draw |
| `grim_set_translation(x, y)` | `ctx.translate(x, y)` | Applied during sprite draw |
| `grim_set_scale(x, y)` | `ctx.scale(x, y)` | Applied during sprite draw |
| `grim_push_transform()` | `ctx.save()` | `Renderer.pushState()` |
| `grim_pop_transform()` | `ctx.restore()` | `Renderer.popState()` |
| `grim_draw_sprite(tex, x, y)` | `ctx.drawImage(image, x, y)` | `Renderer.drawSprite()` |
| `grim_set_viewport(x, y, w, h)` | `ctx.rect() + ctx.clip()` | `Renderer.setViewport()` |
| `grim_set_camera(x, y, zoom)` | Transform matrix | `Renderer.setCamera()` + `applyCamera()` |

### grim.dll Input

| grim.dll Function | DOM Equivalent | Implementation |
|-------------------|----------------|----------------|
| `grim_get_key(key)` | `keydown`/`keyup` events | `InputManager.isKeyPressed()` |
| `grim_get_mouse_x()` | `mousemove` event | `InputManager.getMousePosition().x` |
| `grim_get_mouse_y()` | `mousemove` event | `InputManager.getMousePosition().y` |
| `grim_get_mouse_button(btn)` | `mousedown`/`mouseup` | `InputManager.isMouseButtonPressed()` |
| `grim_mouse_visible(bool)` | `canvas.style.cursor` | Set in CSS |

### grim.dll Audio

| grim.dll Function | Web Audio Equivalent | Implementation |
|-------------------|---------------------|----------------|
| `grim_sound_load(name, file)` | `fetch()` + `decodeAudioData()` | `AudioManager.loadSample()` |
| `grim_sound_play(name)` | `createBufferSource()` + `start()` | `AudioManager.playSample()` |
| `grim_sound_stop(name)` | `source.stop()` | Track in active sounds map |
| `grim_sound_volume(name, vol)` | `gainNode.gain.value` | `AudioManager.setSfxVolume()` |
| `grim_music_play(name)` | Same as sound with `loop = true` | `AudioManager.playTune()` |
| `grim_music_stop(name)` | `source.stop()` | `AudioManager.stopTune()` |

### grim.dll Time

| grim.dll Function | Browser Equivalent | Implementation |
|-------------------|-------------------|----------------|
| `grim_time_get()` | `performance.now()` | Used in GameLoop |
| `grim_time_delta()` | Calculated from `performance.now()` | `GameLoop` accumulator pattern |
| `grim_sleep(ms)` | `setTimeout()` | Rarely needed with RAF |

### grim.dll File I/O

| grim.dll Function | Browser Equivalent | Implementation |
|-------------------|-------------------|----------------|
| `grim_file_read(path)` | `fetch()` | For loading assets |
| `grim_file_write(path, data)` | `localStorage` | For save games only |
| `grim_config_load()` | `localStorage.getItem()` | Settings persistence |
| `grim_config_save()` | `localStorage.setItem()` | Settings persistence |

## Control Flow Patterns

### Main Game Loop

**C Pattern:**
```c
int main(int argc, char **argv) {
  game_init();
  
  while (game_running) {
    grim_poll_events();  // Handle Windows messages
    
    float dt = grim_time_delta();
    game_update(dt);
    game_render();
    
    grim_swap_buffers();  // Present frame
  }
  
  game_shutdown();
  return 0;
}
```

**TypeScript Pattern:**
```typescript
class Game {
  private loop = new GameLoop(
    this.entityManager,
    this.systemManager,
    this.render.bind(this)
  );
  
  start(): void {
    this.setupInputHandlers();  // DOM events
    this.loop.start();  // requestAnimationFrame
  }
  
  private render(interpolation: number, fps: number): void {
    this.renderer.clear(0, 0, 0, 1);
    this.renderSystem.update(this.entityManager, { dt: 0, interpolation, fps });
  }
}
```

### State Machines

**C Pattern:**
```c
typedef enum {
  AI_IDLE,
  AI_CHASE,
  AI_ATTACK,
  AI_FLEE,
  AI_WANDER
} ai_state;

typedef struct {
  ai_state state;
  float state_timer;
  // ...
} creature;

void creature_update_ai(int idx) {
  creature *c = &creature_table[idx];
  
  switch (c->state) {
    case AI_IDLE:
      if (player_in_range(idx)) {
        c->state = AI_CHASE;
      }
      break;
    case AI_CHASE:
      if (player_in_attack_range(idx)) {
        c->state = AI_ATTACK;
      }
      break;
    // ...
  }
}
```

**TypeScript Pattern:**
```typescript
export enum AiMode {
  IDLE = 'idle',
  CHASE = 'chase',
  ATTACK = 'attack',
  FLEE = 'flee',
  WANDER = 'wander',
}

interface Creature extends Component {
  type: 'creature';
  aiMode: AiMode;
  // ...
}

class AiSystem extends System {
  update(entityManager: EntityManager, context: UpdateContext): void {
    const creatures = entityManager.query(['creature', 'transform']);
    
    for (const entity of creatures) {
      const creature = entity.getComponent<'creature'>('creature');
      
      switch (creature.aiMode) {
        case AiMode.IDLE:
          if (this.isPlayerInRange(entity)) {
            creature.aiMode = AiMode.CHASE;
          }
          break;
        case AiMode.CHASE:
          if (this.isPlayerInAttackRange(entity)) {
            creature.aiMode = AiMode.ATTACK;
          }
          break;
        // ...
      }
    }
  }
}
```

### Callbacks/Function Pointers

**C Pattern:**
```c
typedef void (*button_callback)(void *userdata);

typedef struct {
  char label[32];
  button_callback on_click;
  void *userdata;
} button;

void button_handle_click(button *b) {
  if (b->on_click) {
    b->on_click(b->userdata);
  }
}
```

**TypeScript Pattern:**
```typescript
interface ButtonConfig {
  label: string;
  onClick: () => void;  // Closure captures needed data
}

class Button {
  constructor(private config: ButtonConfig) {}
  
  handleClick(): void {
    this.config.onClick();
  }
}

// Usage
const button = new Button({
  label: 'Start Game',
  onClick: () => this.startGame(),  // Method reference
});
```

## Type Safety Improvements

### Magic Numbers to Constants

**C Pattern:**
```c
// Magic numbers scattered in code
if (player->weapon_id == 5) {  // What is 5?
  // Special plasma rifle handling
}

if (creature->type == 3) {  // What is 3?
  // Spider behavior
}
```

**TypeScript Pattern:**
```typescript
// Centralized, typed constants
if (player.weaponId === WeaponId.PLASMA_RIFLE) {
  // Special plasma rifle handling
}

if (creature.creatureTypeId === CreatureTypeId.SPIDER_LARGE) {
  // Spider behavior
}
```

### Type-Safe Component Access

**C Pattern (unsafe):**
```c
// No compile-time checking
creature *c = &creature_table[idx];
player_state *p = (player_state *)c;  // Oops, wrong cast
printf("%d", p->health);  // Undefined behavior
```

**TypeScript Pattern (safe):**
```typescript
// Compile-time type checking
const creature = entity.getComponent<'creature'>('creature');
const player = entity.getComponent<'player'>('player');

// TypeScript error: 'player' might be undefined
console.log(player.health);  // Error without null check

// Correct usage
if (player) {
  console.log(player.health);  // OK, type narrowed
}
```

### Exhaustive Switch Statements

**C Pattern (can miss cases):**
```c
switch (weapon_id) {
  case WEAPON_PISTOL: return 15;
  case WEAPON_SHOTGUN: return 8;
  // Missing: MACHINE_GUN, RIFLE, etc.
  default: return 10;
}
```

**TypeScript Pattern (exhaustiveness checking):**
```typescript
function getWeaponDamage(weaponId: WeaponId): number {
  switch (weaponId) {
    case WeaponId.PISTOL: return 15;
    case WeaponId.SHOTGUN: return 8;
    // Compiler error if any WeaponId case is missing
    default: 
      const _exhaustive: never = weaponId;
      return 10;
  }
}
```

## Common Idioms

### Vector Operations

**C Pattern:**
```c
typedef struct { float x, y; } vec2;

vec2 vec2_add(vec2 a, vec2 b) {
  return (vec2){ a.x + b.x, a.y + b.y };
}

float vec2_length(vec2 v) {
  return sqrt(v.x * v.x + v.y * v.y);
}

vec2 vec2_normalize(vec2 v) {
  float len = vec2_length(v);
  if (len > 0) {
    return (vec2){ v.x / len, v.y / len };
  }
  return (vec2){ 0, 0 };
}
```

**TypeScript Pattern:**
```typescript
export interface Vector2 {
  x: number;
  y: number;
}

export const Vector2 = {
  add(a: Vector2, b: Vector2): Vector2 {
    return { x: a.x + b.x, y: a.y + b.y };
  },
  
  length(v: Vector2): number {
    return Math.sqrt(v.x * v.x + v.y * v.y);
  },
  
  normalize(v: Vector2): Vector2 {
    const len = Vector2.length(v);
    if (len > 0) {
      return { x: v.x / len, y: v.y / len };
    }
    return { x: 0, y: 0 };
  },
  
  // Additional utilities
  distance(a: Vector2, b: Vector2): number {
    return Vector2.length({ x: a.x - b.x, y: a.y - b.y });
  },
  
  scale(v: Vector2, s: number): Vector2 {
    return { x: v.x * s, y: v.y * s };
  },
};
```

### Random Numbers

**C Pattern:**
```c
#include <stdlib.h>

int random_int(int min, int max) {
  return min + rand() % (max - min + 1);
}

float random_float(void) {
  return (float)rand() / (float)RAND_MAX;
}

float random_range(float min, float max) {
  return min + random_float() * (max - min);
}
```

**TypeScript Pattern:**
```typescript
export const Random = {
  int(min: number, max: number): number {
    return Math.floor(Math.random() * (max - min + 1)) + min;
  },
  
  float(): number {
    return Math.random();
  },
  
  range(min: number, max: number): number {
    return min + Math.random() * (max - min);
  },
  
  // Additional utilities
  bool(): boolean {
    return Math.random() < 0.5;
  },
  
  choice<T>(array: T[]): T {
    return array[Math.floor(Math.random() * array.length)];
  },
  
  // Seeded random (for reproducible gameplay)
  seeded(seed: number): RandomGenerator {
    return new SeededRandom(seed);
  },
};
```

### Object Pooling

**C Pattern:**
```c
#define MAX_PARTICLES 1000

typedef struct {
  float x, y;
  float vx, vy;
  float lifetime;
  int active;
} particle;

particle particle_pool[MAX_PARTICLES];

particle *particle_spawn(float x, float y) {
  for (int i = 0; i < MAX_PARTICLES; i++) {
    if (!particle_pool[i].active) {
      particle_pool[i].active = 1;
      particle_pool[i].x = x;
      particle_pool[i].y = y;
      particle_pool[i].lifetime = 1.0f;
      return &particle_pool[i];
    }
  }
  return NULL;
}

void particle_update_all(float dt) {
  for (int i = 0; i < MAX_PARTICLES; i++) {
    if (particle_pool[i].active) {
      particle_pool[i].lifetime -= dt;
      if (particle_pool[i].lifetime <= 0) {
        particle_pool[i].active = 0;
      }
    }
  }
}
```

**TypeScript Pattern:**
```typescript
class ParticlePool {
  private available: Particle[] = [];
  private inUse: Set<Particle> = new Set();
  private maxSize: number;
  
  constructor(maxSize = 1000) {
    this.maxSize = maxSize;
  }
  
  acquire(): Particle | null {
    // Reuse or create
    const particle = this.available.pop() ?? new Particle();
    
    if (this.inUse.size >= this.maxSize) {
      // Pool exhausted, return null or recycle oldest
      return null;
    }
    
    particle.reset();
    this.inUse.add(particle);
    return particle;
  }
  
  release(particle: Particle): void {
    if (this.inUse.delete(particle)) {
      particle.reset();
      this.available.push(particle);
    }
  }
  
  update(dt: number): void {
    for (const particle of this.inUse) {
      particle.lifetime -= dt;
      if (particle.lifetime <= 0) {
        this.release(particle);
      }
    }
  }
  
  *[Symbol.iterator](): Iterator<Particle> {
    yield* this.inUse;
  }
}
```

This mapping guide should help developers understand how the original C patterns were translated to TypeScript, and serve as a reference for similar reverse engineering projects.
