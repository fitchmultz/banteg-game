/* quest_build_alien_dens @ 00436720 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 1 Quest 5 (Alien Dens) */

void quest_build_alien_dens(quest_spawn_entry_t *entries,int *count)

{
  entries->pos_x = 256.0;
  (entries->pos_y_block).pos_y = 256.0;
  (entries->pos_y_block).heading_block.template_id = 8;
  (entries->pos_y_block).heading_block.trigger_time_ms = 0x5dc;
  (entries->pos_y_block).heading_block.count = 1;
  entries[1].pos_x = 768.0;
  entries[1].pos_y_block.pos_y = 768.0;
  entries[1].pos_y_block.heading_block.template_id = 8;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 0x5dc;
  entries[1].pos_y_block.heading_block.count = 1;
  entries[2].pos_x = 512.0;
  entries[2].pos_y_block.pos_y = 512.0;
  entries[2].pos_y_block.heading_block.template_id = 8;
  entries[2].pos_y_block.heading_block.trigger_time_ms = 0x5bcc;
  entries[2].pos_y_block.heading_block.count = config_blob.reserved0._20_4_;
  entries[3].pos_x = 256.0;
  entries[3].pos_y_block.pos_y = 768.0;
  entries[3].pos_y_block.heading_block.template_id = 8;
  entries[3].pos_y_block.heading_block.trigger_time_ms = 0x9664;
  entries[3].pos_y_block.heading_block.count = 1;
  entries[4].pos_x = 768.0;
  entries[4].pos_y_block.pos_y = 256.0;
  entries[4].pos_y_block.heading_block.template_id = 8;
  entries[4].pos_y_block.heading_block.trigger_time_ms = 0x9664;
  entries[4].pos_y_block.heading_block.count = 1;
  *count = 5;
  return;
}



