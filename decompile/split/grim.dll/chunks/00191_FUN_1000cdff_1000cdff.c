/* FUN_1000cdff @ 1000cdff */

/* [binja] float* __stdcall sub_1000cdff(float* arg1, float* arg2, float* arg3, float* arg4, float
   arg5, float arg6) */

float * FUN_1000cdff(float *arg1,float *arg2,float *arg3,float *arg4,float arg5,float arg6)

{
  *arg1 = (*arg4 - *arg2) * arg6 + (*arg3 - *arg2) * arg5 + *arg2;
  arg1[1] = (arg4[1] - arg2[1]) * arg6 + (arg3[1] - arg2[1]) * arg5 + arg2[1];
  return arg1;
}



