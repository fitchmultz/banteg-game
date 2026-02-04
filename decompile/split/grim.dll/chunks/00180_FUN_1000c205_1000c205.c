/* FUN_1000c205 @ 1000c205 */

/* [binja] int32_t __stdcall sub_1000c205(int32_t* arg1, int32_t* arg2, int32_t arg3, int32_t arg4)
    */

int FUN_1000c205(int *arg1,int *arg2,int arg3,int arg4)

{
  int *piVar1;
  int iVar2;
  int **ppiVar3;
  uint uVar4;
  bool bVar5;
  undefined1 local_68 [20];
  uint local_54;
  uint local_50;
  uint local_4c;
  undefined1 local_48 [24];
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  int *local_1c;
  uint local_18;
  int local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  piVar1 = arg1;
  if ((arg1 == (int *)0x0) ||
     (((local_14 = (**(code **)(*arg1 + 0x28))(arg1), local_14 != 3 && (local_14 != 4)) &&
      (local_14 != 5)))) {
    return -0x7789f794;
  }
  local_1c = piVar1;
  iVar2 = 5;
  if (arg4 != -1) goto LAB_1000c2a7;
  if (local_14 == 3) {
    (**(code **)(*piVar1 + 0x38))(piVar1,0,local_48);
    if (((local_30 & local_30 - 1) == 0) && (arg4 = iVar2, (local_2c & local_2c - 1) == 0))
    goto LAB_1000c2a7;
    arg4 = 0;
LAB_1000c2f6:
    bVar5 = arg4 != 0;
    arg4 = iVar2;
    if (bVar5) goto LAB_1000c2a7;
  }
  else {
    if (local_14 == 4) {
      (**(code **)(*piVar1 + 0x38))(piVar1,0,local_68);
      if ((local_54 & local_54 - 1) != 0) goto LAB_1000c2a0;
      local_30 = local_50 & local_50 - 1;
    }
    else {
      if (local_14 != 5) goto LAB_1000c2f6;
      (**(code **)(*piVar1 + 0x38))(piVar1,0,local_48);
      local_30 = local_30 & local_30 - 1;
      local_4c = local_2c;
    }
    if ((local_30 == 0) && (arg4 = iVar2, (local_4c & local_4c - 1) == 0)) goto LAB_1000c2a7;
  }
LAB_1000c2a0:
  arg4 = 0x80004;
LAB_1000c2a7:
  if (local_14 == 5) {
    arg4 = arg4 | 0x70000;
  }
  local_24 = (**(code **)(*piVar1 + 0x34))(piVar1);
  if (arg3 == -1) {
    arg3 = 0;
  }
  if ((uint)arg3 < local_24) {
    arg1 = (int *)0x0;
    local_c = (int *)0x0;
    local_8 = (int *)0x0;
    local_10 = (int *)0x0;
    local_28 = ((local_14 != 5) - 1 & 5) + 1;
    if (((arg4 & 0xffU) == 2) || (local_20 = 0, (arg4 & 0xffU) == 5)) {
      local_20 = 1;
    }
    local_18 = 0;
    iVar2 = arg4;
    if (local_28 != 0) {
      do {
        if (local_14 == 3) {
          ppiVar3 = &arg1;
LAB_1000c370:
          iVar2 = (**(code **)(*local_1c + 0x3c))(local_1c,arg3,ppiVar3);
        }
        else {
          if (local_14 == 4) {
            ppiVar3 = &local_c;
            goto LAB_1000c370;
          }
          if (local_14 == 5) {
            iVar2 = (**(code **)(*local_1c + 0x3c))(local_1c,local_18,arg3,&arg1);
          }
        }
        uVar4 = arg3;
        if (iVar2 < 0) goto LAB_1000c4a3;
LAB_1000c468:
        uVar4 = uVar4 + 1;
        if (uVar4 < local_24) {
          if (local_14 == 3) {
            ppiVar3 = &local_8;
LAB_1000c3b8:
            iVar2 = (**(code **)(*local_1c + 0x3c))(local_1c,uVar4,ppiVar3);
          }
          else {
            if (local_14 == 4) {
              ppiVar3 = &local_10;
              goto LAB_1000c3b8;
            }
            if (local_14 == 5) {
              iVar2 = (**(code **)(*local_1c + 0x3c))(local_1c,local_18,uVar4,&local_8);
            }
          }
          if (-1 < iVar2) {
            if (local_14 == 3) {
LAB_1000c3db:
              iVar2 = FUN_1000bbfc(local_8,arg2,(int *)0x0,arg1,arg2,0,arg4);
            }
            else if (local_14 == 4) {
              iVar2 = FUN_1000bda2(local_10,(int)arg2,0,local_c,(int)arg2,0,arg4,0);
            }
            else if (local_14 == 5) goto LAB_1000c3db;
            if (-1 < iVar2) {
              if (local_20 == 0) goto LAB_1000c448;
              if (arg1 != (int *)0x0) {
                (**(code **)(*arg1 + 8))(arg1);
                arg1 = (int *)0x0;
              }
              if (local_c != (int *)0x0) {
                (**(code **)(*local_c + 8))(local_c);
              }
              arg1 = local_8;
              local_8 = (int *)0x0;
              local_c = local_10;
              goto LAB_1000c465;
            }
          }
          goto LAB_1000c4a3;
        }
        if (arg1 != (int *)0x0) {
          (**(code **)(*arg1 + 8))(arg1);
          arg1 = (int *)0x0;
        }
        if (local_c != (int *)0x0) {
          (**(code **)(*local_c + 8))(local_c);
          local_c = (int *)0x0;
        }
        local_18 = local_18 + 1;
      } while (local_18 < local_28);
    }
    iVar2 = 0;
LAB_1000c4a3:
    if (arg1 != (int *)0x0) {
      (**(code **)(*arg1 + 8))(arg1);
      arg1 = (int *)0x0;
    }
    if (local_c != (int *)0x0) {
      (**(code **)(*local_c + 8))(local_c);
      local_c = (int *)0x0;
    }
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 8))(local_8);
      local_8 = (int *)0x0;
    }
    if (local_10 != (int *)0x0) {
      (**(code **)(*local_10 + 8))(local_10);
    }
  }
  else {
    iVar2 = -0x7789f794;
  }
  return iVar2;
LAB_1000c448:
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
    local_8 = (int *)0x0;
  }
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
LAB_1000c465:
    local_10 = (int *)0x0;
  }
  goto LAB_1000c468;
}



