/* grim_pixel_format_ctor_x8l8v8u8 @ 1001b039 */

/* pixel format ctor for D3DFMT_X8L8V8U8 */

void * __thiscall grim_pixel_format_ctor_x8l8v8u8(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,0x20,2);
  *(undefined ***)this = &PTR_FUN_1004ccf0;
  return this;
}



