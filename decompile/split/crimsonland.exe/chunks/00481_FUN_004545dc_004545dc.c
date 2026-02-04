/* FUN_004545dc @ 004545dc */

/* [binja] int32_t __stdcall sub_4545dc(int arg1, float arg2); wrapper calls PTR_FUN_00479648 (idx
   0x2a) */

float * FUN_004545dc(float *arg1,float *arg2,float arg3)

{
  float *pfVar1;
  
  renderer_select_backend(1);
  pfVar1 = (float *)(*(code *)PTR_FUN_00479648)(arg1,arg2,arg3);
  return pfVar1;
}



