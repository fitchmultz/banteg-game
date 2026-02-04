/* FUN_10037dea @ 10037dea */

void __cdecl
FUN_10037dea(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,int *param_4,int param_5,
            int param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  undefined1 *puVar4;
  short sVar5;
  undefined4 uVar6;
  undefined6 uVar7;
  short sVar9;
  short sVar10;
  ushort uVar11;
  short sVar12;
  undefined8 uVar8;
  short sVar13;
  short sVar16;
  short sVar17;
  short sVar18;
  short sVar19;
  undefined8 uVar14;
  undefined8 uVar15;
  short sVar20;
  undefined4 uVar21;
  short sVar22;
  short sVar23;
  short sVar24;
  short sVar25;
  short sVar26;
  short sVar27;
  short sVar28;
  short sVar29;
  short sVar30;
  undefined4 uVar31;
  undefined8 uVar32;
  short sVar33;
  short sVar34;
  short sVar35;
  short sVar36;
  short sVar37;
  short sVar38;
  short sVar39;
  short sVar41;
  undefined8 uVar40;
  short sVar42;
  short sVar43;
  ushort uVar45;
  undefined8 uVar44;
  
  uVar14 = param_1[0xc];
  uVar40 = param_3[0xc];
  sVar5 = (short)uVar14 * (short)uVar40;
  sVar9 = (short)((ulonglong)uVar14 >> 0x10) * (short)((ulonglong)uVar40 >> 0x10);
  sVar10 = (short)((ulonglong)uVar14 >> 0x20) * (short)((ulonglong)uVar40 >> 0x20);
  sVar12 = (short)((ulonglong)uVar14 >> 0x30) * (short)((ulonglong)uVar40 >> 0x30);
  uVar14 = param_1[4];
  uVar40 = param_3[4];
  sVar13 = (short)uVar14 * (short)uVar40;
  sVar16 = (short)((ulonglong)uVar14 >> 0x10) * (short)((ulonglong)uVar40 >> 0x10);
  sVar18 = (short)((ulonglong)uVar14 >> 0x20) * (short)((ulonglong)uVar40 >> 0x20);
  sVar19 = (short)((ulonglong)uVar14 >> 0x30) * (short)((ulonglong)uVar40 >> 0x30);
  uVar14 = *param_1;
  uVar40 = *param_3;
  sVar24 = (short)uVar14 * (short)uVar40;
  sVar25 = (short)((ulonglong)uVar14 >> 0x10) * (short)((ulonglong)uVar40 >> 0x10);
  sVar27 = (short)((ulonglong)uVar14 >> 0x20) * (short)((ulonglong)uVar40 >> 0x20);
  sVar29 = (short)((ulonglong)uVar14 >> 0x30) * (short)((ulonglong)uVar40 >> 0x30);
  uVar14 = param_1[8];
  uVar40 = param_3[8];
  sVar33 = (short)uVar14 * (short)uVar40;
  sVar34 = (short)((ulonglong)uVar14 >> 0x10) * (short)((ulonglong)uVar40 >> 0x10);
  sVar35 = (short)((ulonglong)uVar14 >> 0x20) * (short)((ulonglong)uVar40 >> 0x20);
  sVar36 = (short)((ulonglong)uVar14 >> 0x30) * (short)((ulonglong)uVar40 >> 0x30);
  sVar17 = sVar16 - sVar9;
  sVar20 = sVar13 + sVar5;
  sVar16 = sVar16 + sVar9;
  sVar22 = sVar18 + sVar10;
  sVar23 = sVar19 + sVar12;
  uVar14 = pmaddwd((ulonglong)CONCAT24(sVar17,CONCAT22(sVar17,sVar13 - sVar5)) & 0xffffffff0000ffff,
                   0x16a0000016a);
  uVar40 = pmaddwd((ulonglong)CONCAT24(sVar19 - sVar12,(uint)(ushort)(sVar18 - sVar10)),
                   0x16a0000016a);
  sVar19 = sVar24 + sVar33;
  sVar26 = sVar25 + sVar34;
  sVar28 = sVar27 + sVar35;
  sVar30 = sVar29 + sVar36;
  sVar24 = sVar24 - sVar33;
  sVar25 = sVar25 - sVar34;
  sVar27 = sVar27 - sVar35;
  sVar29 = sVar29 - sVar36;
  uVar14 = packssdw(CONCAT44((int)((longlong)uVar14 >> 0x28),(int)uVar14 >> 8),
                    CONCAT44((int)((longlong)uVar40 >> 0x28),(int)uVar40 >> 8));
  sVar5 = (short)uVar14 - sVar20;
  sVar9 = (short)((ulonglong)uVar14 >> 0x10) - sVar16;
  sVar10 = (short)((ulonglong)uVar14 >> 0x20) - sVar22;
  sVar12 = (short)((ulonglong)uVar14 >> 0x30) - sVar23;
  param_2[4] = CONCAT26(sVar30 + sVar23,
                        CONCAT24(sVar28 + sVar22,CONCAT22(sVar26 + sVar16,sVar19 + sVar20)));
  param_2[0xc] = CONCAT26(sVar12 + sVar29,
                          CONCAT24(sVar10 + sVar27,CONCAT22(sVar9 + sVar25,sVar5 + sVar24)));
  sVar19 = sVar19 - sVar20;
  sVar26 = sVar26 - sVar16;
  sVar28 = sVar28 - sVar22;
  sVar30 = sVar30 - sVar23;
  *param_2 = CONCAT26(sVar29 - sVar12,
                      CONCAT24(sVar27 - sVar10,CONCAT22(sVar25 - sVar9,sVar24 - sVar5)));
  uVar14 = param_1[10];
  uVar40 = param_3[10];
  sVar18 = (short)uVar14 * (short)uVar40;
  sVar20 = (short)((ulonglong)uVar14 >> 0x10) * (short)((ulonglong)uVar40 >> 0x10);
  sVar22 = (short)((ulonglong)uVar14 >> 0x20) * (short)((ulonglong)uVar40 >> 0x20);
  sVar23 = (short)((ulonglong)uVar14 >> 0x30) * (short)((ulonglong)uVar40 >> 0x30);
  uVar14 = param_1[6];
  uVar40 = param_3[6];
  sVar5 = (short)uVar14 * (short)uVar40;
  sVar10 = (short)((ulonglong)uVar14 >> 0x10) * (short)((ulonglong)uVar40 >> 0x10);
  sVar13 = (short)((ulonglong)uVar14 >> 0x20) * (short)((ulonglong)uVar40 >> 0x20);
  sVar16 = (short)((ulonglong)uVar14 >> 0x30) * (short)((ulonglong)uVar40 >> 0x30);
  uVar14 = param_1[2];
  uVar40 = param_3[2];
  sVar9 = (short)uVar14 * (short)uVar40;
  sVar12 = (short)((ulonglong)uVar14 >> 0x10) * (short)((ulonglong)uVar40 >> 0x10);
  sVar33 = (short)((ulonglong)uVar14 >> 0x20) * (short)((ulonglong)uVar40 >> 0x20);
  sVar17 = (short)((ulonglong)uVar14 >> 0x30) * (short)((ulonglong)uVar40 >> 0x30);
  sVar34 = sVar18 - sVar5;
  sVar35 = sVar20 - sVar10;
  uVar45 = sVar22 - sVar13;
  sVar36 = sVar23 - sVar16;
  uVar14 = param_1[0xe];
  uVar40 = param_3[0xe];
  sVar24 = (short)uVar14 * (short)uVar40;
  sVar25 = (short)((ulonglong)uVar14 >> 0x10) * (short)((ulonglong)uVar40 >> 0x10);
  sVar27 = (short)((ulonglong)uVar14 >> 0x20) * (short)((ulonglong)uVar40 >> 0x20);
  sVar29 = (short)((ulonglong)uVar14 >> 0x30) * (short)((ulonglong)uVar40 >> 0x30);
  sVar18 = sVar18 + sVar5;
  sVar20 = sVar20 + sVar10;
  sVar22 = sVar22 + sVar13;
  sVar23 = sVar23 + sVar16;
  uVar40 = pmaddwd((ulonglong)CONCAT24(sVar35,CONCAT22(sVar35,sVar34)) & 0xffffffff0000ffff,
                   0xfd630000fd63);
  sVar10 = sVar9 + sVar24;
  sVar5 = sVar12 + sVar25;
  sVar13 = sVar33 + sVar27;
  sVar16 = sVar17 + sVar29;
  sVar9 = sVar9 - sVar24;
  sVar12 = sVar12 - sVar25;
  uVar11 = sVar33 - sVar27;
  sVar17 = sVar17 - sVar29;
  uVar14 = pmaddwd((ulonglong)CONCAT24(sVar36,(uint)uVar45),0xfd630000fd63);
  uVar44 = packssdw(CONCAT44((int)((longlong)uVar40 >> 0x28),(int)uVar40 >> 8),
                    CONCAT44((int)((longlong)uVar14 >> 0x28),(int)uVar14 >> 8));
  uVar14 = pmaddwd((ulonglong)CONCAT24(sVar12,CONCAT22(sVar12,sVar9)) & 0xffffffff0000ffff,
                   0x11500000115);
  uVar40 = pmaddwd((ulonglong)CONCAT24(sVar17,(uint)uVar11),0x11500000115);
  uVar8 = packssdw(CONCAT44((int)((longlong)uVar14 >> 0x28),(int)uVar14 >> 8),
                   CONCAT44((int)((longlong)uVar40 >> 0x28),(int)uVar40 >> 8));
  uVar40 = pmaddwd((ulonglong)CONCAT24(sVar35 + sVar12,CONCAT22(sVar35 + sVar12,sVar34 + sVar9)) &
                   0xffffffff0000ffff,0x1d9000001d9);
  sVar25 = sVar10 + sVar18;
  sVar27 = sVar5 + sVar20;
  sVar29 = sVar13 + sVar22;
  sVar33 = sVar16 + sVar23;
  sVar5 = sVar5 - sVar20;
  uVar14 = pmaddwd((ulonglong)CONCAT24(sVar36 + sVar17,(uint)(ushort)(uVar45 + uVar11)),
                   0x1d9000001d9);
  uVar32 = pmaddwd((ulonglong)CONCAT24(sVar5,CONCAT22(sVar5,sVar10 - sVar18)) & 0xffffffff0000ffff,
                   0x16a0000016a);
  uVar15 = packssdw(CONCAT44((int)((longlong)uVar40 >> 0x28),(int)uVar40 >> 8),
                    CONCAT44((int)((longlong)uVar14 >> 0x28),(int)uVar14 >> 8));
  uVar40 = pmaddwd((ulonglong)CONCAT24(sVar16 - sVar23,(uint)(ushort)(sVar13 - sVar22)),
                   0x16a0000016a);
  sVar9 = (short)((ulonglong)uVar15 >> 0x10);
  sVar10 = (short)((ulonglong)uVar15 >> 0x20);
  sVar12 = (short)((ulonglong)uVar15 >> 0x30);
  uVar14 = param_2[4];
  uVar32 = packssdw(CONCAT44((int)((longlong)uVar32 >> 0x28),(int)uVar32 >> 8),
                    CONCAT44((int)((longlong)uVar40 >> 0x28),(int)uVar40 >> 8));
  sVar13 = ((short)uVar15 + (short)uVar44) - sVar25;
  sVar16 = (sVar9 + (short)((ulonglong)uVar44 >> 0x10)) - sVar27;
  sVar17 = (sVar10 + (short)((ulonglong)uVar44 >> 0x20)) - sVar29;
  sVar18 = (sVar12 + (short)((ulonglong)uVar44 >> 0x30)) - sVar33;
  uVar40 = param_2[0xc];
  sVar20 = (short)uVar32 - sVar13;
  sVar22 = (short)((ulonglong)uVar32 >> 0x10) - sVar16;
  sVar23 = (short)((ulonglong)uVar32 >> 0x20) - sVar17;
  sVar24 = (short)((ulonglong)uVar32 >> 0x30) - sVar18;
  sVar5 = ((short)uVar8 - (short)uVar15) + sVar20;
  sVar9 = ((short)((ulonglong)uVar8 >> 0x10) - sVar9) + sVar22;
  sVar10 = ((short)((ulonglong)uVar8 >> 0x20) - sVar10) + sVar23;
  sVar12 = ((short)((ulonglong)uVar8 >> 0x30) - sVar12) + sVar24;
  param_2[8] = CONCAT26(sVar30 + sVar12,
                        CONCAT24(sVar28 + sVar10,CONCAT22(sVar26 + sVar9,sVar19 + sVar5)));
  sVar34 = (short)((ulonglong)uVar14 >> 0x10);
  sVar35 = (short)((ulonglong)uVar14 >> 0x20);
  sVar36 = (short)((ulonglong)uVar14 >> 0x30);
  param_2[6] = CONCAT26(sVar30 - sVar12,
                        CONCAT24(sVar28 - sVar10,CONCAT22(sVar26 - sVar9,sVar19 - sVar5)));
  uVar8 = *param_2;
  *param_2 = CONCAT26(sVar36 + sVar33,
                      CONCAT24(sVar35 + sVar29,CONCAT22(sVar34 + sVar27,(short)uVar14 + sVar25)));
  sVar5 = (short)((ulonglong)uVar40 >> 0x10);
  sVar9 = (short)((ulonglong)uVar40 >> 0x20);
  sVar10 = (short)((ulonglong)uVar40 >> 0x30);
  param_2[0xe] = CONCAT26(sVar36 - sVar33,
                          CONCAT24(sVar35 - sVar29,CONCAT22(sVar34 - sVar27,(short)uVar14 - sVar25))
                         );
  param_2[2] = CONCAT26(sVar10 + sVar18,
                        CONCAT24(sVar9 + sVar17,CONCAT22(sVar5 + sVar16,(short)uVar40 + sVar13)));
  param_2[0xc] = CONCAT26(sVar10 - sVar18,
                          CONCAT24(sVar9 - sVar17,CONCAT22(sVar5 - sVar16,(short)uVar40 - sVar13)));
  sVar9 = (short)((ulonglong)uVar8 >> 0x10);
  sVar16 = (short)((ulonglong)uVar8 >> 0x20);
  sVar17 = (short)((ulonglong)uVar8 >> 0x30);
  uVar14 = param_1[5];
  uVar40 = param_3[5];
  sVar5 = (short)uVar14 * (short)uVar40;
  sVar12 = (short)((ulonglong)uVar14 >> 0x10) * (short)((ulonglong)uVar40 >> 0x10);
  sVar10 = (short)((ulonglong)uVar14 >> 0x20) * (short)((ulonglong)uVar40 >> 0x20);
  sVar13 = (short)((ulonglong)uVar14 >> 0x30) * (short)((ulonglong)uVar40 >> 0x30);
  param_2[4] = CONCAT26(sVar17 + sVar24,
                        CONCAT24(sVar16 + sVar23,CONCAT22(sVar9 + sVar22,(short)uVar8 + sVar20)));
  param_2[10] = CONCAT26(sVar17 - sVar24,
                         CONCAT24(sVar16 - sVar23,CONCAT22(sVar9 - sVar22,(short)uVar8 - sVar20)));
  uVar14 = param_1[0xd];
  uVar40 = param_3[0xd];
  sVar17 = (short)uVar14 * (short)uVar40;
  sVar22 = (short)((ulonglong)uVar14 >> 0x10) * (short)((ulonglong)uVar40 >> 0x10);
  sVar25 = (short)((ulonglong)uVar14 >> 0x20) * (short)((ulonglong)uVar40 >> 0x20);
  sVar27 = (short)((ulonglong)uVar14 >> 0x30) * (short)((ulonglong)uVar40 >> 0x30);
  uVar14 = param_1[1];
  uVar40 = param_3[1];
  sVar24 = (short)uVar14 * (short)uVar40;
  sVar26 = (short)((ulonglong)uVar14 >> 0x10) * (short)((ulonglong)uVar40 >> 0x10);
  sVar28 = (short)((ulonglong)uVar14 >> 0x20) * (short)((ulonglong)uVar40 >> 0x20);
  sVar30 = (short)((ulonglong)uVar14 >> 0x30) * (short)((ulonglong)uVar40 >> 0x30);
  uVar14 = param_1[9];
  sVar9 = sVar12 - sVar22;
  uVar40 = param_3[9];
  sVar16 = (short)uVar14 * (short)uVar40;
  sVar18 = (short)((ulonglong)uVar14 >> 0x10) * (short)((ulonglong)uVar40 >> 0x10);
  sVar19 = (short)((ulonglong)uVar14 >> 0x20) * (short)((ulonglong)uVar40 >> 0x20);
  sVar34 = (short)((ulonglong)uVar14 >> 0x30) * (short)((ulonglong)uVar40 >> 0x30);
  sVar20 = sVar5 + sVar17;
  sVar12 = sVar12 + sVar22;
  sVar22 = sVar10 + sVar25;
  sVar23 = sVar13 + sVar27;
  uVar8 = pmaddwd((ulonglong)CONCAT24(sVar9,CONCAT22(sVar9,sVar5 - sVar17)) & 0xffffffff0000ffff,
                  0x16a0000016a);
  uVar14 = param_1[0xb];
  uVar15 = pmaddwd((ulonglong)CONCAT24(sVar13 - sVar27,(uint)(ushort)(sVar10 - sVar25)),
                   0x16a0000016a);
  uVar40 = param_3[0xb];
  sVar5 = (short)uVar14 * (short)uVar40;
  sVar10 = (short)((ulonglong)uVar14 >> 0x10) * (short)((ulonglong)uVar40 >> 0x10);
  sVar13 = (short)((ulonglong)uVar14 >> 0x20) * (short)((ulonglong)uVar40 >> 0x20);
  sVar17 = (short)((ulonglong)uVar14 >> 0x30) * (short)((ulonglong)uVar40 >> 0x30);
  uVar14 = packssdw(CONCAT44((int)((longlong)uVar8 >> 0x28),(int)uVar8 >> 8),
                    CONCAT44((int)((longlong)uVar15 >> 0x28),(int)uVar15 >> 8));
  sVar25 = sVar24 + sVar16;
  sVar27 = sVar26 + sVar18;
  sVar29 = sVar28 + sVar19;
  sVar33 = sVar30 + sVar34;
  sVar24 = sVar24 - sVar16;
  sVar26 = sVar26 - sVar18;
  sVar28 = sVar28 - sVar19;
  sVar30 = sVar30 - sVar34;
  sVar9 = (short)uVar14 - sVar20;
  sVar16 = (short)((ulonglong)uVar14 >> 0x10) - sVar12;
  sVar18 = (short)((ulonglong)uVar14 >> 0x20) - sVar22;
  sVar19 = (short)((ulonglong)uVar14 >> 0x30) - sVar23;
  uVar14 = param_1[7];
  param_2[5] = CONCAT26(sVar33 + sVar23,
                        CONCAT24(sVar29 + sVar22,CONCAT22(sVar27 + sVar12,sVar25 + sVar20)));
  uVar40 = param_3[7];
  sVar34 = (short)uVar14 * (short)uVar40;
  sVar35 = (short)((ulonglong)uVar14 >> 0x10) * (short)((ulonglong)uVar40 >> 0x10);
  sVar36 = (short)((ulonglong)uVar14 >> 0x20) * (short)((ulonglong)uVar40 >> 0x20);
  sVar42 = (short)((ulonglong)uVar14 >> 0x30) * (short)((ulonglong)uVar40 >> 0x30);
  sVar25 = sVar25 - sVar20;
  sVar27 = sVar27 - sVar12;
  sVar29 = sVar29 - sVar22;
  sVar33 = sVar33 - sVar23;
  param_2[0xd] = CONCAT26(sVar30 + sVar19,
                          CONCAT24(sVar28 + sVar18,CONCAT22(sVar26 + sVar16,sVar24 + sVar9)));
  param_2[9] = CONCAT26(sVar30 - sVar19,
                        CONCAT24(sVar28 - sVar18,CONCAT22(sVar26 - sVar16,sVar24 - sVar9)));
  sVar9 = sVar5 + sVar34;
  sVar12 = sVar10 + sVar35;
  sVar16 = sVar13 + sVar36;
  sVar18 = sVar17 + sVar42;
  uVar14 = param_1[0xf];
  sVar5 = sVar5 - sVar34;
  sVar10 = sVar10 - sVar35;
  uVar11 = sVar13 - sVar36;
  sVar17 = sVar17 - sVar42;
  uVar40 = param_3[0xf];
  sVar13 = (short)uVar14 * (short)uVar40;
  sVar19 = (short)((ulonglong)uVar14 >> 0x10) * (short)((ulonglong)uVar40 >> 0x10);
  sVar22 = (short)((ulonglong)uVar14 >> 0x20) * (short)((ulonglong)uVar40 >> 0x20);
  sVar23 = (short)((ulonglong)uVar14 >> 0x30) * (short)((ulonglong)uVar40 >> 0x30);
  uVar14 = param_1[3];
  uVar40 = param_3[3];
  sVar24 = (short)uVar14 * (short)uVar40;
  sVar28 = (short)((ulonglong)uVar14 >> 0x10) * (short)((ulonglong)uVar40 >> 0x10);
  sVar30 = (short)((ulonglong)uVar14 >> 0x20) * (short)((ulonglong)uVar40 >> 0x20);
  sVar37 = (short)((ulonglong)uVar14 >> 0x30) * (short)((ulonglong)uVar40 >> 0x30);
  sVar26 = sVar24 + sVar13;
  sVar20 = sVar28 + sVar19;
  sVar34 = sVar30 + sVar22;
  sVar38 = sVar37 + sVar23;
  sVar24 = sVar24 - sVar13;
  sVar28 = sVar28 - sVar19;
  uVar45 = sVar30 - sVar22;
  sVar37 = sVar37 - sVar23;
  uVar14 = pmaddwd((ulonglong)CONCAT24(sVar10,CONCAT22(sVar10,sVar5)) & 0xffffffff0000ffff,
                   0xfd630000fd63);
  sVar35 = sVar26 + sVar9;
  sVar36 = sVar20 + sVar12;
  sVar42 = sVar34 + sVar16;
  sVar39 = sVar38 + sVar18;
  uVar40 = pmaddwd((ulonglong)CONCAT24(sVar17,(uint)uVar11),0xfd630000fd63);
  sVar20 = sVar20 - sVar12;
  uVar40 = packssdw(CONCAT44((int)((longlong)uVar14 >> 0x28),(int)uVar14 >> 8),
                    CONCAT44((int)((longlong)uVar40 >> 0x28),(int)uVar40 >> 8));
  uVar8 = pmaddwd((ulonglong)CONCAT24(sVar20,CONCAT22(sVar20,sVar26 - sVar9)) & 0xffffffff0000ffff,
                  0x16a0000016a);
  uVar14 = pmaddwd((ulonglong)CONCAT24(sVar38 - sVar18,(uint)(ushort)(sVar34 - sVar16)),
                   0x16a0000016a);
  uVar15 = packssdw(CONCAT44((int)((longlong)uVar8 >> 0x28),(int)uVar8 >> 8),
                    CONCAT44((int)((longlong)uVar14 >> 0x28),(int)uVar14 >> 8));
  uVar14 = pmaddwd((ulonglong)CONCAT24(sVar10 + sVar28,CONCAT22(sVar10 + sVar28,sVar5 + sVar24)) &
                   0xffffffff0000ffff,0x1d9000001d9);
  uVar8 = pmaddwd((ulonglong)CONCAT24(sVar17 + sVar37,(uint)(ushort)(uVar11 + uVar45)),0x1d9000001d9
                 );
  uVar8 = packssdw(CONCAT44((int)((longlong)uVar14 >> 0x28),(int)uVar14 >> 8),
                   CONCAT44((int)((longlong)uVar8 >> 0x28),(int)uVar8 >> 8));
  uVar32 = pmaddwd((ulonglong)CONCAT24(sVar28,CONCAT22(sVar28,sVar24)) & 0xffffffff0000ffff,
                   0x11500000115);
  uVar14 = pmaddwd((ulonglong)CONCAT24(sVar37,(uint)uVar45),0x11500000115);
  uVar32 = packssdw(CONCAT44((int)((longlong)uVar32 >> 0x28),(int)uVar32 >> 8),
                    CONCAT44((int)((longlong)uVar14 >> 0x28),(int)uVar14 >> 8));
  uVar14 = param_2[5];
  sVar9 = (short)((ulonglong)uVar8 >> 0x10);
  sVar12 = (short)((ulonglong)uVar8 >> 0x20);
  sVar16 = (short)((ulonglong)uVar8 >> 0x30);
  sVar17 = ((short)uVar8 + (short)uVar40) - sVar35;
  sVar18 = (sVar9 + (short)((ulonglong)uVar40 >> 0x10)) - sVar36;
  sVar20 = (sVar12 + (short)((ulonglong)uVar40 >> 0x20)) - sVar42;
  sVar23 = (sVar16 + (short)((ulonglong)uVar40 >> 0x30)) - sVar39;
  sVar26 = (short)uVar15 - sVar17;
  sVar28 = (short)((ulonglong)uVar15 >> 0x10) - sVar18;
  sVar30 = (short)((ulonglong)uVar15 >> 0x20) - sVar20;
  sVar34 = (short)((ulonglong)uVar15 >> 0x30) - sVar23;
  sVar5 = (short)((ulonglong)uVar14 >> 0x10);
  sVar10 = (short)((ulonglong)uVar14 >> 0x20);
  sVar13 = (short)((ulonglong)uVar14 >> 0x30);
  uVar40 = param_2[0xd];
  sVar37 = ((short)uVar32 - (short)uVar8) + sVar26;
  sVar38 = ((short)((ulonglong)uVar32 >> 0x10) - sVar9) + sVar28;
  sVar41 = ((short)((ulonglong)uVar32 >> 0x20) - sVar12) + sVar30;
  sVar43 = ((short)((ulonglong)uVar32 >> 0x30) - sVar16) + sVar34;
  param_2[1] = CONCAT26(sVar13 + sVar39,
                        CONCAT24(sVar10 + sVar42,CONCAT22(sVar5 + sVar36,(short)uVar14 + sVar35)));
  uVar8 = param_2[9];
  param_2[7] = CONCAT26(sVar33 - sVar43,
                        CONCAT24(sVar29 - sVar41,CONCAT22(sVar27 - sVar38,sVar25 - sVar37)));
  sVar19 = (short)((ulonglong)uVar40 >> 0x10);
  sVar22 = (short)((ulonglong)uVar40 >> 0x20);
  sVar24 = (short)((ulonglong)uVar40 >> 0x30);
  param_2[3] = CONCAT26(sVar24 + sVar23,
                        CONCAT24(sVar22 + sVar20,CONCAT22(sVar19 + sVar18,(short)uVar40 + sVar17)));
  sVar9 = (short)((ulonglong)uVar8 >> 0x10);
  sVar12 = (short)((ulonglong)uVar8 >> 0x20);
  sVar16 = (short)((ulonglong)uVar8 >> 0x30);
  param_2[5] = CONCAT26(sVar16 + sVar34,
                        CONCAT24(sVar12 + sVar30,CONCAT22(sVar9 + sVar28,(short)uVar8 + sVar26)));
  uVar6 = CONCAT22(sVar12 - sVar30,sVar29 + sVar41);
  uVar15 = *param_2;
  uVar32 = param_2[2];
  uVar21 = CONCAT22(sVar10 - sVar42,sVar22 - sVar20);
  param_2[9] = CONCAT44(CONCAT22((short)uVar14 - sVar35,(short)uVar40 - sVar17),
                        CONCAT22((short)uVar8 - sVar26,sVar25 + sVar37));
  param_2[0xb] = CONCAT44(CONCAT22(sVar5 - sVar36,sVar19 - sVar18),
                          CONCAT22(sVar9 - sVar28,sVar27 + sVar38));
  param_2[0xd] = CONCAT44(uVar21,uVar6);
  param_2[0xf] = CONCAT44((int)(CONCAT26(sVar13 - sVar39,CONCAT24(sVar24 - sVar23,uVar21)) >> 0x20),
                          (int)(CONCAT26(sVar16 - sVar34,CONCAT24(sVar33 + sVar43,uVar6)) >> 0x20));
  uVar21 = CONCAT22((short)((ulonglong)uVar32 >> 0x20),(short)((ulonglong)uVar15 >> 0x20));
  uVar14 = param_2[4];
  uVar40 = param_2[6];
  uVar6 = CONCAT22((short)((ulonglong)uVar40 >> 0x20),(short)((ulonglong)uVar14 >> 0x20));
  *param_2 = CONCAT44(CONCAT22((short)uVar40,(short)uVar14),CONCAT22((short)uVar32,(short)uVar15));
  param_2[2] = CONCAT44(CONCAT22((short)((ulonglong)uVar40 >> 0x10),
                                 (short)((ulonglong)uVar14 >> 0x10)),
                        CONCAT22((short)((ulonglong)uVar32 >> 0x10),
                                 (short)((ulonglong)uVar15 >> 0x10)));
  param_2[4] = CONCAT44(uVar6,uVar21);
  param_2[6] = CONCAT44((int)(CONCAT26((short)((ulonglong)uVar40 >> 0x30),
                                       CONCAT24((short)((ulonglong)uVar14 >> 0x30),uVar6)) >> 0x20),
                        (int)(CONCAT26((short)((ulonglong)uVar32 >> 0x30),
                                       CONCAT24((short)((ulonglong)uVar15 >> 0x30),uVar21)) >> 0x20)
                       );
  uVar14 = param_2[1];
  uVar40 = param_2[3];
  uVar8 = param_2[5];
  uVar21 = CONCAT22((short)((ulonglong)uVar40 >> 0x20),(short)((ulonglong)uVar14 >> 0x20));
  uVar15 = param_2[7];
  uVar31 = CONCAT22((short)((ulonglong)uVar15 >> 0x20),(short)((ulonglong)uVar8 >> 0x20));
  uVar32 = param_2[8];
  param_2[8] = CONCAT44(CONCAT22((short)uVar15,(short)uVar8),CONCAT22((short)uVar40,(short)uVar14));
  uVar44 = param_2[10];
  param_2[10] = CONCAT44(CONCAT22((short)((ulonglong)uVar15 >> 0x10),
                                  (short)((ulonglong)uVar8 >> 0x10)),
                         CONCAT22((short)((ulonglong)uVar40 >> 0x10),
                                  (short)((ulonglong)uVar14 >> 0x10)));
  uVar1 = param_2[0xc];
  uVar6 = CONCAT22((short)((ulonglong)uVar44 >> 0x20),(short)((ulonglong)uVar32 >> 0x20));
  uVar2 = param_2[0xe];
  param_2[0xc] = CONCAT44(uVar31,uVar21);
  param_2[0xe] = CONCAT44((int)(CONCAT26((short)((ulonglong)uVar15 >> 0x30),
                                         CONCAT24((short)((ulonglong)uVar8 >> 0x30),uVar31)) >> 0x20
                               ),(int)(CONCAT26((short)((ulonglong)uVar40 >> 0x30),
                                                CONCAT24((short)((ulonglong)uVar14 >> 0x30),uVar21))
                                      >> 0x20));
  uVar21 = CONCAT22((short)((ulonglong)uVar2 >> 0x20),(short)((ulonglong)uVar1 >> 0x20));
  param_2[1] = CONCAT44(CONCAT22((short)uVar2,(short)uVar1),CONCAT22((short)uVar44,(short)uVar32));
  param_2[3] = CONCAT44(CONCAT22((short)((ulonglong)uVar2 >> 0x10),(short)((ulonglong)uVar1 >> 0x10)
                                ),
                        CONCAT22((short)((ulonglong)uVar44 >> 0x10),
                                 (short)((ulonglong)uVar32 >> 0x10)));
  param_2[5] = CONCAT44(uVar21,uVar6);
  param_2[7] = CONCAT44((int)(CONCAT26((short)((ulonglong)uVar2 >> 0x30),
                                       CONCAT24((short)((ulonglong)uVar1 >> 0x30),uVar21)) >> 0x20),
                        (int)(CONCAT26((short)((ulonglong)uVar44 >> 0x30),
                                       CONCAT24((short)((ulonglong)uVar32 >> 0x30),uVar6)) >> 0x20))
  ;
  uVar14 = param_2[0xc];
  uVar40 = param_2[4];
  uVar8 = *param_2;
  uVar15 = param_2[8];
  sVar5 = (short)((ulonglong)uVar14 >> 0x10);
  sVar13 = (short)((ulonglong)uVar40 >> 0x10);
  sVar12 = sVar13 - sVar5;
  sVar9 = (short)((ulonglong)uVar14 >> 0x20);
  sVar16 = (short)((ulonglong)uVar40 >> 0x20);
  sVar17 = (short)((ulonglong)uVar40 >> 0x30);
  sVar10 = (short)((ulonglong)uVar14 >> 0x30);
  sVar18 = (short)uVar40 + (short)uVar14;
  sVar13 = sVar13 + sVar5;
  sVar19 = sVar16 + sVar9;
  sVar20 = sVar17 + sVar10;
  uVar14 = pmaddwd((ulonglong)CONCAT24(sVar12,CONCAT22(sVar12,(short)uVar40 - (short)uVar14)) &
                   0xffffffff0000ffff,0x16a0000016a);
  uVar40 = pmaddwd((ulonglong)CONCAT24(sVar17 - sVar10,(uint)(ushort)(sVar16 - sVar9)),0x16a0000016a
                  );
  uVar14 = packssdw(CONCAT44((int)((longlong)uVar14 >> 0x28),(int)uVar14 >> 8),
                    CONCAT44((int)((longlong)uVar40 >> 0x28),(int)uVar40 >> 8));
  sVar22 = (short)uVar8 + (short)uVar15;
  sVar16 = (short)((ulonglong)uVar8 >> 0x10);
  sVar5 = (short)((ulonglong)uVar15 >> 0x10);
  sVar23 = sVar16 + sVar5;
  sVar17 = (short)((ulonglong)uVar8 >> 0x20);
  sVar26 = (short)((ulonglong)uVar8 >> 0x30);
  sVar9 = (short)((ulonglong)uVar15 >> 0x20);
  sVar24 = sVar17 + sVar9;
  sVar10 = (short)((ulonglong)uVar15 >> 0x30);
  sVar25 = sVar26 + sVar10;
  sVar27 = (short)uVar8 - (short)uVar15;
  sVar16 = sVar16 - sVar5;
  sVar17 = sVar17 - sVar9;
  sVar26 = sVar26 - sVar10;
  sVar5 = (short)uVar14 - sVar18;
  sVar9 = (short)((ulonglong)uVar14 >> 0x10) - sVar13;
  sVar10 = (short)((ulonglong)uVar14 >> 0x20) - sVar19;
  sVar12 = (short)((ulonglong)uVar14 >> 0x30) - sVar20;
  param_2[4] = CONCAT26(sVar25 + sVar20,
                        CONCAT24(sVar24 + sVar19,CONCAT22(sVar23 + sVar13,sVar22 + sVar18)));
  param_2[0xc] = CONCAT26(sVar12 + sVar26,
                          CONCAT24(sVar10 + sVar17,CONCAT22(sVar9 + sVar16,sVar5 + sVar27)));
  sVar22 = sVar22 - sVar18;
  sVar23 = sVar23 - sVar13;
  sVar24 = sVar24 - sVar19;
  sVar25 = sVar25 - sVar20;
  *param_2 = CONCAT26(sVar26 - sVar12,
                      CONCAT24(sVar17 - sVar10,CONCAT22(sVar16 - sVar9,sVar27 - sVar5)));
  uVar14 = param_2[10];
  uVar40 = param_2[6];
  uVar8 = param_2[2];
  sVar42 = (short)uVar14 - (short)uVar40;
  sVar5 = (short)((ulonglong)uVar40 >> 0x10);
  sVar12 = (short)((ulonglong)uVar14 >> 0x10);
  sVar37 = sVar12 - sVar5;
  sVar9 = (short)((ulonglong)uVar40 >> 0x20);
  sVar20 = (short)((ulonglong)uVar14 >> 0x20);
  sVar26 = (short)((ulonglong)uVar14 >> 0x30);
  uVar45 = sVar20 - sVar9;
  sVar10 = (short)((ulonglong)uVar40 >> 0x30);
  sVar38 = sVar26 - sVar10;
  uVar15 = param_2[0xe];
  sVar19 = (short)uVar14 + (short)uVar40;
  sVar12 = sVar12 + sVar5;
  sVar20 = sVar20 + sVar9;
  sVar26 = sVar26 + sVar10;
  uVar40 = pmaddwd((ulonglong)CONCAT24(sVar37,CONCAT22(sVar37,sVar42)) & 0xffffffff0000ffff,
                   0xfd630000fd63);
  uVar14 = pmaddwd((ulonglong)CONCAT24(sVar38,(uint)uVar45),0xfd630000fd63);
  uVar32 = packssdw(CONCAT44((int)((longlong)uVar40 >> 0x28),(int)uVar40 >> 8),
                    CONCAT44((int)((longlong)uVar14 >> 0x28),(int)uVar14 >> 8));
  sVar28 = (short)uVar8 + (short)uVar15;
  sVar13 = (short)((ulonglong)uVar15 >> 0x10);
  sVar9 = (short)((ulonglong)uVar8 >> 0x10);
  sVar27 = sVar9 + sVar13;
  sVar16 = (short)((ulonglong)uVar15 >> 0x20);
  sVar18 = (short)((ulonglong)uVar8 >> 0x20);
  sVar10 = (short)((ulonglong)uVar8 >> 0x30);
  sVar33 = sVar18 + sVar16;
  sVar17 = (short)((ulonglong)uVar15 >> 0x30);
  sVar35 = sVar10 + sVar17;
  sVar5 = (short)uVar8 - (short)uVar15;
  sVar9 = sVar9 - sVar13;
  uVar11 = sVar18 - sVar16;
  sVar10 = sVar10 - sVar17;
  uVar14 = pmaddwd((ulonglong)CONCAT24(sVar9,CONCAT22(sVar9,sVar5)) & 0xffffffff0000ffff,
                   0x11500000115);
  uVar40 = pmaddwd((ulonglong)CONCAT24(sVar10,(uint)uVar11),0x11500000115);
  uVar8 = packssdw(CONCAT44((int)((longlong)uVar14 >> 0x28),(int)uVar14 >> 8),
                   CONCAT44((int)((longlong)uVar40 >> 0x28),(int)uVar40 >> 8));
  sVar29 = sVar28 + sVar19;
  sVar30 = sVar27 + sVar12;
  sVar34 = sVar33 + sVar20;
  sVar36 = sVar35 + sVar26;
  uVar14 = pmaddwd((ulonglong)CONCAT24(sVar37 + sVar9,CONCAT22(sVar37 + sVar9,sVar42 + sVar5)) &
                   0xffffffff0000ffff,0x1d9000001d9);
  sVar27 = sVar27 - sVar12;
  uVar40 = pmaddwd((ulonglong)CONCAT24(sVar38 + sVar10,(uint)(ushort)(uVar45 + uVar11)),
                   0x1d9000001d9);
  uVar15 = packssdw(CONCAT44((int)((longlong)uVar14 >> 0x28),(int)uVar14 >> 8),
                    CONCAT44((int)((longlong)uVar40 >> 0x28),(int)uVar40 >> 8));
  sVar9 = (short)((ulonglong)uVar15 >> 0x10);
  sVar10 = (short)((ulonglong)uVar15 >> 0x20);
  sVar12 = (short)((ulonglong)uVar15 >> 0x30);
  sVar13 = ((short)uVar15 + (short)uVar32) - sVar29;
  sVar16 = (sVar9 + (short)((ulonglong)uVar32 >> 0x10)) - sVar30;
  sVar17 = (sVar10 + (short)((ulonglong)uVar32 >> 0x20)) - sVar34;
  sVar18 = (sVar12 + (short)((ulonglong)uVar32 >> 0x30)) - sVar36;
  uVar44 = pmaddwd((ulonglong)CONCAT24(sVar27,CONCAT22(sVar27,sVar28 - sVar19)) & 0xffffffff0000ffff
                   ,0x16a0000016a);
  uVar32 = pmaddwd((ulonglong)CONCAT24(sVar35 - sVar26,(uint)(ushort)(sVar33 - sVar20)),
                   0x16a0000016a);
  uVar14 = param_2[0xc];
  uVar40 = param_2[4];
  uVar32 = packssdw(CONCAT44((int)((longlong)uVar44 >> 0x28),(int)uVar44 >> 8),
                    CONCAT44((int)((longlong)uVar32 >> 0x28),(int)uVar32 >> 8));
  sVar19 = (short)uVar32 - sVar13;
  sVar20 = (short)((ulonglong)uVar32 >> 0x10) - sVar16;
  sVar26 = (short)((ulonglong)uVar32 >> 0x20) - sVar17;
  sVar27 = (short)((ulonglong)uVar32 >> 0x30) - sVar18;
  sVar5 = ((short)uVar8 - (short)uVar15) + sVar19;
  sVar9 = ((short)((ulonglong)uVar8 >> 0x10) - sVar9) + sVar20;
  sVar10 = ((short)((ulonglong)uVar8 >> 0x20) - sVar10) + sVar26;
  sVar12 = ((short)((ulonglong)uVar8 >> 0x30) - sVar12) + sVar27;
  param_2[8] = CONCAT26(sVar25 + sVar12,
                        CONCAT24(sVar24 + sVar10,CONCAT22(sVar23 + sVar9,sVar22 + sVar5)));
  sVar28 = (short)((ulonglong)uVar40 >> 0x10);
  sVar33 = (short)((ulonglong)uVar40 >> 0x20);
  sVar35 = (short)((ulonglong)uVar40 >> 0x30);
  param_2[6] = CONCAT26(sVar25 - sVar12,
                        CONCAT24(sVar24 - sVar10,CONCAT22(sVar23 - sVar9,sVar22 - sVar5)));
  uVar8 = *param_2;
  *param_2 = CONCAT26(sVar35 + sVar36,
                      CONCAT24(sVar33 + sVar34,CONCAT22(sVar28 + sVar30,(short)uVar40 + sVar29)));
  sVar5 = (short)((ulonglong)uVar14 >> 0x10);
  sVar9 = (short)((ulonglong)uVar14 >> 0x20);
  sVar10 = (short)((ulonglong)uVar14 >> 0x30);
  param_2[0xe] = CONCAT26(sVar35 - sVar36,
                          CONCAT24(sVar33 - sVar34,CONCAT22(sVar28 - sVar30,(short)uVar40 - sVar29))
                         );
  param_2[2] = CONCAT26(sVar10 + sVar18,
                        CONCAT24(sVar9 + sVar17,CONCAT22(sVar5 + sVar16,(short)uVar14 + sVar13)));
  param_2[0xc] = CONCAT26(sVar10 - sVar18,
                          CONCAT24(sVar9 - sVar17,CONCAT22(sVar5 - sVar16,(short)uVar14 - sVar13)));
  sVar5 = (short)((ulonglong)uVar8 >> 0x10);
  sVar9 = (short)((ulonglong)uVar8 >> 0x20);
  sVar10 = (short)((ulonglong)uVar8 >> 0x30);
  uVar14 = param_2[5];
  param_2[4] = CONCAT26(sVar10 + sVar27,
                        CONCAT24(sVar9 + sVar26,CONCAT22(sVar5 + sVar20,(short)uVar8 + sVar19)));
  param_2[10] = CONCAT26(sVar10 - sVar27,
                         CONCAT24(sVar9 - sVar26,CONCAT22(sVar5 - sVar20,(short)uVar8 - sVar19)));
  uVar40 = param_2[0xd];
  uVar8 = param_2[1];
  sVar9 = (short)((ulonglong)uVar14 >> 0x10);
  sVar13 = (short)((ulonglong)uVar40 >> 0x10);
  sVar5 = sVar9 - sVar13;
  sVar10 = (short)((ulonglong)uVar14 >> 0x20);
  sVar12 = (short)((ulonglong)uVar14 >> 0x30);
  sVar19 = (short)((ulonglong)uVar40 >> 0x20);
  sVar20 = (short)((ulonglong)uVar40 >> 0x30);
  uVar15 = param_2[9];
  sVar16 = (short)uVar14 + (short)uVar40;
  sVar9 = sVar9 + sVar13;
  sVar17 = sVar10 + sVar19;
  sVar18 = sVar12 + sVar20;
  uVar14 = pmaddwd((ulonglong)CONCAT24(sVar5,CONCAT22(sVar5,(short)uVar14 - (short)uVar40)) &
                   0xffffffff0000ffff,0x16a0000016a);
  uVar40 = pmaddwd((ulonglong)CONCAT24(sVar12 - sVar20,(uint)(ushort)(sVar10 - sVar19)),
                   0x16a0000016a);
  sVar19 = (short)uVar8 + (short)uVar15;
  sVar22 = (short)((ulonglong)uVar8 >> 0x10);
  sVar5 = (short)((ulonglong)uVar15 >> 0x10);
  sVar20 = sVar22 + sVar5;
  sVar23 = (short)((ulonglong)uVar8 >> 0x20);
  sVar25 = (short)((ulonglong)uVar8 >> 0x30);
  sVar10 = (short)((ulonglong)uVar15 >> 0x20);
  sVar24 = sVar23 + sVar10;
  sVar12 = (short)((ulonglong)uVar15 >> 0x30);
  sVar26 = sVar25 + sVar12;
  sVar27 = (short)uVar8 - (short)uVar15;
  sVar22 = sVar22 - sVar5;
  sVar23 = sVar23 - sVar10;
  sVar25 = sVar25 - sVar12;
  uVar14 = packssdw(CONCAT44((int)((longlong)uVar14 >> 0x28),(int)uVar14 >> 8),
                    CONCAT44((int)((longlong)uVar40 >> 0x28),(int)uVar40 >> 8));
  sVar5 = (short)uVar14 - sVar16;
  sVar10 = (short)((ulonglong)uVar14 >> 0x10) - sVar9;
  sVar12 = (short)((ulonglong)uVar14 >> 0x20) - sVar17;
  sVar13 = (short)((ulonglong)uVar14 >> 0x30) - sVar18;
  param_2[5] = CONCAT26(sVar26 + sVar18,
                        CONCAT24(sVar24 + sVar17,CONCAT22(sVar20 + sVar9,sVar19 + sVar16)));
  param_2[0xd] = CONCAT26(sVar25 + sVar13,
                          CONCAT24(sVar23 + sVar12,CONCAT22(sVar22 + sVar10,sVar27 + sVar5)));
  sVar19 = sVar19 - sVar16;
  sVar20 = sVar20 - sVar9;
  sVar24 = sVar24 - sVar17;
  sVar26 = sVar26 - sVar18;
  param_2[9] = CONCAT26(sVar25 - sVar13,
                        CONCAT24(sVar23 - sVar12,CONCAT22(sVar22 - sVar10,sVar27 - sVar5)));
  uVar14 = param_2[0xb];
  uVar40 = param_2[7];
  uVar8 = param_2[0xf];
  uVar15 = param_2[3];
  sVar5 = (short)uVar14 + (short)uVar40;
  sVar10 = (short)((ulonglong)uVar14 >> 0x10);
  sVar22 = (short)((ulonglong)uVar40 >> 0x10);
  sVar9 = sVar10 + sVar22;
  sVar13 = (short)((ulonglong)uVar14 >> 0x20);
  sVar16 = (short)((ulonglong)uVar14 >> 0x30);
  sVar23 = (short)((ulonglong)uVar40 >> 0x20);
  sVar12 = sVar13 + sVar23;
  sVar25 = (short)((ulonglong)uVar40 >> 0x30);
  sVar17 = sVar16 + sVar25;
  sVar18 = (short)uVar14 - (short)uVar40;
  sVar10 = sVar10 - sVar22;
  uVar11 = sVar13 - sVar23;
  sVar16 = sVar16 - sVar25;
  uVar14 = pmaddwd((ulonglong)CONCAT24(sVar10,CONCAT22(sVar10,sVar18)) & 0xffffffff0000ffff,
                   0xfd630000fd63);
  uVar40 = pmaddwd((ulonglong)CONCAT24(sVar16,(uint)uVar11),0xfd630000fd63);
  sVar27 = (short)uVar15 + (short)uVar8;
  sVar13 = (short)((ulonglong)uVar8 >> 0x10);
  sVar28 = (short)((ulonglong)uVar15 >> 0x10);
  sVar22 = sVar28 + sVar13;
  sVar23 = (short)((ulonglong)uVar8 >> 0x20);
  sVar30 = (short)((ulonglong)uVar15 >> 0x20);
  sVar34 = (short)((ulonglong)uVar15 >> 0x30);
  sVar29 = sVar30 + sVar23;
  sVar25 = (short)((ulonglong)uVar8 >> 0x30);
  sVar33 = sVar34 + sVar25;
  sVar38 = (short)uVar15 - (short)uVar8;
  sVar28 = sVar28 - sVar13;
  uVar45 = sVar30 - sVar23;
  sVar34 = sVar34 - sVar25;
  sVar35 = sVar27 + sVar5;
  sVar36 = sVar22 + sVar9;
  sVar42 = sVar29 + sVar12;
  sVar37 = sVar33 + sVar17;
  uVar40 = packssdw(CONCAT44((int)((longlong)uVar14 >> 0x28),(int)uVar14 >> 8),
                    CONCAT44((int)((longlong)uVar40 >> 0x28),(int)uVar40 >> 8));
  sVar22 = sVar22 - sVar9;
  uVar8 = pmaddwd((ulonglong)CONCAT24(sVar22,CONCAT22(sVar22,sVar27 - sVar5)) & 0xffffffff0000ffff,
                  0x16a0000016a);
  uVar14 = pmaddwd((ulonglong)CONCAT24(sVar33 - sVar17,(uint)(ushort)(sVar29 - sVar12)),
                   0x16a0000016a);
  uVar32 = packssdw(CONCAT44((int)((longlong)uVar8 >> 0x28),(int)uVar8 >> 8),
                    CONCAT44((int)((longlong)uVar14 >> 0x28),(int)uVar14 >> 8));
  uVar8 = pmaddwd((ulonglong)CONCAT24(sVar10 + sVar28,CONCAT22(sVar10 + sVar28,sVar18 + sVar38)) &
                  0xffffffff0000ffff,0x1d9000001d9);
  uVar14 = pmaddwd((ulonglong)CONCAT24(sVar16 + sVar34,(uint)(ushort)(uVar11 + uVar45)),
                   0x1d9000001d9);
  uVar15 = packssdw(CONCAT44((int)((longlong)uVar8 >> 0x28),(int)uVar8 >> 8),
                    CONCAT44((int)((longlong)uVar14 >> 0x28),(int)uVar14 >> 8));
  uVar44 = pmaddwd((ulonglong)CONCAT24(sVar28,CONCAT22(sVar28,sVar38)) & 0xffffffff0000ffff,
                   0x11500000115);
  uVar8 = pmaddwd((ulonglong)CONCAT24(sVar34,(uint)uVar45),0x11500000115);
  uVar14 = param_2[5];
  uVar8 = packssdw(CONCAT44((int)((longlong)uVar44 >> 0x28),(int)uVar44 >> 8),
                   CONCAT44((int)((longlong)uVar8 >> 0x28),(int)uVar8 >> 8));
  sVar9 = (short)((ulonglong)uVar15 >> 0x10);
  sVar12 = (short)((ulonglong)uVar15 >> 0x20);
  sVar16 = (short)((ulonglong)uVar15 >> 0x30);
  sVar17 = ((short)uVar15 + (short)uVar40) - sVar35;
  sVar18 = (sVar9 + (short)((ulonglong)uVar40 >> 0x10)) - sVar36;
  sVar23 = (sVar12 + (short)((ulonglong)uVar40 >> 0x20)) - sVar42;
  sVar27 = (sVar16 + (short)((ulonglong)uVar40 >> 0x30)) - sVar37;
  sVar29 = (short)uVar32 - sVar17;
  sVar30 = (short)((ulonglong)uVar32 >> 0x10) - sVar18;
  sVar33 = (short)((ulonglong)uVar32 >> 0x20) - sVar23;
  sVar34 = (short)((ulonglong)uVar32 >> 0x30) - sVar27;
  sVar5 = (short)((ulonglong)uVar14 >> 0x10);
  sVar10 = (short)((ulonglong)uVar14 >> 0x20);
  sVar13 = (short)((ulonglong)uVar14 >> 0x30);
  uVar40 = param_2[0xd];
  sVar38 = ((short)uVar8 - (short)uVar15) + sVar29;
  sVar39 = ((short)((ulonglong)uVar8 >> 0x10) - sVar9) + sVar30;
  sVar41 = ((short)((ulonglong)uVar8 >> 0x20) - sVar12) + sVar33;
  sVar43 = ((short)((ulonglong)uVar8 >> 0x30) - sVar16) + sVar34;
  param_2[1] = CONCAT26(sVar13 + sVar37,
                        CONCAT24(sVar10 + sVar42,CONCAT22(sVar5 + sVar36,(short)uVar14 + sVar35)));
  uVar8 = param_2[9];
  param_2[7] = CONCAT26(sVar26 - sVar43,
                        CONCAT24(sVar24 - sVar41,CONCAT22(sVar20 - sVar39,sVar19 - sVar38)));
  sVar22 = (short)((ulonglong)uVar40 >> 0x10);
  sVar25 = (short)((ulonglong)uVar40 >> 0x20);
  sVar28 = (short)((ulonglong)uVar40 >> 0x30);
  param_2[3] = CONCAT26(sVar28 + sVar27,
                        CONCAT24(sVar25 + sVar23,CONCAT22(sVar22 + sVar18,(short)uVar40 + sVar17)));
  sVar9 = (short)((ulonglong)uVar8 >> 0x10);
  sVar12 = (short)((ulonglong)uVar8 >> 0x20);
  sVar16 = (short)((ulonglong)uVar8 >> 0x30);
  param_2[5] = CONCAT26(sVar16 + sVar34,
                        CONCAT24(sVar12 + sVar33,CONCAT22(sVar9 + sVar30,(short)uVar8 + sVar29)));
  iVar3 = param_4[4] + param_5;
  uVar15 = *param_2;
  uVar32 = param_2[2];
  uVar11 = (ushort)(sVar19 + sVar38) >> 5;
  uVar7 = CONCAT24((ushort)((short)uVar40 - sVar17) >> 5,
                   CONCAT22((ushort)((short)uVar8 - sVar29) >> 5,uVar11));
  uVar45 = (ushort)((short)uVar14 - sVar35) >> 5;
  *(undefined1 *)(iVar3 + 4) = *(undefined1 *)(param_6 + (uVar11 & 0x3ff));
  *(undefined1 *)(iVar3 + 5) = *(undefined1 *)(param_6 + ((uint)((uint6)uVar7 >> 0x10) & 0x3ff));
  *(undefined1 *)(iVar3 + 6) =
       *(undefined1 *)(param_6 + ((uint)(CONCAT26(uVar45,uVar7) >> 0x20) & 0x3ff));
  *(undefined1 *)(iVar3 + 7) = *(undefined1 *)(param_6 + (uVar45 & 0x3ff));
  iVar3 = param_4[5] + param_5;
  uVar11 = (ushort)(sVar20 + sVar39) >> 5;
  uVar7 = CONCAT24((ushort)(sVar22 - sVar18) >> 5,CONCAT22((ushort)(sVar9 - sVar30) >> 5,uVar11));
  uVar45 = (ushort)(sVar5 - sVar36) >> 5;
  *(undefined1 *)(iVar3 + 4) = *(undefined1 *)(param_6 + (uVar11 & 0x3ff));
  *(undefined1 *)(iVar3 + 5) = *(undefined1 *)(param_6 + ((uint)((uint6)uVar7 >> 0x10) & 0x3ff));
  *(undefined1 *)(iVar3 + 6) =
       *(undefined1 *)(param_6 + ((uint)(CONCAT26(uVar45,uVar7) >> 0x20) & 0x3ff));
  *(undefined1 *)(iVar3 + 7) = *(undefined1 *)(param_6 + (uVar45 & 0x3ff));
  iVar3 = param_4[6] + param_5;
  uVar11 = (ushort)(sVar24 + sVar41) >> 5;
  uVar7 = CONCAT24((ushort)(sVar25 - sVar23) >> 5,CONCAT22((ushort)(sVar12 - sVar33) >> 5,uVar11));
  uVar45 = (ushort)(sVar10 - sVar42) >> 5;
  *(undefined1 *)(iVar3 + 4) = *(undefined1 *)(param_6 + (uVar11 & 0x3ff));
  *(undefined1 *)(iVar3 + 5) = *(undefined1 *)(param_6 + ((uint)((uint6)uVar7 >> 0x10) & 0x3ff));
  *(undefined1 *)(iVar3 + 6) =
       *(undefined1 *)(param_6 + ((uint)(CONCAT26(uVar45,uVar7) >> 0x20) & 0x3ff));
  *(undefined1 *)(iVar3 + 7) = *(undefined1 *)(param_6 + (uVar45 & 0x3ff));
  iVar3 = param_4[7] + param_5;
  uVar11 = (ushort)(sVar26 + sVar43) >> 5;
  uVar7 = CONCAT24((ushort)(sVar28 - sVar27) >> 5,CONCAT22((ushort)(sVar16 - sVar34) >> 5,uVar11));
  uVar45 = (ushort)(sVar13 - sVar37) >> 5;
  *(undefined1 *)(iVar3 + 4) = *(undefined1 *)(param_6 + (uVar11 & 0x3ff));
  *(undefined1 *)(iVar3 + 5) = *(undefined1 *)(param_6 + ((uint)((uint6)uVar7 >> 0x10) & 0x3ff));
  *(undefined1 *)(iVar3 + 6) =
       *(undefined1 *)(param_6 + ((uint)(CONCAT26(uVar45,uVar7) >> 0x20) & 0x3ff));
  *(undefined1 *)(iVar3 + 7) = *(undefined1 *)(param_6 + (uVar45 & 0x3ff));
  puVar4 = (undefined1 *)(*param_4 + param_5);
  uVar14 = param_2[6];
  uVar40 = param_2[4];
  uVar11 = (ushort)uVar15 >> 5;
  uVar7 = CONCAT24((ushort)uVar40 >> 5,CONCAT22((ushort)uVar32 >> 5,uVar11));
  uVar45 = (ushort)uVar14 >> 5;
  *puVar4 = *(undefined1 *)(param_6 + (uVar11 & 0x3ff));
  puVar4[1] = *(undefined1 *)(param_6 + ((uint)((uint6)uVar7 >> 0x10) & 0x3ff));
  puVar4[2] = *(undefined1 *)(param_6 + ((uint)(CONCAT26(uVar45,uVar7) >> 0x20) & 0x3ff));
  puVar4[3] = *(undefined1 *)(param_6 + (uVar45 & 0x3ff));
  puVar4 = (undefined1 *)(param_4[1] + param_5);
  uVar11 = (ushort)((ulonglong)uVar15 >> 0x10) >> 5;
  uVar7 = CONCAT24((ushort)((ulonglong)uVar40 >> 0x10) >> 5,
                   CONCAT22((ushort)((ulonglong)uVar32 >> 0x10) >> 5,uVar11));
  uVar45 = (ushort)((ulonglong)uVar14 >> 0x10) >> 5;
  *puVar4 = *(undefined1 *)(param_6 + (uVar11 & 0x3ff));
  puVar4[1] = *(undefined1 *)(param_6 + ((uint)((uint6)uVar7 >> 0x10) & 0x3ff));
  puVar4[2] = *(undefined1 *)(param_6 + ((uint)(CONCAT26(uVar45,uVar7) >> 0x20) & 0x3ff));
  puVar4[3] = *(undefined1 *)(param_6 + (uVar45 & 0x3ff));
  puVar4 = (undefined1 *)(param_4[2] + param_5);
  uVar11 = (ushort)((ulonglong)uVar15 >> 0x20) >> 5;
  uVar7 = CONCAT24((ushort)((ulonglong)uVar40 >> 0x20) >> 5,
                   CONCAT22((ushort)((ulonglong)uVar32 >> 0x20) >> 5,uVar11));
  uVar45 = (ushort)((ulonglong)uVar14 >> 0x20) >> 5;
  *puVar4 = *(undefined1 *)(param_6 + (uVar11 & 0x3ff));
  puVar4[1] = *(undefined1 *)(param_6 + ((uint)((uint6)uVar7 >> 0x10) & 0x3ff));
  puVar4[2] = *(undefined1 *)(param_6 + ((uint)(CONCAT26(uVar45,uVar7) >> 0x20) & 0x3ff));
  puVar4[3] = *(undefined1 *)(param_6 + (uVar45 & 0x3ff));
  puVar4 = (undefined1 *)(param_4[3] + param_5);
  uVar11 = (ushort)((ulonglong)uVar15 >> 0x35);
  uVar7 = CONCAT24((ushort)((ulonglong)uVar40 >> 0x35),
                   CONCAT22((ushort)((ulonglong)uVar32 >> 0x35),uVar11));
  uVar45 = (ushort)((ulonglong)uVar14 >> 0x35);
  *puVar4 = *(undefined1 *)(param_6 + (uVar11 & 0x3ff));
  puVar4[1] = *(undefined1 *)(param_6 + ((uint)((uint6)uVar7 >> 0x10) & 0x3ff));
  puVar4[2] = *(undefined1 *)(param_6 + ((uint)(CONCAT26(uVar45,uVar7) >> 0x20) & 0x3ff));
  puVar4[3] = *(undefined1 *)(param_6 + (uVar45 & 0x3ff));
  puVar4 = (undefined1 *)(param_4[4] + param_5);
  uVar14 = param_2[1];
  uVar40 = param_2[3];
  uVar8 = param_2[5];
  uVar15 = param_2[7];
  uVar32 = param_2[8];
  uVar11 = (ushort)uVar14 >> 5;
  uVar7 = CONCAT24((ushort)uVar8 >> 5,CONCAT22((ushort)uVar40 >> 5,uVar11));
  uVar45 = (ushort)uVar15 >> 5;
  *puVar4 = *(undefined1 *)(param_6 + (uVar11 & 0x3ff));
  puVar4[1] = *(undefined1 *)(param_6 + ((uint)((uint6)uVar7 >> 0x10) & 0x3ff));
  puVar4[2] = *(undefined1 *)(param_6 + ((uint)(CONCAT26(uVar45,uVar7) >> 0x20) & 0x3ff));
  puVar4[3] = *(undefined1 *)(param_6 + (uVar45 & 0x3ff));
  puVar4 = (undefined1 *)(param_4[5] + param_5);
  uVar44 = param_2[10];
  uVar11 = (ushort)((ulonglong)uVar14 >> 0x10) >> 5;
  uVar7 = CONCAT24((ushort)((ulonglong)uVar8 >> 0x10) >> 5,
                   CONCAT22((ushort)((ulonglong)uVar40 >> 0x10) >> 5,uVar11));
  uVar45 = (ushort)((ulonglong)uVar15 >> 0x10) >> 5;
  *puVar4 = *(undefined1 *)(param_6 + (uVar11 & 0x3ff));
  puVar4[1] = *(undefined1 *)(param_6 + ((uint)((uint6)uVar7 >> 0x10) & 0x3ff));
  puVar4[2] = *(undefined1 *)(param_6 + ((uint)(CONCAT26(uVar45,uVar7) >> 0x20) & 0x3ff));
  puVar4[3] = *(undefined1 *)(param_6 + (uVar45 & 0x3ff));
  puVar4 = (undefined1 *)(param_4[6] + param_5);
  uVar1 = param_2[0xc];
  uVar2 = param_2[0xe];
  uVar11 = (ushort)((ulonglong)uVar14 >> 0x20) >> 5;
  uVar7 = CONCAT24((ushort)((ulonglong)uVar8 >> 0x20) >> 5,
                   CONCAT22((ushort)((ulonglong)uVar40 >> 0x20) >> 5,uVar11));
  uVar45 = (ushort)((ulonglong)uVar15 >> 0x20) >> 5;
  *puVar4 = *(undefined1 *)(param_6 + (uVar11 & 0x3ff));
  puVar4[1] = *(undefined1 *)(param_6 + ((uint)((uint6)uVar7 >> 0x10) & 0x3ff));
  puVar4[2] = *(undefined1 *)(param_6 + ((uint)(CONCAT26(uVar45,uVar7) >> 0x20) & 0x3ff));
  puVar4[3] = *(undefined1 *)(param_6 + (uVar45 & 0x3ff));
  puVar4 = (undefined1 *)(param_4[7] + param_5);
  uVar11 = (ushort)((ulonglong)uVar14 >> 0x35);
  uVar7 = CONCAT24((ushort)((ulonglong)uVar8 >> 0x35),
                   CONCAT22((ushort)((ulonglong)uVar40 >> 0x35),uVar11));
  uVar45 = (ushort)((ulonglong)uVar15 >> 0x35);
  *puVar4 = *(undefined1 *)(param_6 + (uVar11 & 0x3ff));
  puVar4[1] = *(undefined1 *)(param_6 + ((uint)((uint6)uVar7 >> 0x10) & 0x3ff));
  puVar4[2] = *(undefined1 *)(param_6 + ((uint)(CONCAT26(uVar45,uVar7) >> 0x20) & 0x3ff));
  puVar4[3] = *(undefined1 *)(param_6 + (uVar45 & 0x3ff));
  iVar3 = *param_4 + param_5;
  uVar11 = (ushort)uVar32 >> 5;
  uVar7 = CONCAT24((ushort)uVar1 >> 5,CONCAT22((ushort)uVar44 >> 5,uVar11));
  uVar45 = (ushort)uVar2 >> 5;
  *(undefined1 *)(iVar3 + 4) = *(undefined1 *)(param_6 + (uVar11 & 0x3ff));
  *(undefined1 *)(iVar3 + 5) = *(undefined1 *)(param_6 + ((uint)((uint6)uVar7 >> 0x10) & 0x3ff));
  *(undefined1 *)(iVar3 + 6) =
       *(undefined1 *)(param_6 + ((uint)(CONCAT26(uVar45,uVar7) >> 0x20) & 0x3ff));
  *(undefined1 *)(iVar3 + 7) = *(undefined1 *)(param_6 + (uVar45 & 0x3ff));
  iVar3 = param_4[1] + param_5;
  uVar11 = (ushort)((ulonglong)uVar32 >> 0x10) >> 5;
  uVar7 = CONCAT24((ushort)((ulonglong)uVar1 >> 0x10) >> 5,
                   CONCAT22((ushort)((ulonglong)uVar44 >> 0x10) >> 5,uVar11));
  uVar45 = (ushort)((ulonglong)uVar2 >> 0x10) >> 5;
  *(undefined1 *)(iVar3 + 4) = *(undefined1 *)(param_6 + (uVar11 & 0x3ff));
  *(undefined1 *)(iVar3 + 5) = *(undefined1 *)(param_6 + ((uint)((uint6)uVar7 >> 0x10) & 0x3ff));
  *(undefined1 *)(iVar3 + 6) =
       *(undefined1 *)(param_6 + ((uint)(CONCAT26(uVar45,uVar7) >> 0x20) & 0x3ff));
  *(undefined1 *)(iVar3 + 7) = *(undefined1 *)(param_6 + (uVar45 & 0x3ff));
  iVar3 = param_4[2] + param_5;
  uVar11 = (ushort)((ulonglong)uVar32 >> 0x20) >> 5;
  uVar7 = CONCAT24((ushort)((ulonglong)uVar1 >> 0x20) >> 5,
                   CONCAT22((ushort)((ulonglong)uVar44 >> 0x20) >> 5,uVar11));
  uVar45 = (ushort)((ulonglong)uVar2 >> 0x20) >> 5;
  *(undefined1 *)(iVar3 + 4) = *(undefined1 *)(param_6 + (uVar11 & 0x3ff));
  *(undefined1 *)(iVar3 + 5) = *(undefined1 *)(param_6 + ((uint)((uint6)uVar7 >> 0x10) & 0x3ff));
  *(undefined1 *)(iVar3 + 6) =
       *(undefined1 *)(param_6 + ((uint)(CONCAT26(uVar45,uVar7) >> 0x20) & 0x3ff));
  *(undefined1 *)(iVar3 + 7) = *(undefined1 *)(param_6 + (uVar45 & 0x3ff));
  iVar3 = param_4[3] + param_5;
  uVar11 = (ushort)((ulonglong)uVar32 >> 0x35);
  uVar7 = CONCAT24((ushort)((ulonglong)uVar1 >> 0x35),
                   CONCAT22((ushort)((ulonglong)uVar44 >> 0x35),uVar11));
  uVar45 = (ushort)((ulonglong)uVar2 >> 0x35);
  *(undefined1 *)(iVar3 + 4) = *(undefined1 *)(param_6 + (uVar11 & 0x3ff));
  *(undefined1 *)(iVar3 + 5) = *(undefined1 *)(param_6 + ((uint)((uint6)uVar7 >> 0x10) & 0x3ff));
  *(undefined1 *)(iVar3 + 6) =
       *(undefined1 *)(param_6 + ((uint)(CONCAT26(uVar45,uVar7) >> 0x20) & 0x3ff));
  *(undefined1 *)(iVar3 + 7) = *(undefined1 *)(param_6 + (uVar45 & 0x3ff));
  return;
}



