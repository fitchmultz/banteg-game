/* grim_pixel_format_ctor_dxt4 @ 1001b442 */

/* pixel format ctor for FourCC DXT4 */

void * __thiscall grim_pixel_format_ctor_dxt4(void *this,uint *desc)

{
  grim_pixel_format_init_dxt(this,desc);
  *(undefined ***)this = &PTR_FUN_1004cdc0;
  return this;
}



