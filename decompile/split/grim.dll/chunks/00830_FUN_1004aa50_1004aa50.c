/* FUN_1004aa50 @ 1004aa50 */

undefined4 __cdecl
FUN_1004aa50(int *param_1,uint param_2,uint param_3,int param_4,int param_5,uint *param_6,
            uint *param_7,int param_8,uint *param_9,uint *param_10)

{
  undefined4 uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  byte bVar16;
  int iVar17;
  uint uVar18;
  uint local_100;
  uint local_fc;
  int local_f8;
  uint *local_f4;
  int local_f0;
  uint *local_e8;
  undefined4 local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  uint local_bc [47];
  
  uVar18 = 0;
  local_bc[0] = 0;
  local_bc[1] = 0;
  local_bc[2] = 0;
  local_bc[3] = 0;
  local_bc[4] = 0;
  local_bc[5] = 0;
  local_bc[6] = 0;
  local_bc[7] = 0;
  local_bc[8] = 0;
  local_bc[9] = 0;
  local_bc[10] = 0;
  local_bc[0xb] = 0;
  local_bc[0xc] = 0;
  local_bc[0xd] = 0;
  local_bc[0xe] = 0;
  local_bc[0xf] = 0;
  piVar8 = param_1;
  uVar13 = param_2;
  do {
    iVar17 = *piVar8;
    piVar8 = piVar8 + 1;
    uVar13 = uVar13 - 1;
    local_bc[iVar17] = local_bc[iVar17] + 1;
  } while (uVar13 != 0);
  if (local_bc[0] == param_2) {
    *param_6 = 0;
    *param_7 = 0;
  }
  else {
    local_fc = 1;
    puVar7 = local_bc;
    do {
      puVar7 = puVar7 + 1;
      if (*puVar7 != 0) break;
      local_fc = local_fc + 1;
    } while (local_fc < 0x10);
    local_100 = *param_7;
    if (*param_7 < local_fc) {
      local_100 = local_fc;
    }
    uVar13 = 0xf;
    puVar7 = local_bc + 0xf;
    do {
      if (*puVar7 != 0) break;
      uVar13 = uVar13 - 1;
      puVar7 = puVar7 + -1;
    } while (uVar13 != 0);
    if (uVar13 < local_100) {
      local_100 = uVar13;
    }
    *param_7 = local_100;
    iVar17 = 1 << ((byte)local_fc & 0x1f);
    if (local_fc < uVar13) {
      puVar7 = local_bc + local_fc;
      uVar9 = local_fc;
      do {
        uVar6 = *puVar7;
        if ((int)(iVar17 - uVar6) < 0) {
          return 0xfffffffd;
        }
        uVar9 = uVar9 + 1;
        puVar7 = puVar7 + 1;
        iVar17 = (iVar17 - uVar6) * 2;
      } while (uVar9 < uVar13);
    }
    iVar17 = iVar17 - local_bc[uVar13];
    if (iVar17 < 0) {
      return 0xfffffffd;
    }
    local_bc[0x11] = 0;
    local_bc[uVar13] = local_bc[uVar13] + iVar17;
    iVar10 = 0;
    iVar14 = uVar13 - 1;
    if (iVar14 != 0) {
      iVar4 = 0;
      do {
        iVar10 = iVar10 + *(int *)((int)local_bc + iVar4 + 4);
        iVar14 = iVar14 + -1;
        *(int *)((int)local_bc + iVar4 + 0x48) = iVar10;
        iVar4 = iVar4 + 4;
      } while (iVar14 != 0);
    }
    uVar9 = 0;
    do {
      iVar10 = *param_1;
      param_1 = param_1 + 1;
      if (iVar10 != 0) {
        uVar6 = local_bc[iVar10 + 0x10];
        param_10[uVar6] = uVar9;
        local_bc[iVar10 + 0x10] = uVar6 + 1;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < param_2);
    iVar10 = -local_100;
    uVar9 = local_bc[uVar13 + 0x10];
    local_f4 = param_10;
    local_d8 = 0;
    local_bc[0x10] = 0;
    local_f8 = -1;
    local_bc[0x20] = 0;
    local_d0 = 0;
    local_d4 = 0;
    if ((int)local_fc <= (int)uVar13) {
      local_f0 = local_fc - 1;
      local_e8 = local_bc + local_fc;
      do {
        uVar6 = *local_e8;
        uVar1 = local_e0;
        while (uVar6 != 0) {
          uVar15 = uVar6 - 1;
          local_e0._2_2_ = (undefined2)((uint)uVar1 >> 0x10);
          uVar2 = local_e0._2_2_;
          iVar14 = iVar10;
          while (local_e0 = uVar1, iVar14 = iVar14 + local_100, iVar14 < (int)local_fc) {
            iVar10 = iVar10 + local_100;
            uVar18 = uVar13 - iVar10;
            if (local_100 < uVar13 - iVar10) {
              uVar18 = local_100;
            }
            uVar11 = local_fc - iVar10;
            uVar3 = 1 << ((byte)uVar11 & 0x1f);
            if ((uVar6 < uVar3) &&
               (iVar4 = uVar3 + (-1 - uVar15), puVar7 = local_e8, uVar11 < uVar18)) {
              while (uVar11 = uVar11 + 1, uVar11 < uVar18) {
                uVar3 = puVar7[1];
                uVar5 = iVar4 * 2;
                if (uVar5 < uVar3 || uVar5 - uVar3 == 0) break;
                iVar4 = uVar5 - uVar3;
                puVar7 = puVar7 + 1;
              }
            }
            local_d4 = 1 << ((byte)uVar11 & 0x1f);
            uVar18 = *param_9;
            uVar3 = local_d4 + uVar18;
            if (0x5a0 < uVar3) {
              return 0xfffffffc;
            }
            *param_9 = uVar3;
            local_d0 = param_8 + uVar18 * 8;
            local_bc[local_f8 + 0x21] = local_d0;
            if (local_f8 + 1 == 0) {
              *param_6 = local_d0;
            }
            else {
              local_bc[local_f8 + 0x11] = local_d8;
              local_e0._2_2_ = (undefined2)((uint)local_e0 >> 0x10);
              local_e0._0_2_ = CONCAT11((char)local_100,(byte)uVar11);
              uVar11 = local_d8 >> ((char)iVar10 - (char)local_100 & 0x1fU);
              uVar18 = local_bc[local_f8 + 0x20];
              local_dc = ((int)(local_d0 - uVar18) >> 3) - uVar11;
              *(undefined4 *)(uVar18 + uVar11 * 8) = local_e0;
              *(uint *)(uVar18 + 4 + uVar11 * 8) = local_dc;
            }
            uVar18 = local_d8;
            local_f8 = local_f8 + 1;
            uVar1 = local_e0;
            uVar2 = local_e0._2_2_;
          }
          bVar16 = (byte)iVar10;
          if (local_f4 < param_10 + uVar9) {
            local_dc = *local_f4;
            if (local_dc < param_3) {
              local_e0._0_1_ = (-(local_dc < 0x100) & 0xa0U) + 0x60;
            }
            else {
              iVar14 = (local_dc - param_3) * 4;
              local_e0._0_1_ = *(char *)(iVar14 + param_5) + 'P';
              local_dc = *(uint *)(iVar14 + param_4);
            }
            local_f4 = local_f4 + 1;
          }
          else {
            local_e0._0_1_ = -0x40;
          }
          local_e0 = CONCAT31(CONCAT21(uVar2,(char)local_fc - bVar16),(char)local_e0);
          iVar14 = 1 << ((char)local_fc - bVar16 & 0x1f);
          uVar6 = uVar18 >> (bVar16 & 0x1f);
          if (uVar6 < local_d4) {
            puVar12 = (undefined4 *)(local_d0 + uVar6 * 8);
            do {
              uVar6 = uVar6 + iVar14;
              *puVar12 = local_e0;
              puVar12[1] = local_dc;
              puVar12 = puVar12 + iVar14 * 2;
            } while (uVar6 < local_d4);
          }
          uVar11 = 1 << ((byte)local_f0 & 0x1f);
          uVar6 = uVar18 & uVar11;
          while (uVar6 != 0) {
            uVar18 = uVar18 ^ uVar11;
            uVar11 = uVar11 >> 1;
            uVar6 = uVar18 & uVar11;
          }
          uVar18 = uVar18 ^ uVar11;
          puVar7 = local_bc + local_f8 + 0x10;
          uVar6 = uVar15;
          uVar1 = local_e0;
          local_d8 = uVar18;
          if (((1 << (bVar16 & 0x1f)) - 1U & uVar18) != local_bc[local_f8 + 0x10]) {
            do {
              local_f8 = local_f8 + -1;
              iVar10 = iVar10 - local_100;
              puVar7 = puVar7 + -1;
            } while (((1 << ((byte)iVar10 & 0x1f)) - 1U & uVar18) != *puVar7);
          }
        }
        local_e8 = local_e8 + 1;
        local_fc = local_fc + 1;
        local_f0 = local_f0 + 1;
        local_e0 = uVar1;
      } while ((int)local_fc <= (int)uVar13);
    }
    if ((iVar17 != 0) && (uVar13 != 1)) {
      return 0xfffffffb;
    }
  }
  return 0;
}



