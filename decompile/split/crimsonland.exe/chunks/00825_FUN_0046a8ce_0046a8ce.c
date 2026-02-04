/* FUN_0046a8ce @ 0046a8ce */

BOOL __cdecl
FUN_0046a8ce(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6,
            int param_7)

{
  undefined1 *puVar1;
  WINBOOL WVar2;
  int iVar3;
  WORD local_20 [2];
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_00470018;
  puStack_10 = &LAB_00465e70;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffc8;
  iVar3 = DAT_004d9b88;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffc8;
  if (DAT_004d9b88 == 0) {
    ExceptionList = &local_14;
    WVar2 = GetStringTypeW(1,L"",1,local_20);
    iVar3 = 1;
    puVar1 = local_1c;
    if (WVar2 == 0) {
      WVar2 = GetStringTypeA(0,1,&DAT_004ab1a8,1,local_20);
      if (WVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      iVar3 = 2;
      puVar1 = local_1c;
    }
  }
  local_1c = puVar1;
  DAT_004d9b88 = iVar3;
  if (DAT_004d9b88 != 2) {
    if (DAT_004d9b88 == 1) {
      if (param_5 == 0) {
        param_5 = DAT_004d9a5c;
      }
      iVar3 = MultiByteToWideChar(param_5,(-(uint)(param_7 != 0) & 8) + 1,param_2,param_3,
                                  (LPWSTR)0x0,0);
      if (iVar3 != 0) {
        local_8 = 0;
        crt_chkstk();
        local_1c = &stack0xffffffc8;
        _memset(&stack0xffffffc8,0,iVar3 * 2);
        local_8 = 0xffffffff;
        if ((&stack0x00000000 != (undefined1 *)0x38) &&
           (iVar3 = MultiByteToWideChar(param_5,1,param_2,param_3,(LPWSTR)&stack0xffffffc8,iVar3),
           iVar3 != 0)) {
          WVar2 = GetStringTypeW(param_1,(LPCWCH)&stack0xffffffc8,iVar3,param_4);
          ExceptionList = local_14;
          return WVar2;
        }
      }
    }
    ExceptionList = local_14;
    return 0;
  }
  if (param_6 == 0) {
    param_6 = DAT_004d9a4c;
  }
  WVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
  ExceptionList = local_14;
  return WVar2;
}



