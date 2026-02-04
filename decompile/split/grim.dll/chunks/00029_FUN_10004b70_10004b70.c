/* FUN_10004b70 @ 10004b70 */

/* [binja] char* sub_10004b70(char* arg1, void** arg2, int32_t* arg3, int32_t* arg4) */

char * __cdecl FUN_10004b70(char *arg1,void **arg2,int *arg3,int *arg4)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint *in_stack_00000014;
  undefined *local_2a4 [33];
  undefined1 local_220 [64];
  int local_1e0;
  int local_1dc;
  int local_184;
  uint local_180;
  int local_178;
  uint local_168;
  uint local_38;
  uint local_34;
  int *local_30;
  char *local_2c;
  int local_28;
  int local_24;
  int *local_20;
  uint local_1c;
  char *local_18;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1004b7e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000a810((int)local_14);
  local_8 = 0;
  local_18 = (char *)0x0;
  local_20 = (int *)FUN_1000a880(arg1,&local_38);
  *arg4 = 0;
  *in_stack_00000014 = 0;
  local_28 = *local_20;
  local_30 = local_20 + 1;
  if (local_30 != (int *)0x0) {
    local_1e0 = FUN_1003ab10(local_2a4);
    local_2a4[0] = &DAT_10004e90;
    iVar2 = setjmp3(local_220,3,&DAT_1000a8ee,local_8,&FuncInfo_100516e8);
    if (iVar2 == 0) {
      FUN_10009a50(&local_1e0,0x3d,0x1a8);
      FUN_1003a990((int)&local_1e0,local_30,local_28);
      FUN_10009b30(&local_1e0,'\x01');
      FUN_10009ec0(&local_1e0);
      uVar7 = local_180 * local_184 * 4 + 0x12;
      *arg3 = uVar7;
      pcVar3 = operator_new(uVar7);
      if (pcVar3 != (char *)0x0) {
        *arg4 = local_184;
        *in_stack_00000014 = local_180;
        local_18 = pcVar3 + 0x12;
        piVar4 = (int *)(**(code **)(local_1dc + 8))(&local_1e0,1,local_178 * local_184,1);
        if (local_168 < local_180) {
          do {
            FUN_1000a070(&local_1e0,piVar4,1);
            uVar7 = 0;
            if (*arg4 != 0) {
              iVar2 = 0;
              pcVar5 = pcVar3 + 0x12 + (*in_stack_00000014 - local_168) * *arg4 * 4 + 2;
              do {
                pcVar5[1] = -1;
                uVar7 = uVar7 + 1;
                pcVar1 = (char *)(*piVar4 + iVar2);
                iVar2 = iVar2 + 3;
                *pcVar5 = *pcVar1;
                pcVar5[-1] = *(char *)(*piVar4 + -2 + iVar2);
                pcVar5[-2] = *(char *)(*piVar4 + -1 + iVar2);
                pcVar5 = pcVar5 + 4;
              } while (uVar7 < (uint)*arg4);
            }
          } while (local_168 < local_180);
        }
        local_18 = pcVar3;
        FUN_10009e00(&local_1e0);
        FUN_10009b20((int)&local_1e0);
        *pcVar3 = '\0';
        pcVar3[1] = '\0';
        pcVar3[2] = '\x02';
        pcVar3[3] = '\0';
        pcVar3[4] = '\0';
        pcVar3[5] = '\0';
        pcVar3[6] = '\0';
        pcVar3[7] = '\0';
        pcVar3[8] = '\0';
        pcVar3[9] = '\0';
        pcVar3[10] = '\0';
        pcVar3[0xb] = '\0';
        *(short *)(pcVar3 + 0xc) = (short)*arg4;
        *(short *)(pcVar3 + 0xe) = (short)*in_stack_00000014;
        local_1c = (uint)*(ushort *)(pcVar3 + 0xe);
        uVar7 = 0;
        local_2c = (char *)(local_28 + 4 + (int)local_20);
        pcVar3[0x10] = ' ';
        pcVar3[0x11] = '\b';
        local_24 = 0;
        iVar2 = 0;
        while (local_1c = local_1c - 1, -1 < (int)local_1c) {
          iVar8 = 0;
          uVar6 = (uint)*(ushort *)(pcVar3 + 0xc);
          if (uVar6 != 0) {
            do {
              if ((int)uVar7 < 1) {
                uVar7 = (uint)(byte)local_2c[iVar2];
                local_24 = iVar2 + 2;
                local_34 = (uint)(byte)local_2c[iVar2 + 1];
                iVar8 = iVar8 + -1;
              }
              else {
                uVar7 = uVar7 - 1;
                pcVar3[(uVar6 * local_1c + iVar8) * 4 + 0x15] = (char)local_34;
              }
              iVar8 = iVar8 + 1;
              uVar6 = (uint)*(ushort *)(pcVar3 + 0xc);
              iVar2 = local_24;
            } while (iVar8 < (int)uVar6);
          }
        }
        if (local_20 != (int *)0x0) {
          operator_delete(local_20);
        }
        local_8 = 0xffffffff;
        grim_noop();
        ExceptionList = local_10;
        return pcVar3;
      }
      local_18 = pcVar3;
      FUN_10009b20((int)&local_1e0);
    }
    else {
      FUN_10009b20((int)&local_1e0);
      if (local_18 != (char *)0x0) {
        operator_delete(local_18);
      }
    }
  }
  local_8 = 0xffffffff;
  grim_noop();
  ExceptionList = local_10;
  return (char *)0x0;
}



