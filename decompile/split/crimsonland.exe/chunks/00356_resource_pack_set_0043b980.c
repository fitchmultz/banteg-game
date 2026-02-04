/* resource_pack_set @ 0043b980 */

/* validates and sets the active resource pack path */

int __cdecl resource_pack_set(char *path)

{
  char cVar1;
  FILE *fp;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  fp = (FILE *)crt_fopen(path,&file_mode_read_binary);
  if (fp == (FILE *)0x0) {
    DAT_004c3968._0_1_ = 0;
    resource_pack_enabled = 0;
    return 0;
  }
  uVar3 = 0xffffffff;
  do {
    pcVar5 = path;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = path + 1;
    cVar1 = *path;
    path = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar5 + -uVar3;
  pcVar6 = (char *)&DAT_004c3968;
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
  resource_pack_enabled = 1;
  iVar2 = crt_fclose(fp);
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}



