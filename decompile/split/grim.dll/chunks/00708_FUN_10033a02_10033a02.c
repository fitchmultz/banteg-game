/* FUN_10033a02 @ 10033a02 */

void __cdecl FUN_10033a02(int param_1,int param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint size;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  char *pcVar10;
  uint local_1c;
  int *local_8;
  
  iVar3 = *(int *)(param_1 + 100);
  iVar4 = *(int *)(param_1 + 0x1a4);
  size = *(uint *)(param_1 + 0x5c);
  if (0 < (int)param_4) {
    iVar9 = param_2 - (int)param_3;
    local_1c = param_4;
    do {
      memzero((void *)*param_3,size);
      iVar5 = *(int *)(iVar4 + 0x30);
      param_1 = 0;
      if (0 < iVar3) {
        local_8 = (int *)(iVar4 + 0x34);
        do {
          param_4 = 0;
          pcVar10 = (char *)*param_3;
          pbVar8 = (byte *)(*(int *)(iVar9 + (int)param_3) + param_1);
          iVar6 = *(int *)(*(int *)(iVar4 + 0x18) + param_1 * 4);
          iVar7 = *local_8;
          for (uVar1 = size; uVar1 != 0; uVar1 = uVar1 - 1) {
            bVar2 = *pbVar8;
            pbVar8 = pbVar8 + iVar3;
            *pcVar10 = *pcVar10 +
                       *(char *)(*(int *)(iVar7 + iVar5 * 0x40 + param_4 * 4) + (uint)bVar2 + iVar6)
            ;
            pcVar10 = pcVar10 + 1;
            param_4 = param_4 + 1 & 0xf;
          }
          param_1 = param_1 + 1;
          local_8 = local_8 + 1;
        } while (param_1 < iVar3);
      }
      param_3 = param_3 + 1;
      local_1c = local_1c - 1;
      *(uint *)(iVar4 + 0x30) = iVar5 + 1U & 0xf;
    } while (local_1c != 0);
  }
  return;
}



