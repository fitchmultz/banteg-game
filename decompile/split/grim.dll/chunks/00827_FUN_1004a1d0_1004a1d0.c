/* FUN_1004a1d0 @ 1004a1d0 */

void __cdecl FUN_1004a1d0(uint param_1,int *param_2,int param_3)

{
  byte bVar1;
  int *piVar2;
  undefined1 *puVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  byte *pbVar11;
  undefined1 *local_c;
  byte *local_8;
  undefined1 *local_4;
  
  piVar5 = param_2;
  uVar4 = param_1;
  piVar2 = *(int **)(param_1 + 4);
  pbVar11 = (byte *)*param_2;
  uVar10 = *(uint *)(param_1 + 0x1c);
  puVar9 = *(undefined1 **)(param_1 + 0x34);
  if (puVar9 < *(undefined1 **)(param_1 + 0x30)) {
    local_c = *(undefined1 **)(param_1 + 0x30) + (-1 - (int)puVar9);
    param_1 = *(uint *)(param_1 + 0x20);
    param_2 = (int *)param_2[1];
  }
  else {
    local_c = (undefined1 *)(*(int *)(param_1 + 0x2c) - (int)puVar9);
    param_1 = *(uint *)(param_1 + 0x20);
    param_2 = (int *)param_2[1];
  }
  do {
    switch(*piVar2) {
    case 0:
      if (((undefined1 *)0x101 < local_c) && ((int *)0x9 < param_2)) {
        *(uint *)(uVar4 + 0x20) = param_1;
        *(uint *)(uVar4 + 0x1c) = uVar10;
        iVar6 = *piVar5;
        piVar5[1] = (int)param_2;
        *piVar5 = (int)pbVar11;
        piVar5[2] = (int)(pbVar11 + (piVar5[2] - iVar6));
        *(undefined1 **)(uVar4 + 0x34) = puVar9;
        param_3 = FUN_1004b220((uint)*(byte *)(piVar2 + 4),(uint)*(byte *)((int)piVar2 + 0x11),
                               piVar2[5],piVar2[6],uVar4,piVar5);
        param_2 = (int *)piVar5[1];
        param_1 = *(uint *)(uVar4 + 0x20);
        pbVar11 = (byte *)*piVar5;
        uVar10 = *(uint *)(uVar4 + 0x1c);
        puVar9 = *(undefined1 **)(uVar4 + 0x34);
        if (puVar9 < *(undefined1 **)(uVar4 + 0x30)) {
          local_c = *(undefined1 **)(uVar4 + 0x30) + (-1 - (int)puVar9);
        }
        else {
          local_c = (undefined1 *)(*(int *)(uVar4 + 0x2c) - (int)puVar9);
        }
        if (param_3 != 0) {
          *piVar2 = (-(uint)(param_3 != 1) & 2) + 7;
          break;
        }
      }
      *piVar2 = 1;
      piVar2[3] = (uint)*(byte *)(piVar2 + 4);
      piVar2[2] = piVar2[5];
    case 1:
      for (; uVar10 < (uint)piVar2[3]; uVar10 = uVar10 + 8) {
        if (param_2 == (int *)0x0) {
LAB_1004a779:
          *(uint *)(uVar4 + 0x1c) = uVar10;
          *(uint *)(uVar4 + 0x20) = param_1;
          iVar6 = *piVar5;
          piVar5[1] = 0;
          *piVar5 = (int)pbVar11;
          piVar5[2] = (int)(pbVar11 + (piVar5[2] - iVar6));
          *(undefined1 **)(uVar4 + 0x34) = puVar9;
          FUN_1004b0e0(uVar4,(int)piVar5,param_3);
          return;
        }
        param_2 = (int *)((int)param_2 + -1);
        param_3 = 0;
        param_1 = param_1 | (uint)*pbVar11 << ((byte)uVar10 & 0x1f);
        pbVar11 = pbVar11 + 1;
      }
      local_8 = (byte *)(piVar2[2] + (*(uint *)(&DAT_10059608 + piVar2[3] * 4) & param_1) * 8);
      param_1 = param_1 >> (local_8[1] & 0x1f);
      uVar10 = uVar10 - local_8[1];
      bVar1 = *local_8;
      uVar7 = (uint)bVar1;
      if (uVar7 == 0) {
        piVar2[2] = *(int *)(local_8 + 4);
        *piVar2 = 6;
      }
      else if ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x40) == 0) {
LAB_1004a3a4:
          piVar2[3] = uVar7;
          piVar2[2] = (int)(local_8 + *(int *)(local_8 + 4) * 8);
        }
        else {
          if ((bVar1 & 0x20) == 0) {
            *piVar2 = 9;
            piVar5[6] = (int)s_invalid_literal_length_code_100583f0;
LAB_1004a7c5:
            *(uint *)(uVar4 + 0x20) = param_1;
            *(uint *)(uVar4 + 0x1c) = uVar10;
            piVar5[1] = (int)param_2;
            piVar5[2] = (int)(pbVar11 + (piVar5[2] - *piVar5));
            *piVar5 = (int)pbVar11;
            *(undefined1 **)(uVar4 + 0x34) = puVar9;
            FUN_1004b0e0(uVar4,(int)piVar5,-3);
            return;
          }
          *piVar2 = 7;
        }
      }
      else {
        piVar2[2] = bVar1 & 0xf;
        iVar6 = *(int *)(local_8 + 4);
        *piVar2 = 2;
        piVar2[1] = iVar6;
      }
      break;
    case 2:
      uVar7 = piVar2[2];
      for (; uVar10 < uVar7; uVar10 = uVar10 + 8) {
        if (param_2 == (int *)0x0) goto LAB_1004a779;
        param_2 = (int *)((int)param_2 + -1);
        param_3 = 0;
        param_1 = param_1 | (uint)*pbVar11 << ((byte)uVar10 & 0x1f);
        pbVar11 = pbVar11 + 1;
      }
      piVar2[1] = piVar2[1] + (*(uint *)(&DAT_10059608 + uVar7 * 4) & param_1);
      param_1 = param_1 >> ((byte)uVar7 & 0x1f);
      uVar10 = uVar10 - uVar7;
      *piVar2 = 3;
      piVar2[3] = (uint)*(byte *)((int)piVar2 + 0x11);
      piVar2[2] = piVar2[6];
    case 3:
      for (; uVar10 < (uint)piVar2[3]; uVar10 = uVar10 + 8) {
        if (param_2 == (int *)0x0) goto LAB_1004a779;
        param_2 = (int *)((int)param_2 + -1);
        param_3 = 0;
        param_1 = param_1 | (uint)*pbVar11 << ((byte)uVar10 & 0x1f);
        pbVar11 = pbVar11 + 1;
      }
      local_8 = (byte *)(piVar2[2] + (*(uint *)(&DAT_10059608 + piVar2[3] * 4) & param_1) * 8);
      param_1 = param_1 >> (local_8[1] & 0x1f);
      uVar10 = uVar10 - local_8[1];
      bVar1 = *local_8;
      uVar7 = (uint)bVar1;
      if ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x40) != 0) {
          *piVar2 = 9;
          piVar5[6] = (int)s_invalid_distance_code_100583d8;
          goto LAB_1004a7c5;
        }
        goto LAB_1004a3a4;
      }
      piVar2[2] = bVar1 & 0xf;
      iVar6 = *(int *)(local_8 + 4);
      *piVar2 = 4;
      piVar2[3] = iVar6;
      break;
    case 4:
      uVar7 = piVar2[2];
      for (; uVar10 < uVar7; uVar10 = uVar10 + 8) {
        if (param_2 == (int *)0x0) goto LAB_1004a779;
        param_2 = (int *)((int)param_2 + -1);
        param_3 = 0;
        param_1 = param_1 | (uint)*pbVar11 << ((byte)uVar10 & 0x1f);
        pbVar11 = pbVar11 + 1;
      }
      piVar2[3] = piVar2[3] + (*(uint *)(&DAT_10059608 + uVar7 * 4) & param_1);
      param_1 = param_1 >> ((byte)uVar7 & 0x1f);
      uVar10 = uVar10 - uVar7;
      *piVar2 = 5;
    case 5:
      if ((uint)((int)puVar9 - *(int *)(uVar4 + 0x28)) < (uint)piVar2[3]) {
        iVar6 = (*(int *)(uVar4 + 0x2c) - *(int *)(uVar4 + 0x28)) - piVar2[3];
      }
      else {
        iVar6 = -piVar2[3];
      }
      local_4 = puVar9 + iVar6;
      iVar6 = piVar2[1];
      while (iVar6 != 0) {
        puVar8 = puVar9;
        if (local_c == (undefined1 *)0x0) {
          if (puVar9 == *(undefined1 **)(uVar4 + 0x2c)) {
            local_c = *(undefined1 **)(uVar4 + 0x30);
            puVar8 = *(undefined1 **)(uVar4 + 0x28);
            if (local_c != puVar8) {
              if (puVar8 < local_c) {
                local_c = local_c + (-1 - (int)puVar8);
              }
              else {
                local_c = *(undefined1 **)(uVar4 + 0x2c) + -(int)puVar8;
              }
              puVar9 = puVar8;
              if (local_c != (undefined1 *)0x0) goto LAB_1004a65b;
            }
          }
          *(undefined1 **)(uVar4 + 0x34) = puVar9;
          param_3 = FUN_1004b0e0(uVar4,(int)piVar5,param_3);
          puVar8 = *(undefined1 **)(uVar4 + 0x34);
          puVar9 = *(undefined1 **)(uVar4 + 0x30);
          if (puVar8 < puVar9) {
            local_c = puVar9 + (-1 - (int)puVar8);
          }
          else {
            local_c = (undefined1 *)(*(int *)(uVar4 + 0x2c) - (int)puVar8);
          }
          if ((puVar8 == *(undefined1 **)(uVar4 + 0x2c)) &&
             (puVar3 = *(undefined1 **)(uVar4 + 0x28), puVar9 != puVar3)) {
            puVar8 = puVar3;
            if (puVar3 < puVar9) {
              local_c = puVar9 + (-1 - (int)puVar3);
            }
            else {
              local_c = *(undefined1 **)(uVar4 + 0x2c) + -(int)puVar3;
            }
          }
          if (local_c == (undefined1 *)0x0) goto LAB_1004a7fd;
        }
LAB_1004a65b:
        puVar9 = puVar8 + 1;
        param_3 = 0;
        *puVar8 = *local_4;
        local_4 = local_4 + 1;
        local_c = local_c + -1;
        if (local_4 == *(undefined1 **)(uVar4 + 0x2c)) {
          local_4 = *(undefined1 **)(uVar4 + 0x28);
        }
        iVar6 = piVar2[1] + -1;
        piVar2[1] = iVar6;
      }
      *piVar2 = 0;
      break;
    case 6:
      puVar8 = puVar9;
      if (local_c == (undefined1 *)0x0) {
        if (puVar9 == *(undefined1 **)(uVar4 + 0x2c)) {
          local_c = *(undefined1 **)(uVar4 + 0x30);
          puVar8 = *(undefined1 **)(uVar4 + 0x28);
          if (local_c != puVar8) {
            if (puVar8 < local_c) {
              local_c = local_c + (-1 - (int)puVar8);
            }
            else {
              local_c = *(undefined1 **)(uVar4 + 0x2c) + -(int)puVar8;
            }
            puVar9 = puVar8;
            if (local_c != (undefined1 *)0x0) goto LAB_1004a748;
          }
        }
        *(undefined1 **)(uVar4 + 0x34) = puVar9;
        param_3 = FUN_1004b0e0(uVar4,(int)piVar5,param_3);
        puVar8 = *(undefined1 **)(uVar4 + 0x34);
        puVar9 = *(undefined1 **)(uVar4 + 0x30);
        if (puVar8 < puVar9) {
          local_c = puVar9 + (-1 - (int)puVar8);
        }
        else {
          local_c = (undefined1 *)(*(int *)(uVar4 + 0x2c) - (int)puVar8);
        }
        if ((puVar8 == *(undefined1 **)(uVar4 + 0x2c)) &&
           (puVar3 = *(undefined1 **)(uVar4 + 0x28), puVar9 != puVar3)) {
          puVar8 = puVar3;
          if (puVar3 < puVar9) {
            local_c = puVar9 + (-1 - (int)puVar3);
          }
          else {
            local_c = *(undefined1 **)(uVar4 + 0x2c) + -(int)puVar3;
          }
        }
        if (local_c == (undefined1 *)0x0) {
LAB_1004a7fd:
          *(uint *)(uVar4 + 0x20) = param_1;
          *(uint *)(uVar4 + 0x1c) = uVar10;
          iVar6 = *piVar5;
          piVar5[1] = (int)param_2;
          *piVar5 = (int)pbVar11;
          piVar5[2] = (int)(pbVar11 + (piVar5[2] - iVar6));
          *(undefined1 **)(uVar4 + 0x34) = puVar8;
          FUN_1004b0e0(uVar4,(int)piVar5,param_3);
          return;
        }
      }
LAB_1004a748:
      param_3 = 0;
      *puVar8 = (char)piVar2[2];
      puVar9 = puVar8 + 1;
      local_c = local_c + -1;
      *piVar2 = 0;
      break;
    case 7:
      if (7 < uVar10) {
        uVar10 = uVar10 - 8;
        param_2 = (int *)((int)param_2 + 1);
        pbVar11 = pbVar11 + -1;
      }
      *(undefined1 **)(uVar4 + 0x34) = puVar9;
      iVar6 = FUN_1004b0e0(uVar4,(int)piVar5,param_3);
      puVar9 = *(undefined1 **)(uVar4 + 0x34);
      if (*(undefined1 **)(uVar4 + 0x30) != puVar9) {
        *(uint *)(uVar4 + 0x1c) = uVar10;
        *(uint *)(uVar4 + 0x20) = param_1;
        piVar5[1] = (int)param_2;
        piVar5[2] = (int)(pbVar11 + (piVar5[2] - *piVar5));
        *piVar5 = (int)pbVar11;
        *(undefined1 **)(uVar4 + 0x34) = puVar9;
        FUN_1004b0e0(uVar4,(int)piVar5,iVar6);
        return;
      }
      *piVar2 = 8;
    case 8:
      goto switchD_1004a21c_caseD_8;
    case 9:
      *(uint *)(uVar4 + 0x20) = param_1;
      *(uint *)(uVar4 + 0x1c) = uVar10;
      piVar5[1] = (int)param_2;
      piVar5[2] = (int)(pbVar11 + (piVar5[2] - *piVar5));
      *piVar5 = (int)pbVar11;
      *(undefined1 **)(uVar4 + 0x34) = puVar9;
      FUN_1004b0e0(uVar4,(int)piVar5,-3);
      return;
    default:
      *(uint *)(uVar4 + 0x20) = param_1;
      *(uint *)(uVar4 + 0x1c) = uVar10;
      piVar5[1] = (int)param_2;
      piVar5[2] = (int)(pbVar11 + (piVar5[2] - *piVar5));
      *piVar5 = (int)pbVar11;
      *(undefined1 **)(uVar4 + 0x34) = puVar9;
      FUN_1004b0e0(uVar4,(int)piVar5,-2);
      return;
    }
  } while( true );
switchD_1004a21c_caseD_8:
  *(uint *)(uVar4 + 0x20) = param_1;
  *(uint *)(uVar4 + 0x1c) = uVar10;
  piVar5[1] = (int)param_2;
  piVar5[2] = (int)(pbVar11 + (piVar5[2] - *piVar5));
  *piVar5 = (int)pbVar11;
  *(undefined1 **)(uVar4 + 0x34) = puVar9;
  FUN_1004b0e0(uVar4,(int)piVar5,1);
  return;
}



