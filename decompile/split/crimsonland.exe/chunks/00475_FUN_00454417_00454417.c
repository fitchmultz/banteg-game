/* FUN_00454417 @ 00454417 */

/* [binja] int32_t __stdcall sub_454417(float arg1); wrapper calls PTR_FUN_00479618 (idx 0x1e) */

float * FUN_00454417(float *arg1,float arg2)

{
  float *pfVar1;
  
  renderer_select_backend(1);
  pfVar1 = (float *)(*(code *)PTR_FUN_00479618)(arg1,arg2);
  return pfVar1;
}



