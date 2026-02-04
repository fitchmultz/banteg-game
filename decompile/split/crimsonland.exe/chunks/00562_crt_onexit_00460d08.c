/* crt_onexit @ 00460d08 */

/* registers an onexit/atexit callback */

void * __cdecl crt_onexit(void *func)

{
  size_t sVar1;
  void *pvVar2;
  
  crt_exit_lock();
  sVar1 = crt_msize(crt_onexit_table_end);
  if (sVar1 < (uint)((int)crt_onexit_table_begin + (4 - (int)crt_onexit_table_end))) {
    sVar1 = crt_msize(crt_onexit_table_end);
    pvVar2 = crt_realloc(crt_onexit_table_end,sVar1 + 0x10);
    if (pvVar2 == (void *)0x0) {
      func = (void *)0x0;
      goto LAB_00460d7d;
    }
    crt_onexit_table_begin =
         (undefined4 *)
         ((int)pvVar2 + ((int)crt_onexit_table_begin - (int)crt_onexit_table_end >> 2) * 4);
    crt_onexit_table_end = pvVar2;
  }
  *crt_onexit_table_begin = func;
  crt_onexit_table_begin = crt_onexit_table_begin + 1;
LAB_00460d7d:
  crt_exit_unlock();
  return func;
}



