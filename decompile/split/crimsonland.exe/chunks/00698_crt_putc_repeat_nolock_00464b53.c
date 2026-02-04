/* crt_putc_repeat_nolock @ 00464b53 */

/* emit repeated chars via crt_putc_nolock (printf padding helper) */

void __cdecl crt_putc_repeat_nolock(uint param_1,int param_2,int *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    crt_putc_nolock(param_1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}



