/* FUN_00454b64 @ 00454b64 */

/* [binja] float* __stdcall sub_454b64(float arg1, float arg2, float arg3) */

float * FUN_00454b64(float arg1,float arg2,float arg3)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  thunk_FUN_0045315a();
  fVar2 = (float10)fcos((float10)(arg3 * 0.5));
  fVar3 = (float10)fsin((float10)(arg3 * 0.5));
  *(float *)((int)arg1 + 0xc) = (float)fVar2;
  fVar1 = (float)fVar3;
  *(float *)arg1 = local_18 * fVar1;
  *(float *)((int)arg1 + 4) = local_14 * fVar1;
  *(float *)((int)arg1 + 8) = local_10 * fVar1;
  return (float *)arg1;
}



