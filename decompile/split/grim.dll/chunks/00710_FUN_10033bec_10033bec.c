/* FUN_10033bec @ 10033bec */

void __cdecl FUN_10033bec(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint size;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  short *psVar11;
  char *pcVar12;
  byte *pbVar13;
  undefined4 *local_28;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_c;
  
  local_28 = param_4;
  iVar3 = *(int *)(param_1 + 100);
  size = *(uint *)(param_1 + 0x5c);
  iVar4 = *(int *)(param_1 + 0x1a4);
  iVar5 = *(int *)(param_1 + 0x11c);
  if (0 < (int)param_4) {
    param_4 = param_3;
    do {
      memzero((void *)*param_4,size);
      param_1 = 0;
      if (0 < iVar3) {
        local_c = (int *)(iVar4 + 0x44);
        do {
          pbVar13 = (byte *)(*(int *)((param_2 - (int)param_3) + (int)param_4) + param_1);
          pcVar12 = (char *)*param_4;
          if (*(char *)(iVar4 + 0x54) == '\0') {
            psVar11 = (short *)*local_c;
            local_14 = 1;
            local_20 = iVar3;
          }
          else {
            local_14 = -1;
            pcVar12 = pcVar12 + (size - 1);
            pbVar13 = pbVar13 + (size - 1) * iVar3;
            psVar11 = (short *)(*local_c + 2 + size * 2);
            local_20 = -iVar3;
          }
          iVar6 = *(int *)(param_1 * 4 + *(int *)(iVar4 + 0x18));
          iVar7 = *(int *)(param_1 * 4 + *(int *)(iVar4 + 0x10));
          iVar8 = 0;
          local_18 = 0;
          local_18._0_2_ = 0;
          local_1c = 0;
          for (uVar1 = size; uVar1 != 0; uVar1 = uVar1 - 1) {
            uVar9 = (uint)*(byte *)((uint)*pbVar13 + iVar5 + (psVar11[local_14] + 8 + iVar8 >> 4));
            bVar2 = *(byte *)(uVar9 + iVar6);
            *pcVar12 = *pcVar12 + bVar2;
            pbVar13 = pbVar13 + local_20;
            pcVar12 = pcVar12 + local_14;
            iVar10 = uVar9 - *(byte *)((uint)bVar2 + iVar7);
            *psVar11 = (short)local_18 + (short)iVar10 * 3;
            local_18 = local_1c + iVar10 * 5;
            iVar8 = iVar10 * 7;
            psVar11 = psVar11 + local_14;
            local_1c = iVar10;
          }
          param_1 = param_1 + 1;
          local_c = local_c + 1;
          *psVar11 = (short)local_18;
        } while (param_1 < iVar3);
      }
      param_4 = param_4 + 1;
      local_28 = (undefined4 *)((int)local_28 + -1);
      *(bool *)(iVar4 + 0x54) = *(char *)(iVar4 + 0x54) == '\0';
    } while (local_28 != (undefined4 *)0x0);
  }
  return;
}



