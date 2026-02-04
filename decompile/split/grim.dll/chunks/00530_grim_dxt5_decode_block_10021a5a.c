/* grim_dxt5_decode_block @ 10021a5a */

/* decodes a DXT5 block (interpolated alpha + DXT1 color) to RGBA floats */

int __cdecl grim_dxt5_decode_block(float *out_rgba,uchar *block)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  uint uVar6;
  float local_24 [8];
  
  iVar3 = grim_dxt1_decode_color_block(out_rgba,(ushort *)(block + 8));
  if (-1 < iVar3) {
    local_24[0] = (float)*block * 0.003921569;
    local_24[1] = (float)block[1] * 0.003921569;
    if (block[1] < *block) {
      uVar4 = 1;
      do {
        fVar1 = (float)(int)(7 - uVar4);
        if ((int)(7 - uVar4) < 0) {
          fVar1 = fVar1 + 4.2949673e+09;
        }
        fVar2 = (float)(int)uVar4;
        if ((int)uVar4 < 0) {
          fVar2 = fVar2 + 4.2949673e+09;
        }
        uVar4 = uVar4 + 1;
        local_24[uVar4] = (fVar2 * local_24[1] + fVar1 * local_24[0]) * 0.14285715;
      } while (uVar4 < 7);
    }
    else {
      uVar4 = 1;
      do {
        fVar1 = (float)(int)(5 - uVar4);
        if ((int)(5 - uVar4) < 0) {
          fVar1 = fVar1 + 4.2949673e+09;
        }
        fVar2 = (float)(int)uVar4;
        if ((int)uVar4 < 0) {
          fVar2 = fVar2 + 4.2949673e+09;
        }
        uVar4 = uVar4 + 1;
        local_24[uVar4] = (fVar2 * local_24[1] + fVar1 * local_24[0]) * 0.2;
      } while (uVar4 < 5);
      local_24[6] = 0.0;
      local_24[7] = 1.0;
    }
    iVar3 = 8;
    uVar4 = (uint)*(uint3 *)(block + 2);
    pfVar5 = out_rgba + 3;
    do {
      uVar6 = uVar4 & 7;
      uVar4 = uVar4 >> 3;
      *pfVar5 = local_24[uVar6];
      pfVar5 = pfVar5 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = 8;
    uVar4 = (uint)*(uint3 *)(block + 5);
    pfVar5 = out_rgba + 0x23;
    do {
      uVar6 = uVar4 & 7;
      uVar4 = uVar4 >> 3;
      *pfVar5 = local_24[uVar6];
      pfVar5 = pfVar5 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = 0;
  }
  return iVar3;
}



