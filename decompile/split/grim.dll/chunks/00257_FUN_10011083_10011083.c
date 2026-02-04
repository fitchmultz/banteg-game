/* FUN_10011083 @ 10011083 */

/* [binja] int32_t __thiscall sub_10011083(int32_t* arg1, void* arg2, int32_t arg3) */

int __thiscall FUN_10011083(void *this,int *arg1,void *arg2,int arg3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  int *piVar7;
  byte bVar8;
  uint uVar9;
  void *pvVar10;
  uint uVar11;
  undefined4 *puVar12;
  void *pvVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  uint *puVar19;
  bool bVar20;
  bool bVar21;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_10;
  uint *local_8;
  
  piVar7 = arg1;
  if (arg2 < (void *)0x12) {
    return -0x7fffbffb;
  }
  if (((((*(byte *)((int)arg1 + 1) & 0xfe) != 0) ||
       (bVar4 = *(byte *)((int)arg1 + 2), (bVar4 & 0xf4) != 0)) || ((short)arg1[3] == 0)) ||
     (*(short *)((int)arg1 + 0xe) == 0)) {
    return -0x7fffbffb;
  }
  uVar9 = (uint)*(byte *)((int)arg1 + 7);
  local_18 = 0;
  if (*(byte *)((int)arg1 + 1) != 0) {
    if (uVar9 == 0xf) {
      local_18 = 0x18;
    }
    else if (uVar9 == 0x10) {
      local_18 = 0x19;
    }
    else if (uVar9 == 0x18) {
      local_18 = 0x14;
    }
    else {
      if (uVar9 != 0x20) {
        return -0x7fffbffb;
      }
      local_18 = 0x15;
    }
  }
  uVar15 = (uint)*(byte *)(arg1 + 4);
  pvVar10 = (void *)(uVar15 + 7 >> 3);
  bVar8 = bVar4 & 3;
  if (bVar8 == 1) {
    if (*(char *)((int)arg1 + 1) == '\0') {
      return -0x7fffbffb;
    }
    if ((char)arg1[4] != '\b') {
      return -0x7fffbffb;
    }
    local_10 = 0x29;
  }
  else if (bVar8 == 2) {
    if (uVar15 == 0xf) {
      local_10 = 0x18;
    }
    else if (uVar15 == 0x10) {
      local_10 = 0x19;
    }
    else if (uVar15 == 0x18) {
      local_10 = 0x14;
    }
    else {
      if (uVar15 != 0x20) {
        return -0x7fffbffb;
      }
      local_10 = 0x15;
    }
  }
  else {
    if (bVar8 != 3) {
      return -0x7fffbffb;
    }
    if ((char)arg1[4] != '\b') {
      return -0x7fffbffb;
    }
    local_10 = 0x32;
  }
  bVar20 = (*(byte *)((int)arg1 + 0x11) & 0x20) != 0x20;
  bVar21 = (*(byte *)((int)arg1 + 0x11) & 0x10) == 0x10;
  uVar11 = (uint)(byte)*arg1;
  if ((int)arg2 - 0x12U < uVar11) {
    return -0x7fffbffb;
  }
  uVar3 = ((int)arg2 - 0x12U) - uVar11;
  local_8 = (uint *)(uVar11 + 0x12 + (int)arg1);
  uVar9 = (uint)*(ushort *)((int)arg1 + 5) * (uVar9 + 7 >> 3);
  if (uVar3 < uVar9) {
    return -0x7fffbffb;
  }
  if ((*(int *)((int)this + 0x40) != 0) && (local_10 == 0x29)) {
    if (0x100 < (uint)*(ushort *)((int)arg1 + 3) + (uint)*(ushort *)((int)arg1 + 5)) {
      return -0x7fffbffb;
    }
    puVar12 = operator_new(0x400);
    *(undefined4 **)((int)this + 8) = puVar12;
    if (puVar12 == (undefined4 *)0x0) {
      return -0x7ff8fff2;
    }
    *(undefined4 *)((int)this + 0x3c) = 1;
    for (iVar16 = 0x100; iVar16 != 0; iVar16 = iVar16 + -1) {
      *puVar12 = 0xffffffff;
      puVar12 = puVar12 + 1;
    }
    puVar1 = (undefined1 *)(*(int *)((int)this + 8) + (uint)*(ushort *)((int)arg1 + 3) * 4);
    puVar2 = puVar1 + (uint)*(ushort *)((int)arg1 + 5) * 4;
    uVar11 = uVar3;
    uVar17 = uVar3;
    arg1 = (int *)local_8;
    for (; puVar1 < puVar2; puVar1 = puVar1 + 4) {
      if (local_18 == 0x14) {
        uVar11 = (uint)*(byte *)((int)arg1 + 2);
        uVar17 = (uint)*(byte *)((int)arg1 + 1);
        local_1c = (uint)(byte)*arg1;
        arg1 = (int *)((int)arg1 + 3);
LAB_10011360:
        local_20 = 0xff;
      }
      else if (local_18 == 0x15) {
        uVar6 = *arg1;
        local_20 = uVar6 >> 0x18;
        uVar17 = uVar6 >> 8 & 0xff;
        uVar11 = uVar6 >> 0x10 & 0xff;
        local_1c = uVar6 & 0xff;
        arg1 = (int *)((uint *)arg1 + 1);
      }
      else {
        if (local_18 == 0x18) {
          uVar5 = (ushort)*arg1;
          uVar11 = uVar5 >> 10 & 0x1f;
          uVar17 = uVar5 >> 5 & 0x1f;
          uVar11 = uVar11 >> 2 | uVar11 << 3;
          uVar17 = uVar17 >> 2 | uVar17 << 3;
          local_1c = (uVar5 & 0x1f) >> 2 | (uVar5 & 0x1f) << 3;
          arg1 = (int *)((int)arg1 + 2);
          goto LAB_10011360;
        }
        if (local_18 == 0x19) {
          uVar5 = (ushort)*arg1;
          local_20 = (uint)(uVar5 >> 0xf) * 0xff;
          uVar11 = uVar5 >> 10 & 0x1f;
          uVar17 = uVar5 >> 5 & 0x1f;
          uVar11 = uVar11 >> 2 | uVar11 << 3;
          uVar17 = uVar17 >> 2 | uVar17 << 3;
          local_1c = (uVar5 & 0x1f) >> 2 | (uVar5 & 0x1f) << 3;
          arg1 = (int *)((int)arg1 + 2);
        }
      }
      puVar1[2] = (char)local_1c;
      puVar1[3] = (undefined1)local_20;
      *puVar1 = (char)uVar11;
      puVar1[1] = (char)uVar17;
    }
  }
  arg2 = (void *)(uVar3 - uVar9);
  local_8 = (uint *)((int)local_8 + uVar9);
  pvVar13 = (void *)((uint)*(ushort *)((int)piVar7 + 0xe) * (uint)*(ushort *)(piVar7 + 3) *
                    (int)pvVar10);
  *(int *)this = local_10;
  *(uint **)((int)this + 4) = local_8;
  *(uint *)((int)this + 0x30) = (uint)*(ushort *)(piVar7 + 3) * (int)pvVar10;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(uint *)((int)this + 0xc) = (uint)*(ushort *)(piVar7 + 3);
  *(uint *)((int)this + 0x10) = (uint)*(ushort *)((int)piVar7 + 0xe);
  *(undefined4 *)((int)this + 0x14) = 1;
  if (*(int *)((int)this + 0x40) != 0) {
    if ((((bVar4 & 8) != 0) || (bVar20)) || (bVar21)) {
      piVar14 = operator_new((uint)pvVar13);
      *(int **)((int)this + 4) = piVar14;
      if (piVar14 == (int *)0x0) {
        return -0x7ff8fff2;
      }
      *(undefined4 *)((int)this + 0x38) = 1;
      if (bVar20) {
        piVar14 = (int *)((*(ushort *)((int)piVar7 + 0xe) - 1) * *(int *)((int)this + 0x30) +
                         (int)piVar14);
      }
      local_18 = 0;
      if (*(short *)((int)piVar7 + 0xe) != 0) {
        do {
          arg1 = piVar14;
          if (bVar21) {
            arg1 = (int *)((*(int *)((int)this + 0x30) - (int)pvVar10) + (int)piVar14);
          }
          uVar9 = (uint)*(ushort *)(piVar7 + 3);
          local_1c = 0;
          if (uVar9 != 0) {
            do {
              if ((bVar4 & 8) == 0) {
                local_20 = 0;
              }
              else {
                if (arg2 == (void *)0x0) {
                  return -0x7fffbffb;
                }
                local_20 = (byte)*local_8 & 0x80;
                uVar9 = ((byte)*local_8 & 0x7f) + 1;
                local_8 = (uint *)((int)local_8 + 1);
                arg2 = (void *)((int)arg2 + -1);
              }
              local_1c = local_1c + uVar9;
              while (uVar9 != 0) {
                uVar9 = uVar9 - 1;
                if (arg2 < pvVar10) {
                  return -0x7fffbffb;
                }
                puVar18 = local_8;
                puVar19 = (uint *)arg1;
                for (uVar11 = uVar15 + 7 >> 5; uVar11 != 0; uVar11 = uVar11 - 1) {
                  *puVar19 = *puVar18;
                  puVar18 = puVar18 + 1;
                  puVar19 = puVar19 + 1;
                }
                for (uVar11 = (uint)pvVar10 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
                  *(byte *)puVar19 = (byte)*puVar18;
                  puVar18 = (uint *)((int)puVar18 + 1);
                  puVar19 = (uint *)((int)puVar19 + 1);
                }
                if (local_20 == 0) {
                  local_8 = (uint *)((int)local_8 + (int)pvVar10);
                  arg2 = (void *)((int)arg2 - (int)pvVar10);
                }
                pvVar13 = pvVar10;
                if (bVar21) {
                  pvVar13 = (void *)-(int)pvVar10;
                }
                arg1 = (int *)((int)arg1 + (int)pvVar13);
              }
              if (local_20 != 0) {
                local_8 = (uint *)((int)local_8 + (int)pvVar10);
                arg2 = (void *)((int)arg2 - (int)pvVar10);
              }
              uVar9 = (uint)*(ushort *)(piVar7 + 3);
            } while (local_1c < uVar9);
          }
          if (bVar20) {
            iVar16 = -*(int *)((int)this + 0x30);
          }
          else {
            iVar16 = *(int *)((int)this + 0x30);
          }
          piVar14 = (int *)((int)piVar14 + iVar16);
          local_18 = local_18 + 1;
        } while (local_18 < *(ushort *)((int)piVar7 + 0xe));
      }
    }
    else {
      if (arg2 < pvVar13) {
        return -0x7fffbffb;
      }
      *(uint **)((int)this + 4) = local_8;
      *(undefined4 *)((int)this + 0x38) = 0;
    }
  }
  return 0;
}



