/* FUN_00463981 @ 00463981 */

char * __cdecl FUN_00463981(undefined8 *param_1,char *param_2,size_t param_3)

{
  uint local_2c [6];
  int local_14;
  int local_10;
  
  crt_fp_to_string((double)*param_1,&local_14,local_2c);
  crt_fp_round_digits(param_2 + (local_14 == 0x2d),local_10 + param_3,&local_14);
  crt_fp_format_fixed(param_2,param_3,&local_14,0);
  return param_2;
}



