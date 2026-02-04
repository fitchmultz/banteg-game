/* quest_build_the_fortress @ 004352d0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 5 Quest 3 (The Fortress) */

void quest_build_the_fortress(quest_spawn_entry_t *entries,int *count)

{
  float fVar1;
  quest_spawn_entry_t *pqVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  pqVar2 = entries;
  fVar1 = (float)terrain_texture_height;
  entries->pos_x = -50.0;
  entries = (quest_spawn_entry_t *)0x200;
  (pqVar2->pos_y_block).pos_y = fVar1 * 0.5;
  (pqVar2->pos_y_block).heading_block.template_id = 0x40;
  (pqVar2->pos_y_block).heading_block.trigger_time_ms = 100;
  (pqVar2->pos_y_block).heading_block.count = 6;
  iVar4 = 0x44c;
  iVar6 = 8;
  piVar3 = &pqVar2[1].pos_y_block.heading_block.trigger_time_ms;
  do {
    piVar3[-4] = 0x44400000;
    piVar3[-3] = (int)((float)(int)entries * 0.125 + 256.0);
    piVar3[-1] = 9;
    *piVar3 = iVar4;
    piVar3[1] = 1;
    iVar4 = iVar4 + 600;
    entries = (quest_spawn_entry_t *)&entries[0x15].pos_y_block.heading_block;
    piVar3 = piVar3 + 6;
  } while (iVar4 < 0x14b4);
  pqVar2[8].pos_x = 128.0;
  pqVar2[8].pos_y_block.pos_y = 512.0;
  pqVar2[8].pos_y_block.heading_block.template_id = 0xe;
  pqVar2[8].pos_y_block.heading_block.trigger_time_ms = 0x1964;
  pqVar2[8].pos_y_block.heading_block.count = 1;
  entries = (quest_spawn_entry_t *)0x180;
  do {
    iVar5 = 1;
    iVar4 = iVar6 * 600 + 0x157c;
    piVar3 = &pqVar2[iVar6].pos_y_block.heading_block.trigger_time_ms;
    do {
      if ((iVar5 != 1) ||
         ((entries != (quest_spawn_entry_t *)0x480 && (entries != (quest_spawn_entry_t *)0x600)))) {
        iVar6 = iVar6 + 1;
        piVar3[-4] = (int)((float)(int)entries * 0.16666667 + 256.0);
        piVar3[-3] = (int)(512.0 - (float)(iVar5 * 0x180) * 0.16666667);
        piVar3[-1] = 10;
        *piVar3 = iVar4;
        piVar3[1] = 1;
        iVar4 = iVar4 + 600;
        piVar3 = piVar3 + 6;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 7);
    entries = entries + 0x10;
  } while ((int)entries < 0x901);
  *count = iVar6;
  return;
}



