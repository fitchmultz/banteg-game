# Crimsonland Remake - Makefile
# Standard targets per AGENTS.md contract

.PHONY: install update build test ci lint type-check format format-check dev clean deploy

# Install dependencies
install:
	pnpm install

# Update all dependencies to latest stable versions
update:
	pnpm update

# Build for production
build:
	pnpm run build

# Run tests (uses wrapper to handle vitest worker cleanup issues)
test:
	bash scripts/test.sh

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

# Deploy to GitHub Pages locally using gh-pages CLI
deploy: build
	npx gh-pages -d dist

# Default target
default: dev
