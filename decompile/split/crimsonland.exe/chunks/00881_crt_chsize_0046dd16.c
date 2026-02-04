/* crt_chsize @ 0046dd16 */

/* resize file (truncate/extend via lseek + SetEndOfFile/zero fill) */

int __cdecl crt_chsize(int fd,int size)

{
  long offset;
  long lVar1;
  int iVar2;
  uint count;
  int iVar3;
  uint *puVar4;
  int *piVar5;
  void *hFile;
  WINBOOL WVar6;
  DWORD DVar7;
  int iVar8;
  uint uVar9;
  char local_1008 [4064];
  undefined4 uStackY_28;
  
  crt_chkstk();
  iVar8 = 0;
  offset = crt_lseek_nolock(fd,0,1);
  if ((offset == -1) || (lVar1 = crt_lseek_nolock(fd,0,2), lVar1 == -1)) {
    iVar8 = -1;
  }
  else {
    uVar9 = size - lVar1;
    if ((int)uVar9 < 1) {
      if ((int)uVar9 < 0) {
        crt_lseek_nolock(fd,size,0);
        hFile = crt_get_osfhandle(fd);
        WVar6 = SetEndOfFile(hFile);
        iVar8 = (WVar6 != 0) - 1;
        if (iVar8 == -1) {
          piVar5 = crt_errno_ptr();
          *piVar5 = 0xd;
          DVar7 = GetLastError();
          puVar4 = crt_doserrno_ptr();
          *puVar4 = DVar7;
        }
      }
    }
    else {
      _memset(local_1008,0,0x1000);
      uStackY_28 = 0x46dd83;
      iVar2 = FUN_0046e261(fd,0x8000);
      do {
        count = 0x1000;
        if ((int)uVar9 < 0x1000) {
          count = uVar9;
        }
        iVar3 = crt_write_nolock(fd,local_1008,count);
        if (iVar3 == -1) {
          puVar4 = crt_doserrno_ptr();
          if (*puVar4 == 5) {
            piVar5 = crt_errno_ptr();
            *piVar5 = 0xd;
          }
          iVar8 = -1;
          break;
        }
        uVar9 = uVar9 - iVar3;
      } while (0 < (int)uVar9);
      FUN_0046e261(fd,iVar2);
    }
    crt_lseek_nolock(fd,offset,0);
  }
  return iVar8;
}



