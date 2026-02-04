/* quest_build_fallback @ 004343e0 */

/* fills a default quest spawn table when no quest builder is present */

void __cdecl quest_build_fallback(quest_spawn_entry_t *entries,int *count)

{
  float fVar1;
  
  console_printf(&console_log_queue,s___Generating_a_fallback_quest__00477782 + 2);
  fVar1 = (float)terrain_texture_height;
  entries->pos_x = -50.0;
  (entries->pos_y_block).pos_y = fVar1 * 0.5;
  (entries->pos_y_block).heading_block.template_id = 0x40;
  (entries->pos_y_block).heading_block.trigger_time_ms = 500;
  (entries->pos_y_block).heading_block.count = 10;
  fVar1 = (float)terrain_texture_height;
  entries[1].pos_x = -50.0;
  entries[1].pos_y_block.pos_y = fVar1 * 0.5;
  entries[1].pos_y_block.heading_block.template_id = 0x40;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 5000;
  entries[1].pos_y_block.heading_block.count = 0x14;
  *count = 2;
  return;
}



