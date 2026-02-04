/* crt_unlock_fh @ 0046ad57 */

/* unlock CRT file handle entry */

void __cdecl crt_unlock_fh(uint fd)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)((&crt_pioinfo_table)[(int)fd >> 5] + (fd & 0x1f) * 9 + 3));
  return;
}



