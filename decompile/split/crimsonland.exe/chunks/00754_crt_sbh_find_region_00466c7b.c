/* crt_sbh_find_region @ 00466c7b */

/* CRT: find small-block heap region for a pointer */

void * __cdecl crt_sbh_find_region(void *ptr)

{
  void *pvVar1;
  
  pvVar1 = DAT_004da39c;
  while( true ) {
    if ((void *)((int)DAT_004da39c + DAT_004da398 * 0x14) <= pvVar1) {
      return (void *)0x0;
    }
    if ((uint)((int)ptr - *(int *)((int)pvVar1 + 0xc)) < 0x100000) break;
    pvVar1 = (void *)((int)pvVar1 + 0x14);
  }
  return pvVar1;
}



