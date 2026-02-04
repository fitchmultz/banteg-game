/* grim_pixel_format_ctor_r8g8b8 @ 1001a428 */

/* pixel format ctor for D3DFMT_R8G8B8 */

void * __thiscall grim_pixel_format_ctor_r8g8b8(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,0x18,1);
  *(undefined ***)this = &PTR_FUN_1004cb6c;
  return this;
}



