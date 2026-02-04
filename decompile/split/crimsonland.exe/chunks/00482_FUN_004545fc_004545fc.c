/* FUN_004545fc @ 004545fc */

/* [binja] float* __stdcall sub_4545fc(float* arg1, float arg2, float arg3) */

float * FUN_004545fc(float *arg1,float arg2,float arg3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float10 fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float10 fVar11;
  
  fVar6 = (float10)fcos((float10)arg3);
  fVar11 = (float10)fsin((float10)arg3);
  fVar1 = (float)fVar6;
  fVar2 = (float)fVar11;
  fVar7 = 1.0 - fVar1;
  fVar3 = *(float *)arg2;
  fVar4 = *(float *)((int)arg2 + 4);
  fVar5 = *(float *)((int)arg2 + 8);
  thunk_FUN_0045315a();
  fVar8 = fVar4 * fVar3 * fVar7;
  fVar9 = fVar4 * fVar5 * fVar7;
  fVar10 = fVar5 * fVar3 * fVar7;
  *arg1 = fVar3 * fVar3 * fVar7 + fVar1;
  arg1[1] = fVar8 + fVar5 * fVar2;
  arg1[2] = fVar10 - fVar4 * fVar2;
  arg1[3] = 0.0;
  arg1[4] = fVar8 - fVar5 * fVar2;
  arg1[5] = fVar4 * fVar4 * fVar7 + fVar1;
  arg1[6] = fVar3 * fVar2 + fVar9;
  arg1[7] = 0.0;
  arg1[8] = fVar4 * fVar2 + fVar10;
  arg1[9] = fVar9 - fVar3 * fVar2;
  arg1[10] = fVar5 * fVar5 * fVar7 + fVar1;
  arg1[0xb] = 0.0;
  arg1[0xc] = 0.0;
  arg1[0xd] = 0.0;
  arg1[0xe] = 0.0;
  arg1[0xf] = 1.0;
  return arg1;
}



