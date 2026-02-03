# Engine Comparison: grim.dll vs Modern Web APIs

## Overview

This document compares the original Crimsonland engine (`grim.dll`) with the modern web technologies used in the remake. Understanding these differences helps explain why certain implementation choices were made.

## grim.dll Architecture

### Design Philosophy

`grim.dll` was a thin abstraction layer designed to:
- **Simplify porting**: Wrap platform-specific APIs (DirectX, Win32)
- **Reduce dependencies**: Single DLL for all engine functionality
- **Maintain compatibility**: Work across Windows 95/98/ME/XP

### Component Structure

```
grim.dll
├── Graphics (Direct3D 8 wrapper)
│   ├── grim_d3d8_init/shutdown
│   ├── grim_begin_frame/end_frame
│   ├── grim_draw_sprite/rect/circle
│   ├── grim_set_color/rotation/scale
│   └── grim_load_texture
├── Audio (DirectSound wrapper)
│   ├── grim_sound_init/shutdown
│   ├── grim_sound_load/play/stop
│   ├── grim_music_play/stop
│   └── grim_volume_set
├── Input (DirectInput wrapper)
│   ├── grim_input_init/shutdown
│   ├── grim_get_key
│   ├── grim_get_mouse_pos/button
│   └── grim_poll_events
├── File I/O (Win32 wrapper)
│   ├── grim_file_read/write
│   ├── grim_config_load/save
│   └── grim_resource_load
└── System (Win32 utilities)
    ├── grim_time_get
    ├── grim_sleep
    └── grim_message_box
```

## Graphics: Direct3D 8 vs Canvas 2D

### API Comparison

| Feature | Direct3D 8 | Canvas 2D |
|---------|------------|-----------|
| **Rendering Model** | Retained (vertex buffers) | Immediate mode |
| **Hardware Acceleration** | Full GPU | Partial (browser-dependent) |
| **Coordinate System** | Left-handed, Y-up | Top-left origin, Y-down |
| **Texture Management** | GPU VRAM | CPU RAM + GPU upload |
| **Transform Pipeline** | Hardware matrix operations | Software (mostly) |
| **Batching** | Automatic draw call batching | Manual |
| **State Management** | Complex state machine | Simple context state |

### Code Comparison: Drawing a Sprite

**Direct3D 8 (Original):**
```c
// Setup (done once)
IDirect3DDevice8 *device;
IDirect3DTexture8 *texture;
D3DXMatrixIdentity(&world_matrix);

// Per-frame
void grim_draw_sprite(IDirect3DTexture8 *tex, float x, float y) {
  // Set texture
  device->SetTexture(0, tex);
  
  // Build transform matrix
  D3DXMATRIX translation;
  D3DXMatrixTranslation(&translation, x, y, 0);
  device->SetTransform(D3DTS_WORLD, &translation);
  
  // Draw quad (vertex buffer assumed set up)
  device->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}
```

**Canvas 2D (Remake):**
```typescript
function drawSprite(
  ctx: CanvasRenderingContext2D,
  image: CanvasImageSource,
  x: number,
  y: number
): void {
  ctx.drawImage(image, x, y);
}
```

### Performance Characteristics

| Metric | D3D 8 | Canvas 2D | Notes |
|--------|-------|-----------|-------|
| **Sprite Drawing** | 100,000+ @ 60fps | 1,000-5,000 @ 60fps | D3D batching is superior |
| **Fill Rate** | GPU-limited | CPU/JS-limited | Canvas 2D overdraw hurts |
| **Memory Usage** | GPU VRAM | Main RAM | Canvas requires upload each frame |
| **Startup Time** | Slower (device init) | Instant | Canvas has no device setup |
| **Portability** | Windows only | Universal | Canvas works everywhere |

### Transform Handling

**D3D 8:**
```c
// Fixed pipeline matrix stack
D3DXMATRIX world, view, proj;
D3DXMatrixTranslation(&world, x, y, 0);
D3DXMatrixRotationZ(&world, angle);
D3DXMatrixScaling(&world, sx, sy, 1);
D3DXMatrixMultiply(&world, &rot, &scale);
D3DXMatrixMultiply(&world, &world, &trans);

device->SetTransform(D3DTS_WORLD, &world);
device->SetTransform(D3DTS_VIEW, &view);
device->SetTransform(D3DTS_PROJECTION, &proj);
```

**Canvas 2D:**
```typescript
// Manual transform stack management
ctx.save();
ctx.translate(x, y);
ctx.rotate(angle);
ctx.scale(sx, sy);
// ... draw ...
ctx.restore();
```

## Audio: DirectSound vs Web Audio API

### API Comparison

| Feature | DirectSound | Web Audio API |
|---------|-------------|---------------|
| **Architecture** | Buffer-based | Node graph |
| **Latency** | Low (~10ms) | Medium (~30-50ms) |
| **Spatial Audio** | 3D positioning | Stereo panner only |
| **Effects** | Hardware EAX | Software filters/nodes |
| **Streaming** | Secondary buffers | AudioBufferSourceNode |
| **Format Support** | WAV, MP3 (codec) | Browser-dependent |

### Code Comparison: Playing a Sound

**DirectSound (Original):**
```c
IDirectSound8 *dsound;
IDirectSoundBuffer8 *sound_buffer;

// Load (once)
DSBUFFERDESC desc = { sizeof(desc) };
desc.dwFlags = DSBCAPS_STATIC | DSBCAPS_CTRLVOLUME;
desc.dwBufferBytes = wave_data_size;
desc.lpwfxFormat = &wave_format;
dsound->CreateSoundBuffer(&desc, &sound_buffer, NULL);
sound_buffer->Lock(...);
memcpy(buffer_ptr, wave_data, wave_data_size);
sound_buffer->Unlock();

// Play
sound_buffer->SetCurrentPosition(0);
sound_buffer->Play(0, 0, 0);
```

**Web Audio API (Remake):**
```typescript
const audioContext = new AudioContext();

async function playSound(audioBuffer: AudioBuffer): Promise<void> {
  const source = audioContext.createBufferSource();
  source.buffer = audioBuffer;
  source.connect(audioContext.destination);
  source.start();
}

// Load (once)
const response = await fetch('sound.wav');
const arrayBuffer = await response.arrayBuffer();
const audioBuffer = await audioContext.decodeAudioData(arrayBuffer);
```

### Audio Graph Architecture

**Web Audio API allows complex routing:**

```
Source → Panner → Gain → Destination
              ↘
                → Filter → Delay → Reverb →
```

This enables:
- **Spatial audio**: Stereo panning based on screen position
- **Dynamic mixing**: Separate SFX and music volume
- **Effects**: Low-pass filters, delays (not used in this project)

### Challenges

**DirectSound:**
- Required COM initialization
- Buffer management complexity
- Hardware acceleration varied by card

**Web Audio API:**
- Autoplay restrictions require user interaction
- decodeAudioData is async
- No native 3D audio (HRTF)

## Input: DirectInput vs DOM Events

### API Comparison

| Feature | DirectInput | DOM Events |
|---------|-------------|------------|
| **Polling Model** | Polling (check state each frame) | Event-driven |
| **Latency** | Low | Medium (event queue) |
| **Device Support** | Joysticks, gamepads, wheels | Keyboard, mouse, touch |
| **Key States** | Immediate scan codes | Event-based with repeat |
| **Mouse** | Absolute/relative modes | Screen coordinates only |
| **Gamepad** | DirectInput joysticks | Gamepad API (separate) |

### Code Comparison: Keyboard Input

**DirectInput (Original):**
```c
IDirectInput8 *dinput;
IDirectInputDevice8 *keyboard_device;
char key_state[256];

// Init
dinput->CreateDevice(GUID_SysKeyboard, &keyboard_device, NULL);
keyboard_device->SetDataFormat(&c_dfDIKeyboard);
keyboard_device->Acquire();

// Per-frame
keyboard_device->GetDeviceState(sizeof(key_state), key_state);

// Check key
if (key_state[DIK_SPACE] & 0x80) {
  // Space is pressed
}
```

**DOM Events (Remake):**
```typescript
const keyState = new Map<string, boolean>();

window.addEventListener('keydown', (e) => {
  keyState.set(e.code, true);
});

window.addEventListener('keyup', (e) => {
  keyState.set(e.code, false);
});

// Check key (in game loop)
if (keyState.get('Space')) {
  // Space is pressed
}
```

### Touch Input (New Capability)

The remake adds mobile support not present in the original:

```typescript
// Virtual joystick
const joystick = { x: 0, y: 0 };

canvas.addEventListener('touchstart', (e) => {
  const touch = e.touches[0];
  if (isInJoystickArea(touch)) {
    joystick.active = true;
    joystick.startX = touch.clientX;
    joystick.startY = touch.clientY;
  }
});

canvas.addEventListener('touchmove', (e) => {
  if (joystick.active) {
    const touch = e.touches[0];
    const dx = touch.clientX - joystick.startX;
    const dy = touch.clientY - joystick.startY;
    const distance = Math.sqrt(dx * dx + dy * dy);
    const maxDistance = 50;
    
    if (distance > 0) {
      const scale = Math.min(distance, maxDistance) / distance;
      joystick.x = (dx * scale) / maxDistance;
      joystick.y = (dy * scale) / maxDistance;
    }
  }
});
```

### Input Latency Comparison

| Path | Original (DInput) | Remake (DOM) |
|------|-------------------|--------------|
| Hardware → Driver | ~1ms | ~1ms |
| Driver → API | ~1ms | ~1ms |
| API → Application | ~0ms (polling) | ~8-16ms (event queue) |
| **Total** | **~2ms** | **~10-18ms** |

The DOM event queue adds latency, but for this game's genre (not a competitive FPS), it's acceptable.

## Window Management: Win32 vs Browser

### Comparison

| Feature | Win32 API | Browser |
|---------|-----------|---------|
| **Window Creation** | RegisterClass/CreateWindow | `<canvas>` element |
| **Resolution** | ChangeDisplaySettings | CSS/Canvas attributes |
| **Fullscreen** | Exclusive mode | Fullscreen API |
| **Resize** | WM_SIZE message | ResizeObserver |
| **Focus** | WM_SETFOCUS/WM_KILLFOCUS | focus/blur events |
| **Minimize** | WM_SIZE + SIZE_MINIMIZED | visibilitychange event |

### Fullscreen Handling

**Win32 (Original):**
```c
// Exclusive fullscreen
D3DPRESENT_PARAMETERS pp = {0};
pp.Windowed = FALSE;
pp.BackBufferWidth = 800;
pp.BackBufferHeight = 600;
pp.BackBufferFormat = D3DFMT_X8R8G8B8;
pp.SwapEffect = D3DSWAPEFFECT_DISCARD;

device->Reset(&pp);
```

**Browser (Remake):**
```typescript
// Fullscreen API (user-initiated)
async function enterFullscreen(): Promise<void> {
  if (canvas.requestFullscreen) {
    await canvas.requestFullscreen();
  }
}

// CSS for responsive sizing
canvas.style.width = '100%';
canvas.style.height = '100%';
canvas.style.objectFit = 'contain';
```

### Resolution Independence

**Original:** Fixed resolutions (640x480, 800x600, 1024x768)

**Remake:** Responsive canvas that scales to container:

```typescript
function resizeCanvas(): void {
  const container = canvas.parentElement;
  const aspectRatio = 16 / 9;
  
  let width = container.clientWidth;
  let height = width / aspectRatio;
  
  if (height > container.clientHeight) {
    height = container.clientHeight;
    width = height * aspectRatio;
  }
  
  canvas.width = width;
  canvas.height = height;
}
```

## Configuration Management

### Original (Registry/INI files)

```c
// grim.dll loaded config from registry or ini file
void grim_config_load(void) {
  HKEY hKey;
  RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Crimsonland", 0, KEY_READ, &hKey);
  
  DWORD size = sizeof(grim_config);
  RegQueryValueEx(hKey, "Settings", NULL, NULL, (LPBYTE)&grim_config, &size);
  
  RegCloseKey(hKey);
}
```

### Remake (localStorage)

```typescript
function saveConfig(config: GameConfig): void {
  localStorage.setItem('crimsonland_config', JSON.stringify(config));
}

function loadConfig(): GameConfig {
  const saved = localStorage.getItem('crimsonland_config');
  if (saved) {
    return JSON.parse(saved);
  }
  return getDefaultConfig();
}
```

### Comparison

| Aspect | Registry/INI | localStorage |
|--------|--------------|--------------|
| **Persistence** | File system | Browser profile |
| **Size Limit** | Unlimited | ~5MB |
| **Format** | Binary/Custom | JSON |
| **Cross-Device** | No | No (per-browser) |
| **Backup** | Manual | Browser sync |
| **Privacy** | Visible to all apps | Origin-restricted |

## Memory Management

### Original (Manual)

```c
// Explicit allocation
texture_t *tex = malloc(sizeof(texture_t));
tex->pixels = malloc(width * height * 4);

// Explicit deallocation
free(tex->pixels);
free(tex);

// Fixed pools for runtime objects
projectile projectile_pool[MAX_PROJECTILES];
```

### Remake (Garbage Collected)

```typescript
// Automatic allocation
const texture = new ImageData(width, height);

// Automatic deallocation (when unreferenced)
// or explicit for large objects
function cleanup(): void {
  this.largeBuffer = null;  // Hint to GC
}
```

### Memory Pool Comparison

| Aspect | C Fixed Pool | JS GC |
|--------|--------------|-------|
| **Allocation** | O(1) find free slot | Varies (can pause) |
| **Deallocation** | O(1) mark free | Automatic, non-deterministic |
| **Memory Usage** | Fixed (waste if unused) | Dynamic (grows/shrinks) |
| **Cache Locality** | Excellent (contiguous) | Poor (scattered) |
| **Fragmentation** | None | Managed by GC |

For performance-critical code, we implement manual pooling:

```typescript
class ParticlePool {
  private available: Particle[] = [];
  private inUse: Set<Particle> = new Set();
  
  acquire(): Particle {
    return this.available.pop() ?? new Particle();
  }
  
  release(particle: Particle): void {
    this.inUse.delete(particle);
    this.available.push(particle);
  }
}
```

## File I/O

### Original (Win32)

```c
// Synchronous file I/O
FILE *file = fopen("data\\weapons.dat", "rb");
fseek(file, 0, SEEK_END);
int size = ftell(file);
fseek(file, 0, SEEK_SET);

void *data = malloc(size);
fread(data, 1, size, file);
fclose(file);
```

### Remake (Fetch API)

```typescript
// Asynchronous by design
async function loadFile(url: string): Promise<ArrayBuffer> {
  const response = await fetch(url);
  if (!response.ok) {
    throw new Error(`Failed to load: ${url}`);
  }
  return await response.arrayBuffer();
}

// Loading multiple files
async function loadAssets(): Promise<void> {
  const [sprites, sounds] = await Promise.all([
    loadFile('assets/sprites.png'),
    loadFile('assets/sounds.mp3'),
  ]);
  // ...
}
```

### Comparison

| Aspect | Win32 | Fetch API |
|--------|-------|-----------|
| **Sync/Async** | Synchronous | Asynchronous |
| **Caching** | Manual | HTTP cache |
| **Progress** | Manual tracking | Progress events |
| **Error Handling** | errno/checks | Promise rejection |
| **Path Resolution** | Relative to CWD | Relative to URL |
| **Security** | Full FS access | Same-origin restriction |

## Build and Deployment

### Original (Compile and Install)

```
1. Compile with Visual Studio 6.0
2. Link with grim.lib
3. Create installer (InstallShield)
4. Distribute executable
```

### Remake (Build and Deploy)

```
1. pnpm install (dependencies)
2. pnpm run build (Vite bundles)
3. Static files output to dist/
4. Deploy dist/ to any static host
```

### Deployment Comparison

| Aspect | Original | Remake |
|--------|----------|--------|
| **Distribution** | Installer/CD | URL |
| **Platform** | Windows only | Universal |
| **Updates** | Patch/download | Instant (refresh) |
| **Dependencies** | DirectX runtime | None (browser) |
| **Offline Play** | Yes | Yes (PWA capable) |
| **DRM** | CD check | None |

## Performance Summary

| Metric | Original (D3D8) | Remake (Web) | Winner |
|--------|-----------------|--------------|--------|
| **Sprite Rendering** | ★★★★★ | ★★★☆☆ | Original |
| **Startup Time** | ★★★☆☆ | ★★★★★ | Remake |
| **Portability** | ★☆☆☆☆ | ★★★★★ | Remake |
| **Input Latency** | ★★★★★ | ★★★☆☆ | Original |
| **Audio Quality** | ★★★★☆ | ★★★★☆ | Tie |
| **Development Speed** | ★★☆☆☆ | ★★★★★ | Remake |
| **Distribution** | ★★☆☆☆ | ★★★★★ | Remake |

## Why the Web Platform Won

Despite lower raw performance, the web platform was the right choice for this project because:

1. **Accessibility**: No installation required
2. **Distribution**: Share via URL, not installer
3. **Maintenance**: Instant updates
4. **Development**: Modern tooling (TypeScript, hot reload)
5. **Future-proof**: Standards-based, not vendor-specific
6. **Cross-platform**: Mobile, tablet, desktop

For a 2003 game with modest technical requirements, the web platform is more than capable of delivering the same gameplay experience.
