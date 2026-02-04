/* grim_pixel_format_ctor_v16u16 @ 1001b071 */

/* pixel format ctor for D3DFMT_V16U16 */

void * __thiscall grim_pixel_format_ctor_v16u16(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,0x20,2);
  *(undefined ***)this = &PTR_FUN_1004cd10;
  return this;
}



