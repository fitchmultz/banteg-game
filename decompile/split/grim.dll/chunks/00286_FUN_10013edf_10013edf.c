/* FUN_10013edf @ 10013edf */

/* [binja] int32_t __fastcall sub_10013edf(int32_t* arg1) */

int __fastcall FUN_10013edf(int *arg1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  ushort *puVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  ushort *puVar12;
  
  iVar5 = *arg1;
  puVar6 = *(ushort **)(arg1[1] + 0x18);
  iVar7 = *(int *)(iVar5 + 0x1050);
  puVar8 = *(ushort **)(iVar5 + 0x18);
  puVar12 = (ushort *)(*(int *)(iVar5 + 0x105c) * iVar7 + (int)puVar8);
  for (; puVar8 < puVar12; puVar8 = puVar8 + iVar7) {
    iVar5 = *(int *)(iVar5 + 0x1058);
    puVar11 = (ushort *)(iVar7 + (int)puVar8);
    puVar9 = puVar6;
    for (puVar10 = puVar8; puVar10 < puVar8 + iVar5; puVar10 = puVar10 + 2) {
      uVar1 = *puVar10;
      uVar2 = puVar10[1];
      uVar3 = puVar11[1];
      uVar4 = *puVar11;
      puVar11 = puVar11 + 2;
      *puVar9 = (ushort)(byte)((byte)((uint)(uVar3 & 0xff) + (uint)(uVar1 & 0xff) +
                                      (uint)(uVar4 & 0xff) + 2 + (uint)(uVar2 & 0xff) >> 2) ^
                              (byte)((uint)(uVar3 & 0xff00) + (uVar1 & 0xffffff00) +
                                     (uint)(uVar4 & 0xff00) + 0x200 + (uint)(uVar2 & 0xff00) >> 2))
                ^ (ushort)((uVar3 & 0xff00) + (uVar1 & 0xff00) + (uVar4 & 0xff00) + 0x200 +
                           (uVar2 & 0xff00) >> 2);
      puVar9 = puVar9 + 1;
    }
    puVar6 = (ushort *)((int)puVar6 + *(int *)(arg1[1] + 0x1050));
    iVar5 = *arg1;
    iVar7 = *(int *)(iVar5 + 0x1050);
  }
  return 0;
}



