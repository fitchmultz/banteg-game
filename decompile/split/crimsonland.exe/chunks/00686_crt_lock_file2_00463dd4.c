/* crt_lock_file2 @ 00463dd4 */

/* CRT: lock FILE by index or per-stream critical section */

void __cdecl crt_lock_file2(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    crt_lock(param_1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



