/* grim_dxt_decode_rgb565 @ 1002060e */

/* unpacks RGB565 into RGBA floats (alpha=1) */

void __fastcall grim_dxt_decode_rgb565(float *out_rgba,uint rgb565)

{
  float *in_EAX;
  
  *in_EAX = (float)((uint)out_rgba >> 0xb & 0x1f) * 0.032258064;
  in_EAX[1] = (float)((uint)out_rgba >> 5 & 0x3f) * 0.015873017;
  in_EAX[2] = (float)((uint)out_rgba & 0x1f) * 0.032258064;
  in_EAX[3] = 1.0;
  return;
}



