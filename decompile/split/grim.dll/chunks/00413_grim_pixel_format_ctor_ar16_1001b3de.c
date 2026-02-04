/* grim_pixel_format_ctor_ar16 @ 1001b3de */

/* pixel format ctor for FourCC AR16 */

void * __thiscall grim_pixel_format_ctor_ar16(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,0x40,1);
  *(undefined ***)this = &PTR_FUN_1004cd80;
  return this;
}



