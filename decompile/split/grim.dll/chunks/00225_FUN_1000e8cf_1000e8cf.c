/* FUN_1000e8cf @ 1000e8cf */

/* [binja] int32_t __stdcall sub_1000e8cf(float arg1, float arg2, float arg3) */

int FUN_1000e8cf(float arg1,float arg2,float arg3)

{
  int iVar1;
  undefined4 in_stack_00000010;
  
  grim_select_renderer_backend(1);
  iVar1 = (*(code *)PTR_FUN_10053cbc)(arg1,arg2,arg3,in_stack_00000010);
  return iVar1;
}



