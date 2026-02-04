/* quest_build_the_annihilation @ 004382c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 4 Quest 9 (The Annihilation) */

void quest_build_the_annihilation(quest_spawn_entry_t *entries,int *count)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 500;
  entries->pos_x = 128.0;
  uVar3 = 0;
  iVar5 = 0;
  piVar1 = &entries[1].pos_y_block.heading_block.template_id;
  (entries->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
  (entries->pos_y_block).heading_block.template_id = 0x2b;
  (entries->pos_y_block).heading_block.trigger_time_ms = 500;
  (entries->pos_y_block).heading_block.count = 2;
  do {
    piVar1[-2] = (int)(float)(iVar5 / 0xc + 0x80);
    if ((uVar3 & 1) == 0) {
      piVar1[-3] = 0x44500000;
    }
    else {
      piVar1[-3] = 0x44600000;
    }
    *piVar1 = 7;
    piVar1[1] = iVar4;
    piVar1[2] = 1;
    iVar4 = iVar4 + 500;
    iVar5 = iVar5 + 0x300;
    piVar1 = piVar1 + 6;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0xc);
  bVar2 = false;
  iVar5 = 0;
  iVar4 = 45000;
  piVar1 = &entries[0xd].pos_y_block.heading_block.template_id;
  do {
    piVar1[-2] = (int)(float)(iVar5 / 0xc + 0x80);
    if (bVar2) {
      piVar1[-3] = 0x44500000;
    }
    else {
      piVar1[-3] = 0x44600000;
    }
    *piVar1 = 7;
    piVar1[1] = iVar4;
    piVar1[2] = 1;
    piVar1 = piVar1 + 6;
    iVar4 = iVar4 + 300;
    bVar2 = (bool)(bVar2 ^ 1);
    iVar5 = iVar5 + 0x300;
  } while (iVar4 < 0xbdd8);
  *count = 0x19;
  return;
}



