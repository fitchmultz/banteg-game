/* crt_msize @ 00463b86 */

/* CRT: allocation size */

size_t __cdecl crt_msize(void *ptr)

{
  byte *pbVar1;
  SIZE_T SVar2;
  size_t sVar3;
  void *local_30;
  byte *local_2c;
  uint local_28;
  size_t local_24;
  byte *local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0046fac0;
  puStack_10 = &LAB_00465e70;
  local_14 = ExceptionList;
  if (crt_heap_mode == 3) {
    ExceptionList = &local_14;
    crt_lock(9);
    local_8 = 0;
    local_20 = crt_sbh_find_region(ptr);
    if (local_20 != (byte *)0x0) {
      local_24 = *(int *)((int)ptr + -4) - 9;
    }
    sVar3 = local_24;
    local_8 = 0xffffffff;
    FUN_00463bf0();
    pbVar1 = local_20;
  }
  else {
    ExceptionList = &local_14;
    if (crt_heap_mode != 2) goto LAB_00463c44;
    ExceptionList = &local_14;
    crt_lock(9);
    local_8 = 1;
    local_2c = crt_sbh_find_block(ptr,&local_30,&local_28);
    if (local_2c != (byte *)0x0) {
      local_24 = (uint)*local_2c << 4;
    }
    sVar3 = local_24;
    local_8 = 0xffffffff;
    FUN_00463c6b();
    pbVar1 = local_2c;
  }
  if (pbVar1 != (byte *)0x0) {
    ExceptionList = local_14;
    return sVar3;
  }
LAB_00463c44:
  SVar2 = HeapSize(crt_heap_handle,0,ptr);
  ExceptionList = local_14;
  return SVar2;
}



