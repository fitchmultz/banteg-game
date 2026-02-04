/* math_atan2_packed @ 004600c0 */

/* packed atan2 approximation; inputs in MM0/MM1 */

ulonglong math_atan2_packed(void)

{
  undefined4 in_EAX;
  undefined4 in_EDX;
  ulonglong in_MM0;
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong in_MM1;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar3 = in_MM1 & DAT_0047b09c;
  uVar1 = in_MM0 & DAT_0047b09c;
  uVar2 = PackedFloatingMAX(uVar1,uVar3);
  uVar7 = (uint)((int)uVar1 < (int)uVar3) * -0x80000000;
  uVar4 = PackedFloatingMIN(uVar3,uVar1);
  uVar5 = FloatingReciprocalAprox(uVar1,uVar2);
  uVar2 = PackedFloatingReciprocalIter1(uVar2,uVar5);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar5);
  uVar2 = PackedFloatingMUL(uVar2,uVar4);
  uVar4 = PackedFloatingMUL(uVar2,uVar2);
  uVar5 = PackedFloatingADD((ulonglong)DAT_0047b0d0,uVar4);
  uVar6 = PackedFloatingMUL((ulonglong)DAT_0047b0dc,uVar4);
  uVar5 = PackedFloatingMUL(uVar5,uVar4);
  uVar6 = PackedFloatingADD(uVar6,(ulonglong)DAT_0047b0d8);
  uVar5 = PackedFloatingADD(uVar5,(ulonglong)DAT_0047b0cc);
  uVar6 = PackedFloatingMUL(uVar6,uVar4);
  uVar5 = PackedFloatingMUL(uVar5,uVar4);
  uVar6 = PackedFloatingADD(uVar6,(ulonglong)DAT_0047b0d4);
  uVar5 = PackedFloatingADD(uVar5,(ulonglong)DAT_0047b0c8);
  uVar4 = PackedFloatingMUL(uVar4,uVar6);
  uVar4 = PackedFloatingMUL(uVar4,uVar2);
  uVar6 = FloatingReciprocalAprox((ulonglong)DAT_0047b0d4,uVar5);
  uVar8 = ((uint)((DAT_0047b098 & in_MM0) >> 1) | DAT_0047b098 & (uint)in_MM1) << 1;
  uVar5 = PackedFloatingReciprocalIter1(uVar5,uVar6);
  uVar5 = PackedFloatingReciprocalIter2(uVar5,uVar6);
  uVar4 = PackedFloatingMUL(uVar4,uVar5);
  uVar1 = PackedFloatingADD(uVar4,uVar2);
  uVar2 = PackedFloatingSUB(~(ulonglong)(uint)((int)uVar7 >> 0x1f) &
                            (ulonglong)(uVar8 ^ DAT_0047b0f8),(ulonglong)DAT_0047b0f8);
  PackedFloatingADD(uVar1 | uVar8 ^ uVar7,uVar2);
  return CONCAT44(in_EDX,in_EAX);
}



