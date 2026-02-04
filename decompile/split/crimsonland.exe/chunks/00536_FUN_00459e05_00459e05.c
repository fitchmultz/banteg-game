/* FUN_00459e05 @ 00459e05 */

void FUN_00459e05(undefined8 *param_1,undefined8 *param_2)

{
  undefined4 extraout_MM0_Da;
  ulonglong extraout_MM0;
  undefined8 uVar1;
  ulonglong uVar2;
  undefined4 uVar4;
  undefined8 uVar3;
  undefined8 in_MM4;
  undefined8 uVar5;
  
  FastExitMediaState();
  uVar1 = *param_2;
  uVar2 = param_2[1];
  uVar4 = (undefined4)(uVar2 >> 0x20);
  uVar3 = PackedFloatingCompareGE(CONCAT44(uVar4,uVar4),0x3f8000003f800000);
  if ((int)uVar3 == 0) {
    math_acos_packed();
    math_sin_packed();
    uVar3 = PackedFloatingCompareGE(extraout_MM0 & 0x7fffffff7fffffff,0x3400000034000000);
    uVar1 = *param_2;
    uVar2 = param_2[1];
    if ((int)uVar3 != 0) {
      uVar5 = FloatingReciprocalAprox(in_MM4,extraout_MM0);
      uVar3 = PackedFloatingReciprocalIter1(extraout_MM0,uVar5);
      uVar3 = PackedFloatingReciprocalIter2(uVar3,uVar5);
      uVar3 = PackedFloatingMUL(CONCAT44(extraout_MM0_Da,extraout_MM0_Da),uVar3);
      uVar1 = PackedFloatingMUL(uVar1,uVar3);
      uVar2 = PackedFloatingMUL(uVar2,uVar3);
    }
  }
  *param_1 = uVar1;
  param_1[1] = uVar2 & 0xffffffff;
  FastExitMediaState();
  return;
}



