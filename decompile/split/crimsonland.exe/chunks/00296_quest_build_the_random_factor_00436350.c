/* quest_build_the_random_factor @ 00436350 */

/* quest builder for Tier 1 Quest 6 (The Random Factor) */

void __cdecl quest_build_the_random_factor(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0x5dc;
  iVar3 = 0;
  do {
    pqVar1 = entries + iVar3;
    pqVar1->pos_x = (float)(terrain_texture_width + 0x40);
    (pqVar1->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (pqVar1->pos_y_block).heading_block.template_id = 0x1d;
    (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar5;
    (pqVar1->pos_y_block).heading_block.count = config_blob.reserved0._20_4_ * 2 + 4;
    pqVar1 = entries + iVar3 + 1;
    pqVar1->pos_x = -64.0;
    iVar4 = iVar3 + 2;
    (pqVar1->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (pqVar1->pos_y_block).heading_block.template_id = 0x1d;
    (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar5 + 200;
    (pqVar1->pos_y_block).heading_block.count = 6;
    iVar2 = crt_rand();
    if (iVar2 % 5 == 3) {
      pqVar1 = entries + iVar4;
      iVar4 = iVar3 + 3;
      pqVar1->pos_x = (float)(terrain_texture_width / 2);
      (pqVar1->pos_y_block).pos_y = 1088.0;
      (pqVar1->pos_y_block).heading_block.template_id = 0x29;
      (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar5;
      (pqVar1->pos_y_block).heading_block.count = config_blob.reserved0._20_4_;
    }
    iVar5 = iVar5 + 10000;
    iVar3 = iVar4;
  } while (iVar5 < 0x18c7c);
  *count = iVar4;
  return;
}



