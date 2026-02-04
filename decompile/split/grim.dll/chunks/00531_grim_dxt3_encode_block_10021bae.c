/* grim_dxt3_encode_block @ 10021bae */

/* encodes a 4x4 RGBA block into DXT3 (explicit alpha + DXT1 color) */

void __cdecl grim_dxt3_encode_block(uint *out_block,float *rgba)

{
  uint *puVar1;
  float fVar2;
  uint *puVar3;
  int iVar4;
  uint *extraout_EDX;
  uint uVar5;
  float *pfVar6;
  float local_54 [16];
  int local_14;
  int local_10;
  float local_c;
  float *local_8;
  
  puVar3 = out_block;
  *out_block = 0;
  out_block[1] = 0;
  pfVar6 = local_54;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar6 = 0.0;
    pfVar6 = pfVar6 + 1;
  }
  fpu_save_control_word();
  local_8 = rgba + 3;
  out_block = extraout_EDX;
  do {
    local_c = local_54[(int)out_block] + *local_8;
    local_14 = (int)ROUND(local_c * 15.0 + 0.5);
    puVar1 = puVar3 + ((uint)out_block >> 3);
    local_10 = local_14;
    fVar2 = (float)local_14;
    *puVar1 = *puVar1 >> 4 | local_14 << 0x1c;
    if (local_14 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    uVar5 = (uint)out_block & 3;
    fVar2 = local_c - fVar2 * 0.06666667;
    if (uVar5 != 3) {
      local_54[(int)out_block + 1] = fVar2 * 0.4375 + local_54[(int)out_block + 1];
    }
    if (out_block < (uint *)0xc) {
      if (uVar5 != 0) {
        local_54[(int)out_block + 3] = fVar2 * 0.1875 + local_54[(int)out_block + 3];
      }
      local_54[(int)(out_block + 1)] = fVar2 * 0.3125 + local_54[(int)(out_block + 1)];
      if (uVar5 != 3) {
        local_54[(int)out_block + 5] = fVar2 * 0.0625 + local_54[(int)out_block + 5];
      }
    }
    out_block = (uint *)((int)out_block + 1);
    local_8 = local_8 + 4;
  } while (out_block < (uint *)0x10);
  grim_dxt1_encode_color_block((ushort *)(puVar3 + 2),0.0);
  return;
}



