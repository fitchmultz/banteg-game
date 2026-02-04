/* quest_build_the_beating @ 00435610 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 5 Quest 1 (The Beating) */

void quest_build_the_beating(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  quest_spawn_entry_t *pqVar7;
  int iVar8;
  int iVar9;
  
  pqVar1 = entries;
  entries->pos_x = 256.0;
  (entries->pos_y_block).pos_y = 256.0;
  (entries->pos_y_block).heading_block.template_id = 0x27;
  (entries->pos_y_block).heading_block.trigger_time_ms = 500;
  (entries->pos_y_block).heading_block.count = 1;
  iVar5 = 10000;
  iVar2 = terrain_texture_height / 2;
  entries[1].pos_x = (float)(terrain_texture_width + 0x20);
  iVar9 = 0x40;
  iVar8 = 8;
  entries[1].pos_y_block.pos_y = (float)iVar2;
  entries[1].pos_y_block.heading_block.template_id = 0x29;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 8000;
  entries[1].pos_y_block.heading_block.count = 3;
  piVar4 = &entries[2].pos_y_block.heading_block.trigger_time_ms;
  do {
    iVar2 = iVar9 + terrain_texture_width;
    iVar9 = iVar9 + 0x20;
    iVar3 = terrain_texture_height / 2;
    piVar4[-4] = (int)(float)iVar2;
    piVar4[-3] = (int)(float)iVar3;
    piVar4[-1] = 0x25;
    *piVar4 = iVar5;
    piVar4[1] = 8;
    iVar5 = iVar5 + 100;
    iVar8 = iVar8 + -1;
    piVar4 = piVar4 + 6;
  } while (iVar8 != 0);
  iVar2 = terrain_texture_height / 2;
  entries[10].pos_x = -32.0;
  iVar5 = 20000;
  pqVar7 = entries + 0xb;
  entries = (quest_spawn_entry_t *)0xffffffc0;
  pqVar1[10].pos_y_block.pos_y = (float)iVar2;
  pqVar1[10].pos_y_block.heading_block.template_id = 0x29;
  pqVar1[10].pos_y_block.heading_block.trigger_time_ms = 18000;
  pqVar1[10].pos_y_block.heading_block.count = 3;
  piVar4 = &(pqVar7->pos_y_block).heading_block.trigger_time_ms;
  do {
    piVar6 = &entries[-2].pos_y_block.heading_block.trigger_time_ms;
    iVar2 = terrain_texture_height / 2;
    piVar4[-4] = (int)(float)(int)entries;
    piVar4[-3] = (int)(float)iVar2;
    piVar4[-1] = 0x25;
    *piVar4 = iVar5;
    piVar4[1] = 8;
    iVar5 = iVar5 + 100;
    piVar4 = piVar4 + 6;
    entries = (quest_spawn_entry_t *)piVar6;
  } while (-0x140 < (int)piVar6);
  iVar2 = 40000;
  entries = (quest_spawn_entry_t *)0xffffffc0;
  piVar4 = &pqVar1[0x13].pos_y_block.heading_block.trigger_time_ms;
  do {
    pqVar7 = (quest_spawn_entry_t *)((int)&entries[-2].pos_y_block.pos_y + 2);
    piVar4[-4] = (int)(float)(terrain_texture_width / 2);
    piVar4[-3] = (int)(float)(int)entries;
    piVar4[-1] = 0xf;
    *piVar4 = iVar2;
    piVar4[1] = 4;
    iVar2 = iVar2 + 100;
    piVar4 = piVar4 + 6;
    entries = pqVar7;
  } while (-0x13c < (int)pqVar7);
  iVar2 = 0;
  iVar5 = 40000;
  piVar4 = &pqVar1[0x19].pos_y_block.heading_block.trigger_time_ms;
  do {
    iVar8 = iVar2 + 0x2c + terrain_texture_width;
    iVar2 = iVar2 + 0x20;
    piVar4[-4] = (int)(float)(terrain_texture_width / 2);
    piVar4[-3] = (int)(float)iVar8;
    piVar4[-1] = 0x12;
    *piVar4 = iVar5;
    piVar4[1] = 2;
    iVar5 = iVar5 + 100;
    piVar4 = piVar4 + 6;
  } while (iVar5 < 0x9e98);
  *count = 0x1f;
  return;
}



