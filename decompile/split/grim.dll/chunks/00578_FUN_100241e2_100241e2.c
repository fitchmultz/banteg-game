/* FUN_100241e2 @ 100241e2 */

void __cdecl FUN_100241e2(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x1c);
  *(undefined4 **)(param_1 + 0x17c) = puVar1;
  *(undefined1 *)(puVar1 + 2) = 0;
  *puVar1 = &LAB_10024094;
  puVar1[1] = &LAB_100241c1;
  FUN_10023ee7();
  return;
}



