/* FUN_100103d6 @ 100103d6 */

/* [binja] int32_t __thiscall sub_100103d6(int32_t* arg1, void* arg2, void* arg3) */

int __thiscall FUN_100103d6(void *this,int *arg1,void *arg2,void *arg3)

{
  void *pvVar1;
  byte bVar2;
  ushort uVar3;
  int *piVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  void *pvVar9;
  undefined1 *puVar10;
  int *piVar11;
  uint uVar12;
  byte *pbVar13;
  byte *pbVar14;
  int iVar15;
  uint uVar16;
  int *piVar17;
  byte *pbVar18;
  byte *pbVar19;
  int *piVar20;
  byte *pbVar21;
  byte *pbVar22;
  byte *pbVar23;
  byte *pbVar24;
  int local_1c;
  byte *local_14;
  
  piVar17 = arg1;
  if (arg2 < (void *)0x28) {
    return -0x7fffbffb;
  }
  uVar12 = *arg1;
  if (uVar12 < 0x28) {
    return -0x7fffbffb;
  }
  piVar4 = (int *)arg1[1];
  iVar6 = arg1[2];
  if (iVar6 < 1) {
    iVar6 = -iVar6;
  }
  uVar3 = *(ushort *)((int)arg1 + 0xe);
  iVar7 = arg1[8];
  if ((uVar3 < 9) && (iVar7 == 0)) {
    iVar7 = 1 << ((byte)uVar3 & 0x1f);
  }
  pvVar1 = (void *)(uVar12 + iVar7 * 4);
  if (arg2 < pvVar1) {
    return -0x7fffbffb;
  }
  if ((short)arg1[3] != 1) {
    return -0x7fffbffb;
  }
  if (((arg1[2] < 0) && (arg1[4] != 0)) && (arg1[4] != 3)) {
    return -0x7fffbffb;
  }
  if ((uint)arg1[4] < 3) {
    arg1 = (int *)(uint)uVar3;
    if (((arg1 == (int *)0x1) || (arg1 == (int *)0x4)) || (arg1 == (int *)0x8)) {
      arg2 = (void *)0x29;
      goto LAB_100106ec;
    }
    if (arg1 == (int *)0x10) goto LAB_100106dc;
    if (arg1 == (int *)0x18) goto LAB_1001058c;
    if (arg1 != (int *)0x20) {
      return -0x7fffbffb;
    }
  }
  else {
    if (arg1[4] != 3) {
      return -0x7fffbfff;
    }
    if (uVar12 < 0x6c) {
      arg2 = (void *)0x0;
      piVar20 = (int *)(uVar12 + (int)arg1);
      iVar7 = piVar20[2];
      iVar15 = piVar20[1];
      iVar8 = *piVar20;
    }
    else {
      arg2 = (void *)arg1[0xd];
      iVar7 = arg1[0xc];
      iVar15 = arg1[0xb];
      iVar8 = arg1[10];
    }
    arg1 = (int *)(uint)*(ushort *)((int)arg1 + 0xe);
    if (arg1 == (int *)0x10) {
      if (iVar7 == 0xff) {
        if (iVar15 != 0xff) {
          return -0x7fffbffb;
        }
        if (iVar8 != 0xff) {
          return -0x7fffbffb;
        }
        if (arg2 != (void *)0xff00) {
          return -0x7fffbffb;
        }
        arg2 = (void *)0x33;
        goto LAB_100106ec;
      }
      if (iVar7 != 0x1f) {
        if (iVar7 == 0xf) {
          if (iVar15 != 0xf0) {
            return -0x7fffbffb;
          }
          if (iVar8 != 0xf00) {
            return -0x7fffbffb;
          }
          if (arg2 == (void *)0xf000) {
            arg2 = (void *)0x1a;
          }
          else {
            if (arg2 != (void *)0x0) {
              return -0x7fffbffb;
            }
            arg2 = (void *)0x1e;
          }
        }
        else {
          if (iVar7 != 3) {
            return -0x7fffbffb;
          }
          if (iVar15 != 0x1c) {
            return -0x7fffbffb;
          }
          if (iVar8 != 0xe0) {
            return -0x7fffbffb;
          }
          if (arg2 != (void *)0xff00) {
            return -0x7fffbffb;
          }
          arg2 = (void *)0x1d;
        }
        goto LAB_100106ec;
      }
      if (iVar15 == 0x7e0) {
        if (iVar8 != 0xf800) {
          return -0x7fffbffb;
        }
        if (arg2 != (void *)0x0) {
          return -0x7fffbffb;
        }
        arg2 = (void *)0x17;
        goto LAB_100106ec;
      }
      if (iVar15 != 0x3e0) {
        return -0x7fffbffb;
      }
      if (iVar8 != 0x7c00) {
        return -0x7fffbffb;
      }
      if (arg2 != (void *)0x0) {
        if (arg2 != (void *)0x8000) {
          return -0x7fffbffb;
        }
        arg2 = (void *)0x19;
        goto LAB_100106ec;
      }
LAB_100106dc:
      arg2 = (void *)0x18;
      goto LAB_100106ec;
    }
    if (arg1 == (int *)0x18) {
      if (iVar7 != 0xff) {
        return -0x7fffbffb;
      }
      if (iVar15 != 0xff00) {
        return -0x7fffbffb;
      }
      if (iVar8 != 0xff0000) {
        return -0x7fffbffb;
      }
      if (arg2 != (void *)0x0) {
        return -0x7fffbffb;
      }
LAB_1001058c:
      arg2 = (void *)0x14;
      goto LAB_100106ec;
    }
    if (arg1 != (int *)0x20) {
      return -0x7fffbffb;
    }
    if (iVar7 != 0xff) {
      if (iVar7 == 0x3ff00000) {
        if (iVar15 != 0xffc00) {
          return -0x7fffbffb;
        }
        if (iVar8 != 0x3ff) {
          return -0x7fffbffb;
        }
        if (arg2 != (void *)0xc0000000) {
          return -0x7fffbffb;
        }
        arg2 = (void *)0x1f;
      }
      else {
        if (iVar7 != 0) {
          return -0x7fffbffb;
        }
        if (iVar15 != -0x10000) {
          return -0x7fffbffb;
        }
        if (iVar8 != 0xffff) {
          return -0x7fffbffb;
        }
        if (arg2 != (void *)0x0) {
          return -0x7fffbffb;
        }
        arg2 = (void *)0x22;
      }
      goto LAB_100106ec;
    }
    if (iVar15 != 0xff00) {
      return -0x7fffbffb;
    }
    if (iVar8 != 0xff0000) {
      return -0x7fffbffb;
    }
    if (arg2 != (void *)0x0) {
      if (arg2 != (void *)0xff000000) {
        return -0x7fffbffb;
      }
      arg2 = (void *)0x15;
      goto LAB_100106ec;
    }
  }
  arg2 = (void *)0x16;
LAB_100106ec:
  if ((*(int *)((int)this + 0x40) != 0) && (arg2 == (void *)0x29)) {
    piVar20 = (int *)piVar17[8];
    if (piVar20 == (int *)0x0) {
      piVar20 = (int *)(1 << ((byte)arg1 & 0x1f));
    }
    *(undefined4 *)((int)this + 0x3c) = 1;
    pvVar9 = operator_new(0x400);
    *(void **)((int)this + 8) = pvVar9;
    if (pvVar9 == (void *)0x0) {
      return -0x7ff8fff2;
    }
    arg1 = (int *)0x0;
    puVar10 = (undefined1 *)(*piVar17 + (int)piVar17);
    if (piVar20 != (int *)0x0) {
      do {
        iVar7 = (int)arg1 * 4;
        *(undefined1 *)(iVar7 + *(int *)((int)this + 8)) = puVar10[2];
        *(undefined1 *)(iVar7 + 1 + *(int *)((int)this + 8)) = puVar10[1];
        *(undefined1 *)(iVar7 + 2 + *(int *)((int)this + 8)) = *puVar10;
        *(undefined1 *)(iVar7 + 3 + *(int *)((int)this + 8)) = 0xff;
        arg1 = (int *)((int)arg1 + 1);
        puVar10 = puVar10 + 4;
      } while (arg1 < piVar20);
    }
    for (; piVar20 < (int *)0x100; piVar20 = (int *)((int)piVar20 + 1)) {
      iVar7 = (int)piVar20 * 4;
      *(undefined1 *)(iVar7 + *(int *)((int)this + 8)) = 0xff;
      *(undefined1 *)(iVar7 + 1 + *(int *)((int)this + 8)) = 0xff;
      *(undefined1 *)(iVar7 + 2 + *(int *)((int)this + 8)) = 0xff;
      *(undefined1 *)(iVar7 + 3 + *(int *)((int)this + 8)) = 0xff;
    }
  }
  uVar3 = *(ushort *)((int)piVar17 + 0xe);
  piVar20 = piVar4;
  if (uVar3 == 1) {
    piVar11 = (int *)((int)piVar4 + 7U >> 3);
  }
  else if (uVar3 == 4) {
    piVar11 = (int *)((int)piVar4 + 1U >> 1);
  }
  else {
    piVar11 = (int *)((uint)(uVar3 >> 3) * (int)piVar4);
    piVar20 = piVar11;
  }
  uVar16 = (int)piVar11 + 3U & 0xfffffffc;
  *(void **)this = arg2;
  uVar12 = (int)piVar20 + 3U & 0xfffffffc;
  *(int **)((int)this + 0xc) = piVar4;
  *(uint *)((int)this + 0x30) = uVar12;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(int *)((int)this + 0x10) = iVar6;
  *(undefined4 *)((int)this + 0x14) = 1;
  if (*(int *)((int)this + 0x40) != 0) {
    if ((piVar17[2] < 0) && (7 < *(ushort *)((int)piVar17 + 0xe))) {
      *(undefined4 *)((int)this + 0x38) = 0;
      *(int *)((int)this + 4) = (int)pvVar1 + (int)piVar17;
    }
    else {
      *(undefined4 *)((int)this + 0x38) = 1;
      pbVar13 = operator_new(uVar12 * iVar6);
      *(byte **)((int)this + 4) = pbVar13;
      if (pbVar13 == (byte *)0x0) {
        return -0x7ff8fff2;
      }
      pbVar18 = (byte *)((int)pvVar1 + (int)piVar17);
      iVar7 = *(int *)((int)this + 0x30);
      pbVar21 = pbVar13;
      local_1c = iVar7;
      if (-1 < piVar17[2]) {
        pbVar21 = pbVar13 + (iVar6 + -1) * iVar7;
        local_1c = -iVar7;
      }
      pbVar14 = pbVar13 + iVar7 * iVar6;
      local_14 = pbVar21;
      if (piVar17[4] == 2) {
        while (pbVar13 <= pbVar21) {
          if (*pbVar18 == 0) {
            bVar5 = pbVar18[1];
            if (bVar5 == 0) {
              pbVar21 = local_14 + -*(int *)((int)this + 0x30);
              local_14 = pbVar21;
            }
            else if (bVar5 == 1) {
              pbVar21 = pbVar13 + -*(int *)((int)this + 0x30);
            }
            else if (bVar5 == 2) {
              pbVar14 = pbVar18 + 3;
              pbVar18 = pbVar18 + 2;
              pbVar21 = pbVar21 + ((uint)*pbVar18 - (uint)*pbVar14 * *(int *)((int)this + 0x30));
            }
            else {
              uVar12 = 0;
              if (bVar5 != 0) {
                do {
                  if ((uVar12 & 1) == 0) {
                    bVar5 = pbVar18[((int)uVar12 >> 1) + 2] >> 4;
                  }
                  else {
                    bVar5 = pbVar18[((int)uVar12 >> 1) + 2] & 0xf;
                  }
                  pbVar21[uVar12] = bVar5;
                  uVar12 = uVar12 + 1;
                } while ((int)uVar12 < (int)(uint)pbVar18[1]);
              }
              pbVar21 = pbVar21 + pbVar18[1];
              pbVar18 = pbVar18 + ((pbVar18[1] >> 1) + 1 & 0xfffffffe);
            }
          }
          else {
            uVar12 = 0;
            if (*pbVar18 != 0) {
              do {
                if ((uVar12 & 1) == 0) {
                  bVar5 = pbVar18[1] >> 4;
                }
                else {
                  bVar5 = pbVar18[1] & 0xf;
                }
                pbVar21[uVar12] = bVar5;
                uVar12 = uVar12 + 1;
              } while ((int)uVar12 < (int)(uint)*pbVar18);
            }
            pbVar21 = pbVar21 + *pbVar18;
          }
          pbVar18 = pbVar18 + 2;
        }
      }
      else if (piVar17[4] == 1) {
        while (pbVar13 <= pbVar21) {
          bVar5 = *pbVar18;
          if (bVar5 == 0) {
            uVar12 = (uint)pbVar18[1];
            if (uVar12 == 0) {
              pbVar21 = local_14 + -*(int *)((int)this + 0x30);
              local_14 = pbVar21;
            }
            else if (uVar12 == 1) {
              pbVar21 = pbVar13 + -*(int *)((int)this + 0x30);
            }
            else {
              if (uVar12 != 2) {
                pbVar14 = pbVar18 + 2;
                pbVar19 = pbVar21;
                for (uVar16 = (uint)(pbVar18[1] >> 2); uVar16 != 0; uVar16 = uVar16 - 1) {
                  *(undefined4 *)pbVar19 = *(undefined4 *)pbVar14;
                  pbVar14 = pbVar14 + 4;
                  pbVar19 = pbVar19 + 4;
                }
                for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
                  *pbVar19 = *pbVar14;
                  pbVar14 = pbVar14 + 1;
                  pbVar19 = pbVar19 + 1;
                }
                uVar12 = (uint)pbVar18[1];
                pbVar18 = pbVar18 + (uVar12 + 1 & 0xfffffffe);
                goto LAB_100109ec;
              }
              pbVar14 = pbVar18 + 3;
              pbVar18 = pbVar18 + 2;
              pbVar21 = pbVar21 + ((uint)*pbVar18 - (uint)*pbVar14 * *(int *)((int)this + 0x30));
            }
          }
          else {
            bVar2 = pbVar18[1];
            pbVar14 = pbVar21;
            for (uVar12 = (uint)(bVar5 >> 2); uVar12 != 0; uVar12 = uVar12 - 1) {
              *(uint *)pbVar14 = CONCAT22(CONCAT11(bVar2,bVar2),CONCAT11(bVar2,bVar2));
              pbVar14 = pbVar14 + 4;
            }
            for (uVar12 = bVar5 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
              *pbVar14 = bVar2;
              pbVar14 = pbVar14 + 1;
            }
            uVar12 = (uint)*pbVar18;
LAB_100109ec:
            pbVar21 = pbVar21 + uVar12;
          }
          pbVar18 = pbVar18 + 2;
        }
      }
      else if (*(short *)((int)piVar17 + 0xe) == 1) {
        for (; (pbVar13 <= pbVar21 && (pbVar21 < pbVar14)); pbVar21 = pbVar21 + local_1c) {
          arg1 = (int *)0x0;
          if (piVar4 != (int *)0x0) {
            do {
              *(byte *)((int)arg1 + (int)pbVar21) =
                   pbVar18[(uint)arg1 >> 3] >> (7 - ((byte)arg1 & 7) & 0x1f) & 1;
              arg1 = (int *)((int)arg1 + 1);
            } while (arg1 < piVar4);
          }
          pbVar18 = pbVar18 + uVar16;
        }
      }
      else if (*(short *)((int)piVar17 + 0xe) == 4) {
        for (; (pbVar13 <= pbVar21 && (pbVar21 < pbVar14)); pbVar21 = pbVar21 + local_1c) {
          piVar17 = (int *)0x0;
          if (piVar4 != (int *)0x0) {
            do {
              if (((uint)piVar17 & 1) == 0) {
                bVar5 = pbVar18[(uint)piVar17 >> 1] >> 4;
              }
              else {
                bVar5 = pbVar18[(uint)piVar17 >> 1] & 0xf;
              }
              *(byte *)((int)piVar17 + (int)pbVar21) = bVar5;
              piVar17 = (int *)((int)piVar17 + 1);
            } while (piVar17 < piVar4);
          }
          pbVar18 = pbVar18 + uVar16;
        }
      }
      else {
        while ((pbVar13 <= pbVar21 && (pbVar21 < pbVar14))) {
          pbVar19 = pbVar18 + uVar16;
          pbVar22 = pbVar21 + local_1c;
          for (uVar12 = (uint)piVar20 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
            *(undefined4 *)pbVar21 = *(undefined4 *)pbVar18;
            pbVar18 = pbVar18 + 4;
            pbVar21 = pbVar21 + 4;
          }
          pbVar23 = pbVar18;
          pbVar24 = pbVar21;
          for (uVar12 = (uint)piVar20 & 3; pbVar18 = pbVar19, pbVar21 = pbVar22, uVar12 != 0;
              uVar12 = uVar12 - 1) {
            *pbVar24 = *pbVar23;
            pbVar23 = pbVar23 + 1;
            pbVar24 = pbVar24 + 1;
          }
        }
      }
    }
  }
  return 0;
}



