/* FUN_10042310 @ 10042310 */

void __cdecl FUN_10042310(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x18);
  param_1[0x68] = (int)puVar1;
  *puVar1 = &DAT_1003ab00;
  switch(param_1[9]) {
  case 1:
    if (param_1[8] != 1) {
LAB_1004237b:
      *(undefined4 *)(*param_1 + 0x14) = 8;
      (**(code **)*param_1)(param_1);
    }
    break;
  case 2:
  case 3:
    if (param_1[8] != 3) {
      *(undefined4 *)(*param_1 + 0x14) = 8;
      (**(code **)*param_1)(param_1);
    }
    break;
  case 4:
  case 5:
    if (param_1[8] != 4) {
      *(undefined4 *)(*param_1 + 0x14) = 8;
      (**(code **)*param_1)(param_1);
    }
    break;
  default:
    if (param_1[8] < 1) goto LAB_1004237b;
  }
  iVar2 = param_1[10];
  if (iVar2 == 1) {
    param_1[0x19] = 1;
    if ((param_1[9] == 1) || (param_1[9] == 3)) {
      puVar1[1] = &LAB_10042750;
      iVar2 = 1;
      if (1 < param_1[8]) {
        iVar3 = 0x54;
        do {
          *(undefined1 *)(param_1[0x31] + 0x30 + iVar3) = 0;
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x54;
        } while (iVar2 < param_1[8]);
      }
      goto LAB_10042498;
    }
  }
  else {
    if (iVar2 == 2) {
      param_1[0x19] = 3;
      if (param_1[9] == 3) {
        puVar1[1] = &LAB_10042590;
        FUN_100424d0((int)param_1);
      }
      else if (param_1[9] == 2) {
        puVar1[1] = FUN_100426c0;
      }
      else {
        *(undefined4 *)(*param_1 + 0x14) = 0x19;
        (**(code **)*param_1)(param_1);
      }
      goto LAB_10042498;
    }
    if (iVar2 == 4) {
      param_1[0x19] = 4;
      if (param_1[9] == 5) {
        puVar1[1] = &LAB_10042780;
        FUN_100424d0((int)param_1);
      }
      else if (param_1[9] == 4) {
        puVar1[1] = FUN_100426c0;
      }
      else {
        *(undefined4 *)(*param_1 + 0x14) = 0x19;
        (**(code **)*param_1)(param_1);
      }
      goto LAB_10042498;
    }
    if (iVar2 == param_1[9]) {
      param_1[0x19] = param_1[8];
      puVar1[1] = FUN_100426c0;
      goto LAB_10042498;
    }
  }
  *(undefined4 *)(*param_1 + 0x14) = 0x19;
  (**(code **)*param_1)(param_1);
LAB_10042498:
  if (*(char *)((int)param_1 + 0x4a) == '\0') {
    param_1[0x1a] = param_1[0x19];
    return;
  }
  param_1[0x1a] = 1;
  return;
}



