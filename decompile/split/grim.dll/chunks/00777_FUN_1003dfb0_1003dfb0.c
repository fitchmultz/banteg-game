/* FUN_1003dfb0 @ 1003dfb0 */

uint __cdecl FUN_1003dfb0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 in_EAX;
  undefined3 uVar4;
  uint uVar3;
  
  uVar4 = (undefined3)((uint)in_EAX >> 8);
  uVar3 = CONCAT31(uVar4,*(char *)(param_1 + 0x48));
  if (((((*(char *)(param_1 + 0x48) != '\0') ||
        (uVar3 = CONCAT31(uVar4,*(char *)(param_1 + 0x108)), *(char *)(param_1 + 0x108) != '\0')) ||
       (uVar3 = 0, *(int *)(param_1 + 0x24) != 3)) ||
      (((*(int *)(param_1 + 0x20) != 3 || (*(int *)(param_1 + 0x28) != 2)) ||
       ((*(int *)(param_1 + 100) != 3 ||
        ((iVar1 = *(int *)(param_1 + 0xc4), *(int *)(iVar1 + 8) != 2 ||
         (uVar3 = 1, *(int *)(iVar1 + 0x5c) != 1)))))))) ||
     ((*(int *)(iVar1 + 0xb0) != 1 ||
      (((((2 < *(int *)(iVar1 + 0xc) || (*(int *)(iVar1 + 0x60) != 1)) ||
         (*(int *)(iVar1 + 0xb4) != 1)) ||
        ((iVar2 = *(int *)(param_1 + 0x114), *(int *)(iVar1 + 0x24) != iVar2 ||
         (*(int *)(iVar1 + 0x78) != iVar2)))) || (*(int *)(iVar1 + 0xcc) != iVar2)))))) {
    uVar3 = uVar3 & 0xffffff00;
  }
  return uVar3;
}



