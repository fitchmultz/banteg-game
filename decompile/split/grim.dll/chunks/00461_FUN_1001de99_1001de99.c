/* FUN_1001de99 @ 1001de99 */

void __cdecl FUN_1001de99(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x5c);
  *(undefined4 **)(param_1 + 400) = puVar1;
  *puVar1 = FUN_1001de6f;
  *(undefined1 **)(*(int *)(param_1 + 400) + 4) = &LAB_1001db15;
  *(code **)(*(int *)(param_1 + 400) + 8) = FUN_1001dd02;
  *(code **)(*(int *)(param_1 + 400) + 0xc) = FUN_1001d90b;
  iVar2 = 0x10;
  do {
    *(code **)(iVar2 + *(int *)(param_1 + 400)) = FUN_1001d90b;
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x50);
  *(code **)(*(int *)(param_1 + 400) + 0x10) = FUN_1001ce6a;
  *(code **)(*(int *)(param_1 + 400) + 0x48) = FUN_1001d0a6;
  FUN_1001de6f(param_1);
  return;
}



