/* FUN_1000ee44 @ 1000ee44 */

/* [binja] int32_t __stdcall sub_1000ee44(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4,
   int32_t arg5, float arg6) */

int FUN_1000ee44(int arg1,int arg2,int arg3,int arg4,int arg5,float arg6)

{
  int iVar1;
  
  grim_select_renderer_backend(1);
  iVar1 = (*(code *)PTR_FUN_10053d04)(arg1,arg2,arg3,arg4,arg5,arg6);
  return iVar1;
}



