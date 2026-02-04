/* highscore_save_record @ 0043b450 */

/* saves a high score record (updates or appends) */

void __cdecl highscore_save_record(byte *record)

{
  byte bVar1;
  char *path;
  FILE *fp;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  path = highscore_build_path();
  if (record == (byte *)0x0) {
    console_printf(&console_log_queue,s_UNEXPECTED__sc_is_null__00477bac);
    return;
  }
  uVar2 = 0xffffffff;
  pbVar4 = record;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
  } while (bVar1 != 0);
  for (iVar3 = ~uVar2 - 2; (0 < iVar3 && (record[iVar3] == 0x20)); iVar3 = iVar3 + -1) {
    record[iVar3] = 0;
  }
  CreateDirectoryA(s_scores5_00477ba4,(LPSECURITY_ATTRIBUTES)0x0);
  if (DAT_004871c9 == '\0') {
    highscore_record_init();
  }
  if (((record[0x44] & 1) == 0) ||
     (iVar3 = highscore_update_record(path,record), (char)iVar3 == '\0')) {
    fp = (FILE *)crt_fopen(path,&DAT_00477ba0);
    if (fp == (FILE *)0x0) {
      console_printf(&console_log_queue,s_Unable_to_save_score__disk_full_o_00477b6c);
      return;
    }
    highscore_write_record((undefined4 *)record,(int *)fp);
    crt_fclose(fp);
  }
  return;
}



