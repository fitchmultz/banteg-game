/* grim_pixel_format_ctor_uyvy @ 1001b4dc */

/* pixel format ctor for FourCC UYVY */

void * __fastcall grim_pixel_format_ctor_uyvy(void *this)

{
  uint *unaff_ESI;
  void *in_stack_00000004;
  
  grim_pixel_format_init_yuv(in_stack_00000004,unaff_ESI);
  *(undefined ***)this = &PTR_FUN_1004cde0;
  return this;
}



