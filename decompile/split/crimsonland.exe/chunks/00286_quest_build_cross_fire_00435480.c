/* quest_build_cross_fire @ 00435480 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 5 Quest 6 (Cross Fire) */

void quest_build_cross_fire(quest_spawn_entry_t *entries,int *count)

{
  float fVar1;
  
  fVar1 = (float)terrain_texture_height;
  entries->pos_x = 1074.0;
  (entries->pos_y_block).pos_y = fVar1 * 0.5;
  (entries->pos_y_block).heading_block.template_id = 0x40;
  (entries->pos_y_block).heading_block.trigger_time_ms = 100;
  (entries->pos_y_block).heading_block.count = 6;
  entries[1].pos_x = -40.0;
  entries[1].pos_y_block.pos_y = 512.0;
  entries[1].pos_y_block.heading_block.template_id = 0x3c;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 0x157c;
  entries[1].pos_y_block.heading_block.count = 4;
  entries[2].pos_x = -40.0;
  entries[2].pos_y_block.pos_y = 512.0;
  entries[2].pos_y_block.heading_block.template_id = 0x3c;
  entries[2].pos_y_block.heading_block.trigger_time_ms = 0x3c8c;
  entries[2].pos_y_block.heading_block.count = 6;
  entries[3].pos_x = 512.0;
  entries[3].pos_y_block.pos_y = 512.0;
  entries[3].pos_y_block.heading_block.template_id = 1;
  entries[3].pos_y_block.heading_block.trigger_time_ms = 0x4844;
  entries[3].pos_y_block.heading_block.count = 2;
  entries[4].pos_x = -100.0;
  entries[4].pos_y_block.pos_y = 512.0;
  entries[4].pos_y_block.heading_block.template_id = 0x3c;
  entries[4].pos_y_block.heading_block.trigger_time_ms = 0x639c;
  entries[4].pos_y_block.heading_block.count = 8;
  entries[5].pos_x = 512.0;
  entries[5].pos_y_block.pos_y = 1152.0;
  entries[5].pos_y_block.heading_block.template_id = 0x40;
  entries[5].pos_y_block.heading_block.trigger_time_ms = 26000;
  entries[5].pos_y_block.heading_block.count = 6;
  entries[6].pos_x = 512.0;
  entries[6].pos_y_block.pos_y = -128.0;
  entries[6].pos_y_block.heading_block.template_id = 0x40;
  entries[6].pos_y_block.heading_block.trigger_time_ms = 26000;
  entries[6].pos_y_block.heading_block.count = 6;
  *count = 7;
  return;
}



