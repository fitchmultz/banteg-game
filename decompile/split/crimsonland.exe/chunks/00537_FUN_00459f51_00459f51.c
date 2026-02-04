/* FUN_00459f51 @ 00459f51 */

void FUN_00459f51(undefined8 *param_1,undefined8 *param_2,ulonglong *param_3,ulonglong *param_4,
                 ulonglong *param_5,ulonglong *param_6,ulonglong *param_7)

{
  undefined4 unaff_ESI;
  undefined4 extraout_MM0_Da;
  undefined4 extraout_MM0_Da_00;
  undefined4 extraout_MM0_Da_01;
  undefined4 extraout_MM0_Da_02;
  undefined8 uVar1;
  ulonglong extraout_MM0;
  ulonglong extraout_MM0_00;
  ulonglong extraout_MM0_01;
  ulonglong extraout_MM0_02;
  ulonglong extraout_MM0_03;
  ulonglong extraout_MM0_04;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  ulonglong local_a8;
  ulonglong local_a0;
  ulonglong local_88;
  ulonglong local_80;
  ulonglong local_78;
  ulonglong local_70;
  undefined4 local_20;
  
  local_a8 = *param_4;
  local_a0 = param_4[1];
  uVar6 = *param_5;
  uVar13 = param_5[1];
  uVar1 = PackedFloatingADD(local_a8,uVar6);
  uVar2 = PackedFloatingADD(local_a0,uVar13);
  uVar4 = PackedFloatingSUB(local_a8,uVar6);
  uVar1 = PackedFloatingMUL(uVar1,uVar1);
  uVar7 = PackedFloatingSUB(local_a0,uVar13);
  uVar2 = PackedFloatingMUL(uVar2,uVar2);
  uVar4 = PackedFloatingMUL(uVar4,uVar4);
  uVar7 = PackedFloatingMUL(uVar7,uVar7);
  uVar1 = PackedFloatingADD(uVar1,uVar2);
  uVar4 = PackedFloatingADD(uVar4,uVar7);
  local_88 = *param_6;
  local_80 = param_6[1];
  uVar9 = PackedFloatingADD(uVar6,local_88);
  uVar11 = PackedFloatingADD(uVar13,local_80);
  uVar2 = PackedFloatingSUB(uVar6,local_88);
  uVar7 = PackedFloatingSUB(uVar13,local_80);
  uVar9 = PackedFloatingMUL(uVar9,uVar9);
  uVar11 = PackedFloatingMUL(uVar11,uVar11);
  uVar2 = PackedFloatingMUL(uVar2,uVar2);
  uVar7 = PackedFloatingMUL(uVar7,uVar7);
  uVar9 = PackedFloatingADD(uVar9,uVar11);
  uVar2 = PackedFloatingADD(uVar2,uVar7);
  uVar1 = PackedFloatingAccumulate(uVar1,uVar9);
  uVar2 = PackedFloatingAccumulate(uVar4,uVar2);
  uVar1 = PackedFloatingCompareGT(uVar2,uVar1);
  uVar5 = packsswb(uVar1,uVar1);
  if ((uVar5 & 1) != 0) {
    local_a8 = *param_4 ^ 0x8000000080000000;
    local_a0 = param_4[1] ^ 0x8000000080000000;
  }
  if ((uVar5 & 0x10000) != 0) {
    local_88 = *param_6 ^ 0x8000000080000000;
    local_80 = param_6[1] ^ 0x8000000080000000;
  }
  local_78 = *param_7;
  uVar5 = param_7[1];
  uVar4 = PackedFloatingADD(local_88,local_78);
  uVar7 = PackedFloatingADD(local_80,uVar5);
  uVar1 = PackedFloatingSUB(local_88,local_78);
  uVar2 = PackedFloatingSUB(local_80,uVar5);
  uVar4 = PackedFloatingMUL(uVar4,uVar4);
  uVar7 = PackedFloatingMUL(uVar7,uVar7);
  uVar1 = PackedFloatingMUL(uVar1,uVar1);
  uVar2 = PackedFloatingMUL(uVar2,uVar2);
  uVar4 = PackedFloatingADD(uVar4,uVar7);
  uVar1 = PackedFloatingADD(uVar1,uVar2);
  uVar2 = PackedFloatingAccumulate(uVar4,uVar4);
  uVar1 = PackedFloatingAccumulate(uVar1,uVar1);
  uVar8 = PackedFloatingCompareGT(uVar1,uVar2);
  local_70 = uVar5;
  if ((uVar8 & 1) != 0) {
    local_78 = *param_7 ^ 0x8000000080000000;
    local_70 = param_7[1] ^ 0x8000000080000000;
  }
  uVar1 = PackedFloatingMUL(uVar6,uVar6);
  uVar2 = PackedFloatingMUL(uVar13,uVar13);
  uVar1 = PackedFloatingADD(uVar1,uVar2);
  uVar1 = PackedFloatingAccumulate(uVar1,uVar1);
  uVar2 = FloatingReciprocalAprox(uVar5,uVar1);
  uVar5 = PackedFloatingCompareGT(uVar1,0x80000000800000);
  uVar1 = PackedFloatingReciprocalIter1(uVar1,uVar2);
  uVar1 = PackedFloatingReciprocalIter2(uVar1,uVar2);
  uVar2 = PackedFloatingMUL((uVar6 ^ 0x8000000080000000) & uVar5,uVar1);
  uVar9 = PackedFloatingMUL((uVar13 ^ 0x80000000) & uVar5,uVar1);
  uVar8 = CONCAT44((int)local_a8,(int)(local_a8 >> 0x20));
  uVar10 = CONCAT44((int)local_a0,(int)(local_a0 >> 0x20));
  uVar5 = PackedFloatingMUL(local_a8,uVar9);
  uVar1 = PackedFloatingMUL(local_a0,uVar2);
  uVar7 = PackedFloatingMUL(uVar10 ^ 0x80000000,uVar2);
  uVar4 = PackedFloatingMUL(uVar8,uVar9);
  uVar1 = PackedFloatingADD(uVar5 ^ 0x80000000,uVar1);
  uVar4 = PackedFloatingSUB(uVar4,uVar7);
  uVar14 = PackedFloatingMUL(uVar10,uVar9);
  uVar4 = PackedFloatingAccumulate(uVar4,uVar1);
  uVar11 = PackedFloatingMUL(uVar8 ^ 0x80000000,uVar2);
  uVar1 = PackedFloatingMUL(local_a8,uVar2);
  uVar7 = PackedFloatingMUL(local_a0 ^ 0x80000000,uVar9);
  uVar11 = PackedFloatingADD(uVar11,uVar14);
  uVar1 = PackedFloatingSUB(uVar7,uVar1);
  uVar8 = PackedFloatingAccumulate(uVar11,uVar1);
  uVar10 = CONCAT44((int)local_88,(int)(local_88 >> 0x20));
  uVar12 = CONCAT44((int)local_80,(int)(local_80 >> 0x20));
  uVar5 = PackedFloatingMUL(local_88,uVar9);
  uVar1 = PackedFloatingMUL(local_80,uVar2);
  uVar11 = PackedFloatingMUL(uVar12 ^ 0x80000000,uVar2);
  uVar7 = PackedFloatingMUL(uVar10,uVar9);
  uVar1 = PackedFloatingADD(uVar5 ^ 0x80000000,uVar1);
  uVar7 = PackedFloatingSUB(uVar7,uVar11);
  uVar14 = PackedFloatingMUL(uVar12,uVar9);
  uVar7 = PackedFloatingAccumulate(uVar7,uVar1);
  uVar11 = PackedFloatingMUL(uVar10 ^ 0x80000000,uVar2);
  uVar1 = PackedFloatingMUL(local_88,uVar2);
  uVar2 = PackedFloatingMUL(local_80 ^ 0x80000000,uVar9);
  uVar9 = PackedFloatingADD(uVar11,uVar14);
  uVar1 = PackedFloatingSUB(uVar2,uVar1);
  uVar5 = PackedFloatingAccumulate(uVar9,uVar1);
  uVar3 = (undefined4)(uVar8 >> 0x20);
  uVar2 = PackedFloatingCompareGE(CONCAT44(uVar3,uVar3),0x3f8000003f800000);
  uVar1 = uVar7;
  if ((int)uVar2 == 0) {
    math_acos_packed();
    math_sin_packed();
    uVar2 = PackedFloatingCompareGE(extraout_MM0 & 0x7fffffff7fffffff,0x3400000034000000);
    if ((int)uVar2 != 0) {
      uVar1 = FloatingReciprocalAprox(uVar1,extraout_MM0);
      uVar2 = PackedFloatingReciprocalIter1(extraout_MM0,uVar1);
      uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar1);
      uVar2 = PackedFloatingMUL(CONCAT44(extraout_MM0_Da,extraout_MM0_Da),uVar2);
      uVar4 = PackedFloatingMUL(uVar4,uVar2);
      uVar8 = PackedFloatingMUL(uVar8,uVar2);
    }
  }
  uVar3 = (undefined4)(uVar5 >> 0x20);
  uVar2 = PackedFloatingCompareGE(CONCAT44(uVar3,uVar3),0x3f8000003f800000);
  if ((int)uVar2 == 0) {
    math_acos_packed();
    math_sin_packed();
    uVar2 = PackedFloatingCompareGE(extraout_MM0_00 & 0x7fffffff7fffffff,0x3400000034000000);
    if ((int)uVar2 != 0) {
      uVar2 = FloatingReciprocalAprox(uVar1,extraout_MM0_00);
      uVar1 = PackedFloatingReciprocalIter1(extraout_MM0_00,uVar2);
      uVar1 = PackedFloatingReciprocalIter2(uVar1,uVar2);
      uVar1 = PackedFloatingMUL(CONCAT44(extraout_MM0_Da_00,extraout_MM0_Da_00),uVar1);
      uVar7 = PackedFloatingMUL(uVar7,uVar1);
      uVar5 = PackedFloatingMUL(uVar5,uVar1);
    }
  }
  uVar1 = PackedFloatingADD(uVar4,uVar7);
  uVar2 = PackedFloatingADD(uVar8 & 0xffffffff,uVar5 & 0xffffffff);
  uVar1 = PackedFloatingMUL(uVar1,0xbe800000be800000);
  uVar8 = PackedFloatingMUL(uVar2,0xbe800000be800000);
  uVar2 = PackedFloatingMUL(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar8 & 0xffffffff,uVar8 & 0xffffffff);
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar4 = PackedFloatingReciprocalSQRAprox(uVar4,uVar2);
  uVar7 = PackedFloatingMUL(uVar4,uVar4);
  uVar7 = PackedFloatingReciprocalSQRIter1(uVar7,uVar2);
  uVar4 = PackedFloatingReciprocalIter2(uVar7,uVar4);
  PackedFloatingMUL(uVar2,uVar4);
  math_sincos_packed();
  uVar5 = PackedFloatingCompareGE(extraout_MM0_01 & 0x7fffffffffffffff,0x3400000034000000);
  uVar3 = (undefined4)(extraout_MM0_01 >> 0x20);
  uVar2 = PackedFloatingMUL(CONCAT44(uVar3,uVar3),CONCAT44(unaff_ESI,(int)uVar4));
  local_20 = (undefined4)uVar8;
  if ((uVar5 & 0x100000000) != 0) {
    uVar2 = CONCAT44((int)uVar2,(int)uVar2);
    uVar4 = PackedFloatingMUL(uVar8 & 0xffffffff,uVar2);
    local_20 = (undefined4)uVar4;
    uVar1 = PackedFloatingMUL(uVar1,uVar2);
  }
  uVar8 = CONCAT44((int)extraout_MM0_01,local_20);
  uVar10 = CONCAT44((int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  uVar12 = CONCAT44(local_20,(int)extraout_MM0_01);
  uVar5 = PackedFloatingMUL(uVar1,uVar13);
  uVar2 = PackedFloatingMUL(uVar8,uVar6);
  uVar7 = PackedFloatingMUL(uVar12 ^ 0x80000000,uVar6);
  uVar4 = PackedFloatingMUL(uVar10,uVar13);
  uVar2 = PackedFloatingADD(uVar5 ^ 0x80000000,uVar2);
  uVar4 = PackedFloatingSUB(uVar4,uVar7);
  uVar9 = PackedFloatingMUL(uVar12,uVar13);
  uVar4 = PackedFloatingAccumulate(uVar4,uVar2);
  uVar7 = PackedFloatingMUL(uVar10 ^ 0x80000000,uVar6);
  uVar1 = PackedFloatingMUL(uVar1,uVar6);
  *param_1 = uVar4;
  uVar2 = PackedFloatingMUL(uVar8 ^ 0x80000000,uVar13);
  uVar7 = PackedFloatingADD(uVar7,uVar9);
  uVar1 = PackedFloatingSUB(uVar2,uVar1);
  uVar1 = PackedFloatingAccumulate(uVar7,uVar1);
  param_1[1] = uVar1;
  uVar1 = PackedFloatingMUL(local_88,local_88);
  uVar2 = PackedFloatingMUL(local_80,local_80);
  uVar1 = PackedFloatingADD(uVar1,uVar2);
  uVar1 = PackedFloatingAccumulate(uVar1,uVar1);
  uVar2 = FloatingReciprocalAprox(uVar4,uVar1);
  uVar5 = PackedFloatingCompareGT(uVar1,0x80000000800000);
  uVar1 = PackedFloatingReciprocalIter1(uVar1,uVar2);
  uVar1 = PackedFloatingReciprocalIter2(uVar1,uVar2);
  uVar2 = PackedFloatingMUL((local_88 ^ 0x8000000080000000) & uVar5,uVar1);
  uVar9 = PackedFloatingMUL((local_80 ^ 0x80000000) & uVar5,uVar1);
  uVar8 = CONCAT44((int)uVar6,(int)(uVar6 >> 0x20));
  uVar10 = CONCAT44((int)uVar13,(int)(uVar13 >> 0x20));
  uVar5 = PackedFloatingMUL(uVar6,uVar9);
  uVar1 = PackedFloatingMUL(uVar13,uVar2);
  uVar7 = PackedFloatingMUL(uVar10 ^ 0x80000000,uVar2);
  uVar4 = PackedFloatingMUL(uVar8,uVar9);
  uVar1 = PackedFloatingADD(uVar5 ^ 0x80000000,uVar1);
  uVar4 = PackedFloatingSUB(uVar4,uVar7);
  uVar14 = PackedFloatingMUL(uVar10,uVar9);
  uVar4 = PackedFloatingAccumulate(uVar4,uVar1);
  uVar11 = PackedFloatingMUL(uVar8 ^ 0x80000000,uVar2);
  uVar1 = PackedFloatingMUL(uVar6,uVar2);
  uVar7 = PackedFloatingMUL(uVar13 ^ 0x80000000,uVar9);
  uVar11 = PackedFloatingADD(uVar11,uVar14);
  uVar1 = PackedFloatingSUB(uVar7,uVar1);
  uVar13 = PackedFloatingAccumulate(uVar11,uVar1);
  uVar5 = CONCAT44((int)local_78,(int)(local_78 >> 0x20));
  uVar8 = CONCAT44((int)local_70,(int)(local_70 >> 0x20));
  uVar6 = PackedFloatingMUL(local_78,uVar9);
  uVar1 = PackedFloatingMUL(local_70,uVar2);
  uVar11 = PackedFloatingMUL(uVar8 ^ 0x80000000,uVar2);
  uVar7 = PackedFloatingMUL(uVar5,uVar9);
  uVar1 = PackedFloatingADD(uVar6 ^ 0x80000000,uVar1);
  uVar7 = PackedFloatingSUB(uVar7,uVar11);
  uVar14 = PackedFloatingMUL(uVar8,uVar9);
  uVar7 = PackedFloatingAccumulate(uVar7,uVar1);
  uVar11 = PackedFloatingMUL(uVar5 ^ 0x80000000,uVar2);
  uVar1 = PackedFloatingMUL(local_78,uVar2);
  uVar2 = PackedFloatingMUL(local_70 ^ 0x80000000,uVar9);
  uVar9 = PackedFloatingADD(uVar11,uVar14);
  uVar1 = PackedFloatingSUB(uVar2,uVar1);
  uVar6 = PackedFloatingAccumulate(uVar9,uVar1);
  uVar3 = (undefined4)(uVar13 >> 0x20);
  uVar2 = PackedFloatingCompareGE(CONCAT44(uVar3,uVar3),0x3f8000003f800000);
  uVar1 = uVar7;
  if ((int)uVar2 == 0) {
    math_acos_packed();
    math_sin_packed();
    uVar2 = PackedFloatingCompareGE(extraout_MM0_02 & 0x7fffffff7fffffff,0x3400000034000000);
    if ((int)uVar2 != 0) {
      uVar1 = FloatingReciprocalAprox(uVar1,extraout_MM0_02);
      uVar2 = PackedFloatingReciprocalIter1(extraout_MM0_02,uVar1);
      uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar1);
      uVar2 = PackedFloatingMUL(CONCAT44(extraout_MM0_Da_01,extraout_MM0_Da_01),uVar2);
      uVar4 = PackedFloatingMUL(uVar4,uVar2);
      uVar13 = PackedFloatingMUL(uVar13,uVar2);
    }
  }
  uVar3 = (undefined4)(uVar6 >> 0x20);
  uVar2 = PackedFloatingCompareGE(CONCAT44(uVar3,uVar3),0x3f8000003f800000);
  if ((int)uVar2 == 0) {
    math_acos_packed();
    math_sin_packed();
    uVar2 = PackedFloatingCompareGE(extraout_MM0_03 & 0x7fffffff7fffffff,0x3400000034000000);
    if ((int)uVar2 != 0) {
      uVar2 = FloatingReciprocalAprox(uVar1,extraout_MM0_03);
      uVar1 = PackedFloatingReciprocalIter1(extraout_MM0_03,uVar2);
      uVar1 = PackedFloatingReciprocalIter2(uVar1,uVar2);
      uVar1 = PackedFloatingMUL(CONCAT44(extraout_MM0_Da_02,extraout_MM0_Da_02),uVar1);
      uVar7 = PackedFloatingMUL(uVar7,uVar1);
      uVar6 = PackedFloatingMUL(uVar6,uVar1);
    }
  }
  uVar1 = PackedFloatingADD(uVar4,uVar7);
  uVar2 = PackedFloatingADD(uVar13 & 0xffffffff,uVar6 & 0xffffffff);
  uVar1 = PackedFloatingMUL(uVar1,0xbe800000be800000);
  uVar13 = PackedFloatingMUL(uVar2,0xbe800000be800000);
  uVar2 = PackedFloatingMUL(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar13 & 0xffffffff,uVar13 & 0xffffffff);
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar4 = PackedFloatingReciprocalSQRAprox(uVar4,uVar2);
  uVar7 = PackedFloatingMUL(uVar4,uVar4);
  uVar7 = PackedFloatingReciprocalSQRIter1(uVar7,uVar2);
  uVar4 = PackedFloatingReciprocalIter2(uVar7,uVar4);
  PackedFloatingMUL(uVar2,uVar4);
  math_sincos_packed();
  uVar6 = PackedFloatingCompareGE(extraout_MM0_04 & 0x7fffffffffffffff,0x3400000034000000);
  uVar3 = (undefined4)(extraout_MM0_04 >> 0x20);
  uVar2 = PackedFloatingMUL(CONCAT44(uVar3,uVar3),CONCAT44(unaff_ESI,(int)uVar4));
  local_20 = (undefined4)uVar13;
  if ((uVar6 & 0x100000000) != 0) {
    uVar2 = CONCAT44((int)uVar2,(int)uVar2);
    uVar4 = PackedFloatingMUL(uVar13 & 0xffffffff,uVar2);
    local_20 = (undefined4)uVar4;
    uVar1 = PackedFloatingMUL(uVar1,uVar2);
  }
  uVar13 = CONCAT44((int)extraout_MM0_04,local_20);
  uVar5 = CONCAT44((int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  uVar8 = CONCAT44(local_20,(int)extraout_MM0_04);
  uVar6 = PackedFloatingMUL(uVar1,local_80);
  uVar2 = PackedFloatingMUL(uVar13,local_88);
  uVar7 = PackedFloatingMUL(uVar8 ^ 0x80000000,local_88);
  uVar4 = PackedFloatingMUL(uVar5,local_80);
  uVar2 = PackedFloatingADD(uVar6 ^ 0x80000000,uVar2);
  uVar4 = PackedFloatingSUB(uVar4,uVar7);
  uVar7 = PackedFloatingMUL(uVar8,local_80);
  uVar2 = PackedFloatingAccumulate(uVar4,uVar2);
  uVar4 = PackedFloatingMUL(uVar5 ^ 0x80000000,local_88);
  uVar1 = PackedFloatingMUL(uVar1,local_88);
  *param_2 = uVar2;
  uVar2 = PackedFloatingMUL(uVar13 ^ 0x80000000,local_80);
  uVar4 = PackedFloatingADD(uVar4,uVar7);
  uVar1 = PackedFloatingSUB(uVar2,uVar1);
  uVar1 = PackedFloatingAccumulate(uVar4,uVar1);
  param_2[1] = uVar1;
  *param_3 = local_88;
  param_3[1] = local_80;
  FastExitMediaState();
  return;
}



