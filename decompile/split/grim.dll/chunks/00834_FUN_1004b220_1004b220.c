/* FUN_1004b220 @ 1004b220 */

undefined4 __cdecl
FUN_1004b220(uint param_1,int param_2,int param_3,int param_4,int param_5,int *param_6)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  int iVar13;
  uint local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  
  local_10 = *(undefined1 **)(param_5 + 0x34);
  uVar7 = *(uint *)(param_5 + 0x20);
  local_14 = param_6[1];
  pbVar10 = (byte *)*param_6;
  uVar3 = *(uint *)(param_5 + 0x1c);
  if (local_10 < *(undefined1 **)(param_5 + 0x30)) {
    local_c = *(undefined1 **)(param_5 + 0x30) + (-1 - (int)local_10);
  }
  else {
    local_c = (undefined1 *)(*(int *)(param_5 + 0x2c) - (int)local_10);
  }
  uVar6 = *(uint *)(&DAT_10059608 + param_1 * 4);
  uVar5 = *(uint *)(&DAT_10059608 + param_2 * 4);
  do {
    for (; uVar3 < 0x14; uVar3 = uVar3 + 8) {
      local_14 = local_14 - 1;
      uVar7 = uVar7 | (uint)*pbVar10 << ((byte)uVar3 & 0x1f);
      pbVar10 = pbVar10 + 1;
    }
    bVar2 = *(byte *)(param_3 + (uVar6 & uVar7) * 8);
    uVar9 = (uint)bVar2;
    iVar13 = param_3 + (uVar6 & uVar7) * 8;
    if (uVar9 == 0) {
LAB_1004b458:
      uVar7 = uVar7 >> (*(byte *)(iVar13 + 1) & 0x1f);
      uVar3 = uVar3 - *(byte *)(iVar13 + 1);
      *local_10 = *(undefined1 *)(iVar13 + 4);
      local_10 = local_10 + 1;
      local_c = local_c + -1;
    }
    else {
      uVar7 = uVar7 >> (*(byte *)(iVar13 + 1) & 0x1f);
      uVar3 = uVar3 - *(byte *)(iVar13 + 1);
      while ((bVar2 & 0x10) == 0) {
        if ((uVar9 & 0x40) != 0) {
          if ((uVar9 & 0x20) != 0) {
            uVar6 = param_6[1] - local_14;
            if (uVar3 >> 3 < param_6[1] - local_14) {
              uVar6 = uVar3 >> 3;
            }
            *(uint *)(param_5 + 0x20) = uVar7;
            *(uint *)(param_5 + 0x1c) = uVar3 + uVar6 * -8;
            iVar13 = *param_6;
            param_6[1] = uVar6 + local_14;
            *param_6 = (int)pbVar10 - uVar6;
            param_6[2] = param_6[2] + (((int)pbVar10 - uVar6) - iVar13);
            *(undefined1 **)(param_5 + 0x34) = local_10;
            return 1;
          }
          uVar5 = param_6[1] - local_14;
          param_6[6] = (int)s_invalid_literal_length_code_100583f0;
          uVar6 = uVar3 >> 3;
          if (uVar3 >> 3 < uVar5) goto LAB_1004b56f;
          goto LAB_1004b571;
        }
        iVar4 = (*(uint *)(&DAT_10059608 + uVar9 * 4) & uVar7) + *(int *)(iVar13 + 4);
        bVar2 = *(byte *)(iVar13 + iVar4 * 8);
        uVar9 = (uint)bVar2;
        iVar13 = iVar13 + iVar4 * 8;
        if (uVar9 == 0) goto LAB_1004b458;
        uVar7 = uVar7 >> (*(byte *)(iVar13 + 1) & 0x1f);
        uVar3 = uVar3 - *(byte *)(iVar13 + 1);
      }
      uVar9 = uVar9 & 0xf;
      param_1 = (*(uint *)(&DAT_10059608 + uVar9 * 4) & uVar7) + *(int *)(iVar13 + 4);
      uVar8 = uVar7 >> (sbyte)uVar9;
      for (uVar3 = uVar3 - uVar9; uVar3 < 0xf; uVar3 = uVar3 + 8) {
        local_14 = local_14 - 1;
        uVar8 = uVar8 | (uint)*pbVar10 << ((byte)uVar3 & 0x1f);
        pbVar10 = pbVar10 + 1;
      }
      iVar13 = param_4 + (uVar5 & uVar8) * 8;
      uVar7 = uVar8 >> (*(byte *)(iVar13 + 1) & 0x1f);
      uVar3 = uVar3 - *(byte *)(iVar13 + 1);
      bVar2 = *(byte *)(param_4 + (uVar5 & uVar8) * 8);
      while ((bVar2 & 0x10) == 0) {
        if ((bVar2 & 0x40) != 0) {
          uVar5 = param_6[1] - local_14;
          param_6[6] = (int)s_invalid_distance_code_100583d8;
          uVar6 = uVar3 >> 3;
          if (uVar3 >> 3 < uVar5) {
LAB_1004b56f:
            uVar5 = uVar6;
          }
LAB_1004b571:
          *(uint *)(param_5 + 0x20) = uVar7;
          *(uint *)(param_5 + 0x1c) = uVar3 + uVar5 * -8;
          iVar13 = *param_6;
          param_6[1] = uVar5 + local_14;
          *param_6 = (int)pbVar10 - uVar5;
          param_6[2] = param_6[2] + (((int)pbVar10 - uVar5) - iVar13);
          *(undefined1 **)(param_5 + 0x34) = local_10;
          return 0xfffffffd;
        }
        iVar4 = (*(uint *)(&DAT_10059608 + (uint)bVar2 * 4) & uVar7) + *(int *)(iVar13 + 4);
        pbVar1 = (byte *)(iVar13 + iVar4 * 8);
        iVar13 = iVar13 + iVar4 * 8;
        uVar7 = uVar7 >> (*(byte *)(iVar13 + 1) & 0x1f);
        uVar3 = uVar3 - *(byte *)(iVar13 + 1);
        bVar2 = *pbVar1;
      }
      uVar9 = bVar2 & 0xf;
      for (; uVar3 < uVar9; uVar3 = uVar3 + 8) {
        local_14 = local_14 - 1;
        uVar7 = uVar7 | (uint)*pbVar10 << ((byte)uVar3 & 0x1f);
        pbVar10 = pbVar10 + 1;
      }
      uVar8 = (*(uint *)(&DAT_10059608 + uVar9 * 4) & uVar7) + *(int *)(iVar13 + 4);
      uVar7 = uVar7 >> (sbyte)uVar9;
      uVar3 = uVar3 - uVar9;
      local_c = local_c + -param_1;
      if ((uint)((int)local_10 - *(int *)(param_5 + 0x28)) < uVar8) {
        uVar8 = (*(int *)(param_5 + 0x28) - (int)local_10) + uVar8;
        puVar12 = (undefined1 *)(*(int *)(param_5 + 0x2c) - uVar8);
        if (uVar8 < param_1) {
          param_1 = param_1 - uVar8;
          do {
            *local_10 = *puVar12;
            local_10 = local_10 + 1;
            puVar12 = puVar12 + 1;
            uVar8 = uVar8 - 1;
          } while (uVar8 != 0);
          puVar12 = *(undefined1 **)(param_5 + 0x28);
        }
      }
      else {
        puVar11 = local_10 + -uVar8;
        *local_10 = *puVar11;
        puVar12 = puVar11 + 2;
        local_10[1] = puVar11[1];
        param_1 = param_1 - 2;
        local_10 = local_10 + 2;
      }
      do {
        *local_10 = *puVar12;
        local_10 = local_10 + 1;
        puVar12 = puVar12 + 1;
        param_1 = param_1 - 1;
      } while (param_1 != 0);
    }
    if ((local_c < (undefined1 *)0x102) || (local_14 < 10)) {
      uVar6 = param_6[1] - local_14;
      if (uVar3 >> 3 < param_6[1] - local_14) {
        uVar6 = uVar3 >> 3;
      }
      *(uint *)(param_5 + 0x20) = uVar7;
      *(uint *)(param_5 + 0x1c) = uVar3 + uVar6 * -8;
      iVar13 = *param_6;
      param_6[1] = uVar6 + local_14;
      *param_6 = (int)pbVar10 - uVar6;
      param_6[2] = param_6[2] + (((int)pbVar10 - uVar6) - iVar13);
      *(undefined1 **)(param_5 + 0x34) = local_10;
      return 0;
    }
  } while( true );
}



