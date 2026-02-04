/* quest_build_lizard_raze @ 00438840 */

/* quest builder for Tier 3 Quest 8 (Lizard Raze) */

void __cdecl quest_build_lizard_raze(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0x5dc;
  iVar2 = 0;
  do {
    iVar3 = iVar2;
    pqVar1 = entries + iVar3;
    pqVar1->pos_x = (float)(terrain_texture_width + 0x40);
    (pqVar1->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (pqVar1->pos_y_block).heading_block.template_id = 0x2e;
    (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar4;
    (pqVar1->pos_y_block).heading_block.count = 6;
    pqVar1 = entries + iVar3 + 1;
    pqVar1->pos_x = -64.0;
    (pqVar1->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (pqVar1->pos_y_block).heading_block.template_id = 0x2e;
    (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar4;
    iVar4 = iVar4 + 6000;
    (pqVar1->pos_y_block).heading_block.count = 6;
    iVar2 = iVar3 + 2;
  } while (iVar4 < 0x1656c);
  pqVar1 = entries + iVar3 + 2;
  pqVar1->pos_x = 128.0;
  (pqVar1->pos_y_block).pos_y = 256.0;
  (pqVar1->pos_y_block).heading_block.template_id = 0xc;
  (pqVar1->pos_y_block).heading_block.trigger_time_ms = 10000;
  (pqVar1->pos_y_block).heading_block.count = 1;
  pqVar1 = entries + iVar3 + 3;
  pqVar1->pos_x = 128.0;
  (pqVar1->pos_y_block).pos_y = 384.0;
  (pqVar1->pos_y_block).heading_block.template_id = 0xc;
  (pqVar1->pos_y_block).heading_block.trigger_time_ms = 10000;
  (pqVar1->pos_y_block).heading_block.count = 1;
  pqVar1 = entries + iVar3 + 4;
  pqVar1->pos_x = 128.0;
  (pqVar1->pos_y_block).pos_y = 512.0;
  (pqVar1->pos_y_block).heading_block.template_id = 0xc;
  (pqVar1->pos_y_block).heading_block.trigger_time_ms = 10000;
  (pqVar1->pos_y_block).heading_block.count = 1;
  *count = iVar3 + 5;
  return;
}



