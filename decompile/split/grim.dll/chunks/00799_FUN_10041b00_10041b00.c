/* FUN_10041b00 @ 10041b00 */

/* [binja] int32_t sub_10041b00(void* arg1, int32_t arg2, int32_t* arg3, int32_t arg4) */

int __cdecl FUN_10041b00(void *arg1,int arg2,int *arg3,int arg4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int in_stack_00000014;
  int *in_stack_00000018;
  int in_stack_0000001c;
  
  iVar1 = *(int *)((int)arg1 + 0x188);
  if (*(int *)(iVar1 + 0x18) == 0) {
    uVar2 = (**(code **)(*(int *)((int)arg1 + 4) + 0x1c))
                      (arg1,*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x14),
                       *(undefined4 *)(iVar1 + 0x10),0);
    *(undefined4 *)(iVar1 + 0xc) = uVar2;
  }
  uVar4 = *(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 0x18);
  uVar3 = in_stack_0000001c - *in_stack_00000018;
  if (uVar3 < uVar4) {
    uVar4 = uVar3;
  }
  uVar3 = *(int *)((int)arg1 + 0x60) - *(int *)(iVar1 + 0x14);
  if (uVar3 < uVar4) {
    uVar4 = uVar3;
  }
  (**(code **)(*(int *)((int)arg1 + 0x1a4) + 4))
            (arg1,*(int *)(iVar1 + 0xc) + *(int *)(iVar1 + 0x18) * 4,
             in_stack_00000014 + *in_stack_00000018 * 4,uVar4);
  *in_stack_00000018 = *in_stack_00000018 + uVar4;
  uVar3 = *(uint *)(iVar1 + 0x10);
  uVar4 = *(int *)(iVar1 + 0x18) + uVar4;
  *(uint *)(iVar1 + 0x18) = uVar4;
  if (uVar3 <= uVar4) {
    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + uVar3;
    *(undefined4 *)(iVar1 + 0x18) = 0;
  }
  return uVar3;
}



