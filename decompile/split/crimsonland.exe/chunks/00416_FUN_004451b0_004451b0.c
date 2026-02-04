/* FUN_004451b0 @ 004451b0 */

/* [binja] void* sub_4451b0() */

void * FUN_004451b0(void)

{
  byte bVar1;
  char *pcVar2;
  highscore_record_t *phVar3;
  int iVar4;
  uint uVar5;
  void *pvVar6;
  void *this;
  void *extraout_ECX;
  uint uVar7;
  int iVar8;
  int iVar9;
  highscore_record_t *phVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  byte *pbVar13;
  highscore_record_t *phVar14;
  undefined4 *puVar15;
  bool bVar16;
  undefined4 *local_8;
  int local_4;
  
  if (DAT_004d7580 == '\0') {
    highscore_load_table();
    iVar9 = 0;
    phVar10 = &highscore_table;
    local_4 = 0;
    local_8 = (undefined4 *)&DAT_004d1228;
    do {
      pbVar12 = &DAT_004d1228;
      iVar8 = 0;
      phVar3 = phVar10;
      pbVar13 = pbVar12;
      if (0x4d1228 < (int)local_8) {
LAB_004451ef:
        do {
          bVar1 = phVar3->player_name[0];
          bVar16 = bVar1 < *pbVar12;
          if (bVar1 == *pbVar12) {
            if (bVar1 != 0) {
              bVar1 = phVar3->player_name[1];
              bVar16 = bVar1 < pbVar12[1];
              if (bVar1 != pbVar12[1]) goto LAB_00445213;
              pbVar12 = pbVar12 + 2;
              phVar3 = (highscore_record_t *)(phVar3->player_name + 2);
              if (bVar1 != 0) goto LAB_004451ef;
            }
            iVar4 = 0;
          }
          else {
LAB_00445213:
            iVar4 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
          }
          iVar9 = local_4;
          if (iVar4 == 0) goto LAB_004452a7;
          iVar8 = iVar8 + 1;
          pbVar12 = pbVar13 + 0x20;
          phVar3 = phVar10;
          pbVar13 = pbVar12;
        } while (iVar8 < local_4);
      }
      uVar5 = 0xffffffff;
      iVar8 = 0;
      phVar3 = phVar10;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar2 = phVar3->player_name;
        phVar3 = (highscore_record_t *)(phVar3->player_name + 1);
      } while (*pcVar2 != '\0');
      pvVar6 = (void *)(~uVar5 - 1);
      this = pvVar6;
      if (0 < (int)pvVar6) {
        do {
          uVar5 = crt_isalpha(this,(int)phVar10->player_name[iVar8]);
          if ((uVar5 == 0) && (phVar10->player_name[iVar8] != '.')) goto LAB_004452a7;
          iVar8 = iVar8 + 1;
          this = extraout_ECX;
        } while (iVar8 < (int)pvVar6);
      }
      uVar5 = 0xffffffff;
      local_4 = iVar9 + 1;
      phVar3 = phVar10;
      do {
        phVar14 = phVar3;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        phVar14 = (highscore_record_t *)(phVar3->player_name + 1);
        pcVar2 = phVar3->player_name;
        phVar3 = phVar14;
      } while (*pcVar2 != '\0');
      uVar5 = ~uVar5;
      puVar11 = (undefined4 *)((int)phVar14 - uVar5);
      puVar15 = local_8;
      for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar15 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar15 = puVar15 + 1;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar15 = *(undefined1 *)puVar11;
        puVar11 = (undefined4 *)((int)puVar11 + 1);
        puVar15 = (undefined4 *)((int)puVar15 + 1);
      }
      console_printf(&console_log_queue,s__d__unique___s_00478e14,local_4,phVar10);
      iVar9 = local_4;
      local_8 = local_8 + 8;
LAB_004452a7:
      phVar10 = phVar10 + 1;
    } while ((int)phVar10 < 0x484730);
    DAT_004d7580 = '\x01';
    DAT_004d7584 = iVar9;
    if (iVar9 == 0) {
      crt_sprintf(&DAT_004d1228,s_quickbrownfox_00478e04);
    }
  }
  if (DAT_004d7584 < 1) {
    return &DAT_004d1228;
  }
  iVar9 = crt_rand();
  return &DAT_004d1228 + (iVar9 % DAT_004d7584) * 0x20;
}



