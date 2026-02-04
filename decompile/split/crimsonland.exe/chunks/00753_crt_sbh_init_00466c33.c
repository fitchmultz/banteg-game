/* crt_sbh_init @ 00466c33 */

/* CRT small-block heap init */

undefined4 __cdecl crt_sbh_init(undefined4 param_1)

{
  DAT_004da39c = HeapAlloc(crt_heap_handle,0,0x140);
  if (DAT_004da39c == (LPVOID)0x0) {
    return 0;
  }
  DAT_004da394 = 0;
  DAT_004da398 = 0;
  DAT_004da390 = DAT_004da39c;
  DAT_004da3a0 = param_1;
  DAT_004da388 = 0x10;
  return 1;
}



