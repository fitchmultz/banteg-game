/* crt_doexit @ 00462eff */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CRT exit worker (atexit/onexit + ExitProcess) */

void __cdecl crt_doexit(uint code,int full,int quick)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  uint uExitCode;
  
  crt_exit_lock();
  if (DAT_004d99c0 == 1) {
    uExitCode = code;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_004d99bc = 1;
  DAT_004d99b8 = (undefined1)quick;
  if (full == 0) {
    if ((crt_onexit_table_end != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(crt_onexit_table_begin - 4), crt_onexit_table_end <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (crt_onexit_table_end <= puVar1);
    }
    crt_call_fn_range((undefined4 *)&DAT_004710fc,(undefined4 *)&DAT_00471104);
  }
  crt_call_fn_range((undefined4 *)&DAT_00471108,(undefined4 *)&DAT_00471110);
  if (quick == 0) {
    DAT_004d99c0 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(code);
  }
  crt_exit_unlock();
  return;
}



