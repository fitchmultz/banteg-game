/* FUN_00454544 @ 00454544 */

/* [binja] int32_t __stdcall sub_454544(float arg1); wrapper calls PTR_FUN_00479620 (idx 0x20) */

float * FUN_00454544(float *arg1,float arg2)

{
  float *pfVar1;
  
  renderer_select_backend(1);
  pfVar1 = (float *)(*(code *)PTR_FUN_00479620)(arg1,arg2);
  return pfVar1;
}



