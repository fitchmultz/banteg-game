/* game_load_status @ 00412c10 */

/* loads status file; regenerates on failure */

void game_load_status(void)

{
  char cVar1;
  char *pcVar2;
  FILE *fp;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  int local_4;
  
  pcVar7 = &file_mode_read_binary;
  pcVar2 = game_build_path(game_status_filename);
  fp = (FILE *)crt_fopen(pcVar2,pcVar7);
  uVar6 = 0;
  if (fp == (FILE *)0x0) {
    console_printf(&console_log_queue,s_GAME_LoadStatus_FAILED__004736a0);
    console_printf(&console_log_queue,s_Generating_new_file___00473688);
    game_status_blob.quest_unlock_index = 0;
    game_status_blob.quest_unlock_index_full = 0;
    game_sequence_load();
    game_save_status();
    game_sequence_load();
  }
  else {
    crt_fseek((int *)fp,0,2);
    iVar3 = crt_ftell((char *)fp);
    if (iVar3 != 0x26c) {
      crt_fclose(fp);
      console_printf(&console_log_queue,s_GAME_LoadStatus_FAILED__invalid_f_00473700);
      game_sequence_load();
      return;
    }
    crt_fseek((int *)fp,0,0);
    crt_fread((char *)&game_status_blob,0x268,1,(int *)fp);
    local_4 = 0;
    crt_fread((char *)&local_4,4,1,(int *)fp);
    iVar3 = 0;
    iVar4 = 0;
    do {
      cVar1 = (char)iVar4;
      cVar1 = *(char *)((int)game_status_blob.weapon_usage_counts + iVar4 + -4) +
              (-0x6f - ((cVar1 * '\a' + '\x0f') * cVar1 + '\x03') * cVar1);
      *(char *)((int)game_status_blob.weapon_usage_counts + iVar4 + -4) = cVar1;
      iVar5 = (cVar1 * 7 + iVar4) * (int)cVar1 + uVar6;
      uVar6 = uVar6 + 0x6f;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0xd + iVar5;
    } while (uVar6 < 0x10b18);
    if (iVar3 != local_4) {
      crt_fclose(fp);
      console_printf(&console_log_queue,s_GAME_LoadStatus_FAILED__check_su_004736d4);
      game_sequence_load();
      return;
    }
    quest_unlock_index_full = (uint)game_status_blob._0_4_ >> 0x10;
    quest_unlock_index = game_status_blob._0_4_ & 0xffff;
    crt_fclose(fp);
    if (*(float *)((int)cv_verbose + 0xc) != 0.0) {
      console_printf(&console_log_queue,s_GAME_LoadStatus_OK__004736bc);
      return;
    }
  }
  return;
}



