/* highscore_rank_index @ 0043b520 */

/* returns the insert index for the current run in the high score table */

int highscore_rank_index(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = highscore_table_count;
  if (config_blob.reserved0._24_4_ == 2) {
    iVar1 = 0;
    if (0 < highscore_table_count) {
      puVar3 = &highscore_table.survival_elapsed_ms;
      while (iVar2 = iVar1, (int)highscore_active_record.survival_elapsed_ms <= (int)*puVar3) {
        iVar1 = iVar1 + 1;
        puVar3 = puVar3 + 0x12;
        if (highscore_table_count <= iVar1) {
          return highscore_table_count;
        }
      }
    }
  }
  else if (config_blob.reserved0._24_4_ == 3) {
    iVar1 = 0;
    if (0 < highscore_table_count) {
      puVar3 = &highscore_table.survival_elapsed_ms;
      while (iVar2 = iVar1, (int)*puVar3 <= (int)highscore_active_record.survival_elapsed_ms) {
        iVar1 = iVar1 + 1;
        puVar3 = puVar3 + 0x12;
        if (highscore_table_count <= iVar1) {
          return highscore_table_count;
        }
      }
    }
  }
  else {
    iVar1 = 0;
    if (0 < highscore_table_count) {
      puVar3 = &highscore_table.score_xp;
      do {
        if ((int)*puVar3 < (int)highscore_active_record.score_xp) {
          return iVar1;
        }
        iVar1 = iVar1 + 1;
        puVar3 = puVar3 + 0x12;
      } while (iVar1 < highscore_table_count);
    }
  }
  return iVar2;
}



