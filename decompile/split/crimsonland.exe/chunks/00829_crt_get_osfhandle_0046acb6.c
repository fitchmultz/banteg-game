/* crt_get_osfhandle @ 0046acb6 */

/* CRT: map file descriptor to OS handle */

void * __cdecl crt_get_osfhandle(int fd)

{
  int *piVar1;
  uint *puVar2;
  
  if (((uint)fd < (uint)crt_nhandle) &&
     (((uint)(&crt_pioinfo_table)[fd >> 5][(fd & 0x1fU) * 9 + 1] & 1) != 0)) {
    return (&crt_pioinfo_table)[fd >> 5][(fd & 0x1fU) * 9];
  }
  piVar1 = crt_errno_ptr();
  *piVar1 = 9;
  puVar2 = crt_doserrno_ptr();
  *puVar2 = 0;
  return (void *)0xffffffff;
}



