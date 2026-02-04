/* FUN_100373d7 @ 100373d7 */

void __cdecl
FUN_100373d7(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,int param_4,int param_5,
            int param_6)

{
  undefined2 uVar1;
  int *piVar2;
  short sVar3;
  int iVar4;
  short sVar6;
  short sVar7;
  short sVar10;
  undefined8 uVar5;
  int iVar8;
  int iVar9;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  short sVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  short sVar24;
  short sVar25;
  short sVar29;
  ulonglong uVar21;
  int iVar26;
  int iVar27;
  ulonglong uVar22;
  ulonglong uVar23;
  int iVar28;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  ulonglong uVar34;
  int iVar38;
  int iVar39;
  ulonglong uVar35;
  ulonglong uVar36;
  int iVar40;
  ulonglong uVar37;
  short sVar41;
  int iVar42;
  int iVar43;
  int iVar44;
  short sVar50;
  undefined8 uVar45;
  short sVar49;
  int iVar51;
  int iVar52;
  short sVar54;
  ulonglong uVar47;
  int iVar53;
  undefined8 uVar48;
  int iVar55;
  int iVar56;
  int iVar57;
  undefined8 uVar58;
  int iVar60;
  int iVar61;
  int iVar62;
  undefined8 uVar59;
  short sVar63;
  int iVar64;
  short sVar67;
  short sVar68;
  undefined8 uVar65;
  int iVar69;
  short sVar70;
  int iVar71;
  int iVar72;
  ulonglong uVar73;
  int iVar74;
  int iVar75;
  undefined8 *local_18;
  undefined8 *local_14;
  undefined8 *local_10;
  int local_c;
  int local_8;
  ulonglong uVar46;
  ulonglong uVar66;
  
  local_18 = param_1;
  local_10 = param_2;
  local_8 = 2;
  local_14 = param_3;
  do {
    uVar5 = local_18[4];
    uVar45 = local_10[4];
    uVar58 = local_18[0xc];
    sVar3 = (short)uVar5 * (short)uVar45;
    sVar6 = (short)((ulonglong)uVar5 >> 0x10) * (short)((ulonglong)uVar45 >> 0x10);
    sVar7 = (short)((ulonglong)uVar5 >> 0x20) * (short)((ulonglong)uVar45 >> 0x20);
    sVar10 = (short)((ulonglong)uVar5 >> 0x30) * (short)((ulonglong)uVar45 >> 0x30);
    uVar37 = CONCAT26(sVar10,CONCAT24(sVar7,CONCAT22(sVar6,sVar3)));
    uVar5 = local_10[0xc];
    sVar17 = (short)uVar58 * (short)uVar5;
    sVar24 = (short)((ulonglong)uVar58 >> 0x10) * (short)((ulonglong)uVar5 >> 0x10);
    sVar25 = (short)((ulonglong)uVar58 >> 0x20) * (short)((ulonglong)uVar5 >> 0x20);
    sVar29 = (short)((ulonglong)uVar58 >> 0x30) * (short)((ulonglong)uVar5 >> 0x30);
    uVar34 = CONCAT26(sVar29,CONCAT24(sVar25,CONCAT22(sVar24,sVar17)));
    uVar45 = pmaddwd(uVar37,0x187e0000187e);
    uVar58 = pmaddwd(uVar37 >> 0x10,0x187e0000187e);
    uVar37 = CONCAT26(sVar10 + sVar29,
                      CONCAT24(sVar7 + sVar25,CONCAT22(sVar6 + sVar24,sVar3 + sVar17)));
    uVar21 = pmaddwd(uVar34,0x3b2100003b21);
    uVar34 = pmaddwd(uVar34 >> 0x10,0x3b2100003b21);
    uVar5 = pmaddwd(uVar37,0x115100001151);
    uVar65 = pmaddwd(uVar37 >> 0x10,0x115100001151);
    iVar18 = (int)(uVar21 ^ 0xffffffffffffffff) + 1 + (int)uVar5;
    iVar51 = (int)((ulonglong)uVar5 >> 0x20);
    iVar26 = (int)((uVar21 ^ 0xffffffffffffffff) >> 0x20) + 1 + iVar51;
    iVar42 = (int)uVar45 + (int)uVar5;
    iVar51 = (int)((ulonglong)uVar45 >> 0x20) + iVar51;
    uVar5 = *local_18;
    iVar30 = (int)(uVar34 ^ 0xffffffffffffffff) + 1 + (int)uVar65;
    iVar60 = (int)((ulonglong)uVar65 >> 0x20);
    iVar38 = (int)((uVar34 ^ 0xffffffffffffffff) >> 0x20) + 1 + iVar60;
    uVar45 = *local_10;
    iVar55 = (int)uVar58 + (int)uVar65;
    iVar60 = (int)((ulonglong)uVar58 >> 0x20) + iVar60;
    uVar58 = local_18[8];
    sVar3 = (short)uVar5 * (short)uVar45;
    sVar6 = (short)((ulonglong)uVar5 >> 0x10) * (short)((ulonglong)uVar45 >> 0x10);
    sVar7 = (short)((ulonglong)uVar5 >> 0x20) * (short)((ulonglong)uVar45 >> 0x20);
    sVar10 = (short)((ulonglong)uVar5 >> 0x30) * (short)((ulonglong)uVar45 >> 0x30);
    uVar5 = local_10[8];
    sVar17 = (short)uVar58 * (short)uVar5;
    sVar24 = (short)((ulonglong)uVar58 >> 0x10) * (short)((ulonglong)uVar5 >> 0x10);
    sVar25 = (short)((ulonglong)uVar58 >> 0x20) * (short)((ulonglong)uVar5 >> 0x20);
    sVar29 = (short)((ulonglong)uVar58 >> 0x30) * (short)((ulonglong)uVar5 >> 0x30);
    uVar37 = CONCAT26(sVar10 + sVar29,
                      CONCAT24(sVar7 + sVar25,CONCAT22(sVar6 + sVar24,sVar3 + sVar17)));
    uVar34 = CONCAT26(sVar10 - sVar29,
                      CONCAT24(sVar7 - sVar25,CONCAT22(sVar6 - sVar24,sVar3 - sVar17)));
    uVar5 = pmaddwd(uVar37,0x100000001);
    uVar65 = pmaddwd(uVar37 >> 0x10,0x100000001);
    uVar45 = pmaddwd(uVar34,0x100000001);
    uVar58 = pmaddwd(uVar34 >> 0x10,0x100000001);
    iVar4 = (int)uVar5 * 0x2000;
    iVar8 = (int)((ulonglong)uVar5 >> 0x20) * 0x2000;
    iVar64 = (int)uVar65 * 0x2000;
    iVar69 = (int)((ulonglong)uVar65 >> 0x20) * 0x2000;
    iVar43 = iVar42 + iVar4;
    iVar52 = iVar51 + iVar8;
    iVar4 = iVar4 - iVar42;
    iVar8 = iVar8 - iVar51;
    iVar19 = (int)uVar58 * 0x2000;
    iVar27 = (int)((ulonglong)uVar58 >> 0x20) * 0x2000;
    iVar56 = iVar55 + iVar64;
    iVar61 = iVar60 + iVar69;
    iVar64 = iVar64 - iVar55;
    iVar69 = iVar69 - iVar60;
    iVar31 = iVar30 + iVar19;
    iVar39 = iVar38 + iVar27;
    iVar11 = (int)uVar45 * 0x2000;
    iVar14 = (int)((ulonglong)uVar45 >> 0x20) * 0x2000;
    iVar19 = iVar19 - iVar30;
    iVar27 = iVar27 - iVar38;
    uVar5 = local_18[2];
    iVar30 = iVar18 + iVar11;
    iVar55 = iVar26 + iVar14;
    uVar45 = local_10[2];
    iVar11 = iVar11 - iVar18;
    iVar14 = iVar14 - iVar26;
    uVar58 = local_18[0xe];
    sVar63 = (short)uVar5 * (short)uVar45;
    sVar67 = (short)((ulonglong)uVar5 >> 0x10) * (short)((ulonglong)uVar45 >> 0x10);
    sVar68 = (short)((ulonglong)uVar5 >> 0x20) * (short)((ulonglong)uVar45 >> 0x20);
    sVar70 = (short)((ulonglong)uVar5 >> 0x30) * (short)((ulonglong)uVar45 >> 0x30);
    uVar66 = CONCAT26(sVar70,CONCAT24(sVar68,CONCAT22(sVar67,sVar63)));
    uVar5 = local_10[0xe];
    uVar45 = local_18[10];
    sVar3 = (short)uVar58 * (short)uVar5;
    sVar6 = (short)((ulonglong)uVar58 >> 0x10) * (short)((ulonglong)uVar5 >> 0x10);
    sVar7 = (short)((ulonglong)uVar58 >> 0x20) * (short)((ulonglong)uVar5 >> 0x20);
    sVar10 = (short)((ulonglong)uVar58 >> 0x30) * (short)((ulonglong)uVar5 >> 0x30);
    uVar37 = CONCAT26(sVar10,CONCAT24(sVar7,CONCAT22(sVar6,sVar3)));
    uVar5 = local_10[10];
    uVar58 = local_18[6];
    sVar17 = (short)uVar45 * (short)uVar5;
    sVar24 = (short)((ulonglong)uVar45 >> 0x10) * (short)((ulonglong)uVar5 >> 0x10);
    sVar25 = (short)((ulonglong)uVar45 >> 0x20) * (short)((ulonglong)uVar5 >> 0x20);
    sVar29 = (short)((ulonglong)uVar45 >> 0x30) * (short)((ulonglong)uVar5 >> 0x30);
    uVar22 = CONCAT26(sVar29,CONCAT24(sVar25,CONCAT22(sVar24,sVar17)));
    uVar5 = local_10[6];
    sVar41 = (short)uVar58 * (short)uVar5;
    sVar49 = (short)((ulonglong)uVar58 >> 0x10) * (short)((ulonglong)uVar5 >> 0x10);
    sVar50 = (short)((ulonglong)uVar58 >> 0x20) * (short)((ulonglong)uVar5 >> 0x20);
    sVar54 = (short)((ulonglong)uVar58 >> 0x30) * (short)((ulonglong)uVar5 >> 0x30);
    uVar46 = CONCAT26(sVar54,CONCAT24(sVar50,CONCAT22(sVar49,sVar41)));
    uVar34 = CONCAT26(sVar10 + sVar70,
                      CONCAT24(sVar7 + sVar68,CONCAT22(sVar6 + sVar67,sVar3 + sVar63)));
    uVar47 = CONCAT26(sVar29 + sVar54,
                      CONCAT24(sVar25 + sVar50,CONCAT22(sVar24 + sVar49,sVar17 + sVar41)));
    uVar36 = CONCAT26(sVar10 + sVar54,
                      CONCAT24(sVar7 + sVar50,CONCAT22(sVar6 + sVar49,sVar3 + sVar41)));
    uVar35 = CONCAT26(sVar29 + sVar70,
                      CONCAT24(sVar25 + sVar68,CONCAT22(sVar24 + sVar67,sVar17 + sVar63)));
    uVar23 = CONCAT26(sVar10 + sVar54 + sVar29 + sVar70,
                      CONCAT24(sVar7 + sVar50 + sVar25 + sVar68,
                               CONCAT22(sVar6 + sVar49 + sVar24 + sVar67,
                                        sVar3 + sVar41 + sVar17 + sVar63)));
    uVar5 = pmaddwd(uVar23,0x25a1000025a1);
    uVar21 = pmaddwd(uVar34,0x1ccd00001ccd);
    uVar45 = pmaddwd(uVar23 >> 0x10,0x25a1000025a1);
    iVar26 = (int)(uVar21 ^ 0xffffffffffffffff) + 1;
    iVar60 = (int)((uVar21 ^ 0xffffffffffffffff) >> 0x20) + 1;
    uVar23 = pmaddwd(uVar47,0x520300005203);
    uVar47 = pmaddwd(uVar47 >> 0x10,0x520300005203);
    uVar73 = pmaddwd(uVar34 >> 0x10,0x1ccd00001ccd);
    uVar21 = pmaddwd(uVar36,0x3ec500003ec5);
    iVar20 = (int)(uVar23 ^ 0xffffffffffffffff) + 1;
    iVar28 = (int)((uVar23 ^ 0xffffffffffffffff) >> 0x20) + 1;
    uVar23 = pmaddwd(uVar36 >> 0x10,0x3ec500003ec5);
    uVar36 = pmaddwd(uVar35,0xc7c00000c7c);
    iVar44 = (int)(uVar47 ^ 0xffffffffffffffff) + 1;
    iVar53 = (int)((uVar47 ^ 0xffffffffffffffff) >> 0x20) + 1;
    uVar34 = pmaddwd(uVar35 >> 0x10,0xc7c00000c7c);
    iVar71 = (int)(uVar73 ^ 0xffffffffffffffff) + 1;
    iVar74 = (int)((uVar73 ^ 0xffffffffffffffff) >> 0x20) + 1;
    iVar12 = (int)(uVar21 ^ 0xffffffffffffffff) + 1 + (int)uVar5;
    iVar51 = (int)((ulonglong)uVar5 >> 0x20);
    iVar15 = (int)((uVar21 ^ 0xffffffffffffffff) >> 0x20) + 1 + iVar51;
    iVar57 = (int)(uVar23 ^ 0xffffffffffffffff) + 1 + (int)uVar45;
    iVar18 = (int)((ulonglong)uVar45 >> 0x20);
    iVar62 = (int)((uVar23 ^ 0xffffffffffffffff) >> 0x20) + 1 + iVar18;
    iVar32 = (int)(uVar36 ^ 0xffffffffffffffff) + 1 + (int)uVar5;
    iVar51 = (int)((uVar36 ^ 0xffffffffffffffff) >> 0x20) + 1 + iVar51;
    iVar38 = (int)(uVar34 ^ 0xffffffffffffffff) + 1 + (int)uVar45;
    iVar18 = (int)((uVar34 ^ 0xffffffffffffffff) >> 0x20) + 1 + iVar18;
    uVar5 = pmaddwd(uVar37,0x98e0000098e);
    uVar45 = pmaddwd(uVar37 >> 0x10,0x98e0000098e);
    uVar65 = pmaddwd(uVar22,0x41b3000041b3);
    uVar58 = pmaddwd(uVar22 >> 0x10,0x41b3000041b3);
    uVar59 = pmaddwd(uVar46,0x625400006254);
    uVar48 = pmaddwd(uVar46 >> 0x10,0x625400006254);
    iVar42 = (int)uVar5 + iVar26 + iVar12;
    iVar9 = (int)((ulonglong)uVar5 >> 0x20) + iVar60 + iVar15;
    iVar13 = (int)uVar45 + iVar71 + iVar57;
    iVar16 = (int)((ulonglong)uVar45 >> 0x20) + iVar74 + iVar62;
    uVar45 = pmaddwd(uVar66,0x300b0000300b);
    iVar33 = (int)uVar65 + iVar20 + iVar32;
    iVar40 = (int)((ulonglong)uVar65 >> 0x20) + iVar28 + iVar51;
    uVar5 = pmaddwd(uVar66 >> 0x10,0x300b0000300b);
    iVar72 = (int)uVar45 + iVar32 + iVar26;
    iVar75 = (int)((ulonglong)uVar45 >> 0x20) + iVar51 + iVar60;
    iVar32 = (int)uVar5 + iVar38 + iVar71;
    iVar71 = (int)((ulonglong)uVar5 >> 0x20) + iVar18 + iVar74;
    iVar51 = (int)uVar58 + iVar44 + iVar38;
    iVar18 = (int)((ulonglong)uVar58 >> 0x20) + iVar53 + iVar18;
    iVar60 = (int)uVar59 + iVar12 + iVar20;
    iVar12 = (int)((ulonglong)uVar59 >> 0x20) + iVar15 + iVar28;
    iVar26 = (int)uVar48 + iVar57 + iVar44;
    iVar38 = (int)((ulonglong)uVar48 >> 0x20) + iVar62 + iVar53;
    local_14[0xe] =
         CONCAT44(CONCAT22((short)((iVar61 - iVar71) + 0x400 >> 0xb),
                           (short)((iVar52 - iVar75) + 0x400 >> 0xb)),
                  CONCAT22((short)((iVar56 - iVar32) + 0x400 >> 0xb),
                           (short)((iVar43 - iVar72) + 0x400 >> 0xb)));
    *local_14 = CONCAT44(CONCAT22((short)(iVar71 + iVar61 + 0x400 >> 0xb),
                                  (short)(iVar75 + iVar52 + 0x400 >> 0xb)),
                         CONCAT22((short)(iVar32 + iVar56 + 0x400 >> 0xb),
                                  (short)(iVar72 + iVar43 + 0x400 >> 0xb)));
    local_14[0xc] =
         CONCAT44(CONCAT22((short)((iVar39 - iVar38) + 0x400 >> 0xb),
                           (short)((iVar55 - iVar12) + 0x400 >> 0xb)),
                  CONCAT22((short)((iVar31 - iVar26) + 0x400 >> 0xb),
                           (short)((iVar30 - iVar60) + 0x400 >> 0xb)));
    local_14[2] = CONCAT44(CONCAT22((short)(iVar38 + iVar39 + 0x400 >> 0xb),
                                    (short)(iVar12 + iVar55 + 0x400 >> 0xb)),
                           CONCAT22((short)(iVar26 + iVar31 + 0x400 >> 0xb),
                                    (short)(iVar60 + iVar30 + 0x400 >> 0xb)));
    local_14[4] = CONCAT44(CONCAT22((short)(iVar27 + iVar18 + 0x400 >> 0xb),
                                    (short)(iVar14 + iVar40 + 0x400 >> 0xb)),
                           CONCAT22((short)(iVar19 + iVar51 + 0x400 >> 0xb),
                                    (short)(iVar11 + iVar33 + 0x400 >> 0xb)));
    local_14[10] = CONCAT44(CONCAT22((short)((iVar27 - iVar18) + 0x400 >> 0xb),
                                     (short)((iVar14 - iVar40) + 0x400 >> 0xb)),
                            CONCAT22((short)((iVar19 - iVar51) + 0x400 >> 0xb),
                                     (short)((iVar11 - iVar33) + 0x400 >> 0xb)));
    local_14[6] = CONCAT44(CONCAT22((short)(iVar69 + iVar16 + 0x400 >> 0xb),
                                    (short)(iVar8 + iVar9 + 0x400 >> 0xb)),
                           CONCAT22((short)(iVar64 + iVar13 + 0x400 >> 0xb),
                                    (short)(iVar4 + iVar42 + 0x400 >> 0xb)));
    local_18 = local_18 + 1;
    local_10 = local_10 + 1;
    local_14[8] = CONCAT44(CONCAT22((short)((iVar69 - iVar16) + 0x400 >> 0xb),
                                    (short)((iVar8 - iVar9) + 0x400 >> 0xb)),
                           CONCAT22((short)((iVar64 - iVar13) + 0x400 >> 0xb),
                                    (short)((iVar4 - iVar42) + 0x400 >> 0xb)));
    local_14 = local_14 + 1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  local_8 = 8;
  local_14 = param_3;
  local_c = 0;
  do {
    uVar5 = *local_14;
    uVar45 = local_14[1];
    sVar3 = (short)uVar45;
    sVar17 = (short)uVar5;
    sVar6 = (short)((ulonglong)uVar45 >> 0x10);
    sVar24 = (short)((ulonglong)uVar5 >> 0x10);
    iVar51 = CONCAT22(sVar24 + sVar6,sVar17 + sVar3);
    sVar7 = (short)((ulonglong)uVar45 >> 0x20);
    sVar25 = (short)((ulonglong)uVar5 >> 0x20);
    sVar29 = (short)((ulonglong)uVar5 >> 0x30);
    sVar10 = (short)((ulonglong)uVar45 >> 0x30);
    uVar65 = pmaddwd(CONCAT44((int)((ulonglong)uVar45 >> 0x20),(int)((ulonglong)uVar5 >> 0x20)),
                     0x3b210000187e);
    uVar58 = pmaddwd(CONCAT26(sVar29 + sVar10,CONCAT24(sVar25 + sVar7,iVar51)),0x115100000000);
    iVar18 = (int)((ulonglong)uVar58 >> 0x20);
    iVar26 = (iVar51 << 0x10) >> 3;
    iVar42 = (int)((uint)(ushort)(sVar17 - sVar3) << 0x10) >> 3;
    iVar51 = (int)uVar65 + iVar18;
    iVar18 = ((uint)((ulonglong)uVar65 >> 0x20) ^ 0xffffffff) + 1 + iVar18;
    sVar41 = sVar17 + sVar3;
    sVar49 = sVar24 + sVar6;
    iVar38 = iVar26 + iVar51;
    iVar8 = iVar42 + iVar18;
    iVar26 = iVar26 - iVar51;
    iVar42 = iVar42 - iVar18;
    uVar5 = pmaddwd(uVar5,0x62540000300b0000);
    uVar58 = pmaddwd(CONCAT26(sVar49 + sVar29 + sVar10,
                              CONCAT24(sVar41 + sVar25 + sVar7,CONCAT22(sVar49 * 2,sVar41 * 2))),
                     0x25a1000000000000);
    uVar37 = pmaddwd(CONCAT26(sVar29 + sVar10,CONCAT24(sVar25 + sVar7,CONCAT22(sVar49,sVar41))),
                     0x3ec500000c7c0000);
    uVar34 = pmaddwd(CONCAT26(sVar24 + sVar10,
                              CONCAT24(sVar17 + sVar7,CONCAT22(sVar29 + sVar6,sVar25 + sVar3))),
                     0x1ccd000052030000);
    uVar45 = pmaddwd(uVar45,0x98e000041b30000);
    iVar18 = (int)((ulonglong)uVar58 >> 0x20);
    iVar55 = (int)(uVar34 ^ 0xffffffffffffffff) + 1;
    iVar60 = (int)((uVar34 ^ 0xffffffffffffffff) >> 0x20) + 1;
    iVar51 = (int)(uVar37 ^ 0xffffffffffffffff) + 1 + iVar18;
    iVar18 = (int)((uVar37 ^ 0xffffffffffffffff) >> 0x20) + 1 + iVar18;
    iVar4 = (int)uVar45 + iVar55 + iVar51;
    iVar30 = (int)((ulonglong)uVar45 >> 0x20) + iVar60 + iVar18;
    iVar51 = (int)uVar5 + iVar60 + iVar51;
    iVar18 = (int)((ulonglong)uVar5 >> 0x20) + iVar55 + iVar18;
    uVar34 = CONCAT44(iVar4 + iVar42 + 0x20000 >> 0x12,iVar30 + iVar26 + 0x20000 >> 0x12) &
             0x3ff000003ff;
    piVar2 = (int *)(param_4 + local_c);
    uVar37 = CONCAT44(iVar18 + iVar8 + 0x20000 >> 0x12,iVar51 + iVar38 + 0x20000 >> 0x12) &
             0x3ff000003ff;
    uVar1 = CONCAT11(*(undefined1 *)(param_6 + (int)uVar34),
                     *(undefined1 *)(param_6 + (int)(uVar34 >> 0x20)));
    local_c = local_c + 4;
    uVar21 = CONCAT44((iVar8 - iVar18) + 0x20000 >> 0x12,(iVar38 - iVar51) + 0x20000 >> 0x12) &
             0x3ff000003ff;
    uVar34 = CONCAT44((iVar42 - iVar4) + 0x20000 >> 0x12,(iVar26 - iVar30) + 0x20000 >> 0x12) &
             0x3ff000003ff;
    local_14 = local_14 + 2;
    *(ulonglong *)(*piVar2 + param_5) =
         CONCAT44(CONCAT22((short)CONCAT31(CONCAT21(uVar1,*(undefined1 *)(param_6 + (int)uVar21)),
                                           *(undefined1 *)(param_6 + (int)(uVar21 >> 0x20))),
                           CONCAT11(*(undefined1 *)(param_6 + (int)(uVar34 >> 0x20)),
                                    *(undefined1 *)(param_6 + (int)uVar34))),
                  CONCAT22(uVar1,CONCAT11(*(undefined1 *)(param_6 + (int)(uVar37 >> 0x20)),
                                          *(undefined1 *)(param_6 + (int)uVar37))));
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  return;
}



