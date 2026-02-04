/* FUN_1003dd90 @ 1003dd90 */

void __cdecl FUN_1003dd90(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  
  piVar2 = param_1;
  if (param_1[4] != 0xca) {
    *(undefined4 *)(*param_1 + 0x14) = 0x12;
    *(int *)(*param_1 + 0x18) = param_1[4];
    (**(code **)*param_1)(param_1);
  }
  iVar3 = param_1[0xb];
  uVar5 = param_1[0xc];
  if ((uint)(iVar3 * 8) < uVar5 || iVar3 * 8 - uVar5 == 0) {
    iVar3 = FUN_1003e460(param_1[6],8);
    param_1[0x17] = iVar3;
    iVar3 = FUN_1003e460(param_1[7],8);
    param_1[0x18] = iVar3;
    param_1[0x45] = 1;
  }
  else if ((uint)(iVar3 * 4) < uVar5 || iVar3 * 4 - uVar5 == 0) {
    iVar3 = FUN_1003e460(param_1[6],4);
    param_1[0x17] = iVar3;
    iVar3 = FUN_1003e460(param_1[7],4);
    param_1[0x18] = iVar3;
    param_1[0x45] = 2;
  }
  else if (uVar5 < (uint)(iVar3 * 2)) {
    param_1[0x17] = param_1[6];
    param_1[0x18] = param_1[7];
    param_1[0x45] = 8;
  }
  else {
    iVar3 = FUN_1003e460(param_1[6],2);
    param_1[0x17] = iVar3;
    iVar3 = FUN_1003e460(param_1[7],2);
    param_1[0x18] = iVar3;
    param_1[0x45] = 4;
  }
  piVar6 = param_1 + 8;
  piVar1 = param_1 + 0x31;
  param_1 = (int *)0x0;
  if (0 < *piVar6) {
    piVar6 = (int *)(*piVar1 + 0xc);
    do {
      iVar3 = piVar2[0x45];
      iVar4 = iVar3;
      if (iVar3 < 8) {
        do {
          iVar7 = piVar6[-1] * iVar4 * 2;
          if ((iVar7 - piVar2[0x43] * iVar3 != 0 && piVar2[0x43] * iVar3 <= iVar7) ||
             (iVar7 = *piVar6 * iVar4 * 2,
             iVar7 - piVar2[0x44] * iVar3 != 0 && piVar2[0x44] * iVar3 <= iVar7)) break;
          iVar4 = iVar4 * 2;
        } while (iVar4 < 8);
      }
      piVar6[6] = iVar4;
      param_1 = (int *)((int)param_1 + 1);
      piVar6 = piVar6 + 0x15;
    } while ((int)param_1 < piVar2[8]);
  }
  iVar3 = 0;
  if (0 < piVar2[8]) {
    piVar6 = (int *)(piVar2[0x31] + 0x24);
    do {
      iVar4 = FUN_1003e460(piVar6[-7] * *piVar6 * piVar2[6],piVar2[0x43] << 3);
      piVar6[1] = iVar4;
      iVar4 = FUN_1003e460(piVar6[-6] * *piVar6 * piVar2[7],piVar2[0x44] << 3);
      piVar6[2] = iVar4;
      iVar3 = iVar3 + 1;
      piVar6 = piVar6 + 0x15;
    } while (iVar3 < piVar2[8]);
  }
  switch(piVar2[10]) {
  case 1:
    piVar2[0x19] = 1;
    break;
  case 2:
  case 3:
    piVar2[0x19] = 3;
    break;
  case 4:
  case 5:
    piVar2[0x19] = 4;
    break;
  default:
    piVar2[0x19] = piVar2[8];
  }
  iVar3 = 1;
  if (*(char *)((int)piVar2 + 0x4a) == '\0') {
    iVar3 = piVar2[0x19];
  }
  piVar2[0x1a] = iVar3;
  uVar5 = FUN_1003dfb0((int)piVar2);
  if ((char)uVar5 == '\0') {
    piVar2[0x1b] = 1;
    return;
  }
  piVar2[0x1b] = piVar2[0x44];
  return;
}



