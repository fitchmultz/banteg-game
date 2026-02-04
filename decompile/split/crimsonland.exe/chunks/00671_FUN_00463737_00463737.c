/* FUN_00463737 @ 00463737 */

/* [binja] int32_t sub_463737() */

int FUN_00463737(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  
  hModule = GetModuleHandleA("KERNEL32");
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,"IsProcessorFeaturePresent");
    if (pFVar1 != (FARPROC)0x0) {
      iVar2 = (*pFVar1)(0);
      return iVar2;
    }
  }
  iVar2 = FUN_004636f9();
  return iVar2;
}



