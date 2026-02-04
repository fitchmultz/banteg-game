/* crt_init_locks @ 00465842 */

/* initializes CRT critical sections */

void crt_init_locks(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_0047b738);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_0047b728);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_0047b718);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_0047b6f8);
  return;
}



