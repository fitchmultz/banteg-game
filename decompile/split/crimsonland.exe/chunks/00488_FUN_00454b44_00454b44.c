/* FUN_00454b44 @ 00454b44 */

/* [binja] int32_t __stdcall sub_454b44(int arg1, float arg2); wrapper calls PTR_FUN_00479614 (idx
   0x1d) */

float * FUN_00454b44(float *arg1,float *arg2,float arg3)

{
  float *pfVar1;
  
  renderer_select_backend(1);
  pfVar1 = (float *)(*(code *)PTR_FUN_00479614)(arg1,arg2,arg3);
  return pfVar1;
}



