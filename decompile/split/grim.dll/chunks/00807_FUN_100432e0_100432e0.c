/* FUN_100432e0 @ 100432e0 */

void __cdecl FUN_100432e0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int local_5b0;
  int local_5ac;
  int *local_5a8;
  int local_5a4;
  byte local_580 [128];
  undefined1 local_500 [256];
  int local_400 [256];
  
  iVar9 = *(int *)(*(int *)(param_1 + 0x1a4) + 0x18);
  iVar15 = (param_3 >> 3) * 0x20;
  iVar16 = iVar15 + 2;
  iVar19 = *(int *)(param_1 + 0x70);
  iVar13 = (param_2 >> 2) * 0x20;
  iVar17 = (param_4 >> 2) * 0x20;
  iVar18 = iVar17 + 4;
  iVar14 = iVar13 + 4;
  local_5a4 = 0x7fffffff;
  local_5b0 = 0;
  if (0 < iVar19) {
    local_5a8 = local_400;
    piVar12 = *(int **)(param_1 + 0x74);
    iVar1 = *piVar12;
    iVar2 = piVar12[1];
    iVar3 = piVar12[2];
    do {
      uVar4 = (uint)*(byte *)(iVar1 + local_5b0);
      if ((int)uVar4 < iVar14) {
        iVar10 = (uVar4 - iVar14) * 2;
        iVar10 = iVar10 * iVar10;
        iVar5 = uVar4 - (iVar13 + 0x1c);
      }
      else {
        iVar5 = iVar13 + 0x1c;
        if (iVar5 < (int)uVar4) {
          iVar10 = (uVar4 - iVar5) * 2;
          iVar10 = iVar10 * iVar10;
        }
        else {
          iVar10 = 0;
          if ((int)uVar4 <= iVar13 + 0x1c + iVar14 >> 1) {
            iVar5 = uVar4 - iVar5;
            goto LAB_100433e8;
          }
        }
        iVar5 = uVar4 - iVar14;
      }
LAB_100433e8:
      uVar4 = (uint)*(byte *)(iVar2 + local_5b0);
      if ((int)uVar4 < iVar16) {
        iVar7 = (uVar4 - iVar16) * 3;
        iVar10 = iVar10 + iVar7 * iVar7;
        iVar7 = uVar4 - (iVar15 + 0x1e);
      }
      else {
        iVar7 = iVar15 + 0x1e;
        if (iVar7 < (int)uVar4) {
          iVar7 = (uVar4 - iVar7) * 3;
          iVar10 = iVar10 + iVar7 * iVar7;
        }
        else if ((int)uVar4 <= iVar15 + 0x1e + iVar16 >> 1) {
          iVar7 = uVar4 - iVar7;
          goto LAB_10043434;
        }
        iVar7 = uVar4 - iVar16;
      }
LAB_10043434:
      uVar4 = (uint)*(byte *)(iVar3 + local_5b0);
      if ((int)uVar4 < iVar18) {
        iVar10 = iVar10 + (uVar4 - iVar18) * (uVar4 - iVar18);
        iVar8 = uVar4 - (iVar17 + 0x1c);
      }
      else {
        iVar8 = iVar17 + 0x1c;
        if (iVar8 < (int)uVar4) {
          iVar10 = iVar10 + (uVar4 - iVar8) * (uVar4 - iVar8);
        }
        else if ((int)uVar4 <= iVar17 + 0x1c + iVar18 >> 1) {
          iVar8 = uVar4 - iVar8;
          goto LAB_1004348f;
        }
        iVar8 = uVar4 - iVar18;
      }
LAB_1004348f:
      *local_5a8 = iVar10;
      iVar5 = iVar5 * 2 * iVar5 * 2 + iVar7 * 3 * iVar7 * 3 + iVar8 * iVar8;
      if (iVar5 < local_5a4) {
        local_5a4 = iVar5;
      }
      local_5a8 = local_5a8 + 1;
      local_5b0 = local_5b0 + 1;
    } while (local_5b0 < iVar19);
  }
  local_5ac = 0;
  local_5b0 = 0;
  if (0 < iVar19) {
    local_5a8 = local_400;
    do {
      if (*local_5a8 <= local_5a4) {
        local_500[local_5ac] = (undefined1)local_5b0;
        local_5ac = local_5ac + 1;
      }
      local_5b0 = local_5b0 + 1;
      local_5a8 = local_5a8 + 1;
    } while (local_5b0 < iVar19);
  }
  FUN_100435e0(param_1,iVar14,iVar16,iVar18,local_5ac,(int)local_500,local_580);
  pbVar11 = local_580;
  piVar12 = (int *)(iVar9 + (param_2 >> 2) * 0x10);
  local_5a4 = 4;
  do {
    iVar9 = ((param_3 >> 3) * 0x100 + (param_4 >> 2) * 4) * 2;
    iVar19 = 8;
    do {
      iVar13 = 4;
      psVar6 = (short *)(*piVar12 + iVar9);
      do {
        *psVar6 = *pbVar11 + 1;
        pbVar11 = pbVar11 + 1;
        iVar13 = iVar13 + -1;
        psVar6 = psVar6 + 1;
      } while (iVar13 != 0);
      iVar9 = iVar9 + 0x40;
      iVar19 = iVar19 + -1;
    } while (iVar19 != 0);
    piVar12 = piVar12 + 1;
    local_5a4 = local_5a4 + -1;
  } while (local_5a4 != 0);
  return;
}



