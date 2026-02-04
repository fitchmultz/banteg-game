/* grim_load_image_jpg @ 10010e13 */

/* [binja] int32_t __thiscall sub_10010e13(int32_t* arg1, int32_t arg2, int32_t arg3) */

int grim_load_image_jpg(int *arg1,int arg2,int arg3)

{
  uint *puVar1;
  int iVar2;
  void *pvVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint *puVar8;
  undefined4 *puVar9;
  code *local_278 [2];
  undefined *local_270;
  undefined1 local_1f4 [64];
  int local_1b4;
  undefined4 *local_1b0;
  undefined4 *local_1a0;
  undefined4 local_170;
  uint local_158;
  uint local_154;
  int local_14c;
  uint local_13c;
  int *local_c;
  undefined4 *local_8;
  
  local_1b4 = FUN_1001e027(local_278);
  local_278[0] = FUN_10010dd0;
  local_270 = &DAT_10010dec;
  iVar2 = setjmp3(local_1f4,0);
  if (iVar2 == 0) {
    FUN_1001c265(&local_1b4,0x3d,0x1a8);
    local_1a0 = (undefined4 *)(*(code *)*local_1b0)(&local_1b4,0,0x24);
    local_1a0[8] = arg2;
    local_1a0[2] = &DAT_10010dec;
    local_1a0[3] = &LAB_10010ded;
    local_1a0[4] = &LAB_10010e02;
    local_1a0[5] = &LAB_1001dd80;
    local_1a0[6] = &DAT_10010dec;
    local_1a0[1] = 0;
    *local_1a0 = 0;
    local_1a0[7] = arg1;
    FUN_1001c5de(&local_1b4,'\x01');
    iVar2 = FUN_1001bf5e();
    if (iVar2 == 0) {
      local_170 = 1;
    }
    local_270 = &LAB_1001df31;
    FUN_1001c76e(&local_1b4);
    if (local_14c == 1) {
      *local_c = 0x32;
      local_c[0xc] = local_158;
    }
    else {
      if (local_14c != 3) goto LAB_10010e5e;
      *local_c = 0x16;
      local_c[0xc] = local_158 << 2;
    }
    local_c[0xd] = 0;
    local_c[3] = local_158;
    local_c[4] = local_154;
    local_c[5] = 1;
    if (local_c[0x10] != 0) {
      local_c[0xe] = 1;
      pvVar3 = operator_new(local_c[0xc] * local_154);
      local_c[1] = (int)pvVar3;
      if ((pvVar3 == (void *)0x0) ||
         (local_8 = (undefined4 *)(*(code *)local_1b0[2])(&local_1b4,1,local_158 * local_14c,1),
         local_8 == (undefined4 *)0x0)) {
        iVar2 = -0x7ff8fff2;
        goto LAB_1001106d;
      }
      if (*local_c == 0x32) {
        puVar6 = (undefined4 *)local_c[1];
        if (local_13c < local_154) {
          do {
            FUN_1001c6ea(&local_1b4,local_8,1);
            puVar7 = (undefined4 *)*local_8;
            puVar9 = puVar6;
            for (uVar5 = local_158 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
              *puVar9 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar9 = puVar9 + 1;
            }
            for (uVar5 = local_158 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
              puVar7 = (undefined4 *)((int)puVar7 + 1);
              puVar9 = (undefined4 *)((int)puVar9 + 1);
            }
            puVar6 = (undefined4 *)((int)puVar6 + local_158);
          } while (local_13c < local_154);
        }
      }
      else if (*local_c == 0x16) {
        puVar8 = (uint *)local_c[1];
        while (local_13c < local_154) {
          FUN_1001c6ea(&local_1b4,local_8,1);
          puVar4 = (undefined1 *)*local_8;
          puVar1 = puVar8 + local_158;
          for (; puVar8 < puVar1; puVar8 = puVar8 + 1) {
            *puVar8 = (uint)CONCAT21(CONCAT11(*puVar4,puVar4[1]),puVar4[2]);
            puVar4 = puVar4 + 3;
          }
        }
      }
      FUN_1001c537(&local_1b4);
    }
    iVar2 = 0;
  }
  else {
LAB_10010e5e:
    iVar2 = -0x7fffbffb;
  }
LAB_1001106d:
  thunk_FUN_10023bc5((int)&local_1b4);
  return iVar2;
}



