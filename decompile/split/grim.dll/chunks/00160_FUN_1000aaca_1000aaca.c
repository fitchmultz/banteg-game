/* FUN_1000aaca @ 1000aaca */

/* [binja] int32_t __fastcall sub_1000aaca(void* arg1, int32_t arg2) */

int __fastcall FUN_1000aaca(void *arg1,int arg2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint local_8;
  
  uVar3 = 0;
  if (*(int *)(&DAT_1004c9c0 + (*(int *)((int)arg1 + 4) * 5 + *(int *)(arg2 + 4)) * 4) != 0) {
    local_8 = 0;
    puVar5 = (uint *)((int)arg1 + 0xc);
    iVar4 = 5;
    do {
      uVar1 = *puVar5;
      if (uVar1 != 0) {
        local_8 = local_8 + 1;
      }
      uVar2 = *(uint *)((arg2 - (int)arg1) + (int)puVar5);
      if (uVar1 < uVar2) {
        if (uVar1 == 0) {
          uVar3 = uVar3 + 0x100;
        }
        else {
          uVar3 = uVar3 + (uVar2 - uVar1);
        }
      }
      else if (uVar2 < uVar1) {
        if (uVar2 == 0) {
          uVar3 = uVar3 + 0x1000000;
        }
        else {
          uVar3 = uVar3 + (uVar1 - uVar2) * 0x10000;
        }
      }
      puVar5 = puVar5 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (local_8 != uVar3 >> 0x18) {
      return uVar3;
    }
  }
  return -1;
}



