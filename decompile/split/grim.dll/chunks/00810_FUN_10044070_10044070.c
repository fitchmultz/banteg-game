/* FUN_10044070 @ 10044070 */

void __cdecl FUN_10044070(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ushort *puVar10;
  ushort *puVar11;
  int iVar12;
  int iVar13;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_14;
  
  piVar1 = param_2 + 3;
  iVar8 = param_2[4];
  iVar4 = param_2[2];
  piVar2 = param_2 + 1;
  piVar3 = param_2 + 5;
  iVar9 = *param_2;
  iVar13 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  if (iVar9 <= *piVar2) {
    local_30 = iVar9 * 8 + 4;
    param_2 = (int *)(*(int *)(*(int *)(param_1 + 0x1a4) + 0x18) + iVar9 * 4);
    local_14 = (*piVar2 - iVar9) + 1;
    do {
      if (iVar4 <= *piVar1) {
        puVar10 = (ushort *)(*param_2 + (iVar4 * 0x20 + iVar8) * 2);
        iVar5 = (*piVar1 - iVar4) + 1;
        iVar9 = iVar4 * 4 + 2;
        do {
          if (iVar8 <= *piVar3) {
            iVar7 = iVar8 * 8 + 4;
            iVar12 = (*piVar3 - iVar8) + 1;
            puVar11 = puVar10;
            do {
              uVar6 = (uint)*puVar11;
              puVar11 = puVar11 + 1;
              if (uVar6 != 0) {
                local_2c = local_2c + local_30 * uVar6;
                local_28 = local_28 + iVar9 * uVar6;
                iVar13 = iVar13 + uVar6;
                local_24 = local_24 + iVar7 * uVar6;
              }
              iVar7 = iVar7 + 8;
              iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
          }
          puVar10 = puVar10 + 0x20;
          iVar9 = iVar9 + 4;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      param_2 = param_2 + 1;
      local_30 = local_30 + 8;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
  }
  iVar8 = iVar13 >> 1;
  *(char *)(**(int **)(param_1 + 0x74) + param_3) = (char)((iVar8 + local_2c) / iVar13);
  *(char *)(*(int *)(*(int *)(param_1 + 0x74) + 4) + param_3) = (char)((local_28 + iVar8) / iVar13);
  *(char *)(*(int *)(*(int *)(param_1 + 0x74) + 8) + param_3) = (char)((local_24 + iVar8) / iVar13);
  return;
}



