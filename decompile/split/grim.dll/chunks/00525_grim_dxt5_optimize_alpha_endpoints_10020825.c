/* grim_dxt5_optimize_alpha_endpoints @ 10020825 */

/* iteratively chooses DXT5 alpha endpoints for 6/8-alpha modes */

void __cdecl
grim_dxt5_optimize_alpha_endpoints(float *min_out,float *max_out,float *alphas,uint mode)

{
  float fVar1;
  float *pfVar2;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  uint uVar6;
  float local_54 [6];
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  float local_30;
  float local_2c;
  float local_28;
  uint local_24;
  undefined4 *local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (mode == 6) {
    pfVar5 = (float *)&grim_dxt5_alpha_weights_min_6;
    local_20 = &grim_dxt5_alpha_weights_max_6;
  }
  else {
    pfVar5 = (float *)&grim_dxt5_alpha_weights_min_8;
    local_20 = (undefined4 *)&grim_dxt5_alpha_weights_max_8;
  }
  uVar3 = 0;
  local_8 = 1.0;
  local_c = 0.0;
  if (mode == 8) {
    do {
      pfVar2 = alphas + uVar3;
      if (*pfVar2 < local_8) {
        local_8 = *pfVar2;
      }
      if (local_c < *pfVar2) {
        local_c = *pfVar2;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x10);
  }
  else {
    do {
      pfVar2 = alphas + uVar3;
      if ((*pfVar2 < local_8) && (0.0 < *pfVar2)) {
        local_8 = *pfVar2;
      }
      if ((local_c < *pfVar2) && (*pfVar2 < 1.0)) {
        local_c = *pfVar2;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x10);
  }
  uVar3 = mode - 1;
  local_28 = (float)(int)uVar3;
  if ((int)uVar3 < 0) {
    local_28 = local_28 + 4.2949673e+09;
  }
  local_34 = uVar3;
  fpu_save_control_word();
  local_24 = 0;
  while (0.00390625 <= local_c - local_8) {
    local_2c = local_28 / (local_c - local_8);
    if (mode != 0) {
      iVar4 = (int)local_20 - (int)pfVar5;
      pfVar2 = pfVar5;
      uVar6 = mode;
      do {
        *(float *)(((int)local_54 - (int)pfVar5) + (int)pfVar2) =
             local_8 * *pfVar2 + local_c * *(float *)(iVar4 + (int)pfVar2);
        pfVar2 = pfVar2 + 1;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    if (mode == 6) {
      local_3c = 0;
      local_38 = 0x3f800000;
    }
    uVar6 = 0;
    local_10 = 0.0;
    local_14 = 0.0;
    local_18 = 0.0;
    local_1c = 0.0;
    do {
      pfVar2 = alphas + uVar6;
      fVar1 = (*pfVar2 - local_8) * local_2c;
      if (fVar1 < 0.0 == (fVar1 == 0.0)) {
        if (fVar1 < local_28) {
          local_30 = fVar1 + 0.5;
          local_34 = (uint)ROUND(fVar1 + 0.5);
        }
        else {
          local_34 = uVar3;
          if ((mode == 6) && (fVar1 = (local_c + 1.0) * 0.5, fVar1 < *pfVar2 != (fVar1 == *pfVar2)))
          goto LAB_10020a28;
        }
LAB_100209e6:
        if (local_34 < mode) {
          local_10 = (*pfVar2 - local_54[local_34]) * pfVar5[local_34] + local_10;
          local_18 = pfVar5[local_34] * pfVar5[local_34] + local_18;
          local_14 = (*pfVar2 - local_54[local_34]) * (float)local_20[local_34] + local_14;
          fVar1 = (float)local_20[local_34];
          local_1c = fVar1 * fVar1 + local_1c;
        }
      }
      else if ((mode != 6) || (local_8 * 0.5 < *pfVar2)) {
        local_34 = 0;
        goto LAB_100209e6;
      }
LAB_10020a28:
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0x10);
    if (0.0 < local_18) {
      local_8 = local_8 - local_10 / local_18;
    }
    if (0.0 < local_1c) {
      local_c = local_c - local_14 / local_1c;
    }
    fVar1 = local_c;
    if (local_c < local_8) {
      local_c = local_8;
      local_8 = fVar1;
    }
    if (((local_10 * local_10 < 0.015625) && (local_14 * local_14 < 0.015625)) ||
       (local_24 = local_24 + 1, 7 < local_24)) break;
  }
  if (0.0 <= local_8) {
    if (1.0 < local_8) {
      local_8 = 1.0;
    }
  }
  else {
    local_8 = 0.0;
  }
  *min_out = local_8;
  if (0.0 <= local_c) {
    if (1.0 < local_c) {
      local_c = 1.0;
    }
  }
  else {
    local_c = 0.0;
  }
  *max_out = local_c;
  return;
}



