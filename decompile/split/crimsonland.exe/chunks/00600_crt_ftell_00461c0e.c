/* crt_ftell @ 00461c0e */

/* CRT: ftell with file lock */

int __cdecl crt_ftell(char *param_1)

{
  int iVar1;
  
  crt_lock_file((uint)param_1);
  iVar1 = crt_ftell_nolock(param_1);
  crt_unlock_file((uint)param_1);
  return iVar1;
}



