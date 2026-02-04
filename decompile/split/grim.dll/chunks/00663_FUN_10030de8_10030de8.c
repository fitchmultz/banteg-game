/* FUN_10030de8 @ 10030de8 */

void __cdecl FUN_10030de8(undefined *param_1)

{
  int *piVar1;
  double dVar2;
  undefined *puVar3;
  int iVar4;
  short *psVar5;
  undefined2 *puVar6;
  double *pdVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int local_10;
  double *local_c;
  int local_8;
  
  puVar3 = param_1;
  piVar10 = (int *)(param_1 + 0x20);
  piVar11 = (int *)(param_1 + 0x198);
  piVar1 = (int *)(param_1 + 0xc4);
  local_8 = 0;
  param_1 = (undefined *)0x0;
  local_10 = 0;
  if (0 < *piVar10) {
    piVar10 = (int *)(*piVar11 + 0x2c);
    piVar11 = (int *)(*piVar1 + 0x24);
    do {
      iVar8 = *piVar11;
      if (iVar8 == 1) {
        param_1 = FUN_10035ecb;
LAB_10030ea3:
        local_8 = 0;
      }
      else {
        if (iVar8 == 2) {
          param_1 = FUN_10035d0d;
          goto LAB_10030ea3;
        }
        if (iVar8 == 4) {
          param_1 = FUN_100359f8;
          goto LAB_10030ea3;
        }
        if (iVar8 == 8) {
          iVar8 = *(int *)(puVar3 + 0x44);
          if (iVar8 == 0) {
            param_1 = FUN_10035f08;
            goto LAB_10030ea3;
          }
          if (iVar8 == 1) {
            param_1 = FUN_10035f54;
            local_8 = 1;
          }
          else {
            if (iVar8 != 2) {
              *(undefined4 *)(*(int *)puVar3 + 0x14) = 0x2f;
              goto LAB_10030e5d;
            }
            param_1 = FUN_10035fa0;
            local_8 = 2;
          }
        }
        else {
          *(undefined4 *)(*(int *)puVar3 + 0x14) = 6;
          *(int *)(*(int *)puVar3 + 0x18) = *piVar11;
LAB_10030e5d:
          (*(code *)**(undefined4 **)puVar3)(puVar3);
        }
      }
      piVar10[-10] = (int)param_1;
      if ((((char)piVar11[3] != '\0') && (*piVar10 != local_8)) && (iVar8 = piVar11[10], iVar8 != 0)
         ) {
        *piVar10 = local_8;
        if (local_8 == 0) {
          puVar6 = (undefined2 *)piVar11[0xb];
          iVar8 = iVar8 - (int)puVar6;
          iVar9 = 0x40;
          do {
            *puVar6 = *(undefined2 *)(iVar8 + (int)puVar6);
            puVar6 = puVar6 + 1;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
        else if (local_8 == 1) {
          iVar9 = piVar11[0xb];
          psVar5 = &DAT_1004f510;
          do {
            *(short *)(iVar9 + -0x1004f510 + (int)psVar5) =
                 (short)((int)*(short *)(iVar8 + -0x1004f510 + (int)psVar5) * (int)*psVar5 + 0x800
                        >> 0xc);
            psVar5 = psVar5 + 1;
          } while ((int)psVar5 < 0x1004f590);
        }
        else if (local_8 == 2) {
          iVar9 = piVar11[0xb];
          iVar4 = 0;
          local_c = (double *)&DAT_1004f590;
          do {
            pdVar7 = (double *)&DAT_1004f590;
            do {
              dVar2 = *pdVar7;
              pdVar7 = pdVar7 + 1;
              *(float *)(iVar9 + iVar4 * 4) =
                   (float)*(ushort *)(iVar8 + iVar4 * 2) * (float)dVar2 * (float)*local_c;
              iVar4 = iVar4 + 1;
            } while ((int)pdVar7 < 0x1004f5d0);
            local_c = local_c + 1;
          } while ((int)local_c < 0x1004f5d0);
        }
        else {
          *(undefined4 *)(*(int *)puVar3 + 0x14) = 0x2f;
          (*(code *)**(undefined4 **)puVar3)(puVar3);
        }
      }
      local_10 = local_10 + 1;
      piVar10 = piVar10 + 1;
      piVar11 = piVar11 + 0x15;
    } while (local_10 < *(int *)(puVar3 + 0x20));
  }
  return;
}



