/* FUN_00455a27 @ 00455a27 */

/* [binja] float* __stdcall sub_455a27(float* arg1, float* arg2, int32_t* arg3, int32_t* arg4,
   int32_t* arg5, int32_t* arg6) */

float * FUN_00455a27(float *arg1,float *arg2,int *arg3,int *arg4,int *arg5,int *arg6)

{
  float fVar1;
  float fVar2;
  
  switch(((arg6 != (int *)0x0) << 1 | arg5 != (int *)0x0) << 1 | arg4 != (int *)0x0) {
  case '\0':
    goto switchD_00455a64_default;
  case '\x01':
    goto LAB_00455b02;
  case '\x02':
    goto LAB_00455b02;
  case '\x03':
    break;
  case '\x04':
    goto LAB_00455b02;
  case '\x05':
    break;
  case '\x06':
    break;
  case '\a':
    thunk_FUN_00453a57();
    break;
  default:
    goto switchD_00455a64_default;
  }
  thunk_FUN_00453a57();
LAB_00455b02:
  thunk_FUN_00453f63();
switchD_00455a64_default:
  if (arg3 != (int *)0x0) {
    fVar1 = (float)*arg3;
    if (*arg3 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    fVar2 = (float)arg3[2];
    if (arg3[2] < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    fVar2 = (*arg2 - fVar1) / fVar2;
    *arg1 = (fVar2 + fVar2) - 1.0;
    fVar1 = (float)arg3[1];
    if (arg3[1] < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    fVar2 = (float)arg3[3];
    if (arg3[3] < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    fVar2 = (arg2[1] - fVar1) / fVar2;
    arg1[1] = -((fVar2 + fVar2) - 1.0);
    arg1[2] = (arg2[2] - (float)arg3[4]) / ((float)arg3[5] - (float)arg3[4]);
  }
  thunk_FUN_00453464();
  return arg1;
}



