/* math_sin_packed @ 004608c0 */

/* packed sin approximation; input in MM0 */

ulonglong math_sin_packed(void)

{
  uint uVar1;
  uint uVar2;
  ulonglong in_MM0;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  uVar1 = (uint)in_MM0;
  uVar2 = uVar1 >> 0x1f;
  uVar1 = uVar1 ^ uVar1 & 0x80000000;
  if ((int)uVar1 < DAT_0047b154) {
    uVar3 = PackedFloatingMUL(in_MM0 & DAT_0047b09c,(ulonglong)DAT_0047b150);
    uVar4 = PackedFloatingToIntDwordConv(uVar3,uVar3);
    uVar3 = PackedIntToFloatingDwordConv(uVar4,uVar4);
    uVar3 = PackedFloatingMUL(CONCAT44((int)uVar3,(int)uVar3),DAT_0047b060);
    uVar6 = PackedFloatingADD(in_MM0 & DAT_0047b09c,uVar3);
    uVar5 = (undefined4)((ulonglong)uVar3 >> 0x20);
    uVar3 = PackedFloatingADD(uVar6,CONCAT44(uVar5,uVar5));
    uVar3 = CONCAT44((int)uVar3,(int)uVar3);
    if ((uVar4 & 1) != 0) {
      uVar3 = PackedFloatingSUBR(uVar3,DAT_0047b070);
    }
    uVar2 = (uVar2 ^ (uint)uVar4 >> 2) << 0x1f;
    uVar6 = PackedFloatingMUL(uVar3,uVar3);
    uVar8 = PackedFloatingMUL(DAT_0047b068,uVar6);
    uVar7 = PackedFloatingMUL(DAT_0047b078,uVar6);
    uVar9 = PackedFloatingADD(uVar8,DAT_0047b018);
    uVar8 = PackedFloatingMUL(DAT_0047b080,uVar6);
    uVar7 = PackedFloatingMUL(uVar9,uVar7);
    uVar9 = PackedFloatingADD(uVar7,DAT_0047b018);
    uVar7 = PackedFloatingMUL(DAT_0047b088,uVar6);
    uVar6 = PackedFloatingMUL(uVar8,uVar9);
    uVar6 = PackedFloatingADD(uVar6,DAT_0047b018);
    uVar6 = PackedFloatingMUL(uVar6,CONCAT44((int)DAT_0047b018,(int)uVar7));
    uVar6 = PackedFloatingADD(uVar6,DAT_0047b018 >> 0x20);
    PackedFloatingMUL(uVar6,CONCAT44((int)uVar3,(int)DAT_0047b018));
  }
  return CONCAT44(uVar2,uVar1);
}



