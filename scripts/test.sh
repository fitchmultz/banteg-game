#!/bin/bash
# Run vitest and properly handle all errors including worker crashes
# Exit code propagates directly from vitest - no masking of errors

set -e

# Run vitest with error output visible
# NODE_OPTIONS increased for memory-intensive tests
NODE_OPTIONS='--max-old-space-size=16384' pnpm vitest run 2>&1
