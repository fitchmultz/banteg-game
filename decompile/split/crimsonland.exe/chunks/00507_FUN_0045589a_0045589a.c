/* FUN_0045589a @ 0045589a */

float * FUN_0045589a(float *param_1,undefined4 param_2,int *param_3,int param_4,int param_5,
                    int param_6)

{
  float fVar1;
  float fVar2;
  
  switch(((param_6 != 0) << 1 | param_5 != 0) << 1 | param_4 != 0) {
  case '\0':
    break;
  case '\x01':
    break;
  case '\x02':
    break;
  case '\x03':
    goto LAB_0045596b;
  case '\x04':
    break;
  case '\x05':
    goto LAB_0045596b;
  case '\x06':
    goto LAB_0045596b;
  case '\a':
    thunk_FUN_00453a57();
LAB_0045596b:
    thunk_FUN_00453a57();
  }
  thunk_FUN_00453464();
  if (param_3 != (int *)0x0) {
    fVar2 = (float)param_3[2];
    if (param_3[2] < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    fVar1 = (float)*param_3;
    if (*param_3 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    *param_1 = fVar1 + fVar2 * (*param_1 + 1.0) * 0.5;
    fVar2 = (float)param_3[3];
    if (param_3[3] < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    fVar1 = (float)param_3[1];
    if (param_3[1] < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    param_1[1] = fVar1 + fVar2 * (1.0 - param_1[1]) * 0.5;
    param_1[2] = ((float)param_3[5] - (float)param_3[4]) * param_1[2] + (float)param_3[4];
  }
  return param_1;
}



