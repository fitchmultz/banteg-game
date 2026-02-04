/* FUN_1000f323 @ 1000f323 */

/* [binja] float* __stdcall sub_1000f323(float* arg1, float* arg2, float* arg3) */

float * FUN_1000f323(float *arg1,float *arg2,float *arg3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  
  fVar1 = arg3[1];
  fVar2 = *arg2;
  fVar3 = arg3[5];
  fVar4 = arg2[1];
  fVar5 = arg3[0xd];
  fVar6 = arg3[2];
  fVar7 = *arg2;
  fVar8 = arg3[6];
  fVar9 = arg2[1];
  fVar10 = arg3[0xe];
  fVar11 = arg3[3];
  fVar12 = *arg2;
  fVar13 = arg3[7];
  fVar14 = arg2[1];
  fVar15 = arg3[0xf];
  *arg1 = *arg2 * *arg3 + arg3[4] * arg2[1] + arg3[0xc];
  arg1[1] = fVar3 * fVar4 + fVar1 * fVar2 + fVar5;
  arg1[2] = fVar8 * fVar9 + fVar6 * fVar7 + fVar10;
  arg1[3] = fVar13 * fVar14 + fVar11 * fVar12 + fVar15;
  return arg1;
}



