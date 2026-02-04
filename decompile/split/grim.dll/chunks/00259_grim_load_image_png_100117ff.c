/* grim_load_image_png @ 100117ff */

/* [binja] int32_t __thiscall sub_100117ff(int32_t* arg1, void* arg2, void* arg3) */

int grim_load_image_png(int *arg1,void *arg2,void *arg3)

{
  undefined1 *puVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_158 [256];
  double local_58;
  double local_50;
  int *local_48;
  void *local_44;
  int local_40;
  undefined1 local_3c [4];
  int *local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint *local_c;
  png_structp local_8;
  
  local_8 = (png_structp)0x0;
  local_c = (uint *)0x0;
  local_20 = (undefined4 *)0x0;
  iVar4 = FUN_100204e3((int)arg1,0,(uint)arg2);
  if (iVar4 != 0) {
    return -0x7fffbffb;
  }
  local_8 = png_create_read_struct("1.0.5",(png_voidp)0x0,&DAT_100117f3,&DAT_10010dec);
  if ((local_8 == (png_structp)0x0) ||
     (local_c = FUN_100205e8((int)local_8), local_c == (uint *)0x0)) goto LAB_10011c62;
  iVar4 = setjmp3(local_8);
  if (iVar4 == 0) {
    local_48 = arg1;
    local_44 = arg2;
    FUN_100204a4(local_8,&local_48,&LAB_100117b0);
    FUN_1001e294(local_8,local_c);
    FUN_1001ea59(local_8,local_c,&local_34,&local_1c,&local_28,&local_30,(uint *)0x0,(uint *)0x0,
                 (uint *)0x0);
    if (local_30 == 0) {
      *local_38 = 0x32;
    }
    else if (local_30 == 2) {
      *local_38 = 0x14;
    }
    else if (local_30 == 3) {
      *local_38 = 0x29;
    }
    else if (local_30 == 4) {
      *local_38 = 0x33;
    }
    else if (local_30 == 6) {
      *local_38 = 0x15;
    }
    if (local_28 == 0x10) {
      FUN_1001ebcd((int)local_8);
      iVar4 = *local_38;
      if (iVar4 == 0x14) {
        *local_38 = 0x36315220;
      }
      else if (iVar4 == 0x15) {
        *local_38 = 0x36315241;
      }
      else if (iVar4 == 0x32) {
        *local_38 = 0x36314c20;
      }
      else {
        if (iVar4 != 0x33) {
          return -0x7fffbffb;
        }
        *local_38 = 0x36314c41;
      }
    }
    if ((int)local_28 < 8) {
      FUN_1001ebdf((int)local_8);
    }
    if ((local_30 == 0) && ((int)local_28 < 8)) {
      FUN_1001ed80((int)local_8);
    }
    iVar4 = FUN_1001ea2e((int)local_8,(int)local_c,(uint *)local_3c);
    if (iVar4 == 0) {
      iVar4 = FUN_1001ea05((int)local_8,(int)local_c,&local_58);
      if (iVar4 != 0) {
        FUN_1001ed4a((int)local_8,2.2,local_58);
      }
    }
    else {
      FUN_100203e1((int)local_8,(int)local_c,local_3c[0]);
    }
    if ((*local_38 != 0x29) && (uVar5 = FUN_1001e9bf((int)local_8,(int)local_c,0x10), uVar5 != 0)) {
      FUN_1001ed80((int)local_8);
      iVar4 = *local_38;
      if (iVar4 == 0x14) {
        *local_38 = 0x15;
      }
      else if (iVar4 == 0x32) {
        *local_38 = 0x33;
      }
      else if (iVar4 == 0x36314c20) {
        *local_38 = 0x36314c41;
      }
      else if (iVar4 == 0x36315220) {
        *local_38 = 0x36315241;
      }
    }
    iVar4 = *local_38;
    if ((((iVar4 == 0x14) || (iVar4 == 0x36315220)) || (iVar4 == 0x15)) || (iVar4 == 0x36315241)) {
      FUN_1001ebc4((int)local_8);
    }
    if (*local_38 == 0x14) {
      FUN_1001ec11((int)local_8,0xff,1);
      *local_38 = 0x16;
    }
    FUN_1001e407(local_8,(int *)local_c);
    iVar4 = *local_38;
    uVar5 = 3;
    if (iVar4 < 0x34) {
      if (iVar4 == 0x33) {
LAB_10011ad2:
        local_10 = 2;
        uVar5 = local_10;
      }
      else if (iVar4 != 0x14) {
        if ((iVar4 == 0x15) || (iVar4 == 0x16)) {
LAB_10011ac8:
          uVar5 = 4;
        }
        else if ((iVar4 == 0x29) || (uVar5 = local_10, iVar4 == 0x32)) goto LAB_10011a8e;
      }
    }
    else if (iVar4 == 0x36314c20) {
LAB_10011a8e:
      local_10 = 1;
      uVar5 = local_10;
    }
    else {
      if (iVar4 == 0x36314c41) goto LAB_10011ad2;
      if ((iVar4 != 0x36315220) && (uVar5 = local_10, iVar4 == 0x36315241)) goto LAB_10011ac8;
    }
    local_10 = uVar5;
    bVar2 = FUN_1001e9ef((int)local_8,(int)local_c);
    if (local_10 == bVar2) {
      local_38[3] = local_34;
      local_38[4] = local_1c;
      local_38[5] = 1;
      iVar4 = FUN_1001e9d9((int)local_8,(int)local_c);
      local_38[0xc] = iVar4;
      local_38[0xd] = 0;
      if (local_38[0x10] == 0) goto LAB_10011d64;
      pvVar6 = operator_new(iVar4 * local_1c);
      local_38[1] = (int)pvVar6;
      if (pvVar6 != (void *)0x0) {
        local_38[0xe] = 1;
        local_20 = operator_new(local_1c << 2);
        if (local_20 != (undefined4 *)0x0) {
          uVar5 = 0;
          if (local_1c != 0) {
            do {
              local_20[uVar5] = local_38[0xc] * uVar5 + local_38[1];
              uVar5 = uVar5 + 1;
            } while (uVar5 < local_1c);
          }
          FUN_1001e7ce(local_8,local_20);
          if (*local_38 == 0x29) {
            local_2c = 0;
            local_24 = 0;
            uVar5 = FUN_1001e9bf((int)local_8,(int)local_c,8);
            if (uVar5 != 0) {
              FUN_1001eb2a((int)local_8,(int)local_c,&local_14,&local_24);
            }
            uVar5 = FUN_1001e9bf((int)local_8,(int)local_c,0x10);
            if (uVar5 != 0) {
              FUN_1001eb5d((int)local_8,(int)local_c,&local_40,&local_2c,(int *)0x0);
            }
            if (((float)local_8[1].jmpbuf[4] <= 1e-06) || ((float)local_8[1].jmpbuf[5] <= 1e-06)) {
              iVar4 = 0;
              do {
                auStack_158[iVar4] = (char)iVar4;
                iVar4 = iVar4 + 1;
              } while (iVar4 < 0x100);
            }
            else {
              local_18 = 0;
              local_50 = (double)(1.0 / ((float)local_8[1].jmpbuf[5] * (float)local_8[1].jmpbuf[4]))
              ;
              do {
                _CIpow();
                uVar3 = ftol();
                iVar4 = local_18 + 1;
                puVar1 = auStack_158 + local_18;
                local_18 = iVar4;
                *puVar1 = uVar3;
              } while (iVar4 < 0x100);
            }
            pvVar6 = operator_new(0x400);
            local_38[2] = (int)pvVar6;
            if (pvVar6 == (void *)0x0) goto LAB_10011c62;
            iVar4 = 0;
            local_38[0xf] = 1;
            if (0 < (int)local_2c) {
              iVar8 = 0;
              do {
                iVar7 = iVar4 * 4;
                *(undefined1 *)(iVar7 + local_38[2]) = auStack_158[*(byte *)(iVar8 + local_14)];
                *(undefined1 *)(local_38[2] + 1 + iVar7) =
                     auStack_158[*(byte *)(iVar8 + 1 + local_14)];
                *(undefined1 *)(local_38[2] + 2 + iVar7) =
                     auStack_158[*(byte *)(iVar8 + 2 + local_14)];
                puVar1 = (undefined1 *)(iVar4 + local_40);
                iVar4 = iVar4 + 1;
                *(undefined1 *)(local_38[2] + 3 + iVar7) = *puVar1;
                iVar8 = iVar8 + 3;
              } while (iVar4 < (int)local_2c);
            }
            if (iVar4 < (int)local_24) {
              iVar8 = iVar4 * 3;
              do {
                iVar7 = iVar4 * 4;
                *(undefined1 *)(iVar7 + local_38[2]) = auStack_158[*(byte *)(iVar8 + local_14)];
                *(undefined1 *)(local_38[2] + 1 + iVar7) =
                     auStack_158[*(byte *)(iVar8 + 1 + local_14)];
                *(undefined1 *)(local_38[2] + 2 + iVar7) =
                     auStack_158[*(byte *)(iVar8 + 2 + local_14)];
                *(undefined1 *)(local_38[2] + 3 + iVar7) = 0xff;
                iVar4 = iVar4 + 1;
                iVar8 = iVar8 + 3;
              } while (iVar4 < (int)local_24);
            }
            if (iVar4 < 0x100) {
              iVar4 = iVar4 << 2;
              do {
                *(undefined1 *)(iVar4 + local_38[2]) = 0xff;
                *(undefined1 *)(iVar4 + 1 + local_38[2]) = 0xff;
                *(undefined1 *)(iVar4 + 2 + local_38[2]) = 0xff;
                *(undefined1 *)(iVar4 + 3 + local_38[2]) = 0xff;
                iVar4 = iVar4 + 4;
              } while (iVar4 < 0x400);
            }
          }
LAB_10011d64:
          iVar4 = 0;
          goto LAB_10011d66;
        }
      }
LAB_10011c62:
      iVar4 = -0x7ff8fff2;
      goto LAB_10011d66;
    }
  }
  iVar4 = -0x7fffbffb;
LAB_10011d66:
  if (local_8 != (png_structp)0x0) {
    FUN_1001e93e(&local_8,&local_c,(undefined4 *)0x0);
  }
  if (local_20 != (undefined4 *)0x0) {
    operator_delete(local_20);
  }
  return iVar4;
}



