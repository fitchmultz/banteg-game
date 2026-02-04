/* entry @ 00463026 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  DWORD DVar1;
  int iVar2;
  uint code;
  _STARTUPINFOA local_60;
  undefined1 *local_1c;
  _EXCEPTION_POINTERS *local_18;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0046fa68;
  puStack_10 = &LAB_00465e70;
  pvStack_14 = ExceptionList;
  local_1c = &stack0xffffff88;
  ExceptionList = &pvStack_14;
  DVar1 = GetVersion();
  _DAT_004d9990 = DVar1 >> 8 & 0xff;
  _DAT_004d998c = DVar1 & 0xff;
  _DAT_004d9988 = _DAT_004d998c * 0x100 + _DAT_004d9990;
  _DAT_004d9984 = DVar1 >> 0x10;
  iVar2 = crt_heap_init(1);
  if (iVar2 == 0) {
    FUN_00463153(0x1c);
  }
  iVar2 = crt_mt_init();
  if (iVar2 == 0) {
    FUN_00463153(0x10);
  }
  local_8 = 0;
  crt_io_init();
  DAT_004db4e4 = GetCommandLineA();
  DAT_004d99c4 = crt_get_environment_strings();
  crt_build_argv();
  crt_build_environ();
  crt_run_initializers();
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  crt_skip_program_name();
  GetModuleHandleA((LPCSTR)0x0);
  code = crimsonland_main();
  crt_exit(code);
  crt_exception_filter(local_18->ExceptionRecord->ExceptionCode,local_18);
  return;
}



