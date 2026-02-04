/* FUN_1003c950 @ 1003c950 */

uint __cdecl FUN_1003c950(int *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  int *piVar11;
  undefined4 *puVar12;
  int iStack_128;
  int iStack_120;
  byte abStack_118 [20];
  uint uStack_104;
  byte abStack_100 [256];
  
  puVar3 = (undefined4 *)param_1[5];
  puVar7 = (undefined1 *)*puVar3;
  iStack_128 = puVar3[1];
  if (iStack_128 == 0) {
    uVar4 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar4 == '\0') goto LAB_1003cc8c;
    iStack_128 = puVar3[1];
    puVar7 = (undefined1 *)*puVar3;
  }
  uVar1 = *puVar7;
  iStack_128 = iStack_128 + -1;
  puVar7 = puVar7 + 1;
  if (iStack_128 == 0) {
    uVar4 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar4 == '\0') {
LAB_1003cc8c:
      return uVar4 & 0xffffff00;
    }
    iStack_128 = puVar3[1];
    puVar7 = (undefined1 *)*puVar3;
  }
  iStack_128 = iStack_128 + -1;
  iVar5 = CONCAT11(uVar1,*puVar7) - 2;
  pbVar8 = puVar7 + 1;
  do {
    if (iVar5 < 1) {
      puVar3[1] = iStack_128;
      *puVar3 = pbVar8;
      return CONCAT31((int3)((uint)iVar5 >> 8),1);
    }
    if (iStack_128 == 0) {
      uVar4 = (*(code *)puVar3[3])(param_1);
      if ((char)uVar4 == '\0') goto LAB_1003cc8c;
      iStack_128 = puVar3[1];
      pbVar8 = (byte *)*puVar3;
    }
    uStack_104 = (uint)*pbVar8;
    *(undefined4 *)(*param_1 + 0x14) = 0x4f;
    iStack_128 = iStack_128 + -1;
    pbVar8 = pbVar8 + 1;
    *(uint *)(*param_1 + 0x18) = uStack_104;
    (**(code **)(*param_1 + 4))(param_1,1);
    abStack_118[0] = 0;
    iStack_120 = 0;
    iVar9 = 1;
    do {
      if (iStack_128 == 0) {
        uVar4 = (*(code *)puVar3[3])(param_1);
        if ((char)uVar4 == '\0') goto LAB_1003cc8c;
        iStack_128 = puVar3[1];
        pbVar8 = (byte *)*puVar3;
      }
      bVar2 = *pbVar8;
      abStack_118[iVar9] = bVar2;
      iStack_128 = iStack_128 + -1;
      pbVar8 = pbVar8 + 1;
      iVar6 = iStack_120 + (uint)bVar2;
      iVar9 = iVar9 + 1;
      iStack_120 = iVar6;
    } while (iVar9 < 0x11);
    iVar9 = *param_1;
    *(uint *)(iVar9 + 0x18) =
         CONCAT12(abStack_118[3],CONCAT11(abStack_118[2],abStack_118[1])) & 0xff;
    *(uint *)(iVar9 + 0x1c) =
         CONCAT12(abStack_118[4],CONCAT11(abStack_118[3],abStack_118[2])) & 0xff;
    *(uint *)(iVar9 + 0x20) =
         CONCAT12(abStack_118[5],CONCAT11(abStack_118[4],abStack_118[3])) & 0xff;
    *(uint *)(iVar9 + 0x24) =
         CONCAT12(abStack_118[6],CONCAT11(abStack_118[5],abStack_118[4])) & 0xff;
    *(uint *)(iVar9 + 0x28) =
         CONCAT12(abStack_118[7],CONCAT11(abStack_118[6],abStack_118[5])) & 0xff;
    *(uint *)(iVar9 + 0x2c) =
         CONCAT12(abStack_118[8],CONCAT11(abStack_118[7],abStack_118[6])) & 0xff;
    *(uint *)(iVar9 + 0x30) =
         CONCAT12(abStack_118[9],CONCAT11(abStack_118[8],abStack_118[7])) & 0xff;
    *(uint *)(iVar9 + 0x34) =
         CONCAT12(abStack_118[10],CONCAT11(abStack_118[9],abStack_118[8])) & 0xff;
    *(undefined4 *)(*param_1 + 0x14) = 0x55;
    (**(code **)(*param_1 + 4))(param_1,2);
    iVar9 = *param_1;
    *(uint *)(iVar9 + 0x18) =
         CONCAT12(abStack_118[0xb],CONCAT11(abStack_118[10],abStack_118[9])) & 0xff;
    *(uint *)(iVar9 + 0x1c) =
         CONCAT12(abStack_118[0xc],CONCAT11(abStack_118[0xb],abStack_118[10])) & 0xff;
    *(uint *)(iVar9 + 0x20) =
         CONCAT12(abStack_118[0xd],CONCAT11(abStack_118[0xc],abStack_118[0xb])) & 0xff;
    *(uint *)(iVar9 + 0x24) =
         CONCAT12(abStack_118[0xe],CONCAT11(abStack_118[0xd],abStack_118[0xc])) & 0xff;
    *(uint *)(iVar9 + 0x28) =
         CONCAT12(abStack_118[0xf],CONCAT11(abStack_118[0xe],abStack_118[0xd])) & 0xff;
    *(uint *)(iVar9 + 0x2c) =
         CONCAT12(abStack_118[0x10],CONCAT11(abStack_118[0xf],abStack_118[0xe])) & 0xff;
    *(uint *)(iVar9 + 0x30) = CONCAT11(abStack_118[0x10],abStack_118[0xf]) & 0xff;
    *(uint *)(iVar9 + 0x34) = (uint)abStack_118[0x10];
    *(undefined4 *)(*param_1 + 0x14) = 0x55;
    (**(code **)(*param_1 + 4))(param_1,2);
    if ((0x100 < iVar6) || (iVar5 + -0x11 < iVar6)) {
      *(undefined4 *)(*param_1 + 0x14) = 0x1c;
      (**(code **)*param_1)(param_1);
    }
    iStack_120 = 0;
    if (0 < iVar6) {
      do {
        if (iStack_128 == 0) {
          uVar4 = (*(code *)puVar3[3])(param_1);
          if ((char)uVar4 == '\0') goto LAB_1003cc8c;
          iStack_128 = puVar3[1];
          pbVar8 = (byte *)*puVar3;
        }
        bVar2 = *pbVar8;
        iStack_128 = iStack_128 + -1;
        pbVar8 = pbVar8 + 1;
        abStack_100[iStack_120] = bVar2;
        iStack_120 = iStack_120 + 1;
      } while (iStack_120 < iVar6);
    }
    iVar5 = (iVar5 + -0x11) - iVar6;
    if ((uStack_104 & 0x10) == 0) {
      iVar9 = uStack_104 + 0x28;
      uVar4 = uStack_104;
    }
    else {
      iVar9 = uStack_104 + 0x1c;
      uVar4 = uStack_104 - 0x10;
    }
    piVar11 = param_1 + iVar9;
    if (((int)uVar4 < 0) || (3 < (int)uVar4)) {
      *(undefined4 *)(*param_1 + 0x14) = 0x1d;
      *(uint *)(*param_1 + 0x18) = uVar4;
      (**(code **)*param_1)(param_1);
    }
    if (*piVar11 == 0) {
      iVar9 = FUN_1003dd70((int)param_1);
      *piVar11 = iVar9;
    }
    puVar12 = (undefined4 *)*piVar11;
    *puVar12 = CONCAT13(abStack_118[3],
                        CONCAT12(abStack_118[2],CONCAT11(abStack_118[1],abStack_118[0])));
    puVar12[1] = CONCAT13(abStack_118[7],
                          CONCAT12(abStack_118[6],CONCAT11(abStack_118[5],abStack_118[4])));
    puVar12[2] = CONCAT13(abStack_118[0xb],
                          CONCAT12(abStack_118[10],CONCAT11(abStack_118[9],abStack_118[8])));
    puVar12[3] = CONCAT13(abStack_118[0xf],
                          CONCAT12(abStack_118[0xe],CONCAT11(abStack_118[0xd],abStack_118[0xc])));
    *(byte *)(puVar12 + 4) = abStack_118[0x10];
    pbVar10 = abStack_100;
    puVar12 = (undefined4 *)(*piVar11 + 0x11);
    for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar12 = *(undefined4 *)pbVar10;
      pbVar10 = pbVar10 + 4;
      puVar12 = puVar12 + 1;
    }
  } while( true );
}



