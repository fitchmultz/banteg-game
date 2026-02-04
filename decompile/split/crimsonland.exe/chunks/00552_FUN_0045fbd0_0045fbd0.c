/* FUN_0045fbd0 @ 0045fbd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0045fbd0(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  uint uVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  
  fVar6 = (float)(*param_1 & _DAT_0047ada0);
  fVar10 = (float)(param_1[1] & uRam0047ada4);
  fVar14 = (float)(param_1[2] & uRam0047ada8);
  fVar18 = (float)(param_1[3] & uRam0047adac);
  uVar22 = param_1[1] & uRam0047ad94;
  uVar23 = param_1[2] & uRam0047ad98;
  uVar24 = param_1[3] & uRam0047ad9c;
  fVar7 = fVar6 * _DAT_0047ad80 + _DAT_0047ad30;
  fVar11 = fVar10 * fRam0047ad84 + fRam0047ad34;
  fVar15 = fVar14 * fRam0047ad88 + fRam0047ad38;
  fVar19 = fVar18 * fRam0047ad8c + fRam0047ad3c;
  fVar8 = fVar7 - _DAT_0047ad30;
  fVar12 = fVar11 - fRam0047ad34;
  fVar16 = fVar15 - fRam0047ad38;
  fVar20 = fVar19 - fRam0047ad3c;
  fVar6 = (((fVar6 - _DAT_0047ad70 * fVar8) - _DAT_0047ad60 * fVar8) - _DAT_0047ad50 * fVar8) -
          _DAT_0047ad40 * fVar8;
  fVar8 = (((fVar10 - fRam0047ad74 * fVar12) - fRam0047ad64 * fVar12) - fRam0047ad54 * fVar12) -
          fRam0047ad44 * fVar12;
  fVar10 = (((fVar14 - fRam0047ad78 * fVar16) - fRam0047ad68 * fVar16) - fRam0047ad58 * fVar16) -
           fRam0047ad48 * fVar16;
  fVar12 = (((fVar18 - fRam0047ad7c * fVar20) - fRam0047ad6c * fVar20) - fRam0047ad5c * fVar20) -
           fRam0047ad4c * fVar20;
  fVar14 = fVar6 * fVar6;
  fVar16 = fVar8 * fVar8;
  fVar18 = fVar10 * fVar10;
  fVar20 = fVar12 * fVar12;
  uVar25 = (uint)fVar7 & _DAT_0047ad00;
  uVar26 = (uint)fVar11 & uRam0047ad04;
  uVar27 = (uint)fVar15 & uRam0047ad08;
  uVar28 = (uint)fVar19 & uRam0047ad0c;
  uVar9 = uVar25 & _DAT_0047acf0;
  uVar13 = uVar26 & uRam0047acf4;
  uVar17 = uVar27 & uRam0047acf8;
  uVar21 = uVar28 & uRam0047acfc;
  uVar1 = uVar26 - uVar13 & _DAT_0047ace0;
  uVar2 = uVar27 - uVar17 & _DAT_0047ace0;
  uVar3 = uVar28 - uVar21 & _DAT_0047ace0;
  uVar4 = uVar25 + uVar9 & _DAT_0047ace0;
  uVar26 = uVar26 + uVar13 & _DAT_0047ace0;
  uVar27 = uVar27 + uVar17 & _DAT_0047ace0;
  uVar28 = uVar28 + uVar21 & _DAT_0047ace0;
  uVar5 = -(uint)((float)(uVar9 << 0x1e) != 0.0);
  uVar13 = -(uint)((float)(uVar13 << 0x1e) != 0.0);
  uVar17 = -(uint)((float)(uVar17 << 0x1e) != 0.0);
  uVar21 = -(uint)((float)(uVar21 << 0x1e) != 0.0);
  fVar6 = (((_DAT_0047ad20 * fVar14 + _DAT_0047acd0) * fVar14 + _DAT_0047acb0) * fVar14 +
          _DAT_0047ac90) * fVar6;
  fVar8 = (((fRam0047ad24 * fVar16 + fRam0047acd4) * fVar16 + fRam0047acb4) * fVar16 + fRam0047ac94)
          * fVar8;
  fVar10 = (((fRam0047ad28 * fVar18 + fRam0047acd8) * fVar18 + fRam0047acb8) * fVar18 + fRam0047ac98
           ) * fVar10;
  fVar12 = (((fRam0047ad2c * fVar20 + fRam0047acdc) * fVar20 + fRam0047acbc) * fVar20 + fRam0047ac9c
           ) * fVar12;
  fVar7 = (((_DAT_0047ad10 * fVar14 + _DAT_0047acc0) * fVar14 + _DAT_0047aca0) * fVar14 +
          _DAT_0047ac80) * fVar14 + _DAT_0047ac70;
  fVar11 = (((fRam0047ad14 * fVar16 + fRam0047acc4) * fVar16 + fRam0047aca4) * fVar16 + fRam0047ac84
           ) * fVar16 + fRam0047ac74;
  fVar14 = (((fRam0047ad18 * fVar18 + fRam0047acc8) * fVar18 + fRam0047aca8) * fVar18 + fRam0047ac88
           ) * fVar18 + fRam0047ac78;
  fVar15 = (((fRam0047ad1c * fVar20 + fRam0047accc) * fVar20 + fRam0047acac) * fVar20 + fRam0047ac8c
           ) * fVar20 + fRam0047ac7c;
  *param_2 = (~uVar5 & (uint)fVar6 | uVar5 & (uint)fVar7) ^
             (uVar25 - uVar9 & _DAT_0047ace0) << 0x1e ^ *param_1 & _DAT_0047ad90;
  param_2[1] = (~uVar13 & (uint)fVar8 | uVar13 & (uint)fVar11) ^ uVar1 << 0x1e ^ uVar22;
  param_2[2] = (~uVar17 & (uint)fVar10 | uVar17 & (uint)fVar14) ^ uVar2 << 0x1e ^ uVar23;
  param_2[3] = (~uVar21 & (uint)fVar12 | uVar21 & (uint)fVar15) ^ uVar3 << 0x1e ^ uVar24;
  *param_3 = (uVar5 & (uint)fVar6 | ~uVar5 & (uint)fVar7) ^ uVar4 << 0x1e;
  param_3[1] = (uVar13 & (uint)fVar8 | ~uVar13 & (uint)fVar11) ^ uVar26 << 0x1e;
  param_3[2] = (uVar17 & (uint)fVar10 | ~uVar17 & (uint)fVar14) ^ uVar27 << 0x1e;
  param_3[3] = (uVar21 & (uint)fVar12 | ~uVar21 & (uint)fVar15) ^ uVar28 << 0x1e;
  return;
}



