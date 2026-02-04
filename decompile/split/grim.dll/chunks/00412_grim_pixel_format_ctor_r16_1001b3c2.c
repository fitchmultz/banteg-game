/* grim_pixel_format_ctor_r16 @ 1001b3c2 */

/* pixel format ctor for FourCC R16 */

void * __thiscall grim_pixel_format_ctor_r16(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,0x30,1);
  *(undefined ***)this = &PTR_FUN_1004cd70;
  return this;
}



