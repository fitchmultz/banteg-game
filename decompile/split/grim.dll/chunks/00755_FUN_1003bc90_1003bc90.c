/* FUN_1003bc90 @ 1003bc90 */

undefined4 __cdecl FUN_1003bc90(int *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  byte *pbVar8;
  
  puVar3 = (undefined4 *)param_1[5];
  iVar7 = puVar3[1];
  pbVar8 = (byte *)*puVar3;
  if (iVar7 == 0) {
    uVar4 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar4 == '\0') goto LAB_1003bd27;
    pbVar8 = (byte *)*puVar3;
    iVar7 = puVar3[1];
  }
  bVar1 = *pbVar8;
  iVar7 = iVar7 + -1;
  pbVar8 = pbVar8 + 1;
  if (iVar7 == 0) {
    uVar4 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar4 == '\0') {
LAB_1003bd27:
      return uVar4 & 0xffffff00;
    }
    pbVar8 = (byte *)*puVar3;
    iVar7 = puVar3[1];
  }
  bVar2 = *pbVar8;
  *(undefined4 *)(*param_1 + 0x14) = 0x5a;
  iVar5 = (uint)bVar1 * 0x100 + (uint)bVar2;
  *(int *)(*param_1 + 0x18) = param_1[0x5e];
  *(int *)(*param_1 + 0x1c) = iVar5;
  (**(code **)(*param_1 + 4))(param_1,1);
  *puVar3 = pbVar8 + 1;
  puVar3[1] = iVar7 + -1;
  uVar6 = (**(code **)(param_1[5] + 0x10))(param_1,iVar5 + -2);
  return CONCAT31((int3)((uint)uVar6 >> 8),1);
}



