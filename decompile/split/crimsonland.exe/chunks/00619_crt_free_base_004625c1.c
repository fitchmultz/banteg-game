/* crt_free_base @ 004625c1 */

/* CRT heap free implementation */

void __cdecl crt_free_base(void *ptr)

{
  char *pcVar1;
  void *local_2c;
  char *local_28;
  uint local_24;
  char *local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0046fa20;
  puStack_10 = &LAB_00465e70;
  local_14 = ExceptionList;
  if (ptr == (void *)0x0) {
    return;
  }
  if (crt_heap_mode == 3) {
    ExceptionList = &local_14;
    crt_lock(9);
    local_8 = 0;
    local_20 = crt_sbh_find_region(ptr);
    if (local_20 != (char *)0x0) {
      FUN_00466ca6(local_20,ptr);
    }
    local_8 = 0xffffffff;
    FUN_0046262b();
    pcVar1 = local_20;
  }
  else {
    ExceptionList = &local_14;
    if (crt_heap_mode != 2) goto LAB_0046268d;
    ExceptionList = &local_14;
    crt_lock(9);
    local_8 = 1;
    local_28 = crt_sbh_find_block(ptr,&local_2c,&local_24);
    if (local_28 != (char *)0x0) {
      FUN_00467a2d(local_2c,local_24,local_28);
    }
    local_8 = 0xffffffff;
    FUN_00462683();
    pcVar1 = local_28;
  }
  if (pcVar1 != (char *)0x0) {
    ExceptionList = local_14;
    return;
  }
LAB_0046268d:
  HeapFree(crt_heap_handle,0,ptr);
  ExceptionList = local_14;
  return;
}



