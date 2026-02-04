/* grim_load_image_dds @ 10011d95 */

/* [binja] int32_t __thiscall sub_10011d95(int32_t* arg1, uint32_t arg2, int32_t* arg3) */

int __thiscall grim_load_image_dds(void *this,int *arg1,uint arg2,int *arg3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  int *local_2c;
  uint local_24;
  int *local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int *local_8;
  
  if (((arg2 < 4) || (*arg1 != 0x20534444)) || (arg2 - 4 < 0x7c)) {
    return -0x7fffbffb;
  }
  local_8 = arg1 + 0x20;
  *(int *)((int)this + 0xc) = arg1[4];
  *(int *)((int)this + 0x10) = arg1[3];
  if ((*(byte *)((int)arg1 + 10) & 0x80) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = arg1[6];
  }
  *(int *)((int)this + 0x14) = iVar1;
  if (iVar1 == 0) {
    *(undefined4 *)((int)this + 0x14) = 1;
  }
  if ((arg1[0x1c] & 0xfc00U) == 0xfc00) {
    local_18 = 6;
  }
  else {
    if ((arg1[0x1c] & 0xfc00U) != 0) {
      return -0x7fffbffb;
    }
    local_18 = 1;
  }
  local_24 = arg1[7];
  if (local_24 == 0) {
    local_24 = 1;
  }
  piVar10 = &DAT_10053ec8;
  iVar1 = DAT_10053ec8;
  while (iVar1 != 0) {
    if ((arg1[0x13] == 0x20) && (uVar11 = piVar10[2], arg1[0x14] == uVar11)) {
      if ((((((uVar11 & 4) == 0) || (arg1[0x15] == piVar10[3])) &&
           (((uVar11 & 0xc4462) == 0 || (arg1[0x16] == piVar10[4])))) &&
          (((uVar11 & 0xe4040) == 0 || (arg1[0x17] == piVar10[5])))) &&
         (((((uVar11 & 0xc4440) == 0 || (arg1[0x18] == piVar10[6])) &&
           (((uVar11 & 0xc4040) == 0 || (arg1[0x19] == piVar10[7])))) &&
          (((uVar11 & 0x80003) == 0 || (arg1[0x1a] == piVar10[8])))))) break;
    }
    piVar10 = piVar10 + 9;
    iVar1 = *piVar10;
  }
  iVar1 = *piVar10;
  if (iVar1 == 0) {
    return -0x7fffbffb;
  }
  piVar10 = grim_format_info_lookup(iVar1);
  if ((*(byte *)((int)arg1 + 10) & 0x80) == 0) {
    *(uint *)((int)this + 0x44) = (uint)(local_18 == 6) * 2 + 3;
  }
  else {
    *(undefined4 *)((int)this + 0x44) = 4;
  }
  if (piVar10[1] == 1) {
    if (arg2 - 0x80 < 0x400) {
      return -0x7fffbffb;
    }
    arg2 = arg2 - 0x480;
    local_2c = local_8;
    local_8 = arg1 + 0x120;
  }
  else {
    local_2c = (int *)0x0;
    arg2 = arg2 - 0x80;
  }
  local_14 = 0;
  piVar3 = (int *)arg2;
  if (local_18 != 0) {
    do {
      uVar11 = *(uint *)((int)this + 0xc);
      uVar8 = *(uint *)((int)this + 0x10);
      arg1 = *(int **)((int)this + 0x14);
      piVar2 = this;
      if (local_14 != 0) {
        piVar2 = operator_new(0x54);
        if (piVar2 == (int *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = FUN_10010285(piVar2);
        }
        if (piVar2 == (int *)0x0) {
          return -0x7ff8fff2;
        }
        local_1c[0x14] = (int)piVar2;
      }
      local_10 = 0;
      piVar9 = piVar3;
      if (local_24 != 0) {
        do {
          piVar3 = piVar2;
          if (local_10 != 0) {
            piVar3 = operator_new(0x54);
            if (piVar3 == (int *)0x0) {
              piVar3 = (int *)0x0;
            }
            else {
              piVar3 = FUN_10010285(piVar3);
            }
            if (piVar3 == (int *)0x0) {
              return -0x7ff8fff2;
            }
            piVar9[0x13] = (int)piVar3;
          }
          if (iVar1 == 0x31545844) {
            iVar4 = (uVar11 + 3 >> 2) << 3;
LAB_10012032:
            iVar6 = (uVar8 + 3 >> 2) * iVar4;
          }
          else {
            if (iVar1 == 0x32545844) {
LAB_1001201e:
              iVar4 = (uVar11 + 3 >> 2) << 4;
              goto LAB_10012032;
            }
            if (iVar1 == 0x32595559) {
LAB_1001200f:
              iVar4 = (uVar11 + 1 >> 1) << 2;
            }
            else {
              if (((iVar1 == 0x33545844) || (iVar1 == 0x34545844)) || (iVar1 == 0x35545844))
              goto LAB_1001201e;
              if (iVar1 == 0x59565955) goto LAB_1001200f;
              iVar4 = ((uint)piVar10[2] >> 3) * uVar11;
            }
            iVar6 = iVar4 * uVar8;
          }
          piVar3[0xe] = 0;
          piVar3[0xf] = 0;
          uVar7 = iVar6 * (int)arg1;
          *piVar3 = iVar1;
          piVar3[0xc] = iVar4;
          piVar3[1] = (int)local_8;
          piVar3[5] = (int)arg1;
          piVar3[0xd] = iVar6;
          piVar3[3] = uVar11;
          piVar3[4] = uVar8;
          piVar3[2] = (int)local_2c;
          if (arg2 < uVar7) {
            return -0x7fffbffb;
          }
          local_8 = (int *)((int)local_8 + uVar7);
          arg2 = arg2 - uVar7;
          uVar5 = 1;
          uVar7 = uVar5;
          if (uVar11 != 1) {
            uVar7 = uVar11 >> 1;
          }
          if (uVar8 != 1) {
            uVar5 = uVar8 >> 1;
          }
          if (arg1 == (int *)0x1) {
            arg1 = (int *)0x1;
          }
          else {
            arg1 = (int *)((uint)arg1 >> 1);
          }
          local_10 = local_10 + 1;
          uVar8 = uVar5;
          piVar9 = piVar3;
          uVar11 = uVar7;
        } while (local_10 < local_24);
      }
      local_14 = local_14 + 1;
      local_1c = piVar2;
    } while (local_14 < local_18);
  }
  return 0;
}



