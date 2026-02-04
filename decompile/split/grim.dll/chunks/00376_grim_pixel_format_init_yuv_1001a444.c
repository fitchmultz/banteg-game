/* grim_pixel_format_init_yuv @ 1001a444 */

/* initializes packed YUV (UYVY/YUY2) cache state and allocates RGB float cache */

void * grim_pixel_format_init_yuv(void *this,uint *desc)

{
  uint uVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 *this_00;
  int iVar4;
  int unaff_EBP;
  
  seh_prolog();
  *(undefined4 **)(unaff_EBP + -0x14) = this_00;
  grim_pixel_format_init(this_00,*(uint **)(unaff_EBP + 8),0,1);
  uVar1 = this_00[0x40c];
  uVar2 = this_00[0x40e] + 1 & 0xfffffffe;
  iVar4 = uVar2 - (uVar1 & 0xfffffffe);
  this_00[0x41e] = uVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *this_00 = &PTR_LAB_1004cb7c;
  this_00[0x41c] = uVar1 & 0xfffffffe;
  this_00[0x41d] = 0;
  this_00[0x420] = 0;
  this_00[0x41f] = 0;
  this_00[0x421] = 0;
  this_00[0x422] = iVar4;
  this_00[0x423] = 0;
  this_00[0x424] = 1;
  pvVar3 = operator_new(iVar4 * 0x10);
  *(void **)(unaff_EBP + -0x10) = pvVar3;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (pvVar3 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    _vector_constructor_iterator_(pvVar3,0x10,iVar4,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
    iVar4 = *(int *)(unaff_EBP + -0x10);
  }
  this_00[0x41b] = iVar4;
  if (iVar4 == 0) {
    this_00[0x424] = 0;
  }
  if (*(int *)(*(int *)(unaff_EBP + 8) + 4) == 0x59565955) {
    this_00[0x425] = 8;
    this_00[0x426] = 0;
  }
  else {
    this_00[0x425] = 0;
    this_00[0x426] = 8;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return this_00;
}



