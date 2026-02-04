/* FUN_0045326f @ 0045326f */

void FUN_0045326f(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = param_6 * param_6;
  fVar2 = param_6 * fVar1;
  fVar5 = (fVar1 * 2.0 - fVar2) - param_6;
  fVar4 = (fVar2 * 3.0 - fVar1 * 5.0) + 2.0;
  fVar3 = (fVar1 * 4.0 - fVar2 * 3.0) + param_6;
  fVar2 = fVar2 - fVar1;
  *param_1 = (fVar2 * *param_5 + fVar3 * *param_4 + fVar4 * *param_3 + fVar5 * *param_2) * 0.5;
  param_1[1] = (fVar5 * param_2[1] + fVar4 * param_3[1] + fVar3 * param_4[1] + fVar2 * param_5[1]) *
               0.5;
  param_1[2] = (fVar5 * param_2[2] + fVar4 * param_3[2] + fVar3 * param_4[2] + fVar2 * param_5[2]) *
               0.5;
  return;
}



