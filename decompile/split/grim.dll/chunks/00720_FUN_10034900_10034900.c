/* FUN_10034900 @ 10034900 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10034900(uint *param_1,uint *param_2,uint *param_3)

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
  
  fVar6 = (float)(*param_1 & _DAT_10055b60);
  fVar10 = (float)(param_1[1] & uRam10055b64);
  fVar14 = (float)(param_1[2] & uRam10055b68);
  fVar18 = (float)(param_1[3] & uRam10055b6c);
  uVar22 = param_1[1] & uRam10055b54;
  uVar23 = param_1[2] & uRam10055b58;
  uVar24 = param_1[3] & uRam10055b5c;
  fVar7 = fVar6 * _DAT_10055b40 + _DAT_10055af0;
  fVar11 = fVar10 * fRam10055b44 + fRam10055af4;
  fVar15 = fVar14 * fRam10055b48 + fRam10055af8;
  fVar19 = fVar18 * fRam10055b4c + fRam10055afc;
  fVar8 = fVar7 - _DAT_10055af0;
  fVar12 = fVar11 - fRam10055af4;
  fVar16 = fVar15 - fRam10055af8;
  fVar20 = fVar19 - fRam10055afc;
  fVar6 = (((fVar6 - _DAT_10055b30 * fVar8) - _DAT_10055b20 * fVar8) - _DAT_10055b10 * fVar8) -
          _DAT_10055b00 * fVar8;
  fVar8 = (((fVar10 - fRam10055b34 * fVar12) - fRam10055b24 * fVar12) - fRam10055b14 * fVar12) -
          fRam10055b04 * fVar12;
  fVar10 = (((fVar14 - fRam10055b38 * fVar16) - fRam10055b28 * fVar16) - fRam10055b18 * fVar16) -
           fRam10055b08 * fVar16;
  fVar12 = (((fVar18 - fRam10055b3c * fVar20) - fRam10055b2c * fVar20) - fRam10055b1c * fVar20) -
           fRam10055b0c * fVar20;
  fVar14 = fVar6 * fVar6;
  fVar16 = fVar8 * fVar8;
  fVar18 = fVar10 * fVar10;
  fVar20 = fVar12 * fVar12;
  uVar25 = (uint)fVar7 & _DAT_10055ac0;
  uVar26 = (uint)fVar11 & uRam10055ac4;
  uVar27 = (uint)fVar15 & uRam10055ac8;
  uVar28 = (uint)fVar19 & uRam10055acc;
  uVar9 = uVar25 & _DAT_10055ab0;
  uVar13 = uVar26 & uRam10055ab4;
  uVar17 = uVar27 & uRam10055ab8;
  uVar21 = uVar28 & uRam10055abc;
  uVar1 = uVar26 - uVar13 & _DAT_10055aa0;
  uVar2 = uVar27 - uVar17 & _DAT_10055aa0;
  uVar3 = uVar28 - uVar21 & _DAT_10055aa0;
  uVar4 = uVar25 + uVar9 & _DAT_10055aa0;
  uVar26 = uVar26 + uVar13 & _DAT_10055aa0;
  uVar27 = uVar27 + uVar17 & _DAT_10055aa0;
  uVar28 = uVar28 + uVar21 & _DAT_10055aa0;
  uVar5 = -(uint)((float)(uVar9 << 0x1e) != 0.0);
  uVar13 = -(uint)((float)(uVar13 << 0x1e) != 0.0);
  uVar17 = -(uint)((float)(uVar17 << 0x1e) != 0.0);
  uVar21 = -(uint)((float)(uVar21 << 0x1e) != 0.0);
  fVar6 = (((_DAT_10055ae0 * fVar14 + _DAT_10055a90) * fVar14 + _DAT_10055a70) * fVar14 +
          _DAT_10055a50) * fVar6;
  fVar8 = (((fRam10055ae4 * fVar16 + fRam10055a94) * fVar16 + fRam10055a74) * fVar16 + fRam10055a54)
          * fVar8;
  fVar10 = (((fRam10055ae8 * fVar18 + fRam10055a98) * fVar18 + fRam10055a78) * fVar18 + fRam10055a58
           ) * fVar10;
  fVar12 = (((fRam10055aec * fVar20 + fRam10055a9c) * fVar20 + fRam10055a7c) * fVar20 + fRam10055a5c
           ) * fVar12;
  fVar7 = (((_DAT_10055ad0 * fVar14 + _DAT_10055a80) * fVar14 + _DAT_10055a60) * fVar14 +
          _DAT_10055a40) * fVar14 + _DAT_10055a30;
  fVar11 = (((fRam10055ad4 * fVar16 + fRam10055a84) * fVar16 + fRam10055a64) * fVar16 + fRam10055a44
           ) * fVar16 + fRam10055a34;
  fVar14 = (((fRam10055ad8 * fVar18 + fRam10055a88) * fVar18 + fRam10055a68) * fVar18 + fRam10055a48
           ) * fVar18 + fRam10055a38;
  fVar15 = (((fRam10055adc * fVar20 + fRam10055a8c) * fVar20 + fRam10055a6c) * fVar20 + fRam10055a4c
           ) * fVar20 + fRam10055a3c;
  *param_2 = (~uVar5 & (uint)fVar6 | uVar5 & (uint)fVar7) ^
             (uVar25 - uVar9 & _DAT_10055aa0) << 0x1e ^ *param_1 & _DAT_10055b50;
  param_2[1] = (~uVar13 & (uint)fVar8 | uVar13 & (uint)fVar11) ^ uVar1 << 0x1e ^ uVar22;
  param_2[2] = (~uVar17 & (uint)fVar10 | uVar17 & (uint)fVar14) ^ uVar2 << 0x1e ^ uVar23;
  param_2[3] = (~uVar21 & (uint)fVar12 | uVar21 & (uint)fVar15) ^ uVar3 << 0x1e ^ uVar24;
  *param_3 = (uVar5 & (uint)fVar6 | ~uVar5 & (uint)fVar7) ^ uVar4 << 0x1e;
  param_3[1] = (uVar13 & (uint)fVar8 | ~uVar13 & (uint)fVar11) ^ uVar26 << 0x1e;
  param_3[2] = (uVar17 & (uint)fVar10 | ~uVar17 & (uint)fVar14) ^ uVar27 << 0x1e;
  param_3[3] = (uVar21 & (uint)fVar12 | ~uVar21 & (uint)fVar15) ^ uVar28 << 0x1e;
  return;
}



