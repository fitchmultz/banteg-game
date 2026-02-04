/* FUN_004544ad @ 004544ad */

/* [binja] int32_t __stdcall sub_4544ad(float arg1); wrapper calls PTR_FUN_0047961c (idx 0x1f) */

float * FUN_004544ad(float *arg1,float arg2)

{
  float *pfVar1;
  
  renderer_select_backend(1);
  pfVar1 = (float *)(*(code *)PTR_FUN_0047961c)(arg1,arg2);
  return pfVar1;
}



