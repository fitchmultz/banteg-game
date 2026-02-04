/* quest_build_spider_spawns @ 00436d70 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 2 Quest 2 (Spider Spawns) */

void quest_build_spider_spawns(quest_spawn_entry_t *entries,int *count)

{
  entries->pos_x = 128.0;
  (entries->pos_y_block).pos_y = 128.0;
  (entries->pos_y_block).heading_block.template_id = 0x10;
  (entries->pos_y_block).heading_block.trigger_time_ms = 0x5dc;
  (entries->pos_y_block).heading_block.count = 1;
  entries[1].pos_x = 896.0;
  entries[1].pos_y_block.pos_y = 896.0;
  entries[1].pos_y_block.heading_block.template_id = 0x10;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 0x5dc;
  entries[1].pos_y_block.heading_block.count = 1;
  entries[2].pos_x = 896.0;
  entries[2].pos_y_block.pos_y = 128.0;
  entries[2].pos_y_block.heading_block.template_id = 0x10;
  entries[2].pos_y_block.heading_block.trigger_time_ms = 0x5dc;
  entries[2].pos_y_block.heading_block.count = 1;
  entries[3].pos_x = 128.0;
  entries[3].pos_y_block.pos_y = 896.0;
  entries[3].pos_y_block.heading_block.template_id = 0x10;
  entries[3].pos_y_block.heading_block.trigger_time_ms = 0x5dc;
  entries[3].pos_y_block.heading_block.count = 1;
  entries[4].pos_x = -64.0;
  entries[4].pos_y_block.pos_y = 512.0;
  entries[4].pos_y_block.heading_block.template_id = 0x38;
  entries[4].pos_y_block.heading_block.trigger_time_ms = 3000;
  entries[4].pos_y_block.heading_block.count = 2;
  entries[5].pos_x = 512.0;
  entries[5].pos_y_block.pos_y = 512.0;
  entries[5].pos_y_block.heading_block.template_id = 10;
  entries[5].pos_y_block.heading_block.trigger_time_ms = 18000;
  entries[5].pos_y_block.heading_block.count = 1;
  entries[6].pos_x = 448.0;
  entries[6].pos_y_block.pos_y = 448.0;
  entries[6].pos_y_block.heading_block.template_id = 0x10;
  entries[6].pos_y_block.heading_block.trigger_time_ms = 0x5014;
  entries[6].pos_y_block.heading_block.count = 1;
  entries[7].pos_x = 576.0;
  entries[7].pos_y_block.pos_y = 448.0;
  entries[7].pos_y_block.heading_block.template_id = 0x10;
  entries[7].pos_y_block.heading_block.trigger_time_ms = 26000;
  entries[7].pos_y_block.heading_block.count = 1;
  entries[8].pos_x = 1088.0;
  entries[8].pos_y_block.pos_y = 512.0;
  entries[8].pos_y_block.heading_block.template_id = 0x38;
  entries[8].pos_y_block.heading_block.trigger_time_ms = 21000;
  entries[8].pos_y_block.heading_block.count = 2;
  entries[9].pos_x = 576.0;
  entries[9].pos_y_block.pos_y = 576.0;
  entries[9].pos_y_block.heading_block.template_id = 0x10;
  entries[9].pos_y_block.heading_block.trigger_time_ms = 0x7b0c;
  entries[9].pos_y_block.heading_block.count = 1;
  entries[10].pos_x = 448.0;
  entries[10].pos_y_block.pos_y = 576.0;
  entries[10].pos_y_block.heading_block.template_id = 0x10;
  entries[10].pos_y_block.heading_block.trigger_time_ms = 22000;
  entries[10].pos_y_block.heading_block.count = 1;
  *count = 0xb;
  return;
}



