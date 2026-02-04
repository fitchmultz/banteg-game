/* grim_dxt_premultiply_rgba_block @ 100206d8 */

/* multiplies rgb by alpha for a 4x4 RGBA block */

int __fastcall grim_dxt_premultiply_rgba_block(float *out_rgba)

{
  float *in_EAX;
  int iVar1;
  
  iVar1 = 0x10;
  do {
    *out_rgba = in_EAX[3] * *in_EAX;
    iVar1 = iVar1 + -1;
    out_rgba[1] = in_EAX[1] * in_EAX[3];
    out_rgba[2] = in_EAX[2] * in_EAX[3];
    out_rgba[3] = in_EAX[3];
    in_EAX = in_EAX + 4;
    out_rgba = out_rgba + 4;
  } while (iVar1 != 0);
  return 0;
}



