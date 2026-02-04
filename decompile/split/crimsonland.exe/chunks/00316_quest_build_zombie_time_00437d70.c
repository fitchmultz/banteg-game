/* quest_build_zombie_time @ 00437d70 */

/* quest builder for Tier 4 Quest 2 (Zombie Time) */

void __cdecl quest_build_zombie_time(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0x5dc;
  do {
    pqVar1 = entries + iVar2;
    pqVar1->pos_x = (float)(terrain_texture_width + 0x40);
    (pqVar1->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (pqVar1->pos_y_block).heading_block.template_id = 0x41;
    (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar3;
    (pqVar1->pos_y_block).heading_block.count = 8;
    pqVar1 = entries + iVar2 + 1;
    pqVar1->pos_x = -64.0;
    iVar2 = iVar2 + 2;
    (pqVar1->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (pqVar1->pos_y_block).heading_block.template_id = 0x41;
    (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar3;
    iVar3 = iVar3 + 8000;
    (pqVar1->pos_y_block).heading_block.count = 8;
  } while (iVar3 < 0x17cdc);
  *count = iVar2;
  return;
}



