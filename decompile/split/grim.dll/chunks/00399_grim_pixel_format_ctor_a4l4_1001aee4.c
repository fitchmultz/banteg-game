/* grim_pixel_format_ctor_a4l4 @ 1001aee4 */

/* pixel format ctor for D3DFMT_A4L4 */

void * __thiscall grim_pixel_format_ctor_a4l4(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,8,1);
  *(undefined ***)this = &PTR_FUN_1004ccc0;
  return this;
}



