/* quest_build_nagolipoli @ 00434480 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 5 Quest 9 (Nagolipoli) */

void quest_build_nagolipoli(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  float fVar2;
  quest_spawn_entry_pos_y_block_t *pqVar3;
  int iVar4;
  quest_spawn_entry_heading_block_t *pqVar5;
  quest_spawn_entry_t *pqVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  float10 fVar12;
  int iStack_20;
  
  pqVar1 = entries;
  iStack_20 = 0;
  pqVar6 = entries;
  do {
    iVar4 = iStack_20;
    pqVar3 = &pqVar6->pos_y_block;
    iVar8 = iStack_20 + 1;
    pqVar6 = (quest_spawn_entry_t *)(pqVar3 + 1);
    fVar11 = (float10)iStack_20 * (float10)0.7853982;
    fVar12 = (float10)fcos(fVar11);
    *(float *)((int)(pqVar3 + -1) + 0x10) = (float)(fVar12 * (float10)128.0);
    fVar12 = (float10)fsin(fVar11);
    pqVar3->pos_y = (float)(fVar12 * (float10)128.0);
    *(float *)((int)(pqVar3 + -1) + 0x10) = *(float *)((int)(pqVar3 + -1) + 0x10) + 512.0;
    pqVar3->pos_y = pqVar3->pos_y + 512.0;
    (pqVar3->heading_block).template_id = 0x40;
    (pqVar3->heading_block).heading = (float)fVar11;
    (pqVar3->heading_block).trigger_time_ms = 2000;
    (pqVar3->heading_block).count = 1;
    iStack_20 = iVar8;
  } while (iVar8 < 8);
  iStack_20 = 0;
  pqVar6 = entries + iVar8;
  do {
    pqVar3 = &pqVar6->pos_y_block;
    fVar11 = (float10)iStack_20;
    pqVar6 = (quest_spawn_entry_t *)(pqVar3 + 1);
    iStack_20 = iStack_20 + 1;
    fVar11 = fVar11 * (float10)0.5235988;
    fVar12 = (float10)fcos(fVar11);
    *(float *)((int)(pqVar3 + -1) + 0x10) = (float)(fVar12 * (float10)178.0);
    fVar12 = (float10)fsin(fVar11);
    pqVar3->pos_y = (float)(fVar12 * (float10)178.0);
    *(float *)((int)(pqVar3 + -1) + 0x10) = *(float *)((int)(pqVar3 + -1) + 0x10) + 512.0;
    pqVar3->pos_y = pqVar3->pos_y + 512.0;
    (pqVar3->heading_block).template_id = 0x40;
    (pqVar3->heading_block).heading = (float)fVar11;
    (pqVar3->heading_block).trigger_time_ms = 8000;
    (pqVar3->heading_block).count = 1;
  } while (iStack_20 < 0xc);
  pqVar6 = entries + iVar4 + 0xd;
  iVar10 = 13000;
  iVar8 = 0;
  iVar4 = iVar4 + 0xd;
  do {
    iVar9 = iVar4;
    iVar7 = iVar8;
    pqVar6->pos_x = -64.0;
    (pqVar6->pos_y_block).pos_y = -64.0;
    (pqVar6->pos_y_block).heading_block.template_id = 0x1c;
    (pqVar6->pos_y_block).heading_block.heading = 1.0471976;
    iVar4 = ((int)(iVar7 + (iVar7 >> 0x1f & 7U)) >> 3) + 1;
    (pqVar6->pos_y_block).heading_block.trigger_time_ms = iVar10;
    (pqVar6->pos_y_block).heading_block.count = iVar4;
    pqVar6[1].pos_x = 1088.0;
    pqVar6[1].pos_y_block.pos_y = -64.0;
    pqVar6[1].pos_y_block.heading_block.template_id = 0x1c;
    pqVar6[1].pos_y_block.heading_block.heading = -1.0471976;
    pqVar6[1].pos_y_block.heading_block.trigger_time_ms = iVar10;
    pqVar6[1].pos_y_block.heading_block.count = iVar4;
    pqVar6[2].pos_x = -64.0;
    pqVar6[2].pos_y_block.pos_y = 1088.0;
    pqVar6[2].pos_y_block.heading_block.template_id = 0x1c;
    pqVar6[2].pos_y_block.heading_block.heading = -1.0471976;
    pqVar6[2].pos_y_block.heading_block.trigger_time_ms = iVar10;
    pqVar6[2].pos_y_block.heading_block.count = iVar4;
    pqVar6[3].pos_x = 1088.0;
    pqVar6[3].pos_y_block.pos_y = 1088.0;
    pqVar6[3].pos_y_block.heading_block.template_id = 0x1c;
    pqVar6[3].pos_y_block.heading_block.heading = 3.926991;
    pqVar6[3].pos_y_block.heading_block.trigger_time_ms = iVar10;
    pqVar6[3].pos_y_block.heading_block.count = iVar4;
    pqVar6 = pqVar6 + 4;
    iVar10 = iVar10 + 800;
    iVar8 = iVar7 + 1;
    iVar4 = iVar9 + 4;
  } while (iVar10 < 0x96c8);
  iStack_20 = 0;
  iVar4 = (iVar7 + 0x97 + iVar8 * 4) * 0xa0;
  pqVar5 = &entries[iVar9 + 4].pos_y_block.heading_block;
  do {
    *(undefined4 *)((int)(pqVar5 + -1) + 8) = 0x42800000;
    *(float *)((int)(pqVar5 + -1) + 0xc) = (float)iStack_20 * 85.333336 + 256.0;
    pqVar5->template_id = 10;
    pqVar5->heading = 0.0;
    pqVar5->trigger_time_ms = iVar4;
    pqVar5->count = 1;
    iStack_20 = iStack_20 + 1;
    iVar4 = iVar4 + 100;
    pqVar5 = (quest_spawn_entry_heading_block_t *)((int)(pqVar5 + 1) + 8);
  } while (iStack_20 < 6);
  iStack_20 = 0;
  pqVar5 = &entries[iVar9 + 10].pos_y_block.heading_block;
  entries = (quest_spawn_entry_t *)(iVar8 * 800 + 25000);
  do {
    fVar2 = (float)iStack_20;
    *(undefined4 *)((int)(pqVar5 + -1) + 8) = 0x44700000;
    iStack_20 = iStack_20 + 1;
    *(float *)((int)(pqVar5 + -1) + 0xc) = fVar2 * 85.333336 + 256.0;
    pqVar5->template_id = 10;
    pqVar5->heading = 0.0;
    pqVar5->trigger_time_ms = (int)entries;
    pqVar5->count = 1;
    entries = (quest_spawn_entry_t *)&entries[4].pos_y_block;
    pqVar5 = (quest_spawn_entry_heading_block_t *)((int)(pqVar5 + 1) + 8);
  } while (iStack_20 < 6);
  pqVar6 = pqVar1 + iVar9 + 0x10;
  pqVar6->pos_x = 512.0;
  (pqVar6->pos_y_block).pos_y = 256.0;
  (pqVar6->pos_y_block).heading_block.template_id = 0xb;
  (pqVar6->pos_y_block).heading_block.heading = 3.1415927;
  iVar4 = (iVar7 + 0xb0 + iVar8 * 4) * 0xa0;
  (pqVar6->pos_y_block).heading_block.trigger_time_ms = iVar4;
  (pqVar6->pos_y_block).heading_block.count = 1;
  pqVar6 = pqVar1 + iVar9 + 0x11;
  pqVar6->pos_x = 512.0;
  (pqVar6->pos_y_block).pos_y = 768.0;
  (pqVar6->pos_y_block).heading_block.template_id = 0xb;
  (pqVar6->pos_y_block).heading_block.heading = 3.1415927;
  (pqVar6->pos_y_block).heading_block.trigger_time_ms = iVar4;
  (pqVar6->pos_y_block).heading_block.count = 1;
  pqVar6 = pqVar1 + iVar9 + 0x12;
  pqVar6->pos_x = 512.0;
  (pqVar6->pos_y_block).pos_y = 1088.0;
  (pqVar6->pos_y_block).heading_block.template_id = 0x1c;
  iVar4 = iVar8 * 800 + 0x6f54;
  (pqVar6->pos_y_block).heading_block.heading = 3.926991;
  (pqVar6->pos_y_block).heading_block.trigger_time_ms = iVar4;
  (pqVar6->pos_y_block).heading_block.count = 8;
  pqVar1 = pqVar1 + iVar9 + 0x13;
  pqVar1->pos_x = 512.0;
  (pqVar1->pos_y_block).pos_y = -64.0;
  (pqVar1->pos_y_block).heading_block.template_id = 0x1c;
  (pqVar1->pos_y_block).heading_block.heading = 3.926991;
  (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar4;
  (pqVar1->pos_y_block).heading_block.count = 8;
  *count = iVar9 + 0x14;
  return;
}



