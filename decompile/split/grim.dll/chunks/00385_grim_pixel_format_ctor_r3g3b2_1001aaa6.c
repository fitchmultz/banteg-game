/* grim_pixel_format_ctor_r3g3b2 @ 1001aaa6 */

/* pixel format ctor for D3DFMT_R3G3B2 */

void * __thiscall grim_pixel_format_ctor_r3g3b2(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,8,1);
  *(undefined ***)this = &PTR_FUN_1004cc20;
  return this;
}



