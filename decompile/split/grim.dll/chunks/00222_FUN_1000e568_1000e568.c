/* FUN_1000e568 @ 1000e568 */

/* [binja] float* __stdcall sub_1000e568(float* arg1, float arg2, float* arg3, int32_t arg4, float*
   arg5) */

float * FUN_1000e568(float *arg1,float arg2,float *arg3,int arg4,float *arg5)

{
  arg1[0xe] = 0.0;
  arg1[0xd] = 0.0;
  arg1[0xc] = 0.0;
  arg1[0xb] = 0.0;
  arg1[9] = 0.0;
  arg1[8] = 0.0;
  arg1[7] = 0.0;
  arg1[6] = 0.0;
  arg1[4] = 0.0;
  arg1[3] = 0.0;
  arg1[2] = 0.0;
  arg1[1] = 0.0;
  *arg1 = arg2;
  arg1[5] = arg2;
  arg1[10] = arg2;
  arg1[0xf] = 1.0;
  if (arg4 != 0) {
    thunk_FUN_1000e40d();
    if (arg3 == (float *)0x0) {
      thunk_FUN_1000d766();
    }
    else {
      arg1[0xc] = arg1[0xc] - *arg3;
      arg1[0xd] = arg1[0xd] - arg3[1];
      arg1[0xe] = arg1[0xe] - arg3[2];
      thunk_FUN_1000d766();
      arg1[0xc] = *arg3 + arg1[0xc];
      arg1[0xd] = arg1[0xd] + arg3[1];
      arg1[0xe] = arg3[2] + arg1[0xe];
    }
  }
  if (arg5 != (float *)0x0) {
    arg1[0xc] = *arg5 + arg1[0xc];
    arg1[0xd] = arg5[1] + arg1[0xd];
    arg1[0xe] = arg5[2] + arg1[0xe];
  }
  return arg1;
}



