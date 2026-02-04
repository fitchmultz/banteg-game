/* math_acos_packed @ 004601c0 */

/* packed acos approximation; input in MM0 */

ulonglong math_acos_packed(void)

{
  uint uVar1;
  undefined4 in_EAX;
  undefined4 in_EDX;
  ulonglong in_MM0;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined8 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  ulonglong uVar5;
  
  uVar2 = in_MM0 & DAT_0047b09c;
  uVar3 = PackedFloatingMUL(uVar2,(ulonglong)DAT_0047b0ac);
  uVar3 = PackedFloatingSUBR(uVar3,(ulonglong)DAT_0047b0ac);
  uVar6 = PackedFloatingReciprocalSQRAprox((ulonglong)DAT_0047b09c,uVar3);
  uVar7 = PackedFloatingMUL(uVar6,uVar6);
  uVar1 = (uint)((int)uVar2 < DAT_0047b0e0);
  uVar4 = -uVar1;
  uVar5 = (ulonglong)uVar4;
  uVar7 = PackedFloatingReciprocalSQRIter1(uVar7,uVar3);
  uVar6 = PackedFloatingReciprocalIter2(uVar7,uVar6);
  uVar8 = PackedFloatingMUL(uVar6,uVar3);
  uVar2 = ~uVar5 & uVar8 | uVar2 & uVar4;
  uVar3 = PackedFloatingMUL(uVar2,uVar2);
  uVar7 = PackedFloatingMUL((ulonglong)DAT_0047b0e8,uVar3);
  uVar6 = PackedFloatingADD((ulonglong)DAT_0047b0f0,uVar3);
  uVar7 = PackedFloatingADD(uVar7,(ulonglong)DAT_0047b0e4);
  uVar7 = PackedFloatingMUL(uVar7,uVar3);
  uVar3 = PackedFloatingMUL(uVar3,uVar6);
  uVar3 = PackedFloatingADD(uVar3,(ulonglong)DAT_0047b0ec);
  uVar7 = PackedFloatingMUL(uVar7,uVar2);
  uVar6 = FloatingReciprocalAprox(uVar6,uVar3);
  uVar3 = PackedFloatingReciprocalIter1(uVar3,uVar6);
  uVar3 = PackedFloatingReciprocalIter2(uVar3,uVar6);
  uVar3 = PackedFloatingMUL(uVar3,uVar7);
  uVar2 = PackedFloatingADD(uVar2,uVar3);
  uVar3 = PackedFloatingADD(~uVar5 & (ulonglong)DAT_0047b0f8 ^ DAT_0047b098 & in_MM0,
                            (ulonglong)DAT_0047b0f4);
  uVar2 = PackedFloatingADD(uVar2,~uVar5 & uVar2);
  PackedFloatingADD(uVar3,uVar2 | (ulonglong)(uVar1 * -0x80000000) ^ DAT_0047b098 & in_MM0);
  return CONCAT44(in_EDX,in_EAX);
}



