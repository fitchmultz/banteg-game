/* crt_read @ 00465fff */

/* CRT: read handle with lock */

int __cdecl crt_read(int fd,char *buf,uint count)

{
  int iVar1;
  int *piVar2;
  uint *puVar3;
  
  if (((uint)fd < (uint)crt_nhandle) &&
     (((uint)(&crt_pioinfo_table)[fd >> 5][(fd & 0x1fU) * 9 + 1] & 1) != 0)) {
    crt_lock_fh(fd);
    iVar1 = crt_read_nolock(fd,buf,count);
    crt_unlock_fh(fd);
    return iVar1;
  }
  piVar2 = crt_errno_ptr();
  *piVar2 = 9;
  puVar3 = crt_doserrno_ptr();
  *puVar3 = 0;
  return -1;
}



