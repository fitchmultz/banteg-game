/* FUN_00463333 @ 00463333 */

/* [binja] struct _EXCEPTION_REGISTRATION_RECORD* __stdcall sub_463333(int32_t arg1,
   EXCEPTION_RECORD* arg2) */

void * FUN_00463333(int arg1,void *arg2)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar1 = ExceptionList;
  RtlUnwind((PVOID)arg1,(PVOID)0x46335b,arg2,(PVOID)0x0);
  *(uint *)((int)arg2 + 4) = *(uint *)((int)arg2 + 4) & 0xfffffffd;
  pvVar2 = ExceptionList;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return pvVar2;
}



