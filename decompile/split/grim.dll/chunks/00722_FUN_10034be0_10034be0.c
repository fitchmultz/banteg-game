/* FUN_10034be0 @ 10034be0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10034be0(uint *param_1,uint *param_2,uint *param_3)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  float fVar16;
  float fVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  float fVar25;
  float fVar26;
  uint uVar27;
  uint uVar28;
  
  fVar16 = (float)(*param_1 & _DAT_10055d80);
  fVar17 = (float)(param_1[1] & uRam10055d84);
  fVar25 = (float)(param_1[2] & uRam10055d88);
  fVar26 = (float)(param_1[3] & uRam10055d8c);
  uVar13 = param_1[1] & uRam10055d74;
  uVar14 = param_1[2] & uRam10055d78;
  uVar15 = param_1[3] & uRam10055d7c;
  fVar1 = fVar16 * _DAT_10055d60 + _DAT_10055d10;
  fVar4 = fVar17 * fRam10055d64 + fRam10055d14;
  fVar7 = fVar25 * fRam10055d68 + fRam10055d18;
  fVar10 = fVar26 * fRam10055d6c + fRam10055d1c;
  fVar2 = fVar1 - _DAT_10055d10;
  fVar5 = fVar4 - fRam10055d14;
  fVar8 = fVar7 - fRam10055d18;
  fVar11 = fVar10 - fRam10055d1c;
  fVar16 = (((fVar16 - _DAT_10055d50 * fVar2) - _DAT_10055d40 * fVar2) - _DAT_10055d30 * fVar2) -
           _DAT_10055d20 * fVar2;
  fVar2 = (((fVar17 - fRam10055d54 * fVar5) - fRam10055d44 * fVar5) - fRam10055d34 * fVar5) -
          fRam10055d24 * fVar5;
  fVar17 = (((fVar25 - fRam10055d58 * fVar8) - fRam10055d48 * fVar8) - fRam10055d38 * fVar8) -
           fRam10055d28 * fVar8;
  fVar5 = (((fVar26 - fRam10055d5c * fVar11) - fRam10055d4c * fVar11) - fRam10055d3c * fVar11) -
          fRam10055d2c * fVar11;
  fVar25 = fVar16 * fVar16;
  fVar8 = fVar2 * fVar2;
  fVar26 = fVar17 * fVar17;
  fVar11 = fVar5 * fVar5;
  uVar18 = (uint)fVar1 & _DAT_10055ce0;
  uVar19 = (uint)fVar4 & uRam10055ce4;
  uVar21 = (uint)fVar7 & uRam10055ce8;
  uVar23 = (uint)fVar10 & uRam10055cec;
  uVar3 = uVar18 & _DAT_10055cd0;
  uVar6 = uVar19 & uRam10055cd4;
  uVar9 = uVar21 & uRam10055cd8;
  uVar12 = uVar23 & uRam10055cdc;
  uVar20 = uVar19 - uVar6 & uRam10055cc4;
  uVar22 = uVar21 - uVar9 & uRam10055cc8;
  uVar24 = uVar23 - uVar12 & uRam10055ccc;
  uVar27 = uVar18 + uVar3 & _DAT_10055cc0;
  uVar28 = uVar19 + uVar6 & uRam10055cc4;
  uVar21 = uVar21 + uVar9 & uRam10055cc8;
  uVar23 = uVar23 + uVar12 & uRam10055ccc;
  uVar19 = -(uint)((float)(uVar3 << 0x1e) != 0.0);
  uVar6 = -(uint)((float)(uVar6 << 0x1e) != 0.0);
  uVar9 = -(uint)((float)(uVar9 << 0x1e) != 0.0);
  uVar12 = -(uint)((float)(uVar12 << 0x1e) != 0.0);
  fVar16 = (((_DAT_10055d00 * fVar25 + _DAT_10055cb0) * fVar25 + _DAT_10055c90) * fVar25 +
           _DAT_10055c70) * fVar16;
  fVar2 = (((fRam10055d04 * fVar8 + fRam10055cb4) * fVar8 + fRam10055c94) * fVar8 + fRam10055c74) *
          fVar2;
  fVar17 = (((fRam10055d08 * fVar26 + fRam10055cb8) * fVar26 + fRam10055c98) * fVar26 + fRam10055c78
           ) * fVar17;
  fVar5 = (((fRam10055d0c * fVar11 + fRam10055cbc) * fVar11 + fRam10055c9c) * fVar11 + fRam10055c7c)
          * fVar5;
  fVar1 = (((_DAT_10055cf0 * fVar25 + _DAT_10055ca0) * fVar25 + _DAT_10055c80) * fVar25 +
          _DAT_10055c60) * fVar25 + _DAT_10055c50;
  fVar4 = (((fRam10055cf4 * fVar8 + fRam10055ca4) * fVar8 + fRam10055c84) * fVar8 + fRam10055c64) *
          fVar8 + fRam10055c54;
  fVar25 = (((fRam10055cf8 * fVar26 + fRam10055ca8) * fVar26 + fRam10055c88) * fVar26 + fRam10055c68
           ) * fVar26 + fRam10055c58;
  fVar7 = (((fRam10055cfc * fVar11 + fRam10055cac) * fVar11 + fRam10055c8c) * fVar11 + fRam10055c6c)
          * fVar11 + fRam10055c5c;
  *param_2 = (~uVar19 & (uint)fVar16 | uVar19 & (uint)fVar1) ^
             (uVar18 - uVar3 & _DAT_10055cc0) << 0x1e ^ *param_1 & _DAT_10055d70;
  param_2[1] = (~uVar6 & (uint)fVar2 | uVar6 & (uint)fVar4) ^ uVar20 << 0x1e ^ uVar13;
  param_2[2] = (~uVar9 & (uint)fVar17 | uVar9 & (uint)fVar25) ^ uVar22 << 0x1e ^ uVar14;
  param_2[3] = (~uVar12 & (uint)fVar5 | uVar12 & (uint)fVar7) ^ uVar24 << 0x1e ^ uVar15;
  *param_3 = (uVar19 & (uint)fVar16 | ~uVar19 & (uint)fVar1) ^ uVar27 << 0x1e;
  param_3[1] = (uVar6 & (uint)fVar2 | ~uVar6 & (uint)fVar4) ^ uVar28 << 0x1e;
  param_3[2] = (uVar9 & (uint)fVar17 | ~uVar9 & (uint)fVar25) ^ uVar21 << 0x1e;
  param_3[3] = (uVar12 & (uint)fVar5 | ~uVar12 & (uint)fVar7) ^ uVar23 << 0x1e;
  return;
}



