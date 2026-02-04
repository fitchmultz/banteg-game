/* grim_pixel_format_ctor_dxt3 @ 1001b42a */

/* pixel format ctor for FourCC DXT3 */

void * __thiscall grim_pixel_format_ctor_dxt3(void *this,uint *desc)

{
  grim_pixel_format_init_dxt(this,desc);
  *(undefined ***)this = &PTR_FUN_1004cdb0;
  return this;
}



