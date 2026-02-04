/* FUN_1001514e @ 1001514e */

/* [binja] int32_t __fastcall sub_1001514e(int32_t* arg1) */

int FUN_1001514e(int *arg1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  undefined4 *puVar13;
  int iVar14;
  uint *puVar15;
  void *pvVar16;
  int *piVar17;
  int *extraout_ECX;
  float *pfVar18;
  int iVar19;
  int unaff_EBP;
  int *piVar20;
  
  seh_prolog();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  uVar9 = extraout_ECX[2];
  *(int **)(unaff_EBP + -0x40) = extraout_ECX;
  if ((char)uVar9 != '\x03') {
    iVar14 = -0x7fffbffb;
    goto LAB_10015527;
  }
  *(uint *)(unaff_EBP + -0x10) = ~(uVar9 >> 0x11) & 1;
  puVar15 = FUN_1001504e(~(uVar9 >> 0x10) & 1);
  *(uint **)(unaff_EBP + -0x30) = puVar15;
  puVar15 = FUN_1001504e(*(int *)(unaff_EBP + -0x10));
  *(uint **)(unaff_EBP + -0x10) = puVar15;
  if ((*(int *)(unaff_EBP + -0x30) == 0) || (puVar15 == (uint *)0x0)) {
LAB_100154fb:
    iVar14 = -0x7ff8fff2;
  }
  else {
    iVar14 = *(int *)(extraout_ECX[1] + 0x1058);
    pvVar16 = operator_new(iVar14 << 4);
    *(void **)(unaff_EBP + -0x14) = pvVar16;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar16 == (void *)0x0) {
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      iVar14 = *(int *)(unaff_EBP + -0x20);
    }
    else {
      _vector_constructor_iterator_(pvVar16,0x10,iVar14,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
      iVar14 = *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + -0x20) = iVar14;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x14) = iVar14;
    if (iVar14 == 0) goto LAB_100154fb;
    iVar14 = *(int *)(*extraout_ECX + 0x1058);
    pvVar16 = operator_new(iVar14 << 5);
    *(void **)(unaff_EBP + -0x1c) = pvVar16;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pvVar16 == (void *)0x0) {
      iVar14 = 0;
    }
    else {
      _vector_constructor_iterator_
                (pvVar16,0x10,iVar14 << 1,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
      iVar14 = *(int *)(unaff_EBP + -0x1c);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x1c) = iVar14;
    if (iVar14 == 0) goto LAB_100154fb;
    iVar10 = *(int *)(*extraout_ECX + 0x1058);
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x18) = 0xffffffff;
    *(int *)(unaff_EBP + -0x2c) = iVar14;
    if (*(int *)(extraout_ECX[1] + 0x105c) != 0) {
      piVar20 = (int *)(*(int *)(unaff_EBP + -0x10) + 8);
      *(int **)(unaff_EBP + -0x38) = piVar20;
      iVar14 = iVar10 * 0x10 + iVar14;
      piVar17 = extraout_ECX;
      do {
        iVar10 = piVar20[-2];
        *(undefined4 *)(unaff_EBP + -0x34) = 0;
        iVar19 = iVar14;
        if (iVar10 != *(int *)(unaff_EBP + -0x24)) {
          iVar11 = *(int *)(unaff_EBP + -0x18);
          if (iVar10 == iVar11) {
            iVar19 = *(int *)(unaff_EBP + -0x2c);
            *(undefined4 *)(unaff_EBP + -0x18) = 0xffffffff;
            *(int *)(unaff_EBP + -0x2c) = iVar14;
            *(int *)(unaff_EBP + -0x24) = iVar11;
          }
          else {
            piVar12 = (int *)*piVar17;
            *(int *)(unaff_EBP + -0x24) = iVar10;
            (**(code **)(*piVar12 + 4))
                      (*(undefined4 *)(unaff_EBP + -0x24),0,*(undefined4 *)(unaff_EBP + -0x2c));
          }
        }
        iVar14 = *piVar20;
        if (iVar14 != *(int *)(unaff_EBP + -0x18)) {
          iVar10 = *(int *)*piVar17;
          *(int *)(unaff_EBP + -0x18) = iVar14;
          (**(code **)(iVar10 + 4))(iVar14,0,iVar19);
        }
        if (*(int *)(piVar17[1] + 0x1058) != 0) {
          piVar17 = (int *)(*(int *)(unaff_EBP + -0x30) + 8);
          *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x20);
          do {
            iVar14 = *piVar17;
            fVar2 = (float)piVar17[1];
            pfVar1 = (float *)(iVar14 * 0x10 + iVar19);
            *(float *)(unaff_EBP + -0x50) = fVar2 * *pfVar1;
            *(float *)(unaff_EBP + -0x4c) = fVar2 * pfVar1[1];
            *(float *)(unaff_EBP + -0x48) = fVar2 * pfVar1[2];
            fVar3 = pfVar1[3];
            iVar10 = piVar17[-2];
            fVar4 = (float)piVar17[-1];
            pfVar1 = (float *)(iVar10 * 0x10 + iVar19);
            fVar5 = *pfVar1;
            *(float *)(unaff_EBP + -0x9c) = fVar4 * pfVar1[1];
            *(float *)(unaff_EBP + -0x98) = fVar4 * pfVar1[2];
            pfVar18 = (float *)(iVar14 * 0x10 + *(int *)(unaff_EBP + -0x2c));
            *(float *)(unaff_EBP + -0x94) = fVar4 * pfVar1[3];
            *(float *)(unaff_EBP + -0x80) = fVar4 * fVar5 + *(float *)(unaff_EBP + -0x50);
            *(float *)(unaff_EBP + -0x7c) =
                 *(float *)(unaff_EBP + -0x9c) + *(float *)(unaff_EBP + -0x4c);
            *(float *)(unaff_EBP + -0x78) =
                 *(float *)(unaff_EBP + -0x98) + *(float *)(unaff_EBP + -0x48);
            fVar4 = (float)piVar20[1];
            *(float *)(unaff_EBP + -0xb0) = *(float *)(unaff_EBP + -0x80) * fVar4;
            *(float *)(unaff_EBP + -0xac) = *(float *)(unaff_EBP + -0x7c) * fVar4;
            *(float *)(unaff_EBP + -0xa8) = *(float *)(unaff_EBP + -0x78) * fVar4;
            fVar5 = (float)piVar17[1];
            *(float *)(unaff_EBP + -0xc0) = fVar5 * *pfVar18;
            *(float *)(unaff_EBP + -0xbc) = fVar5 * pfVar18[1];
            *(float *)(unaff_EBP + -0xb8) = fVar5 * pfVar18[2];
            fVar6 = pfVar18[3];
            pfVar1 = (float *)(iVar10 * 0x10 + *(int *)(unaff_EBP + -0x2c));
            fVar7 = (float)piVar17[-1];
            piVar17 = piVar17 + 4;
            fVar8 = *pfVar1;
            *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) + 1;
            uVar9 = *(uint *)(unaff_EBP + -0x34);
            *(float *)(unaff_EBP + -0x5c) = fVar7 * pfVar1[1];
            *(float *)(unaff_EBP + -0x58) = fVar7 * pfVar1[2];
            iVar14 = *(int *)(unaff_EBP + -0x40);
            *(float *)(unaff_EBP + -0x54) = fVar7 * pfVar1[3];
            *(float *)(unaff_EBP + -0x70) = fVar7 * fVar8 + *(float *)(unaff_EBP + -0xc0);
            *(float *)(unaff_EBP + -0x6c) =
                 *(float *)(unaff_EBP + -0x5c) + *(float *)(unaff_EBP + -0xbc);
            *(float *)(unaff_EBP + -0x68) =
                 *(float *)(unaff_EBP + -0x58) + *(float *)(unaff_EBP + -0xb8);
            fVar7 = (float)piVar20[-1];
            puVar13 = *(undefined4 **)(unaff_EBP + -0x3c);
            *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x3c) + 0x10;
            *(float *)(unaff_EBP + -0x90) = *(float *)(unaff_EBP + -0x70) * fVar7;
            *(float *)(unaff_EBP + -0x8c) = *(float *)(unaff_EBP + -0x6c) * fVar7;
            *(float *)(unaff_EBP + -0x88) = *(float *)(unaff_EBP + -0x68) * fVar7;
            *(float *)(unaff_EBP + -0xd0) =
                 *(float *)(unaff_EBP + -0x90) + *(float *)(unaff_EBP + -0xb0);
            *(float *)(unaff_EBP + -0xcc) =
                 *(float *)(unaff_EBP + -0x8c) + *(float *)(unaff_EBP + -0xac);
            *(float *)(unaff_EBP + -200) =
                 *(float *)(unaff_EBP + -0x88) + *(float *)(unaff_EBP + -0xa8);
            *(float *)(unaff_EBP + -0xc4) =
                 (*(float *)(unaff_EBP + -0x54) + fVar5 * fVar6) * fVar7 +
                 (*(float *)(unaff_EBP + -0x94) + fVar2 * fVar3) * fVar4;
            *puVar13 = *(undefined4 *)(unaff_EBP + -0xd0);
            puVar13[1] = *(undefined4 *)(unaff_EBP + -0xcc);
            puVar13[2] = *(undefined4 *)(unaff_EBP + -200);
            puVar13[3] = *(undefined4 *)(unaff_EBP + -0xc4);
            piVar20 = *(int **)(unaff_EBP + -0x38);
          } while (uVar9 < *(uint *)(*(int *)(iVar14 + 4) + 0x1058));
          piVar17 = *(int **)(unaff_EBP + -0x40);
        }
        (**(code **)(*(int *)piVar17[1] + 8))
                  (*(undefined4 *)(unaff_EBP + -0x28),0,*(undefined4 *)(unaff_EBP + -0x20));
        iVar14 = piVar17[1];
        piVar20 = piVar20 + 4;
        *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
        uVar9 = *(uint *)(iVar14 + 0x105c);
        *(int **)(unaff_EBP + -0x38) = piVar20;
        iVar14 = iVar19;
      } while (*(uint *)(unaff_EBP + -0x28) < uVar9);
    }
    iVar14 = 0;
  }
  operator_delete(*(void **)(unaff_EBP + -0x30));
  operator_delete(*(void **)(unaff_EBP + -0x10));
  operator_delete(*(void **)(unaff_EBP + -0x14));
  operator_delete(*(void **)(unaff_EBP + -0x1c));
LAB_10015527:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar14;
}



