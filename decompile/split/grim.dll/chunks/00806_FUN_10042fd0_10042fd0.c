/* FUN_10042fd0 @ 10042fd0 */

void __cdecl FUN_10042fd0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  
  iVar3 = *(int *)(param_1 + 0x1a4);
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x7fc);
  piVar2 = (int *)(iVar1 + 0x3fc);
  iVar6 = 0x10;
  *(int **)(iVar3 + 0x28) = piVar2;
  iVar3 = 0;
  iVar5 = 0;
  uVar4 = 0x10;
  piVar7 = piVar2;
  piVar8 = piVar2;
  do {
    *piVar7 = iVar3;
    *piVar8 = iVar5;
    piVar7 = piVar7 + 1;
    piVar8 = piVar8 + -1;
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + -1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  piVar7 = (int *)(iVar1 + 0x43c);
  piVar8 = (int *)(iVar1 + 0x3bc);
  do {
    *piVar7 = iVar3;
    *piVar8 = -iVar3;
    uVar4 = uVar4 + 1;
    piVar7 = piVar7 + 1;
    piVar8 = piVar8 + -1;
    iVar3 = iVar3 + (~uVar4 & 1);
  } while ((int)uVar4 < 0x30);
  if ((int)uVar4 < 0x100) {
    piVar7 = piVar2 + uVar4;
    piVar2 = piVar2 + -uVar4;
    iVar1 = 0x100 - uVar4;
    do {
      *piVar7 = iVar3;
      *piVar2 = -iVar3;
      piVar7 = piVar7 + 1;
      piVar2 = piVar2 + -1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}



