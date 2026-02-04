/* FUN_1004b6c3 @ 1004b6c3 */

/* [binja] int32_t __stdcall sub_1004b6c3(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4) */

int FUN_1004b6c3(int arg1,int arg2,int arg3,int arg4)

{
  int iVar1;
  int local_20;
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_100516d8;
  puStack_10 = &DAT_1004b7cc;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  for (local_20 = 0; local_20 < arg3; local_20 = local_20 + 1) {
    (*(code *)arg4)();
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_1004b72d();
  ExceptionList = local_14;
  return iVar1;
}



