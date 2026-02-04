/* crt_commit @ 004655bf */

/* CRT: commit file buffers to disk */

int __cdecl crt_commit(int fd)

{
  void *hFile;
  WINBOOL WVar1;
  DWORD DVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  
  if ((uint)crt_nhandle <= (uint)fd) {
LAB_00465640:
    piVar4 = crt_errno_ptr();
    *piVar4 = 9;
    return -1;
  }
  if (((uint)(&crt_pioinfo_table)[fd >> 5][(fd & 0x1fU) * 9 + 1] & 1) == 0) goto LAB_00465640;
  crt_lock_fh(fd);
  if (((uint)(&crt_pioinfo_table)[fd >> 5][(fd & 0x1fU) * 9 + 1] & 1) != 0) {
    hFile = crt_get_osfhandle(fd);
    WVar1 = FlushFileBuffers(hFile);
    if (WVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    iVar5 = 0;
    if (DVar2 == 0) goto LAB_00465635;
    puVar3 = crt_doserrno_ptr();
    *puVar3 = DVar2;
  }
  piVar4 = crt_errno_ptr();
  *piVar4 = 9;
  iVar5 = -1;
LAB_00465635:
  crt_unlock_fh(fd);
  return iVar5;
}



