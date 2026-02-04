/* FUN_00462a17 @ 00462a17 */

/* [binja] void* sub_462a17(uint32_t arg1) */

void * __cdecl FUN_00462a17(uint arg1)

{
  void *pvVar1;
  LPVOID pvVar2;
  uint dwBytes;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0046fa50;
  puStack_10 = &LAB_00465e70;
  local_14 = ExceptionList;
  if (crt_heap_mode == 3) {
    ExceptionList = &local_14;
    if (arg1 <= DAT_004da3a0) {
      ExceptionList = &local_14;
      crt_lock(9);
      local_8 = 0;
      pvVar1 = crt_sbh_alloc(arg1);
      local_8 = 0xffffffff;
      FUN_00462a7e();
      if (pvVar1 != (void *)0x0) {
        ExceptionList = local_14;
        return pvVar1;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    if (crt_heap_mode == 2) {
      if (arg1 == 0) {
        dwBytes = 0x10;
      }
      else {
        dwBytes = arg1 + 0xf & 0xfffffff0;
      }
      ExceptionList = &local_14;
      if (dwBytes <= DAT_0047db14) {
        ExceptionList = &local_14;
        crt_lock(9);
        local_8 = 1;
        pvVar1 = crt_sbh_alloc_units(dwBytes >> 4);
        local_8 = 0xffffffff;
        FUN_00462add();
        if (pvVar1 != (void *)0x0) {
          ExceptionList = local_14;
          return pvVar1;
        }
      }
      goto LAB_00462af6;
    }
  }
  if (arg1 == 0) {
    arg1 = 1;
  }
  dwBytes = arg1 + 0xf & 0xfffffff0;
LAB_00462af6:
  pvVar2 = HeapAlloc(crt_heap_handle,0,dwBytes);
  ExceptionList = local_14;
  return pvVar2;
}



