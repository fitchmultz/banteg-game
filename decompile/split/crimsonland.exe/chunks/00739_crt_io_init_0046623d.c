/* crt_io_init @ 0046623d */

/* CRT file handle table init */

void crt_io_init(void)

{
  undefined4 *puVar1;
  void **ppvVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  HANDLE hFile;
  byte *pbVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  _STARTUPINFOA local_4c;
  byte *local_8;
  
  ppvVar2 = _malloc(0x480);
  if (ppvVar2 == (void **)0x0) {
    __amsg_exit(0x1b);
  }
  crt_nhandle = 0x20;
  crt_pioinfo_table = ppvVar2;
  for (; ppvVar2 < crt_pioinfo_table + 0x120; ppvVar2 = ppvVar2 + 9) {
    *(undefined1 *)(ppvVar2 + 1) = 0;
    *ppvVar2 = (void *)0xffffffff;
    ppvVar2[2] = (void *)0x0;
    *(undefined1 *)((int)ppvVar2 + 5) = 10;
  }
  GetStartupInfoA(&local_4c);
  if ((local_4c.cbReserved2 != 0) && ((int *)local_4c.lpReserved2 != (int *)0x0)) {
    iVar8 = *(int *)local_4c.lpReserved2;
    pbVar5 = (byte *)((int)local_4c.lpReserved2 + 4);
    local_8 = pbVar5 + iVar8;
    if (0x7ff < iVar8) {
      iVar8 = 0x800;
    }
    iVar9 = iVar8;
    if (crt_nhandle < iVar8) {
      puVar6 = &DAT_004da3c4;
      do {
        puVar3 = _malloc(0x480);
        iVar9 = crt_nhandle;
        if (puVar3 == (undefined4 *)0x0) break;
        crt_nhandle = crt_nhandle + 0x20;
        *puVar6 = puVar3;
        puVar1 = puVar3;
        for (; puVar3 < puVar1 + 0x120; puVar3 = puVar3 + 9) {
          *(undefined1 *)(puVar3 + 1) = 0;
          *puVar3 = 0xffffffff;
          puVar3[2] = 0;
          *(undefined1 *)((int)puVar3 + 5) = 10;
          puVar1 = (undefined4 *)*puVar6;
        }
        puVar6 = puVar6 + 1;
        iVar9 = iVar8;
      } while (crt_nhandle < iVar8);
    }
    uVar7 = 0;
    if (0 < iVar9) {
      do {
        if (((*(HANDLE *)local_8 != (HANDLE)0xffffffff) && ((*pbVar5 & 1) != 0)) &&
           (((*pbVar5 & 8) != 0 || (DVar4 = GetFileType(*(HANDLE *)local_8), DVar4 != 0)))) {
          ppvVar2 = (&crt_pioinfo_table)[(int)uVar7 >> 5];
          ppvVar2[(uVar7 & 0x1f) * 9] = *(void **)local_8;
          *(byte *)(ppvVar2 + (uVar7 & 0x1f) * 9 + 1) = *pbVar5;
        }
        local_8 = local_8 + 4;
        uVar7 = uVar7 + 1;
        pbVar5 = pbVar5 + 1;
      } while ((int)uVar7 < iVar9);
    }
  }
  iVar8 = 0;
  do {
    ppvVar2 = crt_pioinfo_table + iVar8 * 9;
    if (crt_pioinfo_table[iVar8 * 9] == (void *)0xffffffff) {
      *(undefined1 *)(ppvVar2 + 1) = 0x81;
      if (iVar8 == 0) {
        DVar4 = 0xfffffff6;
      }
      else {
        DVar4 = 0xfffffff5 - (iVar8 != 1);
      }
      hFile = GetStdHandle(DVar4);
      if ((hFile != (HANDLE)0xffffffff) && (DVar4 = GetFileType(hFile), DVar4 != 0)) {
        *ppvVar2 = hFile;
        if ((DVar4 & 0xff) != 2) {
          if ((DVar4 & 0xff) == 3) {
            *(byte *)(ppvVar2 + 1) = *(byte *)(ppvVar2 + 1) | 8;
          }
          goto LAB_004663e2;
        }
      }
      *(byte *)(ppvVar2 + 1) = *(byte *)(ppvVar2 + 1) | 0x40;
    }
    else {
      *(byte *)(ppvVar2 + 1) = *(byte *)(ppvVar2 + 1) | 0x80;
    }
LAB_004663e2:
    iVar8 = iVar8 + 1;
    if (2 < iVar8) {
      SetHandleCount(crt_nhandle);
      return;
    }
  } while( true );
}



