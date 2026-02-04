/* grim_pixel_format_ctor_dxt1 @ 1001b3fa */

/* pixel format ctor for FourCC DXT1 */

void * __thiscall grim_pixel_format_ctor_dxt1(void *this,uint *desc)

{
  grim_pixel_format_init_dxt(this,desc);
  *(undefined ***)this = &PTR_FUN_1004cd90;
  return this;
}



