# Deployment Guide

This project uses local deployment to GitHub Pages. No GitHub Actions or remote CI is used (per project policy).

## Prerequisites

- Node.js 20+ and pnpm installed
- GitHub CLI (`gh`) authenticated with appropriate permissions
- Write access to the repository

## Deploy to GitHub Pages

### One-command deployment

```bash
make deploy
```

This will:
1. Build the project for production (`make build`)
2. Deploy the `dist/` directory to GitHub Pages using `gh-pages`

### Manual deployment

If you prefer to run steps manually:

```bash
# Build the project
make build

# Deploy using gh-pages CLI
npx gh-pages -d dist
```

### First-time setup

If you haven't used `gh-pages` before:

```bash
# Install gh-pages globally (optional)
npm install -g gh-pages

# Or use npx (no install needed)
npx gh-pages -d dist
```

## Configuration

GitHub Pages settings:
- Source: Deploy from a branch
- Branch: `gh-pages`
- The `gh-pages` CLI will create and manage this branch automatically

## Verify Deployment

After deployment, the site will be available at:
https://mitchfultz.github.io/crimsonland-remake/

Deployment may take 1-2 minutes to propagate.
