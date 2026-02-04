/* FUN_100435e0 @ 100435e0 */

void __cdecl
FUN_100435e0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,byte *param_7)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  int *piVar11;
  int local_220;
  int local_218;
  int local_214;
  int local_210;
  int local_20c;
  int local_200 [128];
  
  piVar11 = local_200;
  for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar11 = 0x7fffffff;
    piVar11 = piVar11 + 1;
  }
  local_218 = 0;
  if (0 < param_5) {
    do {
      bVar1 = *(byte *)(local_218 + param_6);
      uVar8 = (uint)bVar1;
      piVar11 = *(int **)(param_1 + 0x74);
      local_220 = 4;
      iVar2 = (param_2 - (uint)*(byte *)(uVar8 + *piVar11)) * 2;
      iVar5 = param_3 - (uint)*(byte *)(piVar11[1] + uVar8);
      iVar4 = iVar5 * 3;
      iVar6 = param_4 - (uint)*(byte *)(piVar11[2] + uVar8);
      iVar4 = iVar6 * iVar6 + iVar4 * iVar4 + iVar2 * iVar2;
      local_20c = (iVar2 + 8) * 0x20;
      piVar11 = local_200;
      pbVar9 = param_7;
      do {
        local_214 = 8;
        iVar2 = iVar4;
        local_210 = (iVar5 * 9 + 0x12) * 8;
        do {
          iVar10 = 4;
          iVar3 = iVar2;
          iVar7 = (iVar6 + 4) * 0x10;
          do {
            if (iVar3 < *piVar11) {
              *piVar11 = iVar3;
              *pbVar9 = bVar1;
            }
            iVar3 = iVar3 + iVar7;
            iVar7 = iVar7 + 0x80;
            piVar11 = piVar11 + 1;
            pbVar9 = pbVar9 + 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          iVar2 = iVar2 + local_210;
          local_210 = local_210 + 0x120;
          local_214 = local_214 + -1;
        } while (local_214 != 0);
        iVar4 = iVar4 + local_20c;
        local_20c = local_20c + 0x200;
        local_220 = local_220 + -1;
      } while (local_220 != 0);
      local_218 = local_218 + 1;
    } while (local_218 < param_5);
  }
  return;
}



