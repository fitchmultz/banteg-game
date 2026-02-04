/* quest_build_zombie_masters @ 004360a0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 3 Quest 10 (Zombie Masters) */

void quest_build_zombie_masters(quest_spawn_entry_t *entries,int *count)

{
  entries->pos_x = 256.0;
  (entries->pos_y_block).pos_y = 256.0;
  (entries->pos_y_block).heading_block.template_id = 0;
  (entries->pos_y_block).heading_block.trigger_time_ms = 1000;
  (entries->pos_y_block).heading_block.count = config_blob.reserved0._20_4_;
  entries[1].pos_x = 512.0;
  entries[1].pos_y_block.pos_y = 256.0;
  entries[1].pos_y_block.heading_block.template_id = 0;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 6000;
  entries[1].pos_y_block.heading_block.count = 1;
  entries[2].pos_x = 768.0;
  entries[2].pos_y_block.pos_y = 256.0;
  entries[2].pos_y_block.heading_block.template_id = 0;
  entries[2].pos_y_block.heading_block.trigger_time_ms = 14000;
  entries[2].pos_y_block.heading_block.count = config_blob.reserved0._20_4_;
  entries[3].pos_x = 768.0;
  entries[3].pos_y_block.pos_y = 768.0;
  entries[3].pos_y_block.heading_block.template_id = 0;
  entries[3].pos_y_block.heading_block.trigger_time_ms = 18000;
  entries[3].pos_y_block.heading_block.count = 1;
  *count = 4;
  return;
}



