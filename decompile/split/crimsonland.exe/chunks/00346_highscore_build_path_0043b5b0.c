/* highscore_build_path @ 0043b5b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* builds the high score filename for the current mode */

char * highscore_build_path(void)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined *puVar4;
  
  if (DAT_004c3960 == '\0') {
    crt_getcwd(&DAT_004c375c,0x1ff);
    DAT_004c395b = 0;
    DAT_004c3960 = '\x01';
  }
  if (config_blob.reserved0._24_4_ == 2) {
    puVar4 = &DAT_004c375c;
    pcVar3 = s__s_scores5_rush_hi_00477c60;
  }
  else if (config_blob.reserved0._24_4_ == 1) {
    puVar4 = &DAT_004c375c;
    pcVar3 = s__s_scores5_survival_hi_00477c48;
  }
  else {
    if (config_blob.reserved0._24_4_ == 3) {
      if (config_blob.hardcore == '\0') {
        crt_sprintf(&DAT_004c36dc,s__s_scores5_questhc_d__d_hi_00477c10,&DAT_004c375c,
                    _quest_stage_major,_quest_stage_minor);
      }
      else {
        crt_sprintf(&DAT_004c36dc,s__s_scores5_quest_d__d_hi_00477c2c,&DAT_004c375c,
                    _quest_stage_major,_quest_stage_minor);
      }
      goto LAB_0043b67f;
    }
    puVar4 = (undefined *)(config_blob.reserved0._128_4_ * 0x1b + 0x4803f0);
    pcVar3 = s_scores5_unknown_hi_00477bfc;
  }
  crt_sprintf(&DAT_004c36dc,pcVar3,puVar4);
LAB_0043b67f:
  if (config_blob.reserved0._20_4_ == 2) {
    uVar2 = 0xffffffff;
    pcVar3 = &DAT_004c36dc;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    (&DAT_004c36d8)[uVar2] = 0x5f;
    (&DAT_004c36d9)[uVar2] = 0x32;
    (&DAT_004c36da)[uVar2] = 0x2e;
    (&DAT_004c36db)[uVar2] = 0x68;
    (&DAT_004c36dc)[uVar2] = 0x69;
    (&DAT_004c36dd)[uVar2] = 0;
  }
  if (config_blob.reserved0._128_4_ != 0) {
    crt_sprintf(&DAT_004c365c,&DAT_00477bf4,&DAT_004c36dc,
                config_blob.reserved0._128_4_ * 0x1b + 0x4803f0);
    console_printf(&console_log_queue,s_Opening_named_cache___s__00477bd8,&DAT_004c365c);
    return &DAT_004c365c;
  }
  if (*(float *)((int)cv_verbose + 0xc) != 0.0) {
    console_printf(&console_log_queue,s_Opening___s__00477bc8,&DAT_004c36dc);
  }
  return &DAT_004c36dc;
}



