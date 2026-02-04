/* FUN_1002eec9 @ 1002eec9 */

undefined4 __cdecl FUN_1002eec9(int param_1)

{
  uint *puVar1;
  int iVar2;
  int arg1;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int aiStack_38 [4];
  int *local_28;
  int local_24;
  uint local_20;
  int *local_1c;
  int local_18;
  int *local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  arg1 = param_1;
  param_1 = 0;
  iVar2 = *(int *)(arg1 + 0x184);
  if (0 < *(int *)(arg1 + 0x120)) {
    local_8 = (int *)(arg1 + 0x124);
    do {
      iVar4 = *(int *)(*local_8 + 0xc);
      iVar4 = (**(code **)(*(int *)(arg1 + 4) + 0x20))
                        (arg1,*(undefined4 *)(iVar2 + 0x48 + *(int *)(*local_8 + 4) * 4),
                         *(int *)(arg1 + 0x80) * iVar4,iVar4,1);
      local_8 = local_8 + 1;
      aiStack_38[param_1] = iVar4;
      param_1 = param_1 + 1;
    } while (param_1 < *(int *)(arg1 + 0x120));
  }
  local_8 = *(int **)(iVar2 + 0x18);
  do {
    if (*(int *)(iVar2 + 0x1c) <= (int)local_8) {
      puVar1 = (uint *)(arg1 + 0x80);
      *puVar1 = *puVar1 + 1;
      if (*puVar1 < *(uint *)(arg1 + 0x118)) {
        FUN_1002ec9d((void *)arg1);
        uVar8 = 3;
      }
      else {
        (**(code **)(*(int *)(arg1 + 0x18c) + 0xc))(arg1);
        uVar8 = 4;
      }
      return uVar8;
    }
    uVar7 = *(uint *)(iVar2 + 0x14);
    local_20 = uVar7;
    if (uVar7 < *(uint *)(arg1 + 0x134)) {
      do {
        local_c = 0;
        param_1 = 0;
        if (0 < *(int *)(arg1 + 0x120)) {
          local_1c = (int *)(arg1 + 0x124);
          do {
            iVar4 = *local_1c;
            iVar6 = *(int *)(iVar4 + 0x34);
            local_18 = 0;
            if (0 < *(int *)(iVar4 + 0x38)) {
              local_24 = iVar6 * uVar7 * 0x80;
              local_14 = (int *)(aiStack_38[param_1] + (int)local_8 * 4);
              do {
                iVar5 = *local_14 + local_24;
                local_10 = 0;
                if (0 < iVar6) {
                  local_28 = (int *)(iVar2 + 0x20 + local_c * 4);
                  do {
                    local_c = local_c + 1;
                    *local_28 = iVar5;
                    local_28 = local_28 + 1;
                    iVar5 = iVar5 + 0x80;
                    local_10 = local_10 + 1;
                    iVar6 = *(int *)(iVar4 + 0x34);
                  } while (local_10 < iVar6);
                }
                local_18 = local_18 + 1;
                local_14 = local_14 + 1;
              } while (local_18 < *(int *)(iVar4 + 0x38));
            }
            param_1 = param_1 + 1;
            local_1c = local_1c + 1;
          } while (param_1 < *(int *)(arg1 + 0x120));
        }
        local_20 = uVar7;
        cVar3 = (**(code **)(*(int *)(arg1 + 0x194) + 4))(arg1,iVar2 + 0x20);
        if (cVar3 == '\0') {
          *(int **)(iVar2 + 0x18) = local_8;
          *(uint *)(iVar2 + 0x14) = uVar7;
          return 0;
        }
        uVar7 = uVar7 + 1;
        local_20 = uVar7;
      } while (uVar7 < *(uint *)(arg1 + 0x134));
    }
    *(undefined4 *)(iVar2 + 0x14) = 0;
    local_8 = (int *)((int)local_8 + 1);
  } while( true );
}



