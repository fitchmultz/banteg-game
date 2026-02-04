/* grim_pixel_format_ctor_d16_lockable @ 1001b0c5 */

/* pixel format ctor for D3DFMT_D16_LOCKABLE */

void * __thiscall grim_pixel_format_ctor_d16_lockable(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,0x10,1);
  *(undefined ***)this = &PTR_FUN_1004cd40;
  return this;
}



