/* FUN_1004b64f @ 1004b64f */

/* [binja] struct _EXCEPTION_REGISTRATION_RECORD* __stdcall sub_1004b64f(int32_t arg1, int32_t arg2,
   int32_t arg3, int32_t arg4) */

void * FUN_1004b64f(int arg1,int arg2,int arg3,int arg4)

{
  void *pvVar1;
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_100516c8;
  puStack_10 = &DAT_1004b7cc;
  local_14 = ExceptionList;
  local_8 = 0;
  pvVar1 = ExceptionList;
  ExceptionList = &local_14;
  while( true ) {
    arg3 = arg3 + -1;
    if (arg3 < 0) break;
    pvVar1 = (void *)(*(code *)arg4)();
  }
  ExceptionList = local_14;
  return pvVar1;
}



