/* FUN_1003247d @ 1003247d */

void __cdecl FUN_1003247d(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x30);
  *(undefined4 **)(param_1 + 0x19c) = puVar1;
  *(undefined1 *)(puVar1 + 2) = 0;
  *puVar1 = &LAB_10032055;
  puVar1[10] = *(int *)(param_1 + 100) * *(int *)(param_1 + 0x5c);
  if (*(int *)(param_1 + 0x110) == 2) {
    puVar1[1] = FUN_1003206a;
    puVar1[3] = FUN_10032297;
    uVar2 = (**(code **)(*(int *)(param_1 + 4) + 4))(param_1,1,puVar1[10]);
    puVar1[8] = uVar2;
  }
  else {
    puVar1[8] = 0;
    puVar1[1] = FUN_10032110;
    puVar1[3] = FUN_10032141;
  }
  FUN_10031fa5();
  return;
}



