/* FUN_1000e873 @ 1000e873 */

/* [binja] float* __stdcall sub_1000e873(float arg1, float arg2, float arg3) */

float * FUN_1000e873(float arg1,float arg2,float arg3)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  thunk_FUN_1000ce69();
  fVar2 = (float10)fcos((float10)(arg3 * 0.5));
  fVar3 = (float10)fsin((float10)(arg3 * 0.5));
  *(float *)((int)arg1 + 0xc) = (float)fVar2;
  fVar1 = (float)fVar3;
  *(float *)arg1 = local_18 * fVar1;
  *(float *)((int)arg1 + 4) = local_14 * fVar1;
  *(float *)((int)arg1 + 8) = local_10 * fVar1;
  return (float *)arg1;
}



