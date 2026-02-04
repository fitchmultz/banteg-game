/* crt_fclose @ 00460e5d */

/* fclose wrapper with CRT lock/unlock */

int __cdecl crt_fclose(FILE *fp)

{
  int iVar1;
  
  iVar1 = -1;
  if ((fp->_flag & 0x40) == 0) {
    crt_lock_file((uint)fp);
    iVar1 = __fclose_lk(fp);
    crt_unlock_file((uint)fp);
  }
  else {
    fp->_flag = 0;
  }
  return iVar1;
}



