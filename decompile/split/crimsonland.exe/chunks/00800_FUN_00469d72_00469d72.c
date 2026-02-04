/* FUN_00469d72 @ 00469d72 */

/* [binja] void* sub_469d72(void* arg1) */

void * __cdecl FUN_00469d72(void *arg1)

{
  void *arg2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00470008;
  puStack_10 = &LAB_00465e70;
  local_14 = ExceptionList;
  if ((arg1 != (void *)0x0) &&
     (arg2 = *(void **)(*(int *)((int)arg1 + 0x1c) + 4), arg2 != (void *)0x0)) {
    local_8 = 0;
    ExceptionList = &local_14;
    arg1 = (void *)FUN_00463325(*(int *)((int)arg1 + 0x18),arg2);
  }
  ExceptionList = local_14;
  return arg1;
}



