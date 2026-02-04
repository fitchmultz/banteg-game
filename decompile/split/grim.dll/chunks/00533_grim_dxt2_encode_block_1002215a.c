/* grim_dxt2_encode_block @ 1002215a */

/* premultiplies RGBA and encodes a DXT3-style block (DXT2) */

int __cdecl grim_dxt2_encode_block(void *out_block)

{
  int iVar1;
  int extraout_EAX;
  float local_104 [64];
  
  iVar1 = grim_dxt_premultiply_rgba_block(local_104);
  if (-1 < iVar1) {
    grim_dxt3_encode_block(out_block,local_104);
    iVar1 = extraout_EAX;
    if (-1 < extraout_EAX) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



