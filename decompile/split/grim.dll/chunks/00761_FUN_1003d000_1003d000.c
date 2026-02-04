/* FUN_1003d000 @ 1003d000 */

uint __cdecl FUN_1003d000(int *param_1)

{
  uint uVar1;
  
  if (param_1[0x5e] == 0) {
    uVar1 = FUN_1003b660(param_1);
    if ((char)uVar1 == '\0') {
      return uVar1;
    }
  }
  if (param_1[0x5e] == *(int *)(param_1[100] + 0x54) + 0xd0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x61;
    *(undefined4 *)(*param_1 + 0x18) = *(undefined4 *)(param_1[100] + 0x54);
    uVar1 = (**(code **)(*param_1 + 4))(param_1,3);
    param_1[0x5e] = 0;
  }
  else {
    uVar1 = (**(code **)(param_1[5] + 0x14))(param_1,*(int *)(param_1[100] + 0x54));
    if ((char)uVar1 == '\0') {
      return uVar1;
    }
  }
  *(uint *)(param_1[100] + 0x54) = *(int *)(param_1[100] + 0x54) + 1U & 7;
  return CONCAT31((int3)(uVar1 >> 8),1);
}



