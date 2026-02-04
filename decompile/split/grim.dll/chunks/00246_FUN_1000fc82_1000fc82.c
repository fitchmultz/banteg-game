/* FUN_1000fc82 @ 1000fc82 */

/* [binja] float* __stdcall sub_1000fc82(float* arg1, float* arg2, int32_t arg3) */

float * FUN_1000fc82(float *arg1,float *arg2,int arg3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  thunk_FUN_1000ef90();
  fVar1 = local_c * arg2[2] + local_8 * arg2[3] + local_14 * *arg2 + local_10 * arg2[1];
  fVar4 = -local_14;
  fVar3 = -local_10;
  fVar2 = -local_c;
  fVar5 = -local_8;
  *arg1 = fVar4 * *arg2 + fVar1;
  arg1[4] = fVar3 * *arg2;
  arg1[8] = fVar2 * *arg2;
  arg1[0xc] = fVar5 * *arg2;
  arg1[1] = fVar4 * arg2[1];
  arg1[5] = fVar3 * arg2[1] + fVar1;
  arg1[9] = fVar2 * arg2[1];
  arg1[0xd] = fVar5 * arg2[1];
  arg1[2] = fVar4 * arg2[2];
  arg1[6] = fVar3 * arg2[2];
  arg1[10] = fVar2 * arg2[2] + fVar1;
  arg1[0xe] = fVar5 * arg2[2];
  arg1[3] = fVar4 * arg2[3];
  arg1[7] = fVar3 * arg2[3];
  arg1[0xb] = fVar2 * arg2[3];
  arg1[0xf] = fVar5 * arg2[3] + fVar1;
  return arg1;
}



