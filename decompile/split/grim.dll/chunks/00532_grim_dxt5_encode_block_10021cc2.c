/* grim_dxt5_encode_block @ 10021cc2 */

/* encodes a 4x4 RGBA block into DXT5 (interpolated alpha + DXT1 color) */

int __cdecl grim_dxt5_encode_block(uchar *out_block,float *rgba)

{
  float fVar1;
  float fVar2;
  uchar *puVar3;
  uchar uVar4;
  uint uVar5;
  uchar uVar6;
  int iVar7;
  uint uVar8;
  float *pfVar9;
  float fVar10;
  uint uVar11;
  float *pfVar12;
  float local_a4 [32];
  int local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined *local_14;
  float *local_10;
  float *local_c;
  float local_8;
  
  pfVar9 = rgba + 3;
  local_10 = (float *)*pfVar9;
  pfVar12 = local_a4;
  local_c = local_10;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *pfVar12 = 0.0;
    pfVar12 = pfVar12 + 1;
  }
  fpu_save_control_word();
  puVar3 = out_block;
  uVar8 = 0;
  pfVar12 = pfVar9;
  do {
    local_18 = local_a4[uVar8] + *pfVar12;
    local_14 = (undefined *)(int)ROUND(local_18 * 255.0 + 0.5);
    local_8 = (float)local_14;
    fVar10 = (float)(int)local_14 * 0.003921569;
    local_a4[uVar8 + 0x10] = fVar10;
    if ((float)local_c <= fVar10) {
      if ((float)local_10 < fVar10) {
        local_10 = (float *)fVar10;
      }
    }
    else {
      local_c = (float *)fVar10;
    }
    fVar10 = local_18 - fVar10;
    uVar11 = uVar8 & 3;
    if (uVar11 != 3) {
      local_a4[uVar8 + 1] = fVar10 * 0.4375 + local_a4[uVar8 + 1];
    }
    if (uVar8 < 0xc) {
      if (uVar11 != 0) {
        local_a4[uVar8 + 3] = fVar10 * 0.1875 + local_a4[uVar8 + 3];
      }
      local_a4[uVar8 + 4] = fVar10 * 0.3125 + local_a4[uVar8 + 4];
      if (uVar11 != 3) {
        local_a4[uVar8 + 5] = fVar10 * 0.0625 + local_a4[uVar8 + 5];
      }
    }
    uVar8 = uVar8 + 1;
    pfVar12 = pfVar12 + 4;
  } while (uVar8 < 0x10);
  local_8 = fpu_control_word_saved_dxt;
  iVar7 = grim_dxt1_encode_color_block((ushort *)(out_block + 8),0.0);
  if (iVar7 < 0) {
    return iVar7;
  }
  if ((float)local_c == 1.0) {
    *puVar3 = 0xff;
    puVar3[1] = 0xff;
LAB_10021ea4:
    puVar3[2] = '\0';
    puVar3[3] = '\0';
    puVar3[4] = '\0';
    puVar3[5] = '\0';
    puVar3[6] = '\0';
    puVar3[7] = '\0';
  }
  else {
    if (((float)local_c == 0.0) || ((float)local_10 == 1.0)) {
      rgba = (float *)0x6;
      uVar8 = 6;
    }
    else {
      uVar8 = 8;
      rgba = (float *)0x8;
    }
    grim_dxt5_optimize_alpha_endpoints(&local_8,(float *)&out_block,local_a4 + 0x10,uVar8);
    fpu_save_control_word();
    uVar11 = (uint)ROUND(local_8 * 255.0 + 0.5);
    local_8 = (float)(int)ROUND((float)out_block * 255.0 + 0.5);
    fVar10 = (float)(uVar11 & 0xff) * 0.003921569;
    local_a4[0x19] = (float)((uint)local_8 & 0xff) * 0.003921569;
    uVar4 = (uchar)uVar11;
    uVar6 = SUB41(local_8,0);
    if (uVar8 == 8) {
      if (uVar4 == uVar6) {
        *puVar3 = uVar4;
        puVar3[1] = uVar6;
        goto LAB_10021ea4;
      }
LAB_10021f19:
      puVar3[1] = uVar4;
      *puVar3 = uVar6;
      uVar11 = 1;
      do {
        fVar1 = (float)(int)(7 - uVar11);
        if ((int)(7 - uVar11) < 0) {
          fVar1 = fVar1 + 4.2949673e+09;
        }
        fVar2 = (float)(int)uVar11;
        if ((int)uVar11 < 0) {
          fVar2 = fVar2 + 4.2949673e+09;
        }
        uVar5 = uVar11 + 1;
        local_a4[uVar11 + 0x19] = (fVar2 * fVar10 + fVar1 * local_a4[0x19]) * 0.14285715;
        uVar11 = uVar5;
      } while (uVar5 < 7);
      local_14 = &grim_dxt5_alpha_index_map_8;
      local_a4[0x18] = local_a4[0x19];
      local_a4[0x19] = fVar10;
    }
    else {
      if (uVar8 != 6) goto LAB_10021f19;
      *puVar3 = uVar4;
      puVar3[1] = uVar6;
      uVar11 = 1;
      do {
        fVar1 = (float)(int)(5 - uVar11);
        if ((int)(5 - uVar11) < 0) {
          fVar1 = fVar1 + 4.2949673e+09;
        }
        fVar2 = (float)(int)uVar11;
        if ((int)uVar11 < 0) {
          fVar2 = fVar2 + 4.2949673e+09;
        }
        uVar5 = uVar11 + 1;
        local_a4[uVar11 + 0x19] = (fVar2 * local_a4[0x19] + fVar1 * fVar10) * 0.2;
        uVar11 = uVar5;
      } while (uVar5 < 5);
      local_14 = &grim_dxt5_alpha_index_map_6;
      local_a4[0x1e] = 0.0;
      local_a4[0x1f] = 1.0;
      local_a4[0x18] = fVar10;
    }
    out_block = (uchar *)(uVar8 - 1);
    local_1c = (float)(int)out_block;
    if ((int)out_block < 0) {
      local_1c = local_1c + 4.2949673e+09;
    }
    if (local_a4[0x18] == local_a4[0x19]) {
      local_18 = 0.0;
    }
    else {
      local_18 = local_1c / (local_a4[0x19] - local_a4[0x18]);
    }
    pfVar12 = local_a4;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pfVar12 = 0.0;
      pfVar12 = pfVar12 + 1;
    }
    fpu_save_control_word();
    local_c = pfVar9;
    fVar10 = 0.0;
    do {
      uVar8 = 0;
      out_block._2_1_ = '\0';
      local_8 = (float)((int)fVar10 + 8U);
      if ((uint)fVar10 < (int)fVar10 + 8U) {
        local_10 = local_c;
        do {
          fVar1 = local_a4[(int)fVar10] + *local_10;
          fVar2 = (fVar1 - local_a4[0x18]) * local_18;
          if (fVar2 < 0.0 == (fVar2 == 0.0)) {
            if (fVar2 < local_1c) {
              local_20 = fVar2 + 0.5;
              local_24 = (int)ROUND(fVar2 + 0.5);
              iVar7 = *(int *)(local_14 + local_24 * 4);
            }
            else if ((rgba == (float *)0x6) &&
                    (fVar2 = (local_a4[0x19] + 1.0) * 0.5, fVar2 < fVar1 != (fVar2 == fVar1))) {
              iVar7 = 7;
            }
            else {
              iVar7 = 1;
            }
          }
          else if ((rgba != (float *)0x6) || (local_a4[0x18] * 0.5 < fVar1)) {
            iVar7 = 0;
          }
          else {
            iVar7 = 6;
          }
          fVar1 = fVar1 - local_a4[iVar7 + 0x18];
          uVar8 = uVar8 >> 3 | iVar7 << 0x15;
          uVar11 = (uint)fVar10 & 3;
          if (uVar11 != 3) {
            local_a4[(int)fVar10 + 1] = fVar1 * 0.4375 + local_a4[(int)fVar10 + 1];
          }
          if ((uint)fVar10 < 0xc) {
            if (uVar11 != 0) {
              local_a4[(int)fVar10 + 3] = fVar1 * 0.1875 + local_a4[(int)fVar10 + 3];
            }
            local_a4[(int)fVar10 + 4] = fVar1 * 0.3125 + local_a4[(int)fVar10 + 4];
            if (uVar11 != 3) {
              local_a4[(int)fVar10 + 5] = fVar1 * 0.0625 + local_a4[(int)fVar10 + 5];
            }
          }
          local_10 = local_10 + 4;
          fVar10 = (float)((int)fVar10 + 1);
        } while ((uint)fVar10 < (uint)local_8);
        out_block._2_1_ = (uchar)(uVar8 >> 0x10);
      }
      local_c = local_c + 0x20;
      puVar3[4] = out_block._2_1_;
      puVar3[2] = (uchar)uVar8;
      puVar3[3] = (uchar)(uVar8 >> 8);
      fVar10 = local_8;
      puVar3 = puVar3 + 3;
    } while ((uint)local_8 < 0x10);
  }
  return 0;
}



