/* grim_pixel_format_ctor_yuy2 @ 1001b4f4 */

/* pixel format ctor for FourCC YUY2 */

void * __fastcall grim_pixel_format_ctor_yuy2(void *this)

{
  uint *unaff_ESI;
  void *in_stack_00000004;
  
  grim_pixel_format_init_yuv(in_stack_00000004,unaff_ESI);
  *(undefined ***)this = &PTR_FUN_1004cdf0;
  return this;
}



