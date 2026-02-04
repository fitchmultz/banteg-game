/* grim_pixel_format_ctor_x8r8g8b8 @ 1001a558 */

/* pixel format ctor for D3DFMT_X8R8G8B8 */

void * __thiscall grim_pixel_format_ctor_x8r8g8b8(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,0x20,1);
  *(undefined ***)this = &PTR_FUN_1004cb9c;
  return this;
}



