/* grim_pixel_format_ctor_al16 @ 1001b3a6 */

/* pixel format ctor for FourCC AL16 */

void * __thiscall grim_pixel_format_ctor_al16(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,0x20,1);
  *(undefined ***)this = &PTR_FUN_1004cd60;
  return this;
}



