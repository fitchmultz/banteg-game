/* highscore_read_record @ 0043ab10 */

/* reads and validates a high score record from a file */

char * __cdecl highscore_read_record(char *param_1,int *param_2)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar3 = 0;
  local_4 = 0;
  crt_fread(param_1,0x48,1,param_2);
  if ((*(byte *)(param_2 + 3) & 0x10) != 0) {
    return (char *)0x0;
  }
  crt_fread((char *)&local_4,4,1,param_2);
  uVar1 = 0;
  do {
    param_1[uVar1] = param_1[uVar1] + (-6 - ((char)uVar1 * '\x05' + '\x01') * (char)uVar1);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x48);
  iVar4 = 0x48;
  pcVar2 = param_1;
  do {
    iVar3 = iVar3 + (int)(pcVar2 + (3 - (int)param_1)) * (int)*pcVar2 * 7;
    pcVar2 = pcVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (local_4 != iVar3) {
    param_1[0x1f] = '\0';
    console_printf(&console_log_queue,s_WARN__checksum_failure_on_score_b_00477b40,param_1);
    return (char *)0x0;
  }
  return param_1;
}



