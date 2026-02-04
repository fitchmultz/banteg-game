/* FUN_10044210 @ 10044210 */

void __cdecl FUN_10044210(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int iStack_28;
  int *piStack_20;
  int iStack_1c;
  int iStack_14;
  
  piVar3 = param_1;
  puVar4 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x58);
  param_1[0x69] = (int)puVar4;
  *puVar4 = &LAB_10044690;
  puVar4[2] = &DAT_1003ab00;
  puVar4[3] = &LAB_10044e30;
  puVar4[0x11] = 0;
  puVar4[0xd] = 0;
  if (4 < param_1[0x19]) {
    *(undefined4 *)(*param_1 + 0x14) = 0x36;
    *(undefined4 *)(*param_1 + 0x18) = 4;
    (**(code **)*param_1)(param_1);
  }
  if (0x100 < param_1[0x15]) {
    *(undefined4 *)(*param_1 + 0x14) = 0x38;
    *(undefined4 *)(*param_1 + 0x18) = 0x100;
    (**(code **)*param_1)(param_1);
  }
  iVar2 = param_1[0x69];
  iVar5 = FUN_10044450(param_1,(int *)(iVar2 + 0x20));
  if (param_1[0x19] == 3) {
    iVar13 = *param_1;
    *(int *)(iVar13 + 0x18) = iVar5;
    *(int *)(iVar13 + 0x1c) = *(int *)(iVar2 + 0x20);
    *(undefined4 *)(iVar13 + 0x20) = *(undefined4 *)(iVar2 + 0x24);
    *(undefined4 *)(iVar13 + 0x24) = *(undefined4 *)(iVar2 + 0x28);
    *(undefined4 *)(*param_1 + 0x14) = 0x5d;
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 0x5e;
    *(int *)(*param_1 + 0x18) = iVar5;
  }
  (**(code **)(*param_1 + 4))(param_1,1);
  piVar6 = (int *)(**(code **)(param_1[1] + 8))(param_1,1,iVar5,param_1[0x19]);
  iStack_14 = 0;
  if (0 < param_1[0x19]) {
    piStack_20 = (int *)(iVar2 + 0x20);
    piVar11 = piVar6;
    iVar13 = iVar5;
    do {
      iStack_1c = *piStack_20;
      iVar7 = iVar13 / iStack_1c;
      if (0 < iStack_1c) {
        iVar1 = iStack_1c + -1;
        iStack_28 = 0;
        param_1 = (int *)0x0;
        do {
          for (iVar10 = iStack_28; iVar10 < iVar5; iVar10 = iVar10 + iVar13) {
            iVar9 = 0;
            if (0 < iVar7) {
              do {
                iVar12 = *piVar11 + iVar9;
                iVar9 = iVar9 + 1;
                *(char *)(iVar10 + iVar12) = (char)((iVar1 / 2 + (int)param_1) / iVar1);
              } while (iVar9 < iVar7);
            }
          }
          param_1 = (int *)((int)param_1 + 0xff);
          iStack_28 = iStack_28 + iVar7;
          iStack_1c = iStack_1c + -1;
        } while (iStack_1c != 0);
      }
      piStack_20 = piStack_20 + 1;
      iStack_14 = iStack_14 + 1;
      piVar11 = piVar11 + 1;
      iVar13 = iVar7;
    } while (iStack_14 < piVar3[0x19]);
  }
  *(int **)(iVar2 + 0x10) = piVar6;
  *(int *)(iVar2 + 0x14) = iVar5;
  FUN_10044540((int)piVar3);
  if (piVar3[0x13] == 2) {
    iVar2 = piVar3[0x17];
    iVar5 = 0;
    if (0 < piVar3[0x19]) {
      puVar4 = (undefined4 *)(piVar3[0x69] + 0x44);
      do {
        uVar8 = (**(code **)(piVar3[1] + 4))(piVar3,1,iVar2 * 2 + 4);
        *puVar4 = uVar8;
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar5 < piVar3[0x19]);
    }
  }
  return;
}



