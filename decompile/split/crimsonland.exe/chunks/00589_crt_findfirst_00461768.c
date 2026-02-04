/* crt_findfirst @ 00461768 */

/* CRT _findfirst wrapper over FindFirstFileA */

HANDLE __cdecl crt_findfirst(char *pattern,uint *finddata)

{
  HANDLE pvVar1;
  DWORD DVar2;
  int *piVar3;
  uint uVar4;
  _WIN32_FIND_DATAA local_144;
  
  pvVar1 = FindFirstFileA(pattern,&local_144);
  if (pvVar1 != (HANDLE)0xffffffff) {
    *finddata = -(uint)(local_144.dwFileAttributes != 0x80) & local_144.dwFileAttributes;
    uVar4 = ___timet_from_ft((FILETIME *)&local_144.ftCreationTime);
    finddata[1] = uVar4;
    uVar4 = ___timet_from_ft((FILETIME *)&local_144.ftLastAccessTime);
    finddata[2] = uVar4;
    uVar4 = ___timet_from_ft((FILETIME *)&local_144.ftLastWriteTime);
    finddata[3] = uVar4;
    finddata[4] = local_144.nFileSizeLow;
    crt_strcpy((char *)(finddata + 5),local_144.cFileName);
    return pvVar1;
  }
  DVar2 = GetLastError();
  if (DVar2 < 2) {
LAB_004617a6:
    piVar3 = crt_errno_ptr();
    *piVar3 = 0x16;
  }
  else {
    if (3 < DVar2) {
      if (DVar2 == 8) {
        piVar3 = crt_errno_ptr();
        *piVar3 = 0xc;
        return (HANDLE)0xffffffff;
      }
      if (DVar2 != 0x12) goto LAB_004617a6;
    }
    piVar3 = crt_errno_ptr();
    *piVar3 = 2;
  }
  return (HANDLE)0xffffffff;
}



