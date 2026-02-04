/* crt_invalid_parameter_noinfo_noreturn @ 00465fa9 */

/* invokes invalid-parameter handler (if set) then terminates */

void crt_invalid_parameter_noinfo_noreturn(void)

{
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0046fbb0;
  puStack_10 = &LAB_00465e70;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_crt_terminate_0047b928 != (undefined *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_crt_terminate_0047b928)();
  }
  local_8 = 0xffffffff;
  crt_terminate();
  return;
}



