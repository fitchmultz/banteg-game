/* FUN_1004b5cf @ 1004b5cf */

/* [binja] int32_t __stdcall sub_1004b5cf(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4) */

int FUN_1004b5cf(int arg1,int arg2,int arg3,int arg4)

{
  int iVar1;
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_100516b8;
  puStack_10 = &DAT_1004b7cc;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  while( true ) {
    arg3 = arg3 + -1;
    if (arg3 < 0) break;
    (*(code *)arg4)();
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_1004b637();
  ExceptionList = local_14;
  return iVar1;
}



