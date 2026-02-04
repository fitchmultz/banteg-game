/* FUN_10009fa0 @ 10009fa0 */

uint __cdecl FUN_10009fa0(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x10) != 0xcc) {
    (*(code *)**(undefined4 **)(param_1 + 0x17c))(param_1);
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xcc;
  }
  if (*(char *)(*(int *)(param_1 + 0x17c) + 8) != '\0') {
    puVar1 = (uint *)(param_1 + 0x78);
    do {
      uVar3 = *puVar1;
      if (uVar3 < *(uint *)(param_1 + 0x60)) {
        do {
          if (*(int *)(param_1 + 8) != 0) {
            *(uint *)(*(int *)(param_1 + 8) + 4) = uVar3;
            *(undefined4 *)(*(int *)(param_1 + 8) + 8) = *(undefined4 *)(param_1 + 0x60);
            (*(code *)**(undefined4 **)(param_1 + 8))(param_1);
          }
          uVar2 = *puVar1;
          (**(code **)(*(int *)(param_1 + 0x180) + 4))(param_1,0,puVar1,0);
          uVar3 = *puVar1;
          if (uVar3 == uVar2) {
            return uVar3 & 0xffffff00;
          }
        } while (uVar3 < *(uint *)(param_1 + 0x60));
      }
      (**(code **)(*(int *)(param_1 + 0x17c) + 4))(param_1);
      (*(code *)**(undefined4 **)(param_1 + 0x17c))(param_1);
      *puVar1 = 0;
    } while (*(char *)(*(int *)(param_1 + 0x17c) + 8) != '\0');
  }
  iVar4 = (*(char *)(param_1 + 0x41) != '\0') + 0xcd;
  *(int *)(param_1 + 0x10) = iVar4;
  return CONCAT31((int3)((uint)iVar4 >> 8),1);
}



