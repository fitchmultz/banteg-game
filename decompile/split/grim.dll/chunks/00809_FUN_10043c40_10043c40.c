/* FUN_10043c40 @ 10043c40 */

void __cdecl FUN_10043c40(int param_1,int *param_2)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int *local_4;
  
  iVar6 = *(int *)(*(int *)(param_1 + 0x1a4) + 0x18);
  local_1c = param_2[1];
  local_8 = param_2[5];
  local_14 = param_2[4];
  param_1 = param_2[2];
  local_20 = *param_2;
  local_18 = param_2[3];
  if (local_20 < local_1c) {
    if (local_20 <= local_1c) {
      local_4 = (int *)(iVar6 + local_20 * 4);
      local_10 = local_20;
      do {
        if (param_1 <= local_18) {
          psVar2 = (short *)(*local_4 + (param_1 * 0x20 + local_14) * 2);
          iVar8 = local_14;
          iVar7 = param_1;
          psVar3 = psVar2;
          do {
            for (; iVar8 <= local_8; iVar8 = iVar8 + 1) {
              sVar1 = *psVar2;
              psVar2 = psVar2 + 1;
              if (sVar1 != 0) {
                *param_2 = local_10;
                local_20 = local_10;
                goto LAB_10043d0f;
              }
            }
            iVar7 = iVar7 + 1;
            psVar2 = psVar3 + 0x20;
            iVar8 = local_14;
            psVar3 = psVar2;
          } while (iVar7 <= local_18);
        }
        local_10 = local_10 + 1;
        local_4 = local_4 + 1;
      } while (local_10 <= local_1c);
    }
LAB_10043d0f:
    if (local_20 < local_1c) {
      piVar4 = (int *)(iVar6 + local_1c * 4);
      local_10 = local_1c;
      do {
        if (param_1 <= local_18) {
          psVar2 = (short *)(*piVar4 + (param_1 * 0x20 + local_14) * 2);
          iVar8 = local_14;
          iVar7 = param_1;
          psVar3 = psVar2;
          do {
            for (; iVar8 <= local_8; iVar8 = iVar8 + 1) {
              sVar1 = *psVar2;
              psVar2 = psVar2 + 1;
              if (sVar1 != 0) {
                local_1c = local_10;
                param_2[1] = local_10;
                goto LAB_10043d8f;
              }
            }
            iVar7 = iVar7 + 1;
            psVar2 = psVar3 + 0x20;
            iVar8 = local_14;
            psVar3 = psVar2;
          } while (iVar7 <= local_18);
        }
        local_10 = local_10 + -1;
        piVar4 = piVar4 + -1;
      } while (local_20 <= local_10);
    }
  }
LAB_10043d8f:
  if (param_1 < local_18) {
    if (param_1 <= local_18) {
      iVar8 = (param_1 * 0x20 + local_14) * 2;
      local_10 = param_1;
      do {
        if (local_20 <= local_1c) {
          piVar4 = (int *)(iVar6 + local_20 * 4);
          iVar7 = local_20;
          do {
            psVar2 = (short *)(*piVar4 + iVar8);
            for (iVar5 = local_14; iVar5 <= local_8; iVar5 = iVar5 + 1) {
              sVar1 = *psVar2;
              psVar2 = psVar2 + 1;
              if (sVar1 != 0) {
                param_1 = local_10;
                param_2[2] = local_10;
                goto LAB_10043e16;
              }
            }
            iVar7 = iVar7 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar7 <= local_1c);
        }
        local_10 = local_10 + 1;
        iVar8 = iVar8 + 0x40;
      } while (local_10 <= local_18);
    }
LAB_10043e16:
    if (param_1 < local_18) {
      iVar8 = (local_18 * 0x20 + local_14) * 2;
      local_10 = local_18;
      do {
        if (local_20 <= local_1c) {
          piVar4 = (int *)(iVar6 + local_20 * 4);
          iVar7 = local_20;
          do {
            psVar2 = (short *)(iVar8 + *piVar4);
            for (iVar5 = local_14; iVar5 <= local_8; iVar5 = iVar5 + 1) {
              sVar1 = *psVar2;
              psVar2 = psVar2 + 1;
              if (sVar1 != 0) {
                local_18 = local_10;
                param_2[3] = local_10;
                goto LAB_10043e91;
              }
            }
            iVar7 = iVar7 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar7 <= local_1c);
        }
        local_10 = local_10 + -1;
        iVar8 = iVar8 + -0x40;
      } while (param_1 <= local_10);
    }
  }
LAB_10043e91:
  iVar8 = local_14;
  if (local_14 < local_8) {
    for (; iVar8 <= local_8; iVar8 = iVar8 + 1) {
      if (local_20 <= local_1c) {
        piVar4 = (int *)(iVar6 + local_20 * 4);
        iVar7 = local_20;
        do {
          psVar2 = (short *)(*piVar4 + (param_1 * 0x20 + iVar8) * 2);
          for (iVar5 = param_1; iVar5 <= local_18; iVar5 = iVar5 + 1) {
            if (*psVar2 != 0) {
              param_2[4] = iVar8;
              local_14 = iVar8;
              goto LAB_10043f0f;
            }
            psVar2 = psVar2 + 0x20;
          }
          iVar7 = iVar7 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar7 <= local_1c);
      }
    }
LAB_10043f0f:
    iVar8 = local_8;
    if (local_14 < local_8) {
      do {
        if (local_20 <= local_1c) {
          piVar4 = (int *)(iVar6 + local_20 * 4);
          iVar7 = local_20;
          do {
            psVar2 = (short *)((param_1 * 0x20 + iVar8) * 2 + *piVar4);
            for (iVar5 = param_1; iVar5 <= local_18; iVar5 = iVar5 + 1) {
              if (*psVar2 != 0) {
                param_2[5] = iVar8;
                local_8 = iVar8;
                goto LAB_10043f85;
              }
              psVar2 = psVar2 + 0x20;
            }
            iVar7 = iVar7 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar7 <= local_1c);
        }
        iVar8 = iVar8 + -1;
      } while (local_14 <= iVar8);
    }
  }
LAB_10043f85:
  iVar8 = (local_8 - local_14) * 8;
  iVar5 = (local_18 - param_1) * 0xc;
  iVar7 = (local_1c - local_20) * 0x10;
  param_2[6] = iVar8 * iVar8 + iVar5 * iVar5 + iVar7 * iVar7;
  iVar8 = 0;
  if (local_20 <= local_1c) {
    local_4 = (int *)(iVar6 + local_20 * 4);
    local_10 = (local_1c - local_20) + 1;
    do {
      if (param_1 <= local_18) {
        psVar2 = (short *)(*local_4 + (param_1 * 0x20 + local_14) * 2);
        local_c = (local_18 - param_1) + 1;
        do {
          if (local_14 <= local_8) {
            iVar6 = (local_8 - local_14) + 1;
            psVar3 = psVar2;
            do {
              if (*psVar3 != 0) {
                iVar8 = iVar8 + 1;
              }
              psVar3 = psVar3 + 1;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
          psVar2 = psVar2 + 0x20;
          local_c = local_c + -1;
        } while (local_c != 0);
      }
      local_4 = local_4 + 1;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
    param_2[7] = iVar8;
    return;
  }
  param_2[7] = 0;
  return;
}



