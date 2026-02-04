/* FUN_100165d3 @ 100165d3 */

/* WARNING: Type propagation algorithm not settling */
/* [binja] int32_t __thiscall sub_100165d3(int32_t* arg1, int32_t* arg2, int32_t* arg3, int32_t
   arg4, int32_t arg5, int32_t arg6, int32_t arg7) */

int __thiscall
FUN_100165d3(void *this,int *arg1,int *arg2,int *arg3,int arg4,int arg5,int arg6,int arg7)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  int local_6c [2];
  uint local_64;
  int local_60;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c [4];
  uint local_3c;
  uint local_38;
  uint local_34 [4];
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 *local_10;
  uint local_c;
  int *local_8;
  
  local_10 = this;
  if (*(int *)this != 0) {
    FUN_100161a0(this);
  }
  (**(code **)(*arg2 + 0x20))(arg2,local_6c);
  if (arg4 == 0) {
    bVar1 = false;
    local_34[2] = local_58;
    local_34[3] = local_54;
    uVar4 = ~arg6 & 1;
    local_34[0] = 0;
    local_34[1] = 0;
    local_24 = 0;
    local_20 = local_50;
  }
  else {
    puVar7 = local_34;
    for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *(uint *)arg4;
      arg4 = (int)(arg4 + 4);
      puVar7 = puVar7 + 1;
    }
    if (local_58 < local_34[2]) {
      return -0x7789f794;
    }
    if (local_34[2] < local_34[0]) {
      return -0x7789f794;
    }
    if (local_54 < local_34[3]) {
      return -0x7789f794;
    }
    if (local_34[3] < local_34[1]) {
      return -0x7789f794;
    }
    if (local_50 < local_20) {
      return -0x7789f794;
    }
    if (local_20 < local_24) {
      return -0x7789f794;
    }
    if (((((local_34[0] != 0) || (local_34[2] != local_58)) || (local_34[1] != 0)) ||
        ((local_34[3] != local_54 || (local_24 != 0)))) || (bVar1 = false, local_20 != local_50)) {
      bVar1 = true;
    }
    if (((arg6 & 1U) != 0) || (bVar1)) {
      uVar4 = 0;
    }
    else {
      uVar4 = 1;
    }
  }
  uVar2 = local_20;
  if ((local_60 == 0) && ((local_64 & 0x200) == 0)) {
    return -0x7789f794;
  }
  uVar6 = (arg6 & 1U | 0x80) << 4;
  local_c = uVar6;
  if ((uVar4 == 0) || ((local_64 & 0x200) == 0)) {
LAB_1001673b:
    if (bVar1) {
      if ((local_6c[0] == 0x31545844) || (local_6c[0] == 0x32545844)) {
LAB_10016806:
        uVar4 = local_34[0] & 0xfffffffc;
        local_4c[2] = local_34[2] + 3 & 0xfffffffc;
        local_4c[3] = local_34[3] + 3 & 0xfffffffc;
        if (local_58 < local_4c[2]) {
          local_4c[2] = local_58;
        }
        uVar3 = local_34[1] & 0xfffffffc;
        uVar6 = local_c;
        if (local_54 < local_4c[3]) {
          local_4c[3] = local_54;
        }
joined_r0x10016850:
        local_3c = local_24;
        local_38 = uVar2;
        if (((uVar4 == 0) && (local_4c[2] == local_58)) &&
           ((uVar3 == 0 && ((local_4c[3] == local_54 && (local_24 == 0)))))) {
          local_4c[1] = 0;
          local_4c[0] = 0;
          if (uVar2 == local_50) goto LAB_10016879;
        }
      }
      else {
        if (local_6c[0] == 0x32595559) {
LAB_1001679c:
          uVar4 = local_34[0] & 0xfffffffe;
          local_4c[2] = local_34[2] + 1 & 0xfffffffe;
          uVar3 = local_34[1];
          local_4c[3] = local_34[3];
          if (local_58 < local_4c[2]) {
            local_4c[2] = local_58;
          }
          goto joined_r0x10016850;
        }
        if (((local_6c[0] == 0x33545844) || (local_6c[0] == 0x34545844)) ||
           (local_6c[0] == 0x35545844)) goto LAB_10016806;
        if (local_6c[0] == 0x59565955) goto LAB_1001679c;
        puVar7 = local_34;
        puVar8 = local_4c;
        for (iVar5 = 6; uVar6 = local_c, uVar4 = local_4c[0], uVar3 = local_4c[1], iVar5 != 0;
            iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      local_4c[1] = uVar3;
      local_4c[0] = uVar4;
      iVar5 = (**(code **)(*arg2 + 0x24))(arg2,&local_1c,local_4c,uVar6);
      if (iVar5 < 0) {
        return iVar5;
      }
      local_34[0] = local_34[0] - local_4c[0];
      local_34[2] = local_34[2] - local_4c[0];
      local_34[1] = local_34[1] - local_4c[1];
      local_34[3] = local_34[3] - local_4c[1];
      local_24 = local_24 - local_3c;
      local_20 = uVar2 - local_3c;
      goto LAB_100168c8;
    }
  }
  else {
    if ((arg6 & 0x20000U) == 0) {
      grim_d3d_debug_set_mute(1);
      iVar5 = (**(code **)(*arg2 + 0x1c))(arg2,&DAT_1004e524,&local_8);
      if (-1 < iVar5) {
        iVar5 = (**(code **)(*local_8 + 0x34))(local_8);
        if (iVar5 == 1) {
          uVar6 = uVar6 | 0x2000;
          bVar1 = false;
          local_c = uVar6;
        }
        if (local_8 != (int *)0x0) {
          (**(code **)(*local_8 + 8))(local_8);
          local_8 = (int *)0x0;
        }
      }
      grim_d3d_debug_set_mute(0);
      goto LAB_1001673b;
    }
    uVar6 = uVar6 | 0x2000;
  }
LAB_10016879:
  iVar5 = (**(code **)(*arg2 + 0x24))(arg2,&local_1c,0,uVar6);
  if (iVar5 < 0) {
    return iVar5;
  }
LAB_100168c8:
  *arg1 = local_14;
  arg1[1] = local_6c[0];
  arg1[2] = local_1c;
  arg1[3] = local_18;
  arg1[4] = 0;
  arg1[5] = 0;
  arg1[8] = 0;
  arg1[9] = local_50;
  puVar7 = local_34;
  puVar8 = (uint *)(arg1 + 10);
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  arg1[0x11] = arg5;
  arg1[6] = local_58;
  arg1[0x12] = (int)arg3;
  arg1[7] = local_54;
  arg1[0x10] = 1;
  *local_10 = arg2;
  return 0;
}



