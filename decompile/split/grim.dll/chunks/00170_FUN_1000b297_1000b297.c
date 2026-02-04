/* FUN_1000b297 @ 1000b297 */

/* [binja] int32_t __stdcall sub_1000b297(int32_t** arg1, int32_t arg2, int32_t arg3, int32_t arg4)
    */

int __thiscall FUN_1000b297(void *this,int **arg1,int arg2,int arg3,int arg4)

{
  int iVar1;
  int arg5;
  int in_stack_00000014;
  undefined4 in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  
  if ((arg1 == (int **)0x0) || (in_stack_00000020 == 0)) {
    iVar1 = -0x7789f794;
  }
  else {
    arg5 = in_stack_00000014;
    if (in_stack_00000014 == -1) {
      arg5 = 0;
    }
    iVar1 = FUN_1000b26f(this,arg1,&arg2,&arg3,&arg4,arg5,(int)&stack0x00000018,in_stack_0000001c);
    if ((-1 < iVar1) &&
       (iVar1 = (*(code *)(*arg1)[0x14])
                          (arg1,arg2,arg3,arg4,arg5,in_stack_00000018,in_stack_0000001c,
                           in_stack_00000020), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



