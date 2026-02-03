# Crimsonland Remake - Makefile
# Standard targets per AGENTS.md contract

.PHONY: install build test ci lint type-check format format-check dev clean

# Install dependencies
install:
	pnpm install

# Build for production
build:
	pnpm run build

# Run tests
test:
	pnpm run test

# CI gate: lint + type-check + test + build
ci: lint type-check test build

# Lint and auto-fix issues
lint:
	pnpm run lint

# Type check without emitting
type-check:
	pnpm run type-check

# Format all files
format:
	pnpm run format

# Check formatting without writing
format-check:
	pnpm run format:check

# Start dev server with HMR
dev:
	pnpm run dev

# Clean build artifacts and dependencies
clean:
	rm -rf dist node_modules

# Default target
default: dev
