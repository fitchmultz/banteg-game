/* mat4_invert @ 0045e40a */

/* inverts a 4x4 matrix; optionally writes determinant */

float * mat4_invert(float *out,float *det_out,float *mat)

{
  float fVar1;
  float *pfVar2;
  undefined4 uVar3;
  undefined4 uVar5;
  undefined8 uVar4;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  undefined4 uVar12;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined4 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined4 uVar22;
  undefined8 uVar21;
  undefined4 uStack_34;
  
  uVar12 = (undefined4)((ulonglong)*(undefined8 *)mat >> 0x20);
  uVar3 = (undefined4)*(undefined8 *)(mat + 8);
  uVar17 = (undefined4)*(undefined8 *)(mat + 4);
  uVar13 = (undefined4)*(undefined8 *)mat;
  uVar22 = (undefined4)((ulonglong)*(undefined8 *)(mat + 4) >> 0x20);
  uVar5 = (undefined4)((ulonglong)*(undefined8 *)(mat + 8) >> 0x20);
  uVar10 = PackedFloatingMUL(CONCAT44(uVar12,uVar12),CONCAT44(uVar3,uVar17));
  uVar14 = PackedFloatingMUL(CONCAT44(uVar13,uVar13),CONCAT44(uVar5,uVar22));
  uVar15 = PackedFloatingSUB(uVar14,uVar10);
  uVar6 = (undefined4)((ulonglong)*(undefined8 *)(mat + 0xc) >> 0x20);
  uVar9 = (undefined4)*(undefined8 *)(mat + 0xc);
  uVar18 = PackedFloatingMUL(CONCAT44(uVar5,uVar6),CONCAT44(uVar17,uVar13));
  uVar21 = PackedFloatingMUL(CONCAT44(uVar22,uVar12),CONCAT44(uVar3,uVar9));
  uVar10 = PackedFloatingMUL(CONCAT44(uVar3,uVar17),CONCAT44(uVar6,uVar6));
  uVar14 = PackedFloatingMUL(CONCAT44(uVar5,uVar22),CONCAT44(uVar9,uVar9));
  uVar19 = PackedFloatingSUB(uVar18,uVar21);
  uVar18 = PackedFloatingSUBR(uVar14,uVar10);
  uVar10 = *(undefined8 *)(mat + 0xe);
  uVar14 = *(undefined8 *)(mat + 10);
  uVar3 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar12 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar21 = PackedFloatingMUL(CONCAT44(uVar3,uVar3),uVar10);
  uVar6 = (undefined4)uVar18;
  uVar18 = PackedFloatingMUL(CONCAT44(uVar12,uVar12),*(undefined8 *)(mat + 6));
  uVar7 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),uVar14);
  uVar18 = PackedFloatingADD(uVar21,uVar18);
  uVar4 = PackedFloatingSUB(uVar18,uVar7);
  uVar9 = (undefined4)uVar19;
  uVar5 = (undefined4)((ulonglong)uVar15 >> 0x20);
  uVar21 = PackedFloatingMUL(CONCAT44(uVar12,uVar12),*(undefined8 *)(mat + 2));
  uVar18 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),uVar10);
  uVar7 = PackedFloatingMUL(CONCAT44(uVar9,uVar9),uVar14);
  uVar18 = PackedFloatingSUB(uVar18,uVar7);
  uVar19 = PackedFloatingADD(uVar18,uVar21);
  uVar21 = CONCAT44((int)uVar15,(int)uVar15);
  uVar18 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),*(undefined8 *)(mat + 2));
  uVar10 = PackedFloatingMUL(uVar10,uVar21);
  uVar7 = PackedFloatingMUL(CONCAT44(uVar9,uVar9),*(undefined8 *)(mat + 6));
  uVar10 = PackedFloatingADD(uVar10,uVar18);
  uVar18 = PackedFloatingSUB(uVar10,uVar7);
  uVar10 = PackedFloatingMUL(uVar21,uVar14);
  uVar14 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),*(undefined8 *)(mat + 6));
  uVar21 = PackedFloatingMUL(CONCAT44(uVar3,uVar3),*(undefined8 *)(mat + 2));
  uVar10 = PackedFloatingSUB(uVar10,uVar14);
  uVar15 = PackedFloatingADD(uVar10,uVar21);
  uVar12 = (undefined4)((ulonglong)*(undefined8 *)(mat + 2) >> 0x20);
  uVar3 = (undefined4)*(undefined8 *)(mat + 10);
  uVar17 = (undefined4)*(undefined8 *)(mat + 6);
  uVar13 = (undefined4)*(undefined8 *)(mat + 2);
  uVar22 = (undefined4)((ulonglong)*(undefined8 *)(mat + 6) >> 0x20);
  uVar5 = (undefined4)((ulonglong)*(undefined8 *)(mat + 10) >> 0x20);
  uVar10 = PackedFloatingMUL(CONCAT44(uVar12,uVar12),CONCAT44(uVar3,uVar17));
  uVar14 = PackedFloatingMUL(CONCAT44(uVar13,uVar13),CONCAT44(uVar5,uVar22));
  uVar16 = PackedFloatingSUB(uVar14,uVar10);
  uVar6 = (undefined4)((ulonglong)*(undefined8 *)(mat + 0xe) >> 0x20);
  uVar9 = (undefined4)*(undefined8 *)(mat + 0xe);
  uVar21 = PackedFloatingMUL(CONCAT44(uVar5,uVar6),CONCAT44(uVar17,uVar13));
  uVar7 = PackedFloatingMUL(CONCAT44(uVar22,uVar12),CONCAT44(uVar3,uVar9));
  uVar10 = PackedFloatingMUL(CONCAT44(uVar3,uVar17),CONCAT44(uVar6,uVar6));
  uVar14 = PackedFloatingMUL(CONCAT44(uVar5,uVar22),CONCAT44(uVar9,uVar9));
  uVar20 = PackedFloatingSUB(uVar21,uVar7);
  uVar21 = PackedFloatingSUBR(uVar14,uVar10);
  uVar10 = *(undefined8 *)(mat + 0xc);
  uVar14 = *(undefined8 *)(mat + 8);
  uVar12 = (undefined4)((ulonglong)uVar21 >> 0x20);
  uVar6 = (undefined4)uVar21;
  uVar3 = (undefined4)((ulonglong)uVar20 >> 0x20);
  uVar11 = PackedFloatingMUL(CONCAT44(uVar12,uVar12),*(undefined8 *)(mat + 4));
  uVar21 = PackedFloatingMUL(CONCAT44(uVar3,uVar3),uVar10);
  uVar7 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),uVar14);
  uVar21 = PackedFloatingADD(uVar21,uVar11);
  uVar11 = PackedFloatingSUB(uVar21,uVar7);
  uVar9 = (undefined4)uVar20;
  uVar5 = (undefined4)((ulonglong)uVar16 >> 0x20);
  uVar7 = PackedFloatingMUL(CONCAT44(uVar12,uVar12),*(undefined8 *)mat);
  uVar21 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),uVar10);
  uVar20 = PackedFloatingMUL(CONCAT44(uVar9,uVar9),uVar14);
  uVar21 = PackedFloatingSUB(uVar21,uVar20);
  uVar20 = PackedFloatingADD(uVar21,uVar7);
  uVar16 = CONCAT44((int)uVar16,(int)uVar16);
  uVar7 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),*(undefined8 *)mat);
  uVar21 = PackedFloatingMUL(uVar10,uVar16);
  uVar8 = PackedFloatingMUL(CONCAT44(uVar9,uVar9),*(undefined8 *)(mat + 4));
  uVar21 = PackedFloatingADD(uVar21,uVar7);
  uVar21 = PackedFloatingSUB(uVar21,uVar8);
  uVar7 = PackedFloatingMUL(uVar16,uVar14);
  uVar16 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),*(undefined8 *)(mat + 4));
  uVar8 = PackedFloatingMUL(CONCAT44(uVar3,uVar3),*(undefined8 *)mat);
  uVar7 = PackedFloatingSUB(uVar7,uVar16);
  uVar7 = PackedFloatingADD(uVar7,uVar8);
  uVar10 = PackedFloatingMUL(CONCAT44((int)uVar10,(int)uVar14),0xbf8000003f800000);
  uStack_34 = (undefined4)((ulonglong)uVar20 >> 0x20);
  uVar14 = CONCAT44(uStack_34,(int)((ulonglong)uVar11 >> 0x20));
  uVar16 = PackedFloatingMUL(CONCAT44(mat[4],(int)*(undefined8 *)mat),0xbf8000003f800000);
  uVar10 = PackedFloatingMUL(CONCAT44((int)((ulonglong)uVar7 >> 0x20),
                                      (int)((ulonglong)uVar21 >> 0x20)),uVar10);
  uVar16 = PackedFloatingMUL(uVar16,uVar14);
  uVar10 = PackedFloatingADD(uVar10,uVar16);
  uVar10 = PackedFloatingAccumulate(uVar10,uVar10);
  fVar1 = (float)uVar10;
  if (det_out != (float *)0x0) {
    *det_out = fVar1;
  }
  uVar14 = FloatingReciprocalAprox(uVar14,uVar10);
  uVar16 = PackedFloatingCompareEQ(0,uVar10);
  uVar10 = PackedFloatingReciprocalIter1(CONCAT44(fVar1,fVar1),uVar14);
  uVar10 = PackedFloatingReciprocalIter2(uVar10,uVar14);
  uVar14 = PackedFloatingMUL(uVar10,0xbf8000003f800000);
  uVar10 = CONCAT44((int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
  pfVar2 = (float *)uVar16;
  if ((float *)uVar16 == (float *)0x0) {
    uVar11 = PackedFloatingMUL(uVar11,uVar10);
    uVar20 = PackedFloatingMUL(uVar20,uVar14);
    uVar4 = PackedFloatingMUL(uVar4,uVar10);
    uVar19 = PackedFloatingMUL(uVar19,uVar14);
    *(ulonglong *)out = CONCAT44((int)((ulonglong)uVar20 >> 0x20),(int)((ulonglong)uVar11 >> 0x20));
    *(ulonglong *)(out + 4) = CONCAT44((int)uVar20,(int)uVar11);
    *(ulonglong *)(out + 8) =
         CONCAT44((int)((ulonglong)uVar19 >> 0x20),(int)((ulonglong)uVar4 >> 0x20));
    *(ulonglong *)(out + 0xc) = CONCAT44((int)uVar19,(int)uVar4);
    uVar21 = PackedFloatingMUL(uVar21,uVar10);
    uVar7 = PackedFloatingMUL(uVar7,uVar14);
    uVar10 = PackedFloatingMUL(uVar18,uVar10);
    uVar14 = PackedFloatingMUL(uVar15,uVar14);
    *(ulonglong *)(out + 2) =
         CONCAT44((int)((ulonglong)uVar7 >> 0x20),(int)((ulonglong)uVar21 >> 0x20));
    *(ulonglong *)(out + 6) = CONCAT44((int)uVar7,(int)uVar21);
    *(ulonglong *)(out + 10) =
         CONCAT44((int)((ulonglong)uVar14 >> 0x20),(int)((ulonglong)uVar10 >> 0x20));
    *(ulonglong *)(out + 0xe) = CONCAT44((int)uVar14,(int)uVar10);
    pfVar2 = out;
  }
  return pfVar2;
}



