/* crt_init_thread_data @ 004654a5 */

/* CRT: initialize per-thread data defaults */

void __cdecl crt_init_thread_data(void *ptd)

{
  *(undefined **)((int)ptd + 0x50) = &DAT_0047ba60;
  *(undefined4 *)((int)ptd + 0x14) = 1;
  return;
}



