/* creature_name_assign_random @ 00445380 */

/* builds a randomized creature name string into DAT_004d152c for debug overlays */

void __cdecl creature_name_assign_random(int creature_id)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  char *dst;
  int local_4;
  
  local_4 = 0;
  do {
    if ((int)highscore_active_record.score_xp < 0x79) {
LAB_0044544d:
      if ((((int)highscore_active_record.score_xp < 0x51) ||
          (iVar3 = crt_rand(), 0x4f < iVar3 % 100)) &&
         (((int)highscore_active_record.score_xp < 0x3d || (iVar3 = crt_rand(), 0x27 < iVar3 % 100))
         )) {
        if ((((int)highscore_active_record.score_xp < 0x29) ||
            (iVar3 = crt_rand(), 0x4f < iVar3 % 100)) &&
           (((int)highscore_active_record.score_xp < 0x15 ||
            (iVar3 = crt_rand(), 0x27 < iVar3 % 100)))) {
          dst = &DAT_004d152c + creature_id * 0x40;
          pcVar4 = FUN_00444f70('\0');
          crt_sprintf(dst,&s_fmt_percent_s,pcVar4);
        }
        else {
          dst = &DAT_004d152c + creature_id * 0x40;
          pcVar4 = FUN_00444f70('\0');
          pcVar5 = FUN_00444f70('\x01');
          crt_sprintf(dst,&DAT_00477bf4,pcVar5,pcVar4);
        }
      }
      else {
        dst = &DAT_004d152c + creature_id * 0x40;
        pcVar4 = FUN_00444f70('\0');
        pcVar5 = FUN_00444f70('\0');
        pcVar6 = FUN_00444f70('\x01');
        crt_sprintf(dst,s__s_s_s_00478e24,pcVar6,pcVar5,pcVar4);
      }
    }
    else {
      iVar3 = crt_rand();
      if (iVar3 % 100 < 10) {
        dst = &DAT_004d152c + creature_id * 0x40;
        pcVar4 = FUN_004451b0();
        uVar8 = 0xffffffff;
        do {
          pcVar5 = pcVar4;
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          pcVar5 = pcVar4 + 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar5;
        } while (cVar1 != '\0');
        uVar8 = ~uVar8;
        pcVar4 = pcVar5 + -uVar8;
        pcVar5 = dst;
        for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
          pcVar4 = pcVar4 + 4;
          pcVar5 = pcVar5 + 4;
        }
        for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *pcVar5 = *pcVar4;
          pcVar4 = pcVar4 + 1;
          pcVar5 = pcVar5 + 1;
        }
      }
      else {
        if (((int)highscore_active_record.score_xp < 0x79) ||
           (iVar3 = crt_rand(), 0x4f < iVar3 % 100)) goto LAB_0044544d;
        dst = &DAT_004d152c + creature_id * 0x40;
        pcVar4 = FUN_00444f70('\0');
        pcVar5 = FUN_00444f70('\0');
        pcVar6 = FUN_00444f70('\0');
        pcVar7 = FUN_00444f70('\x01');
        crt_sprintf(dst,s__s_s_s_s_00478e2c,pcVar7,pcVar6,pcVar5,pcVar4);
      }
    }
    iVar3 = creature_is_name_unique(dst,creature_id);
    if ((char)iVar3 != '\0') {
      uVar8 = 0xffffffff;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar1 = *dst;
        dst = dst + 1;
      } while (cVar1 != '\0');
      if ((~uVar8 - 1 < 0x10) || (bVar2 = 99 < local_4, local_4 = local_4 + 1, bVar2)) {
        return;
      }
    }
  } while( true );
}



