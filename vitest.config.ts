import { defineConfig } from 'vitest/config';

export default defineConfig({
  test: {
    globals: true,
    environment: 'jsdom',
    include: ['tests/**/*.{test,spec}.{js,mjs,cjs,ts,mts,cts,jsx,tsx}'],
    // Use fork pool instead of threads for stability with jsdom
    // Forks avoid tinypool thread-related crashes by using separate processes
    pool: 'forks',
    // Limit concurrent forks to prevent memory pressure
    maxWorkers: 2,
    minWorkers: 1,
    // Keep isolation disabled for memory efficiency
    isolate: false,
    fileParallelism: false,
    // Increase test timeout for slower environments
    testTimeout: 30000,
  },
});
