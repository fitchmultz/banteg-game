/* FUN_10010313 @ 10010313 */

/* [binja] int32_t __thiscall sub_10010313(int32_t* arg1, int32_t* arg2) */

int __thiscall FUN_10010313(void *this,int *arg1,int *arg2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  
  if ((*(void **)((int)this + 4) != (void *)0x0) && (*(int *)((int)this + 0x38) != 0)) {
    operator_delete(*(void **)((int)this + 4));
  }
  if ((*(void **)((int)this + 8) != (void *)0x0) && (*(int *)((int)this + 0x3c) != 0)) {
    operator_delete(*(void **)((int)this + 8));
  }
  *(int *)this = arg1[1];
  *(int *)((int)this + 4) = *arg1;
  *(int *)((int)this + 8) = arg1[0x12];
  puVar1 = (uint *)((int)this + 0x18);
  puVar3 = (uint *)(arg1 + 10);
  puVar4 = puVar1;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  *(int *)((int)this + 0x30) = arg1[2];
  *(int *)((int)this + 0x34) = arg1[3];
  iVar2 = *(int *)this;
  if ((iVar2 == 0x31545844) || (iVar2 == 0x32545844)) {
LAB_100103a7:
    *puVar1 = *puVar1 & 0xfffffffc;
    *(uint *)((int)this + 0x1c) = *(uint *)((int)this + 0x1c) & 0xfffffffc;
  }
  else {
    if (iVar2 != 0x32595559) {
      if (((iVar2 == 0x33545844) || (iVar2 == 0x34545844)) || (iVar2 == 0x35545844))
      goto LAB_100103a7;
      if (iVar2 != 0x59565955) goto LAB_100103ae;
    }
    *puVar1 = *puVar1 & 0xfffffffe;
  }
LAB_100103ae:
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(uint *)((int)this + 0xc) = *(int *)((int)this + 0x20) - *puVar1;
  *(int *)((int)this + 0x10) = *(int *)((int)this + 0x24) - *(int *)((int)this + 0x1c);
  *(int *)((int)this + 0x14) = *(int *)((int)this + 0x2c) - *(int *)((int)this + 0x28);
  return 0;
}



