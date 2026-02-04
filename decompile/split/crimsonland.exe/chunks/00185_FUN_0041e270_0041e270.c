/* FUN_0041e270 @ 0041e270 */

/* [binja] int32_t sub_41e270(float* arg1, float* arg2) */

int __cdecl FUN_0041e270(float *arg1,float *arg2)

{
  *arg1 = *arg1 + *arg2;
  arg1[1] = arg2[1] + arg1[1];
  return 0;
}



