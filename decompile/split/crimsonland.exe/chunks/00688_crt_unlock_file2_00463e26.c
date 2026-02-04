/* crt_unlock_file2 @ 00463e26 */

/* CRT: unlock FILE by index or per-stream critical section */

void __cdecl crt_unlock_file2(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    crt_unlock(param_1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



