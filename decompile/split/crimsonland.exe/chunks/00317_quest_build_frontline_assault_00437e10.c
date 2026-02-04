/* quest_build_frontline_assault @ 00437e10 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 1 Quest 4 (Frontline Assault) */

void quest_build_frontline_assault(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  iVar6 = 0x9c4;
  iVar4 = 2;
  do {
    entries->pos_x = (float)(terrain_texture_width / 2);
    (entries->pos_y_block).pos_y = 1088.0;
    if (iVar4 < 5) {
      (entries->pos_y_block).heading_block.template_id = 0x26;
    }
    else if (iVar4 < 10) {
      (entries->pos_y_block).heading_block.template_id = 0x1a;
    }
    else {
      (entries->pos_y_block).heading_block.template_id = 0x26;
    }
    iVar2 = iVar4 * iVar6 + -5000;
    (entries->pos_y_block).heading_block.trigger_time_ms = iVar2;
    (entries->pos_y_block).heading_block.count = 1;
    pqVar1 = entries + 1;
    iVar3 = iVar5 + 1;
    if (4 < iVar4) {
      entries[1].pos_x = -64.0;
      entries[1].pos_y_block.pos_y = -64.0;
      entries[1].pos_y_block.heading_block.template_id = 0x26;
      entries[1].pos_y_block.heading_block.trigger_time_ms = iVar2;
      entries[1].pos_y_block.heading_block.count = 1;
      pqVar1 = entries + 2;
      iVar3 = iVar5 + 2;
    }
    iVar5 = iVar3;
    entries = pqVar1;
    if (10 < iVar4) {
      entries->pos_x = 1088.0;
      (entries->pos_y_block).pos_y = -64.0;
      (entries->pos_y_block).heading_block.template_id = 0x26;
      (entries->pos_y_block).heading_block.trigger_time_ms = iVar2;
      (entries->pos_y_block).heading_block.count = 1;
      iVar5 = iVar5 + 1;
      entries = entries + 1;
    }
    if (iVar4 == 10) {
      entries->pos_x = 1088.0;
      (entries->pos_y_block).pos_y = 512.0;
      iVar3 = (iVar6 * 5 + -0x9c4) * 2;
      (entries->pos_y_block).heading_block.template_id = 0x29;
      (entries->pos_y_block).heading_block.trigger_time_ms = iVar3;
      (entries->pos_y_block).heading_block.count = 1;
      entries[1].pos_x = -64.0;
      entries[1].pos_y_block.pos_y = 512.0;
      entries[1].pos_y_block.heading_block.template_id = 0x29;
      entries[1].pos_y_block.heading_block.trigger_time_ms = iVar3;
      entries[1].pos_y_block.heading_block.count = 1;
      iVar5 = iVar5 + 2;
      entries = entries + 2;
    }
    iVar6 = iVar6 + -0x32;
    if (iVar6 < 0x708) {
      iVar6 = 0x708;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x16);
  *count = iVar5;
  return;
}



