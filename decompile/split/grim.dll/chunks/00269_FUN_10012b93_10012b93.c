/* FUN_10012b93 @ 10012b93 */

/* [binja] int32_t __fastcall sub_10012b93(int32_t* arg1) */

int FUN_10012b93(int *arg1)

{
  int *piVar1;
  float fVar2;
  int *piVar3;
  void *pvVar4;
  int *extraout_ECX;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  float *pfVar9;
  int unaff_EBP;
  undefined4 unaff_EDI;
  undefined4 *puVar10;
  float *pfVar11;
  char arg2;
  
  seh_prolog();
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x58) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x5c) = 0;
  uVar5 = extraout_ECX[2];
  *(uint *)(unaff_EBP + -0x54) = ~(uVar5 >> 0x12) & 1;
  piVar3 = FUN_1001288a(*(uint *)(*extraout_ECX + 0x1058),*(int *)(extraout_ECX[1] + 0x1058),
                        ~(uVar5 >> 0x10) & 1);
  arg2 = (char)unaff_EDI;
  *(int **)(unaff_EBP + -0x44) = piVar3;
  if (piVar3 != (int *)0x0) {
    piVar3 = FUN_1001288a(*(uint *)(*extraout_ECX + 0x105c),*(int *)(extraout_ECX[1] + 0x105c),
                          ~(uVar5 >> 0x11) & 1);
    arg2 = (char)unaff_EDI;
    *(int **)(unaff_EBP + -0x2c) = piVar3;
    if (piVar3 != (int *)0x0) {
      piVar3 = FUN_1001288a(*(uint *)(*extraout_ECX + 0x1060),*(int *)(extraout_ECX[1] + 0x1060),
                            *(int *)(unaff_EBP + -0x54));
      arg2 = (char)unaff_EDI;
      *(int **)(unaff_EBP + -0x28) = piVar3;
      if (piVar3 != (int *)0x0) {
        *(int *)(unaff_EBP + -0x4c) =
             **(int **)(unaff_EBP + -0x44) + (int)*(int **)(unaff_EBP + -0x44);
        *(int *)(unaff_EBP + -0x50) =
             **(int **)(unaff_EBP + -0x2c) + (int)*(int **)(unaff_EBP + -0x2c);
        *(int *)(unaff_EBP + -0x24) =
             **(int **)(unaff_EBP + -0x28) + (int)*(int **)(unaff_EBP + -0x28);
        iVar6 = *(int *)(extraout_ECX[1] + 0x1060);
        piVar3 = operator_new(iVar6 * 0xc + 4);
        *(int **)(unaff_EBP + -0x54) = piVar3;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (piVar3 == (int *)0x0) {
          *(undefined4 *)(unaff_EBP + -0x14) = 0;
          iVar6 = *(int *)(unaff_EBP + -0x14);
        }
        else {
          *piVar3 = iVar6;
          *(int **)(unaff_EBP + -0x58) = piVar3 + 1;
          FUN_1004b6c3((int)(piVar3 + 1),0xc,iVar6,0x10012874);
          iVar6 = *(int *)(unaff_EBP + -0x58);
          *(int *)(unaff_EBP + -0x14) = iVar6;
        }
        arg2 = (char)unaff_EDI;
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int *)(unaff_EBP + -0x58) = iVar6;
        if (iVar6 != 0) {
          iVar6 = *(int *)(*extraout_ECX + 0x1058);
          pvVar4 = operator_new(iVar6 << 4);
          *(void **)(unaff_EBP + -0x5c) = pvVar4;
          *(undefined4 *)(unaff_EBP + -4) = 1;
          if (pvVar4 == (void *)0x0) {
            *(undefined4 *)(unaff_EBP + -0x1c) = 0;
            iVar6 = *(int *)(unaff_EBP + -0x1c);
          }
          else {
            _vector_constructor_iterator_
                      (pvVar4,0x10,iVar6,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
            iVar6 = *(int *)(unaff_EBP + -0x5c);
            *(int *)(unaff_EBP + -0x1c) = iVar6;
          }
          arg2 = (char)unaff_EDI;
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          *(int *)(unaff_EBP + -0x5c) = iVar6;
          if (iVar6 != 0) {
            piVar3 = (int *)(*(int *)(unaff_EBP + -0x28) + 4);
            piVar8 = piVar3;
            if (piVar3 < *(int **)(unaff_EBP + -0x24)) {
              do {
                piVar7 = (int *)(*piVar8 + (int)piVar8);
                for (piVar8 = piVar8 + 1; piVar8 < piVar7; piVar8 = piVar8 + 2) {
                  piVar1 = (int *)(*(int *)(unaff_EBP + -0x14) + 8 + *piVar8 * 0xc);
                  *piVar1 = *piVar1 + 1;
                }
                piVar8 = piVar7;
              } while (piVar7 < *(int **)(unaff_EBP + -0x24));
            }
            *(undefined4 *)(unaff_EBP + -0x40) = 0;
            if (piVar3 < *(int **)(unaff_EBP + -0x24)) {
              do {
                piVar8 = (int *)(*piVar3 + (int)piVar3);
                piVar7 = piVar3 + 1;
                *(int **)(unaff_EBP + -0x18) = piVar8;
                *(int **)(unaff_EBP + -0x54) = piVar7;
                *(int **)(unaff_EBP + -0x10) = piVar7;
                piVar3 = piVar8;
                if (piVar7 < piVar8) {
                  do {
                    piVar3 = (int *)(*(int *)(unaff_EBP + -0x14) +
                                    **(int **)(unaff_EBP + -0x10) * 0xc);
                    if (*piVar3 == 0) {
                      piVar7 = *(int **)(unaff_EBP + -0x20);
                      if (piVar7 == (int *)0x0) {
                        iVar6 = *(int *)(extraout_ECX[1] + 0x105c) *
                                *(int *)(extraout_ECX[1] + 0x1058);
                        pvVar4 = operator_new(iVar6 * 0x10);
                        *(void **)(unaff_EBP + -0x48) = pvVar4;
                        *(undefined4 *)(unaff_EBP + -4) = 2;
                        if (pvVar4 == (void *)0x0) {
                          iVar6 = 0;
                        }
                        else {
                          _vector_constructor_iterator_
                                    (pvVar4,0x10,iVar6,(_func_void_ptr_void_ptr *)&LAB_1000ae4f);
                          iVar6 = *(int *)(unaff_EBP + -0x48);
                        }
                        arg2 = (char)unaff_EDI;
                        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                        *piVar3 = iVar6;
                        if (iVar6 == 0) goto LAB_10012fb2;
                        piVar8 = *(int **)(unaff_EBP + -0x18);
                      }
                      else {
                        *piVar3 = *piVar7;
                        *piVar7 = 0;
                        *(int *)(unaff_EBP + -0x20) = piVar7[1];
                      }
                      puVar10 = (undefined4 *)*piVar3;
                      for (uVar5 = (uint)(*(int *)(extraout_ECX[1] + 0x105c) *
                                          *(int *)(extraout_ECX[1] + 0x1058) * 0x10) >> 2;
                          uVar5 != 0; uVar5 = uVar5 - 1) {
                        *puVar10 = 0;
                        puVar10 = puVar10 + 1;
                      }
                      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                        *(undefined1 *)puVar10 = 0;
                        puVar10 = (undefined4 *)((int)puVar10 + 1);
                      }
                    }
                    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 8;
                    piVar3 = piVar8;
                  } while (*(int **)(unaff_EBP + -0x10) < piVar8);
                }
                *(undefined4 *)(unaff_EBP + -0x38) = 0;
                uVar5 = *(int *)(unaff_EBP + -0x2c) + 4;
                *(uint *)(unaff_EBP + -0x3c) = uVar5;
                if (uVar5 < *(uint *)(unaff_EBP + -0x50)) {
                  do {
                    piVar3 = (int *)(**(int **)(unaff_EBP + -0x3c) +
                                    (int)*(int **)(unaff_EBP + -0x3c));
                    iVar6 = *(int *)*extraout_ECX;
                    *(int **)(unaff_EBP + -0x48) = piVar3;
                    (**(code **)(iVar6 + 4))
                              (*(undefined4 *)(unaff_EBP + -0x38),*(undefined4 *)(unaff_EBP + -0x40)
                               ,*(undefined4 *)(unaff_EBP + -0x1c));
                    uVar5 = *(int *)(unaff_EBP + -0x44) + 4;
                    *(uint *)(unaff_EBP + -0x34) = uVar5;
                    if (uVar5 < *(uint *)(unaff_EBP + -0x4c)) {
                      pfVar9 = (float *)(*(int *)(unaff_EBP + -0x1c) + 8);
                      do {
                        uVar5 = **(int **)(unaff_EBP + -0x34) + (int)*(int **)(unaff_EBP + -0x34);
                        piVar8 = *(int **)(unaff_EBP + -0x54);
                        *(uint *)(unaff_EBP + -0x30) = uVar5;
                        for (; *(int **)(unaff_EBP + -0x10) = piVar8,
                            piVar8 < *(int **)(unaff_EBP + -0x18); piVar8 = piVar8 + 2) {
                          piVar7 = (int *)(*(int *)(unaff_EBP + -0x3c) + 4);
                          if (piVar7 < piVar3) {
                            do {
                              iVar6 = *(int *)(extraout_ECX[1] + 0x1058) * *piVar7 * 0x10 +
                                      *(int *)(*(int *)(unaff_EBP + -0x14) + *piVar8 * 0xc);
                              for (piVar3 = (int *)(*(int *)(unaff_EBP + -0x34) + 4);
                                  piVar3 < *(int **)(unaff_EBP + -0x30); piVar3 = piVar3 + 2) {
                                fVar2 = (float)piVar3[1] * (float)piVar7[1] *
                                        *(float *)(*(int *)(unaff_EBP + -0x10) + 4);
                                pfVar11 = (float *)(*piVar3 * 0x10 + iVar6);
                                *pfVar11 = fVar2 * pfVar9[-2] + *pfVar11;
                                pfVar11 = (float *)(*piVar3 * 0x10 + 4 + iVar6);
                                *pfVar11 = fVar2 * pfVar9[-1] + *pfVar11;
                                pfVar11 = (float *)(*piVar3 * 0x10 + 8 + iVar6);
                                *pfVar11 = fVar2 * *pfVar9 + *pfVar11;
                                pfVar11 = (float *)(*piVar3 * 0x10 + 0xc + iVar6);
                                *pfVar11 = fVar2 * pfVar9[1] + *pfVar11;
                              }
                              piVar8 = *(int **)(unaff_EBP + -0x10);
                              piVar7 = piVar7 + 2;
                            } while (piVar7 < *(int **)(unaff_EBP + -0x48));
                            piVar3 = *(int **)(unaff_EBP + -0x48);
                            uVar5 = *(uint *)(unaff_EBP + -0x30);
                          }
                        }
                        pfVar9 = pfVar9 + 4;
                        *(uint *)(unaff_EBP + -0x34) = uVar5;
                      } while (uVar5 < *(uint *)(unaff_EBP + -0x4c));
                    }
                    *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) + 1;
                    *(int **)(unaff_EBP + -0x3c) = piVar3;
                  } while (piVar3 < *(int **)(unaff_EBP + -0x50));
                  piVar3 = *(int **)(unaff_EBP + -0x18);
                }
                for (piVar8 = *(int **)(unaff_EBP + -0x54); arg2 = (char)unaff_EDI, piVar8 < piVar3;
                    piVar8 = piVar8 + 2) {
                  piVar1 = (int *)(*(int *)(unaff_EBP + -0x14) + *piVar8 * 0xc);
                  piVar7 = piVar1 + 2;
                  *piVar7 = *piVar7 + -1;
                  if (*piVar7 == 0) {
                    piVar7 = (int *)extraout_ECX[1];
                    *(undefined4 *)(unaff_EBP + -0x10) = 0;
                    if (piVar7[0x417] != 0) {
                      do {
                        (**(code **)(*piVar7 + 8))
                                  (*(undefined4 *)(unaff_EBP + -0x10),*piVar8,
                                   piVar7[0x416] * *(int *)(unaff_EBP + -0x10) * 0x10 + *piVar1);
                        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
                        piVar7 = (int *)extraout_ECX[1];
                      } while (*(uint *)(unaff_EBP + -0x10) < (uint)piVar7[0x417]);
                      piVar3 = *(int **)(unaff_EBP + -0x18);
                    }
                    piVar1[1] = *(int *)(unaff_EBP + -0x20);
                    *(int **)(unaff_EBP + -0x20) = piVar1;
                  }
                }
                *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 1;
              } while (piVar3 < *(int **)(unaff_EBP + -0x24));
            }
            iVar6 = 0;
            goto LAB_10012fbe;
          }
        }
LAB_10012fb2:
        iVar6 = -0x7ff8fff2;
        goto LAB_10012fbe;
      }
    }
  }
  iVar6 = -0x7fffbffb;
LAB_10012fbe:
  if (*(void **)(unaff_EBP + -0x58) != (void *)0x0) {
    FUN_10012b47(*(void **)(unaff_EBP + -0x58),(int *)0x3,arg2);
  }
  operator_delete(*(void **)(unaff_EBP + -0x28));
  operator_delete(*(void **)(unaff_EBP + -0x2c));
  operator_delete(*(void **)(unaff_EBP + -0x44));
  operator_delete(*(void **)(unaff_EBP + -0x5c));
  operator_delete((void *)0x0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar6;
}



