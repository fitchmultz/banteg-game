/* FUN_1000d53d @ 1000d53d */

/* [binja] int32_t __stdcall sub_1000d53d(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4,
   float arg5, float arg6) */

int FUN_1000d53d(int arg1,int arg2,int arg3,int arg4,float arg5,float arg6)

{
  int iVar1;
  
  grim_select_renderer_backend(1);
  iVar1 = (*(code *)PTR_FUN_10053d30)(arg1,arg2,arg3,arg4,arg5,arg6);
  return iVar1;
}



