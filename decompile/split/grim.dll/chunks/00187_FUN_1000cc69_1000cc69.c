/* FUN_1000cc69 @ 1000cc69 */

/* [binja] float* __stdcall sub_1000cc69(float* arg1, float* arg2, float* arg3, float* arg4, float*
   arg5, float arg6) */

float * FUN_1000cc69(float *arg1,float *arg2,float *arg3,float *arg4,float *arg5,float arg6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = arg6 * arg6;
  fVar2 = arg6 * fVar1;
  fVar5 = ((fVar2 + fVar2) - fVar1 * 3.0) + 1.0;
  fVar3 = (fVar2 - (fVar1 + fVar1)) + arg6;
  fVar4 = fVar1 * 3.0 - (fVar2 + fVar2);
  *arg1 = (fVar2 - fVar1) * *arg5 + fVar4 * *arg4 + fVar3 * *arg3 + fVar5 * *arg2;
  arg1[1] = fVar5 * arg2[1] + fVar3 * arg3[1] + fVar4 * arg4[1] + (fVar2 - fVar1) * arg5[1];
  return arg1;
}



