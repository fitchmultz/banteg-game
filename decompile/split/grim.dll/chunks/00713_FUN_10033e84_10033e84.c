/* FUN_10033e84 @ 10033e84 */

void __cdecl FUN_10033e84(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x58);
  param_1[0x69] = (int)puVar1;
  puVar1[0x11] = 0;
  puVar1[0xd] = 0;
  *puVar1 = FUN_10033da6;
  puVar1[2] = &DAT_10010dec;
  puVar1[3] = &LAB_10033e70;
  if (4 < param_1[0x19]) {
    *(undefined4 *)(*param_1 + 0x14) = 0x36;
    *(undefined4 *)(*param_1 + 0x18) = 4;
    (**(code **)*param_1)(param_1);
  }
  if (0x100 < param_1[0x15]) {
    *(undefined4 *)(*param_1 + 0x14) = 0x38;
    *(undefined4 *)(*param_1 + 0x18) = 0x100;
    (**(code **)*param_1)(param_1);
  }
  FUN_100335d0();
  FUN_100336fd((int)param_1);
  if (param_1[0x13] == 2) {
    FUN_10033d70();
  }
  return;
}



