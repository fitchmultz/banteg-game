/* FUN_10046400 @ 10046400 */

uint __cdecl FUN_10046400(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int local_38;
  undefined4 local_34;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_18;
  undefined4 local_14;
  
  local_34 = param_4;
  local_38 = param_3;
  local_28 = *param_2;
  local_2c = param_1;
  local_18 = 0;
  local_14 = 0;
  uVar1 = FUN_100475b0((int)&local_38,s_1_1_3_1005820c,0x38);
  if (uVar1 == 0) {
    uVar2 = FUN_100475d0(&local_38,4);
    if (uVar2 == 1) {
      *param_2 = local_24;
      uVar1 = FUN_100473f0((int)&local_38);
    }
    else {
      FUN_100473f0((int)&local_38);
      uVar1 = 0xfffffffb;
      if (uVar2 != 0) {
        return uVar2;
      }
    }
  }
  return uVar1;
}



