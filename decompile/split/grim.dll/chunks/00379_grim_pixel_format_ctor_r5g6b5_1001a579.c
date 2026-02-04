/* grim_pixel_format_ctor_r5g6b5 @ 1001a579 */

/* pixel format ctor for D3DFMT_R5G6B5 */

void * __thiscall grim_pixel_format_ctor_r5g6b5(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,0x10,1);
  *(undefined ***)this = &PTR_FUN_1004cbac;
  return this;
}



