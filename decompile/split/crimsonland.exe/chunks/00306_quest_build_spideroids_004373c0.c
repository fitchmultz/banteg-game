/* quest_build_spideroids @ 004373c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 2 Quest 10 (Spideroids) */

void quest_build_spideroids(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  int iVar2;
  
  entries->pos_x = 1088.0;
  (entries->pos_y_block).pos_y = 512.0;
  (entries->pos_y_block).heading_block.template_id = 1;
  (entries->pos_y_block).heading_block.trigger_time_ms = 1000;
  (entries->pos_y_block).heading_block.count = 1;
  entries[1].pos_x = -64.0;
  entries[1].pos_y_block.pos_y = 512.0;
  entries[1].pos_y_block.heading_block.template_id = 1;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 3000;
  entries[1].pos_y_block.heading_block.count = 1;
  entries[2].pos_x = 1088.0;
  entries[2].pos_y_block.pos_y = 256.0;
  entries[2].pos_y_block.heading_block.template_id = 1;
  entries[2].pos_y_block.heading_block.trigger_time_ms = 6000;
  entries[2].pos_y_block.heading_block.count = 1;
  iVar2 = 3;
  if (config_blob.hardcore != '\0') {
    entries[3].pos_x = 1088.0;
    entries[3].pos_y_block.pos_y = 762.0;
    entries[3].pos_y_block.heading_block.template_id = 1;
    entries[3].pos_y_block.heading_block.trigger_time_ms = 9000;
    entries[3].pos_y_block.heading_block.count = 1;
    entries[4].pos_x = 512.0;
    entries[4].pos_y_block.pos_y = 1088.0;
    entries[4].pos_y_block.heading_block.template_id = 1;
    entries[4].pos_y_block.heading_block.trigger_time_ms = 9000;
    entries[4].pos_y_block.heading_block.count = 1;
    iVar2 = 5;
  }
  if (((int)config_blob.reserved0._20_4_ < 2) && (config_blob.hardcore == '\0')) {
    *count = iVar2;
    return;
  }
  pqVar1 = entries + iVar2;
  pqVar1->pos_x = -64.0;
  (pqVar1->pos_y_block).pos_y = 762.0;
  (pqVar1->pos_y_block).heading_block.template_id = 1;
  (pqVar1->pos_y_block).heading_block.trigger_time_ms = 9000;
  (pqVar1->pos_y_block).heading_block.count = 1;
  *count = iVar2 + 1;
  return;
}



