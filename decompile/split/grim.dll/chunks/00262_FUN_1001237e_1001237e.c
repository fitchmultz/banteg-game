/* FUN_1001237e @ 1001237e */

/* [binja] int32_t __thiscall sub_1001237e(int32_t* arg1, int32_t arg2, int32_t arg3, int32_t* arg4)
    */

int FUN_1001237e(int *arg1,int arg2,int arg3,int *arg4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  int *extraout_ECX;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int unaff_EBP;
  undefined4 *puVar8;
  int *unaff_EDI;
  undefined4 *puVar9;
  HANDLE arg2_00;
  
  seh_prolog();
  *(int **)(unaff_EBP + -0x20) = extraout_ECX;
  FUN_1001bca5((int *)(unaff_EBP + -0x3c));
  iVar5 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar5 == 0) {
LAB_100123d3:
    piVar6 = (int *)&DAT_10053e28;
LAB_100123d8:
    piVar1 = grim_format_info_lookup(*extraout_ECX);
    iVar2 = FUN_1000ab3f(piVar6,extraout_ECX[2],piVar1);
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    if (iVar2 != 0) {
      piVar6 = extraout_ECX;
      if (iVar2 != *extraout_ECX) {
        FUN_1001284c((int *)(unaff_EBP + -0x2c));
        *(undefined1 *)(unaff_EBP + -4) = 1;
        piVar1 = grim_format_info_lookup(iVar2);
        uVar3 = (uint)piVar1[2] >> 3;
        *(uint *)(unaff_EBP + -0x10) = uVar3;
        *(int **)(unaff_EBP + -0x14) = extraout_ECX;
        do {
          puVar7 = *(undefined4 **)(unaff_EBP + -0x14);
          if (puVar7 != (undefined4 *)0x0) {
            do {
              pvVar4 = operator_new(puVar7[5] * puVar7[3] * uVar3 * puVar7[4]);
              *(void **)(unaff_EBP + -0x18) = pvVar4;
              if (pvVar4 == (void *)0x0) {
                *(undefined1 *)(unaff_EBP + -4) = 0;
                FUN_10012856((int *)(unaff_EBP + -0x2c));
                iVar2 = -0x7ff8fff2;
                goto LAB_10012628;
              }
              *(undefined4 *)(unaff_EBP + -0xd4) = puVar7[1];
              *(undefined4 *)(unaff_EBP + -0xd0) = *puVar7;
              *(undefined4 *)(unaff_EBP + -0xcc) = puVar7[0xc];
              *(undefined4 *)(unaff_EBP + -200) = puVar7[0xd];
              puVar8 = puVar7 + 6;
              puVar9 = (undefined4 *)(unaff_EBP + -0xc4);
              for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar9 = *puVar8;
                puVar8 = puVar8 + 1;
                puVar9 = puVar9 + 1;
              }
              puVar8 = puVar7 + 6;
              puVar9 = (undefined4 *)(unaff_EBP + -0xac);
              for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar9 = *puVar8;
                puVar8 = puVar8 + 1;
                puVar9 = puVar9 + 1;
              }
              *(undefined4 *)(unaff_EBP + -0x90) = 0;
              *(undefined4 *)(unaff_EBP + -0x94) = 1;
              *(undefined4 *)(unaff_EBP + -0x8c) = puVar7[2];
              *(undefined4 *)(unaff_EBP + -0x88) = *(undefined4 *)(unaff_EBP + -0x18);
              *(undefined4 *)(unaff_EBP + -0x84) = *(undefined4 *)(unaff_EBP + -0x1c);
              *(int *)(unaff_EBP + -0x80) = puVar7[3] * *(int *)(unaff_EBP + -0x10);
              *(int *)(unaff_EBP + -0x7c) = puVar7[3] * *(int *)(unaff_EBP + -0x10) * puVar7[4];
              *(undefined4 *)(unaff_EBP + -0x78) = 0;
              *(undefined4 *)(unaff_EBP + -0x74) = 0;
              *(undefined4 *)(unaff_EBP + -0x70) = puVar7[3];
              *(undefined4 *)(unaff_EBP + -0x6c) = puVar7[4];
              *(undefined4 *)(unaff_EBP + -0x68) = 0;
              *(undefined4 *)(unaff_EBP + -100) = puVar7[5];
              puVar8 = (undefined4 *)(unaff_EBP + -0x78);
              puVar9 = (undefined4 *)(unaff_EBP + -0x60);
              for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar9 = *puVar8;
                puVar8 = puVar8 + 1;
                puVar9 = puVar9 + 1;
              }
              *(undefined4 *)(unaff_EBP + -0x44) = 0;
              *(undefined4 *)(unaff_EBP + -0x48) = 1;
              *(undefined4 *)(unaff_EBP + -0x40) = puVar7[2];
              iVar2 = FUN_10016007((void *)(unaff_EBP + -0x2c),(int *)(unaff_EBP + -0x88),
                                   (void ***)(unaff_EBP + -0xd4),(void ***)0x80001,(int)unaff_EDI);
              if (iVar2 < 0) {
                operator_delete(*(void **)(unaff_EBP + -0x18));
                *(undefined1 *)(unaff_EBP + -4) = 0;
                FUN_10012856((int *)(unaff_EBP + -0x2c));
                goto LAB_10012628;
              }
              if (((void *)puVar7[1] != (void *)0x0) && (puVar7[0xe] != 0)) {
                operator_delete((void *)puVar7[1]);
                puVar7[1] = 0;
              }
              *puVar7 = *(undefined4 *)(unaff_EBP + -0x1c);
              puVar7[1] = *(undefined4 *)(unaff_EBP + -0x18);
              puVar8 = (undefined4 *)(unaff_EBP + -0x60);
              puVar9 = puVar7 + 6;
              for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar9 = *puVar8;
                puVar8 = puVar8 + 1;
                puVar9 = puVar9 + 1;
              }
              puVar7[0xc] = *(undefined4 *)(unaff_EBP + -0x80);
              puVar7[0xd] = *(undefined4 *)(unaff_EBP + -0x7c);
              uVar3 = *(uint *)(unaff_EBP + -0x10);
              puVar7[0xe] = 1;
              puVar7 = (undefined4 *)puVar7[0x13];
            } while (puVar7 != (undefined4 *)0x0);
            iVar5 = *(int *)(unaff_EBP + 0xc);
            piVar6 = *(int **)(unaff_EBP + -0x20);
          }
          iVar2 = *(int *)(*(int *)(unaff_EBP + -0x14) + 0x50);
          *(int *)(unaff_EBP + -0x14) = iVar2;
        } while (iVar2 != 0);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_10012856((int *)(unaff_EBP + -0x2c));
      }
      iVar2 = FUN_1001bdc7((void *)(unaff_EBP + -0x3c),*(void ***)(unaff_EBP + 8),
                           *(int *)(unaff_EBP + 0x10),unaff_EDI);
      if (iVar2 < 0) goto LAB_10012628;
      if (iVar5 == 0) {
        arg2_00 = (HANDLE)0x1;
LAB_10012618:
        iVar2 = FUN_10010aec(piVar6,*(int **)(unaff_EBP + -0x3c),arg2_00);
      }
      else {
        if (iVar5 != 4) {
          if (iVar5 != 6) {
            iVar2 = -0x7fffbfff;
            goto LAB_10012628;
          }
          arg2_00 = (HANDLE)0x0;
          goto LAB_10012618;
        }
        iVar2 = FUN_100120d6(piVar6,*(int **)(unaff_EBP + -0x3c),unaff_EDI);
      }
      if (-1 < iVar2) {
        iVar2 = 0;
      }
      goto LAB_10012628;
    }
  }
  else {
    if (iVar5 < 1) {
LAB_100125be:
      iVar2 = -0x7789f794;
      goto LAB_10012628;
    }
    if (3 < iVar5) {
      if (iVar5 == 4) {
        piVar6 = (int *)&DAT_10053e40;
        goto LAB_100123d8;
      }
      if (iVar5 != 5) {
        if (iVar5 == 6) goto LAB_100123d3;
        goto LAB_100125be;
      }
    }
  }
  iVar2 = -0x7789f4a7;
LAB_10012628:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1001bed2((int *)(unaff_EBP + -0x3c));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}



