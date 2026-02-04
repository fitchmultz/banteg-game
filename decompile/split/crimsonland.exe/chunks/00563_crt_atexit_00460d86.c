/* crt_atexit @ 00460d86 */

/* atexit wrapper (returns 0/-1) */

int __cdecl crt_atexit(void *func)

{
  void *pvVar1;
  
  pvVar1 = crt_onexit(func);
  return (pvVar1 != (void *)0x0) - 1;
}



