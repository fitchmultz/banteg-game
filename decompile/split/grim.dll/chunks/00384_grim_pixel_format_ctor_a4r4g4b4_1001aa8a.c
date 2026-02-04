/* grim_pixel_format_ctor_a4r4g4b4 @ 1001aa8a */

/* pixel format ctor for D3DFMT_A4R4G4B4 */

void * __thiscall grim_pixel_format_ctor_a4r4g4b4(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,0x10,1);
  *(undefined ***)this = &PTR_FUN_1004cc10;
  return this;
}



