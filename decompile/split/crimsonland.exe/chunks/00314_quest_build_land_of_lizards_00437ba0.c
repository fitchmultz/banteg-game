/* quest_build_land_of_lizards @ 00437ba0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 2 Quest 8 (Land Of Lizards) */

void quest_build_land_of_lizards(quest_spawn_entry_t *entries,int *count)

{
  entries->pos_x = 256.0;
  (entries->pos_y_block).pos_y = 256.0;
  (entries->pos_y_block).heading_block.template_id = 0xe;
  (entries->pos_y_block).heading_block.trigger_time_ms = 2000;
  (entries->pos_y_block).heading_block.count = 1;
  entries[1].pos_x = 768.0;
  entries[1].pos_y_block.pos_y = 256.0;
  entries[1].pos_y_block.heading_block.template_id = 0xe;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 12000;
  entries[1].pos_y_block.heading_block.count = 1;
  entries[2].pos_x = 256.0;
  entries[2].pos_y_block.pos_y = 768.0;
  entries[2].pos_y_block.heading_block.template_id = 0xe;
  entries[2].pos_y_block.heading_block.trigger_time_ms = 22000;
  entries[2].pos_y_block.heading_block.count = 1;
  entries[3].pos_x = 768.0;
  entries[3].pos_y_block.pos_y = 768.0;
  entries[3].pos_y_block.heading_block.template_id = 0xe;
  entries[3].pos_y_block.heading_block.trigger_time_ms = 32000;
  entries[3].pos_y_block.heading_block.count = 1;
  *count = 4;
  return;
}



