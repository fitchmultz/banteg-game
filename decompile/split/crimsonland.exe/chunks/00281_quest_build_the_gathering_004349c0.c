/* quest_build_the_gathering @ 004349c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 5 Quest 10 (The Gathering) */

void quest_build_the_gathering(quest_spawn_entry_t *entries,int *count)

{
  entries->pos_x = 256.0;
  (entries->pos_y_block).pos_y = 512.0;
  (entries->pos_y_block).heading_block.template_id = 1;
  (entries->pos_y_block).heading_block.trigger_time_ms = 500;
  (entries->pos_y_block).heading_block.count = 1;
  entries[1].pos_x = 768.0;
  entries[1].pos_y_block.pos_y = 512.0;
  entries[1].pos_y_block.heading_block.template_id = 1;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 0x251c;
  entries[1].pos_y_block.heading_block.count = 2;
  entries[2].pos_x = 256.0;
  entries[2].pos_y_block.pos_y = 512.0;
  entries[2].pos_y_block.heading_block.template_id = 0x3a;
  entries[2].pos_y_block.heading_block.trigger_time_ms = 0x3c8c;
  entries[2].pos_y_block.heading_block.count = 2;
  entries[3].pos_x = 768.0;
  entries[3].pos_y_block.pos_y = 512.0;
  entries[3].pos_y_block.heading_block.template_id = 0x3a;
  entries[3].pos_y_block.heading_block.trigger_time_ms = 0x5fb4;
  entries[3].pos_y_block.heading_block.count = 2;
  entries[4].pos_x = 256.0;
  entries[4].pos_y_block.pos_y = 512.0;
  entries[4].pos_y_block.heading_block.template_id = 0;
  entries[4].pos_y_block.heading_block.trigger_time_ms = 0x7724;
  entries[4].pos_y_block.heading_block.count = 2;
  entries[5].pos_x = 768.0;
  entries[5].pos_y_block.pos_y = 512.0;
  entries[5].pos_y_block.heading_block.template_id = 0;
  entries[5].pos_y_block.heading_block.trigger_time_ms = 0x9a4c;
  entries[5].pos_y_block.heading_block.count = 2;
  entries[6].pos_x = 64.0;
  entries[6].pos_y_block.pos_y = 64.0;
  entries[6].pos_y_block.heading_block.template_id = 0x3c;
  entries[6].pos_y_block.heading_block.trigger_time_ms = 0xd4e4;
  entries[6].pos_y_block.heading_block.count = 2;
  entries[7].pos_x = 960.0;
  entries[7].pos_y_block.pos_y = 64.0;
  entries[7].pos_y_block.heading_block.template_id = 0x3c;
  entries[7].pos_y_block.heading_block.trigger_time_ms = 0xd4e4;
  entries[7].pos_y_block.heading_block.count = 1;
  entries[8].pos_x = 64.0;
  entries[8].pos_y_block.pos_y = 960.0;
  entries[8].pos_y_block.heading_block.template_id = 0x3c;
  entries[8].pos_y_block.heading_block.trigger_time_ms = 0xd4e4;
  entries[8].pos_y_block.heading_block.count = 2;
  entries[9].pos_x = 960.0;
  entries[9].pos_y_block.pos_y = 960.0;
  entries[9].pos_y_block.heading_block.template_id = 0x3c;
  entries[9].pos_y_block.heading_block.trigger_time_ms = 0xd4e4;
  entries[9].pos_y_block.heading_block.count = 1;
  entries[10].pos_x = -128.0;
  entries[10].pos_y_block.pos_y = 512.0;
  entries[10].pos_y_block.heading_block.template_id = 0x3a;
  entries[10].pos_y_block.heading_block.trigger_time_ms = 0x16184;
  entries[10].pos_y_block.heading_block.count = 6;
  entries[0xb].pos_x = 1152.0;
  entries[0xb].pos_y_block.pos_y = 512.0;
  entries[0xb].pos_y_block.heading_block.template_id = 1;
  entries[0xb].pos_y_block.heading_block.trigger_time_ms = 0x184ac;
  entries[0xb].pos_y_block.heading_block.count = 4;
  entries[0xc].pos_x = 1152.0;
  entries[0xc].pos_y_block.pos_y = 512.0;
  entries[0xc].pos_y_block.heading_block.template_id = 1;
  entries[0xc].pos_y_block.heading_block.trigger_time_ms = 0x1abbc;
  entries[0xc].pos_y_block.heading_block.count = 2;
  *count = 0xd;
  return;
}



