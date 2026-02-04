/* FUN_10016c3c @ 10016c3c */

/* [binja] int32_t __fastcall sub_10016c3c(void*** arg1) */

int FUN_10016c3c(void ***arg1)

{
  int extraout_EAX;
  undefined4 *this;
  uint uVar1;
  int unaff_EBP;
  uint uVar2;
  
  seh_prolog();
  *(undefined4 **)(unaff_EBP + -0x14) = this;
  *this = &PTR_FUN_1004caf8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((this[0x42f] != 0) && (this[0x430] != 0)) {
    uVar1 = this[0x427];
    uVar2 = this[0x428];
    *(undefined4 *)(unaff_EBP + -0x10) = this[0x430];
    if (uVar1 < uVar2) {
      do {
        for (uVar2 = this[0x424]; uVar2 < (uint)this[0x426]; uVar2 = uVar2 + 4) {
          operator_delete(*(void **)(*(int *)(unaff_EBP + -0x10) + 4));
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 8;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < (uint)this[0x428]);
    }
  }
  operator_delete((void *)this[0x42e]);
  operator_delete((void *)this[0x430]);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  grim_vertex_space_converter_destroy(this);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_EAX;
}



