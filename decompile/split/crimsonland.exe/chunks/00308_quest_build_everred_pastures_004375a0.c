/* quest_build_everred_pastures @ 004375a0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 2 Quest 1 (Everred Pastures) */

void quest_build_everred_pastures(quest_spawn_entry_t *entries,int *count)

{
  int iVar1;
  int iVar2;
  quest_spawn_entry_t *pqVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = 0;
  iVar6 = 0;
  do {
    iVar1 = iVar6 + 1;
    entries->pos_x = (float)(terrain_texture_width + 0x40);
    pqVar3 = entries + 4;
    (entries->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (entries->pos_y_block).heading_block.template_id = 0x32;
    iVar2 = iVar6 * 13000 + 0x5dc;
    (entries->pos_y_block).heading_block.trigger_time_ms = iVar2;
    (entries->pos_y_block).heading_block.count = iVar1;
    entries[1].pos_x = -64.0;
    entries[1].pos_y_block.pos_y = (float)(terrain_texture_width / 2);
    entries[1].pos_y_block.heading_block.template_id = 0x33;
    entries[1].pos_y_block.heading_block.trigger_time_ms = iVar2;
    entries[1].pos_y_block.heading_block.count = iVar1;
    entries[2].pos_x = (float)(terrain_texture_width / 2);
    entries[2].pos_y_block.pos_y = (float)(terrain_texture_width + 0x40);
    entries[2].pos_y_block.heading_block.template_id = 0x34;
    entries[2].pos_y_block.heading_block.trigger_time_ms = iVar2;
    entries[2].pos_y_block.heading_block.count = iVar1;
    iVar5 = iVar4 + 4;
    entries[3].pos_x = (float)(terrain_texture_width / 2);
    entries[3].pos_y_block.pos_y = -64.0;
    entries[3].pos_y_block.heading_block.template_id = 0x35;
    entries[3].pos_y_block.heading_block.trigger_time_ms = iVar2;
    entries[3].pos_y_block.heading_block.count = iVar1;
    if (iVar6 == 3) {
      entries[4].pos_x = (float)(terrain_texture_width / 2);
      entries[4].pos_y_block.pos_y = -64.0;
      entries[4].pos_y_block.heading_block.template_id = 0x1b;
      entries[4].pos_y_block.heading_block.trigger_time_ms = 0x9e34;
      entries[4].pos_y_block.heading_block.count = 8;
      iVar5 = iVar4 + 6;
      pqVar3 = entries + 6;
      entries[5].pos_x = (float)(terrain_texture_width / 2);
      entries[5].pos_y_block.pos_y = 1088.0;
      entries[5].pos_y_block.heading_block.template_id = 0x1b;
      entries[5].pos_y_block.heading_block.trigger_time_ms = 0x9e34;
      entries[5].pos_y_block.heading_block.count = 8;
    }
    entries = pqVar3;
    iVar4 = iVar5;
    iVar6 = iVar1;
  } while (iVar1 < 8);
  *count = iVar5;
  return;
}



