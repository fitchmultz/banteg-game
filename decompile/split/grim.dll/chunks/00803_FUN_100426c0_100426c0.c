/* FUN_100426c0 @ 100426c0 */

void __cdecl FUN_100426c0(int param_1,int *param_2,int param_3,int *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = *(int *)(param_1 + 0x20);
  iVar2 = *(int *)(param_1 + 0x5c);
  if (-1 < param_5 + -1) {
    param_1 = param_3 << 2;
    do {
      iVar6 = 0;
      piVar5 = param_2;
      if (0 < iVar1) {
        do {
          puVar4 = *(undefined1 **)(*piVar5 + param_1);
          puVar3 = (undefined1 *)(*param_4 + iVar6);
          for (iVar7 = iVar2; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar3 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar3 = puVar3 + iVar1;
          }
          iVar6 = iVar6 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar6 < iVar1);
      }
      param_1 = param_1 + 4;
      param_4 = param_4 + 1;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  return;
}



