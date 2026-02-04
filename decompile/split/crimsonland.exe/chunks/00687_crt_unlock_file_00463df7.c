/* crt_unlock_file @ 00463df7 */

/* unlock a FILE stream (CRT lock or critical section) */

void __cdecl crt_unlock_file(uint param_1)

{
  if ((0x47b3d7 < param_1) && (param_1 < 0x47b639)) {
    crt_unlock(((int)(param_1 - 0x47b3d8) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



