/* FUN_1003b520 @ 1003b520 */

void __cdecl FUN_1003b520(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[99];
  *puVar1 = &LAB_1003afc0;
  *(undefined1 *)(puVar1 + 4) = 0;
  *(undefined1 *)((int)puVar1 + 0x11) = 0;
  *(undefined1 *)(puVar1 + 5) = 1;
  (**(code **)(*param_1 + 0x10))(param_1);
  (**(code **)param_1[100])(param_1);
  param_1[0x23] = 0;
  return;
}



