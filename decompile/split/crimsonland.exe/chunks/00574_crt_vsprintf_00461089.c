/* crt_vsprintf @ 00461089 */

/* CRT: format string to buffer */

int __cdecl crt_vsprintf(char *dst,char *fmt,void *args)

{
  int iVar1;
  char *local_24;
  int local_20;
  char *local_1c;
  undefined4 local_18;
  
  local_1c = dst;
  local_24 = dst;
  local_18 = 0x42;
  local_20 = 0x7fffffff;
  iVar1 = crt_output((int *)&local_24,(byte *)fmt,args);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    crt_flsbuf(0,(int *)&local_24);
  }
  else {
    *local_24 = '\0';
  }
  return iVar1;
}



