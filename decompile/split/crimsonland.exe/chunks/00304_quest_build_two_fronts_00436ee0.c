/* quest_build_two_fronts @ 00436ee0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 2 Quest 4 (Two Fronts) */

void quest_build_two_fronts(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    entries->pos_x = (float)(terrain_texture_width + 0x40);
    (entries->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (entries->pos_y_block).heading_block.template_id = 0x1a;
    (entries->pos_y_block).heading_block.trigger_time_ms = iVar3 * 2000 + 1000;
    (entries->pos_y_block).heading_block.count = 1;
    entries[1].pos_x = -64.0;
    entries[1].pos_y_block.pos_y = (float)(terrain_texture_width / 2);
    entries[1].pos_y_block.heading_block.template_id = 0x1b;
    entries[1].pos_y_block.heading_block.trigger_time_ms = (iVar3 * 5 + 5) * 400;
    entries[1].pos_y_block.heading_block.count = 1;
    if ((iVar3 == 10) || (pqVar1 = entries + 2, iVar4 = iVar2 + 2, iVar3 == 0x14)) {
      entries[2].pos_x = 256.0;
      iVar4 = iVar3 * 2000 + 0x9c4;
      entries[2].pos_y_block.pos_y = 256.0;
      entries[2].pos_y_block.heading_block.template_id = 10;
      entries[2].pos_y_block.heading_block.trigger_time_ms = iVar4;
      entries[2].pos_y_block.heading_block.count = 1;
      entries[3].pos_x = 768.0;
      entries[3].pos_y_block.pos_y = 768.0;
      entries[3].pos_y_block.heading_block.template_id = 7;
      entries[3].pos_y_block.heading_block.trigger_time_ms = iVar4;
      entries[3].pos_y_block.heading_block.count = 1;
      pqVar1 = entries + 4;
      iVar4 = iVar2 + 4;
    }
    iVar2 = iVar4;
    entries = pqVar1;
    if (iVar3 == 0x1e) {
      entries->pos_x = 768.0;
      (entries->pos_y_block).pos_y = 256.0;
      (entries->pos_y_block).heading_block.template_id = 10;
      (entries->pos_y_block).heading_block.trigger_time_ms = 0xf424;
      (entries->pos_y_block).heading_block.count = 1;
      entries[1].pos_x = 256.0;
      entries[1].pos_y_block.pos_y = 768.0;
      entries[1].pos_y_block.heading_block.template_id = 7;
      entries[1].pos_y_block.heading_block.trigger_time_ms = 0xf424;
      entries[1].pos_y_block.heading_block.count = 1;
      iVar2 = iVar2 + 2;
      entries = entries + 2;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x28);
  *count = iVar2;
  return;
}



