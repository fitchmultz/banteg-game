/* grim_pixel_format_ctor_v8u8 @ 1001b001 */

/* pixel format ctor for D3DFMT_V8U8 */

void * __thiscall grim_pixel_format_ctor_v8u8(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,0x10,2);
  *(undefined ***)this = &PTR_FUN_1004ccd0;
  return this;
}



