/* FUN_1000f4ea @ 1000f4ea */

/* [binja] float* __stdcall sub_1000f4ea(float* arg1, float* arg2, float* arg3) */

float * FUN_1000f4ea(float *arg1,float *arg2,float *arg3)

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
  int iVar16;
  
  fVar1 = *arg2;
  fVar2 = arg3[2];
  fVar3 = *arg2;
  fVar4 = arg3[1];
  fVar5 = arg2[1];
  fVar6 = arg3[6];
  fVar7 = arg2[1];
  fVar8 = arg3[5];
  fVar9 = arg2[2];
  fVar10 = arg3[10];
  fVar11 = arg2[2];
  fVar12 = arg3[9];
  fVar13 = arg3[0xd];
  fVar14 = arg3[0xe];
  fVar15 = arg3[0xf] + arg2[2] * arg3[0xb] + arg2[1] * arg3[7] + *arg2 * arg3[3];
  *arg1 = arg3[0xc] + arg2[2] * arg3[8] + arg2[1] * arg3[4] + *arg2 * *arg3;
  arg1[1] = fVar13 + fVar11 * fVar12 + fVar7 * fVar8 + fVar3 * fVar4;
  arg1[2] = fVar14 + fVar9 * fVar10 + fVar5 * fVar6 + fVar1 * fVar2;
  iVar16 = float_near_equal(fVar15,1.0);
  if (iVar16 == 0) {
    fVar15 = 1.0 / fVar15;
    *arg1 = fVar15 * *arg1;
    arg1[1] = fVar15 * arg1[1];
    arg1[2] = fVar15 * arg1[2];
  }
  return arg1;
}



