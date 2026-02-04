/* FUN_1000f9ce @ 1000f9ce */

/* [binja] float* __stdcall sub_1000f9ce(float* arg1, float* arg2, void* arg3, int32_t* arg4, float*
   arg5, int32_t arg6, float* arg7) */

float * FUN_1000f9ce(float *arg1,float *arg2,void *arg3,int *arg4,float *arg5,int arg6,float *arg7)

{
  float fVar1;
  
  if (arg4 == (int *)0x0) {
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
    arg1[0xf] = 1.0;
    arg1[10] = 1.0;
    arg1[5] = 1.0;
    *arg1 = 1.0;
  }
  else if (arg3 == (void *)0x0) {
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
    *arg1 = (float)*arg4;
    arg1[5] = (float)arg4[1];
    fVar1 = (float)arg4[2];
    arg1[0xf] = 1.0;
    arg1[10] = fVar1;
  }
  else {
    thunk_FUN_1000e40d();
    if (arg2 == (float *)0x0) {
      thunk_FUN_1000d9af();
      thunk_FUN_1000d766();
      thunk_FUN_1000d766();
    }
    else {
      thunk_FUN_1000d9af();
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
      arg1[0xf] = 1.0;
      arg1[10] = 1.0;
      arg1[5] = 1.0;
      *arg1 = 1.0;
      arg1[0xc] = -*arg2;
      arg1[0xd] = -arg2[1];
      arg1[0xe] = -arg2[2];
      thunk_FUN_1000d766();
      thunk_FUN_1000d766();
      thunk_FUN_1000d766();
      arg1[0xc] = arg1[0xc] + *arg2;
      arg1[0xd] = arg2[1] + arg1[0xd];
      arg1[0xe] = arg1[0xe] + arg2[2];
    }
  }
  if (arg6 != 0) {
    thunk_FUN_1000e40d();
    if (arg5 == (float *)0x0) {
      thunk_FUN_1000d766();
    }
    else {
      arg1[0xc] = arg1[0xc] - *arg5;
      arg1[0xd] = arg1[0xd] - arg5[1];
      arg1[0xe] = arg1[0xe] - arg5[2];
      thunk_FUN_1000d766();
      arg1[0xc] = arg1[0xc] + *arg5;
      arg1[0xd] = arg1[0xd] + arg5[1];
      arg1[0xe] = arg1[0xe] + arg5[2];
    }
  }
  if (arg7 != (float *)0x0) {
    arg1[0xc] = arg1[0xc] + *arg7;
    arg1[0xd] = arg7[1] + arg1[0xd];
    arg1[0xe] = arg7[2] + arg1[0xe];
  }
  return arg1;
}



