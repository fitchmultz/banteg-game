/* crt_putc_buffer_nolock @ 00464b84 */

/* emit buffer chars via crt_putc_nolock (printf string helper) */

void __cdecl crt_putc_buffer_nolock(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    crt_putc_nolock((int)cVar1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}



