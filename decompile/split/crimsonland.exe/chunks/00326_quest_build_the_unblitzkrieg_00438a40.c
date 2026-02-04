/* quest_build_the_unblitzkrieg @ 00438a40 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 4 Quest 6 (The Unblitzkrieg) */

void quest_build_the_unblitzkrieg(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  
  iVar5 = 500;
  iVar6 = 0;
  piVar7 = &(entries->pos_y_block).heading_block.template_id;
  uVar3 = 0;
  do {
    uVar8 = uVar3;
    piVar7[-3] = 0x444e0000;
    iVar2 = iVar6 / 10;
    iVar6 = iVar6 + 0x270;
    piVar7[-2] = (int)(float)(iVar2 + 200);
    *piVar7 = (-(uint)((uVar8 & 1) != 0) & 6) + 7;
    piVar7[1] = iVar5;
    piVar7[2] = 1;
    iVar5 = iVar5 + 0x708;
    piVar7 = piVar7 + 6;
    uVar3 = uVar8 + 1;
  } while (iVar6 < 0x1860);
  iVar6 = 0;
  bVar4 = 0;
  piVar7 = &entries[uVar8 + 1].pos_y_block.heading_block.template_id;
  do {
    piVar7[-3] = (int)(float)(0x338 - iVar6 / 10);
    piVar7[-2] = 0x444e0000;
    iVar6 = iVar6 + 0x270;
    *piVar7 = (-(uint)bVar4 & 6) + 7;
    piVar7[1] = iVar5;
    piVar7[2] = 1;
    iVar5 = iVar5 + 0x5dc;
    bVar4 = bVar4 ^ 1;
    piVar7 = piVar7 + 6;
  } while (iVar6 < 0x1860);
  iVar6 = 0;
  pqVar1 = entries + uVar8 + 0xb;
  bVar4 = 0;
  pqVar1->pos_x = 512.0;
  (pqVar1->pos_y_block).pos_y = 512.0;
  (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar5;
  (pqVar1->pos_y_block).heading_block.template_id = 7;
  (pqVar1->pos_y_block).heading_block.count = 1;
  piVar7 = &entries[uVar8 + 0xc].pos_y_block.heading_block.template_id;
  do {
    piVar7[-3] = 0x43480000;
    piVar7[-2] = (int)(float)(0x338 - iVar6 / 10);
    iVar6 = iVar6 + 0x270;
    *piVar7 = (-(uint)bVar4 & 6) + 7;
    piVar7[1] = iVar5;
    piVar7[2] = 1;
    iVar5 = iVar5 + 0x4b0;
    bVar4 = bVar4 ^ 1;
    piVar7 = piVar7 + 6;
  } while (iVar6 < 0x1860);
  iVar6 = 0;
  bVar4 = 0;
  piVar7 = &entries[uVar8 + 0x16].pos_y_block.heading_block.template_id;
  do {
    piVar7[-3] = (int)(float)(iVar6 / 10 + 200);
    piVar7[-2] = 0x43480000;
    iVar6 = iVar6 + 0x270;
    *piVar7 = (-(uint)bVar4 & 6) + 7;
    piVar7[1] = iVar5;
    piVar7[2] = 1;
    iVar5 = iVar5 + 800;
    bVar4 = bVar4 ^ 1;
    piVar7 = piVar7 + 6;
  } while (iVar6 < 0x1860);
  iVar6 = 0;
  bVar4 = 0;
  piVar7 = &entries[uVar8 + 0x20].pos_y_block.heading_block.template_id;
  do {
    piVar7[-3] = 0x444e0000;
    piVar7[-2] = (int)(float)(iVar6 / 10 + 200);
    iVar6 = iVar6 + 0x270;
    *piVar7 = (-(uint)bVar4 & 6) + 7;
    piVar7[1] = iVar5;
    piVar7[2] = 1;
    iVar5 = iVar5 + 800;
    bVar4 = bVar4 ^ 1;
    piVar7 = piVar7 + 6;
  } while (iVar6 < 0x1860);
  iVar6 = 0;
  bVar4 = 0;
  piVar7 = &entries[uVar8 + 0x2a].pos_y_block.heading_block.template_id;
  do {
    piVar7[-3] = (int)(float)(0x338 - iVar6 / 10);
    piVar7[-2] = 0x444e0000;
    iVar6 = iVar6 + 0x270;
    *piVar7 = (-(uint)bVar4 & 6) + 7;
    piVar7[1] = iVar5;
    piVar7[2] = 1;
    iVar5 = iVar5 + 700;
    bVar4 = bVar4 ^ 1;
    piVar7 = piVar7 + 6;
  } while (iVar6 < 0x1860);
  iVar6 = 0;
  bVar4 = 0;
  piVar7 = &entries[uVar8 + 0x34].pos_y_block.heading_block.template_id;
  do {
    piVar7[-3] = 0x43480000;
    piVar7[-2] = (int)(float)(0x338 - iVar6 / 10);
    iVar6 = iVar6 + 0x270;
    *piVar7 = (-(uint)bVar4 & 6) + 7;
    piVar7[1] = iVar5;
    piVar7[2] = 1;
    iVar5 = iVar5 + 700;
    bVar4 = bVar4 ^ 1;
    piVar7 = piVar7 + 6;
  } while (iVar6 < 0x1860);
  iVar6 = 0;
  bVar4 = 0;
  piVar7 = &entries[uVar8 + 0x3e].pos_y_block.heading_block.template_id;
  do {
    piVar7[-3] = (int)(float)(iVar6 / 10 + 200);
    piVar7[-2] = 0x43480000;
    iVar6 = iVar6 + 0x270;
    *piVar7 = (-(uint)bVar4 & 6) + 7;
    piVar7[1] = iVar5;
    piVar7[2] = 1;
    iVar5 = iVar5 + 800;
    bVar4 = bVar4 ^ 1;
    piVar7 = piVar7 + 6;
  } while (iVar6 < 0x1860);
  *count = uVar8 + 0x48;
  return;
}



