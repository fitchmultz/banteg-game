/* grim_pixel_format_ctor_a8 @ 1001aac2 */

/* pixel format ctor for D3DFMT_A8 */

void * __thiscall grim_pixel_format_ctor_a8(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,8,1);
  *(undefined ***)this = &PTR_FUN_1004cc30;
  return this;
}



