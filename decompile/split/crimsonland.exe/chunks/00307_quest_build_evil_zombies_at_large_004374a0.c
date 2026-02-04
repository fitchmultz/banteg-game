/* quest_build_evil_zombies_at_large @ 004374a0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 2 Quest 6 (Evil Zombies At Large) */

void quest_build_evil_zombies_at_large(quest_spawn_entry_t *entries,int *count)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 0x5dc;
  iVar3 = 4;
  do {
    entries->pos_x = (float)(terrain_texture_width + 0x40);
    (entries->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (entries->pos_y_block).heading_block.template_id = 0x41;
    (entries->pos_y_block).heading_block.trigger_time_ms = iVar4;
    (entries->pos_y_block).heading_block.count = iVar3;
    entries[1].pos_x = -64.0;
    entries[1].pos_y_block.pos_y = (float)(terrain_texture_width / 2);
    entries[1].pos_y_block.heading_block.template_id = 0x41;
    entries[1].pos_y_block.heading_block.trigger_time_ms = iVar4;
    entries[1].pos_y_block.heading_block.count = iVar3;
    entries[2].pos_x = (float)(terrain_texture_width / 2);
    entries[2].pos_y_block.pos_y = (float)(terrain_texture_width + 0x40);
    entries[2].pos_y_block.heading_block.template_id = 0x41;
    entries[2].pos_y_block.heading_block.trigger_time_ms = iVar4;
    entries[2].pos_y_block.heading_block.count = iVar3;
    iVar2 = iVar2 + 4;
    entries[3].pos_x = (float)(terrain_texture_width / 2);
    entries[3].pos_y_block.pos_y = -64.0;
    entries[3].pos_y_block.heading_block.template_id = 0x41;
    entries[3].pos_y_block.heading_block.trigger_time_ms = iVar4;
    entries[3].pos_y_block.heading_block.count = iVar3;
    iVar4 = iVar4 + 0x157c;
    iVar1 = iVar3 + -3;
    entries = entries + 4;
    iVar3 = iVar3 + 1;
  } while (iVar1 < 10);
  *count = iVar2;
  return;
}



