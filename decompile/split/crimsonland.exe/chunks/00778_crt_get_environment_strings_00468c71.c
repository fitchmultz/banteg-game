/* crt_get_environment_strings @ 00468c71 */

/* returns a malloc'd copy of the environment block */

char * crt_get_environment_strings(void)

{
  char cVar1;
  WCHAR WVar2;
  WCHAR *pWVar3;
  WCHAR *pWVar4;
  int iVar5;
  size_t _Size;
  LPSTR lpMultiByteStr;
  char *pcVar6;
  char *pcVar7;
  LPWCH lpWideCharStr;
  LPCH penv;
  LPSTR local_8;
  
  lpWideCharStr = (LPWCH)0x0;
  penv = (LPCH)0x0;
  if (DAT_004d9b80 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_004d9b80 = 1;
LAB_00468cc8:
      if ((lpWideCharStr == (LPWCH)0x0) &&
         (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr == (LPWCH)0x0)) {
        return (char *)0x0;
      }
      WVar2 = *lpWideCharStr;
      pWVar4 = lpWideCharStr;
      while (WVar2 != L'\0') {
        do {
          pWVar3 = pWVar4;
          pWVar4 = pWVar3 + 1;
        } while (*pWVar4 != L'\0');
        pWVar4 = pWVar3 + 2;
        WVar2 = *pWVar4;
      }
      iVar5 = ((int)pWVar4 - (int)lpWideCharStr >> 1) + 1;
      _Size = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,(LPSTR)0x0,0,(LPCCH)0x0,(LPBOOL)0x0);
      local_8 = (LPSTR)0x0;
      if (((_Size != 0) && (lpMultiByteStr = _malloc(_Size), lpMultiByteStr != (LPSTR)0x0)) &&
         (iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,lpMultiByteStr,_Size,(LPCCH)0x0,
                                      (LPBOOL)0x0), local_8 = lpMultiByteStr, iVar5 == 0)) {
        crt_free_base(lpMultiByteStr);
        local_8 = (LPSTR)0x0;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return local_8;
    }
    penv = GetEnvironmentStrings();
    if (penv == (LPCH)0x0) {
      return (char *)0x0;
    }
    DAT_004d9b80 = 2;
  }
  else {
    if (DAT_004d9b80 == 1) goto LAB_00468cc8;
    if (DAT_004d9b80 != 2) {
      return (char *)0x0;
    }
  }
  if ((penv == (LPCH)0x0) && (penv = GetEnvironmentStrings(), penv == (LPCH)0x0)) {
    return (char *)0x0;
  }
  cVar1 = *penv;
  pcVar6 = penv;
  while (cVar1 != '\0') {
    do {
      pcVar7 = pcVar6;
      pcVar6 = pcVar7 + 1;
    } while (*pcVar6 != '\0');
    pcVar6 = pcVar7 + 2;
    cVar1 = *pcVar6;
  }
  pcVar7 = _malloc((size_t)(pcVar6 + (1 - (int)penv)));
  if (pcVar7 == (char *)0x0) {
    pcVar7 = (char *)0x0;
  }
  else {
    crt_bufcpy(pcVar7,penv,(size_t)(pcVar6 + (1 - (int)penv)));
  }
  FreeEnvironmentStringsA(penv);
  return pcVar7;
}



