/* crt_heap_init @ 00466bd6 */

/* CRT heap init (small/large block selection) */

undefined4 __cdecl crt_heap_init(int param_1)

{
  undefined **ppuVar1;
  
  crt_heap_handle = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (crt_heap_handle != (HANDLE)0x0) {
    crt_heap_mode = crt_heap_select();
    if (crt_heap_mode == 3) {
      ppuVar1 = (undefined **)crt_sbh_init(0x3f8);
    }
    else {
      if (crt_heap_mode != 2) {
        return 1;
      }
      ppuVar1 = crt_sbh_create_region();
    }
    if (ppuVar1 != (undefined **)0x0) {
      return 1;
    }
    HeapDestroy(crt_heap_handle);
  }
  return 0;
}



