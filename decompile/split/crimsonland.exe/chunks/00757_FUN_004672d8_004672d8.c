/* FUN_004672d8 @ 004672d8 */

/* [binja] int32_t* sub_4672d8() */

int * FUN_004672d8(void)

{
  int *piVar1;
  LPVOID pvVar2;
  
  if (DAT_004da398 == DAT_004da388) {
    pvVar2 = HeapReAlloc(crt_heap_handle,0,DAT_004da39c,(DAT_004da388 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (int *)0x0;
    }
    DAT_004da388 = DAT_004da388 + 0x10;
    DAT_004da39c = pvVar2;
  }
  piVar1 = (int *)((int)DAT_004da39c + DAT_004da398 * 0x14);
  pvVar2 = HeapAlloc(crt_heap_handle,8,0x41c4);
  piVar1[4] = (int)pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    piVar1[3] = (int)pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      piVar1[2] = -1;
      *piVar1 = 0;
      piVar1[1] = 0;
      DAT_004da398 = DAT_004da398 + 1;
      *(undefined4 *)piVar1[4] = 0xffffffff;
      return piVar1;
    }
    HeapFree(crt_heap_handle,0,(LPVOID)piVar1[4]);
  }
  return (int *)0x0;
}



