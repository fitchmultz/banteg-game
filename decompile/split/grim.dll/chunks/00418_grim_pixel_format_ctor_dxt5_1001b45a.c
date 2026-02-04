/* grim_pixel_format_ctor_dxt5 @ 1001b45a */

/* pixel format ctor for FourCC DXT5 */

void * __thiscall grim_pixel_format_ctor_dxt5(void *this,uint *desc)

{
  grim_pixel_format_init_dxt(this,desc);
  *(undefined ***)this = &PTR_FUN_1004cdd0;
  return this;
}



