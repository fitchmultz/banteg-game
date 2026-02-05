#!/bin/bash
# Run vitest and properly handle all errors including worker crashes
# Exit code propagates directly from vitest - no masking of errors

set -e

# Show usage information
show_help() {
    cat << 'EOF'
Usage: test.sh [OPTIONS]

Run the test suite using vitest with proper error handling.

OPTIONS:
    -h, --help      Show this help message and exit

DESCRIPTION:
    Runs vitest with increased memory limits (16GB) to handle
    memory-intensive tests. Properly propagates exit codes from
    vitest without masking errors including worker crashes.

EXAMPLES:
    # Run all tests
    bash scripts/test.sh

    # Show this help
    bash scripts/test.sh --help

    # Via make
    make test

EOF
}

# Parse arguments
for arg in "$@"; do
    case $arg in
        -h|--help)
            show_help
            exit 0
            ;;
    esac
done

# Run vitest with error output visible
# NODE_OPTIONS increased for memory-intensive tests
NODE_OPTIONS='--max-old-space-size=16384' pnpm vitest run 2>&1
