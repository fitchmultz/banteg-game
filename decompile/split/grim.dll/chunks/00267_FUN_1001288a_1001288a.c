/* FUN_1001288a @ 1001288a */

/* WARNING: Removing unreachable block (ram,0x100128ff) */

int * __cdecl FUN_1001288a(uint param_1,int param_2,int param_3)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  float local_24;
  uint local_1c;
  float local_18;
  uint local_10;
  float local_c;
  float local_8;
  
  uVar17 = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    fVar2 = (float)param_2;
    if (param_2 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    fVar3 = (float)(int)param_1;
    if ((int)param_1 < 0) {
      fVar3 = fVar3 + 4.2949673e+09;
    }
    fVar4 = fVar2 / fVar3;
    uVar14 = 0x10;
    if (param_1 != 0) {
      do {
        iVar9 = ftol();
        uVar17 = uVar17 + 1;
        uVar14 = uVar14 + 0xc + iVar9 * 0x10;
      } while (uVar17 < param_1);
    }
    piVar10 = operator_new(uVar14);
    if (piVar10 != (int *)0x0) {
      iVar9 = 0;
      local_1c = 0;
      iVar16 = 4;
      iVar15 = iVar16;
      if (param_1 != 0) {
        do {
          local_8 = 0.0;
          local_10 = 0;
          fVar5 = (float)(int)local_1c;
          iVar16 = iVar15 + 4;
          if ((int)local_1c < 0) {
            fVar5 = fVar5 + 4.2949673e+09;
          }
          do {
            fVar6 = (float)(int)local_10;
            if ((int)local_10 < 0) {
              fVar6 = fVar6 + 4.2949673e+09;
            }
            fVar6 = (fVar6 + fVar5) - 0.5;
            local_24 = fVar6 * fVar4;
            local_c = fVar4 + local_24;
            if (param_3 == 0) {
              if (local_24 < 0.0) {
                local_24 = 0.0;
              }
              if (fVar2 < local_c) {
                local_c = fVar2;
              }
            }
            floor((double)local_24);
            iVar11 = ftol();
            fVar7 = (float)iVar11;
            if (fVar7 < local_c) {
              iVar12 = iVar11 - param_2;
              do {
                local_18 = fVar7 + 1.0;
                if (iVar11 < 0) {
                  iVar13 = iVar11 + param_2;
                }
                else {
                  iVar13 = iVar12;
                  if (iVar11 < param_2) {
                    iVar13 = iVar11;
                  }
                }
                if (iVar13 != iVar9) {
                  if (1e-05 < local_8) {
                    piVar1 = (int *)(iVar16 + (int)piVar10);
                    *piVar1 = iVar9;
                    iVar16 = iVar16 + 8;
                    piVar1[1] = (int)local_8;
                  }
                  local_8 = 0.0;
                  iVar9 = iVar13;
                }
                if (fVar7 < local_24) {
                  fVar7 = local_24;
                }
                if (local_c < local_18) {
                  local_18 = local_c;
                }
                if (param_3 == 0) {
                  if (0.0 <= fVar6) {
                    if (fVar6 + 1.0 < fVar3) goto LAB_10012ab1;
                    fVar8 = 0.0;
                  }
                  else {
                    fVar8 = 1.0;
                  }
                }
                else {
LAB_10012ab1:
                  fVar8 = (local_18 + fVar7) * (0.5 / fVar4) - fVar6;
                }
                if (local_10 != 0) {
                  fVar8 = 1.0 - fVar8;
                }
                iVar11 = iVar11 + 1;
                iVar12 = iVar12 + 1;
                local_8 = (local_18 - fVar7) * fVar8 + local_8;
                fVar7 = (float)iVar11;
              } while (fVar7 < local_c);
            }
            local_10 = local_10 + 1;
          } while (local_10 < 2);
          if (1e-05 < local_8) {
            piVar1 = (int *)(iVar16 + (int)piVar10);
            iVar16 = iVar16 + 8;
            *piVar1 = iVar9;
            piVar1[1] = (int)local_8;
          }
          local_1c = local_1c + 1;
          *(int *)(iVar15 + (int)piVar10) = iVar16 - iVar15;
          iVar15 = iVar16;
        } while (local_1c < param_1);
      }
      *piVar10 = iVar16;
      return piVar10;
    }
  }
  return (int *)0x0;
}



