/* quest_build_the_gang_wars @ 00435120 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 5 Quest 4 (The Gang Wars) */

void quest_build_the_gang_wars(quest_spawn_entry_t *entries,int *count)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  fVar1 = (float)terrain_texture_height;
  entries->pos_x = -150.0;
  (entries->pos_y_block).pos_y = fVar1 * 0.5;
  (entries->pos_y_block).heading_block.template_id = 0x12;
  (entries->pos_y_block).heading_block.trigger_time_ms = 100;
  (entries->pos_y_block).heading_block.count = 1;
  fVar1 = (float)terrain_texture_height;
  entries[1].pos_x = 1174.0;
  iVar4 = 10;
  entries[1].pos_y_block.pos_y = fVar1 * 0.5;
  entries[1].pos_y_block.heading_block.template_id = 0x12;
  entries[1].pos_y_block.heading_block.trigger_time_ms = 0x9c4;
  entries[1].pos_y_block.heading_block.count = 1;
  iVar3 = 0x157c;
  piVar2 = &entries[2].pos_y_block.heading_block.trigger_time_ms;
  do {
    fVar1 = (float)terrain_texture_height;
    piVar2[-4] = 0x4492c000;
    piVar2[-3] = (int)(fVar1 * 0.5);
    piVar2[-1] = 0x12;
    *piVar2 = iVar3;
    piVar2[1] = 2;
    iVar3 = iVar3 + 4000;
    iVar4 = iVar4 + -1;
    piVar2 = piVar2 + 6;
  } while (iVar4 != 0);
  entries[0xc].pos_x = 512.0;
  entries[0xc].pos_y_block.pos_y = 1152.0;
  entries[0xc].pos_y_block.heading_block.template_id = 0x13;
  entries[0xc].pos_y_block.heading_block.trigger_time_ms = 0xc544;
  entries[0xc].pos_y_block.heading_block.count = 1;
  iVar3 = 0xe86c;
  piVar2 = &entries[0xd].pos_y_block.heading_block.trigger_time_ms;
  do {
    fVar1 = (float)terrain_texture_height;
    piVar2[-4] = -0x3cea0000;
    piVar2[-3] = (int)(fVar1 * 0.5);
    piVar2[-1] = 0x12;
    *piVar2 = iVar3;
    piVar2[1] = 2;
    iVar3 = iVar3 + 4000;
    piVar2 = piVar2 + 6;
  } while (iVar3 < 0x184ac);
  entries[0x17].pos_x = 512.0;
  entries[0x17].pos_y_block.pos_y = 1152.0;
  entries[0x17].pos_y_block.heading_block.template_id = 0x13;
  entries[0x17].pos_y_block.heading_block.trigger_time_ms = 0x1a3ec;
  entries[0x17].pos_y_block.heading_block.count = 3;
  *count = 0x18;
  return;
}



