/* highscore_write_record @ 0043ad70 */

/* writes a high score record with date + checksum */

void __cdecl highscore_write_record(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  int local_4c;
  char local_48 [56];
  uint local_10;
  undefined1 local_4;
  undefined1 local_2;
  undefined1 local_1;
  
  local_4c = 0;
  GetLocalTime((LPSYSTEMTIME)&local_system_time);
  pcVar5 = local_48;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = pcVar5 + 4;
  }
  uVar3 = 0xffffffff;
  pcVar5 = &default_player_name;
  do {
    pcVar6 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar6 + -uVar3;
  pcVar6 = local_48;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  local_4 = 0;
  local_2 = 0x7c;
  local_1 = 0xff;
  uVar3 = crt_rand();
  local_10 = uVar3 & 0xfee050f;
  if (*(char *)(param_1 + 0x10) == '\0') {
    *(undefined1 *)(param_1 + 0x10) = (undefined1)local_system_day;
    *(undefined1 *)((int)param_1 + 0x42) = local_system_time._2_1_;
    *(char *)((int)param_1 + 0x43) = (char)local_system_time + '0';
    iVar2 = highscore_date_checksum
                      (local_system_time & 0xffff,local_system_time >> 0x10,(uint)local_system_day);
    *(char *)((int)param_1 + 0x41) = (char)iVar2;
  }
  pcVar5 = local_48;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pcVar5 = *param_1;
    param_1 = param_1 + 1;
    pcVar5 = pcVar5 + 4;
  }
  uVar3 = 0;
  do {
    local_4c = local_4c + (int)(local_48 + uVar3 + (3 - (int)local_48)) * (int)local_48[uVar3] * 7;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x48);
  uVar3 = 0;
  do {
    local_48[uVar3] = local_48[uVar3] + ((char)uVar3 * '\x05' + '\x01') * (char)uVar3 + '\x06';
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x48);
  crt_fwrite(local_48,0x48,1,param_2);
  crt_fwrite((char *)&local_4c,4,1,param_2);
  return;
}



