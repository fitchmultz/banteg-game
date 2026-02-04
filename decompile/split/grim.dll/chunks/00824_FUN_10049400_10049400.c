/* FUN_10049400 @ 10049400 */

void __cdecl FUN_10049400(uint *param_1,int *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  uint *local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint *local_20;
  void *local_1c;
  void *local_18;
  uInt local_14;
  uInt local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  puVar3 = param_1;
  local_30 = (uint *)*param_2;
  local_2c = param_2[1];
  local_28 = param_1[8];
  puVar7 = (uint *)param_1[7];
  puVar8 = (uint *)param_1[0xd];
  if (puVar8 < (uint *)param_1[0xc]) {
    local_24 = (int)param_1[0xc] + (-1 - (int)puVar8);
    param_1 = puVar8;
  }
  else {
    local_24 = param_1[0xb] - (int)puVar8;
    param_1 = puVar8;
  }
switchD_100494b1_default:
  uVar10 = local_28;
  switch(*puVar3) {
  case 0:
    goto switchD_1004944d_caseD_0;
  case 1:
    for (; puVar7 < (uint *)0x20; puVar7 = puVar7 + 2) {
      if (local_2c == 0) {
        puVar3[8] = local_28;
        puVar3[7] = (uint)puVar7;
        iVar5 = *param_2;
        param_2[1] = 0;
        *param_2 = (int)local_30;
        param_2[2] = (int)((int)local_30 + (param_2[2] - iVar5));
        puVar3[0xd] = (uint)param_1;
        FUN_1004b0e0((int)puVar3,(int)param_2,param_3);
        return;
      }
      param_3 = 0;
      local_2c = local_2c - 1;
      local_28 = local_28 | (uint)(byte)*local_30 << ((byte)puVar7 & 0x1f);
      local_30 = (uint *)((int)local_30 + 1);
    }
    uVar10 = local_28 & 0xffff;
    if (~local_28 >> 0x10 != uVar10) {
      *puVar3 = 9;
      param_2[6] = (int)s_invalid_stored_block_lengths_100583a4;
      puVar3[8] = local_28;
      puVar3[7] = (uint)puVar7;
      iVar5 = *param_2;
      *param_2 = (int)local_30;
      param_2[1] = local_2c;
      param_2[2] = (int)((int)local_30 + (param_2[2] - iVar5));
      puVar3[0xd] = (uint)param_1;
      FUN_1004b0e0((int)puVar3,(int)param_2,-3);
      return;
    }
    puVar7 = (uint *)0x0;
    puVar3[1] = uVar10;
    local_28 = 0;
    if (uVar10 != 0) {
      *puVar3 = 2;
      goto switchD_100494b1_default;
    }
    break;
  case 2:
    if (local_2c == 0) {
      puVar3[8] = local_28;
      puVar3[7] = (uint)puVar7;
      iVar5 = *param_2;
      *param_2 = (int)local_30;
      param_2[1] = 0;
      param_2[2] = (int)((int)local_30 + (param_2[2] - iVar5));
      puVar3[0xd] = (uint)param_1;
      FUN_1004b0e0((int)puVar3,(int)param_2,param_3);
      return;
    }
    if (local_24 == 0) {
      if (param_1 == (uint *)puVar3[0xb]) {
        puVar8 = (uint *)puVar3[0xc];
        puVar9 = (uint *)puVar3[10];
        if (puVar8 != puVar9) {
          if (puVar9 < puVar8) {
            local_24 = (int)puVar8 + (-1 - (int)puVar9);
          }
          else {
            local_24 = (int)puVar3[0xb] - (int)puVar9;
          }
          param_1 = puVar9;
          if (local_24 != 0) goto LAB_10049676;
        }
      }
      puVar3[0xd] = (uint)param_1;
      iVar5 = FUN_1004b0e0((int)puVar3,(int)param_2,param_3);
      param_1 = (uint *)puVar3[0xd];
      puVar8 = (uint *)puVar3[0xc];
      if (param_1 < puVar8) {
        local_24 = (int)puVar8 + (-1 - (int)param_1);
      }
      else {
        local_24 = puVar3[0xb] - (int)param_1;
      }
      local_20 = (uint *)puVar3[0xb];
      if ((param_1 == local_20) && (puVar9 = (uint *)puVar3[10], puVar8 != puVar9)) {
        param_1 = puVar9;
        if (puVar9 < puVar8) {
          local_24 = (int)puVar8 + (-1 - (int)puVar9);
        }
        else {
          local_24 = (int)local_20 - (int)puVar9;
        }
      }
      if (local_24 == 0) {
        puVar3[8] = local_28;
        puVar3[7] = (uint)puVar7;
        iVar2 = *param_2;
        param_2[1] = local_2c;
        *param_2 = (int)local_30;
        param_2[2] = (int)((int)local_30 + (param_2[2] - iVar2));
        puVar3[0xd] = (uint)param_1;
        FUN_1004b0e0((int)puVar3,(int)param_2,iVar5);
        return;
      }
    }
LAB_10049676:
    param_3 = 0;
    uVar10 = puVar3[1];
    if (local_2c < puVar3[1]) {
      uVar10 = local_2c;
    }
    if (local_24 < uVar10) {
      uVar10 = local_24;
    }
    puVar8 = local_30;
    puVar9 = param_1;
    for (uVar4 = uVar10 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    local_24 = local_24 - uVar10;
    for (uVar4 = uVar10 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(byte *)puVar9 = (byte)*puVar8;
      puVar8 = (uint *)((int)puVar8 + 1);
      puVar9 = (uint *)((int)puVar9 + 1);
    }
    local_30 = (uint *)((int)local_30 + uVar10);
    uVar4 = puVar3[1];
    local_2c = local_2c - uVar10;
    param_1 = (uint *)((int)param_1 + uVar10);
    puVar3[1] = uVar4 - uVar10;
    if (uVar4 - uVar10 != 0) goto switchD_100494b1_default;
    break;
  case 3:
    for (; puVar7 < (uint *)0xe; puVar7 = puVar7 + 2) {
      if (local_2c == 0) {
        puVar3[8] = local_28;
        puVar3[7] = (uint)puVar7;
        iVar5 = *param_2;
        *param_2 = (int)local_30;
        param_2[1] = 0;
        param_2[2] = (int)((int)local_30 + (param_2[2] - iVar5));
        puVar3[0xd] = (uint)param_1;
        FUN_1004b0e0((int)puVar3,(int)param_2,param_3);
        return;
      }
      local_2c = local_2c - 1;
      param_3 = 0;
      local_28 = local_28 | (uint)(byte)*local_30 << ((byte)puVar7 & 0x1f);
      local_30 = (uint *)((int)local_30 + 1);
    }
    puVar3[1] = local_28 & 0x3fff;
    if ((0x1d < (local_28 & 0x1f)) || (0x3a0 < (local_28 & 0x3e0))) {
      *puVar3 = 9;
      param_2[6] = (int)s_too_many_length_or_distance_symb_10058380;
      puVar3[8] = local_28;
      puVar3[7] = (uint)puVar7;
      iVar5 = *param_2;
      param_2[1] = local_2c;
      *param_2 = (int)local_30;
      param_2[2] = (int)((int)local_30 + (param_2[2] - iVar5));
      puVar3[0xd] = (uint)param_1;
      FUN_1004b0e0((int)puVar3,(int)param_2,-3);
      return;
    }
    uVar10 = (*(code *)param_2[8])
                       (param_2[10],((local_28 & 0x3fff) >> 5 & 0x1f) + 0x102 + (local_28 & 0x1f),4)
    ;
    puVar3[3] = uVar10;
    if (uVar10 == 0) {
      puVar3[8] = local_28;
      puVar3[7] = (uint)puVar7;
      iVar5 = *param_2;
      param_2[1] = local_2c;
      *param_2 = (int)local_30;
      param_2[2] = (int)((int)local_30 + (param_2[2] - iVar5));
      puVar3[0xd] = (uint)param_1;
      FUN_1004b0e0((int)puVar3,(int)param_2,-4);
      return;
    }
    local_28 = local_28 >> 0xe;
    puVar7 = (uint *)((int)puVar7 - 0xe);
    puVar3[2] = 0;
    *puVar3 = 4;
    goto LAB_1004979d;
  case 4:
LAB_1004979d:
    if (puVar3[2] < (puVar3[1] >> 10) + 4) {
      do {
        for (; puVar7 < (uint *)0x3; puVar7 = puVar7 + 2) {
          if (local_2c == 0) {
            puVar3[8] = local_28;
            puVar3[7] = (uint)puVar7;
            iVar5 = *param_2;
            *param_2 = (int)local_30;
            param_2[2] = (int)((int)local_30 + (param_2[2] - iVar5));
            param_2[1] = 0;
            puVar3[0xd] = (uint)param_1;
            FUN_1004b0e0((int)puVar3,(int)param_2,param_3);
            return;
          }
          local_2c = local_2c - 1;
          param_3 = 0;
          local_28 = local_28 | (uint)(byte)*local_30 << ((byte)puVar7 & 0x1f);
          local_30 = (uint *)((int)local_30 + 1);
        }
        uVar10 = local_28 & 7;
        puVar7 = (uint *)((int)puVar7 - 3);
        local_28 = local_28 >> 3;
        *(uint *)(puVar3[3] + *(int *)(&DAT_10051454 + puVar3[2] * 4) * 4) = uVar10;
        uVar10 = puVar3[2];
        puVar3[2] = uVar10 + 1;
      } while (uVar10 + 1 < (puVar3[1] >> 10) + 4);
    }
    uVar10 = puVar3[2];
    while (uVar10 < 0x13) {
      *(undefined4 *)(puVar3[3] + *(int *)(&DAT_10051454 + puVar3[2] * 4) * 4) = 0;
      uVar10 = puVar3[2] + 1;
      puVar3[2] = uVar10;
    }
    puVar3[4] = 7;
    iVar5 = FUN_1004a9a0((int *)puVar3[3],puVar3 + 4,puVar3 + 5,puVar3[9],(int)param_2);
    uVar10 = local_28;
    if (iVar5 == 0) {
      puVar3[2] = 0;
      *puVar3 = 5;
LAB_10049886:
      if (puVar3[2] < (puVar3[1] >> 5 & 0x1f) + 0x102 + (puVar3[1] & 0x1f)) {
        do {
          for (; puVar7 < (uint *)puVar3[4]; puVar7 = puVar7 + 2) {
            if (local_2c == 0) goto LAB_10049e69;
            local_2c = local_2c - 1;
            param_3 = 0;
            uVar10 = uVar10 | (uint)(byte)*local_30 << ((byte)puVar7 & 0x1f);
            local_30 = (uint *)((int)local_30 + 1);
          }
          bVar1 = *(byte *)(puVar3[5] + 1 +
                           (*(uint *)(&DAT_10059608 + (int)puVar3[4] * 4) & uVar10) * 8);
          uVar4 = (uint)bVar1;
          local_c = *(uint *)(puVar3[5] +
                              (*(uint *)(&DAT_10059608 + (int)puVar3[4] * 4) & uVar10) * 8 + 4);
          if (local_c < 0x10) {
            puVar7 = (uint *)((int)puVar7 - uVar4);
            uVar10 = uVar10 >> (bVar1 & 0x1f);
            *(uint *)(puVar3[3] + puVar3[2] * 4) = local_c;
            uVar4 = puVar3[2] + 1;
          }
          else {
            local_24 = 7;
            if (local_c != 0x12) {
              local_24 = local_c - 0xe;
            }
            local_20 = (uint *)(local_24 + uVar4);
            for (; puVar7 < local_20; puVar7 = puVar7 + 2) {
              if (local_2c == 0) {
LAB_10049e69:
                puVar3[8] = uVar10;
                puVar3[7] = (uint)puVar7;
                iVar5 = *param_2;
                *param_2 = (int)local_30;
                param_2[2] = (int)((int)local_30 + (param_2[2] - iVar5));
                param_2[1] = 0;
                puVar3[0xd] = (uint)param_1;
                FUN_1004b0e0((int)puVar3,(int)param_2,param_3);
                return;
              }
              local_2c = local_2c - 1;
              param_3 = 0;
              uVar10 = uVar10 | (uint)(byte)*local_30 << ((byte)puVar7 & 0x1f);
              local_30 = (uint *)((int)local_30 + 1);
            }
            uVar10 = uVar10 >> (bVar1 & 0x1f);
            local_28 = (-(uint)(local_c != 0x12) & 0xfffffff8) + 0xb +
                       (*(uint *)(&DAT_10059608 + local_24 * 4) & uVar10);
            uVar10 = uVar10 >> ((byte)local_24 & 0x1f);
            puVar7 = (uint *)((int)puVar7 - (local_24 + uVar4));
            local_24 = puVar3[2];
            if ((puVar3[1] >> 5 & 0x1f) + 0x102 + (puVar3[1] & 0x1f) < local_28 + local_24) {
LAB_10049ea8:
              (*(code *)param_2[9])(param_2[10],puVar3[3]);
              *puVar3 = 9;
              param_2[6] = (int)s_invalid_bit_length_repeat_10058364;
              puVar3[8] = uVar10;
              puVar3[7] = (uint)puVar7;
              iVar5 = *param_2;
              param_2[1] = local_2c;
              *param_2 = (int)local_30;
              param_2[2] = (int)((int)local_30 + (param_2[2] - iVar5));
              puVar3[0xd] = (uint)param_1;
              FUN_1004b0e0((int)puVar3,(int)param_2,-3);
              return;
            }
            uVar4 = local_24;
            if (local_c == 0x10) {
              if (local_24 == 0) goto LAB_10049ea8;
              uVar6 = *(undefined4 *)((puVar3[3] - 4) + local_24 * 4);
            }
            else {
              uVar6 = 0;
            }
            do {
              uVar4 = uVar4 + 1;
              *(undefined4 *)((puVar3[3] - 4) + uVar4 * 4) = uVar6;
              local_28 = local_28 + -1;
            } while (local_28 != 0);
          }
          puVar3[2] = uVar4;
        } while (puVar3[2] < (puVar3[1] >> 5 & 0x1f) + 0x102 + (puVar3[1] & 0x1f));
      }
      puVar3[5] = 0;
      local_20 = (uint *)0x9;
      local_24 = 6;
      local_28 = FUN_1004af20((puVar3[1] & 0x1f) + 0x101,(puVar3[1] >> 5 & 0x1f) + 1,
                              (int *)puVar3[3],(uint *)&local_20,&local_24,&local_4,&local_8,
                              puVar3[9],(int)param_2);
      (*(code *)param_2[9])(param_2[10],puVar3[3]);
      if (local_28 == 0) {
        uVar4 = FUN_1004a190((char)local_20,(char)local_24,local_4,local_8,(int)param_2);
        if (uVar4 == 0) {
          puVar3[8] = uVar10;
          puVar3[7] = (uint)puVar7;
          param_2[1] = local_2c;
          param_2[2] = (int)((int)local_30 + (param_2[2] - *param_2));
          *param_2 = (int)local_30;
          puVar3[0xd] = (uint)param_1;
          FUN_1004b0e0((int)puVar3,(int)param_2,-4);
          return;
        }
        puVar3[1] = uVar4;
        *puVar3 = 6;
LAB_10049ad6:
        puVar3[8] = uVar10;
        puVar3[7] = (uint)puVar7;
        iVar5 = *param_2;
        param_2[1] = local_2c;
        *param_2 = (int)local_30;
        param_2[2] = (int)((int)local_30 + (param_2[2] - iVar5));
        puVar3[0xd] = (uint)param_1;
        iVar5 = FUN_1004a1d0((uint)puVar3,param_2,param_3);
        if (iVar5 == 1) {
          param_3 = 0;
          FUN_1004a980(puVar3[1],(int)param_2);
          local_28 = puVar3[8];
          param_1 = (uint *)puVar3[0xd];
          local_30 = (uint *)*param_2;
          local_2c = param_2[1];
          puVar7 = (uint *)puVar3[7];
          if (param_1 < (uint *)puVar3[0xc]) {
            local_24 = (int)puVar3[0xc] + (-1 - (int)param_1);
          }
          else {
            local_24 = puVar3[0xb] - (int)param_1;
          }
          if (puVar3[6] == 0) {
            *puVar3 = 0;
            goto switchD_100494b1_default;
          }
          *puVar3 = 7;
LAB_10049f98:
          puVar3[0xd] = (uint)param_1;
          iVar5 = FUN_1004b0e0((int)puVar3,(int)param_2,param_3);
          param_1 = (uint *)puVar3[0xd];
          if ((uint *)puVar3[0xc] == param_1) {
            *puVar3 = 8;
LAB_10049fff:
            puVar3[8] = local_28;
            puVar3[7] = (uint)puVar7;
            param_2[1] = local_2c;
            param_2[2] = (int)((int)local_30 + (param_2[2] - *param_2));
            *param_2 = (int)local_30;
            puVar3[0xd] = (uint)param_1;
            FUN_1004b0e0((int)puVar3,(int)param_2,1);
            return;
          }
          puVar3[7] = (uint)puVar7;
          puVar3[8] = local_28;
          iVar2 = *param_2;
          param_2[1] = local_2c;
          *param_2 = (int)local_30;
          param_2[2] = (int)((int)local_30 + (param_2[2] - iVar2));
          puVar3[0xd] = (uint)param_1;
        }
        FUN_1004b0e0((int)puVar3,(int)param_2,iVar5);
        return;
      }
    }
    else {
      (*(code *)param_2[9])(param_2[10],puVar3[3]);
      local_28 = iVar5;
    }
    if (local_28 == -3) {
      *puVar3 = 9;
    }
    puVar3[8] = uVar10;
    puVar3[7] = (uint)puVar7;
    iVar5 = *param_2;
    param_2[1] = local_2c;
    *param_2 = (int)local_30;
    param_2[2] = (int)((int)local_30 + (param_2[2] - iVar5));
    puVar3[0xd] = (uint)param_1;
    FUN_1004b0e0((int)puVar3,(int)param_2,local_28);
    return;
  case 5:
    goto LAB_10049886;
  case 6:
    goto LAB_10049ad6;
  case 7:
    goto LAB_10049f98;
  case 8:
    goto LAB_10049fff;
  case 9:
    puVar3[8] = local_28;
    puVar3[7] = (uint)puVar7;
    iVar5 = *param_2;
    param_2[1] = local_2c;
    *param_2 = (int)local_30;
    param_2[2] = (int)((int)local_30 + (param_2[2] - iVar5));
    puVar3[0xd] = (uint)param_1;
    FUN_1004b0e0((int)puVar3,(int)param_2,-3);
    return;
  default:
    puVar3[8] = local_28;
    puVar3[7] = (uint)puVar7;
    iVar5 = *param_2;
    param_2[1] = local_2c;
    *param_2 = (int)local_30;
    param_2[2] = (int)((int)local_30 + (param_2[2] - iVar5));
    puVar3[0xd] = (uint)param_1;
    FUN_1004b0e0((int)puVar3,(int)param_2,-2);
    return;
  }
  *puVar3 = -(uint)(puVar3[6] != 0) & 7;
  goto switchD_100494b1_default;
switchD_1004944d_caseD_0:
  for (; puVar7 < (uint *)0x3; puVar7 = puVar7 + 2) {
    if (local_2c == 0) {
      puVar3[8] = local_28;
      puVar3[7] = (uint)puVar7;
      param_2[1] = 0;
      param_2[2] = (int)((int)local_30 + (param_2[2] - *param_2));
      *param_2 = (int)local_30;
      puVar3[0xd] = (uint)param_1;
      FUN_1004b0e0((int)puVar3,(int)param_2,param_3);
      return;
    }
    local_2c = local_2c - 1;
    param_3 = 0;
    local_28 = local_28 | (uint)(byte)*local_30 << ((byte)puVar7 & 0x1f);
    local_30 = (uint *)((int)local_30 + 1);
  }
  puVar3[6] = local_28 & 1;
  switch((local_28 & 7) >> 1) {
  case 0:
    *puVar3 = 1;
    uVar10 = (int)puVar7 - 3U & 7;
    local_28 = (local_28 >> 3) >> (sbyte)uVar10;
    puVar7 = (uint *)(((int)puVar7 - 3U) - uVar10);
    break;
  case 1:
    inflate_trees_fixed(&local_10,&local_14,&local_18,&local_1c,(z_streamp)param_2);
    uVar10 = FUN_1004a190((char)local_10,(char)local_14,local_18,local_1c,(int)param_2);
    puVar3[1] = uVar10;
    if (uVar10 == 0) {
      puVar3[8] = local_28;
      puVar3[7] = (uint)puVar7;
      param_2[1] = local_2c;
      param_2[2] = (int)((int)local_30 + (param_2[2] - *param_2));
      *param_2 = (int)local_30;
      puVar3[0xd] = (uint)param_1;
      FUN_1004b0e0((int)puVar3,(int)param_2,-4);
      return;
    }
    local_28 = local_28 >> 3;
    puVar7 = (uint *)((int)puVar7 - 3);
    *puVar3 = 6;
    break;
  case 2:
    local_28 = local_28 >> 3;
    puVar7 = (uint *)((int)puVar7 - 3);
    *puVar3 = 3;
    break;
  case 3:
    *puVar3 = 9;
    param_2[6] = (int)s_invalid_block_type_100583c4;
    puVar3[8] = local_28 >> 3;
    puVar3[7] = (int)puVar7 - 3;
    param_2[1] = local_2c;
    param_2[2] = (int)((int)local_30 + (param_2[2] - *param_2));
    *param_2 = (int)local_30;
    puVar3[0xd] = (uint)param_1;
    FUN_1004b0e0((int)puVar3,(int)param_2,-3);
    return;
  }
  goto switchD_100494b1_default;
}



