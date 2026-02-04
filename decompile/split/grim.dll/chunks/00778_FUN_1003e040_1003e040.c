/* FUN_1003e040 @ 1003e040 */

void __cdecl FUN_1003e040(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  piVar3 = param_1;
  puVar4 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x1c);
  param_1[0x5f] = (int)puVar4;
  *puVar4 = FUN_1003e2d0;
  puVar4[1] = &LAB_1003e430;
  *(undefined1 *)(puVar4 + 2) = 0;
  iVar2 = param_1[0x5f];
  FUN_1003dd90(param_1);
  puVar5 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x580);
  iVar6 = 0;
  param_1[0x47] = (int)(puVar5 + 0x40);
  puVar4 = puVar5;
  for (iVar8 = 0x40; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  do {
    *(char *)(iVar6 + (int)(puVar5 + 0x40)) = (char)iVar6;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x100);
  puVar4 = puVar5 + 0x80;
  for (iVar6 = 0x60; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar4 = 0xffffffff;
    puVar4 = puVar4 + 1;
  }
  puVar4 = puVar5 + 0xe0;
  for (iVar6 = 0x60; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)param_1[0x47];
  puVar5 = puVar5 + 0x140;
  for (iVar6 = 0x20; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)(iVar2 + 0xc) = 0;
  uVar7 = FUN_1003dfb0((int)param_1);
  *(char *)(iVar2 + 0x10) = (char)uVar7;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  *(undefined4 *)(iVar2 + 0x18) = 0;
  if ((*(char *)((int)param_1 + 0x4a) == '\0') || ((char)param_1[0x10] == '\0')) {
    *(undefined1 *)(param_1 + 0x16) = 0;
    *(undefined1 *)((int)param_1 + 0x59) = 0;
    *(undefined1 *)((int)param_1 + 0x5a) = 0;
  }
  if (*(char *)((int)param_1 + 0x4a) != '\0') {
    if (*(char *)((int)param_1 + 0x41) != '\0') {
      *(undefined4 *)(*param_1 + 0x14) = 0x2e;
      (**(code **)*param_1)(param_1);
    }
    if (param_1[0x19] == 3) {
      if (param_1[0x1d] == 0) {
        if ((char)param_1[0x14] == '\0') {
          *(undefined1 *)(param_1 + 0x16) = 1;
        }
        else {
          *(undefined1 *)((int)param_1 + 0x5a) = 1;
        }
      }
      else {
        *(undefined1 *)((int)param_1 + 0x59) = 1;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x16) = 1;
      *(undefined1 *)((int)param_1 + 0x59) = 0;
      *(undefined1 *)((int)param_1 + 0x5a) = 0;
      param_1[0x1d] = 0;
    }
    if ((char)param_1[0x16] != '\0') {
      FUN_10044210(param_1);
      *(int *)(iVar2 + 0x14) = param_1[0x69];
    }
    if ((*(char *)((int)param_1 + 0x5a) != '\0') || (*(char *)((int)param_1 + 0x59) != '\0')) {
      FUN_10042ea0(param_1);
      *(int *)(iVar2 + 0x18) = param_1[0x69];
    }
  }
  if (*(char *)((int)param_1 + 0x41) == '\0') {
    if (*(char *)(iVar2 + 0x10) == '\0') {
      FUN_10042310(param_1);
      FUN_10041ba0(param_1);
    }
    else {
      FUN_100428e0((int)param_1);
    }
    FUN_10041850((int)param_1,*(char *)((int)param_1 + 0x5a));
  }
  FUN_10041590(param_1);
  if (*(char *)((int)param_1 + 0xc9) == '\0') {
    if ((char)param_1[0x32] == '\0') {
      FUN_10040070((int)param_1);
    }
    else {
      FUN_100406a0((int)param_1);
    }
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 1;
    (**(code **)*param_1)(param_1);
  }
  if ((*(char *)(param_1[99] + 0x10) != '\0') ||
     (piVar1 = param_1 + 0x10, param_1._0_1_ = '\0', (char)*piVar1 != '\0')) {
    param_1._0_1_ = '\x01';
  }
  FUN_1003ec50((int)piVar3,(char)param_1);
  if (*(char *)((int)piVar3 + 0x41) == '\0') {
    FUN_1003e570(piVar3,'\0');
  }
  (**(code **)(piVar3[1] + 0x18))(piVar3);
  (**(code **)(piVar3[99] + 8))(piVar3);
  if (((piVar3[2] != 0) && ((char)piVar3[0x10] == '\0')) && (*(char *)(piVar3[99] + 0x10) != '\0'))
  {
    iVar6 = piVar3[8];
    if ((char)piVar3[0x32] != '\0') {
      iVar6 = iVar6 * 3 + 2;
    }
    *(undefined4 *)(piVar3[2] + 4) = 0;
    *(int *)(piVar3[2] + 8) = piVar3[0x46] * iVar6;
    *(undefined4 *)(piVar3[2] + 0xc) = 0;
    *(uint *)(piVar3[2] + 0x10) = (*(char *)((int)piVar3 + 0x5a) != '\0') + 2;
    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;
  }
  return;
}



