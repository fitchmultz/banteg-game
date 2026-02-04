/* grim_pixel_format_ctor_p8 @ 1001ae74 */

/* pixel format ctor for D3DFMT_P8 */

void * __thiscall grim_pixel_format_ctor_p8(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,8,1);
  *(undefined ***)this = &PTR_FUN_1004cc90;
  return this;
}



