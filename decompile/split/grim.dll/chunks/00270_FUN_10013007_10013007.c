/* FUN_10013007 @ 10013007 */

/* [binja] int32_t __fastcall sub_10013007(int32_t* arg1) */

int __fastcall FUN_10013007(int *arg1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iStack_2c;
  uint local_14;
  undefined4 *local_10;
  uint local_c;
  undefined4 *local_8;
  
  iVar4 = *arg1;
  if (((*(uint *)(iVar4 + 0x103c) | *(uint *)(iVar4 + 0x1038) | *(uint *)(iVar4 + 0x1030) |
       *(uint *)(iVar4 + 0x1034)) & 3) != 0) {
    return -0x7fffbffb;
  }
  iVar1 = arg1[1];
  if (((*(uint *)(iVar1 + 0x103c) | *(uint *)(iVar1 + 0x1038) | *(uint *)(iVar1 + 0x1030) |
       *(uint *)(iVar1 + 0x1034)) & 3) == 0) {
    iVar2 = *(int *)(iVar1 + 4);
    if (iVar2 == 0x31545844) {
      iStack_2c = 8;
    }
    else {
      if ((((iVar2 != 0x32545844) && (iVar2 != 0x33545844)) && (iVar2 != 0x34545844)) &&
         (iVar2 != 0x35545844)) goto LAB_1001306a;
      iStack_2c = 0x10;
    }
    uVar3 = *(uint *)(iVar1 + 0x1058);
    local_10 = (undefined4 *)
               ((*(uint *)(iVar1 + 0x1034) >> 2) * *(int *)(iVar1 + 0x1050) +
                *(int *)(iVar1 + 0x1054) * *(int *)(iVar1 + 0x1040) +
                (*(uint *)(iVar1 + 0x1030) >> 2) * iStack_2c + *(int *)(iVar1 + 0x18));
    local_14 = 0;
    puVar7 = (undefined4 *)
             ((*(uint *)(iVar4 + 0x1034) >> 2) * *(int *)(iVar4 + 0x1050) +
              *(int *)(iVar4 + 0x1054) * *(int *)(iVar4 + 0x1040) +
              (*(uint *)(iVar4 + 0x1030) >> 2) * iStack_2c + *(int *)(iVar4 + 0x18));
    if (*(int *)(iVar1 + 0x1060) != 0) {
      uVar5 = *(uint *)(iVar1 + 0x105c);
      do {
        local_c = 0;
        puVar6 = local_10;
        local_8 = puVar7;
        if (uVar5 != 0) {
          do {
            local_c = local_c + 4;
            puVar8 = local_8;
            puVar9 = puVar6;
            for (uVar5 = (uVar3 >> 2) * iStack_2c >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
              *puVar9 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar9 = puVar9 + 1;
            }
            for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
              *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
              puVar8 = (undefined4 *)((int)puVar8 + 1);
              puVar9 = (undefined4 *)((int)puVar9 + 1);
            }
            puVar6 = (undefined4 *)((int)puVar6 + *(int *)(arg1[1] + 0x1050));
            uVar5 = *(uint *)(arg1[1] + 0x105c);
            local_8 = (undefined4 *)((int)local_8 + *(int *)(*arg1 + 0x1050));
          } while (local_c < uVar5);
        }
        local_10 = (undefined4 *)((int)local_10 + *(int *)(arg1[1] + 0x1054));
        puVar7 = (undefined4 *)((int)puVar7 + *(int *)(*arg1 + 0x1054));
        local_14 = local_14 + 1;
      } while (local_14 < *(uint *)(arg1[1] + 0x1060));
    }
    iVar4 = 0;
  }
  else {
LAB_1001306a:
    iVar4 = -0x7fffbffb;
  }
  return iVar4;
}



