/* quest_build_the_killing @ 004384a0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 3 Quest 3 (The Killing) */

void quest_build_the_killing(quest_spawn_entry_t *entries,int *count)

{
  int iVar1;
  int iVar2;
  int iVar3;
  quest_spawn_entry_t *pqVar4;
  quest_spawn_entry_t *pqVar5;
  int iVar6;
  int iStack_4;
  
  iVar2 = 0;
  iVar6 = 2000;
  iVar3 = 0x1a;
  iStack_4 = 0;
  pqVar5 = entries;
  do {
    crt_rand();
    iVar1 = iStack_4 % 3;
    if (iVar1 == 0) {
      iVar3 = 0x1a;
    }
    else if (iVar1 == 1) {
      iVar3 = 0x1b;
    }
    else if (iVar1 == 2) {
      iVar3 = 0x1c;
    }
    crt_rand();
    iVar1 = iStack_4 % 5;
    pqVar4 = pqVar5;
    if (iVar1 == 0) {
      pqVar5->pos_x = (float)(terrain_texture_width + 0x40);
LAB_00438544:
      entries = (quest_spawn_entry_t *)(terrain_texture_width / 2);
      (pqVar5->pos_y_block).pos_y = (float)(int)entries;
      (pqVar5->pos_y_block).heading_block.template_id = iVar3;
      (pqVar5->pos_y_block).heading_block.trigger_time_ms = iVar6;
      (pqVar5->pos_y_block).heading_block.count = 0xc;
LAB_004386cc:
      iVar2 = iVar2 + 1;
      pqVar5 = pqVar4 + 1;
      iVar6 = iVar6 + 5000;
    }
    else {
      if (iVar1 == 1) {
        pqVar5->pos_x = -64.0;
        goto LAB_00438544;
      }
      if (iVar1 == 2) {
        (pqVar5->pos_y_block).pos_y = (float)(terrain_texture_width + 0x40);
        pqVar5->pos_x = (float)(terrain_texture_width / 2);
        (pqVar5->pos_y_block).heading_block.template_id = iVar3;
        (pqVar5->pos_y_block).heading_block.trigger_time_ms = iVar6;
        (pqVar5->pos_y_block).heading_block.count = 0xc;
        goto LAB_004386cc;
      }
      if (iVar1 == 3) {
        (pqVar5->pos_y_block).pos_y = -64.0;
        pqVar5->pos_x = (float)(terrain_texture_width / 2);
        (pqVar5->pos_y_block).heading_block.template_id = iVar3;
        (pqVar5->pos_y_block).heading_block.trigger_time_ms = iVar6;
        (pqVar5->pos_y_block).heading_block.count = 0xc;
        goto LAB_004386cc;
      }
      if (iVar1 == 4) {
        iVar1 = crt_rand();
        (pqVar5->pos_y_block).pos_y = (float)(iVar1 % 0x300 + 0x80);
        iVar1 = crt_rand();
        pqVar5->pos_x = (float)(iVar1 % 0x300 + 0x80);
        (pqVar5->pos_y_block).heading_block.template_id = 7;
        (pqVar5->pos_y_block).heading_block.trigger_time_ms = iVar6;
        (pqVar5->pos_y_block).heading_block.count = 3;
        iVar1 = crt_rand();
        pqVar5[1].pos_y_block.pos_y = (float)(iVar1 % 0x300 + 0x80);
        iVar1 = crt_rand();
        pqVar4 = pqVar5 + 2;
        iVar2 = iVar2 + 2;
        pqVar5[1].pos_x = (float)(iVar1 % 0x300 + 0x80);
        pqVar5[1].pos_y_block.heading_block.template_id = 7;
        pqVar5[1].pos_y_block.heading_block.trigger_time_ms = iVar6 + 1000;
        pqVar5[1].pos_y_block.heading_block.count = 3;
        iVar1 = crt_rand();
        pqVar5[2].pos_y_block.pos_y = (float)(iVar1 % 0x300 + 0x80);
        iVar1 = crt_rand();
        pqVar4->pos_x = (float)(iVar1 % 0x300 + 0x80);
        pqVar5[2].pos_y_block.heading_block.template_id = 7;
        pqVar5[2].pos_y_block.heading_block.trigger_time_ms = iVar6 + 2000;
        pqVar5[2].pos_y_block.heading_block.count = 3;
        goto LAB_004386cc;
      }
    }
    iVar6 = iVar6 + 1000;
    iStack_4 = iStack_4 + 1;
    if (9 < iStack_4) {
      *count = iVar2;
      return;
    }
  } while( true );
}



