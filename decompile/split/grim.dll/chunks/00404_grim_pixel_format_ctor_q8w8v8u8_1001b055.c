/* grim_pixel_format_ctor_q8w8v8u8 @ 1001b055 */

/* pixel format ctor for D3DFMT_Q8W8V8U8 */

void * __thiscall grim_pixel_format_ctor_q8w8v8u8(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,0x20,3);
  *(undefined ***)this = &PTR_FUN_1004cd00;
  return this;
}



