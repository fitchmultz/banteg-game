/* FUN_00454303 @ 00454303 */

/* [binja] int32_t __stdcall sub_454303(float arg1, float arg2, float arg3); wrapper calls
   PTR_FUN_00479624 (idx 0x21) */

float * FUN_00454303(float *arg1,float arg2,float arg3,float arg4)

{
  float *pfVar1;
  
  renderer_select_backend(1);
  pfVar1 = (float *)(*(code *)PTR_FUN_00479624)(arg1,arg2,arg3,arg4);
  return pfVar1;
}



