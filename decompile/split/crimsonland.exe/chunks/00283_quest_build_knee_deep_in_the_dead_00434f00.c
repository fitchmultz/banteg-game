/* quest_build_knee_deep_in_the_dead @ 00434f00 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 5 Quest 5 (Knee-deep in the Dead) */

void quest_build_knee_deep_in_the_dead(quest_spawn_entry_t *entries,int *count)

{
  float fVar1;
  quest_spawn_entry_t *pqVar2;
  quest_spawn_entry_t *pqVar3;
  quest_spawn_entry_t *pqVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  fVar1 = (float)terrain_texture_height;
  entries->pos_x = -50.0;
  (entries->pos_y_block).pos_y = fVar1 * 0.5;
  (entries->pos_y_block).heading_block.template_id = 0x43;
  (entries->pos_y_block).heading_block.trigger_time_ms = 100;
  (entries->pos_y_block).heading_block.count = 1;
  uVar7 = 0;
  iVar8 = 1;
  pqVar4 = entries + 1;
  iVar5 = 500;
  do {
    uVar6 = uVar7 & 0x80000007;
    bVar10 = uVar6 == 0;
    if ((int)uVar6 < 0) {
      bVar10 = (uVar6 - 1 | 0xfffffff8) == 0xffffffff;
    }
    pqVar2 = pqVar4;
    iVar9 = iVar8;
    if (bVar10) {
      fVar1 = (float)terrain_texture_height;
      pqVar4->pos_x = -50.0;
      iVar9 = iVar8 + 1;
      pqVar2 = pqVar4 + 1;
      (pqVar4->pos_y_block).pos_y = fVar1 * 0.5;
      (pqVar4->pos_y_block).heading_block.template_id = 0x43;
      (pqVar4->pos_y_block).heading_block.trigger_time_ms = iVar5 + -2;
      (pqVar4->pos_y_block).heading_block.count = 1;
    }
    fVar1 = (float)terrain_texture_height;
    pqVar2->pos_x = -50.0;
    (pqVar2->pos_y_block).pos_y = fVar1 * 0.5;
    (pqVar2->pos_y_block).heading_block.template_id = 0x41;
    (pqVar2->pos_y_block).heading_block.trigger_time_ms = iVar5;
    (pqVar2->pos_y_block).heading_block.count = (0x20 < (int)uVar7) + 1;
    iVar8 = iVar9 + 1;
    pqVar4 = pqVar2 + 1;
    if (0x30d4 < iVar5) {
      fVar1 = (float)terrain_texture_height;
      pqVar4->pos_x = -50.0;
      iVar8 = iVar9 + 2;
      pqVar4 = pqVar2 + 2;
      pqVar2[1].pos_y_block.pos_y = fVar1 * 0.5 + 158.0;
      pqVar2[1].pos_y_block.heading_block.template_id = 0x41;
      pqVar2[1].pos_y_block.heading_block.trigger_time_ms = iVar5 + 500;
      pqVar2[1].pos_y_block.heading_block.count = 1;
    }
    pqVar2 = pqVar4;
    if (0x5fb4 < iVar5) {
      fVar1 = (float)terrain_texture_height;
      pqVar4->pos_x = -50.0;
      iVar8 = iVar8 + 1;
      pqVar2 = pqVar4 + 1;
      (pqVar4->pos_y_block).pos_y = fVar1 * 0.5 - 158.0;
      (pqVar4->pos_y_block).heading_block.template_id = 0x41;
      (pqVar4->pos_y_block).heading_block.trigger_time_ms = iVar5 + 1000;
      (pqVar4->pos_y_block).heading_block.count = 1;
    }
    pqVar3 = pqVar2;
    if (0x8e94 < iVar5) {
      fVar1 = (float)terrain_texture_height;
      pqVar2->pos_x = -50.0;
      iVar8 = iVar8 + 1;
      pqVar3 = pqVar2 + 1;
      (pqVar2->pos_y_block).pos_y = fVar1 * 0.5 - 258.0;
      (pqVar2->pos_y_block).heading_block.template_id = 0x42;
      (pqVar2->pos_y_block).heading_block.trigger_time_ms = iVar5 + 0x514;
      (pqVar2->pos_y_block).heading_block.count = 1;
    }
    pqVar4 = pqVar3;
    if (0xbd74 < iVar5) {
      fVar1 = (float)terrain_texture_height;
      pqVar3->pos_x = -50.0;
      iVar8 = iVar8 + 1;
      pqVar4 = pqVar3 + 1;
      (pqVar3->pos_y_block).pos_y = fVar1 * 0.5 + 258.0;
      (pqVar3->pos_y_block).heading_block.template_id = 0x42;
      (pqVar3->pos_y_block).heading_block.trigger_time_ms = iVar5 + 300;
      (pqVar3->pos_y_block).heading_block.count = 1;
    }
    iVar5 = iVar5 + 0x5dc;
    uVar7 = uVar7 + 1;
  } while (iVar5 < 0x178f4);
  *count = iVar8;
  return;
}



