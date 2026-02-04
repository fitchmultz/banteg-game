/* FUN_10014bbc @ 10014bbc */

/* [binja] int32_t __fastcall sub_10014bbc(int32_t* arg1) */

int FUN_10014bbc(int *arg1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  void *pvVar10;
  int iVar11;
  int *extraout_ECX;
  int iVar12;
  float *pfVar13;
  float *pfVar14;
  float *pfVar15;
  int unaff_EBP;
  int iVar16;
  
  seh_prolog();
  if ((char)extraout_ECX[2] == '\x05') {
    iVar9 = *extraout_ECX;
    uVar6 = *(uint *)(iVar9 + 0x1058);
    iVar11 = extraout_ECX[1];
    if ((((*(uint *)(iVar11 + 0x1058) == uVar6 >> 1) ||
         ((*(uint *)(iVar11 + 0x1058) == 1 && (uVar6 == 1)))) &&
        ((*(uint *)(iVar11 + 0x105c) == *(uint *)(iVar9 + 0x105c) >> 1 ||
         ((*(uint *)(iVar11 + 0x105c) == 1 && (*(int *)(iVar9 + 0x105c) == 1)))))) &&
       (*(uint *)(iVar11 + 0x1060) == *(uint *)(iVar9 + 0x1060) >> 1)) {
      if ((1 < uVar6) && ((uVar6 & 1) != 0)) {
        *(uint *)(iVar9 + 0x1058) = uVar6 & 0xfffffffe;
        piVar1 = (int *)(*extraout_ECX + 0x1064);
        *piVar1 = *piVar1 - *(int *)(*extraout_ECX + 0x1068);
      }
      uVar6 = *(uint *)(*extraout_ECX + 0x105c);
      if (1 < uVar6) {
        *(uint *)(*extraout_ECX + 0x105c) = uVar6 & 0xfffffffe;
      }
      uVar6 = *(uint *)(*extraout_ECX + 0x1060);
      if (1 < uVar6) {
        *(uint *)(*extraout_ECX + 0x1060) = uVar6 & 0xfffffffe;
      }
      iVar9 = *(int *)(extraout_ECX[1] + 0x1058);
      pvVar10 = operator_new(iVar9 << 4);
      *(void **)(unaff_EBP + -0x14) = pvVar10;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar10 == (void *)0x0) {
        *(undefined4 *)(unaff_EBP + -0x20) = 0;
      }
      else {
        _vector_constructor_iterator_(pvVar10,0x10,iVar9,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
        *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x14);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (*(int *)(unaff_EBP + -0x20) == 0) {
        iVar9 = -0x7ff8fff2;
      }
      else {
        iVar9 = *(int *)(*extraout_ECX + 0x1058);
        if (*(int *)(*extraout_ECX + 0x105c) == 1) {
          pvVar10 = operator_new(iVar9 << 5);
          *(void **)(unaff_EBP + -0x14) = pvVar10;
          *(undefined4 *)(unaff_EBP + -4) = 1;
          if (pvVar10 == (void *)0x0) {
            iVar12 = 0;
          }
          else {
            _vector_constructor_iterator_
                      (pvVar10,0x10,iVar9 << 1,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
            iVar12 = *(int *)(unaff_EBP + -0x14);
          }
          iVar11 = *(int *)(*extraout_ECX + 0x1058);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          iVar9 = iVar11 * 0x10 + iVar12;
          *(int *)(unaff_EBP + -0x38) = iVar12;
          *(int *)(unaff_EBP + -0x18) = iVar12;
          *(int *)(unaff_EBP + -0x30) = iVar9;
          *(int *)(unaff_EBP + -0x1c) = iVar12;
          *(int *)(unaff_EBP + -0x28) = iVar9;
          iVar16 = iVar9;
        }
        else {
          pvVar10 = operator_new(iVar9 << 6);
          *(void **)(unaff_EBP + -0x14) = pvVar10;
          *(undefined4 *)(unaff_EBP + -4) = 2;
          if (pvVar10 == (void *)0x0) {
            iVar9 = 0;
          }
          else {
            _vector_constructor_iterator_
                      (pvVar10,0x10,iVar9 << 2,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
            iVar9 = *(int *)(unaff_EBP + -0x14);
          }
          iVar11 = *(int *)(*extraout_ECX + 0x1058);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          *(int *)(unaff_EBP + -0x30) = iVar11 * 0x10 + iVar9;
          iVar16 = *(int *)(unaff_EBP + -0x30);
          *(int *)(unaff_EBP + -0x1c) = iVar11 * 0x20 + iVar9;
          *(int *)(unaff_EBP + -0x28) = iVar11 * 0x30 + iVar9;
          iVar12 = *(int *)(unaff_EBP + -0x1c);
          *(int *)(unaff_EBP + -0x38) = iVar9;
          *(int *)(unaff_EBP + -0x18) = iVar9;
          iVar9 = *(int *)(unaff_EBP + -0x28);
        }
        if (*(int *)(unaff_EBP + -0x38) == 0) {
          iVar9 = -0x7ff8fff2;
        }
        else {
          if (iVar11 == 1) {
            *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x18);
            *(int *)(unaff_EBP + -0x40) = iVar16;
          }
          else {
            *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x18) + 0x10;
            iVar12 = iVar12 + 0x10;
            *(int *)(unaff_EBP + -0x40) = iVar16 + 0x10;
            iVar9 = iVar9 + 0x10;
          }
          iVar11 = extraout_ECX[1];
          *(undefined4 *)(unaff_EBP + -0x24) = 0;
          iVar7 = *(int *)(iVar11 + 0x1060);
          *(int *)(unaff_EBP + -0x44) = iVar12;
          *(int *)(unaff_EBP + -0x14) = iVar9;
          if (iVar7 != 0) {
            do {
              *(undefined4 *)(unaff_EBP + -0x10) = 0;
              if (*(int *)(iVar11 + 0x105c) != 0) {
                do {
                  iVar9 = *(int *)(unaff_EBP + -0x24) * 2;
                  (**(code **)(*(int *)*extraout_ECX + 4))
                            (*(int *)(unaff_EBP + -0x10) * 2,iVar9,
                             *(undefined4 *)(unaff_EBP + -0x18));
                  if (iVar16 != *(int *)(unaff_EBP + -0x18)) {
                    (**(code **)(*(int *)*extraout_ECX + 4))
                              (*(int *)(unaff_EBP + -0x10) * 2,iVar9 + 1,iVar16);
                  }
                  if (*(int *)(unaff_EBP + -0x1c) != *(int *)(unaff_EBP + -0x18)) {
                    (**(code **)(*(int *)*extraout_ECX + 4))
                              (*(int *)(unaff_EBP + -0x10) * 2 + 1,iVar9,*(int *)(unaff_EBP + -0x1c)
                              );
                  }
                  iVar11 = *(int *)(unaff_EBP + -0x28);
                  if ((iVar11 != iVar16) && (iVar11 != *(int *)(unaff_EBP + -0x1c))) {
                    (**(code **)(*(int *)*extraout_ECX + 4))
                              (*(int *)(unaff_EBP + -0x10) * 2 + 1,iVar9 + 1,iVar11);
                  }
                  iVar9 = extraout_ECX[1];
                  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
                  if (*(int *)(iVar9 + 0x1058) != 0) {
                    *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x20);
                    do {
                      iVar9 = *(int *)(unaff_EBP + -0x2c) * 0x20;
                      pfVar13 = (float *)(*(int *)(unaff_EBP + -0x3c) + iVar9);
                      fVar2 = *pfVar13;
                      pfVar15 = (float *)(*(int *)(unaff_EBP + -0x18) + iVar9);
                      fVar3 = *pfVar15;
                      fVar4 = pfVar13[1];
                      fVar5 = pfVar15[1];
                      *(float *)(unaff_EBP + -0x8c) = pfVar13[2] + pfVar15[2];
                      pfVar14 = (float *)(iVar9 + iVar16);
                      *(float *)(unaff_EBP + -0x88) = pfVar13[3] + pfVar15[3];
                      *(float *)(unaff_EBP + -0xb4) = fVar2 + fVar3 + *pfVar14;
                      fVar2 = pfVar14[1];
                      fVar3 = pfVar14[2];
                      pfVar13 = (float *)(*(int *)(unaff_EBP + -0x40) + iVar9);
                      *(float *)(unaff_EBP + -0xa8) = *(float *)(unaff_EBP + -0x88) + pfVar14[3];
                      *(float *)(unaff_EBP + -0x84) = *(float *)(unaff_EBP + -0xb4) + *pfVar13;
                      *(float *)(unaff_EBP + -0x80) = fVar4 + fVar5 + fVar2 + pfVar13[1];
                      fVar2 = pfVar13[2];
                      fVar4 = pfVar13[3];
                      pfVar14 = (float *)(*(int *)(unaff_EBP + -0x1c) + iVar9);
                      *(float *)(unaff_EBP + -0x54) = *(float *)(unaff_EBP + -0x84) + *pfVar14;
                      *(float *)(unaff_EBP + -0x50) = *(float *)(unaff_EBP + -0x80) + pfVar14[1];
                      *(float *)(unaff_EBP + -0x4c) =
                           *(float *)(unaff_EBP + -0x8c) + fVar3 + fVar2 + pfVar14[2];
                      fVar2 = pfVar14[3];
                      pfVar14 = (float *)(*(int *)(unaff_EBP + -0x44) + iVar9);
                      fVar3 = *pfVar14;
                      *(float *)(unaff_EBP + -0x60) = *(float *)(unaff_EBP + -0x50) + pfVar14[1];
                      *(float *)(unaff_EBP + -0x5c) = *(float *)(unaff_EBP + -0x4c) + pfVar14[2];
                      *(float *)(unaff_EBP + -0x58) =
                           *(float *)(unaff_EBP + -0xa8) + fVar4 + fVar2 + pfVar14[3];
                      pfVar14 = (float *)(*(int *)(unaff_EBP + -0x28) + iVar9);
                      fVar2 = *pfVar14;
                      puVar8 = *(undefined4 **)(unaff_EBP + -0x34);
                      *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) + 0x10;
                      fVar4 = pfVar14[1];
                      *(float *)(unaff_EBP + -0x9c) = *(float *)(unaff_EBP + -0x5c) + pfVar14[2];
                      fVar5 = pfVar14[3];
                      pfVar14 = (float *)(iVar9 + *(int *)(unaff_EBP + -0x14));
                      *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 1;
                      *(float *)(unaff_EBP + -0x98) = *(float *)(unaff_EBP + -0x58) + fVar5;
                      uVar6 = *(uint *)(unaff_EBP + -0x2c);
                      *(float *)(unaff_EBP + -0xc4) =
                           *(float *)(unaff_EBP + -0x54) + fVar3 + fVar2 + *pfVar14;
                      fVar2 = pfVar14[1];
                      fVar3 = pfVar14[2];
                      *(float *)(unaff_EBP + -0xb8) = *(float *)(unaff_EBP + -0x98) + pfVar14[3];
                      *(float *)(unaff_EBP + -0x74) = *(float *)(unaff_EBP + -0xc4) * 0.125;
                      *(float *)(unaff_EBP + -0x70) =
                           (*(float *)(unaff_EBP + -0x60) + fVar4 + fVar2) * 0.125;
                      *(float *)(unaff_EBP + -0x6c) =
                           (*(float *)(unaff_EBP + -0x9c) + fVar3) * 0.125;
                      *(float *)(unaff_EBP + -0x68) = *(float *)(unaff_EBP + -0xb8) * 0.125;
                      *puVar8 = *(undefined4 *)(unaff_EBP + -0x74);
                      puVar8[1] = *(undefined4 *)(unaff_EBP + -0x70);
                      puVar8[2] = *(undefined4 *)(unaff_EBP + -0x6c);
                      puVar8[3] = *(undefined4 *)(unaff_EBP + -0x68);
                      iVar16 = *(int *)(unaff_EBP + -0x30);
                    } while (uVar6 < *(uint *)(extraout_ECX[1] + 0x1058));
                  }
                  (**(code **)(*(int *)extraout_ECX[1] + 8))
                            (*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x24),
                             *(undefined4 *)(unaff_EBP + -0x20));
                  *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
                } while (*(uint *)(unaff_EBP + -0x10) < *(uint *)(extraout_ECX[1] + 0x105c));
              }
              *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
              iVar11 = extraout_ECX[1];
            } while (*(uint *)(unaff_EBP + -0x24) < *(uint *)(iVar11 + 0x1060));
          }
          operator_delete(*(void **)(unaff_EBP + -0x38));
          iVar9 = 0;
        }
        operator_delete(*(void **)(unaff_EBP + -0x20));
      }
    }
    else {
      iVar9 = -0x7fffbffb;
    }
  }
  else {
    iVar9 = -0x7fffbffb;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar9;
}



