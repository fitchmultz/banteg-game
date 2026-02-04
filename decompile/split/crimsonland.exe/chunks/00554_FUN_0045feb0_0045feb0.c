/* FUN_0045feb0 @ 0045feb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0045feb0(uint *param_1,uint *param_2,uint *param_3)

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
  
  fVar16 = (float)(*param_1 & _DAT_0047afc0);
  fVar17 = (float)(param_1[1] & uRam0047afc4);
  fVar25 = (float)(param_1[2] & uRam0047afc8);
  fVar26 = (float)(param_1[3] & uRam0047afcc);
  uVar13 = param_1[1] & uRam0047afb4;
  uVar14 = param_1[2] & uRam0047afb8;
  uVar15 = param_1[3] & uRam0047afbc;
  fVar1 = fVar16 * _DAT_0047afa0 + _DAT_0047af50;
  fVar4 = fVar17 * fRam0047afa4 + fRam0047af54;
  fVar7 = fVar25 * fRam0047afa8 + fRam0047af58;
  fVar10 = fVar26 * fRam0047afac + fRam0047af5c;
  fVar2 = fVar1 - _DAT_0047af50;
  fVar5 = fVar4 - fRam0047af54;
  fVar8 = fVar7 - fRam0047af58;
  fVar11 = fVar10 - fRam0047af5c;
  fVar16 = (((fVar16 - _DAT_0047af90 * fVar2) - _DAT_0047af80 * fVar2) - _DAT_0047af70 * fVar2) -
           _DAT_0047af60 * fVar2;
  fVar2 = (((fVar17 - fRam0047af94 * fVar5) - fRam0047af84 * fVar5) - fRam0047af74 * fVar5) -
          fRam0047af64 * fVar5;
  fVar17 = (((fVar25 - fRam0047af98 * fVar8) - fRam0047af88 * fVar8) - fRam0047af78 * fVar8) -
           fRam0047af68 * fVar8;
  fVar5 = (((fVar26 - fRam0047af9c * fVar11) - fRam0047af8c * fVar11) - fRam0047af7c * fVar11) -
          fRam0047af6c * fVar11;
  fVar25 = fVar16 * fVar16;
  fVar8 = fVar2 * fVar2;
  fVar26 = fVar17 * fVar17;
  fVar11 = fVar5 * fVar5;
  uVar18 = (uint)fVar1 & _DAT_0047af20;
  uVar19 = (uint)fVar4 & uRam0047af24;
  uVar21 = (uint)fVar7 & uRam0047af28;
  uVar23 = (uint)fVar10 & uRam0047af2c;
  uVar3 = uVar18 & _DAT_0047af10;
  uVar6 = uVar19 & uRam0047af14;
  uVar9 = uVar21 & uRam0047af18;
  uVar12 = uVar23 & uRam0047af1c;
  uVar20 = uVar19 - uVar6 & uRam0047af04;
  uVar22 = uVar21 - uVar9 & uRam0047af08;
  uVar24 = uVar23 - uVar12 & uRam0047af0c;
  uVar27 = uVar18 + uVar3 & _DAT_0047af00;
  uVar28 = uVar19 + uVar6 & uRam0047af04;
  uVar21 = uVar21 + uVar9 & uRam0047af08;
  uVar23 = uVar23 + uVar12 & uRam0047af0c;
  uVar19 = -(uint)((float)(uVar3 << 0x1e) != 0.0);
  uVar6 = -(uint)((float)(uVar6 << 0x1e) != 0.0);
  uVar9 = -(uint)((float)(uVar9 << 0x1e) != 0.0);
  uVar12 = -(uint)((float)(uVar12 << 0x1e) != 0.0);
  fVar16 = (((_DAT_0047af40 * fVar25 + _DAT_0047aef0) * fVar25 + _DAT_0047aed0) * fVar25 +
           _DAT_0047aeb0) * fVar16;
  fVar2 = (((fRam0047af44 * fVar8 + fRam0047aef4) * fVar8 + fRam0047aed4) * fVar8 + fRam0047aeb4) *
          fVar2;
  fVar17 = (((fRam0047af48 * fVar26 + fRam0047aef8) * fVar26 + fRam0047aed8) * fVar26 + fRam0047aeb8
           ) * fVar17;
  fVar5 = (((fRam0047af4c * fVar11 + fRam0047aefc) * fVar11 + fRam0047aedc) * fVar11 + fRam0047aebc)
          * fVar5;
  fVar1 = (((_DAT_0047af30 * fVar25 + _DAT_0047aee0) * fVar25 + _DAT_0047aec0) * fVar25 +
          _DAT_0047aea0) * fVar25 + _DAT_0047ae90;
  fVar4 = (((fRam0047af34 * fVar8 + fRam0047aee4) * fVar8 + fRam0047aec4) * fVar8 + fRam0047aea4) *
          fVar8 + fRam0047ae94;
  fVar25 = (((fRam0047af38 * fVar26 + fRam0047aee8) * fVar26 + fRam0047aec8) * fVar26 + fRam0047aea8
           ) * fVar26 + fRam0047ae98;
  fVar7 = (((fRam0047af3c * fVar11 + fRam0047aeec) * fVar11 + fRam0047aecc) * fVar11 + fRam0047aeac)
          * fVar11 + fRam0047ae9c;
  *param_2 = (~uVar19 & (uint)fVar16 | uVar19 & (uint)fVar1) ^
             (uVar18 - uVar3 & _DAT_0047af00) << 0x1e ^ *param_1 & _DAT_0047afb0;
  param_2[1] = (~uVar6 & (uint)fVar2 | uVar6 & (uint)fVar4) ^ uVar20 << 0x1e ^ uVar13;
  param_2[2] = (~uVar9 & (uint)fVar17 | uVar9 & (uint)fVar25) ^ uVar22 << 0x1e ^ uVar14;
  param_2[3] = (~uVar12 & (uint)fVar5 | uVar12 & (uint)fVar7) ^ uVar24 << 0x1e ^ uVar15;
  *param_3 = (uVar19 & (uint)fVar16 | ~uVar19 & (uint)fVar1) ^ uVar27 << 0x1e;
  param_3[1] = (uVar6 & (uint)fVar2 | ~uVar6 & (uint)fVar4) ^ uVar28 << 0x1e;
  param_3[2] = (uVar9 & (uint)fVar17 | ~uVar9 & (uint)fVar25) ^ uVar21 << 0x1e;
  param_3[3] = (uVar12 & (uint)fVar5 | ~uVar12 & (uint)fVar7) ^ uVar23 << 0x1e;
  return;
}



