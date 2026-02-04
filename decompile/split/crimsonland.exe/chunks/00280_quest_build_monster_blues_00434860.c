/* quest_build_monster_blues @ 00434860 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 5 Quest 8 (Monster Blues) */

void quest_build_monster_blues(quest_spawn_entry_t *entries,int *count)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  
  fVar1 = (float)terrain_texture_height;
  entries->pos_x = -50.0;
  (entries->pos_y_block).pos_y = fVar1 * 0.5;
  (entries->pos_y_block).heading_block.template_id = 4;
  (entries->pos_y_block).heading_block.trigger_time_ms = 500;
  (entries->pos_y_block).heading_block.count = 10;
  fVar1 = (float)terrain_texture_height;
  entries[1].pos_x = 1074.0;
  entries[1].pos_y_block.pos_y = fVar1 * 0.5;
  entries[1].pos_y_block.heading_block.template_id = 6;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 0x1d4c;
  entries[1].pos_y_block.heading_block.count = 10;
  entries[2].pos_x = 512.0;
  entries[2].pos_y_block.pos_y = 1088.0;
  entries[2].pos_y_block.heading_block.template_id = 3;
  entries[2].pos_y_block.heading_block.trigger_time_ms = 0x445c;
  entries[2].pos_y_block.heading_block.count = 0xc;
  entries[3].pos_x = 512.0;
  entries[3].pos_y_block.pos_y = -64.0;
  entries[3].pos_y_block.heading_block.template_id = 3;
  entries[3].pos_y_block.heading_block.trigger_time_ms = 0x445c;
  entries[3].pos_y_block.heading_block.count = 0xc;
  uVar5 = 0;
  iVar6 = 0x6b6c;
  piVar4 = &entries[4].pos_y_block.heading_block.template_id;
  do {
    piVar4[-3] = -0x3d800000;
    uVar2 = uVar5 & 0x80000003;
    piVar4[-2] = 0x44000000;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffffffc) + 1;
    }
    if (uVar2 == 0) {
      *piVar4 = 6;
    }
    else {
      *piVar4 = (-(uint)(uVar2 != 1) & 2) + 3;
    }
    piVar4[1] = iVar6;
    iVar6 = iVar6 + 900;
    iVar3 = uVar5 + ((int)uVar5 >> 0x1f & 7U);
    uVar5 = uVar5 + 1;
    piVar4[2] = (iVar3 >> 3) + 2;
    piVar4 = piVar4 + 6;
  } while ((int)uVar5 < 0x40);
  *count = 0x44;
  return;
}



