/* FUN_00459b4b @ 00459b4b */

void FUN_00459b4b(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,uint param_4)

{
  undefined4 uVar1;
  uint extraout_MM0_Da;
  ulonglong extraout_MM0;
  undefined8 extraout_MM0_00;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar2;
  
  FastExitMediaState();
  uVar3 = PackedFloatingMUL(*param_2,*param_3);
  uVar5 = PackedFloatingMUL(param_2[1],param_3[1]);
  uVar3 = PackedFloatingADD(uVar3,uVar5);
  uVar2 = PackedFloatingSUB(0x3f800000,(ulonglong)param_4);
  uVar1 = (undefined4)uVar2;
  uVar4 = PackedFloatingAccumulate(uVar3,uVar3);
  uVar9 = PackedFloatingCompareGE(0,uVar4);
  uVar10 = uVar9 & 0x8000000080000000;
  uVar4 = uVar4 ^ uVar10;
  uVar5 = PackedFloatingCompareGE(0x3f7fff583f7fff58,uVar4);
  uVar3 = PackedFloatingMUL(uVar4,uVar4);
  uVar3 = PackedFloatingSUBR(uVar3,0x3f8000003f800000);
  if ((int)uVar5 != 0) {
    uVar7 = PackedFloatingReciprocalSQRAprox((ulonglong)param_4,uVar3);
    uVar5 = PackedFloatingMUL(uVar7,uVar7);
    uVar3 = PackedFloatingReciprocalSQRIter1(uVar3,uVar5);
    uVar4 = PackedFloatingReciprocalIter2(uVar3,uVar7);
    uVar3 = FloatingReciprocalAprox(uVar5,uVar4);
    uVar5 = PackedFloatingReciprocalIter1(uVar4,uVar3);
    PackedFloatingReciprocalIter2(uVar5,uVar3);
    math_atan2_packed();
    PackedFloatingMUL(extraout_MM0,(ulonglong)param_4);
    math_sin_packed();
    PackedFloatingMUL(extraout_MM0 & 0xffffffff,uVar2 & 0xffffffff);
    math_sin_packed();
    uVar10 = uVar9 & 0x80000000;
    uVar3 = PackedFloatingMUL(extraout_MM0_00,uVar4 & 0xffffffff);
    uVar1 = (undefined4)uVar3;
    uVar3 = PackedFloatingMUL((ulonglong)extraout_MM0_Da,uVar4 & 0xffffffff);
    param_4 = (uint)uVar3;
  }
  uVar6 = param_4 ^ (uint)uVar10;
  uVar5 = CONCAT44(uVar6,uVar6);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),*param_2);
  uVar7 = PackedFloatingMUL(uVar5,*param_3);
  uVar8 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),param_2[1]);
  uVar5 = PackedFloatingMUL(uVar5,param_3[1]);
  uVar3 = PackedFloatingADD(uVar3,uVar7);
  uVar5 = PackedFloatingADD(uVar8,uVar5);
  *param_1 = uVar3;
  param_1[1] = uVar5;
  FastExitMediaState();
  return;
}



