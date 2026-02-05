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

# CI gate: format + lint + type-check + test + replay tests + build + parity-check
ci: format lint type-check test replay-test build parity-check

# Parity audit: extract canonical data and run parity tests
parity-check:
	@echo "Running parity audit..."
	pnpm run extract:parity
	pnpm run test:parity

# Run replay tests
replay-test:
	pnpm run test:replay

# Update golden files
replay-update:
	UPDATE_GOLDEN=1 pnpm run test:replay

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

# Clean build artifacts, dependencies, lock files, and logs
clean:
	rm -rf dist node_modules pnpm-lock.yaml .ralph/logs *.log

# Deploy to GitHub Pages locally using gh-pages CLI
deploy: build
	npx gh-pages -d dist

# Default target
default: dev
