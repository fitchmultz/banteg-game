/* crt_rand @ 00461746 */

/* returns a pseudo-random value using the per-thread seed (rand) */

int __cdecl crt_rand(void)

{
  DWORD *pDVar1;
  uint uVar2;
  
  pDVar1 = crt_get_thread_data();
  uVar2 = pDVar1[5] * 0x343fd + 0x269ec3;
  pDVar1[5] = uVar2;
  return uVar2 >> 0x10 & 0x7fff;
}



