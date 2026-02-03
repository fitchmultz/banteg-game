# AGENTS.md

## Goal

claude boys, ralph boys, it's your time to shine and prove me wrong

create a new repo, copy just the two C files from here. they are about 14 days of work worth, they contain the full game decompiled and mapped out, with all the gameplay related functions correctly typed and renamed. you don't have to do the hard part in this assignment.

your task is to rewrite the game from scratch from these two files in any other language and engine of your choice and ideally make it run in a browser. share your result, ideally with a writeup of what you have learned and an open source repo.

this is a serious peace offering and im genuinely interested.

## Project Structure

- `decompile` contains the 2 aforementioned C files
- `docs` contains comprehensive project documentation
- `src` contains the TypeScript implementation

Agent can determine everything else.

## Project Status

**Completed:** This project is a complete, playable browser-based remake of Crimsonland (2003).

### Documentation

- [ARCHITECTURE.md](docs/ARCHITECTURE.md) - System architecture and design decisions
- [LESSONS_LEARNED.md](docs/LESSONS_LEARNED.md) - Educational writeup of the decompilation-to-remake process
- [MAPPING.md](docs/MAPPING.md) - C-to-TypeScript translation guide
- [ENGINE_COMPARISON.md](docs/ENGINE_COMPARISON.md) - grim.dll vs modern web APIs
- [CONTRIBUTING.md](CONTRIBUTING.md) - Development guidelines
- [LICENSE](LICENSE) - MIT License

### Play Online

🎮 **[Play the game here](https://mitchfultz.github.io/crimsonland-remake/)**

### Key Achievements

- Full rewrite from 3.5MB of decompiled C source
- ECS architecture replacing global state tables
- Fixed timestep game loop preserving original feel
- 20+ weapons, 8 enemy types, 30+ perks
- Survival and Quest game modes
- Mobile touch controls
- Automated GitHub Pages deployment
