/* quest_build_alien_squads @ 00435ea0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 1 Quest 8 (Alien Squads) */

void quest_build_alien_squads(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  int iVar2;
  int iVar3;
  
  entries->pos_x = -256.0;
  (entries->pos_y_block).pos_y = 256.0;
  (entries->pos_y_block).heading_block.template_id = 0x12;
  (entries->pos_y_block).heading_block.trigger_time_ms = 0x5dc;
  (entries->pos_y_block).heading_block.count = 1;
  entries[1].pos_x = -256.0;
  entries[1].pos_y_block.pos_y = 768.0;
  entries[1].pos_y_block.heading_block.template_id = 0x12;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 0x9c4;
  entries[1].pos_y_block.heading_block.count = 1;
  entries[2].pos_x = 768.0;
  entries[2].pos_y_block.pos_y = -256.0;
  entries[2].pos_y_block.heading_block.template_id = 0x12;
  entries[2].pos_y_block.heading_block.trigger_time_ms = 0x157c;
  entries[2].pos_y_block.heading_block.count = 1;
  entries[3].pos_x = 768.0;
  entries[3].pos_y_block.pos_y = 1280.0;
  entries[3].pos_y_block.heading_block.template_id = 0x12;
  entries[3].pos_y_block.heading_block.trigger_time_ms = 0x2134;
  entries[3].pos_y_block.heading_block.count = 1;
  entries[4].pos_x = 1280.0;
  entries[4].pos_y_block.pos_y = 1280.0;
  entries[4].pos_y_block.heading_block.template_id = 0x12;
  entries[4].pos_y_block.heading_block.trigger_time_ms = 0x38a4;
  entries[4].pos_y_block.heading_block.count = 1;
  entries[5].pos_x = 1280.0;
  entries[5].pos_y_block.pos_y = 768.0;
  entries[5].pos_y_block.heading_block.template_id = 0x12;
  entries[5].pos_y_block.heading_block.trigger_time_ms = 0x4844;
  entries[5].pos_y_block.heading_block.count = 1;
  entries[6].pos_x = -256.0;
  entries[6].pos_y_block.pos_y = 256.0;
  entries[6].pos_y_block.heading_block.template_id = 0x12;
  entries[6].pos_y_block.heading_block.trigger_time_ms = 25000;
  entries[6].pos_y_block.heading_block.count = 1;
  entries[7].pos_x = -256.0;
  entries[7].pos_y_block.pos_y = 768.0;
  entries[7].pos_y_block.heading_block.template_id = 0x12;
  entries[7].pos_y_block.heading_block.trigger_time_ms = 30000;
  entries[7].pos_y_block.heading_block.count = 1;
  iVar3 = 8;
  pqVar1 = entries + 8;
  iVar2 = 0x8d68;
  do {
    pqVar1->pos_x = -64.0;
    (pqVar1->pos_y_block).pos_y = -64.0;
    (pqVar1->pos_y_block).heading_block.template_id = 0x26;
    (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar2 + -400;
    (pqVar1->pos_y_block).heading_block.count = 1;
    iVar3 = iVar3 + 2;
    pqVar1[1].pos_x = 1088.0;
    pqVar1[1].pos_y_block.pos_y = 1088.0;
    pqVar1[1].pos_y_block.heading_block.template_id = 0x26;
    pqVar1[1].pos_y_block.heading_block.trigger_time_ms = iVar2;
    pqVar1[1].pos_y_block.heading_block.count = 1;
    iVar2 = iVar2 + 0x708;
    pqVar1 = pqVar1 + 2;
  } while (iVar2 < 83000);
  *count = iVar3;
  return;
}



