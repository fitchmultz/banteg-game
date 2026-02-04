/* crt_srand @ 00461739 */

/* sets the per-thread RNG seed (srand) */

void __cdecl crt_srand(uint seed)

{
  DWORD *pDVar1;
  
  pDVar1 = crt_get_thread_data();
  pDVar1[5] = seed;
  return;
}



