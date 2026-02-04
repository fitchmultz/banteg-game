/* quest_build_army_of_three @ 00434ca0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 5 Quest 7 (Army of Three) */

void quest_build_army_of_three(quest_spawn_entry_t *entries,int *count)

{
  entries->pos_x = -64.0;
  (entries->pos_y_block).pos_y = 256.0;
  (entries->pos_y_block).heading_block.template_id = 0x15;
  (entries->pos_y_block).heading_block.trigger_time_ms = 500;
  (entries->pos_y_block).heading_block.count = 1;
  entries[1].pos_x = -64.0;
  entries[1].pos_y_block.pos_y = 512.0;
  entries[1].pos_y_block.heading_block.template_id = 0x15;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 0x157c;
  entries[1].pos_y_block.heading_block.count = 1;
  entries[2].pos_x = -64.0;
  entries[2].pos_y_block.pos_y = 768.0;
  entries[2].pos_y_block.heading_block.template_id = 0x15;
  entries[2].pos_y_block.heading_block.trigger_time_ms = 15000;
  entries[2].pos_y_block.heading_block.count = 1;
  entries[3].pos_x = -64.0;
  entries[3].pos_y_block.pos_y = 768.0;
  entries[3].pos_y_block.heading_block.template_id = 0x17;
  entries[3].pos_y_block.heading_block.trigger_time_ms = 0x4c2c;
  entries[3].pos_y_block.heading_block.count = 1;
  entries[4].pos_x = -64.0;
  entries[4].pos_y_block.pos_y = 512.0;
  entries[4].pos_y_block.heading_block.template_id = 0x17;
  entries[4].pos_y_block.heading_block.trigger_time_ms = 0x57e4;
  entries[4].pos_y_block.heading_block.count = 1;
  entries[5].pos_x = -64.0;
  entries[5].pos_y_block.pos_y = 256.0;
  entries[5].pos_y_block.heading_block.template_id = 0x17;
  entries[5].pos_y_block.heading_block.trigger_time_ms = 0x6784;
  entries[5].pos_y_block.heading_block.count = 1;
  entries[6].pos_x = -64.0;
  entries[6].pos_y_block.pos_y = 256.0;
  entries[6].pos_y_block.heading_block.template_id = 0x16;
  entries[6].pos_y_block.heading_block.trigger_time_ms = 0x8aac;
  entries[6].pos_y_block.heading_block.count = 1;
  entries[7].pos_x = -64.0;
  entries[7].pos_y_block.pos_y = 512.0;
  entries[7].pos_y_block.heading_block.template_id = 0x16;
  entries[7].pos_y_block.heading_block.trigger_time_ms = 0x9a4c;
  entries[7].pos_y_block.heading_block.count = 1;
  entries[8].pos_x = -64.0;
  entries[8].pos_y_block.pos_y = 768.0;
  entries[8].pos_y_block.heading_block.template_id = 0x16;
  entries[8].pos_y_block.heading_block.trigger_time_ms = 0xa604;
  entries[8].pos_y_block.heading_block.count = 1;
  entries[9].pos_x = 512.0;
  entries[9].pos_y_block.pos_y = 1152.0;
  entries[9].pos_y_block.heading_block.template_id = 0x15;
  entries[9].pos_y_block.heading_block.trigger_time_ms = 0xcd14;
  entries[9].pos_y_block.heading_block.count = 3;
  entries[10].pos_x = 512.0;
  entries[10].pos_y_block.pos_y = -256.0;
  entries[10].pos_y_block.heading_block.template_id = 0x17;
  entries[10].pos_y_block.heading_block.trigger_time_ms = 0xdcb4;
  entries[10].pos_y_block.heading_block.count = 3;
  *count = 0xb;
  return;
}



