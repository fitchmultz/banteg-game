/* grim_dxt1_optimize_color_endpoints @ 10020b2a */

/* optimizes DXT1 color endpoints for 3- or 4-color mode */

void __cdecl
grim_dxt1_optimize_color_endpoints(float *min_out,float *max_out,float *rgba,float mode)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float *pfVar11;
  int iVar12;
  float *pfVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  float fVar17;
  float local_c4 [16];
  float *local_84;
  int local_80;
  float local_7c;
  float local_78;
  float local_74;
  float *local_6c;
  undefined4 *local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_34 [6];
  float local_1c;
  float local_14;
  float local_10;
  float local_c;
  undefined4 uStack_8;
  
  fVar10 = mode;
  if (mode == 4.2039e-45) {
    local_6c = (float *)&grim_dxt1_color_weights_min_3;
    local_68 = &grim_dxt1_color_weights_max_3;
  }
  else {
    local_6c = (float *)&grim_dxt1_color_weights_min_4;
    local_68 = (undefined4 *)&grim_dxt1_color_weights_max_4;
  }
  local_34[4] = 0.0;
  fVar17 = 0.0;
  local_14 = DAT_100544c0;
  local_10 = DAT_100544c4;
  local_1c = 0.0;
  local_c = DAT_100544c8;
  uStack_8 = DAT_100544cc;
  pfVar11 = rgba + 2;
  iVar12 = 0x10;
  local_84 = pfVar11;
  pfVar13 = pfVar11;
  iVar14 = iVar12;
  do {
    if (pfVar13[-2] < local_14) {
      local_14 = pfVar13[-2];
    }
    if (pfVar13[-1] < local_10) {
      local_10 = pfVar13[-1];
    }
    if (*pfVar13 < local_c) {
      local_c = *pfVar13;
    }
    if (local_34[4] < pfVar13[-2]) {
      local_34[4] = pfVar13[-2];
    }
    if (fVar17 < pfVar13[-1]) {
      fVar17 = pfVar13[-1];
    }
    if (local_1c < *pfVar13) {
      local_1c = *pfVar13;
    }
    fVar4 = local_1c;
    pfVar13 = pfVar13 + 4;
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  local_34[5] = fVar17;
  fVar7 = local_34[4] - local_14;
  fVar6 = fVar17 - local_10;
  fVar5 = local_1c - local_c;
  local_48 = fVar7 * fVar7 + fVar6 * fVar6 + fVar5 * fVar5;
  if (1.1754944e-38 <= local_48) {
    fVar8 = 1.0 / local_48;
    local_7c = fVar7 * fVar8;
    local_78 = fVar6 * fVar8;
    local_74 = fVar8 * fVar5;
    local_58 = (local_34[4] + local_14) * 0.5;
    local_54 = (fVar17 + local_10) * 0.5;
    local_50 = (local_1c + local_c) * 0.5;
    local_34[3] = 0.0;
    local_34[2] = 0.0;
    local_34[1] = 0.0;
    fVar3 = 0.0;
    do {
      local_44 = (pfVar11[-2] - local_58) * fVar7 * fVar8;
      local_40 = (pfVar11[-1] - local_54) * fVar6 * fVar8;
      fVar2 = *pfVar11;
      pfVar11 = pfVar11 + 4;
      iVar12 = iVar12 + -1;
      fVar2 = (fVar2 - local_50) * fVar8 * fVar5;
      fVar9 = local_40 + fVar2 + local_44;
      fVar3 = fVar9 * fVar9 + fVar3;
      fVar9 = (local_40 + local_44) - fVar2;
      local_34[1] = fVar9 * fVar9 + local_34[1];
      fVar9 = (local_44 - local_40) + fVar2;
      local_34[2] = fVar9 * fVar9 + local_34[2];
      fVar2 = (local_44 - local_40) - fVar2;
      local_34[3] = fVar2 * fVar2 + local_34[3];
    } while (iVar12 != 0);
    local_34[0] = fVar3;
    uVar16 = 0;
    uVar15 = 1;
    do {
      if (fVar3 < local_34[uVar15]) {
        fVar3 = local_34[uVar15];
        uVar16 = uVar15;
      }
      uVar15 = uVar15 + 1;
    } while (uVar15 < 4);
    if ((uVar16 & 2) != 0) {
      local_34[5] = local_10;
      local_10 = fVar17;
    }
    if ((uVar16 & 1) != 0) {
      local_1c = local_c;
      local_c = fVar4;
    }
    if (0.00024414062 <= local_48) {
      local_60 = (float)((int)mode + -1);
      if ((int)mode + -1 < 0) {
        local_60 = local_60 + 4.2949673e+09;
      }
      fpu_save_control_word();
      local_48 = 0.0;
      while( true ) {
        iVar12 = 0x10;
        if (fVar10 != 0.0) {
          pfVar13 = local_c4 + 1;
          iVar14 = (int)local_68 - (int)local_6c;
          pfVar11 = local_6c;
          fVar17 = fVar10;
          do {
            pfVar13[-1] = local_34[4] * *(float *)(iVar14 + (int)pfVar11) + local_14 * *pfVar11;
            *pfVar13 = local_34[5] * *(float *)(iVar14 + (int)pfVar11) + local_10 * *pfVar11;
            fVar4 = *pfVar11;
            pfVar1 = (float *)(iVar14 + (int)pfVar11);
            pfVar11 = pfVar11 + 1;
            pfVar13[1] = local_1c * *pfVar1 + local_c * fVar4;
            pfVar13 = pfVar13 + 4;
            fVar17 = (float)((int)fVar17 + -1);
          } while (fVar17 != 0.0);
        }
        fVar17 = local_34[4] - local_14;
        fVar7 = local_34[5] - local_10;
        fVar6 = local_1c - local_c;
        fVar4 = fVar17 * fVar17 + fVar7 * fVar7 + fVar6 * fVar6;
        if (fVar4 < 0.00024414062) break;
        fVar4 = local_60 / fVar4;
        local_44 = fVar4 * fVar17;
        local_40 = fVar7 * fVar4;
        local_3c = fVar4 * fVar6;
        local_34[2] = 0.0;
        local_34[1] = 0.0;
        local_34[0] = 0.0;
        local_50 = 0.0;
        local_54 = 0.0;
        local_58 = 0.0;
        local_5c = 0.0;
        mode = 0.0;
        pfVar13 = local_84;
        do {
          fVar5 = (*pfVar13 - local_c) * fVar4 * fVar6 +
                  (pfVar13[-2] - local_14) * fVar4 * fVar17 +
                  (pfVar13[-1] - local_10) * fVar7 * fVar4;
          local_64 = fVar5;
          if (fVar5 < local_60) {
            local_64 = fVar5 + 0.5;
            local_80 = (int)ROUND(fVar5 + 0.5);
          }
          else {
            local_80 = (int)fVar10 + -1;
          }
          pfVar11 = pfVar13 + -2;
          local_78 = local_c4[local_80 * 4 + 1] - pfVar13[-1];
          fVar5 = *pfVar13;
          fVar3 = local_6c[local_80] * 0.125;
          pfVar13 = pfVar13 + 4;
          iVar12 = iVar12 + -1;
          fVar8 = (float)local_68[local_80] * 0.125;
          mode = fVar3 * local_6c[local_80] + mode;
          local_58 = fVar3 * (local_c4[local_80 * 4] - *pfVar11) + local_58;
          local_54 = fVar3 * local_78 + local_54;
          local_50 = fVar3 * (local_c4[local_80 * 4 + 2] - fVar5) + local_50;
          local_5c = fVar8 * (float)local_68[local_80] + local_5c;
          local_34[0] = fVar8 * (local_c4[local_80 * 4] - *pfVar11) + local_34[0];
          local_34[1] = local_78 * fVar8 + local_34[1];
          local_34[2] = fVar8 * (local_c4[local_80 * 4 + 2] - fVar5) + local_34[2];
        } while (iVar12 != 0);
        if (0.0 < mode) {
          fVar17 = -1.0 / mode;
          local_14 = local_58 * fVar17 + local_14;
          local_10 = local_54 * fVar17 + local_10;
          local_c = fVar17 * local_50 + local_c;
        }
        if (0.0 < local_5c) {
          local_5c = -1.0 / local_5c;
          local_34[4] = local_34[0] * local_5c + local_34[4];
          local_34[5] = local_34[1] * local_5c + local_34[5];
          local_1c = local_5c * local_34[2] + local_1c;
        }
        if (((((local_58 * local_58 < 1.5258789e-05) && (local_54 * local_54 < 1.5258789e-05)) &&
             (local_50 * local_50 < 1.5258789e-05)) &&
            (((local_34[0] * local_34[0] < 1.5258789e-05 &&
              (local_34[1] * local_34[1] < 1.5258789e-05)) &&
             (local_34[2] * local_34[2] < 1.5258789e-05)))) ||
           (local_48 = (float)((int)local_48 + 1), 7 < (uint)local_48)) break;
      }
      *min_out = local_14;
      min_out[1] = local_10;
      min_out[2] = local_c;
      *max_out = local_34[4];
      max_out[1] = local_34[5];
    }
    else {
      *min_out = local_14;
      min_out[1] = local_10;
      min_out[2] = local_c;
      max_out[1] = local_34[5];
      *max_out = local_34[4];
    }
  }
  else {
    *min_out = local_14;
    min_out[1] = local_10;
    min_out[2] = local_c;
    max_out[1] = fVar17;
    *max_out = local_34[4];
  }
  max_out[2] = local_1c;
  return;
}



