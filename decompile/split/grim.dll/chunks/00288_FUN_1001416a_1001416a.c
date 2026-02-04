/* FUN_1001416a @ 1001416a */

/* [binja] int32_t __fastcall sub_1001416a(int32_t* arg1) */

int __fastcall FUN_1001416a(int *arg1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 *puVar11;
  bool bVar12;
  uint local_14;
  uint local_10;
  uint local_8;
  
  iVar2 = arg1[1];
  iVar1 = *arg1;
  if (*(int *)(iVar2 + 4) != *(int *)(iVar1 + 4)) {
    return -0x7fffbffb;
  }
  if ((((*(int *)(iVar1 + 0x10) == 0) && (*(int *)(iVar2 + 0x1058) == *(int *)(iVar1 + 0x1058))) &&
      (local_14 = *(uint *)(iVar2 + 0x105c), local_14 == *(uint *)(iVar1 + 0x105c))) &&
     (*(int *)(iVar2 + 0x1060) == *(int *)(iVar1 + 0x1060))) {
    if (*(int *)(iVar2 + 0xc) == 0) {
      iVar1 = FUN_10013007(arg1);
      return iVar1;
    }
    if (*(int *)(iVar2 + 0x14) != 0) {
      if ((int *)(iVar2 + 0x30) != (int *)(iVar1 + 0x30)) {
        iVar3 = 0x100;
        bVar12 = true;
        piVar8 = (int *)(iVar2 + 0x30);
        piVar10 = (int *)(iVar1 + 0x30);
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar12 = *piVar8 == *piVar10;
          piVar8 = piVar8 + 1;
          piVar10 = piVar10 + 1;
        } while (bVar12);
        if (!bVar12) goto LAB_10014298;
      }
    }
    local_8 = 0;
    if (*(int *)(iVar2 + 0x1060) != 0) {
      do {
        puVar6 = (undefined4 *)(*(int *)(iVar2 + 0x1054) * local_8 + *(int *)(iVar2 + 0x18));
        puVar7 = (undefined4 *)(*(int *)(*arg1 + 0x1054) * local_8 + *(int *)(*arg1 + 0x18));
        local_10 = 0;
        if (local_14 != 0) {
          do {
            uVar5 = *(uint *)(iVar2 + 0x1064);
            puVar9 = puVar7;
            puVar11 = puVar6;
            for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
              *puVar11 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar11 = puVar11 + 1;
            }
            for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
              puVar9 = (undefined4 *)((int)puVar9 + 1);
              puVar11 = (undefined4 *)((int)puVar11 + 1);
            }
            iVar2 = arg1[1];
            puVar7 = (undefined4 *)((int)puVar7 + *(int *)(*arg1 + 0x1050));
            puVar6 = (undefined4 *)((int)puVar6 + *(int *)(iVar2 + 0x1050));
            local_14 = *(uint *)(iVar2 + 0x105c);
            local_10 = local_10 + 1;
          } while (local_10 < local_14);
        }
        local_8 = local_8 + 1;
        iVar2 = arg1[1];
      } while (local_8 < *(uint *)(iVar2 + 0x1060));
    }
    iVar1 = 0;
  }
  else {
LAB_10014298:
    iVar1 = -0x7fffbffb;
  }
  return iVar1;
}



