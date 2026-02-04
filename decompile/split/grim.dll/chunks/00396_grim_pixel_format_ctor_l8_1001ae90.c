/* grim_pixel_format_ctor_l8 @ 1001ae90 */

/* pixel format ctor for D3DFMT_L8 */

void * __thiscall grim_pixel_format_ctor_l8(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,8,1);
  *(undefined ***)this = &PTR_FUN_1004cca0;
  return this;
}



