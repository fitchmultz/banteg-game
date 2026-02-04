/* huft_build @ 1003692a */

/* zlib (internal): build Huffman decoding tables */

int __cdecl huft_build(uInt *b,uInt n,uInt s,uInt *d,uInt *e,void **t,uInt *m,void *hp,uInt *hn)

{
  uint *puVar1;
  uint *in_EAX;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uInt *puVar8;
  uInt uVar9;
  uint uVar10;
  int iVar11;
  byte bVar12;
  int iVar13;
  int local_fc [15];
  uint local_c0 [16];
  uint local_80 [17];
  int local_3c;
  int local_38;
  int local_34;
  uint local_30;
  uInt *local_2c;
  uint *local_28;
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_80[0] = 0;
  local_80[1] = 0;
  local_80[2] = 0;
  local_80[3] = 0;
  local_80[4] = 0;
  local_80[5] = 0;
  local_80[6] = 0;
  local_80[7] = 0;
  local_80[8] = 0;
  local_80[9] = 0;
  local_80[10] = 0;
  local_80[0xb] = 0;
  local_80[0xc] = 0;
  local_80[0xd] = 0;
  local_80[0xe] = 0;
  local_80[0xf] = 0;
  puVar8 = b;
  uVar9 = n;
  do {
    local_80[*puVar8] = local_80[*puVar8] + 1;
    puVar8 = puVar8 + 1;
    uVar9 = uVar9 - 1;
  } while (uVar9 != 0);
  if (local_80[0] == n) {
    *t = (void *)0x0;
    *in_EAX = 0;
  }
  else {
    uVar10 = 1;
    local_8 = *in_EAX;
    uVar2 = 0xf;
    do {
      if (local_80[uVar10] != 0) break;
      uVar10 = uVar10 + 1;
    } while (uVar10 < 0x10);
    local_c = uVar10;
    if (*in_EAX < uVar10) {
      local_8 = uVar10;
    }
    do {
      if (local_80[uVar2] != 0) break;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
    local_30 = uVar2;
    if (uVar2 < local_8) {
      local_8 = uVar2;
    }
    *in_EAX = local_8;
    iVar11 = 1 << ((byte)uVar10 & 0x1f);
    for (; uVar10 < uVar2; uVar10 = uVar10 + 1) {
      if ((int)(iVar11 - local_80[uVar10]) < 0) {
        return -3;
      }
      iVar11 = (iVar11 - local_80[uVar10]) * 2;
    }
    uVar10 = local_80[uVar2];
    iVar11 = iVar11 - uVar10;
    local_38 = iVar11;
    if (iVar11 < 0) {
      return -3;
    }
    local_80[uVar2] = uVar10 + iVar11;
    iVar6 = 0;
    iVar3 = uVar2 - 1;
    local_c0[1] = 0;
    if (iVar3 != 0) {
      iVar13 = 0;
      do {
        iVar6 = iVar6 + *(int *)((int)local_80 + iVar13 + 4);
        iVar3 = iVar3 + -1;
        *(int *)((int)local_c0 + iVar13 + 8) = iVar6;
        iVar13 = iVar13 + 4;
      } while (iVar3 != 0);
    }
    uVar10 = 0;
    do {
      iVar3 = local_38;
      uVar9 = *b;
      b = b + 1;
      if (uVar9 != 0) {
        uVar7 = local_c0[uVar9];
        hn[uVar7] = uVar10;
        local_c0[uVar9] = uVar7 + 1;
        iVar11 = iVar3;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < n);
    uVar2 = local_c0[uVar2];
    local_10 = -1;
    b = hn;
    iVar3 = -local_8;
    local_24 = 0;
    local_c0[0] = 0;
    local_fc[0] = 0;
    local_2c = (uInt *)0x0;
    local_14 = 0;
    if ((int)local_c <= (int)local_30) {
      local_34 = local_c - 1;
      local_28 = local_80 + local_c;
      do {
        local_20 = *local_28;
        uVar9 = local_1c;
        while (local_1c = uVar9, local_20 != 0) {
          local_1c._2_2_ = (undefined2)(uVar9 >> 0x10);
          local_20 = local_20 - 1;
          local_3c = local_8 + iVar3;
          if (local_3c < (int)local_c) {
            local_80[0x10] = iVar3 - local_8;
            do {
              iVar11 = local_10;
              local_10 = local_10 + 1;
              iVar3 = iVar3 + local_8;
              local_80[0x10] = local_80[0x10] + local_8;
              local_3c = local_3c + local_8;
              uVar10 = local_30 - iVar3;
              if (local_8 < local_30 - iVar3) {
                uVar10 = local_8;
              }
              uVar7 = local_c - iVar3;
              uVar4 = 1 << ((byte)uVar7 & 0x1f);
              if ((local_20 + 1 < uVar4) &&
                 (iVar6 = uVar4 + (-1 - local_20), puVar1 = local_28, uVar7 < uVar10)) {
                while (uVar7 = uVar7 + 1, uVar7 < uVar10) {
                  uVar4 = puVar1[1];
                  uVar5 = iVar6 * 2;
                  if (uVar5 < uVar4 || uVar5 - uVar4 == 0) break;
                  iVar6 = uVar5 - uVar4;
                  puVar1 = puVar1 + 1;
                }
              }
              local_14 = 1 << ((byte)uVar7 & 0x1f);
              uVar10 = *(int *)hp + local_14;
              if (0x5a0 < uVar10) {
                return -4;
              }
              local_2c = m + *(int *)hp * 2;
              local_fc[local_10] = (int)(m + *(int *)hp * 2);
              uVar4 = local_24;
              *(uint *)hp = uVar10;
              if (local_10 == 0) {
                *t = local_2c;
              }
              else {
                local_c0[local_10] = local_24;
                local_1c = CONCAT31(CONCAT21(local_1c._2_2_,(undefined1)local_8),(byte)uVar7);
                uVar4 = uVar4 >> ((byte)local_80[0x10] & 0x1f);
                iVar11 = local_fc[iVar11];
                local_18 = ((int)local_2c - iVar11 >> 3) - uVar4;
                *(uInt *)(iVar11 + uVar4 * 8) = local_1c;
                *(uint *)(iVar11 + 4 + uVar4 * 8) = local_18;
              }
              iVar11 = local_38;
            } while (local_3c < (int)local_c);
          }
          bVar12 = (byte)iVar3;
          if (b < hn + uVar2) {
            local_18 = *b;
            if (local_18 < s) {
              local_1c._0_1_ = (local_18 < 0x100) - 1U & 0x60;
            }
            else {
              local_1c._0_1_ = (char)e[local_18 - s] + 0x50;
              local_18 = d[local_18 - s];
            }
            b = b + 1;
          }
          else {
            local_1c._0_1_ = 0xc0;
          }
          local_1c = CONCAT31(CONCAT21(local_1c._2_2_,(char)local_c - bVar12),(byte)local_1c);
          iVar6 = 1 << ((char)local_c - bVar12 & 0x1f);
          uVar10 = local_24 >> (bVar12 & 0x1f);
          if (uVar10 < local_14) {
            puVar8 = local_2c + uVar10 * 2;
            do {
              *puVar8 = local_1c;
              puVar8[1] = local_18;
              uVar10 = uVar10 + iVar6;
              puVar8 = puVar8 + iVar6 * 2;
              iVar11 = local_38;
            } while (uVar10 < local_14);
          }
          uVar10 = 1 << ((byte)local_34 & 0x1f);
          while ((local_24 & uVar10) != 0) {
            local_24 = local_24 ^ uVar10;
            uVar10 = uVar10 >> 1;
          }
          local_24 = local_24 ^ uVar10;
          uVar9 = local_1c;
          if (((1 << (bVar12 & 0x1f)) - 1U & local_24) != local_c0[local_10]) {
            do {
              iVar3 = iVar3 - local_8;
              local_10 = local_10 + -1;
            } while (((1 << ((byte)iVar3 & 0x1f)) - 1U & local_24) != local_c0[local_10]);
          }
        }
        local_c = local_c + 1;
        local_28 = local_28 + 1;
        local_34 = local_34 + 1;
      } while ((int)local_c <= (int)local_30);
    }
    if ((iVar11 != 0) && (local_30 != 1)) {
      return -5;
    }
  }
  return 0;
}



