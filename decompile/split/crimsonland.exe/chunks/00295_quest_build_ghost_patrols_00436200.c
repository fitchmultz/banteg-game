/* quest_build_ghost_patrols @ 00436200 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 2 Quest 9 (Ghost Patrols) */

void quest_build_ghost_patrols(quest_spawn_entry_t *entries,int *count)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  bool bVar5;
  
  iVar2 = 0x9c4;
  entries->pos_x = (float)(terrain_texture_width + 0x80);
  (entries->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
  (entries->pos_y_block).heading_block.template_id = 0x2b;
  (entries->pos_y_block).heading_block.trigger_time_ms = 0x5dc;
  (entries->pos_y_block).heading_block.count = 2;
  piVar3 = &entries[1].pos_y_block.heading_block.template_id;
  uVar1 = 0;
  do {
    uVar4 = uVar1;
    uVar1 = uVar4 & 0x80000001;
    bVar5 = uVar1 == 0;
    if ((int)uVar1 < 0) {
      bVar5 = (uVar1 - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (bVar5) {
      piVar3[-3] = 0xc3000000;
    }
    else {
      piVar3[-3] = 0x44900000;
    }
    uVar1 = uVar4 + 1;
    piVar3[-2] = (int)(float)(terrain_texture_width / 2);
    *piVar3 = 0x19;
    piVar3[1] = iVar2;
    piVar3[2] = 1;
    iVar2 = iVar2 + 0x9c4;
    piVar3 = piVar3 + 6;
  } while (iVar2 < 0x7ef4);
  entries[0xd].pos_x = -264.0;
  entries[0xd].pos_y_block.pos_y = (float)(terrain_texture_width / 2);
  entries[0xd].pos_y_block.heading_block.template_id = 0x2b;
  entries[0xd].pos_y_block.heading_block.trigger_time_ms = uVar1 * 0x9c4 + -0x9c4;
  entries[0xd].pos_y_block.heading_block.count = 1;
  entries[0xe].pos_x = -128.0;
  entries[0xe].pos_y_block.pos_y = (float)(terrain_texture_width / 2);
  entries[0xe].pos_y_block.heading_block.template_id = 0x18;
  entries[0xe].pos_y_block.heading_block.trigger_time_ms = (uVar4 + 0x10 + uVar1 * 4) * 500;
  entries[0xe].pos_y_block.heading_block.count = 1;
  *count = 0xf;
  return;
}



