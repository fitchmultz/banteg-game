/* grim_load_image_pnm @ 1001152a */

/* [binja] int32_t __thiscall sub_1001152a(int32_t* arg1, char* arg2, int32_t arg3) */

int __thiscall grim_load_image_pnm(void *this,int *arg1,char *arg2,int arg3)

{
  char *pcVar1;
  byte bVar2;
  bool bVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  uint local_18;
  uint *local_14;
  uint local_c;
  int local_8;
  
  if (arg2 < (char *)0x2) {
    return -0x7fffbffb;
  }
  if ((char)*arg1 == 'P') {
    if (*(char *)((int)arg1 + 1) == '3') {
      bVar3 = true;
    }
    else {
      if (*(char *)((int)arg1 + 1) != '6') {
        return -0x7fffbffb;
      }
      bVar3 = false;
    }
    pbVar9 = (byte *)((int)arg1 + 2);
    arg2 = arg2 + -2;
    local_8 = 0;
    local_18 = 0;
    local_c = 0xff;
    pbVar4 = pbVar9;
    while (arg2 != (char *)0x0) {
      uVar8 = 0;
      if ((!bVar3) && (local_8 == 3)) {
        if (0xff < local_c) {
          return -0x7fffbffb;
        }
        if (((char *)0x1 < arg2) && (*pbVar9 == 0xd)) {
          pbVar9 = pbVar9 + 1;
          arg2 = arg2 + -1;
        }
        pcVar1 = arg2 + -1;
        pbVar9 = pbVar9 + 1;
        for (; (pcVar1 != (char *)0x0 && (arg1 < local_14)); arg1 = (int *)((uint *)arg1 + 1)) {
          *arg1 = ((((uint)*pbVar9 * 0xff) / local_c | 0xffffff00) << 8 |
                  ((uint)pbVar9[1] * 0xff) / local_c) << 8 | ((uint)pbVar9[2] * 0xff) / local_c;
          pcVar1 = pcVar1 + -3;
          pbVar9 = pbVar9 + 3;
        }
        return -(uint)((uint *)arg1 != local_14) & 0x80004005;
      }
      iVar7 = isspace((uint)*pbVar9);
      if (iVar7 == 0) {
        if (*pbVar9 == 0x23) {
          for (; (arg2 != (char *)0x0 && (*pbVar9 != 10)); pbVar9 = pbVar9 + 1) {
            arg2 = arg2 + -1;
          }
          goto LAB_100115b4;
        }
        while ((arg2 != (char *)0x0 && (iVar7 = isspace((uint)*pbVar9), iVar7 == 0))) {
          iVar7 = isdigit((uint)*pbVar9);
          if (iVar7 == 0) {
            return -0x7fffbffb;
          }
          bVar2 = *pbVar9;
          pbVar9 = pbVar9 + 1;
          arg2 = arg2 + -1;
          uVar8 = (bVar2 - 0x30) + uVar8 * 10;
          pbVar4 = pbVar9;
        }
        uVar5 = uVar8;
        uVar6 = local_c;
        if (local_8 == 0) {
LAB_100116f9:
          local_c = uVar6;
          local_18 = uVar5;
          if (uVar8 == 0) {
            return -0x7fffbffb;
          }
        }
        else if (local_8 == 1) {
          if (uVar8 == 0) {
            return -0x7fffbffb;
          }
          arg1 = operator_new(uVar8 * local_18 * 4);
          *(int **)((int)this + 4) = arg1;
          if (arg1 == (int *)0x0) {
            return -0x7ff8fff2;
          }
          local_14 = (uint *)(arg1 + uVar8 * local_18);
          *(undefined4 *)((int)this + 0x34) = 0;
          *(undefined4 *)((int)this + 0x38) = 1;
          *(undefined4 *)this = 0x16;
          *(uint *)((int)this + 0x30) = local_18 << 2;
          *(uint *)((int)this + 0xc) = local_18;
          *(uint *)((int)this + 0x10) = uVar8;
          *(undefined4 *)((int)this + 0x14) = 1;
          pbVar9 = pbVar4;
        }
        else {
          uVar5 = local_18;
          uVar6 = uVar8;
          if (local_8 == 2) goto LAB_100116f9;
          if (local_8 == 3) {
            if (local_14 <= arg1) {
              return -0x7fffbffb;
            }
            *arg1 = ((uVar8 * 0xff) / local_c | 0xffffff00) << 0x10;
          }
          else if (local_8 == 4) {
            *arg1 = *arg1 | (uVar8 * 0xff) / local_c << 8;
          }
          else if (local_8 == 5) {
            *arg1 = *arg1 | (uVar8 * 0xff) / local_c;
            arg1 = (int *)((uint *)arg1 + 1);
            if ((uint *)arg1 == local_14) {
              return 0;
            }
            local_8 = 2;
          }
        }
        local_8 = local_8 + 1;
      }
      else {
LAB_100115b4:
        pbVar9 = pbVar9 + 1;
        arg2 = arg2 + -1;
        pbVar4 = pbVar9;
      }
    }
  }
  return -0x7fffbffb;
}



