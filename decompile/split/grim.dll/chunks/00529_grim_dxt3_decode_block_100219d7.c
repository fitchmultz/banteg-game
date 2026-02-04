/* grim_dxt3_decode_block @ 100219d7 */

/* WARNING: Removing unreachable block (ram,0x10021a10) */
/* WARNING: Removing unreachable block (ram,0x10021a3f) */
/* decodes a DXT3 block (explicit alpha + DXT1 color) to RGBA floats */

int __cdecl grim_dxt3_decode_block(float *out_rgba,uint *block)

{
  int iVar1;
  float *pfVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = grim_dxt1_decode_color_block(out_rgba,(ushort *)(block + 2));
  if (-1 < iVar1) {
    uVar3 = *block;
    iVar1 = 8;
    pfVar2 = out_rgba + 3;
    do {
      uVar4 = uVar3 & 0xf;
      uVar3 = uVar3 >> 4;
      *pfVar2 = (float)uVar4 * 0.06666667;
      pfVar2 = pfVar2 + 4;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    uVar3 = block[1];
    iVar1 = 8;
    pfVar2 = out_rgba + 0x23;
    do {
      uVar4 = uVar3 & 0xf;
      uVar3 = uVar3 >> 4;
      *pfVar2 = (float)uVar4 * 0.06666667;
      pfVar2 = pfVar2 + 4;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    iVar1 = 0;
  }
  return iVar1;
}



