/* quest_build_the_end_of_all @ 00438e10 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 4 Quest 10 (The End of All) */

void quest_build_the_end_of_all(quest_spawn_entry_t *entries,int *count)

{
  float fVar1;
  bool bVar2;
  quest_spawn_entry_t *pqVar3;
  int *piVar4;
  int iVar5;
  quest_spawn_entry_t *pqVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  
  pqVar3 = entries;
  entries->pos_x = 128.0;
  (entries->pos_y_block).pos_y = 128.0;
  (entries->pos_y_block).heading_block.template_id = 0x3c;
  (entries->pos_y_block).heading_block.trigger_time_ms = 3000;
  (entries->pos_y_block).heading_block.count = 1;
  entries[1].pos_x = 896.0;
  entries[1].pos_y_block.pos_y = 128.0;
  entries[1].pos_y_block.heading_block.template_id = 0x3c;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 6000;
  entries[1].pos_y_block.heading_block.count = 1;
  entries[2].pos_x = 128.0;
  entries[2].pos_y_block.pos_y = 896.0;
  entries[2].pos_y_block.heading_block.template_id = 0x3c;
  entries[2].pos_y_block.heading_block.trigger_time_ms = 9000;
  entries[2].pos_y_block.heading_block.count = 1;
  entries[3].pos_x = 896.0;
  entries[3].pos_y_block.pos_y = 896.0;
  entries[3].pos_y_block.heading_block.template_id = 0x3c;
  entries[3].pos_y_block.heading_block.trigger_time_ms = 12000;
  entries[3].pos_y_block.heading_block.count = 1;
  entries = (quest_spawn_entry_t *)0x0;
  iVar5 = 13000;
  piVar4 = &pqVar3[4].pos_y_block.heading_block.template_id;
  do {
    pqVar6 = (quest_spawn_entry_t *)((int)&entries->pos_x + 1);
    fVar8 = (float10)fcos((float10)(int)entries * (float10)1.0471976);
    piVar4[-3] = (int)(float)(fVar8 * (float10)80.0 + (float10)512.0);
    fVar8 = (float10)fsin((float10)(int)entries * (float10)1.0471976);
    piVar4[-2] = (int)(float)(fVar8 * (float10)80.0 + (float10)512.0);
    *piVar4 = 7;
    piVar4[1] = iVar5;
    piVar4[2] = 1;
    iVar5 = iVar5 + 300;
    piVar4 = piVar4 + 6;
    entries = pqVar6;
  } while (iVar5 < 0x39d0);
  iVar5 = 18000;
  pqVar3[10].pos_x = 512.0;
  pqVar3[10].pos_y_block.pos_y = 512.0;
  pqVar3[10].pos_y_block.heading_block.template_id = 0xb;
  entries = (quest_spawn_entry_t *)0x100;
  pqVar3[10].pos_y_block.heading_block.trigger_time_ms = (int)pqVar6 * 300 + 13000;
  pqVar3[10].pos_y_block.heading_block.count = 1;
  bVar2 = false;
  piVar4 = &pqVar3[0xb].pos_y_block.heading_block.template_id;
  do {
    if (bVar2) {
      piVar4[-3] = 0x44900000;
    }
    else {
      piVar4[-3] = 0xc3000000;
    }
    fVar1 = (float)(int)entries;
    entries = (quest_spawn_entry_t *)&entries[5].pos_y_block.heading_block;
    bVar2 = (bool)(bVar2 ^ 1);
    piVar4[-2] = (int)fVar1;
    *piVar4 = 0x3c;
    piVar4[1] = iVar5;
    piVar4[2] = 2;
    iVar5 = iVar5 + 1000;
    piVar4 = piVar4 + 6;
  } while ((int)entries < 0x300);
  iVar5 = 43000;
  entries = (quest_spawn_entry_t *)0x0;
  iVar7 = 0x15;
  piVar4 = &pqVar3[0xf].pos_y_block.heading_block.template_id;
  do {
    fVar8 = (float10)(int)entries;
    entries = (quest_spawn_entry_t *)((int)&entries->pos_x + 1);
    fVar8 = fVar8 * (float10)1.0471976 + (float10)0.5235988;
    fVar9 = (float10)fcos(fVar8);
    piVar4[-3] = (int)(float)(fVar9 * (float10)80.0 + (float10)512.0);
    fVar8 = (float10)fsin(fVar8);
    piVar4[-2] = (int)(float)(fVar8 * (float10)80.0 + (float10)512.0);
    *piVar4 = 7;
    piVar4[1] = iVar5;
    piVar4[2] = 1;
    iVar5 = iVar5 + 300;
    piVar4 = piVar4 + 6;
  } while (iVar5 < 0xaf00);
  if (config_blob.hardcore != '\0') {
    entries = (quest_spawn_entry_t *)0x0;
    iVar5 = 0xf550;
    iVar7 = 0x21;
    piVar4 = &pqVar3[0x15].pos_y_block.heading_block.template_id;
    do {
      fVar8 = (float10)(int)entries;
      entries = (quest_spawn_entry_t *)((int)&entries->pos_x + 1);
      fVar8 = (fVar8 + (float10)1.0) * (float10)0.5235988;
      fVar9 = (float10)fcos(fVar8);
      piVar4[-3] = (int)(float)(fVar9 * (float10)180.0 + (float10)512.0);
      fVar8 = (float10)fsin(fVar8);
      piVar4[-2] = (int)(float)(fVar8 * (float10)180.0 + (float10)512.0);
      *piVar4 = 7;
      piVar4[1] = iVar5;
      piVar4[2] = 1;
      iVar5 = iVar5 + 500;
      piVar4 = piVar4 + 6;
    } while (iVar5 < 0x10cc0);
  }
  bVar2 = false;
  iVar5 = 48000;
  entries = (quest_spawn_entry_t *)0x100;
  piVar4 = &pqVar3[iVar7].pos_y_block.heading_block.template_id;
  do {
    if (bVar2) {
      piVar4[-3] = 0x44900000;
    }
    else {
      piVar4[-3] = 0xc3000000;
    }
    fVar1 = (float)(int)entries;
    entries = (quest_spawn_entry_t *)&entries[5].pos_y_block.heading_block;
    bVar2 = (bool)(bVar2 ^ 1);
    piVar4[-2] = (int)fVar1;
    *piVar4 = 0x3c;
    piVar4[1] = iVar5;
    piVar4[2] = 2;
    iVar5 = iVar5 + 1000;
    piVar4 = piVar4 + 6;
  } while ((int)entries < 0x300);
  *count = iVar7 + 4;
  return;
}



