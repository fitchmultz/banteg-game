/* FUN_00463a7d @ 00463a7d */

void __cdecl FUN_00463a7d(undefined8 *param_1,char *param_2,size_t param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  uint local_2c [6];
  int local_14;
  int local_10;
  
  crt_fp_to_string((double)*param_1,&local_14,local_2c);
  iVar1 = local_10 + -1;
  crt_fp_round_digits(param_2 + (local_14 == 0x2d),param_3,&local_14);
  local_10 = local_10 + -1;
  if ((local_10 < -4) || ((int)param_3 <= local_10)) {
    crt_fp_format_exp(param_2,param_3,param_4,&local_14,1);
  }
  else {
    pcVar2 = param_2 + (local_14 == 0x2d);
    if (iVar1 < local_10) {
      do {
        pcVar3 = pcVar2;
        pcVar2 = pcVar3 + 1;
      } while (*pcVar3 != '\0');
      pcVar3[-1] = '\0';
    }
    crt_fp_format_fixed(param_2,param_3,&local_14,1);
  }
  return;
}



