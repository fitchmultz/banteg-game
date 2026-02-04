/* FUN_00469a69 @ 00469a69 */

undefined4 __cdecl
FUN_00469a69(DWORD param_1,undefined4 param_2,DWORD param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7)

{
  DWORD *pDVar1;
  undefined4 uVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0046ffe0;
  puStack_10 = &LAB_00465e70;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  crt_get_thread_data();
  crt_get_thread_data();
  pDVar1 = crt_get_thread_data();
  pDVar1[0x1b] = param_1;
  pDVar1 = crt_get_thread_data();
  pDVar1[0x1c] = param_3;
  local_8 = 1;
  uVar2 = FUN_004633b8(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_00469b36();
  ExceptionList = local_14;
  return uVar2;
}



