/* FUN_1003c640 @ 1003c640 */

uint __cdecl FUN_1003c640(int *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  uint *puVar12;
  int *piStack_10;
  int iStack_8;
  
  puVar4 = (undefined4 *)param_1[5];
  pbVar10 = (byte *)*puVar4;
  iVar9 = puVar4[1];
  if (*(char *)(param_1[100] + 0x51) == '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 0x3d;
    (**(code **)*param_1)(param_1);
  }
  if (iVar9 == 0) {
    uVar5 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar5 == '\0') goto LAB_1003c944;
    iVar9 = puVar4[1];
    pbVar10 = (byte *)*puVar4;
  }
  bVar1 = *pbVar10;
  iVar9 = iVar9 + -1;
  pbVar10 = pbVar10 + 1;
  if (iVar9 == 0) {
    uVar5 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar5 == '\0') goto LAB_1003c944;
    iVar9 = puVar4[1];
    pbVar10 = (byte *)*puVar4;
  }
  bVar2 = *pbVar10;
  iVar9 = iVar9 + -1;
  pbVar10 = pbVar10 + 1;
  if (iVar9 == 0) {
    uVar5 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar5 == '\0') goto LAB_1003c944;
    iVar9 = puVar4[1];
    pbVar10 = (byte *)*puVar4;
  }
  bVar3 = *pbVar10;
  uVar6 = (uint)bVar3;
  iVar9 = iVar9 + -1;
  pbVar10 = pbVar10 + 1;
  if ((((uint)bVar1 * 0x100 + (uint)bVar2 != uVar6 * 2 + 6) || (bVar3 == 0)) || (4 < bVar3)) {
    *(undefined4 *)(*param_1 + 0x14) = 9;
    (**(code **)*param_1)(param_1);
  }
  *(undefined4 *)(*param_1 + 0x14) = 0x66;
  *(uint *)(*param_1 + 0x18) = uVar6;
  (**(code **)(*param_1 + 4))(param_1,1);
  param_1[0x48] = uVar6;
  iStack_8 = 0;
  if (uVar6 != 0) {
    piStack_10 = param_1 + 0x49;
    do {
      if (iVar9 == 0) {
        uVar5 = (*(code *)puVar4[3])(param_1);
        if ((char)uVar5 == '\0') goto LAB_1003c944;
        iVar9 = puVar4[1];
        pbVar10 = (byte *)*puVar4;
      }
      uVar8 = (uint)*pbVar10;
      iVar9 = iVar9 + -1;
      pbVar10 = pbVar10 + 1;
      if (iVar9 == 0) {
        uVar5 = (*(code *)puVar4[3])(param_1);
        if ((char)uVar5 == '\0') goto LAB_1003c944;
        iVar9 = puVar4[1];
        pbVar10 = (byte *)*puVar4;
      }
      puVar12 = (uint *)param_1[0x31];
      iVar9 = iVar9 + -1;
      bVar1 = *pbVar10;
      pbVar10 = pbVar10 + 1;
      iVar7 = 0;
      if (0 < param_1[8]) {
        do {
          if (uVar8 == *puVar12) goto LAB_1003c7e9;
          iVar7 = iVar7 + 1;
          puVar12 = puVar12 + 0x15;
        } while (iVar7 < param_1[8]);
      }
      *(undefined4 *)(*param_1 + 0x14) = 5;
      *(uint *)(*param_1 + 0x18) = uVar8;
      (**(code **)*param_1)(param_1);
LAB_1003c7e9:
      *piStack_10 = (int)puVar12;
      puVar12[5] = (int)(uint)bVar1 >> 4;
      puVar12[6] = bVar1 & 0xf;
      iVar7 = *param_1;
      *(uint *)(iVar7 + 0x18) = uVar8;
      *(uint *)(iVar7 + 0x1c) = puVar12[5];
      *(uint *)(iVar7 + 0x20) = puVar12[6];
      *(undefined4 *)(*param_1 + 0x14) = 0x67;
      (**(code **)(*param_1 + 4))(param_1,1);
      iStack_8 = iStack_8 + 1;
      piStack_10 = piStack_10 + 1;
    } while (iStack_8 < (int)uVar6);
  }
  if (iVar9 == 0) {
    uVar5 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar5 == '\0') goto LAB_1003c944;
    iVar9 = puVar4[1];
    pbVar10 = (byte *)*puVar4;
  }
  iVar9 = iVar9 + -1;
  pbVar11 = pbVar10 + 1;
  param_1[0x5a] = (uint)*pbVar10;
  if (iVar9 == 0) {
    uVar5 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar5 == '\0') goto LAB_1003c944;
    iVar9 = puVar4[1];
    pbVar11 = (byte *)*puVar4;
  }
  iVar9 = iVar9 + -1;
  pbVar10 = pbVar11 + 1;
  param_1[0x5b] = (uint)*pbVar11;
  if (iVar9 == 0) {
    uVar5 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar5 == '\0') {
LAB_1003c944:
      return uVar5 & 0xffffff00;
    }
    iVar9 = puVar4[1];
    pbVar10 = (byte *)*puVar4;
  }
  bVar1 = *pbVar10;
  param_1[0x5d] = bVar1 & 0xf;
  iVar7 = *param_1;
  param_1[0x5c] = (int)(uint)bVar1 >> 4;
  *(int *)(iVar7 + 0x18) = param_1[0x5a];
  *(int *)(iVar7 + 0x1c) = param_1[0x5b];
  *(int *)(iVar7 + 0x20) = param_1[0x5c];
  *(int *)(iVar7 + 0x24) = param_1[0x5d];
  *(undefined4 *)(*param_1 + 0x14) = 0x68;
  (**(code **)(*param_1 + 4))(param_1,1);
  *(undefined4 *)(param_1[100] + 0x54) = 0;
  iVar7 = param_1[0x1f];
  param_1[0x1f] = iVar7 + 1;
  *puVar4 = pbVar10 + 1;
  puVar4[1] = iVar9 + -1;
  return CONCAT31((int3)((uint)(iVar7 + 1) >> 8),1);
}



