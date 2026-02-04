/* FUN_1000be28 @ 1000be28 */

undefined4 FUN_1000be28(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *extraout_ECX;
  uint uVar7;
  int *unaff_EBX;
  uint arg3;
  int unaff_EBP;
  undefined4 uVar8;
  uint *puVar9;
  
  seh_prolog();
  FUN_10010285((int *)(unaff_EBP + -0x98));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((*(int *)(unaff_EBP + 8) == 0) || (extraout_ECX == (int *)0x0)) {
    uVar8 = 0x8876086c;
    goto LAB_1000c194;
  }
  iVar2 = (**(code **)(*extraout_ECX + 0x28))(extraout_ECX);
  *(int *)(unaff_EBP + -0x40) = iVar2;
  if (((iVar2 != 3) && (iVar2 != 4)) && (iVar2 != 5)) {
    uVar8 = 0x8876086c;
    goto LAB_1000c194;
  }
  *(int **)(unaff_EBP + -0x24) = extraout_ECX;
  if (*(int *)(unaff_EBP + 0xc) == 4) {
    *(uint *)(unaff_EBP + -0x30) = ((iVar2 != 5) - 1 & 5) + 1;
    iVar3 = (**(code **)(*extraout_ECX + 0x34))(extraout_ECX);
  }
  else {
    iVar3 = 1;
    *(undefined4 *)(unaff_EBP + -0x30) = 1;
  }
  arg3 = iVar3 * *(int *)(unaff_EBP + -0x30);
  puVar9 = (uint *)0x0;
  *(int *)(unaff_EBP + -0x20) = iVar3;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  if (iVar2 == 3) {
LAB_1000becd:
    puVar4 = operator_new(arg3 * 0x10 + 4);
    *(uint **)(unaff_EBP + -0x2c) = puVar4;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (puVar4 != (uint *)0x0) {
      puVar9 = puVar4 + 1;
      *puVar4 = arg3;
      FUN_1004b6c3((int)puVar9,0x10,arg3,0x10016121);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(uint **)(unaff_EBP + -0x2c) = puVar9;
    if (puVar9 != (uint *)0x0) {
      puVar5 = operator_new(arg3 * 4);
      *(undefined4 **)(unaff_EBP + -0x14) = puVar5;
joined_r0x1000bfcb:
      if (puVar5 != (undefined4 *)0x0) {
        for (uVar7 = arg3 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
        }
        for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
          *(undefined1 *)puVar5 = 0;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
        }
        goto LAB_1000bf39;
      }
    }
LAB_1000c1dc:
    *(undefined4 *)(unaff_EBP + -0x10) = 0x8007000e;
  }
  else {
    if (iVar2 == 4) {
      puVar9 = operator_new(arg3 * 4 + 4);
      *(uint **)(unaff_EBP + -0x34) = puVar9;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      if (puVar9 == (uint *)0x0) {
        puVar4 = (uint *)0x0;
      }
      else {
        puVar4 = puVar9 + 1;
        *puVar9 = arg3;
        FUN_1004b6c3((int)puVar4,4,arg3,0x1001619a);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      *(uint **)(unaff_EBP + -0x34) = puVar4;
      if (puVar4 != (uint *)0x0) {
        puVar5 = operator_new(arg3 * 4);
        *(undefined4 **)(unaff_EBP + -0x18) = puVar5;
        goto joined_r0x1000bfcb;
      }
      goto LAB_1000c1dc;
    }
    if (iVar2 == 5) goto LAB_1000becd;
LAB_1000bf39:
    *(int *)(unaff_EBP + -0x38) = unaff_EBP + -0x98;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    if (*(int *)(unaff_EBP + -0x30) != 0) {
      *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      do {
        uVar7 = 0;
        if (*(int *)(unaff_EBP + -0x1c) != 0) {
          piVar6 = operator_new(0x54);
          *(int **)(unaff_EBP + -0x28) = piVar6;
          *(undefined1 *)(unaff_EBP + -4) = 3;
          if (piVar6 == (int *)0x0) {
            piVar6 = (int *)0x0;
          }
          else {
            piVar6 = FUN_10010285(piVar6);
          }
          *(undefined1 *)(unaff_EBP + -4) = 0;
          if (piVar6 == (int *)0x0) goto LAB_1000c1dc;
          *(int **)(*(int *)(unaff_EBP + -0x38) + 0x50) = piVar6;
          *(int **)(unaff_EBP + -0x38) = piVar6;
        }
        *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x38);
        if (*(int *)(unaff_EBP + -0x20) != 0) {
          do {
            if (uVar7 != 0) {
              piVar6 = operator_new(0x54);
              *(int **)(unaff_EBP + -0x44) = piVar6;
              *(undefined1 *)(unaff_EBP + -4) = 4;
              if (piVar6 == (int *)0x0) {
                piVar6 = (int *)0x0;
              }
              else {
                piVar6 = FUN_10010285(piVar6);
              }
              *(undefined1 *)(unaff_EBP + -4) = 0;
              if (piVar6 == (int *)0x0) goto LAB_1000c1dc;
              *(int **)(*(int *)(unaff_EBP + -0x28) + 0x4c) = piVar6;
              *(int **)(unaff_EBP + -0x28) = piVar6;
            }
            iVar2 = *(int *)(unaff_EBP + -0x3c) + uVar7;
            iVar3 = *(int *)(unaff_EBP + -0x40);
            if (iVar3 == 3) {
              iVar3 = *(int *)(unaff_EBP + -0x14);
LAB_1000c06a:
              uVar8 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0x3c))
                                (*(int **)(unaff_EBP + -0x24),uVar7,iVar3 + iVar2 * 4);
LAB_1000c078:
              *(undefined4 *)(unaff_EBP + -0x10) = uVar8;
            }
            else {
              if (iVar3 == 4) {
                iVar3 = *(int *)(unaff_EBP + -0x18);
                goto LAB_1000c06a;
              }
              if (iVar3 == 5) {
                uVar8 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0x3c))
                                  (*(int **)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x1c),
                                   uVar7,*(int *)(unaff_EBP + -0x14) + iVar2 * 4);
                goto LAB_1000c078;
              }
            }
            if (*(int *)(unaff_EBP + -0x10) < 0) goto LAB_1000c117;
            iVar3 = *(int *)(unaff_EBP + -0x40);
            if (iVar3 == 3) {
LAB_1000c097:
              iVar2 = FUN_100161bb((void *)(iVar2 * 0x10 + *(int *)(unaff_EBP + -0x2c)),
                                   (char *)(unaff_EBP + -0xe4),
                                   *(int **)(*(int *)(unaff_EBP + -0x14) + iVar2 * 4),
                                   *(int **)(unaff_EBP + 0x10),0,(int *)0x0,1,(int)unaff_EBX);
LAB_1000c0ba:
              *(int *)(unaff_EBP + -0x10) = iVar2;
            }
            else {
              if (iVar3 == 4) {
                iVar2 = FUN_100165d3((void *)(*(int *)(unaff_EBP + -0x34) + iVar2 * 4),
                                     (int *)(unaff_EBP + -0xe4),
                                     *(int **)(iVar2 * 4 + *(int *)(unaff_EBP + -0x18)),
                                     *(int **)(unaff_EBP + 0x10),0,0,1,(int)unaff_EBX);
                goto LAB_1000c0ba;
              }
              if (iVar3 == 5) goto LAB_1000c097;
            }
            if (*(int *)(unaff_EBP + -0x10) < 0) goto LAB_1000c117;
            iVar2 = FUN_10010313(*(void **)(unaff_EBP + -0x28),(int *)(unaff_EBP + -0xe4),unaff_EBX)
            ;
            *(int *)(unaff_EBP + -0x10) = iVar2;
            if (iVar2 < 0) goto LAB_1000c117;
            uVar7 = uVar7 + 1;
          } while (uVar7 < *(uint *)(unaff_EBP + -0x20));
        }
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
        *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x3c) + *(int *)(unaff_EBP + -0x20);
      } while (*(uint *)(unaff_EBP + -0x1c) < *(uint *)(unaff_EBP + -0x30));
    }
    iVar2 = FUN_1001237e(*(int **)(unaff_EBP + 8),*(int *)(unaff_EBP + 0xc),
                         *(int *)(unaff_EBP + 0x14),unaff_EBX);
    *(int *)(unaff_EBP + -0x10) = iVar2;
    if (-1 < iVar2) {
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
    }
  }
LAB_1000c117:
  uVar7 = 0;
  if (*(CODBCFieldInfo **)(unaff_EBP + -0x2c) != (CODBCFieldInfo *)0x0) {
    CODBCFieldInfo::_vector_deleting_destructor_(*(CODBCFieldInfo **)(unaff_EBP + -0x2c),3);
  }
  if (*(void **)(unaff_EBP + -0x34) != (void *)0x0) {
    FID_conflict__vector_deleting_destructor_(*(void **)(unaff_EBP + -0x34),3);
  }
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    if (arg3 != 0) {
      do {
        piVar6 = (int *)(*(int *)(unaff_EBP + -0x14) + uVar7 * 4);
        piVar1 = (int *)*piVar6;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *piVar6 = 0;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < arg3);
    }
    operator_delete(*(void **)(unaff_EBP + -0x14));
  }
  uVar7 = 0;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    if (arg3 != 0) {
      do {
        piVar6 = (int *)(*(int *)(unaff_EBP + -0x18) + uVar7 * 4);
        piVar1 = (int *)*piVar6;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *piVar6 = 0;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < arg3);
    }
    operator_delete(*(void **)(unaff_EBP + -0x18));
  }
  uVar8 = *(undefined4 *)(unaff_EBP + -0x10);
LAB_1000c194:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1001029e((void *)(unaff_EBP + -0x98));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar8;
}



