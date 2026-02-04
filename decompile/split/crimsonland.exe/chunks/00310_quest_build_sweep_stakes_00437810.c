/* quest_build_sweep_stakes @ 00437810 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* quest builder for Tier 2 Quest 5 (Sweep Stakes) */

void quest_build_sweep_stakes(quest_spawn_entry_trigger_cursor_t *cursor,int *count)

{
  int iVar1;
  quest_spawn_entry_trigger_cursor_t *pqVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  int iStack_18;
  
  iVar3 = 2000;
  iVar4 = 2000;
  cursor = (quest_spawn_entry_trigger_cursor_t *)&(cursor->next).heading;
  do {
    iVar1 = crt_rand();
    iStack_18 = 0x54;
    fVar5 = (float10)(iVar1 % 0x264) * (float10)0.01;
    fVar6 = (float10)fcos(fVar5);
    fVar5 = (float10)fsin(fVar5);
    pqVar2 = cursor;
    do {
      fVar7 = (float10)iStack_18;
      iStack_18 = iStack_18 + 0x2a;
      pqVar2[-1].next.pos_x = (float)(fVar7 * (float10)(float)fVar6) + 512.0;
      pqVar2[-1].next.pos_y = (float)(fVar7 * fVar5 + (float10)512.0);
      pqVar2[-1].next.template_id = 0x36;
      pqVar2->trigger_time_ms = iVar3;
      pqVar2->count = 1;
      fVar7 = (float10)fpatan((float10)pqVar2[-1].next.pos_y - (float10)512.0,
                              (float10)pqVar2[-1].next.pos_x - (float10)512.0);
      pqVar2[-1].next.heading = (float)(fVar7 - (float10)1.5707964);
      pqVar2 = pqVar2 + 1;
    } while (iStack_18 < 0xfc);
    iVar1 = iVar4;
    if (iVar4 < 600) {
      iVar1 = 600;
    }
    iVar4 = iVar4 + -0x50;
    iVar3 = iVar3 + iVar1;
    cursor = cursor + 4;
  } while (0x2d0 < iVar4);
  *count = 0x40;
  return;
}



