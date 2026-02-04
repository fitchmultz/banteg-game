/* quest_spawn_table_empty @ 00434220 */

/* returns 1 when the quest spawn table has no pending entries */

int quest_spawn_table_empty(void)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = quest_spawn_count - 1;
  if (-1 < (int)uVar1) {
    piVar2 = &(&quest_spawn_table)[uVar1].pos_y_block.heading_block.count;
    do {
      if (0 < *piVar2) {
        return uVar1 & 0xffffff00;
      }
      uVar1 = uVar1 - 1;
      piVar2 = piVar2 + -6;
    } while (-1 < (int)uVar1);
  }
  return CONCAT31((int3)(uVar1 >> 8),1);
}



