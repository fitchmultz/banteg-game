/* FUN_100424d0 @ 100424d0 */

void __cdecl FUN_100424d0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = *(int *)(param_1 + 0x1a0);
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar1 + 8) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar1 + 0xc) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar1 + 0x10) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar1 + 0x14) = uVar2;
  iVar3 = 0;
  param_1 = 0x5b6900;
  iVar6 = -0xe25100;
  iVar5 = -0xb2f480;
  iVar4 = 0x2c8d00;
  do {
    *(int *)(iVar3 + *(int *)(iVar1 + 8)) = iVar5 >> 0x10;
    *(int *)(iVar3 + *(int *)(iVar1 + 0xc)) = iVar6 >> 0x10;
    *(int *)(iVar3 + *(int *)(iVar1 + 0x10)) = param_1;
    *(int *)(iVar3 + *(int *)(iVar1 + 0x14)) = iVar4;
    param_1 = param_1 + -0xb6d2;
    iVar4 = iVar4 + -0x581a;
    iVar5 = iVar5 + 0x166e9;
    iVar6 = iVar6 + 0x1c5a2;
    iVar3 = iVar3 + 4;
  } while (-0x2b34e7 < iVar4);
  return;
}



