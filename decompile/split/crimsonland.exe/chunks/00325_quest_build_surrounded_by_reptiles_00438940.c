/* quest_build_surrounded_by_reptiles @ 00438940 */

/* quest builder for Tier 3 Quest 5 (Surrounded By Reptiles) */

void __cdecl quest_build_surrounded_by_reptiles(quest_spawn_entry_t *entries,int *count)

{
  float fVar1;
  quest_spawn_entry_t *pqVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar3 = 0;
  local_4 = 0;
  iVar4 = 1000;
  pqVar2 = entries;
  do {
    fVar1 = (float)local_4;
    pqVar2->pos_x = 256.0;
    iVar3 = iVar3 + 2;
    local_4 = local_4 + 0x200;
    fVar1 = fVar1 * 0.2 + 256.0;
    (pqVar2->pos_y_block).pos_y = fVar1;
    (pqVar2->pos_y_block).heading_block.template_id = 0xd;
    (pqVar2->pos_y_block).heading_block.trigger_time_ms = iVar4;
    (pqVar2->pos_y_block).heading_block.count = 1;
    pqVar2[1].pos_x = 768.0;
    pqVar2[1].pos_y_block.pos_y = fVar1;
    pqVar2[1].pos_y_block.heading_block.template_id = 0xd;
    pqVar2[1].pos_y_block.heading_block.trigger_time_ms = iVar4;
    pqVar2[1].pos_y_block.heading_block.count = 1;
    iVar4 = iVar4 + 800;
    pqVar2 = pqVar2 + 2;
  } while (iVar4 < 5000);
  local_4 = 0;
  iVar4 = 8000;
  pqVar2 = entries + iVar3;
  do {
    fVar1 = (float)local_4;
    (pqVar2->pos_y_block).pos_y = 256.0;
    iVar3 = iVar3 + 2;
    local_4 = local_4 + 0x200;
    fVar1 = fVar1 * 0.2 + 256.0;
    pqVar2->pos_x = fVar1;
    (pqVar2->pos_y_block).heading_block.template_id = 0xd;
    (pqVar2->pos_y_block).heading_block.trigger_time_ms = iVar4;
    (pqVar2->pos_y_block).heading_block.count = 1;
    pqVar2[1].pos_y_block.pos_y = 768.0;
    pqVar2[1].pos_x = fVar1;
    pqVar2[1].pos_y_block.heading_block.template_id = 0xd;
    pqVar2[1].pos_y_block.heading_block.trigger_time_ms = iVar4;
    pqVar2[1].pos_y_block.heading_block.count = 1;
    iVar4 = iVar4 + 800;
    pqVar2 = pqVar2 + 2;
  } while (iVar4 < 12000);
  *count = iVar3;
  return;
}



