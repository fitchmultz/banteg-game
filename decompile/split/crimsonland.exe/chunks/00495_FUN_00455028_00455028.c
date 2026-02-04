/* FUN_00455028 @ 00455028 */

/* [binja] int32_t __stdcall sub_455028(int arg1, int arg2, float arg3); wrapper calls
   PTR_FUN_0047962c (idx 0x23) */

float * FUN_00455028(float *arg1,float *arg2,float *arg3,float arg4)

{
  float *pfVar1;
  
  renderer_select_backend(1);
  pfVar1 = (float *)(*(code *)PTR_FUN_0047962c)(arg1,arg2,arg3,arg4);
  return pfVar1;
}



