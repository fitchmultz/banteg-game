/* FUN_100312d7 @ 100312d7 */

/* [binja] int32_t* sub_100312d7(void* arg1, int32_t arg2, int32_t* arg3, int32_t arg4, int32_t*
   arg5, int32_t arg6) */

int * __cdecl FUN_100312d7(void *arg1,int arg2,int *arg3,int arg4,int *arg5,int arg6)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  int in_stack_0000001c;
  int local_8;
  
  pvVar3 = arg1;
  iVar2 = *(int *)((int)arg1 + 0x19c);
  if (*(int *)((int)arg1 + 0x110) <= *(int *)(iVar2 + 0x5c)) {
    arg1 = (void *)0x0;
    local_8 = *(int *)((int)pvVar3 + 0xc4);
    if (0 < *(int *)((int)pvVar3 + 0x20)) {
      iVar4 = iVar2 + 0xc;
      do {
        (**(code **)(iVar4 + 0x28))
                  (pvVar3,local_8,
                   *(int *)(arg2 + (int)arg1 * 4) + *(int *)(iVar4 + 0x58) * *arg3 * 4,iVar4);
        local_8 = local_8 + 0x54;
        arg1 = (void *)((int)arg1 + 1);
        iVar4 = iVar4 + 4;
      } while ((int)arg1 < *(int *)((int)pvVar3 + 0x20));
    }
    *(undefined4 *)(iVar2 + 0x5c) = 0;
  }
  uVar5 = *(int *)((int)pvVar3 + 0x110) - *(int *)(iVar2 + 0x5c);
  if (*(uint *)(iVar2 + 0x60) < uVar5) {
    uVar5 = *(uint *)(iVar2 + 0x60);
  }
  uVar1 = in_stack_0000001c - *(int *)arg6;
  if (uVar1 < uVar5) {
    uVar5 = uVar1;
  }
  (**(code **)(*(int *)((int)pvVar3 + 0x1a0) + 4))
            (pvVar3,iVar2 + 0xc,*(undefined4 *)(iVar2 + 0x5c),arg5 + *(int *)arg6,uVar5);
  *(uint *)arg6 = *(int *)arg6 + uVar5;
  *(int *)(iVar2 + 0x60) = *(int *)(iVar2 + 0x60) - uVar5;
  *(int *)(iVar2 + 0x5c) = *(int *)(iVar2 + 0x5c) + uVar5;
  if (*(int *)((int)pvVar3 + 0x110) <= *(int *)(iVar2 + 0x5c)) {
    *arg3 = *arg3 + 1;
    arg6 = (int)arg3;
  }
  return (int *)arg6;
}



