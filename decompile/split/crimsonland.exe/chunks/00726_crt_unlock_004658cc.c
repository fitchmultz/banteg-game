/* crt_unlock @ 004658cc */

/* CRT lock table leave */

void __cdecl crt_unlock(int param_1)

{
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(&DAT_0047b6f4 + param_1 * 4));
  return;
}



