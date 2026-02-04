/* grim_pixel_format_ctor_a1r5g5b5 @ 1001a79d */

/* pixel format ctor for D3DFMT_A1R5G5B5 */

void * __thiscall grim_pixel_format_ctor_a1r5g5b5(void *this,uint *desc)

{
  grim_pixel_format_init(this,desc,0x10,1);
  *(undefined ***)this = &PTR_FUN_1004cbec;
  return this;
}



