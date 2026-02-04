/* inflate_codes @ 100363b5 */

/* zlib (internal): decode codes */

int __cdecl inflate_codes(void *s,z_streamp z,int r)

{
  byte bVar1;
  int *piVar2;
  undefined1 *puVar3;
  Bytef *pBVar4;
  void *s_00;
  z_streamp z_00;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puStack_18;
  undefined1 *local_10;
  uInt local_c;
  byte *local_8;
  
  z_00 = z;
  s_00 = s;
  local_8 = z->next_in;
  local_c = z->avail_in;
  puVar9 = *(undefined1 **)((int)s + 0x34);
  piVar2 = *(int **)((int)s + 4);
  z = *(z_streamp *)((int)s + 0x20);
  if (puVar9 < *(undefined1 **)((int)s + 0x30)) {
    local_10 = *(undefined1 **)((int)s + 0x30) + (-1 - (int)puVar9);
    s = *(void **)((int)s + 0x1c);
  }
  else {
    local_10 = (undefined1 *)(*(int *)((int)s + 0x2c) - (int)puVar9);
    s = *(void **)((int)s + 0x1c);
  }
  do {
    puVar8 = puVar9;
    switch(*piVar2) {
    case 0:
      if (((undefined1 *)0x101 < local_10) && (9 < local_c)) {
        *(z_streamp *)((int)s_00 + 0x20) = z;
        *(void **)((int)s_00 + 0x1c) = s;
        z_00->avail_in = local_c;
        z_00->total_in = (uLong)(local_8 + (z_00->total_in - (int)z_00->next_in));
        z_00->next_in = local_8;
        *(undefined1 **)((int)s_00 + 0x34) = puVar9;
        r = FUN_10038bbd((uint)*(byte *)(piVar2 + 4),(uint)*(byte *)((int)piVar2 + 0x11),piVar2[5],
                         piVar2[6],(int)s_00,(byte *)z_00);
        puVar9 = *(undefined1 **)((int)s_00 + 0x34);
        local_8 = z_00->next_in;
        local_c = z_00->avail_in;
        z = *(z_streamp *)((int)s_00 + 0x20);
        s = *(void **)((int)s_00 + 0x1c);
        if (puVar9 < *(undefined1 **)((int)s_00 + 0x30)) {
          local_10 = *(undefined1 **)((int)s_00 + 0x30) + (-1 - (int)puVar9);
        }
        else {
          local_10 = (undefined1 *)(*(int *)((int)s_00 + 0x2c) - (int)puVar9);
        }
        if (r != 0) {
          *piVar2 = (uint)(r != 1) * 2 + 7;
          break;
        }
      }
      piVar2[3] = (uint)*(byte *)(piVar2 + 4);
      piVar2[2] = piVar2[5];
      *piVar2 = 1;
    case 1:
      for (; s < (void *)piVar2[3]; s = (void *)((int)s + 8)) {
        if (local_c == 0) goto code_r0x1003687e;
        r = 0;
        local_c = local_c - 1;
        z = (z_streamp)((uint)z | (uint)*local_8 << ((byte)s & 0x1f));
        local_8 = local_8 + 1;
      }
      pbVar5 = (byte *)(piVar2[2] + (*(uint *)(&DAT_10057020 + piVar2[3] * 4) & (uint)z) * 8);
      z = (z_streamp)((uint)z >> (pbVar5[1] & 0x1f));
      s = (void *)((int)s - (uint)pbVar5[1]);
      bVar1 = *pbVar5;
      uVar7 = (uint)bVar1;
      if (uVar7 == 0) {
        pbVar5 = *(byte **)(pbVar5 + 4);
        *piVar2 = 6;
      }
      else {
        if ((bVar1 & 0x10) != 0) {
          piVar2[2] = uVar7 & 0xf;
          piVar2[1] = *(int *)(pbVar5 + 4);
          *piVar2 = 2;
          break;
        }
        if ((bVar1 & 0x40) != 0) {
          if ((bVar1 & 0x20) == 0) {
            *piVar2 = 9;
            z_00->msg = "invalid literal/length code";
code_r0x1003686b:
            r = -3;
            puVar8 = puVar9;
            goto code_r0x1003682e;
          }
          *piVar2 = 7;
          break;
        }
        piVar2[3] = uVar7;
        pbVar5 = pbVar5 + *(int *)(pbVar5 + 4) * 8;
      }
code_r0x1003663a:
      piVar2[2] = (int)pbVar5;
      break;
    case 2:
      for (; s < (void *)piVar2[2]; s = (void *)((int)s + 8)) {
        if (local_c == 0) goto code_r0x1003687e;
        r = 0;
        local_c = local_c - 1;
        z = (z_streamp)((uint)z | (uint)*local_8 << ((byte)s & 0x1f));
        local_8 = local_8 + 1;
      }
      piVar2[1] = piVar2[1] + (*(uint *)(&DAT_10057020 + piVar2[2] * 4) & (uint)z);
      z = (z_streamp)((uint)z >> ((byte)piVar2[2] & 0x1f));
      s = (void *)((int)s - piVar2[2]);
      piVar2[3] = (uint)*(byte *)((int)piVar2 + 0x11);
      piVar2[2] = piVar2[6];
      *piVar2 = 3;
    case 3:
      for (; s < (void *)piVar2[3]; s = (void *)((int)s + 8)) {
        if (local_c == 0) goto code_r0x1003687e;
        r = 0;
        local_c = local_c - 1;
        z = (z_streamp)((uint)z | (uint)*local_8 << ((byte)s & 0x1f));
        local_8 = local_8 + 1;
      }
      pbVar5 = (byte *)(piVar2[2] + (*(uint *)(&DAT_10057020 + piVar2[3] * 4) & (uint)z) * 8);
      z = (z_streamp)((uint)z >> (pbVar5[1] & 0x1f));
      s = (void *)((int)s - (uint)pbVar5[1]);
      bVar1 = *pbVar5;
      if ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x40) != 0) {
          *piVar2 = 9;
          z_00->msg = "invalid distance code";
          goto code_r0x1003686b;
        }
        piVar2[3] = (uint)bVar1;
        pbVar5 = pbVar5 + *(int *)(pbVar5 + 4) * 8;
        goto code_r0x1003663a;
      }
      piVar2[2] = bVar1 & 0xf;
      piVar2[3] = *(int *)(pbVar5 + 4);
      *piVar2 = 4;
      break;
    case 4:
      for (; s < (void *)piVar2[2]; s = (void *)((int)s + 8)) {
        if (local_c == 0) goto code_r0x1003687e;
        r = 0;
        local_c = local_c - 1;
        z = (z_streamp)((uint)z | (uint)*local_8 << ((byte)s & 0x1f));
        local_8 = local_8 + 1;
      }
      piVar2[3] = piVar2[3] + (*(uint *)(&DAT_10057020 + piVar2[2] * 4) & (uint)z);
      z = (z_streamp)((uint)z >> ((byte)piVar2[2] & 0x1f));
      s = (void *)((int)s - piVar2[2]);
      *piVar2 = 5;
    case 5:
      if ((uint)((int)puVar9 - *(int *)((int)s_00 + 0x28)) < (uint)piVar2[3]) {
        iVar6 = (*(int *)((int)s_00 + 0x2c) - *(int *)((int)s_00 + 0x28)) - piVar2[3];
      }
      else {
        iVar6 = -piVar2[3];
      }
      puStack_18 = puVar9 + iVar6;
      while (piVar2[1] != 0) {
        puVar8 = puVar9;
        if (local_10 == (undefined1 *)0x0) {
          if (puVar9 == *(undefined1 **)((int)s_00 + 0x2c)) {
            local_10 = *(undefined1 **)((int)s_00 + 0x30);
            puVar8 = *(undefined1 **)((int)s_00 + 0x28);
            if (local_10 != puVar8) {
              if (puVar8 < local_10) {
                local_10 = local_10 + (-1 - (int)puVar8);
              }
              else {
                local_10 = *(undefined1 **)((int)s_00 + 0x2c) + -(int)puVar8;
              }
              puVar9 = puVar8;
              if (local_10 != (undefined1 *)0x0) goto code_r0x10036751;
            }
          }
          *(undefined1 **)((int)s_00 + 0x34) = puVar9;
          r = inflate_flush(s_00,z_00,r);
          puVar8 = *(undefined1 **)((int)s_00 + 0x34);
          puVar9 = *(undefined1 **)((int)s_00 + 0x30);
          if (puVar8 < puVar9) {
            local_10 = puVar9 + (-1 - (int)puVar8);
          }
          else {
            local_10 = (undefined1 *)(*(int *)((int)s_00 + 0x2c) - (int)puVar8);
          }
          if ((puVar8 == *(undefined1 **)((int)s_00 + 0x2c)) &&
             (puVar3 = *(undefined1 **)((int)s_00 + 0x28), puVar9 != puVar3)) {
            puVar8 = puVar3;
            if (puVar3 < puVar9) {
              local_10 = puVar9 + (-1 - (int)puVar3);
            }
            else {
              local_10 = *(undefined1 **)((int)s_00 + 0x2c) + -(int)puVar3;
            }
          }
          if (local_10 == (undefined1 *)0x0) goto code_r0x1003682e;
        }
code_r0x10036751:
        r = 0;
        *puVar8 = *puStack_18;
        puVar9 = puVar8 + 1;
        puStack_18 = puStack_18 + 1;
        local_10 = local_10 + -1;
        if (puStack_18 == *(undefined1 **)((int)s_00 + 0x2c)) {
          puStack_18 = *(undefined1 **)((int)s_00 + 0x28);
        }
        piVar2[1] = piVar2[1] + -1;
      }
      *piVar2 = 0;
      break;
    case 6:
      if (local_10 != (undefined1 *)0x0) goto code_r0x10036810;
      if (puVar9 == *(undefined1 **)((int)s_00 + 0x2c)) {
        local_10 = *(undefined1 **)((int)s_00 + 0x30);
        puVar8 = *(undefined1 **)((int)s_00 + 0x28);
        if (local_10 != puVar8) {
          if (puVar8 < local_10) {
            local_10 = local_10 + (-1 - (int)puVar8);
          }
          else {
            local_10 = *(undefined1 **)((int)s_00 + 0x2c) + -(int)puVar8;
          }
          puVar9 = puVar8;
          if (local_10 != (undefined1 *)0x0) goto code_r0x10036810;
        }
      }
      *(undefined1 **)((int)s_00 + 0x34) = puVar9;
      r = inflate_flush(s_00,z_00,r);
      puVar8 = *(undefined1 **)((int)s_00 + 0x34);
      puVar9 = *(undefined1 **)((int)s_00 + 0x30);
      if (puVar8 < puVar9) {
        local_10 = puVar9 + (-1 - (int)puVar8);
      }
      else {
        local_10 = (undefined1 *)(*(int *)((int)s_00 + 0x2c) - (int)puVar8);
      }
      if ((puVar8 == *(undefined1 **)((int)s_00 + 0x2c)) &&
         (puVar3 = *(undefined1 **)((int)s_00 + 0x28), puVar9 != puVar3)) {
        puVar8 = puVar3;
        if (puVar3 < puVar9) {
          local_10 = puVar9 + (-1 - (int)puVar3);
        }
        else {
          local_10 = *(undefined1 **)((int)s_00 + 0x2c) + -(int)puVar3;
        }
      }
      if (local_10 == (undefined1 *)0x0) goto code_r0x1003682e;
code_r0x10036810:
      r = 0;
      *puVar8 = (char)piVar2[2];
      puVar9 = puVar8 + 1;
      local_10 = local_10 + -1;
      *piVar2 = 0;
      break;
    case 7:
      if ((void *)0x7 < s) {
        s = (void *)((int)s + -8);
        local_c = local_c + 1;
        local_8 = local_8 + -1;
      }
      *(undefined1 **)((int)s_00 + 0x34) = puVar9;
      r = inflate_flush(s_00,z_00,r);
      puVar9 = *(undefined1 **)((int)s_00 + 0x34);
      if (*(undefined1 **)((int)s_00 + 0x30) == puVar9) {
        *piVar2 = 8;
code_r0x100368ea:
        r = 1;
        puVar8 = puVar9;
code_r0x1003682e:
        *(z_streamp *)((int)s_00 + 0x20) = z;
        *(void **)((int)s_00 + 0x1c) = s;
        z_00->avail_in = local_c;
        puVar9 = puVar8;
code_r0x10036840:
        pBVar4 = z_00->next_in;
        z_00->next_in = local_8;
        z_00->total_in = (uLong)(local_8 + (z_00->total_in - (int)pBVar4));
      }
      else {
        *(z_streamp *)((int)s_00 + 0x20) = z;
        *(void **)((int)s_00 + 0x1c) = s;
        z_00->avail_in = local_c;
        pBVar4 = z_00->next_in;
        z_00->next_in = local_8;
        z_00->total_in = (uLong)(local_8 + (z_00->total_in - (int)pBVar4));
      }
      *(undefined1 **)((int)s_00 + 0x34) = puVar9;
      iVar6 = inflate_flush(s_00,z_00,r);
      return iVar6;
    case 8:
      goto code_r0x100368ea;
    case 9:
      goto code_r0x1003686b;
    default:
      r = -2;
      goto code_r0x1003682e;
    }
  } while( true );
code_r0x1003687e:
  *(z_streamp *)((int)s_00 + 0x20) = z;
  *(void **)((int)s_00 + 0x1c) = s;
  z_00->avail_in = 0;
  goto code_r0x10036840;
}



