/* FUN_1001bf5e @ 1001bf5e */

int FUN_1001bf5e(void)

{
  LONG LVar1;
  int iVar2;
  int extraout_ECX;
  int extraout_ECX_00;
  int local_14;
  DWORD local_10 [2];
  HKEY local_8;
  
  LVar1 = RegOpenKeyA((HKEY)0x80000002,"Software\\Microsoft\\Direct3D",&local_8);
  iVar2 = extraout_ECX;
  if (LVar1 == 0) {
    local_10[1] = 4;
    LVar1 = RegQueryValueExA(local_8,"DisableMMX",(LPDWORD)0x0,local_10,(LPBYTE)&local_14,
                             local_10 + 1);
    if (((LVar1 == 0) && (local_10[0] == 4)) && (local_14 != 0)) {
      RegCloseKey(local_8);
      DAT_10054498 = 0;
      return 0;
    }
    RegCloseKey(local_8);
    iVar2 = extraout_ECX_00;
  }
  if (DAT_10054498 < 0) {
    DAT_10054498 = 0;
    iVar2 = FUN_1001bf39(iVar2);
    if (iVar2 != 0) {
      DAT_10054498 = 1;
    }
  }
  return DAT_10054498;
}



