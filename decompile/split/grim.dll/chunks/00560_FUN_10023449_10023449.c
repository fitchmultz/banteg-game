/* FUN_10023449 @ 10023449 */

/* [binja] void* sub_10023449(int32_t* arg1, int32_t* arg2, char arg3, int32_t arg4, int32_t arg5,
   int32_t arg6) */

void * __thiscall FUN_10023449(void *this,int *arg1,int *arg2,char arg3,int arg4,int arg5,int arg6)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = arg1[1];
  if (arg2 != (int *)0x1) {
    *(undefined4 *)(*arg1 + 0x14) = 0xc;
    *(int **)(*arg1 + 0x18) = arg2;
    this = arg1;
    (**(code **)*arg1)();
  }
  puVar2 = FUN_1002318f(this,arg1,arg2,(int *)0x78);
  *puVar2 = 0;
  puVar2[1] = arg5;
  puVar2[2] = arg4;
  puVar2[3] = arg6;
  *(undefined1 *)((int)puVar2 + 0x22) = 0;
  *(char *)(puVar2 + 8) = arg3;
  puVar2[9] = *(undefined4 *)(iVar1 + 0x40);
  *(undefined4 **)(iVar1 + 0x40) = puVar2;
  return puVar2;
}



