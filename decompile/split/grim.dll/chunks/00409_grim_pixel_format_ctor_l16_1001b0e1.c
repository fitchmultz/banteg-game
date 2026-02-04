/* grim_pixel_format_ctor_l16 @ 1001b0e1 */

/* pixel format ctor for FourCC L16 (16-bit luminance) */

void * __thiscall grim_pixel_format_ctor_l16(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,0x10,1);
  *(undefined ***)this = &PTR_FUN_1004cd50;
  return this;
}



