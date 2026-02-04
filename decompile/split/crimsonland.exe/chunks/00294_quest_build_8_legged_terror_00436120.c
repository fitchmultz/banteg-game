/* quest_build_8_legged_terror @ 00436120 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 1 Quest 10 (8-legged Terror) */

void quest_build_8_legged_terror(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  int iVar2;
  int iVar3;
  
  entries->pos_x = (float)(terrain_texture_width + -0x100);
  iVar3 = 1;
  pqVar1 = entries + 1;
  (entries->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
  (entries->pos_y_block).heading_block.template_id = 0x3a;
  (entries->pos_y_block).heading_block.trigger_time_ms = 1000;
  (entries->pos_y_block).heading_block.count = 1;
  iVar2 = 6000;
  do {
    pqVar1->pos_x = -25.0;
    (pqVar1->pos_y_block).pos_y = -25.0;
    (pqVar1->pos_y_block).heading_block.template_id = 0x3d;
    (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar2;
    (pqVar1->pos_y_block).heading_block.count = config_blob.reserved0._20_4_;
    pqVar1[1].pos_x = 1049.0;
    pqVar1[1].pos_y_block.pos_y = -25.0;
    pqVar1[1].pos_y_block.heading_block.template_id = 0x3d;
    pqVar1[1].pos_y_block.heading_block.trigger_time_ms = iVar2;
    pqVar1[1].pos_y_block.heading_block.count = 1;
    pqVar1[2].pos_x = -25.0;
    pqVar1[2].pos_y_block.pos_y = 1049.0;
    pqVar1[2].pos_y_block.heading_block.template_id = 0x3d;
    pqVar1[2].pos_y_block.heading_block.trigger_time_ms = iVar2;
    pqVar1[2].pos_y_block.heading_block.count = config_blob.reserved0._20_4_;
    iVar3 = iVar3 + 4;
    pqVar1[3].pos_x = 1049.0;
    pqVar1[3].pos_y_block.pos_y = 1049.0;
    pqVar1[3].pos_y_block.heading_block.template_id = 0x3d;
    pqVar1[3].pos_y_block.heading_block.trigger_time_ms = iVar2;
    pqVar1[3].pos_y_block.heading_block.count = 1;
    iVar2 = iVar2 + 0x898;
    pqVar1 = pqVar1 + 4;
  } while (iVar2 < 0x8fc0);
  *count = iVar3;
  return;
}



