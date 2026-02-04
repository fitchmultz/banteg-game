/* crt_fseek @ 00461d91 */

/* fseek wrapper with CRT lock/unlock */

int __cdecl crt_fseek(int *param_1,int param_2,DWORD param_3)

{
  int iVar1;
  
  crt_lock_file((uint)param_1);
  iVar1 = crt_fseek_nolock(param_1,param_2,param_3);
  crt_unlock_file((uint)param_1);
  return iVar1;
}



