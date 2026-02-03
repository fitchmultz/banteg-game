# Lessons Learned: From Decompiled C to Browser Game

## Introduction

This document captures the lessons learned during the process of rewriting Crimsonland (2003) from decompiled C source code to a modern browser-based TypeScript implementation. This project represents approximately 14 days of reverse engineering work already completed in the decompiled source files.

## The Decompiled Source

### What We Received

The decompiled source consisted of two files totaling ~3.5MB:

| File | Size | Contents |
|------|------|----------|
| `crimsonland.exe_decompiled.c` | ~2MB | Main game logic: player, creatures, weapons, perks, quests |
| `grim.dll_decompiled.c` | ~1.5MB | Engine layer: Direct3D 8, DirectSound, DirectInput, file I/O |

### The Reverse Engineering Work

The original reverse engineering had already:

1. **Named functions**: Converted `FUN_004010f0` to descriptive names like `player_update`
2. **Typed variables**: Added proper C types to previously untyped data
3. **Identified structures**: Mapped out structs for weapons, creatures, perks
4. **Documented behavior**: Comments explaining what functions do

Example from the decompiled source:

```c
/* player_weapon_fire @ 0040a5f0 */
/* handles weapon firing logic including spread calculation */
void player_weapon_fire(int player_idx) {
  player_state *p = &player_state_table[player_idx];
  weapon_data *w = &weapon_table[p->weapon_id];
  
  // Calculate spread based on continuous fire
  float spread = w->base_spread + p->spread_accumulator;
  p->spread_accumulator = min(p->spread_accumulator + 0.02f, w->max_spread);
  
  // Spawn projectile
  projectile_spawn(p->x, p->y, p->aim_angle + spread_random(-spread, spread), ...);
}
```

## Understanding the Original Architecture

### grim.dll: The Engine Abstraction

The original game used `grim.dll` as a thin wrapper around Windows APIs:

```c
// grim.dll provided these abstractions:
grim_begin_frame()      // Clear backbuffer, begin D3D scene
grim_end_frame()        // Present backbuffer
grim_draw_sprite()      // Draw textured quad
grim_draw_rect()        // Draw colored rectangle
grim_play_sound()       // DirectSound buffer playback
grim_get_key()          // DirectInput key state
grim_load_texture()     // D3D texture creation
```

This abstraction was designed for:
- **Portability**: Easier to port to different Windows versions
- **Simplicity**: Simpler API than raw DirectX
- **Batching**: Could optimize draw calls

### Frame-Based Timing

The original used fixed 60 FPS timing:

```c
// From decompiled source
#define FRAME_DT_MS 16.666f  // 60 FPS

void game_update(void) {
  // All gameplay logic assumes 16.67ms per frame
  player_update(FRAME_DT_MS);
  creature_update_all(FRAME_DT_MS);
  projectile_update_all(FRAME_DT_MS);
}
```

This design choice made the game:
- **Deterministic**: Same input always produces same output
- **Speed-sensitive**: Running at 120 FPS would double game speed
- **Simple**: No delta time calculations needed

### Global State Tables

The original used global arrays for all game entities:

```c
// From decompiled source
player_state player_state_table[4];     // Max 4 players
creature creature_table[256];           // Max 256 enemies
projectile projectile_table[512];       // Max 512 bullets
bonus bonus_table[64];                  // Max 64 pickups

// Entities referenced by index
void creature_damage(int creature_idx, int damage) {
  creature *c = &creature_table[creature_idx];
  c->health -= damage;
  if (c->health <= 0) {
    creature_die(creature_idx);
  }
}
```

This approach:
- **Pros**: Simple, cache-friendly, no memory allocation during gameplay
- **Cons**: Fixed limits, manual lifecycle management, global state

## Mapping C Patterns to TypeScript

### Global State → Component Data

**C Pattern:**
```c
typedef struct {
  float x, y;
  float health;
  int weapon_id;
  // ...
} player_state;

player_state player_state_table[4];
```

**TypeScript ECS:**
```typescript
interface Player extends Component {
  type: 'player';
  health: number;
  weaponId: WeaponId;
  // ...
}

interface Transform extends Component {
  type: 'transform';
  x: number;
  y: number;
}

// Entity has both components
entity.addComponent(createPlayer());
entity.addComponent(createTransform(x, y));
```

### Function Pointers → System Methods

**C Pattern:**
```c
typedef void (*update_func)(float dt);

typedef struct {
  update_func update;
  void (*render)(void);
} game_system;

game_system systems[] = {
  { player_update, player_render },
  { creature_update, creature_render },
  // ...
};

void game_update_all(float dt) {
  for (int i = 0; i < num_systems; i++) {
    systems[i].update(dt);
  }
}
```

**TypeScript:**
```typescript
abstract class System {
  abstract readonly name: string;
  abstract readonly priority: number;
  abstract update(entityManager: EntityManager, context: UpdateContext): void;
}

class PlayerSystem extends System {
  readonly name = 'PlayerSystem';
  readonly priority = 10;
  
  update(entityManager: EntityManager, context: UpdateContext): void {
    // Process all player entities
  }
}
```

### Fixed Arrays → Maps and Sets

**C Pattern:**
```c
#define MAX_CREATURES 256
creature creature_table[MAX_CREATURES];
int creature_active[MAX_CREATURES];  // 0 = inactive, 1 = active

int creature_spawn(creature_type type, float x, float y) {
  // Find first inactive slot
  for (int i = 0; i < MAX_CREATURES; i++) {
    if (!creature_active[i]) {
      creature_table[i].type = type;
      creature_table[i].x = x;
      creature_table[i].y = y;
      creature_active[i] = 1;
      return i;  // Return index as handle
    }
  }
  return -1;  // Failed to spawn
}
```

**TypeScript:**
```typescript
class EntityManager {
  private entities: Map<EntityId, Entity>;
  private nextId: EntityId = 1;
  private toDestroy: Set<EntityId>;
  
  createEntity(): Entity {
    const id = this.nextId++;
    const entity = new Entity(id);
    this.entities.set(id, entity);
    return entity;
  }
  
  destroyEntity(id: EntityId): void {
    this.toDestroy.add(id);  // Defer destruction
  }
  
  processDestructions(): void {
    for (const id of this.toDestroy) {
      this.entities.delete(id);
    }
    this.toDestroy.clear();
  }
}
```

### Manual Memory Management → GC + Object Pools

The original C code manually managed memory:
```c
// Original allocated particles from a fixed pool
particle *particle_alloc(void) {
  for (int i = 0; i < MAX_PARTICLES; i++) {
    if (!particle_pool[i].active) {
      particle_pool[i].active = 1;
      return &particle_pool[i];
    }
  }
  return NULL;  // Pool exhausted
}

void particle_free(particle *p) {
  p->active = 0;
}
```

In TypeScript, we rely on garbage collection but use object pooling for frequently created/destroyed objects:
```typescript
class ParticlePool {
  private available: Particle[] = [];
  private inUse: Set<Particle> = new Set();
  
  acquire(): Particle {
    const particle = this.available.pop() ?? new Particle();
    this.inUse.add(particle);
    return particle;
  }
  
  release(particle: Particle): void {
    this.inUse.delete(particle);
    particle.reset();
    this.available.push(particle);
  }
}
```

### Structs → Interfaces with Factory Functions

**C Pattern:**
```c
typedef struct {
  int damage;
  float fire_rate;
  int clip_size;
  // ...
} weapon_data;

weapon_data weapon_table[] = {
  { 15, 0.3f, 12, /* ... */ },  // Pistol
  { 12, 0.1f, 30, /* ... */ },  // Assault Rifle
  // ...
};
```

**TypeScript:**
```typescript
export interface WeaponData {
  name: string;
  damage: number;
  fireRate: number;
  clipSize: number;
  // ...
}

export const WEAPON_DATA: Record<WeaponId, WeaponData> = {
  [WeaponId.PISTOL]: {
    name: 'Pistol',
    damage: 15,
    fireRate: 0.3,
    clipSize: 12,
    // ...
  },
  [WeaponId.ASSAULT_RIFLE]: {
    name: 'Assault Rifle',
    damage: 12,
    fireRate: 0.1,
    clipSize: 30,
    // ...
  },
};
```

## Engine Replacement Strategy

### Direct3D 8 → Canvas 2D

The original used Direct3D 8 for rendering. We replaced this with HTML5 Canvas 2D:

| Original (grim.dll) | Replacement (Renderer.ts) |
|---------------------|---------------------------|
| `grim_begin_frame()` | `ctx.save()` + `ctx.fillRect()` (clear) |
| `grim_end_frame()` | `ctx.restore()` |
| `grim_draw_rect_filled(x, y, w, h)` | `ctx.fillRect(x, y, w, h)` |
| `grim_set_color(r, g, b, a)` | `ctx.fillStyle = rgba(...)` |
| `grim_draw_sprite(tex, x, y)` | `ctx.drawImage(image, x, y)` |
| `grim_set_rotation(angle)` | `ctx.rotate(angle)` |
| `grim_set_translation(x, y)` | `ctx.translate(x, y)` |
| `grim_push_transform()` | `ctx.save()` |
| `grim_pop_transform()` | `ctx.restore()` |

**Key differences:**
- D3D uses a retained mode (build display lists), Canvas 2D is immediate mode
- D3D has hardware acceleration for transforms, Canvas 2D is software (mostly)
- D3D textures are GPU resident, Canvas 2D images are CPU → GPU each frame

### DirectSound → Web Audio API

| Original (grim.dll) | Replacement (AudioManager.ts) |
|---------------------|-------------------------------|
| `grim_sound_load(name, file)` | `fetch()` + `decodeAudioData()` |
| `grim_sound_play(name)` | `createBufferSource()` + `start()` |
| `grim_sound_pan(name, pan)` | `createStereoPanner()` |
| `grim_music_play(name)` | Same as sound, with `loop = true` |
| `grim_volume_set(vol)` | `gainNode.gain.value = vol` |

**Challenges:**
- Web Audio requires user interaction before playing (autoplay policy)
- No direct equivalent to DirectSound's 3D positional audio
- Audio files must be fetched asynchronously

### DirectInput → DOM Events

| Original (grim.dll) | Replacement (InputManager.ts) |
|---------------------|-------------------------------|
| `grim_get_key(keycode)` | `event.key` in `keydown`/`keyup` handlers |
| `grim_get_mouse_pos(x, y)` | `event.clientX` / `event.clientY` |
| `grim_get_mouse_button(btn)` | `event.buttons` in `mousedown`/`mouseup` |

**Mobile addition:**
- Virtual joystick using touch events
- On-screen buttons for fire/reload

## Key Insights from Decompiled Code

### AI Update Tick

The original AI only updated every 70 ticks (~1.17 seconds at 60 FPS):

```c
// From decompiled source
void creature_update_all(float dt) {
  creature_update_tick++;
  
  for (int i = 0; i < MAX_CREATURES; i++) {
    if (!creature_active[i]) continue;
    
    // Only update AI every 70 ticks
    if (creature_update_tick % 0x46 == 0) {
      creature_update_ai(i);  // Expensive pathfinding/targeting
    }
    
    // Always update movement
    creature_update_movement(i, dt);  // Simple velocity integration
  }
}
```

This optimization:
- **Reduces CPU usage**: AI is expensive, movement is cheap
- **Maintains quality**: 1 second reaction time is acceptable for zombies
- **Scales well**: More enemies doesn't increase AI cost proportionally

### Weapon Spread Mechanics

The decompiled source revealed interesting spread behavior:

```c
// From decompiled source
void player_weapon_fire(int player_idx) {
  player_state *p = &player_state_table[player_idx];
  weapon_data *w = &weapon_table[p->weapon_id];
  
  // Calculate random spread angle
  float spread_angle = w->base_spread + p->spread_accumulator;
  float fire_angle = p->aim_angle + random_float(-spread_angle, spread_angle);
  
  // Spawn projectile
  projectile_spawn(p->x, p->y, fire_angle, w->projectile_type);
  
  // Accumulate spread for next shot (continuous fire penalty)
  p->spread_accumulator += w->spread_growth;
  if (p->spread_accumulator > w->max_spread) {
    p->spread_accumulator = w->max_spread;
  }
}

void player_update(float dt) {
  // ...
  
  // Decay spread when not firing
  for (int i = 0; i < num_players; i++) {
    player_state *p = &player_state_table[i];
    p->spread_accumulator *= 0.95f;  // 5% decay per frame
  }
}
```

This creates:
- **Tap firing reward**: First shot is accurate
- **Spray penalty**: Continuous fire becomes inaccurate
- **Recovery**: Pause to restore accuracy

### Perk Selection Logic

The perk selection has complex probability weighting:

```c
// Simplified from decompiled source
perk_id select_random_perk(player_state *p) {
  int total_weight = 0;
  int weights[MAX_PERKS];
  
  for (int i = 0; i < num_available_perks; i++) {
    perk_data *perk = &perk_table[available_perks[i]];
    
    // Base weight
    int weight = perk->base_weight;
    
    // Modifiers
    if (perk->is_rare) weight /= 2;
    if (p->has_perk[perk->prereq]) weight *= 2;
    if (perk->incompatible_with != -1 && p->has_perk[perk->incompatible_with]) {
      weight = 0;  // Can't select incompatible perk
    }
    
    // Player level requirement
    if (p->level < perk->min_level) weight = 0;
    
    weights[i] = weight;
    total_weight += weight;
  }
  
  // Weighted random selection
  int roll = random_int(0, total_weight);
  for (int i = 0; i < num_available_perks; i++) {
    roll -= weights[i];
    if (roll <= 0) return available_perks[i];
  }
  
  return available_perks[0];
}
```

This ensures:
- **Rarity system**: Some perks are genuinely rare
- **Synergy**: Prerequisites make certain builds more likely
- **Incompatibility**: Some perk combinations are impossible

### Quest Spawn Patterns

Quests have unique spawn patterns not just based on waves:

```c
// From decompiled source for specific quest
void quest_06_spawn_logic(float game_time) {
  // Spawn pattern: waves of increasing difficulty
  int wave = (int)(game_time / 30);  // New wave every 30 seconds
  
  // First 60 seconds: only zombies
  if (game_time < 60) {
    spawn_creature(CreatureType.ZOMBIE, random_edge_position());
    return;
  }
  
  // 60-120 seconds: zombies + fast zombies
  if (game_time < 120) {
    if (random_float() < 0.3f) {
      spawn_creature(CreatureType.ZOMBIE_FAST, random_edge_position());
    } else {
      spawn_creature(CreatureType.ZOMBIE, random_edge_position());
    }
    return;
  }
  
  // After 120 seconds: all types
  spawn_creature(random_creature_type(), random_edge_position());
}
```

## What Worked Well

### 1. ECS Pattern Natural Fit

The ECS pattern mapped almost directly to the original's entity tables:

```c
// Original: Array of structs with type field
creature_table[i].type = CREATURE_ZOMBIE;
creature_table[i].health = 100;

// New: Component composition
entity.addComponent(createCreature(CreatureType.ZOMBIE));
entity.addComponent(createHealth(100));
```

This made translation straightforward and reduced bugs.

### 2. Fixed Timestep Preserved Game Feel

Maintaining the original's 60 UPS timing was crucial:

```typescript
const timeStep = 1000 / 60; // 16.67ms

while (accumulator >= timeStep) {
  update(timeStep / 1000);
  accumulator -= timeStep;
}
```

This ensures:
- **Identical physics**: Same collision results as original
- **Consistent difficulty**: Enemy spawn rates match
- **Predictable gameplay**: Muscle memory transfers

### 3. TypeScript Strict Mode

Using strict TypeScript caught many translation errors:

```typescript
// Type error: Property 'weapon_id' does not exist
player.weapon_id = newWeapon;  // Error!

// Correct
player.weaponId = newWeapon;   // OK
```

### 4. Component Factories Mirrored C Initialization

The factory functions closely matched C struct initialization:

```c
// C
player_state p = {
  .health = 100,
  .max_health = 100,
  .weapon_id = WEAPON_PISTOL,
  .ammo = 100,
};
```

```typescript
// TypeScript
const player = createPlayer({
  health: 100,
  maxHealth: 100,
  weaponId: WeaponId.PISTOL,
  ammo: 100,
});
```

## Challenges Faced

### 1. Understanding Implicit State Dependencies

The C code often relied on global state ordering:

```c
// This function assumes player_update() was called first
void creature_update(int idx) {
  creature *c = &creature_table[idx];
  // Accesses player_state_table[0] directly
  float dx = player_state_table[0].x - c->x;
  // ...
}
```

In ECS, we had to make dependencies explicit:
```typescript
class AiSystem extends System {
  update(entityManager: EntityManager): void {
    const players = entityManager.query(['player', 'transform']);
    const creatures = entityManager.query(['creature', 'transform']);
    
    for (const creature of creatures) {
      // Explicit dependency: need player positions
      for (const player of players) {
        // Calculate distance...
      }
    }
  }
}
```

### 2. Converting Frame-Based to Time-Based

Some systems needed real-time, not frame counts:

```c
// Original: frame counter
int particle_lifetime_frames = 30;  // Half second at 60 FPS
void particle_update(particle *p) {
  p->lifetime_frames--;
  if (p->lifetime_frames <= 0) particle_destroy(p);
}
```

```typescript
// New: actual time
interface Lifetime extends Component {
  type: 'lifetime';
  remaining: number;  // seconds
}

class LifetimeSystem extends System {
  update(entityManager: EntityManager, context: UpdateContext): void {
    const dt = context.dt;  // actual delta time
    for (const entity of entities) {
      const lifetime = entity.getComponent('lifetime');
      lifetime.remaining -= dt;
      if (lifetime.remaining <= 0) {
        entityManager.destroyEntity(entity.id);
      }
    }
  }
}
```

This change was necessary because:
- Browser frame rates vary (60Hz, 120Hz, 30Hz on battery)
- RequestAnimationFrame doesn't guarantee 60 FPS
- Visual effects should look consistent regardless of FPS

### 3. Reverse-Engineering Binary Data Tables

Some data was only available as binary blobs in the original. We had to:

1. **Identify the format**: Look at struct layouts in decompiled code
2. **Extract values**: Run original game with debug output
3. **Verify correctness**: Compare behavior side-by-side

Example: Weapon stats weren't in the decompiled source as nice tables, but as binary data loaded into memory. We had to infer values from the initialization code:

```c
// From decompiled initialization
void weapon_table_init(void) {
  weapon_table[0].damage = 15;      // Pistol
  weapon_table[0].fire_rate = 0.3f;
  weapon_table[0].clip_size = 12;
  // ...
  
  weapon_table[1].damage = 12;      // Assault Rifle
  weapon_table[1].fire_rate = 0.1f;
  weapon_table[1].clip_size = 30;
  // ...
}
```

### 4. Balancing Fidelity vs Modern Web Patterns

We faced decisions about when to deviate from the original:

**Kept original behavior:**
- Fixed timestep for game logic
- Exact weapon stats and fire rates
- Perk probabilities and effects
- Creature AI update intervals

**Modernized:**
- Input handling (DOM events vs DirectInput polling)
- Rendering (immediate mode vs retained mode)
- Audio (synthesized vs sampled)
- UI layout (responsive vs fixed resolution)

## Performance Considerations

### Canvas 2D vs D3D

The original used Direct3D 8 with hardware acceleration. Canvas 2D is mostly CPU-based:

| Operation | D3D 8 | Canvas 2D |
|-----------|-------|-----------|
| Sprite drawing | GPU batching | CPU immediate mode |
| Transformations | Hardware matrix ops | Software matrix ops |
| Fill rate | GPU limited | CPU limited |
| Texture memory | GPU VRAM | CPU RAM + upload each frame |

For this game's scope (<1000 sprites), Canvas 2D is sufficient, but a WebGL renderer would be the next optimization.

### Entity Query Caching

Initially, we queried entities every frame:

```typescript
// Slow: allocates new array every frame
update() {
  const creatures = entityManager.query(['creature', 'transform']);
  // ...
}
```

Optimized to cache queries:

```typescript
// Fast: reuse arrays
private cachedCreatures: Entity[] = [];

update() {
  // Only rebuild if entity composition changed
  if (entityManager.isDirty) {
    this.cachedCreatures = entityManager.query(['creature', 'transform']);
  }
  // ...
}
```

However, for the entity counts in this game, the simpler approach was fast enough, so we kept it for code clarity.

### Particle System Optimization

Particles are the most frequently created/destroyed objects:

```typescript
class ParticleSystem {
  // Pool particles to reduce GC pressure
  private particlePool: Particle[] = [];
  private activeParticles: Set<Particle> = new Set();
  
  emit(count: number): void {
    for (let i = 0; i < count; i++) {
      const p = this.particlePool.pop() ?? new Particle();
      p.reset();
      this.activeParticles.add(p);
    }
  }
  
  update(dt: number): void {
    for (const p of this.activeParticles) {
      if (p.lifetime <= 0) {
        this.activeParticles.delete(p);
        this.particlePool.push(p);
      }
    }
  }
}
```

### Mobile Touch Input Latency

Touch events have higher latency than mouse/keyboard:

```typescript
class InputManager {
  // Use touch-action CSS to prevent browser handling
  // Use passive listeners where possible
  // Debounce rapid touch events
  
  setupTouchHandlers() {
    this.canvas.style.touchAction = 'none';  // Critical!
    
    this.canvas.addEventListener('touchstart', handler, { 
      passive: true  // Don't block scroll (we prevent it anyway)
    });
  }
}
```

## Testing the Translation

### Side-by-Side Comparison

We verified correctness by running both versions simultaneously:

1. **Visual comparison**: Same seed, same input → same screen
2. **State comparison**: Dump entity states at key moments
3. **Recording/playback**: Record input from original, replay in remake

### Automated Balance Testing

To ensure perks and weapons felt right:

```typescript
test('shotgun does more DPS than pistol at close range', () => {
  const pistolDps = calculateDps(WeaponId.PISTOL, distance = 100);
  const shotgunDps = calculateDps(WeaponId.SHOTGUN, distance = 100);
  expect(shotgunDps).toBeGreaterThan(pistolDps * 1.5);
});
```

## Lessons for Future Reverse Engineering Projects

### 1. Start with Data Tables

Data tables (weapons, creatures, perks) are the easiest to translate and provide immediate value. Get these right first.

### 2. Understand the Timing Model

Is the game:
- **Frame-based**: Fixed timestep, deterministic
- **Delta-time based**: Variable timestep, real-time
- **Hybrid**: Fixed for logic, variable for rendering

This affects how you structure your game loop.

### 3. Map Global State Explicitly

Document all global variables and their relationships:

```
player_state_table[4] depends on:
  - weapon_table (read)
  - perk_table (read)
  - creature_table (read for collision)
  - projectile_table (write for firing)
```

### 4. Preserve Behavior, Not Implementation

The goal is identical gameplay, not identical code structure. Modern patterns often produce cleaner results.

### 5. Test Incrementally

Don't translate the entire game before testing. Start with:
1. Rendering a single sprite
2. Moving with keyboard input
3. Shooting projectiles
4. One enemy type
5. Collision detection
6. Expand from there

## Conclusion

This project demonstrated that:

1. **Decompiled source is valuable**: The reverse engineering work saved weeks of analysis
2. **Modern web tech is capable**: Canvas 2D can handle classic game requirements
3. **ECS works for remakes**: The pattern mapped naturally to original data structures
4. **TypeScript is excellent for translation**: Strict typing caught errors early
5. **Fixed timestep still matters**: Game feel depends on consistent timing

The resulting game is:
- **Faithful to the original**: Same mechanics, balance, and feel
- **Modern in implementation**: Clean TypeScript, web standards
- **Accessible**: Runs in any browser, no installation
- **Educational**: Source code demonstrates reverse engineering techniques

For anyone considering a similar project: the combination of decompiled source + modern language + web platform is a powerful way to preserve and extend classic games.
