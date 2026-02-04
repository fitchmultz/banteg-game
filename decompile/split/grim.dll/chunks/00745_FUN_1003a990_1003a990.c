/* FUN_1003a990 @ 1003a990 */

void __cdecl FUN_1003a990(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x30);
    *(int *)(param_1 + 0x14) = iVar2;
    uVar3 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x1000);
    *(undefined4 *)(iVar2 + 0x28) = uVar3;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x14);
  puVar1[2] = &LAB_1003aa10;
  puVar1[3] = FUN_1003aa20;
  puVar1[4] = FUN_1003aac0;
  puVar1[5] = &LAB_1003b560;
  puVar1[6] = &DAT_1003ab00;
  puVar1[7] = param_2;
  puVar1[8] = param_3;
  puVar1[9] = 0;
  puVar1[1] = 0;
  *puVar1 = 0;
  return;
}



