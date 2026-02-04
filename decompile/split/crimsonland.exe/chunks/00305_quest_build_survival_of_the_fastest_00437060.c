/* quest_build_survival_of_the_fastest @ 00437060 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 2 Quest 7 (Survival Of The Fastest) */

void quest_build_survival_of_the_fastest(quest_spawn_entry_t *entries,int *count)

{
  float fVar1;
  quest_spawn_entry_t *pqVar2;
  int *piVar3;
  int iVar4;
  int iStack_c;
  
  pqVar2 = entries;
  iVar4 = 500;
  iStack_c = 0x100;
  piVar3 = &(entries->pos_y_block).heading_block.trigger_time_ms;
  do {
    fVar1 = (float)iStack_c;
    iStack_c = iStack_c + 0x48;
    piVar3[-4] = (int)fVar1;
    piVar3[-3] = 0x43800000;
    piVar3[-1] = 0x10;
    *piVar3 = iVar4;
    piVar3[1] = 1;
    iVar4 = iVar4 + 900;
    piVar3 = piVar3 + 6;
  } while (iStack_c < 0x2b0);
  iStack_c = 0x170c;
  entries = (quest_spawn_entry_t *)0x100;
  piVar3 = &pqVar2[6].pos_y_block.heading_block.trigger_time_ms;
  do {
    fVar1 = (float)(int)entries;
    entries = entries + 3;
    piVar3[-4] = 0x442c0000;
    piVar3[-3] = (int)fVar1;
    piVar3[-1] = 0x10;
    *piVar3 = iStack_c;
    piVar3[1] = 1;
    iStack_c = iStack_c + 900;
    piVar3 = piVar3 + 6;
  } while ((int)entries < 0x2b0);
  entries = (quest_spawn_entry_t *)0x2b0;
  iVar4 = 4;
  iStack_c = 0x2c24;
  piVar3 = &pqVar2[0xc].pos_y_block.heading_block.trigger_time_ms;
  do {
    piVar3[-4] = (int)(float)(int)entries;
    piVar3[-3] = 0x442c0000;
    piVar3[-1] = 0x10;
    *piVar3 = iStack_c;
    piVar3[1] = 1;
    entries = entries + -3;
    iStack_c = iStack_c + 900;
    iVar4 = iVar4 + -1;
    piVar3 = piVar3 + 6;
  } while (iVar4 != 0);
  entries = (quest_spawn_entry_t *)0x2b0;
  iStack_c = 0x3a34;
  iVar4 = 4;
  piVar3 = &pqVar2[0x10].pos_y_block.heading_block.trigger_time_ms;
  do {
    piVar3[-4] = 0x43c80000;
    piVar3[-3] = (int)(float)(int)entries;
    piVar3[-1] = 0x10;
    *piVar3 = iStack_c;
    piVar3[1] = 1;
    entries = entries + -3;
    iStack_c = iStack_c + 900;
    iVar4 = iVar4 + -1;
    piVar3 = piVar3 + 6;
  } while (iVar4 != 0);
  iStack_c = 0x4844;
  iVar4 = 400;
  piVar3 = &pqVar2[0x14].pos_y_block.heading_block.trigger_time_ms;
  do {
    fVar1 = (float)iVar4;
    iVar4 = iVar4 + 0x48;
    piVar3[-4] = (int)fVar1;
    piVar3[-3] = 0x43c80000;
    piVar3[-1] = 0x10;
    *piVar3 = iStack_c;
    piVar3[1] = 1;
    iStack_c = iStack_c + 900;
    piVar3 = piVar3 + 6;
  } while (iVar4 < 0x220);
  pqVar2[0x16].pos_x = 128.0;
  pqVar2[0x16].pos_y_block.pos_y = 128.0;
  pqVar2[0x16].pos_y_block.heading_block.template_id = 0x10;
  pqVar2[0x16].pos_y_block.heading_block.trigger_time_ms = 0x571c;
  pqVar2[0x16].pos_y_block.heading_block.count = 1;
  pqVar2[0x17].pos_x = 896.0;
  pqVar2[0x17].pos_y_block.pos_y = 128.0;
  pqVar2[0x17].pos_y_block.heading_block.template_id = 7;
  pqVar2[0x17].pos_y_block.heading_block.trigger_time_ms = 0x571c;
  pqVar2[0x17].pos_y_block.heading_block.count = 1;
  pqVar2[0x18].pos_x = 128.0;
  pqVar2[0x18].pos_y_block.pos_y = 896.0;
  pqVar2[0x18].pos_y_block.heading_block.template_id = 7;
  pqVar2[0x18].pos_y_block.heading_block.trigger_time_ms = 0x5eec;
  pqVar2[0x18].pos_y_block.heading_block.count = 1;
  pqVar2[0x19].pos_x = 896.0;
  pqVar2[0x19].pos_y_block.pos_y = 896.0;
  pqVar2[0x19].pos_y_block.heading_block.template_id = 0x10;
  pqVar2[0x19].pos_y_block.heading_block.trigger_time_ms = 0x5eec;
  pqVar2[0x19].pos_y_block.heading_block.count = 1;
  *count = 0x1a;
  return;
}



