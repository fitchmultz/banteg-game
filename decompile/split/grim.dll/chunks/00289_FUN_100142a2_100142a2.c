/* FUN_100142a2 @ 100142a2 */

/* [binja] int32_t __fastcall sub_100142a2(int32_t* arg1) */

int FUN_100142a2(int *arg1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  int *extraout_ECX;
  uint uVar6;
  int unaff_EBP;
  uint uVar7;
  
  seh_prolog();
  iVar5 = extraout_ECX[1];
  iVar1 = *extraout_ECX;
  iVar2 = *(int *)(iVar5 + 0x1058);
  if (((iVar2 == *(int *)(iVar1 + 0x1058)) && (*(int *)(iVar5 + 0x105c) == *(int *)(iVar1 + 0x105c))
      ) && (*(int *)(iVar5 + 0x1060) == *(int *)(iVar1 + 0x1060))) {
    pvVar3 = operator_new(iVar2 << 4);
    *(void **)(unaff_EBP + -0x10) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar3 == (void *)0x0) {
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
    }
    else {
      _vector_constructor_iterator_(pvVar3,0x10,iVar2,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
      *(void **)(unaff_EBP + -0x10) = pvVar3;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    uVar6 = 0;
    if (*(int *)(unaff_EBP + -0x10) != 0) {
      if (*(int *)(extraout_ECX[1] + 0x1060) != 0) {
        uVar4 = *(uint *)(extraout_ECX[1] + 0x105c);
        do {
          uVar7 = 0;
          if (uVar4 != 0) {
            do {
              (**(code **)(*(int *)*extraout_ECX + 4))
                        (uVar7,uVar6,*(undefined4 *)(unaff_EBP + -0x10));
              (**(code **)(*(int *)extraout_ECX[1] + 8))
                        (uVar7,uVar6,*(undefined4 *)(unaff_EBP + -0x10));
              uVar4 = *(uint *)(extraout_ECX[1] + 0x105c);
              uVar7 = uVar7 + 1;
            } while (uVar7 < uVar4);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint *)(extraout_ECX[1] + 0x1060));
      }
      operator_delete(*(void **)(unaff_EBP + -0x10));
      iVar5 = 0;
      goto LAB_10014384;
    }
  }
  iVar5 = -0x7fffbffb;
LAB_10014384:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar5;
}



