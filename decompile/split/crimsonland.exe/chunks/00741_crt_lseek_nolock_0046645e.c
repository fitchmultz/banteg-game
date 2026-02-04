/* crt_lseek_nolock @ 0046645e */

/* lseek implementation via SetFilePointer */

long __cdecl crt_lseek_nolock(int fd,long offset,int origin)

{
  void *hFile;
  int *piVar1;
  DWORD DVar2;
  uint os_error;
  
  hFile = crt_get_osfhandle(fd);
  if (hFile == (void *)0xffffffff) {
    piVar1 = crt_errno_ptr();
    *piVar1 = 9;
  }
  else {
    DVar2 = SetFilePointer(hFile,offset,(PLONG)0x0,origin);
    if (DVar2 == 0xffffffff) {
      os_error = GetLastError();
    }
    else {
      os_error = 0;
    }
    if (os_error == 0) {
      *(byte *)((&crt_pioinfo_table)[fd >> 5] + (fd & 0x1fU) * 9 + 1) =
           *(byte *)((&crt_pioinfo_table)[fd >> 5] + (fd & 0x1fU) * 9 + 1) & 0xfd;
      return DVar2;
    }
    crt_dosmaperr(os_error);
  }
  return -1;
}



