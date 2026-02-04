/* grim_dxt4_encode_block @ 1002218e */

/* premultiplies RGBA and encodes a DXT5-style block (DXT4) */

int __cdecl grim_dxt4_encode_block(void *out_block)

{
  int iVar1;
  float local_104 [64];
  
  iVar1 = grim_dxt_premultiply_rgba_block(local_104);
  if (-1 < iVar1) {
    iVar1 = grim_dxt5_encode_block(out_block,local_104);
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



