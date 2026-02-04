/* crt_close_nolock @ 00463ea6 */

/* CRT: close file handle without lock */

int __cdecl crt_close_nolock(int fd)

{
  void *pvVar1;
  void *pvVar2;
  WINBOOL WVar3;
  DWORD os_error;
  int iVar4;
  
  pvVar1 = crt_get_osfhandle(fd);
  if (pvVar1 != (void *)0xffffffff) {
    if ((fd == 1) || (fd == 2)) {
      pvVar1 = crt_get_osfhandle(2);
      pvVar2 = crt_get_osfhandle(1);
      if (pvVar2 == pvVar1) goto LAB_00463ef4;
    }
    pvVar1 = crt_get_osfhandle(fd);
    WVar3 = CloseHandle(pvVar1);
    if (WVar3 == 0) {
      os_error = GetLastError();
      goto LAB_00463ef6;
    }
  }
LAB_00463ef4:
  os_error = 0;
LAB_00463ef6:
  FUN_0046ac37(fd);
  *(undefined1 *)((&crt_pioinfo_table)[fd >> 5] + (fd & 0x1fU) * 9 + 1) = 0;
  if (os_error == 0) {
    iVar4 = 0;
  }
  else {
    crt_dosmaperr(os_error);
    iVar4 = -1;
  }
  return iVar4;
}



