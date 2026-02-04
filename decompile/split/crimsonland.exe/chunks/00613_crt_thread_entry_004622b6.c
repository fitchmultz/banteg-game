/* crt_thread_entry @ 004622b6 */

/* CRT: thread start trampoline */

uint crt_thread_entry(void *thread_data)

{
  LPVOID pvVar1;
  WINBOOL WVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0046fa10;
  puStack_10 = &LAB_00465e70;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  pvVar1 = TlsGetValue(DAT_0047b6f0);
  if (pvVar1 != (LPVOID)0x0) {
    *(undefined4 *)((int)pvVar1 + 0x48) = *(undefined4 *)((int)thread_data + 0x48);
    *(undefined4 *)((int)pvVar1 + 0x4c) = *(undefined4 *)((int)thread_data + 0x4c);
    crt_free_thread_data(thread_data);
    thread_data = pvVar1;
  }
  WVar2 = TlsSetValue(DAT_0047b6f0,thread_data);
  if (WVar2 == 0) {
    __amsg_exit(0x10);
  }
  if (PTR_FUN_0047b164 != (undefined *)0x0) {
    (*(code *)PTR_FUN_0047b164)();
  }
  local_8 = 0;
  (**(code **)((int)thread_data + 0x48))(*(undefined4 *)((int)thread_data + 0x4c));
  crt_endthread();
  ExceptionList = local_14;
  return 0;
}



