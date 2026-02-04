/* FUN_1003cf10 @ 1003cf10 */

undefined4 __cdecl FUN_1003cf10(int *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  int iVar9;
  
  puVar3 = (undefined4 *)param_1[5];
  puVar7 = (undefined1 *)*puVar3;
  iVar9 = puVar3[1];
  if (iVar9 == 0) {
    uVar4 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar4 == '\0') goto LAB_1003cff6;
    puVar7 = (undefined1 *)*puVar3;
    iVar9 = puVar3[1];
  }
  uVar1 = *puVar7;
  iVar9 = iVar9 + -1;
  puVar7 = puVar7 + 1;
  if (iVar9 == 0) {
    uVar4 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar4 == '\0') goto LAB_1003cff6;
    puVar7 = (undefined1 *)*puVar3;
    iVar9 = puVar3[1];
  }
  iVar9 = iVar9 + -1;
  pbVar8 = puVar7 + 1;
  if (CONCAT11(uVar1,*puVar7) != 4) {
    *(undefined4 *)(*param_1 + 0x14) = 9;
    (**(code **)*param_1)(param_1);
  }
  if (iVar9 == 0) {
    uVar4 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar4 == '\0') goto LAB_1003cff6;
    pbVar8 = (byte *)*puVar3;
    iVar9 = puVar3[1];
  }
  bVar2 = *pbVar8;
  iVar9 = iVar9 + -1;
  pbVar8 = pbVar8 + 1;
  if (iVar9 == 0) {
    uVar4 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar4 == '\0') {
LAB_1003cff6:
      return uVar4 & 0xffffff00;
    }
    pbVar8 = (byte *)*puVar3;
    iVar9 = puVar3[1];
  }
  iVar5 = (uint)bVar2 * 0x100 + (uint)*pbVar8;
  *(undefined4 *)(*param_1 + 0x14) = 0x51;
  *(int *)(*param_1 + 0x18) = iVar5;
  uVar6 = (**(code **)(*param_1 + 4))(param_1,1);
  param_1[0x3f] = iVar5;
  puVar3[1] = iVar9 + -1;
  *puVar3 = pbVar8 + 1;
  return CONCAT31((int3)((uint)uVar6 >> 8),1);
}



