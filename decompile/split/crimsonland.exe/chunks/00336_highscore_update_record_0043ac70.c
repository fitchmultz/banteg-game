/* highscore_update_record @ 0043ac70 */

/* updates a matching record in the high score file when allowed */

int __cdecl highscore_update_record(char *path,byte *record)

{
  char cVar1;
  byte bVar2;
  FILE *fp;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  char *pcVar8;
  byte *pbVar9;
  byte local_48 [56];
  uint local_10;
  byte local_4;
  undefined1 local_2;
  undefined1 local_1;
  
  pbVar7 = local_48;
  for (iVar4 = 0x12; iVar4 != 0; iVar4 = iVar4 + -1) {
    pbVar7[0] = 0;
    pbVar7[1] = 0;
    pbVar7[2] = 0;
    pbVar7[3] = 0;
    pbVar7 = pbVar7 + 4;
  }
  uVar5 = 0xffffffff;
  pcVar3 = &default_player_name;
  do {
    pcVar8 = pcVar3;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar8;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pbVar7 = (byte *)(pcVar8 + -uVar5);
  pbVar9 = local_48;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pbVar9 = *(undefined4 *)pbVar7;
    pbVar7 = pbVar7 + 4;
    pbVar9 = pbVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pbVar9 = *pbVar7;
    pbVar7 = pbVar7 + 1;
    pbVar9 = pbVar9 + 1;
  }
  local_4 = 0;
  local_2 = 0x7c;
  local_1 = 0xff;
  local_10 = crt_rand();
  local_10 = local_10 & 0xfee050f;
  fp = (FILE *)crt_fopen(path,&DAT_00477b68);
  uVar5 = 0;
  if (fp != (FILE *)0x0) {
    bVar2 = (byte)fp->_flag;
    while ((bVar2 & 0x10) == 0) {
      pcVar3 = highscore_read_record((char *)local_48,(int *)fp);
      if ((pcVar3 != (char *)0x0) &&
         (iVar4 = highscore_record_equals(record,local_48), (char)iVar4 != '\0')) {
        if ((local_4 & 2) != 0) {
          iVar4 = crt_fclose(fp);
          return CONCAT31((int3)((uint)iVar4 >> 8),1);
        }
        if (local_4 == 0) {
          record[0x44] = 2;
        }
        crt_fseek((int *)fp,-0x4c,1);
        highscore_write_record((undefined4 *)record,(int *)fp);
        crt_fflush((int *)fp);
        iVar4 = crt_fclose(fp);
        return CONCAT31((int3)((uint)iVar4 >> 8),1);
      }
      bVar2 = (byte)fp->_flag;
    }
    crt_fflush((int *)fp);
    uVar5 = crt_fclose(fp);
  }
  return uVar5 & 0xffffff00;
}



