/* FUN_1000d07e @ 1000d07e */

/* [binja] float* __stdcall sub_1000d07e(float* arg1, float* arg2, float* arg3, float* arg4, float
   arg5, float arg6) */

float * FUN_1000d07e(float *arg1,float *arg2,float *arg3,float *arg4,float arg5,float arg6)

{
  *arg1 = (*arg4 - *arg2) * arg6 + (*arg3 - *arg2) * arg5 + *arg2;
  arg1[1] = (arg4[1] - arg2[1]) * arg6 + (arg3[1] - arg2[1]) * arg5 + arg2[1];
  arg1[2] = (arg4[2] - arg2[2]) * arg6 + (arg3[2] - arg2[2]) * arg5 + arg2[2];
  return arg1;
}



