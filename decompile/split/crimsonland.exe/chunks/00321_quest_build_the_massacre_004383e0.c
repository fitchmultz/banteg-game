/* quest_build_the_massacre @ 004383e0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 4 Quest 5 (The Massacre) */

void quest_build_the_massacre(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  iVar6 = 0x5dc;
  uVar2 = 0;
  iVar4 = 0;
  do {
    pqVar1 = entries + 1;
    entries->pos_x = (float)(terrain_texture_width + 0x40);
    iVar5 = iVar4 + 1;
    uVar3 = uVar2 & 0x80000001;
    bVar7 = uVar3 == 0;
    (entries->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (entries->pos_y_block).heading_block.template_id = 0x41;
    (entries->pos_y_block).heading_block.trigger_time_ms = iVar6;
    (entries->pos_y_block).heading_block.count = uVar2 + 3;
    if ((int)uVar3 < 0) {
      bVar7 = (uVar3 - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (bVar7) {
      pqVar1->pos_x = (float)(terrain_texture_width + 0x80);
      iVar5 = iVar4 + 2;
      pqVar1 = entries + 2;
      entries[1].pos_y_block.pos_y = (float)(terrain_texture_width / 2);
      entries[1].pos_y_block.heading_block.template_id = 0x2b;
      entries[1].pos_y_block.heading_block.trigger_time_ms = iVar6;
      entries[1].pos_y_block.heading_block.count = uVar2 + 1;
    }
    iVar6 = iVar6 + 5000;
    entries = pqVar1;
    uVar2 = uVar2 + 1;
    iVar4 = iVar5;
  } while (iVar6 < 0x1656c);
  *count = iVar5;
  return;
}



