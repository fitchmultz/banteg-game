/* FUN_004547f3 @ 004547f3 */

/* [binja] int32_t __stdcall sub_4547f3(float arg1, float arg2, float arg3); wrapper calls
   PTR_FUN_00479640 (idx 0x28) */

float * FUN_004547f3(float *arg1,float arg2,float arg3,float arg4)

{
  float *pfVar1;
  
  renderer_select_backend(1);
  pfVar1 = (float *)(*(code *)PTR_FUN_00479640)(arg1,arg2,arg3,arg4);
  return pfVar1;
}



