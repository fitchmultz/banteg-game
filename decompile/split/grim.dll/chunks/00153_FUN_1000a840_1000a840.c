/* FUN_1000a840 @ 1000a840 */

/* [binja] bool __stdcall sub_1000a840(int32_t* arg1, uint32_t arg2, int32_t arg3, int32_t arg4) */

bool FUN_1000a840(int *arg1,uint arg2,int arg3,int arg4)

{
  void *pvVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = arg2;
  pvVar1 = operator_new(arg2);
  *arg1 = (int)pvVar1;
  arg2 = uVar2;
  uVar2 = FUN_10046400(pvVar1,&arg2,arg3,arg4);
  uVar3 = FUN_1000a820(uVar2);
  return (char)uVar3 == '\0';
}



