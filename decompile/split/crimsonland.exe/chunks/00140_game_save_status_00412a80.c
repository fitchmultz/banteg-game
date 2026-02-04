/* game_save_status @ 00412a80 */

/* writes registry state and saves status file */

void game_save_status(void)

{
  char cVar1;
  LONG LVar2;
  char *pcVar3;
  FILE *fp;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  HKEY local_8;
  int local_4;
  
  LVar2 = RegCreateKeyExA((HKEY)0x80000002,(LPCSTR)&DAT_004852d0,0,(LPSTR)0x0,0,0xf003f,
                          (LPSECURITY_ATTRIBUTES)0x0,(PHKEY)&local_8,(LPDWORD)0x0);
  uVar7 = game_status_blob.game_sequence_id;
  if (LVar2 == 0) {
    reg_write_dword(local_8,s_sequence_0047361c,game_status_blob.game_sequence_id);
    reg_write_dword(local_8,s_dataPathId_0047367c,uVar7 * 0xd + 3 >> 1);
    reg_write_dword(local_8,s_transferFailed_0047366c,0);
    RegCloseKey((HKEY)local_8);
  }
  pcVar8 = &file_mode_write_binary;
  pcVar3 = game_build_path(game_status_filename);
  fp = (FILE *)crt_fopen(pcVar3,pcVar8);
  if (fp != (FILE *)0x0) {
    game_status_blob.quest_unlock_index = (ushort)quest_unlock_index;
    local_4 = 0;
    iVar5 = 0;
    game_status_blob.quest_unlock_index_full = (ushort)quest_unlock_index_full;
    uVar7 = 0;
    do {
      cVar1 = *(char *)((int)game_status_blob.weapon_usage_counts + iVar5 + -4);
      iVar6 = (cVar1 * 7 + iVar5) * (int)cVar1 + uVar7;
      cVar4 = (char)iVar5;
      uVar7 = uVar7 + 0x6f;
      local_4 = local_4 + 0xd + iVar6;
      *(char *)((int)game_status_blob.weapon_usage_counts + iVar5 + -4) =
           ((cVar4 * '\a' + '\x0f') * cVar4 + '\x03') * cVar4 + cVar1 + 'o';
      iVar5 = iVar5 + 1;
    } while (uVar7 < 0x10b18);
    crt_fwrite((char *)&game_status_blob,0x268,1,(int *)fp);
    crt_fwrite((char *)&local_4,4,1,(int *)fp);
    crt_fclose(fp);
    if (*(float *)((int)cv_verbose + 0xc) != 0.0) {
      console_printf(&console_log_queue,s_GAME_SaveStatus_OK__00473644);
    }
    game_load_status();
    game_sequence_load();
    game_sequence_load();
    return;
  }
  console_printf(&console_log_queue,s_GAME_SaveStatus_FAILED__00473628);
  game_sequence_load();
  return;
}



