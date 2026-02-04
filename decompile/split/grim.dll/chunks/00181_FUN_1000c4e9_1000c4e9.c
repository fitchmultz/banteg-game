/* FUN_1000c4e9 @ 1000c4e9 */

/* [binja] int32_t sub_1000c4e9(int32_t** arg1, void* arg2, int32_t* arg3, int32_t arg4, int32_t
   arg5, int32_t arg6, int32_t arg7, int32_t arg8, void* arg9, int32_t arg10, int32_t arg11,
   int32_t** arg12) */

int FUN_1000c4e9(int **arg1,void *arg2,int *arg3,int arg4,int arg5,int arg6,int arg7,int arg8,
                void *arg9,int arg10,int arg11,int **arg12)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int unaff_EBP;
  undefined4 *puVar10;
  int *piVar11;
  int unaff_EDI;
  int iVar12;
  undefined4 *puVar13;
  
  seh_prolog();
  piVar8 = *(int **)(unaff_EBP + 0x3c);
  FUN_10010285((int *)(unaff_EBP + -0x8c));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  if ((((*(int *)(unaff_EBP + 8) == 0) || (*(int *)(unaff_EBP + 0xc) == 0)) ||
      (*(int *)(unaff_EBP + 0x10) == 0)) || (*(int *)(unaff_EBP + 0x48) == 0)) {
    iVar12 = -0x7789f794;
    goto LAB_1000cb0e;
  }
  if ((piVar8 == (int *)0x0) && (*(int *)(unaff_EBP + 0x44) == -1)) {
    piVar8 = (int *)(unaff_EBP + -0xcc);
  }
  iVar12 = FUN_10012677((void *)(unaff_EBP + -0x8c),*(int **)(unaff_EBP + 0xc),
                        *(void **)(unaff_EBP + 0x10),piVar8,(int *)0x1,unaff_EDI);
  if (iVar12 < 0) goto LAB_1000cb0e;
  if (*(int *)(unaff_EBP + 0x44) == -1) {
    *(int *)(unaff_EBP + 0x44) = piVar8[5];
  }
  iVar12 = *(int *)(unaff_EBP + -0x40);
  *(undefined4 *)(unaff_EBP + -0x24) = 1;
  for (; iVar12 != 0; iVar12 = *(int *)(iVar12 + 0x4c)) {
    *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
  }
  *(undefined4 *)(unaff_EBP + -0x28) = 1;
  if (*(int *)(unaff_EBP + 0x44) == 5) {
    iVar12 = *(int *)(unaff_EBP + -0x3c);
    if (iVar12 != 0) {
      do {
        iVar12 = *(int *)(iVar12 + 0x50);
        *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
      } while (iVar12 != 0);
      if (*(int *)(unaff_EBP + -0x28) == 6) goto LAB_1000c5b6;
    }
    iVar12 = -0x7fffbffb;
    goto LAB_1000cb0e;
  }
LAB_1000c5b6:
  if ((*(int *)(unaff_EBP + 0x14) == 0) || (*(int *)(unaff_EBP + 0x14) == -1)) {
    *(undefined4 *)(unaff_EBP + 0x14) = *(undefined4 *)(unaff_EBP + -0x80);
  }
  if ((*(int *)(unaff_EBP + 0x18) == 0) || (*(int *)(unaff_EBP + 0x18) == -1)) {
    *(undefined4 *)(unaff_EBP + 0x18) = *(undefined4 *)(unaff_EBP + -0x7c);
  }
  if ((*(int *)(unaff_EBP + 0x1c) == 0) || (*(int *)(unaff_EBP + 0x1c) == -1)) {
    *(undefined4 *)(unaff_EBP + 0x1c) = *(undefined4 *)(unaff_EBP + -0x78);
  }
  if (*(int *)(unaff_EBP + 0x30) == -1) {
    *(undefined4 *)(unaff_EBP + 0x30) = 0x80004;
  }
  if (*(int *)(unaff_EBP + 0x34) == -1) {
    *(undefined4 *)(unaff_EBP + 0x34) = 5;
  }
  if (*(int *)(unaff_EBP + 0x44) == 5) {
    *(uint *)(unaff_EBP + 0x30) = *(uint *)(unaff_EBP + 0x30) | 0x70000;
    *(uint *)(unaff_EBP + 0x34) = *(uint *)(unaff_EBP + 0x34) | 0x70000;
  }
  if (((*(char *)(unaff_EBP + 0x30) == '\x01') ||
      (uVar7 = *(uint *)(unaff_EBP + 0x34) & 0xff, uVar7 == 2)) ||
     (*(undefined4 *)(unaff_EBP + -0x30) = 0, uVar7 == 5)) {
    *(undefined4 *)(unaff_EBP + -0x30) = 1;
  }
  if (*(int *)(unaff_EBP + 0x28) == 0) {
    iVar12 = *(int *)(unaff_EBP + -0x8c);
    if (*(int *)(unaff_EBP + 0x38) != 0) {
      piVar8 = grim_format_info_lookup(iVar12);
      iVar2 = piVar8[1];
      if ((((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 2)) && (piVar8[4] == 0)) {
        uVar3 = *(undefined4 *)(unaff_EBP + 0x44);
        uVar4 = *(undefined4 *)(unaff_EBP + 0x24);
        piVar11 = (int *)(unaff_EBP + -0xb0);
        for (iVar12 = 9; iVar12 != 0; iVar12 = iVar12 + -1) {
          *piVar11 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar11 = piVar11 + 1;
        }
        *(undefined4 *)(unaff_EBP + -0xb0) = 0;
        *(undefined4 *)(unaff_EBP + -0xa0) = 1;
        iVar12 = FUN_1000abad((int *)0x0,uVar4,uVar3,(int *)(unaff_EBP + -0xb0));
        if (iVar12 == 0) {
          iVar12 = *(int *)(unaff_EBP + -0x8c);
        }
      }
    }
    iVar12 = FUN_1000ac8f(iVar12);
    *(int *)(unaff_EBP + 0x28) = iVar12;
    if ((*(int *)(unaff_EBP + 0x2c) != 3) && (iVar12 == 0x14)) {
      *(undefined4 *)(unaff_EBP + 0x28) = 0x16;
    }
  }
  iVar12 = *(int *)(unaff_EBP + -0x84);
  if (iVar12 == 0) {
    puVar10 = (undefined4 *)(unaff_EBP + -0x4cc);
    for (iVar12 = 0x100; uVar7 = 0, iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar10 = 0xffffffff;
      puVar10 = puVar10 + 1;
    }
  }
  else {
    uVar9 = *(uint *)(unaff_EBP + 0x38);
    bVar1 = *(byte *)(unaff_EBP + 0x3a);
    uVar7 = 0;
    do {
      uVar5 = *(uint *)(iVar12 + uVar7 * 4);
      *(uint *)(unaff_EBP + -0x4cc + uVar7 * 4) =
           -(uint)(uVar5 != ((uint)bVar1 | (uVar9 & 0xff) << 0x10 | uVar9 & 0xff00ff00)) & uVar5;
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0x100);
    *(undefined4 *)(unaff_EBP + 0x38) = 0;
  }
  if (*(undefined4 **)(unaff_EBP + 0x40) == (undefined4 *)0x0) {
    if (*(int *)(unaff_EBP + 0x28) == 0x28) {
LAB_1000c75c:
      *(undefined4 *)(unaff_EBP + 0x28) = 0x15;
    }
    else if (*(int *)(unaff_EBP + 0x28) == 0x29) {
      *(undefined4 *)(unaff_EBP + 0x28) = 0x16;
      uVar9 = 0;
      do {
        if (*(char *)(unaff_EBP + -0x4c9 + uVar9 * 4) != -1) goto LAB_1000c75c;
        uVar9 = uVar9 + 1;
      } while (uVar9 < 0x100);
    }
  }
  else {
    puVar10 = (undefined4 *)(unaff_EBP + -0x4cc);
    puVar13 = *(undefined4 **)(unaff_EBP + 0x40);
    for (iVar12 = 0x100; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar13 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar13 = puVar13 + 1;
    }
    uVar7 = 0;
  }
  if ((*(int *)(unaff_EBP + 0x2c) != 0) ||
     (*(undefined4 *)(unaff_EBP + -0x34) = 1, (*(byte *)(unaff_EBP + 0x25) & 2) != 0)) {
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
  }
  iVar12 = FUN_1000af45(uVar7,*(uint *)(unaff_EBP + 0x24),*(int **)(unaff_EBP + 8),
                        (uint *)(unaff_EBP + 0x14),(uint *)(unaff_EBP + 0x18),
                        (uint *)(unaff_EBP + 0x1c),(uint *)(unaff_EBP + 0x20),
                        (int *)(unaff_EBP + 0x28),*(int *)(unaff_EBP + 0x2c),
                        *(int *)(unaff_EBP + 0x44));
  if (-1 < iVar12) {
    iVar2 = *(int *)(unaff_EBP + 0x44);
    uVar3 = *(undefined4 *)(unaff_EBP + 0x28);
    uVar4 = *(undefined4 *)(unaff_EBP + 0x14);
    if (iVar2 == 3) {
      iVar12 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x50))
                         (*(int **)(unaff_EBP + 8),uVar4,*(undefined4 *)(unaff_EBP + 0x18),
                          *(undefined4 *)(unaff_EBP + 0x20),*(undefined4 *)(unaff_EBP + 0x24),uVar3,
                          *(undefined4 *)(unaff_EBP + 0x2c),unaff_EBP + -0x1c);
    }
    else if (iVar2 == 4) {
      iVar12 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x54))
                         (*(int **)(unaff_EBP + 8),uVar4,*(undefined4 *)(unaff_EBP + 0x18),
                          *(undefined4 *)(unaff_EBP + 0x1c),*(undefined4 *)(unaff_EBP + 0x20),
                          *(undefined4 *)(unaff_EBP + 0x24),uVar3,*(undefined4 *)(unaff_EBP + 0x2c),
                          unaff_EBP + -0x1c);
    }
    else if (iVar2 == 5) {
      iVar12 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x58))
                         (*(int **)(unaff_EBP + 8),uVar4,*(undefined4 *)(unaff_EBP + 0x20),
                          *(undefined4 *)(unaff_EBP + 0x24),uVar3,*(undefined4 *)(unaff_EBP + 0x2c),
                          unaff_EBP + -0x1c);
    }
    if (-1 < iVar12) {
      if (*(int *)(unaff_EBP + -0x34) == 0) {
        piVar8 = *(int **)(unaff_EBP + -0x1c);
      }
      else {
        iVar2 = *(int *)(unaff_EBP + 0x44);
        if (iVar2 == 3) {
          iVar12 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x50))
                             (*(int **)(unaff_EBP + 8),uVar4,*(undefined4 *)(unaff_EBP + 0x18),
                              *(undefined4 *)(unaff_EBP + 0x20),0,uVar3,2,unaff_EBP + -0x20);
        }
        else if (iVar2 == 4) {
          iVar12 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x54))
                             (*(int **)(unaff_EBP + 8),uVar4,*(undefined4 *)(unaff_EBP + 0x18),
                              *(undefined4 *)(unaff_EBP + 0x1c),*(undefined4 *)(unaff_EBP + 0x20),0,
                              uVar3,2,unaff_EBP + -0x20);
        }
        else if (iVar2 == 5) {
          iVar12 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x58))
                             (*(int **)(unaff_EBP + 8),uVar4,*(undefined4 *)(unaff_EBP + 0x20),0,
                              uVar3,2,unaff_EBP + -0x20);
        }
        if (iVar12 < 0) goto LAB_1000cacc;
        piVar8 = *(int **)(unaff_EBP + -0x20);
      }
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      piVar11 = (int *)(unaff_EBP + -0x8c);
      *(int **)(unaff_EBP + -0x38) = piVar11;
      if (*(int *)(unaff_EBP + -0x28) != 0) {
        do {
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          if (*(int *)(unaff_EBP + -0x24) != 0) {
            while (*(uint *)(unaff_EBP + -0x10) < *(uint *)(unaff_EBP + 0x20)) {
              iVar2 = *(int *)(unaff_EBP + 0x44);
              if (iVar2 == 3) {
                iVar12 = unaff_EBP + -0x14;
LAB_1000c8eb:
                iVar12 = (**(code **)(*piVar8 + 0x3c))
                                   (piVar8,*(undefined4 *)(unaff_EBP + -0x10),iVar12);
              }
              else {
                if (iVar2 == 4) {
                  iVar12 = unaff_EBP + -0x18;
                  goto LAB_1000c8eb;
                }
                if (iVar2 == 5) {
                  iVar12 = (**(code **)(*piVar8 + 0x3c))
                                     (piVar8,*(undefined4 *)(unaff_EBP + -0x2c),
                                      *(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x14);
                }
              }
              if (iVar12 < 0) goto LAB_1000cacc;
              iVar2 = *(int *)(unaff_EBP + 0x44);
              if (iVar2 == 3) {
LAB_1000c90d:
                iVar12 = FUN_1000acc0(*(int **)(unaff_EBP + -0x14),*(int *)(unaff_EBP + 0x40),
                                      (int *)0x0,piVar11[1],*piVar11,piVar11[0xc],unaff_EBP + -0x4cc
                                      ,piVar11 + 6,*(int *)(unaff_EBP + 0x30),
                                      *(int *)(unaff_EBP + 0x38));
              }
              else if (iVar2 == 4) {
                iVar12 = FUN_1000ae72(*(int **)(unaff_EBP + -0x18),*(int *)(unaff_EBP + 0x40),0,
                                      piVar11[1],*piVar11,piVar11[0xc],piVar11[0xd],
                                      unaff_EBP + -0x4cc,(int)(piVar11 + 6),
                                      *(int *)(unaff_EBP + 0x30),*(int *)(unaff_EBP + 0x38));
              }
              else if (iVar2 == 5) goto LAB_1000c90d;
              if (iVar12 < 0) goto LAB_1000cacc;
              piVar6 = *(int **)(unaff_EBP + -0x18);
              if (piVar6 != (int *)0x0) {
                (**(code **)(*piVar6 + 8))(piVar6);
                *(undefined4 *)(unaff_EBP + -0x18) = 0;
              }
              piVar6 = *(int **)(unaff_EBP + -0x14);
              if (piVar6 != (int *)0x0) {
                (**(code **)(*piVar6 + 8))(piVar6);
                *(undefined4 *)(unaff_EBP + -0x14) = 0;
              }
              *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
              if (*(uint *)(unaff_EBP + -0x24) <= *(uint *)(unaff_EBP + -0x10)) break;
              piVar11 = (int *)piVar11[0x13];
            }
          }
          if ((*(int *)(unaff_EBP + -0x30) == 0) &&
             (*(uint *)(unaff_EBP + -0x10) < *(uint *)(unaff_EBP + 0x20))) {
            do {
              iVar2 = *(int *)(unaff_EBP + 0x44);
              if (iVar2 == 3) {
                iVar12 = unaff_EBP + -0x14;
LAB_1000c9db:
                iVar12 = (**(code **)(*piVar8 + 0x3c))
                                   (piVar8,*(undefined4 *)(unaff_EBP + -0x10),iVar12);
              }
              else {
                if (iVar2 == 4) {
                  iVar12 = unaff_EBP + -0x18;
                  goto LAB_1000c9db;
                }
                if (iVar2 == 5) {
                  iVar12 = (**(code **)(*piVar8 + 0x3c))
                                     (piVar8,*(undefined4 *)(unaff_EBP + -0x2c),
                                      *(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x14);
                }
              }
              if (iVar12 < 0) goto LAB_1000cacc;
              iVar2 = *(int *)(unaff_EBP + 0x44);
              if (iVar2 == 3) {
LAB_1000ca01:
                iVar12 = FUN_1000acc0(*(int **)(unaff_EBP + -0x14),*(int *)(unaff_EBP + 0x40),
                                      (int *)0x0,piVar11[1],*piVar11,piVar11[0xc],unaff_EBP + -0x4cc
                                      ,piVar11 + 6,*(int *)(unaff_EBP + 0x30),
                                      *(int *)(unaff_EBP + 0x38));
              }
              else if (iVar2 == 4) {
                iVar12 = FUN_1000ae72(*(int **)(unaff_EBP + -0x18),*(int *)(unaff_EBP + 0x40),0,
                                      piVar11[1],*piVar11,piVar11[0xc],piVar11[0xd],
                                      unaff_EBP + -0x4cc,(int)(piVar11 + 6),
                                      *(int *)(unaff_EBP + 0x30),*(int *)(unaff_EBP + 0x38));
              }
              else if (iVar2 == 5) goto LAB_1000ca01;
              if (iVar12 < 0) goto LAB_1000cacc;
              piVar6 = *(int **)(unaff_EBP + -0x18);
              if (piVar6 != (int *)0x0) {
                (**(code **)(*piVar6 + 8))(piVar6);
                *(undefined4 *)(unaff_EBP + -0x18) = 0;
              }
              piVar6 = *(int **)(unaff_EBP + -0x14);
              if (piVar6 != (int *)0x0) {
                (**(code **)(*piVar6 + 8))(piVar6);
                *(undefined4 *)(unaff_EBP + -0x14) = 0;
              }
              *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
            } while (*(uint *)(unaff_EBP + -0x10) < *(uint *)(unaff_EBP + 0x20));
          }
          *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 1;
          piVar11 = *(int **)(*(int *)(unaff_EBP + -0x38) + 0x50);
          *(int **)(unaff_EBP + -0x38) = piVar11;
        } while (*(uint *)(unaff_EBP + -0x2c) < *(uint *)(unaff_EBP + -0x28));
      }
      if ((((*(int *)(unaff_EBP + -0x30) == 0) ||
           (*(uint *)(unaff_EBP + 0x20) <= *(uint *)(unaff_EBP + -0x24))) ||
          (iVar12 = FUN_1000c205(piVar8,(int *)(unaff_EBP + -0x4cc),*(int *)(unaff_EBP + -0x24) + -1
                                 ,*(int *)(unaff_EBP + 0x34)), -1 < iVar12)) &&
         ((*(int *)(unaff_EBP + -0x34) == 0 ||
          (iVar12 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x74))
                              (*(int **)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x20),
                               *(undefined4 *)(unaff_EBP + -0x1c)), -1 < iVar12)))) {
        uVar3 = *(undefined4 *)(unaff_EBP + -0x1c);
        *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        **(undefined4 **)(unaff_EBP + 0x48) = uVar3;
        iVar12 = 0;
      }
    }
  }
LAB_1000cacc:
  piVar8 = *(int **)(unaff_EBP + -0x18);
  if (piVar8 != (int *)0x0) {
    (**(code **)(*piVar8 + 8))(piVar8);
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
  }
  piVar8 = *(int **)(unaff_EBP + -0x14);
  if (piVar8 != (int *)0x0) {
    (**(code **)(*piVar8 + 8))(piVar8);
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
  }
  piVar8 = *(int **)(unaff_EBP + -0x1c);
  if (piVar8 != (int *)0x0) {
    (**(code **)(*piVar8 + 8))(piVar8);
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  }
  piVar8 = *(int **)(unaff_EBP + -0x20);
  if (piVar8 != (int *)0x0) {
    (**(code **)(*piVar8 + 8))(piVar8);
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
  }
LAB_1000cb0e:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1001029e((void *)(unaff_EBP + -0x8c));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar12;
}



