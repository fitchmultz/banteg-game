/* FUN_004556ff @ 004556ff */

/* [binja] float* __stdcall sub_4556ff(float* arg1, float* arg2, float* arg3) */

float * FUN_004556ff(float *arg1,float *arg2,float *arg3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = arg3[1];
  fVar2 = *arg2;
  fVar3 = arg3[5];
  fVar4 = arg2[1];
  *arg1 = *arg2 * *arg3 + arg3[4] * arg2[1];
  arg1[1] = fVar3 * fVar4 + fVar1 * fVar2;
  return arg1;
}



