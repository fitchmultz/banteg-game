/* FUN_1003b770 @ 1003b770 */

void __cdecl FUN_1003b770(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x5c);
  *(undefined4 **)(param_1 + 400) = puVar1;
  *puVar1 = &LAB_1003d090;
  *(undefined1 **)(*(int *)(param_1 + 400) + 4) = &LAB_1003bd30;
  *(code **)(*(int *)(param_1 + 400) + 8) = FUN_1003d000;
  *(code **)(*(int *)(param_1 + 400) + 0xc) = FUN_1003bc90;
  iVar2 = 0x10;
  do {
    *(code **)(*(int *)(param_1 + 400) + iVar2) = FUN_1003bc90;
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x50);
  *(undefined1 **)(*(int *)(param_1 + 400) + 0x10) = &LAB_1003b820;
  *(undefined1 **)(*(int *)(param_1 + 400) + 0x48) = &LAB_1003bac0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x178) = 0;
  *(undefined1 *)(*(int *)(param_1 + 400) + 0x50) = 0;
  *(undefined1 *)(*(int *)(param_1 + 400) + 0x51) = 0;
  *(undefined4 *)(*(int *)(param_1 + 400) + 0x58) = 0;
  return;
}



