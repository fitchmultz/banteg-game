/* grim_load_interface @ 0041dc80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* load grim DLL and fetch GRIM_GetInterface */

int __cdecl grim_load_interface(char *dll_name)

{
  char cVar1;
  FARPROC pFVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  _DAT_00490304 = LoadLibraryA(dll_name);
  if (_DAT_00490304 == (HMODULE)0x0) {
    return 0;
  }
  pFVar2 = GetProcAddress(_DAT_00490304,s_GRIM__GetInterface_004739bc);
  uVar4 = 0xffffffff;
  do {
    pcVar6 = dll_name;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = dll_name + 1;
    cVar1 = *dll_name;
    dll_name = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = pcVar6 + -uVar4;
  pcVar7 = (char *)&DAT_00490308;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  if (pFVar2 == (FARPROC)0x0) {
    return 0;
  }
  iVar3 = (*pFVar2)();
  return iVar3;
}



