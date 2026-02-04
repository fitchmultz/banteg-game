/* grim_pixel_format_ctor_a8p8 @ 1001ae3c */

/* pixel format ctor for D3DFMT_A8P8 */

void * __thiscall grim_pixel_format_ctor_a8p8(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,0x10,1);
  *(undefined ***)this = &PTR_FUN_1004cc80;
  return this;
}



