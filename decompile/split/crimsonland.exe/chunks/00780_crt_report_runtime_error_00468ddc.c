/* crt_report_runtime_error @ 00468ddc */

/* formats and displays CRT runtime errors */

void __cdecl crt_report_runtime_error(DWORD param_1)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  size_t sVar4;
  HANDLE hFile;
  int iVar5;
  CHAR *_Dest;
  char acStackY_1e3 [7];
  LPCVOID lpBuffer;
  LPOVERLAPPED lpOverlapped;
  CHAR local_1a8 [260];
  char local_a4 [160];
  
  iVar5 = 0;
  pDVar2 = &DAT_0047db28;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while (pDVar2 < &DAT_0047dbb8);
  if (param_1 == (&DAT_0047db28)[iVar5 * 2]) {
    if ((DAT_004d99cc == 1) || ((DAT_004d99cc == 0 && (DAT_0047b184 == 1)))) {
      pDVar2 = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x47db2c);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      hFile = GetStdHandle(0xfffffff4);
      WriteFile(hFile,lpBuffer,sVar4,pDVar2,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,local_1a8,0x104);
      if (DVar3 == 0) {
        crt_strcpy(local_1a8,"<program name unknown>");
      }
      _Dest = local_1a8;
      sVar4 = _strlen(local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen(local_1a8);
        _Dest = acStackY_1e3 + sVar4;
        _strncpy(_Dest,"...",3);
      }
      crt_strcpy(local_a4,"Runtime Error!\n\nProgram: ");
      crt_strcat(local_a4,_Dest);
      crt_strcat(local_a4,"\n\n");
      crt_strcat(local_a4,*(char **)(iVar5 * 8 + 0x47db2c));
      acStackY_1e3[3] = '\0';
      acStackY_1e3[4] = -0x71;
      acStackY_1e3[5] = 'F';
      acStackY_1e3[6] = '\0';
      FUN_0046d5e3((int)local_a4,0x46feb8,0x12010);
    }
  }
  return;
}



