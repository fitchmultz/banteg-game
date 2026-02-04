/* FUN_1000abad @ 1000abad */

int __cdecl FUN_1000abad(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *arg2;
  int *piVar4;
  int *piVar5;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined1 local_18 [12];
  undefined4 local_c;
  int *local_8;
  
  local_8 = (int *)0x0;
  grim_d3d_debug_set_mute(1);
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x18))(param_1,&local_8);
    (**(code **)(*param_1 + 0x1c))(param_1,&local_ec);
    (**(code **)(*param_1 + 0x20))(param_1,local_18);
  }
  uVar3 = 0xffffffff;
  arg2 = &DAT_1004c3b0;
  piVar5 = &DAT_1004c388;
  piVar4 = &DAT_1004c388;
  if (&DAT_1004c3b0 < PTR_DAT_10053c50) {
    do {
      piVar5 = piVar4;
      if ((*arg2 != 0) &&
         ((param_1 == (int *)0x0 ||
          (iVar1 = (**(code **)(*local_8 + 0x28))
                             (local_8,local_e8,local_ec,local_c,param_2,param_3,*arg2), -1 < iVar1))
         )) {
        piVar5 = arg2;
        if (*param_4 == *arg2) break;
        piVar5 = piVar4;
        if ((((arg2[8] != 0) && (uVar2 = FUN_1000aaca(param_4,(int)arg2), uVar2 != 0xffffffff)) &&
            (uVar2 <= uVar3)) && ((uVar2 != uVar3 || ((uint)arg2[2] < (uint)piVar4[2])))) {
          uVar3 = uVar2;
          piVar5 = arg2;
        }
      }
      arg2 = arg2 + 9;
      piVar4 = piVar5;
    } while (arg2 < PTR_DAT_10053c50);
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
    local_8 = (int *)0x0;
  }
  grim_d3d_debug_set_mute(0);
  return *piVar5;
}



