/* quest_build_land_hostile @ 00435bd0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 1 Quest 1 (Land Hostile) */

void quest_build_land_hostile(quest_spawn_entry_t *entries,int *count)

{
  int iVar1;
  
  iVar1 = terrain_texture_height + 0x40;
  entries->pos_x = (float)(terrain_texture_width / 2);
  (entries->pos_y_block).pos_y = (float)iVar1;
  (entries->pos_y_block).heading_block.template_id = 0x26;
  (entries->pos_y_block).heading_block.trigger_time_ms = 500;
  (entries->pos_y_block).heading_block.count = 1;
  entries[1].pos_x = -64.0;
  entries[1].pos_y_block.pos_y = 1088.0;
  entries[1].pos_y_block.heading_block.template_id = 0x26;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 0x9c4;
  entries[1].pos_y_block.heading_block.count = 2;
  entries[2].pos_x = -64.0;
  entries[2].pos_y_block.pos_y = -64.0;
  entries[2].pos_y_block.heading_block.template_id = 0x26;
  entries[2].pos_y_block.heading_block.trigger_time_ms = 0x1964;
  entries[2].pos_y_block.heading_block.count = 3;
  entries[3].pos_x = 1088.0;
  entries[3].pos_y_block.pos_y = -64.0;
  entries[3].pos_y_block.heading_block.template_id = 0x26;
  entries[3].pos_y_block.heading_block.trigger_time_ms = 0x2cec;
  entries[3].pos_y_block.heading_block.count = 4;
  *count = 4;
  return;
}



