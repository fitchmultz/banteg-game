/* crt_getcwd @ 0046248e */

/* CRT: get current working directory */

char * __cdecl crt_getcwd(char *buf,uint size)

{
  char *pcVar1;
  
  crt_lock(0xc);
  pcVar1 = crt_getdcwd(0,buf,size);
  crt_unlock(0xc);
  return pcVar1;
}



