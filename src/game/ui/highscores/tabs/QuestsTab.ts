/**
 * Quests Tab Renderer
 *
 * Renders the Quests high scores tab with sortable quest completion data.
 */

import { ALL_QUESTS } from '../../../data/quests';
import type { QuestScoreEntry, SortOption, SortDirection } from '../types';
import { formatTime } from '../rendering';
import { LAYOUT } from '../layout';
import type { ProgressionManager } from '../../../progression/ProgressionManager';

export function getQuestScores(progressionManager: ProgressionManager): QuestScoreEntry[] {
  const entries: QuestScoreEntry[] = [];

  for (const quest of ALL_QUESTS) {
    const highScore = progressionManager.getQuestHighScore(quest.id);
    if (highScore) {
      entries.push({
        questId: quest.id,
        questName: quest.name,
        highScore,
      });
    }
  }

  return entries;
}

export function sortQuestScores(
  scores: QuestScoreEntry[],
  sortBy: SortOption,
  sortDirection: SortDirection
): QuestScoreEntry[] {
  return [...scores].sort((a, b) => {
    let comparison = 0;

    switch (sortBy) {
      case 'score':
        comparison = a.highScore.bestScore - b.highScore.bestScore;
        break;
      case 'time':
        comparison = a.highScore.bestTime - b.highScore.bestTime;
        break;
      case 'date':
        comparison =
          new Date(a.highScore.completedAt).getTime() - new Date(b.highScore.completedAt).getTime();
        break;
    }

    return sortDirection === 'asc' ? comparison : -comparison;
  });
}

export function drawQuestsTab(
  ctx: CanvasRenderingContext2D,
  progressionManager: ProgressionManager,
  centerX: number,
  startY: number,
  width: number,
  sortBy: SortOption,
  sortDirection: SortDirection
): void {
  // Section title
  ctx.font = 'bold 20px Arial, sans-serif';
  ctx.textAlign = 'center';
  ctx.fillStyle = '#FFD700';
  ctx.fillText('QUEST COMPLETIONS', centerX, startY);

  // Get quest scores
  const questScores = getQuestScores(progressionManager);

  if (questScores.length === 0) {
    ctx.font = '16px Arial, sans-serif';
    ctx.fillStyle = '#888899';
    ctx.fillText('No quests completed yet', centerX, startY + 50);
    return;
  }

  // Sort quest scores
  const sortedScores = sortQuestScores(questScores, sortBy, sortDirection);

  // Draw headers
  const headersY = startY + 40;
  const colWidth = width / 4;

  ctx.font = 'bold 14px Arial, sans-serif';
  ctx.fillStyle = '#AAAAAA';
  ctx.textAlign = 'left';
  ctx.fillText('Quest', centerX - width / 2, headersY);
  ctx.textAlign = 'center';
  ctx.fillText('Score', centerX - width / 2 + colWidth * 1.5, headersY);
  ctx.fillText('Time', centerX - width / 2 + colWidth * 2.5, headersY);
  ctx.fillText('Date', centerX - width / 2 + colWidth * 3.5, headersY);

  // Draw rows
  const rowY = headersY + 25;
  const maxRows = 4;

  for (let i = 0; i < Math.min(sortedScores.length, maxRows); i++) {
    const entry = sortedScores[i];
    if (!entry) continue;

    const y = rowY + i * LAYOUT.ROW_HEIGHT;
    const isEven = i % 2 === 0;

    // Row background
    if (isEven) {
      ctx.fillStyle = 'rgba(255, 255, 255, 0.05)';
      ctx.fillRect(centerX - width / 2, y - 15, width, LAYOUT.ROW_HEIGHT);
    }

    // Truncate quest name if too long
    let questName = entry.questName;
    ctx.font = '14px Arial, sans-serif';
    ctx.textAlign = 'left';
    ctx.fillStyle = '#FFFFFF';

    const maxNameWidth = colWidth - 10;
    while (ctx.measureText(`${questName}...`).width > maxNameWidth && questName.length > 0) {
      questName = questName.slice(0, -1);
    }
    if (questName.length < entry.questName.length) {
      questName = `${questName}...`;
    }
    ctx.fillText(questName, centerX - width / 2, y);

    // Score
    ctx.textAlign = 'center';
    ctx.fillText(
      entry.highScore.bestScore.toLocaleString(),
      centerX - width / 2 + colWidth * 1.5,
      y
    );

    // Time
    ctx.fillText(formatTime(entry.highScore.bestTime), centerX - width / 2 + colWidth * 2.5, y);

    // Date
    const date = new Date(entry.highScore.completedAt).toLocaleDateString();
    ctx.fillText(date, centerX - width / 2 + colWidth * 3.5, y);
  }

  if (sortedScores.length > maxRows) {
    ctx.font = '12px Arial, sans-serif';
    ctx.fillStyle = '#666666';
    ctx.textAlign = 'center';
    ctx.fillText(
      `... and ${sortedScores.length - maxRows} more`,
      centerX,
      rowY + maxRows * LAYOUT.ROW_HEIGHT + 10
    );
  }
}
