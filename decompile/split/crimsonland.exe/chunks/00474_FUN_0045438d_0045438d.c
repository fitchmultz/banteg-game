/* FUN_0045438d @ 0045438d */

/* [binja] int32_t __stdcall sub_45438d(float arg1, float arg2, float arg3); wrapper calls
   PTR_FUN_00479608 (idx 0x1a) */

float * FUN_0045438d(float *arg1,float arg2,float arg3,float arg4)

{
  float *pfVar1;
  
  renderer_select_backend(1);
  pfVar1 = (float *)(*(code *)PTR_FUN_00479608)(arg1,arg2,arg3,arg4);
  return pfVar1;
}



