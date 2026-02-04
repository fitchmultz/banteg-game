/* FUN_100332e1 @ 100332e1 */

void __cdecl FUN_100332e1(int *param_1,char param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint size;
  int iVar4;
  
  iVar1 = param_1[0x69];
  iVar2 = *(int *)(iVar1 + 0x18);
  if (param_1[0x13] != 0) {
    param_1[0x13] = 2;
  }
  if (param_2 == '\0') {
    if (param_1[0x13] == 2) {
      *(code **)(iVar1 + 4) = FUN_10032fc1;
    }
    else {
      *(code **)(iVar1 + 4) = FUN_10032f18;
    }
    *(undefined **)(iVar1 + 8) = &DAT_10010dec;
    iVar4 = param_1[0x1c];
    if (iVar4 < 1) {
      *(undefined4 *)(*param_1 + 0x14) = 0x37;
      *(undefined4 *)(*param_1 + 0x18) = 1;
      (**(code **)*param_1)(param_1);
    }
    if (0x100 < iVar4) {
      *(undefined4 *)(*param_1 + 0x14) = 0x38;
      *(undefined4 *)(*param_1 + 0x18) = 0x100;
      (**(code **)*param_1)(param_1);
    }
    if (param_1[0x13] == 2) {
      size = (param_1[0x17] + 2) * 6;
      if (*(int *)(iVar1 + 0x20) == 0) {
        uVar3 = (**(code **)(param_1[1] + 4))(param_1,1,size);
        *(undefined4 *)(iVar1 + 0x20) = uVar3;
      }
      memzero(*(void **)(iVar1 + 0x20),size);
      if (*(int *)(iVar1 + 0x28) == 0) {
        FUN_1003322f();
      }
      *(undefined1 *)(iVar1 + 0x24) = 0;
    }
  }
  else {
    *(code **)(iVar1 + 4) = FUN_100324f2;
    *(undefined1 **)(iVar1 + 8) = &LAB_100332bf;
    *(undefined1 *)(iVar1 + 0x1c) = 1;
  }
  if (*(char *)(iVar1 + 0x1c) != '\0') {
    iVar4 = 0;
    do {
      memzero(*(void **)(iVar2 + iVar4 * 4),0x1000);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x20);
    *(undefined1 *)(iVar1 + 0x1c) = 0;
  }
  return;
}



