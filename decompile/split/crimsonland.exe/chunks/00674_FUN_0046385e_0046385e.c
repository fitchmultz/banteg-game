/* FUN_0046385e @ 0046385e */

undefined1 * __cdecl FUN_0046385e(undefined8 *param_1,undefined1 *param_2,int param_3,int param_4)

{
  uint local_2c [6];
  int local_14 [4];
  
  crt_fp_to_string((double)*param_1,local_14,local_2c);
  crt_fp_round_digits(param_2 + (uint)(0 < param_3) + (uint)(local_14[0] == 0x2d),param_3 + 1,
                      local_14);
  crt_fp_format_exp(param_2,param_3,param_4,local_14,0);
  return param_2;
}



