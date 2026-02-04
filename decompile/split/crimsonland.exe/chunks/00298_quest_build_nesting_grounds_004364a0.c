/* quest_build_nesting_grounds @ 004364a0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 1 Quest 9 (Nesting Grounds) */

void quest_build_nesting_grounds(quest_spawn_entry_t *entries,int *count)

{
  entries->pos_x = (float)(terrain_texture_width / 2);
  (entries->pos_y_block).pos_y = (float)(terrain_texture_height + 0x40);
  (entries->pos_y_block).heading_block.template_id = 0x1d;
  (entries->pos_y_block).heading_block.trigger_time_ms = 0x5dc;
  (entries->pos_y_block).heading_block.count = config_blob.reserved0._20_4_ * 2 + 6;
  entries[1].pos_x = 256.0;
  entries[1].pos_y_block.pos_y = 256.0;
  entries[1].pos_y_block.heading_block.template_id = 9;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 8000;
  entries[1].pos_y_block.heading_block.count = 1;
  entries[2].pos_x = 512.0;
  entries[2].pos_y_block.pos_y = 512.0;
  entries[2].pos_y_block.heading_block.template_id = 9;
  entries[2].pos_y_block.heading_block.trigger_time_ms = 13000;
  entries[2].pos_y_block.heading_block.count = 1;
  entries[3].pos_x = 768.0;
  entries[3].pos_y_block.pos_y = 768.0;
  entries[3].pos_y_block.heading_block.template_id = 9;
  entries[3].pos_y_block.heading_block.trigger_time_ms = 18000;
  entries[3].pos_y_block.heading_block.count = 1;
  entries[4].pos_x = (float)(terrain_texture_width / 2);
  entries[4].pos_y_block.pos_y = (float)(terrain_texture_height + 0x40);
  entries[4].pos_y_block.heading_block.template_id = 0x1d;
  entries[4].pos_y_block.heading_block.trigger_time_ms = 25000;
  entries[4].pos_y_block.heading_block.count = config_blob.reserved0._20_4_ * 2 + 6;
  entries[5].pos_x = (float)(terrain_texture_width / 2);
  entries[5].pos_y_block.pos_y = (float)(terrain_texture_height + 0x40);
  entries[5].pos_y_block.heading_block.template_id = 0x1d;
  entries[5].pos_y_block.heading_block.trigger_time_ms = 39000;
  entries[5].pos_y_block.heading_block.count = config_blob.reserved0._20_4_ * 3 + 3;
  entries[6].pos_x = 384.0;
  entries[6].pos_y_block.pos_y = 512.0;
  entries[6].pos_y_block.heading_block.template_id = 9;
  entries[6].pos_y_block.heading_block.trigger_time_ms = 0xa08c;
  entries[6].pos_y_block.heading_block.count = 1;
  entries[7].pos_x = 640.0;
  entries[7].pos_y_block.pos_y = 512.0;
  entries[7].pos_y_block.heading_block.template_id = 9;
  entries[7].pos_y_block.heading_block.trigger_time_ms = 0xa474;
  entries[7].pos_y_block.heading_block.count = 1;
  entries[8].pos_x = 512.0;
  entries[8].pos_y_block.pos_y = 640.0;
  entries[8].pos_y_block.heading_block.template_id = 9;
  entries[8].pos_y_block.heading_block.trigger_time_ms = 0xa85c;
  entries[8].pos_y_block.heading_block.count = 1;
  entries[9].pos_x = 512.0;
  entries[9].pos_y_block.pos_y = 512.0;
  entries[9].pos_y_block.heading_block.template_id = 8;
  entries[9].pos_y_block.heading_block.trigger_time_ms = 0xac44;
  entries[9].pos_y_block.heading_block.count = 1;
  entries[10].pos_x = (float)(terrain_texture_width / 2);
  entries[10].pos_y_block.pos_y = (float)(terrain_texture_height + 0x40);
  entries[10].pos_y_block.heading_block.template_id = 0x1e;
  entries[10].pos_y_block.heading_block.trigger_time_ms = 50000;
  entries[10].pos_y_block.heading_block.count = config_blob.reserved0._20_4_ * 2 + 5;
  entries[0xb].pos_x = (float)(terrain_texture_width / 2);
  entries[0xb].pos_y_block.pos_y = (float)(terrain_texture_height + 0x40);
  entries[0xb].pos_y_block.heading_block.template_id = 0x1f;
  entries[0xb].pos_y_block.heading_block.trigger_time_ms = 55000;
  entries[0xb].pos_y_block.heading_block.count = config_blob.reserved0._20_4_ * 2 + 2;
  *count = 0xc;
  return;
}



