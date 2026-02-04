/* crt_sopen @ 0046adbd */

/* CRT: open file with share mode, wraps CreateFile */

int __cdecl crt_sopen(char *filename,int oflag,int shflag,int pmode)

{
  void **ppvVar1;
  uint uVar2;
  uint fd;
  int *piVar3;
  uint *puVar4;
  HANDLE hFile;
  DWORD DVar5;
  int iVar6;
  long lVar7;
  bool bVar8;
  _SECURITY_ATTRIBUTES local_20;
  DWORD local_14;
  DWORD local_10;
  DWORD local_c;
  byte local_5;
  
  bVar8 = (oflag & 0x80U) == 0;
  local_20.nLength = 0xc;
  local_20.lpSecurityDescriptor = (LPVOID)0x0;
  if (bVar8) {
    local_5 = 0;
  }
  else {
    local_5 = 0x10;
  }
  local_20.bInheritHandle = (WINBOOL)bVar8;
  if (((oflag & 0x8000U) == 0) && (((oflag & 0x4000U) != 0 || (DAT_004d9cd8 != 0x8000)))) {
    local_5 = local_5 | 0x80;
  }
  uVar2 = oflag & 3;
  if (uVar2 == 0) {
    local_10 = 0x80000000;
  }
  else if (uVar2 == 1) {
    local_10 = 0x40000000;
  }
  else {
    if (uVar2 != 2) goto LAB_0046aec1;
    local_10 = 0xc0000000;
  }
  if (shflag == 0x10) {
    local_14 = 0;
  }
  else if (shflag == 0x20) {
    local_14 = 1;
  }
  else if (shflag == 0x30) {
    local_14 = 2;
  }
  else {
    if (shflag != 0x40) goto LAB_0046aec1;
    local_14 = 3;
  }
  uVar2 = oflag & 0x700;
  if (uVar2 < 0x401) {
    if ((uVar2 == 0x400) || (uVar2 == 0)) {
      local_c = 3;
    }
    else if (uVar2 == 0x100) {
      local_c = 4;
    }
    else {
      if (uVar2 == 0x200) goto LAB_0046aedb;
      if (uVar2 != 0x300) goto LAB_0046aec1;
      local_c = 2;
    }
  }
  else {
    if (uVar2 != 0x500) {
      if (uVar2 == 0x600) {
LAB_0046aedb:
        local_c = 5;
        goto LAB_0046aeeb;
      }
      if (uVar2 != 0x700) {
LAB_0046aec1:
        piVar3 = crt_errno_ptr();
        *piVar3 = 0x16;
        puVar4 = crt_doserrno_ptr();
        *puVar4 = 0;
        return -1;
      }
    }
    local_c = 1;
  }
LAB_0046aeeb:
  uVar2 = 0x80;
  if (((oflag & 0x100U) != 0) && ((~DAT_004d9980 & pmode & 0x80) == 0)) {
    uVar2 = 1;
  }
  if ((oflag & 0x40U) != 0) {
    uVar2 = uVar2 | 0x4000000;
    local_10 = CONCAT13(local_10._3_1_,0x10000);
  }
  if ((oflag & 0x1000U) != 0) {
    uVar2 = uVar2 | 0x100;
  }
  if ((oflag & 0x20U) == 0) {
    if ((oflag & 0x10U) != 0) {
      uVar2 = uVar2 | 0x10000000;
    }
  }
  else {
    uVar2 = uVar2 | 0x8000000;
  }
  fd = FUN_0046aa98();
  if (fd == 0xffffffff) {
    piVar3 = crt_errno_ptr();
    *piVar3 = 0x18;
    puVar4 = crt_doserrno_ptr();
    *puVar4 = 0;
    return -1;
  }
  hFile = CreateFileA(filename,local_10,local_14,&local_20,local_c,uVar2,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    DVar5 = GetFileType(hFile);
    if (DVar5 != 0) {
      if (DVar5 == 2) {
        local_5 = local_5 | 0x40;
      }
      else if (DVar5 == 3) {
        local_5 = local_5 | 8;
      }
      FUN_0046abbb(fd,hFile);
      filename._3_1_ = local_5 & 0x48;
      *(byte *)((&crt_pioinfo_table)[(int)fd >> 5] + (fd & 0x1f) * 9 + 1) = local_5 | 1;
      if ((((local_5 & 0x48) == 0) && ((local_5 & 0x80) != 0)) && ((oflag & 2U) != 0)) {
        local_14 = crt_lseek_nolock(fd,-1,2);
        if (local_14 == 0xffffffff) {
          puVar4 = crt_doserrno_ptr();
          if (*puVar4 == 0x83) goto LAB_0046b065;
        }
        else {
          shflag = shflag & 0xffffff;
          iVar6 = crt_read_nolock(fd,(char *)((int)&shflag + 3),1);
          if ((((iVar6 != 0) || (shflag._3_1_ != '\x1a')) ||
              (iVar6 = crt_chsize(fd,local_14), iVar6 != -1)) &&
             (lVar7 = crt_lseek_nolock(fd,0,0), lVar7 != -1)) goto LAB_0046b065;
        }
        crt_close(fd);
        uVar2 = 0xffffffff;
      }
      else {
LAB_0046b065:
        uVar2 = fd;
        if ((filename._3_1_ == 0) && ((oflag & 8U) != 0)) {
          ppvVar1 = (&crt_pioinfo_table)[(int)fd >> 5] + (fd & 0x1f) * 9 + 1;
          *(byte *)ppvVar1 = *(byte *)ppvVar1 | 0x20;
        }
      }
      goto LAB_0046b07e;
    }
    CloseHandle(hFile);
  }
  DVar5 = GetLastError();
  crt_dosmaperr(DVar5);
  uVar2 = 0xffffffff;
LAB_0046b07e:
  crt_unlock_fh(fd);
  return uVar2;
}



