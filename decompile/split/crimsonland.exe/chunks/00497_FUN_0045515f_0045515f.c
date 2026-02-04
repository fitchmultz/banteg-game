/* FUN_0045515f @ 0045515f */

float * FUN_0045515f(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                    float param_6)

{
  float fVar1;
  float local_24 [4];
  float local_14 [4];
  
  thunk_FUN_00455028(local_24,param_2,param_5,param_6);
  thunk_FUN_00455028(local_14,param_3,param_4,param_6);
  fVar1 = (1.0 - param_6) * param_6;
  thunk_FUN_00455028(param_1,local_24,local_14,fVar1 + fVar1);
  return param_1;
}



