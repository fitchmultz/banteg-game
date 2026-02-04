/* FUN_0046d5e3 @ 0046d5e3 */

/* [binja] int32_t sub_46d5e3(int32_t arg1, int32_t arg2, int32_t arg3) */

int __cdecl FUN_0046d5e3(int arg1,int arg2,int arg3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_004d9cb4 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_004d9cb4 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_004d9cb4 != (FARPROC)0x0) {
        DAT_004d9cb8 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_004d9cbc = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_0046d632;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_0046d632:
    if (DAT_004d9cb8 != (FARPROC)0x0) {
      iVar1 = (*DAT_004d9cb8)();
      if ((iVar1 != 0) && (DAT_004d9cbc != (FARPROC)0x0)) {
        iVar1 = (*DAT_004d9cbc)(iVar1);
      }
    }
    iVar1 = (*DAT_004d9cb4)(iVar1,arg1,arg2,arg3);
  }
  return iVar1;
}



