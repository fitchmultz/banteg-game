/* FUN_1003b370 @ 1003b370 */

uint __cdecl FUN_1003b370(int *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piStack_4;
  
  piVar2 = param_1;
  iVar3 = param_1[0x48];
  if (iVar3 != 1) {
    if ((iVar3 < 1) || (4 < iVar3)) {
      *(undefined4 *)(*param_1 + 0x14) = 0x18;
      *(int *)(*param_1 + 0x18) = param_1[0x48];
      *(undefined4 *)(*param_1 + 0x1c) = 4;
      (**(code **)*param_1)(param_1);
    }
    iVar3 = FUN_1003e460(param_1[6],param_1[0x43] << 3);
    param_1[0x4d] = iVar3;
    iVar3 = FUN_1003e460(param_1[7],param_1[0x44] << 3);
    param_1[0x4e] = iVar3;
    piVar4 = (int *)param_1[0x48];
    param_1[0x4f] = 0;
    param_1 = (int *)0x0;
    if (0 < (int)piVar4) {
      piStack_4 = piVar2 + 0x49;
      do {
        iVar3 = *piStack_4;
        uVar6 = *(uint *)(iVar3 + 8);
        uVar1 = *(uint *)(iVar3 + 0xc);
        *(uint *)(iVar3 + 0x40) = *(int *)(iVar3 + 0x24) * uVar6;
        uVar5 = *(uint *)(iVar3 + 0x1c) % uVar6;
        iVar7 = uVar1 * uVar6;
        *(uint *)(iVar3 + 0x34) = uVar6;
        *(uint *)(iVar3 + 0x38) = uVar1;
        *(int *)(iVar3 + 0x3c) = iVar7;
        if (uVar5 == 0) {
          uVar5 = uVar6;
        }
        *(uint *)(iVar3 + 0x44) = uVar5;
        uVar6 = *(uint *)(iVar3 + 0x20) % uVar1;
        if (uVar6 == 0) {
          uVar6 = uVar1;
        }
        *(uint *)(iVar3 + 0x48) = uVar6;
        if (10 < piVar2[0x4f] + iVar7) {
          *(undefined4 *)(*piVar2 + 0x14) = 0xb;
          (**(code **)*piVar2)(piVar2);
        }
        if (0 < iVar7) {
          do {
            piVar2[piVar2[0x4f] + 0x50] = (int)param_1;
            iVar7 = iVar7 + -1;
            piVar2[0x4f] = piVar2[0x4f] + 1;
          } while (iVar7 != 0);
        }
        piVar4 = (int *)((int)param_1 + 1);
        piStack_4 = piStack_4 + 1;
        param_1 = piVar4;
      } while ((int)piVar4 < piVar2[0x48]);
    }
    return (uint)piVar4;
  }
  iVar3 = param_1[0x49];
  param_1[0x4d] = *(int *)(iVar3 + 0x1c);
  param_1[0x4e] = *(int *)(iVar3 + 0x20);
  uVar6 = *(uint *)(iVar3 + 0xc);
  *(undefined4 *)(iVar3 + 0x40) = *(undefined4 *)(iVar3 + 0x24);
  uVar1 = *(uint *)(iVar3 + 0x20);
  uVar5 = uVar1 % uVar6;
  *(undefined4 *)(iVar3 + 0x34) = 1;
  *(undefined4 *)(iVar3 + 0x38) = 1;
  *(undefined4 *)(iVar3 + 0x3c) = 1;
  *(undefined4 *)(iVar3 + 0x44) = 1;
  if (uVar5 == 0) {
    uVar5 = uVar6;
  }
  *(uint *)(iVar3 + 0x48) = uVar5;
  param_1[0x4f] = 1;
  param_1[0x50] = 0;
  return uVar1 / uVar6;
}



