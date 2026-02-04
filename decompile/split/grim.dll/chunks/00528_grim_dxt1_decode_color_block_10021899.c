/* grim_dxt1_decode_color_block @ 10021899 */

/* decodes a DXT1 color block into 16 RGBA floats */

int __cdecl grim_dxt1_decode_color_block(float *out_rgba,ushort *block)

{
  float *pfVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  uint in_EDX;
  uint rgb565;
  uint uVar5;
  uint uVar6;
  float local_5c [4];
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  float local_c;
  float local_8;
  
  uVar2 = *block;
  grim_dxt_decode_rgb565((float *)(uint)uVar2,in_EDX);
  uVar3 = block[1];
  grim_dxt_decode_rgb565((float *)(uint)uVar3,rgb565);
  if (uVar3 < uVar2) {
    local_3c = (local_4c - local_5c[0]) * 0.33333334 + local_5c[0];
    local_38 = (local_48 - local_5c[1]) * 0.33333334 + local_5c[1];
    local_8 = local_44 - local_5c[2];
    local_34 = local_8 * 0.33333334 + local_5c[2];
    local_c = local_40 - local_5c[3];
    local_30 = local_c * 0.33333334 + local_5c[3];
    local_2c = (local_4c - local_5c[0]) * 0.6666667 + local_5c[0];
    local_28 = (local_48 - local_5c[1]) * 0.6666667 + local_5c[1];
    local_24 = local_8 * 0.6666667 + local_5c[2];
    local_20 = local_c * 0.6666667 + local_5c[3];
  }
  else {
    local_3c = (local_4c - local_5c[0]) * 0.5 + local_5c[0];
    local_38 = (local_48 - local_5c[1]) * 0.5 + local_5c[1];
    local_34 = (local_44 - local_5c[2]) * 0.5 + local_5c[2];
    local_30 = (local_40 - local_5c[3]) * 0.5 + local_5c[3];
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_2c = 0.0;
    local_28 = 0.0;
    local_24 = 0.0;
    local_20 = 0.0;
  }
  uVar6 = *(uint *)(block + 2);
  iVar4 = 0x10;
  do {
    uVar5 = uVar6 & 3;
    *out_rgba = local_5c[uVar5 * 4];
    out_rgba[1] = local_5c[uVar5 * 4 + 1];
    pfVar1 = out_rgba + 3;
    out_rgba[2] = local_5c[uVar5 * 4 + 2];
    out_rgba = out_rgba + 4;
    uVar6 = uVar6 >> 2;
    iVar4 = iVar4 + -1;
    *pfVar1 = local_5c[uVar5 * 4 + 3];
  } while (iVar4 != 0);
  return 0;
}



