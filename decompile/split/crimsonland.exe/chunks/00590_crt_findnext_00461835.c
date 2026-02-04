/* crt_findnext @ 00461835 */

/* CRT _findnext wrapper over FindNextFileA (returns 0/-1) */

int __cdecl crt_findnext(HANDLE handle,uint *finddata)

{
  WINBOOL WVar1;
  DWORD DVar2;
  int *piVar3;
  uint uVar4;
  _WIN32_FIND_DATAA local_144;
  
  WVar1 = FindNextFileA(handle,&local_144);
  if (WVar1 != 0) {
    *finddata = -(uint)(local_144.dwFileAttributes != 0x80) & local_144.dwFileAttributes;
    uVar4 = ___timet_from_ft((FILETIME *)&local_144.ftCreationTime);
    finddata[1] = uVar4;
    uVar4 = ___timet_from_ft((FILETIME *)&local_144.ftLastAccessTime);
    finddata[2] = uVar4;
    uVar4 = ___timet_from_ft((FILETIME *)&local_144.ftLastWriteTime);
    finddata[3] = uVar4;
    finddata[4] = local_144.nFileSizeLow;
    crt_strcpy((char *)(finddata + 5),local_144.cFileName);
    return 0;
  }
  DVar2 = GetLastError();
  if (DVar2 < 2) {
LAB_0046186f:
    piVar3 = crt_errno_ptr();
    *piVar3 = 0x16;
  }
  else {
    if (3 < DVar2) {
      if (DVar2 == 8) {
        piVar3 = crt_errno_ptr();
        *piVar3 = 0xc;
        return -1;
      }
      if (DVar2 != 0x12) goto LAB_0046186f;
    }
    piVar3 = crt_errno_ptr();
    *piVar3 = 2;
  }
  return -1;
}



