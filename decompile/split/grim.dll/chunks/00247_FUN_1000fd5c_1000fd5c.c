/* FUN_1000fd5c @ 1000fd5c */

/* [binja] float* __stdcall sub_1000fd5c(float* arg1, float arg2) */

float * FUN_1000fd5c(float *arg1,float arg2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  thunk_FUN_1000ef90();
  fVar1 = local_14 * -2.0;
  fVar3 = local_10 * -2.0;
  fVar2 = local_c * -2.0;
  *arg1 = local_14 * fVar1 + 1.0;
  arg1[1] = fVar3 * local_14;
  arg1[2] = fVar2 * local_14;
  arg1[3] = 0.0;
  arg1[4] = local_10 * fVar1;
  arg1[5] = local_10 * fVar3 + 1.0;
  arg1[6] = fVar2 * local_10;
  arg1[7] = 0.0;
  arg1[8] = local_c * fVar1;
  arg1[9] = local_c * fVar3;
  arg1[10] = local_c * fVar2 + 1.0;
  arg1[0xb] = 0.0;
  arg1[0xc] = local_8 * fVar1;
  arg1[0xd] = local_8 * fVar3;
  arg1[0xe] = local_8 * fVar2;
  arg1[0xf] = 1.0;
  return arg1;
}



