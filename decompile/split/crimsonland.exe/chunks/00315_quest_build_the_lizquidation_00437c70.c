/* quest_build_the_lizquidation @ 00437c70 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 3 Quest 6 (The Lizquidation) */

void quest_build_the_lizquidation(quest_spawn_entry_t *entries,int *count)

{
  int iVar1;
  quest_spawn_entry_t *pqVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar3 = 0;
  do {
    iVar1 = iVar5 * 8000 + 0x5dc;
    pqVar2 = entries + iVar3;
    pqVar2->pos_x = (float)(terrain_texture_width + 0x40);
    (pqVar2->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (pqVar2->pos_y_block).heading_block.template_id = 0x2e;
    (pqVar2->pos_y_block).heading_block.trigger_time_ms = iVar1;
    (pqVar2->pos_y_block).heading_block.count = iVar5 + 6;
    pqVar2 = entries + iVar3 + 1;
    pqVar2->pos_x = -64.0;
    iVar4 = iVar3 + 2;
    (pqVar2->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (pqVar2->pos_y_block).heading_block.template_id = 0x2e;
    (pqVar2->pos_y_block).heading_block.trigger_time_ms = iVar1;
    (pqVar2->pos_y_block).heading_block.count = iVar5 + 6;
    if (iVar5 == 4) {
      pqVar2 = entries + iVar4;
      pqVar2->pos_x = (float)(terrain_texture_width + 0x80);
      iVar4 = iVar3 + 3;
      (pqVar2->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
      (pqVar2->pos_y_block).heading_block.template_id = 0x2b;
      (pqVar2->pos_y_block).heading_block.trigger_time_ms = 0x5dc;
      (pqVar2->pos_y_block).heading_block.count = 2;
    }
    iVar5 = iVar5 + 1;
    iVar3 = iVar4;
  } while (iVar5 < 10);
  *count = iVar4;
  return;
}



