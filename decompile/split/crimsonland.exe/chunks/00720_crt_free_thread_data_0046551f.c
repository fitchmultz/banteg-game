/* crt_free_thread_data @ 0046551f */

/* frees CRT per-thread data */

void __cdecl crt_free_thread_data(undefined *param_1)

{
  if (DAT_0047b6f0 != 0xffffffff) {
    if ((param_1 != (undefined *)0x0) ||
       (param_1 = TlsGetValue(DAT_0047b6f0), param_1 != (undefined *)0x0)) {
      if (*(void **)(param_1 + 0x24) != (void *)0x0) {
        crt_free_base(*(void **)(param_1 + 0x24));
      }
      if (*(void **)(param_1 + 0x28) != (void *)0x0) {
        crt_free_base(*(void **)(param_1 + 0x28));
      }
      if (*(void **)(param_1 + 0x30) != (void *)0x0) {
        crt_free_base(*(void **)(param_1 + 0x30));
      }
      if (*(void **)(param_1 + 0x38) != (void *)0x0) {
        crt_free_base(*(void **)(param_1 + 0x38));
      }
      if (*(void **)(param_1 + 0x40) != (void *)0x0) {
        crt_free_base(*(void **)(param_1 + 0x40));
      }
      if (*(void **)(param_1 + 0x44) != (void *)0x0) {
        crt_free_base(*(void **)(param_1 + 0x44));
      }
      if (*(undefined **)(param_1 + 0x50) != &DAT_0047ba60) {
        crt_free_base(*(undefined **)(param_1 + 0x50));
      }
      crt_free_base(param_1);
    }
    TlsSetValue(DAT_0047b6f0,(LPVOID)0x0);
    return;
  }
  return;
}



