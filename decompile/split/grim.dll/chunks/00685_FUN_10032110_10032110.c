/* FUN_10032110 @ 10032110 */

/* [binja] int32_t sub_10032110(void* arg1, int32_t arg2, int32_t* arg3, int32_t arg4, int32_t*
   arg5) */

int __cdecl FUN_10032110(void *arg1,int arg2,int *arg3,int arg4,int *arg5)

{
  int iVar1;
  int *in_stack_00000018;
  
  iVar1 = (**(code **)(*(int *)((int)arg1 + 0x19c) + 0xc))
                    (arg1,arg2,*arg3,arg5 + *in_stack_00000018);
  *in_stack_00000018 = *in_stack_00000018 + 1;
  *arg3 = *arg3 + 1;
  return iVar1;
}



