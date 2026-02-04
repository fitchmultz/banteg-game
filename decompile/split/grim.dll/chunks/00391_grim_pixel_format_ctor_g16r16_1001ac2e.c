/* grim_pixel_format_ctor_g16r16 @ 1001ac2e */

/* pixel format ctor for D3DFMT_G16R16 */

void * __thiscall grim_pixel_format_ctor_g16r16(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,0x20,1);
  *(undefined ***)this = &PTR_FUN_1004cc70;
  return this;
}



