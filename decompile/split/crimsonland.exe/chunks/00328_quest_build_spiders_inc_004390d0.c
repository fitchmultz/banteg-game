/* quest_build_spiders_inc @ 004390d0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 3 Quest 7 (Spiders Inc.) */

void quest_build_spiders_inc(quest_spawn_entry_t *entries,int *count)

{
  int iVar1;
  quest_spawn_entry_t *pqVar2;
  quest_spawn_entry_t *pqVar3;
  int iVar4;
  int iVar5;
  
  pqVar3 = entries;
  (entries->pos_y_block).pos_y = (float)(terrain_texture_width + 0x40);
  entries->pos_x = (float)(terrain_texture_width / 2);
  (entries->pos_y_block).heading_block.template_id = 0x38;
  (entries->pos_y_block).heading_block.trigger_time_ms = 500;
  (entries->pos_y_block).heading_block.count = 1;
  entries[1].pos_y_block.pos_y = (float)(terrain_texture_width + 0x40);
  entries[1].pos_x = (float)(terrain_texture_width / 2 + 0x40);
  entries[1].pos_y_block.heading_block.template_id = 0x38;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 500;
  entries[1].pos_y_block.heading_block.count = 1;
  entries[2].pos_y_block.pos_y = -64.0;
  iVar4 = 17000;
  entries = (quest_spawn_entry_t *)0x0;
  pqVar3[2].pos_x = (float)(terrain_texture_width / 2);
  pqVar3[2].pos_y_block.heading_block.template_id = 0x40;
  pqVar3[2].pos_y_block.heading_block.trigger_time_ms = 500;
  pqVar3[2].pos_y_block.heading_block.count = 4;
  iVar5 = 3;
  do {
    iVar1 = (int)entries / 2 + 3;
    pqVar2 = pqVar3 + iVar5;
    (pqVar2->pos_y_block).pos_y = (float)(terrain_texture_width + 0x40);
    pqVar2->pos_x = (float)(terrain_texture_width / 2);
    (pqVar2->pos_y_block).heading_block.template_id = 0x38;
    (pqVar2->pos_y_block).heading_block.trigger_time_ms = iVar4;
    (pqVar2->pos_y_block).heading_block.count = iVar1;
    pqVar2 = pqVar3 + iVar5 + 1;
    (pqVar2->pos_y_block).pos_y = -64.0;
    iVar5 = iVar5 + 2;
    pqVar2->pos_x = (float)(terrain_texture_width / 2);
    (pqVar2->pos_y_block).heading_block.template_id = 0x38;
    (pqVar2->pos_y_block).heading_block.trigger_time_ms = iVar4;
    (pqVar2->pos_y_block).heading_block.count = iVar1;
    iVar4 = iVar4 + 6000;
    entries = (quest_spawn_entry_t *)((int)&entries->pos_x + 1);
  } while (iVar4 < 0x1a1f8);
  *count = iVar5;
  return;
}



