/* quest_build_lizard_kings @ 00437710 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 3 Quest 2 (Lizard Kings) */

void quest_build_lizard_kings(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  int *piVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  
  pqVar1 = entries;
  entries->pos_x = 1152.0;
  (entries->pos_y_block).pos_y = 512.0;
  iVar3 = 0x5dc;
  (entries->pos_y_block).heading_block.template_id = 0x11;
  (entries->pos_y_block).heading_block.trigger_time_ms = 0x5dc;
  (entries->pos_y_block).heading_block.count = 1;
  entries[1].pos_x = -128.0;
  entries[1].pos_y_block.pos_y = 512.0;
  entries[1].pos_y_block.heading_block.template_id = 0x11;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 0x5dc;
  entries[1].pos_y_block.heading_block.count = 1;
  entries[2].pos_x = 1152.0;
  entries[2].pos_y_block.pos_y = 896.0;
  entries[2].pos_y_block.heading_block.template_id = 0x11;
  entries[2].pos_y_block.heading_block.trigger_time_ms = 0x5dc;
  entries[2].pos_y_block.heading_block.count = 1;
  entries = (quest_spawn_entry_t *)0x0;
  piVar2 = &pqVar1[3].pos_y_block.heading_block.template_id;
  do {
    fVar4 = (float10)(int)entries;
    fVar5 = fVar4 * (float10)0.34906587;
    fVar6 = (float10)fcos(fVar5);
    piVar2[-3] = (int)(float)(fVar6 * (float10)256.0 + (float10)512.0);
    fVar5 = (float10)fsin(fVar5);
    piVar2[-2] = (int)(float)(fVar5 * (float10)256.0 + (float10)512.0);
    *piVar2 = 0x31;
    piVar2[1] = iVar3;
    piVar2[2] = 1;
    iVar3 = iVar3 + 900;
    entries = (quest_spawn_entry_t *)((int)&entries->pos_x + 1);
    ((quest_spawn_entry_heading_block_t *)(piVar2 + -1))->heading =
         (float)(fVar4 * (float10)-0.34906587);
    piVar2 = piVar2 + 6;
  } while ((int)entries < 0x1c);
  *count = 0x1f;
  return;
}



