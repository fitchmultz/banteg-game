/* quest_build_lizard_zombie_pact @ 00438700 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 4 Quest 3 (Lizard Zombie Pact) */

void quest_build_lizard_zombie_pact(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_4;
  
  iVar5 = 0x5dc;
  iStack_4 = 0;
  iVar3 = 0;
  do {
    pqVar1 = entries + iVar3;
    pqVar1->pos_x = (float)(terrain_texture_width + 0x40);
    (pqVar1->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (pqVar1->pos_y_block).heading_block.template_id = 0x41;
    (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar5;
    (pqVar1->pos_y_block).heading_block.count = 6;
    pqVar1 = entries + iVar3 + 1;
    pqVar1->pos_x = -64.0;
    (pqVar1->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (pqVar1->pos_y_block).heading_block.template_id = 0x41;
    (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar5;
    (pqVar1->pos_y_block).heading_block.count = 6;
    iVar4 = iVar3 + 2;
    if (iStack_4 % 5 == 0) {
      pqVar1 = entries + iVar4;
      iVar2 = iStack_4 / 5;
      pqVar1->pos_x = 356.0;
      (pqVar1->pos_y_block).pos_y = (float)(iVar2 * 0xb4 + 0x100);
      (pqVar1->pos_y_block).heading_block.template_id = 0xc;
      (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar5;
      (pqVar1->pos_y_block).heading_block.count = iVar2 + 1;
      iVar4 = iVar3 + 4;
      pqVar1 = entries + iVar3 + 3;
      pqVar1->pos_x = 356.0;
      (pqVar1->pos_y_block).pos_y = (float)(iVar2 * 0xb4 + 0x180);
      (pqVar1->pos_y_block).heading_block.template_id = 0xc;
      (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar5;
      (pqVar1->pos_y_block).heading_block.count = iVar2 + 2;
    }
    iVar5 = iVar5 + 7000;
    iStack_4 = iStack_4 + 1;
    iVar3 = iVar4;
  } while (iVar5 < 0x1bb5c);
  *count = iVar4;
  return;
}



