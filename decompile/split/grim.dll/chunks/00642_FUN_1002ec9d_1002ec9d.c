/* FUN_1002ec9d @ 1002ec9d */

/* [binja] void* __fastcall sub_1002ec9d(void* arg1) */

void * __fastcall FUN_1002ec9d(void *arg1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = *(void **)((int)arg1 + 0x184);
  if (*(int *)((int)arg1 + 0x120) < 2) {
    if (*(uint *)((int)arg1 + 0x80) < *(int *)((int)arg1 + 0x118) - 1U) {
      uVar2 = *(undefined4 *)(*(int *)((int)arg1 + 0x124) + 0xc);
    }
    else {
      uVar2 = *(undefined4 *)(*(int *)((int)arg1 + 0x124) + 0x48);
    }
    *(undefined4 *)((int)pvVar1 + 0x1c) = uVar2;
  }
  else {
    *(undefined4 *)((int)pvVar1 + 0x1c) = 1;
  }
  *(undefined4 *)((int)pvVar1 + 0x14) = 0;
  *(undefined4 *)((int)pvVar1 + 0x18) = 0;
  return pvVar1;
}



