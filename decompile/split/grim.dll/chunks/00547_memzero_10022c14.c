/* memzero @ 10022c14 */

/* zero-fill helper (memset to 0) */

void __cdecl memzero(void *dst,uint size)

{
  uint uVar1;
  
  for (uVar1 = size >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined4 *)dst = 0;
    dst = (undefined4 *)((int)dst + 4);
  }
  for (uVar1 = size & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)dst = 0;
    dst = (undefined4 *)((int)dst + 1);
  }
  return;
}



