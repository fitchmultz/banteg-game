/* crt_lseek @ 004663f9 */

/* lseek wrapper (locks file handle, then SetFilePointer) */

long __cdecl crt_lseek(int fd,long offset,int origin)

{
  long lVar1;
  int *piVar2;
  uint *puVar3;
  
  if (((uint)fd < (uint)crt_nhandle) &&
     (((uint)(&crt_pioinfo_table)[fd >> 5][(fd & 0x1fU) * 9 + 1] & 1) != 0)) {
    crt_lock_fh(fd);
    lVar1 = crt_lseek_nolock(fd,offset,origin);
    crt_unlock_fh(fd);
    return lVar1;
  }
  piVar2 = crt_errno_ptr();
  *piVar2 = 9;
  puVar3 = crt_doserrno_ptr();
  *puVar3 = 0;
  return -1;
}



