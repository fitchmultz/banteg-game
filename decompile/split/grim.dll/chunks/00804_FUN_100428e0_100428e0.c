/* FUN_100428e0 @ 100428e0 */

void __cdecl FUN_100428e0(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x30);
  *(undefined4 **)(param_1 + 0x19c) = puVar1;
  *puVar1 = &LAB_10042a10;
  *(undefined1 *)(puVar1 + 2) = 0;
  iVar4 = *(int *)(param_1 + 100) * *(int *)(param_1 + 0x5c);
  puVar1[10] = iVar4;
  if (*(int *)(param_1 + 0x110) == 2) {
    puVar1[1] = &LAB_10042a30;
    puVar1[3] = &LAB_10042c90;
    uVar2 = (**(code **)(*(int *)(param_1 + 4) + 4))(param_1,1,iVar4);
    puVar1[8] = uVar2;
  }
  else {
    puVar1[1] = &LAB_10042b00;
    puVar1[3] = &LAB_10042b40;
    puVar1[8] = 0;
  }
  iVar4 = *(int *)(param_1 + 0x19c);
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar4 + 0x10) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar4 + 0x14) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar4 + 0x18) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar4 + 0x1c) = uVar2;
  iVar3 = 0;
  param_1 = 0x5b6900;
  iVar7 = -0xe25100;
  iVar6 = -0xb2f480;
  iVar5 = 0x2c8d00;
  do {
    *(int *)(iVar3 + *(int *)(iVar4 + 0x10)) = iVar6 >> 0x10;
    *(int *)(iVar3 + *(int *)(iVar4 + 0x14)) = iVar7 >> 0x10;
    *(int *)(iVar3 + *(int *)(iVar4 + 0x18)) = param_1;
    *(int *)(iVar3 + *(int *)(iVar4 + 0x1c)) = iVar5;
    param_1 = param_1 + -0xb6d2;
    iVar5 = iVar5 + -0x581a;
    iVar6 = iVar6 + 0x166e9;
    iVar7 = iVar7 + 0x1c5a2;
    iVar3 = iVar3 + 4;
  } while (-0x2b34e7 < iVar5);
  return;
}



