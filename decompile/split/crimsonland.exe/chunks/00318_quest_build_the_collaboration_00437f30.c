/* quest_build_the_collaboration @ 00437f30 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 4 Quest 4 (The Collaboration) */

void quest_build_the_collaboration(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  
  iVar3 = 0;
  iVar5 = 0x5dc;
  do {
    lVar6 = __ftol();
    iVar2 = (int)lVar6;
    pqVar1 = entries + iVar3;
    pqVar1->pos_x = (float)(terrain_texture_width + 0x40);
    (pqVar1->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (pqVar1->pos_y_block).heading_block.template_id = 0x1a;
    (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar5;
    (pqVar1->pos_y_block).heading_block.count = iVar2;
    pqVar1 = entries + iVar3 + 1;
    (pqVar1->pos_y_block).pos_y = (float)(terrain_texture_width + 0x40);
    pqVar1->pos_x = (float)(terrain_texture_width / 2);
    (pqVar1->pos_y_block).heading_block.template_id = 0x1b;
    (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar5;
    (pqVar1->pos_y_block).heading_block.count = iVar2;
    pqVar1 = entries + iVar3 + 2;
    pqVar1->pos_x = -64.0;
    iVar4 = iVar3 + 3;
    (pqVar1->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (pqVar1->pos_y_block).heading_block.template_id = 0x1c;
    (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar5;
    (pqVar1->pos_y_block).heading_block.count = iVar2;
    iVar3 = iVar3 + 4;
    pqVar1 = entries + iVar4;
    pqVar1->pos_x = 512.0;
    (pqVar1->pos_y_block).pos_y = -64.0;
    (pqVar1->pos_y_block).heading_block.template_id = 0x41;
    (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar5;
    iVar5 = iVar5 + 11000;
    (pqVar1->pos_y_block).heading_block.count = iVar2;
  } while (iVar5 < 0x2b55c);
  *count = iVar3;
  return;
}



