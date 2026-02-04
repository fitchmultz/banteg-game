/* FUN_1000e541 @ 1000e541 */

/* [binja] int32_t __stdcall sub_1000e541(int32_t arg1, float arg2, int32_t arg3, int32_t arg4,
   int32_t arg5) */

int FUN_1000e541(int arg1,float arg2,int arg3,int arg4,int arg5)

{
  int iVar1;
  
  grim_select_renderer_backend(1);
  iVar1 = (*(code *)PTR_FUN_10053cfc)(arg1,arg2,arg3,arg4,arg5);
  return iVar1;
}



