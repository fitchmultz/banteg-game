/* FUN_10034e00 @ 10034e00 */

ulonglong FUN_10034e00(void)

{
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
  ulonglong uVar9;
  
  uVar9 = (DAT_10055e58 & in_MM0) >> 1 | DAT_10055e58 & in_MM1;
  uVar3 = in_MM1 & DAT_10055e5c;
  uVar1 = in_MM0 & DAT_10055e5c;
  uVar2 = PackedFloatingMAX(uVar1,uVar3);
  uVar7 = (uint)((int)uVar1 < (int)uVar3) * -0x80000000;
  uVar4 = PackedFloatingMIN(uVar3,uVar1);
  uVar5 = FloatingReciprocalAprox(uVar1,uVar2);
  uVar2 = PackedFloatingReciprocalIter1(uVar2,uVar5);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar5);
  uVar2 = PackedFloatingMUL(uVar2,uVar4);
  uVar4 = PackedFloatingMUL(uVar2,uVar2);
  uVar5 = PackedFloatingADD((ulonglong)DAT_10055e90,uVar4);
  uVar6 = PackedFloatingMUL((ulonglong)DAT_10055e9c,uVar4);
  uVar5 = PackedFloatingMUL(uVar5,uVar4);
  uVar6 = PackedFloatingADD(uVar6,(ulonglong)DAT_10055e98);
  uVar5 = PackedFloatingADD(uVar5,(ulonglong)DAT_10055e8c);
  uVar6 = PackedFloatingMUL(uVar6,uVar4);
  uVar5 = PackedFloatingMUL(uVar5,uVar4);
  uVar6 = PackedFloatingADD(uVar6,(ulonglong)DAT_10055e94);
  uVar5 = PackedFloatingADD(uVar5,(ulonglong)DAT_10055e88);
  uVar4 = PackedFloatingMUL(uVar4,uVar6);
  uVar4 = PackedFloatingMUL(uVar4,uVar2);
  uVar6 = FloatingReciprocalAprox((ulonglong)DAT_10055e94,uVar5);
  uVar8 = (int)uVar9 << 1;
  uVar5 = PackedFloatingReciprocalIter1(uVar5,uVar6);
  uVar5 = PackedFloatingReciprocalIter2(uVar5,uVar6);
  uVar4 = PackedFloatingMUL(uVar4,uVar5);
  uVar1 = PackedFloatingADD(uVar4,uVar2);
  uVar2 = PackedFloatingSUB(~(ulonglong)(uint)((int)uVar7 >> 0x1f) &
                            (ulonglong)(uVar8 ^ DAT_10055eb8),(ulonglong)DAT_10055eb8);
  uVar1 = PackedFloatingADD(uVar1 | uVar8 ^ uVar7,uVar2);
  return uVar1 | DAT_10055e58 & uVar9;
}



