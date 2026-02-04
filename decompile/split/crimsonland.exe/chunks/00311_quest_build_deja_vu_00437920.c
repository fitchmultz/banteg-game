/* quest_build_deja_vu @ 00437920 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 3 Quest 9 (Deja vu) */

void quest_build_deja_vu(quest_spawn_entry_t *entries,int *count)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  int iStack_18;
  
  iVar4 = 2000;
  iStack_18 = 2000;
  piVar3 = &(entries->pos_y_block).heading_block.trigger_time_ms;
  do {
    iVar1 = crt_rand();
    entries = (quest_spawn_entry_t *)0x54;
    fVar5 = (float10)(iVar1 % 0x264) * (float10)0.01;
    fVar6 = (float10)fcos(fVar5);
    fVar5 = (float10)fsin(fVar5);
    piVar2 = piVar3;
    do {
      fVar7 = (float10)(int)entries;
      entries = (quest_spawn_entry_t *)
                ((int)&entries[1].pos_y_block.heading_block.trigger_time_ms + 2);
      piVar2[-4] = (int)((float)(fVar7 * (float10)(float)fVar6) + 512.0);
      piVar2[-3] = (int)(float)(fVar7 * fVar5 + (float10)512.0);
      piVar2[-1] = 0xd;
      *piVar2 = iVar4;
      piVar2[1] = 1;
      piVar2 = piVar2 + 6;
    } while ((int)entries < 0xfc);
    iVar4 = iVar4 + iStack_18;
    iStack_18 = iStack_18 + -0x50;
    piVar3 = piVar3 + 0x18;
  } while (0x230 < iStack_18);
  *count = 0x48;
  return;
}



