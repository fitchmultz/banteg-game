/* FUN_1000e012 @ 1000e012 */

/* [binja] int32_t __stdcall sub_1000e012(float arg1, float arg2, float arg3) */

int FUN_1000e012(float arg1,float arg2,float arg3)

{
  int iVar1;
  undefined4 in_stack_00000010;
  
  grim_select_renderer_backend(1);
  iVar1 = (*(code *)PTR_FUN_10053cdc)(arg1,arg2,arg3,in_stack_00000010);
  return iVar1;
}



