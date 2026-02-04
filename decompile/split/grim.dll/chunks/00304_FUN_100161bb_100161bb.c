/* FUN_100161bb @ 100161bb */

/* WARNING: Type propagation algorithm not settling */
/* [binja] int32_t __thiscall sub_100161bb(char* arg1, int32_t* arg2, int32_t* arg3, int32_t arg4,
   int32_t* arg5, int32_t arg6, int32_t arg7) */

int __thiscall
FUN_100161bb(void *this,char *arg1,int *arg2,int *arg3,int arg4,int *arg5,int arg6,int arg7)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int local_64 [2];
  uint local_5c;
  int local_58;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  local_1c = this;
  FUN_10016131(this);
  (**(code **)(*arg2 + 0x20))(arg2,local_64);
  if (arg4 == 0) {
    local_2c = local_4c;
    local_28 = local_48;
    local_c = ~arg6 & 1;
    local_34 = 0;
    local_30 = 0;
    bVar2 = false;
  }
  else {
    local_34 = *(uint *)arg4;
    local_30 = *(uint *)(arg4 + 4);
    local_2c = *(uint *)(arg4 + 8);
    local_28 = *(uint *)(arg4 + 0xc);
    if (((((int)local_34 < 0) || (local_4c < local_2c)) || ((int)local_2c < (int)local_34)) ||
       ((((int)local_30 < 0 || (local_48 < local_28)) || ((int)local_28 < (int)local_30)))) {
      return -0x7789f794;
    }
    if (((local_34 != 0) || (local_2c != local_4c)) ||
       ((local_30 != 0 || (bVar2 = false, local_28 != local_48)))) {
      bVar2 = true;
    }
    if (((arg6 & 1U) != 0) || (bVar2)) {
      local_c = 0;
    }
    else {
      local_c = 1;
    }
  }
  local_8 = arg6 & 0x10000;
  if (local_8 == 0) {
    if ((local_58 == 0) && ((local_5c & 0x200) == 0)) {
      grim_d3d_debug_set_mute(1);
      iVar5 = (**(code **)(*arg2 + 0x1c))(arg2,&DAT_1004e544,&local_18);
      if (iVar5 < 0) {
        local_5c = arg2[4];
        local_8 = ~(local_5c >> 0x1a) & 1;
      }
      else {
        local_8 = 1;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
          local_18 = (int *)0x0;
        }
      }
      grim_d3d_debug_set_mute(0);
      if (local_8 != 0) goto LAB_100162e3;
    }
    local_14 = arg2;
  }
  else {
LAB_100162e3:
    piVar7 = local_1c;
    if ((((local_64[0] == 0x31545844) || (local_64[0] == 0x32545844)) || (local_64[0] == 0x33545844)
        ) || ((local_64[0] == 0x34545844 ||
              (local_14 = (int *)local_48, uVar6 = local_4c, local_64[0] == 0x35545844)))) {
      local_14 = (int *)(local_48 + 3 & 0xfffffffc);
      uVar6 = local_4c + 3 & 0xfffffffc;
    }
    piVar1 = local_1c + 3;
    (**(code **)(*arg2 + 0xc))(arg2,piVar1);
    piVar7 = piVar7 + 2;
    iVar5 = (**(code **)(*(int *)*piVar1 + 0x6c))((int *)*piVar1,uVar6,local_14,local_64[0],piVar7);
    if (iVar5 < 0) {
      return iVar5;
    }
    if ((local_c == 0) &&
       (iVar5 = (**(code **)(*(int *)*piVar1 + 0x70))((int *)*piVar1,arg2,0,0,*piVar7,0), iVar5 < 0)
       ) {
      return iVar5;
    }
    local_14 = (int *)*piVar7;
  }
  uVar6 = (arg6 & 1U | 0x80) << 4;
  if (((local_c == 0) || (local_8 != 0)) || ((local_5c & 0x200) == 0)) {
LAB_10016400:
    uVar3 = local_44;
    uVar4 = local_40;
    if (bVar2) {
      if ((local_64[0] == 0x31545844) || (local_64[0] == 0x32545844)) {
LAB_10016488:
        local_44 = local_34 & 0xfffffffc;
        local_3c = local_2c + 3 & 0xfffffffc;
        local_40 = local_30 & 0xfffffffc;
        local_38 = local_28 + 3 & 0xfffffffc;
        if (local_8 == 0) {
          if (local_4c < local_3c) {
            local_3c = local_4c;
          }
          if (local_48 < local_38) {
            local_38 = local_48;
          }
joined_r0x100164d3:
          if (((local_44 == 0) && (local_3c == local_4c)) && (local_40 == 0)) {
            uVar3 = 0;
            uVar4 = 0;
            if (local_38 == local_48) goto LAB_100165b3;
          }
        }
        else if (((local_44 == 0) && (local_3c == (local_4c + 3 & 0xfffffffc))) && (local_40 == 0))
        {
          uVar3 = 0;
          uVar4 = 0;
          if (local_38 == (local_48 + 3 & 0xfffffffc)) goto LAB_100165b3;
        }
      }
      else {
        if (local_64[0] == 0x32595559) {
LAB_1001644c:
          local_44 = local_34 & 0xfffffffe;
          local_3c = local_2c + 1 & 0xfffffffe;
          local_40 = local_30;
          local_38 = local_28;
          if (local_4c < local_3c) {
            local_3c = local_4c;
          }
          goto joined_r0x100164d3;
        }
        if (((local_64[0] == 0x33545844) || (local_64[0] == 0x34545844)) ||
           (local_64[0] == 0x35545844)) goto LAB_10016488;
        if (local_64[0] == 0x59565955) goto LAB_1001644c;
        local_44 = local_34;
        local_40 = local_30;
        local_3c = local_2c;
        local_38 = local_28;
      }
      iVar5 = (**(code **)(*local_14 + 0x24))(local_14,&local_24,&local_44,uVar6);
      if (iVar5 < 0) {
        return iVar5;
      }
      local_34 = local_34 - local_44;
      local_2c = local_2c - local_44;
      local_30 = local_30 - local_40;
      local_28 = local_28 - local_40;
      goto LAB_10016511;
    }
  }
  else {
    if ((arg6 & 0x20000U) == 0) {
      grim_d3d_debug_set_mute(1);
      iVar5 = (**(code **)(*arg2 + 0x1c))(arg2,&DAT_1004e534,&local_10);
      if (-1 < iVar5) {
        iVar5 = (**(code **)(*local_10 + 0x34))(local_10);
        if (iVar5 == 1) {
          uVar6 = uVar6 | 0x2000;
          bVar2 = false;
        }
        if (local_10 != (int *)0x0) {
          (**(code **)(*local_10 + 8))(local_10);
          local_10 = (int *)0x0;
        }
      }
      grim_d3d_debug_set_mute(0);
      goto LAB_10016400;
    }
    uVar6 = uVar6 | 0x2000;
    uVar3 = local_44;
    uVar4 = local_40;
  }
LAB_100165b3:
  local_40 = uVar4;
  local_44 = uVar3;
  iVar5 = (**(code **)(*local_14 + 0x24))(local_14,&local_24,0,uVar6);
  if (iVar5 < 0) {
    return iVar5;
  }
LAB_10016511:
  arg1[0xc] = '\0';
  arg1[0xd] = '\0';
  arg1[0xe] = '\0';
  arg1[0xf] = '\0';
  arg1[0x10] = '\0';
  arg1[0x11] = '\0';
  arg1[0x12] = '\0';
  arg1[0x13] = '\0';
  arg1[0x14] = '\0';
  arg1[0x15] = '\0';
  arg1[0x16] = '\0';
  arg1[0x17] = '\0';
  arg1[0x20] = '\0';
  arg1[0x21] = '\0';
  arg1[0x22] = '\0';
  arg1[0x23] = '\0';
  arg1[0x38] = '\0';
  arg1[0x39] = '\0';
  arg1[0x3a] = '\0';
  arg1[0x3b] = '\0';
  *(undefined4 *)arg1 = local_20;
  *(int *)(arg1 + 4) = local_64[0];
  *(uint *)(arg1 + 0x28) = local_34;
  arg1[0x3c] = '\x01';
  arg1[0x3d] = '\0';
  arg1[0x3e] = '\0';
  arg1[0x3f] = '\0';
  arg1[0x40] = '\x01';
  arg1[0x41] = '\0';
  arg1[0x42] = '\0';
  arg1[0x43] = '\0';
  *(undefined4 *)(arg1 + 8) = local_24;
  *(uint *)(arg1 + 0x2c) = local_30;
  *(int **)(arg1 + 0x44) = arg5;
  *(uint *)(arg1 + 0x18) = local_4c;
  *(uint *)(arg1 + 0x30) = local_2c;
  *(int **)(arg1 + 0x48) = arg3;
  *(uint *)(arg1 + 0x1c) = local_48;
  arg1[0x24] = '\x01';
  arg1[0x25] = '\0';
  arg1[0x26] = '\0';
  arg1[0x27] = '\0';
  *(uint *)(arg1 + 0x34) = local_28;
  local_1c[1] = (int)arg2;
  *local_1c = arg6;
  return 0;
}



