/* FUN_004551f6 @ 004551f6 */

undefined4 *
FUN_004551f6(undefined4 *param_1,undefined4 *param_2,float *param_3,float *param_4,float param_5,
            float param_6)

{
  float a;
  int iVar1;
  float local_24 [4];
  float local_14 [4];
  
  a = param_5 + param_6;
  iVar1 = float_near_equal(a,0.0);
  if (iVar1 == 0) {
    thunk_FUN_00455028(local_24,(float *)param_2,param_3,a);
    thunk_FUN_00455028(local_14,(float *)param_2,param_4,a);
    thunk_FUN_00455028((float *)param_1,local_24,local_14,param_6 / a);
  }
  else if (param_1 != param_2) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
  }
  return param_1;
}



