/* quest_build_target_practice @ 00437a00 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 1 Quest 3 (Target Practice) */

void quest_build_target_practice(quest_spawn_entry_t *entries,int *count)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  
  iVar4 = 2000;
  iVar6 = 2000;
  piVar5 = &(entries->pos_y_block).heading_block.trigger_time_ms;
  do {
    iVar2 = crt_rand();
    fVar1 = (float)(iVar2 % 0x264) * 0.01;
    uVar3 = crt_rand();
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    fVar7 = (float10)(int)((uVar3 + 2) * 0x20);
    fVar8 = (float10)fcos((float10)fVar1);
    fVar9 = (float10)fsin((float10)fVar1);
    piVar5[-4] = (int)((float)(fVar8 * fVar7) + 512.0);
    piVar5[-3] = (int)(float)(fVar9 * fVar7 + (float10)512.0);
    piVar5[-1] = 0x36;
    *piVar5 = iVar4;
    piVar5[1] = 1;
    fVar7 = (float10)fpatan((float10)(float)piVar5[-3] - (float10)512.0,
                            (float10)(float)piVar5[-4] - (float10)512.0);
    ((quest_spawn_entry_heading_block_t *)(piVar5 + -2))->heading =
         (float)(fVar7 - (float10)1.5707964);
    iVar2 = iVar6;
    if (iVar6 < 0x44c) {
      iVar2 = 0x44c;
    }
    iVar6 = iVar6 + -0x32;
    iVar4 = iVar4 + iVar2;
    piVar5 = piVar5 + 6;
  } while (500 < iVar6);
  *count = 0x1e;
  return;
}



