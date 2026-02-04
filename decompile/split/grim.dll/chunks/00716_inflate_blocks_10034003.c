/* inflate_blocks @ 10034003 */

/* zlib (internal): process inflate blocks */

int __cdecl inflate_blocks(void *s,z_streamp z,int r)

{
  int *piVar1;
  byte bVar2;
  byte *pbVar3;
  Bytef *pBVar4;
  void *s_00;
  int iVar5;
  uint uVar6;
  voidpf pvVar7;
  byte *pbVar8;
  undefined4 uVar9;
  void *pvVar10;
  byte *pbVar11;
  void *pvStack_38;
  void *pvStack_34;
  byte *pbStack_30;
  uInt uStack_2c;
  uInt uStack_28;
  void *pvStack_24;
  void *pvStack_20;
  byte *pbStack_1c;
  byte *local_18;
  byte *local_14;
  byte *local_10;
  byte *local_c;
  uint local_8;
  
  s_00 = s;
  local_c = (byte *)z->avail_in;
  local_8 = *(uint *)((int)s + 0x20);
  local_10 = *(byte **)((int)s + 0x34);
  if (local_10 < *(byte **)((int)s + 0x30)) {
    local_14 = *(byte **)((int)s + 0x30) + (-1 - (int)local_10);
  }
  else {
    local_14 = (byte *)(*(int *)((int)s + 0x2c) - (int)local_10);
  }
  uVar6 = *(uint *)s;
  s = *(void **)((int)s + 0x1c);
  pbVar11 = z->next_in;
  while (local_18 = pbVar11, uVar6 < 10) {
    switch(*(undefined4 *)(&DAT_10034776 + uVar6 * 4)) {
    case 0x100340aa:
      for (; pbVar11 = local_18, s < (void *)0x3; s = (void *)((int)s + 8)) {
        if (local_c == (byte *)0x0) goto code_r0x100346a3;
        r = 0;
        local_c = local_c + -1;
        local_8 = local_8 | (uint)*local_18 << ((byte)s & 0x1f);
        local_18 = local_18 + 1;
      }
      uVar6 = (local_8 & 7) >> 1;
      *(uint *)((int)s_00 + 0x18) = local_8 & 1;
      if (uVar6 == 0) {
        uVar6 = (int)s - 3U & 7;
        local_8 = (local_8 >> 3) >> (sbyte)uVar6;
        s = (void *)(((int)s - 3U) - uVar6);
        *(undefined4 *)s_00 = 1;
      }
      else if (uVar6 == 1) {
        func_0x10036e31(&uStack_2c,&uStack_28,&pvStack_24,&pvStack_20,z);
        pvVar10 = inflate_codes_new(uStack_2c,uStack_28,pvStack_24,pvStack_20,z);
        *(void **)((int)s_00 + 4) = pvVar10;
        if (pvVar10 == (void *)0x0) goto code_r0x10034717;
        local_8 = local_8 >> 3;
        s = (void *)((int)s + -3);
        *(undefined4 *)s_00 = 6;
      }
      else {
        if (uVar6 == 2) {
          local_8 = local_8 >> 3;
          uVar6 = 3;
          s = (void *)((int)s + -3);
          goto code_r0x10034105;
        }
        if (uVar6 == 3) {
          *(undefined4 *)s_00 = 9;
          z->msg = "invalid block type";
          *(uint *)((int)s_00 + 0x20) = local_8 >> 3;
          s = (void *)((int)s + -3);
          r = -3;
          goto code_r0x10034055;
        }
      }
      break;
    case 0x10034174:
      for (; pbVar11 = local_18, s < (void *)0x20; s = (void *)((int)s + 8)) {
        if (local_c == (byte *)0x0) goto code_r0x100346a3;
        r = 0;
        local_c = local_c + -1;
        local_8 = local_8 | (uint)*local_18 << ((byte)s & 0x1f);
        local_18 = local_18 + 1;
      }
      if (~local_8 >> 0x10 != (local_8 & 0xffff)) {
        *(undefined4 *)s_00 = 9;
        z->msg = "invalid stored block lengths";
        goto code_r0x1003465b;
      }
      *(uint *)((int)s_00 + 4) = local_8 & 0xffff;
      s = (void *)0x0;
      local_8 = 0;
      if (*(int *)((int)s_00 + 4) == 0) goto code_r0x100342b6;
      uVar6 = 2;
code_r0x10034105:
      *(uint *)s_00 = uVar6;
      break;
    case 0x100341d5:
      if (local_c == (byte *)0x0) {
code_r0x100346a3:
        *(uint *)((int)s_00 + 0x20) = local_8;
        *(void **)((int)s_00 + 0x1c) = s;
        z->avail_in = 0;
        goto code_r0x1003405e;
      }
      if (local_14 == (byte *)0x0) {
        local_14 = (byte *)0x0;
        if (local_10 == *(byte **)((int)s_00 + 0x2c)) {
          pbVar8 = *(byte **)((int)s_00 + 0x30);
          pbVar3 = *(byte **)((int)s_00 + 0x28);
          if (pbVar3 != pbVar8) {
            if (pbVar3 < pbVar8) {
              local_14 = pbVar8 + (-1 - (int)pbVar3);
            }
            else {
              local_14 = *(byte **)((int)s_00 + 0x2c) + -(int)pbVar3;
            }
            local_10 = pbVar3;
            if (local_14 != (byte *)0x0) goto code_r0x10034276;
          }
        }
        *(byte **)((int)s_00 + 0x34) = local_10;
        r = inflate_flush(s_00,z,r);
        pbStack_1c = *(byte **)((int)s_00 + 0x30);
        local_10 = *(byte **)((int)s_00 + 0x34);
        if (local_10 < pbStack_1c) {
          local_14 = pbStack_1c + (-1 - (int)local_10);
        }
        else {
          local_14 = (byte *)(*(int *)((int)s_00 + 0x2c) - (int)local_10);
        }
        pbStack_30 = *(byte **)((int)s_00 + 0x2c);
        if (local_10 == pbStack_30) {
          pbVar8 = *(byte **)((int)s_00 + 0x28);
          if (pbVar8 != pbStack_1c) {
            local_10 = pbVar8;
            if (pbVar8 < pbStack_1c) {
              local_14 = pbStack_1c + (-1 - (int)pbVar8);
            }
            else {
              local_14 = pbStack_30 + -(int)pbVar8;
            }
          }
        }
        if (local_14 == (byte *)0x0) {
          *(uint *)((int)s_00 + 0x20) = local_8;
          *(void **)((int)s_00 + 0x1c) = s;
          z->avail_in = (uInt)local_c;
          z->total_in = (uLong)(pbVar11 + (z->total_in - (int)z->next_in));
          goto code_r0x10034068;
        }
      }
code_r0x10034276:
      r = 0;
      pbVar11 = *(byte **)((int)s_00 + 4);
      if (local_c < *(byte **)((int)s_00 + 4)) {
        pbVar11 = local_c;
      }
      if (local_14 < pbVar11) {
        pbVar11 = local_14;
      }
      pbVar8 = local_18 + (int)pbVar11;
      local_c = local_c + -(int)pbVar11;
      pbVar3 = local_10 + (int)pbVar11;
      local_14 = local_14 + -(int)pbVar11;
      for (uVar6 = (uint)pbVar11 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)local_10 = *(undefined4 *)local_18;
        local_18 = local_18 + 4;
        local_10 = local_10 + 4;
      }
      for (uVar6 = (uint)pbVar11 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *local_10 = *local_18;
        local_18 = local_18 + 1;
        local_10 = local_10 + 1;
      }
      piVar1 = (int *)((int)s_00 + 4);
      *piVar1 = *piVar1 - (int)pbVar11;
      local_18 = pbVar8;
      local_10 = pbVar3;
      if (*piVar1 == 0) {
code_r0x100342b6:
        uVar6 = -(uint)(*(int *)((int)s_00 + 0x18) != 0) & 7;
        goto code_r0x10034105;
      }
      break;
    case 0x100342c5:
      for (; s < (void *)0xe; s = (void *)((int)s + 8)) {
        if (local_c == (byte *)0x0) goto code_r0x100346a3;
        r = 0;
        local_c = local_c + -1;
        local_8 = local_8 | (uint)*pbVar11 << ((byte)s & 0x1f);
        pbVar11 = pbVar11 + 1;
      }
      *(uint *)((int)s_00 + 4) = local_8 & 0x3fff;
      if ((0x1d < (local_8 & 0x1f)) || (uVar6 = (local_8 & 0x3fff) >> 5 & 0x1f, 0x1d < uVar6)) {
        *(undefined4 *)s_00 = 9;
        z->msg = "too many length or distance symbols";
        goto code_r0x1003465b;
      }
      pvVar7 = (*z->zalloc)(z->opaque,uVar6 + 0x102 + (local_8 & 0x1f),4);
      *(voidpf *)((int)s_00 + 0xc) = pvVar7;
      if (pvVar7 != (voidpf)0x0) {
        local_8 = local_8 >> 0xe;
        s = (void *)((int)s + -0xe);
        *(undefined4 *)((int)s_00 + 8) = 0;
        *(undefined4 *)s_00 = 4;
        goto code_r0x10034394;
      }
code_r0x10034717:
      r = (int)(byte *)0xfffffffc;
      goto code_r0x1003404c;
    case 0x10034394:
code_r0x10034394:
      while (*(uint *)((int)s_00 + 8) < (*(uint *)((int)s_00 + 4) >> 10) + 4) {
        for (; s < (void *)0x3; s = (void *)((int)s + 8)) {
          if (local_c == (byte *)0x0) goto code_r0x100346a3;
          r = 0;
          local_c = local_c + -1;
          local_8 = local_8 | (uint)*pbVar11 << ((byte)s & 0x1f);
          pbVar11 = pbVar11 + 1;
        }
        *(uint *)(*(int *)((int)s_00 + 0xc) +
                 *(int *)(&UNK_1004f6e0 + *(int *)((int)s_00 + 8) * 4) * 4) = local_8 & 7;
        *(int *)((int)s_00 + 8) = *(int *)((int)s_00 + 8) + 1;
        s = (void *)((int)s + -3);
        local_8 = local_8 >> 3;
      }
      while (*(uint *)((int)s_00 + 8) < 0x13) {
        *(undefined4 *)
         (*(int *)((int)s_00 + 0xc) + *(int *)(&UNK_1004f6e0 + *(int *)((int)s_00 + 8) * 4) * 4) = 0
        ;
        *(int *)((int)s_00 + 8) = *(int *)((int)s_00 + 8) + 1;
      }
      *(uInt *)((int)s_00 + 0x10) = 7;
      local_14 = (byte *)inflate_trees_bits(*(uInt **)((int)s_00 + 0xc),(uInt *)((int)s_00 + 0x10),
                                            (void **)((int)s_00 + 0x14),*(void **)((int)s_00 + 0x24)
                                            ,z);
      if (local_14 == (byte *)0x0) {
        *(undefined4 *)((int)s_00 + 8) = 0;
        *(undefined4 *)s_00 = 5;
        goto code_r0x10034512;
      }
      (*z->zfree)(z->opaque,*(voidpf *)((int)s_00 + 0xc));
      goto code_r0x10034707;
    case 0x10034512:
code_r0x10034512:
      while (*(uint *)((int)s_00 + 8) <
             (*(uint *)((int)s_00 + 4) >> 5 & 0x1f) + 0x102 + (*(uint *)((int)s_00 + 4) & 0x1f)) {
        for (; s < *(void **)((int)s_00 + 0x10); s = (void *)((int)s + 8)) {
          if (local_c == (byte *)0x0) goto code_r0x100346a3;
          r = 0;
          local_c = local_c + -1;
          local_8 = local_8 | (uint)*pbVar11 << ((byte)s & 0x1f);
          pbVar11 = pbVar11 + 1;
        }
        iVar5 = *(int *)((int)s_00 + 0x14) +
                (*(uint *)(&DAT_10057020 + (int)*(void **)((int)s_00 + 0x10) * 4) & local_8) * 8;
        bVar2 = *(byte *)(iVar5 + 1);
        local_14 = (byte *)(uint)bVar2;
        pbStack_30 = *(byte **)(iVar5 + 4);
        if (pbStack_30 < (byte *)0x10) {
          local_8 = local_8 >> (bVar2 & 0x1f);
          s = (void *)((int)s - (int)local_14);
          *(byte **)(*(int *)((int)s_00 + 0xc) + *(int *)((int)s_00 + 8) * 4) = pbStack_30;
          *(int *)((int)s_00 + 8) = *(int *)((int)s_00 + 8) + 1;
        }
        else {
          if (pbStack_30 == (byte *)0x12) {
            pbVar8 = (byte *)0x7;
          }
          else {
            pbVar8 = pbStack_30 + -0xe;
          }
          local_18 = (byte *)((uint)(pbStack_30 == (byte *)0x12) * 8 + 3);
          for (; s < pbVar8 + (int)local_14; s = (void *)((int)s + 8)) {
            if (local_c == (byte *)0x0) goto code_r0x100346a3;
            r = 0;
            local_c = local_c + -1;
            local_8 = local_8 | (uint)*pbVar11 << ((byte)s & 0x1f);
            pbVar11 = pbVar11 + 1;
          }
          local_8 = local_8 >> (bVar2 & 0x1f);
          local_18 = local_18 + (*(uint *)(&DAT_10057020 + (int)pbVar8 * 4) & local_8);
          local_8 = local_8 >> ((byte)pbVar8 & 0x1f);
          s = (void *)((int)s - (int)(pbVar8 + (int)local_14));
          iVar5 = *(int *)((int)s_00 + 8);
          if ((byte *)((*(uint *)((int)s_00 + 4) >> 5 & 0x1f) + 0x102 +
                      (*(uint *)((int)s_00 + 4) & 0x1f)) < local_18 + iVar5) {
code_r0x100346bb:
            (*z->zfree)(z->opaque,*(voidpf *)((int)s_00 + 0xc));
            *(undefined4 *)s_00 = 9;
            z->msg = "invalid bit length repeat";
            *(uint *)((int)s_00 + 0x20) = local_8;
            *(void **)((int)s_00 + 0x1c) = s;
            z->avail_in = (uInt)local_c;
            z->total_in = (uLong)(pbVar11 + (z->total_in - (int)z->next_in));
            z->next_in = pbVar11;
            *(byte **)((int)s_00 + 0x34) = local_10;
            iVar5 = inflate_flush(s_00,z,-3);
            return iVar5;
          }
          if (pbStack_30 == (byte *)0x10) {
            if (iVar5 == 0) goto code_r0x100346bb;
            uVar9 = *(undefined4 *)(*(int *)((int)s_00 + 0xc) + -4 + iVar5 * 4);
          }
          else {
            uVar9 = 0;
          }
          do {
            *(undefined4 *)(*(int *)((int)s_00 + 0xc) + iVar5 * 4) = uVar9;
            iVar5 = iVar5 + 1;
            local_18 = local_18 + -1;
          } while (local_18 != (byte *)0x0);
          *(int *)((int)s_00 + 8) = iVar5;
          local_18 = (byte *)0x0;
        }
      }
      *(undefined4 *)((int)s_00 + 0x14) = 0;
      pbStack_1c = (byte *)0x9;
      local_18 = (byte *)0x6;
      local_14 = (byte *)inflate_trees_dynamic
                                   ((*(uint *)((int)s_00 + 4) & 0x1f) + 0x101,
                                    (*(uint *)((int)s_00 + 4) >> 5 & 0x1f) + 1,
                                    *(uInt **)((int)s_00 + 0xc),(uInt *)&pbStack_1c,
                                    (uInt *)&local_18,&pvStack_38,&pvStack_34,
                                    *(void **)((int)s_00 + 0x24),z);
      (*z->zfree)(z->opaque,*(voidpf *)((int)s_00 + 0xc));
      if (local_14 == (byte *)0x0) {
        pvVar10 = inflate_codes_new((uInt)pbStack_1c,(uInt)local_18,pvStack_38,pvStack_34,z);
        if (pvVar10 == (void *)0x0) goto code_r0x10034717;
        *(void **)((int)s_00 + 4) = pvVar10;
        *(undefined4 *)s_00 = 6;
        goto code_r0x100345b3;
      }
code_r0x10034707:
      r = (int)local_14;
      if (local_14 == (byte *)0xfffffffd) {
        *(undefined4 *)s_00 = 9;
      }
      goto code_r0x1003404c;
    case 0x100345b3:
code_r0x100345b3:
      *(uint *)((int)s_00 + 0x20) = local_8;
      *(void **)((int)s_00 + 0x1c) = s;
      z->avail_in = (uInt)local_c;
      z->total_in = (uLong)(pbVar11 + (z->total_in - (int)z->next_in));
      z->next_in = pbVar11;
      *(byte **)((int)s_00 + 0x34) = local_10;
      r = inflate_codes(s_00,z,r);
      if ((byte *)r != (byte *)0x1) goto code_r0x1003406d;
      r = 0;
      inflate_codes_free(*(void **)((int)s_00 + 4),z);
      local_c = (byte *)z->avail_in;
      local_18 = z->next_in;
      local_8 = *(uint *)((int)s_00 + 0x20);
      s = *(void **)((int)s_00 + 0x1c);
      local_10 = *(byte **)((int)s_00 + 0x34);
      if (local_10 < *(byte **)((int)s_00 + 0x30)) {
        local_14 = *(byte **)((int)s_00 + 0x30) + (-1 - (int)local_10);
      }
      else {
        local_14 = (byte *)(*(int *)((int)s_00 + 0x2c) - (int)local_10);
      }
      if (*(int *)((int)s_00 + 0x18) != 0) {
        *(undefined4 *)s_00 = 7;
        goto code_r0x10034724;
      }
      *(undefined4 *)s_00 = 0;
      break;
    case 0x1003465b:
code_r0x1003465b:
      r = (int)(byte *)0xfffffffd;
      goto code_r0x1003404c;
    case 0x10034724:
code_r0x10034724:
      pbVar11 = local_18;
      *(byte **)((int)s_00 + 0x34) = local_10;
      r = inflate_flush(s_00,z,r);
      local_10 = *(byte **)((int)s_00 + 0x34);
      if (*(byte **)((int)s_00 + 0x30) == local_10) {
        *(undefined4 *)s_00 = 8;
        goto code_r0x1003476f;
      }
      *(uint *)((int)s_00 + 0x20) = local_8;
      *(void **)((int)s_00 + 0x1c) = s;
      z->avail_in = (uInt)local_c;
      pBVar4 = z->next_in;
      z->next_in = pbVar11;
      z->total_in = (uLong)(pbVar11 + (z->total_in - (int)pBVar4));
      *(byte **)((int)s_00 + 0x34) = local_10;
      goto code_r0x1003406d;
    case 0x1003476f:
code_r0x1003476f:
      r = (int)(byte *)0x1;
      goto code_r0x1003404c;
    }
    pbVar11 = local_18;
    uVar6 = *(uint *)s_00;
  }
  r = (int)(byte *)0xfffffffe;
code_r0x1003404c:
  *(uint *)((int)s_00 + 0x20) = local_8;
code_r0x10034055:
  *(void **)((int)s_00 + 0x1c) = s;
  z->avail_in = (uInt)local_c;
code_r0x1003405e:
  z->total_in = (uLong)(pbVar11 + (z->total_in - (int)z->next_in));
code_r0x10034068:
  z->next_in = pbVar11;
  *(byte **)((int)s_00 + 0x34) = local_10;
code_r0x1003406d:
  iVar5 = inflate_flush(s_00,z,r);
  return iVar5;
}



