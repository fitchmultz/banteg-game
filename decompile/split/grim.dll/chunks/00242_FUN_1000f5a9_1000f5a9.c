/* FUN_1000f5a9 @ 1000f5a9 */

/* [binja] float* __stdcall sub_1000f5a9(float* arg1, int32_t arg2, int32_t* arg3, int32_t* arg4,
   int32_t* arg5, int32_t* arg6) */

float * FUN_1000f5a9(float *arg1,int arg2,int *arg3,int *arg4,int *arg5,int *arg6)

{
  float fVar1;
  float fVar2;
  
  switch(((arg6 != (int *)0x0) << 1 | arg5 != (int *)0x0) << 1 | arg4 != (int *)0x0) {
  case '\0':
    break;
  case '\x01':
    break;
  case '\x02':
    break;
  case '\x03':
    goto code_r0x1000f67a;
  case '\x04':
    break;
  case '\x05':
    goto code_r0x1000f67a;
  case '\x06':
    goto code_r0x1000f67a;
  case '\a':
    thunk_FUN_1000d766();
code_r0x1000f67a:
    thunk_FUN_1000d766();
  }
  thunk_FUN_1000d173();
  if (arg3 != (int *)0x0) {
    fVar2 = (float)arg3[2];
    if (arg3[2] < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    fVar1 = (float)*arg3;
    if (*arg3 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    *arg1 = fVar1 + fVar2 * (*arg1 + 1.0) * 0.5;
    fVar2 = (float)arg3[3];
    if (arg3[3] < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    fVar1 = (float)arg3[1];
    if (arg3[1] < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    arg1[1] = fVar1 + fVar2 * (1.0 - arg1[1]) * 0.5;
    arg1[2] = ((float)arg3[5] - (float)arg3[4]) * arg1[2] + (float)arg3[4];
  }
  return arg1;
}



