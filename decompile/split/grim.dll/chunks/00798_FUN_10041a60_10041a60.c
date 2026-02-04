/* FUN_10041a60 @ 10041a60 */

/* [binja] int32_t sub_10041a60(void* arg1, int32_t arg2, int32_t arg3, int32_t arg4, void** arg5)
    */

int __cdecl FUN_10041a60(void *arg1,int arg2,int arg3,int arg4,void **arg5)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int *in_stack_00000018;
  
  iVar2 = *(int *)((int)arg1 + 0x188);
  puVar1 = (uint *)(iVar2 + 0x18);
  if (*(int *)(iVar2 + 0x18) == 0) {
    uVar4 = (**(code **)(*(int *)((int)arg1 + 4) + 0x1c))
                      (arg1,*(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar2 + 0x14),
                       *(undefined4 *)(iVar2 + 0x10),1);
    *(undefined4 *)(iVar2 + 0xc) = uVar4;
  }
  uVar3 = *puVar1;
  (**(code **)(*(int *)((int)arg1 + 0x19c) + 4))
            (arg1,arg2,arg3,arg4,*(undefined4 *)(iVar2 + 0xc),puVar1,*(undefined4 *)(iVar2 + 0x10));
  if (uVar3 < *puVar1) {
    iVar5 = *puVar1 - uVar3;
    (**(code **)(*(int *)((int)arg1 + 0x1a4) + 4))(arg1,*(int *)(iVar2 + 0xc) + uVar3 * 4,0,iVar5);
    *in_stack_00000018 = *in_stack_00000018 + iVar5;
  }
  uVar3 = *(uint *)(iVar2 + 0x10);
  if (uVar3 <= *puVar1) {
    *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + uVar3;
    *puVar1 = 0;
  }
  return uVar3;
}



