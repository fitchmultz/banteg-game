/* FUN_1000ed37 @ 1000ed37 */

/* [binja] int32_t __stdcall sub_1000ed37(int32_t arg1, int32_t arg2, float arg3) */

int FUN_1000ed37(int arg1,int arg2,float arg3)

{
  int iVar1;
  undefined4 in_stack_00000010;
  
  grim_select_renderer_backend(1);
  iVar1 = (*(code *)PTR_FUN_10053ce4)(arg1,arg2,arg3,in_stack_00000010);
  return iVar1;
}



