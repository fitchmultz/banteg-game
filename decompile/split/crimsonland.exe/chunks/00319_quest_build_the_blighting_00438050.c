/* quest_build_the_blighting @ 00438050 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 3 Quest 1 (The Blighting) */

void quest_build_the_blighting(quest_spawn_entry_t *entries,int *count)

{
  uint uVar1;
  quest_spawn_entry_t *pqVar2;
  quest_spawn_entry_t *pqVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uStack_8;
  
  entries->pos_x = (float)(terrain_texture_width + 0x80);
  iVar5 = 0x1a;
  (entries->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
  (entries->pos_y_block).heading_block.template_id = 0x2b;
  (entries->pos_y_block).heading_block.trigger_time_ms = 0x5dc;
  (entries->pos_y_block).heading_block.count = 2;
  entries[1].pos_x = -128.0;
  entries[1].pos_y_block.pos_y = (float)(terrain_texture_width / 2);
  entries[1].pos_y_block.heading_block.template_id = 0x2b;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 0x5dc;
  entries[1].pos_y_block.heading_block.count = 2;
  entries[2].pos_y_block.pos_y = 128.0;
  entries[2].pos_x = 896.0;
  entries[2].pos_y_block.heading_block.template_id = 7;
  entries[2].pos_y_block.heading_block.trigger_time_ms = 2000;
  entries[2].pos_y_block.heading_block.count = 1;
  entries[3].pos_y_block.pos_y = 128.0;
  entries[3].pos_x = 128.0;
  entries[3].pos_y_block.heading_block.template_id = 7;
  entries[3].pos_y_block.heading_block.trigger_time_ms = 2000;
  entries[3].pos_y_block.heading_block.count = 1;
  entries[4].pos_y_block.pos_y = 896.0;
  entries[4].pos_x = 128.0;
  entries[4].pos_y_block.heading_block.template_id = 7;
  entries[4].pos_y_block.heading_block.trigger_time_ms = 2000;
  entries[4].pos_y_block.heading_block.count = 1;
  entries[5].pos_y_block.pos_y = 896.0;
  entries[5].pos_x = 896.0;
  entries[5].pos_y_block.heading_block.template_id = 7;
  entries[5].pos_y_block.heading_block.trigger_time_ms = 2000;
  entries[5].pos_y_block.heading_block.count = 1;
  iVar7 = 6;
  iVar6 = 4000;
  uStack_8 = 0;
  pqVar3 = entries + 6;
  do {
    uVar1 = uStack_8 & 0x80000001;
    if ((int)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
    }
    if ((uStack_8 == 2) || (pqVar2 = pqVar3, uStack_8 == 4)) {
      pqVar3->pos_x = -128.0;
      iVar7 = iVar7 + 1;
      pqVar2 = pqVar3 + 1;
      (pqVar3->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
      (pqVar3->pos_y_block).heading_block.template_id = 0x2b;
      (pqVar3->pos_y_block).heading_block.trigger_time_ms = iVar6;
      (pqVar3->pos_y_block).heading_block.count = 4;
    }
    if ((uStack_8 == 3) || (pqVar3 = pqVar2, uStack_8 == 5)) {
      pqVar2->pos_x = 1152.0;
      iVar7 = iVar7 + 1;
      pqVar3 = pqVar2 + 1;
      (pqVar2->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
      (pqVar2->pos_y_block).heading_block.template_id = 0x2b;
      (pqVar2->pos_y_block).heading_block.trigger_time_ms = iVar6;
      (pqVar2->pos_y_block).heading_block.count = 4;
    }
    if (uVar1 == 0) {
      iVar5 = 0x1a;
    }
    else if (uVar1 == 1) {
      iVar5 = 0x1c;
    }
    iVar4 = (int)uStack_8 % 5;
    if (iVar4 == 0) {
      pqVar3->pos_x = (float)(terrain_texture_width + 0x40);
      (pqVar3->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
LAB_00438283:
      (pqVar3->pos_y_block).heading_block.template_id = iVar5;
      (pqVar3->pos_y_block).heading_block.trigger_time_ms = iVar6;
      (pqVar3->pos_y_block).heading_block.count = 0xc;
      iVar7 = iVar7 + 1;
      pqVar3 = pqVar3 + 1;
      iVar6 = iVar6 + 15000;
    }
    else {
      if (iVar4 == 1) {
        pqVar3->pos_x = -64.0;
        (pqVar3->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
        goto LAB_00438283;
      }
      if (iVar4 == 2) {
        (pqVar3->pos_y_block).pos_y = (float)(terrain_texture_width + 0x40);
LAB_00438281:
        pqVar3->pos_x = (float)(terrain_texture_width / 2);
        goto LAB_00438283;
      }
      if (iVar4 == 3) {
        (pqVar3->pos_y_block).pos_y = -64.0;
        goto LAB_00438281;
      }
    }
    iVar6 = iVar6 + 1000;
    uStack_8 = uStack_8 + 1;
    if (7 < (int)uStack_8) {
      *count = iVar7;
      return;
    }
  } while( true );
}



