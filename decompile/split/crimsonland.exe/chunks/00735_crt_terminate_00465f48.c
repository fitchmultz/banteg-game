/* crt_terminate @ 00465f48 */

/* invokes the per-thread terminate handler then aborts */

void crt_terminate(void)

{
  DWORD *pDVar1;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0046fb98;
  puStack_10 = &LAB_00465e70;
  pvStack_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_14;
  pDVar1 = crt_get_thread_data();
  if (pDVar1[0x18] != 0) {
    local_8 = 1;
    pDVar1 = crt_get_thread_data();
    (*(code *)pDVar1[0x18])();
  }
  local_8 = 0xffffffff;
  FUN_0046cb6f();
  return;
}



