/* quest_build_hidden_evil @ 00435a30 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 3 Quest 4 (Hidden Evil) */

void quest_build_hidden_evil(quest_spawn_entry_t *entries,int *count)

{
  int iVar1;
  
  iVar1 = terrain_texture_height + 0x40;
  entries->pos_x = (float)(terrain_texture_width / 2);
  (entries->pos_y_block).pos_y = (float)iVar1;
  (entries->pos_y_block).heading_block.template_id = 0x21;
  (entries->pos_y_block).heading_block.trigger_time_ms = 500;
  (entries->pos_y_block).heading_block.count = 0x32;
  iVar1 = terrain_texture_height + 0x40;
  entries[1].pos_x = (float)(terrain_texture_width / 2);
  entries[1].pos_y_block.pos_y = (float)iVar1;
  entries[1].pos_y_block.heading_block.template_id = 0x22;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 15000;
  entries[1].pos_y_block.heading_block.count = 0x1e;
  iVar1 = terrain_texture_height + 0x40;
  entries[2].pos_x = (float)(terrain_texture_width / 2);
  entries[2].pos_y_block.pos_y = (float)iVar1;
  entries[2].pos_y_block.heading_block.template_id = 0x23;
  entries[2].pos_y_block.heading_block.trigger_time_ms = 25000;
  entries[2].pos_y_block.heading_block.count = 0x14;
  iVar1 = terrain_texture_height + 0x40;
  entries[3].pos_x = (float)(terrain_texture_width / 2);
  entries[3].pos_y_block.pos_y = (float)iVar1;
  entries[3].pos_y_block.heading_block.template_id = 0x23;
  entries[3].pos_y_block.heading_block.trigger_time_ms = 30000;
  entries[3].pos_y_block.heading_block.count = 0x1e;
  iVar1 = terrain_texture_height + 0x40;
  entries[4].pos_x = (float)(terrain_texture_width / 2);
  entries[4].pos_y_block.pos_y = (float)iVar1;
  entries[4].pos_y_block.heading_block.template_id = 0x22;
  entries[4].pos_y_block.heading_block.trigger_time_ms = 35000;
  entries[4].pos_y_block.heading_block.count = 0x1e;
  *count = 5;
  return;
}



