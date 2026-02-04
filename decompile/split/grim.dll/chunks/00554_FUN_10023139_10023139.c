/* FUN_10023139 @ 10023139 */

void __cdecl FUN_10023139(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x18);
  *(undefined4 **)(param_1 + 0x18c) = puVar1;
  *(undefined1 *)(puVar1 + 4) = 0;
  *(undefined1 *)((int)puVar1 + 0x11) = 0;
  *puVar1 = &LAB_1002305e;
  puVar1[1] = FUN_100230f1;
  puVar1[2] = FUN_10023024;
  puVar1[3] = &LAB_10023128;
  *(undefined1 *)(puVar1 + 5) = 1;
  return;
}



