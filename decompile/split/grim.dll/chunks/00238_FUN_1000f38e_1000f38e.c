/* FUN_1000f38e @ 1000f38e */

/* [binja] float* __stdcall sub_1000f38e(float* arg1, float* arg2, float* arg3) */

float * FUN_1000f38e(float *arg1,float *arg2,float *arg3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  
  fVar1 = *arg2;
  fVar2 = arg3[1];
  fVar3 = arg2[1];
  fVar4 = arg3[5];
  fVar5 = arg3[0xd];
  fVar6 = arg3[0xf] + arg2[1] * arg3[7] + *arg2 * arg3[3];
  *arg1 = arg3[0xc] + arg2[1] * arg3[4] + *arg2 * *arg3;
  arg1[1] = fVar5 + fVar3 * fVar4 + fVar1 * fVar2;
  iVar7 = float_near_equal(fVar6,1.0);
  if (iVar7 == 0) {
    fVar6 = 1.0 / fVar6;
    *arg1 = fVar6 * *arg1;
    arg1[1] = fVar6 * arg1[1];
  }
  return arg1;
}



