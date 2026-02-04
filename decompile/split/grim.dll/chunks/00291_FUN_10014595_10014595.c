/* FUN_10014595 @ 10014595 */

/* [binja] int32_t __fastcall sub_10014595(int32_t* arg1) */

int FUN_10014595(int *arg1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  void *pvVar5;
  undefined4 *puVar6;
  int *extraout_ECX;
  int unaff_EBP;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  
  seh_prolog();
  if ((char)extraout_ECX[2] == '\x02') {
    iVar4 = *(int *)(*extraout_ECX + 0x1058);
    pvVar5 = operator_new(iVar4 << 4);
    *(void **)(unaff_EBP + -0x30) = pvVar5;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar5 == (void *)0x0) {
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
    }
    else {
      _vector_constructor_iterator_(pvVar5,0x10,iVar4,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x30);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(int *)(unaff_EBP + -0x10) == 0) {
      iVar4 = -0x7ff8fff2;
    }
    else {
      iVar4 = *(int *)(extraout_ECX[1] + 0x1058);
      pvVar5 = operator_new(iVar4 << 4);
      *(void **)(unaff_EBP + -0x30) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar5 == (void *)0x0) {
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
      }
      else {
        _vector_constructor_iterator_(pvVar5,0x10,iVar4,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
        *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x30);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (*(int *)(unaff_EBP + -0x14) == 0) {
        operator_delete(*(void **)(unaff_EBP + -0x10));
        iVar4 = -0x7ff8fff2;
      }
      else {
        iVar4 = *extraout_ECX;
        iVar1 = extraout_ECX[1];
        iVar2 = *(int *)(iVar4 + 0x1058);
        uVar7 = *(uint *)(iVar1 + 0x1058);
        uVar9 = *(uint *)(iVar1 + 0x105c);
        uVar3 = *(uint *)(iVar1 + 0x1060);
        *(undefined4 *)(unaff_EBP + -0x28) = 0;
        *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        *(uint *)(unaff_EBP + -0x34) = (uint)(iVar2 << 0x10) / uVar7;
        *(uint *)(unaff_EBP + -0x38) = (uint)(*(int *)(iVar4 + 0x105c) << 0x10) / uVar9;
        *(uint *)(unaff_EBP + -0x3c) = (uint)(*(int *)(iVar4 + 0x1060) << 0x10) / uVar3;
        if (uVar3 != 0) {
          do {
            *(undefined4 *)(unaff_EBP + -0x2c) = 0xffffffff;
            uVar7 = 0;
            *(undefined4 *)(unaff_EBP + -0x30) = 0;
            *(undefined4 *)(unaff_EBP + -0x18) = 0;
            if (uVar9 != 0) {
              do {
                *(undefined4 *)(unaff_EBP + -0x20) = 0;
                *(undefined4 *)(unaff_EBP + -0x24) = 0;
                if (((*(uint *)(unaff_EBP + -0x2c) ^ uVar7) & 0xffff0000) != 0) {
                  (**(code **)(*(int *)*extraout_ECX + 4))
                            (uVar7 >> 0x10,*(uint *)(unaff_EBP + -0x28) >> 0x10,
                             *(undefined4 *)(unaff_EBP + -0x10));
                  *(uint *)(unaff_EBP + -0x2c) = uVar7;
                }
                if (*(int *)(extraout_ECX[1] + 0x1058) != 0) {
                  puVar6 = *(undefined4 **)(unaff_EBP + -0x14);
                  do {
                    uVar7 = *(uint *)(unaff_EBP + -0x20);
                    *(int *)(unaff_EBP + -0x20) =
                         *(int *)(unaff_EBP + -0x20) + *(int *)(unaff_EBP + -0x34);
                    puVar8 = (undefined4 *)((uVar7 >> 0x10) * 0x10 + *(int *)(unaff_EBP + -0x10));
                    *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
                    uVar7 = *(uint *)(unaff_EBP + -0x24);
                    *puVar6 = *puVar8;
                    puVar6[1] = puVar8[1];
                    puVar6[2] = puVar8[2];
                    puVar6[3] = puVar8[3];
                    puVar6 = puVar6 + 4;
                  } while (uVar7 < *(uint *)(extraout_ECX[1] + 0x1058));
                }
                (**(code **)(*(int *)extraout_ECX[1] + 8))
                          (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x1c),
                           *(undefined4 *)(unaff_EBP + -0x14));
                uVar7 = *(int *)(unaff_EBP + -0x30) + *(int *)(unaff_EBP + -0x38);
                iVar4 = extraout_ECX[1];
                *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
                uVar9 = *(uint *)(iVar4 + 0x105c);
                *(uint *)(unaff_EBP + -0x30) = uVar7;
              } while (*(uint *)(unaff_EBP + -0x18) < uVar9);
            }
            *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + *(int *)(unaff_EBP + -0x3c);
            *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
          } while (*(uint *)(unaff_EBP + -0x1c) < *(uint *)(extraout_ECX[1] + 0x1060));
        }
        operator_delete(*(void **)(unaff_EBP + -0x10));
        operator_delete(*(void **)(unaff_EBP + -0x14));
        iVar4 = 0;
      }
    }
  }
  else {
    iVar4 = -0x7fffbffb;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4;
}



