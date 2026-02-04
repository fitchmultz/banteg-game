/* FUN_1003e570 @ 1003e570 */

void __cdecl FUN_1003e570(int *param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  puVar2 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x50);
  param_1[0x60] = (int)puVar2;
  *puVar2 = &LAB_1003e6f0;
  if (param_2 != '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 4;
    (**(code **)*param_1)(param_1);
  }
  if (*(char *)(param_1[0x67] + 8) == '\0') {
    _param_2 = param_1[0x45];
  }
  else {
    if (param_1[0x45] < 2) {
      *(undefined4 *)(*param_1 + 0x14) = 0x2e;
      (**(code **)*param_1)(param_1);
    }
    iVar8 = param_1[0x60];
    iVar1 = param_1[0x45];
    iVar3 = (**(code **)param_1[1])(param_1,1,param_1[8] << 3);
    *(int *)(iVar8 + 0x38) = iVar3;
    *(int *)(iVar8 + 0x3c) = iVar3 + param_1[8] * 4;
    iVar3 = 0;
    if (0 < param_1[8]) {
      piVar7 = (int *)(param_1[0x31] + 0xc);
      do {
        iVar4 = (piVar7[6] * *piVar7) / param_1[0x45];
        iVar9 = (iVar1 + 4) * iVar4;
        iVar5 = (**(code **)param_1[1])(param_1,1,iVar9 * 8);
        iVar5 = iVar5 + iVar4 * 4;
        *(int *)(*(int *)(iVar8 + 0x38) + iVar3 * 4) = iVar5;
        *(int *)(*(int *)(iVar8 + 0x3c) + iVar3 * 4) = iVar5 + iVar9 * 4;
        iVar3 = iVar3 + 1;
        piVar7 = piVar7 + 0x15;
      } while (iVar3 < param_1[8]);
    }
    _param_2 = param_1[0x45] + 2;
  }
  iVar8 = 0;
  if (0 < param_1[8]) {
    piVar7 = (int *)(param_1[0x31] + 0x24);
    puVar2 = puVar2 + 2;
    do {
      uVar6 = (**(code **)(param_1[1] + 8))
                        (param_1,1,piVar7[-2] * *piVar7,
                         ((piVar7[-6] * *piVar7) / param_1[0x45]) * _param_2);
      *puVar2 = uVar6;
      iVar8 = iVar8 + 1;
      puVar2 = puVar2 + 1;
      piVar7 = piVar7 + 0x15;
    } while (iVar8 < param_1[8]);
  }
  return;
}



