/* FUN_10015c65 @ 10015c65 */

/* [binja] int32_t __fastcall sub_10015c65(int32_t* arg1) */

int FUN_10015c65(int *arg1)

{
  int iVar1;
  float fVar2;
  int *piVar3;
  int *piVar4;
  void *pvVar5;
  int *extraout_ECX;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  float *pfVar9;
  int unaff_EBP;
  float *pfVar10;
  int iVar11;
  undefined4 unaff_EDI;
  undefined4 *puVar12;
  char arg2;
  
  seh_prolog();
  iVar11 = extraout_ECX[1];
  iVar1 = *(int *)(iVar11 + 0x1060);
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x3c) = 0;
  if ((iVar1 != 1) || (*(int *)(*extraout_ECX + 0x1060) != 1)) {
    iVar11 = -0x7fffbffb;
    goto LAB_10015ff8;
  }
  uVar6 = extraout_ECX[2];
  piVar3 = FUN_1001288a(*(uint *)(*extraout_ECX + 0x1058),*(int *)(iVar11 + 0x1058),
                        ~(uVar6 >> 0x10) & 1);
  arg2 = (char)unaff_EDI;
  *(int **)(unaff_EBP + -0x38) = piVar3;
  if (piVar3 == (int *)0x0) {
LAB_10015fba:
    iVar11 = -0x7fffbffb;
  }
  else {
    piVar4 = FUN_1001288a(*(uint *)(*extraout_ECX + 0x105c),*(int *)(extraout_ECX[1] + 0x105c),
                          ~(uVar6 >> 0x11) & 1);
    arg2 = (char)unaff_EDI;
    *(int **)(unaff_EBP + -0x20) = piVar4;
    if (piVar4 == (int *)0x0) goto LAB_10015fba;
    *(int *)(unaff_EBP + -0x2c) = *piVar3 + (int)piVar3;
    piVar4 = (int *)(**(int **)(unaff_EBP + -0x20) + (int)*(int **)(unaff_EBP + -0x20));
    iVar11 = *(int *)(extraout_ECX[1] + 0x105c);
    *(int **)(unaff_EBP + -0x44) = piVar4;
    piVar3 = operator_new(iVar11 * 0xc + 4);
    *(int **)(unaff_EBP + -0x40) = piVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (piVar3 == (int *)0x0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      iVar11 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      *piVar3 = iVar11;
      *(int **)(unaff_EBP + -0x34) = piVar3 + 1;
      FUN_1004b6c3((int)(piVar3 + 1),0xc,iVar11,0x10012874);
      iVar11 = *(int *)(unaff_EBP + -0x34);
      *(int *)(unaff_EBP + -0x14) = iVar11;
    }
    arg2 = (char)unaff_EDI;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x34) = iVar11;
    if (iVar11 == 0) {
LAB_10015fb3:
      iVar11 = -0x7ff8fff2;
    }
    else {
      iVar11 = *(int *)(*extraout_ECX + 0x1058);
      pvVar5 = operator_new(iVar11 << 4);
      *(void **)(unaff_EBP + -0x3c) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar5 == (void *)0x0) {
        *(undefined4 *)(unaff_EBP + -0x24) = 0;
        iVar11 = *(int *)(unaff_EBP + -0x24);
      }
      else {
        _vector_constructor_iterator_(pvVar5,0x10,iVar11,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
        iVar11 = *(int *)(unaff_EBP + -0x3c);
        *(int *)(unaff_EBP + -0x24) = iVar11;
      }
      arg2 = (char)unaff_EDI;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(int *)(unaff_EBP + -0x3c) = iVar11;
      if (iVar11 == 0) goto LAB_10015fb3;
      piVar3 = (int *)(*(int *)(unaff_EBP + -0x20) + 4);
      *(int **)(unaff_EBP + -0x30) = piVar3;
      while (piVar3 < piVar4) {
        piVar8 = (int *)(*piVar3 + (int)piVar3);
        for (piVar7 = piVar3 + 1; piVar3 = piVar8, piVar7 < piVar8; piVar7 = piVar7 + 2) {
          piVar3 = (int *)(*(int *)(unaff_EBP + -0x14) + 8 + *piVar7 * 0xc);
          *piVar3 = *piVar3 + 1;
        }
      }
      piVar3 = *(int **)(unaff_EBP + -0x30);
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      if (piVar3 < piVar4) {
        do {
          iVar11 = *piVar3;
          piVar4 = piVar3 + 1;
          *(int **)(unaff_EBP + -0x1c) = (int *)(iVar11 + (int)piVar3);
          *(int **)(unaff_EBP + -0x30) = piVar4;
          piVar3 = (int *)(iVar11 + (int)piVar3);
          while (*(int **)(unaff_EBP + -0x10) = piVar4, piVar4 < piVar3) {
            piVar4 = (int *)(*(int *)(unaff_EBP + -0x14) + *piVar4 * 0xc);
            if (*piVar4 == 0) {
              piVar3 = *(int **)(unaff_EBP + -0x18);
              if (piVar3 == (int *)0x0) {
                iVar11 = *(int *)(extraout_ECX[1] + 0x1058);
                pvVar5 = operator_new(iVar11 << 4);
                *(void **)(unaff_EBP + -0x40) = pvVar5;
                *(undefined4 *)(unaff_EBP + -4) = 2;
                if (pvVar5 == (void *)0x0) {
                  iVar11 = 0;
                }
                else {
                  _vector_constructor_iterator_
                            (pvVar5,0x10,iVar11,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
                  iVar11 = *(int *)(unaff_EBP + -0x40);
                }
                arg2 = (char)unaff_EDI;
                *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                *piVar4 = iVar11;
                if (iVar11 == 0) goto LAB_10015fb3;
              }
              else {
                *piVar4 = *piVar3;
                *piVar3 = 0;
                *(int *)(unaff_EBP + -0x18) = piVar3[1];
              }
              piVar3 = *(int **)(unaff_EBP + -0x1c);
              puVar12 = (undefined4 *)*piVar4;
              for (uVar6 = (uint)(*(int *)(extraout_ECX[1] + 0x1058) << 4) >> 2; uVar6 != 0;
                  uVar6 = uVar6 - 1) {
                *puVar12 = 0;
                puVar12 = puVar12 + 1;
              }
              for (iVar11 = 0; iVar11 != 0; iVar11 = iVar11 + -1) {
                *(undefined1 *)puVar12 = 0;
                puVar12 = (undefined4 *)((int)puVar12 + 1);
              }
            }
            piVar4 = (int *)(*(int *)(unaff_EBP + -0x10) + 8);
          }
          iVar11 = *(int *)(unaff_EBP + -0x24);
          (**(code **)(*(int *)*extraout_ECX + 4))(*(undefined4 *)(unaff_EBP + -0x28),0,iVar11);
          piVar4 = (int *)(*(int *)(unaff_EBP + -0x38) + 4);
          if (piVar4 < *(int **)(unaff_EBP + -0x2c)) {
            pfVar9 = (float *)(iVar11 + 8);
            do {
              piVar7 = *(int **)(unaff_EBP + -0x30);
              piVar8 = (int *)(*piVar4 + (int)piVar4);
              *(int **)(unaff_EBP + -0x10) = piVar7;
              if (piVar7 < piVar3) {
                *(int **)(unaff_EBP + -0x40) = piVar4 + 1;
                while( true ) {
                  iVar11 = *(int *)(*(int *)(unaff_EBP + -0x14) + *piVar7 * 0xc);
                  piVar4 = *(int **)(unaff_EBP + -0x40);
                  if (piVar4 < piVar8) {
                    do {
                      fVar2 = (float)piVar4[1] * *(float *)(*(int *)(unaff_EBP + -0x10) + 4);
                      pfVar10 = (float *)(*piVar4 * 0x10 + iVar11);
                      *pfVar10 = fVar2 * pfVar9[-2] + *pfVar10;
                      pfVar10 = (float *)(*piVar4 * 0x10 + 4 + iVar11);
                      *pfVar10 = fVar2 * pfVar9[-1] + *pfVar10;
                      pfVar10 = (float *)(*piVar4 * 0x10 + 8 + iVar11);
                      *pfVar10 = fVar2 * *pfVar9 + *pfVar10;
                      pfVar10 = (float *)(*piVar4 * 0x10 + 0xc + iVar11);
                      piVar4 = piVar4 + 2;
                      *pfVar10 = fVar2 * pfVar9[1] + *pfVar10;
                    } while (piVar4 < piVar8);
                    piVar3 = *(int **)(unaff_EBP + -0x1c);
                  }
                  *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 8;
                  if (piVar3 <= *(int **)(unaff_EBP + -0x10)) break;
                  piVar7 = *(int **)(unaff_EBP + -0x10);
                }
              }
              pfVar9 = pfVar9 + 4;
              piVar4 = piVar8;
            } while (piVar8 < *(int **)(unaff_EBP + -0x2c));
          }
          piVar4 = *(int **)(unaff_EBP + -0x30);
          if (piVar4 < piVar3) {
            do {
              puVar12 = (undefined4 *)(*(int *)(unaff_EBP + -0x14) + *piVar4 * 0xc);
              piVar3 = puVar12 + 2;
              *piVar3 = *piVar3 + -1;
              if (*piVar3 == 0) {
                (**(code **)(*(int *)extraout_ECX[1] + 8))(*piVar4,0,*puVar12);
                puVar12[1] = *(undefined4 *)(unaff_EBP + -0x18);
                *(undefined4 **)(unaff_EBP + -0x18) = puVar12;
              }
              piVar4 = piVar4 + 2;
            } while (piVar4 < *(int **)(unaff_EBP + -0x1c));
            piVar3 = *(int **)(unaff_EBP + -0x1c);
          }
          arg2 = (char)unaff_EDI;
          *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
        } while (piVar3 < *(int **)(unaff_EBP + -0x44));
      }
      iVar11 = 0;
    }
  }
  if (*(void **)(unaff_EBP + -0x34) != (void *)0x0) {
    FUN_10012b47(*(void **)(unaff_EBP + -0x34),(int *)0x3,arg2);
  }
  operator_delete(*(void **)(unaff_EBP + -0x20));
  operator_delete(*(void **)(unaff_EBP + -0x38));
  operator_delete(*(void **)(unaff_EBP + -0x3c));
  operator_delete((void *)0x0);
LAB_10015ff8:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar11;
}



