# Decompiled Source Directory

This directory contains the decompiled C source code from the original Crimsonland (2003) game.

## Directory Structure

```
decompile/
├── README.md              # This file
├── original/              # Authoritative decompiled source files
│   ├── crimsonland.exe_decompiled.c   # ~2MB, main game logic
│   └── grim.dll_decompiled.c          # ~1.5MB, engine layer
└── split/                 # Deterministic per-function splits
    ├── crimsonland.exe/   # Split chunks from crimsonland.exe_decompiled.c
    │   ├── manifest.json  # Chunk metadata and reassembly info
    │   └── chunks/        # Individual function files
    └── grim.dll/          # Split chunks from grim.dll_decompiled.c
        ├── manifest.json
        └── chunks/
```

## Invariants

1. **Byte Identity**: Concatenating split chunks in manifest order produces the **exact original bytes**.
2. **Determinism**: Same input → identical output tree (filenames, manifest contents, file bytes).
3. **Derived Artifacts**: Files in `split/` are derived from `original/`. Do not edit split chunks by hand.
4. **Reproducible**: The splitting process is deterministic and can be re-run at any time.

## Marker Format

Split boundaries are defined by lines matching:
```c
/* <function_name> @ <hex_address> */
```

Examples:
- `/* console_input_clear @ 00401030 */`
- `/* FUN_100019f0 @ 100019f0 */`

The marker line itself is included at the start of the corresponding function chunk.

## Usage

### Split the original files

```bash
# Split crimsonland.exe_decompiled.c
node scripts/decompile/split.mjs split \
  --in decompile/original/crimsonland.exe_decompiled.c \
  --out decompile/split/crimsonland.exe

# Split grim.dll_decompiled.c
node scripts/decompile/split.mjs split \
  --in decompile/original/grim.dll_decompiled.c \
  --out decompile/split/grim.dll
```

### Verify split output

```bash
# Verify without re-splitting
node scripts/decompile/split.mjs verify \
  --manifest decompile/split/crimsonland.exe/manifest.json \
  --original decompile/original/crimsonland.exe_decompiled.c
```

### Regenerate all splits

```bash
# Clean and regenerate (use --clean to replace existing output)
node scripts/decompile/split.mjs split \
  --in decompile/original/crimsonland.exe_decompiled.c \
  --out decompile/split/crimsonland.exe \
  --clean

node scripts/decompile/split.mjs split \
  --in decompile/original/grim.dll_decompiled.c \
  --out decompile/split/grim.dll \
  --clean
```

## File Contents

### crimsonland.exe_decompiled.c

Main game logic including:
- Player state and weapon handling
- Creature (enemy) AI and spawning
- Projectile and collision systems
- Perk selection and effects
- Quest mode logic
- Survival mode scoring
- UI and rendering calls

### grim.dll_decompiled.c

Engine abstraction layer including:
- Direct3D 8 graphics wrapper
- DirectSound audio wrapper
- DirectInput input wrapper
- File I/O operations
- Configuration management
- Window management

## Background

These files represent approximately 14 days of reverse engineering work:
- Functions renamed from `FUN_004010f0` to descriptive names like `player_update`
- Variables typed with proper C types
- Structures mapped for weapons, creatures, perks
- Comments explaining function behavior

See `docs/LESSONS_LEARNED.md` for details on how this code was translated to TypeScript.
