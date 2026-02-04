/* FUN_1003cca0 @ 1003cca0 */

uint __cdecl FUN_1003cca0(int *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  byte *pbVar11;
  int iVar12;
  ushort *puVar13;
  int *piStack_c;
  
  puVar3 = (undefined4 *)param_1[5];
  iVar12 = puVar3[1];
  puVar10 = (undefined1 *)*puVar3;
  if (iVar12 == 0) {
    uVar7 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar7 == '\0') goto LAB_1003cf06;
    puVar10 = (undefined1 *)*puVar3;
    iVar12 = puVar3[1];
  }
  uVar1 = *puVar10;
  iVar12 = iVar12 + -1;
  puVar10 = puVar10 + 1;
  if (iVar12 == 0) {
    uVar7 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar7 == '\0') {
LAB_1003cf06:
      return uVar7 & 0xffffff00;
    }
    puVar10 = (undefined1 *)*puVar3;
    iVar12 = puVar3[1];
  }
  iVar12 = iVar12 + -1;
  pbVar11 = puVar10 + 1;
  iVar9 = CONCAT11(uVar1,*puVar10) - 2;
  do {
    iVar5 = iVar9;
    if (iVar5 < 1) {
      *puVar3 = pbVar11;
      puVar3[1] = iVar12;
      return CONCAT31((int3)((uint)iVar5 >> 8),1);
    }
    if (iVar12 == 0) {
      uVar7 = (*(code *)puVar3[3])(param_1);
      if ((char)uVar7 == '\0') goto LAB_1003cf06;
      pbVar11 = (byte *)*puVar3;
      iVar12 = puVar3[1];
    }
    bVar2 = *pbVar11;
    *(undefined4 *)(*param_1 + 0x14) = 0x50;
    iVar12 = iVar12 + -1;
    pbVar11 = pbVar11 + 1;
    uVar7 = bVar2 & 0xf;
    *(uint *)(*param_1 + 0x18) = uVar7;
    iVar8 = (int)(uint)bVar2 >> 4;
    *(int *)(*param_1 + 0x1c) = iVar8;
    (**(code **)(*param_1 + 4))(param_1,1);
    if (3 < uVar7) {
      *(undefined4 *)(*param_1 + 0x14) = 0x1e;
      *(uint *)(*param_1 + 0x18) = uVar7;
      (**(code **)*param_1)(param_1);
    }
    if (param_1[uVar7 + 0x24] == 0) {
      iVar9 = FUN_1003dd50((int)param_1);
      param_1[uVar7 + 0x24] = iVar9;
    }
    iVar9 = param_1[uVar7 + 0x24];
    piStack_c = (int *)&DAT_10050550;
    do {
      if (iVar8 == 0) {
        if (iVar12 == 0) {
          uVar7 = (*(code *)puVar3[3])(param_1);
          if ((char)uVar7 == '\0') goto LAB_1003cf06;
          pbVar11 = (byte *)*puVar3;
          iVar12 = puVar3[1];
        }
        uVar6 = (ushort)*pbVar11;
      }
      else {
        if (iVar12 == 0) {
          uVar7 = (*(code *)puVar3[3])(param_1);
          if ((char)uVar7 == '\0') goto LAB_1003cf06;
          pbVar11 = (byte *)*puVar3;
          iVar12 = puVar3[1];
        }
        bVar2 = *pbVar11;
        iVar12 = iVar12 + -1;
        pbVar11 = pbVar11 + 1;
        if (iVar12 == 0) {
          uVar7 = (*(code *)puVar3[3])(param_1);
          if ((char)uVar7 == '\0') goto LAB_1003cf06;
          pbVar11 = (byte *)*puVar3;
          iVar12 = puVar3[1];
        }
        uVar6 = (ushort)bVar2 * 0x100 + (ushort)*pbVar11;
      }
      iVar12 = iVar12 + -1;
      pbVar11 = pbVar11 + 1;
      iVar4 = *piStack_c;
      piStack_c = piStack_c + 1;
      *(ushort *)(iVar9 + iVar4 * 2) = uVar6;
    } while ((int)piStack_c < 0x10050650);
    if (1 < *(int *)(*param_1 + 0x68)) {
      puVar13 = (ushort *)(iVar9 + 4);
      piStack_c = (int *)0x8;
      do {
        iVar9 = *param_1;
        *(uint *)(iVar9 + 0x18) = (uint)puVar13[-2];
        *(uint *)(iVar9 + 0x1c) = (uint)puVar13[-1];
        *(uint *)(iVar9 + 0x20) = (uint)*puVar13;
        *(uint *)(iVar9 + 0x24) = (uint)puVar13[1];
        *(uint *)(iVar9 + 0x28) = (uint)puVar13[2];
        *(uint *)(iVar9 + 0x2c) = (uint)puVar13[3];
        *(uint *)(iVar9 + 0x30) = (uint)puVar13[4];
        *(uint *)(iVar9 + 0x34) = (uint)puVar13[5];
        *(undefined4 *)(*param_1 + 0x14) = 0x5c;
        (**(code **)(*param_1 + 4))(param_1,2);
        puVar13 = puVar13 + 8;
        piStack_c = (int *)((int)piStack_c + -1);
      } while (piStack_c != (int *)0x0);
    }
    iVar9 = iVar5 + -0x41;
    if (iVar8 != 0) {
      iVar9 = iVar5 + -0x81;
    }
  } while( true );
}



