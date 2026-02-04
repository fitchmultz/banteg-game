/* FUN_00452f5a @ 00452f5a */

void FUN_00452f5a(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = param_6 * param_6;
  fVar2 = param_6 * fVar1;
  fVar5 = ((fVar2 + fVar2) - fVar1 * 3.0) + 1.0;
  fVar3 = (fVar2 - (fVar1 + fVar1)) + param_6;
  fVar4 = fVar1 * 3.0 - (fVar2 + fVar2);
  *param_1 = (fVar2 - fVar1) * *param_5 + fVar4 * *param_4 + fVar3 * *param_3 + fVar5 * *param_2;
  param_1[1] = fVar5 * param_2[1] +
               fVar3 * param_3[1] + fVar4 * param_4[1] + (fVar2 - fVar1) * param_5[1];
  return;
}



