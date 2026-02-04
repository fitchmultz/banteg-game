/* FUN_1001b493 @ 1001b493 */

/* [binja] int32_t __fastcall sub_1001b493(void*** arg1) */

int FUN_1001b493(void ***arg1)

{
  int extraout_EAX;
  undefined4 *this;
  int unaff_EBP;
  
  seh_prolog();
  *(undefined4 **)(unaff_EBP + -0x10) = this;
  *this = &PTR_LAB_1004cb7c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  grim_pixel_format_flush_yuv_cache(this);
  if ((void *)this[0x41b] != (void *)0x0) {
    operator_delete((void *)this[0x41b]);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  grim_vertex_space_converter_destroy(this);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_EAX;
}



