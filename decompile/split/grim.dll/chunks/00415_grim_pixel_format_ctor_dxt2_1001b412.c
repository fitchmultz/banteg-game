/* grim_pixel_format_ctor_dxt2 @ 1001b412 */

/* pixel format ctor for FourCC DXT2 */

void * __thiscall grim_pixel_format_ctor_dxt2(void *this,uint *desc)

{
  grim_pixel_format_init_dxt(this,desc);
  *(undefined ***)this = &PTR_FUN_1004cda0;
  return this;
}



