/* crt_fwrite @ 004615ae */

/* fwrite wrapper with CRT lock/unlock */

uint __cdecl crt_fwrite(char *param_1,uint param_2,uint param_3,int *param_4)

{
  uint uVar1;
  
  crt_lock_file((uint)param_4);
  uVar1 = crt_fwrite_nolock(param_1,param_2,param_3,param_4);
  crt_unlock_file((uint)param_4);
  return uVar1;
}



