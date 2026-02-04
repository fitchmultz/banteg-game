/* crt_lock_fh @ 0046acf8 */

/* lock CRT file handle entry */

void __cdecl crt_lock_fh(uint fd)

{
  void **ppvVar1;
  uint uVar2;
  
  uVar2 = fd & 0x1f;
  ppvVar1 = (&crt_pioinfo_table)[(int)fd >> 5];
  if (ppvVar1[uVar2 * 9 + 2] == (void *)0x0) {
    crt_lock(0x11);
    if (ppvVar1[uVar2 * 9 + 2] == (void *)0x0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(ppvVar1 + uVar2 * 9 + 3));
      ppvVar1[uVar2 * 9 + 2] = (void *)((int)ppvVar1[uVar2 * 9 + 2] + 1);
    }
    crt_unlock(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&crt_pioinfo_table)[(int)fd >> 5] + uVar2 * 9 + 3));
  return;
}



