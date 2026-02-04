/* quest_build_minor_alien_breach @ 00435cc0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 1 Quest 2 (Minor Alien Breach) */

void quest_build_minor_alien_breach(quest_spawn_entry_t *entries,int *count)

{
  int iVar1;
  quest_spawn_entry_t *pqVar2;
  quest_spawn_entry_t *pqVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  entries->pos_x = 256.0;
  (entries->pos_y_block).pos_y = 256.0;
  (entries->pos_y_block).heading_block.template_id = 0x26;
  iVar6 = 2;
  (entries->pos_y_block).heading_block.trigger_time_ms = 1000;
  (entries->pos_y_block).heading_block.count = 2;
  entries[1].pos_x = 256.0;
  entries[1].pos_y_block.pos_y = 128.0;
  entries[1].pos_y_block.heading_block.template_id = 0x26;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 0x6a4;
  entries[1].pos_y_block.heading_block.count = 2;
  iVar4 = 2;
  pqVar3 = entries + 2;
  do {
    iVar1 = terrain_texture_height / 2;
    pqVar3->pos_x = (float)(terrain_texture_width + 0x40);
    (pqVar3->pos_y_block).pos_y = (float)iVar1;
    (pqVar3->pos_y_block).heading_block.template_id = 0x26;
    iVar5 = (iVar4 * 5 + -10) * 0x2d0;
    (pqVar3->pos_y_block).heading_block.trigger_time_ms = iVar5;
    (pqVar3->pos_y_block).heading_block.count = 1;
    pqVar2 = pqVar3 + 1;
    iVar1 = iVar6 + 1;
    if (6 < iVar4) {
      iVar1 = terrain_texture_height / 2;
      pqVar3[1].pos_x = (float)(terrain_texture_width + 0x40);
      pqVar3[1].pos_y_block.pos_y = (float)(iVar1 + -0x100);
      pqVar3[1].pos_y_block.heading_block.template_id = 0x26;
      pqVar3[1].pos_y_block.heading_block.trigger_time_ms = iVar5;
      pqVar3[1].pos_y_block.heading_block.count = 1;
      pqVar2 = pqVar3 + 2;
      iVar1 = iVar6 + 2;
    }
    iVar6 = iVar1;
    pqVar3 = pqVar2;
    if (iVar4 == 0xd) {
      iVar1 = terrain_texture_height + 0x40;
      iVar6 = iVar6 + 1;
      pqVar3->pos_x = (float)(terrain_texture_width / 2);
      (pqVar3->pos_y_block).pos_y = (float)iVar1;
      (pqVar3->pos_y_block).heading_block.template_id = 0x29;
      (pqVar3->pos_y_block).heading_block.trigger_time_ms = 0x9ab0;
      (pqVar3->pos_y_block).heading_block.count = 1;
      pqVar2 = pqVar3 + 1;
LAB_00435e39:
      iVar1 = terrain_texture_height / 2;
      pqVar2->pos_x = -64.0;
      iVar6 = iVar6 + 1;
      pqVar3 = pqVar2 + 1;
      (pqVar2->pos_y_block).pos_y = (float)(iVar1 + 0x100);
      (pqVar2->pos_y_block).heading_block.template_id = 0x26;
      (pqVar2->pos_y_block).heading_block.trigger_time_ms = iVar5;
      (pqVar2->pos_y_block).heading_block.count = 1;
    }
    else {
      pqVar2 = pqVar3;
      if (10 < iVar4) goto LAB_00435e39;
    }
    iVar4 = iVar4 + 1;
    if (0x11 < iVar4) {
      *count = iVar6;
      return;
    }
  } while( true );
}



