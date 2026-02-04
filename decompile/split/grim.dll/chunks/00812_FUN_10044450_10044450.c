/* FUN_10044450 @ 10044450 */

int __cdecl FUN_10044450(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piStack_c;
  
  iVar2 = param_1[0x19];
  iVar3 = param_1[0x15];
  iVar8 = 1;
  do {
    iVar7 = iVar8;
    iVar8 = iVar7 + 1;
    iVar5 = iVar8;
    if (1 < iVar2) {
      iVar6 = iVar2 + -1;
      do {
        iVar5 = iVar5 * iVar8;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  } while (iVar5 <= iVar3);
  if (iVar7 < 2) {
    *(undefined4 *)(*param_1 + 0x14) = 0x37;
    *(int *)(*param_1 + 0x18) = iVar5;
    (**(code **)*param_1)(param_1);
  }
  iVar5 = 1;
  iVar8 = iVar2;
  piVar9 = param_2;
  if (0 < iVar2) {
    for (; iVar6 = iVar2, iVar8 != 0; iVar8 = iVar8 + -1) {
      *piVar9 = iVar7;
      piVar9 = piVar9 + 1;
    }
    do {
      iVar5 = iVar5 * iVar7;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  do {
    iVar8 = 0;
    bVar4 = false;
    if (iVar2 < 1) {
      return iVar5;
    }
    piStack_c = &DAT_10050950;
    iVar7 = iVar5;
    do {
      iVar6 = iVar8;
      if (param_1[10] == 2) {
        iVar6 = *piStack_c;
      }
      iVar1 = param_2[iVar6] + 1;
      iVar5 = (iVar7 / param_2[iVar6]) * iVar1;
      if (iVar5 - iVar3 != 0 && iVar3 <= iVar5) {
        iVar5 = iVar7;
        if (!bVar4) {
          return iVar7;
        }
        break;
      }
      param_2[iVar6] = iVar1;
      iVar8 = iVar8 + 1;
      piStack_c = piStack_c + 1;
      bVar4 = true;
      iVar7 = iVar5;
    } while (iVar8 < iVar2);
  } while( true );
}



