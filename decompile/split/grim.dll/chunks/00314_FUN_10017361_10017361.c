/* FUN_10017361 @ 10017361 */

/* [binja] int32_t __thiscall sub_10017361(void* arg1, void* arg2) */

int FUN_10017361(void *arg1,void *arg2)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  seh_prolog();
  if (*(int *)(extraout_ECX + 8) != *(int *)(*(int *)(unaff_EBP + 8) + 8)) {
    iVar3 = *(int *)(extraout_ECX + 0x1058);
    pvVar1 = operator_new(iVar3 << 4);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    pvVar2 = (void *)0x0;
    if (pvVar1 != (void *)0x0) {
      _vector_constructor_iterator_(pvVar1,0x10,iVar3,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
      pvVar2 = pvVar1;
    }
    *(void **)(extraout_ECX + 0x104c) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      iVar3 = -0x7ff8fff2;
      goto LAB_100173cd;
    }
    *(undefined4 *)(extraout_ECX + 0x1048) = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 8);
  }
  iVar3 = 0;
LAB_100173cd:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar3;
}



