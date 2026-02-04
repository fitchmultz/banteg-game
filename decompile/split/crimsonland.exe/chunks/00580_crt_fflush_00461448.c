/* crt_fflush @ 00461448 */

/* CRT: fflush wrapper (NULL flushes all) */

int __cdecl crt_fflush(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    iVar1 = crt_flushall(0);
    return iVar1;
  }
  crt_lock_file((uint)param_1);
  iVar1 = crt_fflush_nolock(param_1);
  crt_unlock_file((uint)param_1);
  return iVar1;
}



