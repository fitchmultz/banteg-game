/* FUN_10014799 @ 10014799 */

/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* [binja] int32_t __fastcall sub_10014799(int32_t* arg1) */

int FUN_10014799(int *arg1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  void *pvVar9;
  float *pfVar10;
  float *pfVar11;
  int *arg1_00;
  float *pfVar12;
  uint uVar13;
  int unaff_EBP;
  
  seh_prolog();
  if ((char)arg1_00[2] != '\x05') {
    iVar8 = -0x7fffbffb;
    goto LAB_10014b8f;
  }
  iVar8 = *arg1_00;
  uVar13 = *(uint *)(iVar8 + 0x1058);
  iVar6 = arg1_00[1];
  if ((((*(uint *)(iVar6 + 0x1058) != uVar13 >> 1) &&
       ((*(uint *)(iVar6 + 0x1058) != 1 || (uVar13 != 1)))) ||
      ((*(uint *)(iVar6 + 0x105c) != *(uint *)(iVar8 + 0x105c) >> 1 &&
       ((*(uint *)(iVar6 + 0x105c) != 1 || (*(int *)(iVar8 + 0x105c) != 1)))))) ||
     ((*(int *)(iVar6 + 0x1060) != 1 || (*(int *)(iVar8 + 0x1060) != 1)))) {
    iVar8 = -0x7fffbffb;
    goto LAB_10014b8f;
  }
  if ((1 < uVar13) && ((uVar13 & 1) != 0)) {
    *(uint *)(iVar8 + 0x1058) = uVar13 & 0xfffffffe;
    piVar1 = (int *)(*arg1_00 + 0x1064);
    *piVar1 = *piVar1 - *(int *)(*arg1_00 + 0x1068);
  }
  uVar13 = *(uint *)(*arg1_00 + 0x105c);
  if (1 < uVar13) {
    *(uint *)(*arg1_00 + 0x105c) = uVar13 & 0xfffffffe;
  }
  if ((*(byte *)((int)arg1_00 + 10) & 8) == 0) {
    iVar8 = *arg1_00;
    iVar6 = *(int *)(iVar8 + 4);
    if (((iVar6 == *(int *)(arg1_00[1] + 4)) && (1 < *(uint *)(iVar8 + 0x1058))) &&
       (1 < *(uint *)(iVar8 + 0x105c))) {
      if (iVar6 < 0x1d) {
        if (iVar6 == 0x1c) {
LAB_10014914:
          iVar8 = FUN_10013bd7(arg1_00);
        }
        else {
          switch(iVar6) {
          default:
            goto switchD_100148a1_caseD_14;
          case 0x15:
            iVar8 = FUN_100132bb(arg1_00);
            break;
          case 0x16:
            iVar8 = FUN_10013551(arg1_00);
            break;
          case 0x17:
            iVar8 = FUN_10013582(arg1_00);
            break;
          case 0x18:
            iVar8 = FUN_100136d2(arg1_00);
            break;
          case 0x19:
            iVar8 = FUN_100137f6(arg1_00);
            break;
          case 0x1a:
            iVar8 = FUN_10013945(arg1_00);
            break;
          case 0x1b:
            iVar8 = FUN_10013a98(arg1_00);
          }
        }
      }
      else if (iVar6 == 0x1d) {
        iVar8 = FUN_10013c72(arg1_00);
      }
      else if (iVar6 == 0x1e) {
        iVar8 = FUN_10013dbe(arg1_00);
      }
      else {
        if ((iVar6 == 0x28) || (iVar6 == 0x29)) goto switchD_100148a1_caseD_14;
        if (iVar6 == 0x32) goto LAB_10014914;
        if (iVar6 == 0x33) {
          iVar8 = FUN_10013edf(arg1_00);
        }
        else {
          if (iVar6 != 0x34) goto switchD_100148a1_caseD_14;
          iVar8 = FUN_1001402b(arg1_00);
        }
      }
      if (-1 < iVar8) {
        iVar8 = 0;
        goto LAB_10014b8f;
      }
    }
  }
switchD_100148a1_caseD_14:
  iVar8 = *(int *)(arg1_00[1] + 0x1058);
  pvVar9 = operator_new(iVar8 << 4);
  *(void **)(unaff_EBP + -0x2c) = pvVar9;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar9 == (void *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  }
  else {
    _vector_constructor_iterator_(pvVar9,0x10,iVar8,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x2c);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    iVar8 = -0x7ff8fff2;
  }
  else {
    iVar8 = *(int *)(*arg1_00 + 0x1058);
    if (*(int *)(*arg1_00 + 0x105c) == 1) {
      pvVar9 = operator_new(iVar8 << 4);
      *(void **)(unaff_EBP + -0x2c) = pvVar9;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar9 == (void *)0x0) {
        iVar8 = 0;
      }
      else {
        _vector_constructor_iterator_(pvVar9,0x10,iVar8,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
        iVar8 = *(int *)(unaff_EBP + -0x2c);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(int *)(unaff_EBP + -0x24) = iVar8;
      *(int *)(unaff_EBP + -0x14) = iVar8;
    }
    else {
      pvVar9 = operator_new(iVar8 << 5);
      *(void **)(unaff_EBP + -0x2c) = pvVar9;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      if (pvVar9 == (void *)0x0) {
        iVar8 = 0;
      }
      else {
        _vector_constructor_iterator_
                  (pvVar9,0x10,iVar8 << 1,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
        iVar8 = *(int *)(unaff_EBP + -0x2c);
      }
      iVar6 = *(int *)(*arg1_00 + 0x1058);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(int *)(unaff_EBP + -0x24) = iVar8;
      *(int *)(unaff_EBP + -0x14) = iVar8;
      iVar8 = iVar6 * 0x10 + iVar8;
    }
    *(int *)(unaff_EBP + -0x10) = iVar8;
    if (*(int *)(unaff_EBP + -0x24) == 0) {
      iVar8 = -0x7ff8fff2;
    }
    else {
      if (*(int *)(*arg1_00 + 0x1058) == 1) {
        *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x14);
        iVar8 = *(int *)(unaff_EBP + -0x10);
      }
      else {
        *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x14) + 0x10;
        iVar8 = *(int *)(unaff_EBP + -0x10) + 0x10;
      }
      *(int *)(unaff_EBP + -0x2c) = iVar8;
      iVar8 = *(int *)(arg1_00[1] + 0x105c);
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      if (iVar8 != 0) {
        do {
          iVar8 = *(int *)(unaff_EBP + -0x14);
          iVar6 = *(int *)(unaff_EBP + -0x18) * 2;
          (**(code **)(*(int *)*arg1_00 + 4))(iVar6,0,iVar8);
          if (*(int *)(unaff_EBP + -0x10) != iVar8) {
            (**(code **)(*(int *)*arg1_00 + 4))(iVar6 + 1,0,*(undefined4 *)(unaff_EBP + -0x10));
          }
          uVar13 = 0;
          if (*(int *)(arg1_00[1] + 0x1058) != 0) {
            *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x1c);
            do {
              iVar8 = uVar13 * 0x20;
              pfVar10 = (float *)(*(int *)(unaff_EBP + -0x28) + iVar8);
              fVar2 = *pfVar10;
              pfVar12 = (float *)(*(int *)(unaff_EBP + -0x14) + iVar8);
              fVar3 = *pfVar12;
              puVar7 = *(undefined4 **)(unaff_EBP + -0x20);
              fVar4 = pfVar10[1];
              *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 0x10;
              fVar5 = pfVar12[1];
              *(float *)(unaff_EBP + -0x44) = pfVar10[2] + pfVar12[2];
              pfVar11 = (float *)(*(int *)(unaff_EBP + -0x10) + iVar8);
              *(float *)(unaff_EBP + -0x40) = pfVar10[3] + pfVar12[3];
              *(float *)(unaff_EBP + -0x5c) = fVar2 + fVar3 + *pfVar11;
              fVar2 = pfVar11[1];
              fVar3 = pfVar11[2];
              pfVar10 = (float *)(*(int *)(unaff_EBP + -0x2c) + iVar8);
              *(float *)(unaff_EBP + -0x50) = *(float *)(unaff_EBP + -0x40) + pfVar11[3];
              uVar13 = uVar13 + 1;
              *(float *)(unaff_EBP + -0x6c) = *(float *)(unaff_EBP + -0x5c) + *pfVar10;
              *(float *)(unaff_EBP + -0x68) = fVar4 + fVar5 + fVar2 + pfVar10[1];
              fVar2 = pfVar10[2];
              fVar4 = pfVar10[3];
              *(float *)(unaff_EBP + -0x3c) = *(float *)(unaff_EBP + -0x6c) * 0.25;
              *(float *)(unaff_EBP + -0x38) = *(float *)(unaff_EBP + -0x68) * 0.25;
              *(float *)(unaff_EBP + -0x34) = (*(float *)(unaff_EBP + -0x44) + fVar3 + fVar2) * 0.25
              ;
              *(float *)(unaff_EBP + -0x30) = (*(float *)(unaff_EBP + -0x50) + fVar4) * 0.25;
              *puVar7 = *(undefined4 *)(unaff_EBP + -0x3c);
              puVar7[1] = *(undefined4 *)(unaff_EBP + -0x38);
              puVar7[2] = *(undefined4 *)(unaff_EBP + -0x34);
              puVar7[3] = *(undefined4 *)(unaff_EBP + -0x30);
            } while (uVar13 < *(uint *)(arg1_00[1] + 0x1058));
          }
          (**(code **)(*(int *)arg1_00[1] + 8))
                    (*(undefined4 *)(unaff_EBP + -0x18),0,*(undefined4 *)(unaff_EBP + -0x1c));
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
        } while (*(uint *)(unaff_EBP + -0x18) < *(uint *)(arg1_00[1] + 0x105c));
      }
      operator_delete(*(void **)(unaff_EBP + -0x24));
      iVar8 = 0;
    }
    operator_delete(*(void **)(unaff_EBP + -0x1c));
  }
LAB_10014b8f:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar8;
}



