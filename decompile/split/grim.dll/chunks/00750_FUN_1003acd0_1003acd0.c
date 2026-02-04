/* FUN_1003acd0 @ 1003acd0 */

void __cdecl FUN_1003acd0(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x18);
  *(undefined4 **)(param_1 + 0x18c) = puVar1;
  *puVar1 = &LAB_1003afc0;
  puVar1[1] = FUN_1003b520;
  puVar1[2] = &LAB_1003ad20;
  puVar1[3] = &LAB_1003afa0;
  *(undefined1 *)(puVar1 + 4) = 0;
  *(undefined1 *)((int)puVar1 + 0x11) = 0;
  *(undefined1 *)(puVar1 + 5) = 1;
  return;
}



