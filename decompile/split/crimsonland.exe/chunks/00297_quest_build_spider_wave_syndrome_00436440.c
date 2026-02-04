/* quest_build_spider_wave_syndrome @ 00436440 */

/* quest builder for Tier 1 Quest 7 (Spider Wave Syndrome) */

void __cdecl quest_build_spider_wave_syndrome(quest_spawn_entry_t *entries,int *count)

{
  quest_spawn_entry_t *pqVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0x5dc;
  do {
    pqVar1 = entries + iVar2;
    pqVar1->pos_x = -64.0;
    iVar2 = iVar2 + 1;
    (pqVar1->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
    (pqVar1->pos_y_block).heading_block.template_id = 0x40;
    (pqVar1->pos_y_block).heading_block.trigger_time_ms = iVar3;
    iVar3 = iVar3 + 0x157c;
    (pqVar1->pos_y_block).heading_block.count = config_blob.reserved0._20_4_ * 2 + 6;
  } while (iVar3 < 0x18894);
  *count = iVar2;
  return;
}



