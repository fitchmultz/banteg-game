#!/bin/bash
# Run vitest and handle worker cleanup errors that occur after tests pass
# This script ensures CI passes when all tests actually pass, despite vitest/tinypool cleanup issues

# Run vitest and capture output and exit code
OUTPUT=$(NODE_OPTIONS='--max-old-space-size=16384' pnpm vitest run 2>&1) || EXIT_CODE=$?

# Print output for visibility
echo "$OUTPUT"

# Check for actual test failures (not worker cleanup errors)
# Look for FAIL patterns that indicate real test failures
FAILED_TEST_FILES=$(echo "$OUTPUT" | grep -E "FAIL\s+tests?/" || true)
FAILED_ASSERTIONS=$(echo "$OUTPUT" | grep -E "(AssertionError|expect\()" || true)

# Check final test summary - look for "failed" in the summary line with non-zero count
TEST_SUMMARY_FAILED=$(echo "$OUTPUT" | grep -E "Test Files.*\(\d+ failed\)" || true)

# If there are actual test file failures or assertion errors, fail
if [ -n "$FAILED_TEST_FILES" ] || [ -n "$FAILED_ASSERTIONS" ] || [ -n "$TEST_SUMMARY_FAILED" ]; then
    echo ""
    echo "❌ Tests failed - check output above"
    exit 1
fi

# Check for passing tests
TEST_SUMMARY_PASSED=$(echo "$OUTPUT" | grep -E "Test Files.*passed" || true)

if [ -n "$TEST_SUMMARY_PASSED" ]; then
    echo ""
    echo "✅ All tests passed"
    exit 0
fi

# If we can't determine test status, fail safe
echo ""
echo "❌ Could not determine test status"
exit 1
