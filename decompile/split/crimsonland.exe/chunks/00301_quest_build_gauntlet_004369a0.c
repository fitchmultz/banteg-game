/* quest_build_gauntlet @ 004369a0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 4 Quest 7 (Gauntlet) */

void quest_build_gauntlet(quest_spawn_entry_t *entries,int *count)

{
  int iVar1;
  quest_spawn_entry_t *pqVar2;
  int *piVar3;
  quest_spawn_entry_t *pqVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  int iStack_8;
  int iStack_4;
  
  pqVar2 = entries;
  iVar6 = 0;
  iStack_8 = 0;
  if (config_blob.hardcore != '\0') {
    config_blob.reserved0._20_4_ = config_blob.reserved0._20_4_ + 4;
  }
  iStack_4 = config_blob.reserved0._20_4_ + 9;
  if (0 < iStack_4) {
    iVar7 = 0;
    piVar3 = &(entries->pos_y_block).heading_block.template_id;
    do {
      fVar8 = (float10)fcos(((float10)iStack_8 * (float10)6.2831855) / (float10)iStack_4);
      piVar3[-3] = (int)(float)(fVar8 * (float10)158.0 + (float10)512.0);
      iVar6 = iStack_8 + 1;
      fVar8 = (float10)fsin(((float10)iStack_8 * (float10)6.2831855) /
                            (float10)(config_blob.reserved0._20_4_ + 9));
      piVar3[-2] = (int)(float)(fVar8 * (float10)158.0 + (float10)512.0);
      *piVar3 = 10;
      piVar3[1] = iVar7;
      piVar3[2] = 1;
      iVar7 = iVar7 + 200;
      iStack_4 = config_blob.reserved0._20_4_ + 9;
      piVar3 = piVar3 + 6;
      iStack_8 = iVar6;
    } while (iVar6 < iStack_4);
  }
  if (config_blob.reserved0._20_4_ != -9 && -1 < config_blob.reserved0._20_4_ + 9) {
    iVar5 = 4000;
    pqVar4 = entries + iVar6;
    iVar7 = 2;
    do {
      pqVar4->pos_x = (float)(terrain_texture_width + 0x40);
      (pqVar4->pos_y_block).pos_y = (float)(terrain_texture_width / 2);
      (pqVar4->pos_y_block).heading_block.template_id = 0x41;
      (pqVar4->pos_y_block).heading_block.trigger_time_ms = iVar5;
      (pqVar4->pos_y_block).heading_block.count = iVar7;
      pqVar4[1].pos_x = -64.0;
      pqVar4[1].pos_y_block.pos_y = (float)(terrain_texture_width / 2);
      pqVar4[1].pos_y_block.heading_block.template_id = 0x41;
      pqVar4[1].pos_y_block.heading_block.trigger_time_ms = iVar5;
      pqVar4[1].pos_y_block.heading_block.count = iVar7;
      pqVar4[2].pos_x = (float)(terrain_texture_width / 2);
      pqVar4[2].pos_y_block.pos_y = (float)(terrain_texture_width + 0x40);
      pqVar4[2].pos_y_block.heading_block.template_id = 0x41;
      pqVar4[2].pos_y_block.heading_block.trigger_time_ms = iVar5;
      pqVar4[2].pos_y_block.heading_block.count = iVar7;
      iVar6 = iVar6 + 4;
      pqVar4[3].pos_x = (float)(terrain_texture_width / 2);
      pqVar4[3].pos_y_block.pos_y = -64.0;
      pqVar4[3].pos_y_block.heading_block.template_id = 0x41;
      pqVar4[3].pos_y_block.heading_block.trigger_time_ms = iVar5;
      pqVar4[3].pos_y_block.heading_block.count = iVar7;
      iVar5 = iVar5 + 0x157c;
      iVar1 = iVar7 + -1;
      pqVar4 = pqVar4 + 4;
      iVar7 = iVar7 + 1;
    } while (iVar1 < config_blob.reserved0._20_4_ + 9);
  }
  iStack_4 = config_blob.reserved0._20_4_ + 0x11;
  entries = (quest_spawn_entry_t *)0x0;
  if (0 < iStack_4) {
    iVar7 = 0xa604;
    piVar3 = &pqVar2[iVar6].pos_y_block.heading_block.template_id;
    do {
      fVar8 = (float10)(int)entries;
      fVar9 = (float10)fcos((fVar8 * (float10)6.2831855) / (float10)iStack_4);
      piVar3[-3] = (int)(float)(fVar9 * (float10)258.0 + (float10)512.0);
      iVar6 = iVar6 + 1;
      entries = (quest_spawn_entry_t *)((int)&entries->pos_x + 1);
      fVar8 = (float10)fsin((fVar8 * (float10)6.2831855) /
                            (float10)(config_blob.reserved0._20_4_ + 0x11));
      piVar3[-2] = (int)(float)(fVar8 * (float10)258.0 + (float10)512.0);
      *piVar3 = 10;
      piVar3[1] = iVar7;
      piVar3[2] = 1;
      iVar7 = iVar7 + 500;
      iStack_4 = config_blob.reserved0._20_4_ + 0x11;
      piVar3 = piVar3 + 6;
    } while ((int)entries < iStack_4);
  }
  if (config_blob.hardcore == '\0') {
    *count = iVar6;
    return;
  }
  config_blob.reserved0._20_4_ = config_blob.reserved0._20_4_ + -4;
  *count = iVar6;
  return;
}



